namespace Vx.Translation;

public static class All {

  /**
   * @function context_all
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-all)
   */
  public interface Func_context_all : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_context vx_context_all(Vx.Core.Type_anylist args);
  }

  public class Class_context_all : Vx.Core.Class_base, Func_context_all {

    public override Vx.Translation.All.Func_context_all vx_new(params Object[] vals) {
      Class_context_all output = new Class_context_all();
      return output;
    }

    public override Vx.Translation.All.Func_context_all vx_copy(params Object[] vals) {
      Class_context_all output = new Class_context_all();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translation/all", // pkgname
        "context-all", // name
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_context_all;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_context_all;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Translation.All.f_context_all(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translation.All.f_context_all(args);
      return output;
    }

    public Vx.Core.Type_context vx_context_all(Vx.Core.Type_anylist args) {
      return Vx.Translation.All.f_context_all(args);
    }

  }

  public static Func_context_all e_context_all = new Vx.Translation.All.Class_context_all();
  public static Func_context_all t_context_all = new Vx.Translation.All.Class_context_all();

  public static Vx.Core.Type_context f_context_all(Vx.Core.Type_anylist args) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Core.f_new(
      Vx.Core.t_context,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":session"),
        Vx.Core.f_new(
          Vx.Core.t_session,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":translation"),
            Vx.Translation.En.f_translation_en(),
            Vx.Core.vx_new_string(":translationmap"),
            Vx.Translation.All.f_translationmap_all()
          )
        )
      )
    );
    return output;
  }

  /**
   * @function translationmap_all
   * Returns a translationmap with all translations.
   * @return {translationmap}
   * (func translationmap-all)
   */
  public interface Func_translationmap_all : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_translationmap vx_translationmap_all();
  }

  public class Class_translationmap_all : Vx.Core.Class_base, Func_translationmap_all {

    public override Vx.Translation.All.Func_translationmap_all vx_new(params Object[] vals) {
      Class_translationmap_all output = new Class_translationmap_all();
      return output;
    }

    public override Vx.Translation.All.Func_translationmap_all vx_copy(params Object[] vals) {
      Class_translationmap_all output = new Class_translationmap_all();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translation/all", // pkgname
        "translationmap-all", // name
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
      return e_translationmap_all;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translationmap_all;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Translation.All.f_translationmap_all();
      return output;
    }

    public Vx.Core.Type_translationmap vx_translationmap_all() {
      return Vx.Translation.All.f_translationmap_all();
    }

  }

  public static Func_translationmap_all e_translationmap_all = new Vx.Translation.All.Class_translationmap_all();
  public static Func_translationmap_all t_translationmap_all = new Vx.Translation.All.Class_translationmap_all();

  public static Vx.Core.Type_translationmap f_translationmap_all() {
    Vx.Core.Type_translationmap output = Vx.Core.e_translationmap;
    output = Vx.Translate.f_translationmap_from_translations(
      Vx.Core.vx_new(Vx.Core.t_translationlist,
        Vx.Translation.En.f_translation_en(),
        Vx.Translation.Es.f_translation_es()
      )
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapfunc.put("context-all", Vx.Translation.All.t_context_all);
    mapfunc.put("translationmap-all", Vx.Translation.All.t_translationmap_all);
    Vx.Core.vx_global_package_set("vx/translation/all", maptype, mapconst, mapfunc);
    }
  }

}
