package com.vxlisp.vx

object vx_state {


  interface Type_valuemap : vx_core.Type_map {
  }

  class Class_valuemap : vx_core.Class_base, Type_valuemap {
    constructor() {}

    var vx_p_map : Map<String, vx_core.Type_any> = vx_core.immutablemap(LinkedHashMap<String, vx_core.Type_any>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_core.Type_any) {
        var castval : vx_core.Type_any = value as vx_core.Type_any
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
        if (castval == vx_core.e_any) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var map : vx_state.Class_valuemap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_core.Type_any> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_core.e_any)
      return output
    }

    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_state.Class_valuemap = vx_state.Class_valuemap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_core.Type_any) {
          var castval : vx_core.Type_any = value as vx_core.Type_any
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/state/valuemap", ":invalidvalue", value)
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      output.vx_p_map = vx_core.immutablemap(map)
      if (msgblock != vx_core.e_msgblock) {
        output.vxmsgblock = msgblock
      }
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_state.Type_valuemap = vx_core.vx_copy(vx_state.e_valuemap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_state.Type_valuemap = this
      var ischanged : Boolean = false
      var value : vx_state.Class_valuemap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(value.vx_map())
      var key : String = ""
      var msg : vx_core.Type_msg = vx_core.e_msg
      var msgval : vx_core.Type_any = vx_core.e_any
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub is vx_core.Type_string) {
            var valstring : vx_core.Type_string = valsub as vx_core.Type_string
            key = valstring.vx_string()
          } else if (valsub is String) {
            var sval : String = valsub as String
            key = sval
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valinvalid
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/state/valuemap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_core.Type_any = vx_core.e_any
          if (false) {
          } else if (valsub is vx_core.Type_any) {
            var valallowed : vx_core.Type_any = valsub as vx_core.Type_any
            valany = valallowed
          } else if (valsub is vx_core.Type_any) {
            valany = valsub as vx_core.Type_any
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valinvalid
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
            mapany.put("key", vx_core.vx_new_string(key))
            mapany.put("value", msgval)
            var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
            msg = vx_core.vx_msg_from_error("vx/state/valuemap", ":invalidkeyvalue", msgmap)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (valany != vx_core.e_any) {
            ischanged = true
            if (key.startsWith(":")) {
              key = key.substring(1)
            }
            mapval.put(key, valany)
            key = ""
          }
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_state.Class_valuemap = vx_state.Class_valuemap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.e_valuemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_valuemap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/state", // pkgname
        "valuemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      )
      return output
    }

  }

  val e_valuemap : vx_state.Type_valuemap = vx_state.Class_valuemap()
  val t_valuemap : vx_state.Type_valuemap = vx_state.Class_valuemap()

  interface Func_any_readstate_from_mapname_name : vx_core.Type_func, vx_core.Type_replfunc {
    fun <T : vx_core.Type_any> vx_any_readstate_from_mapname_name(generic_any_1 : T, context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string) : T
  }

  class Class_any_readstate_from_mapname_name : vx_core.Class_base, Func_any_readstate_from_mapname_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_any_readstate_from_mapname_name = vx_state.Class_any_readstate_from_mapname_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_any_readstate_from_mapname_name = vx_state.Class_any_readstate_from_mapname_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-mapname-name", // name
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
      var output : vx_core.Type_any = vx_state.e_any_readstate_from_mapname_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_any_readstate_from_mapname_name
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var mapname : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_state.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_readstate_from_mapname_name(generic_any_1 : T, context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string) : T {
      var output : T = vx_state.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name)
      return output
    }

  }

  val e_any_readstate_from_mapname_name : vx_state.Func_any_readstate_from_mapname_name = vx_state.Class_any_readstate_from_mapname_name()
  val t_any_readstate_from_mapname_name : vx_state.Func_any_readstate_from_mapname_name = vx_state.Class_any_readstate_from_mapname_name()

  fun <T : vx_core.Type_any> f_any_readstate_from_mapname_name(generic_any_1 : T, context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var submap : vx_state.Type_valuemap = vx_state.f_valuemap_readstate_from_mapname(
          context,
          mapname
        )
        var output_1 : vx_core.Type_any = vx_core.f_any_from_map(
          generic_any_1,
          submap,
          name
        )
        output_1
      })
    )
    return output
  }


  interface Func_any_readstate_from_name : vx_core.Func_any_from_any_context {
    fun <T : vx_core.Type_any> vx_any_readstate_from_name(generic_any_1 : T, context : vx_core.Type_context, name : vx_core.Type_string) : T
  }

  class Class_any_readstate_from_name : vx_core.Class_base, Func_any_readstate_from_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_any_readstate_from_name = vx_state.Class_any_readstate_from_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_any_readstate_from_name = vx_state.Class_any_readstate_from_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-name", // name
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
      var output : vx_core.Type_any = vx_state.e_any_readstate_from_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_any_readstate_from_name
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_state.f_any_readstate_from_name(vx_core.t_any, context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_any_readstate_from_name(generic_any_1, context, name)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_readstate_from_name(generic_any_1 : T, context : vx_core.Type_context, name : vx_core.Type_string) : T {
      var output : T = vx_state.f_any_readstate_from_name(generic_any_1, context, name)
      return output
    }

  }

  val e_any_readstate_from_name : vx_state.Func_any_readstate_from_name = vx_state.Class_any_readstate_from_name()
  val t_any_readstate_from_name : vx_state.Func_any_readstate_from_name = vx_state.Class_any_readstate_from_name()

  fun <T : vx_core.Type_any> f_any_readstate_from_name(generic_any_1 : T, context : vx_core.Type_context, name : vx_core.Type_string) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_core.f_any_from_any(
      generic_any_1,
      vx_state.f_value_readstate_from_name(
        context,
        name
      )
    )
    return output
  }


  interface Func_boolean_removestate_from_name : vx_core.Func_any_from_any_context {
    fun vx_boolean_removestate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_removestate_from_name : vx_core.Class_base, Func_boolean_removestate_from_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_removestate_from_name = vx_state.Class_boolean_removestate_from_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_removestate_from_name = vx_state.Class_boolean_removestate_from_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-removestate<-name", // name
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
      var output : vx_core.Type_any = vx_state.e_boolean_removestate_from_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_boolean_removestate_from_name
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_state.f_boolean_removestate_from_name(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_boolean_removestate_from_name(context, name)
      return output
    }

    override fun vx_boolean_removestate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_boolean_removestate_from_name(context, name)
      return output
    }

  }

  val e_boolean_removestate_from_name : vx_state.Func_boolean_removestate_from_name = vx_state.Class_boolean_removestate_from_name()
  val t_boolean_removestate_from_name : vx_state.Func_boolean_removestate_from_name = vx_state.Class_boolean_removestate_from_name()

  fun f_boolean_removestate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var statelistenermap : vx_core.Type_statelistenermap = vx_state.f_statelistenermap_readstate(
          context
        )
        var output_1 : vx_core.Type_any = vx_core.f_boolean_write_from_map_name_value(
          statelistenermap,
          name,
          vx_core.f_empty(
            vx_core.t_statelistener
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writestate_from_mapname_name_value : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_writestate_from_mapname_name_value(context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_mapname_name_value : vx_core.Class_base, Func_boolean_writestate_from_mapname_name_value {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_mapname_name_value = vx_state.Class_boolean_writestate_from_mapname_name_value()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_mapname_name_value = vx_state.Class_boolean_writestate_from_mapname_name_value()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-mapname-name-value", // name
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
      var output : vx_core.Type_any = vx_state.e_boolean_writestate_from_mapname_name_value
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_boolean_writestate_from_mapname_name_value
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var mapname : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_state.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value)
      return output
    }

    override fun vx_boolean_writestate_from_mapname_name_value(context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value)
      return output
    }

  }

  val e_boolean_writestate_from_mapname_name_value : vx_state.Func_boolean_writestate_from_mapname_name_value = vx_state.Class_boolean_writestate_from_mapname_name_value()
  val t_boolean_writestate_from_mapname_name_value : vx_state.Func_boolean_writestate_from_mapname_name_value = vx_state.Class_boolean_writestate_from_mapname_name_value()

  fun f_boolean_writestate_from_mapname_name_value(context : vx_core.Type_context, mapname : vx_core.Type_string, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var valmap : vx_state.Type_valuemap = vx_state.f_any_readstate_from_name(
          vx_state.t_valuemap,
          context,
          mapname
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_boolean,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_is_empty_1(
                  valmap
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_let(
                  vx_core.t_boolean,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var valmap2 : vx_state.Type_valuemap = vx_core.f_new(
                      vx_state.t_valuemap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        name,
                        value
                      )
                    )
                    var listener : vx_core.Type_statelistener = vx_core.f_new(
                      vx_core.t_statelistener,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":name"),
                        mapname,
                        vx_core.vx_new_string(":value"),
                        valmap2
                      )
                    )
                    var output_4 : vx_core.Type_any = vx_state.f_boolean_writestate_from_statelistener(
                      context,
                      listener
                    )
                    output_4
                  })
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_boolean_write_from_map_name_value(
                  valmap,
                  name,
                  value
                )
                output_5
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writestate_from_name_value : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_writestate_from_name_value(context : vx_core.Type_context, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_name_value : vx_core.Class_base, Func_boolean_writestate_from_name_value {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_name_value = vx_state.Class_boolean_writestate_from_name_value()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_name_value = vx_state.Class_boolean_writestate_from_name_value()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-name-value", // name
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
      var output : vx_core.Type_any = vx_state.e_boolean_writestate_from_name_value
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_boolean_writestate_from_name_value
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_state.f_boolean_writestate_from_name_value(context, name, value)
      return output
    }

    override fun vx_boolean_writestate_from_name_value(context : vx_core.Type_context, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_boolean_writestate_from_name_value(context, name, value)
      return output
    }

  }

  val e_boolean_writestate_from_name_value : vx_state.Func_boolean_writestate_from_name_value = vx_state.Class_boolean_writestate_from_name_value()
  val t_boolean_writestate_from_name_value : vx_state.Func_boolean_writestate_from_name_value = vx_state.Class_boolean_writestate_from_name_value()

  fun f_boolean_writestate_from_name_value(context : vx_core.Type_context, name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var listenercur : vx_core.Type_statelistener = vx_state.f_statelistener_readstate_from_name(
          context,
          name
        )
        var listenerchg : vx_core.Type_statelistener = vx_core.f_copy(
          listenercur,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            name,
            vx_core.vx_new_string(":value"),
            value
          )
        )
        var output_1 : vx_core.Type_any = vx_state.f_boolean_writestate_from_statelistener(
          context,
          listenerchg
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writestate_from_statelistener : vx_core.Func_any_from_any_context {
    fun vx_boolean_writestate_from_statelistener(context : vx_core.Type_context, statelistener : vx_core.Type_statelistener) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_statelistener : vx_core.Class_base, Func_boolean_writestate_from_statelistener {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_statelistener = vx_state.Class_boolean_writestate_from_statelistener()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_boolean_writestate_from_statelistener = vx_state.Class_boolean_writestate_from_statelistener()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-statelistener", // name
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
      var output : vx_core.Type_any = vx_state.e_boolean_writestate_from_statelistener
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_boolean_writestate_from_statelistener
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_statelistener = value as vx_core.Type_statelistener
      var outputval : vx_core.Type_any = vx_state.f_boolean_writestate_from_statelistener(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var statelistener : vx_core.Type_statelistener = vx_core.f_any_from_any(vx_core.t_statelistener, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_boolean_writestate_from_statelistener(context, statelistener)
      return output
    }

    override fun vx_boolean_writestate_from_statelistener(context : vx_core.Type_context, statelistener : vx_core.Type_statelistener) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_boolean_writestate_from_statelistener(context, statelistener)
      return output
    }

  }

  val e_boolean_writestate_from_statelistener : vx_state.Func_boolean_writestate_from_statelistener = vx_state.Class_boolean_writestate_from_statelistener()
  val t_boolean_writestate_from_statelistener : vx_state.Func_boolean_writestate_from_statelistener = vx_state.Class_boolean_writestate_from_statelistener()

  fun f_boolean_writestate_from_statelistener(context : vx_core.Type_context, statelistener : vx_core.Type_statelistener) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var statelistenermap : vx_core.Type_statelistenermap = vx_state.f_statelistenermap_readstate(
          context
        )
        var name : vx_core.Type_string = statelistener.name()
        var output_1 : vx_core.Type_any = vx_core.f_boolean_write_from_map_name_value(
          statelistenermap,
          name,
          statelistener
        )
        output_1
      })
    )
    return output
  }


  interface Func_change : vx_core.Func_any_from_any {
    fun vx_change(valuemap : vx_state.Type_valuemap) : vx_core.Type_boolean
  }

  class Class_change : vx_core.Class_base, Func_change {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_change = vx_state.Class_change()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_change = vx_state.Class_change()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "change", // name
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
      var output : vx_core.Type_any = vx_state.e_change
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_change
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_state.Type_valuemap = value as vx_state.Type_valuemap
      var outputval : vx_core.Type_any = vx_state.f_change(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var valuemap : vx_state.Type_valuemap = vx_core.f_any_from_any(vx_state.t_valuemap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_change(valuemap)
      return output
    }

    override fun vx_change(valuemap : vx_state.Type_valuemap) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_change(valuemap)
      return output
    }

  }

  val e_change : vx_state.Func_change = vx_state.Class_change()
  val t_change : vx_state.Func_change = vx_state.Class_change()

  fun f_change(valuemap : vx_state.Type_valuemap) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_register : vx_core.Func_any_from_any {
    fun vx_register(listener : vx_core.Type_statelistener) : vx_core.Type_boolean
  }

  class Class_register : vx_core.Class_base, Func_register {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_register = vx_state.Class_register()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_register = vx_state.Class_register()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "register", // name
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
      var output : vx_core.Type_any = vx_state.e_register
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_register
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_statelistener = value as vx_core.Type_statelistener
      var outputval : vx_core.Type_any = vx_state.f_register(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var listener : vx_core.Type_statelistener = vx_core.f_any_from_any(vx_core.t_statelistener, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_register(listener)
      return output
    }

    override fun vx_register(listener : vx_core.Type_statelistener) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_state.f_register(listener)
      return output
    }

  }

  val e_register : vx_state.Func_register = vx_state.Class_register()
  val t_register : vx_state.Func_register = vx_state.Class_register()

  fun f_register(listener : vx_core.Type_statelistener) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_state_from_context : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_state_from_context(context : vx_core.Type_context) : vx_core.Type_state
  }

  class Class_state_from_context : vx_core.Class_base, Func_state_from_context {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_state_from_context = vx_state.Class_state_from_context()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_state_from_context = vx_state.Class_state_from_context()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "state<-context", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "state", // name
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
      var output : vx_core.Type_any = vx_state.e_state_from_context
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_state_from_context
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_state_from_context(context)
      return output
    }

    override fun vx_state_from_context(context : vx_core.Type_context) : vx_core.Type_state {
      var output : vx_core.Type_state = vx_state.f_state_from_context(context)
      return output
    }

  }

  val e_state_from_context : vx_state.Func_state_from_context = vx_state.Class_state_from_context()
  val t_state_from_context : vx_state.Func_state_from_context = vx_state.Class_state_from_context()

  fun f_state_from_context(context : vx_core.Type_context) : vx_core.Type_state {
    var output : vx_core.Type_state = vx_core.e_state
    output = context.state()
    return output
  }


  interface Func_statelistener_readstate_from_name : vx_core.Func_any_from_any_context {
    fun vx_statelistener_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_statelistener
  }

  class Class_statelistener_readstate_from_name : vx_core.Class_base, Func_statelistener_readstate_from_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_statelistener_readstate_from_name = vx_state.Class_statelistener_readstate_from_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_statelistener_readstate_from_name = vx_state.Class_statelistener_readstate_from_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "statelistener-readstate<-name", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "statelistener", // name
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
      var output : vx_core.Type_any = vx_state.e_statelistener_readstate_from_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_statelistener_readstate_from_name
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_state.f_statelistener_readstate_from_name(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_statelistener_readstate_from_name(context, name)
      return output
    }

    override fun vx_statelistener_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_statelistener {
      var output : vx_core.Type_statelistener = vx_state.f_statelistener_readstate_from_name(context, name)
      return output
    }

  }

  val e_statelistener_readstate_from_name : vx_state.Func_statelistener_readstate_from_name = vx_state.Class_statelistener_readstate_from_name()
  val t_statelistener_readstate_from_name : vx_state.Func_statelistener_readstate_from_name = vx_state.Class_statelistener_readstate_from_name()

  fun f_statelistener_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_statelistener {
    var output : vx_core.Type_statelistener = vx_core.e_statelistener
    output = vx_core.f_let(
      vx_core.t_statelistener,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var statelistenermap : vx_core.Type_statelistenermap = vx_state.f_statelistenermap_readstate(
          context
        )
        var output_1 : vx_core.Type_any = vx_core.f_any_from_map(
          vx_core.t_statelistener,
          statelistenermap,
          name
        )
        output_1
      })
    )
    return output
  }


  interface Func_statelistenermap_readstate : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_statelistenermap_readstate(context : vx_core.Type_context) : vx_core.Type_statelistenermap
  }

  class Class_statelistenermap_readstate : vx_core.Class_base, Func_statelistenermap_readstate {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_statelistenermap_readstate = vx_state.Class_statelistenermap_readstate()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_statelistenermap_readstate = vx_state.Class_statelistenermap_readstate()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "statelistenermap-readstate", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "statelistenermap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_statelistener), // allowtypes
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
      var output : vx_core.Type_any = vx_state.e_statelistenermap_readstate
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_statelistenermap_readstate
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_statelistenermap_readstate(context)
      return output
    }

    override fun vx_statelistenermap_readstate(context : vx_core.Type_context) : vx_core.Type_statelistenermap {
      var output : vx_core.Type_statelistenermap = vx_state.f_statelistenermap_readstate(context)
      return output
    }

  }

  val e_statelistenermap_readstate : vx_state.Func_statelistenermap_readstate = vx_state.Class_statelistenermap_readstate()
  val t_statelistenermap_readstate : vx_state.Func_statelistenermap_readstate = vx_state.Class_statelistenermap_readstate()

  fun f_statelistenermap_readstate(context : vx_core.Type_context) : vx_core.Type_statelistenermap {
    var output : vx_core.Type_statelistenermap = vx_core.e_statelistenermap
    output = vx_core.f_let(
      vx_core.t_statelistenermap,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var state : vx_core.Type_state = vx_state.f_state_from_context(
          context
        )
        var output_1 : vx_core.Type_any = state.statelistenermap()
        output_1
      })
    )
    return output
  }


  interface Func_value_readstate_from_name : vx_core.Func_any_from_any_context {
    fun vx_value_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_value_readstate_from_name : vx_core.Class_base, Func_value_readstate_from_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_value_readstate_from_name = vx_state.Class_value_readstate_from_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_value_readstate_from_name = vx_state.Class_value_readstate_from_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "value-readstate<-name", // name
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
      var output : vx_core.Type_any = vx_state.e_value_readstate_from_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_value_readstate_from_name
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_state.f_value_readstate_from_name(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_value_readstate_from_name(context, name)
      return output
    }

    override fun vx_value_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.f_value_readstate_from_name(context, name)
      return output
    }

  }

  val e_value_readstate_from_name : vx_state.Func_value_readstate_from_name = vx_state.Class_value_readstate_from_name()
  val t_value_readstate_from_name : vx_state.Func_value_readstate_from_name = vx_state.Class_value_readstate_from_name()

  fun f_value_readstate_from_name(context : vx_core.Type_context, name : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var statelistener : vx_core.Type_statelistener = vx_state.f_statelistener_readstate_from_name(
          context,
          name
        )
        var output_1 : vx_core.Type_any = statelistener.value()
        output_1
      })
    )
    return output
  }


  interface Func_valuemap_readstate_from_mapname : vx_core.Func_any_from_any_context {
    fun vx_valuemap_readstate_from_mapname(context : vx_core.Type_context, mapname : vx_core.Type_string) : vx_state.Type_valuemap
  }

  class Class_valuemap_readstate_from_mapname : vx_core.Class_base, Func_valuemap_readstate_from_mapname {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_valuemap_readstate_from_mapname = vx_state.Class_valuemap_readstate_from_mapname()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_state.Class_valuemap_readstate_from_mapname = vx_state.Class_valuemap_readstate_from_mapname()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/state", // pkgname
        "valuemap-readstate<-mapname", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/state", // pkgname
          "valuemap", // name
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
      var output : vx_core.Type_any = vx_state.e_valuemap_readstate_from_mapname
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_state.t_valuemap_readstate_from_mapname
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_state.f_valuemap_readstate_from_mapname(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var mapname : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_state.f_valuemap_readstate_from_mapname(context, mapname)
      return output
    }

    override fun vx_valuemap_readstate_from_mapname(context : vx_core.Type_context, mapname : vx_core.Type_string) : vx_state.Type_valuemap {
      var output : vx_state.Type_valuemap = vx_state.f_valuemap_readstate_from_mapname(context, mapname)
      return output
    }

  }

  val e_valuemap_readstate_from_mapname : vx_state.Func_valuemap_readstate_from_mapname = vx_state.Class_valuemap_readstate_from_mapname()
  val t_valuemap_readstate_from_mapname : vx_state.Func_valuemap_readstate_from_mapname = vx_state.Class_valuemap_readstate_from_mapname()

  fun f_valuemap_readstate_from_mapname(context : vx_core.Type_context, mapname : vx_core.Type_string) : vx_state.Type_valuemap {
    var output : vx_state.Type_valuemap = vx_state.e_valuemap
    output = vx_core.f_let(
      vx_state.t_valuemap,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var value : vx_core.Type_any = vx_state.f_value_readstate_from_name(
          context,
          mapname
        )
        var valmap : vx_state.Type_valuemap = vx_core.f_any_from_any(
          vx_state.t_valuemap,
          value
        )
        var output_1 : vx_core.Type_any = valmap
        output_1
      })
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("valuemap", vx_state.t_valuemap)
    mapfunc.put("any-readstate<-mapname-name", vx_state.t_any_readstate_from_mapname_name)
    mapfunc.put("any-readstate<-name", vx_state.t_any_readstate_from_name)
    mapfunc.put("boolean-removestate<-name", vx_state.t_boolean_removestate_from_name)
    mapfunc.put("boolean-writestate<-mapname-name-value", vx_state.t_boolean_writestate_from_mapname_name_value)
    mapfunc.put("boolean-writestate<-name-value", vx_state.t_boolean_writestate_from_name_value)
    mapfunc.put("boolean-writestate<-statelistener", vx_state.t_boolean_writestate_from_statelistener)
    mapfunc.put("change", vx_state.t_change)
    mapfunc.put("register", vx_state.t_register)
    mapfunc.put("state<-context", vx_state.t_state_from_context)
    mapfunc.put("statelistener-readstate<-name", vx_state.t_statelistener_readstate_from_name)
    mapfunc.put("statelistenermap-readstate", vx_state.t_statelistenermap_readstate)
    mapfunc.put("value-readstate<-name", vx_state.t_value_readstate_from_name)
    mapfunc.put("valuemap-readstate<-mapname", vx_state.t_valuemap_readstate_from_mapname)
    vx_core.vx_global_package_set("vx/state", maptype, mapconst, mapfunc)
  }

}
