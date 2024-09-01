package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_xml {


  interface Type_xml : vx_core.Type_struct {
    fun tag() : vx_core.Type_string
    fun text() : vx_core.Type_string
    fun prop() : vx_core.Type_string
    fun propmap() : vx_core.Type_stringmap
    fun children() : vx_data_xml.Type_xmllist
    fun parent() : vx_data_xml.Type_xml
  }

  class Class_xml : vx_core.Class_base, Type_xml {
    constructor() {}

    var vx_p_tag : vx_core.Type_string? = null

    override fun tag() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_tag
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

    var vx_p_prop : vx_core.Type_string? = null

    override fun prop() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_prop
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_propmap : vx_core.Type_stringmap? = null

    override fun propmap() : vx_core.Type_stringmap {
      var output : vx_core.Type_stringmap = vx_core.e_stringmap
      var testnull : vx_core.Type_stringmap? = vx_p_propmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_children : vx_data_xml.Type_xmllist? = null

    override fun children() : vx_data_xml.Type_xmllist {
      var output : vx_data_xml.Type_xmllist = vx_data_xml.e_xmllist
      var testnull : vx_data_xml.Type_xmllist? = vx_p_children
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_parent : vx_data_xml.Type_xml? = null

    override fun parent() : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
      var testnull : vx_data_xml.Type_xml? = vx_p_parent
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":tag")) {
        output = this.tag()
      } else if ((skey==":text")) {
        output = this.text()
      } else if ((skey==":prop")) {
        output = this.prop()
      } else if ((skey==":propmap")) {
        output = this.propmap()
      } else if ((skey==":children")) {
        output = this.children()
      } else if ((skey==":parent")) {
        output = this.parent()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":tag", this.tag())
      map.put(":text", this.text())
      map.put(":prop", this.prop())
      map.put(":propmap", this.propmap())
      map.put(":children", this.children())
      map.put(":parent", this.parent())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_xml.Type_xml = vx_core.vx_copy(vx_data_xml.e_xml, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_xml.Type_xml = this
      var ischanged : Boolean = false
      var value : vx_data_xml.Class_xml = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_tag : vx_core.Type_string = value.tag()
      var vx_p_text : vx_core.Type_string = value.text()
      var vx_p_prop : vx_core.Type_string = value.prop()
      var vx_p_propmap : vx_core.Type_stringmap = value.propmap()
      var vx_p_children : vx_data_xml.Type_xmllist = value.children()
      var vx_p_parent : vx_data_xml.Type_xml = value.parent()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":tag")
      validkeys.add(":text")
      validkeys.add(":prop")
      validkeys.add(":propmap")
      validkeys.add(":children")
      validkeys.add(":parent")
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
            msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":tag")) {
            if (valsub == vx_p_tag) {
            } else if (valsub is vx_core.Type_string) {
              var valtag : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_tag = valtag
            } else if (valsub is String) {
              ischanged = true
              vx_p_tag = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("tag"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":prop")) {
            if (valsub == vx_p_prop) {
            } else if (valsub is vx_core.Type_string) {
              var valprop : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_prop = valprop
            } else if (valsub is String) {
              ischanged = true
              vx_p_prop = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("prop"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":propmap")) {
            if (valsub == vx_p_propmap) {
            } else if (valsub is vx_core.Type_stringmap) {
              var valpropmap : vx_core.Type_stringmap = valsub as vx_core.Type_stringmap
              ischanged = true
              vx_p_propmap = valpropmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("propmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":children")) {
            if (valsub == vx_p_children) {
            } else if (valsub is vx_data_xml.Type_xmllist) {
              var valchildren : vx_data_xml.Type_xmllist = valsub as vx_data_xml.Type_xmllist
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
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":parent")) {
            if (valsub == vx_p_parent) {
            } else if (valsub is vx_data_xml.Type_xml) {
              var valparent : vx_data_xml.Type_xml = valsub as vx_data_xml.Type_xml
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
              msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/xml/xml", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_xml.Class_xml = vx_data_xml.Class_xml()
        work.vx_p_tag = vx_p_tag
        work.vx_p_text = vx_p_text
        work.vx_p_prop = vx_p_prop
        work.vx_p_propmap = vx_p_propmap
        work.vx_p_children = vx_p_children
        work.vx_p_parent = vx_p_parent
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.e_xml
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/xml", // pkgname
        "xml", // name
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

  val e_xml : vx_data_xml.Type_xml = vx_data_xml.Class_xml()
  val t_xml : vx_data_xml.Type_xml = vx_data_xml.Class_xml()

  interface Type_xmllist : vx_core.Type_list {
    fun vx_listxml() : List<vx_data_xml.Type_xml>
    fun vx_xml(index : vx_core.Type_int) : vx_data_xml.Type_xml
  }

  class Class_xmllist : vx_core.Class_base, Type_xmllist {
    constructor() {}

    var vx_p_list : List<vx_data_xml.Type_xml> = vx_core.immutablelist(
      ArrayList<vx_data_xml.Type_xml>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_xml(index : vx_core.Type_int) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
      var list : vx_data_xml.Class_xmllist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_xml.Type_xml> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listxml() : List<vx_data_xml.Type_xml> {
      var output : List<vx_data_xml.Type_xml> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_xml.Type_xml = this.vx_xml(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_xml.Type_xmllist = vx_core.vx_copy(vx_data_xml.e_xmllist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_xml.Type_xmllist = this
      var ischanged : Boolean = false
      var value : vx_data_xml.Class_xmllist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_xml.Type_xml> = ArrayList<vx_data_xml.Type_xml>(value.vx_listxml())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_xml.Type_xmllist) {
          var multi : vx_data_xml.Type_xmllist = valsub as vx_data_xml.Type_xmllist
          ischanged = true
          listval.addAll(multi.vx_listxml())
        } else if (valsub is vx_data_xml.Type_xml) {
          var allowsub : vx_data_xml.Type_xml = valsub as vx_data_xml.Type_xml
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_xml.Type_xml) {
          ischanged = true
          listval.add(valsub as vx_data_xml.Type_xml)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_xml.Type_xml) {
              var valitem : vx_data_xml.Type_xml = item as vx_data_xml.Type_xml
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/xml/xmllist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/xml/xmllist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_xml.Class_xmllist = vx_data_xml.Class_xmllist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.e_xmllist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xmllist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/xml", // pkgname
        "xmllist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_xml.t_xml), // allowtypes
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

  val e_xmllist : vx_data_xml.Type_xmllist = vx_data_xml.Class_xmllist()
  val t_xmllist : vx_data_xml.Type_xmllist = vx_data_xml.Class_xmllist()

  interface Type_xmlpropmap : vx_core.Type_map {
    fun vx_mapstring() : Map<String, vx_core.Type_string>
    fun vx_string(key : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_xmlpropmap : vx_core.Class_base, Type_xmlpropmap {
    constructor() {}

    var vx_p_map : Map<String, vx_core.Type_string> = vx_core.immutablemap(LinkedHashMap<String, vx_core.Type_string>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_core.Type_string) {
        var castval : vx_core.Type_string = value as vx_core.Type_string
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_core.Type_string> = LinkedHashMap<String, vx_core.Type_string>(this.vx_p_map)
        if (castval == vx_core.e_string) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_string(key : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var map : vx_data_xml.Class_xmlpropmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_core.Type_string> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_core.e_string)
      return output
    }

    override fun vx_mapstring() : Map<String, vx_core.Type_string> {
      var output : Map<String, vx_core.Type_string> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_string(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_data_xml.Class_xmlpropmap = vx_data_xml.Class_xmlpropmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_core.Type_string> = LinkedHashMap<String, vx_core.Type_string>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_core.Type_string) {
          var castval : vx_core.Type_string = value as vx_core.Type_string
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":invalidvalue", value)
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
      var output : vx_data_xml.Type_xmlpropmap = vx_core.vx_copy(vx_data_xml.e_xmlpropmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_xml.Type_xmlpropmap = this
      var ischanged : Boolean = false
      var value : vx_data_xml.Class_xmlpropmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_core.Type_string> = LinkedHashMap<String, vx_core.Type_string>(value.vx_mapstring())
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
            msg = vx_core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_core.Type_string = vx_core.e_string
          if (false) {
          } else if (valsub is vx_core.Type_string) {
            var valallowed : vx_core.Type_string = valsub as vx_core.Type_string
            valany = valallowed
          } else if (valsub is String) {
            valany = vx_core.vx_new(vx_core.t_string, valsub)
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
            msg = vx_core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_data_xml.Class_xmlpropmap = vx_data_xml.Class_xmlpropmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.e_xmlpropmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xmlpropmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/xml", // pkgname
        "xmlpropmap", // name
        ":map", // extends
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

  val e_xmlpropmap : vx_data_xml.Type_xmlpropmap = vx_data_xml.Class_xmlpropmap()
  val t_xmlpropmap : vx_data_xml.Type_xmlpropmap = vx_data_xml.Class_xmlpropmap()

  class Const_delimxml {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxml", // name
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
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_data_xml.c_delimxmlcomment,
              vx_data_xml.c_delimxmlcdata,
              vx_core.f_copy(
                vx_data_textblock.c_delimbracketangle,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":delimlist"),
                  vx_core.f_new(
                    vx_data_textblock.t_delimlist,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_data_xml.c_delimxmlequal,
                      vx_data_textblock.c_delimwhitespace,
                      vx_data_textblock.c_delimquote
                    )
                  )
                )
              )
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

  val c_delimxml : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimxmlcdata {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcdata", // name
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
          vx_core.vx_new_string("delimxmlcomment"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("<![CDATA["),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("]]>")
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

  val c_delimxmlcdata : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimxmlcomment {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcomment", // name
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
          vx_core.vx_new_string("delimxmlcomment"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("<!--"),
          vx_core.vx_new_string(":endtext"),
          vx_core.vx_new_string("-->")
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

  val c_delimxmlcomment : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  class Const_delimxmlequal {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlequal", // name
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
          vx_core.vx_new_string("delimxmlequal"),
          vx_core.vx_new_string(":starttext"),
          vx_core.vx_new_string("=")
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

  val c_delimxmlequal : vx_data_textblock.Type_delim = vx_data_textblock.Class_delim()


  interface Func_string_decodexml_from_string : vx_core.Func_any_from_any {
    fun vx_string_decodexml_from_string(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_decodexml_from_string : vx_core.Class_base, Func_string_decodexml_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_string_decodexml_from_string = vx_data_xml.Class_string_decodexml_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_string_decodexml_from_string = vx_data_xml.Class_string_decodexml_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "string-decodexml<-string", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_string_decodexml_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_string_decodexml_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_xml.f_string_decodexml_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_string_decodexml_from_string(text)
      return output
    }

    override fun vx_string_decodexml_from_string(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_xml.f_string_decodexml_from_string(text)
      return output
    }

  }

  val e_string_decodexml_from_string : vx_data_xml.Func_string_decodexml_from_string = vx_data_xml.Class_string_decodexml_from_string()
  val t_string_decodexml_from_string : vx_data_xml.Func_string_decodexml_from_string = vx_data_xml.Class_string_decodexml_from_string()

  fun f_string_decodexml_from_string(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var lt : vx_core.Type_string = vx_core.f_string_from_string_find_replace(
          text,
          vx_core.vx_new_string("&lt;"),
          vx_core.vx_new_string("<")
        )
        var gt : vx_core.Type_string = vx_core.f_string_from_string_find_replace(
          text,
          vx_core.vx_new_string("&gt;"),
          vx_core.vx_new_string(">")
        )
        var amp : vx_core.Type_string = vx_core.f_string_from_string_find_replace(
          gt,
          vx_core.vx_new_string("&amp;"),
          vx_core.vx_new_string("&")
        )
        var result : vx_core.Type_string = vx_core.f_string_from_string_find_replace(
          text,
          vx_core.c_quote,
          vx_core.vx_new_string("\\\"")
        )
        var output_1 : vx_core.Type_any = result
        output_1
      })
    )
    return output
  }


  interface Func_string_first_from_xml : vx_core.Func_any_from_any {
    fun vx_string_first_from_xml(xml : vx_data_xml.Type_xml) : vx_core.Type_string
  }

  class Class_string_first_from_xml : vx_core.Class_base, Func_string_first_from_xml {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_string_first_from_xml = vx_data_xml.Class_string_first_from_xml()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_string_first_from_xml = vx_data_xml.Class_string_first_from_xml()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "string-first<-xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_string_first_from_xml
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_string_first_from_xml
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_xml.Type_xml = value as vx_data_xml.Type_xml
      var outputval : vx_core.Type_any = vx_data_xml.f_string_first_from_xml(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xml : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_string_first_from_xml(xml)
      return output
    }

    override fun vx_string_first_from_xml(xml : vx_data_xml.Type_xml) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_xml.f_string_first_from_xml(xml)
      return output
    }

  }

  val e_string_first_from_xml : vx_data_xml.Func_string_first_from_xml = vx_data_xml.Class_string_first_from_xml()
  val t_string_first_from_xml : vx_data_xml.Func_string_first_from_xml = vx_data_xml.Class_string_first_from_xml()

  fun f_string_first_from_xml(xml : vx_data_xml.Type_xml) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var children : vx_data_xml.Type_xmllist = xml.children()
        var first : vx_data_xml.Type_xml = vx_core.f_any_from_list(
          vx_data_xml.t_xml,
          children,
          vx_core.vx_new_int(1)
        )
        var text : vx_core.Type_string = first.text()
        var decode : vx_core.Type_string = vx_data_xml.f_string_decodexml_from_string(
          text
        )
        var outdent : vx_core.Type_string = vx_type.f_string_outdent(
          decode
        )
        var trim : vx_core.Type_string = vx_type.f_string_trim(
          outdent
        )
        var output_1 : vx_core.Type_any = trim
        output_1
      })
    )
    return output
  }


  interface Func_textblock_xml_from_string : vx_core.Func_any_from_any {
    fun vx_textblock_xml_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_xml_from_string : vx_core.Class_base, Func_textblock_xml_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_textblock_xml_from_string = vx_data_xml.Class_textblock_xml_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_textblock_xml_from_string = vx_data_xml.Class_textblock_xml_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "textblock-xml<-string", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_textblock_xml_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_textblock_xml_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_xml.f_textblock_xml_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_textblock_xml_from_string(text)
      return output
    }

    override fun vx_textblock_xml_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_data_xml.f_textblock_xml_from_string(text)
      return output
    }

  }

  val e_textblock_xml_from_string : vx_data_xml.Func_textblock_xml_from_string = vx_data_xml.Class_textblock_xml_from_string()
  val t_textblock_xml_from_string : vx_data_xml.Func_textblock_xml_from_string = vx_data_xml.Class_textblock_xml_from_string()

  fun f_textblock_xml_from_string(text : vx_core.Type_string) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      text,
      vx_data_xml.c_delimxml
    )
    return output
  }


  interface Func_xml_angle_from_xml_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_angle_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_angle_from_xml_textblock : vx_core.Class_base, Func_xml_angle_from_xml_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_angle_from_xml_textblock = vx_data_xml.Class_xml_angle_from_xml_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_angle_from_xml_textblock = vx_data_xml.Class_xml_angle_from_xml_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-angle<-xml-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_angle_from_xml_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_angle_from_xml_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var tb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_angle_from_xml_textblock(xmlarg, tb)
      return output
    }

    override fun vx_xml_angle_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_angle_from_xml_textblock(xmlarg, tb)
      return output
    }

  }

  val e_xml_angle_from_xml_textblock : vx_data_xml.Func_xml_angle_from_xml_textblock = vx_data_xml.Class_xml_angle_from_xml_textblock()
  val t_xml_angle_from_xml_textblock : vx_data_xml.Func_xml_angle_from_xml_textblock = vx_data_xml.Class_xml_angle_from_xml_textblock()

  fun f_xml_angle_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_if_2(
      vx_data_xml.t_xml,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_eq(
              tb.text(),
              vx_core.f_new(
                vx_core.t_string,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string("</"),
                  xmlarg.tag(),
                  vx_core.vx_new_string(">")
                )
              )
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_data_xml.f_xml_close_from_xml_textblock(
              xmlarg,
              tb
            )
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_data_xml.t_xml,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var children : vx_data_textblock.Type_textblocklist = tb.children()
                var xmlchg : vx_data_xml.Type_xml = vx_core.f_new(
                  vx_data_xml.t_xml,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":tag"),
                    vx_core.vx_new_string(":notag"),
                    vx_core.vx_new_string(":parent"),
                    xmlarg
                  )
                )
                var output_4 : vx_core.Type_any = vx_data_xml.f_xml_properties_from_xml_textblocklist(
                  xmlchg,
                  children
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


  interface Func_xml_close_from_xml_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_close_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_close_from_xml_textblock : vx_core.Class_base, Func_xml_close_from_xml_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_close_from_xml_textblock = vx_data_xml.Class_xml_close_from_xml_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_close_from_xml_textblock = vx_data_xml.Class_xml_close_from_xml_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-close<-xml-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_close_from_xml_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_close_from_xml_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var tb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_close_from_xml_textblock(xmlarg, tb)
      return output
    }

    override fun vx_xml_close_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_close_from_xml_textblock(xmlarg, tb)
      return output
    }

  }

  val e_xml_close_from_xml_textblock : vx_data_xml.Func_xml_close_from_xml_textblock = vx_data_xml.Class_xml_close_from_xml_textblock()
  val t_xml_close_from_xml_textblock : vx_data_xml.Func_xml_close_from_xml_textblock = vx_data_xml.Class_xml_close_from_xml_textblock()

  fun f_xml_close_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var tag : vx_core.Type_string = xmlarg.tag()
        var text : vx_core.Type_string = tb.text()
        var parent : vx_data_xml.Type_xml = xmlarg.parent()
        var isnoparent : vx_core.Type_boolean = vx_core.f_is_empty_1(
          parent
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_xml.t_xml,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_or(
                  vx_core.f_eq(
                    vx_core.vx_new_string("/"),
                    text
                  ),
                  vx_core.f_eq(
                    text,
                    vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("</"),
                        tag,
                        vx_core.vx_new_string(">")
                      )
                    )
                  )
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_if_2(
                  vx_data_xml.t_xml,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = isnoparent
                        output_4
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = xmlarg
                        output_5
                      })
                    ),
                    vx_core.f_else(
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_6 : vx_core.Type_any = vx_core.f_copy(
                          parent,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":children"),
                            vx_core.f_new(
                              vx_data_xml.t_xmllist,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                parent.children(),
                                vx_core.f_copy(
                                  xmlarg,
                                  vx_core.vx_new(
                                    vx_core.t_anylist,
                                    vx_core.vx_new_string(":parent"),
                                    vx_core.f_empty(
                                      vx_data_xml.t_xml
                                    )
                                  )
                                )
                              )
                            )
                          )
                        )
                        output_6
                      })
                    )
                  )
                )
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_core.f_copy(
                  xmlarg,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.f_msg_from_error_1(
                      vx_core.vx_new_string(":invalidxmlclosetag"),
                      vx_core.f_new(
                        vx_core.t_anymap,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":tag"),
                          text,
                          vx_core.vx_new_string(":startpos"),
                          tb.startpos(),
                          vx_core.vx_new_string(":endpos"),
                          tb.endpos(),
                          vx_core.vx_new_string(":line"),
                          tb.line(),
                          vx_core.vx_new_string(":column"),
                          tb.column()
                        )
                      )
                    )
                  )
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


  interface Func_xml_parse_from_xml_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_parse_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_parse_from_xml_textblock : vx_core.Class_base, Func_xml_parse_from_xml_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_parse_from_xml_textblock = vx_data_xml.Class_xml_parse_from_xml_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_parse_from_xml_textblock = vx_data_xml.Class_xml_parse_from_xml_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_parse_from_xml_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_parse_from_xml_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var tb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_parse_from_xml_textblock(xmlarg, tb)
      return output
    }

    override fun vx_xml_parse_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_parse_from_xml_textblock(xmlarg, tb)
      return output
    }

  }

  val e_xml_parse_from_xml_textblock : vx_data_xml.Func_xml_parse_from_xml_textblock = vx_data_xml.Class_xml_parse_from_xml_textblock()
  val t_xml_parse_from_xml_textblock : vx_data_xml.Func_xml_parse_from_xml_textblock = vx_data_xml.Class_xml_parse_from_xml_textblock()

  fun f_xml_parse_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var delim : vx_data_textblock.Type_delim = tb.delim()
        var text : vx_core.Type_string = tb.text()
        var starttext : vx_core.Type_string = delim.starttext()
        var output_1 : vx_core.Type_any = vx_core.f_switch(
          vx_data_xml.t_xml,
          starttext,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(""),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_data_xml.f_xml_text_from_xml_textblock(
                  xmlarg,
                  tb
                )
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_data_textblock.c_delimbracketangle.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_data_xml.f_xml_angle_from_xml_textblock(
                  xmlarg,
                  tb
                )
                output_3
              })
            ),
            vx_core.f_case_1(
              vx_data_textblock.c_delimwhitespace.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = xmlarg
                output_4
              })
            ),
            vx_core.f_case_1(
              vx_data_xml.c_delimxmlcomment.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = xmlarg
                output_5
              })
            ),
            vx_core.f_case_1(
              vx_data_xml.c_delimxmlcdata.starttext(),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = xmlarg
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


  interface Func_xml_parse_from_xml_textblocklist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_parse_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml
  }

  class Class_xml_parse_from_xml_textblocklist : vx_core.Class_base, Func_xml_parse_from_xml_textblocklist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_parse_from_xml_textblocklist = vx_data_xml.Class_xml_parse_from_xml_textblocklist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_parse_from_xml_textblocklist = vx_data_xml.Class_xml_parse_from_xml_textblocklist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblocklist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_parse_from_xml_textblocklist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_parse_from_xml_textblocklist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblocklist : vx_data_textblock.Type_textblocklist = vx_core.f_any_from_any(vx_data_textblock.t_textblocklist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist)
      return output
    }

    override fun vx_xml_parse_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist)
      return output
    }

  }

  val e_xml_parse_from_xml_textblocklist : vx_data_xml.Func_xml_parse_from_xml_textblocklist = vx_data_xml.Class_xml_parse_from_xml_textblocklist()
  val t_xml_parse_from_xml_textblocklist : vx_data_xml.Func_xml_parse_from_xml_textblocklist = vx_data_xml.Class_xml_parse_from_xml_textblocklist()

  fun f_xml_parse_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_any_from_list_start_reduce(
      vx_data_xml.t_xml,
      textblocklist,
      xmlarg,
      vx_core.t_any_from_reduce.vx_fn_new({xmlarg_lmb_any : vx_core.Type_any, tb_lmb_any : vx_core.Type_any ->
        val xmlarg_lmb : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, xmlarg_lmb_any)
        val tb_lmb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, tb_lmb_any)
        var output_1 : vx_core.Type_any = vx_data_xml.f_xml_parse_from_xml_textblock(xmlarg_lmb, tb_lmb)
        output_1
      })
    )
    return output
  }


  interface Func_xml_properties_from_xml_textblocklist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_properties_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml
  }

  class Class_xml_properties_from_xml_textblocklist : vx_core.Class_base, Func_xml_properties_from_xml_textblocklist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_properties_from_xml_textblocklist = vx_data_xml.Class_xml_properties_from_xml_textblocklist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_properties_from_xml_textblocklist = vx_data_xml.Class_xml_properties_from_xml_textblocklist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-properties<-xml-textblocklist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_properties_from_xml_textblocklist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_properties_from_xml_textblocklist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var textblocklist : vx_data_textblock.Type_textblocklist = vx_core.f_any_from_any(vx_data_textblock.t_textblocklist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist)
      return output
    }

    override fun vx_xml_properties_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist)
      return output
    }

  }

  val e_xml_properties_from_xml_textblocklist : vx_data_xml.Func_xml_properties_from_xml_textblocklist = vx_data_xml.Class_xml_properties_from_xml_textblocklist()
  val t_xml_properties_from_xml_textblocklist : vx_data_xml.Func_xml_properties_from_xml_textblocklist = vx_data_xml.Class_xml_properties_from_xml_textblocklist()

  fun f_xml_properties_from_xml_textblocklist(xmlarg : vx_data_xml.Type_xml, textblocklist : vx_data_textblock.Type_textblocklist) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var xmlchg : vx_data_xml.Type_xml = vx_core.f_any_from_list_start_reduce(
          vx_data_xml.t_xml,
          textblocklist,
          xmlarg,
          vx_core.t_any_from_reduce.vx_fn_new({reduce_any : vx_core.Type_any, current_any : vx_core.Type_any ->
            var reduce : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, reduce_any)
            var current : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, current_any)
            var output_2 : vx_core.Type_any = vx_data_xml.f_xml_property_from_xml_textblock(
              reduce,
              current
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = xmlchg
        output_1
      })
    )
    return output
  }


  interface Func_xml_property_from_xml_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_property_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tbarg : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_property_from_xml_textblock : vx_core.Class_base, Func_xml_property_from_xml_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_property_from_xml_textblock = vx_data_xml.Class_xml_property_from_xml_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_property_from_xml_textblock = vx_data_xml.Class_xml_property_from_xml_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-property<-xml-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_property_from_xml_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_property_from_xml_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var tbarg : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_property_from_xml_textblock(xmlarg, tbarg)
      return output
    }

    override fun vx_xml_property_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tbarg : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_property_from_xml_textblock(xmlarg, tbarg)
      return output
    }

  }

  val e_xml_property_from_xml_textblock : vx_data_xml.Func_xml_property_from_xml_textblock = vx_data_xml.Class_xml_property_from_xml_textblock()
  val t_xml_property_from_xml_textblock : vx_data_xml.Func_xml_property_from_xml_textblock = vx_data_xml.Class_xml_property_from_xml_textblock()

  fun f_xml_property_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tbarg : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var delim : vx_data_textblock.Type_delim = tbarg.delim()
        var text : vx_core.Type_string = tbarg.text()
        var delimname : vx_core.Type_string = delim.name()
        var tag : vx_core.Type_string = xmlarg.tag()
        var prop : vx_core.Type_string = xmlarg.prop()
        var propmap : vx_core.Type_stringmap = xmlarg.propmap()
        var output_1 : vx_core.Type_any = vx_core.f_switch(
          vx_data_xml.t_xml,
          delimname,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_case_1(
              vx_core.vx_new_string(""),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_if_2(
                  vx_data_xml.t_xml,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_3 : vx_core.Type_any = vx_type.f_boolean_from_string_starts(
                          text,
                          vx_core.vx_new_string("/")
                        )
                        output_3
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = vx_data_xml.f_xml_close_from_xml_textblock(
                          xmlarg,
                          tbarg
                        )
                        output_4
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_eq(
                          vx_core.vx_new_string(":notag"),
                          tag
                        )
                        output_5
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_6 : vx_core.Type_any = vx_core.f_copy(
                          xmlarg,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":tag"),
                            text
                          )
                        )
                        output_6
                      })
                    ),
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_7 : vx_core.Type_any = vx_core.f_eq(
                          vx_core.vx_new_string(""),
                          prop
                        )
                        output_7
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_8 : vx_core.Type_any = vx_core.f_copy(
                          xmlarg,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":prop"),
                            text
                          )
                        )
                        output_8
                      })
                    )
                  )
                )
                output_2
              })
            ),
            vx_core.f_case_1(
              vx_core.vx_new_string("delimquote"),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_9 : vx_core.Type_any = vx_core.f_if_1(
                  vx_data_xml.t_xml,
                  vx_core.f_eq(
                    vx_core.vx_new_string(""),
                    prop
                  ),
                  vx_core.f_copy(
                    xmlarg,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.f_msg_from_error(
                        vx_core.vx_new_string("Found quoted text with no matching attribute.")
                      )
                    )
                  ),
                  vx_core.f_copy(
                    xmlarg,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":prop"),
                      vx_core.vx_new_string(""),
                      vx_core.vx_new_string(":propmap"),
                      vx_core.f_copy(
                        propmap,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          prop,
                          vx_core.f_any_from_list(
                            vx_data_textblock.t_textblock,
                            tbarg.children(),
                            vx_core.vx_new_int(1)
                          ).text()
                        )
                      )
                    )
                  )
                )
                output_9
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_10 : vx_core.Type_any = xmlarg
                output_10
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_xml_read_from_file : vx_core.Func_any_from_any_context {
    fun vx_xml_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_xml.Type_xml
  }

  class Class_xml_read_from_file : vx_core.Class_base, Func_xml_read_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_read_from_file = vx_data_xml.Class_xml_read_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_read_from_file = vx_data_xml.Class_xml_read_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-read<-file", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_read_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_read_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_xml.f_xml_read_from_file(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_xml_read_from_file(context, file)
      return output
    }

    override fun vx_xml_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_read_from_file(context, file)
      return output
    }

  }

  val e_xml_read_from_file : vx_data_xml.Func_xml_read_from_file = vx_data_xml.Class_xml_read_from_file()
  val t_xml_read_from_file : vx_data_xml.Func_xml_read_from_file = vx_data_xml.Class_xml_read_from_file()

  fun f_xml_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var loaded : vx_data_file.Type_file = vx_data_file.f_file_read_from_file(
          context,
          file
        )
        var output_1 : vx_core.Type_any = vx_data_xml.f_xml_from_file(
          loaded
        )
        output_1
      })
    )
    return output
  }


  interface Func_xml_text_from_xml_textblock : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_xml_text_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_text_from_xml_textblock : vx_core.Class_base, Func_xml_text_from_xml_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_text_from_xml_textblock = vx_data_xml.Class_xml_text_from_xml_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_text_from_xml_textblock = vx_data_xml.Class_xml_text_from_xml_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-text<-xml-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_text_from_xml_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_text_from_xml_textblock
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var xmlarg : vx_data_xml.Type_xml = vx_core.f_any_from_any(vx_data_xml.t_xml, arglist.vx_any(vx_core.vx_new_int(0)))
      var tb : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_xml.f_xml_text_from_xml_textblock(xmlarg, tb)
      return output
    }

    override fun vx_xml_text_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_text_from_xml_textblock(xmlarg, tb)
      return output
    }

  }

  val e_xml_text_from_xml_textblock : vx_data_xml.Func_xml_text_from_xml_textblock = vx_data_xml.Class_xml_text_from_xml_textblock()
  val t_xml_text_from_xml_textblock : vx_data_xml.Func_xml_text_from_xml_textblock = vx_data_xml.Class_xml_text_from_xml_textblock()

  fun f_xml_text_from_xml_textblock(xmlarg : vx_data_xml.Type_xml, tb : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = tb.text()
        var xmlchg : vx_data_xml.Type_xml = vx_core.f_new(
          vx_data_xml.t_xml,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            text
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_data_xml.t_xml,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_is_empty_1(
                  xmlarg
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = xmlchg
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_copy(
                  xmlarg,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":children"),
                    vx_core.f_new(
                      vx_data_xml.t_xmllist,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        xmlarg.children(),
                        xmlchg
                      )
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


  interface Func_xml_from_file : vx_core.Func_any_from_any {
    fun vx_xml_from_file(file : vx_data_file.Type_file) : vx_data_xml.Type_xml
  }

  class Class_xml_from_file : vx_core.Class_base, Func_xml_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_file = vx_data_xml.Class_xml_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_file = vx_data_xml.Class_xml_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-file", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_xml.f_xml_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_xml_from_file(file)
      return output
    }

    override fun vx_xml_from_file(file : vx_data_file.Type_file) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_from_file(file)
      return output
    }

  }

  val e_xml_from_file : vx_data_xml.Func_xml_from_file = vx_data_xml.Class_xml_from_file()
  val t_xml_from_file : vx_data_xml.Func_xml_from_file = vx_data_xml.Class_xml_from_file()

  fun f_xml_from_file(file : vx_data_file.Type_file) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = file.text()
        var output_1 : vx_core.Type_any = vx_data_xml.f_xml_from_string(
          text
        )
        output_1
      })
    )
    return output
  }


  interface Func_xml_from_string : vx_core.Func_any_from_any {
    fun vx_xml_from_string(text : vx_core.Type_string) : vx_data_xml.Type_xml
  }

  class Class_xml_from_string : vx_core.Class_base, Func_xml_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_string = vx_data_xml.Class_xml_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_string = vx_data_xml.Class_xml_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_xml.f_xml_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_xml_from_string(text)
      return output
    }

    override fun vx_xml_from_string(text : vx_core.Type_string) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_from_string(text)
      return output
    }

  }

  val e_xml_from_string : vx_data_xml.Func_xml_from_string = vx_data_xml.Class_xml_from_string()
  val t_xml_from_string : vx_data_xml.Func_xml_from_string = vx_data_xml.Class_xml_from_string()

  fun f_xml_from_string(text : vx_core.Type_string) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_core.f_let(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var tb : vx_data_textblock.Type_textblock = vx_data_xml.f_textblock_xml_from_string(
          text
        )
        var output_1 : vx_core.Type_any = vx_data_xml.f_xml_from_textblock(
          tb
        )
        output_1
      })
    )
    return output
  }


  interface Func_xml_from_textblock : vx_core.Func_any_from_any {
    fun vx_xml_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml
  }

  class Class_xml_from_textblock : vx_core.Class_base, Func_xml_from_textblock {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_textblock = vx_data_xml.Class_xml_from_textblock()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_xml.Class_xml_from_textblock = vx_data_xml.Class_xml_from_textblock()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      var output : vx_core.Type_any = vx_data_xml.e_xml_from_textblock
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_xml.t_xml_from_textblock
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_textblock.Type_textblock = value as vx_data_textblock.Type_textblock
      var outputval : vx_core.Type_any = vx_data_xml.f_xml_from_textblock(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var textblock : vx_data_textblock.Type_textblock = vx_core.f_any_from_any(vx_data_textblock.t_textblock, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_xml.f_xml_from_textblock(textblock)
      return output
    }

    override fun vx_xml_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
      var output : vx_data_xml.Type_xml = vx_data_xml.f_xml_from_textblock(textblock)
      return output
    }

  }

  val e_xml_from_textblock : vx_data_xml.Func_xml_from_textblock = vx_data_xml.Class_xml_from_textblock()
  val t_xml_from_textblock : vx_data_xml.Func_xml_from_textblock = vx_data_xml.Class_xml_from_textblock()

  fun f_xml_from_textblock(textblock : vx_data_textblock.Type_textblock) : vx_data_xml.Type_xml {
    var output : vx_data_xml.Type_xml = vx_data_xml.e_xml
    output = vx_data_xml.f_xml_parse_from_xml_textblocklist(
      vx_core.f_empty(
        vx_data_xml.t_xml
      ),
      textblock.children()
    )
    return output
  }


  init {
    Const_delimxml.const_new(c_delimxml)
    Const_delimxmlcdata.const_new(c_delimxmlcdata)
    Const_delimxmlcomment.const_new(c_delimxmlcomment)
    Const_delimxmlequal.const_new(c_delimxmlequal)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("xml", vx_data_xml.t_xml)
    maptype.put("xmllist", vx_data_xml.t_xmllist)
    maptype.put("xmlpropmap", vx_data_xml.t_xmlpropmap)
    mapconst.put("delimxml", vx_data_xml.c_delimxml)
    mapconst.put("delimxmlcdata", vx_data_xml.c_delimxmlcdata)
    mapconst.put("delimxmlcomment", vx_data_xml.c_delimxmlcomment)
    mapconst.put("delimxmlequal", vx_data_xml.c_delimxmlequal)
    mapfunc.put("string-decodexml<-string", vx_data_xml.t_string_decodexml_from_string)
    mapfunc.put("string-first<-xml", vx_data_xml.t_string_first_from_xml)
    mapfunc.put("textblock-xml<-string", vx_data_xml.t_textblock_xml_from_string)
    mapfunc.put("xml-angle<-xml-textblock", vx_data_xml.t_xml_angle_from_xml_textblock)
    mapfunc.put("xml-close<-xml-textblock", vx_data_xml.t_xml_close_from_xml_textblock)
    mapfunc.put("xml-parse<-xml-textblock", vx_data_xml.t_xml_parse_from_xml_textblock)
    mapfunc.put("xml-parse<-xml-textblocklist", vx_data_xml.t_xml_parse_from_xml_textblocklist)
    mapfunc.put("xml-properties<-xml-textblocklist", vx_data_xml.t_xml_properties_from_xml_textblocklist)
    mapfunc.put("xml-property<-xml-textblock", vx_data_xml.t_xml_property_from_xml_textblock)
    mapfunc.put("xml-read<-file", vx_data_xml.t_xml_read_from_file)
    mapfunc.put("xml-text<-xml-textblock", vx_data_xml.t_xml_text_from_xml_textblock)
    mapfunc.put("xml<-file", vx_data_xml.t_xml_from_file)
    mapfunc.put("xml<-string", vx_data_xml.t_xml_from_string)
    mapfunc.put("xml<-textblock", vx_data_xml.t_xml_from_textblock)
    vx_core.vx_global_package_set("vx/data/xml", maptype, mapconst, mapfunc)
  }

}
