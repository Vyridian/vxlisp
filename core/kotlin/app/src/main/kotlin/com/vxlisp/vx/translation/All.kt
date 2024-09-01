package com.vxlisp.vx.translation

import com.vxlisp.vx.*

object vx_translation_all {


  interface Func_context_all : vx_core.Func_any_from_any {
    fun vx_context_all(args : vx_core.Type_anylist) : vx_core.Type_context
  }

  class Class_context_all : vx_core.Class_base, Func_context_all {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_all.Class_context_all = vx_translation_all.Class_context_all()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_all.Class_context_all = vx_translation_all.Class_context_all()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/all", // pkgname
        "context-all", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "context", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_all.e_context_all
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_all.t_context_all
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_translation_all.f_context_all(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var args : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translation_all.f_context_all(args)
      return output
    }

    override fun vx_context_all(args : vx_core.Type_anylist) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_translation_all.f_context_all(args)
      return output
    }

  }

  val e_context_all : vx_translation_all.Func_context_all = vx_translation_all.Class_context_all()
  val t_context_all : vx_translation_all.Func_context_all = vx_translation_all.Class_context_all()

  fun f_context_all(args : vx_core.Type_anylist) : vx_core.Type_context {
    var output : vx_core.Type_context = vx_core.e_context
    output = vx_core.f_new(
      vx_core.t_context,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":session"),
        vx_core.f_new(
          vx_core.t_session,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":translation"),
            vx_translation_en.f_translation_en(),
            vx_core.vx_new_string(":translationmap"),
            vx_translation_all.f_translationmap_all()
          )
        )
      )
    )
    return output
  }


  interface Func_translationmap_all : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translationmap_all() : vx_core.Type_translationmap
  }

  class Class_translationmap_all : vx_core.Class_base, Func_translationmap_all {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_all.Class_translationmap_all = vx_translation_all.Class_translationmap_all()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_all.Class_translationmap_all = vx_translation_all.Class_translationmap_all()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/all", // pkgname
        "translationmap-all", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "translationmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_translation), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_all.e_translationmap_all
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_all.t_translationmap_all
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_all.f_translationmap_all()
      return output
    }

    override fun vx_translationmap_all() : vx_core.Type_translationmap {
      var output : vx_core.Type_translationmap = vx_translation_all.f_translationmap_all()
      return output
    }

  }

  val e_translationmap_all : vx_translation_all.Func_translationmap_all = vx_translation_all.Class_translationmap_all()
  val t_translationmap_all : vx_translation_all.Func_translationmap_all = vx_translation_all.Class_translationmap_all()

  fun f_translationmap_all() : vx_core.Type_translationmap {
    var output : vx_core.Type_translationmap = vx_core.e_translationmap
    output = vx_translate.f_translationmap_from_translations(
      vx_core.vx_new(
        vx_core.t_translationlist,
        vx_translation_en.f_translation_en(),
        vx_translation_es.f_translation_es()
      )
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("context-all", vx_translation_all.t_context_all)
    mapfunc.put("translationmap-all", vx_translation_all.t_translationmap_all)
    vx_core.vx_global_package_set("vx/translation/all", maptype, mapconst, mapfunc)
  }

}
