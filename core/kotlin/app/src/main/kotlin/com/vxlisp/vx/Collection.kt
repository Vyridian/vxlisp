package com.vxlisp.vx

object vx_collection {

  fun <T : vx_core.Type_any> vx_any_from_for_until_loop_max(
    generic_any_1 : T,
    start : T,
    fn_until : vx_core.Func_boolean_from_any,
    fn_loop : vx_core.Func_any_from_any,
    max : vx_core.Type_int) : T {
    var output : T = start
    var iscontinue : Boolean = true
    var icount : Int = 0
    var imax : Int = max.vx_int()
    while (iscontinue) {
      if (icount >= imax) {
        val path : String = "vx/collection/any<-for-until-loop-max"
        val code : String = ":loopmaximumexceeded"
        val details : vx_core.Type_int = vx_core.vx_new_int(icount)
        val msg : vx_core.Type_msg = vx_core.vx_msg_from_error(path, code, details)
        output = vx_core.vx_copy(output, msg)
        iscontinue = false
      } else {
        icount += 1
        output = fn_loop.vx_any_from_any(generic_any_1, output)
        val valcontinue : vx_core.Type_boolean = fn_until.vx_boolean_from_any(output)
        iscontinue = !valcontinue.vx_boolean()
      }
    }
    return output
  }

  fun <T : vx_core.Type_any> vx_any_from_for_while_loop_max(
    generic_any_1 : T,
    start : T,
    fn_while : vx_core.Func_boolean_from_any,
    fn_loop : vx_core.Func_any_from_any,
    max : vx_core.Type_int) : T {
    var output : T = start
    var iscontinue : Boolean = true
    var icount : Int = 0
    val imax : Int = max.vx_int()
    while (iscontinue) {
      if (icount >= imax) {
        val path : String = "vx/collection/any<-for-while-loop-max"
        val code : String = ":loopmaximumexceeded"
        val details : vx_core.Type_int = vx_core.vx_new_int(icount)
        val msg : vx_core.Type_msg = vx_core.vx_msg_from_error(path, code, details)
        output = vx_core.vx_copy(output, msg)
        iscontinue = false
      } else {
        icount += 1
        val valcontinue : vx_core.Type_boolean = fn_while.vx_boolean_from_any(output)
        iscontinue = valcontinue.vx_boolean()
        if (iscontinue) {
          output = fn_loop.vx_any_from_any(generic_any_1, output)
        }
      }
    }
    return output
  }

  fun <T : vx_core.Type_list> vx_list_from_for_end_loop(
    generic_list_1 : T,
    start : vx_core.Type_int,
    end : vx_core.Type_int,
    fn_loop : vx_core.Func_any_from_int) : T {
    var output : T = vx_core.f_empty(generic_list_1)
    val listvals : MutableList<vx_core.Type_any> = ArrayList<vx_core.Type_any>()
    val istart : Int = start.vx_int()
    val iend : Int = end.vx_int()
    if (istart <= iend) {
      for (i : Int in istart..iend) {
        val value : vx_core.Type_any = fn_loop.vx_any_from_int(
          vx_core.t_any, vx_core.vx_new_int(i)
        )
        listvals.add(value)
      }
    } else {
      for (i : Int in istart..iend) {
        val value : vx_core.Type_any = fn_loop.vx_any_from_int(
          vx_core.t_any, vx_core.vx_new_int(i)
        )
        listvals.add(value)
      }
    }
    if (listvals.size > 0) {
      val anylist : vx_core.Type_anylist = vx_core.vx_new(vx_core.t_anylist, listvals)
      output = vx_core.f_new(generic_list_1, anylist)
    }
    return output
  }

  fun <T : vx_core.Type_list> vx_list_from_for_while_loop_max(
    generic_list_1 : T,
    start : vx_core.Type_any,
    fn_while : vx_core.Func_boolean_from_any,
    fn_loop : vx_core.Func_any_from_any,
    max : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_list_1)
    val listvals : MutableList<vx_core.Type_any> = ArrayList<vx_core.Type_any>()
    var iscontinue : Boolean = true
    var icount : Int = 0
    val imax : Int = max.vx_int()
    var work : vx_core.Type_any = start
    while (iscontinue) {
      if (icount >= imax) {
        val path : String = "vx/collection/list<-for-until-loop-max"
        val code : String = ":loopmaximumexceeded"
        val details : vx_core.Type_int = vx_core.vx_new_int(icount)
        val msg : vx_core.Type_msg = vx_core.vx_msg_from_error(path, code, details)
        output = vx_core.vx_copy(output, msg)
        iscontinue = false
      } else {
        val valwhile : vx_core.Type_boolean = fn_while.vx_boolean_from_any(work)
        iscontinue = !valwhile.vx_boolean()
        if (iscontinue) {
          icount += 1
          work = fn_loop.vx_any_from_any(vx_core.t_any, work)
          listvals.add(work)
        }
      }
    }
    if (listvals.size > 0) {
      val anylist : vx_core.Type_anylist = vx_core.vx_new(vx_core.t_anylist, listvals)
      output = vx_core.f_new(generic_list_1, anylist)
    }
    return output
  }

  fun <T : vx_core.Type_list> vx_list_from_list_filter(
    generic_list_1 : T,
    vallist : vx_core.Type_list,
    fn_filter : vx_core.Func_any_from_any) : T {
    var output : T = vx_core.f_empty(generic_list_1)
    val listval : List<vx_core.Type_any> = vallist.vx_list()
    val items : MutableList<vx_core.Type_any> = ArrayList<vx_core.Type_any>()
    for (value : vx_core.Type_any in listval) {
      val newval : vx_core.Type_any = fn_filter.vx_any_from_any(vx_core.t_any, value)
      val isempty : vx_core.Type_boolean = vx_core.f_is_empty_1(newval)
      if (!isempty.vx_boolean()) {
        items.add(newval)
      }
    }
    output = vx_core.vx_new(generic_list_1, items)
    return output
  }

  fun <T : vx_core.Type_list> vx_list_from_list_start_end(
    generic_list_1 : T,
    values : vx_core.Type_list,
    start : vx_core.Type_int,
    end : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_list_1)
    val istart : Int = start.vx_int()
    var iend : Int = end.vx_int()
    val listval : List<vx_core.Type_any> = values.vx_list()
    val maxlen : Int = listval.size
    if (iend < 0) {
     iend += maxlen
    }
    if (istart < 1) {
    } else if (istart > iend) {
    } else if (istart > maxlen) {
    } else {
      if (iend >= maxlen) {
        iend = maxlen
      }
      val listsub : List<vx_core.Type_any> = listval.subList(istart - 1, iend)
      output = vx_core.vx_new(generic_list_1, listsub)
    }
    return output
  }
  
  fun <T : vx_core.Type_map> vx_map_from_map_keys(
    generic_map_1 : T,
    valuemap : vx_core.Type_map,
    keys : vx_core.Type_stringlist) : T {
    var output : T = vx_core.f_empty(generic_map_1)
    val keylist : List<vx_core.Type_string> = keys.vx_liststring()
    if (keylist.size > 0) {
      val map : Map<String, vx_core.Type_any> = valuemap.vx_map()
      val values : MutableList<vx_core.Type_any> = ArrayList<vx_core.Type_any>()
      for (key : vx_core.Type_string in keylist) {
        val value : vx_core.Type_any? = map.get(key.vx_string())
        if (value != null) {
          values.add(key)
          values.add(value)
        }
      }
      val anyvalues : vx_core.Type_anylist = vx_core.vx_new_anylist(values)
      output = vx_core.f_new(generic_map_1, anyvalues)
    }
    return output
  }

  interface Func_any_from_for_until_loop : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any> vx_any_from_for_until_loop(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T
  }

  class Class_any_from_for_until_loop : vx_core.Class_base, Func_any_from_for_until_loop {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_until_loop = vx_collection.Class_any_from_for_until_loop()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_until_loop = vx_collection.Class_any_from_for_until_loop()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop", // name
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
      var output : vx_core.Type_any = vx_collection.e_any_from_for_until_loop
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_any_from_for_until_loop
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_until : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_for_until_loop(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T {
      var output : T = vx_collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop)
      return output
    }

  }

  val e_any_from_for_until_loop : vx_collection.Func_any_from_for_until_loop = vx_collection.Class_any_from_for_until_loop()
  val t_any_from_for_until_loop : vx_collection.Func_any_from_for_until_loop = vx_collection.Class_any_from_for_until_loop()

  fun <T : vx_core.Type_any> f_any_from_for_until_loop(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_until_loop_max(
      generic_any_1,
      start,
      fn_until,
      fn_loop,
      vx_core.vx_new_int(10000)
    )
    return output
  }


  interface Func_any_from_for_until_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any> vx_any_from_for_until_loop_max(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T
  }

  class Class_any_from_for_until_loop_max : vx_core.Class_base, Func_any_from_for_until_loop_max {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_until_loop_max = vx_collection.Class_any_from_for_until_loop_max()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_until_loop_max = vx_collection.Class_any_from_for_until_loop_max()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop-max", // name
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
      var output : vx_core.Type_any = vx_collection.e_any_from_for_until_loop_max
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_any_from_for_until_loop_max
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_until : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      var max : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_for_until_loop_max(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T {
      var output : T = vx_collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max)
      return output
    }

  }

  val e_any_from_for_until_loop_max : vx_collection.Func_any_from_for_until_loop_max = vx_collection.Class_any_from_for_until_loop_max()
  val t_any_from_for_until_loop_max : vx_collection.Func_any_from_for_until_loop_max = vx_collection.Class_any_from_for_until_loop_max()

  fun <T : vx_core.Type_any> f_any_from_for_until_loop_max(generic_any_1 : T, start : T, fn_until : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_collection.vx_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max)
    return output
  }


  interface Func_any_from_for_while_loop : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any> vx_any_from_for_while_loop(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T
  }

  class Class_any_from_for_while_loop : vx_core.Class_base, Func_any_from_for_while_loop {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_while_loop = vx_collection.Class_any_from_for_while_loop()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_while_loop = vx_collection.Class_any_from_for_while_loop()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop", // name
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
      var output : vx_core.Type_any = vx_collection.e_any_from_for_while_loop
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_any_from_for_while_loop
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_while : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_for_while_loop(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T {
      var output : T = vx_collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop)
      return output
    }

  }

  val e_any_from_for_while_loop : vx_collection.Func_any_from_for_while_loop = vx_collection.Class_any_from_for_while_loop()
  val t_any_from_for_while_loop : vx_collection.Func_any_from_for_while_loop = vx_collection.Class_any_from_for_while_loop()

  fun <T : vx_core.Type_any> f_any_from_for_while_loop(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_while_loop_max(
      generic_any_1,
      start,
      fn_while,
      fn_loop,
      vx_core.vx_new_int(1000)
    )
    return output
  }


  interface Func_any_from_for_while_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any> vx_any_from_for_while_loop_max(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T
  }

  class Class_any_from_for_while_loop_max : vx_core.Class_base, Func_any_from_for_while_loop_max {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_while_loop_max = vx_collection.Class_any_from_for_while_loop_max()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_for_while_loop_max = vx_collection.Class_any_from_for_while_loop_max()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop-max", // name
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
      var output : vx_core.Type_any = vx_collection.e_any_from_for_while_loop_max
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_any_from_for_while_loop_max
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_while : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      var max : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_for_while_loop_max(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T {
      var output : T = vx_collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max)
      return output
    }

  }

  val e_any_from_for_while_loop_max : vx_collection.Func_any_from_for_while_loop_max = vx_collection.Class_any_from_for_while_loop_max()
  val t_any_from_for_while_loop_max : vx_collection.Func_any_from_for_while_loop_max = vx_collection.Class_any_from_for_while_loop_max()

  fun <T : vx_core.Type_any> f_any_from_for_while_loop_max(generic_any_1 : T, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_collection.vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max)
    return output
  }


  interface Func_any_from_map_pos : vx_core.Type_func, vx_core.Type_replfunc {
    fun <N : vx_core.Type_map, T : vx_core.Type_any> vx_any_from_map_pos(generic_any_1 : T, map : N, pos : vx_core.Type_int) : T
  }

  class Class_any_from_map_pos : vx_core.Class_base, Func_any_from_map_pos {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_map_pos = vx_collection.Class_any_from_map_pos()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_any_from_map_pos = vx_collection.Class_any_from_map_pos()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-map-pos", // name
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
      var output : vx_core.Type_any = vx_collection.e_any_from_map_pos
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_any_from_map_pos
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var map : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var pos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_any_from_map_pos(generic_any_1, map, pos)
      return output
    }

    override fun <N : vx_core.Type_map, T : vx_core.Type_any> vx_any_from_map_pos(generic_any_1 : T, map : N, pos : vx_core.Type_int) : T {
      var output : T = vx_collection.f_any_from_map_pos(generic_any_1, map, pos)
      return output
    }

  }

  val e_any_from_map_pos : vx_collection.Func_any_from_map_pos = vx_collection.Class_any_from_map_pos()
  val t_any_from_map_pos : vx_collection.Func_any_from_map_pos = vx_collection.Class_any_from_map_pos()

  fun <N : vx_core.Type_map, T : vx_core.Type_any> f_any_from_map_pos(generic_any_1 : T, map : N, pos : vx_core.Type_int) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var keys : vx_core.Type_stringlist = vx_core.f_stringlist_from_map(
          map
        )
        var key : vx_core.Type_string = vx_core.f_any_from_list(
          vx_core.t_string,
          keys,
          pos
        )
        var output_1 : vx_core.Type_any = vx_core.f_any_from_map(
          generic_any_1,
          map,
          key
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_write_from_map_removekey : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_map_removekey(valuemap : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_map_removekey : vx_core.Class_base, Func_boolean_write_from_map_removekey {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_boolean_write_from_map_removekey = vx_collection.Class_boolean_write_from_map_removekey()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_boolean_write_from_map_removekey = vx_collection.Class_boolean_write_from_map_removekey()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekey", // name
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
      var output : vx_core.Type_any = vx_collection.e_boolean_write_from_map_removekey
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_boolean_write_from_map_removekey
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_boolean_write_from_map_removekey(valuemap, key)
      return output
    }

    override fun vx_boolean_write_from_map_removekey(valuemap : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_collection.f_boolean_write_from_map_removekey(valuemap, key)
      return output
    }

  }

  val e_boolean_write_from_map_removekey : vx_collection.Func_boolean_write_from_map_removekey = vx_collection.Class_boolean_write_from_map_removekey()
  val t_boolean_write_from_map_removekey : vx_collection.Func_boolean_write_from_map_removekey = vx_collection.Class_boolean_write_from_map_removekey()

  fun f_boolean_write_from_map_removekey(valuemap : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_boolean_write_from_map_name_value(
      valuemap,
      key,
      vx_core.f_empty(
        vx_core.t_any
      )
    )
    return output
  }


  interface Func_boolean_write_from_map_removekeys : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_map_removekeys(valuemap : vx_core.Type_map, keys : vx_core.Type_stringlist) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_map_removekeys : vx_core.Class_base, Func_boolean_write_from_map_removekeys {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_boolean_write_from_map_removekeys = vx_collection.Class_boolean_write_from_map_removekeys()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_boolean_write_from_map_removekeys = vx_collection.Class_boolean_write_from_map_removekeys()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekeys", // name
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
      var output : vx_core.Type_any = vx_collection.e_boolean_write_from_map_removekeys
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_boolean_write_from_map_removekeys
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var keys : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_boolean_write_from_map_removekeys(valuemap, keys)
      return output
    }

    override fun vx_boolean_write_from_map_removekeys(valuemap : vx_core.Type_map, keys : vx_core.Type_stringlist) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_collection.f_boolean_write_from_map_removekeys(valuemap, keys)
      return output
    }

  }

  val e_boolean_write_from_map_removekeys : vx_collection.Func_boolean_write_from_map_removekeys = vx_collection.Class_boolean_write_from_map_removekeys()
  val t_boolean_write_from_map_removekeys : vx_collection.Func_boolean_write_from_map_removekeys = vx_collection.Class_boolean_write_from_map_removekeys()

  fun f_boolean_write_from_map_removekeys(valuemap : vx_core.Type_map, keys : vx_core.Type_stringlist) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var writelist : vx_core.Type_booleanlist = vx_core.f_list_from_list_1(
          vx_core.t_booleanlist,
          keys,
          vx_core.t_any_from_any.vx_fn_new({key_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var output_2 : vx_core.Type_any = vx_collection.f_boolean_write_from_map_removekey(
              valuemap,
              key
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_core.f_and_1(
          writelist
        )
        output_1
      })
    )
    return output
  }


  interface Func_int_from_map_key : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_from_map_key(map : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_from_map_key : vx_core.Class_base, Func_int_from_map_key {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_int_from_map_key = vx_collection.Class_int_from_map_key()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_int_from_map_key = vx_collection.Class_int_from_map_key()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "int<-map-key", // name
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
      var output : vx_core.Type_any = vx_collection.e_int_from_map_key
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_int_from_map_key
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var map : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_int_from_map_key(map, key)
      return output
    }

    override fun vx_int_from_map_key(map : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_collection.f_int_from_map_key(map, key)
      return output
    }

  }

  val e_int_from_map_key : vx_collection.Func_int_from_map_key = vx_collection.Class_int_from_map_key()
  val t_int_from_map_key : vx_collection.Func_int_from_map_key = vx_collection.Class_int_from_map_key()

  fun f_int_from_map_key(map : vx_core.Type_map, key : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var keys : vx_core.Type_stringlist = vx_core.f_stringlist_from_map(
          map
        )
        var output_1 : vx_core.Type_any = vx_collection.f_int_from_stringlist_find(
          keys,
          key
        )
        output_1
      })
    )
    return output
  }


  interface Func_int_from_stringlist_find : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_from_stringlist_find(stringlist : vx_core.Type_stringlist, find : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_from_stringlist_find : vx_core.Class_base, Func_int_from_stringlist_find {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_int_from_stringlist_find = vx_collection.Class_int_from_stringlist_find()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_int_from_stringlist_find = vx_collection.Class_int_from_stringlist_find()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "int<-stringlist-find", // name
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
      var output : vx_core.Type_any = vx_collection.e_int_from_stringlist_find
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_int_from_stringlist_find
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stringlist : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_int_from_stringlist_find(stringlist, find)
      return output
    }

    override fun vx_int_from_stringlist_find(stringlist : vx_core.Type_stringlist, find : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_collection.f_int_from_stringlist_find(stringlist, find)
      return output
    }

  }

  val e_int_from_stringlist_find : vx_collection.Func_int_from_stringlist_find = vx_collection.Class_int_from_stringlist_find()
  val t_int_from_stringlist_find : vx_collection.Func_int_from_stringlist_find = vx_collection.Class_int_from_stringlist_find()

  fun f_int_from_stringlist_find(stringlist : vx_core.Type_stringlist, find : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var poslist : vx_core.Type_intlist = vx_core.f_list_from_list_intany(
          vx_core.t_intlist,
          stringlist,
          vx_core.t_any_from_int_any.vx_fn_new({pos_any : vx_core.Type_any, value_any : vx_core.Type_any ->
            var pos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, pos_any)
            var value : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value_any)
            var output_2 : vx_core.Type_any = vx_core.f_if_1(
              vx_core.t_int,
              vx_core.f_eq(
                find,
                value
              ),
              pos,
              vx_core.vx_new_int(0)
            )
            output_2
          })
        )
        var gt0list : vx_core.Type_intlist = vx_collection.f_list_from_list_filter(
          vx_core.t_intlist,
          poslist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, item_any)
            var output_3 : vx_core.Type_any = item
            output_3
          })
        )
        var output_1 : vx_core.Type_any = vx_core.f_first_from_list(
          vx_core.t_int,
          gt0list
        )
        output_1
      })
    )
    return output
  }


  interface Func_is_list : vx_core.Func_any_from_any {
    fun vx_is_list(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_list : vx_core.Class_base, Func_is_list {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_is_list = vx_collection.Class_is_list()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_is_list = vx_collection.Class_is_list()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "is-list", // name
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
      var output : vx_core.Type_any = vx_collection.e_is_list
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_is_list
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_collection.f_is_list(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_collection.f_is_list(value)
      return output
    }

    override fun vx_is_list(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_collection.f_is_list(value)
      return output
    }

  }

  val e_is_list : vx_collection.Func_is_list = vx_collection.Class_is_list()
  val t_is_list : vx_collection.Func_is_list = vx_collection.Class_is_list()

  fun f_is_list(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.vx_new_string(":list"),
      vx_core.f_extends_from_any(
        value
      )
    )
    return output
  }


  interface Func_is_map : vx_core.Func_any_from_any {
    fun vx_is_map(value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_is_map : vx_core.Class_base, Func_is_map {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_is_map = vx_collection.Class_is_map()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_is_map = vx_collection.Class_is_map()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "is-map", // name
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
      var output : vx_core.Type_any = vx_collection.e_is_map
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_is_map
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_collection.f_is_map(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_collection.f_is_map(value)
      return output
    }

    override fun vx_is_map(value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_collection.f_is_map(value)
      return output
    }

  }

  val e_is_map : vx_collection.Func_is_map = vx_collection.Class_is_map()
  val t_is_map : vx_collection.Func_is_map = vx_collection.Class_is_map()

  fun f_is_map(value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.vx_new_string(":map"),
      vx_core.f_extends_from_any(
        value
      )
    )
    return output
  }


  interface Func_list_from_for_end_loop : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list> vx_list_from_for_end_loop(generic_list_1 : X, start : vx_core.Type_int, end : vx_core.Type_int, fn_loop : vx_core.Func_any_from_int) : X
  }

  class Class_list_from_for_end_loop : vx_core.Class_base, Func_list_from_for_end_loop {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_end_loop = vx_collection.Class_list_from_for_end_loop()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_end_loop = vx_collection.Class_list_from_for_end_loop()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-end-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_for_end_loop
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_for_end_loop
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_int = vx_core.f_any_from_any(vx_core.t_any_from_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop)
      return output
    }

    override fun <X : vx_core.Type_list> vx_list_from_for_end_loop(generic_list_1 : X, start : vx_core.Type_int, end : vx_core.Type_int, fn_loop : vx_core.Func_any_from_int) : X {
      var output : X = vx_collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop)
      return output
    }

  }

  val e_list_from_for_end_loop : vx_collection.Func_list_from_for_end_loop = vx_collection.Class_list_from_for_end_loop()
  val t_list_from_for_end_loop : vx_collection.Func_list_from_for_end_loop = vx_collection.Class_list_from_for_end_loop()

  fun <X : vx_core.Type_list> f_list_from_for_end_loop(generic_list_1 : X, start : vx_core.Type_int, end : vx_core.Type_int, fn_loop : vx_core.Func_any_from_int) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop)
    return output
  }


  interface Func_list_from_for_while_loop : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any, X : vx_core.Type_list> vx_list_from_for_while_loop(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : X
  }

  class Class_list_from_for_while_loop : vx_core.Class_base, Func_list_from_for_while_loop {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_while_loop = vx_collection.Class_list_from_for_while_loop()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_while_loop = vx_collection.Class_list_from_for_while_loop()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_for_while_loop
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_for_while_loop
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_while : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop)
      return output
    }

    override fun <T : vx_core.Type_any, X : vx_core.Type_list> vx_list_from_for_while_loop(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : X {
      var output : X = vx_collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop)
      return output
    }

  }

  val e_list_from_for_while_loop : vx_collection.Func_list_from_for_while_loop = vx_collection.Class_list_from_for_while_loop()
  val t_list_from_for_while_loop : vx_collection.Func_list_from_for_while_loop = vx_collection.Class_list_from_for_while_loop()

  fun <T : vx_core.Type_any, X : vx_core.Type_list> f_list_from_for_while_loop(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_for_while_loop_max(
      generic_list_1,
      start,
      fn_while,
      fn_loop,
      vx_core.vx_new_int(1000)
    )
    return output
  }


  interface Func_list_from_for_while_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any, X : vx_core.Type_list> vx_list_from_for_while_loop_max(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : X
  }

  class Class_list_from_for_while_loop_max : vx_core.Class_base, Func_list_from_for_while_loop_max {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_while_loop_max = vx_collection.Class_list_from_for_while_loop_max()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_for_while_loop_max = vx_collection.Class_list_from_for_while_loop_max()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop-max", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_for_while_loop_max
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_for_while_loop_max
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_while : vx_core.Func_boolean_from_any = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      var fn_loop : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)))
      var max : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max)
      return output
    }

    override fun <T : vx_core.Type_any, X : vx_core.Type_list> vx_list_from_for_while_loop_max(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : X {
      var output : X = vx_collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max)
      return output
    }

  }

  val e_list_from_for_while_loop_max : vx_collection.Func_list_from_for_while_loop_max = vx_collection.Class_list_from_for_while_loop_max()
  val t_list_from_for_while_loop_max : vx_collection.Func_list_from_for_while_loop_max = vx_collection.Class_list_from_for_while_loop_max()

  fun <T : vx_core.Type_any, X : vx_core.Type_list> f_list_from_for_while_loop_max(generic_list_1 : X, start : T, fn_while : vx_core.Func_boolean_from_any, fn_loop : vx_core.Func_any_from_any, max : vx_core.Type_int) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max)
    return output
  }


  interface Func_list_from_list_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list> vx_list_from_list_end(generic_list_1 : X, values : X, end : vx_core.Type_int) : X
  }

  class Class_list_from_list_end : vx_core.Class_base, Func_list_from_list_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_end = vx_collection.Class_list_from_list_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_end = vx_collection.Class_list_from_list_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_list_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_list_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var values : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_list_from_list_end(generic_list_1, values, end)
      return output
    }

    override fun <X : vx_core.Type_list> vx_list_from_list_end(generic_list_1 : X, values : X, end : vx_core.Type_int) : X {
      var output : X = vx_collection.f_list_from_list_end(generic_list_1, values, end)
      return output
    }

  }

  val e_list_from_list_end : vx_collection.Func_list_from_list_end = vx_collection.Class_list_from_list_end()
  val t_list_from_list_end : vx_collection.Func_list_from_list_end = vx_collection.Class_list_from_list_end()

  fun <X : vx_core.Type_list> f_list_from_list_end(generic_list_1 : X, values : X, end : vx_core.Type_int) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end(
      generic_list_1,
      values,
      vx_core.vx_new_int(1),
      end
    )
    return output
  }


  interface Func_list_from_list_filter : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list, Y : vx_core.Type_list> vx_list_from_list_filter(generic_list_1 : X, vallist : Y, fn_filter : vx_core.Func_any_from_any) : X
  }

  class Class_list_from_list_filter : vx_core.Class_base, Func_list_from_list_filter {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_filter = vx_collection.Class_list_from_list_filter()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_filter = vx_collection.Class_list_from_list_filter()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filter", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_list_filter
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_list_filter
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var vallist : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_filter : vx_core.Func_any_from_any = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter)
      return output
    }

    override fun <X : vx_core.Type_list, Y : vx_core.Type_list> vx_list_from_list_filter(generic_list_1 : X, vallist : Y, fn_filter : vx_core.Func_any_from_any) : X {
      var output : X = vx_collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter)
      return output
    }

  }

  val e_list_from_list_filter : vx_collection.Func_list_from_list_filter = vx_collection.Class_list_from_list_filter()
  val t_list_from_list_filter : vx_collection.Func_list_from_list_filter = vx_collection.Class_list_from_list_filter()

  fun <X : vx_core.Type_list, Y : vx_core.Type_list> f_list_from_list_filter(generic_list_1 : X, vallist : Y, fn_filter : vx_core.Func_any_from_any) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_filter(generic_list_1, vallist, fn_filter)
    return output
  }


  interface Func_list_from_list_filtertypes : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list, Y : vx_core.Type_list> vx_list_from_list_filtertypes(generic_list_1 : X, vallist : Y, filtertypes : vx_core.Type_typelist) : X
  }

  class Class_list_from_list_filtertypes : vx_core.Class_base, Func_list_from_list_filtertypes {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_filtertypes = vx_collection.Class_list_from_list_filtertypes()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_filtertypes = vx_collection.Class_list_from_list_filtertypes()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_list_filtertypes
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_list_filtertypes
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var vallist : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var filtertypes : vx_core.Type_typelist = vx_core.f_any_from_any(vx_core.t_typelist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes)
      return output
    }

    override fun <X : vx_core.Type_list, Y : vx_core.Type_list> vx_list_from_list_filtertypes(generic_list_1 : X, vallist : Y, filtertypes : vx_core.Type_typelist) : X {
      var output : X = vx_collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes)
      return output
    }

  }

  val e_list_from_list_filtertypes : vx_collection.Func_list_from_list_filtertypes = vx_collection.Class_list_from_list_filtertypes()
  val t_list_from_list_filtertypes : vx_collection.Func_list_from_list_filtertypes = vx_collection.Class_list_from_list_filtertypes()

  fun <X : vx_core.Type_list, Y : vx_core.Type_list> f_list_from_list_filtertypes(generic_list_1 : X, vallist : Y, filtertypes : vx_core.Type_typelist) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_filter(
      generic_list_1,
      vallist,
      vx_core.t_any_from_any.vx_fn_new({value_any : vx_core.Type_any ->
        var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, value_any)
        var output_1 : vx_core.Type_any = vx_core.f_if(
          vx_core.t_any,
          vx_type.f_is_type_from_any_typelist(
            value,
            filtertypes
          ),
          value
        )
        output_1
      })
    )
    return output
  }


  interface Func_list_from_list_start : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list> vx_list_from_list_start(generic_list_1 : X, values : X, start : vx_core.Type_int) : X
  }

  class Class_list_from_list_start : vx_core.Class_base, Func_list_from_list_start {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_start = vx_collection.Class_list_from_list_start()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_start = vx_collection.Class_list_from_list_start()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_list_start
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_list_start
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var values : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_list_from_list_start(generic_list_1, values, start)
      return output
    }

    override fun <X : vx_core.Type_list> vx_list_from_list_start(generic_list_1 : X, values : X, start : vx_core.Type_int) : X {
      var output : X = vx_collection.f_list_from_list_start(generic_list_1, values, start)
      return output
    }

  }

  val e_list_from_list_start : vx_collection.Func_list_from_list_start = vx_collection.Class_list_from_list_start()
  val t_list_from_list_start : vx_collection.Func_list_from_list_start = vx_collection.Class_list_from_list_start()

  fun <X : vx_core.Type_list> f_list_from_list_start(generic_list_1 : X, values : X, start : vx_core.Type_int) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end(
      generic_list_1,
      values,
      start,
      vx_core.f_length_1(
        values
      )
    )
    return output
  }


  interface Func_list_from_list_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun <X : vx_core.Type_list> vx_list_from_list_start_end(generic_list_1 : X, values : X, start : vx_core.Type_int, end : vx_core.Type_int) : X
  }

  class Class_list_from_list_start_end : vx_core.Class_base, Func_list_from_list_start_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_start_end = vx_collection.Class_list_from_list_start_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_list_from_list_start_end = vx_collection.Class_list_from_list_start_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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
      var output : vx_core.Type_any = vx_collection.e_list_from_list_start_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_list_from_list_start_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_list_1 : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var values : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_list_from_list_start_end(generic_list_1, values, start, end)
      return output
    }

    override fun <X : vx_core.Type_list> vx_list_from_list_start_end(generic_list_1 : X, values : X, start : vx_core.Type_int, end : vx_core.Type_int) : X {
      var output : X = vx_collection.f_list_from_list_start_end(generic_list_1, values, start, end)
      return output
    }

  }

  val e_list_from_list_start_end : vx_collection.Func_list_from_list_start_end = vx_collection.Class_list_from_list_start_end()
  val t_list_from_list_start_end : vx_collection.Func_list_from_list_start_end = vx_collection.Class_list_from_list_start_end()

  fun <X : vx_core.Type_list> f_list_from_list_start_end(generic_list_1 : X, values : X, start : vx_core.Type_int, end : vx_core.Type_int) : X {
    var output : X = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_start_end(generic_list_1, values, start, end)
    return output
  }


  interface Func_map_from_map_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun <N : vx_core.Type_map> vx_map_from_map_end(generic_map_1 : N, valuemap : N, end : vx_core.Type_int) : N
  }

  class Class_map_from_map_end : vx_core.Class_base, Func_map_from_map_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_end = vx_collection.Class_map_from_map_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_end = vx_collection.Class_map_from_map_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
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
      var output : vx_core.Type_any = vx_collection.e_map_from_map_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_map_from_map_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_map_1 : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_map_from_map_end(generic_map_1, valuemap, end)
      return output
    }

    override fun <N : vx_core.Type_map> vx_map_from_map_end(generic_map_1 : N, valuemap : N, end : vx_core.Type_int) : N {
      var output : N = vx_collection.f_map_from_map_end(generic_map_1, valuemap, end)
      return output
    }

  }

  val e_map_from_map_end : vx_collection.Func_map_from_map_end = vx_collection.Class_map_from_map_end()
  val t_map_from_map_end : vx_collection.Func_map_from_map_end = vx_collection.Class_map_from_map_end()

  fun <N : vx_core.Type_map> f_map_from_map_end(generic_map_1 : N, valuemap : N, end : vx_core.Type_int) : N {
    var output : N = vx_core.f_empty(generic_map_1)
    output = vx_collection.f_map_from_map_start_end(
      generic_map_1,
      valuemap,
      vx_core.vx_new_int(1),
      end
    )
    return output
  }


  interface Func_map_from_map_keys : vx_core.Type_func, vx_core.Type_replfunc {
    fun <N : vx_core.Type_map> vx_map_from_map_keys(generic_map_1 : N, valuemap : N, keys : vx_core.Type_stringlist) : N
  }

  class Class_map_from_map_keys : vx_core.Class_base, Func_map_from_map_keys {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_keys = vx_collection.Class_map_from_map_keys()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_keys = vx_collection.Class_map_from_map_keys()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-keys", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
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
      var output : vx_core.Type_any = vx_collection.e_map_from_map_keys
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_map_from_map_keys
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_map_1 : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var keys : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_map_from_map_keys(generic_map_1, valuemap, keys)
      return output
    }

    override fun <N : vx_core.Type_map> vx_map_from_map_keys(generic_map_1 : N, valuemap : N, keys : vx_core.Type_stringlist) : N {
      var output : N = vx_collection.f_map_from_map_keys(generic_map_1, valuemap, keys)
      return output
    }

  }

  val e_map_from_map_keys : vx_collection.Func_map_from_map_keys = vx_collection.Class_map_from_map_keys()
  val t_map_from_map_keys : vx_collection.Func_map_from_map_keys = vx_collection.Class_map_from_map_keys()

  fun <N : vx_core.Type_map> f_map_from_map_keys(generic_map_1 : N, valuemap : N, keys : vx_core.Type_stringlist) : N {
    var output : N = vx_core.f_empty(generic_map_1)
    output = vx_collection.vx_map_from_map_keys(generic_map_1, valuemap, keys)
    return output
  }


  interface Func_map_from_map_start : vx_core.Type_func, vx_core.Type_replfunc {
    fun <N : vx_core.Type_map> vx_map_from_map_start(generic_map_1 : N, valuemap : N, start : vx_core.Type_int) : N
  }

  class Class_map_from_map_start : vx_core.Class_base, Func_map_from_map_start {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_start = vx_collection.Class_map_from_map_start()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_start = vx_collection.Class_map_from_map_start()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
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
      var output : vx_core.Type_any = vx_collection.e_map_from_map_start
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_map_from_map_start
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_map_1 : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_collection.f_map_from_map_start(generic_map_1, valuemap, start)
      return output
    }

    override fun <N : vx_core.Type_map> vx_map_from_map_start(generic_map_1 : N, valuemap : N, start : vx_core.Type_int) : N {
      var output : N = vx_collection.f_map_from_map_start(generic_map_1, valuemap, start)
      return output
    }

  }

  val e_map_from_map_start : vx_collection.Func_map_from_map_start = vx_collection.Class_map_from_map_start()
  val t_map_from_map_start : vx_collection.Func_map_from_map_start = vx_collection.Class_map_from_map_start()

  fun <N : vx_core.Type_map> f_map_from_map_start(generic_map_1 : N, valuemap : N, start : vx_core.Type_int) : N {
    var output : N = vx_core.f_empty(generic_map_1)
    output = vx_collection.f_map_from_map_start_end(
      generic_map_1,
      valuemap,
      start,
      vx_core.f_length_2(
        valuemap
      )
    )
    return output
  }


  interface Func_map_from_map_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun <N : vx_core.Type_map> vx_map_from_map_start_end(generic_map_1 : N, valuemap : N, start : vx_core.Type_int, end : vx_core.Type_int) : N
  }

  class Class_map_from_map_start_end : vx_core.Class_base, Func_map_from_map_start_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_start_end = vx_collection.Class_map_from_map_start_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_collection.Class_map_from_map_start_end = vx_collection.Class_map_from_map_start_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
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
      var output : vx_core.Type_any = vx_collection.e_map_from_map_start_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_collection.t_map_from_map_start_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_map_1 : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var valuemap : vx_core.Type_map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end)
      return output
    }

    override fun <N : vx_core.Type_map> vx_map_from_map_start_end(generic_map_1 : N, valuemap : N, start : vx_core.Type_int, end : vx_core.Type_int) : N {
      var output : N = vx_collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end)
      return output
    }

  }

  val e_map_from_map_start_end : vx_collection.Func_map_from_map_start_end = vx_collection.Class_map_from_map_start_end()
  val t_map_from_map_start_end : vx_collection.Func_map_from_map_start_end = vx_collection.Class_map_from_map_start_end()

  fun <N : vx_core.Type_map> f_map_from_map_start_end(generic_map_1 : N, valuemap : N, start : vx_core.Type_int, end : vx_core.Type_int) : N {
    var output : N = vx_core.f_empty(generic_map_1)
    output = vx_core.f_let(
      generic_map_1,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var keys1 : vx_core.Type_stringlist = vx_core.f_stringlist_from_map(
          valuemap
        )
        var keys2 : vx_core.Type_stringlist = vx_collection.f_list_from_list_start_end(
          vx_core.t_stringlist,
          keys1,
          start,
          end
        )
        var output_1 : vx_core.Type_any = vx_collection.f_map_from_map_keys(
          generic_map_1,
          valuemap,
          keys2
        )
        output_1
      })
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    mapfunc.put("any<-for-until-loop", vx_collection.t_any_from_for_until_loop)
    mapfunc.put("any<-for-until-loop-max", vx_collection.t_any_from_for_until_loop_max)
    mapfunc.put("any<-for-while-loop", vx_collection.t_any_from_for_while_loop)
    mapfunc.put("any<-for-while-loop-max", vx_collection.t_any_from_for_while_loop_max)
    mapfunc.put("any<-map-pos", vx_collection.t_any_from_map_pos)
    mapfunc.put("boolean-write<-map-removekey", vx_collection.t_boolean_write_from_map_removekey)
    mapfunc.put("boolean-write<-map-removekeys", vx_collection.t_boolean_write_from_map_removekeys)
    mapfunc.put("int<-map-key", vx_collection.t_int_from_map_key)
    mapfunc.put("int<-stringlist-find", vx_collection.t_int_from_stringlist_find)
    mapfunc.put("is-list", vx_collection.t_is_list)
    mapfunc.put("is-map", vx_collection.t_is_map)
    mapfunc.put("list<-for-end-loop", vx_collection.t_list_from_for_end_loop)
    mapfunc.put("list<-for-while-loop", vx_collection.t_list_from_for_while_loop)
    mapfunc.put("list<-for-while-loop-max", vx_collection.t_list_from_for_while_loop_max)
    mapfunc.put("list<-list-end", vx_collection.t_list_from_list_end)
    mapfunc.put("list<-list-filter", vx_collection.t_list_from_list_filter)
    mapfunc.put("list<-list-filtertypes", vx_collection.t_list_from_list_filtertypes)
    mapfunc.put("list<-list-start", vx_collection.t_list_from_list_start)
    mapfunc.put("list<-list-start-end", vx_collection.t_list_from_list_start_end)
    mapfunc.put("map<-map-end", vx_collection.t_map_from_map_end)
    mapfunc.put("map<-map-keys", vx_collection.t_map_from_map_keys)
    mapfunc.put("map<-map-start", vx_collection.t_map_from_map_start)
    mapfunc.put("map<-map-start-end", vx_collection.t_map_from_map_start_end)
    vx_core.vx_global_package_set("vx/collection", maptype, mapconst, mapfunc)
  }

}
