package com.vxlisp.vx.web

import com.vxlisp.vx.*

object vx_web_html {

  fun vx_htmlstring_from_string(
    text : vx_core.Type_string) : vx_core.Type_string  {
    var str : String = text.vx_string()
    str = vx_core.vx_string_from_string_find_replace(str, "&", "&amp;")
    str = vx_core.vx_string_from_string_find_replace(str, "'", "\'")
    str = vx_core.vx_string_from_string_find_replace(str, ">", "&gt;")
    str = vx_core.vx_string_from_string_find_replace(str, "<", "&lt;")
    val output : vx_core.Type_string = vx_core.vx_new_string(str)
    return output
  }

  interface Type_body : vx_core.Type_struct {
    fun nodes() : vx_web_html.Type_divchildlist
  }

  class Class_body : vx_core.Class_base, Type_body {
    constructor() {}

    var vx_p_nodes : vx_web_html.Type_divchildlist? = null

    override fun nodes() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_nodes
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_body = vx_core.vx_copy(vx_web_html.e_body, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_body = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_body = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_nodes : vx_web_html.Type_divchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_divchildlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_divchildlist
          } else if (valsub is vx_web_html.Type_divchild) {
            var valdefault : vx_web_html.Type_divchild = valsub as vx_web_html.Type_divchild
            var vallist : vx_web_html.Type_divchildlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_divchildlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/body", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valnodes : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/body", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_body = vx_web_html.Class_body()
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_body
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_body
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "body", // name
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

  val e_body : vx_web_html.Type_body = vx_web_html.Class_body()
  val t_body : vx_web_html.Type_body = vx_web_html.Class_body()

  interface Type_details : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun summary() : vx_web_html.Type_divchildlist
    fun nodes() : vx_web_html.Type_divchildlist
  }

  class Class_details : vx_core.Class_base, Type_details {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_summary : vx_web_html.Type_divchildlist? = null

    override fun summary() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_summary
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_divchildlist? = null

    override fun nodes() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":summary")) {
        output = this.summary()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":summary", this.summary())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_details = vx_core.vx_copy(vx_web_html.e_details, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_details = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_details = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_summary : vx_web_html.Type_divchildlist = value.summary()
      var vx_p_nodes : vx_web_html.Type_divchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":summary")
      validkeys.add(":nodes")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":summary")) {
            if (valsub == vx_p_summary) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valsummary : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_summary = valsummary
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("summary"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valnodes : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_details = vx_web_html.Class_details()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_summary = vx_p_summary
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_details
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_details
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_details : vx_web_html.Type_details = vx_web_html.Class_details()
  val t_details : vx_web_html.Type_details = vx_web_html.Class_details()

  interface Type_div : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun nodes() : vx_web_html.Type_divchildlist
  }

  class Class_div : vx_core.Class_base, Type_div {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_divchildlist? = null

    override fun nodes() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_div = vx_core.vx_copy(vx_web_html.e_div, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_div = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_div = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_nodes : vx_web_html.Type_divchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_divchildlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_divchildlist
          } else if (valsub is vx_web_html.Type_divchild) {
            var valdefault : vx_web_html.Type_divchild = valsub as vx_web_html.Type_divchild
            var vallist : vx_web_html.Type_divchildlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_divchildlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valnodes : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_div = vx_web_html.Class_div()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_div
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_div
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_div : vx_web_html.Type_div = vx_web_html.Class_div()
  val t_div : vx_web_html.Type_div = vx_web_html.Class_div()

  interface Type_divchild : vx_core.Type_struct {
  }

  class Class_divchild : vx_core.Class_base, Type_divchild {
    constructor() {}

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divchild = vx_core.vx_copy(vx_web_html.e_divchild, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divchild = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_divchild = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_divchild = vx_web_html.Class_divchild()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_divchild
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_divchild
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "divchild", // name
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

  val e_divchild : vx_web_html.Type_divchild = vx_web_html.Class_divchild()
  val t_divchild : vx_web_html.Type_divchild = vx_web_html.Class_divchild()

  interface Type_divchildlist : vx_core.Type_list {
    fun vx_listdivchild() : List<vx_web_html.Type_divchild>
    fun vx_divchild(index : vx_core.Type_int) : vx_web_html.Type_divchild
  }

  class Class_divchildlist : vx_core.Class_base, Type_divchildlist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_divchild> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_divchild>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_divchild(index : vx_core.Type_int) : vx_web_html.Type_divchild {
      var output : vx_web_html.Type_divchild = vx_web_html.e_divchild
      var list : vx_web_html.Class_divchildlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_divchild> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listdivchild() : List<vx_web_html.Type_divchild> {
      var output : List<vx_web_html.Type_divchild> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_divchild = this.vx_divchild(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divchildlist = vx_core.vx_copy(vx_web_html.e_divchildlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divchildlist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_divchildlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_divchild> = ArrayList<vx_web_html.Type_divchild>(value.vx_listdivchild())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_divchildlist) {
          var multi : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
          ischanged = true
          listval.addAll(multi.vx_listdivchild())
        } else if (valsub is vx_web_html.Type_divchild) {
          var allowsub : vx_web_html.Type_divchild = valsub as vx_web_html.Type_divchild
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_divchild) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_divchild)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_divchild) {
              var valitem : vx_web_html.Type_divchild = item as vx_web_html.Type_divchild
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_divchildlist = vx_web_html.Class_divchildlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_divchildlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_divchildlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_divchild), // allowtypes
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

  val e_divchildlist : vx_web_html.Type_divchildlist = vx_web_html.Class_divchildlist()
  val t_divchildlist : vx_web_html.Type_divchildlist = vx_web_html.Class_divchildlist()

  interface Type_divlist : vx_core.Type_list {
    fun vx_listdiv() : List<vx_web_html.Type_div>
    fun vx_div(index : vx_core.Type_int) : vx_web_html.Type_div
  }

  class Class_divlist : vx_core.Class_base, Type_divlist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_div> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_div>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_div(index : vx_core.Type_int) : vx_web_html.Type_div {
      var output : vx_web_html.Type_div = vx_web_html.e_div
      var list : vx_web_html.Class_divlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_div> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listdiv() : List<vx_web_html.Type_div> {
      var output : List<vx_web_html.Type_div> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_div = this.vx_div(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divlist = vx_core.vx_copy(vx_web_html.e_divlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_divlist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_divlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_div> = ArrayList<vx_web_html.Type_div>(value.vx_listdiv())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_divlist) {
          var multi : vx_web_html.Type_divlist = valsub as vx_web_html.Type_divlist
          ischanged = true
          listval.addAll(multi.vx_listdiv())
        } else if (valsub is vx_web_html.Type_div) {
          var allowsub : vx_web_html.Type_div = valsub as vx_web_html.Type_div
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_div) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_div)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_div) {
              var valitem : vx_web_html.Type_div = item as vx_web_html.Type_div
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_divlist = vx_web_html.Class_divlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_divlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_divlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_div), // allowtypes
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

  val e_divlist : vx_web_html.Type_divlist = vx_web_html.Class_divlist()
  val t_divlist : vx_web_html.Type_divlist = vx_web_html.Class_divlist()

  interface Type_footer : vx_core.Type_struct {
    fun nodes() : vx_web_html.Type_divchildlist
  }

  class Class_footer : vx_core.Class_base, Type_footer {
    constructor() {}

    var vx_p_nodes : vx_web_html.Type_divchildlist? = null

    override fun nodes() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_nodes
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_footer = vx_core.vx_copy(vx_web_html.e_footer, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_footer = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_footer = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_nodes : vx_web_html.Type_divchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_divchildlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_divchildlist
          } else if (valsub is vx_web_html.Type_divchild) {
            var valdefault : vx_web_html.Type_divchild = valsub as vx_web_html.Type_divchild
            var vallist : vx_web_html.Type_divchildlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_divchildlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/footer", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valnodes : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/footer", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_footer = vx_web_html.Class_footer()
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_footer
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_footer
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "footer", // name
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

  val e_footer : vx_web_html.Type_footer = vx_web_html.Class_footer()
  val t_footer : vx_web_html.Type_footer = vx_web_html.Class_footer()

  interface Type_h1 : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun text() : vx_core.Type_string
  }

  class Class_h1 : vx_core.Class_base, Type_h1 {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h1 = vx_core.vx_copy(vx_web_html.e_h1, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h1 = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_h1 = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":text")
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
          } else if (valsub is vx_core.Type_string) {
            ischanged = true
            vx_p_text = valsub as vx_core.Type_string
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else if (valsub is vx_core.Type_string) {
              var valstr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_text = valstr
            } else if (valsub is String) {
              ischanged = true
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_h1 = vx_web_html.Class_h1()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_h1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_h1
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_h1 : vx_web_html.Type_h1 = vx_web_html.Class_h1()
  val t_h1 : vx_web_html.Type_h1 = vx_web_html.Class_h1()

  interface Type_h2 : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun text() : vx_core.Type_string
  }

  class Class_h2 : vx_core.Class_base, Type_h2 {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h2 = vx_core.vx_copy(vx_web_html.e_h2, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h2 = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_h2 = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":text")
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
          } else if (valsub is vx_core.Type_string) {
            ischanged = true
            vx_p_text = valsub as vx_core.Type_string
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else if (valsub is vx_core.Type_string) {
              var valstr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_text = valstr
            } else if (valsub is String) {
              ischanged = true
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_h2 = vx_web_html.Class_h2()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_h2
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_h2
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_h2 : vx_web_html.Type_h2 = vx_web_html.Class_h2()
  val t_h2 : vx_web_html.Type_h2 = vx_web_html.Class_h2()

  interface Type_h3 : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun text() : vx_core.Type_string
  }

  class Class_h3 : vx_core.Class_base, Type_h3 {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h3 = vx_core.vx_copy(vx_web_html.e_h3, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_h3 = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_h3 = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":text")
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
          } else if (valsub is vx_core.Type_string) {
            ischanged = true
            vx_p_text = valsub as vx_core.Type_string
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else if (valsub is vx_core.Type_string) {
              var valstr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_text = valstr
            } else if (valsub is String) {
              ischanged = true
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_h3 = vx_web_html.Class_h3()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_h3
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_h3
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_h3 : vx_web_html.Type_h3 = vx_web_html.Class_h3()
  val t_h3 : vx_web_html.Type_h3 = vx_web_html.Class_h3()

  interface Type_head : vx_core.Type_struct {
    fun nodes() : vx_web_html.Type_headchildlist
  }

  class Class_head : vx_core.Class_base, Type_head {
    constructor() {}

    var vx_p_nodes : vx_web_html.Type_headchildlist? = null

    override fun nodes() : vx_web_html.Type_headchildlist {
      var output : vx_web_html.Type_headchildlist = vx_web_html.e_headchildlist
      var testnull : vx_web_html.Type_headchildlist? = vx_p_nodes
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_head = vx_core.vx_copy(vx_web_html.e_head, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_head = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_head = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_nodes : vx_web_html.Type_headchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_headchildlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_headchildlist
          } else if (valsub is vx_web_html.Type_headchild) {
            var valdefault : vx_web_html.Type_headchild = valsub as vx_web_html.Type_headchild
            var vallist : vx_web_html.Type_headchildlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_headchildlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/head", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_headchildlist) {
              var valnodes : vx_web_html.Type_headchildlist = valsub as vx_web_html.Type_headchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/head", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_head = vx_web_html.Class_head()
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_head
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_head
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "head", // name
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

  val e_head : vx_web_html.Type_head = vx_web_html.Class_head()
  val t_head : vx_web_html.Type_head = vx_web_html.Class_head()

  interface Type_headchild : vx_core.Type_struct {
  }

  class Class_headchild : vx_core.Class_base, Type_headchild {
    constructor() {}

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_headchild = vx_core.vx_copy(vx_web_html.e_headchild, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_headchild = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_headchild = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_headchild = vx_web_html.Class_headchild()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_headchild
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_headchild
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "headchild", // name
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

  val e_headchild : vx_web_html.Type_headchild = vx_web_html.Class_headchild()
  val t_headchild : vx_web_html.Type_headchild = vx_web_html.Class_headchild()

  interface Type_headchildlist : vx_core.Type_list {
    fun vx_listheadchild() : List<vx_web_html.Type_headchild>
    fun vx_headchild(index : vx_core.Type_int) : vx_web_html.Type_headchild
  }

  class Class_headchildlist : vx_core.Class_base, Type_headchildlist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_headchild> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_headchild>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_headchild(index : vx_core.Type_int) : vx_web_html.Type_headchild {
      var output : vx_web_html.Type_headchild = vx_web_html.e_headchild
      var list : vx_web_html.Class_headchildlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_headchild> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listheadchild() : List<vx_web_html.Type_headchild> {
      var output : List<vx_web_html.Type_headchild> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_headchild = this.vx_headchild(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_headchildlist = vx_core.vx_copy(vx_web_html.e_headchildlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_headchildlist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_headchildlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_headchild> = ArrayList<vx_web_html.Type_headchild>(value.vx_listheadchild())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_headchildlist) {
          var multi : vx_web_html.Type_headchildlist = valsub as vx_web_html.Type_headchildlist
          ischanged = true
          listval.addAll(multi.vx_listheadchild())
        } else if (valsub is vx_web_html.Type_headchild) {
          var allowsub : vx_web_html.Type_headchild = valsub as vx_web_html.Type_headchild
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_headchild) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_headchild)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_headchild) {
              var valitem : vx_web_html.Type_headchild = item as vx_web_html.Type_headchild
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_headchildlist = vx_web_html.Class_headchildlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_headchildlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_headchildlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_headchild), // allowtypes
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

  val e_headchildlist : vx_web_html.Type_headchildlist = vx_web_html.Class_headchildlist()
  val t_headchildlist : vx_web_html.Type_headchildlist = vx_web_html.Class_headchildlist()

  interface Type_html : vx_core.Type_struct {
    fun lang() : vx_core.Type_string
    fun head() : vx_web_html.Type_head
    fun body() : vx_web_html.Type_body
    fun footer() : vx_web_html.Type_footer
  }

  class Class_html : vx_core.Class_base, Type_html {
    constructor() {}

    var vx_p_lang : vx_core.Type_string? = null

    override fun lang() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_lang
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_head : vx_web_html.Type_head? = null

    override fun head() : vx_web_html.Type_head {
      var output : vx_web_html.Type_head = vx_web_html.e_head
      var testnull : vx_web_html.Type_head? = vx_p_head
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_body : vx_web_html.Type_body? = null

    override fun body() : vx_web_html.Type_body {
      var output : vx_web_html.Type_body = vx_web_html.e_body
      var testnull : vx_web_html.Type_body? = vx_p_body
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_footer : vx_web_html.Type_footer? = null

    override fun footer() : vx_web_html.Type_footer {
      var output : vx_web_html.Type_footer = vx_web_html.e_footer
      var testnull : vx_web_html.Type_footer? = vx_p_footer
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":lang")) {
        output = this.lang()
      } else if ((skey==":head")) {
        output = this.head()
      } else if ((skey==":body")) {
        output = this.body()
      } else if ((skey==":footer")) {
        output = this.footer()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":lang", this.lang())
      map.put(":head", this.head())
      map.put(":body", this.body())
      map.put(":footer", this.footer())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_html = vx_core.vx_copy(vx_web_html.e_html, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_html = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_html = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_lang : vx_core.Type_string = value.lang()
      var vx_p_head : vx_web_html.Type_head = value.head()
      var vx_p_body : vx_web_html.Type_body = value.body()
      var vx_p_footer : vx_web_html.Type_footer = value.footer()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":lang")
      validkeys.add(":head")
      validkeys.add(":body")
      validkeys.add(":footer")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":lang")) {
            if (valsub == vx_p_lang) {
            } else if (valsub is vx_core.Type_string) {
              var vallang : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_lang = vallang
            } else if (valsub is String) {
              ischanged = true
              vx_p_lang = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("lang"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":head")) {
            if (valsub == vx_p_head) {
            } else if (valsub is vx_web_html.Type_head) {
              var valhead : vx_web_html.Type_head = valsub as vx_web_html.Type_head
              ischanged = true
              vx_p_head = valhead
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("head"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":body")) {
            if (valsub == vx_p_body) {
            } else if (valsub is vx_web_html.Type_body) {
              var valbody : vx_web_html.Type_body = valsub as vx_web_html.Type_body
              ischanged = true
              vx_p_body = valbody
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("body"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":footer")) {
            if (valsub == vx_p_footer) {
            } else if (valsub is vx_web_html.Type_footer) {
              var valfooter : vx_web_html.Type_footer = valsub as vx_web_html.Type_footer
              ischanged = true
              vx_p_footer = valfooter
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("footer"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_html = vx_web_html.Class_html()
        work.vx_p_lang = vx_p_lang
        work.vx_p_head = vx_p_head
        work.vx_p_body = vx_p_body
        work.vx_p_footer = vx_p_footer
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_html
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "html", // name
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

  val e_html : vx_web_html.Type_html = vx_web_html.Class_html()
  val t_html : vx_web_html.Type_html = vx_web_html.Class_html()

  interface Type_img : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun src() : vx_core.Type_string
  }

  class Class_img : vx_core.Class_base, Type_img {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_src : vx_core.Type_string? = null

    override fun src() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_src
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":src")) {
        output = this.src()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":src", this.src())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_img = vx_core.vx_copy(vx_web_html.e_img, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_img = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_img = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_src : vx_core.Type_string = value.src()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":src")
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
          } else if (valsub is vx_core.Type_string) {
            ischanged = true
            vx_p_src = valsub as vx_core.Type_string
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else if (valsub is vx_core.Type_string) {
              var valstr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_src = valstr
            } else if (valsub is String) {
              ischanged = true
              vx_p_src = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":src")) {
            if (valsub == vx_p_src) {
            } else if (valsub is vx_core.Type_string) {
              var valsrc : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_src = valsrc
            } else if (valsub is String) {
              ischanged = true
              vx_p_src = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("src"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_img = vx_web_html.Class_img()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_src = vx_p_src
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_img
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_img
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "img", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_img : vx_web_html.Type_img = vx_web_html.Class_img()
  val t_img : vx_web_html.Type_img = vx_web_html.Class_img()

  interface Type_meta : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_headchild {
    fun charset() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun content() : vx_core.Type_string
  }

  class Class_meta : vx_core.Class_base, Type_meta {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_charset : vx_core.Type_string? = null

    override fun charset() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_charset
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

    var vx_p_content : vx_core.Type_string? = null

    override fun content() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_content
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":charset")) {
        output = this.charset()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":content")) {
        output = this.content()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":charset", this.charset())
      map.put(":name", this.name())
      map.put(":content", this.content())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_meta = vx_core.vx_copy(vx_web_html.e_meta, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_meta = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_meta = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_charset : vx_core.Type_string = value.charset()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_content : vx_core.Type_string = value.content()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":charset")
      validkeys.add(":name")
      validkeys.add(":content")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":charset")) {
            if (valsub == vx_p_charset) {
            } else if (valsub is vx_core.Type_string) {
              var valcharset : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_charset = valcharset
            } else if (valsub is String) {
              ischanged = true
              vx_p_charset = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("charset"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":content")) {
            if (valsub == vx_p_content) {
            } else if (valsub is vx_core.Type_string) {
              var valcontent : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_content = valcontent
            } else if (valsub is String) {
              ischanged = true
              vx_p_content = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("content"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_meta = vx_web_html.Class_meta()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_charset = vx_p_charset
        work.vx_p_name = vx_p_name
        work.vx_p_content = vx_p_content
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_meta
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_meta
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_headchild), // traits
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

  val e_meta : vx_web_html.Type_meta = vx_web_html.Class_meta()
  val t_meta : vx_web_html.Type_meta = vx_web_html.Class_meta()

  interface Type_node : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun eventmap() : vx_event.Type_eventmap
    fun style() : vx_web_html.Type_style
    fun style_unique() : vx_web_html.Type_style
    fun stylelist() : vx_web_html.Type_stylelist
  }

  class Class_node : vx_core.Class_base, Type_node {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_node = vx_core.vx_copy(vx_web_html.e_node, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_node = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_node = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_node = vx_web_html.Class_node()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_node
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_node
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "node", // name
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

  val e_node : vx_web_html.Type_node = vx_web_html.Class_node()
  val t_node : vx_web_html.Type_node = vx_web_html.Class_node()

  interface Type_nodelist : vx_core.Type_list {
    fun vx_listnode() : List<vx_web_html.Type_node>
    fun vx_node(index : vx_core.Type_int) : vx_web_html.Type_node
  }

  class Class_nodelist : vx_core.Class_base, Type_nodelist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_node> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_node>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_node(index : vx_core.Type_int) : vx_web_html.Type_node {
      var output : vx_web_html.Type_node = vx_web_html.e_node
      var list : vx_web_html.Class_nodelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_node> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listnode() : List<vx_web_html.Type_node> {
      var output : List<vx_web_html.Type_node> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_node = this.vx_node(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_nodelist = vx_core.vx_copy(vx_web_html.e_nodelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_nodelist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_nodelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_node> = ArrayList<vx_web_html.Type_node>(value.vx_listnode())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_nodelist) {
          var multi : vx_web_html.Type_nodelist = valsub as vx_web_html.Type_nodelist
          ischanged = true
          listval.addAll(multi.vx_listnode())
        } else if (valsub is vx_web_html.Type_node) {
          var allowsub : vx_web_html.Type_node = valsub as vx_web_html.Type_node
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_node) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_node)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_node) {
              var valitem : vx_web_html.Type_node = item as vx_web_html.Type_node
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_nodelist = vx_web_html.Class_nodelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_nodelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_nodelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node), // allowtypes
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

  val e_nodelist : vx_web_html.Type_nodelist = vx_web_html.Class_nodelist()
  val t_nodelist : vx_web_html.Type_nodelist = vx_web_html.Class_nodelist()

  interface Type_p : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun text() : vx_core.Type_string
  }

  class Class_p : vx_core.Class_base, Type_p {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_p = vx_core.vx_copy(vx_web_html.e_p, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_p = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_p = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":text")
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
          } else if (valsub is vx_core.Type_string) {
            ischanged = true
            vx_p_text = valsub as vx_core.Type_string
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidkeytype", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey
            }
            var isvalidkey : Boolean = validkeys.contains(testkey)
            if (isvalidkey) {
              key = testkey
            } else if (valsub is vx_core.Type_string) {
              var valstr : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_text = valstr
            } else if (valsub is String) {
              ischanged = true
              vx_p_text = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              msgval = vx_core.vx_new_string(testkey)
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_p = vx_web_html.Class_p()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_p
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_p
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_p : vx_web_html.Type_p = vx_web_html.Class_p()
  val t_p : vx_web_html.Type_p = vx_web_html.Class_p()

  interface Type_propmap : vx_core.Type_map {
    fun vx_mapstring() : Map<String, vx_core.Type_string>
    fun vx_string(key : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_propmap : vx_core.Class_base, Type_propmap {
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
      var map : vx_web_html.Class_propmap = this
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
      var output : vx_web_html.Class_propmap = vx_web_html.Class_propmap()
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
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/web/html/propmap", ":invalidvalue", value)
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
      var output : vx_web_html.Type_propmap = vx_core.vx_copy(vx_web_html.e_propmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_propmap = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_propmap = this
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
            msg = vx_core.vx_msg_from_error("vx/web/html/propmap", ":keyexpected", msgval)
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
            msg = vx_core.vx_msg_from_error("vx/web/html/propmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_web_html.Class_propmap = vx_web_html.Class_propmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_propmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_propmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
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

  val e_propmap : vx_web_html.Type_propmap = vx_web_html.Class_propmap()
  val t_propmap : vx_web_html.Type_propmap = vx_web_html.Class_propmap()

  interface Type_style : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun props() : vx_web_html.Type_propmap
    fun stylelist() : vx_web_html.Type_stylelist
  }

  class Class_style : vx_core.Class_base, Type_style {
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

    var vx_p_props : vx_web_html.Type_propmap? = null

    override fun props() : vx_web_html.Type_propmap {
      var output : vx_web_html.Type_propmap = vx_web_html.e_propmap
      var testnull : vx_web_html.Type_propmap? = vx_p_props
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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
      } else if ((skey==":props")) {
        output = this.props()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":props", this.props())
      map.put(":stylelist", this.stylelist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_style = vx_core.vx_copy(vx_web_html.e_style, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_style = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_style = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_props : vx_web_html.Type_propmap = value.props()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":props")
      validkeys.add(":stylelist")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":props")) {
            if (valsub == vx_p_props) {
            } else if (valsub is vx_web_html.Type_propmap) {
              var valprops : vx_web_html.Type_propmap = valsub as vx_web_html.Type_propmap
              ischanged = true
              vx_p_props = valprops
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("props"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_style = vx_web_html.Class_style()
        work.vx_p_name = vx_p_name
        work.vx_p_props = vx_p_props
        work.vx_p_stylelist = vx_p_stylelist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_style
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_style
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "style", // name
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

  val e_style : vx_web_html.Type_style = vx_web_html.Class_style()
  val t_style : vx_web_html.Type_style = vx_web_html.Class_style()

  interface Type_stylelist : vx_core.Type_list {
    fun vx_liststyle() : List<vx_web_html.Type_style>
    fun vx_style(index : vx_core.Type_int) : vx_web_html.Type_style
  }

  class Class_stylelist : vx_core.Class_base, Type_stylelist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_style> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_style>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_style(index : vx_core.Type_int) : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var list : vx_web_html.Class_stylelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_style> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_liststyle() : List<vx_web_html.Type_style> {
      var output : List<vx_web_html.Type_style> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_style = this.vx_style(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_stylelist = vx_core.vx_copy(vx_web_html.e_stylelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_stylelist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_stylelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_style> = ArrayList<vx_web_html.Type_style>(value.vx_liststyle())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_stylelist) {
          var multi : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
          ischanged = true
          listval.addAll(multi.vx_liststyle())
        } else if (valsub is vx_web_html.Type_style) {
          var allowsub : vx_web_html.Type_style = valsub as vx_web_html.Type_style
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_style) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_style)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_style) {
              var valitem : vx_web_html.Type_style = item as vx_web_html.Type_style
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_stylelist = vx_web_html.Class_stylelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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

  val e_stylelist : vx_web_html.Type_stylelist = vx_web_html.Class_stylelist()
  val t_stylelist : vx_web_html.Type_stylelist = vx_web_html.Class_stylelist()

  interface Type_stylemap : vx_core.Type_map {
    fun vx_mapstyle() : Map<String, vx_web_html.Type_style>
    fun vx_style(key : vx_core.Type_string) : vx_web_html.Type_style
  }

  class Class_stylemap : vx_core.Class_base, Type_stylemap {
    constructor() {}

    var vx_p_map : Map<String, vx_web_html.Type_style> = vx_core.immutablemap(LinkedHashMap<String, vx_web_html.Type_style>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_web_html.Type_style) {
        var castval : vx_web_html.Type_style = value as vx_web_html.Type_style
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_web_html.Type_style> = LinkedHashMap<String, vx_web_html.Type_style>(this.vx_p_map)
        if (castval == vx_web_html.e_style) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_style(key : vx_core.Type_string) : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var map : vx_web_html.Class_stylemap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_web_html.Type_style> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_web_html.e_style)
      return output
    }

    override fun vx_mapstyle() : Map<String, vx_web_html.Type_style> {
      var output : Map<String, vx_web_html.Type_style> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_style(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_web_html.Class_stylemap = vx_web_html.Class_stylemap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_web_html.Type_style> = LinkedHashMap<String, vx_web_html.Type_style>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_web_html.Type_style) {
          var castval : vx_web_html.Type_style = value as vx_web_html.Type_style
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/web/html/stylemap", ":invalidvalue", value)
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
      var output : vx_web_html.Type_stylemap = vx_core.vx_copy(vx_web_html.e_stylemap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_stylemap = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_stylemap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_web_html.Type_style> = LinkedHashMap<String, vx_web_html.Type_style>(value.vx_mapstyle())
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
            msg = vx_core.vx_msg_from_error("vx/web/html/stylemap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_web_html.Type_style = vx_web_html.e_style
          if (false) {
          } else if (valsub is vx_web_html.Type_style) {
            var valallowed : vx_web_html.Type_style = valsub as vx_web_html.Type_style
            valany = valallowed
          } else if (valsub is vx_web_html.Type_style) {
            valany = valsub as vx_web_html.Type_style
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
            msg = vx_core.vx_msg_from_error("vx/web/html/stylemap", ":invalidkeyvalue", msgmap)
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
        var work : vx_web_html.Class_stylemap = vx_web_html.Class_stylemap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_stylemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylemap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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

  val e_stylemap : vx_web_html.Type_stylemap = vx_web_html.Class_stylemap()
  val t_stylemap : vx_web_html.Type_stylemap = vx_web_html.Class_stylemap()

  interface Type_stylesheet : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_headchild {
    fun name() : vx_core.Type_string
    fun styles() : vx_web_html.Type_stylelist
    fun stylemap() : vx_web_html.Type_stylemap
  }

  class Class_stylesheet : vx_core.Class_base, Type_stylesheet {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    var vx_p_styles : vx_web_html.Type_stylelist? = null

    override fun styles() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_styles
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylemap : vx_web_html.Type_stylemap? = null

    override fun stylemap() : vx_web_html.Type_stylemap {
      var output : vx_web_html.Type_stylemap = vx_web_html.e_stylemap
      var testnull : vx_web_html.Type_stylemap? = vx_p_stylemap
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":styles")) {
        output = this.styles()
      } else if ((skey==":stylemap")) {
        output = this.stylemap()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":name", this.name())
      map.put(":styles", this.styles())
      map.put(":stylemap", this.stylemap())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_stylesheet = vx_core.vx_copy(vx_web_html.e_stylesheet, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_stylesheet = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_stylesheet = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_styles : vx_web_html.Type_stylelist = value.styles()
      var vx_p_stylemap : vx_web_html.Type_stylemap = value.stylemap()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":name")
      validkeys.add(":styles")
      validkeys.add(":stylemap")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":styles")) {
            if (valsub == vx_p_styles) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstyles : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_styles = valstyles
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("styles"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylemap")) {
            if (valsub == vx_p_stylemap) {
            } else if (valsub is vx_web_html.Type_stylemap) {
              var valstylemap : vx_web_html.Type_stylemap = valsub as vx_web_html.Type_stylemap
              ischanged = true
              vx_p_stylemap = valstylemap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylemap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_stylesheet = vx_web_html.Class_stylesheet()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_name = vx_p_name
        work.vx_p_styles = vx_p_styles
        work.vx_p_stylemap = vx_p_stylemap
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylesheet
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_headchild), // traits
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

  val e_stylesheet : vx_web_html.Type_stylesheet = vx_web_html.Class_stylesheet()
  val t_stylesheet : vx_web_html.Type_stylesheet = vx_web_html.Class_stylesheet()

  interface Type_table : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_divchild {
    fun tbody() : vx_web_html.Type_tbody
    fun thead() : vx_web_html.Type_thead
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_tbody : vx_web_html.Type_tbody? = null

    override fun tbody() : vx_web_html.Type_tbody {
      var output : vx_web_html.Type_tbody = vx_web_html.e_tbody
      var testnull : vx_web_html.Type_tbody? = vx_p_tbody
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_thead : vx_web_html.Type_thead? = null

    override fun thead() : vx_web_html.Type_thead {
      var output : vx_web_html.Type_thead = vx_web_html.e_thead
      var testnull : vx_web_html.Type_thead? = vx_p_thead
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":tbody")) {
        output = this.tbody()
      } else if ((skey==":thead")) {
        output = this.thead()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":tbody", this.tbody())
      map.put(":thead", this.thead())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_table = vx_core.vx_copy(vx_web_html.e_table, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_table = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_table = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_tbody : vx_web_html.Type_tbody = value.tbody()
      var vx_p_thead : vx_web_html.Type_thead = value.thead()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":tbody")
      validkeys.add(":thead")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":tbody")) {
            if (valsub == vx_p_tbody) {
            } else if (valsub is vx_web_html.Type_tbody) {
              var valtbody : vx_web_html.Type_tbody = valsub as vx_web_html.Type_tbody
              ischanged = true
              vx_p_tbody = valtbody
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("tbody"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":thead")) {
            if (valsub == vx_p_thead) {
            } else if (valsub is vx_web_html.Type_thead) {
              var valthead : vx_web_html.Type_thead = valsub as vx_web_html.Type_thead
              ischanged = true
              vx_p_thead = valthead
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("thead"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_table = vx_web_html.Class_table()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_tbody = vx_p_tbody
        work.vx_p_thead = vx_p_thead
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_table
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_table
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_divchild), // traits
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

  val e_table : vx_web_html.Type_table = vx_web_html.Class_table()
  val t_table : vx_web_html.Type_table = vx_web_html.Class_table()

  interface Type_tbody : vx_core.Type_struct, vx_web_html.Type_node {
    fun nodes() : vx_web_html.Type_trlist
  }

  class Class_tbody : vx_core.Class_base, Type_tbody {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_trlist? = null

    override fun nodes() : vx_web_html.Type_trlist {
      var output : vx_web_html.Type_trlist = vx_web_html.e_trlist
      var testnull : vx_web_html.Type_trlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tbody = vx_core.vx_copy(vx_web_html.e_tbody, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tbody = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_tbody = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_nodes : vx_web_html.Type_trlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_trlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_trlist
          } else if (valsub is vx_web_html.Type_tr) {
            var valdefault : vx_web_html.Type_tr = valsub as vx_web_html.Type_tr
            var vallist : vx_web_html.Type_trlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_trlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_trlist) {
              var valnodes : vx_web_html.Type_trlist = valsub as vx_web_html.Type_trlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_tbody = vx_web_html.Class_tbody()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_tbody
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_tbody
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node), // traits
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

  val e_tbody : vx_web_html.Type_tbody = vx_web_html.Class_tbody()
  val t_tbody : vx_web_html.Type_tbody = vx_web_html.Class_tbody()

  interface Type_td : vx_core.Type_struct, vx_web_html.Type_node {
    fun nodes() : vx_web_html.Type_divchildlist
  }

  class Class_td : vx_core.Class_base, Type_td {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_divchildlist? = null

    override fun nodes() : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
      var testnull : vx_web_html.Type_divchildlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_td = vx_core.vx_copy(vx_web_html.e_td, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_td = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_td = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_nodes : vx_web_html.Type_divchildlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_divchildlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_divchildlist
          } else if (valsub is vx_web_html.Type_divchild) {
            var valdefault : vx_web_html.Type_divchild = valsub as vx_web_html.Type_divchild
            var vallist : vx_web_html.Type_divchildlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_divchildlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_divchildlist) {
              var valnodes : vx_web_html.Type_divchildlist = valsub as vx_web_html.Type_divchildlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_td = vx_web_html.Class_td()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_td
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_td
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node), // traits
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

  val e_td : vx_web_html.Type_td = vx_web_html.Class_td()
  val t_td : vx_web_html.Type_td = vx_web_html.Class_td()

  interface Type_tdlist : vx_core.Type_list {
    fun vx_listtd() : List<vx_web_html.Type_td>
    fun vx_td(index : vx_core.Type_int) : vx_web_html.Type_td
  }

  class Class_tdlist : vx_core.Class_base, Type_tdlist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_td> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_td>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_td(index : vx_core.Type_int) : vx_web_html.Type_td {
      var output : vx_web_html.Type_td = vx_web_html.e_td
      var list : vx_web_html.Class_tdlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_td> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtd() : List<vx_web_html.Type_td> {
      var output : List<vx_web_html.Type_td> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_td = this.vx_td(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tdlist = vx_core.vx_copy(vx_web_html.e_tdlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tdlist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_tdlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_td> = ArrayList<vx_web_html.Type_td>(value.vx_listtd())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_tdlist) {
          var multi : vx_web_html.Type_tdlist = valsub as vx_web_html.Type_tdlist
          ischanged = true
          listval.addAll(multi.vx_listtd())
        } else if (valsub is vx_web_html.Type_td) {
          var allowsub : vx_web_html.Type_td = valsub as vx_web_html.Type_td
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_td) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_td)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_td) {
              var valitem : vx_web_html.Type_td = item as vx_web_html.Type_td
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_tdlist = vx_web_html.Class_tdlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_tdlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_tdlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_td), // allowtypes
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

  val e_tdlist : vx_web_html.Type_tdlist = vx_web_html.Class_tdlist()
  val t_tdlist : vx_web_html.Type_tdlist = vx_web_html.Class_tdlist()

  interface Type_thead : vx_core.Type_struct, vx_web_html.Type_node {
    fun nodes() : vx_web_html.Type_trlist
  }

  class Class_thead : vx_core.Class_base, Type_thead {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_trlist? = null

    override fun nodes() : vx_web_html.Type_trlist {
      var output : vx_web_html.Type_trlist = vx_web_html.e_trlist
      var testnull : vx_web_html.Type_trlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_thead = vx_core.vx_copy(vx_web_html.e_thead, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_thead = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_thead = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_nodes : vx_web_html.Type_trlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_trlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_trlist
          } else if (valsub is vx_web_html.Type_tr) {
            var valdefault : vx_web_html.Type_tr = valsub as vx_web_html.Type_tr
            var vallist : vx_web_html.Type_trlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_trlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_trlist) {
              var valnodes : vx_web_html.Type_trlist = valsub as vx_web_html.Type_trlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_thead = vx_web_html.Class_thead()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_thead
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_thead
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node), // traits
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

  val e_thead : vx_web_html.Type_thead = vx_web_html.Class_thead()
  val t_thead : vx_web_html.Type_thead = vx_web_html.Class_thead()

  interface Type_title : vx_core.Type_struct, vx_web_html.Type_node, vx_web_html.Type_headchild {
    fun text() : vx_core.Type_string
  }

  class Class_title : vx_core.Class_base, Type_title {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":id")) {
        output = this.id()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_title = vx_core.vx_copy(vx_web_html.e_title, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_title = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_title = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":text")
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
            msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_title = vx_web_html.Class_title()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_title
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_title
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_headchild), // traits
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

  val e_title : vx_web_html.Type_title = vx_web_html.Class_title()
  val t_title : vx_web_html.Type_title = vx_web_html.Class_title()

  interface Type_tr : vx_core.Type_struct, vx_web_html.Type_node {
    fun nodes() : vx_web_html.Type_tdlist
  }

  class Class_tr : vx_core.Class_base, Type_tr {
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

    var vx_p_eventmap : vx_event.Type_eventmap? = null

    override fun eventmap() : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.e_eventmap
      var testnull : vx_event.Type_eventmap? = vx_p_eventmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_web_html.Type_style? = null

    override fun style() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style_unique : vx_web_html.Type_style? = null

    override fun style_unique() : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.e_style
      var testnull : vx_web_html.Type_style? = vx_p_style_unique
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_web_html.Type_stylelist? = null

    override fun stylelist() : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
      var testnull : vx_web_html.Type_stylelist? = vx_p_stylelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_nodes : vx_web_html.Type_tdlist? = null

    override fun nodes() : vx_web_html.Type_tdlist {
      var output : vx_web_html.Type_tdlist = vx_web_html.e_tdlist
      var testnull : vx_web_html.Type_tdlist? = vx_p_nodes
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
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":style-unique")) {
        output = this.style_unique()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":nodes")) {
        output = this.nodes()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":eventmap", this.eventmap())
      map.put(":style", this.style())
      map.put(":style-unique", this.style_unique())
      map.put(":stylelist", this.stylelist())
      map.put(":nodes", this.nodes())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tr = vx_core.vx_copy(vx_web_html.e_tr, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_tr = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_tr = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_style : vx_web_html.Type_style = value.style()
      var vx_p_style_unique : vx_web_html.Type_style = value.style_unique()
      var vx_p_stylelist : vx_web_html.Type_stylelist = value.stylelist()
      var vx_p_nodes : vx_web_html.Type_tdlist = value.nodes()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":eventmap")
      validkeys.add(":style")
      validkeys.add(":style-unique")
      validkeys.add(":stylelist")
      validkeys.add(":nodes")
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
          } else if (valsub is vx_web_html.Type_tdlist) {
            ischanged = true
            vx_p_nodes = valsub as vx_web_html.Type_tdlist
          } else if (valsub is vx_web_html.Type_td) {
            var valdefault : vx_web_html.Type_td = valsub as vx_web_html.Type_td
            var vallist : vx_web_html.Type_tdlist
            vallist = vx_p_nodes
            if (vallist == null) {
              vallist = vx_core.vx_new(vx_web_html.t_tdlist, valdefault)
            } else {
              vallist = vx_core.vx_copy(vallist, valdefault)
            }
            ischanged = true
            vx_p_nodes = vallist
          } else {
            if (false) {
            } else if (valsub is vx_core.Type_any) {
              var valmsg : vx_core.Type_any = valsub as vx_core.Type_any
              msgval = valmsg
            } else {
              msgval = vx_core.vx_new_string(valsub.toString())
            }
            msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":eventmap")) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub is vx_event.Type_eventmap) {
              var valeventmap : vx_event.Type_eventmap = valsub as vx_event.Type_eventmap
              ischanged = true
              vx_p_eventmap = valeventmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("eventmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style = valstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style-unique")) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub is vx_web_html.Type_style) {
              var valstyle_unique : vx_web_html.Type_style = valsub as vx_web_html.Type_style
              ischanged = true
              vx_p_style_unique = valstyle_unique
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("style-unique"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_web_html.Type_stylelist) {
              var valstylelist : vx_web_html.Type_stylelist = valsub as vx_web_html.Type_stylelist
              ischanged = true
              vx_p_stylelist = valstylelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":nodes")) {
            if (valsub == vx_p_nodes) {
            } else if (valsub is vx_web_html.Type_tdlist) {
              var valnodes : vx_web_html.Type_tdlist = valsub as vx_web_html.Type_tdlist
              ischanged = true
              vx_p_nodes = valnodes
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("nodes"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_tr = vx_web_html.Class_tr()
        work.vx_p_id = vx_p_id
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_style = vx_p_style
        work.vx_p_style_unique = vx_p_style_unique
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_nodes = vx_p_nodes
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_tr
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_tr
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node), // traits
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

  val e_tr : vx_web_html.Type_tr = vx_web_html.Class_tr()
  val t_tr : vx_web_html.Type_tr = vx_web_html.Class_tr()

  interface Type_trlist : vx_core.Type_list {
    fun vx_listtr() : List<vx_web_html.Type_tr>
    fun vx_tr(index : vx_core.Type_int) : vx_web_html.Type_tr
  }

  class Class_trlist : vx_core.Class_base, Type_trlist {
    constructor() {}

    var vx_p_list : List<vx_web_html.Type_tr> = vx_core.immutablelist(
      ArrayList<vx_web_html.Type_tr>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_tr(index : vx_core.Type_int) : vx_web_html.Type_tr {
      var output : vx_web_html.Type_tr = vx_web_html.e_tr
      var list : vx_web_html.Class_trlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_web_html.Type_tr> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtr() : List<vx_web_html.Type_tr> {
      var output : List<vx_web_html.Type_tr> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_web_html.Type_tr = this.vx_tr(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_trlist = vx_core.vx_copy(vx_web_html.e_trlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_html.Type_trlist = this
      var ischanged : Boolean = false
      var value : vx_web_html.Class_trlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_web_html.Type_tr> = ArrayList<vx_web_html.Type_tr>(value.vx_listtr())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_web_html.Type_trlist) {
          var multi : vx_web_html.Type_trlist = valsub as vx_web_html.Type_trlist
          ischanged = true
          listval.addAll(multi.vx_listtr())
        } else if (valsub is vx_web_html.Type_tr) {
          var allowsub : vx_web_html.Type_tr = valsub as vx_web_html.Type_tr
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_web_html.Type_tr) {
          ischanged = true
          listval.add(valsub as vx_web_html.Type_tr)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_web_html.Type_tr) {
              var valitem : vx_web_html.Type_tr = item as vx_web_html.Type_tr
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_html.Class_trlist = vx_web_html.Class_trlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.e_trlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_trlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_tr), // allowtypes
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

  val e_trlist : vx_web_html.Type_trlist = vx_web_html.Class_trlist()
  val t_trlist : vx_web_html.Type_trlist = vx_web_html.Class_trlist()

  interface Func_htmlstring_from_string : vx_core.Func_any_from_any {
    fun vx_htmlstring_from_string(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_htmlstring_from_string : vx_core.Class_base, Func_htmlstring_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_htmlstring_from_string = vx_web_html.Class_htmlstring_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_htmlstring_from_string = vx_web_html.Class_htmlstring_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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
      var output : vx_core.Type_any = vx_web_html.e_htmlstring_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_htmlstring_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_html.f_htmlstring_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_htmlstring_from_string(text)
      return output
    }

    override fun vx_htmlstring_from_string(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_htmlstring_from_string(text)
      return output
    }

  }

  val e_htmlstring_from_string : vx_web_html.Func_htmlstring_from_string = vx_web_html.Class_htmlstring_from_string()
  val t_htmlstring_from_string : vx_web_html.Func_htmlstring_from_string = vx_web_html.Class_htmlstring_from_string()

  fun f_htmlstring_from_string(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_web_html.vx_htmlstring_from_string(text)
    return output
  }


  interface Func_string_indent : vx_core.Func_any_from_any {
    fun vx_string_indent(indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_indent : vx_core.Class_base, Func_string_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_indent = vx_web_html.Class_string_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_indent = vx_web_html.Class_string_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_indent
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_int = value as vx_core.Type_int
      var outputval : vx_core.Type_any = vx_web_html.f_string_indent(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_indent(indent)
      return output
    }

    override fun vx_string_indent(indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_indent(indent)
      return output
    }

  }

  val e_string_indent : vx_web_html.Func_string_indent = vx_web_html.Class_string_indent()
  val t_string_indent : vx_web_html.Func_string_indent = vx_web_html.Class_string_indent()

  fun f_string_indent(indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_string_repeat(
      vx_core.vx_new_string("  "),
      indent
    )
    return output
  }


  interface Func_string_from_body_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_body_indent(body : vx_web_html.Type_body, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_body_indent : vx_core.Class_base, Func_string_from_body_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_body_indent = vx_web_html.Class_string_from_body_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_body_indent = vx_web_html.Class_string_from_body_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_body_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_body_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var body : vx_web_html.Type_body = vx_core.f_any_from_any(vx_web_html.t_body, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_body_indent(body, indent)
      return output
    }

    override fun vx_string_from_body_indent(body : vx_web_html.Type_body, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_body_indent(body, indent)
      return output
    }

  }

  val e_string_from_body_indent : vx_web_html.Func_string_from_body_indent = vx_web_html.Class_string_from_body_indent()
  val t_string_from_body_indent : vx_web_html.Func_string_from_body_indent = vx_web_html.Class_string_from_body_indent()

  fun f_string_from_body_indent(body : vx_web_html.Type_body, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_divchildlist = body.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("body"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_details_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_details_indent(details : vx_web_html.Type_details, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_details_indent : vx_core.Class_base, Func_string_from_details_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_details_indent = vx_web_html.Class_string_from_details_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_details_indent = vx_web_html.Class_string_from_details_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_details_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_details_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var details : vx_web_html.Type_details = vx_core.f_any_from_any(vx_web_html.t_details, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_details_indent(details, indent)
      return output
    }

    override fun vx_string_from_details_indent(details : vx_web_html.Type_details, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_details_indent(details, indent)
      return output
    }

  }

  val e_string_from_details_indent : vx_web_html.Func_string_from_details_indent = vx_web_html.Class_string_from_details_indent()
  val t_string_from_details_indent : vx_web_html.Func_string_from_details_indent = vx_web_html.Class_string_from_details_indent()

  fun f_string_from_details_indent(details : vx_web_html.Type_details, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var summary : vx_web_html.Type_divchildlist = details.summary()
        var nodes : vx_web_html.Type_divchildlist = details.nodes()
        var ssummary : vx_core.Type_string = vx_web_html.f_string_from_nodelist_indent(
          summary,
          vx_core.f_plus(
            indent,
            vx_core.vx_new_int(2)
          )
        )
        var snodes : vx_core.Type_string = vx_web_html.f_string_from_nodelist_indent(
          nodes,
          vx_core.f_plus(
            indent,
            vx_core.vx_new_int(1)
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<details>"),
            sindent,
            vx_core.vx_new_string("  <summary>"),
            ssummary,
            sindent,
            vx_core.vx_new_string("  </summary>"),
            snodes,
            sindent,
            vx_core.vx_new_string("</details>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_div_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_div_indent(div : vx_web_html.Type_div, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_div_indent : vx_core.Class_base, Func_string_from_div_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_div_indent = vx_web_html.Class_string_from_div_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_div_indent = vx_web_html.Class_string_from_div_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_div_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_div_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var div : vx_web_html.Type_div = vx_core.f_any_from_any(vx_web_html.t_div, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_div_indent(div, indent)
      return output
    }

    override fun vx_string_from_div_indent(div : vx_web_html.Type_div, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_div_indent(div, indent)
      return output
    }

  }

  val e_string_from_div_indent : vx_web_html.Func_string_from_div_indent = vx_web_html.Class_string_from_div_indent()
  val t_string_from_div_indent : vx_web_html.Func_string_from_div_indent = vx_web_html.Class_string_from_div_indent()

  fun f_string_from_div_indent(div : vx_web_html.Type_div, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_divchildlist = div.nodes()
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          div.id()
        )
        var sclass : vx_core.Type_string = vx_web_html.f_string_from_propstyle_stylelist(
          div.style(),
          div.stylelist()
        )
        var sstyle : vx_core.Type_string = vx_web_html.f_string_from_propstyleunique(
          div.style_unique()
        )
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("div"),
          vx_core.f_new(
            vx_core.t_string,
            vx_core.vx_new(
              vx_core.t_anylist,
              sid,
              sclass,
              sstyle
            )
          ),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_footer_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_footer_indent(footer : vx_web_html.Type_footer, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_footer_indent : vx_core.Class_base, Func_string_from_footer_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_footer_indent = vx_web_html.Class_string_from_footer_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_footer_indent = vx_web_html.Class_string_from_footer_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_footer_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_footer_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var footer : vx_web_html.Type_footer = vx_core.f_any_from_any(vx_web_html.t_footer, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_footer_indent(footer, indent)
      return output
    }

    override fun vx_string_from_footer_indent(footer : vx_web_html.Type_footer, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_footer_indent(footer, indent)
      return output
    }

  }

  val e_string_from_footer_indent : vx_web_html.Func_string_from_footer_indent = vx_web_html.Class_string_from_footer_indent()
  val t_string_from_footer_indent : vx_web_html.Func_string_from_footer_indent = vx_web_html.Class_string_from_footer_indent()

  fun f_string_from_footer_indent(footer : vx_web_html.Type_footer, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_divchildlist = footer.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("footer"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_h1_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_h1_indent(h1 : vx_web_html.Type_h1, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_h1_indent : vx_core.Class_base, Func_string_from_h1_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h1_indent = vx_web_html.Class_string_from_h1_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h1_indent = vx_web_html.Class_string_from_h1_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_h1_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_h1_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var h1 : vx_web_html.Type_h1 = vx_core.f_any_from_any(vx_web_html.t_h1, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_h1_indent(h1, indent)
      return output
    }

    override fun vx_string_from_h1_indent(h1 : vx_web_html.Type_h1, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_h1_indent(h1, indent)
      return output
    }

  }

  val e_string_from_h1_indent : vx_web_html.Func_string_from_h1_indent = vx_web_html.Class_string_from_h1_indent()
  val t_string_from_h1_indent : vx_web_html.Func_string_from_h1_indent = vx_web_html.Class_string_from_h1_indent()

  fun f_string_from_h1_indent(h1 : vx_web_html.Type_h1, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var text : vx_core.Type_string = h1.text()
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          h1.id()
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<h1"),
            sid,
            vx_core.vx_new_string(">"),
            text,
            vx_core.vx_new_string("</h1>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_h2_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_h2_indent(h2 : vx_web_html.Type_h2, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_h2_indent : vx_core.Class_base, Func_string_from_h2_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h2_indent = vx_web_html.Class_string_from_h2_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h2_indent = vx_web_html.Class_string_from_h2_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_h2_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_h2_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var h2 : vx_web_html.Type_h2 = vx_core.f_any_from_any(vx_web_html.t_h2, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_h2_indent(h2, indent)
      return output
    }

    override fun vx_string_from_h2_indent(h2 : vx_web_html.Type_h2, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_h2_indent(h2, indent)
      return output
    }

  }

  val e_string_from_h2_indent : vx_web_html.Func_string_from_h2_indent = vx_web_html.Class_string_from_h2_indent()
  val t_string_from_h2_indent : vx_web_html.Func_string_from_h2_indent = vx_web_html.Class_string_from_h2_indent()

  fun f_string_from_h2_indent(h2 : vx_web_html.Type_h2, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = h2.text()
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          h2.id()
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<h2"),
            sid,
            vx_core.vx_new_string(">"),
            text,
            vx_core.vx_new_string("</h2>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_h3_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_h3_indent(h3 : vx_web_html.Type_h3, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_h3_indent : vx_core.Class_base, Func_string_from_h3_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h3_indent = vx_web_html.Class_string_from_h3_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_h3_indent = vx_web_html.Class_string_from_h3_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_h3_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_h3_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var h3 : vx_web_html.Type_h3 = vx_core.f_any_from_any(vx_web_html.t_h3, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_h3_indent(h3, indent)
      return output
    }

    override fun vx_string_from_h3_indent(h3 : vx_web_html.Type_h3, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_h3_indent(h3, indent)
      return output
    }

  }

  val e_string_from_h3_indent : vx_web_html.Func_string_from_h3_indent = vx_web_html.Class_string_from_h3_indent()
  val t_string_from_h3_indent : vx_web_html.Func_string_from_h3_indent = vx_web_html.Class_string_from_h3_indent()

  fun f_string_from_h3_indent(h3 : vx_web_html.Type_h3, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = h3.text()
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          h3.id()
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<h3"),
            sid,
            vx_core.vx_new_string(">"),
            text,
            vx_core.vx_new_string("</h3>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_head_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_head_indent(head : vx_web_html.Type_head, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_head_indent : vx_core.Class_base, Func_string_from_head_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_head_indent = vx_web_html.Class_string_from_head_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_head_indent = vx_web_html.Class_string_from_head_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_head_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_head_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var head : vx_web_html.Type_head = vx_core.f_any_from_any(vx_web_html.t_head, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_head_indent(head, indent)
      return output
    }

    override fun vx_string_from_head_indent(head : vx_web_html.Type_head, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_head_indent(head, indent)
      return output
    }

  }

  val e_string_from_head_indent : vx_web_html.Func_string_from_head_indent = vx_web_html.Class_string_from_head_indent()
  val t_string_from_head_indent : vx_web_html.Func_string_from_head_indent = vx_web_html.Class_string_from_head_indent()

  fun f_string_from_head_indent(head : vx_web_html.Type_head, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_headchildlist = head.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("head"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_html : vx_core.Func_any_from_any {
    fun vx_string_from_html(html : vx_web_html.Type_html) : vx_core.Type_string
  }

  class Class_string_from_html : vx_core.Class_base, Func_string_from_html {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_html = vx_web_html.Class_string_from_html()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_html = vx_web_html.Class_string_from_html()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_html
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_html
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_html = value as vx_web_html.Type_html
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_html(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var html : vx_web_html.Type_html = vx_core.f_any_from_any(vx_web_html.t_html, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_html(html)
      return output
    }

    override fun vx_string_from_html(html : vx_web_html.Type_html) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_html(html)
      return output
    }

  }

  val e_string_from_html : vx_web_html.Func_string_from_html = vx_web_html.Class_string_from_html()
  val t_string_from_html : vx_web_html.Func_string_from_html = vx_web_html.Class_string_from_html()

  fun f_string_from_html(html : vx_web_html.Type_html) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var lang : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("lang"),
          html.lang()
        )
        var head : vx_web_html.Type_head = html.head()
        var body : vx_web_html.Type_body = html.body()
        var footer : vx_web_html.Type_footer = html.footer()
        var shead : vx_core.Type_string = vx_web_html.f_string_from_head_indent(
          head,
          vx_core.vx_new_int(1)
        )
        var sbody : vx_core.Type_string = vx_web_html.f_string_from_body_indent(
          body,
          vx_core.vx_new_int(1)
        )
        var sfooter : vx_core.Type_string = vx_web_html.f_string_from_footer_indent(
          footer,
          vx_core.vx_new_int(1)
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("<!DOCTYPE html>"),
            vx_core.c_newline,
            vx_core.vx_new_string("<html"),
            lang,
            vx_core.vx_new_string(">"),
            shead,
            sbody,
            sfooter,
            vx_core.c_newline,
            vx_core.vx_new_string("</html>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_img_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_img_indent(img : vx_web_html.Type_img, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_img_indent : vx_core.Class_base, Func_string_from_img_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_img_indent = vx_web_html.Class_string_from_img_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_img_indent = vx_web_html.Class_string_from_img_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-img-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_img_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_img_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var img : vx_web_html.Type_img = vx_core.f_any_from_any(vx_web_html.t_img, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_img_indent(img, indent)
      return output
    }

    override fun vx_string_from_img_indent(img : vx_web_html.Type_img, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_img_indent(img, indent)
      return output
    }

  }

  val e_string_from_img_indent : vx_web_html.Func_string_from_img_indent = vx_web_html.Class_string_from_img_indent()
  val t_string_from_img_indent : vx_web_html.Func_string_from_img_indent = vx_web_html.Class_string_from_img_indent()

  fun f_string_from_img_indent(img : vx_web_html.Type_img, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var ssrc : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("src"),
          img.src()
        )
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          img.id()
        )
        var sclass : vx_core.Type_string = vx_web_html.f_string_from_propstyle_stylelist(
          img.style(),
          img.stylelist()
        )
        var sstyle : vx_core.Type_string = vx_web_html.f_string_from_propstyleunique(
          img.style_unique()
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<img"),
            sid,
            sclass,
            sstyle,
            ssrc,
            vx_core.vx_new_string(" />")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_indent : vx_core.Func_any_from_any {
    fun vx_string_from_indent(indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_indent : vx_core.Class_base, Func_string_from_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_indent = vx_web_html.Class_string_from_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_indent = vx_web_html.Class_string_from_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_indent
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_int = value as vx_core.Type_int
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_indent(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_indent(indent)
      return output
    }

    override fun vx_string_from_indent(indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_indent(indent)
      return output
    }

  }

  val e_string_from_indent : vx_web_html.Func_string_from_indent = vx_web_html.Class_string_from_indent()
  val t_string_from_indent : vx_web_html.Func_string_from_indent = vx_web_html.Class_string_from_indent()

  fun f_string_from_indent(indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_1(
      vx_core.t_string,
      vx_core.f_eq(
        indent,
        vx_core.vx_new_int(0)
      ),
      vx_core.vx_new_string(""),
      vx_core.f_new(
        vx_core.t_string,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.c_newline,
          vx_web_html.f_string_indent(
            indent
          )
        )
      )
    )
    return output
  }


  interface Func_string_from_meta_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_meta_indent(meta : vx_web_html.Type_meta, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_meta_indent : vx_core.Class_base, Func_string_from_meta_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_meta_indent = vx_web_html.Class_string_from_meta_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_meta_indent = vx_web_html.Class_string_from_meta_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_meta_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_meta_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var meta : vx_web_html.Type_meta = vx_core.f_any_from_any(vx_web_html.t_meta, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_meta_indent(meta, indent)
      return output
    }

    override fun vx_string_from_meta_indent(meta : vx_web_html.Type_meta, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_meta_indent(meta, indent)
      return output
    }

  }

  val e_string_from_meta_indent : vx_web_html.Func_string_from_meta_indent = vx_web_html.Class_string_from_meta_indent()
  val t_string_from_meta_indent : vx_web_html.Func_string_from_meta_indent = vx_web_html.Class_string_from_meta_indent()

  fun f_string_from_meta_indent(meta : vx_web_html.Type_meta, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var charset : vx_core.Type_string = meta.charset()
        var name : vx_core.Type_string = meta.name()
        var content : vx_core.Type_string = meta.content()
        var scharset : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_ne(
                  vx_core.vx_new_string(""),
                  charset
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_web_html.f_string_from_propname_val(
                  vx_core.vx_new_string("charset"),
                  charset
                )
                output_3
              })
            )
          )
        )
        var sname : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_ne(
                  vx_core.vx_new_string(""),
                  name
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_web_html.f_string_from_propname_val(
                  vx_core.vx_new_string("name"),
                  name
                )
                output_5
              })
            )
          )
        )
        var scontext : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_core.f_ne(
                  vx_core.vx_new_string(""),
                  content
                )
                output_6
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_web_html.f_string_from_propname_val(
                  vx_core.vx_new_string("content"),
                  content
                )
                output_7
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<meta"),
            scharset,
            sname,
            scontext,
            vx_core.vx_new_string(" />")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_node_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_node_indent(node : vx_core.Type_any, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_node_indent : vx_core.Class_base, Func_string_from_node_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_node_indent = vx_web_html.Class_string_from_node_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_node_indent = vx_web_html.Class_string_from_node_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_node_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_node_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var node : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_node_indent(node, indent)
      return output
    }

    override fun vx_string_from_node_indent(node : vx_core.Type_any, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_node_indent(node, indent)
      return output
    }

  }

  val e_string_from_node_indent : vx_web_html.Func_string_from_node_indent = vx_web_html.Class_string_from_node_indent()
  val t_string_from_node_indent : vx_web_html.Func_string_from_node_indent = vx_web_html.Class_string_from_node_indent()

  fun f_string_from_node_indent(node : vx_core.Type_any, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_switch(
      vx_core.t_string,
      vx_core.f_type_from_any(
        node
      ),
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_case_1(
          vx_web_html.t_body,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_web_html.f_string_from_body_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_body,
                node
              ),
              indent
            )
            output_1
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_details,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_web_html.f_string_from_details_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_details,
                node
              ),
              indent
            )
            output_2
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_div,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_web_html.f_string_from_div_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_div,
                node
              ),
              indent
            )
            output_3
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_h1,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_web_html.f_string_from_h1_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_h1,
                node
              ),
              indent
            )
            output_4
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_h2,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_5 : vx_core.Type_any = vx_web_html.f_string_from_h2_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_h2,
                node
              ),
              indent
            )
            output_5
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_h3,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_6 : vx_core.Type_any = vx_web_html.f_string_from_h3_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_h3,
                node
              ),
              indent
            )
            output_6
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_head,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_7 : vx_core.Type_any = vx_web_html.f_string_from_head_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_head,
                node
              ),
              indent
            )
            output_7
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_footer,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_8 : vx_core.Type_any = vx_web_html.f_string_from_footer_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_footer,
                node
              ),
              indent
            )
            output_8
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_img,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_9 : vx_core.Type_any = vx_web_html.f_string_from_img_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_img,
                node
              ),
              indent
            )
            output_9
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_meta,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_10 : vx_core.Type_any = vx_web_html.f_string_from_meta_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_meta,
                node
              ),
              indent
            )
            output_10
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_p,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_11 : vx_core.Type_any = vx_web_html.f_string_from_p_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_p,
                node
              ),
              indent
            )
            output_11
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_stylesheet,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_12 : vx_core.Type_any = vx_web_html.f_string_from_stylesheet_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_stylesheet,
                node
              ),
              indent
            )
            output_12
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_table,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_13 : vx_core.Type_any = vx_web_html.f_string_from_table_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_table,
                node
              ),
              indent
            )
            output_13
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_title,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_14 : vx_core.Type_any = vx_web_html.f_string_from_title_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_title,
                node
              ),
              indent
            )
            output_14
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_tbody,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_15 : vx_core.Type_any = vx_web_html.f_string_from_tbody_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_tbody,
                node
              ),
              indent
            )
            output_15
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_thead,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_16 : vx_core.Type_any = vx_web_html.f_string_from_thead_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_thead,
                node
              ),
              indent
            )
            output_16
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_td,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_17 : vx_core.Type_any = vx_web_html.f_string_from_td_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_td,
                node
              ),
              indent
            )
            output_17
          })
        ),
        vx_core.f_case_1(
          vx_web_html.t_tr,
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_18 : vx_core.Type_any = vx_web_html.f_string_from_tr_indent(
              vx_core.f_any_from_any(
                vx_web_html.t_tr,
                node
              ),
              indent
            )
            output_18
          })
        )
      )
    )
    return output
  }


  interface Func_string_from_nodelist_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_nodelist_indent(nodelist : vx_core.Type_list, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_nodelist_indent : vx_core.Class_base, Func_string_from_nodelist_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_nodelist_indent = vx_web_html.Class_string_from_nodelist_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_nodelist_indent = vx_web_html.Class_string_from_nodelist_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_nodelist_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_nodelist_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var nodelist : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_nodelist_indent(nodelist, indent)
      return output
    }

    override fun vx_string_from_nodelist_indent(nodelist : vx_core.Type_list, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_nodelist_indent(nodelist, indent)
      return output
    }

  }

  val e_string_from_nodelist_indent : vx_web_html.Func_string_from_nodelist_indent = vx_web_html.Class_string_from_nodelist_indent()
  val t_string_from_nodelist_indent : vx_web_html.Func_string_from_nodelist_indent = vx_web_html.Class_string_from_nodelist_indent()

  fun f_string_from_nodelist_indent(nodelist : vx_core.Type_list, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var textlist : vx_core.Type_stringlist = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          nodelist,
          vx_core.t_any_from_any.vx_fn_new({node_any : vx_core.Type_any ->
            var node : vx_web_html.Type_node = vx_core.f_any_from_any(vx_web_html.t_node, node_any)
            var output_2 : vx_core.Type_any = vx_web_html.f_string_from_node_indent(
              node,
              indent
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_type.f_string_from_stringlist_join(
          textlist,
          vx_core.vx_new_string("")
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_nodelist_tag_prop_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_nodelist_tag_prop_indent(nodes : vx_core.Type_list, tag : vx_core.Type_string, prop : vx_core.Type_string, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_nodelist_tag_prop_indent : vx_core.Class_base, Func_string_from_nodelist_tag_prop_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_nodelist_tag_prop_indent = vx_web_html.Class_string_from_nodelist_tag_prop_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_nodelist_tag_prop_indent = vx_web_html.Class_string_from_nodelist_tag_prop_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_nodelist_tag_prop_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_nodelist_tag_prop_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var nodes : vx_core.Type_list = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)))
      var tag : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var prop : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(2)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent)
      return output
    }

    override fun vx_string_from_nodelist_tag_prop_indent(nodes : vx_core.Type_list, tag : vx_core.Type_string, prop : vx_core.Type_string, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent)
      return output
    }

  }

  val e_string_from_nodelist_tag_prop_indent : vx_web_html.Func_string_from_nodelist_tag_prop_indent = vx_web_html.Class_string_from_nodelist_tag_prop_indent()
  val t_string_from_nodelist_tag_prop_indent : vx_web_html.Func_string_from_nodelist_tag_prop_indent = vx_web_html.Class_string_from_nodelist_tag_prop_indent()

  fun f_string_from_nodelist_tag_prop_indent(nodes : vx_core.Type_list, tag : vx_core.Type_string, prop : vx_core.Type_string, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = vx_web_html.f_string_from_nodelist_indent(
          nodes,
          vx_core.f_plus1(
            indent
          )
        )
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var eindent : vx_core.Type_string = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_is_empty(
                  text
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.vx_new_string("")
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_is_empty(
                  sindent
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = vx_core.c_newline
                output_5
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = sindent
                output_6
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<"),
            tag,
            prop,
            vx_core.vx_new_string(">"),
            text,
            eindent,
            vx_core.vx_new_string("</"),
            tag,
            vx_core.vx_new_string(">")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_p_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_p_indent(p : vx_web_html.Type_p, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_p_indent : vx_core.Class_base, Func_string_from_p_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_p_indent = vx_web_html.Class_string_from_p_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_p_indent = vx_web_html.Class_string_from_p_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_p_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_p_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var p : vx_web_html.Type_p = vx_core.f_any_from_any(vx_web_html.t_p, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_p_indent(p, indent)
      return output
    }

    override fun vx_string_from_p_indent(p : vx_web_html.Type_p, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_p_indent(p, indent)
      return output
    }

  }

  val e_string_from_p_indent : vx_web_html.Func_string_from_p_indent = vx_web_html.Class_string_from_p_indent()
  val t_string_from_p_indent : vx_web_html.Func_string_from_p_indent = vx_web_html.Class_string_from_p_indent()

  fun f_string_from_p_indent(p : vx_web_html.Type_p, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var text : vx_core.Type_string = vx_web_html.f_htmlstring_from_string(
          p.text()
        )
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          p.id()
        )
        var sclass : vx_core.Type_string = vx_web_html.f_string_from_propstyle_stylelist(
          p.style(),
          p.stylelist()
        )
        var sstyle : vx_core.Type_string = vx_web_html.f_string_from_propstyleunique(
          p.style_unique()
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<p"),
            sid,
            sclass,
            sstyle,
            vx_core.vx_new_string(">"),
            text,
            vx_core.vx_new_string("</p>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_propname_val : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_propname_val(key : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_from_propname_val : vx_core.Class_base, Func_string_from_propname_val {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propname_val = vx_web_html.Class_string_from_propname_val()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propname_val = vx_web_html.Class_string_from_propname_val()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_propname_val
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_propname_val
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var value : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_propname_val(key, value)
      return output
    }

    override fun vx_string_from_propname_val(key : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_propname_val(key, value)
      return output
    }

  }

  val e_string_from_propname_val : vx_web_html.Func_string_from_propname_val = vx_web_html.Class_string_from_propname_val()
  val t_string_from_propname_val : vx_web_html.Func_string_from_propname_val = vx_web_html.Class_string_from_propname_val()

  fun f_string_from_propname_val(key : vx_core.Type_string, value : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if(
      vx_core.t_string,
      vx_core.f_notempty(
        value
      ),
      vx_core.f_new(
        vx_core.t_string,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(" "),
          key,
          vx_core.vx_new_string("="),
          vx_core.c_quote,
          value,
          vx_core.c_quote
        )
      )
    )
    return output
  }


  interface Func_string_from_propstyle : vx_core.Func_any_from_any {
    fun vx_string_from_propstyle(style : vx_web_html.Type_style) : vx_core.Type_string
  }

  class Class_string_from_propstyle : vx_core.Class_base, Func_string_from_propstyle {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyle = vx_web_html.Class_string_from_propstyle()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyle = vx_web_html.Class_string_from_propstyle()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_propstyle
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_propstyle
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_style = value as vx_web_html.Type_style
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_propstyle(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var style : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_propstyle(style)
      return output
    }

    override fun vx_string_from_propstyle(style : vx_web_html.Type_style) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_propstyle(style)
      return output
    }

  }

  val e_string_from_propstyle : vx_web_html.Func_string_from_propstyle = vx_web_html.Class_string_from_propstyle()
  val t_string_from_propstyle : vx_web_html.Func_string_from_propstyle = vx_web_html.Class_string_from_propstyle()

  fun f_string_from_propstyle(style : vx_web_html.Type_style) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_notempty_1(
              style
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(" class="),
                vx_core.c_quote,
                vx_type.f_string_from_string_start(
                  style.name(),
                  vx_core.vx_new_int(2)
                ),
                vx_core.c_quote
              )
            )
            output_2
          })
        )
      )
    )
    return output
  }


  interface Func_string_from_propstyle_stylelist : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_propstyle_stylelist(style : vx_web_html.Type_style, stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string
  }

  class Class_string_from_propstyle_stylelist : vx_core.Class_base, Func_string_from_propstyle_stylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyle_stylelist = vx_web_html.Class_string_from_propstyle_stylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyle_stylelist = vx_web_html.Class_string_from_propstyle_stylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle-stylelist", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_propstyle_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_propstyle_stylelist
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var style : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      var stylelist : vx_web_html.Type_stylelist = vx_core.f_any_from_any(vx_web_html.t_stylelist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_propstyle_stylelist(style, stylelist)
      return output
    }

    override fun vx_string_from_propstyle_stylelist(style : vx_web_html.Type_style, stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_propstyle_stylelist(style, stylelist)
      return output
    }

  }

  val e_string_from_propstyle_stylelist : vx_web_html.Func_string_from_propstyle_stylelist = vx_web_html.Class_string_from_propstyle_stylelist()
  val t_string_from_propstyle_stylelist : vx_web_html.Func_string_from_propstyle_stylelist = vx_web_html.Class_string_from_propstyle_stylelist()

  fun f_string_from_propstyle_stylelist(style : vx_web_html.Type_style, stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_notempty_1(
              style
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_web_html.f_string_from_propstyle(
              style
            )
            output_2
          })
        ),
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_notempty_1(
              stylelist
            )
            output_3
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_4 : vx_core.Type_any = vx_web_html.f_string_from_propstylelist(
              stylelist
            )
            output_4
          })
        )
      )
    )
    return output
  }


  interface Func_string_from_propstylelist : vx_core.Func_any_from_any {
    fun vx_string_from_propstylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string
  }

  class Class_string_from_propstylelist : vx_core.Class_base, Func_string_from_propstylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstylelist = vx_web_html.Class_string_from_propstylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstylelist = vx_web_html.Class_string_from_propstylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstylelist", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_propstylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_propstylelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylelist = value as vx_web_html.Type_stylelist
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_propstylelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylelist : vx_web_html.Type_stylelist = vx_core.f_any_from_any(vx_web_html.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_propstylelist(stylelist)
      return output
    }

    override fun vx_string_from_propstylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_propstylelist(stylelist)
      return output
    }

  }

  val e_string_from_propstylelist : vx_web_html.Func_string_from_propstylelist = vx_web_html.Class_string_from_propstylelist()
  val t_string_from_propstylelist : vx_web_html.Func_string_from_propstylelist = vx_web_html.Class_string_from_propstylelist()

  fun f_string_from_propstylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_notempty_1(
              stylelist
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_let(
              vx_core.t_string,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var joined : vx_core.Type_string = vx_web_html.f_string_from_stylelist(
                  stylelist
                )
                var output_3 : vx_core.Type_any = vx_core.f_if(
                  vx_core.t_string,
                  vx_core.f_ne(
                    vx_core.vx_new_string(""),
                    joined
                  ),
                  vx_core.f_new(
                    vx_core.t_string,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(" class="),
                      vx_core.c_quote,
                      joined,
                      vx_core.c_quote
                    )
                  )
                )
                output_3
              })
            )
            output_2
          })
        )
      )
    )
    return output
  }


  interface Func_string_from_propstyleunique : vx_core.Func_any_from_any {
    fun vx_string_from_propstyleunique(style : vx_web_html.Type_style) : vx_core.Type_string
  }

  class Class_string_from_propstyleunique : vx_core.Class_base, Func_string_from_propstyleunique {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyleunique = vx_web_html.Class_string_from_propstyleunique()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_propstyleunique = vx_web_html.Class_string_from_propstyleunique()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyleunique", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_propstyleunique
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_propstyleunique
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_style = value as vx_web_html.Type_style
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_propstyleunique(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var style : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_propstyleunique(style)
      return output
    }

    override fun vx_string_from_propstyleunique(style : vx_web_html.Type_style) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_propstyleunique(style)
      return output
    }

  }

  val e_string_from_propstyleunique : vx_web_html.Func_string_from_propstyleunique = vx_web_html.Class_string_from_propstyleunique()
  val t_string_from_propstyleunique : vx_web_html.Func_string_from_propstyleunique = vx_web_html.Class_string_from_propstyleunique()

  fun f_string_from_propstyleunique(style : vx_web_html.Type_style) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_if_2(
      vx_core.t_string,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_notempty_1(
              style
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = vx_core.f_let(
              vx_core.t_string,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var props : vx_web_html.Type_propmap = style.props()
                var text : vx_core.Type_string = vx_web_html.f_string_from_stylepropmap_indent(
                  props,
                  vx_core.vx_new_int(0)
                )
                var output_3 : vx_core.Type_any = vx_core.f_if_2(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_thenelselist,
                    vx_core.f_then(
                      vx_core.t_boolean_from_func.vx_fn_new({ ->
                        var output_4 : vx_core.Type_any = vx_core.f_notempty(
                          text
                        )
                        output_4
                      }),
                      vx_core.t_any_from_func.vx_fn_new({ ->
                        var output_5 : vx_core.Type_any = vx_core.f_new(
                          vx_core.t_string,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(" style="),
                            vx_core.c_quote,
                            text,
                            vx_core.c_quote
                          )
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
      )
    )
    return output
  }


  interface Func_string_from_style_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_style_indent(style : vx_web_html.Type_style, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_style_indent : vx_core.Class_base, Func_string_from_style_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_style_indent = vx_web_html.Class_string_from_style_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_style_indent = vx_web_html.Class_string_from_style_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_style_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_style_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var style : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_style_indent(style, indent)
      return output
    }

    override fun vx_string_from_style_indent(style : vx_web_html.Type_style, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_style_indent(style, indent)
      return output
    }

  }

  val e_string_from_style_indent : vx_web_html.Func_string_from_style_indent = vx_web_html.Class_string_from_style_indent()
  val t_string_from_style_indent : vx_web_html.Func_string_from_style_indent = vx_web_html.Class_string_from_style_indent()

  fun f_string_from_style_indent(style : vx_web_html.Type_style, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var name : vx_core.Type_string = style.name()
        var propmap : vx_web_html.Type_propmap = style.props()
        var sublist : vx_web_html.Type_stylelist = style.stylelist()
        var stext : vx_core.Type_string = vx_web_html.f_string_from_stylepropmap_indent(
          propmap,
          vx_core.f_plus1(
            indent
          )
        )
        var subtext : vx_core.Type_string = vx_web_html.f_string_from_stylelist_indent(
          sublist,
          vx_core.f_plus1(
            indent
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            name,
            vx_core.vx_new_string(" {"),
            stext,
            subtext,
            sindent,
            vx_core.vx_new_string("}")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_stylelist : vx_core.Func_any_from_any {
    fun vx_string_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string
  }

  class Class_string_from_stylelist : vx_core.Class_base, Func_string_from_stylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylelist = vx_web_html.Class_string_from_stylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylelist = vx_web_html.Class_string_from_stylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_stylelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylelist = value as vx_web_html.Type_stylelist
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_stylelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylelist : vx_web_html.Type_stylelist = vx_core.f_any_from_any(vx_web_html.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_stylelist(stylelist)
      return output
    }

    override fun vx_string_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_stylelist(stylelist)
      return output
    }

  }

  val e_string_from_stylelist : vx_web_html.Func_string_from_stylelist = vx_web_html.Class_string_from_stylelist()
  val t_string_from_stylelist : vx_web_html.Func_string_from_stylelist = vx_web_html.Class_string_from_stylelist()

  fun f_string_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var namelist : vx_core.Type_stringlist = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          stylelist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, item_any)
            var output_2 : vx_core.Type_any = vx_type.f_string_from_string_start(
              item.name(),
              vx_core.vx_new_int(2)
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_type.f_string_from_stringlist_join(
          namelist,
          vx_core.vx_new_string(" ")
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_stylelist_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_stylelist_indent(stylelist : vx_web_html.Type_stylelist, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_stylelist_indent : vx_core.Class_base, Func_string_from_stylelist_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylelist_indent = vx_web_html.Class_string_from_stylelist_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylelist_indent = vx_web_html.Class_string_from_stylelist_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_stylelist_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_stylelist_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylelist : vx_web_html.Type_stylelist = vx_core.f_any_from_any(vx_web_html.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_stylelist_indent(stylelist, indent)
      return output
    }

    override fun vx_string_from_stylelist_indent(stylelist : vx_web_html.Type_stylelist, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_stylelist_indent(stylelist, indent)
      return output
    }

  }

  val e_string_from_stylelist_indent : vx_web_html.Func_string_from_stylelist_indent = vx_web_html.Class_string_from_stylelist_indent()
  val t_string_from_stylelist_indent : vx_web_html.Func_string_from_stylelist_indent = vx_web_html.Class_string_from_stylelist_indent()

  fun f_string_from_stylelist_indent(stylelist : vx_web_html.Type_stylelist, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sstyles : vx_core.Type_stringlist = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          stylelist,
          vx_core.t_any_from_any.vx_fn_new({substyle_any : vx_core.Type_any ->
            var substyle : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, substyle_any)
            var output_2 : vx_core.Type_any = vx_web_html.f_string_from_style_indent(
              substyle,
              indent
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_type.f_string_from_stringlist_join(
          sstyles,
          vx_core.c_newline
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_stylepropmap_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_stylepropmap_indent(propmap : vx_web_html.Type_propmap, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_stylepropmap_indent : vx_core.Class_base, Func_string_from_stylepropmap_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylepropmap_indent = vx_web_html.Class_string_from_stylepropmap_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylepropmap_indent = vx_web_html.Class_string_from_stylepropmap_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_stylepropmap_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_stylepropmap_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var propmap : vx_web_html.Type_propmap = vx_core.f_any_from_any(vx_web_html.t_propmap, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_stylepropmap_indent(propmap, indent)
      return output
    }

    override fun vx_string_from_stylepropmap_indent(propmap : vx_web_html.Type_propmap, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_stylepropmap_indent(propmap, indent)
      return output
    }

  }

  val e_string_from_stylepropmap_indent : vx_web_html.Func_string_from_stylepropmap_indent = vx_web_html.Class_string_from_stylepropmap_indent()
  val t_string_from_stylepropmap_indent : vx_web_html.Func_string_from_stylepropmap_indent = vx_web_html.Class_string_from_stylepropmap_indent()

  fun f_string_from_stylepropmap_indent(propmap : vx_web_html.Type_propmap, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var sprops : vx_core.Type_stringlist = vx_core.f_list_from_map_1(
          vx_core.t_stringlist,
          propmap,
          vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var value : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value_any)
            var output_2 : vx_core.Type_any = vx_core.f_new(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_anylist,
                sindent,
                key,
                vx_core.vx_new_string(": "),
                value,
                vx_core.vx_new_string(";")
              )
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = vx_type.f_string_from_stringlist_join(
          sprops,
          vx_core.vx_new_string("")
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_stylesheet_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_stylesheet_indent(stylesheet : vx_web_html.Type_stylesheet, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_stylesheet_indent : vx_core.Class_base, Func_string_from_stylesheet_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylesheet_indent = vx_web_html.Class_string_from_stylesheet_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_stylesheet_indent = vx_web_html.Class_string_from_stylesheet_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_stylesheet_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_stylesheet_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_stylesheet_indent(stylesheet, indent)
      return output
    }

    override fun vx_string_from_stylesheet_indent(stylesheet : vx_web_html.Type_stylesheet, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_stylesheet_indent(stylesheet, indent)
      return output
    }

  }

  val e_string_from_stylesheet_indent : vx_web_html.Func_string_from_stylesheet_indent = vx_web_html.Class_string_from_stylesheet_indent()
  val t_string_from_stylesheet_indent : vx_web_html.Func_string_from_stylesheet_indent = vx_web_html.Class_string_from_stylesheet_indent()

  fun f_string_from_stylesheet_indent(stylesheet : vx_web_html.Type_stylesheet, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var styles : vx_web_html.Type_stylelist = stylesheet.styles()
        var sstyles : vx_core.Type_string = vx_web_html.f_string_from_stylelist_indent(
          styles,
          vx_core.f_plus1(
            indent
          )
        )
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var eindent : vx_core.Type_string = vx_core.f_if(
          vx_core.t_string,
          vx_core.f_notempty(
            sstyles
          ),
          sindent
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<style>"),
            sstyles,
            eindent,
            vx_core.vx_new_string("</style>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_table_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_table_indent(table : vx_web_html.Type_table, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_table_indent : vx_core.Class_base, Func_string_from_table_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_table_indent = vx_web_html.Class_string_from_table_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_table_indent = vx_web_html.Class_string_from_table_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_table_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_table_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var table : vx_web_html.Type_table = vx_core.f_any_from_any(vx_web_html.t_table, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_table_indent(table, indent)
      return output
    }

    override fun vx_string_from_table_indent(table : vx_web_html.Type_table, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_table_indent(table, indent)
      return output
    }

  }

  val e_string_from_table_indent : vx_web_html.Func_string_from_table_indent = vx_web_html.Class_string_from_table_indent()
  val t_string_from_table_indent : vx_web_html.Func_string_from_table_indent = vx_web_html.Class_string_from_table_indent()

  fun f_string_from_table_indent(table : vx_web_html.Type_table, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var sid : vx_core.Type_string = vx_web_html.f_string_from_propname_val(
          vx_core.vx_new_string("id"),
          table.id()
        )
        var thead : vx_web_html.Type_thead = table.thead()
        var tbody : vx_web_html.Type_tbody = table.tbody()
        var shead : vx_core.Type_string = vx_web_html.f_string_from_thead_indent(
          thead,
          vx_core.f_plus1(
            indent
          )
        )
        var sbody : vx_core.Type_string = vx_web_html.f_string_from_tbody_indent(
          tbody,
          vx_core.f_plus1(
            indent
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<table"),
            sid,
            vx_core.vx_new_string(">"),
            shead,
            sbody,
            sindent,
            vx_core.vx_new_string("</table>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_tbody_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_tbody_indent(tbody : vx_web_html.Type_tbody, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_tbody_indent : vx_core.Class_base, Func_string_from_tbody_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_tbody_indent = vx_web_html.Class_string_from_tbody_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_tbody_indent = vx_web_html.Class_string_from_tbody_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_tbody_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_tbody_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var tbody : vx_web_html.Type_tbody = vx_core.f_any_from_any(vx_web_html.t_tbody, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_tbody_indent(tbody, indent)
      return output
    }

    override fun vx_string_from_tbody_indent(tbody : vx_web_html.Type_tbody, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_tbody_indent(tbody, indent)
      return output
    }

  }

  val e_string_from_tbody_indent : vx_web_html.Func_string_from_tbody_indent = vx_web_html.Class_string_from_tbody_indent()
  val t_string_from_tbody_indent : vx_web_html.Func_string_from_tbody_indent = vx_web_html.Class_string_from_tbody_indent()

  fun f_string_from_tbody_indent(tbody : vx_web_html.Type_tbody, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_trlist = tbody.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("tbody"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_td_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_td_indent(td : vx_web_html.Type_td, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_td_indent : vx_core.Class_base, Func_string_from_td_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_td_indent = vx_web_html.Class_string_from_td_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_td_indent = vx_web_html.Class_string_from_td_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_td_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_td_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var td : vx_web_html.Type_td = vx_core.f_any_from_any(vx_web_html.t_td, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_td_indent(td, indent)
      return output
    }

    override fun vx_string_from_td_indent(td : vx_web_html.Type_td, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_td_indent(td, indent)
      return output
    }

  }

  val e_string_from_td_indent : vx_web_html.Func_string_from_td_indent = vx_web_html.Class_string_from_td_indent()
  val t_string_from_td_indent : vx_web_html.Func_string_from_td_indent = vx_web_html.Class_string_from_td_indent()

  fun f_string_from_td_indent(td : vx_web_html.Type_td, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_divchildlist = td.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("td"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_thead_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_thead_indent(thead : vx_web_html.Type_thead, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_thead_indent : vx_core.Class_base, Func_string_from_thead_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_thead_indent = vx_web_html.Class_string_from_thead_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_thead_indent = vx_web_html.Class_string_from_thead_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_thead_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_thead_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var thead : vx_web_html.Type_thead = vx_core.f_any_from_any(vx_web_html.t_thead, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_thead_indent(thead, indent)
      return output
    }

    override fun vx_string_from_thead_indent(thead : vx_web_html.Type_thead, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_thead_indent(thead, indent)
      return output
    }

  }

  val e_string_from_thead_indent : vx_web_html.Func_string_from_thead_indent = vx_web_html.Class_string_from_thead_indent()
  val t_string_from_thead_indent : vx_web_html.Func_string_from_thead_indent = vx_web_html.Class_string_from_thead_indent()

  fun f_string_from_thead_indent(thead : vx_web_html.Type_thead, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_trlist = thead.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("thead"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_title_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_title_indent(title : vx_web_html.Type_title, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_title_indent : vx_core.Class_base, Func_string_from_title_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_title_indent = vx_web_html.Class_string_from_title_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_title_indent = vx_web_html.Class_string_from_title_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_title_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_title_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var title : vx_web_html.Type_title = vx_core.f_any_from_any(vx_web_html.t_title, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_title_indent(title, indent)
      return output
    }

    override fun vx_string_from_title_indent(title : vx_web_html.Type_title, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_title_indent(title, indent)
      return output
    }

  }

  val e_string_from_title_indent : vx_web_html.Func_string_from_title_indent = vx_web_html.Class_string_from_title_indent()
  val t_string_from_title_indent : vx_web_html.Func_string_from_title_indent = vx_web_html.Class_string_from_title_indent()

  fun f_string_from_title_indent(title : vx_web_html.Type_title, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var sindent : vx_core.Type_string = vx_web_html.f_string_from_indent(
          indent
        )
        var text : vx_core.Type_string = title.text()
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            sindent,
            vx_core.vx_new_string("<title>"),
            text,
            vx_core.vx_new_string("</title>")
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_tr_indent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_string_from_tr_indent(tr : vx_web_html.Type_tr, indent : vx_core.Type_int) : vx_core.Type_string
  }

  class Class_string_from_tr_indent : vx_core.Class_base, Func_string_from_tr_indent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_tr_indent = vx_web_html.Class_string_from_tr_indent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_tr_indent = vx_web_html.Class_string_from_tr_indent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_tr_indent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_tr_indent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var tr : vx_web_html.Type_tr = vx_core.f_any_from_any(vx_web_html.t_tr, arglist.vx_any(vx_core.vx_new_int(0)))
      var indent : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_string_from_tr_indent(tr, indent)
      return output
    }

    override fun vx_string_from_tr_indent(tr : vx_web_html.Type_tr, indent : vx_core.Type_int) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_tr_indent(tr, indent)
      return output
    }

  }

  val e_string_from_tr_indent : vx_web_html.Func_string_from_tr_indent = vx_web_html.Class_string_from_tr_indent()
  val t_string_from_tr_indent : vx_web_html.Func_string_from_tr_indent = vx_web_html.Class_string_from_tr_indent()

  fun f_string_from_tr_indent(tr : vx_web_html.Type_tr, indent : vx_core.Type_int) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var nodes : vx_web_html.Type_tdlist = tr.nodes()
        var output_1 : vx_core.Type_any = vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core.vx_new_string("tr"),
          vx_core.vx_new_string(""),
          indent
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_from_uri : vx_core.Func_any_from_any {
    fun vx_string_from_uri(uri : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_from_uri : vx_core.Class_base, Func_string_from_uri {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_uri = vx_web_html.Class_string_from_uri()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_string_from_uri = vx_web_html.Class_string_from_uri()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
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
      var output : vx_core.Type_any = vx_web_html.e_string_from_uri
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_string_from_uri
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_html.f_string_from_uri(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uri : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_string_from_uri(uri)
      return output
    }

    override fun vx_string_from_uri(uri : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_string_from_uri(uri)
      return output
    }

  }

  val e_string_from_uri : vx_web_html.Func_string_from_uri = vx_web_html.Class_string_from_uri()
  val t_string_from_uri : vx_web_html.Func_string_from_uri = vx_web_html.Class_string_from_uri()

  fun f_string_from_uri(uri : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    return output
  }


  interface Func_style_from_stylesheet_name : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_style_from_stylesheet_name(stylesheet : vx_web_html.Type_stylesheet, name : vx_core.Type_string) : vx_web_html.Type_style
  }

  class Class_style_from_stylesheet_name : vx_core.Class_base, Func_style_from_stylesheet_name {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_style_from_stylesheet_name = vx_web_html.Class_style_from_stylesheet_name()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_style_from_stylesheet_name = vx_web_html.Class_style_from_stylesheet_name()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
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
      var output : vx_core.Type_any = vx_web_html.e_style_from_stylesheet_name
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_style_from_stylesheet_name
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      var name : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_web_html.f_style_from_stylesheet_name(stylesheet, name)
      return output
    }

    override fun vx_style_from_stylesheet_name(stylesheet : vx_web_html.Type_stylesheet, name : vx_core.Type_string) : vx_web_html.Type_style {
      var output : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(stylesheet, name)
      return output
    }

  }

  val e_style_from_stylesheet_name : vx_web_html.Func_style_from_stylesheet_name = vx_web_html.Class_style_from_stylesheet_name()
  val t_style_from_stylesheet_name : vx_web_html.Func_style_from_stylesheet_name = vx_web_html.Class_style_from_stylesheet_name()

  fun f_style_from_stylesheet_name(stylesheet : vx_web_html.Type_stylesheet, name : vx_core.Type_string) : vx_web_html.Type_style {
    var output : vx_web_html.Type_style = vx_web_html.e_style
    output = vx_core.f_any_from_map(
      vx_web_html.t_style,
      vx_web_html.f_stylemap_from_stylesheet(
        stylesheet
      ),
      name
    )
    return output
  }


  interface Func_stylemap_from_stylelist : vx_core.Func_any_from_any {
    fun vx_stylemap_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_web_html.Type_stylemap
  }

  class Class_stylemap_from_stylelist : vx_core.Class_base, Func_stylemap_from_stylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylemap_from_stylelist = vx_web_html.Class_stylemap_from_stylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylemap_from_stylelist = vx_web_html.Class_stylemap_from_stylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_web_html.e_stylemap_from_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylemap_from_stylelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylelist = value as vx_web_html.Type_stylelist
      var outputval : vx_core.Type_any = vx_web_html.f_stylemap_from_stylelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylelist : vx_web_html.Type_stylelist = vx_core.f_any_from_any(vx_web_html.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_stylemap_from_stylelist(stylelist)
      return output
    }

    override fun vx_stylemap_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_web_html.Type_stylemap {
      var output : vx_web_html.Type_stylemap = vx_web_html.f_stylemap_from_stylelist(stylelist)
      return output
    }

  }

  val e_stylemap_from_stylelist : vx_web_html.Func_stylemap_from_stylelist = vx_web_html.Class_stylemap_from_stylelist()
  val t_stylemap_from_stylelist : vx_web_html.Func_stylemap_from_stylelist = vx_web_html.Class_stylemap_from_stylelist()

  fun f_stylemap_from_stylelist(stylelist : vx_web_html.Type_stylelist) : vx_web_html.Type_stylemap {
    var output : vx_web_html.Type_stylemap = vx_web_html.e_stylemap
    output = vx_core.f_map_from_list(
      vx_web_html.t_stylemap,
      stylelist,
      vx_core.t_any_from_any.vx_fn_new({style_any : vx_core.Type_any ->
        var style : vx_web_html.Type_style = vx_core.f_any_from_any(vx_web_html.t_style, style_any)
        var output_1 : vx_core.Type_any = style.name()
        output_1
      })
    )
    return output
  }


  interface Func_stylemap_from_stylesheet : vx_core.Func_any_from_any {
    fun vx_stylemap_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylemap
  }

  class Class_stylemap_from_stylesheet : vx_core.Class_base, Func_stylemap_from_stylesheet {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylemap_from_stylesheet = vx_web_html.Class_stylemap_from_stylesheet()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylemap_from_stylesheet = vx_web_html.Class_stylemap_from_stylesheet()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_web_html.e_stylemap_from_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylemap_from_stylesheet
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylesheet = value as vx_web_html.Type_stylesheet
      var outputval : vx_core.Type_any = vx_web_html.f_stylemap_from_stylesheet(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_stylemap_from_stylesheet(stylesheet)
      return output
    }

    override fun vx_stylemap_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylemap {
      var output : vx_web_html.Type_stylemap = vx_web_html.f_stylemap_from_stylesheet(stylesheet)
      return output
    }

  }

  val e_stylemap_from_stylesheet : vx_web_html.Func_stylemap_from_stylesheet = vx_web_html.Class_stylemap_from_stylesheet()
  val t_stylemap_from_stylesheet : vx_web_html.Func_stylemap_from_stylesheet = vx_web_html.Class_stylemap_from_stylesheet()

  fun f_stylemap_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylemap {
    var output : vx_web_html.Type_stylemap = vx_web_html.e_stylemap
    output = stylesheet.stylemap()
    return output
  }


  interface Func_styles_from_stylesheet : vx_core.Func_any_from_any {
    fun vx_styles_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylelist
  }

  class Class_styles_from_stylesheet : vx_core.Class_base, Func_styles_from_stylesheet {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_styles_from_stylesheet = vx_web_html.Class_styles_from_stylesheet()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_styles_from_stylesheet = vx_web_html.Class_styles_from_stylesheet()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_web_html.e_styles_from_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_styles_from_stylesheet
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylesheet = value as vx_web_html.Type_stylesheet
      var outputval : vx_core.Type_any = vx_web_html.f_styles_from_stylesheet(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_styles_from_stylesheet(stylesheet)
      return output
    }

    override fun vx_styles_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylelist {
      var output : vx_web_html.Type_stylelist = vx_web_html.f_styles_from_stylesheet(stylesheet)
      return output
    }

  }

  val e_styles_from_stylesheet : vx_web_html.Func_styles_from_stylesheet = vx_web_html.Class_styles_from_stylesheet()
  val t_styles_from_stylesheet : vx_web_html.Func_styles_from_stylesheet = vx_web_html.Class_styles_from_stylesheet()

  fun f_styles_from_stylesheet(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylelist {
    var output : vx_web_html.Type_stylelist = vx_web_html.e_stylelist
    output = stylesheet.styles()
    return output
  }


  interface Func_stylesheet_loadmap : vx_core.Func_any_from_any {
    fun vx_stylesheet_loadmap(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylesheet
  }

  class Class_stylesheet_loadmap : vx_core.Class_base, Func_stylesheet_loadmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylesheet_loadmap = vx_web_html.Class_stylesheet_loadmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_stylesheet_loadmap = vx_web_html.Class_stylesheet_loadmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_web_html.t_node, vx_web_html.t_headchild), // traits
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
      var output : vx_core.Type_any = vx_web_html.e_stylesheet_loadmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_stylesheet_loadmap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_stylesheet = value as vx_web_html.Type_stylesheet
      var outputval : vx_core.Type_any = vx_web_html.f_stylesheet_loadmap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheet : vx_web_html.Type_stylesheet = vx_core.f_any_from_any(vx_web_html.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_stylesheet_loadmap(stylesheet)
      return output
    }

    override fun vx_stylesheet_loadmap(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylesheet {
      var output : vx_web_html.Type_stylesheet = vx_web_html.f_stylesheet_loadmap(stylesheet)
      return output
    }

  }

  val e_stylesheet_loadmap : vx_web_html.Func_stylesheet_loadmap = vx_web_html.Class_stylesheet_loadmap()
  val t_stylesheet_loadmap : vx_web_html.Func_stylesheet_loadmap = vx_web_html.Class_stylesheet_loadmap()

  fun f_stylesheet_loadmap(stylesheet : vx_web_html.Type_stylesheet) : vx_web_html.Type_stylesheet {
    var output : vx_web_html.Type_stylesheet = vx_web_html.e_stylesheet
    output = vx_core.f_copy(
      stylesheet,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":stylemap"),
        vx_web_html.f_stylemap_from_stylelist(
          stylesheet.styles()
        )
      )
    )
    return output
  }


  interface Func_uri_from_string : vx_core.Func_any_from_any {
    fun vx_uri_from_string(text : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_uri_from_string : vx_core.Class_base, Func_uri_from_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_uri_from_string = vx_web_html.Class_uri_from_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_html.Class_uri_from_string = vx_web_html.Class_uri_from_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
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
      var output : vx_core.Type_any = vx_web_html.e_uri_from_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_html.t_uri_from_string
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_web_html.f_uri_from_string(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_html.f_uri_from_string(text)
      return output
    }

    override fun vx_uri_from_string(text : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_html.f_uri_from_string(text)
      return output
    }

  }

  val e_uri_from_string : vx_web_html.Func_uri_from_string = vx_web_html.Class_uri_from_string()
  val t_uri_from_string : vx_web_html.Func_uri_from_string = vx_web_html.Class_uri_from_string()

  fun f_uri_from_string(text : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("body", vx_web_html.t_body)
    maptype.put("details", vx_web_html.t_details)
    maptype.put("div", vx_web_html.t_div)
    maptype.put("divchild", vx_web_html.t_divchild)
    maptype.put("divchildlist", vx_web_html.t_divchildlist)
    maptype.put("divlist", vx_web_html.t_divlist)
    maptype.put("footer", vx_web_html.t_footer)
    maptype.put("h1", vx_web_html.t_h1)
    maptype.put("h2", vx_web_html.t_h2)
    maptype.put("h3", vx_web_html.t_h3)
    maptype.put("head", vx_web_html.t_head)
    maptype.put("headchild", vx_web_html.t_headchild)
    maptype.put("headchildlist", vx_web_html.t_headchildlist)
    maptype.put("html", vx_web_html.t_html)
    maptype.put("img", vx_web_html.t_img)
    maptype.put("meta", vx_web_html.t_meta)
    maptype.put("node", vx_web_html.t_node)
    maptype.put("nodelist", vx_web_html.t_nodelist)
    maptype.put("p", vx_web_html.t_p)
    maptype.put("propmap", vx_web_html.t_propmap)
    maptype.put("style", vx_web_html.t_style)
    maptype.put("stylelist", vx_web_html.t_stylelist)
    maptype.put("stylemap", vx_web_html.t_stylemap)
    maptype.put("stylesheet", vx_web_html.t_stylesheet)
    maptype.put("table", vx_web_html.t_table)
    maptype.put("tbody", vx_web_html.t_tbody)
    maptype.put("td", vx_web_html.t_td)
    maptype.put("tdlist", vx_web_html.t_tdlist)
    maptype.put("thead", vx_web_html.t_thead)
    maptype.put("title", vx_web_html.t_title)
    maptype.put("tr", vx_web_html.t_tr)
    maptype.put("trlist", vx_web_html.t_trlist)
    mapfunc.put("htmlstring<-string", vx_web_html.t_htmlstring_from_string)
    mapfunc.put("string-indent", vx_web_html.t_string_indent)
    mapfunc.put("string<-body-indent", vx_web_html.t_string_from_body_indent)
    mapfunc.put("string<-details-indent", vx_web_html.t_string_from_details_indent)
    mapfunc.put("string<-div-indent", vx_web_html.t_string_from_div_indent)
    mapfunc.put("string<-footer-indent", vx_web_html.t_string_from_footer_indent)
    mapfunc.put("string<-h1-indent", vx_web_html.t_string_from_h1_indent)
    mapfunc.put("string<-h2-indent", vx_web_html.t_string_from_h2_indent)
    mapfunc.put("string<-h3-indent", vx_web_html.t_string_from_h3_indent)
    mapfunc.put("string<-head-indent", vx_web_html.t_string_from_head_indent)
    mapfunc.put("string<-html", vx_web_html.t_string_from_html)
    mapfunc.put("string<-img-indent", vx_web_html.t_string_from_img_indent)
    mapfunc.put("string<-indent", vx_web_html.t_string_from_indent)
    mapfunc.put("string<-meta-indent", vx_web_html.t_string_from_meta_indent)
    mapfunc.put("string<-node-indent", vx_web_html.t_string_from_node_indent)
    mapfunc.put("string<-nodelist-indent", vx_web_html.t_string_from_nodelist_indent)
    mapfunc.put("string<-nodelist-tag-prop-indent", vx_web_html.t_string_from_nodelist_tag_prop_indent)
    mapfunc.put("string<-p-indent", vx_web_html.t_string_from_p_indent)
    mapfunc.put("string<-propname-val", vx_web_html.t_string_from_propname_val)
    mapfunc.put("string<-propstyle", vx_web_html.t_string_from_propstyle)
    mapfunc.put("string<-propstyle-stylelist", vx_web_html.t_string_from_propstyle_stylelist)
    mapfunc.put("string<-propstylelist", vx_web_html.t_string_from_propstylelist)
    mapfunc.put("string<-propstyleunique", vx_web_html.t_string_from_propstyleunique)
    mapfunc.put("string<-style-indent", vx_web_html.t_string_from_style_indent)
    mapfunc.put("string<-stylelist", vx_web_html.t_string_from_stylelist)
    mapfunc.put("string<-stylelist-indent", vx_web_html.t_string_from_stylelist_indent)
    mapfunc.put("string<-stylepropmap-indent", vx_web_html.t_string_from_stylepropmap_indent)
    mapfunc.put("string<-stylesheet-indent", vx_web_html.t_string_from_stylesheet_indent)
    mapfunc.put("string<-table-indent", vx_web_html.t_string_from_table_indent)
    mapfunc.put("string<-tbody-indent", vx_web_html.t_string_from_tbody_indent)
    mapfunc.put("string<-td-indent", vx_web_html.t_string_from_td_indent)
    mapfunc.put("string<-thead-indent", vx_web_html.t_string_from_thead_indent)
    mapfunc.put("string<-title-indent", vx_web_html.t_string_from_title_indent)
    mapfunc.put("string<-tr-indent", vx_web_html.t_string_from_tr_indent)
    mapfunc.put("string<-uri", vx_web_html.t_string_from_uri)
    mapfunc.put("style<-stylesheet-name", vx_web_html.t_style_from_stylesheet_name)
    mapfunc.put("stylemap<-stylelist", vx_web_html.t_stylemap_from_stylelist)
    mapfunc.put("stylemap<-stylesheet", vx_web_html.t_stylemap_from_stylesheet)
    mapfunc.put("styles<-stylesheet", vx_web_html.t_styles_from_stylesheet)
    mapfunc.put("stylesheet-loadmap", vx_web_html.t_stylesheet_loadmap)
    mapfunc.put("uri<-string", vx_web_html.t_uri_from_string)
    vx_core.vx_global_package_set("vx/web/html", maptype, mapconst, mapfunc)
  }

}
