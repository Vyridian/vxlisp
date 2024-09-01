package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_table {


  interface Type_cell : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun value() : vx_core.Type_any
  }

  class Class_cell : vx_core.Class_base, Type_cell {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":value")) {
        output = this.value()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":value", this.value())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_cell = vx_core.vx_copy(vx_data_table.e_cell, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_cell = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_cell = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_value : vx_core.Type_any = value.value()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":value")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/cell", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_cell = vx_data_table.Class_cell()
        work.vx_p_id = vx_p_id
        work.vx_p_value = vx_p_value
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_cell
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_cell
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "cell", // name
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

  val e_cell : vx_data_table.Type_cell = vx_data_table.Class_cell()
  val t_cell : vx_data_table.Type_cell = vx_data_table.Class_cell()

  interface Type_celllist : vx_core.Type_list {
    fun vx_listcell() : List<vx_data_table.Type_cell>
    fun vx_cell(index : vx_core.Type_int) : vx_data_table.Type_cell
  }

  class Class_celllist : vx_core.Class_base, Type_celllist {
    constructor() {}

    var vx_p_list : List<vx_data_table.Type_cell> = vx_core.immutablelist(
      ArrayList<vx_data_table.Type_cell>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_cell(index : vx_core.Type_int) : vx_data_table.Type_cell {
      var output : vx_data_table.Type_cell = vx_data_table.e_cell
      var list : vx_data_table.Class_celllist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_table.Type_cell> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listcell() : List<vx_data_table.Type_cell> {
      var output : List<vx_data_table.Type_cell> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_table.Type_cell = this.vx_cell(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_celllist = vx_core.vx_copy(vx_data_table.e_celllist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_celllist = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_celllist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_table.Type_cell> = ArrayList<vx_data_table.Type_cell>(value.vx_listcell())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_table.Type_celllist) {
          var multi : vx_data_table.Type_celllist = valsub as vx_data_table.Type_celllist
          ischanged = true
          listval.addAll(multi.vx_listcell())
        } else if (valsub is vx_data_table.Type_cell) {
          var allowsub : vx_data_table.Type_cell = valsub as vx_data_table.Type_cell
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_table.Type_cell) {
          ischanged = true
          listval.add(valsub as vx_data_table.Type_cell)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_table.Type_cell) {
              var valitem : vx_data_table.Type_cell = item as vx_data_table.Type_cell
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_celllist = vx_data_table.Class_celllist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_celllist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_celllist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_cell), // allowtypes
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

  val e_celllist : vx_data_table.Type_celllist = vx_data_table.Class_celllist()
  val t_celllist : vx_data_table.Type_celllist = vx_data_table.Class_celllist()

  interface Type_cellmap : vx_core.Type_map {
    fun vx_mapcell() : Map<String, vx_data_table.Type_cell>
    fun vx_cell(key : vx_core.Type_string) : vx_data_table.Type_cell
  }

  class Class_cellmap : vx_core.Class_base, Type_cellmap {
    constructor() {}

    var vx_p_map : Map<String, vx_data_table.Type_cell> = vx_core.immutablemap(LinkedHashMap<String, vx_data_table.Type_cell>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_data_table.Type_cell) {
        var castval : vx_data_table.Type_cell = value as vx_data_table.Type_cell
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_data_table.Type_cell> = LinkedHashMap<String, vx_data_table.Type_cell>(this.vx_p_map)
        if (castval == vx_data_table.e_cell) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_cell(key : vx_core.Type_string) : vx_data_table.Type_cell {
      var output : vx_data_table.Type_cell = vx_data_table.e_cell
      var map : vx_data_table.Class_cellmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_data_table.Type_cell> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_data_table.e_cell)
      return output
    }

    override fun vx_mapcell() : Map<String, vx_data_table.Type_cell> {
      var output : Map<String, vx_data_table.Type_cell> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_cell(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_table.Class_cellmap = vx_data_table.Class_cellmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_data_table.Type_cell> = LinkedHashMap<String, vx_data_table.Type_cell>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_data_table.Type_cell) {
          var castval : vx_data_table.Type_cell = value as vx_data_table.Type_cell
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/table/cellmap", ":invalidvalue", value)
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
      var output : vx_data_table.Type_cellmap = vx_core.vx_copy(vx_data_table.e_cellmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_cellmap = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_cellmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_data_table.Type_cell> = LinkedHashMap<String, vx_data_table.Type_cell>(value.vx_mapcell())
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
            msg = vx_core.vx_msg_from_error("vx/data/table/cellmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_data_table.Type_cell = vx_data_table.e_cell
          if (false) {
          } else if (valsub is vx_data_table.Type_cell) {
            var valallowed : vx_data_table.Type_cell = valsub as vx_data_table.Type_cell
            valany = valallowed
          } else if (valsub is vx_data_table.Type_cell) {
            valany = valsub as vx_data_table.Type_cell
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
            msg = vx_core.vx_msg_from_error("vx/data/table/cellmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_table.Class_cellmap = vx_data_table.Class_cellmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_cellmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_cellmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_cell), // allowtypes
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

  val e_cellmap : vx_data_table.Type_cellmap = vx_data_table.Class_cellmap()
  val t_cellmap : vx_data_table.Type_cellmap = vx_data_table.Class_cellmap()

  interface Type_field : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun fldtype() : vx_core.Type_any
  }

  class Class_field : vx_core.Class_base, Type_field {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_name : vx_core.Type_string? = null

    override fun name() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_name
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fldtype : vx_core.Type_any? = null

    override fun fldtype() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_fldtype
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":fldtype")) {
        output = this.fldtype()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":fldtype", this.fldtype())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_field = vx_core.vx_copy(vx_data_table.e_field, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_field = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_field = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_fldtype : vx_core.Type_any = value.fldtype()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
      validkeys.add(":fldtype")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
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
              msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fldtype")) {
            if (valsub == vx_p_fldtype) {
            } else if (valsub is vx_core.Type_any) {
              var valfldtype : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_fldtype = valfldtype
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fldtype"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_field = vx_data_table.Class_field()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_fldtype = vx_p_fldtype
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_field
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_field
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "field", // name
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

  val e_field : vx_data_table.Type_field = vx_data_table.Class_field()
  val t_field : vx_data_table.Type_field = vx_data_table.Class_field()

  interface Type_fieldlist : vx_core.Type_list {
    fun vx_listfield() : List<vx_data_table.Type_field>
    fun vx_field(index : vx_core.Type_int) : vx_data_table.Type_field
  }

  class Class_fieldlist : vx_core.Class_base, Type_fieldlist {
    constructor() {}

    var vx_p_list : List<vx_data_table.Type_field> = vx_core.immutablelist(
      ArrayList<vx_data_table.Type_field>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_field(index : vx_core.Type_int) : vx_data_table.Type_field {
      var output : vx_data_table.Type_field = vx_data_table.e_field
      var list : vx_data_table.Class_fieldlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_table.Type_field> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listfield() : List<vx_data_table.Type_field> {
      var output : List<vx_data_table.Type_field> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_table.Type_field = this.vx_field(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_fieldlist = vx_core.vx_copy(vx_data_table.e_fieldlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_fieldlist = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_fieldlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_table.Type_field> = ArrayList<vx_data_table.Type_field>(value.vx_listfield())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_table.Type_fieldlist) {
          var multi : vx_data_table.Type_fieldlist = valsub as vx_data_table.Type_fieldlist
          ischanged = true
          listval.addAll(multi.vx_listfield())
        } else if (valsub is vx_data_table.Type_field) {
          var allowsub : vx_data_table.Type_field = valsub as vx_data_table.Type_field
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_table.Type_field) {
          ischanged = true
          listval.add(valsub as vx_data_table.Type_field)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_table.Type_field) {
              var valitem : vx_data_table.Type_field = item as vx_data_table.Type_field
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_fieldlist = vx_data_table.Class_fieldlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_fieldlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_fieldlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_field), // allowtypes
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

  val e_fieldlist : vx_data_table.Type_fieldlist = vx_data_table.Class_fieldlist()
  val t_fieldlist : vx_data_table.Type_fieldlist = vx_data_table.Class_fieldlist()

  interface Type_fieldmap : vx_core.Type_list {
    fun vx_listfield() : List<vx_data_table.Type_field>
    fun vx_field(index : vx_core.Type_int) : vx_data_table.Type_field
  }

  class Class_fieldmap : vx_core.Class_base, Type_fieldmap {
    constructor() {}

    var vx_p_list : List<vx_data_table.Type_field> = vx_core.immutablelist(
      ArrayList<vx_data_table.Type_field>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_field(index : vx_core.Type_int) : vx_data_table.Type_field {
      var output : vx_data_table.Type_field = vx_data_table.e_field
      var list : vx_data_table.Class_fieldmap = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_table.Type_field> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listfield() : List<vx_data_table.Type_field> {
      var output : List<vx_data_table.Type_field> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_table.Type_field = this.vx_field(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_fieldmap = vx_core.vx_copy(vx_data_table.e_fieldmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_fieldmap = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_fieldmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_table.Type_field> = ArrayList<vx_data_table.Type_field>(value.vx_listfield())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_table.Type_fieldmap) {
          var multi : vx_data_table.Type_fieldmap = valsub as vx_data_table.Type_fieldmap
          ischanged = true
          listval.addAll(multi.vx_listfield())
        } else if (valsub is vx_data_table.Type_field) {
          var allowsub : vx_data_table.Type_field = valsub as vx_data_table.Type_field
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_table.Type_field) {
          ischanged = true
          listval.add(valsub as vx_data_table.Type_field)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_table.Type_field) {
              var valitem : vx_data_table.Type_field = item as vx_data_table.Type_field
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_fieldmap = vx_data_table.Class_fieldmap()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_fieldmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_fieldmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_field), // allowtypes
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

  val e_fieldmap : vx_data_table.Type_fieldmap = vx_data_table.Class_fieldmap()
  val t_fieldmap : vx_data_table.Type_fieldmap = vx_data_table.Class_fieldmap()

  interface Type_filter : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun idlist() : vx_core.Type_stringlist
  }

  class Class_filter : vx_core.Class_base, Type_filter {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_name : vx_core.Type_string? = null

    override fun name() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_name
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_idlist : vx_core.Type_stringlist? = null

    override fun idlist() : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_core.e_stringlist
      var testnull : vx_core.Type_stringlist? = vx_p_idlist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":idlist")) {
        output = this.idlist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":idlist", this.idlist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_filter = vx_core.vx_copy(vx_data_table.e_filter, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_filter = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_filter = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_idlist : vx_core.Type_stringlist = value.idlist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
      validkeys.add(":idlist")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
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
              msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":idlist")) {
            if (valsub == vx_p_idlist) {
            } else if (valsub is vx_core.Type_stringlist) {
              var validlist : vx_core.Type_stringlist = valsub as vx_core.Type_stringlist
              ischanged = true
              vx_p_idlist = validlist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("idlist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_filter = vx_data_table.Class_filter()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_idlist = vx_p_idlist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_filter
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_filter
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "filter", // name
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

  val e_filter : vx_data_table.Type_filter = vx_data_table.Class_filter()
  val t_filter : vx_data_table.Type_filter = vx_data_table.Class_filter()

  interface Type_row : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun cellmap() : vx_data_table.Type_cellmap
    fun cellsort() : vx_data_table.Type_sort
  }

  class Class_row : vx_core.Class_base, Type_row {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_cellmap : vx_data_table.Type_cellmap? = null

    override fun cellmap() : vx_data_table.Type_cellmap {
      var output : vx_data_table.Type_cellmap = vx_data_table.e_cellmap
      var testnull : vx_data_table.Type_cellmap? = vx_p_cellmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_cellsort : vx_data_table.Type_sort? = null

    override fun cellsort() : vx_data_table.Type_sort {
      var output : vx_data_table.Type_sort = vx_data_table.e_sort
      var testnull : vx_data_table.Type_sort? = vx_p_cellsort
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":cellmap")) {
        output = this.cellmap()
      } else if ((skey==":cellsort")) {
        output = this.cellsort()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":cellmap", this.cellmap())
      map.put(":cellsort", this.cellsort())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_row = vx_core.vx_copy(vx_data_table.e_row, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_row = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_row = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_cellmap : vx_data_table.Type_cellmap = value.cellmap()
      var vx_p_cellsort : vx_data_table.Type_sort = value.cellsort()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":cellmap")
      validkeys.add(":cellsort")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":cellmap")) {
            if (valsub == vx_p_cellmap) {
            } else if (valsub is vx_data_table.Type_cellmap) {
              var valcellmap : vx_data_table.Type_cellmap = valsub as vx_data_table.Type_cellmap
              ischanged = true
              vx_p_cellmap = valcellmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("cellmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":cellsort")) {
            if (valsub == vx_p_cellsort) {
            } else if (valsub is vx_data_table.Type_sort) {
              var valcellsort : vx_data_table.Type_sort = valsub as vx_data_table.Type_sort
              ischanged = true
              vx_p_cellsort = valcellsort
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("cellsort"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_row = vx_data_table.Class_row()
        work.vx_p_id = vx_p_id
        work.vx_p_cellmap = vx_p_cellmap
        work.vx_p_cellsort = vx_p_cellsort
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_row
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_row
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "row", // name
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

  val e_row : vx_data_table.Type_row = vx_data_table.Class_row()
  val t_row : vx_data_table.Type_row = vx_data_table.Class_row()

  interface Type_rowlist : vx_core.Type_list {
    fun vx_listrow() : List<vx_data_table.Type_row>
    fun vx_row(index : vx_core.Type_int) : vx_data_table.Type_row
  }

  class Class_rowlist : vx_core.Class_base, Type_rowlist {
    constructor() {}

    var vx_p_list : List<vx_data_table.Type_row> = vx_core.immutablelist(
      ArrayList<vx_data_table.Type_row>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_row(index : vx_core.Type_int) : vx_data_table.Type_row {
      var output : vx_data_table.Type_row = vx_data_table.e_row
      var list : vx_data_table.Class_rowlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_table.Type_row> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listrow() : List<vx_data_table.Type_row> {
      var output : List<vx_data_table.Type_row> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_table.Type_row = this.vx_row(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_rowlist = vx_core.vx_copy(vx_data_table.e_rowlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_rowlist = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_rowlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_table.Type_row> = ArrayList<vx_data_table.Type_row>(value.vx_listrow())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_table.Type_rowlist) {
          var multi : vx_data_table.Type_rowlist = valsub as vx_data_table.Type_rowlist
          ischanged = true
          listval.addAll(multi.vx_listrow())
        } else if (valsub is vx_data_table.Type_row) {
          var allowsub : vx_data_table.Type_row = valsub as vx_data_table.Type_row
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_table.Type_row) {
          ischanged = true
          listval.add(valsub as vx_data_table.Type_row)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_table.Type_row) {
              var valitem : vx_data_table.Type_row = item as vx_data_table.Type_row
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_rowlist = vx_data_table.Class_rowlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_rowlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_rowlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_row), // allowtypes
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

  val e_rowlist : vx_data_table.Type_rowlist = vx_data_table.Class_rowlist()
  val t_rowlist : vx_data_table.Type_rowlist = vx_data_table.Class_rowlist()

  interface Type_rowmap : vx_core.Type_map {
    fun vx_maprow() : Map<String, vx_data_table.Type_row>
    fun vx_row(key : vx_core.Type_string) : vx_data_table.Type_row
  }

  class Class_rowmap : vx_core.Class_base, Type_rowmap {
    constructor() {}

    var vx_p_map : Map<String, vx_data_table.Type_row> = vx_core.immutablemap(LinkedHashMap<String, vx_data_table.Type_row>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_data_table.Type_row) {
        var castval : vx_data_table.Type_row = value as vx_data_table.Type_row
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_data_table.Type_row> = LinkedHashMap<String, vx_data_table.Type_row>(this.vx_p_map)
        if (castval == vx_data_table.e_row) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_row(key : vx_core.Type_string) : vx_data_table.Type_row {
      var output : vx_data_table.Type_row = vx_data_table.e_row
      var map : vx_data_table.Class_rowmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_data_table.Type_row> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_data_table.e_row)
      return output
    }

    override fun vx_maprow() : Map<String, vx_data_table.Type_row> {
      var output : Map<String, vx_data_table.Type_row> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_row(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_table.Class_rowmap = vx_data_table.Class_rowmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_data_table.Type_row> = LinkedHashMap<String, vx_data_table.Type_row>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_data_table.Type_row) {
          var castval : vx_data_table.Type_row = value as vx_data_table.Type_row
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/table/rowmap", ":invalidvalue", value)
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
      var output : vx_data_table.Type_rowmap = vx_core.vx_copy(vx_data_table.e_rowmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_rowmap = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_rowmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_data_table.Type_row> = LinkedHashMap<String, vx_data_table.Type_row>(value.vx_maprow())
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
            msg = vx_core.vx_msg_from_error("vx/data/table/rowmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_data_table.Type_row = vx_data_table.e_row
          if (false) {
          } else if (valsub is vx_data_table.Type_row) {
            var valallowed : vx_data_table.Type_row = valsub as vx_data_table.Type_row
            valany = valallowed
          } else if (valsub is vx_data_table.Type_row) {
            valany = valsub as vx_data_table.Type_row
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
            msg = vx_core.vx_msg_from_error("vx/data/table/rowmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_table.Class_rowmap = vx_data_table.Class_rowmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_rowmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_rowmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_table.t_row), // allowtypes
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

  val e_rowmap : vx_data_table.Type_rowmap = vx_data_table.Class_rowmap()
  val t_rowmap : vx_data_table.Type_rowmap = vx_data_table.Class_rowmap()

  interface Type_sort : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun idlist() : vx_core.Type_stringlist
  }

  class Class_sort : vx_core.Class_base, Type_sort {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_name : vx_core.Type_string? = null

    override fun name() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_name
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_idlist : vx_core.Type_stringlist? = null

    override fun idlist() : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_core.e_stringlist
      var testnull : vx_core.Type_stringlist? = vx_p_idlist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":idlist")) {
        output = this.idlist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":idlist", this.idlist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_sort = vx_core.vx_copy(vx_data_table.e_sort, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_sort = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_sort = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_idlist : vx_core.Type_stringlist = value.idlist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
      validkeys.add(":idlist")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
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
              msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":idlist")) {
            if (valsub == vx_p_idlist) {
            } else if (valsub is vx_core.Type_stringlist) {
              var validlist : vx_core.Type_stringlist = valsub as vx_core.Type_stringlist
              ischanged = true
              vx_p_idlist = validlist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("idlist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_sort = vx_data_table.Class_sort()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_idlist = vx_p_idlist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_sort
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_sort
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "sort", // name
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

  val e_sort : vx_data_table.Type_sort = vx_data_table.Class_sort()
  val t_sort : vx_data_table.Type_sort = vx_data_table.Class_sort()

  interface Type_table : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun fieldmap() : vx_data_table.Type_fieldmap
    fun fieldsort() : vx_data_table.Type_sort
    fun rowmap() : vx_data_table.Type_rowmap
    fun rowfilter() : vx_data_table.Type_filter
    fun rowsort() : vx_data_table.Type_sort
  }

  class Class_table : vx_core.Class_base, Type_table {
    constructor() {}

    var vx_p_id : vx_core.Type_string? = null

    override fun id() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_id
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_name : vx_core.Type_string? = null

    override fun name() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_name
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fieldmap : vx_data_table.Type_fieldmap? = null

    override fun fieldmap() : vx_data_table.Type_fieldmap {
      var output : vx_data_table.Type_fieldmap = vx_data_table.e_fieldmap
      var testnull : vx_data_table.Type_fieldmap? = vx_p_fieldmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fieldsort : vx_data_table.Type_sort? = null

    override fun fieldsort() : vx_data_table.Type_sort {
      var output : vx_data_table.Type_sort = vx_data_table.e_sort
      var testnull : vx_data_table.Type_sort? = vx_p_fieldsort
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_rowmap : vx_data_table.Type_rowmap? = null

    override fun rowmap() : vx_data_table.Type_rowmap {
      var output : vx_data_table.Type_rowmap = vx_data_table.e_rowmap
      var testnull : vx_data_table.Type_rowmap? = vx_p_rowmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_rowfilter : vx_data_table.Type_filter? = null

    override fun rowfilter() : vx_data_table.Type_filter {
      var output : vx_data_table.Type_filter = vx_data_table.e_filter
      var testnull : vx_data_table.Type_filter? = vx_p_rowfilter
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_rowsort : vx_data_table.Type_sort? = null

    override fun rowsort() : vx_data_table.Type_sort {
      var output : vx_data_table.Type_sort = vx_data_table.e_sort
      var testnull : vx_data_table.Type_sort? = vx_p_rowsort
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":fieldmap")) {
        output = this.fieldmap()
      } else if ((skey==":fieldsort")) {
        output = this.fieldsort()
      } else if ((skey==":rowmap")) {
        output = this.rowmap()
      } else if ((skey==":rowfilter")) {
        output = this.rowfilter()
      } else if ((skey==":rowsort")) {
        output = this.rowsort()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":fieldmap", this.fieldmap())
      map.put(":fieldsort", this.fieldsort())
      map.put(":rowmap", this.rowmap())
      map.put(":rowfilter", this.rowfilter())
      map.put(":rowsort", this.rowsort())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_table = vx_core.vx_copy(vx_data_table.e_table, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_table.Type_table = this
      var ischanged : Boolean = false
      var value : vx_data_table.Class_table = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_fieldmap : vx_data_table.Type_fieldmap = value.fieldmap()
      var vx_p_fieldsort : vx_data_table.Type_sort = value.fieldsort()
      var vx_p_rowmap : vx_data_table.Type_rowmap = value.rowmap()
      var vx_p_rowfilter : vx_data_table.Type_filter = value.rowfilter()
      var vx_p_rowsort : vx_data_table.Type_sort = value.rowsort()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
      validkeys.add(":fieldmap")
      validkeys.add(":fieldsort")
      validkeys.add(":rowmap")
      validkeys.add(":rowfilter")
      validkeys.add(":rowsort")
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
            msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is vx_core.Type_string) {
              var valid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_id = valid
            } else if (valsub is String) {
              ischanged = true
              vx_p_id = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("id"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
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
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fieldmap")) {
            if (valsub == vx_p_fieldmap) {
            } else if (valsub is vx_data_table.Type_fieldmap) {
              var valfieldmap : vx_data_table.Type_fieldmap = valsub as vx_data_table.Type_fieldmap
              ischanged = true
              vx_p_fieldmap = valfieldmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fieldmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fieldsort")) {
            if (valsub == vx_p_fieldsort) {
            } else if (valsub is vx_data_table.Type_sort) {
              var valfieldsort : vx_data_table.Type_sort = valsub as vx_data_table.Type_sort
              ischanged = true
              vx_p_fieldsort = valfieldsort
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fieldsort"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":rowmap")) {
            if (valsub == vx_p_rowmap) {
            } else if (valsub is vx_data_table.Type_rowmap) {
              var valrowmap : vx_data_table.Type_rowmap = valsub as vx_data_table.Type_rowmap
              ischanged = true
              vx_p_rowmap = valrowmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("rowmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":rowfilter")) {
            if (valsub == vx_p_rowfilter) {
            } else if (valsub is vx_data_table.Type_filter) {
              var valrowfilter : vx_data_table.Type_filter = valsub as vx_data_table.Type_filter
              ischanged = true
              vx_p_rowfilter = valrowfilter
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("rowfilter"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":rowsort")) {
            if (valsub == vx_p_rowsort) {
            } else if (valsub is vx_data_table.Type_sort) {
              var valrowsort : vx_data_table.Type_sort = valsub as vx_data_table.Type_sort
              ischanged = true
              vx_p_rowsort = valrowsort
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("rowsort"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_table.Class_table = vx_data_table.Class_table()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_fieldmap = vx_p_fieldmap
        work.vx_p_fieldsort = vx_p_fieldsort
        work.vx_p_rowmap = vx_p_rowmap
        work.vx_p_rowfilter = vx_p_rowfilter
        work.vx_p_rowsort = vx_p_rowsort
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.e_table
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_table.t_table
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/table", // pkgname
        "table", // name
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

  val e_table : vx_data_table.Type_table = vx_data_table.Class_table()
  val t_table : vx_data_table.Type_table = vx_data_table.Class_table()

  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("cell", vx_data_table.t_cell)
    maptype.put("celllist", vx_data_table.t_celllist)
    maptype.put("cellmap", vx_data_table.t_cellmap)
    maptype.put("field", vx_data_table.t_field)
    maptype.put("fieldlist", vx_data_table.t_fieldlist)
    maptype.put("fieldmap", vx_data_table.t_fieldmap)
    maptype.put("filter", vx_data_table.t_filter)
    maptype.put("row", vx_data_table.t_row)
    maptype.put("rowlist", vx_data_table.t_rowlist)
    maptype.put("rowmap", vx_data_table.t_rowmap)
    maptype.put("sort", vx_data_table.t_sort)
    maptype.put("table", vx_data_table.t_table)
    vx_core.vx_global_package_set("vx/data/table", maptype, mapconst, mapfunc)
  }

}
