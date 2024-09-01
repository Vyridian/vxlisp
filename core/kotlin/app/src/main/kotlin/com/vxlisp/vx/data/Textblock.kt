package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_textblock {


  interface Type_delim : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun starttext() : vx_core.Type_string
    fun endtext() : vx_core.Type_string
    fun pos() : vx_core.Type_int
    fun delimlist() : vx_data_textblock.Type_delimlist
  }

  class Class_delim : vx_core.Class_base, Type_delim {
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

    var vx_p_starttext : vx_core.Type_string? = null

    override fun starttext() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_starttext
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_endtext : vx_core.Type_string? = null

    override fun endtext() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_endtext
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pos : vx_core.Type_int? = null

    override fun pos() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_pos
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_delimlist : vx_data_textblock.Type_delimlist? = null

    override fun delimlist() : vx_data_textblock.Type_delimlist {
      var output : vx_data_textblock.Type_delimlist = vx_data_textblock.e_delimlist
      var testnull : vx_data_textblock.Type_delimlist? = vx_p_delimlist
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
      } else if ((skey==":starttext")) {
        output = this.starttext()
      } else if ((skey==":endtext")) {
        output = this.endtext()
      } else if ((skey==":pos")) {
        output = this.pos()
      } else if ((skey==":delimlist")) {
        output = this.delimlist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":starttext", this.starttext())
      map.put(":endtext", this.endtext())
      map.put(":pos", this.pos())
      map.put(":delimlist", this.delimlist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_delim = vx_core.vx_copy(vx_data_textblock.e_delim, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_delim = this
      var ischanged : Boolean = false
      var value : vx_data_textblock.Class_delim = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_starttext : vx_core.Type_string = value.starttext()
      var vx_p_endtext : vx_core.Type_string = value.endtext()
      var vx_p_pos : vx_core.Type_int = value.pos()
      var vx_p_delimlist : vx_data_textblock.Type_delimlist = value.delimlist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":starttext")
      validkeys.add(":endtext")
      validkeys.add(":pos")
      validkeys.add(":delimlist")
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
            msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":starttext")) {
            if (valsub == vx_p_starttext) {
            } else if (valsub is vx_core.Type_string) {
              var valstarttext : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_starttext = valstarttext
            } else if (valsub is String) {
              ischanged = true
              vx_p_starttext = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("starttext"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":endtext")) {
            if (valsub == vx_p_endtext) {
            } else if (valsub is vx_core.Type_string) {
              var valendtext : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_endtext = valendtext
            } else if (valsub is String) {
              ischanged = true
              vx_p_endtext = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("endtext"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pos")) {
            if (valsub == vx_p_pos) {
            } else if (valsub is vx_core.Type_int) {
              var valpos : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_pos = valpos
            } else if (valsub is Int) {
              ischanged = true
              vx_p_pos = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pos"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":delimlist")) {
            if (valsub == vx_p_delimlist) {
            } else if (valsub is vx_data_textblock.Type_delimlist) {
              var valdelimlist : vx_data_textblock.Type_delimlist = valsub as vx_data_textblock.Type_delimlist
              ischanged = true
              vx_p_delimlist = valdelimlist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("delimlist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_textblock.Class_delim = vx_data_textblock.Class_delim()
        work.vx_p_name = vx_p_name
        work.vx_p_starttext = vx_p_starttext
        work.vx_p_endtext = vx_p_endtext
        work.vx_p_pos = vx_p_pos
        work.vx_p_delimlist = vx_p_delimlist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delim
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
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
      return output
    }

  }

  val e_delim : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()
  val t_delim : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()

  interface Type_delimlist : vx_core.Type_list {
    fun vx_listdelim() : List<vx_data_textblock.Type_delim>
    fun vx_delim(index : vx_core.Type_int) : vx_data_textblock.Type_delim
  }

  class Class_delimlist : vx_core.Class_base, Type_delimlist {
    constructor() {}

    var vx_p_list : List<vx_data_textblock.Type_delim> = vx_core.immutablelist(
      ArrayList<vx_data_textblock.Type_delim>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_delim(index : vx_core.Type_int) : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
      var list : vx_data_textblock.Class_delimlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_textblock.Type_delim> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listdelim() : List<vx_data_textblock.Type_delim> {
      var output : List<vx_data_textblock.Type_delim> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_textblock.Type_delim = this.vx_delim(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_delimlist = vx_core.vx_copy(vx_data_textblock.e_delimlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_delimlist = this
      var ischanged : Boolean = false
      var value : vx_data_textblock.Class_delimlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_textblock.Type_delim> = ArrayList<vx_data_textblock.Type_delim>(value.vx_listdelim())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_textblock.Type_delimlist) {
          var multi : vx_data_textblock.Type_delimlist = valsub as vx_data_textblock.Type_delimlist
          ischanged = true
          listval.addAll(multi.vx_listdelim())
        } else if (valsub is vx_data_textblock.Type_delim) {
          var allowsub : vx_data_textblock.Type_delim = valsub as vx_data_textblock.Type_delim
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_textblock.Type_delim) {
          ischanged = true
          listval.add(valsub as vx_data_textblock.Type_delim)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_textblock.Type_delim) {
              var valitem : vx_data_textblock.Type_delim = item as vx_data_textblock.Type_delim
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_textblock.Class_delimlist = vx_data_textblock.Class_delimlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_delimlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delimlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_delim), // allowtypes
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

  val e_delimlist : vx_data_textblock.Type_delimlist = vx_data_textblock.Class_delimlist()
  val t_delimlist : vx_data_textblock.Type_delimlist = vx_data_textblock.Class_delimlist()

  interface Type_textblock : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun text() : vx_core.Type_string
    fun startpos() : vx_core.Type_int
    fun endpos() : vx_core.Type_int
    fun curpos() : vx_core.Type_int
    fun line() : vx_core.Type_int
    fun column() : vx_core.Type_int
    fun delim() : vx_data_textblock.Type_delim
    fun close() : vx_data_textblock.Type_delim
    fun parent() : vx_data_textblock.Type_textblock
    fun children() : vx_data_textblock.Type_textblocklist
  }

  class Class_textblock : vx_core.Class_base, Type_textblock {
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

    var vx_p_text : vx_core.Type_string? = null

    override fun text() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_text
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_startpos : vx_core.Type_int? = null

    override fun startpos() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_startpos
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_endpos : vx_core.Type_int? = null

    override fun endpos() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_endpos
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_curpos : vx_core.Type_int? = null

    override fun curpos() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_curpos
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_line : vx_core.Type_int? = null

    override fun line() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_line
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_column : vx_core.Type_int? = null

    override fun column() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_column
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_delim : vx_data_textblock.Type_delim? = null

    override fun delim() : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
      var testnull : vx_data_textblock.Type_delim? = vx_p_delim
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_close : vx_data_textblock.Type_delim? = null

    override fun close() : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
      var testnull : vx_data_textblock.Type_delim? = vx_p_close
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_parent : vx_data_textblock.Type_textblock? = null

    override fun parent() : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
      var testnull : vx_data_textblock.Type_textblock? = vx_p_parent
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_children : vx_data_textblock.Type_textblocklist? = null

    override fun children() : vx_data_textblock.Type_textblocklist {
      var output : vx_data_textblock.Type_textblocklist = vx_data_textblock.e_textblocklist
      var testnull : vx_data_textblock.Type_textblocklist? = vx_p_children
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
      } else if ((skey==":text")) {
        output = this.text()
      } else if ((skey==":startpos")) {
        output = this.startpos()
      } else if ((skey==":endpos")) {
        output = this.endpos()
      } else if ((skey==":curpos")) {
        output = this.curpos()
      } else if ((skey==":line")) {
        output = this.line()
      } else if ((skey==":column")) {
        output = this.column()
      } else if ((skey==":delim")) {
        output = this.delim()
      } else if ((skey==":close")) {
        output = this.close()
      } else if ((skey==":parent")) {
        output = this.parent()
      } else if ((skey==":children")) {
        output = this.children()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":text", this.text())
      map.put(":startpos", this.startpos())
      map.put(":endpos", this.endpos())
      map.put(":curpos", this.curpos())
      map.put(":line", this.line())
      map.put(":column", this.column())
      map.put(":delim", this.delim())
      map.put(":close", this.close())
      map.put(":parent", this.parent())
      map.put(":children", this.children())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_textblock = vx_core.vx_copy(vx_data_textblock.e_textblock, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_textblock = this
      var ischanged : Boolean = false
      var value : vx_data_textblock.Class_textblock = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_text : vx_core.Type_string = value.text()
      var vx_p_startpos : vx_core.Type_int = value.startpos()
      var vx_p_endpos : vx_core.Type_int = value.endpos()
      var vx_p_curpos : vx_core.Type_int = value.curpos()
      var vx_p_line : vx_core.Type_int = value.line()
      var vx_p_column : vx_core.Type_int = value.column()
      var vx_p_delim : vx_data_textblock.Type_delim = value.delim()
      var vx_p_close : vx_data_textblock.Type_delim = value.close()
      var vx_p_parent : vx_data_textblock.Type_textblock = value.parent()
      var vx_p_children : vx_data_textblock.Type_textblocklist = value.children()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":text")
      validkeys.add(":startpos")
      validkeys.add(":endpos")
      validkeys.add(":curpos")
      validkeys.add(":line")
      validkeys.add(":column")
      validkeys.add(":delim")
      validkeys.add(":close")
      validkeys.add(":parent")
      validkeys.add(":children")
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
            msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":text")) {
            if (valsub == vx_p_text) {
            } else if (valsub is vx_core.Type_string) {
              var valtext : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_text = valtext
            } else if (valsub is String) {
              ischanged = true
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("text"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":startpos")) {
            if (valsub == vx_p_startpos) {
            } else if (valsub is vx_core.Type_int) {
              var valstartpos : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_startpos = valstartpos
            } else if (valsub is Int) {
              ischanged = true
              vx_p_startpos = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("startpos"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":endpos")) {
            if (valsub == vx_p_endpos) {
            } else if (valsub is vx_core.Type_int) {
              var valendpos : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_endpos = valendpos
            } else if (valsub is Int) {
              ischanged = true
              vx_p_endpos = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("endpos"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":curpos")) {
            if (valsub == vx_p_curpos) {
            } else if (valsub is vx_core.Type_int) {
              var valcurpos : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_curpos = valcurpos
            } else if (valsub is Int) {
              ischanged = true
              vx_p_curpos = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("curpos"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":line")) {
            if (valsub == vx_p_line) {
            } else if (valsub is vx_core.Type_int) {
              var valline : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_line = valline
            } else if (valsub is Int) {
              ischanged = true
              vx_p_line = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("line"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":column")) {
            if (valsub == vx_p_column) {
            } else if (valsub is vx_core.Type_int) {
              var valcolumn : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_column = valcolumn
            } else if (valsub is Int) {
              ischanged = true
              vx_p_column = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("column"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":delim")) {
            if (valsub == vx_p_delim) {
            } else if (valsub is vx_data_textblock.Type_delim) {
              var valdelim : vx_data_textblock.Type_delim = valsub as vx_data_textblock.Type_delim
              ischanged = true
              vx_p_delim = valdelim
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("delim"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":close")) {
            if (valsub == vx_p_close) {
            } else if (valsub is vx_data_textblock.Type_delim) {
              var valclose : vx_data_textblock.Type_delim = valsub as vx_data_textblock.Type_delim
              ischanged = true
              vx_p_close = valclose
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("close"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":parent")) {
            if (valsub == vx_p_parent) {
            } else if (valsub is vx_data_textblock.Type_textblock) {
              var valparent : vx_data_textblock.Type_textblock = valsub as vx_data_textblock.Type_textblock
              ischanged = true
              vx_p_parent = valparent
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("parent"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":children")) {
            if (valsub == vx_p_children) {
            } else if (valsub is vx_data_textblock.Type_textblocklist) {
              var valchildren : vx_data_textblock.Type_textblocklist = valsub as vx_data_textblock.Type_textblocklist
              ischanged = true
              vx_p_children = valchildren
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("children"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_textblock.Class_textblock = vx_data_textblock.Class_textblock()
        work.vx_p_name = vx_p_name
        work.vx_p_text = vx_p_text
        work.vx_p_startpos = vx_p_startpos
        work.vx_p_endpos = vx_p_endpos
        work.vx_p_curpos = vx_p_curpos
        work.vx_p_line = vx_p_line
        work.vx_p_column = vx_p_column
        work.vx_p_delim = vx_p_delim
        work.vx_p_close = vx_p_close
        work.vx_p_parent = vx_p_parent
        work.vx_p_children = vx_p_children
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
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
      )
      return output
    }

  }

  val e_textblock : vx_data_textblock.Type_textblock = vx_data_textblock.Class_textblock()
  val t_textblock : vx_data_textblock.Type_textblock = vx_data_textblock.Class_textblock()

  interface Type_textblocklist : vx_core.Type_list {
    fun vx_listtextblock() : List<vx_data_textblock.Type_textblock>
    fun vx_textblock(index : vx_core.Type_int) : vx_data_textblock.Type_textblock
  }

  class Class_textblocklist : vx_core.Class_base, Type_textblocklist {
    constructor() {}

    var vx_p_list : List<vx_data_textblock.Type_textblock> = vx_core.immutablelist(
      ArrayList<vx_data_textblock.Type_textblock>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_textblock(index : vx_core.Type_int) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
      var list : vx_data_textblock.Class_textblocklist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_textblock.Type_textblock> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtextblock() : List<vx_data_textblock.Type_textblock> {
      var output : List<vx_data_textblock.Type_textblock> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_textblock.Type_textblock = this.vx_textblock(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_textblocklist = vx_core.vx_copy(vx_data_textblock.e_textblocklist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_textblock.Type_textblocklist = this
      var ischanged : Boolean = false
      var value : vx_data_textblock.Class_textblocklist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_textblock.Type_textblock> = ArrayList<vx_data_textblock.Type_textblock>(value.vx_listtextblock())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_textblock.Type_textblocklist) {
          var multi : vx_data_textblock.Type_textblocklist = valsub as vx_data_textblock.Type_textblocklist
          ischanged = true
          listval.addAll(multi.vx_listtextblock())
        } else if (valsub is vx_data_textblock.Type_textblock) {
          var allowsub : vx_data_textblock.Type_textblock = valsub as vx_data_textblock.Type_textblock
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_textblock.Type_textblock) {
          ischanged = true
          listval.add(valsub as vx_data_textblock.Type_textblock)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_textblock.Type_textblock) {
              var valitem : vx_data_textblock.Type_textblock = item as vx_data_textblock.Type_textblock
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_textblock.Class_textblocklist = vx_data_textblock.Class_textblocklist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_textblocklist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblocklist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_textblock), // allowtypes
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

  val e_textblocklist : vx_data_textblock.Type_textblocklist = vx_data_textblock.Class_textblocklist()
  val t_textblocklist : vx_data_textblock.Type_textblocklist = vx_data_textblock.Class_textblocklist()

  class Const_delimbracketangle {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketangle", // name
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
          vx_core.vx_new_string("delimbracketangle"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("<"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string(">")
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

  val c_delimbracketangle : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimbracketcurly {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketcurly", // name
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
          vx_core.vx_new_string("delimbracketcurly"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("{"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("}")
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

  val c_delimbracketcurly : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimbracketsquare {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketsquare", // name
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
          vx_core.vx_new_string("delimbracketsquare"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("["),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("]")
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

  val c_delimbracketsquare : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimclose {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclose", // name
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
          vx_core.vx_new_string("delimclose")
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

  val c_delimclose : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimclosing {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclosing", // name
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
          vx_core.vx_new_string("delimclosing")
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

  val c_delimclosing : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimcomma {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomma", // name
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
          vx_core.vx_new_string("delimcomma"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string(",")
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

  val c_delimcomma : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimcomment {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomment", // name
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
          vx_core.vx_new_string("delimcomment"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("//"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("\n")
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

  val c_delimcomment : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimcommentblock {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcommentblock", // name
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
          vx_core.vx_new_string("delimcommentblock"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("/*"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("*/")
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

  val c_delimcommentblock : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimline {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimline", // name
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
          vx_core.vx_new_string("delimline"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("\n")
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

  val c_delimline : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimlisttest1 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest1", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_delim), // allowtypes
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

    fun const_new(output : vx_data_textblock.Type_delimlist) : Unit {
      var outval : vx_data_textblock.Class_delimlist = output as vx_data_textblock.Class_delimlist
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delimlist = vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_data_textblock.c_delimtest2
        )
      )
      outval.vx_p_list = value.vx_listdelim()
    }

    }
  }

  val c_delimlisttest1 : vx_data_textblock.Type_delimlist = vx_data_textblock.Class_delimlist()


  class Const_delimlisttest2 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest2", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_delim), // allowtypes
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

    fun const_new(output : vx_data_textblock.Type_delimlist) : Unit {
      var outval : vx_data_textblock.Class_delimlist = output as vx_data_textblock.Class_delimlist
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delimlist = vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_data_textblock.c_delimcomma,
          vx_data_textblock.c_delimtest3
        )
      )
      outval.vx_p_list = value.vx_listdelim()
    }

    }
  }

  val c_delimlisttest2 : vx_data_textblock.Type_delimlist = vx_data_textblock.Class_delimlist()


  class Const_delimlisttest3 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest3", // name
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_delim), // allowtypes
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

    fun const_new(output : vx_data_textblock.Type_delimlist) : Unit {
      var outval : vx_data_textblock.Class_delimlist = output as vx_data_textblock.Class_delimlist
      outval.vx_p_constdef = constdef()
      var value : vx_data_textblock.Type_delimlist = vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_data_textblock.c_delimcomma,
          vx_data_textblock.c_delimwhitespace
        )
      )
      outval.vx_p_list = value.vx_listdelim()
    }

    }
  }

  val c_delimlisttest3 : vx_data_textblock.Type_delimlist = vx_data_textblock.Class_delimlist()


  class Const_delimnonwhitespace {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimnonwhitespace", // name
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
          vx_core.vx_new_string("delimnonwhitespace"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string(":nonwhitespace"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string(":whitespace")
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

  val c_delimnonwhitespace : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimparen {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimparen", // name
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
          vx_core.vx_new_string("delimparen"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("("),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string(")")
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

  val c_delimparen : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimquote {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquote", // name
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
          vx_core.vx_new_string("delimquote"),
          vx_core.vx_new_string(":starttext"),
          vx_core.c_quote,
          vx_core.vx_new_string(":endtext"),
          vx_core.c_quote
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

  val c_delimquote : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimquoteblock {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquoteblock", // name
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
          vx_core.vx_new_string("delimquoteblock"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("`"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("`")
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

  val c_delimquoteblock : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimspace {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimspace", // name
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
          vx_core.vx_new_string("delimspace"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string(" "),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string(" ")
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

  val c_delimspace : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimtest1 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest1", // name
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
          vx_core.vx_new_string(":delimlist"),
          vx_data_textblock.c_delimlisttest1
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

  val c_delimtest1 : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimtest2 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest2", // name
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
        vx_data_textblock.c_delimbracketangle,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":delimlist"),
          vx_data_textblock.c_delimlisttest2
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

  val c_delimtest2 : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimtest3 {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest3", // name
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
        vx_data_textblock.c_delimbracketcurly,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":delimlist"),
          vx_data_textblock.c_delimlisttest3
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

  val c_delimtest3 : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimtext {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtext", // name
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
          vx_core.vx_new_string("delimtext")
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

  val c_delimtext : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimwhitespace {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimwhitespace", // name
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
          vx_core.vx_new_string("delimwhitespace"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string(":whitespace")
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

  val c_delimwhitespace : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  interface Func_children_from_textblock : vx_core.Func_any_from_any {
    fun vx_children_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblocklist
  }

  class Class_children_from_textblock : vx_core.Class_base, Func_children_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_children_from_textblock = vx_data_textblock.Class_children_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_children_from_textblock = vx_data_textblock.Class_children_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_textblock), // allowtypes
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
      var output : vx_core.Type_any = vx_data_textblock.e_children_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_children_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_children_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_children_from_textblock(textblock)
      return output
    }

    override fun vx_children_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblocklist {
      var output : vx_data_textblock.Type_textblocklist = vx_data_textblock.f_children_from_textblock(textblock)
      return output
    }

  }

  val e_children_from_textblock : vx_data_textblock.Func_children_from_textblock = vx_data_textblock.Class_children_from_textblock()
  val t_children_from_textblock : vx_data_textblock.Func_children_from_textblock = vx_data_textblock.Class_children_from_textblock()

  fun f_children_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblocklist {
    var output : vx_data_textblock.Type_textblocklist = vx_data_textblock.e_textblocklist
    output = textblock.children()
    return output
  }


  interface Func_delim_first_from_delim_delim : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_delim_first_from_delim_delim(delim1 : vx_data_textblock.Type_delim, delim2 : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim
  }

  class Class_delim_first_from_delim_delim : vx_core.Class_base, Func_delim_first_from_delim_delim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_first_from_delim_delim = vx_data_textblock.Class_delim_first_from_delim_delim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_first_from_delim_delim = vx_data_textblock.Class_delim_first_from_delim_delim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-delim-delim", // name
        0, // idx
        false, // async
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_delim_first_from_delim_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delim_first_from_delim_delim
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var delim1 : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim2 : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_delim_first_from_delim_delim(delim1, delim2)
      return output
    }

    override fun vx_delim_first_from_delim_delim(delim1 : vx_data_textblock.Type_delim, delim2 : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.f_delim_first_from_delim_delim(delim1, delim2)
      return output
    }

  }

  val e_delim_first_from_delim_delim : vx_data_textblock.Func_delim_first_from_delim_delim = vx_data_textblock.Class_delim_first_from_delim_delim()
  val t_delim_first_from_delim_delim : vx_data_textblock.Func_delim_first_from_delim_delim = vx_data_textblock.Class_delim_first_from_delim_delim()

  fun f_delim_first_from_delim_delim(delim1 : vx_data_textblock.Type_delim, delim2 : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim {
    var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
    output = vx_core.f_let(
      vx_data_textblock.t_delim,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pos1 : vx_core.Type_int = delim1.pos()
        var pos2 : vx_core.Type_int = delim2.pos()
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_delim,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_int(0),
                  pos2
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = delim1
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_int(0),
                  pos1
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = delim2
                output_5
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_is_empty_1(
                  delim2
                )
                output_6
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = delim1
                output_7
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_8 : vx_core.Type_any = vx_core.f_is_empty_1(
                  delim1
                )
                output_8
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = delim2
                output_9
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = vx_core.f_lt(
                  pos2,
                  pos1
                )
                output_10
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_11 : vx_core.Type_any = delim2
                output_11
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_12 : vx_core.Type_any = delim1
                output_12
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_delim_first_from_string_delimlist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_delim_first_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delim
  }

  class Class_delim_first_from_string_delimlist : vx_core.Class_base, Func_delim_first_from_string_delimlist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_first_from_string_delimlist = vx_data_textblock.Class_delim_first_from_string_delimlist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_first_from_string_delimlist = vx_data_textblock.Class_delim_first_from_string_delimlist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist", // name
        0, // idx
        false, // async
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_delim_first_from_string_delimlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delim_first_from_string_delimlist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delimlist : vx_data_textblock.Type_delimlist = vx_core.f_any_from_any(vx_data_textblock.t_delimlist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_delim_first_from_string_delimlist(text, delimlist)
      return output
    }

    override fun vx_delim_first_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.f_delim_first_from_string_delimlist(text, delimlist)
      return output
    }

  }

  val e_delim_first_from_string_delimlist : vx_data_textblock.Func_delim_first_from_string_delimlist = vx_data_textblock.Class_delim_first_from_string_delimlist()
  val t_delim_first_from_string_delimlist : vx_data_textblock.Func_delim_first_from_string_delimlist = vx_data_textblock.Class_delim_first_from_string_delimlist()

  fun f_delim_first_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delim {
    var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
    output = vx_core.f_if_2(
      vx_data_textblock.t_delim,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_is_empty_1(
              delimlist
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_empty(
              vx_data_textblock.t_delim
            )
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_data_textblock.t_delim,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var resolvedlist : vx_data_textblock.Type_delimlist = vx_data_textblock.f_delimlist_pos_from_string_delimlist(
                  text,
                  delimlist
                )
                var output_4 : vx_core.Type_any = vx_core.f_any_from_list_start_reduce(
                  vx_data_textblock.t_delim,
                  resolvedlist,
                  vx_core.f_empty(
                    vx_data_textblock.t_delim
                  ),
                  vx_core.t_any_from_reduce.vx_fn_new({delim1_lmb_any : vx_core.Type_any, delim2_lmb_any : vx_core.Type_any ->
                    val delim1_lmb : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, delim1_lmb_any)
                    val delim2_lmb : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, delim2_lmb_any)
                    var output_5 : vx_core.Type_any = vx_data_textblock.f_delim_first_from_delim_delim(delim1_lmb, delim2_lmb)
                    output_5
                  })
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


  interface Func_delim_pos_from_string_delim : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_delim_pos_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim
  }

  class Class_delim_pos_from_string_delim : vx_core.Class_base, Func_delim_pos_from_string_delim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_pos_from_string_delim = vx_data_textblock.Class_delim_pos_from_string_delim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delim_pos_from_string_delim = vx_data_textblock.Class_delim_pos_from_string_delim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim", // name
        0, // idx
        false, // async
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.e_delim_pos_from_string_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delim_pos_from_string_delim
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_delim_pos_from_string_delim(text, delim)
      return output
    }

    override fun vx_delim_pos_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim {
      var output : vx_data_textblock.Type_delim = vx_data_textblock.f_delim_pos_from_string_delim(text, delim)
      return output
    }

  }

  val e_delim_pos_from_string_delim : vx_data_textblock.Func_delim_pos_from_string_delim = vx_data_textblock.Class_delim_pos_from_string_delim()
  val t_delim_pos_from_string_delim : vx_data_textblock.Func_delim_pos_from_string_delim = vx_data_textblock.Class_delim_pos_from_string_delim()

  fun f_delim_pos_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_delim {
    var output : vx_data_textblock.Type_delim = vx_data_textblock.e_delim
    output = vx_core.f_let(
      vx_data_textblock.t_delim,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var find : vx_core.Type_string = delim.starttext()
        var pos : vx_core.Type_int = vx_type.f_int_from_string_findkeyword(
          text,
          find
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_delim,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  pos,
                  vx_core.vx_new_int(0)
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = delim
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_copy(
                  delim,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":pos"),
                    pos
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


  interface Func_delimlist_pos_from_string_delimlist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_delimlist_pos_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delimlist
  }

  class Class_delimlist_pos_from_string_delimlist : vx_core.Class_base, Func_delimlist_pos_from_string_delimlist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delimlist_pos_from_string_delimlist = vx_data_textblock.Class_delimlist_pos_from_string_delimlist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_delimlist_pos_from_string_delimlist = vx_data_textblock.Class_delimlist_pos_from_string_delimlist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_delim), // allowtypes
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
      var output : vx_core.Type_any = vx_data_textblock.e_delimlist_pos_from_string_delimlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_delimlist_pos_from_string_delimlist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delimlist : vx_data_textblock.Type_delimlist = vx_core.f_any_from_any(vx_data_textblock.t_delimlist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_delimlist_pos_from_string_delimlist(text, delimlist)
      return output
    }

    override fun vx_delimlist_pos_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delimlist {
      var output : vx_data_textblock.Type_delimlist = vx_data_textblock.f_delimlist_pos_from_string_delimlist(text, delimlist)
      return output
    }

  }

  val e_delimlist_pos_from_string_delimlist : vx_data_textblock.Func_delimlist_pos_from_string_delimlist = vx_data_textblock.Class_delimlist_pos_from_string_delimlist()
  val t_delimlist_pos_from_string_delimlist : vx_data_textblock.Func_delimlist_pos_from_string_delimlist = vx_data_textblock.Class_delimlist_pos_from_string_delimlist()

  fun f_delimlist_pos_from_string_delimlist(text : vx_core.Type_string, delimlist : vx_data_textblock.Type_delimlist) : vx_data_textblock.Type_delimlist {
    var output : vx_data_textblock.Type_delimlist = vx_data_textblock.e_delimlist
    output = vx_core.f_list_from_list_1(
      vx_data_textblock.t_delimlist,
      delimlist,
      vx_core.t_any_from_any.vx_fn_new({delim_any : vx_core.Type_any ->
        var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, delim_any)
        var output_1 : vx_core.Type_any = vx_data_textblock.f_delim_pos_from_string_delim(
          text,
          delim
        )
        output_1
      })
    )
    return output
  }


  interface Func_is_close : vx_core.Func_any_from_any {
    fun vx_is_close(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean
  }

  class Class_is_close : vx_core.Class_base, Func_is_close {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_is_close = vx_data_textblock.Class_is_close()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_is_close = vx_data_textblock.Class_is_close()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-close", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_is_close
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_is_close
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_delim = value as vx_data_textblock.Type_delim
      var outputval : vx_core.Type_any = vx_data_textblock.f_is_close(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var delimarg : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_is_close(delimarg)
      return output
    }

    override fun vx_is_close(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_textblock.f_is_close(delimarg)
      return output
    }

  }

  val e_is_close : vx_data_textblock.Func_is_close = vx_data_textblock.Class_is_close()
  val t_is_close : vx_data_textblock.Func_is_close = vx_data_textblock.Class_is_close()

  fun f_is_close(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_eq(
      delimarg.name(),
      vx_data_textblock.c_delimclose.name()
    )
    return output
  }


  interface Func_is_single : vx_core.Func_any_from_any {
    fun vx_is_single(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean
  }

  class Class_is_single : vx_core.Class_base, Func_is_single {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_is_single = vx_data_textblock.Class_is_single()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_is_single = vx_data_textblock.Class_is_single()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-single", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_is_single
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_is_single
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_delim = value as vx_data_textblock.Type_delim
      var outputval : vx_core.Type_any = vx_data_textblock.f_is_single(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var delimarg : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_is_single(delimarg)
      return output
    }

    override fun vx_is_single(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_textblock.f_is_single(delimarg)
      return output
    }

  }

  val e_is_single : vx_data_textblock.Func_is_single = vx_data_textblock.Class_is_single()
  val t_is_single : vx_data_textblock.Func_is_single = vx_data_textblock.Class_is_single()

  fun f_is_single(delimarg : vx_data_textblock.Type_delim) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_and(
      vx_core.f_ne(
        vx_core.vx_new_string(""),
        delimarg.starttext()
      ),
      vx_core.f_eq(
        vx_core.vx_new_string(""),
        delimarg.endtext()
      )
    )
    return output
  }


  interface Func_stringlist_from_textblocklist : vx_core.Func_any_from_any {
    fun vx_stringlist_from_textblocklist(textblocklist : vx_data_textblock.Type_textblocklist) : vx_core.Type_stringlist
  }

  class Class_stringlist_from_textblocklist : vx_core.Class_base, Func_stringlist_from_textblocklist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_stringlist_from_textblocklist = vx_data_textblock.Class_stringlist_from_textblocklist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_stringlist_from_textblocklist = vx_data_textblock.Class_stringlist_from_textblocklist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_stringlist_from_textblocklist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_stringlist_from_textblocklist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblocklist = value as vx_data_textblock.Type_textblocklist
      var outputval : vx_core.Type_any = vx_data_textblock.f_stringlist_from_textblocklist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblocklist : vx_data_textblock.Type_textblocklist = vx_core.f_any_from_any(vx_data_textblock.t_textblocklist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_stringlist_from_textblocklist(textblocklist)
      return output
    }

    override fun vx_stringlist_from_textblocklist(textblocklist : vx_data_textblock.Type_textblocklist) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_data_textblock.f_stringlist_from_textblocklist(textblocklist)
      return output
    }

  }

  val e_stringlist_from_textblocklist : vx_data_textblock.Func_stringlist_from_textblocklist = vx_data_textblock.Class_stringlist_from_textblocklist()
  val t_stringlist_from_textblocklist : vx_data_textblock.Func_stringlist_from_textblocklist = vx_data_textblock.Class_stringlist_from_textblocklist()

  fun f_stringlist_from_textblocklist(textblocklist : vx_data_textblock.Type_textblocklist) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_core.f_list_from_list_1(
      vx_core.t_stringlist,
      textblocklist,
      vx_data_textblock.t_text_from_textblock
    )
    return output
  }


  interface Func_text_from_textblock : vx_core.Func_any_from_any {
    fun vx_text_from_textblock(block : vx_data_textblock.Type_textblock) : vx_core.Type_string
  }

  class Class_text_from_textblock : vx_core.Class_base, Func_text_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_text_from_textblock = vx_data_textblock.Class_text_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_text_from_textblock = vx_data_textblock.Class_text_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_text_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_text_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_text_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var block : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_text_from_textblock(block)
      return output
    }

    override fun vx_text_from_textblock(block : vx_data_textblock.Type_textblock) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_textblock.f_text_from_textblock(block)
      return output
    }

  }

  val e_text_from_textblock : vx_data_textblock.Func_text_from_textblock = vx_data_textblock.Class_text_from_textblock()
  val t_text_from_textblock : vx_data_textblock.Func_text_from_textblock = vx_data_textblock.Class_text_from_textblock()

  fun f_text_from_textblock(block : vx_data_textblock.Type_textblock) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = block.text()
    return output
  }


  interface Func_textblock_addchild_from_textblock_find_child : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_addchild_from_textblock_find_child(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, child : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_addchild_from_textblock_find_child : vx_core.Class_base, Func_textblock_addchild_from_textblock_find_child {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_addchild_from_textblock_find_child = vx_data_textblock.Class_textblock_addchild_from_textblock_find_child()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_addchild_from_textblock_find_child = vx_data_textblock.Class_textblock_addchild_from_textblock_find_child()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-find-child", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_addchild_from_textblock_find_child
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_addchild_from_textblock_find_child
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      var child : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child)
      return output
    }

    override fun vx_textblock_addchild_from_textblock_find_child(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, child : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child)
      return output
    }

  }

  val e_textblock_addchild_from_textblock_find_child : vx_data_textblock.Func_textblock_addchild_from_textblock_find_child = vx_data_textblock.Class_textblock_addchild_from_textblock_find_child()
  val t_textblock_addchild_from_textblock_find_child : vx_data_textblock.Func_textblock_addchild_from_textblock_find_child = vx_data_textblock.Class_textblock_addchild_from_textblock_find_child()

  fun f_textblock_addchild_from_textblock_find_child(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, child : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_if_2(
      vx_data_textblock.t_textblock,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_is_empty_1(
              textblockarg
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_empty(
              vx_data_textblock.t_textblock
            )
            output_2
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_and_1(
              vx_core.vx_new(
                vx_core.t_booleanlist,
                vx_core.f_eqeq(
                  find,
                  textblockarg
                )
              )
            )
            output_3
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_core.f_copy(
              textblockarg,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":children"),
                vx_core.f_copy(
                  textblockarg.children(),
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    child
                  )
                )
              )
            )
            output_4
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_5 : vx_core.Type_any = vx_core.f_copy(
              textblockarg,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":parent"),
                vx_data_textblock.f_textblock_addchild_from_textblock_find_child(
                  textblockarg.parent(),
                  find,
                  child
                )
              )
            )
            output_5
          })
        )
      )
    )
    return output
  }


  interface Func_textblock_delimnotfound : vx_core.Func_any_from_any {
    fun vx_textblock_delimnotfound(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_delimnotfound : vx_core.Class_base, Func_textblock_delimnotfound {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_delimnotfound = vx_data_textblock.Class_textblock_delimnotfound()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_delimnotfound = vx_data_textblock.Class_textblock_delimnotfound()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-delimnotfound", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_delimnotfound
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_delimnotfound
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_textblock_delimnotfound(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_textblock_delimnotfound(textblockarg)
      return output
    }

    override fun vx_textblock_delimnotfound(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_delimnotfound(textblockarg)
      return output
    }

  }

  val e_textblock_delimnotfound : vx_data_textblock.Func_textblock_delimnotfound = vx_data_textblock.Class_textblock_delimnotfound()
  val t_textblock_delimnotfound : vx_data_textblock.Func_textblock_delimnotfound = vx_data_textblock.Class_textblock_delimnotfound()

  fun f_textblock_delimnotfound(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = textblockarg.text()
        var delima : vx_data_textblock.Type_delim = textblockarg.delim()
        var close : vx_data_textblock.Type_delim = textblockarg.close()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var childp : vx_data_textblock.Type_textblocklist = parent.children()
        var delimp : vx_data_textblock.Type_delim = parent.delim()
        var delims : vx_data_textblock.Type_delimlist = delimp.delimlist()
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_not(
                  vx_core.f_is_empty_1(
                    close
                  )
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_let(
                  vx_data_textblock.t_textblock,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var msgerr : vx_core.Type_msg = vx_core.f_msg_from_error_1(
                      vx_core.vx_new_string("closedelimmissing"),
                      close
                    )
                    var child : vx_data_textblock.Type_textblock = vx_core.f_copy(
                      textblockarg,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":delim"),
                        vx_core.f_empty(
                          vx_data_textblock.t_delim
                        ),
                        vx_core.vx_new_string(":close"),
                        vx_core.f_empty(
                          vx_data_textblock.t_delim
                        ),
                        vx_core.vx_new_string(":parent"),
                        vx_core.f_empty(
                          vx_data_textblock.t_textblock
                        )
                      )
                    )
                    var find : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_findparent_from_textblock(
                      parent
                    )
                    var childrenf : vx_data_textblock.Type_textblocklist = find.children()
                    var childrenr : vx_data_textblock.Type_textblocklist = vx_core.f_copy(
                      childrenf,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        child
                      )
                    )
                    var replace : vx_data_textblock.Type_textblock = vx_core.f_copy(
                      find,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        msgerr,
                        vx_core.vx_new_string(":children"),
                        childrenr
                      )
                    )
                    var parent2 : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
                      parent,
                      find,
                      replace
                    )
                    var gparent : vx_data_textblock.Type_textblock = parent2.parent()
                    var parent3 : vx_data_textblock.Type_textblock = vx_core.f_copy(
                      parent2,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":parent"),
                        vx_core.f_empty(
                          vx_data_textblock.t_textblock
                        )
                      )
                    )
                    var childreng : vx_data_textblock.Type_textblocklist = gparent.children()
                    var childrenc : vx_data_textblock.Type_textblocklist = vx_core.f_copy(
                      childreng,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        parent3
                      )
                    )
                    var output_4 : vx_core.Type_any = vx_core.f_copy(
                      gparent,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":children"),
                        childrenc,
                        msgerr
                      )
                    )
                    output_4
                  })
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_is_empty_1(
                  parent
                )
                output_5
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = textblockarg
                output_6
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_core.f_let(
                  vx_data_textblock.t_textblock,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var delimchg : vx_data_textblock.Type_delim = vx_core.f_if_1(
                      vx_data_textblock.t_delim,
                      vx_core.f_is_empty_1(
                        delima.delimlist()
                      ),
                      delima,
                      vx_core.f_copy(
                        delima,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":delimlist"),
                          vx_core.f_empty(
                            vx_data_textblock.t_delimlist
                          )
                        )
                      )
                    )
                    var child : vx_data_textblock.Type_textblock = vx_core.f_if_1(
                      vx_data_textblock.t_textblock,
                      vx_core.f_eq(
                        vx_core.vx_new_string(""),
                        text
                      ),
                      vx_core.f_empty(
                        vx_data_textblock.t_textblock
                      ),
                      vx_core.f_copy(
                        textblockarg,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":delim"),
                          delimchg,
                          vx_core.vx_new_string(":parent"),
                          vx_core.f_empty(
                            vx_data_textblock.t_textblock
                          )
                        )
                      )
                    )
                    var find : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_findparent_from_textblock(
                      parent
                    )
                    var closef : vx_data_textblock.Type_delim = find.close()
                    var closing : vx_core.Type_boolean = vx_core.f_if(
                      vx_core.t_boolean,
                      vx_core.f_eqeq(
                        closef,
                        vx_data_textblock.c_delimclosing
                      ),
                      vx_core.vx_new_boolean(true)
                    )
                    var output_8 : vx_core.Type_any = vx_core.f_if_2(
                      vx_data_textblock.t_textblock,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_9 : vx_core.Type_any = closing
                            output_9
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_10 : vx_core.Type_any = vx_core.f_let(
                              vx_data_textblock.t_textblock,
                              vx_core.t_any_from_func.vx_fn_new({ ->
                                var parent2 : vx_data_textblock.Type_textblock = find.parent()
                                var find2 : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_findparent_from_textblock(
                                  parent2
                                )
                                var children1 : vx_data_textblock.Type_textblocklist = vx_core.f_if_1(
                                  vx_data_textblock.t_textblocklist,
                                  vx_core.f_is_empty_1(
                                    child
                                  ),
                                  find.children(),
                                  vx_core.f_copy(
                                    find.children(),
                                    vx_core.vx_new(
                                      vx_core.t_anylist,
                                      child
                                    )
                                  )
                                )
                                var replace1 : vx_data_textblock.Type_textblock = vx_core.f_copy(
                                  find,
                                  vx_core.vx_new(
                                    vx_core.t_anylist,
                                    vx_core.vx_new_string(":close"),
                                    vx_core.f_empty(
                                      vx_data_textblock.t_delim
                                    ),
                                    vx_core.vx_new_string(":parent"),
                                    vx_core.f_empty(
                                      vx_data_textblock.t_textblock
                                    ),
                                    vx_core.vx_new_string(":children"),
                                    children1
                                  )
                                )
                                var output_11 : vx_core.Type_any = vx_core.f_if_2(
                                  vx_data_textblock.t_textblock,
                                  vx_core.vx_new(
                                    vx_core.t_thenelselist,
                                    vx_core.f_then(
                                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                                        var output_12 : vx_core.Type_any = vx_core.f_is_empty_1(
                                          find2
                                        )
                                        output_12
                                      }),
                                      vx_core.t_any_from_func.vx_fn_new({ ->
                                        var output_13 : vx_core.Type_any = vx_core.f_copy(
                                          parent,
                                          vx_core.vx_new(
                                            vx_core.t_anylist,
                                            vx_core.vx_new_string(":parent"),
                                            vx_core.f_copy(
                                              parent2,
                                              vx_core.vx_new(
                                                vx_core.t_anylist,
                                                vx_core.vx_new_string(":children"),
                                                vx_core.f_new(
                                                  vx_data_textblock.t_textblocklist,
                                                  vx_core.vx_new(
                                                    vx_core.t_anylist,
                                                    replace1
                                                  )
                                                )
                                              )
                                            )
                                          )
                                        )
                                        output_13
                                      })
                                    ),
                                    vx_core.f_else(
                                      vx_core.t_any_from_func.vx_fn_new({ ->
                                        var output_14 : vx_core.Type_any = vx_core.f_let(
                                          vx_data_textblock.t_textblock,
                                          vx_core.t_any_from_func.vx_fn_new({ ->
                                            var children2 : vx_data_textblock.Type_textblocklist = vx_core.f_copy(
                                              find2.children(),
                                              vx_core.vx_new(
                                                vx_core.t_anylist,
                                                replace1
                                              )
                                            )
                                            var replace2 : vx_data_textblock.Type_textblock = vx_core.f_copy(
                                              find2,
                                              vx_core.vx_new(
                                                vx_core.t_anylist,
                                                vx_core.vx_new_string(":close"),
                                                vx_core.f_empty(
                                                  vx_data_textblock.t_delim
                                                ),
                                                vx_core.vx_new_string(":children"),
                                                children2
                                              )
                                            )
                                            var replace : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
                                              parent2,
                                              find2,
                                              replace2
                                            )
                                            var output_15 : vx_core.Type_any = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
                                              parent,
                                              find,
                                              replace
                                            )
                                            output_15
                                          })
                                        )
                                        output_14
                                      })
                                    )
                                  )
                                )
                                output_11
                              })
                            )
                            output_10
                          })
                        ),
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_16 : vx_core.Type_any = vx_core.f_is_empty_1(
                              child
                            )
                            output_16
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_17 : vx_core.Type_any = parent
                            output_17
                          })
                        ),
                        vx_core.f_else(
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_18 : vx_core.Type_any = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(
                              parent,
                              find,
                              child
                            )
                            output_18
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
        output_1
      })
    )
    return output
  }


  interface Func_textblock_findparent_from_textblock : vx_core.Func_any_from_any {
    fun vx_textblock_findparent_from_textblock(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_findparent_from_textblock : vx_core.Class_base, Func_textblock_findparent_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_findparent_from_textblock = vx_data_textblock.Class_textblock_findparent_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_findparent_from_textblock = vx_data_textblock.Class_textblock_findparent_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-findparent<-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_findparent_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_findparent_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_textblock_findparent_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_textblock_findparent_from_textblock(textblockarg)
      return output
    }

    override fun vx_textblock_findparent_from_textblock(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_findparent_from_textblock(textblockarg)
      return output
    }

  }

  val e_textblock_findparent_from_textblock : vx_data_textblock.Func_textblock_findparent_from_textblock = vx_data_textblock.Class_textblock_findparent_from_textblock()
  val t_textblock_findparent_from_textblock : vx_data_textblock.Func_textblock_findparent_from_textblock = vx_data_textblock.Class_textblock_findparent_from_textblock()

  fun f_textblock_findparent_from_textblock(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var delimcurr : vx_data_textblock.Type_delim = textblockarg.delim()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var children : vx_data_textblock.Type_textblocklist = textblockarg.children()
        var starttext : vx_core.Type_string = delimcurr.starttext()
        var endtext : vx_core.Type_string = delimcurr.endtext()
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_is_empty_1(
                  textblockarg
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_or(
                  vx_core.f_is_empty_1(
                    parent
                  ),
                  vx_core.f_and(
                    vx_core.f_ne(
                      vx_core.vx_new_string(""),
                      starttext
                    ),
                    vx_core.f_ne(
                      vx_core.vx_new_string(""),
                      endtext
                    )
                  )
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = textblockarg
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_data_textblock.f_textblock_findparent_from_textblock(
                  parent
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


  interface Func_textblock_init : vx_core.Func_any_from_any {
    fun vx_textblock_init(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_init : vx_core.Class_base, Func_textblock_init {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_init = vx_data_textblock.Class_textblock_init()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_init = vx_data_textblock.Class_textblock_init()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-init", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_init
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_init
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_textblock_init(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_textblock_init(textblockarg)
      return output
    }

    override fun vx_textblock_init(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_init(textblockarg)
      return output
    }

  }

  val e_textblock_init : vx_data_textblock.Func_textblock_init = vx_data_textblock.Class_textblock_init()
  val t_textblock_init : vx_data_textblock.Func_textblock_init = vx_data_textblock.Class_textblock_init()

  fun f_textblock_init(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = textblockarg.text()
        var startpos : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            vx_core.vx_new_string(""),
            text
          ),
          vx_core.vx_new_int(0),
          vx_core.vx_new_int(1)
        )
        var endpos : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            vx_core.vx_new_string(""),
            text
          ),
          vx_core.vx_new_int(0),
          vx_core.f_length(
            text
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_copy(
          textblockarg,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":startpos"),
            startpos,
            vx_core.vx_new_string(":endpos"),
            endpos,
            vx_core.vx_new_string(":parent"),
            vx_core.f_copy(
              textblockarg,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":startpos"),
                startpos,
                vx_core.vx_new_string(":endpos"),
                endpos,
                vx_core.vx_new_string(":delim"),
                vx_core.f_empty(
                  vx_data_textblock.t_delim
                )
              )
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_parse : vx_core.Func_any_from_any {
    fun vx_textblock_parse(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_parse : vx_core.Class_base, Func_textblock_parse {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse = vx_data_textblock.Class_textblock_parse()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse = vx_data_textblock.Class_textblock_parse()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_parse
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_parse
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_textblock_parse(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_textblock_parse(textblock)
      return output
    }

    override fun vx_textblock_parse(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_parse(textblock)
      return output
    }

  }

  val e_textblock_parse : vx_data_textblock.Func_textblock_parse = vx_data_textblock.Class_textblock_parse()
  val t_textblock_parse : vx_data_textblock.Func_textblock_parse = vx_data_textblock.Class_textblock_parse()

  fun f_textblock_parse(textblock : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_collection.f_any_from_for_until_loop_max(
      vx_data_textblock.t_textblock,
      textblock,
      vx_core.t_boolean_from_any.vx_fn_new({current_any : vx_core.Type_any ->
        var current : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, current_any)
        var output_1 : vx_core.Type_any = vx_core.f_is_empty_1(
          current.parent()
        )
        output_1
      }),
      vx_core.t_any_from_any.vx_fn_new({current_any : vx_core.Type_any ->
        var current : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, current_any)
        var output_2 : vx_core.Type_any = vx_data_textblock.f_textblock_parse_one(
          current
        )
        output_2
      }),
      vx_core.vx_new_int(100000)
    )
    return output
  }


  interface Func_textblock_parse_one : vx_core.Func_any_from_any {
    fun vx_textblock_parse_one(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_parse_one : vx_core.Class_base, Func_textblock_parse_one {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse_one = vx_data_textblock.Class_textblock_parse_one()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse_one = vx_data_textblock.Class_textblock_parse_one()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse-one", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_parse_one
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_parse_one
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_textblock.f_textblock_parse_one(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_textblock.f_textblock_parse_one(textblockarg)
      return output
    }

    override fun vx_textblock_parse_one(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_parse_one(textblockarg)
      return output
    }

  }

  val e_textblock_parse_one : vx_data_textblock.Func_textblock_parse_one = vx_data_textblock.Class_textblock_parse_one()
  val t_textblock_parse_one : vx_data_textblock.Func_textblock_parse_one = vx_data_textblock.Class_textblock_parse_one()

  fun f_textblock_parse_one(textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var delimarg : vx_data_textblock.Type_delim = textblockarg.delim()
        var close : vx_data_textblock.Type_delim = textblockarg.close()
        var startpos : vx_core.Type_int = textblockarg.startpos()
        var textarg : vx_core.Type_string = textblockarg.text()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var is_init : vx_core.Type_boolean = vx_core.f_and(
          vx_core.f_is_empty_1(
            parent
          ),
          vx_core.f_eq(
            startpos,
            vx_core.vx_new_int(0)
          )
        )
        var starttext : vx_core.Type_string = delimarg.starttext()
        var endtext : vx_core.Type_string = delimarg.endtext()
        var delimlistarg : vx_data_textblock.Type_delimlist = delimarg.delimlist()
        var startposchg : vx_core.Type_int = vx_core.f_if_2(
          vx_core.t_int,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_13 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_string(""),
                  textarg
                )
                output_13
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_14 : vx_core.Type_any = startpos
                output_14
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_15 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_int(0),
                  startpos
                )
                output_15
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_16 : vx_core.Type_any = vx_core.vx_new_int(1)
                output_16
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_17 : vx_core.Type_any = startpos
                output_17
              })
            )
          )
        )
        var delimlistcl : vx_data_textblock.Type_delimlist = vx_core.f_if_1(
          vx_data_textblock.t_delimlist,
          vx_core.f_is_empty_1(
            close
          ),
          delimlistarg,
          vx_core.f_copy(
            delimlistarg,
            vx_core.vx_new(
              vx_core.t_anylist,
              close
            )
          )
        )
        var delimfirst : vx_data_textblock.Type_delim = vx_data_textblock.f_delim_first_from_string_delimlist(
          textarg,
          delimlistcl
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = is_init
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_data_textblock.f_textblock_init(
                  textblockarg
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_is_empty_1(
                  parent
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = textblockarg
                output_5
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_is_empty_1(
                  delimfirst
                )
                output_6
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_data_textblock.f_textblock_delimnotfound(
                  textblockarg
                )
                output_7
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_8 : vx_core.Type_any = vx_data_textblock.f_is_close(
                  delimfirst
                )
                output_8
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = vx_data_textblock.f_textblock_from_close_textblock(
                  delimfirst,
                  textblockarg
                )
                output_9
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = vx_data_textblock.f_is_single(
                  delimfirst
                )
                output_10
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_11 : vx_core.Type_any = vx_data_textblock.f_textblock_from_single_textblock(
                  delimfirst,
                  textblockarg
                )
                output_11
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_12 : vx_core.Type_any = vx_data_textblock.f_textblock_from_open_textblock(
                  delimfirst,
                  textblockarg
                )
                output_12
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_parse_from_string_delim : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_parse_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_parse_from_string_delim : vx_core.Class_base, Func_textblock_parse_from_string_delim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse_from_string_delim = vx_data_textblock.Class_textblock_parse_from_string_delim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_parse_from_string_delim = vx_data_textblock.Class_textblock_parse_from_string_delim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse<-string-delim", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_parse_from_string_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_parse_from_string_delim
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_parse_from_string_delim(text, delim)
      return output
    }

    override fun vx_textblock_parse_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_parse_from_string_delim(text, delim)
      return output
    }

  }

  val e_textblock_parse_from_string_delim : vx_data_textblock.Func_textblock_parse_from_string_delim = vx_data_textblock.Class_textblock_parse_from_string_delim()
  val t_textblock_parse_from_string_delim : vx_data_textblock.Func_textblock_parse_from_string_delim = vx_data_textblock.Class_textblock_parse_from_string_delim()

  fun f_textblock_parse_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var textblockinit : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_string_delim(
          text,
          delim
        )
        var output_1 : vx_core.Type_any = vx_data_textblock.f_textblock_parse(
          textblockinit
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_replace_from_textblock_find_replace : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_replace_from_textblock_find_replace(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, replace : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_replace_from_textblock_find_replace : vx_core.Class_base, Func_textblock_replace_from_textblock_find_replace {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_replace_from_textblock_find_replace = vx_data_textblock.Class_textblock_replace_from_textblock_find_replace()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_replace_from_textblock_find_replace = vx_data_textblock.Class_textblock_replace_from_textblock_find_replace()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-replace<-textblock-find-replace", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_replace_from_textblock_find_replace
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_replace_from_textblock_find_replace
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      var replace : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace)
      return output
    }

    override fun vx_textblock_replace_from_textblock_find_replace(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, replace : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace)
      return output
    }

  }

  val e_textblock_replace_from_textblock_find_replace : vx_data_textblock.Func_textblock_replace_from_textblock_find_replace = vx_data_textblock.Class_textblock_replace_from_textblock_find_replace()
  val t_textblock_replace_from_textblock_find_replace : vx_data_textblock.Func_textblock_replace_from_textblock_find_replace = vx_data_textblock.Class_textblock_replace_from_textblock_find_replace()

  fun f_textblock_replace_from_textblock_find_replace(textblockarg : vx_data_textblock.Type_textblock, find : vx_data_textblock.Type_textblock, replace : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_if_2(
      vx_data_textblock.t_textblock,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_is_empty_1(
              textblockarg
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_empty(
              vx_data_textblock.t_textblock
            )
            output_2
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_and_1(
              vx_core.vx_new(
                vx_core.t_booleanlist,
                vx_core.f_eqeq(
                  find,
                  textblockarg
                )
              )
            )
            output_3
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = replace
            output_4
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_5 : vx_core.Type_any = vx_core.f_copy(
              textblockarg,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":parent"),
                vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
                  textblockarg.parent(),
                  find,
                  replace
                )
              )
            )
            output_5
          })
        )
      )
    )
    return output
  }


  interface Func_textblock_startleft_from_string_delim_offset : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_startleft_from_string_delim_offset(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_startleft_from_string_delim_offset : vx_core.Class_base, Func_textblock_startleft_from_string_delim_offset {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_startleft_from_string_delim_offset = vx_data_textblock.Class_textblock_startleft_from_string_delim_offset()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_startleft_from_string_delim_offset = vx_data_textblock.Class_textblock_startleft_from_string_delim_offset()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startleft<-string-delim-offset", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_startleft_from_string_delim_offset
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_startleft_from_string_delim_offset
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      var offset : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_data_textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset)
      return output
    }

    override fun vx_textblock_startleft_from_string_delim_offset(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset)
      return output
    }

  }

  val e_textblock_startleft_from_string_delim_offset : vx_data_textblock.Func_textblock_startleft_from_string_delim_offset = vx_data_textblock.Class_textblock_startleft_from_string_delim_offset()
  val t_textblock_startleft_from_string_delim_offset : vx_data_textblock.Func_textblock_startleft_from_string_delim_offset = vx_data_textblock.Class_textblock_startleft_from_string_delim_offset()

  fun f_textblock_startleft_from_string_delim_offset(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pos : vx_core.Type_int = delim.pos()
        var start : vx_core.Type_int = vx_core.vx_new_int(1)
        var end : vx_core.Type_int = vx_core.f_minus(
          pos,
          vx_core.vx_new_int(1)
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_string(""),
                  text
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_int(0),
                  pos
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_type.f_string_from_string_start_end(
                      text,
                      start,
                      end
                    ),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.f_plus(
                      offset,
                      start
                    ),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.f_plus(
                      offset,
                      end
                    ),
                    vx_core.vx_new_string(":curpos"),
                    vx_core.vx_new_int(0)
                  )
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


  interface Func_textblock_startright_from_string_delim_offset : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_startright_from_string_delim_offset(text : vx_core.Type_string, delimin : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_startright_from_string_delim_offset : vx_core.Class_base, Func_textblock_startright_from_string_delim_offset {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_startright_from_string_delim_offset = vx_data_textblock.Class_textblock_startright_from_string_delim_offset()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_startright_from_string_delim_offset = vx_data_textblock.Class_textblock_startright_from_string_delim_offset()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startright<-string-delim-offset", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_startright_from_string_delim_offset
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_startright_from_string_delim_offset
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delimin : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      var offset : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_data_textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset)
      return output
    }

    override fun vx_textblock_startright_from_string_delim_offset(text : vx_core.Type_string, delimin : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset)
      return output
    }

  }

  val e_textblock_startright_from_string_delim_offset : vx_data_textblock.Func_textblock_startright_from_string_delim_offset = vx_data_textblock.Class_textblock_startright_from_string_delim_offset()
  val t_textblock_startright_from_string_delim_offset : vx_data_textblock.Func_textblock_startright_from_string_delim_offset = vx_data_textblock.Class_textblock_startright_from_string_delim_offset()

  fun f_textblock_startright_from_string_delim_offset(text : vx_core.Type_string, delimin : vx_data_textblock.Type_delim, offset : vx_core.Type_int) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var startpos : vx_core.Type_int = delimin.pos()
        var starttext : vx_core.Type_string = delimin.starttext()
        var endtext : vx_core.Type_string = delimin.endtext()
        var delimlist : vx_data_textblock.Type_delimlist = delimin.delimlist()
        var close : vx_data_textblock.Type_delim = vx_core.f_if_2(
          vx_data_textblock.t_delim,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_core.f_eq(
                  endtext,
                  vx_core.vx_new_string("")
                )
                output_7
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_8 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_delim
                )
                output_8
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = vx_core.f_copy(
                  vx_data_textblock.c_delimclose,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":starttext"),
                    endtext
                  )
                )
                output_9
              })
            )
          )
        )
        var delimlen : vx_core.Type_int = vx_core.f_switch(
          vx_core.t_int,
          starttext,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(":nonwhitespace"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = vx_core.vx_new_int(0)
                output_10
              })
            ),
            vx_core.f_case_1(
              vx_core.vx_new_string(":whitespace"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_11 : vx_core.Type_any = vx_core.vx_new_int(0)
                output_11
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_12 : vx_core.Type_any = vx_core.f_length(
                  starttext
                )
                output_12
              })
            )
          )
        )
        var curpos : vx_core.Type_int = vx_core.vx_new_int(0)
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  text,
                  vx_core.vx_new_string("")
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_lt(
                  startpos,
                  vx_core.vx_new_int(0)
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_type.f_string_from_string_start(
                      text,
                      startpos
                    ),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.f_plus(
                      offset,
                      startpos
                    ),
                    vx_core.vx_new_string(":curpos"),
                    curpos,
                    vx_core.vx_new_string(":delim"),
                    delimin,
                    vx_core.vx_new_string(":close"),
                    close
                  )
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


  interface Func_textblock_from_close_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_close_textblock(close : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_close_textblock : vx_core.Class_base, Func_textblock_from_close_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_close_textblock = vx_data_textblock.Class_textblock_from_close_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_close_textblock = vx_data_textblock.Class_textblock_from_close_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-close-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_close_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_close_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var close : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_close_textblock(close, textblockarg)
      return output
    }

    override fun vx_textblock_from_close_textblock(close : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_close_textblock(close, textblockarg)
      return output
    }

  }

  val e_textblock_from_close_textblock : vx_data_textblock.Func_textblock_from_close_textblock = vx_data_textblock.Class_textblock_from_close_textblock()
  val t_textblock_from_close_textblock : vx_data_textblock.Func_textblock_from_close_textblock = vx_data_textblock.Class_textblock_from_close_textblock()

  fun f_textblock_from_close_textblock(close : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = textblockarg.text()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var startpos : vx_core.Type_int = textblockarg.startpos()
        var endpos : vx_core.Type_int = textblockarg.endpos()
        var pos : vx_core.Type_int = close.pos()
        var textclose : vx_core.Type_string = close.starttext()
        var lenclose : vx_core.Type_int = vx_core.f_length(
          textclose
        )
        var posminus : vx_core.Type_int = vx_core.f_minus1(
          pos
        )
        var startleft : vx_core.Type_int = startpos
        var startclose : vx_core.Type_int = vx_core.f_plus(
          startpos,
          posminus
        )
        var endclose : vx_core.Type_int = vx_core.f_switch(
          vx_core.t_int,
          textclose,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(":whitespace"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_type.f_int_from_string_findkeyword(
                  text,
                  vx_core.vx_new_string(":nonwhitespace")
                )
                output_2
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_plus(
                  vx_core.f_minus1(
                    startclose
                  ),
                  lenclose
                )
                output_3
              })
            )
          )
        )
        var endleft : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            vx_core.vx_new_int(1),
            pos
          ),
          startclose,
          vx_core.f_minus1(
            startclose
          )
        )
        var startright : vx_core.Type_int = vx_core.f_plus1(
          endclose
        )
        var endright : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_lt(
            endpos,
            startright
          ),
          startright,
          endpos
        )
        var textleft : vx_core.Type_string = vx_type.f_string_from_string_end(
          text,
          posminus
        )
        var textright : vx_core.Type_string = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(
            pos,
            lenclose
          )
        )
        var find : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_findparent_from_textblock(
          parent
        )
        var closefind : vx_data_textblock.Type_delim = find.close()
        var textfind : vx_core.Type_string = find.text()
        var startfind : vx_core.Type_int = find.startpos()
        var delimfind : vx_data_textblock.Type_delim = find.delim()
        var delimright : vx_data_textblock.Type_delim = vx_core.f_new(
          vx_data_textblock.t_delim,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":delimlist"),
            delimfind.delimlist()
          )
        )
        var lenfind : vx_core.Type_int = vx_core.f_minus(
          vx_core.f_plus1(
            endclose
          ),
          startfind
        )
        var textreplace : vx_core.Type_string = vx_type.f_string_from_string_end(
          textfind,
          lenfind
        )
        var replace : vx_data_textblock.Type_textblock = vx_core.f_copy(
          find,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            textreplace,
            vx_core.vx_new_string(":endpos"),
            endclose,
            vx_core.vx_new_string(":delim"),
            vx_core.f_copy(
              delimfind,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":delimlist"),
                vx_core.f_empty(
                  vx_data_textblock.t_delimlist
                )
              )
            ),
            vx_core.vx_new_string(":close"),
            vx_data_textblock.c_delimclosing
          )
        )
        var parentchg : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
          parent,
          find,
          replace
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            textleft,
            vx_core.vx_new_string(":startpos"),
            startleft,
            vx_core.vx_new_string(":endpos"),
            endleft,
            vx_core.vx_new_string(":parent"),
            vx_core.f_copy(
              textblockarg,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":text"),
                textright,
                vx_core.vx_new_string(":startpos"),
                startright,
                vx_core.vx_new_string(":endpos"),
                endright,
                vx_core.vx_new_string(":delim"),
                delimright,
                vx_core.vx_new_string(":close"),
                closefind,
                vx_core.vx_new_string(":parent"),
                parentchg
              )
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_from_empty_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_empty_textblock(empty : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_empty_textblock : vx_core.Class_base, Func_textblock_from_empty_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_empty_textblock = vx_data_textblock.Class_textblock_from_empty_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_empty_textblock = vx_data_textblock.Class_textblock_from_empty_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-empty-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_empty_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_empty_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var empty : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_empty_textblock(empty, textblockarg)
      return output
    }

    override fun vx_textblock_from_empty_textblock(empty : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_empty_textblock(empty, textblockarg)
      return output
    }

  }

  val e_textblock_from_empty_textblock : vx_data_textblock.Func_textblock_from_empty_textblock = vx_data_textblock.Class_textblock_from_empty_textblock()
  val t_textblock_from_empty_textblock : vx_data_textblock.Func_textblock_from_empty_textblock = vx_data_textblock.Class_textblock_from_empty_textblock()

  fun f_textblock_from_empty_textblock(empty : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    return output
  }


  interface Func_textblock_from_open_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_open_textblock(open : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_open_textblock : vx_core.Class_base, Func_textblock_from_open_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_open_textblock = vx_data_textblock.Class_textblock_from_open_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_open_textblock = vx_data_textblock.Class_textblock_from_open_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-open-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_open_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_open_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var open : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_open_textblock(open, textblockarg)
      return output
    }

    override fun vx_textblock_from_open_textblock(open : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_open_textblock(open, textblockarg)
      return output
    }

  }

  val e_textblock_from_open_textblock : vx_data_textblock.Func_textblock_from_open_textblock = vx_data_textblock.Class_textblock_from_open_textblock()
  val t_textblock_from_open_textblock : vx_data_textblock.Func_textblock_from_open_textblock = vx_data_textblock.Class_textblock_from_open_textblock()

  fun f_textblock_from_open_textblock(open : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = textblockarg.text()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var startpos : vx_core.Type_int = textblockarg.startpos()
        var endpos : vx_core.Type_int = textblockarg.endpos()
        var delima : vx_data_textblock.Type_delim = textblockarg.delim()
        var pos : vx_core.Type_int = open.pos()
        var textopen : vx_core.Type_string = open.starttext()
        var textclose : vx_core.Type_string = open.endtext()
        var delimlistl : vx_data_textblock.Type_delimlist = open.delimlist()
        var lenopen : vx_core.Type_int = vx_core.f_length(
          textopen
        )
        var posminus : vx_core.Type_int = vx_core.f_minus1(
          pos
        )
        var startleft : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            pos,
            vx_core.vx_new_int(1)
          ),
          vx_core.f_minus1(
            startpos
          ),
          startpos
        )
        var endleft : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            pos,
            vx_core.vx_new_int(1)
          ),
          vx_core.f_minus1(
            startpos
          ),
          vx_core.f_plus(
            vx_core.f_minus1(
              startleft
            ),
            posminus
          )
        )
        var startright : vx_core.Type_int = vx_core.f_plus_2(
          vx_core.vx_new(
            vx_core.t_intlist,
            startpos,
            posminus,
            lenopen
          )
        )
        var startopen : vx_core.Type_int = vx_core.f_plus(
          startpos,
          posminus
        )
        var textleft : vx_core.Type_string = vx_type.f_string_from_string_end(
          text,
          posminus
        )
        var textpar : vx_core.Type_string = vx_type.f_string_from_string_start(
          text,
          pos
        )
        var textright : vx_core.Type_string = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(
            pos,
            lenopen
          )
        )
        var close : vx_data_textblock.Type_delim = vx_core.f_copy(
          vx_data_textblock.c_delimclose,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":starttext"),
            textclose
          )
        )
        var tbleft : vx_data_textblock.Type_textblock = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_string(""),
                  textleft
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    textleft,
                    vx_core.vx_new_string(":startpos"),
                    startleft,
                    vx_core.vx_new_string(":endpos"),
                    endleft
                  )
                )
                output_4
              })
            )
          )
        )
        var tbpar1 : vx_data_textblock.Type_textblock = vx_core.f_copy(
          textblockarg,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            textpar,
            vx_core.vx_new_string(":startpos"),
            startopen,
            vx_core.vx_new_string(":delim"),
            vx_core.f_copy(
              open,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":pos"),
                vx_core.vx_new_int(0),
                vx_core.vx_new_string(":delimlist"),
                delima.delimlist()
              )
            ),
            vx_core.vx_new_string(":parent"),
            parent
          )
        )
        var tbfind : vx_data_textblock.Type_textblock = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_string(""),
                  textleft
                )
                output_5
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_empty(
                  vx_data_textblock.t_textblock
                )
                output_6
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_data_textblock.f_textblock_findparent_from_textblock(
                  parent
                )
                output_7
              })
            )
          )
        )
        var tbparent : vx_data_textblock.Type_textblock = vx_core.f_if_2(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_8 : vx_core.Type_any = vx_core.f_is_empty_1(
                  tbfind
                )
                output_8
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = tbpar1
                output_9
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(
                  tbpar1,
                  tbfind,
                  tbleft
                )
                output_10
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            textright,
            vx_core.vx_new_string(":startpos"),
            startright,
            vx_core.vx_new_string(":endpos"),
            endpos,
            vx_core.vx_new_string(":delim"),
            vx_core.f_new(
              vx_data_textblock.t_delim,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            vx_core.vx_new_string(":close"),
            close,
            vx_core.vx_new_string(":parent"),
            tbparent
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_from_single_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_single_textblock(single : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_single_textblock : vx_core.Class_base, Func_textblock_from_single_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_single_textblock = vx_data_textblock.Class_textblock_from_single_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_single_textblock = vx_data_textblock.Class_textblock_from_single_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-single-textblock", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_single_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_single_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var single : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblockarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_single_textblock(single, textblockarg)
      return output
    }

    override fun vx_textblock_from_single_textblock(single : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_single_textblock(single, textblockarg)
      return output
    }

  }

  val e_textblock_from_single_textblock : vx_data_textblock.Func_textblock_from_single_textblock = vx_data_textblock.Class_textblock_from_single_textblock()
  val t_textblock_from_single_textblock : vx_data_textblock.Func_textblock_from_single_textblock = vx_data_textblock.Class_textblock_from_single_textblock()

  fun f_textblock_from_single_textblock(single : vx_data_textblock.Type_delim, textblockarg : vx_data_textblock.Type_textblock) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = textblockarg.text()
        var parent : vx_data_textblock.Type_textblock = textblockarg.parent()
        var startpos : vx_core.Type_int = textblockarg.startpos()
        var endpos : vx_core.Type_int = textblockarg.endpos()
        var pos : vx_core.Type_int = single.pos()
        var origsingle : vx_core.Type_string = single.starttext()
        var textsingle : vx_core.Type_string = vx_core.f_switch(
          vx_core.t_string,
          origsingle,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(":whitespace"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_let(
                  vx_core.t_string,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var text2 : vx_core.Type_string = vx_type.f_string_from_string_start(
                      text,
                      pos
                    )
                    var pos2 : vx_core.Type_int = vx_type.f_int_from_string_findkeyword(
                      text2,
                      vx_core.vx_new_string(":nonwhitespace")
                    )
                    var pos3 : vx_core.Type_int = vx_core.f_if_2(
                      vx_core.t_int,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_4 : vx_core.Type_any = vx_core.f_eq(
                              vx_core.vx_new_int(0),
                              pos2
                            )
                            output_4
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_5 : vx_core.Type_any = vx_core.f_length(
                              text2
                            )
                            output_5
                          })
                        ),
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_6 : vx_core.Type_any = vx_core.f_eq(
                              pos2,
                              pos
                            )
                            output_6
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_7 : vx_core.Type_any = pos2
                            output_7
                          })
                        ),
                        vx_core.f_else(
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_8 : vx_core.Type_any = vx_core.f_minus1(
                              pos2
                            )
                            output_8
                          })
                        )
                      )
                    )
                    var output_3 : vx_core.Type_any = vx_type.f_string_from_string_start_end(
                      text,
                      pos,
                      pos3
                    )
                    output_3
                  })
                )
                output_2
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = origsingle
                output_9
              })
            )
          )
        )
        var delimlistl : vx_data_textblock.Type_delimlist = single.delimlist()
        var lensingle : vx_core.Type_int = vx_core.f_length(
          textsingle
        )
        var posminus : vx_core.Type_int = vx_core.f_minus1(
          pos
        )
        var startleft : vx_core.Type_int = startpos
        var startsingle : vx_core.Type_int = vx_core.f_plus(
          startpos,
          posminus
        )
        var endsingle : vx_core.Type_int = vx_core.f_switch(
          vx_core.t_int,
          textsingle,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(":whitespace"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = vx_type.f_int_from_string_findkeyword(
                  text,
                  vx_core.vx_new_string(":nonwhitespace")
                )
                output_10
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_11 : vx_core.Type_any = vx_core.f_plus(
                  vx_core.f_minus1(
                    startsingle
                  ),
                  lensingle
                )
                output_11
              })
            )
          )
        )
        var endleft : vx_core.Type_int = vx_core.f_if_1(
          vx_core.t_int,
          vx_core.f_eq(
            startsingle,
            startpos
          ),
          startsingle,
          vx_core.f_minus1(
            startsingle
          )
        )
        var startright : vx_core.Type_int = vx_core.f_plus1(
          endsingle
        )
        var textleft : vx_core.Type_string = vx_type.f_string_from_string_end(
          text,
          posminus
        )
        var textpar : vx_core.Type_string = vx_type.f_string_from_string_start(
          text,
          pos
        )
        var textright : vx_core.Type_string = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(
            pos,
            lensingle
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            textleft,
            vx_core.vx_new_string(":startpos"),
            startleft,
            vx_core.vx_new_string(":endpos"),
            endleft,
            vx_core.vx_new_string(":delim"),
            vx_core.f_new(
              vx_data_textblock.t_delim,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            vx_core.vx_new_string(":parent"),
            vx_core.f_new(
              vx_data_textblock.t_textblock,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":text"),
                textsingle,
                vx_core.vx_new_string(":startpos"),
                startsingle,
                vx_core.vx_new_string(":endpos"),
                endsingle,
                vx_core.vx_new_string(":delim"),
                vx_core.f_copy(
                  single,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":pos"),
                    vx_core.vx_new_int(0),
                    vx_core.vx_new_string(":delimlist"),
                    vx_core.f_empty(
                      vx_data_textblock.t_delimlist
                    )
                  )
                ),
                vx_core.vx_new_string(":parent"),
                vx_core.f_copy(
                  textblockarg,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    textright,
                    vx_core.vx_new_string(":startpos"),
                    startright,
                    vx_core.vx_new_string(":endpos"),
                    endpos
                  )
                )
              )
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_from_string_delim : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_string_delim : vx_core.Class_base, Func_textblock_from_string_delim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_string_delim = vx_data_textblock.Class_textblock_from_string_delim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_string_delim = vx_data_textblock.Class_textblock_from_string_delim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-string-delim", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_string_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_string_delim
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_string_delim(text, delim)
      return output
    }

    override fun vx_textblock_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_string_delim(text, delim)
      return output
    }

  }

  val e_textblock_from_string_delim : vx_data_textblock.Func_textblock_from_string_delim = vx_data_textblock.Class_textblock_from_string_delim()
  val t_textblock_from_string_delim : vx_data_textblock.Func_textblock_from_string_delim = vx_data_textblock.Class_textblock_from_string_delim()

  fun f_textblock_from_string_delim(text : vx_core.Type_string, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_new(
      vx_data_textblock.t_textblock,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":text"),
        text,
        vx_core.vx_new_string(":delim"),
        delim,
        vx_core.vx_new_string(":startpos"),
        vx_core.vx_new_int(0),
        vx_core.vx_new_string(":endpos"),
        vx_core.f_length(
          text
        )
      )
    )
    return output
  }


  interface Func_textblock_from_textblock_delim : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblock_from_textblock_delim(textblock : vx_data_textblock.Type_textblock, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_textblock_delim : vx_core.Class_base, Func_textblock_from_textblock_delim {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_textblock_delim = vx_data_textblock.Class_textblock_from_textblock_delim()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblock_from_textblock_delim = vx_data_textblock.Class_textblock_from_textblock_delim()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-textblock-delim", // name
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblock_from_textblock_delim
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblock_from_textblock_delim
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      var delim : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblock_from_textblock_delim(textblock, delim)
      return output
    }

    override fun vx_textblock_from_textblock_delim(textblock : vx_data_textblock.Type_textblock, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_textblock_delim(textblock, delim)
      return output
    }

  }

  val e_textblock_from_textblock_delim : vx_data_textblock.Func_textblock_from_textblock_delim = vx_data_textblock.Class_textblock_from_textblock_delim()
  val t_textblock_from_textblock_delim : vx_data_textblock.Func_textblock_from_textblock_delim = vx_data_textblock.Class_textblock_from_textblock_delim()

  fun f_textblock_from_textblock_delim(textblock : vx_data_textblock.Type_textblock, delim : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    return output
  }


  interface Func_textblocklist_from_textblocklist_remove : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_textblocklist_from_textblocklist_remove(tblist : vx_data_textblock.Type_textblocklist, remove : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblocklist
  }

  class Class_textblocklist_from_textblocklist_remove : vx_core.Class_base, Func_textblocklist_from_textblocklist_remove {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblocklist_from_textblocklist_remove = vx_data_textblock.Class_textblocklist_from_textblocklist_remove()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_textblock.Class_textblocklist_from_textblocklist_remove = vx_data_textblock.Class_textblocklist_from_textblocklist_remove()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_data_textblock.t_textblock), // allowtypes
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
      var output : vx_core.Type_any = vx_data_textblock.e_textblocklist_from_textblocklist_remove
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_textblock.t_textblocklist_from_textblocklist_remove
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var tblist : vx_data_textblock.Type_textblocklist = vx_core.f_any_from_any(vx_data_textblock.t_textblocklist, arglist.vx_any(vx_core.vx_new_int(0)))
      var remove : vx_data_textblock.Type_delim = vx_core.f_any_from_any(vx_data_textblock.t_delim, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_textblock.f_textblocklist_from_textblocklist_remove(tblist, remove)
      return output
    }

    override fun vx_textblocklist_from_textblocklist_remove(tblist : vx_data_textblock.Type_textblocklist, remove : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblocklist {
      var output : vx_data_textblock.Type_textblocklist = vx_data_textblock.f_textblocklist_from_textblocklist_remove(tblist, remove)
      return output
    }

  }

  val e_textblocklist_from_textblocklist_remove : vx_data_textblock.Func_textblocklist_from_textblocklist_remove = vx_data_textblock.Class_textblocklist_from_textblocklist_remove()
  val t_textblocklist_from_textblocklist_remove : vx_data_textblock.Func_textblocklist_from_textblocklist_remove = vx_data_textblock.Class_textblocklist_from_textblocklist_remove()

  fun f_textblocklist_from_textblocklist_remove(tblist : vx_data_textblock.Type_textblocklist, remove : vx_data_textblock.Type_delim) : vx_data_textblock.Type_textblocklist {
    var output : vx_data_textblock.Type_textblocklist = vx_data_textblock.e_textblocklist
    output = vx_collection.f_list_from_list_filter(
      vx_data_textblock.t_textblocklist,
      tblist,
      vx_core.t_any_from_any.vx_fn_new({textblock_any : vx_core.Type_any ->
        var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, textblock_any)
        var output_1 : vx_core.Type_any = vx_core.f_let(
          vx_data_textblock.t_textblock,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var delimcurr : vx_data_textblock.Type_delim = textblock.delim()
            var namecurr : vx_core.Type_string = delimcurr.name()
            var nameremove : vx_core.Type_string = remove.name()
            var output_2 : vx_core.Type_any = vx_core.f_if(
              vx_data_textblock.t_textblock,
              vx_core.f_ne(
                namecurr,
                nameremove
              ),
              textblock
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  init {
    Const_delimbracketangle.const_new(c_delimbracketangle)
    Const_delimbracketcurly.const_new(c_delimbracketcurly)
    Const_delimbracketsquare.const_new(c_delimbracketsquare)
    Const_delimclose.const_new(c_delimclose)
    Const_delimclosing.const_new(c_delimclosing)
    Const_delimcomma.const_new(c_delimcomma)
    Const_delimcomment.const_new(c_delimcomment)
    Const_delimcommentblock.const_new(c_delimcommentblock)
    Const_delimline.const_new(c_delimline)
    Const_delimlisttest1.const_new(c_delimlisttest1)
    Const_delimlisttest2.const_new(c_delimlisttest2)
    Const_delimlisttest3.const_new(c_delimlisttest3)
    Const_delimnonwhitespace.const_new(c_delimnonwhitespace)
    Const_delimparen.const_new(c_delimparen)
    Const_delimquote.const_new(c_delimquote)
    Const_delimquoteblock.const_new(c_delimquoteblock)
    Const_delimspace.const_new(c_delimspace)
    Const_delimtest1.const_new(c_delimtest1)
    Const_delimtest2.const_new(c_delimtest2)
    Const_delimtest3.const_new(c_delimtest3)
    Const_delimtext.const_new(c_delimtext)
    Const_delimwhitespace.const_new(c_delimwhitespace)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("delim", vx_data_textblock.t_delim)
    maptype.put("delimlist", vx_data_textblock.t_delimlist)
    maptype.put("textblock", vx_data_textblock.t_textblock)
    maptype.put("textblocklist", vx_data_textblock.t_textblocklist)
    mapconst.put("delimbracketangle", vx_data_textblock.c_delimbracketangle)
    mapconst.put("delimbracketcurly", vx_data_textblock.c_delimbracketcurly)
    mapconst.put("delimbracketsquare", vx_data_textblock.c_delimbracketsquare)
    mapconst.put("delimclose", vx_data_textblock.c_delimclose)
    mapconst.put("delimclosing", vx_data_textblock.c_delimclosing)
    mapconst.put("delimcomma", vx_data_textblock.c_delimcomma)
    mapconst.put("delimcomment", vx_data_textblock.c_delimcomment)
    mapconst.put("delimcommentblock", vx_data_textblock.c_delimcommentblock)
    mapconst.put("delimline", vx_data_textblock.c_delimline)
    mapconst.put("delimlisttest1", vx_data_textblock.c_delimlisttest1)
    mapconst.put("delimlisttest2", vx_data_textblock.c_delimlisttest2)
    mapconst.put("delimlisttest3", vx_data_textblock.c_delimlisttest3)
    mapconst.put("delimnonwhitespace", vx_data_textblock.c_delimnonwhitespace)
    mapconst.put("delimparen", vx_data_textblock.c_delimparen)
    mapconst.put("delimquote", vx_data_textblock.c_delimquote)
    mapconst.put("delimquoteblock", vx_data_textblock.c_delimquoteblock)
    mapconst.put("delimspace", vx_data_textblock.c_delimspace)
    mapconst.put("delimtest1", vx_data_textblock.c_delimtest1)
    mapconst.put("delimtest2", vx_data_textblock.c_delimtest2)
    mapconst.put("delimtest3", vx_data_textblock.c_delimtest3)
    mapconst.put("delimtext", vx_data_textblock.c_delimtext)
    mapconst.put("delimwhitespace", vx_data_textblock.c_delimwhitespace)
    mapfunc.put("children<-textblock", vx_data_textblock.t_children_from_textblock)
    mapfunc.put("delim-first<-delim-delim", vx_data_textblock.t_delim_first_from_delim_delim)
    mapfunc.put("delim-first<-string-delimlist", vx_data_textblock.t_delim_first_from_string_delimlist)
    mapfunc.put("delim-pos<-string-delim", vx_data_textblock.t_delim_pos_from_string_delim)
    mapfunc.put("delimlist-pos<-string-delimlist", vx_data_textblock.t_delimlist_pos_from_string_delimlist)
    mapfunc.put("is-close", vx_data_textblock.t_is_close)
    mapfunc.put("is-single", vx_data_textblock.t_is_single)
    mapfunc.put("stringlist<-textblocklist", vx_data_textblock.t_stringlist_from_textblocklist)
    mapfunc.put("text<-textblock", vx_data_textblock.t_text_from_textblock)
    mapfunc.put("textblock-addchild<-textblock-find-child", vx_data_textblock.t_textblock_addchild_from_textblock_find_child)
    mapfunc.put("textblock-delimnotfound", vx_data_textblock.t_textblock_delimnotfound)
    mapfunc.put("textblock-findparent<-textblock", vx_data_textblock.t_textblock_findparent_from_textblock)
    mapfunc.put("textblock-init", vx_data_textblock.t_textblock_init)
    mapfunc.put("textblock-parse", vx_data_textblock.t_textblock_parse)
    mapfunc.put("textblock-parse-one", vx_data_textblock.t_textblock_parse_one)
    mapfunc.put("textblock-parse<-string-delim", vx_data_textblock.t_textblock_parse_from_string_delim)
    mapfunc.put("textblock-replace<-textblock-find-replace", vx_data_textblock.t_textblock_replace_from_textblock_find_replace)
    mapfunc.put("textblock-startleft<-string-delim-offset", vx_data_textblock.t_textblock_startleft_from_string_delim_offset)
    mapfunc.put("textblock-startright<-string-delim-offset", vx_data_textblock.t_textblock_startright_from_string_delim_offset)
    mapfunc.put("textblock<-close-textblock", vx_data_textblock.t_textblock_from_close_textblock)
    mapfunc.put("textblock<-empty-textblock", vx_data_textblock.t_textblock_from_empty_textblock)
    mapfunc.put("textblock<-open-textblock", vx_data_textblock.t_textblock_from_open_textblock)
    mapfunc.put("textblock<-single-textblock", vx_data_textblock.t_textblock_from_single_textblock)
    mapfunc.put("textblock<-string-delim", vx_data_textblock.t_textblock_from_string_delim)
    mapfunc.put("textblock<-textblock-delim", vx_data_textblock.t_textblock_from_textblock_delim)
    mapfunc.put("textblocklist<-textblocklist-remove", vx_data_textblock.t_textblocklist_from_textblocklist_remove)
    vx_core.vx_global_package_set("vx/data/textblock", maptype, mapconst, mapfunc)
  }

}
