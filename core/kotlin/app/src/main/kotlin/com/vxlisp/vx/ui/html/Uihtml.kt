package com.vxlisp.vx.ui.html

import java.util.concurrent.CompletableFuture
import com.vxlisp.vx.*
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*
import com.vxlisp.vx.ui.*

object vx_ui_html_uihtml {


  class Const_layout_app_html {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-app-html", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_copy(
        vx_ui_ui.c_layout_app,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":fn-layout"),
          vx_ui_html_uihtml.t_ui_layout_app_from_ui_orig_parent
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_app_html : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_else_html {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-else-html", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_copy(
        vx_ui_ui.c_layout_else,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":fn-layout"),
          vx_ui_html_uihtml.t_ui_layout_default_from_ui_orig_parent
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_else_html : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_image_html {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-image-html", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_copy(
        vx_ui_ui.c_layout_image,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":fn-layout"),
          vx_ui_html_uihtml.t_ui_layout_image_from_ui_orig_parent
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_image_html : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_label_html {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-label-html", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_copy(
        vx_ui_ui.c_layout_label,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":fn-layout"),
          vx_ui_html_uihtml.t_ui_layout_label_from_ui_orig_parent
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_label_html : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layoutenginehtml {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layoutenginehtml", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_ui_ui.Type_layoutengine) : Unit {
      var outval : vx_ui_ui.Class_layoutengine = output as vx_ui_ui.Class_layoutengine
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layoutengine = vx_core.f_new(
        vx_ui_ui.t_layoutengine,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":layoutmap"),
          vx_ui_ui.f_layoutmap_from_layoutlist(
            vx_core.f_new(
              vx_ui_ui.t_layoutlist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_ui_html_uihtml.c_layout_app_html,
                vx_ui_html_uihtml.c_layout_image_html,
                vx_ui_html_uihtml.c_layout_label_html
              )
            )
          ),
          vx_core.vx_new_string(":layoutelse"),
          vx_ui_html_uihtml.c_layout_else_html,
          vx_core.vx_new_string(":boolean-print"),
          vx_ui_html_uihtml.t_boolean_print_html,
          vx_core.vx_new_string(":boolean-layoutremove"),
          vx_ui_html_uihtml.t_boolean_layoutremove_html,
          vx_core.vx_new_string(":boolean-layoutselected"),
          vx_ui_html_uihtml.t_boolean_layoutselected_html,
          vx_core.vx_new_string(":boolean-layoutvisible"),
          vx_ui_html_uihtml.t_boolean_layoutvisible_html,
          vx_core.vx_new_string(":stylesheetrender"),
          vx_ui_html_uihtml.t_stylesheet_layout_html
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_boolean_print = value.boolean_print()
      outval.vx_p_boolean_layoutremove = value.boolean_layoutremove()
      outval.vx_p_boolean_layoutselected = value.boolean_layoutselected()
      outval.vx_p_boolean_layoutvisible = value.boolean_layoutvisible()
      outval.vx_p_layoutmap = value.layoutmap()
      outval.vx_p_layoutelse = value.layoutelse()
      outval.vx_p_stylesheetrender = value.stylesheetrender()
    }

    }
  }

  val c_layoutenginehtml : vx_ui_ui.Type_layoutengine = vx_ui_ui.Class_layoutengine()


  class Const_style_hidden {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style-hidden", // name
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_web_html.Type_style) : Unit {
      var outval : vx_web_html.Class_style = output as vx_web_html.Class_style
      outval.vx_p_constdef = constdef()
      var value : vx_web_html.Type_style = vx_core.f_new(
        vx_web_html.t_style,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string(".style-hidden")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_props = value.props()
      outval.vx_p_stylelist = value.stylelist()
    }

    }
  }

  val c_style_hidden : vx_web_html.Type_style = vx_web_html.Class_style()


  class Const_style_selected {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style-selected", // name
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      )
      return output
    }

    fun const_new(output : vx_web_html.Type_style) : Unit {
      var outval : vx_web_html.Class_style = output as vx_web_html.Class_style
      outval.vx_p_constdef = constdef()
      var value : vx_web_html.Type_style = vx_core.f_new(
        vx_web_html.t_style,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string(".style-selected")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_props = value.props()
      outval.vx_p_stylelist = value.stylelist()
    }

    }
  }

  val c_style_selected : vx_web_html.Type_style = vx_web_html.Class_style()


  interface Func_boolean_layoutremove_html : vx_core.Func_any_from_any {
    fun vx_boolean_layoutremove_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutremove_html : vx_core.Class_base, Func_boolean_layoutremove_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutremove_html = vx_ui_html_uihtml.Class_boolean_layoutremove_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutremove_html = vx_ui_html_uihtml.Class_boolean_layoutremove_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutremove-html", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_layoutremove_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_layoutremove_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_layoutremove_html(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_layoutremove_html(ui)
      return output
    }

    override fun vx_boolean_layoutremove_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_layoutremove_html(ui)
      return output
    }

  }

  val e_boolean_layoutremove_html : vx_ui_html_uihtml.Func_boolean_layoutremove_html = vx_ui_html_uihtml.Class_boolean_layoutremove_html()
  val t_boolean_layoutremove_html : vx_ui_html_uihtml.Func_boolean_layoutremove_html = vx_ui_html_uihtml.Class_boolean_layoutremove_html()

  fun f_boolean_layoutremove_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var id : vx_core.Type_string = ui.uid()
        var output_1 : vx_core.Type_any = vx_web_htmldoc.f_boolean_remove_from_id(
          id
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutselected_html : vx_core.Func_any_from_any {
    fun vx_boolean_layoutselected_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutselected_html : vx_core.Class_base, Func_boolean_layoutselected_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutselected_html = vx_ui_html_uihtml.Class_boolean_layoutselected_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutselected_html = vx_ui_html_uihtml.Class_boolean_layoutselected_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutselected-html", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_layoutselected_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_layoutselected_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_layoutselected_html(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_layoutselected_html(ui)
      return output
    }

    override fun vx_boolean_layoutselected_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_layoutselected_html(ui)
      return output
    }

  }

  val e_boolean_layoutselected_html : vx_ui_html_uihtml.Func_boolean_layoutselected_html = vx_ui_html_uihtml.Class_boolean_layoutselected_html()
  val t_boolean_layoutselected_html : vx_ui_html_uihtml.Func_boolean_layoutselected_html = vx_ui_html_uihtml.Class_boolean_layoutselected_html()

  fun f_boolean_layoutselected_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(
      ui
    )
    return output
  }


  interface Func_boolean_layoutvisible_html : vx_core.Func_any_from_any {
    fun vx_boolean_layoutvisible_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutvisible_html : vx_core.Class_base, Func_boolean_layoutvisible_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutvisible_html = vx_ui_html_uihtml.Class_boolean_layoutvisible_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_layoutvisible_html = vx_ui_html_uihtml.Class_boolean_layoutvisible_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutvisible-html", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_layoutvisible_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_layoutvisible_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_layoutvisible_html(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_layoutvisible_html(ui)
      return output
    }

    override fun vx_boolean_layoutvisible_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_layoutvisible_html(ui)
      return output
    }

  }

  val e_boolean_layoutvisible_html : vx_ui_html_uihtml.Func_boolean_layoutvisible_html = vx_ui_html_uihtml.Class_boolean_layoutvisible_html()
  val t_boolean_layoutvisible_html : vx_ui_html_uihtml.Func_boolean_layoutvisible_html = vx_ui_html_uihtml.Class_boolean_layoutvisible_html()

  fun f_boolean_layoutvisible_html(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(
      ui
    )
    return output
  }


  interface Func_boolean_print_html : vx_core.Func_any_from_any_context {
    fun vx_boolean_print_html(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_print_html : vx_core.Class_base, Func_boolean_print_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_print_html = vx_ui_html_uihtml.Class_boolean_print_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_print_html = vx_ui_html_uihtml.Class_boolean_print_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-print-html", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_print_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_print_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_print_html(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_print_html(context, ui)
      return output
    }

    override fun vx_boolean_print_html(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_print_html(context, ui)
      return output
    }

  }

  val e_boolean_print_html : vx_ui_html_uihtml.Func_boolean_print_html = vx_ui_html_uihtml.Class_boolean_print_html()
  val t_boolean_print_html : vx_ui_html_uihtml.Func_boolean_print_html = vx_ui_html_uihtml.Class_boolean_print_html()

  fun f_boolean_print_html(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var stylesheetui : vx_ui_ui.Type_stylesheet = vx_ui_ui.f_stylesheet_readstate(
          context
        )
        var stylesheethtml : vx_web_html.Type_stylesheet = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(
          stylesheetui
        )
        var styletext : vx_core.Type_string = vx_web_html.f_string_from_stylesheet_indent(
          stylesheethtml,
          vx_core.vx_new_int(0)
        )
        var output_1 : vx_core.Type_any = vx_web_htmldoc.f_boolean_print_from_id_stylesheettext(
          uid,
          styletext
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeclass_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_writeclass_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writeclass_from_ui : vx_core.Class_base, Func_boolean_writeclass_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeclass_from_ui = vx_ui_html_uihtml.Class_boolean_writeclass_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeclass_from_ui = vx_ui_html_uihtml.Class_boolean_writeclass_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeclass<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_writeclass_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_writeclass_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(ui)
      return output
    }

    override fun vx_boolean_writeclass_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(ui)
      return output
    }

  }

  val e_boolean_writeclass_from_ui : vx_ui_html_uihtml.Func_boolean_writeclass_from_ui = vx_ui_html_uihtml.Class_boolean_writeclass_from_ui()
  val t_boolean_writeclass_from_ui : vx_ui_html_uihtml.Func_boolean_writeclass_from_ui = vx_ui_html_uihtml.Class_boolean_writeclass_from_ui()

  fun f_boolean_writeclass_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var id : vx_core.Type_string = ui.uid()
        var sclass : vx_core.Type_string = vx_ui_html_uihtml.f_string_class_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_web_htmldoc.f_boolean_write_from_id_attribute_value(
          id,
          vx_core.vx_new_string("class"),
          sclass
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeeventsall_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_writeeventsall_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writeeventsall_from_ui : vx_core.Class_base, Func_boolean_writeeventsall_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeeventsall<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_writeeventsall_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_writeeventsall_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(ui)
      return output
    }

    override fun vx_boolean_writeeventsall_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(ui)
      return output
    }

  }

  val e_boolean_writeeventsall_from_ui : vx_ui_html_uihtml.Func_boolean_writeeventsall_from_ui = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui()
  val t_boolean_writeeventsall_from_ui : vx_ui_html_uihtml.Func_boolean_writeeventsall_from_ui = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_ui()

  fun f_boolean_writeeventsall_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var iswrite1 : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_writeevents_from_ui(
          ui
        )
        var iswrite2 : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_uimap(
          uimap
        )
        var output_1 : vx_core.Type_any = vx_core.f_and(
          iswrite1,
          iswrite2
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeeventsall_from_uimap : vx_core.Func_any_from_any {
    fun vx_boolean_writeeventsall_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_core.Type_boolean
  }

  class Class_boolean_writeeventsall_from_uimap : vx_core.Class_base, Func_boolean_writeeventsall_from_uimap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeeventsall<-uimap", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_writeeventsall_from_uimap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_writeeventsall_from_uimap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uimap = value as vx_ui_ui.Type_uimap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writeeventsall_from_uimap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_writeeventsall_from_uimap(uimap)
      return output
    }

    override fun vx_boolean_writeeventsall_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_uimap(uimap)
      return output
    }

  }

  val e_boolean_writeeventsall_from_uimap : vx_ui_html_uihtml.Func_boolean_writeeventsall_from_uimap = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap()
  val t_boolean_writeeventsall_from_uimap : vx_ui_html_uihtml.Func_boolean_writeeventsall_from_uimap = vx_ui_html_uihtml.Class_boolean_writeeventsall_from_uimap()

  fun f_boolean_writeeventsall_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var boollist : vx_core.Type_booleanlist = vx_core.f_list_from_map_1(
          vx_core.t_booleanlist,
          uimap,
          vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
            var output_2 : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(
              value
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_core.f_and_1(
          boollist
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeselected_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_writeselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writeselected_from_ui : vx_core.Class_base, Func_boolean_writeselected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeselected_from_ui = vx_ui_html_uihtml.Class_boolean_writeselected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writeselected_from_ui = vx_ui_html_uihtml.Class_boolean_writeselected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeselected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_writeselected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_writeselected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writeselected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_writeselected_from_ui(ui)
      return output
    }

    override fun vx_boolean_writeselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeselected_from_ui(ui)
      return output
    }

  }

  val e_boolean_writeselected_from_ui : vx_ui_html_uihtml.Func_boolean_writeselected_from_ui = vx_ui_html_uihtml.Class_boolean_writeselected_from_ui()
  val t_boolean_writeselected_from_ui : vx_ui_html_uihtml.Func_boolean_writeselected_from_ui = vx_ui_html_uihtml.Class_boolean_writeselected_from_ui()

  fun f_boolean_writeselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(
      ui
    )
    return output
  }


  interface Func_boolean_writevisible_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_writevisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writevisible_from_ui : vx_core.Class_base, Func_boolean_writevisible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writevisible_from_ui = vx_ui_html_uihtml.Class_boolean_writevisible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_boolean_writevisible_from_ui = vx_ui_html_uihtml.Class_boolean_writevisible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writevisible<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_boolean_writevisible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_boolean_writevisible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_boolean_writevisible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_boolean_writevisible_from_ui(ui)
      return output
    }

    override fun vx_boolean_writevisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writevisible_from_ui(ui)
      return output
    }

  }

  val e_boolean_writevisible_from_ui : vx_ui_html_uihtml.Func_boolean_writevisible_from_ui = vx_ui_html_uihtml.Class_boolean_writevisible_from_ui()
  val t_boolean_writevisible_from_ui : vx_ui_html_uihtml.Func_boolean_writevisible_from_ui = vx_ui_html_uihtml.Class_boolean_writevisible_from_ui()

  fun f_boolean_writevisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_ui_html_uihtml.f_boolean_writeclass_from_ui(
      ui
    )
    return output
  }


  interface Func_context_write : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_context_write(context : vx_core.Type_context) : vx_core.Type_context
  }

  class Class_context_write : vx_core.Class_base, Func_context_write {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_context_write = vx_ui_html_uihtml.Class_context_write()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_context_write = vx_ui_html_uihtml.Class_context_write()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_context_write
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_context_write
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_context_write(context)
      return output
    }

    override fun vx_context_write(context : vx_core.Type_context) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_ui_html_uihtml.f_context_write(context)
      return output
    }

  }

  val e_context_write : vx_ui_html_uihtml.Func_context_write = vx_ui_html_uihtml.Class_context_write()
  val t_context_write : vx_ui_html_uihtml.Func_context_write = vx_ui_html_uihtml.Class_context_write()

  fun f_context_write(context : vx_core.Type_context) : vx_core.Type_context {
    var output : vx_core.Type_context = vx_core.e_context
    output = vx_web_htmldoc.f_context_write(
      context
    )
    return output
  }


  interface Func_divchild_from_ui : vx_core.Func_any_from_any {
    fun vx_divchild_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_divchild
  }

  class Class_divchild_from_ui : vx_core.Class_base, Func_divchild_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchild_from_ui = vx_ui_html_uihtml.Class_divchild_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchild_from_ui = vx_ui_html_uihtml.Class_divchild_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchild<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "divchild", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_divchild_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_divchild_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_divchild_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_divchild_from_ui(ui)
      return output
    }

    override fun vx_divchild_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_divchild {
      var output : vx_web_html.Type_divchild = vx_ui_html_uihtml.f_divchild_from_ui(ui)
      return output
    }

  }

  val e_divchild_from_ui : vx_ui_html_uihtml.Func_divchild_from_ui = vx_ui_html_uihtml.Class_divchild_from_ui()
  val t_divchild_from_ui : vx_ui_html_uihtml.Func_divchild_from_ui = vx_ui_html_uihtml.Class_divchild_from_ui()

  fun f_divchild_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_divchild {
    var output : vx_web_html.Type_divchild = vx_web_html.e_divchild
    output = vx_core.f_let(
      vx_web_html.t_div,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uimapchild : vx_ui_ui.Type_uimap = ui.uimap()
        var uistyle : vx_ui_ui.Type_style = ui.style()
        var uistyles : vx_ui_ui.Type_stylelist = ui.stylelist()
        var styleunique : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_style(
          uistyle
        )
        var htmlstyles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylelist(
          uistyles
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_div,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":id"),
            uid,
            vx_core.vx_new_string(":style-unique"),
            styleunique,
            vx_core.vx_new_string(":stylelist"),
            htmlstyles
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_divchildlist_from_uimap : vx_core.Func_any_from_any {
    fun vx_divchildlist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist
  }

  class Class_divchildlist_from_uimap : vx_core.Class_base, Func_divchildlist_from_uimap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap = vx_ui_html_uihtml.Class_divchildlist_from_uimap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap = vx_ui_html_uihtml.Class_divchildlist_from_uimap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_divchild), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_divchildlist_from_uimap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_divchildlist_from_uimap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uimap = value as vx_ui_ui.Type_uimap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_divchildlist_from_uimap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_divchildlist_from_uimap(uimap)
      return output
    }

    override fun vx_divchildlist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_ui_html_uihtml.f_divchildlist_from_uimap(uimap)
      return output
    }

  }

  val e_divchildlist_from_uimap : vx_ui_html_uihtml.Func_divchildlist_from_uimap = vx_ui_html_uihtml.Class_divchildlist_from_uimap()
  val t_divchildlist_from_uimap : vx_ui_html_uihtml.Func_divchildlist_from_uimap = vx_ui_html_uihtml.Class_divchildlist_from_uimap()

  fun f_divchildlist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist {
    var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_map_1(
      vx_web_html.t_divchildlist,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
        var output_1 : vx_core.Type_any = vx_core.f_let(
          vx_web_html.t_div,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var uid : vx_core.Type_string = value.uid()
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_web_html.t_div,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":id"),
                uid
              )
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_divchildlist_from_uimap_1 : vx_core.Func_any_from_any {
    fun vx_divchildlist_from_uimap_1(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist
  }

  class Class_divchildlist_from_uimap_1 : vx_core.Class_base, Func_divchildlist_from_uimap_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap_1 = vx_ui_html_uihtml.Class_divchildlist_from_uimap_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap_1 = vx_ui_html_uihtml.Class_divchildlist_from_uimap_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_divchild), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_divchildlist_from_uimap_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_divchildlist_from_uimap_1
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uimap = value as vx_ui_ui.Type_uimap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_divchildlist_from_uimap_1(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_divchildlist_from_uimap_1(uimap)
      return output
    }

    override fun vx_divchildlist_from_uimap_1(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_ui_html_uihtml.f_divchildlist_from_uimap_1(uimap)
      return output
    }

  }

  val e_divchildlist_from_uimap_1 : vx_ui_html_uihtml.Func_divchildlist_from_uimap_1 = vx_ui_html_uihtml.Class_divchildlist_from_uimap_1()
  val t_divchildlist_from_uimap_1 : vx_ui_html_uihtml.Func_divchildlist_from_uimap_1 = vx_ui_html_uihtml.Class_divchildlist_from_uimap_1()

  fun f_divchildlist_from_uimap_1(uimap : vx_ui_ui.Type_uimap) : vx_web_html.Type_divchildlist {
    var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_map_1(
      vx_web_html.t_divchildlist,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
        var output_1 : vx_core.Type_any = vx_core.f_let(
          vx_web_html.t_div,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var uid : vx_core.Type_string = value.uid()
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_web_html.t_div,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":id"),
                uid
              )
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_divchildlist_from_uimap_origmap_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_divchildlist_from_uimap_origmap_parent(uimap : vx_ui_ui.Type_uimap, origmap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_divchildlist
  }

  class Class_divchildlist_from_uimap_origmap_parent : vx_core.Class_base, Func_divchildlist_from_uimap_origmap_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent = vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent = vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap-origmap-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_divchild), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_divchildlist_from_uimap_origmap_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_divchildlist_from_uimap_origmap_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      var origmap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, parent)
      return output
    }

    override fun vx_divchildlist_from_uimap_origmap_parent(uimap : vx_ui_ui.Type_uimap, origmap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_ui_html_uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, parent)
      return output
    }

  }

  val e_divchildlist_from_uimap_origmap_parent : vx_ui_html_uihtml.Func_divchildlist_from_uimap_origmap_parent = vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent()
  val t_divchildlist_from_uimap_origmap_parent : vx_ui_html_uihtml.Func_divchildlist_from_uimap_origmap_parent = vx_ui_html_uihtml.Class_divchildlist_from_uimap_origmap_parent()

  fun f_divchildlist_from_uimap_origmap_parent(uimap : vx_ui_ui.Type_uimap, origmap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_divchildlist {
    var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_map_1(
      vx_web_html.t_divchildlist,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
        var output_1 : vx_core.Type_any = vx_core.f_let(
          vx_web_html.t_node,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var origvalue : vx_ui_ui.Type_ui = vx_core.f_any_from_map(
              vx_ui_ui.t_ui,
              origmap,
              key
            )
            var output_2 : vx_core.Type_any = vx_ui_html_uihtml.f_node_from_ui_orig_parent(
              value,
              origvalue,
              parent
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_node_app_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_app_from_ui_orig_parent : vx_core.Class_base, Func_node_app_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_app_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_app_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_node_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_node_app_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent()
  val t_node_app_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_app_from_ui_orig_parent()

  fun f_node_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var origmap : vx_ui_ui.Type_uimap = orig.uimap()
        var children : vx_web_html.Type_divchildlist = vx_ui_html_uihtml.f_divchildlist_from_uimap_origmap_parent(
          uimap,
          origmap,
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_div,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":id"),
            uid,
            vx_core.vx_new_string(":nodes"),
            children
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_node_default_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_default_from_ui_orig_parent : vx_core.Class_base, Func_node_default_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_default_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_default_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_node_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_node_default_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent()
  val t_node_default_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_default_from_ui_orig_parent()

  fun f_node_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var uistyle : vx_ui_ui.Type_style = ui.style()
        var origmap : vx_ui_ui.Type_uimap = orig.uimap()
        var style : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_style(
          uistyle
        )
        var styles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_extra_from_ui(
          ui
        )
        var children : vx_web_html.Type_divchildlist = vx_ui_html_uihtml.f_divchildlist_from_uimap_origmap_parent(
          uimap,
          origmap,
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_div,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":id"),
            uid,
            vx_core.vx_new_string(":style-unique"),
            style,
            vx_core.vx_new_string(":stylelist"),
            styles,
            vx_core.vx_new_string(":nodes"),
            children
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_node_image_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_image_from_ui_orig_parent : vx_core.Class_base, Func_node_image_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-image<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_image_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_image_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_node_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_node_image_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent()
  val t_node_image_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_image_from_ui_orig_parent()

  fun f_node_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uistyle : vx_ui_ui.Type_style = ui.style()
        var data : vx_core.Type_any = ui.data()
        var file : vx_data_file.Type_file = vx_core.f_any_from_any(
          vx_data_file.t_file,
          data
        )
        var path : vx_core.Type_string = vx_data_file.f_pathfull_from_file(
          file
        )
        var style : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_style(
          uistyle
        )
        var styles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_extra_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_img,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":id"),
            uid,
            vx_core.vx_new_string(":style-unique"),
            style,
            vx_core.vx_new_string(":stylelist"),
            styles,
            vx_core.vx_new_string(":src"),
            path
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_node_label_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_label_from_ui_orig_parent : vx_core.Class_base, Func_node_label_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_label_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_label_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_node_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_node_label_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent()
  val t_node_label_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_label_from_ui_orig_parent()

  fun f_node_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var data : vx_core.Type_any = ui.data()
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var uistyle : vx_ui_ui.Type_style = ui.style()
        var uistyles : vx_ui_ui.Type_stylelist = ui.stylelist()
        var datatype : vx_core.Type_any = vx_core.f_type_from_any(
          data
        )
        var style : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_style(
          uistyle
        )
        var styles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylelist(
          uistyles
        )
        var text : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eqeq(
                  datatype,
                  vx_core.t_string
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_any_from_any(
                  vx_core.t_string,
                  data
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_string_from_any(
                  data
                )
                output_4
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_p,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":id"),
            uid,
            vx_core.vx_new_string(":style-unique"),
            style,
            vx_core.vx_new_string(":stylelist"),
            styles,
            vx_core.vx_new_string(":text"),
            text
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_node_layout_from_node_ui_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_layout_from_node_ui_parent(node : vx_web_html.Type_node, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_layout_from_node_ui_parent : vx_core.Class_base, Func_node_layout_from_node_ui_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent = vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent = vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-layout<-node-ui-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_layout_from_node_ui_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_layout_from_node_ui_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var node : vx_web_html.Type_node = vx_core.f_any_from_any(vx_web_html.t_node, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(node, ui, parent)
      return output
    }

    override fun vx_node_layout_from_node_ui_parent(node : vx_web_html.Type_node, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(node, ui, parent)
      return output
    }

  }

  val e_node_layout_from_node_ui_parent : vx_ui_html_uihtml.Func_node_layout_from_node_ui_parent = vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent()
  val t_node_layout_from_node_ui_parent : vx_ui_html_uihtml.Func_node_layout_from_node_ui_parent = vx_ui_html_uihtml.Class_node_layout_from_node_ui_parent()

  fun f_node_layout_from_node_ui_parent(node : vx_web_html.Type_node, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var id : vx_core.Type_string = ui.uid()
        var parentid : vx_core.Type_string = parent.uid()
        var htmltext : vx_core.Type_string = vx_web_html.f_string_from_node_indent(
          node,
          vx_core.vx_new_int(2)
        )
        var htmldone : vx_core.Type_boolean = vx_web_htmldoc.f_boolean_replace_from_id_parent_htmltext(
          id,
          parentid,
          htmltext
        )
        var output_1 : vx_core.Type_any = node
        output_1
      })
    )
    return output
  }


  interface Func_node_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_node_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node
  }

  class Class_node_from_ui_orig_parent : vx_core.Class_base, Func_node_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_node_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_node_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_node_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_node_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_node_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_node_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_from_ui_orig_parent()
  val t_node_from_ui_orig_parent : vx_ui_html_uihtml.Func_node_from_ui_orig_parent = vx_ui_html_uihtml.Class_node_from_ui_orig_parent()

  fun f_node_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_web_html.Type_node {
    var output : vx_web_html.Type_node = vx_web_html.e_node
    output = vx_core.f_let(
      vx_web_html.t_node,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var style : vx_ui_ui.Type_style = ui.style()
        var layout : vx_ui_ui.Type_layout = style.layout()
        var output_1 : vx_core.Type_any = vx_core.f_switch(
          vx_web_html.t_node,
          layout,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_ui_ui.c_layout_image,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_ui_html_uihtml.f_node_image_from_ui_orig_parent(
                  ui,
                  orig,
                  parent
                )
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_ui_ui.c_layout_label,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_ui_html_uihtml.f_node_label_from_ui_orig_parent(
                  ui,
                  orig,
                  parent
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_ui_html_uihtml.f_node_default_from_ui_orig_parent(
                  ui,
                  orig,
                  parent
                )
                output_4
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_class_from_ui : vx_core.Func_any_from_any {
    fun vx_string_class_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string
  }

  class Class_string_class_from_ui : vx_core.Class_base, Func_string_class_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_class_from_ui = vx_ui_html_uihtml.Class_string_class_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_class_from_ui = vx_ui_html_uihtml.Class_string_class_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-class<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_string_class_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_string_class_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_string_class_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_string_class_from_ui(ui)
      return output
    }

    override fun vx_string_class_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_html_uihtml.f_string_class_from_ui(ui)
      return output
    }

  }

  val e_string_class_from_ui : vx_ui_html_uihtml.Func_string_class_from_ui = vx_ui_html_uihtml.Class_string_class_from_ui()
  val t_string_class_from_ui : vx_ui_html_uihtml.Func_string_class_from_ui = vx_ui_html_uihtml.Class_string_class_from_ui()

  fun f_string_class_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var htmlstyles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_extra_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_stylelist(
          htmlstyles
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_style_from_font : vx_core.Func_any_from_any {
    fun vx_string_style_from_font(font : vx_ui_ui.Type_font) : vx_core.Type_string
  }

  class Class_string_style_from_font : vx_core.Class_base, Func_string_style_from_font {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_style_from_font = vx_ui_html_uihtml.Class_string_style_from_font()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_style_from_font = vx_ui_html_uihtml.Class_string_style_from_font()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-font", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_string_style_from_font
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_string_style_from_font
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_font = value as vx_ui_ui.Type_font
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_string_style_from_font(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var font : vx_ui_ui.Type_font = vx_core.f_any_from_any(vx_ui_ui.t_font, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_string_style_from_font(font)
      return output
    }

    override fun vx_string_style_from_font(font : vx_ui_ui.Type_font) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_html_uihtml.f_string_style_from_font(font)
      return output
    }

  }

  val e_string_style_from_font : vx_ui_html_uihtml.Func_string_style_from_font = vx_ui_html_uihtml.Class_string_style_from_font()
  val t_string_style_from_font : vx_ui_html_uihtml.Func_string_style_from_font = vx_ui_html_uihtml.Class_string_style_from_font()

  fun f_string_style_from_font(font : vx_ui_ui.Type_font) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var face : vx_ui_ui.Type_fontface = font.fontface()
        var size : vx_core.Type_int = font.fontsize()
        var name : vx_core.Type_string = face.name()
        var ssize : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_gt(
                  size,
                  vx_core.vx_new_int(0)
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_new(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.f_divide(
                      size,
                      vx_core.vx_new_int(100)
                    ),
                    vx_core.vx_new_string("em"),
                    vx_core.vx_new_string(" ")
                  )
                )
                output_5
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_notempty(
                  name
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_new(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    ssize,
                    vx_core.c_quote,
                    name,
                    vx_core.c_quote
                  )
                )
                output_3
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_style_from_image : vx_core.Func_any_from_any {
    fun vx_string_style_from_image(image : vx_ui_ui.Type_image) : vx_core.Type_string
  }

  class Class_string_style_from_image : vx_core.Class_base, Func_string_style_from_image {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_style_from_image = vx_ui_html_uihtml.Class_string_style_from_image()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_style_from_image = vx_ui_html_uihtml.Class_string_style_from_image()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-image", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_string_style_from_image
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_string_style_from_image
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_image = value as vx_ui_ui.Type_image
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_string_style_from_image(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var image : vx_ui_ui.Type_image = vx_core.f_any_from_any(vx_ui_ui.t_image, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_string_style_from_image(image)
      return output
    }

    override fun vx_string_style_from_image(image : vx_ui_ui.Type_image) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_html_uihtml.f_string_style_from_image(image)
      return output
    }

  }

  val e_string_style_from_image : vx_ui_html_uihtml.Func_string_style_from_image = vx_ui_html_uihtml.Class_string_style_from_image()
  val t_string_style_from_image : vx_ui_html_uihtml.Func_string_style_from_image = vx_ui_html_uihtml.Class_string_style_from_image()

  fun f_string_style_from_image(image : vx_ui_ui.Type_image) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_notempty_1(
              image
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_let(
              vx_core.t_string,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var file : vx_data_file.Type_file = image.file()
                var url : vx_core.Type_string = vx_data_file.f_pathfull_from_file(
                  file
                )
                var output_3 : vx_core.Type_any = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = vx_core.f_notempty(
                          url
                        )
                        output_4
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("url("),
                            url,
                            vx_core.vx_new_string(")")
                          )
                        )
                        output_5
                      })
                    )
                  )
                )
                output_3
              })
            )
            output_2
          })
        )
      )
    )
    return output
  }


  interface Func_string_stylename_from_name_styletype : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_stylename_from_name_styletype(name : vx_core.Type_string, styletype : vx_ui_ui.Type_styletype) : vx_core.Type_string
  }

  class Class_string_stylename_from_name_styletype : vx_core.Class_base, Func_string_stylename_from_name_styletype {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_stylename_from_name_styletype = vx_ui_html_uihtml.Class_string_stylename_from_name_styletype()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_string_stylename_from_name_styletype = vx_ui_html_uihtml.Class_string_stylename_from_name_styletype()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-stylename<-name-styletype", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_string_stylename_from_name_styletype
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_string_stylename_from_name_styletype
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var styletype : vx_ui_ui.Type_styletype = vx_core.f_any_from_any(vx_ui_ui.t_styletype, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_html_uihtml.f_string_stylename_from_name_styletype(name, styletype)
      return output
    }

    override fun vx_string_stylename_from_name_styletype(name : vx_core.Type_string, styletype : vx_ui_ui.Type_styletype) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_html_uihtml.f_string_stylename_from_name_styletype(name, styletype)
      return output
    }

  }

  val e_string_stylename_from_name_styletype : vx_ui_html_uihtml.Func_string_stylename_from_name_styletype = vx_ui_html_uihtml.Class_string_stylename_from_name_styletype()
  val t_string_stylename_from_name_styletype : vx_ui_html_uihtml.Func_string_stylename_from_name_styletype = vx_ui_html_uihtml.Class_string_stylename_from_name_styletype()

  fun f_string_stylename_from_name_styletype(name : vx_core.Type_string, styletype : vx_ui_ui.Type_styletype) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_eq(
              vx_core.vx_new_string(""),
              name
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.vx_new_string("")
            output_2
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_eqeq(
              styletype,
              vx_ui_ui.c_styletype_shared
            )
            output_3
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string("."),
                name
              )
            )
            output_4
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_5 : vx_core.Type_any = vx_core.f_eqeq(
              styletype,
              vx_ui_ui.c_styletype_system
            )
            output_5
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_6 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string("#"),
                name
              )
            )
            output_6
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_7 : vx_core.Type_any = name
            output_7
          })
        )
      )
    )
    return output
  }


  interface Func_style_from_fontface : vx_core.Func_any_from_any {
    fun vx_style_from_fontface(fontface : vx_ui_ui.Type_fontface) : vx_web_html.Type_style
  }

  class Class_style_from_fontface : vx_core.Class_base, Func_style_from_fontface {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_style_from_fontface = vx_ui_html_uihtml.Class_style_from_fontface()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_style_from_fontface = vx_ui_html_uihtml.Class_style_from_fontface()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-fontface", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_style_from_fontface
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_style_from_fontface
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_fontface = value as vx_ui_ui.Type_fontface
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_style_from_fontface(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var fontface : vx_ui_ui.Type_fontface = vx_core.f_any_from_any(vx_ui_ui.t_fontface, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_style_from_fontface(fontface)
      return output
    }

    override fun vx_style_from_fontface(fontface : vx_ui_ui.Type_fontface) : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_fontface(fontface)
      return output
    }

  }

  val e_style_from_fontface : vx_ui_html_uihtml.Func_style_from_fontface = vx_ui_html_uihtml.Class_style_from_fontface()
  val t_style_from_fontface : vx_ui_html_uihtml.Func_style_from_fontface = vx_ui_html_uihtml.Class_style_from_fontface()

  fun f_style_from_fontface(fontface : vx_ui_ui.Type_fontface) : vx_web_html.Type_style {
    var output : vx_web_html.Type_style = vx_web_html.e_style
    output = vx_core.f_let(
      vx_web_html.t_style,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var name : vx_core.Type_string = fontface.name()
        var weight : vx_core.Type_string = fontface.weight()
        var unicode : vx_core.Type_string = fontface.unicode()
        var files : vx_data_file.Type_filelist = fontface.filelist()
        var urls : vx_core.Type_stringlist = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          files,
          vx_core.t_any_from_any.vx_fn_new({file_any : vx_core.Type_any ->
            var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, file_any)
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string("url("),
                vx_data_file.f_pathfull_from_file(
                  file
                ),
                vx_core.vx_new_string(")")
              )
            )
            output_2
          })
        )
        var fontfamily : vx_core.Type_string = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.c_quote,
            name,
            vx_core.c_quote
          )
        )
        var srcurls : vx_core.Type_string = vx_type.f_string_from_stringlist_join(
          urls,
          vx_core.vx_new_string(",")
        )
        var src : vx_core.Type_string = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            srcurls,
            vx_core.vx_new_string(";")
          )
        )
        var propmap : vx_web_html.Type_propmap = vx_core.f_new(
          vx_web_html.t_propmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":font-family"),
            fontfamily,
            vx_core.vx_new_string(":font-style"),
            vx_core.vx_new_string("normal"),
            vx_core.vx_new_string(":font-weight"),
            weight,
            vx_core.vx_new_string(":font-display"),
            vx_core.vx_new_string("swap"),
            vx_core.vx_new_string(":src"),
            src,
            vx_core.vx_new_string(":unicode-range"),
            unicode
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("@font-face"),
            vx_core.vx_new_string(":props"),
            propmap
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_style_from_style : vx_core.Func_any_from_any {
    fun vx_style_from_style(uistyle : vx_ui_ui.Type_style) : vx_web_html.Type_style
  }

  class Class_style_from_style : vx_core.Class_base, Func_style_from_style {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_style_from_style = vx_ui_html_uihtml.Class_style_from_style()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_style_from_style = vx_ui_html_uihtml.Class_style_from_style()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-style", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_style_from_style
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_style_from_style
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_style = value as vx_ui_ui.Type_style
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_style_from_style(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uistyle : vx_ui_ui.Type_style = vx_core.f_any_from_any(vx_ui_ui.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_style_from_style(uistyle)
      return output
    }

    override fun vx_style_from_style(uistyle : vx_ui_ui.Type_style) : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_ui_html_uihtml.f_style_from_style(uistyle)
      return output
    }

  }

  val e_style_from_style : vx_ui_html_uihtml.Func_style_from_style = vx_ui_html_uihtml.Class_style_from_style()
  val t_style_from_style : vx_ui_html_uihtml.Func_style_from_style = vx_ui_html_uihtml.Class_style_from_style()

  fun f_style_from_style(uistyle : vx_ui_ui.Type_style) : vx_web_html.Type_style {
    var output : vx_web_html.Type_style = vx_web_html.e_style
    output = vx_core.f_if_2(
      vx_web_html.t_style,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_is_empty_1(
              uistyle
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_empty(
              vx_web_html.t_style
            )
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_web_html.t_style,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var layout : vx_ui_ui.Type_layout = uistyle.layout()
                var name : vx_core.Type_string = uistyle.name()
                var flip : vx_ui_ui.Type_flip = uistyle.flip()
                var font : vx_ui_ui.Type_font = uistyle.font()
                var pin : vx_ui_ui.Type_pin = uistyle.pin()
                var pointorigin : vx_ui_ui.Type_point = uistyle.pointorigin()
                var pointpos : vx_ui_ui.Type_point = uistyle.pointpos()
                var pointsize : vx_ui_ui.Type_point = uistyle.pointsize()
                var pointrotate : vx_ui_ui.Type_point = uistyle.pointrotate()
                var styletype : vx_ui_ui.Type_styletype = uistyle.type()
                var color_bkg : vx_core.Type_string = uistyle.color_bkg()
                var color_bkghover : vx_core.Type_string = uistyle.color_bkghover()
                var color_border : vx_core.Type_string = uistyle.color_border()
                var color_font : vx_core.Type_string = uistyle.color_font()
                var cursor : vx_ui_ui.Type_cursor = uistyle.cursor()
                var hidden : vx_core.Type_boolean = uistyle.hidden()
                var align : vx_ui_ui.Type_align = uistyle.align()
                var scroll_x : vx_core.Type_boolean = uistyle.scroll_x()
                var scroll_y : vx_core.Type_boolean = uistyle.scroll_y()
                var posx : vx_core.Type_int = pointpos.x()
                var posy : vx_core.Type_int = pointpos.y()
                var postype : vx_ui_ui.Type_pointtype = pointpos.pointtype()
                var sizex : vx_core.Type_int = pointsize.x()
                var sizey : vx_core.Type_int = pointsize.y()
                var sizetype : vx_ui_ui.Type_pointtype = pointsize.pointtype()
                var stylename : vx_core.Type_string = vx_ui_html_uihtml.f_string_stylename_from_name_styletype(
                  name,
                  styletype
                )
                var bkgcolor : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_notempty(
                          color_bkg
                        )
                        output_5
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_6 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("#"),
                            color_bkg
                          )
                        )
                        output_6
                      })
                    )
                  )
                )
                var borderwidth : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_7 : vx_core.Type_any = vx_core.f_notempty(
                          color_border
                        )
                        output_7
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_8 : vx_core.Type_any = vx_core.vx_new_string("thin")
                        output_8
                      })
                    )
                  )
                )
                var bordercolor : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_9 : vx_core.Type_any = vx_core.f_notempty(
                          color_border
                        )
                        output_9
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_10 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("#"),
                            color_border
                          )
                        )
                        output_10
                      })
                    )
                  )
                )
                var borderstyle : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_11 : vx_core.Type_any = vx_core.f_notempty(
                          color_border
                        )
                        output_11
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_12 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("solid")
                          )
                        )
                        output_12
                      })
                    )
                  )
                )
                var fontcolor : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_13 : vx_core.Type_any = vx_core.f_notempty(
                          color_font
                        )
                        output_13
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_14 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("#"),
                            color_font
                          )
                        )
                        output_14
                      })
                    )
                  )
                )
                var position : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_15 : vx_core.Type_any = vx_core.f_or_1(
                          vx_core.vx_new(
                            vx_core.t_booleanlist,
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_app
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_background
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_main
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_navbar
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_parallax
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_statusbar
                            ),
                            vx_core.f_eqeq(
                              layout,
                              vx_ui_ui.c_layout_titlebar
                            )
                          )
                        )
                        output_15
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_16 : vx_core.Type_any = vx_core.vx_new_string("fixed")
                        output_16
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_17 : vx_core.Type_any = vx_core.f_eqeq(
                          postype,
                          vx_ui_ui.c_pointtype_relative
                        )
                        output_17
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_18 : vx_core.Type_any = vx_core.vx_new_string("relative")
                        output_18
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_19 : vx_core.Type_any = vx_core.f_eqeq(
                          postype,
                          vx_ui_ui.c_pointtype_absolute
                        )
                        output_19
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_20 : vx_core.Type_any = vx_core.vx_new_string("absolute")
                        output_20
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_21 : vx_core.Type_any = vx_core.f_notempty_1(
                          pointpos
                        )
                        output_21
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_22 : vx_core.Type_any = vx_core.vx_new_string("absolute")
                        output_22
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_23 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_23
                      })
                    )
                  )
                )
                var top : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_24 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_24
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_25 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            posy,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_25
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_26 : vx_core.Type_any = vx_core.f_eqeq(
                          vx_core.vx_new_int(0),
                          posy
                        )
                        output_26
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_27 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_27
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_28 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            posy,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_28
                      })
                    )
                  )
                )
                var bottom : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_29 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_29
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_30 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_30
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_31 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_bottom
                        )
                        output_31
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_32 : vx_core.Type_any = vx_core.vx_new_string("0mm")
                        output_32
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_33 : vx_core.Type_any = vx_core.f_or(
                          vx_core.f_eqeq(
                            pin,
                            vx_ui_ui.c_pin_left
                          ),
                          vx_core.f_eqeq(
                            pin,
                            vx_ui_ui.c_pin_center_v
                          )
                        )
                        output_33
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_34 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizey,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_34
                      })
                    )
                  )
                )
                var left : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_35 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_35
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_36 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_36
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_37 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_bottom
                        )
                        output_37
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_38 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            posx,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_38
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_39 : vx_core.Type_any = vx_core.f_eqeq(
                          vx_core.vx_new_int(0),
                          posx
                        )
                        output_39
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_40 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_40
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_41 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            posx,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_41
                      })
                    )
                  )
                )
                var right : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_42 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_42
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_43 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_43
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_44 : vx_core.Type_any = vx_core.f_or_1(
                          vx_core.vx_new(
                            vx_core.t_booleanlist,
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_top
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_bottom
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_center_v
                            )
                          )
                        )
                        output_44
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_45 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizex,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_45
                      })
                    )
                  )
                )
                var height : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_46 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_46
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_47 : vx_core.Type_any = vx_core.vx_new_string("100%")
                        output_47
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_48 : vx_core.Type_any = vx_core.f_or_1(
                          vx_core.vx_new(
                            vx_core.t_booleanlist,
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_left
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_right
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_center_v
                            )
                          )
                        )
                        output_48
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_49 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_49
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_50 : vx_core.Type_any = vx_core.f_eqeq(
                          sizetype,
                          vx_ui_ui.c_pointtype_percent
                        )
                        output_50
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_51 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizey,
                            vx_core.vx_new_string("%")
                          )
                        )
                        output_51
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_52 : vx_core.Type_any = vx_core.f_eqeq(
                          vx_core.vx_new_int(0),
                          sizey
                        )
                        output_52
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_53 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_53
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_54 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizey,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_54
                      })
                    )
                  )
                )
                var width : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_55 : vx_core.Type_any = vx_core.f_eqeq(
                          pin,
                          vx_ui_ui.c_pin_expand
                        )
                        output_55
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_56 : vx_core.Type_any = vx_core.vx_new_string("100%")
                        output_56
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_57 : vx_core.Type_any = vx_core.f_or_1(
                          vx_core.vx_new(
                            vx_core.t_booleanlist,
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_top
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_bottom
                            ),
                            vx_core.f_eqeq(
                              pin,
                              vx_ui_ui.c_pin_center_v
                            )
                          )
                        )
                        output_57
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_58 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_58
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_59 : vx_core.Type_any = vx_core.f_eqeq(
                          sizetype,
                          vx_ui_ui.c_pointtype_percent
                        )
                        output_59
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_60 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizex,
                            vx_core.vx_new_string("%")
                          )
                        )
                        output_60
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_61 : vx_core.Type_any = vx_core.f_eqeq(
                          vx_core.vx_new_int(0),
                          sizex
                        )
                        output_61
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_62 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_62
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_63 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            sizex,
                            vx_core.vx_new_string("mm")
                          )
                        )
                        output_63
                      })
                    )
                  )
                )
                var display : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_64 : vx_core.Type_any = hidden
                        output_64
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_65 : vx_core.Type_any = vx_core.vx_new_string("none")
                        output_65
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_66 : vx_core.Type_any = vx_core.f_eqeq(
                          layout,
                          vx_ui_ui.c_layout_flow_item
                        )
                        output_66
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_67 : vx_core.Type_any = vx_core.vx_new_string("inline-block")
                        output_67
                      })
                    )
                  )
                )
                var sfont : vx_core.Type_string = vx_ui_html_uihtml.f_string_style_from_font(
                  font
                )
                var gap : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_68 : vx_core.Type_any = vx_core.f_or(
                          vx_core.f_eqeq(
                            layout,
                            vx_ui_ui.c_layout_flow_columns
                          ),
                          vx_core.f_eqeq(
                            layout,
                            vx_ui_ui.c_layout_flow_rows
                          )
                        )
                        output_68
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_69 : vx_core.Type_any = vx_core.vx_new_string("1mm")
                        output_69
                      })
                    )
                  )
                )
                var overflowx : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_70 : vx_core.Type_any = scroll_x
                        output_70
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_71 : vx_core.Type_any = vx_core.vx_new_string("auto")
                        output_71
                      })
                    )
                  )
                )
                var overflowy : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_72 : vx_core.Type_any = scroll_y
                        output_72
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_73 : vx_core.Type_any = vx_core.vx_new_string("auto")
                        output_73
                      })
                    )
                  )
                )
                var hoverbkgrdcolor : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_74 : vx_core.Type_any = vx_core.f_ne(
                          vx_core.vx_new_string(""),
                          color_bkghover
                        )
                        output_74
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_75 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("#"),
                            color_bkghover
                          )
                        )
                        output_75
                      })
                    )
                  )
                )
                var scursor : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_76 : vx_core.Type_any = vx_core.f_eqeq(
                          cursor,
                          vx_ui_ui.t_cursor_pointer
                        )
                        output_76
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_77 : vx_core.Type_any = vx_core.vx_new_string("pointer")
                        output_77
                      })
                    )
                  )
                )
                var textalign : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_78 : vx_core.Type_any = vx_core.f_eqeq(
                          align,
                          vx_ui_ui.c_align_left
                        )
                        output_78
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_79 : vx_core.Type_any = vx_core.vx_new_string("left")
                        output_79
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_80 : vx_core.Type_any = vx_core.f_eqeq(
                          align,
                          vx_ui_ui.c_align_center
                        )
                        output_80
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_81 : vx_core.Type_any = vx_core.vx_new_string("center")
                        output_81
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_82 : vx_core.Type_any = vx_core.f_eqeq(
                          align,
                          vx_ui_ui.c_align_right
                        )
                        output_82
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_83 : vx_core.Type_any = vx_core.vx_new_string("right")
                        output_83
                      })
                    )
                  )
                )
                var transform_rotate : vx_core.Type_string = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_84 : vx_core.Type_any = vx_core.f_is_empty_1(
                          pointrotate
                        )
                        output_84
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_85 : vx_core.Type_any = vx_core.vx_new_string("")
                        output_85
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_86 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string("rotate("),
                            pointrotate.x(),
                            vx_core.vx_new_string("deg)")
                          )
                        )
                        output_86
                      })
                    )
                  )
                )
                var transform_scale : vx_core.Type_string = vx_core.f_switch(
                  vx_core.t_string,
                  flip,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_case_1(
                      vx_ui_ui.c_flip_x,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_87 : vx_core.Type_any = vx_core.vx_new_string("scale(-1, 1)")
                        output_87
                      })
                    ),
                    vx_core.f_case_1(
                      vx_ui_ui.c_flip_y,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_88 : vx_core.Type_any = vx_core.vx_new_string("scale( 1,-1)")
                        output_88
                      })
                    ),
                    vx_core.f_case_1(
                      vx_ui_ui.c_flip_xy,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_89 : vx_core.Type_any = vx_core.vx_new_string("scale(-1,-1)")
                        output_89
                      })
                    )
                  )
                )
                var transforms : vx_core.Type_stringlist = vx_core.f_new(
                  vx_core.t_stringlist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    transform_rotate,
                    transform_scale
                  )
                )
                var transform : vx_core.Type_string = vx_type.f_string_from_stringlist_join(
                  transforms,
                  vx_core.vx_new_string(" ")
                )
                var transformorigin : vx_core.Type_string = vx_core.f_switch(
                  vx_core.t_string,
                  pointorigin,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_case_1(
                      vx_ui_ui.c_point_center,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_90 : vx_core.Type_any = vx_core.vx_new_string("center")
                        output_90
                      })
                    ),
                    vx_core.f_case_1(
                      vx_ui_ui.c_point_lefttop,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_91 : vx_core.Type_any = vx_core.vx_new_string("left top")
                        output_91
                      })
                    ),
                    vx_core.f_case_1(
                      vx_ui_ui.c_point_rightbottom,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_92 : vx_core.Type_any = vx_core.vx_new_string("right bottom")
                        output_92
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_93 : vx_core.Type_any = vx_core.f_if_2(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_thenelselist,
                            vx_core.f_then(
                              vx_core.t_boolean_from_func.vx_fn_new({ ->
                                var output_94 : vx_core.Type_any = vx_core.f_is_empty_1(
                                  pointrotate
                                )
                                output_94
                              }),
                              vx_core.t_any_from_func.vx_fn_new({ ->
                                var output_95 : vx_core.Type_any = vx_core.vx_new_string("")
                                output_95
                              })
                            ),
                            vx_core.f_then(
                              vx_core.t_boolean_from_func.vx_fn_new({ ->
                                var output_96 : vx_core.Type_any = vx_core.f_eqeq(
                                  layout,
                                  vx_ui_ui.c_layout_label
                                )
                                output_96
                              }),
                              vx_core.t_any_from_func.vx_fn_new({ ->
                                var output_97 : vx_core.Type_any = vx_core.vx_new_string("left top")
                                output_97
                              })
                            )
                          )
                        )
                        output_93
                      })
                    )
                  )
                )
                var props : vx_web_html.Type_propmap = vx_core.f_new(
                  vx_web_html.t_propmap,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":background-color"),
                    bkgcolor,
                    vx_core.vx_new_string(":border-color"),
                    bordercolor,
                    vx_core.vx_new_string(":border-style"),
                    borderstyle,
                    vx_core.vx_new_string(":border-width"),
                    borderwidth,
                    vx_core.vx_new_string(":color"),
                    fontcolor,
                    vx_core.vx_new_string(":cursor"),
                    scursor,
                    vx_core.vx_new_string(":display"),
                    display,
                    vx_core.vx_new_string(":font"),
                    sfont,
                    vx_core.vx_new_string(":gap"),
                    gap,
                    vx_core.vx_new_string(":position"),
                    position,
                    vx_core.vx_new_string(":top"),
                    top,
                    vx_core.vx_new_string(":bottom"),
                    bottom,
                    vx_core.vx_new_string(":left"),
                    left,
                    vx_core.vx_new_string(":right"),
                    right,
                    vx_core.vx_new_string(":height"),
                    height,
                    vx_core.vx_new_string(":width"),
                    width,
                    vx_core.vx_new_string(":overflow-x"),
                    overflowx,
                    vx_core.vx_new_string(":overflow-y"),
                    overflowy,
                    vx_core.vx_new_string(":text-align"),
                    textalign,
                    vx_core.vx_new_string(":transform"),
                    transform,
                    vx_core.vx_new_string(":transform-origin"),
                    transformorigin
                  )
                )
                var hoverprops : vx_web_html.Type_propmap = vx_core.f_new(
                  vx_web_html.t_propmap,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":background-color"),
                    hoverbkgrdcolor
                  )
                )
                var substylelist : vx_web_html.Type_stylelist = vx_core.f_if_2(
                  vx_web_html.t_stylelist,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_98 : vx_core.Type_any = vx_core.f_notempty_1(
                          hoverprops
                        )
                        output_98
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_99 : vx_core.Type_any = vx_core.f_new(
                          vx_web_html.t_stylelist,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.f_new(
                              vx_web_html.t_style,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                vx_core.vx_new_string(":name"),
                                vx_core.vx_new_string("&:hover"),
                                vx_core.vx_new_string(":props"),
                                hoverprops
                              )
                            )
                          )
                        )
                        output_99
                      })
                    )
                  )
                )
                var output_4 : vx_core.Type_any = vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    stylename,
                    vx_core.vx_new_string(":props"),
                    props,
                    vx_core.vx_new_string(":stylelist"),
                    substylelist
                  )
                )
                output_4
              })
            )
            output_3
          })
        )
      )
    )
    return output
  }


  interface Func_stylelist_extra_from_ui : vx_core.Func_any_from_any {
    fun vx_stylelist_extra_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_stylelist
  }

  class Class_stylelist_extra_from_ui : vx_core.Class_base, Func_stylelist_extra_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_extra_from_ui = vx_ui_html_uihtml.Class_stylelist_extra_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_extra_from_ui = vx_ui_html_uihtml.Class_stylelist_extra_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-extra<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylelist_extra_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylelist_extra_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylelist_extra_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylelist_extra_from_ui(ui)
      return output
    }

    override fun vx_stylelist_extra_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_extra_from_ui(ui)
      return output
    }

  }

  val e_stylelist_extra_from_ui : vx_ui_html_uihtml.Func_stylelist_extra_from_ui = vx_ui_html_uihtml.Class_stylelist_extra_from_ui()
  val t_stylelist_extra_from_ui : vx_ui_html_uihtml.Func_stylelist_extra_from_ui = vx_ui_html_uihtml.Class_stylelist_extra_from_ui()

  fun f_stylelist_extra_from_ui(ui : vx_ui_ui.Type_ui) : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = vx_core.f_let(
      vx_web_html.t_stylelist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uistyles : vx_ui_ui.Type_stylelist = ui.stylelist()
        var selected : vx_core.Type_boolean = ui.selected()
        var hidden : vx_core.Type_boolean = ui.hidden()
        var styles1 : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylelist(
          uistyles
        )
        var styles2 : vx_web_html.Type_stylelist = vx_core.f_if_2(
          vx_web_html.t_stylelist,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = hidden
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_copy(
                  styles1,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_ui_html_uihtml.c_style_hidden
                  )
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = selected
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_copy(
                  styles1,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_ui_html_uihtml.c_style_selected
                  )
                )
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = styles1
                output_6
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = styles2
        output_1
      })
    )
    return output
  }


  interface Func_stylelist_reset : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_stylelist_reset() : vx_web_html.Type_stylelist
  }

  class Class_stylelist_reset : vx_core.Class_base, Func_stylelist_reset {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_reset = vx_ui_html_uihtml.Class_stylelist_reset()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_reset = vx_ui_html_uihtml.Class_stylelist_reset()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-reset", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylelist_reset
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylelist_reset
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_ui_html_uihtml.f_stylelist_reset()
      return output
    }

    override fun vx_stylelist_reset() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_reset()
      return output
    }

  }

  val e_stylelist_reset : vx_ui_html_uihtml.Func_stylelist_reset = vx_ui_html_uihtml.Class_stylelist_reset()
  val t_stylelist_reset : vx_ui_html_uihtml.Func_stylelist_reset = vx_ui_html_uihtml.Class_stylelist_reset()

  fun f_stylelist_reset() : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = vx_core.f_new(
      vx_web_html.t_stylelist,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("html"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":border"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":margin"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":padding"),
                vx_core.vx_new_string("0mm")
              )
            )
          )
        ),
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("body"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":border"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":margin"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":padding"),
                vx_core.vx_new_string("0mm")
              )
            )
          )
        ),
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("div"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":border"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":box-sizing"),
                vx_core.vx_new_string("border-box"),
                vx_core.vx_new_string(":margin"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":padding"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":position"),
                vx_core.vx_new_string("relative")
              )
            )
          )
        ),
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("img"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":border"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":display"),
                vx_core.vx_new_string("block"),
                vx_core.vx_new_string(":margin"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":padding"),
                vx_core.vx_new_string("0mm")
              )
            )
          )
        ),
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("p"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":margin-block-start"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":margin-block-end"),
                vx_core.vx_new_string("0mm"),
                vx_core.vx_new_string(":white-space"),
                vx_core.vx_new_string("pre-line")
              )
            )
          )
        ),
        vx_core.f_new(
          vx_web_html.t_style,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("*"),
            vx_core.vx_new_string(":props"),
            vx_core.f_new(
              vx_web_html.t_propmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":-webkit-print-color-adjust"),
                vx_core.vx_new_string("exact !important"),
                vx_core.vx_new_string(":color-adjust"),
                vx_core.vx_new_string("exact !important"),
                vx_core.vx_new_string(":print-color-adjust"),
                vx_core.vx_new_string("exact !important")
              )
            )
          )
        )
      )
    )
    return output
  }


  interface Func_stylelist_from_fontfacemap : vx_core.Func_any_from_any {
    fun vx_stylelist_from_fontfacemap(fontfacemap : vx_ui_ui.Type_fontfacemap) : vx_web_html.Type_stylelist
  }

  class Class_stylelist_from_fontfacemap : vx_core.Class_base, Func_stylelist_from_fontfacemap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_fontfacemap = vx_ui_html_uihtml.Class_stylelist_from_fontfacemap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_fontfacemap = vx_ui_html_uihtml.Class_stylelist_from_fontfacemap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-fontfacemap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylelist_from_fontfacemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylelist_from_fontfacemap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_fontfacemap = value as vx_ui_ui.Type_fontfacemap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylelist_from_fontfacemap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var fontfacemap : vx_ui_ui.Type_fontfacemap = vx_core.f_any_from_any(vx_ui_ui.t_fontfacemap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylelist_from_fontfacemap(fontfacemap)
      return output
    }

    override fun vx_stylelist_from_fontfacemap(fontfacemap : vx_ui_ui.Type_fontfacemap) : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_fontfacemap(fontfacemap)
      return output
    }

  }

  val e_stylelist_from_fontfacemap : vx_ui_html_uihtml.Func_stylelist_from_fontfacemap = vx_ui_html_uihtml.Class_stylelist_from_fontfacemap()
  val t_stylelist_from_fontfacemap : vx_ui_html_uihtml.Func_stylelist_from_fontfacemap = vx_ui_html_uihtml.Class_stylelist_from_fontfacemap()

  fun f_stylelist_from_fontfacemap(fontfacemap : vx_ui_ui.Type_fontfacemap) : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = vx_core.f_list_from_map_1(
      vx_web_html.t_stylelist,
      fontfacemap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, fontface_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var fontface : vx_ui_ui.Type_fontface = vx_core.f_any_from_any(vx_ui_ui.t_fontface, fontface_any)
        var output_1 : vx_core.Type_any = vx_ui_html_uihtml.f_style_from_fontface(
          fontface
        )
        output_1
      })
    )
    return output
  }


  interface Func_stylelist_from_stylelist : vx_core.Func_any_from_any {
    fun vx_stylelist_from_stylelist(uistylelist : vx_ui_ui.Type_stylelist) : vx_web_html.Type_stylelist
  }

  class Class_stylelist_from_stylelist : vx_core.Class_base, Func_stylelist_from_stylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_stylelist = vx_ui_html_uihtml.Class_stylelist_from_stylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_stylelist = vx_ui_html_uihtml.Class_stylelist_from_stylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylelist_from_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylelist_from_stylelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylelist = value as vx_ui_ui.Type_stylelist
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylelist_from_stylelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uistylelist : vx_ui_ui.Type_stylelist = vx_core.f_any_from_any(vx_ui_ui.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylelist_from_stylelist(uistylelist)
      return output
    }

    override fun vx_stylelist_from_stylelist(uistylelist : vx_ui_ui.Type_stylelist) : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylelist(uistylelist)
      return output
    }

  }

  val e_stylelist_from_stylelist : vx_ui_html_uihtml.Func_stylelist_from_stylelist = vx_ui_html_uihtml.Class_stylelist_from_stylelist()
  val t_stylelist_from_stylelist : vx_ui_html_uihtml.Func_stylelist_from_stylelist = vx_ui_html_uihtml.Class_stylelist_from_stylelist()

  fun f_stylelist_from_stylelist(uistylelist : vx_ui_ui.Type_stylelist) : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = vx_core.f_list_from_list_1(
      vx_web_html.t_stylelist,
      uistylelist,
      vx_ui_html_uihtml.t_style_from_style
    )
    return output
  }


  interface Func_stylelist_from_stylemap : vx_core.Func_any_from_any {
    fun vx_stylelist_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylelist
  }

  class Class_stylelist_from_stylemap : vx_core.Class_base, Func_stylelist_from_stylemap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_stylemap = vx_ui_html_uihtml.Class_stylelist_from_stylemap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylelist_from_stylemap = vx_ui_html_uihtml.Class_stylelist_from_stylemap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylemap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylelist_from_stylemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylelist_from_stylemap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylemap = value as vx_ui_ui.Type_stylemap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylelist_from_stylemap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uistylemap : vx_ui_ui.Type_stylemap = vx_core.f_any_from_any(vx_ui_ui.t_stylemap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylelist_from_stylemap(uistylemap)
      return output
    }

    override fun vx_stylelist_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylemap(uistylemap)
      return output
    }

  }

  val e_stylelist_from_stylemap : vx_ui_html_uihtml.Func_stylelist_from_stylemap = vx_ui_html_uihtml.Class_stylelist_from_stylemap()
  val t_stylelist_from_stylemap : vx_ui_html_uihtml.Func_stylelist_from_stylemap = vx_ui_html_uihtml.Class_stylelist_from_stylemap()

  fun f_stylelist_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = vx_core.f_list_from_map_1(
      vx_web_html.t_stylelist,
      uistylemap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_style = vx_core.f_any_from_any(vx_ui_ui.t_style, value_any)
        var output_1 : vx_core.Type_any = vx_ui_html_uihtml.f_style_from_style(
          value
        )
        output_1
      })
    )
    return output
  }


  interface Func_stylemap_from_stylemap : vx_core.Func_any_from_any {
    fun vx_stylemap_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylemap
  }

  class Class_stylemap_from_stylemap : vx_core.Class_base, Func_stylemap_from_stylemap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylemap_from_stylemap = vx_ui_html_uihtml.Class_stylemap_from_stylemap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylemap_from_stylemap = vx_ui_html_uihtml.Class_stylemap_from_stylemap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylemap<-stylemap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylemap_from_stylemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylemap_from_stylemap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylemap = value as vx_ui_ui.Type_stylemap
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylemap_from_stylemap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uistylemap : vx_ui_ui.Type_stylemap = vx_core.f_any_from_any(vx_ui_ui.t_stylemap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylemap_from_stylemap(uistylemap)
      return output
    }

    override fun vx_stylemap_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylemap {
      var output : vx_web_html.Type_stylemap = vx_ui_html_uihtml.f_stylemap_from_stylemap(uistylemap)
      return output
    }

  }

  val e_stylemap_from_stylemap : vx_ui_html_uihtml.Func_stylemap_from_stylemap = vx_ui_html_uihtml.Class_stylemap_from_stylemap()
  val t_stylemap_from_stylemap : vx_ui_html_uihtml.Func_stylemap_from_stylemap = vx_ui_html_uihtml.Class_stylemap_from_stylemap()

  fun f_stylemap_from_stylemap(uistylemap : vx_ui_ui.Type_stylemap) : vx_web_html.Type_stylemap {
    var output : vx_web_html.Type_stylemap = vx_web_html.e_stylemap
    output = vx_core.f_map_from_map_1(
      vx_web_html.t_stylemap,
      uistylemap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_style = vx_core.f_any_from_any(vx_ui_ui.t_style, value_any)
        var output_1 : vx_core.Type_any = vx_ui_html_uihtml.f_style_from_style(
          value
        )
        output_1
      })
    )
    return output
  }


  interface Func_stylesheet_layout_html : vx_core.Func_any_from_any_async {
    fun vx_stylesheet_layout_html(stylesheetui : vx_ui_ui.Type_stylesheet) : CompletableFuture<vx_ui_ui.Type_stylesheet>
  }

  class Class_stylesheet_layout_html : vx_core.Class_base, Func_stylesheet_layout_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylesheet_layout_html = vx_ui_html_uihtml.Class_stylesheet_layout_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylesheet_layout_html = vx_ui_html_uihtml.Class_stylesheet_layout_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-layout-html", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylesheet_layout_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylesheet_layout_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_ui_ui.Type_stylesheet = vx_core.f_any_from_any(vx_ui_ui.t_stylesheet, value)
      var future : CompletableFuture<vx_ui_ui.Type_stylesheet> = vx_ui_html_uihtml.f_stylesheet_layout_html(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var stylesheetui : vx_ui_ui.Type_stylesheet = vx_core.f_any_from_any(vx_ui_ui.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_ui_ui.Type_stylesheet> = vx_ui_html_uihtml.f_stylesheet_layout_html(stylesheetui)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_stylesheet_layout_html(stylesheetui : vx_ui_ui.Type_stylesheet) : CompletableFuture<vx_ui_ui.Type_stylesheet> {
      var output : CompletableFuture<vx_ui_ui.Type_stylesheet> = vx_ui_html_uihtml.f_stylesheet_layout_html(stylesheetui)
      return output
    }

  }

  val e_stylesheet_layout_html : vx_ui_html_uihtml.Func_stylesheet_layout_html = vx_ui_html_uihtml.Class_stylesheet_layout_html()
  val t_stylesheet_layout_html : vx_ui_html_uihtml.Func_stylesheet_layout_html = vx_ui_html_uihtml.Class_stylesheet_layout_html()

  fun f_stylesheet_layout_html(stylesheetui : vx_ui_ui.Type_stylesheet) : CompletableFuture<vx_ui_ui.Type_stylesheet> {
    var output : CompletableFuture<vx_ui_ui.Type_stylesheet> = vx_core.vx_async_new_from_value(vx_ui_ui.e_stylesheet)
    output = vx_core.f_let_async(
      vx_ui_ui.t_stylesheet,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var stylesheethtml : vx_web_html.Type_stylesheet = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(
          stylesheetui
        )
        var future_write : CompletableFuture<vx_core.Type_boolean> = vx_web_htmldoc.f_boolean_write_from_stylesheet(
          stylesheethtml
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_write, {write ->
          var output_2 : vx_core.Type_any = stylesheetui
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_stylesheet_from_stylesheet : vx_core.Func_any_from_any {
    fun vx_stylesheet_from_stylesheet(uistylesheet : vx_ui_ui.Type_stylesheet) : vx_web_html.Type_stylesheet
  }

  class Class_stylesheet_from_stylesheet : vx_core.Class_base, Func_stylesheet_from_stylesheet {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylesheet_from_stylesheet = vx_ui_html_uihtml.Class_stylesheet_from_stylesheet()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_stylesheet_from_stylesheet = vx_ui_html_uihtml.Class_stylesheet_from_stylesheet()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet<-stylesheet", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_headchild), // traits
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_stylesheet_from_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_stylesheet_from_stylesheet
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylesheet = value as vx_ui_ui.Type_stylesheet
      var outputval : vx_core.Type_any = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uistylesheet : vx_ui_ui.Type_stylesheet = vx_core.f_any_from_any(vx_ui_ui.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(uistylesheet)
      return output
    }

    override fun vx_stylesheet_from_stylesheet(uistylesheet : vx_ui_ui.Type_stylesheet) : vx_web_html.Type_stylesheet {
      var output : vx_web_html.Type_stylesheet = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(uistylesheet)
      return output
    }

  }

  val e_stylesheet_from_stylesheet : vx_ui_html_uihtml.Func_stylesheet_from_stylesheet = vx_ui_html_uihtml.Class_stylesheet_from_stylesheet()
  val t_stylesheet_from_stylesheet : vx_ui_html_uihtml.Func_stylesheet_from_stylesheet = vx_ui_html_uihtml.Class_stylesheet_from_stylesheet()

  fun f_stylesheet_from_stylesheet(uistylesheet : vx_ui_ui.Type_stylesheet) : vx_web_html.Type_stylesheet {
    var output : vx_web_html.Type_stylesheet = vx_web_html.e_stylesheet
    output = vx_core.f_let(
      vx_web_html.t_stylesheet,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uistylemap : vx_ui_ui.Type_stylemap = uistylesheet.stylemap()
        var fontfacemap : vx_ui_ui.Type_fontfacemap = uistylesheet.fontfacemap()
        var resetlist : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_reset()
        var fontstyles : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_fontfacemap(
          fontfacemap
        )
        var stylelist : vx_web_html.Type_stylelist = vx_ui_html_uihtml.f_stylelist_from_stylemap(
          uistylemap
        )
        var allstyles : vx_web_html.Type_stylelist = vx_core.f_new(
          vx_web_html.t_stylelist,
          vx_core.vx_new(
            vx_core.t_anylist,
            resetlist,
            fontstyles,
            stylelist
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_stylesheet,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":styles"),
            allstyles
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout_app_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_app_from_ui_orig_parent : vx_core.Class_base, Func_ui_layout_app_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_ui_layout_app_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_ui_layout_app_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_ui_layout_app_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_html_uihtml.f_ui_layout_app_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_app_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent()
  val t_ui_layout_app_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_app_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_app_from_ui_orig_parent()

  fun f_ui_layout_app_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var node : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_app_from_ui_orig_parent(
          ui,
          orig,
          parent
        )
        var nodechg : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(
          node,
          ui,
          parent
        )
        var iswrite : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout_default_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_default_from_ui_orig_parent : vx_core.Class_base, Func_ui_layout_default_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_ui_layout_default_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_ui_layout_default_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_ui_layout_default_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_html_uihtml.f_ui_layout_default_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_default_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent()
  val t_ui_layout_default_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_default_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_default_from_ui_orig_parent()

  fun f_ui_layout_default_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var node : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_default_from_ui_orig_parent(
          ui,
          orig,
          parent
        )
        var nodechg : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(
          node,
          ui,
          parent
        )
        var iswrite : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout_image_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_image_from_ui_orig_parent : vx_core.Class_base, Func_ui_layout_image_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-image<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_ui_layout_image_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_ui_layout_image_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_ui_layout_image_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_html_uihtml.f_ui_layout_image_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_image_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent()
  val t_ui_layout_image_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_image_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_image_from_ui_orig_parent()

  fun f_ui_layout_image_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var node : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_image_from_ui_orig_parent(
          ui,
          orig,
          parent
        )
        var nodechg : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(
          node,
          ui,
          parent
        )
        var iswrite : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout_label_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_label_from_ui_orig_parent : vx_core.Class_base, Func_ui_layout_label_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_html_uihtml.e_ui_layout_label_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_html_uihtml.t_ui_layout_label_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_html_uihtml.f_ui_layout_label_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_html_uihtml.f_ui_layout_label_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_label_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent()
  val t_ui_layout_label_from_ui_orig_parent : vx_ui_html_uihtml.Func_ui_layout_label_from_ui_orig_parent = vx_ui_html_uihtml.Class_ui_layout_label_from_ui_orig_parent()

  fun f_ui_layout_label_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var node : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_label_from_ui_orig_parent(
          ui,
          orig,
          parent
        )
        var nodechg : vx_web_html.Type_node = vx_ui_html_uihtml.f_node_layout_from_node_ui_parent(
          node,
          ui,
          parent
        )
        var iswrite : vx_core.Type_boolean = vx_ui_html_uihtml.f_boolean_writeeventsall_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  init {
    Const_layout_app_html.const_new(c_layout_app_html)
    Const_layout_else_html.const_new(c_layout_else_html)
    Const_layout_image_html.const_new(c_layout_image_html)
    Const_layout_label_html.const_new(c_layout_label_html)
    Const_layoutenginehtml.const_new(c_layoutenginehtml)
    Const_style_hidden.const_new(c_style_hidden)
    Const_style_selected.const_new(c_style_selected)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapconst.put("layout-app-html", vx_ui_html_uihtml.c_layout_app_html)
    mapconst.put("layout-else-html", vx_ui_html_uihtml.c_layout_else_html)
    mapconst.put("layout-image-html", vx_ui_html_uihtml.c_layout_image_html)
    mapconst.put("layout-label-html", vx_ui_html_uihtml.c_layout_label_html)
    mapconst.put("layoutenginehtml", vx_ui_html_uihtml.c_layoutenginehtml)
    mapconst.put("style-hidden", vx_ui_html_uihtml.c_style_hidden)
    mapconst.put("style-selected", vx_ui_html_uihtml.c_style_selected)
    mapfunc.put("boolean-layoutremove-html", vx_ui_html_uihtml.t_boolean_layoutremove_html)
    mapfunc.put("boolean-layoutselected-html", vx_ui_html_uihtml.t_boolean_layoutselected_html)
    mapfunc.put("boolean-layoutvisible-html", vx_ui_html_uihtml.t_boolean_layoutvisible_html)
    mapfunc.put("boolean-print-html", vx_ui_html_uihtml.t_boolean_print_html)
    mapfunc.put("boolean-writeclass<-ui", vx_ui_html_uihtml.t_boolean_writeclass_from_ui)
    mapfunc.put("boolean-writeeventsall<-ui", vx_ui_html_uihtml.t_boolean_writeeventsall_from_ui)
    mapfunc.put("boolean-writeeventsall<-uimap", vx_ui_html_uihtml.t_boolean_writeeventsall_from_uimap)
    mapfunc.put("boolean-writeselected<-ui", vx_ui_html_uihtml.t_boolean_writeselected_from_ui)
    mapfunc.put("boolean-writevisible<-ui", vx_ui_html_uihtml.t_boolean_writevisible_from_ui)
    mapfunc.put("context-write", vx_ui_html_uihtml.t_context_write)
    mapfunc.put("divchild<-ui", vx_ui_html_uihtml.t_divchild_from_ui)
    mapfunc.put("divchildlist<-uimap", vx_ui_html_uihtml.t_divchildlist_from_uimap)
    mapfunc.put("divchildlist<-uimap_1", vx_ui_html_uihtml.t_divchildlist_from_uimap_1)
    mapfunc.put("divchildlist<-uimap-origmap-parent", vx_ui_html_uihtml.t_divchildlist_from_uimap_origmap_parent)
    mapfunc.put("node-app<-ui-orig-parent", vx_ui_html_uihtml.t_node_app_from_ui_orig_parent)
    mapfunc.put("node-default<-ui-orig-parent", vx_ui_html_uihtml.t_node_default_from_ui_orig_parent)
    mapfunc.put("node-image<-ui-orig-parent", vx_ui_html_uihtml.t_node_image_from_ui_orig_parent)
    mapfunc.put("node-label<-ui-orig-parent", vx_ui_html_uihtml.t_node_label_from_ui_orig_parent)
    mapfunc.put("node-layout<-node-ui-parent", vx_ui_html_uihtml.t_node_layout_from_node_ui_parent)
    mapfunc.put("node<-ui-orig-parent", vx_ui_html_uihtml.t_node_from_ui_orig_parent)
    mapfunc.put("string-class<-ui", vx_ui_html_uihtml.t_string_class_from_ui)
    mapfunc.put("string-style<-font", vx_ui_html_uihtml.t_string_style_from_font)
    mapfunc.put("string-style<-image", vx_ui_html_uihtml.t_string_style_from_image)
    mapfunc.put("string-stylename<-name-styletype", vx_ui_html_uihtml.t_string_stylename_from_name_styletype)
    mapfunc.put("style<-fontface", vx_ui_html_uihtml.t_style_from_fontface)
    mapfunc.put("style<-style", vx_ui_html_uihtml.t_style_from_style)
    mapfunc.put("stylelist-extra<-ui", vx_ui_html_uihtml.t_stylelist_extra_from_ui)
    mapfunc.put("stylelist-reset", vx_ui_html_uihtml.t_stylelist_reset)
    mapfunc.put("stylelist<-fontfacemap", vx_ui_html_uihtml.t_stylelist_from_fontfacemap)
    mapfunc.put("stylelist<-stylelist", vx_ui_html_uihtml.t_stylelist_from_stylelist)
    mapfunc.put("stylelist<-stylemap", vx_ui_html_uihtml.t_stylelist_from_stylemap)
    mapfunc.put("stylemap<-stylemap", vx_ui_html_uihtml.t_stylemap_from_stylemap)
    mapfunc.put("stylesheet-layout-html", vx_ui_html_uihtml.t_stylesheet_layout_html)
    mapfunc.put("stylesheet<-stylesheet", vx_ui_html_uihtml.t_stylesheet_from_stylesheet)
    mapfunc.put("ui-layout-app<-ui-orig-parent", vx_ui_html_uihtml.t_ui_layout_app_from_ui_orig_parent)
    mapfunc.put("ui-layout-default<-ui-orig-parent", vx_ui_html_uihtml.t_ui_layout_default_from_ui_orig_parent)
    mapfunc.put("ui-layout-image<-ui-orig-parent", vx_ui_html_uihtml.t_ui_layout_image_from_ui_orig_parent)
    mapfunc.put("ui-layout-label<-ui-orig-parent", vx_ui_html_uihtml.t_ui_layout_label_from_ui_orig_parent)
    vx_core.vx_global_package_set("vx/ui/html/uihtml", maptype, mapconst, mapfunc)
  }

}
