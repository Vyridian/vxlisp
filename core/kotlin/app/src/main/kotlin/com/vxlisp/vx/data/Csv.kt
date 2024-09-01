package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_csv {


  interface Type_csv : vx_core.Type_struct {
    fun headers() : vx_core.Type_stringlist
    fun rows() : vx_data_csv.Type_csvrows
  }

  class Class_csv : vx_core.Class_base, Type_csv {
    constructor() {}

    var vx_p_headers : vx_core.Type_stringlist? = null

    override fun headers() : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_core.e_stringlist
      var testnull : vx_core.Type_stringlist? = vx_p_headers
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_rows : vx_data_csv.Type_csvrows? = null

    override fun rows() : vx_data_csv.Type_csvrows {
      var output : vx_data_csv.Type_csvrows = vx_data_csv.e_csvrows
      var testnull : vx_data_csv.Type_csvrows? = vx_p_rows
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":headers")) {
        output = this.headers()
      } else if ((skey==":rows")) {
        output = this.rows()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":headers", this.headers())
      map.put(":rows", this.rows())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_csv.Type_csv = vx_core.vx_copy(vx_data_csv.e_csv, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_csv.Type_csv = this
      var ischanged : Boolean = false
      var value : vx_data_csv.Class_csv = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_headers : vx_core.Type_stringlist = value.headers()
      var vx_p_rows : vx_data_csv.Type_csvrows = value.rows()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":headers")
      validkeys.add(":rows")
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
            msg = vx_core.vx_msg_from_error("vx/data/csv/csv", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":headers")) {
            if (valsub == vx_p_headers) {
            } else if (valsub is vx_core.Type_stringlist) {
              var valheaders : vx_core.Type_stringlist = valsub as vx_core.Type_stringlist
              ischanged = true
              vx_p_headers = valheaders
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("headers"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":rows")) {
            if (valsub == vx_p_rows) {
            } else if (valsub is vx_data_csv.Type_csvrows) {
              var valrows : vx_data_csv.Type_csvrows = valsub as vx_data_csv.Type_csvrows
              ischanged = true
              vx_p_rows = valrows
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("rows"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_csv.Class_csv = vx_data_csv.Class_csv()
        work.vx_p_headers = vx_p_headers
        work.vx_p_rows = vx_p_rows
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.e_csv
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csv
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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

  val e_csv : vx_data_csv.Type_csv = vx_data_csv.Class_csv()
  val t_csv : vx_data_csv.Type_csv = vx_data_csv.Class_csv()

  interface Type_csvrowmap : vx_core.Type_map {
    fun vx_mapstringlist() : Map<String, vx_core.Type_stringlist>
    fun vx_stringlist(key : vx_core.Type_string) : vx_core.Type_stringlist
  }

  class Class_csvrowmap : vx_core.Class_base, Type_csvrowmap {
    constructor() {}

    var vx_p_map : Map<String, vx_core.Type_stringlist> = vx_core.immutablemap(LinkedHashMap<String, vx_core.Type_stringlist>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_core.Type_stringlist) {
        var castval : vx_core.Type_stringlist = value as vx_core.Type_stringlist
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_core.Type_stringlist> = LinkedHashMap<String, vx_core.Type_stringlist>(this.vx_p_map)
        if (castval == vx_core.e_stringlist) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_stringlist(key : vx_core.Type_string) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_core.e_stringlist
      var map : vx_data_csv.Class_csvrowmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_core.Type_stringlist> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_core.e_stringlist)
      return output
    }

    override fun vx_mapstringlist() : Map<String, vx_core.Type_stringlist> {
      var output : Map<String, vx_core.Type_stringlist> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_stringlist(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_csv.Class_csvrowmap = vx_data_csv.Class_csvrowmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_core.Type_stringlist> = LinkedHashMap<String, vx_core.Type_stringlist>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_core.Type_stringlist) {
          var castval : vx_core.Type_stringlist = value as vx_core.Type_stringlist
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidvalue", value)
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
      var output : vx_data_csv.Type_csvrowmap = vx_core.vx_copy(vx_data_csv.e_csvrowmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_csv.Type_csvrowmap = this
      var ischanged : Boolean = false
      var value : vx_data_csv.Class_csvrowmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_core.Type_stringlist> = LinkedHashMap<String, vx_core.Type_stringlist>(value.vx_mapstringlist())
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
            msg = vx_core.vx_msg_from_error("vx/data/csv/csvrowmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_core.Type_stringlist = vx_core.e_stringlist
          if (false) {
          } else if (valsub is vx_core.Type_stringlist) {
            var valallowed : vx_core.Type_stringlist = valsub as vx_core.Type_stringlist
            valany = valallowed
          } else if (valsub is vx_core.Type_stringlist) {
            valany = valsub as vx_core.Type_stringlist
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
            msg = vx_core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_csv.Class_csvrowmap = vx_data_csv.Class_csvrowmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.e_csvrowmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csvrowmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrowmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_stringlist), // allowtypes
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

  val e_csvrowmap : vx_data_csv.Type_csvrowmap = vx_data_csv.Class_csvrowmap()
  val t_csvrowmap : vx_data_csv.Type_csvrowmap = vx_data_csv.Class_csvrowmap()

  interface Type_csvrows : vx_core.Type_list {
    fun vx_liststringlist() : List<vx_core.Type_stringlist>
    fun vx_stringlist(index : vx_core.Type_int) : vx_core.Type_stringlist
  }

  class Class_csvrows : vx_core.Class_base, Type_csvrows {
    constructor() {}

    var vx_p_list : List<vx_core.Type_stringlist> = vx_core.immutablelist(
      ArrayList<vx_core.Type_stringlist>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_stringlist(index : vx_core.Type_int) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_core.e_stringlist
      var list : vx_data_csv.Class_csvrows = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_core.Type_stringlist> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_liststringlist() : List<vx_core.Type_stringlist> {
      var output : List<vx_core.Type_stringlist> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_core.Type_stringlist = this.vx_stringlist(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_csv.Type_csvrows = vx_core.vx_copy(vx_data_csv.e_csvrows, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_csv.Type_csvrows = this
      var ischanged : Boolean = false
      var value : vx_data_csv.Class_csvrows = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_core.Type_stringlist> = ArrayList<vx_core.Type_stringlist>(value.vx_liststringlist())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_csv.Type_csvrows) {
          var multi : vx_data_csv.Type_csvrows = valsub as vx_data_csv.Type_csvrows
          ischanged = true
          listval.addAll(multi.vx_liststringlist())
        } else if (valsub is vx_core.Type_stringlist) {
          var allowsub : vx_core.Type_stringlist = valsub as vx_core.Type_stringlist
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_core.Type_stringlist) {
          ischanged = true
          listval.add(valsub as vx_core.Type_stringlist)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_core.Type_stringlist) {
              var valitem : vx_core.Type_stringlist = item as vx_core.Type_stringlist
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_csv.Class_csvrows = vx_data_csv.Class_csvrows()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.e_csvrows
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csvrows
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_core.t_stringlist), // allowtypes
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

  val e_csvrows : vx_data_csv.Type_csvrows = vx_data_csv.Class_csvrows()
  val t_csvrows : vx_data_csv.Type_csvrows = vx_data_csv.Class_csvrows()

  class Const_delimcsv {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/csv", // pkgname
        "delimcsv", // name
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
          vx_core.vx_new_string("delimcsv"),
          vx_core.vx_new_string(":delimlist"),
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_data_textblock.c_delimline,
              vx_data_textblock.c_delimquote,
              vx_data_textblock.c_delimcomma
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

  val c_delimcsv : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  interface Func_csv_read_from_file : vx_core.Func_any_from_any_context {
    fun vx_csv_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_csv.Type_csv
  }

  class Class_csv_read_from_file : vx_core.Class_base, Func_csv_read_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_read_from_file = vx_data_csv.Class_csv_read_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_read_from_file = vx_data_csv.Class_csv_read_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv-read<-file", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
      var output : vx_core.Type_any = vx_data_csv.e_csv_read_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csv_read_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_csv.f_csv_read_from_file(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_csv_read_from_file(context, file)
      return output
    }

    override fun vx_csv_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_csv.Type_csv {
      var output : vx_data_csv.Type_csv = vx_data_csv.f_csv_read_from_file(context, file)
      return output
    }

  }

  val e_csv_read_from_file : vx_data_csv.Func_csv_read_from_file = vx_data_csv.Class_csv_read_from_file()
  val t_csv_read_from_file : vx_data_csv.Func_csv_read_from_file = vx_data_csv.Class_csv_read_from_file()

  fun f_csv_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_csv.Type_csv {
    var output : vx_data_csv.Type_csv = vx_data_csv.e_csv
    output = vx_core.f_let(
      vx_data_csv.t_csv,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var loaded : vx_data_file.Type_file = vx_data_file.f_file_read_from_file(
          context,
          file
        )
        var output_1 : vx_core.Type_any = vx_data_csv.f_csv_from_file(
          loaded
        )
        output_1
      })
    )
    return output
  }


  interface Func_csv_from_file : vx_core.Func_any_from_any {
    fun vx_csv_from_file(file : vx_data_file.Type_file) : vx_data_csv.Type_csv
  }

  class Class_csv_from_file : vx_core.Class_base, Func_csv_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_file = vx_data_csv.Class_csv_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_file = vx_data_csv.Class_csv_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-file", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
      var output : vx_core.Type_any = vx_data_csv.e_csv_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csv_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_csv.f_csv_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_csv_from_file(file)
      return output
    }

    override fun vx_csv_from_file(file : vx_data_file.Type_file) : vx_data_csv.Type_csv {
      var output : vx_data_csv.Type_csv = vx_data_csv.f_csv_from_file(file)
      return output
    }

  }

  val e_csv_from_file : vx_data_csv.Func_csv_from_file = vx_data_csv.Class_csv_from_file()
  val t_csv_from_file : vx_data_csv.Func_csv_from_file = vx_data_csv.Class_csv_from_file()

  fun f_csv_from_file(file : vx_data_file.Type_file) : vx_data_csv.Type_csv {
    var output : vx_data_csv.Type_csv = vx_data_csv.e_csv
    output = vx_core.f_let(
      vx_data_csv.t_csv,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = file.text()
        var output_1 : vx_core.Type_any = vx_data_csv.f_csv_from_string(
          text
        )
        output_1
      })
    )
    return output
  }


  interface Func_csv_from_string : vx_core.Func_any_from_any {
    fun vx_csv_from_string(text : vx_core.Type_string) : vx_data_csv.Type_csv
  }

  class Class_csv_from_string : vx_core.Class_base, Func_csv_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_string = vx_data_csv.Class_csv_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_string = vx_data_csv.Class_csv_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
      var output : vx_core.Type_any = vx_data_csv.e_csv_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csv_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_csv.f_csv_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_csv_from_string(text)
      return output
    }

    override fun vx_csv_from_string(text : vx_core.Type_string) : vx_data_csv.Type_csv {
      var output : vx_data_csv.Type_csv = vx_data_csv.f_csv_from_string(text)
      return output
    }

  }

  val e_csv_from_string : vx_data_csv.Func_csv_from_string = vx_data_csv.Class_csv_from_string()
  val t_csv_from_string : vx_data_csv.Func_csv_from_string = vx_data_csv.Class_csv_from_string()

  fun f_csv_from_string(text : vx_core.Type_string) : vx_data_csv.Type_csv {
    var output : vx_data_csv.Type_csv = vx_data_csv.e_csv
    output = vx_data_csv.f_csv_from_textblock(
      vx_data_textblock.f_textblock_parse_from_string_delim(
        text,
        vx_data_csv.c_delimcsv
      )
    )
    return output
  }


  interface Func_csv_from_textblock : vx_core.Func_any_from_any {
    fun vx_csv_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csv
  }

  class Class_csv_from_textblock : vx_core.Class_base, Func_csv_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_textblock = vx_data_csv.Class_csv_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csv_from_textblock = vx_data_csv.Class_csv_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
      var output : vx_core.Type_any = vx_data_csv.e_csv_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csv_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_csv.f_csv_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_csv_from_textblock(textblock)
      return output
    }

    override fun vx_csv_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csv {
      var output : vx_data_csv.Type_csv = vx_data_csv.f_csv_from_textblock(textblock)
      return output
    }

  }

  val e_csv_from_textblock : vx_data_csv.Func_csv_from_textblock = vx_data_csv.Class_csv_from_textblock()
  val t_csv_from_textblock : vx_data_csv.Func_csv_from_textblock = vx_data_csv.Class_csv_from_textblock()

  fun f_csv_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csv {
    var output : vx_data_csv.Type_csv = vx_data_csv.e_csv
    output = vx_core.f_let(
      vx_data_csv.t_csv,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var allrows : vx_data_csv.Type_csvrows = vx_data_csv.f_csvrows_from_textblock(
          textblock
        )
        var headers : vx_core.Type_stringlist = vx_core.f_any_from_list(
          vx_core.t_stringlist,
          allrows,
          vx_core.vx_new_int(1)
        )
        var rows : vx_data_csv.Type_csvrows = vx_collection.f_list_from_list_end(
          vx_data_csv.t_csvrows,
          allrows,
          vx_core.vx_new_int(2)
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_csv.t_csv,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":headers"),
            headers,
            vx_core.vx_new_string(":rows"),
            rows
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_csvrows_from_textblock : vx_core.Func_any_from_any {
    fun vx_csvrows_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csvrows
  }

  class Class_csvrows_from_textblock : vx_core.Class_base, Func_csvrows_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csvrows_from_textblock = vx_data_csv.Class_csvrows_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_csvrows_from_textblock = vx_data_csv.Class_csvrows_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/csv", // pkgname
          "csvrows", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_stringlist), // allowtypes
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
      var output : vx_core.Type_any = vx_data_csv.e_csvrows_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_csvrows_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_csv.f_csvrows_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_csvrows_from_textblock(textblock)
      return output
    }

    override fun vx_csvrows_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csvrows {
      var output : vx_data_csv.Type_csvrows = vx_data_csv.f_csvrows_from_textblock(textblock)
      return output
    }

  }

  val e_csvrows_from_textblock : vx_data_csv.Func_csvrows_from_textblock = vx_data_csv.Class_csvrows_from_textblock()
  val t_csvrows_from_textblock : vx_data_csv.Func_csvrows_from_textblock = vx_data_csv.Class_csvrows_from_textblock()

  fun f_csvrows_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_csv.Type_csvrows {
    var output : vx_data_csv.Type_csvrows = vx_data_csv.e_csvrows
    output = vx_core.f_let(
      vx_data_csv.t_csvrows,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var parsedtb : vx_data_textblock.Type_textblock = vx_data_textblock.f_textblock_from_textblock_delim(
          textblock,
          vx_data_csv.c_delimcsv
        )
        var children : vx_data_textblock.Type_textblocklist = vx_data_textblock.f_children_from_textblock(
          parsedtb
        )
        var strings : vx_core.Type_stringlist = vx_data_textblock.f_stringlist_from_textblocklist(
          children
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_csv.t_csvrows,
          vx_core.vx_new(
            vx_core.t_anylist,
            strings
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_stringmap_from_csv : vx_core.Func_any_from_any {
    fun vx_stringmap_from_csv(csv : vx_data_csv.Type_csv) : vx_core.Type_stringmap
  }

  class Class_stringmap_from_csv : vx_core.Class_base, Func_stringmap_from_csv {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_stringmap_from_csv = vx_data_csv.Class_stringmap_from_csv()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_stringmap_from_csv = vx_data_csv.Class_stringmap_from_csv()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "stringmap<-csv", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
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
      var output : vx_core.Type_any = vx_data_csv.e_stringmap_from_csv
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_stringmap_from_csv
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_csv.Type_csv = value as vx_data_csv.Type_csv
      var outputval : vx_core.Type_any = vx_data_csv.f_stringmap_from_csv(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var csv : vx_data_csv.Type_csv = vx_core.f_any_from_any(vx_data_csv.t_csv, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_stringmap_from_csv(csv)
      return output
    }

    override fun vx_stringmap_from_csv(csv : vx_data_csv.Type_csv) : vx_core.Type_stringmap {
      var output : vx_core.Type_stringmap = vx_data_csv.f_stringmap_from_csv(csv)
      return output
    }

  }

  val e_stringmap_from_csv : vx_data_csv.Func_stringmap_from_csv = vx_data_csv.Class_stringmap_from_csv()
  val t_stringmap_from_csv : vx_data_csv.Func_stringmap_from_csv = vx_data_csv.Class_stringmap_from_csv()

  fun f_stringmap_from_csv(csv : vx_data_csv.Type_csv) : vx_core.Type_stringmap {
    var output : vx_core.Type_stringmap = vx_core.e_stringmap
    output = vx_core.f_let(
      vx_core.t_stringmap,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var rows : vx_data_csv.Type_csvrows = csv.rows()
        var rowmap : vx_data_csv.Type_csvrowmap = vx_core.f_map_from_list(
          vx_data_csv.t_csvrowmap,
          rows,
          vx_core.t_any_from_any.vx_fn_new({textlist_any : vx_core.Type_any ->
            var textlist : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, textlist_any)
            var output_3 : vx_core.Type_any = vx_core.f_any_from_list(
              vx_core.t_string,
              textlist,
              vx_core.vx_new_int(1)
            )
            output_3
          })
        )
        var output_1 : vx_core.Type_any = vx_core.f_map_from_map_1(
          vx_core.t_stringmap,
          rowmap,
          vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var value : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, value_any)
            var output_2 : vx_core.Type_any = vx_core.f_any_from_list(
              vx_core.t_string,
              value,
              vx_core.vx_new_int(2)
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_textblock_csv_from_string : vx_core.Func_any_from_any {
    fun vx_textblock_csv_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_csv_from_string : vx_core.Class_base, Func_textblock_csv_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_textblock_csv_from_string = vx_data_csv.Class_textblock_csv_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_csv.Class_textblock_csv_from_string = vx_data_csv.Class_textblock_csv_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
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
      var output : vx_core.Type_any = vx_data_csv.e_textblock_csv_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_csv.t_textblock_csv_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_csv.f_textblock_csv_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_csv.f_textblock_csv_from_string(text)
      return output
    }

    override fun vx_textblock_csv_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_csv.f_textblock_csv_from_string(text)
      return output
    }

  }

  val e_textblock_csv_from_string : vx_data_csv.Func_textblock_csv_from_string = vx_data_csv.Class_textblock_csv_from_string()
  val t_textblock_csv_from_string : vx_data_csv.Func_textblock_csv_from_string = vx_data_csv.Class_textblock_csv_from_string()

  fun f_textblock_csv_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      text,
      vx_data_csv.c_delimcsv
    )
    return output
  }


  init {
    Const_delimcsv.const_new(c_delimcsv)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("csv", vx_data_csv.t_csv)
    maptype.put("csvrowmap", vx_data_csv.t_csvrowmap)
    maptype.put("csvrows", vx_data_csv.t_csvrows)
    mapconst.put("delimcsv", vx_data_csv.c_delimcsv)
    mapfunc.put("csv-read<-file", vx_data_csv.t_csv_read_from_file)
    mapfunc.put("csv<-file", vx_data_csv.t_csv_from_file)
    mapfunc.put("csv<-string", vx_data_csv.t_csv_from_string)
    mapfunc.put("csv<-textblock", vx_data_csv.t_csv_from_textblock)
    mapfunc.put("csvrows<-textblock", vx_data_csv.t_csvrows_from_textblock)
    mapfunc.put("stringmap<-csv", vx_data_csv.t_stringmap_from_csv)
    mapfunc.put("textblock-csv<-string", vx_data_csv.t_textblock_csv_from_string)
    vx_core.vx_global_package_set("vx/data/csv", maptype, mapconst, mapfunc)
  }

}
