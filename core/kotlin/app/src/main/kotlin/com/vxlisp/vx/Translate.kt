package com.vxlisp.vx

import com.vxlisp.vx.data.*

object vx_translate {


  interface Func_session_from_session_name : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_session_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_session
  }

  class Class_session_from_session_name : vx_core.Class_base, Func_session_from_session_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_name = vx_translate.Class_session_from_session_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_name = vx_translate.Class_session_from_session_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
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
      var output : vx_core.Type_any = vx_translate.e_session_from_session_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_session_from_session_name
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var session : vx_core.Type_session = vx_core.f_any_from_any(vx_core.t_session, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_translate.f_session_from_session_name(session, name)
      return output
    }

    override fun vx_session_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_session {
      var output : vx_core.Type_session = vx_translate.f_session_from_session_name(session, name)
      return output
    }

  }

  val e_session_from_session_name : vx_translate.Func_session_from_session_name = vx_translate.Class_session_from_session_name()
  val t_session_from_session_name : vx_translate.Func_session_from_session_name = vx_translate.Class_session_from_session_name()

  fun f_session_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_session {
    var output : vx_core.Type_session = vx_core.e_session
    output = vx_core.f_copy(
      session,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":translation"),
        vx_translate.f_translation_from_session_name(
          session,
          name
        )
      )
    )
    return output
  }


  interface Func_session_from_session_translation : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_session_from_session_translation(session : vx_core.Type_session, translation : vx_core.Type_translation) : vx_core.Type_session
  }

  class Class_session_from_session_translation : vx_core.Class_base, Func_session_from_session_translation {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_translation = vx_translate.Class_session_from_session_translation()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_translation = vx_translate.Class_session_from_session_translation()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
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
      var output : vx_core.Type_any = vx_translate.e_session_from_session_translation
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_session_from_session_translation
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var session : vx_core.Type_session = vx_core.f_any_from_any(vx_core.t_session, arglist.vx_any(vx_core.vx_new_int(0)))
      var translation : vx_core.Type_translation = vx_core.f_any_from_any(vx_core.t_translation, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_translate.f_session_from_session_translation(session, translation)
      return output
    }

    override fun vx_session_from_session_translation(session : vx_core.Type_session, translation : vx_core.Type_translation) : vx_core.Type_session {
      var output : vx_core.Type_session = vx_translate.f_session_from_session_translation(session, translation)
      return output
    }

  }

  val e_session_from_session_translation : vx_translate.Func_session_from_session_translation = vx_translate.Class_session_from_session_translation()
  val t_session_from_session_translation : vx_translate.Func_session_from_session_translation = vx_translate.Class_session_from_session_translation()

  fun f_session_from_session_translation(session : vx_core.Type_session, translation : vx_core.Type_translation) : vx_core.Type_session {
    var output : vx_core.Type_session = vx_core.e_session
    output = vx_core.f_copy(
      session,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":translation"),
        translation
      )
    )
    return output
  }


  interface Func_session_from_session_translationmap_name : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_session_from_session_translationmap_name(session : vx_core.Type_session, translationmap : vx_core.Type_translationmap, name : vx_core.Type_string) : vx_core.Type_session
  }

  class Class_session_from_session_translationmap_name : vx_core.Class_base, Func_session_from_session_translationmap_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_translationmap_name = vx_translate.Class_session_from_session_translationmap_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_session_from_session_translationmap_name = vx_translate.Class_session_from_session_translationmap_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
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
      var output : vx_core.Type_any = vx_translate.e_session_from_session_translationmap_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_session_from_session_translationmap_name
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var session : vx_core.Type_session = vx_core.f_any_from_any(vx_core.t_session, arglist.vx_any(vx_core.vx_new_int(0)))
      var translationmap : vx_core.Type_translationmap = vx_core.f_any_from_any(vx_core.t_translationmap, arglist.vx_any(vx_core.vx_new_int(1)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_translate.f_session_from_session_translationmap_name(session, translationmap, name)
      return output
    }

    override fun vx_session_from_session_translationmap_name(session : vx_core.Type_session, translationmap : vx_core.Type_translationmap, name : vx_core.Type_string) : vx_core.Type_session {
      var output : vx_core.Type_session = vx_translate.f_session_from_session_translationmap_name(session, translationmap, name)
      return output
    }

  }

  val e_session_from_session_translationmap_name : vx_translate.Func_session_from_session_translationmap_name = vx_translate.Class_session_from_session_translationmap_name()
  val t_session_from_session_translationmap_name : vx_translate.Func_session_from_session_translationmap_name = vx_translate.Class_session_from_session_translationmap_name()

  fun f_session_from_session_translationmap_name(session : vx_core.Type_session, translationmap : vx_core.Type_translationmap, name : vx_core.Type_string) : vx_core.Type_session {
    var output : vx_core.Type_session = vx_core.e_session
    output = vx_core.f_copy(
      session,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":translation"),
        vx_core.f_any_from_map(
          vx_core.t_anylist,
          translationmap,
          name
        ),
        vx_core.vx_new_string(":translationmap"),
        translationmap
      )
    )
    return output
  }


  interface Func_translate : vx_core.Func_any_from_any_context {
    fun vx_translate(context : vx_core.Type_context, text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_translate : vx_core.Class_base, Func_translate {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate = vx_translate.Class_translate()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate = vx_translate.Class_translate()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      var output : vx_core.Type_any = vx_translate.e_translate
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translate
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_translate.f_translate(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translate.f_translate(context, text)
      return output
    }

    override fun vx_translate(context : vx_core.Type_context, text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_translate.f_translate(context, text)
      return output
    }

  }

  val e_translate : vx_translate.Func_translate = vx_translate.Class_translate()
  val t_translate : vx_translate.Func_translate = vx_translate.Class_translate()

  fun f_translate(context : vx_core.Type_context, text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_translate.f_translate_from_translation_string(
      vx_translate.f_translation_from_context(
        context
      ),
      text
    )
    return output
  }


  interface Func_translate_1 : vx_core.Func_any_from_any_context {
    fun vx_translate_1(context : vx_core.Type_context, msg : vx_core.Type_msg) : vx_core.Type_string
  }

  class Class_translate_1 : vx_core.Class_base, Func_translate_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_1 = vx_translate.Class_translate_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_1 = vx_translate.Class_translate_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      var output : vx_core.Type_any = vx_translate.e_translate_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translate_1
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_msg = value as vx_core.Type_msg
      var outputval : vx_core.Type_any = vx_translate.f_translate_1(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var msg : vx_core.Type_msg = vx_core.f_any_from_any(vx_core.t_msg, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translate.f_translate_1(context, msg)
      return output
    }

    override fun vx_translate_1(context : vx_core.Type_context, msg : vx_core.Type_msg) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_translate.f_translate_1(context, msg)
      return output
    }

  }

  val e_translate_1 : vx_translate.Func_translate_1 = vx_translate.Class_translate_1()
  val t_translate_1 : vx_translate.Func_translate_1 = vx_translate.Class_translate_1()

  fun f_translate_1(context : vx_core.Type_context, msg : vx_core.Type_msg) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var path : vx_core.Type_string = msg.path()
        var code : vx_core.Type_string = msg.code()
        var text : vx_core.Type_string = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("!"),
            path,
            vx_core.vx_new_string(" "),
            code
          )
        )
        var output_1 : vx_core.Type_any = vx_translate.f_translate(
          context,
          text
        )
        output_1
      })
    )
    return output
  }


  interface Func_translate_from_translation_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translate_from_translation_string(translation : vx_core.Type_translation, text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_translate_from_translation_string : vx_core.Class_base, Func_translate_from_translation_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_from_translation_string = vx_translate.Class_translate_from_translation_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_from_translation_string = vx_translate.Class_translate_from_translation_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      var output : vx_core.Type_any = vx_translate.e_translate_from_translation_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translate_from_translation_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var translation : vx_core.Type_translation = vx_core.f_any_from_any(vx_core.t_translation, arglist.vx_any(vx_core.vx_new_int(0)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_translate.f_translate_from_translation_string(translation, text)
      return output
    }

    override fun vx_translate_from_translation_string(translation : vx_core.Type_translation, text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_translate.f_translate_from_translation_string(translation, text)
      return output
    }

  }

  val e_translate_from_translation_string : vx_translate.Func_translate_from_translation_string = vx_translate.Class_translate_from_translation_string()
  val t_translate_from_translation_string : vx_translate.Func_translate_from_translation_string = vx_translate.Class_translate_from_translation_string()

  fun f_translate_from_translation_string(translation : vx_core.Type_translation, text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_1(
      vx_core.t_string,
      vx_core.f_is_empty_1(
        translation
      ),
      text,
      vx_core.f_let(
        vx_core.t_string,
        vx_core.t_any_from_func.vx_fn_new({ ->
          var wordmap : vx_core.Type_stringmap = translation.wordmap()
          var xlate : vx_core.Type_string = vx_core.f_any_from_map(
            vx_core.t_string,
            wordmap,
            text
          )
          var output_1 : vx_core.Type_any = vx_core.f_if_1(
            vx_core.t_string,
            vx_core.f_is_empty(
              xlate
            ),
            text,
            xlate
          )
          output_1
        })
      )
    )
    return output
  }


  interface Func_translate_from_translationmap_name_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translate_from_translationmap_name_string(translationmap : vx_core.Type_translationmap, name : vx_core.Type_string, text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_translate_from_translationmap_name_string : vx_core.Class_base, Func_translate_from_translationmap_name_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_from_translationmap_name_string = vx_translate.Class_translate_from_translationmap_name_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translate_from_translationmap_name_string = vx_translate.Class_translate_from_translationmap_name_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      var output : vx_core.Type_any = vx_translate.e_translate_from_translationmap_name_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translate_from_translationmap_name_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var translationmap : vx_core.Type_translationmap = vx_core.f_any_from_any(vx_core.t_translationmap, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_translate.f_translate_from_translationmap_name_string(translationmap, name, text)
      return output
    }

    override fun vx_translate_from_translationmap_name_string(translationmap : vx_core.Type_translationmap, name : vx_core.Type_string, text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_translate.f_translate_from_translationmap_name_string(translationmap, name, text)
      return output
    }

  }

  val e_translate_from_translationmap_name_string : vx_translate.Func_translate_from_translationmap_name_string = vx_translate.Class_translate_from_translationmap_name_string()
  val t_translate_from_translationmap_name_string : vx_translate.Func_translate_from_translationmap_name_string = vx_translate.Class_translate_from_translationmap_name_string()

  fun f_translate_from_translationmap_name_string(translationmap : vx_core.Type_translationmap, name : vx_core.Type_string, text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var translation : vx_core.Type_translation = vx_core.f_any_from_map(
          vx_core.t_translation,
          translationmap,
          name
        )
        var output_1 : vx_core.Type_any = vx_translate.f_translate_from_translation_string(
          translation,
          text
        )
        output_1
      })
    )
    return output
  }


  interface Func_translation_load_session : vx_core.Func_any_from_any_context {
    fun vx_translation_load_session(context : vx_core.Type_context, translation : vx_core.Type_translation) : vx_core.Type_translation
  }

  class Class_translation_load_session : vx_core.Class_base, Func_translation_load_session {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_load_session = vx_translate.Class_translation_load_session()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_load_session = vx_translate.Class_translation_load_session()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
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
      var output : vx_core.Type_any = vx_translate.e_translation_load_session
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translation_load_session
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_translation = value as vx_core.Type_translation
      var outputval : vx_core.Type_any = vx_translate.f_translation_load_session(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var translation : vx_core.Type_translation = vx_core.f_any_from_any(vx_core.t_translation, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translate.f_translation_load_session(context, translation)
      return output
    }

    override fun vx_translation_load_session(context : vx_core.Type_context, translation : vx_core.Type_translation) : vx_core.Type_translation {
      var output : vx_core.Type_translation = vx_translate.f_translation_load_session(context, translation)
      return output
    }

  }

  val e_translation_load_session : vx_translate.Func_translation_load_session = vx_translate.Class_translation_load_session()
  val t_translation_load_session : vx_translate.Func_translation_load_session = vx_translate.Class_translation_load_session()

  fun f_translation_load_session(context : vx_core.Type_context, translation : vx_core.Type_translation) : vx_core.Type_translation {
    var output : vx_core.Type_translation = vx_core.e_translation
    return output
  }


  interface Func_translation_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translation_from_context(context : vx_core.Type_context) : vx_core.Type_translation
  }

  class Class_translation_from_context : vx_core.Class_base, Func_translation_from_context {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_from_context = vx_translate.Class_translation_from_context()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_from_context = vx_translate.Class_translation_from_context()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
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
      var output : vx_core.Type_any = vx_translate.e_translation_from_context
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translation_from_context
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translate.f_translation_from_context(context)
      return output
    }

    override fun vx_translation_from_context(context : vx_core.Type_context) : vx_core.Type_translation {
      var output : vx_core.Type_translation = vx_translate.f_translation_from_context(context)
      return output
    }

  }

  val e_translation_from_context : vx_translate.Func_translation_from_context = vx_translate.Class_translation_from_context()
  val t_translation_from_context : vx_translate.Func_translation_from_context = vx_translate.Class_translation_from_context()

  fun f_translation_from_context(context : vx_core.Type_context) : vx_core.Type_translation {
    var output : vx_core.Type_translation = vx_core.e_translation
    output = vx_core.f_session_from_context(
      context
    ).translation()
    return output
  }


  interface Func_translation_from_session_name : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_translation_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_translation
  }

  class Class_translation_from_session_name : vx_core.Class_base, Func_translation_from_session_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_from_session_name = vx_translate.Class_translation_from_session_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translation_from_session_name = vx_translate.Class_translation_from_session_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
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
      var output : vx_core.Type_any = vx_translate.e_translation_from_session_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translation_from_session_name
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var session : vx_core.Type_session = vx_core.f_any_from_any(vx_core.t_session, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_translate.f_translation_from_session_name(session, name)
      return output
    }

    override fun vx_translation_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_translation {
      var output : vx_core.Type_translation = vx_translate.f_translation_from_session_name(session, name)
      return output
    }

  }

  val e_translation_from_session_name : vx_translate.Func_translation_from_session_name = vx_translate.Class_translation_from_session_name()
  val t_translation_from_session_name : vx_translate.Func_translation_from_session_name = vx_translate.Class_translation_from_session_name()

  fun f_translation_from_session_name(session : vx_core.Type_session, name : vx_core.Type_string) : vx_core.Type_translation {
    var output : vx_core.Type_translation = vx_core.e_translation
    output = vx_core.f_let(
      vx_core.t_translation,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var translationmap : vx_core.Type_translationmap = session.translationmap()
        var output_1 : vx_core.Type_any = vx_core.f_any_from_map(
          vx_core.t_translation,
          translationmap,
          name
        )
        output_1
      })
    )
    return output
  }


  interface Func_translationmap_from_translations : vx_core.Func_any_from_any {
    fun vx_translationmap_from_translations(translations : vx_core.Type_translationlist) : vx_core.Type_translationmap
  }

  class Class_translationmap_from_translations : vx_core.Class_base, Func_translationmap_from_translations {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translationmap_from_translations = vx_translate.Class_translationmap_from_translations()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_translate.Class_translationmap_from_translations = vx_translate.Class_translationmap_from_translations()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
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
      var output : vx_core.Type_any = vx_translate.e_translationmap_from_translations
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_translate.t_translationmap_from_translations
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_translationlist = value as vx_core.Type_translationlist
      var outputval : vx_core.Type_any = vx_translate.f_translationmap_from_translations(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var translations : vx_core.Type_translationlist = vx_core.f_any_from_any(vx_core.t_translationlist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_translate.f_translationmap_from_translations(translations)
      return output
    }

    override fun vx_translationmap_from_translations(translations : vx_core.Type_translationlist) : vx_core.Type_translationmap {
      var output : vx_core.Type_translationmap = vx_translate.f_translationmap_from_translations(translations)
      return output
    }

  }

  val e_translationmap_from_translations : vx_translate.Func_translationmap_from_translations = vx_translate.Class_translationmap_from_translations()
  val t_translationmap_from_translations : vx_translate.Func_translationmap_from_translations = vx_translate.Class_translationmap_from_translations()

  fun f_translationmap_from_translations(translations : vx_core.Type_translationlist) : vx_core.Type_translationmap {
    var output : vx_core.Type_translationmap = vx_core.e_translationmap
    output = vx_core.f_map_from_list(
      vx_core.t_translationmap,
      translations,
      vx_core.t_any_from_any.vx_fn_new({translation_any : vx_core.Type_any ->
        var translation : vx_core.Type_translation = vx_core.f_any_from_any(vx_core.t_translation, translation_any)
        var output_1 : vx_core.Type_any = translation.name()
        output_1
      })
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("session<-session-name", vx_translate.t_session_from_session_name)
    mapfunc.put("session<-session-translation", vx_translate.t_session_from_session_translation)
    mapfunc.put("session<-session-translationmap-name", vx_translate.t_session_from_session_translationmap_name)
    mapfunc.put("translate", vx_translate.t_translate)
    mapfunc.put("translate_1", vx_translate.t_translate_1)
    mapfunc.put("translate<-translation-string", vx_translate.t_translate_from_translation_string)
    mapfunc.put("translate<-translationmap-name-string", vx_translate.t_translate_from_translationmap_name_string)
    mapfunc.put("translation-load-session", vx_translate.t_translation_load_session)
    mapfunc.put("translation<-context", vx_translate.t_translation_from_context)
    mapfunc.put("translation<-session-name", vx_translate.t_translation_from_session_name)
    mapfunc.put("translationmap<-translations", vx_translate.t_translationmap_from_translations)
    vx_core.vx_global_package_set("vx/translate", maptype, mapconst, mapfunc)
  }

}
