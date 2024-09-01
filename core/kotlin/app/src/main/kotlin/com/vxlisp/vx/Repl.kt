package com.vxlisp.vx

import com.vxlisp.vx.data.*

object vx_repl {


  interface Type_liblist : vx_core.Type_list {
    fun vx_liststring() : List<vx_core.Type_string>
    fun vx_string(index : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_liblist : vx_core.Class_base, Type_liblist {
    constructor() {}

    var vx_p_list : List<vx_core.Type_string> = vx_core.immutablelist(
      ArrayList<vx_core.Type_string>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_string(index : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var list : vx_repl.Class_liblist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_core.Type_string> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_liststring() : List<vx_core.Type_string> {
      var output : List<vx_core.Type_string> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_core.Type_string = this.vx_string(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_liblist = vx_core.vx_copy(vx_repl.e_liblist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_liblist = this
      var ischanged : Boolean = false
      var value : vx_repl.Class_liblist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_core.Type_string> = ArrayList<vx_core.Type_string>(value.vx_liststring())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_repl.Type_liblist) {
          var multi : vx_repl.Type_liblist = valsub as vx_repl.Type_liblist
          ischanged = true
          listval.addAll(multi.vx_liststring())
        } else if (valsub is vx_core.Type_string) {
          var allowsub : vx_core.Type_string = valsub as vx_core.Type_string
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is String) {
          ischanged = true
          listval.add(vx_core.vx_new(vx_core.t_string, valsub))
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_core.Type_string) {
              var valitem : vx_core.Type_string = item as vx_core.Type_string
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_repl.Class_liblist = vx_repl.Class_liblist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.e_liblist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_liblist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_string), // allowtypes
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

  val e_liblist : vx_repl.Type_liblist = vx_repl.Class_liblist()
  val t_liblist : vx_repl.Type_liblist = vx_repl.Class_liblist()

  interface Type_repl : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun type() : vx_core.Type_any
    fun repllist() : vx_repl.Type_repllist
    fun async() : vx_core.Type_boolean
    fun value() : vx_core.Type_any
    fun doc() : vx_core.Type_string
  }

  class Class_repl : vx_core.Class_base, Type_repl {
    constructor() {}

    var vx_p_name : vx_core.Type_string? = null

    override fun name() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_name
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_type : vx_core.Type_any? = null

    override fun type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_type
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_repllist : vx_repl.Type_repllist? = null

    override fun repllist() : vx_repl.Type_repllist {
      var output : vx_repl.Type_repllist = vx_repl.e_repllist
      var testnull : vx_repl.Type_repllist? = vx_p_repllist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_async : vx_core.Type_boolean? = null

    override fun async() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_async
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_value : vx_core.Type_any? = null

    override fun value() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_value
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_doc : vx_core.Type_string? = null

    override fun doc() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_doc
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":type")) {
        output = this.type()
      } else if ((skey==":repllist")) {
        output = this.repllist()
      } else if ((skey==":async")) {
        output = this.async()
      } else if ((skey==":value")) {
        output = this.value()
      } else if ((skey==":doc")) {
        output = this.doc()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":type", this.type())
      map.put(":repllist", this.repllist())
      map.put(":async", this.async())
      map.put(":value", this.value())
      map.put(":doc", this.doc())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_repl = vx_core.vx_copy(vx_repl.e_repl, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_repl = this
      var ischanged : Boolean = false
      var value : vx_repl.Class_repl = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_type : vx_core.Type_any = value.type()
      var vx_p_repllist : vx_repl.Type_repllist = value.repllist()
      var vx_p_async : vx_core.Type_boolean = value.async()
      var vx_p_value : vx_core.Type_any = value.value()
      var vx_p_doc : vx_core.Type_string = value.doc()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":type")
      validkeys.add(":repllist")
      validkeys.add(":async")
      validkeys.add(":value")
      validkeys.add(":doc")
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
            msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is vx_core.Type_string) {
              var valname : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_name = valname
            } else if (valsub is String) {
              ischanged = true
              vx_p_name = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("name"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":type")) {
            if (valsub == vx_p_type) {
            } else if (valsub is vx_core.Type_any) {
              var valtype : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_type = valtype
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("type"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":repllist")) {
            if (valsub == vx_p_repllist) {
            } else if (valsub is vx_repl.Type_repllist) {
              var valrepllist : vx_repl.Type_repllist = valsub as vx_repl.Type_repllist
              ischanged = true
              vx_p_repllist = valrepllist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("repllist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":async")) {
            if (valsub == vx_p_async) {
            } else if (valsub is vx_core.Type_boolean) {
              var valasync : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_async = valasync
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_async = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("async"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":value")) {
            if (valsub == vx_p_value) {
            } else if (valsub is vx_core.Type_any) {
              var valvalue : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_value = valvalue
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("value"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":doc")) {
            if (valsub == vx_p_doc) {
            } else if (valsub is vx_core.Type_string) {
              var valdoc : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_doc = valdoc
            } else if (valsub is String) {
              ischanged = true
              vx_p_doc = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("doc"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_repl.Class_repl = vx_repl.Class_repl()
        work.vx_p_name = vx_p_name
        work.vx_p_type = vx_p_type
        work.vx_p_repllist = vx_p_repllist
        work.vx_p_async = vx_p_async
        work.vx_p_value = vx_p_value
        work.vx_p_doc = vx_p_doc
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.e_repl
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/repl", // pkgname
        "repl", // name
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

  val e_repl : vx_repl.Type_repl = vx_repl.Class_repl()
  val t_repl : vx_repl.Type_repl = vx_repl.Class_repl()

  interface Type_replarglist : vx_core.Type_struct {
    fun key() : vx_core.Type_string
    fun current() : vx_repl.Type_repl
    fun repllist() : vx_repl.Type_repllist
  }

  class Class_replarglist : vx_core.Class_base, Type_replarglist {
    constructor() {}

    var vx_p_key : vx_core.Type_string? = null

    override fun key() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_key
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_current : vx_repl.Type_repl? = null

    override fun current() : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.e_repl
      var testnull : vx_repl.Type_repl? = vx_p_current
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_repllist : vx_repl.Type_repllist? = null

    override fun repllist() : vx_repl.Type_repllist {
      var output : vx_repl.Type_repllist = vx_repl.e_repllist
      var testnull : vx_repl.Type_repllist? = vx_p_repllist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":key")) {
        output = this.key()
      } else if ((skey==":current")) {
        output = this.current()
      } else if ((skey==":repllist")) {
        output = this.repllist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":key", this.key())
      map.put(":current", this.current())
      map.put(":repllist", this.repllist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_replarglist = vx_core.vx_copy(vx_repl.e_replarglist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_replarglist = this
      var ischanged : Boolean = false
      var value : vx_repl.Class_replarglist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_key : vx_core.Type_string = value.key()
      var vx_p_current : vx_repl.Type_repl = value.current()
      var vx_p_repllist : vx_repl.Type_repllist = value.repllist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":key")
      validkeys.add(":current")
      validkeys.add(":repllist")
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
            msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":key")) {
            if (valsub == vx_p_key) {
            } else if (valsub is vx_core.Type_string) {
              var valkey : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_key = valkey
            } else if (valsub is String) {
              ischanged = true
              vx_p_key = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("key"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":current")) {
            if (valsub == vx_p_current) {
            } else if (valsub is vx_repl.Type_repl) {
              var valcurrent : vx_repl.Type_repl = valsub as vx_repl.Type_repl
              ischanged = true
              vx_p_current = valcurrent
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("current"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":repllist")) {
            if (valsub == vx_p_repllist) {
            } else if (valsub is vx_repl.Type_repllist) {
              var valrepllist : vx_repl.Type_repllist = valsub as vx_repl.Type_repllist
              ischanged = true
              vx_p_repllist = valrepllist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("repllist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_repl.Class_replarglist = vx_repl.Class_replarglist()
        work.vx_p_key = vx_p_key
        work.vx_p_current = vx_p_current
        work.vx_p_repllist = vx_p_repllist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.e_replarglist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_replarglist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/repl", // pkgname
        "replarglist", // name
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

  val e_replarglist : vx_repl.Type_replarglist = vx_repl.Class_replarglist()
  val t_replarglist : vx_repl.Type_replarglist = vx_repl.Class_replarglist()

  interface Type_repllist : vx_core.Type_list {
    fun vx_listrepl() : List<vx_repl.Type_repl>
    fun vx_repl(index : vx_core.Type_int) : vx_repl.Type_repl
  }

  class Class_repllist : vx_core.Class_base, Type_repllist {
    constructor() {}

    var vx_p_list : List<vx_repl.Type_repl> = vx_core.immutablelist(
      ArrayList<vx_repl.Type_repl>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_repl(index : vx_core.Type_int) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.e_repl
      var list : vx_repl.Class_repllist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_repl.Type_repl> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listrepl() : List<vx_repl.Type_repl> {
      var output : List<vx_repl.Type_repl> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_repl.Type_repl = this.vx_repl(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_repllist = vx_core.vx_copy(vx_repl.e_repllist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_repl.Type_repllist = this
      var ischanged : Boolean = false
      var value : vx_repl.Class_repllist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_repl.Type_repl> = ArrayList<vx_repl.Type_repl>(value.vx_listrepl())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_repl.Type_repllist) {
          var multi : vx_repl.Type_repllist = valsub as vx_repl.Type_repllist
          ischanged = true
          listval.addAll(multi.vx_listrepl())
        } else if (valsub is vx_repl.Type_repl) {
          var allowsub : vx_repl.Type_repl = valsub as vx_repl.Type_repl
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_repl.Type_repl) {
          ischanged = true
          listval.add(valsub as vx_repl.Type_repl)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_repl.Type_repl) {
              var valitem : vx_repl.Type_repl = item as vx_repl.Type_repl
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_repl.Class_repllist = vx_repl.Class_repllist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.e_repllist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repllist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_repl.t_repl), // allowtypes
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

  val e_repllist : vx_repl.Type_repllist = vx_repl.Class_repllist()
  val t_repllist : vx_repl.Type_repllist = vx_repl.Class_repllist()

  class Const_delimvxlisp {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlisp", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    fun const_new(output : vx_data_textblock.Type_delim) : Unit {
      var outval : vx_data_textblock.Class_delim = output as vx_data_textblock.Class_delim
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delim = vx_core.f_new(
        vx_data_textblock.t_delim,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("delimvxlisp"),
          vx_core.vx_new_string(":delimlist"),
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_repl.c_delimvxlispparen,
              vx_data_textblock.c_delimcomment,
              vx_data_textblock.c_delimcommentblock
            )
          )
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_starttext = value.starttext()
      outval.vx_p_endtext = value.endtext()
      outval.vx_p_pos = value.pos()
      outval.vx_p_delimlist = value.delimlist()
    }

    }
  }

  val c_delimvxlisp : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimvxlispbracket {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispbracket", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    fun const_new(output : vx_data_textblock.Type_delim) : Unit {
      var outval : vx_data_textblock.Class_delim = output as vx_data_textblock.Class_delim
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delim = vx_core.f_copy(
        vx_data_textblock.c_delimbracketsquare,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("delimvxlispbracketsquare"),
          vx_core.vx_new_string(":delimlist"),
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_data_textblock.c_delimcomment,
              vx_data_textblock.c_delimcommentblock,
              vx_data_textblock.c_delimquote,
              vx_data_textblock.c_delimquoteblock,
              vx_data_textblock.c_delimwhitespace,
              vx_repl.c_delimvxlispparen
            )
          )
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_starttext = value.starttext()
      outval.vx_p_endtext = value.endtext()
      outval.vx_p_pos = value.pos()
      outval.vx_p_delimlist = value.delimlist()
    }

    }
  }

  val c_delimvxlispbracket : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimvxlispparen {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispparen", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    fun const_new(output : vx_data_textblock.Type_delim) : Unit {
      var outval : vx_data_textblock.Class_delim = output as vx_data_textblock.Class_delim
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delim = vx_core.f_copy(
        vx_data_textblock.c_delimparen,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("delimvxlispparen"),
          vx_core.vx_new_string(":delimlist"),
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_data_textblock.c_delimcomment,
              vx_data_textblock.c_delimcommentblock,
              vx_data_textblock.c_delimquote,
              vx_data_textblock.c_delimquoteblock,
              vx_data_textblock.c_delimwhitespace,
              vx_repl.c_delimvxlispbracket,
              vx_repl.c_delimvxlispparen
            )
          )
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_starttext = value.starttext()
      outval.vx_p_endtext = value.endtext()
      outval.vx_p_pos = value.pos()
      outval.vx_p_delimlist = value.delimlist()
    }

    }
  }

  val c_delimvxlispparen : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  interface Func_any_repl_from_functype_args : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_any_repl_from_functype_args(type : vx_core.Type_any, args : vx_core.Type_anylist) : vx_core.Type_any
  }

  class Class_any_repl_from_functype_args : vx_core.Class_base, Func_any_repl_from_functype_args {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_repl_from_functype_args = vx_repl.Class_any_repl_from_functype_args()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_repl_from_functype_args = vx_repl.Class_any_repl_from_functype_args()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
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
      var output : vx_core.Type_any = vx_repl.e_any_repl_from_functype_args
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_any_repl_from_functype_args
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var type : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var args : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_any_repl_from_functype_args(type, args)
      return output
    }

    override fun vx_any_repl_from_functype_args(type : vx_core.Type_any, args : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_any_repl_from_functype_args(type, args)
      return output
    }

  }

  val e_any_repl_from_functype_args : vx_repl.Func_any_repl_from_functype_args = vx_repl.Class_any_repl_from_functype_args()
  val t_any_repl_from_functype_args : vx_repl.Func_any_repl_from_functype_args = vx_repl.Class_any_repl_from_functype_args()

  fun f_any_repl_from_functype_args(type : vx_core.Type_any, args : vx_core.Type_anylist) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    return output
  }


  interface Func_any_from_liblist_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_any_from_liblist_string(context : vx_core.Type_context, liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_any_from_liblist_string : vx_core.Class_base, Func_any_from_liblist_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_liblist_string = vx_repl.Class_any_from_liblist_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_liblist_string = vx_repl.Class_any_from_liblist_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
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
      var output : vx_core.Type_any = vx_repl.e_any_from_liblist_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_any_from_liblist_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var liblist : vx_repl.Type_liblist = vx_core.f_any_from_any(vx_repl.t_liblist, arglist.vx_any(vx_core.vx_new_int(0)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_any_from_liblist_string(context, liblist, text)
      return output
    }

    override fun vx_any_from_liblist_string(context : vx_core.Type_context, liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_any_from_liblist_string(context, liblist, text)
      return output
    }

  }

  val e_any_from_liblist_string : vx_repl.Func_any_from_liblist_string = vx_repl.Class_any_from_liblist_string()
  val t_any_from_liblist_string : vx_repl.Func_any_from_liblist_string = vx_repl.Class_any_from_liblist_string()

  fun f_any_from_liblist_string(context : vx_core.Type_context, liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var repl : vx_repl.Type_repl = vx_repl.f_repl_from_liblist_string(
          liblist,
          text
        )
        var output_1 : vx_core.Type_any = vx_repl.f_any_from_repl(
          context,
          repl
        )
        output_1
      })
    )
    return output
  }


  interface Func_any_from_macro : vx_core.Func_any_from_any_context {
    fun <T : vx_core.Type_any> vx_any_from_macro(generic_any_1 : T, context : vx_core.Type_context, anylist : vx_core.Type_anylist) : T
  }

  class Class_any_from_macro : vx_core.Class_base, Func_any_from_macro {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_macro = vx_repl.Class_any_from_macro()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_macro = vx_repl.Class_any_from_macro()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
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
      var output : vx_core.Type_any = vx_repl.e_any_from_macro
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_any_from_macro
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_repl.f_any_from_macro(vx_core.t_any, context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var anylist : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_any_from_macro(generic_any_1, context, anylist)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_macro(generic_any_1 : T, context : vx_core.Type_context, anylist : vx_core.Type_anylist) : T {
      var output : T = vx_repl.f_any_from_macro(generic_any_1, context, anylist)
      return output
    }

  }

  val e_any_from_macro : vx_repl.Func_any_from_macro = vx_repl.Class_any_from_macro()
  val t_any_from_macro : vx_repl.Func_any_from_macro = vx_repl.Class_any_from_macro()

  fun <T : vx_core.Type_any> f_any_from_macro(generic_any_1 : T, context : vx_core.Type_context, anylist : vx_core.Type_anylist) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var repl : vx_repl.Type_repl = vx_repl.f_repl_from_macro(
          context,
          anylist
        )
        var value : vx_core.Type_any = vx_repl.f_any_from_repl(
          context,
          repl
        )
        var output_1 : vx_core.Type_any = vx_core.f_any_from_any(
          generic_any_1,
          value
        )
        output_1
      })
    )
    return output
  }


  interface Func_any_from_repl : vx_core.Func_any_from_any_context {
    fun vx_any_from_repl(context : vx_core.Type_context, repl : vx_repl.Type_repl) : vx_core.Type_any
  }

  class Class_any_from_repl : vx_core.Class_base, Func_any_from_repl {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_repl = vx_repl.Class_any_from_repl()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_repl = vx_repl.Class_any_from_repl()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_any_from_repl
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_any_from_repl
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_repl.Type_repl = value as vx_repl.Type_repl
      var outputval : vx_core.Type_any = vx_repl.f_any_from_repl(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var repl : vx_repl.Type_repl = vx_core.f_any_from_any(vx_repl.t_repl, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_any_from_repl(context, repl)
      return output
    }

    override fun vx_any_from_repl(context : vx_core.Type_context, repl : vx_repl.Type_repl) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_any_from_repl(context, repl)
      return output
    }

  }

  val e_any_from_repl : vx_repl.Func_any_from_repl = vx_repl.Class_any_from_repl()
  val t_any_from_repl : vx_repl.Func_any_from_repl = vx_repl.Class_any_from_repl()

  fun f_any_from_repl(context : vx_core.Type_context, repl : vx_repl.Type_repl) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var value : vx_core.Type_any = repl.value()
        var repltype : vx_core.Type_any = repl.type()
        var repllist : vx_repl.Type_repllist = repl.repllist()
        var args : vx_core.Type_anylist = vx_repl.f_anylist_from_repllist(
          context,
          repllist
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_any,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_notempty_1(
                  value
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = value
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_is_func(
                  repltype
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_repl.f_any_repl_from_functype_args(
                  repltype,
                  args
                )
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_new(
                  repltype,
                  args
                )
                output_6
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_any_from_script : vx_core.Func_any_from_any_context {
    fun vx_any_from_script(context : vx_core.Type_context, script : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_any_from_script : vx_core.Class_base, Func_any_from_script {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_script = vx_repl.Class_any_from_script()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_any_from_script = vx_repl.Class_any_from_script()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-script", // name
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
      var output : vx_core.Type_any = vx_repl.e_any_from_script
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_any_from_script
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_repl.f_any_from_script(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var script : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_any_from_script(context, script)
      return output
    }

    override fun vx_any_from_script(context : vx_core.Type_context, script : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_any_from_script(context, script)
      return output
    }

  }

  val e_any_from_script : vx_repl.Func_any_from_script = vx_repl.Class_any_from_script()
  val t_any_from_script : vx_repl.Func_any_from_script = vx_repl.Class_any_from_script()

  fun f_any_from_script(context : vx_core.Type_context, script : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var textblock : vx_data_textblock.Type_textblock = vx_repl.f_textblock_from_script(
          script
        )
        var repl : vx_repl.Type_repl = vx_repl.f_repl_from_textblock(
          textblock
        )
        var output_1 : vx_core.Type_any = vx_repl.f_any_from_repl(
          context,
          repl
        )
        output_1
      })
    )
    return output
  }


  interface Func_anylist_from_repllist : vx_core.Func_any_from_any_context {
    fun vx_anylist_from_repllist(context : vx_core.Type_context, repllist : vx_repl.Type_repllist) : vx_core.Type_anylist
  }

  class Class_anylist_from_repllist : vx_core.Class_base, Func_anylist_from_repllist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_anylist_from_repllist = vx_repl.Class_anylist_from_repllist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_anylist_from_repllist = vx_repl.Class_anylist_from_repllist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "anylist", // name
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
      var output : vx_core.Type_any = vx_repl.e_anylist_from_repllist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_anylist_from_repllist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_repl.Type_repllist = value as vx_repl.Type_repllist
      var outputval : vx_core.Type_any = vx_repl.f_anylist_from_repllist(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var repllist : vx_repl.Type_repllist = vx_core.f_any_from_any(vx_repl.t_repllist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_anylist_from_repllist(context, repllist)
      return output
    }

    override fun vx_anylist_from_repllist(context : vx_core.Type_context, repllist : vx_repl.Type_repllist) : vx_core.Type_anylist {
      var output : vx_core.Type_anylist = vx_repl.f_anylist_from_repllist(context, repllist)
      return output
    }

  }

  val e_anylist_from_repllist : vx_repl.Func_anylist_from_repllist = vx_repl.Class_anylist_from_repllist()
  val t_anylist_from_repllist : vx_repl.Func_anylist_from_repllist = vx_repl.Class_anylist_from_repllist()

  fun f_anylist_from_repllist(context : vx_core.Type_context, repllist : vx_repl.Type_repllist) : vx_core.Type_anylist {
    var output : vx_core.Type_anylist = vx_core.e_anylist
    output = vx_core.f_list_from_list_1(
      vx_core.t_anylist,
      repllist,
      vx_core.t_any_from_any.vx_fn_new({repl_any : vx_core.Type_any ->
        var repl : vx_repl.Type_repl = vx_core.f_any_from_any(vx_repl.t_repl, repl_any)
        var output_1 : vx_core.Type_any = vx_repl.f_any_from_repl(
          context,
          repl
        )
        output_1
      })
    )
    return output
  }


  interface Func_argmap_from_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_argmap_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_core.Type_argmap
  }

  class Class_argmap_from_textblock_argmap : vx_core.Class_base, Func_argmap_from_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_argmap_from_textblock_argmap = vx_repl.Class_argmap_from_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_argmap_from_textblock_argmap = vx_repl.Class_argmap_from_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_arg), // allowtypes
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
      var output : vx_core.Type_any = vx_repl.e_argmap_from_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_argmap_from_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_argmap_from_textblock_argmap(textblock, argmap)
      return output
    }

    override fun vx_argmap_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_core.Type_argmap {
      var output : vx_core.Type_argmap = vx_repl.f_argmap_from_textblock_argmap(textblock, argmap)
      return output
    }

  }

  val e_argmap_from_textblock_argmap : vx_repl.Func_argmap_from_textblock_argmap = vx_repl.Class_argmap_from_textblock_argmap()
  val t_argmap_from_textblock_argmap : vx_repl.Func_argmap_from_textblock_argmap = vx_repl.Class_argmap_from_textblock_argmap()

  fun f_argmap_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_core.Type_argmap {
    var output : vx_core.Type_argmap = vx_core.e_argmap
    output = vx_core.f_if_1(
      vx_core.t_argmap,
      vx_core.f_ne(
        vx_core.vx_new_string("delimbracketsquare"),
        textblock.delim().name()
      ),
      argmap,
      argmap
    )
    return output
  }


  interface Func_const_from_string : vx_core.Func_any_from_any {
    fun vx_const_from_string(text : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_const_from_string : vx_core.Class_base, Func_const_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_const_from_string = vx_repl.Class_const_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_const_from_string = vx_repl.Class_const_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "const<-string", // name
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
      var output : vx_core.Type_any = vx_repl.e_const_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_const_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_repl.f_const_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_const_from_string(text)
      return output
    }

    override fun vx_const_from_string(text : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_const_from_string(text)
      return output
    }

  }

  val e_const_from_string : vx_repl.Func_const_from_string = vx_repl.Class_const_from_string()
  val t_const_from_string : vx_repl.Func_const_from_string = vx_repl.Class_const_from_string()

  fun f_const_from_string(text : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pkgpos : vx_core.Type_int = vx_type.f_int_from_string_findlast(
          text,
          vx_core.vx_new_string("/")
        )
        var pkgname : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          vx_core.f_eq(
            vx_core.vx_new_int(0),
            pkgpos
          ),
          vx_core.vx_new_string("vx/core"),
          vx_type.f_string_from_string_end(
            text,
            vx_core.f_minus1(
              pkgpos
            )
          )
        )
        var name : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          vx_core.f_eq(
            vx_core.vx_new_int(0),
            pkgpos
          ),
          text,
          vx_type.f_string_from_string_start(
            text,
            vx_core.f_plus1(
              pkgpos
            )
          )
        )
        var pkg : vx_core.Type_package = vx_core.f_package_global_from_name(
          pkgname
        )
        var constmap : vx_core.Type_constmap = pkg.constmap()
        var constval : vx_core.Type_any = vx_core.f_any_from_map(
          vx_core.t_any,
          constmap,
          name
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_1(
          vx_core.t_any,
          vx_core.f_notempty_1(
            constval
          ),
          constval,
          vx_core.f_empty(
            vx_core.t_any
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_repl_bracket_from_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_bracket_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl
  }

  class Class_repl_bracket_from_textblock_argmap : vx_core.Class_base, Func_repl_bracket_from_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_bracket_from_textblock_argmap = vx_repl.Class_repl_bracket_from_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_bracket_from_textblock_argmap = vx_repl.Class_repl_bracket_from_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_bracket_from_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_bracket_from_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap)
      return output
    }

    override fun vx_repl_bracket_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap)
      return output
    }

  }

  val e_repl_bracket_from_textblock_argmap : vx_repl.Func_repl_bracket_from_textblock_argmap = vx_repl.Class_repl_bracket_from_textblock_argmap()
  val t_repl_bracket_from_textblock_argmap : vx_repl.Func_repl_bracket_from_textblock_argmap = vx_repl.Class_repl_bracket_from_textblock_argmap()

  fun f_repl_bracket_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_empty(
      vx_repl.t_repl
    )
    return output
  }


  interface Func_repl_empty_from_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_empty_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl
  }

  class Class_repl_empty_from_textblock_argmap : vx_core.Class_base, Func_repl_empty_from_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_empty_from_textblock_argmap = vx_repl.Class_repl_empty_from_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_empty_from_textblock_argmap = vx_repl.Class_repl_empty_from_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_empty_from_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_empty_from_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap)
      return output
    }

    override fun vx_repl_empty_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap)
      return output
    }

  }

  val e_repl_empty_from_textblock_argmap : vx_repl.Func_repl_empty_from_textblock_argmap = vx_repl.Class_repl_empty_from_textblock_argmap()
  val t_repl_empty_from_textblock_argmap : vx_repl.Func_repl_empty_from_textblock_argmap = vx_repl.Class_repl_empty_from_textblock_argmap()

  fun f_repl_empty_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_let(
      vx_repl.t_repl,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var children : vx_data_textblock.Type_textblocklist = textblock.children()
        var len : vx_core.Type_int = vx_core.f_length_1(
          children
        )
        var output_1 : vx_core.Type_any = vx_core.f_switch(
          vx_repl.t_repl,
          len,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_int(0),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_repl.f_repl_from_string_argmap(
                  textblock.text(),
                  argmap
                )
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_core.vx_new_int(1),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_repl.f_repl_from_textblock_argmap(
                  vx_core.f_any_from_list(
                    vx_data_textblock.t_textblock,
                    children,
                    vx_core.vx_new_int(1)
                  ),
                  argmap
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.f_msg_from_error(
                      vx_core.vx_new_string("Empty delim cannot have more than one child.")
                    )
                  )
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


  interface Func_repl_paren_from_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_paren_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl
  }

  class Class_repl_paren_from_textblock_argmap : vx_core.Class_base, Func_repl_paren_from_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_paren_from_textblock_argmap = vx_repl.Class_repl_paren_from_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_paren_from_textblock_argmap = vx_repl.Class_repl_paren_from_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_paren_from_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_paren_from_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap)
      return output
    }

    override fun vx_repl_paren_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap)
      return output
    }

  }

  val e_repl_paren_from_textblock_argmap : vx_repl.Func_repl_paren_from_textblock_argmap = vx_repl.Class_repl_paren_from_textblock_argmap()
  val t_repl_paren_from_textblock_argmap : vx_repl.Func_repl_paren_from_textblock_argmap = vx_repl.Class_repl_paren_from_textblock_argmap()

  fun f_repl_paren_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_let(
      vx_repl.t_repl,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var childlst : vx_data_textblock.Type_textblocklist = textblock.children()
        var children : vx_data_textblock.Type_textblocklist = vx_data_textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          vx_data_textblock.c_delimwhitespace
        )
        var tbfunc : vx_data_textblock.Type_textblock = vx_core.f_any_from_list(
          vx_data_textblock.t_textblock,
          children,
          vx_core.vx_new_int(1)
        )
        var sfunc : vx_core.Type_string = tbfunc.text()
        var replfunc : vx_repl.Type_repl = vx_repl.f_repl_from_string_argmap(
          sfunc,
          argmap
        )
        var typefunc : vx_core.Type_any = replfunc.type()
        var posarg : vx_core.Type_int = vx_core.f_switch(
          vx_core.t_int,
          typefunc,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.t_let,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.vx_new_int(3)
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_core.t_fn,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.vx_new_int(3)
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.vx_new_int(2)
                output_4
              })
            )
          )
        )
        var argmap2 : vx_core.Type_argmap = vx_core.f_switch(
          vx_core.t_argmap,
          typefunc,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.t_let,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_repl.f_argmap_from_textblock_argmap(
                  vx_core.f_any_from_list(
                    vx_data_textblock.t_textblock,
                    children,
                    vx_core.vx_new_int(3)
                  ),
                  argmap
                )
                output_5
              })
            ),
            vx_core.f_case_1(
              vx_core.t_fn,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_repl.f_argmap_from_textblock_argmap(
                  vx_core.f_any_from_list(
                    vx_data_textblock.t_textblock,
                    children,
                    vx_core.vx_new_int(3)
                  ),
                  argmap
                )
                output_6
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = argmap
                output_7
              })
            )
          )
        )
        var tbargs : vx_data_textblock.Type_textblocklist = vx_collection.f_list_from_list_start(
          vx_data_textblock.t_textblocklist,
          children,
          posarg
        )
        var replargs : vx_repl.Type_repllist = vx_repl.f_repllist_from_textblocklist_argmap(
          tbargs,
          argmap
        )
        var output_1 : vx_core.Type_any = vx_core.f_copy(
          replfunc,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":repllist"),
            replargs
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_repl_from_liblist_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_from_liblist_string(liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_repl.Type_repl
  }

  class Class_repl_from_liblist_string : vx_core.Class_base, Func_repl_from_liblist_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_liblist_string = vx_repl.Class_repl_from_liblist_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_liblist_string = vx_repl.Class_repl_from_liblist_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_liblist_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_liblist_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var liblist : vx_repl.Type_liblist = vx_core.f_any_from_any(vx_repl.t_liblist, arglist.vx_any(vx_core.vx_new_int(0)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_from_liblist_string(liblist, text)
      return output
    }

    override fun vx_repl_from_liblist_string(liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_liblist_string(liblist, text)
      return output
    }

  }

  val e_repl_from_liblist_string : vx_repl.Func_repl_from_liblist_string = vx_repl.Class_repl_from_liblist_string()
  val t_repl_from_liblist_string : vx_repl.Func_repl_from_liblist_string = vx_repl.Class_repl_from_liblist_string()

  fun f_repl_from_liblist_string(liblist : vx_repl.Type_liblist, text : vx_core.Type_string) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    return output
  }


  interface Func_repl_from_macro : vx_core.Func_any_from_any_context {
    fun vx_repl_from_macro(context : vx_core.Type_context, anylist : vx_core.Type_anylist) : vx_repl.Type_repl
  }

  class Class_repl_from_macro : vx_core.Class_base, Func_repl_from_macro {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_macro = vx_repl.Class_repl_from_macro()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_macro = vx_repl.Class_repl_from_macro()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_macro
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_macro
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_repl.f_repl_from_macro(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var anylist : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_repl_from_macro(context, anylist)
      return output
    }

    override fun vx_repl_from_macro(context : vx_core.Type_context, anylist : vx_core.Type_anylist) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_macro(context, anylist)
      return output
    }

  }

  val e_repl_from_macro : vx_repl.Func_repl_from_macro = vx_repl.Class_repl_from_macro()
  val t_repl_from_macro : vx_repl.Func_repl_from_macro = vx_repl.Class_repl_from_macro()

  fun f_repl_from_macro(context : vx_core.Type_context, anylist : vx_core.Type_anylist) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_let(
      vx_repl.t_repl,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var textlist : vx_core.Type_stringlist = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          anylist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, item_any)
            var output_2 : vx_core.Type_any = vx_core.f_let(
              vx_core.t_string,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var typ : vx_core.Type_any = vx_core.f_type_from_any(
                  item
                )
                var output_3 : vx_core.Type_any = vx_core.f_switch(
                  vx_core.t_string,
                  typ,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_case_1(
                      vx_core.t_string,
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = vx_core.f_any_from_any(
                          vx_core.t_string,
                          item
                        )
                        output_4
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_string_from_any(
                          item
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
        var script : vx_core.Type_string = vx_type.f_string_from_stringlist_join(
          textlist,
          vx_core.vx_new_string("")
        )
        var tb : vx_data_textblock.Type_textblock = vx_repl.f_textblock_from_script(
          script
        )
        var output_1 : vx_core.Type_any = vx_repl.f_repl_from_textblock(
          tb
        )
        output_1
      })
    )
    return output
  }


  interface Func_repl_from_script : vx_core.Func_any_from_any {
    fun vx_repl_from_script(script : vx_core.Type_string) : vx_repl.Type_repl
  }

  class Class_repl_from_script : vx_core.Class_base, Func_repl_from_script {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_script = vx_repl.Class_repl_from_script()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_script = vx_repl.Class_repl_from_script()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_script
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_script
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_repl.f_repl_from_script(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var script : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_repl_from_script(script)
      return output
    }

    override fun vx_repl_from_script(script : vx_core.Type_string) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_script(script)
      return output
    }

  }

  val e_repl_from_script : vx_repl.Func_repl_from_script = vx_repl.Class_repl_from_script()
  val t_repl_from_script : vx_repl.Func_repl_from_script = vx_repl.Class_repl_from_script()

  fun f_repl_from_script(script : vx_core.Type_string) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_let(
      vx_repl.t_repl,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var textblock : vx_data_textblock.Type_textblock = vx_repl.f_textblock_from_script(
          script
        )
        var output_1 : vx_core.Type_any = vx_repl.f_repl_from_textblock(
          textblock
        )
        output_1
      })
    )
    return output
  }


  interface Func_repl_from_string_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_from_string_argmap(text : vx_core.Type_string, argmap : vx_core.Type_argmap) : vx_repl.Type_repl
  }

  class Class_repl_from_string_argmap : vx_core.Class_base, Func_repl_from_string_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_string_argmap = vx_repl.Class_repl_from_string_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_string_argmap = vx_repl.Class_repl_from_string_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_string_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_string_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_from_string_argmap(text, argmap)
      return output
    }

    override fun vx_repl_from_string_argmap(text : vx_core.Type_string, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_string_argmap(text, argmap)
      return output
    }

  }

  val e_repl_from_string_argmap : vx_repl.Func_repl_from_string_argmap = vx_repl.Class_repl_from_string_argmap()
  val t_repl_from_string_argmap : vx_repl.Func_repl_from_string_argmap = vx_repl.Class_repl_from_string_argmap()

  fun f_repl_from_string_argmap(text : vx_core.Type_string, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_if_2(
      vx_repl.t_repl,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_and(
              vx_type.f_boolean_from_string_starts(
                text,
                vx_core.c_quote
              ),
              vx_type.f_boolean_from_string_ends(
                text,
                vx_core.c_quote
              )
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_repl.t_repl,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":value"),
                vx_type.f_string_from_string_start_end(
                  text,
                  vx_core.vx_new_int(2),
                  vx_core.vx_new_int(-1)
                )
              )
            )
            output_2
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_is_int(
              text
            )
            output_3
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_core.f_new(
              vx_repl.t_repl,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":value"),
                vx_core.f_int_from_string(
                  text
                )
              )
            )
            output_4
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_5 : vx_core.Type_any = vx_core.f_is_float(
              text
            )
            output_5
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_6 : vx_core.Type_any = vx_core.f_new(
              vx_repl.t_repl,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":value"),
                vx_core.f_float_from_string(
                  text
                )
              )
            )
            output_6
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_7 : vx_core.Type_any = vx_core.f_let(
              vx_repl.t_repl,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var arg : vx_core.Type_any = vx_core.f_any_from_map(
                  vx_core.t_any,
                  argmap,
                  text
                )
                var output_8 : vx_core.Type_any = vx_core.f_if_2(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_9 : vx_core.Type_any = vx_core.f_notempty_1(
                          arg
                        )
                        output_9
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_10 : vx_core.Type_any = vx_core.f_new(
                          vx_repl.t_repl,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":value"),
                            arg
                          )
                        )
                        output_10
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_11 : vx_core.Type_any = vx_core.f_let(
                          vx_repl.t_repl,
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var cnst : vx_core.Type_any = vx_repl.f_const_from_string(
                              text
                            )
                            var output_12 : vx_core.Type_any = vx_core.f_if_2(
                              vx_repl.t_repl,
                              vx_core.vx_new(
                                vx_core.t_thenelselist,
                                vx_core.f_then(
                                  vx_core.t_boolean_from_func.vx_fn_new({ ->
                                    var output_13 : vx_core.Type_any = vx_core.f_notempty_1(
                                      cnst
                                    )
                                    output_13
                                  }),
                                  vx_core.t_any_from_func.vx_fn_new({ ->
                                    var output_14 : vx_core.Type_any = vx_core.f_new(
                                      vx_repl.t_repl,
                                      vx_core.vx_new(
                                        vx_core.t_anylist,
                                        vx_core.vx_new_string(":value"),
                                        cnst
                                      )
                                    )
                                    output_14
                                  })
                                ),
                                vx_core.f_else(
                                  vx_core.t_any_from_func.vx_fn_new({ ->
                                    var output_15 : vx_core.Type_any = vx_core.f_let(
                                      vx_repl.t_repl,
                                      vx_core.t_any_from_func.vx_fn_new({ ->
                                        var typefunc : vx_core.Type_any = vx_repl.f_typefunc_from_string(
                                          text
                                        )
                                        var output_16 : vx_core.Type_any = vx_core.f_if_2(
                                          vx_repl.t_repl,
                                          vx_core.vx_new(
                                            vx_core.t_thenelselist,
                                            vx_core.f_then(
                                              vx_core.t_boolean_from_func.vx_fn_new({ ->
                                                var output_17 : vx_core.Type_any = vx_core.f_notempty_1(
                                                  typefunc
                                                )
                                                output_17
                                              }),
                                              vx_core.t_any_from_func.vx_fn_new({ ->
                                                var output_18 : vx_core.Type_any = vx_core.f_new(
                                                  vx_repl.t_repl,
                                                  vx_core.vx_new(
                                                    vx_core.t_anylist,
                                                    vx_core.vx_new_string(":type"),
                                                    typefunc
                                                  )
                                                )
                                                output_18
                                              })
                                            ),
                                            vx_core.f_else(
                                              vx_core.t_any_from_func.vx_fn_new({ ->
                                                var output_19 : vx_core.Type_any = vx_core.f_new(
                                                  vx_repl.t_repl,
                                                  vx_core.vx_new(
                                                    vx_core.t_anylist,
                                                    vx_core.f_msg_from_error_1(
                                                      vx_core.vx_new_string(":repltypenotfound"),
                                                      text
                                                    )
                                                  )
                                                )
                                                output_19
                                              })
                                            )
                                          )
                                        )
                                        output_16
                                      })
                                    )
                                    output_15
                                  })
                                )
                              )
                            )
                            output_12
                          })
                        )
                        output_11
                      })
                    )
                  )
                )
                output_8
              })
            )
            output_7
          })
        )
      )
    )
    return output
  }


  interface Func_repl_from_textblock : vx_core.Func_any_from_any {
    fun vx_repl_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_repl.Type_repl
  }

  class Class_repl_from_textblock : vx_core.Class_base, Func_repl_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_textblock = vx_repl.Class_repl_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_textblock = vx_repl.Class_repl_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_repl.f_repl_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_repl_from_textblock(textblock)
      return output
    }

    override fun vx_repl_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_textblock(textblock)
      return output
    }

  }

  val e_repl_from_textblock : vx_repl.Func_repl_from_textblock = vx_repl.Class_repl_from_textblock()
  val t_repl_from_textblock : vx_repl.Func_repl_from_textblock = vx_repl.Class_repl_from_textblock()

  fun f_repl_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_repl.f_repl_from_textblock_argmap(
      textblock,
      vx_core.f_empty(
        vx_core.t_argmap
      )
    )
    return output
  }


  interface Func_repl_from_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repl_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl
  }

  class Class_repl_from_textblock_argmap : vx_core.Class_base, Func_repl_from_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_textblock_argmap = vx_repl.Class_repl_from_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repl_from_textblock_argmap = vx_repl.Class_repl_from_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      var output : vx_core.Type_any = vx_repl.e_repl_from_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repl_from_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repl_from_textblock_argmap(textblock, argmap)
      return output
    }

    override fun vx_repl_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
      var output : vx_repl.Type_repl = vx_repl.f_repl_from_textblock_argmap(textblock, argmap)
      return output
    }

  }

  val e_repl_from_textblock_argmap : vx_repl.Func_repl_from_textblock_argmap = vx_repl.Class_repl_from_textblock_argmap()
  val t_repl_from_textblock_argmap : vx_repl.Func_repl_from_textblock_argmap = vx_repl.Class_repl_from_textblock_argmap()

  fun f_repl_from_textblock_argmap(textblock : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_repl {
    var output : vx_repl.Type_repl = vx_repl.e_repl
    output = vx_core.f_let(
      vx_repl.t_repl,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var delim : vx_data_textblock.Type_delim = textblock.delim()
        var starttext : vx_core.Type_string = delim.starttext()
        var output_1 : vx_core.Type_any = vx_core.f_switch(
          vx_repl.t_repl,
          starttext,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(""),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_repl.f_repl_empty_from_textblock_argmap(
                  textblock,
                  argmap
                )
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_data_textblock.c_delimparen.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_repl.f_repl_paren_from_textblock_argmap(
                  textblock,
                  argmap
                )
                output_3
              })
            ),
            vx_core.f_case_1(
              vx_data_textblock.c_delimbracketsquare.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_repl.f_repl_bracket_from_textblock_argmap(
                  textblock,
                  argmap
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


  interface Func_replarglist_from_replarglist_textblock_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_replarglist_from_replarglist_textblock_argmap(replargs : vx_repl.Type_replarglist, tb : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_replarglist
  }

  class Class_replarglist_from_replarglist_textblock_argmap : vx_core.Class_base, Func_replarglist_from_replarglist_textblock_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_replarglist_from_replarglist_textblock_argmap = vx_repl.Class_replarglist_from_replarglist_textblock_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_replarglist_from_replarglist_textblock_argmap = vx_repl.Class_replarglist_from_replarglist_textblock_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "replarglist", // name
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
      var output : vx_core.Type_any = vx_repl.e_replarglist_from_replarglist_textblock_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_replarglist_from_replarglist_textblock_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var replargs : vx_repl.Type_replarglist = vx_core.f_any_from_any(vx_repl.t_replarglist, arglist.vx_any(vx_core.vx_new_int(0)))
      var tb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap)
      return output
    }

    override fun vx_replarglist_from_replarglist_textblock_argmap(replargs : vx_repl.Type_replarglist, tb : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_replarglist {
      var output : vx_repl.Type_replarglist = vx_repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap)
      return output
    }

  }

  val e_replarglist_from_replarglist_textblock_argmap : vx_repl.Func_replarglist_from_replarglist_textblock_argmap = vx_repl.Class_replarglist_from_replarglist_textblock_argmap()
  val t_replarglist_from_replarglist_textblock_argmap : vx_repl.Func_replarglist_from_replarglist_textblock_argmap = vx_repl.Class_replarglist_from_replarglist_textblock_argmap()

  fun f_replarglist_from_replarglist_textblock_argmap(replargs : vx_repl.Type_replarglist, tb : vx_data_textblock.Type_textblock, argmap : vx_core.Type_argmap) : vx_repl.Type_replarglist {
    var output : vx_repl.Type_replarglist = vx_repl.e_replarglist
    output = vx_core.f_let(
      vx_repl.t_replarglist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var key : vx_core.Type_string = replargs.key()
        var current : vx_repl.Type_repl = replargs.current()
        var repllist : vx_repl.Type_repllist = replargs.repllist()
        var currlist : vx_repl.Type_repllist = current.repllist()
        var text : vx_core.Type_string = vx_data_textblock.t_textblock.text()
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_repl.t_replarglist,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  key,
                  vx_core.vx_new_string("")
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_if_2(
                  vx_repl.t_replarglist,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = vx_core.f_eq_1(
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            text
                          )
                        )
                        output_4
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_copy(
                          replargs,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":key"),
                            text
                          )
                        )
                        output_5
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_6 : vx_core.Type_any = vx_core.f_eq(
                          text,
                          vx_core.vx_new_string(":=")
                        )
                        output_6
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_7 : vx_core.Type_any = vx_core.f_copy(
                          replargs,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":key"),
                            text
                          )
                        )
                        output_7
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_8 : vx_core.Type_any = vx_core.f_eq(
                          text,
                          vx_core.vx_new_string(":doc")
                        )
                        output_8
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_9 : vx_core.Type_any = vx_core.f_copy(
                          replargs,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":key"),
                            text
                          )
                        )
                        output_9
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_10 : vx_core.Type_any = vx_core.f_copy(
                          replargs,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":current"),
                            vx_core.f_new(
                              vx_repl.t_repl,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                vx_core.vx_new_string(":name"),
                                text
                              )
                            ),
                            vx_core.vx_new_string(":repllist"),
                            vx_core.f_copy(
                              repllist,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                current
                              )
                            )
                          )
                        )
                        output_10
                      })
                    )
                  )
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_11 : vx_core.Type_any = vx_core.f_eq_1(
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    key
                  )
                )
                output_11
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_12 : vx_core.Type_any = vx_core.f_copy(
                  replargs,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":key"),
                    vx_core.vx_new_string(""),
                    vx_core.vx_new_string(":current"),
                    vx_core.f_copy(
                      current,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":type"),
                        text
                      )
                    )
                  )
                )
                output_12
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_13 : vx_core.Type_any = vx_core.f_eq(
                  key,
                  vx_core.vx_new_string(":=")
                )
                output_13
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_14 : vx_core.Type_any = vx_core.f_copy(
                  replargs,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":key"),
                    vx_core.vx_new_string(""),
                    vx_core.vx_new_string(":current"),
                    vx_core.f_copy(
                      current,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":repllist"),
                        vx_core.f_copy(
                          currlist,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_repl.f_repl_from_textblock_argmap(
                              tb,
                              argmap
                            )
                          )
                        )
                      )
                    )
                  )
                )
                output_14
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_15 : vx_core.Type_any = vx_core.f_eq(
                  key,
                  vx_core.vx_new_string(":doc")
                )
                output_15
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_16 : vx_core.Type_any = vx_core.f_copy(
                  replargs,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":key"),
                    vx_core.vx_new_string(""),
                    vx_core.vx_new_string(":current"),
                    vx_core.f_copy(
                      current,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":doc"),
                        text
                      )
                    )
                  )
                )
                output_16
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_17 : vx_core.Type_any = replargs
                output_17
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_repllist_from_textblocklist_argmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_repllist_from_textblocklist_argmap(textblocklist : vx_data_textblock.Type_textblocklist, argmap : vx_core.Type_argmap) : vx_repl.Type_repllist
  }

  class Class_repllist_from_textblocklist_argmap : vx_core.Class_base, Func_repllist_from_textblocklist_argmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repllist_from_textblocklist_argmap = vx_repl.Class_repllist_from_textblocklist_argmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_repllist_from_textblocklist_argmap = vx_repl.Class_repllist_from_textblocklist_argmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/repl", // pkgname
          "repllist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_repl.t_repl), // allowtypes
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
      var output : vx_core.Type_any = vx_repl.e_repllist_from_textblocklist_argmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_repllist_from_textblocklist_argmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblocklist : vx_data_textblock.Type_textblocklist = vx_core.f_any_from_any(vx_data_textblock.t_textblocklist, arglist.vx_any(vx_core.vx_new_int(0)))
      var argmap : vx_core.Type_argmap = vx_core.f_any_from_any(vx_core.t_argmap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap)
      return output
    }

    override fun vx_repllist_from_textblocklist_argmap(textblocklist : vx_data_textblock.Type_textblocklist, argmap : vx_core.Type_argmap) : vx_repl.Type_repllist {
      var output : vx_repl.Type_repllist = vx_repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap)
      return output
    }

  }

  val e_repllist_from_textblocklist_argmap : vx_repl.Func_repllist_from_textblocklist_argmap = vx_repl.Class_repllist_from_textblocklist_argmap()
  val t_repllist_from_textblocklist_argmap : vx_repl.Func_repllist_from_textblocklist_argmap = vx_repl.Class_repllist_from_textblocklist_argmap()

  fun f_repllist_from_textblocklist_argmap(textblocklist : vx_data_textblock.Type_textblocklist, argmap : vx_core.Type_argmap) : vx_repl.Type_repllist {
    var output : vx_repl.Type_repllist = vx_repl.e_repllist
    output = vx_core.f_list_from_list_1(
      vx_repl.t_repllist,
      textblocklist,
      vx_core.t_any_from_any.vx_fn_new({textblock_any : vx_core.Type_any ->
        var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, textblock_any)
        var output_1 : vx_core.Type_any = vx_repl.f_repl_from_textblock(
          textblock
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_from_script : vx_core.Func_any_from_any {
    fun vx_textblock_from_script(script : vx_core.Type_string) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_script : vx_core.Class_base, Func_textblock_from_script {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_textblock_from_script = vx_repl.Class_textblock_from_script()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_textblock_from_script = vx_repl.Class_textblock_from_script()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      var output : vx_core.Type_any = vx_repl.e_textblock_from_script
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_textblock_from_script
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_repl.f_textblock_from_script(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var script : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_textblock_from_script(script)
      return output
    }

    override fun vx_textblock_from_script(script : vx_core.Type_string) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_repl.f_textblock_from_script(script)
      return output
    }

  }

  val e_textblock_from_script : vx_repl.Func_textblock_from_script = vx_repl.Class_textblock_from_script()
  val t_textblock_from_script : vx_repl.Func_textblock_from_script = vx_repl.Class_textblock_from_script()

  fun f_textblock_from_script(script : vx_core.Type_string) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      script,
      vx_repl.c_delimvxlisp
    )
    return output
  }


  interface Func_typefunc_from_string : vx_core.Func_any_from_any {
    fun vx_typefunc_from_string(text : vx_core.Type_string) : vx_core.Type_any
  }

  class Class_typefunc_from_string : vx_core.Class_base, Func_typefunc_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_typefunc_from_string = vx_repl.Class_typefunc_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_repl.Class_typefunc_from_string = vx_repl.Class_typefunc_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
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
      var output : vx_core.Type_any = vx_repl.e_typefunc_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.t_typefunc_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_repl.f_typefunc_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_repl.f_typefunc_from_string(text)
      return output
    }

    override fun vx_typefunc_from_string(text : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_repl.f_typefunc_from_string(text)
      return output
    }

  }

  val e_typefunc_from_string : vx_repl.Func_typefunc_from_string = vx_repl.Class_typefunc_from_string()
  val t_typefunc_from_string : vx_repl.Func_typefunc_from_string = vx_repl.Class_typefunc_from_string()

  fun f_typefunc_from_string(text : vx_core.Type_string) : vx_core.Type_any {
    var output : vx_core.Type_any = vx_core.e_any
    output = vx_core.f_let(
      vx_core.t_any,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pkgpos : vx_core.Type_int = vx_type.f_int_from_string_findlast(
          text,
          vx_core.vx_new_string("/")
        )
        var pkgname : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          vx_core.f_eq(
            vx_core.vx_new_int(0),
            pkgpos
          ),
          vx_core.vx_new_string("vx/core"),
          vx_type.f_string_from_string_end(
            text,
            vx_core.f_minus1(
              pkgpos
            )
          )
        )
        var name : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          vx_core.f_eq(
            vx_core.vx_new_int(0),
            pkgpos
          ),
          text,
          vx_type.f_string_from_string_start(
            text,
            vx_core.f_plus1(
              pkgpos
            )
          )
        )
        var pkg : vx_core.Type_package = vx_core.f_package_global_from_name(
          pkgname
        )
        var typemap : vx_core.Type_typemap = pkg.typemap()
        var typeval : vx_core.Type_any = vx_core.f_any_from_map(
          vx_core.t_any,
          typemap,
          name
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_1(
          vx_core.t_any,
          vx_core.f_notempty_1(
            typeval
          ),
          typeval,
          vx_core.f_let(
            vx_core.t_any,
            vx_core.t_any_from_func.vx_fn_new({ ->
              var funcmap : vx_core.Type_funcmap = pkg.funcmap()
              var funcval : vx_core.Type_any = vx_core.f_any_from_map(
                vx_core.t_any,
                funcmap,
                name
              )
              var output_2 : vx_core.Type_any = vx_core.f_if_1(
                vx_core.t_any,
                vx_core.f_notempty_1(
                  funcval
                ),
                funcval,
                vx_core.f_empty(
                  vx_core.t_any
                )
              )
              output_2
            })
          )
        )
        output_1
      })
    )
    return output
  }


  init {
    Const_delimvxlisp.const_new(c_delimvxlisp)
    Const_delimvxlispbracket.const_new(c_delimvxlispbracket)
    Const_delimvxlispparen.const_new(c_delimvxlispparen)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("liblist", vx_repl.t_liblist)
    maptype.put("repl", vx_repl.t_repl)
    maptype.put("replarglist", vx_repl.t_replarglist)
    maptype.put("repllist", vx_repl.t_repllist)
    mapconst.put("delimvxlisp", vx_repl.c_delimvxlisp)
    mapconst.put("delimvxlispbracket", vx_repl.c_delimvxlispbracket)
    mapconst.put("delimvxlispparen", vx_repl.c_delimvxlispparen)
    mapfunc.put("any-repl<-functype-args", vx_repl.t_any_repl_from_functype_args)
    mapfunc.put("any<-liblist-string", vx_repl.t_any_from_liblist_string)
    mapfunc.put("any<-macro", vx_repl.t_any_from_macro)
    mapfunc.put("any<-repl", vx_repl.t_any_from_repl)
    mapfunc.put("any<-script", vx_repl.t_any_from_script)
    mapfunc.put("anylist<-repllist", vx_repl.t_anylist_from_repllist)
    mapfunc.put("argmap<-textblock-argmap", vx_repl.t_argmap_from_textblock_argmap)
    mapfunc.put("const<-string", vx_repl.t_const_from_string)
    mapfunc.put("repl-bracket<-textblock-argmap", vx_repl.t_repl_bracket_from_textblock_argmap)
    mapfunc.put("repl-empty<-textblock-argmap", vx_repl.t_repl_empty_from_textblock_argmap)
    mapfunc.put("repl-paren<-textblock-argmap", vx_repl.t_repl_paren_from_textblock_argmap)
    mapfunc.put("repl<-liblist-string", vx_repl.t_repl_from_liblist_string)
    mapfunc.put("repl<-macro", vx_repl.t_repl_from_macro)
    mapfunc.put("repl<-script", vx_repl.t_repl_from_script)
    mapfunc.put("repl<-string-argmap", vx_repl.t_repl_from_string_argmap)
    mapfunc.put("repl<-textblock", vx_repl.t_repl_from_textblock)
    mapfunc.put("repl<-textblock-argmap", vx_repl.t_repl_from_textblock_argmap)
    mapfunc.put("replarglist<-replarglist-textblock-argmap", vx_repl.t_replarglist_from_replarglist_textblock_argmap)
    mapfunc.put("repllist<-textblocklist-argmap", vx_repl.t_repllist_from_textblocklist_argmap)
    mapfunc.put("textblock<-script", vx_repl.t_textblock_from_script)
    mapfunc.put("typefunc<-string", vx_repl.t_typefunc_from_string)
    vx_core.vx_global_package_set("vx/repl", maptype, mapconst, mapfunc)
  }

}
