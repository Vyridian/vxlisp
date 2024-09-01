package com.vxlisp.vx.translation

import com.vxlisp.vx.*
import com.vxlisp.vx.data.*

object vx_translation_en {


  interface Func_context_en : vx_core.Func_any_from_any {
    fun vx_context_en(args : vx_core.Type_anylist) : vx_core.Type_context
  }

  class Class_context_en : vx_core.Class_base, Func_context_en {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_context_en = vx_translation_en.Class_context_en()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_context_en = vx_translation_en.Class_context_en()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/en", // pkgname
        "context-en", // name
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
      var output : vx_core.Type_any = vx_translation_en.e_context_en
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_en.t_context_en
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_translation_en.f_context_en(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var args : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translation_en.f_context_en(args)
      return output
    }

    override fun vx_context_en(args : vx_core.Type_anylist) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_translation_en.f_context_en(args)
      return output
    }

  }

  val e_context_en : vx_translation_en.Func_context_en = vx_translation_en.Class_context_en()
  val t_context_en : vx_translation_en.Func_context_en = vx_translation_en.Class_context_en()

  fun f_context_en(args : vx_core.Type_anylist) : vx_core.Type_context {
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
            vx_translation_en.f_translation_en()
          )
        )
      )
    )
    return output
  }


  interface Func_context_test : vx_core.Func_any_from_any {
    fun vx_context_test(args : vx_core.Type_anylist) : vx_core.Type_context
  }

  class Class_context_test : vx_core.Class_base, Func_context_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_context_test = vx_translation_en.Class_context_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_context_test = vx_translation_en.Class_context_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/en", // pkgname
        "context-test", // name
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
      var output : vx_core.Type_any = vx_translation_en.e_context_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_en.t_context_test
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_translation_en.f_context_test(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var args : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translation_en.f_context_test(args)
      return output
    }

    override fun vx_context_test(args : vx_core.Type_anylist) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_translation_en.f_context_test(args)
      return output
    }

  }

  val e_context_test : vx_translation_en.Func_context_test = vx_translation_en.Class_context_test()
  val t_context_test : vx_translation_en.Func_context_test = vx_translation_en.Class_context_test()

  fun f_context_test(args : vx_core.Type_anylist) : vx_core.Type_context {
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
            vx_core.vx_new_string(":user"),
            vx_core.f_new(
              vx_core.t_user,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":security"),
                vx_translation_en.f_securitydata_test()
              )
            )
          )
        )
      )
    )
    return output
  }


  interface Func_securitydata_test : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_securitydata_test() : vx_core.Type_security
  }

  class Class_securitydata_test : vx_core.Class_base, Func_securitydata_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_securitydata_test = vx_translation_en.Class_securitydata_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_securitydata_test = vx_translation_en.Class_securitydata_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/en", // pkgname
        "securitydata-test", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      var output : vx_core.Type_any = vx_translation_en.e_securitydata_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_en.t_securitydata_test
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_en.f_securitydata_test()
      return output
    }

    override fun vx_securitydata_test() : vx_core.Type_security {
      var output : vx_core.Type_security = vx_translation_en.f_securitydata_test()
      return output
    }

  }

  val e_securitydata_test : vx_translation_en.Func_securitydata_test = vx_translation_en.Class_securitydata_test()
  val t_securitydata_test : vx_translation_en.Func_securitydata_test = vx_translation_en.Class_securitydata_test()

  fun f_securitydata_test() : vx_core.Type_security {
    var output : vx_core.Type_security = vx_core.e_security
    output = vx_core.f_new(
      vx_core.t_security,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":allowfuncs"),
        vx_core.f_new(
          vx_core.t_funclist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_data_file.t_boolean_write_from_file_any,
            vx_data_file.t_boolean_write_from_file_string,
            vx_data_file.t_file_read_from_file,
            vx_data_file.t_string_read_from_file
          )
        )
      )
    )
    return output
  }


  interface Func_translation_en : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translation_en() : vx_core.Type_translation
  }

  class Class_translation_en : vx_core.Class_base, Func_translation_en {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_translation_en = vx_translation_en.Class_translation_en()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_translation_en = vx_translation_en.Class_translation_en()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/en", // pkgname
        "translation-en", // name
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
      var output : vx_core.Type_any = vx_translation_en.e_translation_en
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_en.t_translation_en
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_en.f_translation_en()
      return output
    }

    override fun vx_translation_en() : vx_core.Type_translation {
      var output : vx_core.Type_translation = vx_translation_en.f_translation_en()
      return output
    }

  }

  val e_translation_en : vx_translation_en.Func_translation_en = vx_translation_en.Class_translation_en()
  val t_translation_en : vx_translation_en.Func_translation_en = vx_translation_en.Class_translation_en()

  fun f_translation_en() : vx_core.Type_translation {
    var output : vx_core.Type_translation = vx_core.e_translation
    output = vx_core.f_new(
      vx_core.t_translation,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":name"),
        vx_core.vx_new_string("en"),
        vx_core.vx_new_string(":wordmap"),
        vx_translation_en.f_words()
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
      val output : vx_translation_en.Class_words = vx_translation_en.Class_words()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translation_en.Class_words = vx_translation_en.Class_words()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translation/en", // pkgname
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
      var output : vx_core.Type_any = vx_translation_en.e_words
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translation_en.t_words
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_translation_en.f_words()
      return output
    }

    override fun vx_words() : vx_core.Type_stringmap {
      var output : vx_core.Type_stringmap = vx_translation_en.f_words()
      return output
    }

  }

  val e_words : vx_translation_en.Func_words = vx_translation_en.Class_words()
  val t_words : vx_translation_en.Func_words = vx_translation_en.Class_words()

  fun f_words() : vx_core.Type_stringmap {
    var output : vx_core.Type_stringmap = vx_core.e_stringmap
    output = vx_core.f_new(
      vx_core.t_stringmap,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string("Hello"),
        vx_core.vx_new_string("Hello"),
        vx_core.vx_new_string("World"),
        vx_core.vx_new_string("World"),
        vx_core.vx_new_string("!vx/core/func exception"),
        vx_core.vx_new_string("Exception in Function"),
        vx_core.vx_new_string("!vx/core/func permissiondenied"),
        vx_core.vx_new_string("Permission Denied to Function"),
        vx_core.vx_new_string("!vx/repl/repl/repl<-string-argmap repltypenotfound"),
        vx_core.vx_new_string("Repl Type Not Found")
      )
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("context-en", vx_translation_en.t_context_en)
    mapfunc.put("context-test", vx_translation_en.t_context_test)
    mapfunc.put("securitydata-test", vx_translation_en.t_securitydata_test)
    mapfunc.put("translation-en", vx_translation_en.t_translation_en)
    mapfunc.put("words", vx_translation_en.t_words)
    vx_core.vx_global_package_set("vx/translation/en", maptype, mapconst, mapfunc)
  }

}
