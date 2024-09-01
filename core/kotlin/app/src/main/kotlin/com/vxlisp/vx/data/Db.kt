package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_db {


  interface Type_db : vx_core.Type_struct {
    fun dbid() : vx_core.Type_string
  }

  class Class_db : vx_core.Class_base, Type_db {
    constructor() {}

    var vx_p_dbid : vx_core.Type_string? = null

    override fun dbid() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_dbid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbid", this.dbid())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_db = vx_core.vx_copy(vx_data_db.e_db, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_db = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_db = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbid : vx_core.Type_string = value.dbid()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbid")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/db", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbid")) {
            if (valsub == vx_p_dbid) {
            } else if (valsub is vx_core.Type_string) {
              var valdbid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_dbid = valdbid
            } else if (valsub is String) {
              ischanged = true
              vx_p_dbid = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/db", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_db = vx_data_db.Class_db()
        work.vx_p_dbid = vx_p_dbid
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_db
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_db
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "db", // name
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

  val e_db : vx_data_db.Type_db = vx_data_db.Class_db()
  val t_db : vx_data_db.Type_db = vx_data_db.Class_db()

  interface Type_dbcell : vx_core.Type_struct {
    fun dbcellid() : vx_core.Type_string
    fun dbcellmap() : vx_data_db.Type_dbcellmap
    fun dbfieldmap() : vx_data_db.Type_dbfieldmap
    fun dbparent() : vx_data_db.Type_dbcell
    fun dbtable() : vx_data_db.Type_dbtable
  }

  class Class_dbcell : vx_core.Class_base, Type_dbcell {
    constructor() {}

    var vx_p_dbcellid : vx_core.Type_string? = null

    override fun dbcellid() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_dbcellid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbcellmap : vx_data_db.Type_dbcellmap? = null

    override fun dbcellmap() : vx_data_db.Type_dbcellmap {
      var output : vx_data_db.Type_dbcellmap = vx_data_db.e_dbcellmap
      var testnull : vx_data_db.Type_dbcellmap? = vx_p_dbcellmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbfieldmap : vx_data_db.Type_dbfieldmap? = null

    override fun dbfieldmap() : vx_data_db.Type_dbfieldmap {
      var output : vx_data_db.Type_dbfieldmap = vx_data_db.e_dbfieldmap
      var testnull : vx_data_db.Type_dbfieldmap? = vx_p_dbfieldmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbparent : vx_data_db.Type_dbcell? = null

    override fun dbparent() : vx_data_db.Type_dbcell {
      var output : vx_data_db.Type_dbcell = vx_data_db.e_dbcell
      var testnull : vx_data_db.Type_dbcell? = vx_p_dbparent
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbtable : vx_data_db.Type_dbtable? = null

    override fun dbtable() : vx_data_db.Type_dbtable {
      var output : vx_data_db.Type_dbtable = vx_data_db.e_dbtable
      var testnull : vx_data_db.Type_dbtable? = vx_p_dbtable
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbcellid")) {
        output = this.dbcellid()
      } else if ((skey==":dbcellmap")) {
        output = this.dbcellmap()
      } else if ((skey==":dbfieldmap")) {
        output = this.dbfieldmap()
      } else if ((skey==":dbparent")) {
        output = this.dbparent()
      } else if ((skey==":dbtable")) {
        output = this.dbtable()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbcellid", this.dbcellid())
      map.put(":dbcellmap", this.dbcellmap())
      map.put(":dbfieldmap", this.dbfieldmap())
      map.put(":dbparent", this.dbparent())
      map.put(":dbtable", this.dbtable())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbcell = vx_core.vx_copy(vx_data_db.e_dbcell, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbcell = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbcell = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbcellid : vx_core.Type_string = value.dbcellid()
      var vx_p_dbcellmap : vx_data_db.Type_dbcellmap = value.dbcellmap()
      var vx_p_dbfieldmap : vx_data_db.Type_dbfieldmap = value.dbfieldmap()
      var vx_p_dbparent : vx_data_db.Type_dbcell = value.dbparent()
      var vx_p_dbtable : vx_data_db.Type_dbtable = value.dbtable()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbcellid")
      validkeys.add(":dbcellmap")
      validkeys.add(":dbfieldmap")
      validkeys.add(":dbparent")
      validkeys.add(":dbtable")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbcellid")) {
            if (valsub == vx_p_dbcellid) {
            } else if (valsub is vx_core.Type_string) {
              var valdbcellid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_dbcellid = valdbcellid
            } else if (valsub is String) {
              ischanged = true
              vx_p_dbcellid = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbcellid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbcellmap")) {
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub is vx_data_db.Type_dbcellmap) {
              var valdbcellmap : vx_data_db.Type_dbcellmap = valsub as vx_data_db.Type_dbcellmap
              ischanged = true
              vx_p_dbcellmap = valdbcellmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbcellmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbfieldmap")) {
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub is vx_data_db.Type_dbfieldmap) {
              var valdbfieldmap : vx_data_db.Type_dbfieldmap = valsub as vx_data_db.Type_dbfieldmap
              ischanged = true
              vx_p_dbfieldmap = valdbfieldmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbfieldmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbparent")) {
            if (valsub == vx_p_dbparent) {
            } else if (valsub is vx_data_db.Type_dbcell) {
              var valdbparent : vx_data_db.Type_dbcell = valsub as vx_data_db.Type_dbcell
              ischanged = true
              vx_p_dbparent = valdbparent
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbparent"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbtable")) {
            if (valsub == vx_p_dbtable) {
            } else if (valsub is vx_data_db.Type_dbtable) {
              var valdbtable : vx_data_db.Type_dbtable = valsub as vx_data_db.Type_dbtable
              ischanged = true
              vx_p_dbtable = valdbtable
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbtable"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbcell = vx_data_db.Class_dbcell()
        work.vx_p_dbcellid = vx_p_dbcellid
        work.vx_p_dbcellmap = vx_p_dbcellmap
        work.vx_p_dbfieldmap = vx_p_dbfieldmap
        work.vx_p_dbparent = vx_p_dbparent
        work.vx_p_dbtable = vx_p_dbtable
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbcell
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbcell
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbcell", // name
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

  val e_dbcell : vx_data_db.Type_dbcell = vx_data_db.Class_dbcell()
  val t_dbcell : vx_data_db.Type_dbcell = vx_data_db.Class_dbcell()

  interface Type_dbcellmap : vx_core.Type_map {
    fun vx_mapdbcell() : Map<String, vx_data_db.Type_dbcell>
    fun vx_dbcell(key : vx_core.Type_string) : vx_data_db.Type_dbcell
  }

  class Class_dbcellmap : vx_core.Class_base, Type_dbcellmap {
    constructor() {}

    var vx_p_map : Map<String, vx_data_db.Type_dbcell> = vx_core.immutablemap(LinkedHashMap<String, vx_data_db.Type_dbcell>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_data_db.Type_dbcell) {
        var castval : vx_data_db.Type_dbcell = value as vx_data_db.Type_dbcell
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_data_db.Type_dbcell> = LinkedHashMap<String, vx_data_db.Type_dbcell>(this.vx_p_map)
        if (castval == vx_data_db.e_dbcell) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_dbcell(key : vx_core.Type_string) : vx_data_db.Type_dbcell {
      var output : vx_data_db.Type_dbcell = vx_data_db.e_dbcell
      var map : vx_data_db.Class_dbcellmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_data_db.Type_dbcell> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_data_db.e_dbcell)
      return output
    }

    override fun vx_mapdbcell() : Map<String, vx_data_db.Type_dbcell> {
      var output : Map<String, vx_data_db.Type_dbcell> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_dbcell(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_db.Class_dbcellmap = vx_data_db.Class_dbcellmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_data_db.Type_dbcell> = LinkedHashMap<String, vx_data_db.Type_dbcell>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_data_db.Type_dbcell) {
          var castval : vx_data_db.Type_dbcell = value as vx_data_db.Type_dbcell
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidvalue", value)
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
      var output : vx_data_db.Type_dbcellmap = vx_core.vx_copy(vx_data_db.e_dbcellmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbcellmap = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbcellmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_data_db.Type_dbcell> = LinkedHashMap<String, vx_data_db.Type_dbcell>(value.vx_mapdbcell())
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbcellmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_data_db.Type_dbcell = vx_data_db.e_dbcell
          if (false) {
          } else if (valsub is vx_data_db.Type_dbcell) {
            var valallowed : vx_data_db.Type_dbcell = valsub as vx_data_db.Type_dbcell
            valany = valallowed
          } else if (valsub is vx_data_db.Type_dbcell) {
            valany = valsub as vx_data_db.Type_dbcell
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_db.Class_dbcellmap = vx_data_db.Class_dbcellmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbcellmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbcellmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_db.t_dbcell), // allowtypes
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

  val e_dbcellmap : vx_data_db.Type_dbcellmap = vx_data_db.Class_dbcellmap()
  val t_dbcellmap : vx_data_db.Type_dbcellmap = vx_data_db.Class_dbcellmap()

  interface Type_dbfield : vx_core.Type_struct {
    fun dbfieldid() : vx_core.Type_string
    fun type() : vx_core.Type_any
    fun value() : vx_core.Type_any
  }

  class Class_dbfield : vx_core.Class_base, Type_dbfield {
    constructor() {}

    var vx_p_dbfieldid : vx_core.Type_string? = null

    override fun dbfieldid() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_dbfieldid
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
      } else if ((skey==":dbfieldid")) {
        output = this.dbfieldid()
      } else if ((skey==":type")) {
        output = this.type()
      } else if ((skey==":value")) {
        output = this.value()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbfieldid", this.dbfieldid())
      map.put(":type", this.type())
      map.put(":value", this.value())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbfield = vx_core.vx_copy(vx_data_db.e_dbfield, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbfield = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbfield = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbfieldid : vx_core.Type_string = value.dbfieldid()
      var vx_p_type : vx_core.Type_any = value.type()
      var vx_p_value : vx_core.Type_any = value.value()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbfieldid")
      validkeys.add(":type")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbfieldid")) {
            if (valsub == vx_p_dbfieldid) {
            } else if (valsub is vx_core.Type_string) {
              var valdbfieldid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_dbfieldid = valdbfieldid
            } else if (valsub is String) {
              ischanged = true
              vx_p_dbfieldid = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbfieldid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbfield = vx_data_db.Class_dbfield()
        work.vx_p_dbfieldid = vx_p_dbfieldid
        work.vx_p_type = vx_p_type
        work.vx_p_value = vx_p_value
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbfield
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbfield
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbfield", // name
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

  val e_dbfield : vx_data_db.Type_dbfield = vx_data_db.Class_dbfield()
  val t_dbfield : vx_data_db.Type_dbfield = vx_data_db.Class_dbfield()

  interface Type_dbfieldmap : vx_core.Type_map {
    fun vx_mapdbfield() : Map<String, vx_data_db.Type_dbfield>
    fun vx_dbfield(key : vx_core.Type_string) : vx_data_db.Type_dbfield
  }

  class Class_dbfieldmap : vx_core.Class_base, Type_dbfieldmap {
    constructor() {}

    var vx_p_map : Map<String, vx_data_db.Type_dbfield> = vx_core.immutablemap(LinkedHashMap<String, vx_data_db.Type_dbfield>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_data_db.Type_dbfield) {
        var castval : vx_data_db.Type_dbfield = value as vx_data_db.Type_dbfield
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_data_db.Type_dbfield> = LinkedHashMap<String, vx_data_db.Type_dbfield>(this.vx_p_map)
        if (castval == vx_data_db.e_dbfield) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_dbfield(key : vx_core.Type_string) : vx_data_db.Type_dbfield {
      var output : vx_data_db.Type_dbfield = vx_data_db.e_dbfield
      var map : vx_data_db.Class_dbfieldmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_data_db.Type_dbfield> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_data_db.e_dbfield)
      return output
    }

    override fun vx_mapdbfield() : Map<String, vx_data_db.Type_dbfield> {
      var output : Map<String, vx_data_db.Type_dbfield> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_dbfield(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_db.Class_dbfieldmap = vx_data_db.Class_dbfieldmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_data_db.Type_dbfield> = LinkedHashMap<String, vx_data_db.Type_dbfield>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_data_db.Type_dbfield) {
          var castval : vx_data_db.Type_dbfield = value as vx_data_db.Type_dbfield
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidvalue", value)
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
      var output : vx_data_db.Type_dbfieldmap = vx_core.vx_copy(vx_data_db.e_dbfieldmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbfieldmap = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbfieldmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_data_db.Type_dbfield> = LinkedHashMap<String, vx_data_db.Type_dbfield>(value.vx_mapdbfield())
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbfieldmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_data_db.Type_dbfield = vx_data_db.e_dbfield
          if (false) {
          } else if (valsub is vx_data_db.Type_dbfield) {
            var valallowed : vx_data_db.Type_dbfield = valsub as vx_data_db.Type_dbfield
            valany = valallowed
          } else if (valsub is vx_data_db.Type_dbfield) {
            valany = valsub as vx_data_db.Type_dbfield
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_db.Class_dbfieldmap = vx_data_db.Class_dbfieldmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbfieldmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbfieldmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_db.t_dbfield), // allowtypes
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

  val e_dbfieldmap : vx_data_db.Type_dbfieldmap = vx_data_db.Class_dbfieldmap()
  val t_dbfieldmap : vx_data_db.Type_dbfieldmap = vx_data_db.Class_dbfieldmap()

  interface Type_dbid : vx_core.Type_any {
  }

  class Class_dbid : vx_core.Class_base, Type_dbid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbid = vx_core.vx_copy(vx_data_db.e_dbid, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbid = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbid = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbid = vx_data_db.Class_dbid()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbid
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbid", // name
        ":string", // extends
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

  val e_dbid : vx_data_db.Type_dbid = vx_data_db.Class_dbid()
  val t_dbid : vx_data_db.Type_dbid = vx_data_db.Class_dbid()

  interface Type_dblink : vx_core.Type_struct {
    fun fromid() : vx_data_db.Type_dbid
    fun toid() : vx_data_db.Type_dbid
  }

  class Class_dblink : vx_core.Class_base, Type_dblink {
    constructor() {}

    var vx_p_fromid : vx_data_db.Type_dbid? = null

    override fun fromid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_fromid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_toid : vx_data_db.Type_dbid? = null

    override fun toid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_toid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":fromid")) {
        output = this.fromid()
      } else if ((skey==":toid")) {
        output = this.toid()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":fromid", this.fromid())
      map.put(":toid", this.toid())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dblink = vx_core.vx_copy(vx_data_db.e_dblink, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dblink = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dblink = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_fromid : vx_data_db.Type_dbid = value.fromid()
      var vx_p_toid : vx_data_db.Type_dbid = value.toid()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":fromid")
      validkeys.add(":toid")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dblink", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":fromid")) {
            if (valsub == vx_p_fromid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valfromid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_fromid = valfromid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fromid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":toid")) {
            if (valsub == vx_p_toid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valtoid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_toid = valtoid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("toid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dblink = vx_data_db.Class_dblink()
        work.vx_p_fromid = vx_p_fromid
        work.vx_p_toid = vx_p_toid
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dblink
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dblink
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dblink", // name
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

  val e_dblink : vx_data_db.Type_dblink = vx_data_db.Class_dblink()
  val t_dblink : vx_data_db.Type_dblink = vx_data_db.Class_dblink()

  interface Type_dblinklist : vx_core.Type_list {
    fun vx_listdblink() : List<vx_data_db.Type_dblink>
    fun vx_dblink(index : vx_core.Type_int) : vx_data_db.Type_dblink
  }

  class Class_dblinklist : vx_core.Class_base, Type_dblinklist {
    constructor() {}

    var vx_p_list : List<vx_data_db.Type_dblink> = vx_core.immutablelist(
      ArrayList<vx_data_db.Type_dblink>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_dblink(index : vx_core.Type_int) : vx_data_db.Type_dblink {
      var output : vx_data_db.Type_dblink = vx_data_db.e_dblink
      var list : vx_data_db.Class_dblinklist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_db.Type_dblink> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listdblink() : List<vx_data_db.Type_dblink> {
      var output : List<vx_data_db.Type_dblink> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_db.Type_dblink = this.vx_dblink(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dblinklist = vx_core.vx_copy(vx_data_db.e_dblinklist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dblinklist = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dblinklist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_db.Type_dblink> = ArrayList<vx_data_db.Type_dblink>(value.vx_listdblink())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_db.Type_dblinklist) {
          var multi : vx_data_db.Type_dblinklist = valsub as vx_data_db.Type_dblinklist
          ischanged = true
          listval.addAll(multi.vx_listdblink())
        } else if (valsub is vx_data_db.Type_dblink) {
          var allowsub : vx_data_db.Type_dblink = valsub as vx_data_db.Type_dblink
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_db.Type_dblink) {
          ischanged = true
          listval.add(valsub as vx_data_db.Type_dblink)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_db.Type_dblink) {
              var valitem : vx_data_db.Type_dblink = item as vx_data_db.Type_dblink
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dblinklist = vx_data_db.Class_dblinklist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dblinklist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dblinklist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dblinklist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_db.t_dblink), // allowtypes
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

  val e_dblinklist : vx_data_db.Type_dblinklist = vx_data_db.Class_dblinklist()
  val t_dblinklist : vx_data_db.Type_dblinklist = vx_data_db.Class_dblinklist()

  interface Type_dbnode : vx_core.Type_struct {
    fun dbid() : vx_data_db.Type_dbid
    fun links() : vx_data_db.Type_dblinklist
  }

  class Class_dbnode : vx_core.Class_base, Type_dbnode {
    constructor() {}

    var vx_p_dbid : vx_data_db.Type_dbid? = null

    override fun dbid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_dbid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_links : vx_data_db.Type_dblinklist? = null

    override fun links() : vx_data_db.Type_dblinklist {
      var output : vx_data_db.Type_dblinklist = vx_data_db.e_dblinklist
      var testnull : vx_data_db.Type_dblinklist? = vx_p_links
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid()
      } else if ((skey==":links")) {
        output = this.links()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbid", this.dbid())
      map.put(":links", this.links())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbnode = vx_core.vx_copy(vx_data_db.e_dbnode, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbnode = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbnode = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbid : vx_data_db.Type_dbid = value.dbid()
      var vx_p_links : vx_data_db.Type_dblinklist = value.links()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbid")
      validkeys.add(":links")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbid")) {
            if (valsub == vx_p_dbid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valdbid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_dbid = valdbid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":links")) {
            if (valsub == vx_p_links) {
            } else if (valsub is vx_data_db.Type_dblinklist) {
              var vallinks : vx_data_db.Type_dblinklist = valsub as vx_data_db.Type_dblinklist
              ischanged = true
              vx_p_links = vallinks
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("links"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbnode = vx_data_db.Class_dbnode()
        work.vx_p_dbid = vx_p_dbid
        work.vx_p_links = vx_p_links
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbnode
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbnode
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbnode", // name
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

  val e_dbnode : vx_data_db.Type_dbnode = vx_data_db.Class_dbnode()
  val t_dbnode : vx_data_db.Type_dbnode = vx_data_db.Class_dbnode()

  interface Type_dbnote : vx_core.Type_struct {
    fun dbid() : vx_data_db.Type_dbid
    fun valid() : vx_data_db.Type_dbid
    fun noteid() : vx_data_db.Type_dbid
    fun valueid() : vx_data_db.Type_dbid
    fun value() : vx_core.Type_string
  }

  class Class_dbnote : vx_core.Class_base, Type_dbnote {
    constructor() {}

    var vx_p_dbid : vx_data_db.Type_dbid? = null

    override fun dbid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_dbid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_valid : vx_data_db.Type_dbid? = null

    override fun valid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_valid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_noteid : vx_data_db.Type_dbid? = null

    override fun noteid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_noteid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_valueid : vx_data_db.Type_dbid? = null

    override fun valueid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_valueid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_value : vx_core.Type_string? = null

    override fun value() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_value
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid()
      } else if ((skey==":valid")) {
        output = this.valid()
      } else if ((skey==":noteid")) {
        output = this.noteid()
      } else if ((skey==":valueid")) {
        output = this.valueid()
      } else if ((skey==":value")) {
        output = this.value()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbid", this.dbid())
      map.put(":valid", this.valid())
      map.put(":noteid", this.noteid())
      map.put(":valueid", this.valueid())
      map.put(":value", this.value())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbnote = vx_core.vx_copy(vx_data_db.e_dbnote, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbnote = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbnote = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbid : vx_data_db.Type_dbid = value.dbid()
      var vx_p_valid : vx_data_db.Type_dbid = value.valid()
      var vx_p_noteid : vx_data_db.Type_dbid = value.noteid()
      var vx_p_valueid : vx_data_db.Type_dbid = value.valueid()
      var vx_p_value : vx_core.Type_string = value.value()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbid")
      validkeys.add(":valid")
      validkeys.add(":noteid")
      validkeys.add(":valueid")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbid")) {
            if (valsub == vx_p_dbid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valdbid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_dbid = valdbid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":valid")) {
            if (valsub == vx_p_valid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valvalid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_valid = valvalid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("valid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":noteid")) {
            if (valsub == vx_p_noteid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valnoteid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_noteid = valnoteid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("noteid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":valueid")) {
            if (valsub == vx_p_valueid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valvalueid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_valueid = valvalueid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("valueid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":value")) {
            if (valsub == vx_p_value) {
            } else if (valsub is vx_core.Type_string) {
              var valvalue : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_value = valvalue
            } else if (valsub is String) {
              ischanged = true
              vx_p_value = vx_core.vx_new(vx_core.t_string, valsub)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbnote = vx_data_db.Class_dbnote()
        work.vx_p_dbid = vx_p_dbid
        work.vx_p_valid = vx_p_valid
        work.vx_p_noteid = vx_p_noteid
        work.vx_p_valueid = vx_p_valueid
        work.vx_p_value = vx_p_value
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbnote
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbnote
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbnote", // name
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

  val e_dbnote : vx_data_db.Type_dbnote = vx_data_db.Class_dbnote()
  val t_dbnote : vx_data_db.Type_dbnote = vx_data_db.Class_dbnote()

  interface Type_dbtable : vx_core.Type_struct {
    fun dbtableid() : vx_core.Type_string
    fun db() : vx_data_db.Type_db
    fun dbcellmap() : vx_data_db.Type_dbcellmap
    fun dbfieldmap() : vx_data_db.Type_dbfieldmap
  }

  class Class_dbtable : vx_core.Class_base, Type_dbtable {
    constructor() {}

    var vx_p_dbtableid : vx_core.Type_string? = null

    override fun dbtableid() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_dbtableid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_db : vx_data_db.Type_db? = null

    override fun db() : vx_data_db.Type_db {
      var output : vx_data_db.Type_db = vx_data_db.e_db
      var testnull : vx_data_db.Type_db? = vx_p_db
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbcellmap : vx_data_db.Type_dbcellmap? = null

    override fun dbcellmap() : vx_data_db.Type_dbcellmap {
      var output : vx_data_db.Type_dbcellmap = vx_data_db.e_dbcellmap
      var testnull : vx_data_db.Type_dbcellmap? = vx_p_dbcellmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_dbfieldmap : vx_data_db.Type_dbfieldmap? = null

    override fun dbfieldmap() : vx_data_db.Type_dbfieldmap {
      var output : vx_data_db.Type_dbfieldmap = vx_data_db.e_dbfieldmap
      var testnull : vx_data_db.Type_dbfieldmap? = vx_p_dbfieldmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbtableid")) {
        output = this.dbtableid()
      } else if ((skey==":db")) {
        output = this.db()
      } else if ((skey==":dbcellmap")) {
        output = this.dbcellmap()
      } else if ((skey==":dbfieldmap")) {
        output = this.dbfieldmap()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbtableid", this.dbtableid())
      map.put(":db", this.db())
      map.put(":dbcellmap", this.dbcellmap())
      map.put(":dbfieldmap", this.dbfieldmap())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbtable = vx_core.vx_copy(vx_data_db.e_dbtable, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbtable = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbtable = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbtableid : vx_core.Type_string = value.dbtableid()
      var vx_p_db : vx_data_db.Type_db = value.db()
      var vx_p_dbcellmap : vx_data_db.Type_dbcellmap = value.dbcellmap()
      var vx_p_dbfieldmap : vx_data_db.Type_dbfieldmap = value.dbfieldmap()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbtableid")
      validkeys.add(":db")
      validkeys.add(":dbcellmap")
      validkeys.add(":dbfieldmap")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbtableid")) {
            if (valsub == vx_p_dbtableid) {
            } else if (valsub is vx_core.Type_string) {
              var valdbtableid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_dbtableid = valdbtableid
            } else if (valsub is String) {
              ischanged = true
              vx_p_dbtableid = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbtableid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":db")) {
            if (valsub == vx_p_db) {
            } else if (valsub is vx_data_db.Type_db) {
              var valdb : vx_data_db.Type_db = valsub as vx_data_db.Type_db
              ischanged = true
              vx_p_db = valdb
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("db"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbcellmap")) {
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub is vx_data_db.Type_dbcellmap) {
              var valdbcellmap : vx_data_db.Type_dbcellmap = valsub as vx_data_db.Type_dbcellmap
              ischanged = true
              vx_p_dbcellmap = valdbcellmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbcellmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":dbfieldmap")) {
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub is vx_data_db.Type_dbfieldmap) {
              var valdbfieldmap : vx_data_db.Type_dbfieldmap = valsub as vx_data_db.Type_dbfieldmap
              ischanged = true
              vx_p_dbfieldmap = valdbfieldmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbfieldmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbtable = vx_data_db.Class_dbtable()
        work.vx_p_dbtableid = vx_p_dbtableid
        work.vx_p_db = vx_p_db
        work.vx_p_dbcellmap = vx_p_dbcellmap
        work.vx_p_dbfieldmap = vx_p_dbfieldmap
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbtable
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbtable
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbtable", // name
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

  val e_dbtable : vx_data_db.Type_dbtable = vx_data_db.Class_dbtable()
  val t_dbtable : vx_data_db.Type_dbtable = vx_data_db.Class_dbtable()

  interface Type_dbvalue : vx_core.Type_struct {
    fun dbid() : vx_data_db.Type_dbid
    fun fromid() : vx_data_db.Type_dbid
    fun toid() : vx_data_db.Type_dbid
    fun noteid() : vx_data_db.Type_dbid
    fun valid() : vx_data_db.Type_dbid
    fun valtext() : vx_core.Type_string
  }

  class Class_dbvalue : vx_core.Class_base, Type_dbvalue {
    constructor() {}

    var vx_p_dbid : vx_data_db.Type_dbid? = null

    override fun dbid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_dbid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fromid : vx_data_db.Type_dbid? = null

    override fun fromid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_fromid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_toid : vx_data_db.Type_dbid? = null

    override fun toid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_toid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_noteid : vx_data_db.Type_dbid? = null

    override fun noteid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_noteid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_valid : vx_data_db.Type_dbid? = null

    override fun valid() : vx_data_db.Type_dbid {
      var output : vx_data_db.Type_dbid = vx_data_db.e_dbid
      var testnull : vx_data_db.Type_dbid? = vx_p_valid
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_valtext : vx_core.Type_string? = null

    override fun valtext() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_valtext
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid()
      } else if ((skey==":fromid")) {
        output = this.fromid()
      } else if ((skey==":toid")) {
        output = this.toid()
      } else if ((skey==":noteid")) {
        output = this.noteid()
      } else if ((skey==":valid")) {
        output = this.valid()
      } else if ((skey==":valtext")) {
        output = this.valtext()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":dbid", this.dbid())
      map.put(":fromid", this.fromid())
      map.put(":toid", this.toid())
      map.put(":noteid", this.noteid())
      map.put(":valid", this.valid())
      map.put(":valtext", this.valtext())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbvalue = vx_core.vx_copy(vx_data_db.e_dbvalue, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_db.Type_dbvalue = this
      var ischanged : Boolean = false
      var value : vx_data_db.Class_dbvalue = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_dbid : vx_data_db.Type_dbid = value.dbid()
      var vx_p_fromid : vx_data_db.Type_dbid = value.fromid()
      var vx_p_toid : vx_data_db.Type_dbid = value.toid()
      var vx_p_noteid : vx_data_db.Type_dbid = value.noteid()
      var vx_p_valid : vx_data_db.Type_dbid = value.valid()
      var vx_p_valtext : vx_core.Type_string = value.valtext()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":dbid")
      validkeys.add(":fromid")
      validkeys.add(":toid")
      validkeys.add(":noteid")
      validkeys.add(":valid")
      validkeys.add(":valtext")
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
            msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":dbid")) {
            if (valsub == vx_p_dbid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valdbid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_dbid = valdbid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("dbid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fromid")) {
            if (valsub == vx_p_fromid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valfromid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_fromid = valfromid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fromid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":toid")) {
            if (valsub == vx_p_toid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valtoid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_toid = valtoid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("toid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":noteid")) {
            if (valsub == vx_p_noteid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valnoteid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_noteid = valnoteid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("noteid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":valid")) {
            if (valsub == vx_p_valid) {
            } else if (valsub is vx_data_db.Type_dbid) {
              var valvalid : vx_data_db.Type_dbid = valsub as vx_data_db.Type_dbid
              ischanged = true
              vx_p_valid = valvalid
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("valid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":valtext")) {
            if (valsub == vx_p_valtext) {
            } else if (valsub is vx_core.Type_string) {
              var valvaltext : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_valtext = valvaltext
            } else if (valsub is String) {
              ischanged = true
              vx_p_valtext = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("valtext"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_db.Class_dbvalue = vx_data_db.Class_dbvalue()
        work.vx_p_dbid = vx_p_dbid
        work.vx_p_fromid = vx_p_fromid
        work.vx_p_toid = vx_p_toid
        work.vx_p_noteid = vx_p_noteid
        work.vx_p_valid = vx_p_valid
        work.vx_p_valtext = vx_p_valtext
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.e_dbvalue
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_db.t_dbvalue
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/db", // pkgname
        "dbvalue", // name
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

  val e_dbvalue : vx_data_db.Type_dbvalue = vx_data_db.Class_dbvalue()
  val t_dbvalue : vx_data_db.Type_dbvalue = vx_data_db.Class_dbvalue()

  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("db", vx_data_db.t_db)
    maptype.put("dbcell", vx_data_db.t_dbcell)
    maptype.put("dbcellmap", vx_data_db.t_dbcellmap)
    maptype.put("dbfield", vx_data_db.t_dbfield)
    maptype.put("dbfieldmap", vx_data_db.t_dbfieldmap)
    maptype.put("dbid", vx_data_db.t_dbid)
    maptype.put("dblink", vx_data_db.t_dblink)
    maptype.put("dblinklist", vx_data_db.t_dblinklist)
    maptype.put("dbnode", vx_data_db.t_dbnode)
    maptype.put("dbnote", vx_data_db.t_dbnote)
    maptype.put("dbtable", vx_data_db.t_dbtable)
    maptype.put("dbvalue", vx_data_db.t_dbvalue)
    vx_core.vx_global_package_set("vx/data/db", maptype, mapconst, mapfunc)
  }

}
