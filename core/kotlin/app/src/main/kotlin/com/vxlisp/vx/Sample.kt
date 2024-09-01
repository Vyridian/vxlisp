package com.vxlisp.vx

object vx_sample {


  interface Type_mytype : vx_core.Type_struct {
    fun mynum() : vx_core.Type_int
    fun mystr() : vx_core.Type_string
  }

  class Class_mytype : vx_core.Class_base, Type_mytype {
    constructor() {}

    var vx_p_mynum : vx_core.Type_int? = null

    override fun mynum() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_mynum
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_mystr : vx_core.Type_string? = null

    override fun mystr() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_mystr
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":mynum")) {
        output = this.mynum()
      } else if ((skey==":mystr")) {
        output = this.mystr()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":mynum", this.mynum())
      map.put(":mystr", this.mystr())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_sample.Type_mytype = vx_core.vx_copy(vx_sample.e_mytype, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_sample.Type_mytype = this
      var ischanged : Boolean = false
      var value : vx_sample.Class_mytype = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_mynum : vx_core.Type_int = value.mynum()
      var vx_p_mystr : vx_core.Type_string = value.mystr()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":mynum")
      validkeys.add(":mystr")
      var key : String = ""
      var msg : vx_core.Type_msg = vx_core.e_msg
      var msgval : vx_core.Type_any = vx_core.e_any
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (key.equals("")) {
          var istestkey : Boolean = false
          var testkey : String = ""
          if (false) {
          } else if (valsub is vx_core.Type_string) {
            var valstr : vx_core.Type_string = valsub as vx_core.Type_string
            testkey = valstr.vx_string()
            istestkey = true
          } else if (valsub is String) {
            var sval : String = valsub as String
            testkey = sval
            istestkey = true
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":mynum")) {
            if (valsub == vx_p_mynum) {
            } else if (valsub is vx_core.Type_int) {
              var valmynum : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_mynum = valmynum
            } else if (valsub is Int) {
              ischanged = true
              vx_p_mynum = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("mynum"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":mystr")) {
            if (valsub == vx_p_mystr) {
            } else if (valsub is vx_core.Type_string) {
              var valmystr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_mystr = valmystr
            } else if (valsub is String) {
              ischanged = true
              vx_p_mystr = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("mystr"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_sample.Class_mytype = vx_sample.Class_mytype()
        work.vx_p_mynum = vx_p_mynum
        work.vx_p_mystr = vx_p_mystr
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_sample.e_mytype
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_sample.t_mytype
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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
      return output
    }

  }

  val e_mytype : vx_sample.Type_mytype = vx_sample.Class_mytype()
  val t_mytype : vx_sample.Type_mytype = vx_sample.Class_mytype()

  class Const_myconst {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
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
        )
      )
      return output
    }

    fun const_new(output : vx_core.Type_int) : Unit {
      var outval : vx_core.Class_int = output as vx_core.Class_int
      outval.vx_p_constdef = constdef()
      outval.vxint = 4
    }

    }
  }

  val c_myconst : vx_core.Type_int = vx_core.Class_int()


  interface Func_main : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_main() : vx_core.Type_none
  }

  class Class_main : vx_core.Class_base, Func_main {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_sample.Class_main = vx_sample.Class_main()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_sample.Class_main = vx_sample.Class_main()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
      var output : vx_core.Type_any = vx_sample.e_main
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_sample.t_main
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_sample.f_main()
      return output
    }

    override fun vx_main() : vx_core.Type_none {
      var output : vx_core.Type_none = vx_sample.f_main()
      return output
    }

  }

  val e_main : vx_sample.Func_main = vx_sample.Class_main()
  val t_main : vx_sample.Func_main = vx_sample.Class_main()

  fun f_main() : vx_core.Type_none {
    var output : vx_core.Type_none = vx_core.e_none
    vx_sample.f_myfunc(
      vx_core.vx_new_int(2)
    )
    return output
  }


  interface Func_myfunc : vx_core.Func_any_from_any {
    fun vx_myfunc(myarg : vx_core.Type_int) : vx_core.Type_int
  }

  class Class_myfunc : vx_core.Class_base, Func_myfunc {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_sample.Class_myfunc = vx_sample.Class_myfunc()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_sample.Class_myfunc = vx_sample.Class_myfunc()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
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
      var output : vx_core.Type_any = vx_sample.e_myfunc
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_sample.t_myfunc
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_int = value as vx_core.Type_int
      var outputval : vx_core.Type_any = vx_sample.f_myfunc(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var myarg : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_sample.f_myfunc(myarg)
      return output
    }

    override fun vx_myfunc(myarg : vx_core.Type_int) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_sample.f_myfunc(myarg)
      return output
    }

  }

  val e_myfunc : vx_sample.Func_myfunc = vx_sample.Class_myfunc()
  val t_myfunc : vx_sample.Func_myfunc = vx_sample.Class_myfunc()

  fun f_myfunc(myarg : vx_core.Type_int) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_plus(
      vx_sample.c_myconst,
      myarg
    )
    return output
  }


  init {
    Const_myconst.const_new(c_myconst)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("mytype", vx_sample.t_mytype)
    mapconst.put("myconst", vx_sample.c_myconst)
    mapfunc.put("main", vx_sample.t_main)
    mapfunc.put("myfunc", vx_sample.t_myfunc)
    vx_core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc)
  }

}
