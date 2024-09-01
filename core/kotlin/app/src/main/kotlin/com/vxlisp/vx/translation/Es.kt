package com.vxlisp.vx.translation

import com.vxlisp.vx.*

object vx_translation_es {


  interface Func_translation_es : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translation_es() : vx_core.Type_translation
  }

  class Class_translation_es : vx_core.Class_base, Func_translation_es {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_es.Class_translation_es = vx_translation_es.Class_translation_es()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_es.Class_translation_es = vx_translation_es.Class_translation_es()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/es", // pkgname
        "translation-es", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
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
      var output : vx_core.Type_any = vx_translation_es.e_translation_es
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_es.t_translation_es
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_es.f_translation_es()
      return output
    }

    override fun vx_translation_es() : vx_core.Type_translation {
      var output : vx_core.Type_translation = vx_translation_es.f_translation_es()
      return output
    }

  }

  val e_translation_es : vx_translation_es.Func_translation_es = vx_translation_es.Class_translation_es()
  val t_translation_es : vx_translation_es.Func_translation_es = vx_translation_es.Class_translation_es()

  fun f_translation_es() : vx_core.Type_translation {
    var output : vx_core.Type_translation = vx_core.e_translation
    output = vx_core.f_new(
      vx_core.t_translation,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":name"),
        vx_core.vx_new_string("es"),
        vx_core.vx_new_string(":wordmap"),
        vx_translation_es.f_words()
      )
    )
    return output
  }


  interface Func_words : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_words() : vx_core.Type_stringmap
  }

  class Class_words : vx_core.Class_base, Func_words {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_es.Class_words = vx_translation_es.Class_words()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_es.Class_words = vx_translation_es.Class_words()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/es", // pkgname
        "words", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
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
      var output : vx_core.Type_any = vx_translation_es.e_words
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_es.t_words
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_es.f_words()
      return output
    }

    override fun vx_words() : vx_core.Type_stringmap {
      var output : vx_core.Type_stringmap = vx_translation_es.f_words()
      return output
    }

  }

  val e_words : vx_translation_es.Func_words = vx_translation_es.Class_words()
  val t_words : vx_translation_es.Func_words = vx_translation_es.Class_words()

  fun f_words() : vx_core.Type_stringmap {
    var output : vx_core.Type_stringmap = vx_core.e_stringmap
    output = vx_core.f_new(
      vx_core.t_stringmap,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string("Hello"),
        vx_core.vx_new_string("Hola"),
        vx_core.vx_new_string("World"),
        vx_core.vx_new_string("Mundo")
      )
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("translation-es", vx_translation_es.t_translation_es)
    mapfunc.put("words", vx_translation_es.t_words)
    vx_core.vx_global_package_set("vx/translation/es", maptype, mapconst, mapfunc)
  }

}
