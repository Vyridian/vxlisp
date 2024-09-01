package com.vxlisp.vx.web

import java.util.concurrent.CompletableFuture
import com.vxlisp.vx.*
import com.vxlisp.vx.ui.*

object vx_web_htmldoc {


  interface Func_boolean_print_from_id_stylesheettext : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_print_from_id_stylesheettext(id : vx_core.Type_string, stylesheettext : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_print_from_id_stylesheettext : vx_core.Class_base, Func_boolean_print_from_id_stylesheettext {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext = vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext = vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-print<-id-stylesheettext", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_print_from_id_stylesheettext
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_print_from_id_stylesheettext
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var stylesheettext : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_htmldoc.f_boolean_print_from_id_stylesheettext(id, stylesheettext)
      return output
    }

    override fun vx_boolean_print_from_id_stylesheettext(id : vx_core.Type_string, stylesheettext : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_print_from_id_stylesheettext(id, stylesheettext)
      return output
    }

  }

  val e_boolean_print_from_id_stylesheettext : vx_web_htmldoc.Func_boolean_print_from_id_stylesheettext = vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext()
  val t_boolean_print_from_id_stylesheettext : vx_web_htmldoc.Func_boolean_print_from_id_stylesheettext = vx_web_htmldoc.Class_boolean_print_from_id_stylesheettext()

  fun f_boolean_print_from_id_stylesheettext(id : vx_core.Type_string, stylesheettext : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_remove_from_id : vx_core.Func_any_from_any {
    fun vx_boolean_remove_from_id(id : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_remove_from_id : vx_core.Class_base, Func_boolean_remove_from_id {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_remove_from_id = vx_web_htmldoc.Class_boolean_remove_from_id()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_remove_from_id = vx_web_htmldoc.Class_boolean_remove_from_id()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-remove<-id", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_remove_from_id
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_remove_from_id
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_htmldoc.f_boolean_remove_from_id(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_boolean_remove_from_id(id)
      return output
    }

    override fun vx_boolean_remove_from_id(id : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_remove_from_id(id)
      return output
    }

  }

  val e_boolean_remove_from_id : vx_web_htmldoc.Func_boolean_remove_from_id = vx_web_htmldoc.Class_boolean_remove_from_id()
  val t_boolean_remove_from_id : vx_web_htmldoc.Func_boolean_remove_from_id = vx_web_htmldoc.Class_boolean_remove_from_id()

  fun f_boolean_remove_from_id(id : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_replace_from_id_htmltext : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_replace_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_replace_from_id_htmltext : vx_core.Class_base, Func_boolean_replace_from_id_htmltext {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_replace_from_id_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_htmltext()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_replace_from_id_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_htmltext()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_replace_from_id_htmltext
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_replace_from_id_htmltext
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var htmltext : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext)
      return output
    }

    override fun vx_boolean_replace_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext)
      return output
    }

  }

  val e_boolean_replace_from_id_htmltext : vx_web_htmldoc.Func_boolean_replace_from_id_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_htmltext()
  val t_boolean_replace_from_id_htmltext : vx_web_htmldoc.Func_boolean_replace_from_id_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_htmltext()

  fun f_boolean_replace_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_replace_from_id_parent_htmltext : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_replace_from_id_parent_htmltext(id : vx_core.Type_string, parent : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_replace_from_id_parent_htmltext : vx_core.Class_base, Func_boolean_replace_from_id_parent_htmltext {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-parent-htmltext", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_replace_from_id_parent_htmltext
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_replace_from_id_parent_htmltext
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var htmltext : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_web_htmldoc.f_boolean_replace_from_id_parent_htmltext(id, parent, htmltext)
      return output
    }

    override fun vx_boolean_replace_from_id_parent_htmltext(id : vx_core.Type_string, parent : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_replace_from_id_parent_htmltext(id, parent, htmltext)
      return output
    }

  }

  val e_boolean_replace_from_id_parent_htmltext : vx_web_htmldoc.Func_boolean_replace_from_id_parent_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext()
  val t_boolean_replace_from_id_parent_htmltext : vx_web_htmldoc.Func_boolean_replace_from_id_parent_htmltext = vx_web_htmldoc.Class_boolean_replace_from_id_parent_htmltext()

  fun f_boolean_replace_from_id_parent_htmltext(id : vx_core.Type_string, parent : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_write_stylesheet_from_string : vx_core.Func_any_from_any_async {
    fun vx_boolean_write_stylesheet_from_string(text : vx_core.Type_string) : CompletableFuture<vx_core.Type_boolean>
  }

  class Class_boolean_write_stylesheet_from_string : vx_core.Class_base, Func_boolean_write_stylesheet_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_stylesheet_from_string = vx_web_htmldoc.Class_boolean_write_stylesheet_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_stylesheet_from_string = vx_web_htmldoc.Class_boolean_write_stylesheet_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write-stylesheet<-string", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_write_stylesheet_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_write_stylesheet_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value)
      var future : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_stylesheet_from_string(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_stylesheet_from_string(text)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_boolean_write_stylesheet_from_string(text : vx_core.Type_string) : CompletableFuture<vx_core.Type_boolean> {
      var output : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_stylesheet_from_string(text)
      return output
    }

  }

  val e_boolean_write_stylesheet_from_string : vx_web_htmldoc.Func_boolean_write_stylesheet_from_string = vx_web_htmldoc.Class_boolean_write_stylesheet_from_string()
  val t_boolean_write_stylesheet_from_string : vx_web_htmldoc.Func_boolean_write_stylesheet_from_string = vx_web_htmldoc.Class_boolean_write_stylesheet_from_string()

  fun f_boolean_write_stylesheet_from_string(text : vx_core.Type_string) : CompletableFuture<vx_core.Type_boolean> {
    var output : CompletableFuture<vx_core.Type_boolean> = vx_core.vx_async_new_from_value(vx_core.e_boolean)
    return output
  }


  interface Func_boolean_write_from_id_attribute_value : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_id_attribute_value(id : vx_core.Type_string, attribute : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_id_attribute_value : vx_core.Class_base, Func_boolean_write_from_id_attribute_value {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_attribute_value = vx_web_htmldoc.Class_boolean_write_from_id_attribute_value()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_attribute_value = vx_web_htmldoc.Class_boolean_write_from_id_attribute_value()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-attribute-value", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_write_from_id_attribute_value
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_write_from_id_attribute_value
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var attribute : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var value : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_web_htmldoc.f_boolean_write_from_id_attribute_value(id, attribute, value)
      return output
    }

    override fun vx_boolean_write_from_id_attribute_value(id : vx_core.Type_string, attribute : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_write_from_id_attribute_value(id, attribute, value)
      return output
    }

  }

  val e_boolean_write_from_id_attribute_value : vx_web_htmldoc.Func_boolean_write_from_id_attribute_value = vx_web_htmldoc.Class_boolean_write_from_id_attribute_value()
  val t_boolean_write_from_id_attribute_value : vx_web_htmldoc.Func_boolean_write_from_id_attribute_value = vx_web_htmldoc.Class_boolean_write_from_id_attribute_value()

  fun f_boolean_write_from_id_attribute_value(id : vx_core.Type_string, attribute : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_write_from_id_htmltext : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_id_htmltext : vx_core.Class_base, Func_boolean_write_from_id_htmltext {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_htmltext = vx_web_htmldoc.Class_boolean_write_from_id_htmltext()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_htmltext = vx_web_htmldoc.Class_boolean_write_from_id_htmltext()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-htmltext", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_write_from_id_htmltext
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_write_from_id_htmltext
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var htmltext : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_htmldoc.f_boolean_write_from_id_htmltext(id, htmltext)
      return output
    }

    override fun vx_boolean_write_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_write_from_id_htmltext(id, htmltext)
      return output
    }

  }

  val e_boolean_write_from_id_htmltext : vx_web_htmldoc.Func_boolean_write_from_id_htmltext = vx_web_htmldoc.Class_boolean_write_from_id_htmltext()
  val t_boolean_write_from_id_htmltext : vx_web_htmldoc.Func_boolean_write_from_id_htmltext = vx_web_htmldoc.Class_boolean_write_from_id_htmltext()

  fun f_boolean_write_from_id_htmltext(id : vx_core.Type_string, htmltext : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_write_from_id_visible : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_id_visible(id : vx_core.Type_string, visible : vx_core.Type_boolean) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_id_visible : vx_core.Class_base, Func_boolean_write_from_id_visible {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_visible = vx_web_htmldoc.Class_boolean_write_from_id_visible()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_id_visible = vx_web_htmldoc.Class_boolean_write_from_id_visible()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-visible", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_write_from_id_visible
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_write_from_id_visible
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var visible : vx_core.Type_boolean = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_htmldoc.f_boolean_write_from_id_visible(id, visible)
      return output
    }

    override fun vx_boolean_write_from_id_visible(id : vx_core.Type_string, visible : vx_core.Type_boolean) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_write_from_id_visible(id, visible)
      return output
    }

  }

  val e_boolean_write_from_id_visible : vx_web_htmldoc.Func_boolean_write_from_id_visible = vx_web_htmldoc.Class_boolean_write_from_id_visible()
  val t_boolean_write_from_id_visible : vx_web_htmldoc.Func_boolean_write_from_id_visible = vx_web_htmldoc.Class_boolean_write_from_id_visible()

  fun f_boolean_write_from_id_visible(id : vx_core.Type_string, visible : vx_core.Type_boolean) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_write_from_stylesheet : vx_core.Func_any_from_any_async {
    fun vx_boolean_write_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : CompletableFuture<vx_core.Type_boolean>
  }

  class Class_boolean_write_from_stylesheet : vx_core.Class_base, Func_boolean_write_from_stylesheet {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_stylesheet = vx_web_htmldoc.Class_boolean_write_from_stylesheet()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_write_from_stylesheet = vx_web_htmldoc.Class_boolean_write_from_stylesheet()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_write_from_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_write_from_stylesheet
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, value)
      var future : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_from_stylesheet(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_from_stylesheet(stylesheet)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_boolean_write_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : CompletableFuture<vx_core.Type_boolean> {
      var output : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_from_stylesheet(stylesheet)
      return output
    }

  }

  val e_boolean_write_from_stylesheet : vx_web_htmldoc.Func_boolean_write_from_stylesheet = vx_web_htmldoc.Class_boolean_write_from_stylesheet()
  val t_boolean_write_from_stylesheet : vx_web_htmldoc.Func_boolean_write_from_stylesheet = vx_web_htmldoc.Class_boolean_write_from_stylesheet()

  fun f_boolean_write_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : CompletableFuture<vx_core.Type_boolean> {
    var output : CompletableFuture<vx_core.Type_boolean> = vx_core.vx_async_new_from_value(vx_core.e_boolean)
    output = vx_core.f_let_async(
      vx_core.t_boolean,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var text : vx_core.Type_string = vx_web_htmldoc.f_string_from_stylesheet(
          stylesheet
        )
        var future_iswrite : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_stylesheet_from_string(
          text
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_iswrite, {iswrite ->
          var output_2 : vx_core.Type_any = iswrite
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeevents_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_writeevents_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writeevents_from_ui : vx_core.Class_base, Func_boolean_writeevents_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_writeevents_from_ui = vx_web_htmldoc.Class_boolean_writeevents_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_boolean_writeevents_from_ui = vx_web_htmldoc.Class_boolean_writeevents_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-writeevents<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_boolean_writeevents_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_boolean_writeevents_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_web_htmldoc.f_boolean_writeevents_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_boolean_writeevents_from_ui(ui)
      return output
    }

    override fun vx_boolean_writeevents_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_writeevents_from_ui(ui)
      return output
    }

  }

  val e_boolean_writeevents_from_ui : vx_web_htmldoc.Func_boolean_writeevents_from_ui = vx_web_htmldoc.Class_boolean_writeevents_from_ui()
  val t_boolean_writeevents_from_ui : vx_web_htmldoc.Func_boolean_writeevents_from_ui = vx_web_htmldoc.Class_boolean_writeevents_from_ui()

  fun f_boolean_writeevents_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_context_read : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_context_read() : vx_core.Type_context
  }

  class Class_context_read : vx_core.Class_base, Func_context_read {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_context_read = vx_web_htmldoc.Class_context_read()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_context_read = vx_web_htmldoc.Class_context_read()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-read", // name
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_context_read
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_context_read
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_web_htmldoc.f_context_read()
      return output
    }

    override fun vx_context_read() : vx_core.Type_context {
      var output : vx_core.Type_context = vx_web_htmldoc.f_context_read()
      return output
    }

  }

  val e_context_read : vx_web_htmldoc.Func_context_read = vx_web_htmldoc.Class_context_read()
  val t_context_read : vx_web_htmldoc.Func_context_read = vx_web_htmldoc.Class_context_read()

  fun f_context_read() : vx_core.Type_context {
    var output : vx_core.Type_context = vx_core.e_context
    return output
  }


  interface Func_context_write : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_context_write(context : vx_core.Type_context) : vx_core.Type_context
  }

  class Class_context_write : vx_core.Class_base, Func_context_write {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_context_write = vx_web_htmldoc.Class_context_write()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_context_write = vx_web_htmldoc.Class_context_write()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-write", // name
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_context_write
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_context_write
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_context_write(context)
      return output
    }

    override fun vx_context_write(context : vx_core.Type_context) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_web_htmldoc.f_context_write(context)
      return output
    }

  }

  val e_context_write : vx_web_htmldoc.Func_context_write = vx_web_htmldoc.Class_context_write()
  val t_context_write : vx_web_htmldoc.Func_context_write = vx_web_htmldoc.Class_context_write()

  fun f_context_write(context : vx_core.Type_context) : vx_core.Type_context {
    var output : vx_core.Type_context = vx_core.e_context
    return output
  }


  interface Func_string_from_id : vx_core.Func_any_from_any {
    fun vx_string_from_id(id : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_from_id : vx_core.Class_base, Func_string_from_id {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_string_from_id = vx_web_htmldoc.Class_string_from_id()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_string_from_id = vx_web_htmldoc.Class_string_from_id()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-id", // name
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_string_from_id
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_string_from_id
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_htmldoc.f_string_from_id(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var id : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_string_from_id(id)
      return output
    }

    override fun vx_string_from_id(id : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_htmldoc.f_string_from_id(id)
      return output
    }

  }

  val e_string_from_id : vx_web_htmldoc.Func_string_from_id = vx_web_htmldoc.Class_string_from_id()
  val t_string_from_id : vx_web_htmldoc.Func_string_from_id = vx_web_htmldoc.Class_string_from_id()

  fun f_string_from_id(id : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    return output
  }


  interface Func_string_from_stylesheet : vx_core.Func_any_from_any {
    fun vx_string_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_core.Type_string
  }

  class Class_string_from_stylesheet : vx_core.Class_base, Func_string_from_stylesheet {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_string_from_stylesheet = vx_web_htmldoc.Class_string_from_stylesheet()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_string_from_stylesheet = vx_web_htmldoc.Class_string_from_stylesheet()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-stylesheet", // name
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_string_from_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_string_from_stylesheet
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylesheet = value as vx_web_html.Type_stylesheet
      var outputval : vx_core.Type_any = vx_web_htmldoc.f_string_from_stylesheet(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_string_from_stylesheet(stylesheet)
      return output
    }

    override fun vx_string_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_htmldoc.f_string_from_stylesheet(stylesheet)
      return output
    }

  }

  val e_string_from_stylesheet : vx_web_htmldoc.Func_string_from_stylesheet = vx_web_htmldoc.Class_string_from_stylesheet()
  val t_string_from_stylesheet : vx_web_htmldoc.Func_string_from_stylesheet = vx_web_htmldoc.Class_string_from_stylesheet()

  fun f_string_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var stylelist : vx_web_html.Type_stylelist = vx_web_html.f_styles_from_stylesheet(
          stylesheet
        )
        var text : vx_core.Type_string = vx_web_html.f_string_from_stylelist_indent(
          stylelist,
          vx_core.vx_new_int(0)
        )
        var output_1 : vx_core.Type_any = text
        output_1
      })
    )
    return output
  }


  interface Func_ui_readstate_from_uid : vx_core.Func_any_from_any {
    fun vx_ui_readstate_from_uid(uid : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_ui_readstate_from_uid : vx_core.Class_base, Func_ui_readstate_from_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_ui_readstate_from_uid = vx_web_htmldoc.Class_ui_readstate_from_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_htmldoc.Class_ui_readstate_from_uid = vx_web_htmldoc.Class_ui_readstate_from_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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
      var output : vx_core.Type_any = vx_web_htmldoc.e_ui_readstate_from_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.t_ui_readstate_from_uid
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_htmldoc.f_ui_readstate_from_uid(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_htmldoc.f_ui_readstate_from_uid(uid)
      return output
    }

    override fun vx_ui_readstate_from_uid(uid : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_htmldoc.f_ui_readstate_from_uid(uid)
      return output
    }

  }

  val e_ui_readstate_from_uid : vx_web_htmldoc.Func_ui_readstate_from_uid = vx_web_htmldoc.Class_ui_readstate_from_uid()
  val t_ui_readstate_from_uid : vx_web_htmldoc.Func_ui_readstate_from_uid = vx_web_htmldoc.Class_ui_readstate_from_uid()

  fun f_ui_readstate_from_uid(uid : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("boolean-print<-id-stylesheettext", vx_web_htmldoc.t_boolean_print_from_id_stylesheettext)
    mapfunc.put("boolean-remove<-id", vx_web_htmldoc.t_boolean_remove_from_id)
    mapfunc.put("boolean-replace<-id-htmltext", vx_web_htmldoc.t_boolean_replace_from_id_htmltext)
    mapfunc.put("boolean-replace<-id-parent-htmltext", vx_web_htmldoc.t_boolean_replace_from_id_parent_htmltext)
    mapfunc.put("boolean-write-stylesheet<-string", vx_web_htmldoc.t_boolean_write_stylesheet_from_string)
    mapfunc.put("boolean-write<-id-attribute-value", vx_web_htmldoc.t_boolean_write_from_id_attribute_value)
    mapfunc.put("boolean-write<-id-htmltext", vx_web_htmldoc.t_boolean_write_from_id_htmltext)
    mapfunc.put("boolean-write<-id-visible", vx_web_htmldoc.t_boolean_write_from_id_visible)
    mapfunc.put("boolean-write<-stylesheet", vx_web_htmldoc.t_boolean_write_from_stylesheet)
    mapfunc.put("boolean-writeevents<-ui", vx_web_htmldoc.t_boolean_writeevents_from_ui)
    mapfunc.put("context-read", vx_web_htmldoc.t_context_read)
    mapfunc.put("context-write", vx_web_htmldoc.t_context_write)
    mapfunc.put("string<-id", vx_web_htmldoc.t_string_from_id)
    mapfunc.put("string<-stylesheet", vx_web_htmldoc.t_string_from_stylesheet)
    mapfunc.put("ui-readstate<-uid", vx_web_htmldoc.t_ui_readstate_from_uid)
    vx_core.vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc)
  }

}
