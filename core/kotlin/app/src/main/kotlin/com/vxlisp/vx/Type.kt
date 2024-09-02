package com.vxlisp.vx

object vx_type {

  fun vx_boolean_from_string_ends(
    text : vx_core.Type_string,
    ends : vx_core.Type_string) : vx_core.Type_boolean {
    val check : Boolean = vx_core.vx_boolean_from_string_ends(
      text.vx_string(),
      ends.vx_string())
    val output : vx_core.Type_boolean = vx_core.vx_new_boolean(check)
    return output
  }

  fun vx_boolean_from_string_starts(
    text : vx_core.Type_string,
    starts : vx_core.Type_string) : vx_core.Type_boolean {
    val check : Boolean = vx_core.vx_boolean_from_string_starts(
      text.vx_string(),
      starts.vx_string()
    )
    val output = vx_core.vx_new_boolean(check)
    return output
  }

  // vx_int_from_string_find(string, string)
  fun vx_int_from_string_find(
    text : String,
    find : String) : Int {
    val output : Int = text.indexOf(find) + 1
    return output
  }

  // vx_int_from_string_find(string, string)
  fun vx_int_from_string_find(
    text : vx_core.Type_string,
    find : vx_core.Type_string) : vx_core.Type_int {
    val ipos : Int = vx_int_from_string_find(
      text.vx_string(), find.vx_string()
    )
    val output : vx_core.Type_int = vx_core.vx_new_int(ipos)
    return output
  }

  // vx_int_from_string_findkeyword(string, string)
  fun vx_int_from_string_findkeyword(
    text : String,
    find : String) : Int {
    var output : Int = -1
    if (text == "") {
    } else if (find == ":nonwhitespace") {
      val wschars1 : String = " \n\r\t"
      val ilen : Int = text.length
      for (i : Int in 0..ilen-1) {
        val cchar : Char = text[i]
        val pos : Int = wschars1.indexOf(cchar)
        if (pos < 0) {
          output = i
          break
        }
      }
    } else if (find == ":whitespace") {
      val wschars2 : String = " \n\r\t"
      for (cchar : Char in wschars2.iterator()) {
        val pos : Int = text.indexOf(cchar)
        if (pos < 0) {
        } else if (output < 0) {
          output = pos
        } else if (pos < output) {
          output = pos
        }
      }
    } else {
	     output = text.indexOf(find)
		  }
    output += 1
    return output
 	}

  // vx_int_from_string_findkeyword(string, string)
  fun vx_int_from_string_findkeyword(
    text : vx_core.Type_string,
    find : vx_core.Type_string) : vx_core.Type_int {
    val ipos : Int = vx_int_from_string_findkeyword(
      text.vx_string(),
      find.vx_string()
    )
    val output : vx_core.Type_int = vx_core.vx_new_int(ipos)
    return output
  }

  // vx_int_from_string_findlast(string, string)
  fun vx_int_from_string_findlast(
    text : String,
    findlast : String) : Int {
    val output = text.lastIndexOf(findlast) + 1
    return output
  }

  // vx_int_from_string_findlast(string, string)
  fun vx_int_from_string_findlast(
    text : vx_core.Type_string,
    findlast : vx_core.Type_string) : vx_core.Type_int {
    val ipos : Int = vx_int_from_string_findlast(
      text.vx_string(),
      findlast.vx_string()
    )
    val output : vx_core.Type_int = vx_core.vx_new_int(ipos)
    return output
  }

  // vx_string_from_string_start_end(string, int, int)
  fun vx_string_from_string_start_end(
    text : vx_core.Type_string,
    start : vx_core.Type_int,
    end : vx_core.Type_int) : vx_core.Type_string {
    val stext : String = vx_core.vx_string_from_string_start_end(
      text.vx_string(),
      start.vx_int(),
      end.vx_int()
    )
    val output = vx_core.vx_new_string(stext)
    return output
  }

  // vx_string_from_stringlist_join(stringlist, string)
  fun vx_string_from_stringlist_join(
    vals  : vx_core.Type_stringlist,
    delim : vx_core.Type_string) : vx_core.Type_string {
    val fn : (vx_core.Type_any) -> String = {item ->
      val valstring : vx_core.Type_string = vx_core.f_any_from_any(
        vx_core.t_string,
        item
      )
      val output_1 : String = valstring.vx_string()
      output_1
    }
    val listvalstring : List<String> = vx_core.arraylist_from_arraylist_fn(
      vals.vx_list(),
      fn
    )
    val sdelim : String = delim.vx_string()
    val stext : String = listvalstring.joinToString(separator = sdelim)
    val output : vx_core.Type_string = vx_core.vx_new_string(stext)
    return output
  }

  // vx_string_lowercase(string)
  fun vx_string_lowercase(
    text : vx_core.Type_string) : vx_core.Type_string {
    var stext : String = text.vx_string()
    stext = stext.toLowerCase()
    val output : vx_core.Type_string = vx_core.vx_new_string(stext)
    return output
  }

  // vx_string_trim(string)
  fun vx_string_trim(
    text : vx_core.Type_string) : vx_core.Type_string {
    var stext : String = text.vx_string()
    stext = stext.trim()
    val output : vx_core.Type_string = vx_core.vx_new_string(stext)
    return output
  }

  // vx_string_uppercase(string)
  fun vx_string_uppercase(
    text : vx_core.Type_string) : vx_core.Type_string {
    var stext : String = text.vx_string()
    stext = stext.toUpperCase()
    val output : vx_core.Type_string = vx_core.vx_new_string(stext)
    return output
  }

  fun vx_stringlist_from_string_split(
    text : vx_core.Type_string,
    delim : vx_core.Type_string) : vx_core.Type_stringlist {
    val stext : String = text.vx_string()
    val sdelim : String = delim.vx_string()
    val liststring : List<String> = stext.split(sdelim)
    val arraystring : Array<String> = liststring.toTypedArray()
    val output = vx_core.vx_new(vx_core.t_stringlist, *arraystring)
    return output
  }

  interface Func_allowtypenames_from_type : vx_core.Func_any_from_any {
    fun vx_allowtypenames_from_type(type : vx_core.Type_any) : vx_core.Type_stringlist
  }

  class Class_allowtypenames_from_type : vx_core.Class_base, Func_allowtypenames_from_type {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_allowtypenames_from_type = vx_type.Class_allowtypenames_from_type()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_allowtypenames_from_type = vx_type.Class_allowtypenames_from_type()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      var output : vx_core.Type_any = vx_type.e_allowtypenames_from_type
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_allowtypenames_from_type
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_allowtypenames_from_type(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var type : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_allowtypenames_from_type(type)
      return output
    }

    override fun vx_allowtypenames_from_type(type : vx_core.Type_any) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_type.f_allowtypenames_from_type(type)
      return output
    }

  }

  val e_allowtypenames_from_type : vx_type.Func_allowtypenames_from_type = vx_type.Class_allowtypenames_from_type()
  val t_allowtypenames_from_type : vx_type.Func_allowtypenames_from_type = vx_type.Class_allowtypenames_from_type()

  fun f_allowtypenames_from_type(type : vx_core.Type_any) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_type.f_allowtypes_from_type(
        type
      )
    )
    return output
  }


  interface Func_allowtypes_from_type : vx_core.Func_any_from_any {
    fun vx_allowtypes_from_type(type : vx_core.Type_any) : vx_core.Type_typelist
  }

  class Class_allowtypes_from_type : vx_core.Class_base, Func_allowtypes_from_type {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_allowtypes_from_type = vx_type.Class_allowtypes_from_type()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_allowtypes_from_type = vx_type.Class_allowtypes_from_type()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
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
      var output : vx_core.Type_any = vx_type.e_allowtypes_from_type
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_allowtypes_from_type
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_allowtypes_from_type(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var type : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_allowtypes_from_type(type)
      return output
    }

    override fun vx_allowtypes_from_type(type : vx_core.Type_any) : vx_core.Type_typelist {
      var output : vx_core.Type_typelist = vx_type.f_allowtypes_from_type(type)
      return output
    }

  }

  val e_allowtypes_from_type : vx_type.Func_allowtypes_from_type = vx_type.Class_allowtypes_from_type()
  val t_allowtypes_from_type : vx_type.Func_allowtypes_from_type = vx_type.Class_allowtypes_from_type()

  fun f_allowtypes_from_type(type : vx_core.Type_any) : vx_core.Type_typelist {
    var output : vx_core.Type_typelist = vx_core.e_typelist
    output = vx_core.f_typedef_from_type(
      type
    ).allowtypes()
    return output
  }


  interface Func_any_from_int : vx_core.Func_any_from_any {
    fun <T : vx_core.Type_any> vx_any_from_int(generic_any_1 : T, value : vx_core.Type_int) : T
  }

  class Class_any_from_int : vx_core.Class_base, Func_any_from_int {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_any_from_int = vx_type.Class_any_from_int()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_any_from_int = vx_type.Class_any_from_int()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "any<-int", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
      var output : vx_core.Type_any = vx_type.e_any_from_int
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_any_from_int
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_int = value as vx_core.Type_int
      var outputval : vx_core.Type_any = vx_type.f_any_from_int(vx_core.t_any, inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var value : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_any_from_int(generic_any_1, value)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_int(generic_any_1 : T, value : vx_core.Type_int) : T {
      var output : T = vx_type.f_any_from_int(generic_any_1, value)
      return output
    }

  }

  val e_any_from_int : vx_type.Func_any_from_int = vx_type.Class_any_from_int()
  val t_any_from_int : vx_type.Func_any_from_int = vx_type.Class_any_from_int()

  fun <T : vx_core.Type_any> f_any_from_int(generic_any_1 : T, value : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    return output
  }


  interface Func_boolean_from_string_ends : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_from_string_ends(text : vx_core.Type_string, ends : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_from_string_ends : vx_core.Class_base, Func_boolean_from_string_ends {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_boolean_from_string_ends = vx_type.Class_boolean_from_string_ends()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_boolean_from_string_ends = vx_type.Class_boolean_from_string_ends()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-ends", // name
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
      var output : vx_core.Type_any = vx_type.e_boolean_from_string_ends
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_boolean_from_string_ends
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var ends : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_boolean_from_string_ends(text, ends)
      return output
    }

    override fun vx_boolean_from_string_ends(text : vx_core.Type_string, ends : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_boolean_from_string_ends(text, ends)
      return output
    }

  }

  val e_boolean_from_string_ends : vx_type.Func_boolean_from_string_ends = vx_type.Class_boolean_from_string_ends()
  val t_boolean_from_string_ends : vx_type.Func_boolean_from_string_ends = vx_type.Class_boolean_from_string_ends()

  fun f_boolean_from_string_ends(text : vx_core.Type_string, ends : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_type.vx_boolean_from_string_ends(text, ends)
    return output
  }


  interface Func_boolean_from_string_starts : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_from_string_starts(text : vx_core.Type_string, starts : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_from_string_starts : vx_core.Class_base, Func_boolean_from_string_starts {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_boolean_from_string_starts = vx_type.Class_boolean_from_string_starts()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_boolean_from_string_starts = vx_type.Class_boolean_from_string_starts()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "boolean<-string-starts", // name
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
      var output : vx_core.Type_any = vx_type.e_boolean_from_string_starts
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_boolean_from_string_starts
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var starts : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_boolean_from_string_starts(text, starts)
      return output
    }

    override fun vx_boolean_from_string_starts(text : vx_core.Type_string, starts : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_boolean_from_string_starts(text, starts)
      return output
    }

  }

  val e_boolean_from_string_starts : vx_type.Func_boolean_from_string_starts = vx_type.Class_boolean_from_string_starts()
  val t_boolean_from_string_starts : vx_type.Func_boolean_from_string_starts = vx_type.Class_boolean_from_string_starts()

  fun f_boolean_from_string_starts(text : vx_core.Type_string, starts : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_type.vx_boolean_from_string_starts(text, starts)
    return output
  }


  interface Func_int_from_string_find : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_from_string_find(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_from_string_find : vx_core.Class_base, Func_int_from_string_find {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_find = vx_type.Class_int_from_string_find()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_find = vx_type.Class_int_from_string_find()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-find", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
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
      var output : vx_core.Type_any = vx_type.e_int_from_string_find
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_int_from_string_find
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_int_from_string_find(text, find)
      return output
    }

    override fun vx_int_from_string_find(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_type.f_int_from_string_find(text, find)
      return output
    }

  }

  val e_int_from_string_find : vx_type.Func_int_from_string_find = vx_type.Class_int_from_string_find()
  val t_int_from_string_find : vx_type.Func_int_from_string_find = vx_type.Class_int_from_string_find()

  fun f_int_from_string_find(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_type.vx_int_from_string_find(text, find)
    return output
  }


  interface Func_int_from_string_findkeyword : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_from_string_findkeyword(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_from_string_findkeyword : vx_core.Class_base, Func_int_from_string_findkeyword {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_findkeyword = vx_type.Class_int_from_string_findkeyword()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_findkeyword = vx_type.Class_int_from_string_findkeyword()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findkeyword", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
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
      var output : vx_core.Type_any = vx_type.e_int_from_string_findkeyword
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_int_from_string_findkeyword
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_int_from_string_findkeyword(text, find)
      return output
    }

    override fun vx_int_from_string_findkeyword(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_type.f_int_from_string_findkeyword(text, find)
      return output
    }

  }

  val e_int_from_string_findkeyword : vx_type.Func_int_from_string_findkeyword = vx_type.Class_int_from_string_findkeyword()
  val t_int_from_string_findkeyword : vx_type.Func_int_from_string_findkeyword = vx_type.Class_int_from_string_findkeyword()

  fun f_int_from_string_findkeyword(text : vx_core.Type_string, find : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_type.vx_int_from_string_findkeyword(text, find)
    return output
  }


  interface Func_int_from_string_findlast : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_from_string_findlast(text : vx_core.Type_string, findlast : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_from_string_findlast : vx_core.Class_base, Func_int_from_string_findlast {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_findlast = vx_type.Class_int_from_string_findlast()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_int_from_string_findlast = vx_type.Class_int_from_string_findlast()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "int<-string-findlast", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
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
      var output : vx_core.Type_any = vx_type.e_int_from_string_findlast
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_int_from_string_findlast
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var findlast : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_int_from_string_findlast(text, findlast)
      return output
    }

    override fun vx_int_from_string_findlast(text : vx_core.Type_string, findlast : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_type.f_int_from_string_findlast(text, findlast)
      return output
    }

  }

  val e_int_from_string_findlast : vx_type.Func_int_from_string_findlast = vx_type.Class_int_from_string_findlast()
  val t_int_from_string_findlast : vx_type.Func_int_from_string_findlast = vx_type.Class_int_from_string_findlast()

  fun f_int_from_string_findlast(text : vx_core.Type_string, findlast : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_type.vx_int_from_string_findlast(text, findlast)
    return output
  }


  interface Func_is_boolean : vx_core.Func_any_from_any {
    fun vx_is_boolean(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_boolean : vx_core.Class_base, Func_is_boolean {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_boolean = vx_type.Class_is_boolean()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_boolean = vx_type.Class_is_boolean()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-boolean", // name
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
      var output : vx_core.Type_any = vx_type.e_is_boolean
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_boolean
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_is_boolean(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_is_boolean(value)
      return output
    }

    override fun vx_is_boolean(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_boolean(value)
      return output
    }

  }

  val e_is_boolean : vx_type.Func_is_boolean = vx_type.Class_is_boolean()
  val t_is_boolean : vx_type.Func_is_boolean = vx_type.Class_is_boolean()

  fun f_is_boolean(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.vx_new_string("boolean"),
      vx_core.f_typename_from_any(
        value
      )
    )
    return output
  }


  interface Func_is_decimal : vx_core.Func_any_from_any {
    fun vx_is_decimal(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_decimal : vx_core.Class_base, Func_is_decimal {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_decimal = vx_type.Class_is_decimal()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_decimal = vx_type.Class_is_decimal()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-decimal", // name
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
      var output : vx_core.Type_any = vx_type.e_is_decimal
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_decimal
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_is_decimal(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_is_decimal(value)
      return output
    }

    override fun vx_is_decimal(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_decimal(value)
      return output
    }

  }

  val e_is_decimal : vx_type.Func_is_decimal = vx_type.Class_is_decimal()
  val t_is_decimal : vx_type.Func_is_decimal = vx_type.Class_is_decimal()

  fun f_is_decimal(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.vx_new_string("decimal"),
      vx_core.f_typename_from_any(
        value
      )
    )
    return output
  }


  interface Func_is_none : vx_core.Func_any_from_any {
    fun vx_is_none(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_none : vx_core.Class_base, Func_is_none {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_none = vx_type.Class_is_none()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_none = vx_type.Class_is_none()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-none", // name
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
      var output : vx_core.Type_any = vx_type.e_is_none
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_none
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_is_none(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_is_none(value)
      return output
    }

    override fun vx_is_none(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_none(value)
      return output
    }

  }

  val e_is_none : vx_type.Func_is_none = vx_type.Class_is_none()
  val t_is_none : vx_type.Func_is_none = vx_type.Class_is_none()

  fun f_is_none(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      value,
      vx_core.t_none
    )
    return output
  }


  interface Func_is_string : vx_core.Func_any_from_any {
    fun vx_is_string(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_string : vx_core.Class_base, Func_is_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_string = vx_type.Class_is_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_string = vx_type.Class_is_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-string", // name
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
      var output : vx_core.Type_any = vx_type.e_is_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_is_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_is_string(value)
      return output
    }

    override fun vx_is_string(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_string(value)
      return output
    }

  }

  val e_is_string : vx_type.Func_is_string = vx_type.Class_is_string()
  val t_is_string : vx_type.Func_is_string = vx_type.Class_is_string()

  fun f_is_string(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.vx_new_string("vx/core/string"),
      vx_core.f_typename_from_any(
        value
      )
    )
    return output
  }


  interface Func_is_type : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_is_type(value : vx_core.Type_any, type : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_type : vx_core.Class_base, Func_is_type {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_type = vx_type.Class_is_type()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_type = vx_type.Class_is_type()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-type", // name
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
      var output : vx_core.Type_any = vx_type.e_is_type
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_type
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var type : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_is_type(value, type)
      return output
    }

    override fun vx_is_type(value : vx_core.Type_any, type : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_type(value, type)
      return output
    }

  }

  val e_is_type : vx_type.Func_is_type = vx_type.Class_is_type()
  val t_is_type : vx_type.Func_is_type = vx_type.Class_is_type()

  fun f_is_type(value : vx_core.Type_any, type : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_or_1(
      vx_core.vx_new(
        vx_core.t_booleanlist,
        vx_core.f_eq(
          vx_core.f_typename_from_type(
            type
          ),
          vx_core.f_typename_from_any(
            value
          )
        ),
        vx_core.f_contains_1(
          vx_type.f_allowtypenames_from_type(
            type
          ),
          vx_core.f_typename_from_any(
            value
          )
        ),
        vx_core.f_contains_1(
          vx_type.f_traitnames_from_any(
            value
          ),
          vx_core.f_typename_from_type(
            type
          )
        )
      )
    )
    return output
  }


  interface Func_is_type_from_any_typelist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_is_type_from_any_typelist(value : vx_core.Type_any, typelist : vx_core.Type_typelist) : vx_core.Type_boolean
  }

  class Class_is_type_from_any_typelist : vx_core.Class_base, Func_is_type_from_any_typelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_type_from_any_typelist = vx_type.Class_is_type_from_any_typelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_is_type_from_any_typelist = vx_type.Class_is_type_from_any_typelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
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
      var output : vx_core.Type_any = vx_type.e_is_type_from_any_typelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_is_type_from_any_typelist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var typelist : vx_core.Type_typelist = vx_core.f_any_from_any(vx_core.t_typelist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_is_type_from_any_typelist(value, typelist)
      return output
    }

    override fun vx_is_type_from_any_typelist(value : vx_core.Type_any, typelist : vx_core.Type_typelist) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_type.f_is_type_from_any_typelist(value, typelist)
      return output
    }

  }

  val e_is_type_from_any_typelist : vx_type.Func_is_type_from_any_typelist = vx_type.Class_is_type_from_any_typelist()
  val t_is_type_from_any_typelist : vx_type.Func_is_type_from_any_typelist = vx_type.Class_is_type_from_any_typelist()

  fun f_is_type_from_any_typelist(value : vx_core.Type_any, typelist : vx_core.Type_typelist) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_any_from_list_start_reduce(
      vx_core.t_boolean,
      typelist,
      vx_core.vx_new_boolean(false),
      vx_core.t_any_from_reduce.vx_fn_new({result_any : vx_core.Type_any, type_any : vx_core.Type_any ->
        var result : vx_core.Type_boolean = vx_core.f_any_from_any(vx_core.t_boolean, result_any)
        var type : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, type_any)
        var output_1 : vx_core.Type_any = vx_core.f_or(
          result,
          vx_type.f_is_type(
            value,
            type
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_lowercase : vx_core.Func_any_from_any {
    fun vx_string_lowercase(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_lowercase : vx_core.Class_base, Func_string_lowercase {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_lowercase = vx_type.Class_string_lowercase()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_lowercase = vx_type.Class_string_lowercase()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string-lowercase", // name
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
      var output : vx_core.Type_any = vx_type.e_string_lowercase
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_lowercase
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_type.f_string_lowercase(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_string_lowercase(text)
      return output
    }

    override fun vx_string_lowercase(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_lowercase(text)
      return output
    }

  }

  val e_string_lowercase : vx_type.Func_string_lowercase = vx_type.Class_string_lowercase()
  val t_string_lowercase : vx_type.Func_string_lowercase = vx_type.Class_string_lowercase()

  fun f_string_lowercase(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.vx_string_lowercase(text)
    return output
  }


  interface Func_string_outdent : vx_core.Func_any_from_any {
    fun vx_string_outdent(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_outdent : vx_core.Class_base, Func_string_outdent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_outdent = vx_type.Class_string_outdent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_outdent = vx_type.Class_string_outdent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string-outdent", // name
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
      var output : vx_core.Type_any = vx_type.e_string_outdent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_outdent
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_type.f_string_outdent(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_string_outdent(text)
      return output
    }

    override fun vx_string_outdent(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_outdent(text)
      return output
    }

  }

  val e_string_outdent : vx_type.Func_string_outdent = vx_type.Class_string_outdent()
  val t_string_outdent : vx_type.Func_string_outdent = vx_type.Class_string_outdent()

  fun f_string_outdent(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pos : vx_core.Type_int = vx_type.f_int_from_string_findkeyword(
          text,
          vx_core.vx_new_string(":nonwhitespace")
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_int(0),
                  pos
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = text
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_let(
                  vx_core.t_string,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var indent : vx_core.Type_string = vx_type.f_string_from_string_end(
                      text,
                      vx_core.f_minus1(
                        pos
                      )
                    )
                    var rest : vx_core.Type_string = vx_type.f_string_from_string_start(
                      text,
                      pos
                    )
                    var linepos : vx_core.Type_int = vx_type.f_int_from_string_find(
                      indent,
                      vx_core.vx_new_string("\n")
                    )
                    var outdent : vx_core.Type_string = vx_core.f_if_1(
                      vx_core.t_string,
                      vx_core.f_eq(
                        vx_core.vx_new_int(0),
                        linepos
                      ),
                      vx_core.vx_new_string(""),
                      vx_core.vx_new_string("\n")
                    )
                    var output_5 : vx_core.Type_any = vx_core.f_string_from_string_find_replace(
                      rest,
                      indent,
                      outdent
                    )
                    output_5
                  })
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


  interface Func_string_trim : vx_core.Func_any_from_any {
    fun vx_string_trim(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_trim : vx_core.Class_base, Func_string_trim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_trim = vx_type.Class_string_trim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_trim = vx_type.Class_string_trim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string-trim", // name
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
      var output : vx_core.Type_any = vx_type.e_string_trim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_trim
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_type.f_string_trim(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_string_trim(text)
      return output
    }

    override fun vx_string_trim(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_trim(text)
      return output
    }

  }

  val e_string_trim : vx_type.Func_string_trim = vx_type.Class_string_trim()
  val t_string_trim : vx_type.Func_string_trim = vx_type.Class_string_trim()

  fun f_string_trim(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.vx_string_trim(text)
    return output
  }


  interface Func_string_uppercase : vx_core.Func_any_from_any {
    fun vx_string_uppercase(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_uppercase : vx_core.Class_base, Func_string_uppercase {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_uppercase = vx_type.Class_string_uppercase()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_uppercase = vx_type.Class_string_uppercase()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string-uppercase", // name
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
      var output : vx_core.Type_any = vx_type.e_string_uppercase
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_uppercase
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_type.f_string_uppercase(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_string_uppercase(text)
      return output
    }

    override fun vx_string_uppercase(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_uppercase(text)
      return output
    }

  }

  val e_string_uppercase : vx_type.Func_string_uppercase = vx_type.Class_string_uppercase()
  val t_string_uppercase : vx_type.Func_string_uppercase = vx_type.Class_string_uppercase()

  fun f_string_uppercase(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.vx_string_uppercase(text)
    return output
  }


  interface Func_string_from_int : vx_core.Func_any_from_any {
    fun vx_string_from_int(value : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_int : vx_core.Class_base, Func_string_from_int {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_int = vx_type.Class_string_from_int()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_int = vx_type.Class_string_from_int()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string<-int", // name
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
      var output : vx_core.Type_any = vx_type.e_string_from_int
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_from_int
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_int = value as vx_core.Type_int
      var outputval : vx_core.Type_any = vx_type.f_string_from_int(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_string_from_int(value)
      return output
    }

    override fun vx_string_from_int(value : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_from_int(value)
      return output
    }

  }

  val e_string_from_int : vx_type.Func_string_from_int = vx_type.Class_string_from_int()
  val t_string_from_int : vx_type.Func_string_from_int = vx_type.Class_string_from_int()

  fun f_string_from_int(value : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_switch(
      vx_core.t_string,
      value,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_core.c_infinity,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.vx_new_string("infinity")
            output_1
          })
        ),
        vx_core.f_case_1(
          vx_core.c_neginfinity,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.vx_new_string("neginfinity")
            output_2
          })
        ),
        vx_core.f_case_1(
          vx_core.c_notanumber,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.vx_new_string("notanumber")
            output_3
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                value
              )
            )
            output_4
          })
        )
      )
    )
    return output
  }


  interface Func_string_from_string_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_string_end(text : vx_core.Type_string, endpos : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_string_end : vx_core.Class_base, Func_string_from_string_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_end = vx_type.Class_string_from_string_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_end = vx_type.Class_string_from_string_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
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
      var output : vx_core.Type_any = vx_type.e_string_from_string_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_from_string_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var endpos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_string_from_string_end(text, endpos)
      return output
    }

    override fun vx_string_from_string_end(text : vx_core.Type_string, endpos : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_from_string_end(text, endpos)
      return output
    }

  }

  val e_string_from_string_end : vx_type.Func_string_from_string_end = vx_type.Class_string_from_string_end()
  val t_string_from_string_end : vx_type.Func_string_from_string_end = vx_type.Class_string_from_string_end()

  fun f_string_from_string_end(text : vx_core.Type_string, endpos : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(
      text,
      vx_core.vx_new_int(1),
      endpos
    )
    return output
  }


  interface Func_string_from_string_start : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_string_start(text : vx_core.Type_string, startpos : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_string_start : vx_core.Class_base, Func_string_from_string_start {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_start = vx_type.Class_string_from_string_start()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_start = vx_type.Class_string_from_string_start()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
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
      var output : vx_core.Type_any = vx_type.e_string_from_string_start
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_from_string_start
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var startpos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_string_from_string_start(text, startpos)
      return output
    }

    override fun vx_string_from_string_start(text : vx_core.Type_string, startpos : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_from_string_start(text, startpos)
      return output
    }

  }

  val e_string_from_string_start : vx_type.Func_string_from_string_start = vx_type.Class_string_from_string_start()
  val t_string_from_string_start : vx_type.Func_string_from_string_start = vx_type.Class_string_from_string_start()

  fun f_string_from_string_start(text : vx_core.Type_string, startpos : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(
      text,
      startpos,
      vx_core.f_length(
        text
      )
    )
    return output
  }


  interface Func_string_from_string_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_string_start_end(text : vx_core.Type_string, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_string_start_end : vx_core.Class_base, Func_string_from_string_start_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_start_end = vx_type.Class_string_from_string_start_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_string_start_end = vx_type.Class_string_from_string_start_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
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
      var output : vx_core.Type_any = vx_type.e_string_from_string_start_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_from_string_start_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_type.f_string_from_string_start_end(text, start, end)
      return output
    }

    override fun vx_string_from_string_start_end(text : vx_core.Type_string, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_from_string_start_end(text, start, end)
      return output
    }

  }

  val e_string_from_string_start_end : vx_type.Func_string_from_string_start_end = vx_type.Class_string_from_string_start_end()
  val t_string_from_string_start_end : vx_type.Func_string_from_string_start_end = vx_type.Class_string_from_string_start_end()

  fun f_string_from_string_start_end(text : vx_core.Type_string, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.vx_string_from_string_start_end(text, start, end)
    return output
  }


  interface Func_string_from_stringlist_join : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_stringlist_join(vals : vx_core.Type_stringlist, delim : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_from_stringlist_join : vx_core.Class_base, Func_string_from_stringlist_join {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_stringlist_join = vx_type.Class_string_from_stringlist_join()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_string_from_stringlist_join = vx_type.Class_string_from_stringlist_join()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
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
      var output : vx_core.Type_any = vx_type.e_string_from_stringlist_join
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_string_from_stringlist_join
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var vals : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_string_from_stringlist_join(vals, delim)
      return output
    }

    override fun vx_string_from_stringlist_join(vals : vx_core.Type_stringlist, delim : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_type.f_string_from_stringlist_join(vals, delim)
      return output
    }

  }

  val e_string_from_stringlist_join : vx_type.Func_string_from_stringlist_join = vx_type.Class_string_from_stringlist_join()
  val t_string_from_stringlist_join : vx_type.Func_string_from_stringlist_join = vx_type.Class_string_from_stringlist_join()

  fun f_string_from_stringlist_join(vals : vx_core.Type_stringlist, delim : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_type.vx_string_from_stringlist_join(vals, delim)
    return output
  }


  interface Func_stringlist_from_string_split : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_stringlist_from_string_split(text : vx_core.Type_string, delim : vx_core.Type_string) : vx_core.Type_stringlist
  }

  class Class_stringlist_from_string_split : vx_core.Class_base, Func_stringlist_from_string_split {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_stringlist_from_string_split = vx_type.Class_stringlist_from_string_split()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_stringlist_from_string_split = vx_type.Class_stringlist_from_string_split()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "stringlist<-string-split", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      var output : vx_core.Type_any = vx_type.e_stringlist_from_string_split
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_stringlist_from_string_split
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_type.f_stringlist_from_string_split(text, delim)
      return output
    }

    override fun vx_stringlist_from_string_split(text : vx_core.Type_string, delim : vx_core.Type_string) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_type.f_stringlist_from_string_split(text, delim)
      return output
    }

  }

  val e_stringlist_from_string_split : vx_type.Func_stringlist_from_string_split = vx_type.Class_stringlist_from_string_split()
  val t_stringlist_from_string_split : vx_type.Func_stringlist_from_string_split = vx_type.Class_stringlist_from_string_split()

  fun f_stringlist_from_string_split(text : vx_core.Type_string, delim : vx_core.Type_string) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_type.vx_stringlist_from_string_split(text, delim)
    return output
  }


  interface Func_traitnames_from_any : vx_core.Func_any_from_any {
    fun vx_traitnames_from_any(value : vx_core.Type_any) : vx_core.Type_stringlist
  }

  class Class_traitnames_from_any : vx_core.Class_base, Func_traitnames_from_any {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traitnames_from_any = vx_type.Class_traitnames_from_any()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traitnames_from_any = vx_type.Class_traitnames_from_any()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
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
      var output : vx_core.Type_any = vx_type.e_traitnames_from_any
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_traitnames_from_any
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_traitnames_from_any(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_traitnames_from_any(value)
      return output
    }

    override fun vx_traitnames_from_any(value : vx_core.Type_any) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_type.f_traitnames_from_any(value)
      return output
    }

  }

  val e_traitnames_from_any : vx_type.Func_traitnames_from_any = vx_type.Class_traitnames_from_any()
  val t_traitnames_from_any : vx_type.Func_traitnames_from_any = vx_type.Class_traitnames_from_any()

  fun f_traitnames_from_any(value : vx_core.Type_any) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_type.f_traits_from_any(
        value
      )
    )
    return output
  }


  interface Func_traits_from_any : vx_core.Func_any_from_any {
    fun vx_traits_from_any(value : vx_core.Type_any) : vx_core.Type_typelist
  }

  class Class_traits_from_any : vx_core.Class_base, Func_traits_from_any {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traits_from_any = vx_type.Class_traits_from_any()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traits_from_any = vx_type.Class_traits_from_any()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "traits<-any", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
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
      var output : vx_core.Type_any = vx_type.e_traits_from_any
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_traits_from_any
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_type.f_traits_from_any(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_traits_from_any(value)
      return output
    }

    override fun vx_traits_from_any(value : vx_core.Type_any) : vx_core.Type_typelist {
      var output : vx_core.Type_typelist = vx_type.f_traits_from_any(value)
      return output
    }

  }

  val e_traits_from_any : vx_type.Func_traits_from_any = vx_type.Class_traits_from_any()
  val t_traits_from_any : vx_type.Func_traits_from_any = vx_type.Class_traits_from_any()

  fun f_traits_from_any(value : vx_core.Type_any) : vx_core.Type_typelist {
    var output : vx_core.Type_typelist = vx_core.e_typelist
    output = vx_core.f_traits_from_typedef(
      vx_core.f_typedef_from_any(
        value
      )
    )
    return output
  }


  interface Func_traits_from_typedef : vx_core.Func_any_from_any {
    fun vx_traits_from_typedef(vtypedef : vx_core.Type_typedef) : vx_core.Type_typelist
  }

  class Class_traits_from_typedef : vx_core.Class_base, Func_traits_from_typedef {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traits_from_typedef = vx_type.Class_traits_from_typedef()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_type.Class_traits_from_typedef = vx_type.Class_traits_from_typedef()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/type", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
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
      var output : vx_core.Type_any = vx_type.e_traits_from_typedef
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_type.t_traits_from_typedef
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_typedef = value as vx_core.Type_typedef
      var outputval : vx_core.Type_any = vx_type.f_traits_from_typedef(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var vtypedef : vx_core.Type_typedef = vx_core.f_any_from_any(vx_core.t_typedef, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_type.f_traits_from_typedef(vtypedef)
      return output
    }

    override fun vx_traits_from_typedef(vtypedef : vx_core.Type_typedef) : vx_core.Type_typelist {
      var output : vx_core.Type_typelist = vx_type.f_traits_from_typedef(vtypedef)
      return output
    }

  }

  val e_traits_from_typedef : vx_type.Func_traits_from_typedef = vx_type.Class_traits_from_typedef()
  val t_traits_from_typedef : vx_type.Func_traits_from_typedef = vx_type.Class_traits_from_typedef()

  fun f_traits_from_typedef(vtypedef : vx_core.Type_typedef) : vx_core.Type_typelist {
    var output : vx_core.Type_typelist = vx_core.e_typelist
    output = vtypedef.traits()
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("allowtypenames<-type", vx_type.t_allowtypenames_from_type)
    mapfunc.put("allowtypes<-type", vx_type.t_allowtypes_from_type)
    mapfunc.put("any<-int", vx_type.t_any_from_int)
    mapfunc.put("boolean<-string-ends", vx_type.t_boolean_from_string_ends)
    mapfunc.put("boolean<-string-starts", vx_type.t_boolean_from_string_starts)
    mapfunc.put("int<-string-find", vx_type.t_int_from_string_find)
    mapfunc.put("int<-string-findkeyword", vx_type.t_int_from_string_findkeyword)
    mapfunc.put("int<-string-findlast", vx_type.t_int_from_string_findlast)
    mapfunc.put("is-boolean", vx_type.t_is_boolean)
    mapfunc.put("is-decimal", vx_type.t_is_decimal)
    mapfunc.put("is-none", vx_type.t_is_none)
    mapfunc.put("is-string", vx_type.t_is_string)
    mapfunc.put("is-type", vx_type.t_is_type)
    mapfunc.put("is-type<-any-typelist", vx_type.t_is_type_from_any_typelist)
    mapfunc.put("string-lowercase", vx_type.t_string_lowercase)
    mapfunc.put("string-outdent", vx_type.t_string_outdent)
    mapfunc.put("string-trim", vx_type.t_string_trim)
    mapfunc.put("string-uppercase", vx_type.t_string_uppercase)
    mapfunc.put("string<-int", vx_type.t_string_from_int)
    mapfunc.put("string<-string-end", vx_type.t_string_from_string_end)
    mapfunc.put("string<-string-start", vx_type.t_string_from_string_start)
    mapfunc.put("string<-string-start-end", vx_type.t_string_from_string_start_end)
    mapfunc.put("string<-stringlist-join", vx_type.t_string_from_stringlist_join)
    mapfunc.put("stringlist<-string-split", vx_type.t_stringlist_from_string_split)
    mapfunc.put("traitnames<-any", vx_type.t_traitnames_from_any)
    mapfunc.put("traits<-any", vx_type.t_traits_from_any)
    mapfunc.put("traits<-typedef", vx_type.t_traits_from_typedef)
    vx_core.vx_global_package_set("vx/type", maptype, mapconst, mapfunc)
  }

}
