package com.vxlisp.vx.ui

import com.vxlisp.vx.*
import com.vxlisp.vx.data.*

object vx_ui_ui {


  interface Type_align : vx_core.Type_struct {
  }

  class Class_align : vx_core.Class_base, Type_align {
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
      var output : vx_ui_ui.Type_align = vx_core.vx_copy(vx_ui_ui.e_align, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_align = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_align = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_align = vx_ui_ui.Class_align()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_align
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_align
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "align", // name
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

  val e_align : vx_ui_ui.Type_align = vx_ui_ui.Class_align()
  val t_align : vx_ui_ui.Type_align = vx_ui_ui.Class_align()

  interface Type_bounds : vx_core.Type_struct {
    fun left() : vx_core.Type_int
    fun right() : vx_core.Type_int
    fun top() : vx_core.Type_int
    fun bottom() : vx_core.Type_int
  }

  class Class_bounds : vx_core.Class_base, Type_bounds {
    constructor() {}

    var vx_p_left : vx_core.Type_int? = null

    override fun left() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_left
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_right : vx_core.Type_int? = null

    override fun right() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_right
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_top : vx_core.Type_int? = null

    override fun top() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_top
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_bottom : vx_core.Type_int? = null

    override fun bottom() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_bottom
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":left")) {
        output = this.left()
      } else if ((skey==":right")) {
        output = this.right()
      } else if ((skey==":top")) {
        output = this.top()
      } else if ((skey==":bottom")) {
        output = this.bottom()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":left", this.left())
      map.put(":right", this.right())
      map.put(":top", this.top())
      map.put(":bottom", this.bottom())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_bounds = vx_core.vx_copy(vx_ui_ui.e_bounds, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_bounds = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_bounds = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_left : vx_core.Type_int = value.left()
      var vx_p_right : vx_core.Type_int = value.right()
      var vx_p_top : vx_core.Type_int = value.top()
      var vx_p_bottom : vx_core.Type_int = value.bottom()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":left")
      validkeys.add(":right")
      validkeys.add(":top")
      validkeys.add(":bottom")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":left")) {
            if (valsub == vx_p_left) {
            } else if (valsub is vx_core.Type_int) {
              var valleft : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_left = valleft
            } else if (valsub is Int) {
              ischanged = true
              vx_p_left = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("left"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":right")) {
            if (valsub == vx_p_right) {
            } else if (valsub is vx_core.Type_int) {
              var valright : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_right = valright
            } else if (valsub is Int) {
              ischanged = true
              vx_p_right = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("right"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":top")) {
            if (valsub == vx_p_top) {
            } else if (valsub is vx_core.Type_int) {
              var valtop : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_top = valtop
            } else if (valsub is Int) {
              ischanged = true
              vx_p_top = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("top"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":bottom")) {
            if (valsub == vx_p_bottom) {
            } else if (valsub is vx_core.Type_int) {
              var valbottom : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_bottom = valbottom
            } else if (valsub is Int) {
              ischanged = true
              vx_p_bottom = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("bottom"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_bounds = vx_ui_ui.Class_bounds()
        work.vx_p_left = vx_p_left
        work.vx_p_right = vx_p_right
        work.vx_p_top = vx_p_top
        work.vx_p_bottom = vx_p_bottom
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_bounds
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_bounds
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "bounds", // name
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

  val e_bounds : vx_ui_ui.Type_bounds = vx_ui_ui.Class_bounds()
  val t_bounds : vx_ui_ui.Type_bounds = vx_ui_ui.Class_bounds()

  interface Type_cursor : vx_core.Type_struct {
  }

  class Class_cursor : vx_core.Class_base, Type_cursor {
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
      var output : vx_ui_ui.Type_cursor = vx_core.vx_copy(vx_ui_ui.e_cursor, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_cursor = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_cursor = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_cursor = vx_ui_ui.Class_cursor()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_cursor
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_cursor
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor", // name
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

  val e_cursor : vx_ui_ui.Type_cursor = vx_ui_ui.Class_cursor()
  val t_cursor : vx_ui_ui.Type_cursor = vx_ui_ui.Class_cursor()

  interface Type_cursor_pointer : vx_core.Type_any {
  }

  class Class_cursor_pointer : vx_core.Class_base, Type_cursor_pointer {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_cursor_pointer = vx_core.vx_copy(vx_ui_ui.e_cursor_pointer, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_cursor_pointer = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_cursor_pointer = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_cursor_pointer = vx_ui_ui.Class_cursor_pointer()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_cursor_pointer
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_cursor_pointer
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor-pointer", // name
        ":cursor", // extends
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

  val e_cursor_pointer : vx_ui_ui.Type_cursor_pointer = vx_ui_ui.Class_cursor_pointer()
  val t_cursor_pointer : vx_ui_ui.Type_cursor_pointer = vx_ui_ui.Class_cursor_pointer()

  interface Type_flip : vx_core.Type_struct {
  }

  class Class_flip : vx_core.Class_base, Type_flip {
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
      var output : vx_ui_ui.Type_flip = vx_core.vx_copy(vx_ui_ui.e_flip, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_flip = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_flip = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_flip = vx_ui_ui.Class_flip()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_flip
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_flip
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "flip", // name
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

  val e_flip : vx_ui_ui.Type_flip = vx_ui_ui.Class_flip()
  val t_flip : vx_ui_ui.Type_flip = vx_ui_ui.Class_flip()

  interface Type_font : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun fontface() : vx_ui_ui.Type_fontface
    fun fontsize() : vx_core.Type_int
    fun fontstyle() : vx_ui_ui.Type_fontstyle
  }

  class Class_font : vx_core.Class_base, Type_font {
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

    var vx_p_fontface : vx_ui_ui.Type_fontface? = null

    override fun fontface() : vx_ui_ui.Type_fontface {
      var output : vx_ui_ui.Type_fontface = vx_ui_ui.e_fontface
      var testnull : vx_ui_ui.Type_fontface? = vx_p_fontface
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fontsize : vx_core.Type_int? = null

    override fun fontsize() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_fontsize
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fontstyle : vx_ui_ui.Type_fontstyle? = null

    override fun fontstyle() : vx_ui_ui.Type_fontstyle {
      var output : vx_ui_ui.Type_fontstyle = vx_ui_ui.e_fontstyle
      var testnull : vx_ui_ui.Type_fontstyle? = vx_p_fontstyle
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
      } else if ((skey==":fontface")) {
        output = this.fontface()
      } else if ((skey==":fontsize")) {
        output = this.fontsize()
      } else if ((skey==":fontstyle")) {
        output = this.fontstyle()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":fontface", this.fontface())
      map.put(":fontsize", this.fontsize())
      map.put(":fontstyle", this.fontstyle())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_font = vx_core.vx_copy(vx_ui_ui.e_font, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_font = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_font = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_fontface : vx_ui_ui.Type_fontface = value.fontface()
      var vx_p_fontsize : vx_core.Type_int = value.fontsize()
      var vx_p_fontstyle : vx_ui_ui.Type_fontstyle = value.fontstyle()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":fontface")
      validkeys.add(":fontsize")
      validkeys.add(":fontstyle")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fontface")) {
            if (valsub == vx_p_fontface) {
            } else if (valsub is vx_ui_ui.Type_fontface) {
              var valfontface : vx_ui_ui.Type_fontface = valsub as vx_ui_ui.Type_fontface
              ischanged = true
              vx_p_fontface = valfontface
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fontface"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fontsize")) {
            if (valsub == vx_p_fontsize) {
            } else if (valsub is vx_core.Type_int) {
              var valfontsize : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_fontsize = valfontsize
            } else if (valsub is Int) {
              ischanged = true
              vx_p_fontsize = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fontsize"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fontstyle")) {
            if (valsub == vx_p_fontstyle) {
            } else if (valsub is vx_ui_ui.Type_fontstyle) {
              var valfontstyle : vx_ui_ui.Type_fontstyle = valsub as vx_ui_ui.Type_fontstyle
              ischanged = true
              vx_p_fontstyle = valfontstyle
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fontstyle"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_font = vx_ui_ui.Class_font()
        work.vx_p_name = vx_p_name
        work.vx_p_fontface = vx_p_fontface
        work.vx_p_fontsize = vx_p_fontsize
        work.vx_p_fontstyle = vx_p_fontstyle
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_font
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_font
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "font", // name
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

  val e_font : vx_ui_ui.Type_font = vx_ui_ui.Class_font()
  val t_font : vx_ui_ui.Type_font = vx_ui_ui.Class_font()

  interface Type_fontface : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun weight() : vx_core.Type_string
    fun unicode() : vx_core.Type_string
    fun filelist() : vx_data_file.Type_filelist
  }

  class Class_fontface : vx_core.Class_base, Type_fontface {
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

    var vx_p_weight : vx_core.Type_string? = null

    override fun weight() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_weight
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_unicode : vx_core.Type_string? = null

    override fun unicode() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_unicode
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_filelist : vx_data_file.Type_filelist? = null

    override fun filelist() : vx_data_file.Type_filelist {
      var output : vx_data_file.Type_filelist = vx_data_file.e_filelist
      var testnull : vx_data_file.Type_filelist? = vx_p_filelist
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
      } else if ((skey==":weight")) {
        output = this.weight()
      } else if ((skey==":unicode")) {
        output = this.unicode()
      } else if ((skey==":filelist")) {
        output = this.filelist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":weight", this.weight())
      map.put(":unicode", this.unicode())
      map.put(":filelist", this.filelist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontface = vx_core.vx_copy(vx_ui_ui.e_fontface, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontface = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontface = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_weight : vx_core.Type_string = value.weight()
      var vx_p_unicode : vx_core.Type_string = value.unicode()
      var vx_p_filelist : vx_data_file.Type_filelist = value.filelist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":weight")
      validkeys.add(":unicode")
      validkeys.add(":filelist")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":weight")) {
            if (valsub == vx_p_weight) {
            } else if (valsub is vx_core.Type_string) {
              var valweight : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_weight = valweight
            } else if (valsub is String) {
              ischanged = true
              vx_p_weight = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("weight"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":unicode")) {
            if (valsub == vx_p_unicode) {
            } else if (valsub is vx_core.Type_string) {
              var valunicode : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_unicode = valunicode
            } else if (valsub is String) {
              ischanged = true
              vx_p_unicode = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("unicode"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":filelist")) {
            if (valsub == vx_p_filelist) {
            } else if (valsub is vx_data_file.Type_filelist) {
              var valfilelist : vx_data_file.Type_filelist = valsub as vx_data_file.Type_filelist
              ischanged = true
              vx_p_filelist = valfilelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("filelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_fontface = vx_ui_ui.Class_fontface()
        work.vx_p_name = vx_p_name
        work.vx_p_weight = vx_p_weight
        work.vx_p_unicode = vx_p_unicode
        work.vx_p_filelist = vx_p_filelist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontface
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontface
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontface", // name
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

  val e_fontface : vx_ui_ui.Type_fontface = vx_ui_ui.Class_fontface()
  val t_fontface : vx_ui_ui.Type_fontface = vx_ui_ui.Class_fontface()

  interface Type_fontfacelist : vx_core.Type_list {
    fun vx_listfontface() : List<vx_ui_ui.Type_fontface>
    fun vx_fontface(index : vx_core.Type_int) : vx_ui_ui.Type_fontface
  }

  class Class_fontfacelist : vx_core.Class_base, Type_fontfacelist {
    constructor() {}

    var vx_p_list : List<vx_ui_ui.Type_fontface> = vx_core.immutablelist(
      ArrayList<vx_ui_ui.Type_fontface>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_fontface(index : vx_core.Type_int) : vx_ui_ui.Type_fontface {
      var output : vx_ui_ui.Type_fontface = vx_ui_ui.e_fontface
      var list : vx_ui_ui.Class_fontfacelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_ui_ui.Type_fontface> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listfontface() : List<vx_ui_ui.Type_fontface> {
      var output : List<vx_ui_ui.Type_fontface> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontface = this.vx_fontface(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontfacelist = vx_core.vx_copy(vx_ui_ui.e_fontfacelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontfacelist = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontfacelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_ui_ui.Type_fontface> = ArrayList<vx_ui_ui.Type_fontface>(value.vx_listfontface())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_ui_ui.Type_fontfacelist) {
          var multi : vx_ui_ui.Type_fontfacelist = valsub as vx_ui_ui.Type_fontfacelist
          ischanged = true
          listval.addAll(multi.vx_listfontface())
        } else if (valsub is vx_ui_ui.Type_fontface) {
          var allowsub : vx_ui_ui.Type_fontface = valsub as vx_ui_ui.Type_fontface
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_ui_ui.Type_fontface) {
          ischanged = true
          listval.add(valsub as vx_ui_ui.Type_fontface)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_ui_ui.Type_fontface) {
              var valitem : vx_ui_ui.Type_fontface = item as vx_ui_ui.Type_fontface
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_fontfacelist = vx_ui_ui.Class_fontfacelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontfacelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontfacelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_fontface), // allowtypes
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

  val e_fontfacelist : vx_ui_ui.Type_fontfacelist = vx_ui_ui.Class_fontfacelist()
  val t_fontfacelist : vx_ui_ui.Type_fontfacelist = vx_ui_ui.Class_fontfacelist()

  interface Type_fontfacemap : vx_core.Type_map {
    fun vx_mapfontface() : Map<String, vx_ui_ui.Type_fontface>
    fun vx_fontface(key : vx_core.Type_string) : vx_ui_ui.Type_fontface
  }

  class Class_fontfacemap : vx_core.Class_base, Type_fontfacemap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_fontface> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_fontface>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_fontface) {
        var castval : vx_ui_ui.Type_fontface = value as vx_ui_ui.Type_fontface
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_fontface> = LinkedHashMap<String, vx_ui_ui.Type_fontface>(this.vx_p_map)
        if (castval == vx_ui_ui.e_fontface) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_fontface(key : vx_core.Type_string) : vx_ui_ui.Type_fontface {
      var output : vx_ui_ui.Type_fontface = vx_ui_ui.e_fontface
      var map : vx_ui_ui.Class_fontfacemap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_fontface> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_fontface)
      return output
    }

    override fun vx_mapfontface() : Map<String, vx_ui_ui.Type_fontface> {
      var output : Map<String, vx_ui_ui.Type_fontface> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_fontface(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_fontfacemap = vx_ui_ui.Class_fontfacemap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_fontface> = LinkedHashMap<String, vx_ui_ui.Type_fontface>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_fontface) {
          var castval : vx_ui_ui.Type_fontface = value as vx_ui_ui.Type_fontface
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_fontfacemap = vx_core.vx_copy(vx_ui_ui.e_fontfacemap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontfacemap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontfacemap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_fontface> = LinkedHashMap<String, vx_ui_ui.Type_fontface>(value.vx_mapfontface())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_fontface = vx_ui_ui.e_fontface
          if (false) {
          } else if (valsub is vx_ui_ui.Type_fontface) {
            var valallowed : vx_ui_ui.Type_fontface = valsub as vx_ui_ui.Type_fontface
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_fontface) {
            valany = valsub as vx_ui_ui.Type_fontface
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_fontfacemap = vx_ui_ui.Class_fontfacemap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontfacemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontfacemap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_fontface), // allowtypes
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

  val e_fontfacemap : vx_ui_ui.Type_fontfacemap = vx_ui_ui.Class_fontfacemap()
  val t_fontfacemap : vx_ui_ui.Type_fontfacemap = vx_ui_ui.Class_fontfacemap()

  interface Type_fontmap : vx_core.Type_map {
    fun vx_mapfont() : Map<String, vx_ui_ui.Type_font>
    fun vx_font(key : vx_core.Type_string) : vx_ui_ui.Type_font
  }

  class Class_fontmap : vx_core.Class_base, Type_fontmap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_font> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_font>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_font) {
        var castval : vx_ui_ui.Type_font = value as vx_ui_ui.Type_font
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_font> = LinkedHashMap<String, vx_ui_ui.Type_font>(this.vx_p_map)
        if (castval == vx_ui_ui.e_font) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_font(key : vx_core.Type_string) : vx_ui_ui.Type_font {
      var output : vx_ui_ui.Type_font = vx_ui_ui.e_font
      var map : vx_ui_ui.Class_fontmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_font> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_font)
      return output
    }

    override fun vx_mapfont() : Map<String, vx_ui_ui.Type_font> {
      var output : Map<String, vx_ui_ui.Type_font> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_font(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_fontmap = vx_ui_ui.Class_fontmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_font> = LinkedHashMap<String, vx_ui_ui.Type_font>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_font) {
          var castval : vx_ui_ui.Type_font = value as vx_ui_ui.Type_font
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_fontmap = vx_core.vx_copy(vx_ui_ui.e_fontmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontmap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_font> = LinkedHashMap<String, vx_ui_ui.Type_font>(value.vx_mapfont())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_font = vx_ui_ui.e_font
          if (false) {
          } else if (valsub is vx_ui_ui.Type_font) {
            var valallowed : vx_ui_ui.Type_font = valsub as vx_ui_ui.Type_font
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_font) {
            valany = valsub as vx_ui_ui.Type_font
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_fontmap = vx_ui_ui.Class_fontmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_font), // allowtypes
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

  val e_fontmap : vx_ui_ui.Type_fontmap = vx_ui_ui.Class_fontmap()
  val t_fontmap : vx_ui_ui.Type_fontmap = vx_ui_ui.Class_fontmap()

  interface Type_fontstyle : vx_core.Type_struct {
    fun name() : vx_core.Type_string
  }

  class Class_fontstyle : vx_core.Class_base, Type_fontstyle {
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":name")) {
        output = this.name()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontstyle = vx_core.vx_copy(vx_ui_ui.e_fontstyle, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontstyle = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontstyle = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_fontstyle = vx_ui_ui.Class_fontstyle()
        work.vx_p_name = vx_p_name
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontstyle
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontstyle
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstyle", // name
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

  val e_fontstyle : vx_ui_ui.Type_fontstyle = vx_ui_ui.Class_fontstyle()
  val t_fontstyle : vx_ui_ui.Type_fontstyle = vx_ui_ui.Class_fontstyle()

  interface Type_fontstylemap : vx_core.Type_map {
    fun vx_mapfontstyle() : Map<String, vx_ui_ui.Type_fontstyle>
    fun vx_fontstyle(key : vx_core.Type_string) : vx_ui_ui.Type_fontstyle
  }

  class Class_fontstylemap : vx_core.Class_base, Type_fontstylemap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_fontstyle> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_fontstyle>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_fontstyle) {
        var castval : vx_ui_ui.Type_fontstyle = value as vx_ui_ui.Type_fontstyle
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_fontstyle> = LinkedHashMap<String, vx_ui_ui.Type_fontstyle>(this.vx_p_map)
        if (castval == vx_ui_ui.e_fontstyle) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_fontstyle(key : vx_core.Type_string) : vx_ui_ui.Type_fontstyle {
      var output : vx_ui_ui.Type_fontstyle = vx_ui_ui.e_fontstyle
      var map : vx_ui_ui.Class_fontstylemap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_fontstyle> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_fontstyle)
      return output
    }

    override fun vx_mapfontstyle() : Map<String, vx_ui_ui.Type_fontstyle> {
      var output : Map<String, vx_ui_ui.Type_fontstyle> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_fontstyle(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_fontstylemap = vx_ui_ui.Class_fontstylemap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_fontstyle> = LinkedHashMap<String, vx_ui_ui.Type_fontstyle>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_fontstyle) {
          var castval : vx_ui_ui.Type_fontstyle = value as vx_ui_ui.Type_fontstyle
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_fontstylemap = vx_core.vx_copy(vx_ui_ui.e_fontstylemap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_fontstylemap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_fontstylemap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_fontstyle> = LinkedHashMap<String, vx_ui_ui.Type_fontstyle>(value.vx_mapfontstyle())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_fontstyle = vx_ui_ui.e_fontstyle
          if (false) {
          } else if (valsub is vx_ui_ui.Type_fontstyle) {
            var valallowed : vx_ui_ui.Type_fontstyle = valsub as vx_ui_ui.Type_fontstyle
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_fontstyle) {
            valany = valsub as vx_ui_ui.Type_fontstyle
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_fontstylemap = vx_ui_ui.Class_fontstylemap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_fontstylemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontstylemap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstylemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_fontstyle), // allowtypes
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

  val e_fontstylemap : vx_ui_ui.Type_fontstylemap = vx_ui_ui.Class_fontstylemap()
  val t_fontstylemap : vx_ui_ui.Type_fontstylemap = vx_ui_ui.Class_fontstylemap()

  interface Type_image : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun label() : vx_core.Type_string
    fun file() : vx_data_file.Type_file
  }

  class Class_image : vx_core.Class_base, Type_image {
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

    var vx_p_label : vx_core.Type_string? = null

    override fun label() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_label
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_file : vx_data_file.Type_file? = null

    override fun file() : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_data_file.e_file
      var testnull : vx_data_file.Type_file? = vx_p_file
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
      } else if ((skey==":label")) {
        output = this.label()
      } else if ((skey==":file")) {
        output = this.file()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":label", this.label())
      map.put(":file", this.file())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_image = vx_core.vx_copy(vx_ui_ui.e_image, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_image = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_image = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_label : vx_core.Type_string = value.label()
      var vx_p_file : vx_data_file.Type_file = value.file()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":label")
      validkeys.add(":file")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":label")) {
            if (valsub == vx_p_label) {
            } else if (valsub is vx_core.Type_string) {
              var vallabel : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_label = vallabel
            } else if (valsub is String) {
              ischanged = true
              vx_p_label = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("label"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":file")) {
            if (valsub == vx_p_file) {
            } else if (valsub is vx_data_file.Type_file) {
              var valfile : vx_data_file.Type_file = valsub as vx_data_file.Type_file
              ischanged = true
              vx_p_file = valfile
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("file"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_image = vx_ui_ui.Class_image()
        work.vx_p_name = vx_p_name
        work.vx_p_label = vx_p_label
        work.vx_p_file = vx_p_file
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_image
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_image
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "image", // name
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

  val e_image : vx_ui_ui.Type_image = vx_ui_ui.Class_image()
  val t_image : vx_ui_ui.Type_image = vx_ui_ui.Class_image()

  interface Type_layout : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun fn_layout() : vx_ui_ui.Func_ui_layout_from_ui_orig_parent
  }

  class Class_layout : vx_core.Class_base, Type_layout {
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

    var vx_p_fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent? = null

    override fun fn_layout() : vx_ui_ui.Func_ui_layout_from_ui_orig_parent {
      var output : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = vx_ui_ui.e_ui_layout_from_ui_orig_parent
      var testnull : vx_ui_ui.Func_ui_layout_from_ui_orig_parent? = vx_p_fn_layout
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
      } else if ((skey==":fn-layout")) {
        output = this.fn_layout()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":fn-layout", this.fn_layout())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layout = vx_core.vx_copy(vx_ui_ui.e_layout, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layout = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_layout = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = value.fn_layout()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":fn-layout")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fn-layout")) {
            if (valsub == vx_p_fn_layout) {
            } else if (valsub is vx_ui_ui.Func_ui_layout_from_ui_orig_parent) {
              var valfn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = valsub as vx_ui_ui.Func_ui_layout_from_ui_orig_parent
              ischanged = true
              vx_p_fn_layout = valfn_layout
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fn-layout"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_layout = vx_ui_ui.Class_layout()
        work.vx_p_name = vx_p_name
        work.vx_p_fn_layout = vx_p_fn_layout
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_layout
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layout
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "layout", // name
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

  val e_layout : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()
  val t_layout : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()

  interface Type_layoutengine : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun boolean_print() : vx_ui_ui.Func_boolean_print
    fun boolean_layoutremove() : vx_ui_ui.Func_boolean_layoutremove_from_ui
    fun boolean_layoutselected() : vx_ui_ui.Func_boolean_layoutselected_from_ui
    fun boolean_layoutvisible() : vx_ui_ui.Func_boolean_layoutvisible_from_ui
    fun layoutmap() : vx_ui_ui.Type_layoutmap
    fun layoutelse() : vx_ui_ui.Type_layout
    fun stylesheetrender() : vx_ui_ui.Func_stylesheet_render
  }

  class Class_layoutengine : vx_core.Class_base, Type_layoutengine {
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

    var vx_p_boolean_print : vx_ui_ui.Func_boolean_print? = null

    override fun boolean_print() : vx_ui_ui.Func_boolean_print {
      var output : vx_ui_ui.Func_boolean_print = vx_ui_ui.e_boolean_print
      var testnull : vx_ui_ui.Func_boolean_print? = vx_p_boolean_print
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_boolean_layoutremove : vx_ui_ui.Func_boolean_layoutremove_from_ui? = null

    override fun boolean_layoutremove() : vx_ui_ui.Func_boolean_layoutremove_from_ui {
      var output : vx_ui_ui.Func_boolean_layoutremove_from_ui = vx_ui_ui.e_boolean_layoutremove_from_ui
      var testnull : vx_ui_ui.Func_boolean_layoutremove_from_ui? = vx_p_boolean_layoutremove
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_boolean_layoutselected : vx_ui_ui.Func_boolean_layoutselected_from_ui? = null

    override fun boolean_layoutselected() : vx_ui_ui.Func_boolean_layoutselected_from_ui {
      var output : vx_ui_ui.Func_boolean_layoutselected_from_ui = vx_ui_ui.e_boolean_layoutselected_from_ui
      var testnull : vx_ui_ui.Func_boolean_layoutselected_from_ui? = vx_p_boolean_layoutselected
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_boolean_layoutvisible : vx_ui_ui.Func_boolean_layoutvisible_from_ui? = null

    override fun boolean_layoutvisible() : vx_ui_ui.Func_boolean_layoutvisible_from_ui {
      var output : vx_ui_ui.Func_boolean_layoutvisible_from_ui = vx_ui_ui.e_boolean_layoutvisible_from_ui
      var testnull : vx_ui_ui.Func_boolean_layoutvisible_from_ui? = vx_p_boolean_layoutvisible
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_layoutmap : vx_ui_ui.Type_layoutmap? = null

    override fun layoutmap() : vx_ui_ui.Type_layoutmap {
      var output : vx_ui_ui.Type_layoutmap = vx_ui_ui.e_layoutmap
      var testnull : vx_ui_ui.Type_layoutmap? = vx_p_layoutmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_layoutelse : vx_ui_ui.Type_layout? = null

    override fun layoutelse() : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
      var testnull : vx_ui_ui.Type_layout? = vx_p_layoutelse
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylesheetrender : vx_ui_ui.Func_stylesheet_render? = null

    override fun stylesheetrender() : vx_ui_ui.Func_stylesheet_render {
      var output : vx_ui_ui.Func_stylesheet_render = vx_ui_ui.e_stylesheet_render
      var testnull : vx_ui_ui.Func_stylesheet_render? = vx_p_stylesheetrender
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
      } else if ((skey==":boolean-print")) {
        output = this.boolean_print()
      } else if ((skey==":boolean-layoutremove")) {
        output = this.boolean_layoutremove()
      } else if ((skey==":boolean-layoutselected")) {
        output = this.boolean_layoutselected()
      } else if ((skey==":boolean-layoutvisible")) {
        output = this.boolean_layoutvisible()
      } else if ((skey==":layoutmap")) {
        output = this.layoutmap()
      } else if ((skey==":layoutelse")) {
        output = this.layoutelse()
      } else if ((skey==":stylesheetrender")) {
        output = this.stylesheetrender()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":boolean-print", this.boolean_print())
      map.put(":boolean-layoutremove", this.boolean_layoutremove())
      map.put(":boolean-layoutselected", this.boolean_layoutselected())
      map.put(":boolean-layoutvisible", this.boolean_layoutvisible())
      map.put(":layoutmap", this.layoutmap())
      map.put(":layoutelse", this.layoutelse())
      map.put(":stylesheetrender", this.stylesheetrender())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layoutengine = vx_core.vx_copy(vx_ui_ui.e_layoutengine, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layoutengine = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_layoutengine = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_boolean_print : vx_ui_ui.Func_boolean_print = value.boolean_print()
      var vx_p_boolean_layoutremove : vx_ui_ui.Func_boolean_layoutremove_from_ui = value.boolean_layoutremove()
      var vx_p_boolean_layoutselected : vx_ui_ui.Func_boolean_layoutselected_from_ui = value.boolean_layoutselected()
      var vx_p_boolean_layoutvisible : vx_ui_ui.Func_boolean_layoutvisible_from_ui = value.boolean_layoutvisible()
      var vx_p_layoutmap : vx_ui_ui.Type_layoutmap = value.layoutmap()
      var vx_p_layoutelse : vx_ui_ui.Type_layout = value.layoutelse()
      var vx_p_stylesheetrender : vx_ui_ui.Func_stylesheet_render = value.stylesheetrender()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":boolean-print")
      validkeys.add(":boolean-layoutremove")
      validkeys.add(":boolean-layoutselected")
      validkeys.add(":boolean-layoutvisible")
      validkeys.add(":layoutmap")
      validkeys.add(":layoutelse")
      validkeys.add(":stylesheetrender")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boolean-print")) {
            if (valsub == vx_p_boolean_print) {
            } else if (valsub is vx_ui_ui.Func_boolean_print) {
              var valboolean_print : vx_ui_ui.Func_boolean_print = valsub as vx_ui_ui.Func_boolean_print
              ischanged = true
              vx_p_boolean_print = valboolean_print
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boolean-print"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boolean-layoutremove")) {
            if (valsub == vx_p_boolean_layoutremove) {
            } else if (valsub is vx_ui_ui.Func_boolean_layoutremove_from_ui) {
              var valboolean_layoutremove : vx_ui_ui.Func_boolean_layoutremove_from_ui = valsub as vx_ui_ui.Func_boolean_layoutremove_from_ui
              ischanged = true
              vx_p_boolean_layoutremove = valboolean_layoutremove
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boolean-layoutremove"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boolean-layoutselected")) {
            if (valsub == vx_p_boolean_layoutselected) {
            } else if (valsub is vx_ui_ui.Func_boolean_layoutselected_from_ui) {
              var valboolean_layoutselected : vx_ui_ui.Func_boolean_layoutselected_from_ui = valsub as vx_ui_ui.Func_boolean_layoutselected_from_ui
              ischanged = true
              vx_p_boolean_layoutselected = valboolean_layoutselected
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boolean-layoutselected"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boolean-layoutvisible")) {
            if (valsub == vx_p_boolean_layoutvisible) {
            } else if (valsub is vx_ui_ui.Func_boolean_layoutvisible_from_ui) {
              var valboolean_layoutvisible : vx_ui_ui.Func_boolean_layoutvisible_from_ui = valsub as vx_ui_ui.Func_boolean_layoutvisible_from_ui
              ischanged = true
              vx_p_boolean_layoutvisible = valboolean_layoutvisible
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boolean-layoutvisible"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":layoutmap")) {
            if (valsub == vx_p_layoutmap) {
            } else if (valsub is vx_ui_ui.Type_layoutmap) {
              var vallayoutmap : vx_ui_ui.Type_layoutmap = valsub as vx_ui_ui.Type_layoutmap
              ischanged = true
              vx_p_layoutmap = vallayoutmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("layoutmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":layoutelse")) {
            if (valsub == vx_p_layoutelse) {
            } else if (valsub is vx_ui_ui.Type_layout) {
              var vallayoutelse : vx_ui_ui.Type_layout = valsub as vx_ui_ui.Type_layout
              ischanged = true
              vx_p_layoutelse = vallayoutelse
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("layoutelse"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylesheetrender")) {
            if (valsub == vx_p_stylesheetrender) {
            } else if (valsub is vx_ui_ui.Func_stylesheet_render) {
              var valstylesheetrender : vx_ui_ui.Func_stylesheet_render = valsub as vx_ui_ui.Func_stylesheet_render
              ischanged = true
              vx_p_stylesheetrender = valstylesheetrender
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylesheetrender"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_layoutengine = vx_ui_ui.Class_layoutengine()
        work.vx_p_name = vx_p_name
        work.vx_p_boolean_print = vx_p_boolean_print
        work.vx_p_boolean_layoutremove = vx_p_boolean_layoutremove
        work.vx_p_boolean_layoutselected = vx_p_boolean_layoutselected
        work.vx_p_boolean_layoutvisible = vx_p_boolean_layoutvisible
        work.vx_p_layoutmap = vx_p_layoutmap
        work.vx_p_layoutelse = vx_p_layoutelse
        work.vx_p_stylesheetrender = vx_p_stylesheetrender
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_layoutengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layoutengine
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutengine", // name
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

  val e_layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.Class_layoutengine()
  val t_layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.Class_layoutengine()

  interface Type_layoutlist : vx_core.Type_list {
    fun vx_listlayout() : List<vx_ui_ui.Type_layout>
    fun vx_layout(index : vx_core.Type_int) : vx_ui_ui.Type_layout
  }

  class Class_layoutlist : vx_core.Class_base, Type_layoutlist {
    constructor() {}

    var vx_p_list : List<vx_ui_ui.Type_layout> = vx_core.immutablelist(
      ArrayList<vx_ui_ui.Type_layout>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_layout(index : vx_core.Type_int) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
      var list : vx_ui_ui.Class_layoutlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_ui_ui.Type_layout> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listlayout() : List<vx_ui_ui.Type_layout> {
      var output : List<vx_ui_ui.Type_layout> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layout = this.vx_layout(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layoutlist = vx_core.vx_copy(vx_ui_ui.e_layoutlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layoutlist = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_layoutlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_ui_ui.Type_layout> = ArrayList<vx_ui_ui.Type_layout>(value.vx_listlayout())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_ui_ui.Type_layoutlist) {
          var multi : vx_ui_ui.Type_layoutlist = valsub as vx_ui_ui.Type_layoutlist
          ischanged = true
          listval.addAll(multi.vx_listlayout())
        } else if (valsub is vx_ui_ui.Type_layout) {
          var allowsub : vx_ui_ui.Type_layout = valsub as vx_ui_ui.Type_layout
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_ui_ui.Type_layout) {
          ischanged = true
          listval.add(valsub as vx_ui_ui.Type_layout)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_ui_ui.Type_layout) {
              var valitem : vx_ui_ui.Type_layout = item as vx_ui_ui.Type_layout
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_layoutlist = vx_ui_ui.Class_layoutlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_layoutlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layoutlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_layout), // allowtypes
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

  val e_layoutlist : vx_ui_ui.Type_layoutlist = vx_ui_ui.Class_layoutlist()
  val t_layoutlist : vx_ui_ui.Type_layoutlist = vx_ui_ui.Class_layoutlist()

  interface Type_layoutmap : vx_core.Type_map {
    fun vx_maplayout() : Map<String, vx_ui_ui.Type_layout>
    fun vx_layout(key : vx_core.Type_string) : vx_ui_ui.Type_layout
  }

  class Class_layoutmap : vx_core.Class_base, Type_layoutmap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_layout> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_layout>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_layout) {
        var castval : vx_ui_ui.Type_layout = value as vx_ui_ui.Type_layout
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_layout> = LinkedHashMap<String, vx_ui_ui.Type_layout>(this.vx_p_map)
        if (castval == vx_ui_ui.e_layout) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_layout(key : vx_core.Type_string) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
      var map : vx_ui_ui.Class_layoutmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_layout> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_layout)
      return output
    }

    override fun vx_maplayout() : Map<String, vx_ui_ui.Type_layout> {
      var output : Map<String, vx_ui_ui.Type_layout> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_layout(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_layoutmap = vx_ui_ui.Class_layoutmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_layout> = LinkedHashMap<String, vx_ui_ui.Type_layout>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_layout) {
          var castval : vx_ui_ui.Type_layout = value as vx_ui_ui.Type_layout
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_layoutmap = vx_core.vx_copy(vx_ui_ui.e_layoutmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_layoutmap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_layoutmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_layout> = LinkedHashMap<String, vx_ui_ui.Type_layout>(value.vx_maplayout())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
          if (false) {
          } else if (valsub is vx_ui_ui.Type_layout) {
            var valallowed : vx_ui_ui.Type_layout = valsub as vx_ui_ui.Type_layout
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_layout) {
            valany = valsub as vx_ui_ui.Type_layout
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_layoutmap = vx_ui_ui.Class_layoutmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_layoutmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layoutmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_layout), // allowtypes
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

  val e_layoutmap : vx_ui_ui.Type_layoutmap = vx_ui_ui.Class_layoutmap()
  val t_layoutmap : vx_ui_ui.Type_layoutmap = vx_ui_ui.Class_layoutmap()

  interface Type_pin : vx_core.Type_struct {
    fun name() : vx_core.Type_string
  }

  class Class_pin : vx_core.Class_base, Type_pin {
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

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":name")) {
        output = this.name()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_pin = vx_core.vx_copy(vx_ui_ui.e_pin, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_pin = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_pin = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/pin", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_pin = vx_ui_ui.Class_pin()
        work.vx_p_name = vx_p_name
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_pin
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_pin
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "pin", // name
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

  val e_pin : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()
  val t_pin : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()

  interface Type_point : vx_core.Type_struct {
    fun x() : vx_core.Type_int
    fun y() : vx_core.Type_int
    fun z() : vx_core.Type_int
    fun t() : vx_core.Type_int
    fun i() : vx_core.Type_int
    fun pointtype() : vx_ui_ui.Type_pointtype
  }

  class Class_point : vx_core.Class_base, Type_point {
    constructor() {}

    var vx_p_x : vx_core.Type_int? = null

    override fun x() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_x
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_y : vx_core.Type_int? = null

    override fun y() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_y
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_z : vx_core.Type_int? = null

    override fun z() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_z
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_t : vx_core.Type_int? = null

    override fun t() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_t
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_i : vx_core.Type_int? = null

    override fun i() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_i
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pointtype : vx_ui_ui.Type_pointtype? = null

    override fun pointtype() : vx_ui_ui.Type_pointtype {
      var output : vx_ui_ui.Type_pointtype = vx_ui_ui.e_pointtype
      var testnull : vx_ui_ui.Type_pointtype? = vx_p_pointtype
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":x")) {
        output = this.x()
      } else if ((skey==":y")) {
        output = this.y()
      } else if ((skey==":z")) {
        output = this.z()
      } else if ((skey==":t")) {
        output = this.t()
      } else if ((skey==":i")) {
        output = this.i()
      } else if ((skey==":pointtype")) {
        output = this.pointtype()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":x", this.x())
      map.put(":y", this.y())
      map.put(":z", this.z())
      map.put(":t", this.t())
      map.put(":i", this.i())
      map.put(":pointtype", this.pointtype())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_point = vx_core.vx_copy(vx_ui_ui.e_point, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_point = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_point = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_x : vx_core.Type_int = value.x()
      var vx_p_y : vx_core.Type_int = value.y()
      var vx_p_z : vx_core.Type_int = value.z()
      var vx_p_t : vx_core.Type_int = value.t()
      var vx_p_i : vx_core.Type_int = value.i()
      var vx_p_pointtype : vx_ui_ui.Type_pointtype = value.pointtype()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":x")
      validkeys.add(":y")
      validkeys.add(":z")
      validkeys.add(":t")
      validkeys.add(":i")
      validkeys.add(":pointtype")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":x")) {
            if (valsub == vx_p_x) {
            } else if (valsub is vx_core.Type_int) {
              var valx : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_x = valx
            } else if (valsub is Int) {
              ischanged = true
              vx_p_x = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("x"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":y")) {
            if (valsub == vx_p_y) {
            } else if (valsub is vx_core.Type_int) {
              var valy : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_y = valy
            } else if (valsub is Int) {
              ischanged = true
              vx_p_y = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("y"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":z")) {
            if (valsub == vx_p_z) {
            } else if (valsub is vx_core.Type_int) {
              var valz : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_z = valz
            } else if (valsub is Int) {
              ischanged = true
              vx_p_z = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("z"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":t")) {
            if (valsub == vx_p_t) {
            } else if (valsub is vx_core.Type_int) {
              var valt : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_t = valt
            } else if (valsub is Int) {
              ischanged = true
              vx_p_t = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("t"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":i")) {
            if (valsub == vx_p_i) {
            } else if (valsub is vx_core.Type_int) {
              var vali : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_i = vali
            } else if (valsub is Int) {
              ischanged = true
              vx_p_i = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("i"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pointtype")) {
            if (valsub == vx_p_pointtype) {
            } else if (valsub is vx_ui_ui.Type_pointtype) {
              var valpointtype : vx_ui_ui.Type_pointtype = valsub as vx_ui_ui.Type_pointtype
              ischanged = true
              vx_p_pointtype = valpointtype
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pointtype"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_point = vx_ui_ui.Class_point()
        work.vx_p_x = vx_p_x
        work.vx_p_y = vx_p_y
        work.vx_p_z = vx_p_z
        work.vx_p_t = vx_p_t
        work.vx_p_i = vx_p_i
        work.vx_p_pointtype = vx_p_pointtype
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_point
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_point
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "point", // name
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

  val e_point : vx_ui_ui.Type_point = vx_ui_ui.Class_point()
  val t_point : vx_ui_ui.Type_point = vx_ui_ui.Class_point()

  interface Type_pointtype : vx_core.Type_any {
  }

  class Class_pointtype : vx_core.Class_base, Type_pointtype {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_pointtype = vx_core.vx_copy(vx_ui_ui.e_pointtype, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_pointtype = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_pointtype = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_pointtype = vx_ui_ui.Class_pointtype()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_pointtype
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_pointtype
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "pointtype", // name
        ":int", // extends
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

  val e_pointtype : vx_ui_ui.Type_pointtype = vx_ui_ui.Class_pointtype()
  val t_pointtype : vx_ui_ui.Type_pointtype = vx_ui_ui.Class_pointtype()

  interface Type_style : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun align() : vx_ui_ui.Type_align
    fun boundsmargin() : vx_ui_ui.Type_bounds
    fun boundspadding() : vx_ui_ui.Type_bounds
    fun color_bkg() : vx_core.Type_string
    fun color_bkghover() : vx_core.Type_string
    fun color_border() : vx_core.Type_string
    fun color_font() : vx_core.Type_string
    fun cursor() : vx_ui_ui.Type_cursor
    fun flip() : vx_ui_ui.Type_flip
    fun font() : vx_ui_ui.Type_font
    fun hidden() : vx_core.Type_boolean
    fun image_bkg() : vx_ui_ui.Type_image
    fun layout() : vx_ui_ui.Type_layout
    fun type() : vx_ui_ui.Type_styletype
    fun pin() : vx_ui_ui.Type_pin
    fun pointorigin() : vx_ui_ui.Type_point
    fun pointpos() : vx_ui_ui.Type_point
    fun pointrotate() : vx_ui_ui.Type_point
    fun pointsize() : vx_ui_ui.Type_point
    fun scroll_x() : vx_core.Type_boolean
    fun scroll_y() : vx_core.Type_boolean
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

    var vx_p_align : vx_ui_ui.Type_align? = null

    override fun align() : vx_ui_ui.Type_align {
      var output : vx_ui_ui.Type_align = vx_ui_ui.e_align
      var testnull : vx_ui_ui.Type_align? = vx_p_align
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_boundsmargin : vx_ui_ui.Type_bounds? = null

    override fun boundsmargin() : vx_ui_ui.Type_bounds {
      var output : vx_ui_ui.Type_bounds = vx_ui_ui.e_bounds
      var testnull : vx_ui_ui.Type_bounds? = vx_p_boundsmargin
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_boundspadding : vx_ui_ui.Type_bounds? = null

    override fun boundspadding() : vx_ui_ui.Type_bounds {
      var output : vx_ui_ui.Type_bounds = vx_ui_ui.e_bounds
      var testnull : vx_ui_ui.Type_bounds? = vx_p_boundspadding
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_color_bkg : vx_core.Type_string? = null

    override fun color_bkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_color_bkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_color_bkghover : vx_core.Type_string? = null

    override fun color_bkghover() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_color_bkghover
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_color_border : vx_core.Type_string? = null

    override fun color_border() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_color_border
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_color_font : vx_core.Type_string? = null

    override fun color_font() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_color_font
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_cursor : vx_ui_ui.Type_cursor? = null

    override fun cursor() : vx_ui_ui.Type_cursor {
      var output : vx_ui_ui.Type_cursor = vx_ui_ui.e_cursor
      var testnull : vx_ui_ui.Type_cursor? = vx_p_cursor
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_flip : vx_ui_ui.Type_flip? = null

    override fun flip() : vx_ui_ui.Type_flip {
      var output : vx_ui_ui.Type_flip = vx_ui_ui.e_flip
      var testnull : vx_ui_ui.Type_flip? = vx_p_flip
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_font : vx_ui_ui.Type_font? = null

    override fun font() : vx_ui_ui.Type_font {
      var output : vx_ui_ui.Type_font = vx_ui_ui.e_font
      var testnull : vx_ui_ui.Type_font? = vx_p_font
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_hidden : vx_core.Type_boolean? = null

    override fun hidden() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_hidden
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_image_bkg : vx_ui_ui.Type_image? = null

    override fun image_bkg() : vx_ui_ui.Type_image {
      var output : vx_ui_ui.Type_image = vx_ui_ui.e_image
      var testnull : vx_ui_ui.Type_image? = vx_p_image_bkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_layout : vx_ui_ui.Type_layout? = null

    override fun layout() : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
      var testnull : vx_ui_ui.Type_layout? = vx_p_layout
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_type : vx_ui_ui.Type_styletype? = null

    override fun type() : vx_ui_ui.Type_styletype {
      var output : vx_ui_ui.Type_styletype = vx_ui_ui.e_styletype
      var testnull : vx_ui_ui.Type_styletype? = vx_p_type
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pin : vx_ui_ui.Type_pin? = null

    override fun pin() : vx_ui_ui.Type_pin {
      var output : vx_ui_ui.Type_pin = vx_ui_ui.e_pin
      var testnull : vx_ui_ui.Type_pin? = vx_p_pin
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pointorigin : vx_ui_ui.Type_point? = null

    override fun pointorigin() : vx_ui_ui.Type_point {
      var output : vx_ui_ui.Type_point = vx_ui_ui.e_point
      var testnull : vx_ui_ui.Type_point? = vx_p_pointorigin
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pointpos : vx_ui_ui.Type_point? = null

    override fun pointpos() : vx_ui_ui.Type_point {
      var output : vx_ui_ui.Type_point = vx_ui_ui.e_point
      var testnull : vx_ui_ui.Type_point? = vx_p_pointpos
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pointrotate : vx_ui_ui.Type_point? = null

    override fun pointrotate() : vx_ui_ui.Type_point {
      var output : vx_ui_ui.Type_point = vx_ui_ui.e_point
      var testnull : vx_ui_ui.Type_point? = vx_p_pointrotate
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_pointsize : vx_ui_ui.Type_point? = null

    override fun pointsize() : vx_ui_ui.Type_point {
      var output : vx_ui_ui.Type_point = vx_ui_ui.e_point
      var testnull : vx_ui_ui.Type_point? = vx_p_pointsize
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_scroll_x : vx_core.Type_boolean? = null

    override fun scroll_x() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_scroll_x
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_scroll_y : vx_core.Type_boolean? = null

    override fun scroll_y() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_scroll_y
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
      } else if ((skey==":align")) {
        output = this.align()
      } else if ((skey==":boundsmargin")) {
        output = this.boundsmargin()
      } else if ((skey==":boundspadding")) {
        output = this.boundspadding()
      } else if ((skey==":color-bkg")) {
        output = this.color_bkg()
      } else if ((skey==":color-bkghover")) {
        output = this.color_bkghover()
      } else if ((skey==":color-border")) {
        output = this.color_border()
      } else if ((skey==":color-font")) {
        output = this.color_font()
      } else if ((skey==":cursor")) {
        output = this.cursor()
      } else if ((skey==":flip")) {
        output = this.flip()
      } else if ((skey==":font")) {
        output = this.font()
      } else if ((skey==":hidden")) {
        output = this.hidden()
      } else if ((skey==":image-bkg")) {
        output = this.image_bkg()
      } else if ((skey==":layout")) {
        output = this.layout()
      } else if ((skey==":type")) {
        output = this.type()
      } else if ((skey==":pin")) {
        output = this.pin()
      } else if ((skey==":pointorigin")) {
        output = this.pointorigin()
      } else if ((skey==":pointpos")) {
        output = this.pointpos()
      } else if ((skey==":pointrotate")) {
        output = this.pointrotate()
      } else if ((skey==":pointsize")) {
        output = this.pointsize()
      } else if ((skey==":scroll-x")) {
        output = this.scroll_x()
      } else if ((skey==":scroll-y")) {
        output = this.scroll_y()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":align", this.align())
      map.put(":boundsmargin", this.boundsmargin())
      map.put(":boundspadding", this.boundspadding())
      map.put(":color-bkg", this.color_bkg())
      map.put(":color-bkghover", this.color_bkghover())
      map.put(":color-border", this.color_border())
      map.put(":color-font", this.color_font())
      map.put(":cursor", this.cursor())
      map.put(":flip", this.flip())
      map.put(":font", this.font())
      map.put(":hidden", this.hidden())
      map.put(":image-bkg", this.image_bkg())
      map.put(":layout", this.layout())
      map.put(":type", this.type())
      map.put(":pin", this.pin())
      map.put(":pointorigin", this.pointorigin())
      map.put(":pointpos", this.pointpos())
      map.put(":pointrotate", this.pointrotate())
      map.put(":pointsize", this.pointsize())
      map.put(":scroll-x", this.scroll_x())
      map.put(":scroll-y", this.scroll_y())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_style = vx_core.vx_copy(vx_ui_ui.e_style, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_style = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_style = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_align : vx_ui_ui.Type_align = value.align()
      var vx_p_boundsmargin : vx_ui_ui.Type_bounds = value.boundsmargin()
      var vx_p_boundspadding : vx_ui_ui.Type_bounds = value.boundspadding()
      var vx_p_color_bkg : vx_core.Type_string = value.color_bkg()
      var vx_p_color_bkghover : vx_core.Type_string = value.color_bkghover()
      var vx_p_color_border : vx_core.Type_string = value.color_border()
      var vx_p_color_font : vx_core.Type_string = value.color_font()
      var vx_p_cursor : vx_ui_ui.Type_cursor = value.cursor()
      var vx_p_flip : vx_ui_ui.Type_flip = value.flip()
      var vx_p_font : vx_ui_ui.Type_font = value.font()
      var vx_p_hidden : vx_core.Type_boolean = value.hidden()
      var vx_p_image_bkg : vx_ui_ui.Type_image = value.image_bkg()
      var vx_p_layout : vx_ui_ui.Type_layout = value.layout()
      var vx_p_type : vx_ui_ui.Type_styletype = value.type()
      var vx_p_pin : vx_ui_ui.Type_pin = value.pin()
      var vx_p_pointorigin : vx_ui_ui.Type_point = value.pointorigin()
      var vx_p_pointpos : vx_ui_ui.Type_point = value.pointpos()
      var vx_p_pointrotate : vx_ui_ui.Type_point = value.pointrotate()
      var vx_p_pointsize : vx_ui_ui.Type_point = value.pointsize()
      var vx_p_scroll_x : vx_core.Type_boolean = value.scroll_x()
      var vx_p_scroll_y : vx_core.Type_boolean = value.scroll_y()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":align")
      validkeys.add(":boundsmargin")
      validkeys.add(":boundspadding")
      validkeys.add(":color-bkg")
      validkeys.add(":color-bkghover")
      validkeys.add(":color-border")
      validkeys.add(":color-font")
      validkeys.add(":cursor")
      validkeys.add(":flip")
      validkeys.add(":font")
      validkeys.add(":hidden")
      validkeys.add(":image-bkg")
      validkeys.add(":layout")
      validkeys.add(":type")
      validkeys.add(":pin")
      validkeys.add(":pointorigin")
      validkeys.add(":pointpos")
      validkeys.add(":pointrotate")
      validkeys.add(":pointsize")
      validkeys.add(":scroll-x")
      validkeys.add(":scroll-y")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":align")) {
            if (valsub == vx_p_align) {
            } else if (valsub is vx_ui_ui.Type_align) {
              var valalign : vx_ui_ui.Type_align = valsub as vx_ui_ui.Type_align
              ischanged = true
              vx_p_align = valalign
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("align"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boundsmargin")) {
            if (valsub == vx_p_boundsmargin) {
            } else if (valsub is vx_ui_ui.Type_bounds) {
              var valboundsmargin : vx_ui_ui.Type_bounds = valsub as vx_ui_ui.Type_bounds
              ischanged = true
              vx_p_boundsmargin = valboundsmargin
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boundsmargin"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":boundspadding")) {
            if (valsub == vx_p_boundspadding) {
            } else if (valsub is vx_ui_ui.Type_bounds) {
              var valboundspadding : vx_ui_ui.Type_bounds = valsub as vx_ui_ui.Type_bounds
              ischanged = true
              vx_p_boundspadding = valboundspadding
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("boundspadding"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":color-bkg")) {
            if (valsub == vx_p_color_bkg) {
            } else if (valsub is vx_core.Type_string) {
              var valcolor_bkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_color_bkg = valcolor_bkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_color_bkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("color-bkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":color-bkghover")) {
            if (valsub == vx_p_color_bkghover) {
            } else if (valsub is vx_core.Type_string) {
              var valcolor_bkghover : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_color_bkghover = valcolor_bkghover
            } else if (valsub is String) {
              ischanged = true
              vx_p_color_bkghover = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("color-bkghover"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":color-border")) {
            if (valsub == vx_p_color_border) {
            } else if (valsub is vx_core.Type_string) {
              var valcolor_border : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_color_border = valcolor_border
            } else if (valsub is String) {
              ischanged = true
              vx_p_color_border = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("color-border"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":color-font")) {
            if (valsub == vx_p_color_font) {
            } else if (valsub is vx_core.Type_string) {
              var valcolor_font : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_color_font = valcolor_font
            } else if (valsub is String) {
              ischanged = true
              vx_p_color_font = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("color-font"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":cursor")) {
            if (valsub == vx_p_cursor) {
            } else if (valsub is vx_ui_ui.Type_cursor) {
              var valcursor : vx_ui_ui.Type_cursor = valsub as vx_ui_ui.Type_cursor
              ischanged = true
              vx_p_cursor = valcursor
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("cursor"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":flip")) {
            if (valsub == vx_p_flip) {
            } else if (valsub is vx_ui_ui.Type_flip) {
              var valflip : vx_ui_ui.Type_flip = valsub as vx_ui_ui.Type_flip
              ischanged = true
              vx_p_flip = valflip
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("flip"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":font")) {
            if (valsub == vx_p_font) {
            } else if (valsub is vx_ui_ui.Type_font) {
              var valfont : vx_ui_ui.Type_font = valsub as vx_ui_ui.Type_font
              ischanged = true
              vx_p_font = valfont
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("font"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":hidden")) {
            if (valsub == vx_p_hidden) {
            } else if (valsub is vx_core.Type_boolean) {
              var valhidden : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_hidden = valhidden
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_hidden = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("hidden"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":image-bkg")) {
            if (valsub == vx_p_image_bkg) {
            } else if (valsub is vx_ui_ui.Type_image) {
              var valimage_bkg : vx_ui_ui.Type_image = valsub as vx_ui_ui.Type_image
              ischanged = true
              vx_p_image_bkg = valimage_bkg
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("image-bkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":layout")) {
            if (valsub == vx_p_layout) {
            } else if (valsub is vx_ui_ui.Type_layout) {
              var vallayout : vx_ui_ui.Type_layout = valsub as vx_ui_ui.Type_layout
              ischanged = true
              vx_p_layout = vallayout
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("layout"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":type")) {
            if (valsub == vx_p_type) {
            } else if (valsub is vx_ui_ui.Type_styletype) {
              var valtype : vx_ui_ui.Type_styletype = valsub as vx_ui_ui.Type_styletype
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pin")) {
            if (valsub == vx_p_pin) {
            } else if (valsub is vx_ui_ui.Type_pin) {
              var valpin : vx_ui_ui.Type_pin = valsub as vx_ui_ui.Type_pin
              ischanged = true
              vx_p_pin = valpin
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pin"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pointorigin")) {
            if (valsub == vx_p_pointorigin) {
            } else if (valsub is vx_ui_ui.Type_point) {
              var valpointorigin : vx_ui_ui.Type_point = valsub as vx_ui_ui.Type_point
              ischanged = true
              vx_p_pointorigin = valpointorigin
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pointorigin"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pointpos")) {
            if (valsub == vx_p_pointpos) {
            } else if (valsub is vx_ui_ui.Type_point) {
              var valpointpos : vx_ui_ui.Type_point = valsub as vx_ui_ui.Type_point
              ischanged = true
              vx_p_pointpos = valpointpos
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pointpos"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pointrotate")) {
            if (valsub == vx_p_pointrotate) {
            } else if (valsub is vx_ui_ui.Type_point) {
              var valpointrotate : vx_ui_ui.Type_point = valsub as vx_ui_ui.Type_point
              ischanged = true
              vx_p_pointrotate = valpointrotate
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pointrotate"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":pointsize")) {
            if (valsub == vx_p_pointsize) {
            } else if (valsub is vx_ui_ui.Type_point) {
              var valpointsize : vx_ui_ui.Type_point = valsub as vx_ui_ui.Type_point
              ischanged = true
              vx_p_pointsize = valpointsize
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pointsize"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":scroll-x")) {
            if (valsub == vx_p_scroll_x) {
            } else if (valsub is vx_core.Type_boolean) {
              var valscroll_x : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_scroll_x = valscroll_x
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_scroll_x = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("scroll-x"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":scroll-y")) {
            if (valsub == vx_p_scroll_y) {
            } else if (valsub is vx_core.Type_boolean) {
              var valscroll_y : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_scroll_y = valscroll_y
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_scroll_y = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("scroll-y"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_style = vx_ui_ui.Class_style()
        work.vx_p_name = vx_p_name
        work.vx_p_align = vx_p_align
        work.vx_p_boundsmargin = vx_p_boundsmargin
        work.vx_p_boundspadding = vx_p_boundspadding
        work.vx_p_color_bkg = vx_p_color_bkg
        work.vx_p_color_bkghover = vx_p_color_bkghover
        work.vx_p_color_border = vx_p_color_border
        work.vx_p_color_font = vx_p_color_font
        work.vx_p_cursor = vx_p_cursor
        work.vx_p_flip = vx_p_flip
        work.vx_p_font = vx_p_font
        work.vx_p_hidden = vx_p_hidden
        work.vx_p_image_bkg = vx_p_image_bkg
        work.vx_p_layout = vx_p_layout
        work.vx_p_type = vx_p_type
        work.vx_p_pin = vx_p_pin
        work.vx_p_pointorigin = vx_p_pointorigin
        work.vx_p_pointpos = vx_p_pointpos
        work.vx_p_pointrotate = vx_p_pointrotate
        work.vx_p_pointsize = vx_p_pointsize
        work.vx_p_scroll_x = vx_p_scroll_x
        work.vx_p_scroll_y = vx_p_scroll_y
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_style
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_style
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
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

  val e_style : vx_ui_ui.Type_style = vx_ui_ui.Class_style()
  val t_style : vx_ui_ui.Type_style = vx_ui_ui.Class_style()

  interface Type_stylelist : vx_core.Type_list {
    fun vx_liststyle() : List<vx_ui_ui.Type_style>
    fun vx_style(index : vx_core.Type_int) : vx_ui_ui.Type_style
  }

  class Class_stylelist : vx_core.Class_base, Type_stylelist {
    constructor() {}

    var vx_p_list : List<vx_ui_ui.Type_style> = vx_core.immutablelist(
      ArrayList<vx_ui_ui.Type_style>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_style(index : vx_core.Type_int) : vx_ui_ui.Type_style {
      var output : vx_ui_ui.Type_style = vx_ui_ui.e_style
      var list : vx_ui_ui.Class_stylelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_ui_ui.Type_style> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_liststyle() : List<vx_ui_ui.Type_style> {
      var output : List<vx_ui_ui.Type_style> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_ui_ui.Type_style = this.vx_style(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_stylelist = vx_core.vx_copy(vx_ui_ui.e_stylelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_stylelist = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_stylelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_ui_ui.Type_style> = ArrayList<vx_ui_ui.Type_style>(value.vx_liststyle())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_ui_ui.Type_stylelist) {
          var multi : vx_ui_ui.Type_stylelist = valsub as vx_ui_ui.Type_stylelist
          ischanged = true
          listval.addAll(multi.vx_liststyle())
        } else if (valsub is vx_ui_ui.Type_style) {
          var allowsub : vx_ui_ui.Type_style = valsub as vx_ui_ui.Type_style
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_ui_ui.Type_style) {
          ischanged = true
          listval.add(valsub as vx_ui_ui.Type_style)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_ui_ui.Type_style) {
              var valitem : vx_ui_ui.Type_style = item as vx_ui_ui.Type_style
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_stylelist = vx_ui_ui.Class_stylelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_style), // allowtypes
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

  val e_stylelist : vx_ui_ui.Type_stylelist = vx_ui_ui.Class_stylelist()
  val t_stylelist : vx_ui_ui.Type_stylelist = vx_ui_ui.Class_stylelist()

  interface Type_stylemap : vx_core.Type_map {
    fun vx_mapstyle() : Map<String, vx_ui_ui.Type_style>
    fun vx_style(key : vx_core.Type_string) : vx_ui_ui.Type_style
  }

  class Class_stylemap : vx_core.Class_base, Type_stylemap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_style> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_style>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_style) {
        var castval : vx_ui_ui.Type_style = value as vx_ui_ui.Type_style
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_style> = LinkedHashMap<String, vx_ui_ui.Type_style>(this.vx_p_map)
        if (castval == vx_ui_ui.e_style) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_style(key : vx_core.Type_string) : vx_ui_ui.Type_style {
      var output : vx_ui_ui.Type_style = vx_ui_ui.e_style
      var map : vx_ui_ui.Class_stylemap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_style> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_style)
      return output
    }

    override fun vx_mapstyle() : Map<String, vx_ui_ui.Type_style> {
      var output : Map<String, vx_ui_ui.Type_style> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_style(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_stylemap = vx_ui_ui.Class_stylemap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_style> = LinkedHashMap<String, vx_ui_ui.Type_style>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_style) {
          var castval : vx_ui_ui.Type_style = value as vx_ui_ui.Type_style
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_stylemap = vx_core.vx_copy(vx_ui_ui.e_stylemap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_stylemap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_stylemap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_style> = LinkedHashMap<String, vx_ui_ui.Type_style>(value.vx_mapstyle())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/stylemap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_style = vx_ui_ui.e_style
          if (false) {
          } else if (valsub is vx_ui_ui.Type_style) {
            var valallowed : vx_ui_ui.Type_style = valsub as vx_ui_ui.Type_style
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_style) {
            valany = valsub as vx_ui_ui.Type_style
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_stylemap = vx_ui_ui.Class_stylemap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_stylemap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylemap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_style), // allowtypes
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

  val e_stylemap : vx_ui_ui.Type_stylemap = vx_ui_ui.Class_stylemap()
  val t_stylemap : vx_ui_ui.Type_stylemap = vx_ui_ui.Class_stylemap()

  interface Type_stylesheet : vx_core.Type_struct {
    fun fontfacemap() : vx_ui_ui.Type_fontfacemap
    fun stylemap() : vx_ui_ui.Type_stylemap
  }

  class Class_stylesheet : vx_core.Class_base, Type_stylesheet {
    constructor() {}

    var vx_p_fontfacemap : vx_ui_ui.Type_fontfacemap? = null

    override fun fontfacemap() : vx_ui_ui.Type_fontfacemap {
      var output : vx_ui_ui.Type_fontfacemap = vx_ui_ui.e_fontfacemap
      var testnull : vx_ui_ui.Type_fontfacemap? = vx_p_fontfacemap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylemap : vx_ui_ui.Type_stylemap? = null

    override fun stylemap() : vx_ui_ui.Type_stylemap {
      var output : vx_ui_ui.Type_stylemap = vx_ui_ui.e_stylemap
      var testnull : vx_ui_ui.Type_stylemap? = vx_p_stylemap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":fontfacemap")) {
        output = this.fontfacemap()
      } else if ((skey==":stylemap")) {
        output = this.stylemap()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":fontfacemap", this.fontfacemap())
      map.put(":stylemap", this.stylemap())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_stylesheet = vx_core.vx_copy(vx_ui_ui.e_stylesheet, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_stylesheet = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_stylesheet = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_fontfacemap : vx_ui_ui.Type_fontfacemap = value.fontfacemap()
      var vx_p_stylemap : vx_ui_ui.Type_stylemap = value.stylemap()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":fontfacemap")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":fontfacemap")) {
            if (valsub == vx_p_fontfacemap) {
            } else if (valsub is vx_ui_ui.Type_fontfacemap) {
              var valfontfacemap : vx_ui_ui.Type_fontfacemap = valsub as vx_ui_ui.Type_fontfacemap
              ischanged = true
              vx_p_fontfacemap = valfontfacemap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fontfacemap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylemap")) {
            if (valsub == vx_p_stylemap) {
            } else if (valsub is vx_ui_ui.Type_stylemap) {
              var valstylemap : vx_ui_ui.Type_stylemap = valsub as vx_ui_ui.Type_stylemap
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_stylesheet = vx_ui_ui.Class_stylesheet()
        work.vx_p_fontfacemap = vx_p_fontfacemap
        work.vx_p_stylemap = vx_p_stylemap
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_stylesheet
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylesheet
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet", // name
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

  val e_stylesheet : vx_ui_ui.Type_stylesheet = vx_ui_ui.Class_stylesheet()
  val t_stylesheet : vx_ui_ui.Type_stylesheet = vx_ui_ui.Class_stylesheet()

  interface Type_styletype : vx_core.Type_struct {
  }

  class Class_styletype : vx_core.Class_base, Type_styletype {
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
      var output : vx_ui_ui.Type_styletype = vx_core.vx_copy(vx_ui_ui.e_styletype, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_styletype = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_styletype = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_styletype = vx_ui_ui.Class_styletype()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_styletype
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_styletype
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "styletype", // name
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

  val e_styletype : vx_ui_ui.Type_styletype = vx_ui_ui.Class_styletype()
  val t_styletype : vx_ui_ui.Type_styletype = vx_ui_ui.Class_styletype()

  interface Type_ui : vx_core.Type_struct {
    fun uid() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun layout() : vx_ui_ui.Type_layout
    fun path() : vx_core.Type_string
    fun hidden() : vx_core.Type_boolean
    fun selected() : vx_core.Type_boolean
    fun selectmulti() : vx_core.Type_boolean
    fun style() : vx_ui_ui.Type_style
    fun stylelist() : vx_ui_ui.Type_stylelist
    fun eventmap() : vx_event.Type_eventmap
    fun data() : vx_core.Type_any
    fun uimap() : vx_ui_ui.Type_uimap
  }

  class Class_ui : vx_core.Class_base, Type_ui {
    constructor() {}

    var vx_p_uid : vx_core.Type_string? = null

    override fun uid() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_uid
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

    var vx_p_layout : vx_ui_ui.Type_layout? = null

    override fun layout() : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
      var testnull : vx_ui_ui.Type_layout? = vx_p_layout
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_path : vx_core.Type_string? = null

    override fun path() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_path
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_hidden : vx_core.Type_boolean? = null

    override fun hidden() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_hidden
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_selected : vx_core.Type_boolean? = null

    override fun selected() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_selected
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_selectmulti : vx_core.Type_boolean? = null

    override fun selectmulti() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_selectmulti
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_style : vx_ui_ui.Type_style? = null

    override fun style() : vx_ui_ui.Type_style {
      var output : vx_ui_ui.Type_style = vx_ui_ui.e_style
      var testnull : vx_ui_ui.Type_style? = vx_p_style
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylelist : vx_ui_ui.Type_stylelist? = null

    override fun stylelist() : vx_ui_ui.Type_stylelist {
      var output : vx_ui_ui.Type_stylelist = vx_ui_ui.e_stylelist
      var testnull : vx_ui_ui.Type_stylelist? = vx_p_stylelist
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

    var vx_p_data : vx_core.Type_any? = null

    override fun data() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_data
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_uimap : vx_ui_ui.Type_uimap? = null

    override fun uimap() : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
      var testnull : vx_ui_ui.Type_uimap? = vx_p_uimap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":uid")) {
        output = this.uid()
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":layout")) {
        output = this.layout()
      } else if ((skey==":path")) {
        output = this.path()
      } else if ((skey==":hidden")) {
        output = this.hidden()
      } else if ((skey==":selected")) {
        output = this.selected()
      } else if ((skey==":selectmulti")) {
        output = this.selectmulti()
      } else if ((skey==":style")) {
        output = this.style()
      } else if ((skey==":stylelist")) {
        output = this.stylelist()
      } else if ((skey==":eventmap")) {
        output = this.eventmap()
      } else if ((skey==":data")) {
        output = this.data()
      } else if ((skey==":uimap")) {
        output = this.uimap()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":uid", this.uid())
      map.put(":name", this.name())
      map.put(":layout", this.layout())
      map.put(":path", this.path())
      map.put(":hidden", this.hidden())
      map.put(":selected", this.selected())
      map.put(":selectmulti", this.selectmulti())
      map.put(":style", this.style())
      map.put(":stylelist", this.stylelist())
      map.put(":eventmap", this.eventmap())
      map.put(":data", this.data())
      map.put(":uimap", this.uimap())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_ui = vx_core.vx_copy(vx_ui_ui.e_ui, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_ui = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_ui = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_uid : vx_core.Type_string = value.uid()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_layout : vx_ui_ui.Type_layout = value.layout()
      var vx_p_path : vx_core.Type_string = value.path()
      var vx_p_hidden : vx_core.Type_boolean = value.hidden()
      var vx_p_selected : vx_core.Type_boolean = value.selected()
      var vx_p_selectmulti : vx_core.Type_boolean = value.selectmulti()
      var vx_p_style : vx_ui_ui.Type_style = value.style()
      var vx_p_stylelist : vx_ui_ui.Type_stylelist = value.stylelist()
      var vx_p_eventmap : vx_event.Type_eventmap = value.eventmap()
      var vx_p_data : vx_core.Type_any = value.data()
      var vx_p_uimap : vx_ui_ui.Type_uimap = value.uimap()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":uid")
      validkeys.add(":name")
      validkeys.add(":layout")
      validkeys.add(":path")
      validkeys.add(":hidden")
      validkeys.add(":selected")
      validkeys.add(":selectmulti")
      validkeys.add(":style")
      validkeys.add(":stylelist")
      validkeys.add(":eventmap")
      validkeys.add(":data")
      validkeys.add(":uimap")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":uid")) {
            if (valsub == vx_p_uid) {
            } else if (valsub is vx_core.Type_string) {
              var valuid : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_uid = valuid
            } else if (valsub is String) {
              ischanged = true
              vx_p_uid = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("uid"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":layout")) {
            if (valsub == vx_p_layout) {
            } else if (valsub is vx_ui_ui.Type_layout) {
              var vallayout : vx_ui_ui.Type_layout = valsub as vx_ui_ui.Type_layout
              ischanged = true
              vx_p_layout = vallayout
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("layout"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":path")) {
            if (valsub == vx_p_path) {
            } else if (valsub is vx_core.Type_string) {
              var valpath : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_path = valpath
            } else if (valsub is String) {
              ischanged = true
              vx_p_path = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("path"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":hidden")) {
            if (valsub == vx_p_hidden) {
            } else if (valsub is vx_core.Type_boolean) {
              var valhidden : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_hidden = valhidden
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_hidden = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("hidden"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":selected")) {
            if (valsub == vx_p_selected) {
            } else if (valsub is vx_core.Type_boolean) {
              var valselected : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_selected = valselected
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_selected = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("selected"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":selectmulti")) {
            if (valsub == vx_p_selectmulti) {
            } else if (valsub is vx_core.Type_boolean) {
              var valselectmulti : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_selectmulti = valselectmulti
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_selectmulti = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("selectmulti"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":style")) {
            if (valsub == vx_p_style) {
            } else if (valsub is vx_ui_ui.Type_style) {
              var valstyle : vx_ui_ui.Type_style = valsub as vx_ui_ui.Type_style
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylelist")) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub is vx_ui_ui.Type_stylelist) {
              var valstylelist : vx_ui_ui.Type_stylelist = valsub as vx_ui_ui.Type_stylelist
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":data")) {
            if (valsub == vx_p_data) {
            } else if (valsub is vx_core.Type_any) {
              var valdata : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_data = valdata
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("data"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":uimap")) {
            if (valsub == vx_p_uimap) {
            } else if (valsub is vx_ui_ui.Type_uimap) {
              var valuimap : vx_ui_ui.Type_uimap = valsub as vx_ui_ui.Type_uimap
              ischanged = true
              vx_p_uimap = valuimap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("uimap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_ui = vx_ui_ui.Class_ui()
        work.vx_p_uid = vx_p_uid
        work.vx_p_name = vx_p_name
        work.vx_p_layout = vx_p_layout
        work.vx_p_path = vx_p_path
        work.vx_p_hidden = vx_p_hidden
        work.vx_p_selected = vx_p_selected
        work.vx_p_selectmulti = vx_p_selectmulti
        work.vx_p_style = vx_p_style
        work.vx_p_stylelist = vx_p_stylelist
        work.vx_p_eventmap = vx_p_eventmap
        work.vx_p_data = vx_p_data
        work.vx_p_uimap = vx_p_uimap
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "ui", // name
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

  val e_ui : vx_ui_ui.Type_ui = vx_ui_ui.Class_ui()
  val t_ui : vx_ui_ui.Type_ui = vx_ui_ui.Class_ui()

  interface Type_uiengine : vx_core.Type_struct {
    fun parentmap() : vx_ui_ui.Type_uimap
    fun layoutengine() : vx_ui_ui.Type_layoutengine
    fun stylesheet() : vx_ui_ui.Type_stylesheet
    fun ui() : vx_ui_ui.Type_ui
  }

  class Class_uiengine : vx_core.Class_base, Type_uiengine {
    constructor() {}

    var vx_p_parentmap : vx_ui_ui.Type_uimap? = null

    override fun parentmap() : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
      var testnull : vx_ui_ui.Type_uimap? = vx_p_parentmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_layoutengine : vx_ui_ui.Type_layoutengine? = null

    override fun layoutengine() : vx_ui_ui.Type_layoutengine {
      var output : vx_ui_ui.Type_layoutengine = vx_ui_ui.e_layoutengine
      var testnull : vx_ui_ui.Type_layoutengine? = vx_p_layoutengine
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_stylesheet : vx_ui_ui.Type_stylesheet? = null

    override fun stylesheet() : vx_ui_ui.Type_stylesheet {
      var output : vx_ui_ui.Type_stylesheet = vx_ui_ui.e_stylesheet
      var testnull : vx_ui_ui.Type_stylesheet? = vx_p_stylesheet
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_ui : vx_ui_ui.Type_ui? = null

    override fun ui() : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
      var testnull : vx_ui_ui.Type_ui? = vx_p_ui
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":parentmap")) {
        output = this.parentmap()
      } else if ((skey==":layoutengine")) {
        output = this.layoutengine()
      } else if ((skey==":stylesheet")) {
        output = this.stylesheet()
      } else if ((skey==":ui")) {
        output = this.ui()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":parentmap", this.parentmap())
      map.put(":layoutengine", this.layoutengine())
      map.put(":stylesheet", this.stylesheet())
      map.put(":ui", this.ui())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_uiengine = vx_core.vx_copy(vx_ui_ui.e_uiengine, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_uiengine = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_uiengine = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_parentmap : vx_ui_ui.Type_uimap = value.parentmap()
      var vx_p_layoutengine : vx_ui_ui.Type_layoutengine = value.layoutengine()
      var vx_p_stylesheet : vx_ui_ui.Type_stylesheet = value.stylesheet()
      var vx_p_ui : vx_ui_ui.Type_ui = value.ui()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":parentmap")
      validkeys.add(":layoutengine")
      validkeys.add(":stylesheet")
      validkeys.add(":ui")
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":parentmap")) {
            if (valsub == vx_p_parentmap) {
            } else if (valsub is vx_ui_ui.Type_uimap) {
              var valparentmap : vx_ui_ui.Type_uimap = valsub as vx_ui_ui.Type_uimap
              ischanged = true
              vx_p_parentmap = valparentmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("parentmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":layoutengine")) {
            if (valsub == vx_p_layoutengine) {
            } else if (valsub is vx_ui_ui.Type_layoutengine) {
              var vallayoutengine : vx_ui_ui.Type_layoutengine = valsub as vx_ui_ui.Type_layoutengine
              ischanged = true
              vx_p_layoutengine = vallayoutengine
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("layoutengine"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":stylesheet")) {
            if (valsub == vx_p_stylesheet) {
            } else if (valsub is vx_ui_ui.Type_stylesheet) {
              var valstylesheet : vx_ui_ui.Type_stylesheet = valsub as vx_ui_ui.Type_stylesheet
              ischanged = true
              vx_p_stylesheet = valstylesheet
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("stylesheet"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":ui")) {
            if (valsub == vx_p_ui) {
            } else if (valsub is vx_ui_ui.Type_ui) {
              var valui : vx_ui_ui.Type_ui = valsub as vx_ui_ui.Type_ui
              ischanged = true
              vx_p_ui = valui
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("ui"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_uiengine = vx_ui_ui.Class_uiengine()
        work.vx_p_parentmap = vx_p_parentmap
        work.vx_p_layoutengine = vx_p_layoutengine
        work.vx_p_stylesheet = vx_p_stylesheet
        work.vx_p_ui = vx_p_ui
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_uiengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uiengine
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine", // name
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

  val e_uiengine : vx_ui_ui.Type_uiengine = vx_ui_ui.Class_uiengine()
  val t_uiengine : vx_ui_ui.Type_uiengine = vx_ui_ui.Class_uiengine()

  interface Type_uilist : vx_core.Type_list {
    fun vx_listui() : List<vx_ui_ui.Type_ui>
    fun vx_ui(index : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_uilist : vx_core.Class_base, Type_uilist {
    constructor() {}

    var vx_p_list : List<vx_ui_ui.Type_ui> = vx_core.immutablelist(
      ArrayList<vx_ui_ui.Type_ui>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_ui(index : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
      var list : vx_ui_ui.Class_uilist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_ui_ui.Type_ui> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listui() : List<vx_ui_ui.Type_ui> {
      var output : List<vx_ui_ui.Type_ui> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_ui_ui.Type_ui = this.vx_ui(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_uilist = vx_core.vx_copy(vx_ui_ui.e_uilist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_uilist = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_uilist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_ui_ui.Type_ui> = ArrayList<vx_ui_ui.Type_ui>(value.vx_listui())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_ui_ui.Type_uilist) {
          var multi : vx_ui_ui.Type_uilist = valsub as vx_ui_ui.Type_uilist
          ischanged = true
          listval.addAll(multi.vx_listui())
        } else if (valsub is vx_ui_ui.Type_ui) {
          var allowsub : vx_ui_ui.Type_ui = valsub as vx_ui_ui.Type_ui
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_ui_ui.Type_ui) {
          ischanged = true
          listval.add(valsub as vx_ui_ui.Type_ui)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_ui_ui.Type_ui) {
              var valitem : vx_ui_ui.Type_ui = item as vx_ui_ui.Type_ui
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_ui_ui.Class_uilist = vx_ui_ui.Class_uilist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_uilist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uilist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "uilist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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

  val e_uilist : vx_ui_ui.Type_uilist = vx_ui_ui.Class_uilist()
  val t_uilist : vx_ui_ui.Type_uilist = vx_ui_ui.Class_uilist()

  interface Type_uimap : vx_core.Type_map {
    fun vx_mapui() : Map<String, vx_ui_ui.Type_ui>
    fun vx_ui(key : vx_core.Type_string) : vx_ui_ui.Type_ui
  }

  class Class_uimap : vx_core.Class_base, Type_uimap {
    constructor() {}

    var vx_p_map : Map<String, vx_ui_ui.Type_ui> = vx_core.immutablemap(LinkedHashMap<String, vx_ui_ui.Type_ui>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_ui_ui.Type_ui) {
        var castval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_ui_ui.Type_ui> = LinkedHashMap<String, vx_ui_ui.Type_ui>(this.vx_p_map)
        if (castval == vx_ui_ui.e_ui) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_ui(key : vx_core.Type_string) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
      var map : vx_ui_ui.Class_uimap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_ui_ui.Type_ui> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_ui_ui.e_ui)
      return output
    }

    override fun vx_mapui() : Map<String, vx_ui_ui.Type_ui> {
      var output : Map<String, vx_ui_ui.Type_ui> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_ui(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_ui_ui.Class_uimap = vx_ui_ui.Class_uimap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_ui_ui.Type_ui> = LinkedHashMap<String, vx_ui_ui.Type_ui>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_ui_ui.Type_ui) {
          var castval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidvalue", value)
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
      var output : vx_ui_ui.Type_uimap = vx_core.vx_copy(vx_ui_ui.e_uimap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_ui_ui.Type_uimap = this
      var ischanged : Boolean = false
      var value : vx_ui_ui.Class_uimap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_ui_ui.Type_ui> = LinkedHashMap<String, vx_ui_ui.Type_ui>(value.vx_mapui())
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/uimap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
          if (false) {
          } else if (valsub is vx_ui_ui.Type_ui) {
            var valallowed : vx_ui_ui.Type_ui = valsub as vx_ui_ui.Type_ui
            valany = valallowed
          } else if (valsub is vx_ui_ui.Type_ui) {
            valany = valsub as vx_ui_ui.Type_ui
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
            msg = vx_core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidkeyvalue", msgmap)
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
        var work : vx_ui_ui.Class_uimap = vx_ui_ui.Class_uimap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.e_uimap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uimap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/ui/ui", // pkgname
        "uimap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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

  val e_uimap : vx_ui_ui.Type_uimap = vx_ui_ui.Class_uimap()
  val t_uimap : vx_ui_ui.Type_uimap = vx_ui_ui.Class_uimap()

  class Const_align_center {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-center", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_align_center : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_align_left {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-left", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_align_left : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_align_right {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-right", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_align_right : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_flip_x {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-x", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_flip_x : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_flip_xy {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-xy", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_flip_xy : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_flip_y {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-y", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
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

    fun const_new(output : vx_ui_ui.Type_align) : Unit {
      var outval : vx_ui_ui.Class_align = output as vx_ui_ui.Class_align
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_flip_y : vx_ui_ui.Type_align = vx_ui_ui.Class_align()


  class Const_layout_app {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-app", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-app")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_app : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_background {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-background", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-background")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_background : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_button {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-button", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-button")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_button : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_combobox {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-combobox", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-combobox")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_combobox : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_else {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-else", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-else")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_else : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_flow_columns {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-columns", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-flow-columns")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_flow_columns : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_flow_item {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-item", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-flow-item")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_flow_item : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_flow_rows {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-rows", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-flow-rows")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_flow_rows : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_image {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-image", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-image")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_image : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_label {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-label", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-label")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_label : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_main {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-main", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-main")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_main : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_maxpanel {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-maxpanel", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-maxpanel")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_maxpanel : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_menubar {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menubar", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-menubar")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_menubar : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_menudrawer {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menudrawer", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-menudrawer")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_menudrawer : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_msgbox {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-msgbox", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-msgbox")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_msgbox : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_navbar {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navbar", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-navbar")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_navbar : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_navdrawer {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navdrawer", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-navdrawer")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_navdrawer : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_panel {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-panel", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-panel")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_panel : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_parallax {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-parallax", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-parallax")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_parallax : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_statusbar {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusbar", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-statusbar")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_statusbar : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_statusdrawer {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusdrawer", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-statusdrawer")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_statusdrawer : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_text {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-text", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-text")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_text : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_textentry {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-textentry", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-textentry")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_textentry : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_layout_titlebar {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-titlebar", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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

    fun const_new(output : vx_ui_ui.Type_layout) : Unit {
      var outval : vx_ui_ui.Class_layout = output as vx_ui_ui.Class_layout
      outval.vx_p_constdef = constdef()
      var value : vx_ui_ui.Type_layout = vx_core.f_new(
        vx_ui_ui.t_layout,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("layout-titlebar")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_fn_layout = value.fn_layout()
    }

    }
  }

  val c_layout_titlebar : vx_ui_ui.Type_layout = vx_ui_ui.Class_layout()


  class Const_pin_bottom {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-bottom", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_bottom : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_center {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_center : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_center_h {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-h", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_center_h : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_center_v {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-v", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_center_v : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_expand {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-expand", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_expand : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_left {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-left", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_left : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_right {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-right", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_right : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_pin_top {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-top", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
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

    fun const_new(output : vx_ui_ui.Type_pin) : Unit {
      var outval : vx_ui_ui.Class_pin = output as vx_ui_ui.Class_pin
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pin_top : vx_ui_ui.Type_pin = vx_ui_ui.Class_pin()


  class Const_point_center {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-center", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
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

    fun const_new(output : vx_ui_ui.Type_point) : Unit {
      var outval : vx_ui_ui.Class_point = output as vx_ui_ui.Class_point
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_point_center : vx_ui_ui.Type_point = vx_ui_ui.Class_point()


  class Const_point_lefttop {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-lefttop", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
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

    fun const_new(output : vx_ui_ui.Type_point) : Unit {
      var outval : vx_ui_ui.Class_point = output as vx_ui_ui.Class_point
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_point_lefttop : vx_ui_ui.Type_point = vx_ui_ui.Class_point()


  class Const_point_rightbottom {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-rightbottom", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
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

    fun const_new(output : vx_ui_ui.Type_point) : Unit {
      var outval : vx_ui_ui.Class_point = output as vx_ui_ui.Class_point
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_point_rightbottom : vx_ui_ui.Type_point = vx_ui_ui.Class_point()


  class Const_pointtype_absolute {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-absolute", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
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

    fun const_new(output : vx_ui_ui.Type_pointtype) : Unit {
      var outval : vx_ui_ui.Class_pointtype = output as vx_ui_ui.Class_pointtype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pointtype_absolute : vx_ui_ui.Type_pointtype = vx_ui_ui.Class_pointtype()


  class Const_pointtype_percent {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-percent", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
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

    fun const_new(output : vx_ui_ui.Type_pointtype) : Unit {
      var outval : vx_ui_ui.Class_pointtype = output as vx_ui_ui.Class_pointtype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pointtype_percent : vx_ui_ui.Type_pointtype = vx_ui_ui.Class_pointtype()


  class Const_pointtype_relative {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-relative", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
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

    fun const_new(output : vx_ui_ui.Type_pointtype) : Unit {
      var outval : vx_ui_ui.Class_pointtype = output as vx_ui_ui.Class_pointtype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_pointtype_relative : vx_ui_ui.Type_pointtype = vx_ui_ui.Class_pointtype()


  class Const_styletype_custom {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-custom", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
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

    fun const_new(output : vx_ui_ui.Type_styletype) : Unit {
      var outval : vx_ui_ui.Class_styletype = output as vx_ui_ui.Class_styletype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_styletype_custom : vx_ui_ui.Type_styletype = vx_ui_ui.Class_styletype()


  class Const_styletype_shared {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-shared", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
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

    fun const_new(output : vx_ui_ui.Type_styletype) : Unit {
      var outval : vx_ui_ui.Class_styletype = output as vx_ui_ui.Class_styletype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_styletype_shared : vx_ui_ui.Type_styletype = vx_ui_ui.Class_styletype()


  class Const_styletype_system {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-system", // name
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
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

    fun const_new(output : vx_ui_ui.Type_styletype) : Unit {
      var outval : vx_ui_ui.Class_styletype = output as vx_ui_ui.Class_styletype
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_styletype_system : vx_ui_ui.Type_styletype = vx_ui_ui.Class_styletype()


  interface Func_boolean_layout_from_ui_parent_selected : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layout_from_ui_parent_selected(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_boolean) : vx_core.Type_boolean
  }

  class Class_boolean_layout_from_ui_parent_selected : vx_core.Class_base, Func_boolean_layout_from_ui_parent_selected {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layout_from_ui_parent_selected = vx_ui_ui.Class_boolean_layout_from_ui_parent_selected()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layout_from_ui_parent_selected = vx_ui_ui.Class_boolean_layout_from_ui_parent_selected()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-selected", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layout_from_ui_parent_selected
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layout_from_ui_parent_selected
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var selected : vx_core.Type_boolean = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected)
      return output
    }

    override fun vx_boolean_layout_from_ui_parent_selected(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_boolean) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected)
      return output
    }

  }

  val e_boolean_layout_from_ui_parent_selected : vx_ui_ui.Func_boolean_layout_from_ui_parent_selected = vx_ui_ui.Class_boolean_layout_from_ui_parent_selected()
  val t_boolean_layout_from_ui_parent_selected : vx_ui_ui.Func_boolean_layout_from_ui_parent_selected = vx_ui_ui.Class_boolean_layout_from_ui_parent_selected()

  fun f_boolean_layout_from_ui_parent_selected(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_boolean) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var uiselected : vx_ui_ui.Type_ui = vx_core.f_copy(
          ui,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":selected"),
            selected
          )
        )
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(
          uiselected,
          parent
        )
        var fn_layoutselected : vx_ui_ui.Func_boolean_layoutselected_from_ui = layoutengine.boolean_layoutselected()
        var output_1 : vx_core.Type_any = vx_core.vx_any_from_func(
          vx_core.t_boolean,
          fn_layoutselected,
          uiselected
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layout_from_ui_parent_visible : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layout_from_ui_parent_visible(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_boolean) : vx_core.Type_boolean
  }

  class Class_boolean_layout_from_ui_parent_visible : vx_core.Class_base, Func_boolean_layout_from_ui_parent_visible {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layout_from_ui_parent_visible = vx_ui_ui.Class_boolean_layout_from_ui_parent_visible()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layout_from_ui_parent_visible = vx_ui_ui.Class_boolean_layout_from_ui_parent_visible()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-visible", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layout_from_ui_parent_visible
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layout_from_ui_parent_visible
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var visible : vx_core.Type_boolean = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible)
      return output
    }

    override fun vx_boolean_layout_from_ui_parent_visible(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_boolean) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible)
      return output
    }

  }

  val e_boolean_layout_from_ui_parent_visible : vx_ui_ui.Func_boolean_layout_from_ui_parent_visible = vx_ui_ui.Class_boolean_layout_from_ui_parent_visible()
  val t_boolean_layout_from_ui_parent_visible : vx_ui_ui.Func_boolean_layout_from_ui_parent_visible = vx_ui_ui.Class_boolean_layout_from_ui_parent_visible()

  fun f_boolean_layout_from_ui_parent_visible(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_boolean) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var uivisible : vx_ui_ui.Type_ui = vx_core.f_copy(
          ui,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":hidden"),
            vx_core.f_not(
              visible
            )
          )
        )
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(
          uivisible,
          parent
        )
        var fn_layoutvisible : vx_ui_ui.Func_boolean_layoutvisible_from_ui = layoutengine.boolean_layoutvisible()
        var output_1 : vx_core.Type_any = vx_core.vx_any_from_func(
          vx_core.t_boolean,
          fn_layoutvisible,
          uivisible
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutaddchild_from_ui_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutaddchild_from_ui_parent(context : vx_core.Type_context, uiarg : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutaddchild_from_ui_parent : vx_core.Class_base, Func_boolean_layoutaddchild_from_ui_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent = vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent = vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutaddchild<-ui-parent", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutaddchild_from_ui_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutaddchild_from_ui_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent)
      return output
    }

    override fun vx_boolean_layoutaddchild_from_ui_parent(context : vx_core.Type_context, uiarg : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent)
      return output
    }

  }

  val e_boolean_layoutaddchild_from_ui_parent : vx_ui_ui.Func_boolean_layoutaddchild_from_ui_parent = vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent()
  val t_boolean_layoutaddchild_from_ui_parent : vx_ui_ui.Func_boolean_layoutaddchild_from_ui_parent = vx_ui_ui.Class_boolean_layoutaddchild_from_ui_parent()

  fun f_boolean_layoutaddchild_from_ui_parent(context : vx_core.Type_context, uiarg : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var ui2 : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui(
          context,
          uiarg
        )
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(
          ui2,
          parent
        )
        var ui3 : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout_from_ui_orig_parent(
          ui2,
          vx_core.f_empty(
            vx_ui_ui.t_ui
          ),
          parent
        )
        var output_1 : vx_core.Type_any = iswrite
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutremove_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_layoutremove_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutremove_from_ui : vx_core.Class_base, Func_boolean_layoutremove_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui = vx_ui_ui.Class_boolean_layoutremove_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui = vx_ui_ui.Class_boolean_layoutremove_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutremove_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutremove_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_layoutremove_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_layoutremove_from_ui(ui)
      return output
    }

    override fun vx_boolean_layoutremove_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutremove_from_ui(ui)
      return output
    }

  }

  val e_boolean_layoutremove_from_ui : vx_ui_ui.Func_boolean_layoutremove_from_ui = vx_ui_ui.Class_boolean_layoutremove_from_ui()
  val t_boolean_layoutremove_from_ui : vx_ui_ui.Func_boolean_layoutremove_from_ui = vx_ui_ui.Class_boolean_layoutremove_from_ui()

  fun f_boolean_layoutremove_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_layoutremove_from_ui_keys : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutremove_from_ui_keys(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, keys : vx_core.Type_stringlist) : vx_core.Type_boolean
  }

  class Class_boolean_layoutremove_from_ui_keys : vx_core.Class_base, Func_boolean_layoutremove_from_ui_keys {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_keys = vx_ui_ui.Class_boolean_layoutremove_from_ui_keys()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_keys = vx_ui_ui.Class_boolean_layoutremove_from_ui_keys()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-keys", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutremove_from_ui_keys
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutremove_from_ui_keys
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var keys : vx_core.Type_stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys)
      return output
    }

    override fun vx_boolean_layoutremove_from_ui_keys(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, keys : vx_core.Type_stringlist) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys)
      return output
    }

  }

  val e_boolean_layoutremove_from_ui_keys : vx_ui_ui.Func_boolean_layoutremove_from_ui_keys = vx_ui_ui.Class_boolean_layoutremove_from_ui_keys()
  val t_boolean_layoutremove_from_ui_keys : vx_ui_ui.Func_boolean_layoutremove_from_ui_keys = vx_ui_ui.Class_boolean_layoutremove_from_ui_keys()

  fun f_boolean_layoutremove_from_ui_keys(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, keys : vx_core.Type_stringlist) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var writelist : vx_core.Type_booleanlist = vx_core.f_list_from_list_1(
          vx_core.t_booleanlist,
          keys,
          vx_core.t_any_from_any.vx_fn_new({key_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var output_2 : vx_core.Type_any = vx_core.f_let(
              vx_core.t_boolean,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var childui : vx_ui_ui.Type_ui = vx_core.f_any_from_map(
                  vx_ui_ui.t_ui,
                  uimap,
                  key
                )
                var output_3 : vx_core.Type_any = vx_ui_ui.f_boolean_layoutremove_from_ui_parent(
                  context,
                  childui,
                  ui
                )
                output_3
              })
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


  interface Func_boolean_layoutremove_from_ui_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutremove_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutremove_from_ui_parent : vx_core.Class_base, Func_boolean_layoutremove_from_ui_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_parent = vx_ui_ui.Class_boolean_layoutremove_from_ui_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_parent = vx_ui_ui.Class_boolean_layoutremove_from_ui_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-parent", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutremove_from_ui_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutremove_from_ui_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent)
      return output
    }

    override fun vx_boolean_layoutremove_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent)
      return output
    }

  }

  val e_boolean_layoutremove_from_ui_parent : vx_ui_ui.Func_boolean_layoutremove_from_ui_parent = vx_ui_ui.Class_boolean_layoutremove_from_ui_parent()
  val t_boolean_layoutremove_from_ui_parent : vx_ui_ui.Func_boolean_layoutremove_from_ui_parent = vx_ui_ui.Class_boolean_layoutremove_from_ui_parent()

  fun f_boolean_layoutremove_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var uid : vx_core.Type_string = ui.uid()
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_writeremove_from_ui_uid(
          parent,
          uid
        )
        var fn_layoutremove : vx_ui_ui.Func_boolean_layoutremove_from_ui = layoutengine.boolean_layoutremove()
        var output_1 : vx_core.Type_any = vx_core.vx_any_from_func(
          vx_core.t_boolean,
          fn_layoutremove,
          ui
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutremove_from_ui_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutremove_from_ui_start_end(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_boolean
  }

  class Class_boolean_layoutremove_from_ui_start_end : vx_core.Class_base, Func_boolean_layoutremove_from_ui_start_end {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end = vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end = vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-start-end", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutremove_from_ui_start_end
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutremove_from_ui_start_end
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var start : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      var end : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end)
      return output
    }

    override fun vx_boolean_layoutremove_from_ui_start_end(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end)
      return output
    }

  }

  val e_boolean_layoutremove_from_ui_start_end : vx_ui_ui.Func_boolean_layoutremove_from_ui_start_end = vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end()
  val t_boolean_layoutremove_from_ui_start_end : vx_ui_ui.Func_boolean_layoutremove_from_ui_start_end = vx_ui_ui.Class_boolean_layoutremove_from_ui_start_end()

  fun f_boolean_layoutremove_from_ui_start_end(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, start : vx_core.Type_int, end : vx_core.Type_int) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var keys : vx_core.Type_stringlist = vx_core.f_stringlist_from_map(
          uimap
        )
        var subkeys : vx_core.Type_stringlist = vx_collection.f_list_from_list_start_end(
          vx_core.t_stringlist,
          keys,
          start,
          end
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_boolean_layoutremove_from_ui_keys(
          context,
          ui,
          subkeys
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutselected_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_layoutselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutselected_from_ui : vx_core.Class_base, Func_boolean_layoutselected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui = vx_ui_ui.Class_boolean_layoutselected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui = vx_ui_ui.Class_boolean_layoutselected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutselected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutselected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_layoutselected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_layoutselected_from_ui(ui)
      return output
    }

    override fun vx_boolean_layoutselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutselected_from_ui(ui)
      return output
    }

  }

  val e_boolean_layoutselected_from_ui : vx_ui_ui.Func_boolean_layoutselected_from_ui = vx_ui_ui.Class_boolean_layoutselected_from_ui()
  val t_boolean_layoutselected_from_ui : vx_ui_ui.Func_boolean_layoutselected_from_ui = vx_ui_ui.Class_boolean_layoutselected_from_ui()

  fun f_boolean_layoutselected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_layoutselected_from_ui_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutselected_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutselected_from_ui_parent : vx_core.Class_base, Func_boolean_layoutselected_from_ui_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui_parent = vx_ui_ui.Class_boolean_layoutselected_from_ui_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui_parent = vx_ui_ui.Class_boolean_layoutselected_from_ui_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-parent", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutselected_from_ui_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutselected_from_ui_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent)
      return output
    }

    override fun vx_boolean_layoutselected_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent)
      return output
    }

  }

  val e_boolean_layoutselected_from_ui_parent : vx_ui_ui.Func_boolean_layoutselected_from_ui_parent = vx_ui_ui.Class_boolean_layoutselected_from_ui_parent()
  val t_boolean_layoutselected_from_ui_parent : vx_ui_ui.Func_boolean_layoutselected_from_ui_parent = vx_ui_ui.Class_boolean_layoutselected_from_ui_parent()

  fun f_boolean_layoutselected_from_ui_parent(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(
          ui,
          parent
        )
        var fn_layoutselected : vx_ui_ui.Func_boolean_layoutselected_from_ui = layoutengine.boolean_layoutselected()
        var output_1 : vx_core.Type_any = vx_core.vx_any_from_func(
          vx_core.t_boolean,
          fn_layoutselected,
          ui
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_layoutselected_from_ui_selected : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_layoutselected_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_core.Type_boolean
  }

  class Class_boolean_layoutselected_from_ui_selected : vx_core.Class_base, Func_boolean_layoutselected_from_ui_selected {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui_selected = vx_ui_ui.Class_boolean_layoutselected_from_ui_selected()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutselected_from_ui_selected = vx_ui_ui.Class_boolean_layoutselected_from_ui_selected()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-selected", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutselected_from_ui_selected
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutselected_from_ui_selected
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var selected : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_layoutselected_from_ui_selected(ui, selected)
      return output
    }

    override fun vx_boolean_layoutselected_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutselected_from_ui_selected(ui, selected)
      return output
    }

  }

  val e_boolean_layoutselected_from_ui_selected : vx_ui_ui.Func_boolean_layoutselected_from_ui_selected = vx_ui_ui.Class_boolean_layoutselected_from_ui_selected()
  val t_boolean_layoutselected_from_ui_selected : vx_ui_ui.Func_boolean_layoutselected_from_ui_selected = vx_ui_ui.Class_boolean_layoutselected_from_ui_selected()

  fun f_boolean_layoutselected_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_layoutvisible_from_ui : vx_core.Func_any_from_any {
    fun vx_boolean_layoutvisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_layoutvisible_from_ui : vx_core.Class_base, Func_boolean_layoutvisible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutvisible_from_ui = vx_ui_ui.Class_boolean_layoutvisible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_layoutvisible_from_ui = vx_ui_ui.Class_boolean_layoutvisible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutvisible<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_layoutvisible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_layoutvisible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_layoutvisible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_layoutvisible_from_ui(ui)
      return output
    }

    override fun vx_boolean_layoutvisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_layoutvisible_from_ui(ui)
      return output
    }

  }

  val e_boolean_layoutvisible_from_ui : vx_ui_ui.Func_boolean_layoutvisible_from_ui = vx_ui_ui.Class_boolean_layoutvisible_from_ui()
  val t_boolean_layoutvisible_from_ui : vx_ui_ui.Func_boolean_layoutvisible_from_ui = vx_ui_ui.Class_boolean_layoutvisible_from_ui()

  fun f_boolean_layoutvisible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    return output
  }


  interface Func_boolean_print : vx_core.Func_any_from_any_context {
    fun vx_boolean_print(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_print : vx_core.Class_base, Func_boolean_print {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_print = vx_ui_ui.Class_boolean_print()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_print = vx_ui_ui.Class_boolean_print()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-print", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_print
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_print
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_print(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_print(context, ui)
      return output
    }

    override fun vx_boolean_print(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_print(context, ui)
      return output
    }

  }

  val e_boolean_print : vx_ui_ui.Func_boolean_print = vx_ui_ui.Class_boolean_print()
  val t_boolean_print : vx_ui_ui.Func_boolean_print = vx_ui_ui.Class_boolean_print()

  fun f_boolean_print(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var fn_print : vx_ui_ui.Func_boolean_print = layoutengine.boolean_print()
        var output_1 : vx_core.Type_any = vx_core.vx_any_from_func(
          vx_core.t_boolean,
          fn_print,
          context,
          ui
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_removestate_uiapp : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_removestate_uiapp(context : vx_core.Type_context) : vx_core.Type_boolean
  }

  class Class_boolean_removestate_uiapp : vx_core.Class_base, Func_boolean_removestate_uiapp {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_removestate_uiapp = vx_ui_ui.Class_boolean_removestate_uiapp()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_removestate_uiapp = vx_ui_ui.Class_boolean_removestate_uiapp()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-removestate-uiapp", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_removestate_uiapp
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_removestate_uiapp
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_removestate_uiapp(context)
      return output
    }

    override fun vx_boolean_removestate_uiapp(context : vx_core.Type_context) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_removestate_uiapp(context)
      return output
    }

  }

  val e_boolean_removestate_uiapp : vx_ui_ui.Func_boolean_removestate_uiapp = vx_ui_ui.Class_boolean_removestate_uiapp()
  val t_boolean_removestate_uiapp : vx_ui_ui.Func_boolean_removestate_uiapp = vx_ui_ui.Class_boolean_removestate_uiapp()

  fun f_boolean_removestate_uiapp(context : vx_core.Type_context) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_state.f_boolean_removestate_from_name(
      context,
      vx_core.vx_new_string(":uiapp")
    )
    return output
  }


  interface Func_boolean_write_from_ui_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_ui_parent(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_ui_parent : vx_core.Class_base, Func_boolean_write_from_ui_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_write_from_ui_parent = vx_ui_ui.Class_boolean_write_from_ui_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_write_from_ui_parent = vx_ui_ui.Class_boolean_write_from_ui_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-write<-ui-parent", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_write_from_ui_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_write_from_ui_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_write_from_ui_parent(ui, parent)
      return output
    }

    override fun vx_boolean_write_from_ui_parent(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(ui, parent)
      return output
    }

  }

  val e_boolean_write_from_ui_parent : vx_ui_ui.Func_boolean_write_from_ui_parent = vx_ui_ui.Class_boolean_write_from_ui_parent()
  val t_boolean_write_from_ui_parent : vx_ui_ui.Func_boolean_write_from_ui_parent = vx_ui_ui.Class_boolean_write_from_ui_parent()

  fun f_boolean_write_from_ui_parent(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uimap : vx_ui_ui.Type_uimap = parent.uimap()
        var output_1 : vx_core.Type_any = vx_core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          ui
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writeremove_from_ui_uid : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_writeremove_from_ui_uid(uiarg : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_writeremove_from_ui_uid : vx_core.Class_base, Func_boolean_writeremove_from_ui_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writeremove_from_ui_uid = vx_ui_ui.Class_boolean_writeremove_from_ui_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writeremove_from_ui_uid = vx_ui_ui.Class_boolean_writeremove_from_ui_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writeremove<-ui-uid", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_writeremove_from_ui_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_writeremove_from_ui_uid
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_boolean_writeremove_from_ui_uid(uiarg, uid)
      return output
    }

    override fun vx_boolean_writeremove_from_ui_uid(uiarg : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_writeremove_from_ui_uid(uiarg, uid)
      return output
    }

  }

  val e_boolean_writeremove_from_ui_uid : vx_ui_ui.Func_boolean_writeremove_from_ui_uid = vx_ui_ui.Class_boolean_writeremove_from_ui_uid()
  val t_boolean_writeremove_from_ui_uid : vx_ui_ui.Func_boolean_writeremove_from_ui_uid = vx_ui_ui.Class_boolean_writeremove_from_ui_uid()

  fun f_boolean_writeremove_from_ui_uid(uiarg : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = uiarg.uimap()
        var output_1 : vx_core.Type_any = vx_core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          vx_core.f_empty(
            vx_ui_ui.t_ui
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writestate_from_ui : vx_core.Func_any_from_any_context {
    fun vx_boolean_writestate_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_ui : vx_core.Class_base, Func_boolean_writestate_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_ui = vx_ui_ui.Class_boolean_writestate_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_ui = vx_ui_ui.Class_boolean_writestate_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_writestate_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_writestate_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_writestate_from_ui(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_writestate_from_ui(context, ui)
      return output
    }

    override fun vx_boolean_writestate_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_writestate_from_ui(context, ui)
      return output
    }

  }

  val e_boolean_writestate_from_ui : vx_ui_ui.Func_boolean_writestate_from_ui = vx_ui_ui.Class_boolean_writestate_from_ui()
  val t_boolean_writestate_from_ui : vx_ui_ui.Func_boolean_writestate_from_ui = vx_ui_ui.Class_boolean_writestate_from_ui()

  fun f_boolean_writestate_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = ui.uid()
        var uiapp : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_readstate_uiapp(
          context
        )
        var parentuid : vx_core.Type_string = vx_ui_ui.f_string_parentuid_from_uid(
          uid
        )
        var parentui : vx_ui_ui.Type_ui = vx_core.f_if_2(
          vx_ui_ui.t_ui,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  vx_core.vx_new_string(""),
                  parentuid
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = uiapp
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_ui_ui.f_ui_from_ui_find(
                  uiapp,
                  parentuid
                )
                output_4
              })
            )
          )
        )
        var isfound : vx_core.Type_boolean = vx_core.f_notempty_1(
          parentui
        )
        var iswrite : vx_core.Type_boolean = vx_core.f_if_2(
          vx_core.t_boolean,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = isfound
                output_5
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_ui_ui.f_boolean_write_from_ui_parent(
                  ui,
                  parentui
                )
                output_6
              })
            )
          )
        )
        var output_1 : vx_core.Type_any = isfound
        output_1
      })
    )
    return output
  }


  interface Func_boolean_writestate_from_uiapp : vx_core.Func_any_from_any_context {
    fun vx_boolean_writestate_from_uiapp(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_uiapp : vx_core.Class_base, Func_boolean_writestate_from_uiapp {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_uiapp = vx_ui_ui.Class_boolean_writestate_from_uiapp()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_uiapp = vx_ui_ui.Class_boolean_writestate_from_uiapp()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiapp", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_writestate_from_uiapp
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_writestate_from_uiapp
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_writestate_from_uiapp(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_writestate_from_uiapp(context, ui)
      return output
    }

    override fun vx_boolean_writestate_from_uiapp(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_writestate_from_uiapp(context, ui)
      return output
    }

  }

  val e_boolean_writestate_from_uiapp : vx_ui_ui.Func_boolean_writestate_from_uiapp = vx_ui_ui.Class_boolean_writestate_from_uiapp()
  val t_boolean_writestate_from_uiapp : vx_ui_ui.Func_boolean_writestate_from_uiapp = vx_ui_ui.Class_boolean_writestate_from_uiapp()

  fun f_boolean_writestate_from_uiapp(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_state.f_boolean_writestate_from_name_value(
      context,
      vx_core.vx_new_string(":uiapp"),
      ui
    )
    return output
  }


  interface Func_boolean_writestate_from_uiengine : vx_core.Func_any_from_any_context {
    fun vx_boolean_writestate_from_uiengine(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_core.Type_boolean
  }

  class Class_boolean_writestate_from_uiengine : vx_core.Class_base, Func_boolean_writestate_from_uiengine {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_uiengine = vx_ui_ui.Class_boolean_writestate_from_uiengine()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_boolean_writestate_from_uiengine = vx_ui_ui.Class_boolean_writestate_from_uiengine()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiengine", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_boolean_writestate_from_uiengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_boolean_writestate_from_uiengine
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uiengine = value as vx_ui_ui.Type_uiengine
      var outputval : vx_core.Type_any = vx_ui_ui.f_boolean_writestate_from_uiengine(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var uiengine : vx_ui_ui.Type_uiengine = vx_core.f_any_from_any(vx_ui_ui.t_uiengine, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_boolean_writestate_from_uiengine(context, uiengine)
      return output
    }

    override fun vx_boolean_writestate_from_uiengine(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_ui_ui.f_boolean_writestate_from_uiengine(context, uiengine)
      return output
    }

  }

  val e_boolean_writestate_from_uiengine : vx_ui_ui.Func_boolean_writestate_from_uiengine = vx_ui_ui.Class_boolean_writestate_from_uiengine()
  val t_boolean_writestate_from_uiengine : vx_ui_ui.Func_boolean_writestate_from_uiengine = vx_ui_ui.Class_boolean_writestate_from_uiengine()

  fun f_boolean_writestate_from_uiengine(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_state.f_boolean_writestate_from_name_value(
      context,
      vx_core.vx_new_string(":uiengine"),
      uiengine
    )
    return output
  }


  interface Func_fontfacemap_from_fontfacelist : vx_core.Func_any_from_any {
    fun vx_fontfacemap_from_fontfacelist(fontfacelist : vx_ui_ui.Type_fontfacelist) : vx_ui_ui.Type_fontfacemap
  }

  class Class_fontfacemap_from_fontfacelist : vx_core.Class_base, Func_fontfacemap_from_fontfacelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_fontfacemap_from_fontfacelist = vx_ui_ui.Class_fontfacemap_from_fontfacelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_fontfacemap_from_fontfacelist = vx_ui_ui.Class_fontfacemap_from_fontfacelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "fontfacemap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_fontface), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_fontfacemap_from_fontfacelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_fontfacemap_from_fontfacelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_fontfacelist = value as vx_ui_ui.Type_fontfacelist
      var outputval : vx_core.Type_any = vx_ui_ui.f_fontfacemap_from_fontfacelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var fontfacelist : vx_ui_ui.Type_fontfacelist = vx_core.f_any_from_any(vx_ui_ui.t_fontfacelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_fontfacemap_from_fontfacelist(fontfacelist)
      return output
    }

    override fun vx_fontfacemap_from_fontfacelist(fontfacelist : vx_ui_ui.Type_fontfacelist) : vx_ui_ui.Type_fontfacemap {
      var output : vx_ui_ui.Type_fontfacemap = vx_ui_ui.f_fontfacemap_from_fontfacelist(fontfacelist)
      return output
    }

  }

  val e_fontfacemap_from_fontfacelist : vx_ui_ui.Func_fontfacemap_from_fontfacelist = vx_ui_ui.Class_fontfacemap_from_fontfacelist()
  val t_fontfacemap_from_fontfacelist : vx_ui_ui.Func_fontfacemap_from_fontfacelist = vx_ui_ui.Class_fontfacemap_from_fontfacelist()

  fun f_fontfacemap_from_fontfacelist(fontfacelist : vx_ui_ui.Type_fontfacelist) : vx_ui_ui.Type_fontfacemap {
    var output : vx_ui_ui.Type_fontfacemap = vx_ui_ui.e_fontfacemap
    output = vx_core.f_map_from_list(
      vx_ui_ui.t_fontfacemap,
      fontfacelist,
      vx_core.t_any_from_any.vx_fn_new({fontface_any : vx_core.Type_any ->
        var fontface : vx_ui_ui.Type_fontface = vx_core.f_any_from_any(vx_ui_ui.t_fontface, fontface_any)
        var output_1 : vx_core.Type_any = fontface.name()
        output_1
      })
    )
    return output
  }


  interface Func_int_child_from_ui_uid : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_int_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_int
  }

  class Class_int_child_from_ui_uid : vx_core.Class_base, Func_int_child_from_ui_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_child_from_ui_uid = vx_ui_ui.Class_int_child_from_ui_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_child_from_ui_uid = vx_ui_ui.Class_int_child_from_ui_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-child<-ui-uid", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_int_child_from_ui_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_int_child_from_ui_uid
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_int_child_from_ui_uid(ui, uid)
      return output
    }

    override fun vx_int_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_ui_ui.f_int_child_from_ui_uid(ui, uid)
      return output
    }

  }

  val e_int_child_from_ui_uid : vx_ui_ui.Func_int_child_from_ui_uid = vx_ui_ui.Class_int_child_from_ui_uid()
  val t_int_child_from_ui_uid : vx_ui_ui.Func_int_child_from_ui_uid = vx_ui_ui.Class_int_child_from_ui_uid()

  fun f_int_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var output_1 : vx_core.Type_any = vx_collection.f_int_from_map_key(
          uimap,
          uid
        )
        output_1
      })
    )
    return output
  }


  interface Func_int_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_int_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int
  }

  class Class_int_selected_from_ui : vx_core.Class_base, Func_int_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_selected_from_ui = vx_ui_ui.Class_int_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_selected_from_ui = vx_ui_ui.Class_int_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-selected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_int_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_int_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_int_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_int_selected_from_ui(ui)
      return output
    }

    override fun vx_int_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_ui_ui.f_int_selected_from_ui(ui)
      return output
    }

  }

  val e_int_selected_from_ui : vx_ui_ui.Func_int_selected_from_ui = vx_ui_ui.Class_int_selected_from_ui()
  val t_int_selected_from_ui : vx_ui_ui.Func_int_selected_from_ui = vx_ui_ui.Class_int_selected_from_ui()

  fun f_int_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = vx_ui_ui.f_string_selected_from_ui(
          ui
        )
        var uidlist : vx_core.Type_stringlist = vx_ui_ui.f_stringlist_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_collection.f_int_from_stringlist_find(
          uidlist,
          uid
        )
        output_1
      })
    )
    return output
  }


  interface Func_int_visible_from_ui : vx_core.Func_any_from_any {
    fun vx_int_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int
  }

  class Class_int_visible_from_ui : vx_core.Class_base, Func_int_visible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_visible_from_ui = vx_ui_ui.Class_int_visible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_int_visible_from_ui = vx_ui_ui.Class_int_visible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-visible<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_int_visible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_int_visible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_int_visible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_int_visible_from_ui(ui)
      return output
    }

    override fun vx_int_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int {
      var output : vx_core.Type_int = vx_ui_ui.f_int_visible_from_ui(ui)
      return output
    }

  }

  val e_int_visible_from_ui : vx_ui_ui.Func_int_visible_from_ui = vx_ui_ui.Class_int_visible_from_ui()
  val t_int_visible_from_ui : vx_ui_ui.Func_int_visible_from_ui = vx_ui_ui.Class_int_visible_from_ui()

  fun f_int_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_int {
    var output : vx_core.Type_int = vx_core.e_int
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var intlist : vx_core.Type_intlist = vx_ui_ui.f_intlist_visible_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_first_from_list(
          vx_core.t_int,
          intlist
        )
        output_1
      })
    )
    return output
  }


  interface Func_intlist_visible_from_ui : vx_core.Func_any_from_any {
    fun vx_intlist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_core.Type_intlist
  }

  class Class_intlist_visible_from_ui : vx_core.Class_base, Func_intlist_visible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_intlist_visible_from_ui = vx_ui_ui.Class_intlist_visible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_intlist_visible_from_ui = vx_ui_ui.Class_intlist_visible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "intlist-visible<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "intlist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_int), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_intlist_visible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_intlist_visible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_intlist_visible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_intlist_visible_from_ui(uiarg)
      return output
    }

    override fun vx_intlist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_core.Type_intlist {
      var output : vx_core.Type_intlist = vx_ui_ui.f_intlist_visible_from_ui(uiarg)
      return output
    }

  }

  val e_intlist_visible_from_ui : vx_ui_ui.Func_intlist_visible_from_ui = vx_ui_ui.Class_intlist_visible_from_ui()
  val t_intlist_visible_from_ui : vx_ui_ui.Func_intlist_visible_from_ui = vx_ui_ui.Class_intlist_visible_from_ui()

  fun f_intlist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_core.Type_intlist {
    var output : vx_core.Type_intlist = vx_core.e_intlist
    output = vx_core.f_let(
      vx_core.t_intlist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = uiarg.uimap()
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
          uimap
        )
        var intlist : vx_ui_ui.Type_uilist = vx_core.f_list_from_list_intany(
          vx_ui_ui.t_uilist,
          uilist,
          vx_core.t_any_from_int_any.vx_fn_new({pos_any : vx_core.Type_any, subui_any : vx_core.Type_any ->
            var pos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, pos_any)
            var subui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, subui_any)
            var output_3 : vx_core.Type_any = vx_core.f_if_2(
              vx_core.t_int,
              vx_core.vx_new(
                vx_core.t_thenelselist,
                vx_core.f_then(
                  vx_core.t_boolean_from_func.vx_fn_new({ ->
                    var output_4 : vx_core.Type_any = vx_core.f_not(
                      subui.hidden()
                    )
                    output_4
                  }),
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var output_5 : vx_core.Type_any = pos
                    output_5
                  })
                )
              )
            )
            output_3
          })
        )
        var output_1 : vx_core.Type_any = vx_collection.f_list_from_list_filter(
          vx_core.t_intlist,
          intlist,
          vx_core.t_any_from_any.vx_fn_new({pos_any : vx_core.Type_any ->
            var pos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, pos_any)
            var output_2 : vx_core.Type_any = pos
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_layout_from_style : vx_core.Func_any_from_any {
    fun vx_layout_from_style(style : vx_ui_ui.Type_style) : vx_ui_ui.Type_layout
  }

  class Class_layout_from_style : vx_core.Class_base, Func_layout_from_style {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_style = vx_ui_ui.Class_layout_from_style()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_style = vx_ui_ui.Class_layout_from_style()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-style", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_layout_from_style
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layout_from_style
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_style = value as vx_ui_ui.Type_style
      var outputval : vx_core.Type_any = vx_ui_ui.f_layout_from_style(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var style : vx_ui_ui.Type_style = vx_core.f_any_from_any(vx_ui_ui.t_style, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_layout_from_style(style)
      return output
    }

    override fun vx_layout_from_style(style : vx_ui_ui.Type_style) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_style(style)
      return output
    }

  }

  val e_layout_from_style : vx_ui_ui.Func_layout_from_style = vx_ui_ui.Class_layout_from_style()
  val t_layout_from_style : vx_ui_ui.Func_layout_from_style = vx_ui_ui.Class_layout_from_style()

  fun f_layout_from_style(style : vx_ui_ui.Type_style) : vx_ui_ui.Type_layout {
    var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
    output = style.layout()
    return output
  }


  interface Func_layout_from_ui : vx_core.Func_any_from_any_context {
    fun vx_layout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_layout
  }

  class Class_layout_from_ui : vx_core.Class_base, Func_layout_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui = vx_ui_ui.Class_layout_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui = vx_ui_ui.Class_layout_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_layout_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layout_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_layout_from_ui(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_layout_from_ui(context, ui)
      return output
    }

    override fun vx_layout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_ui(context, ui)
      return output
    }

  }

  val e_layout_from_ui : vx_ui_ui.Func_layout_from_ui = vx_ui_ui.Class_layout_from_ui()
  val t_layout_from_ui : vx_ui_ui.Func_layout_from_ui = vx_ui_ui.Class_layout_from_ui()

  fun f_layout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_layout {
    var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
    output = vx_core.f_let(
      vx_ui_ui.t_layout,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(
          context
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_layout_from_ui_layoutengine(
          ui,
          layoutengine
        )
        output_1
      })
    )
    return output
  }


  interface Func_layout_from_ui_layoutengine : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_layout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_layout
  }

  class Class_layout_from_ui_layoutengine : vx_core.Class_base, Func_layout_from_ui_layoutengine {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui_layoutengine = vx_ui_ui.Class_layout_from_ui_layoutengine()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui_layoutengine = vx_ui_ui.Class_layout_from_ui_layoutengine()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutengine", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_layout_from_ui_layoutengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layout_from_ui_layoutengine
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var layoutengine : vx_ui_ui.Type_layoutengine = vx_core.f_any_from_any(vx_ui_ui.t_layoutengine, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_layout_from_ui_layoutengine(ui, layoutengine)
      return output
    }

    override fun vx_layout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_ui_layoutengine(ui, layoutengine)
      return output
    }

  }

  val e_layout_from_ui_layoutengine : vx_ui_ui.Func_layout_from_ui_layoutengine = vx_ui_ui.Class_layout_from_ui_layoutengine()
  val t_layout_from_ui_layoutengine : vx_ui_ui.Func_layout_from_ui_layoutengine = vx_ui_ui.Class_layout_from_ui_layoutengine()

  fun f_layout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_layout {
    var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
    output = vx_core.f_let(
      vx_ui_ui.t_layout,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutmap : vx_ui_ui.Type_layoutmap = layoutengine.layoutmap()
        var layoutelse : vx_ui_ui.Type_layout = layoutengine.layoutelse()
        var output_1 : vx_core.Type_any = vx_ui_ui.f_layout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        )
        output_1
      })
    )
    return output
  }


  interface Func_layout_from_ui_layoutmap_else : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_layout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_layout
  }

  class Class_layout_from_ui_layoutmap_else : vx_core.Class_base, Func_layout_from_ui_layoutmap_else {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui_layoutmap_else = vx_ui_ui.Class_layout_from_ui_layoutmap_else()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layout_from_ui_layoutmap_else = vx_ui_ui.Class_layout_from_ui_layoutmap_else()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_layout_from_ui_layoutmap_else
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layout_from_ui_layoutmap_else
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var layoutmap : vx_ui_ui.Type_layoutmap = vx_core.f_any_from_any(vx_ui_ui.t_layoutmap, arglist.vx_any(vx_core.vx_new_int(1)))
      var layoutelse : vx_ui_ui.Type_layout = vx_core.f_any_from_any(vx_ui_ui.t_layout, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      return output
    }

    override fun vx_layout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_layout {
      var output : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      return output
    }

  }

  val e_layout_from_ui_layoutmap_else : vx_ui_ui.Func_layout_from_ui_layoutmap_else = vx_ui_ui.Class_layout_from_ui_layoutmap_else()
  val t_layout_from_ui_layoutmap_else : vx_ui_ui.Func_layout_from_ui_layoutmap_else = vx_ui_ui.Class_layout_from_ui_layoutmap_else()

  fun f_layout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_layout {
    var output : vx_ui_ui.Type_layout = vx_ui_ui.e_layout
    output = vx_core.f_let(
      vx_ui_ui.t_layout,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var style : vx_ui_ui.Type_style = ui.style()
        var layout : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_style(
          style
        )
        var layname : vx_core.Type_string = layout.name()
        var layout1 : vx_ui_ui.Type_layout = vx_core.f_any_from_map(
          vx_ui_ui.t_layout,
          layoutmap,
          layname
        )
        var layout2 : vx_ui_ui.Type_layout = vx_core.f_if_1(
          vx_ui_ui.t_layout,
          vx_core.f_notempty_1(
            layout1
          ),
          layout1,
          layoutelse
        )
        var output_1 : vx_core.Type_any = layout2
        output_1
      })
    )
    return output
  }


  interface Func_layoutengine_readstate : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_layoutengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_layoutengine
  }

  class Class_layoutengine_readstate : vx_core.Class_base, Func_layoutengine_readstate {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layoutengine_readstate = vx_ui_ui.Class_layoutengine_readstate()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layoutengine_readstate = vx_ui_ui.Class_layoutengine_readstate()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutengine-readstate", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_layoutengine_readstate
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layoutengine_readstate
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_layoutengine_readstate(context)
      return output
    }

    override fun vx_layoutengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_layoutengine {
      var output : vx_ui_ui.Type_layoutengine = vx_ui_ui.f_layoutengine_readstate(context)
      return output
    }

  }

  val e_layoutengine_readstate : vx_ui_ui.Func_layoutengine_readstate = vx_ui_ui.Class_layoutengine_readstate()
  val t_layoutengine_readstate : vx_ui_ui.Func_layoutengine_readstate = vx_ui_ui.Class_layoutengine_readstate()

  fun f_layoutengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_layoutengine {
    var output : vx_ui_ui.Type_layoutengine = vx_ui_ui.e_layoutengine
    output = vx_core.f_let(
      vx_ui_ui.t_layoutengine,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uiengine : vx_ui_ui.Type_uiengine = vx_ui_ui.f_uiengine_readstate(
          context
        )
        var output_1 : vx_core.Type_any = uiengine.layoutengine()
        output_1
      })
    )
    return output
  }


  interface Func_layoutmap_from_layoutlist : vx_core.Func_any_from_any {
    fun vx_layoutmap_from_layoutlist(layoutlist : vx_ui_ui.Type_layoutlist) : vx_ui_ui.Type_layoutmap
  }

  class Class_layoutmap_from_layoutlist : vx_core.Class_base, Func_layoutmap_from_layoutlist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layoutmap_from_layoutlist = vx_ui_ui.Class_layoutmap_from_layoutlist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_layoutmap_from_layoutlist = vx_ui_ui.Class_layoutmap_from_layoutlist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_layout), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_layoutmap_from_layoutlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_layoutmap_from_layoutlist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_layoutlist = value as vx_ui_ui.Type_layoutlist
      var outputval : vx_core.Type_any = vx_ui_ui.f_layoutmap_from_layoutlist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var layoutlist : vx_ui_ui.Type_layoutlist = vx_core.f_any_from_any(vx_ui_ui.t_layoutlist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_layoutmap_from_layoutlist(layoutlist)
      return output
    }

    override fun vx_layoutmap_from_layoutlist(layoutlist : vx_ui_ui.Type_layoutlist) : vx_ui_ui.Type_layoutmap {
      var output : vx_ui_ui.Type_layoutmap = vx_ui_ui.f_layoutmap_from_layoutlist(layoutlist)
      return output
    }

  }

  val e_layoutmap_from_layoutlist : vx_ui_ui.Func_layoutmap_from_layoutlist = vx_ui_ui.Class_layoutmap_from_layoutlist()
  val t_layoutmap_from_layoutlist : vx_ui_ui.Func_layoutmap_from_layoutlist = vx_ui_ui.Class_layoutmap_from_layoutlist()

  fun f_layoutmap_from_layoutlist(layoutlist : vx_ui_ui.Type_layoutlist) : vx_ui_ui.Type_layoutmap {
    var output : vx_ui_ui.Type_layoutmap = vx_ui_ui.e_layoutmap
    output = vx_core.f_map_from_list(
      vx_ui_ui.t_layoutmap,
      layoutlist,
      vx_core.t_any_from_any.vx_fn_new({layout_any : vx_core.Type_any ->
        var layout : vx_ui_ui.Type_layout = vx_core.f_any_from_any(vx_ui_ui.t_layout, layout_any)
        var output_1 : vx_core.Type_any = layout.name()
        output_1
      })
    )
    return output
  }


  interface Func_string_parentuid_from_uid : vx_core.Func_any_from_any {
    fun vx_string_parentuid_from_uid(uid : vx_core.Type_string) : vx_core.Type_string
  }

  class Class_string_parentuid_from_uid : vx_core.Class_base, Func_string_parentuid_from_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_string_parentuid_from_uid = vx_ui_ui.Class_string_parentuid_from_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_string_parentuid_from_uid = vx_ui_ui.Class_string_parentuid_from_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-parentuid<-uid", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_string_parentuid_from_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_string_parentuid_from_uid
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_ui_ui.f_string_parentuid_from_uid(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_string_parentuid_from_uid(uid)
      return output
    }

    override fun vx_string_parentuid_from_uid(uid : vx_core.Type_string) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_ui.f_string_parentuid_from_uid(uid)
      return output
    }

  }

  val e_string_parentuid_from_uid : vx_ui_ui.Func_string_parentuid_from_uid = vx_ui_ui.Class_string_parentuid_from_uid()
  val t_string_parentuid_from_uid : vx_ui_ui.Func_string_parentuid_from_uid = vx_ui_ui.Class_string_parentuid_from_uid()

  fun f_string_parentuid_from_uid(uid : vx_core.Type_string) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var lastpos : vx_core.Type_int = vx_type.f_int_from_string_findlast(
          uid,
          vx_core.vx_new_string("/")
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_gt(
                  lastpos,
                  vx_core.vx_new_int(0)
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_type.f_string_from_string_end(
                  uid,
                  vx_core.f_minus(
                    lastpos,
                    vx_core.vx_new_int(1)
                  )
                )
                output_3
              })
            )
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_string_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_string_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string
  }

  class Class_string_selected_from_ui : vx_core.Class_base, Func_string_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_string_selected_from_ui = vx_ui_ui.Class_string_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_string_selected_from_ui = vx_ui_ui.Class_string_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-selected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_string_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_string_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_string_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_string_selected_from_ui(ui)
      return output
    }

    override fun vx_string_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_ui.f_string_selected_from_ui(ui)
      return output
    }

  }

  val e_string_selected_from_ui : vx_ui_ui.Func_string_selected_from_ui = vx_ui_ui.Class_string_selected_from_ui()
  val t_string_selected_from_ui : vx_ui_ui.Func_string_selected_from_ui = vx_ui_ui.Class_string_selected_from_ui()

  fun f_string_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var selectedui : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_selected_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = selectedui.uid()
        output_1
      })
    )
    return output
  }


  interface Func_stringlist_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_stringlist_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist
  }

  class Class_stringlist_selected_from_ui : vx_core.Class_base, Func_stringlist_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stringlist_selected_from_ui = vx_ui_ui.Class_stringlist_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stringlist_selected_from_ui = vx_ui_ui.Class_stringlist_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_stringlist_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stringlist_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_stringlist_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_stringlist_selected_from_ui(ui)
      return output
    }

    override fun vx_stringlist_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_ui_ui.f_stringlist_selected_from_ui(ui)
      return output
    }

  }

  val e_stringlist_selected_from_ui : vx_ui_ui.Func_stringlist_selected_from_ui = vx_ui_ui.Class_stringlist_selected_from_ui()
  val t_stringlist_selected_from_ui : vx_ui_ui.Func_stringlist_selected_from_ui = vx_ui_ui.Class_stringlist_selected_from_ui()

  fun f_stringlist_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_core.f_let(
      vx_core.t_stringlist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
          uimap
        )
        var output_1 : vx_core.Type_any = vx_core.f_list_from_list_1(
          vx_core.t_stringlist,
          uilist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, item_any)
            var output_2 : vx_core.Type_any = vx_core.f_if_1(
              vx_core.t_string,
              item.selected(),
              item.uid(),
              vx_core.vx_new_string("")
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_stringlist_from_ui : vx_core.Func_any_from_any {
    fun vx_stringlist_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist
  }

  class Class_stringlist_from_ui : vx_core.Class_base, Func_stringlist_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stringlist_from_ui = vx_ui_ui.Class_stringlist_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stringlist_from_ui = vx_ui_ui.Class_stringlist_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_stringlist_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stringlist_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_stringlist_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_stringlist_from_ui(ui)
      return output
    }

    override fun vx_stringlist_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist {
      var output : vx_core.Type_stringlist = vx_ui_ui.f_stringlist_from_ui(ui)
      return output
    }

  }

  val e_stringlist_from_ui : vx_ui_ui.Func_stringlist_from_ui = vx_ui_ui.Class_stringlist_from_ui()
  val t_stringlist_from_ui : vx_ui_ui.Func_stringlist_from_ui = vx_ui_ui.Class_stringlist_from_ui()

  fun f_stringlist_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_stringlist {
    var output : vx_core.Type_stringlist = vx_core.e_stringlist
    output = vx_core.f_let(
      vx_core.t_stringlist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var output_1 : vx_core.Type_any = vx_core.f_stringlist_from_map(
          uimap
        )
        output_1
      })
    )
    return output
  }


  interface Func_stylemap_from_stylelist : vx_core.Func_any_from_any {
    fun vx_stylemap_from_stylelist(stylelist : vx_ui_ui.Type_stylelist) : vx_ui_ui.Type_stylemap
  }

  class Class_stylemap_from_stylelist : vx_core.Class_base, Func_stylemap_from_stylelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylemap_from_stylelist = vx_ui_ui.Class_stylemap_from_stylelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylemap_from_stylelist = vx_ui_ui.Class_stylemap_from_stylelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_style), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_stylemap_from_stylelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylemap_from_stylelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylelist = value as vx_ui_ui.Type_stylelist
      var outputval : vx_core.Type_any = vx_ui_ui.f_stylemap_from_stylelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylelist : vx_ui_ui.Type_stylelist = vx_core.f_any_from_any(vx_ui_ui.t_stylelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_stylemap_from_stylelist(stylelist)
      return output
    }

    override fun vx_stylemap_from_stylelist(stylelist : vx_ui_ui.Type_stylelist) : vx_ui_ui.Type_stylemap {
      var output : vx_ui_ui.Type_stylemap = vx_ui_ui.f_stylemap_from_stylelist(stylelist)
      return output
    }

  }

  val e_stylemap_from_stylelist : vx_ui_ui.Func_stylemap_from_stylelist = vx_ui_ui.Class_stylemap_from_stylelist()
  val t_stylemap_from_stylelist : vx_ui_ui.Func_stylemap_from_stylelist = vx_ui_ui.Class_stylemap_from_stylelist()

  fun f_stylemap_from_stylelist(stylelist : vx_ui_ui.Type_stylelist) : vx_ui_ui.Type_stylemap {
    var output : vx_ui_ui.Type_stylemap = vx_ui_ui.e_stylemap
    output = vx_core.f_map_from_list(
      vx_ui_ui.t_stylemap,
      stylelist,
      vx_core.t_any_from_any.vx_fn_new({style_any : vx_core.Type_any ->
        var style : vx_ui_ui.Type_style = vx_core.f_any_from_any(vx_ui_ui.t_style, style_any)
        var output_1 : vx_core.Type_any = style.name()
        output_1
      })
    )
    return output
  }


  interface Func_stylesheet_readstate : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_stylesheet_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_stylesheet
  }

  class Class_stylesheet_readstate : vx_core.Class_base, Func_stylesheet_readstate {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylesheet_readstate = vx_ui_ui.Class_stylesheet_readstate()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylesheet_readstate = vx_ui_ui.Class_stylesheet_readstate()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-readstate", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_stylesheet_readstate
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylesheet_readstate
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_stylesheet_readstate(context)
      return output
    }

    override fun vx_stylesheet_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_stylesheet {
      var output : vx_ui_ui.Type_stylesheet = vx_ui_ui.f_stylesheet_readstate(context)
      return output
    }

  }

  val e_stylesheet_readstate : vx_ui_ui.Func_stylesheet_readstate = vx_ui_ui.Class_stylesheet_readstate()
  val t_stylesheet_readstate : vx_ui_ui.Func_stylesheet_readstate = vx_ui_ui.Class_stylesheet_readstate()

  fun f_stylesheet_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_stylesheet {
    var output : vx_ui_ui.Type_stylesheet = vx_ui_ui.e_stylesheet
    output = vx_core.f_let(
      vx_ui_ui.t_stylesheet,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uiengine : vx_ui_ui.Type_uiengine = vx_ui_ui.f_uiengine_readstate(
          context
        )
        var output_1 : vx_core.Type_any = uiengine.stylesheet()
        output_1
      })
    )
    return output
  }


  interface Func_stylesheet_render : vx_core.Func_any_from_any {
    fun vx_stylesheet_render(stylesheetui : vx_ui_ui.Type_stylesheet) : vx_ui_ui.Type_stylesheet
  }

  class Class_stylesheet_render : vx_core.Class_base, Func_stylesheet_render {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylesheet_render = vx_ui_ui.Class_stylesheet_render()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_stylesheet_render = vx_ui_ui.Class_stylesheet_render()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-render", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_stylesheet_render
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_stylesheet_render
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_stylesheet = value as vx_ui_ui.Type_stylesheet
      var outputval : vx_core.Type_any = vx_ui_ui.f_stylesheet_render(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var stylesheetui : vx_ui_ui.Type_stylesheet = vx_core.f_any_from_any(vx_ui_ui.t_stylesheet, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_stylesheet_render(stylesheetui)
      return output
    }

    override fun vx_stylesheet_render(stylesheetui : vx_ui_ui.Type_stylesheet) : vx_ui_ui.Type_stylesheet {
      var output : vx_ui_ui.Type_stylesheet = vx_ui_ui.f_stylesheet_render(stylesheetui)
      return output
    }

  }

  val e_stylesheet_render : vx_ui_ui.Func_stylesheet_render = vx_ui_ui.Class_stylesheet_render()
  val t_stylesheet_render : vx_ui_ui.Func_stylesheet_render = vx_ui_ui.Class_stylesheet_render()

  fun f_stylesheet_render(stylesheetui : vx_ui_ui.Type_stylesheet) : vx_ui_ui.Type_stylesheet {
    var output : vx_ui_ui.Type_stylesheet = vx_ui_ui.e_stylesheet
    return output
  }


  interface Func_ui_addlayout_from_ui : vx_core.Func_any_from_any_context {
    fun vx_ui_addlayout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_addlayout_from_ui : vx_core.Class_base, Func_ui_addlayout_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui = vx_ui_ui.Class_ui_addlayout_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui = vx_ui_ui.Class_ui_addlayout_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_addlayout_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_addlayout_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_addlayout_from_ui(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_addlayout_from_ui(context, ui)
      return output
    }

    override fun vx_ui_addlayout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui(context, ui)
      return output
    }

  }

  val e_ui_addlayout_from_ui : vx_ui_ui.Func_ui_addlayout_from_ui = vx_ui_ui.Class_ui_addlayout_from_ui()
  val t_ui_addlayout_from_ui : vx_ui_ui.Func_ui_addlayout_from_ui = vx_ui_ui.Class_ui_addlayout_from_ui()

  fun f_ui_addlayout_from_ui(context : vx_core.Type_context, ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uiengine : vx_ui_ui.Type_uiengine = vx_ui_ui.f_uiengine_readstate(
          context
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_addlayout_from_ui_uiengine(
          ui,
          uiengine
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_addlayout_from_ui_layoutengine : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_addlayout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_ui
  }

  class Class_ui_addlayout_from_ui_layoutengine : vx_core.Class_base, Func_ui_addlayout_from_ui_layoutengine {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine = vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine = vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutengine", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_addlayout_from_ui_layoutengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_addlayout_from_ui_layoutengine
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var layoutengine : vx_ui_ui.Type_layoutengine = vx_core.f_any_from_any(vx_ui_ui.t_layoutengine, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine)
      return output
    }

    override fun vx_ui_addlayout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine)
      return output
    }

  }

  val e_ui_addlayout_from_ui_layoutengine : vx_ui_ui.Func_ui_addlayout_from_ui_layoutengine = vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine()
  val t_ui_addlayout_from_ui_layoutengine : vx_ui_ui.Func_ui_addlayout_from_ui_layoutengine = vx_ui_ui.Class_ui_addlayout_from_ui_layoutengine()

  fun f_ui_addlayout_from_ui_layoutengine(ui : vx_ui_ui.Type_ui, layoutengine : vx_ui_ui.Type_layoutengine) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutmap : vx_ui_ui.Type_layoutmap = layoutengine.layoutmap()
        var layoutelse : vx_ui_ui.Type_layout = layoutengine.layoutelse()
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_addlayout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_addlayout_from_ui_layoutmap_else : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_addlayout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_ui
  }

  class Class_ui_addlayout_from_ui_layoutmap_else : vx_core.Class_base, Func_ui_addlayout_from_ui_layoutmap_else {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else = vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else = vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_addlayout_from_ui_layoutmap_else
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_addlayout_from_ui_layoutmap_else
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var layoutmap : vx_ui_ui.Type_layoutmap = vx_core.f_any_from_any(vx_ui_ui.t_layoutmap, arglist.vx_any(vx_core.vx_new_int(1)))
      var layoutelse : vx_ui_ui.Type_layout = vx_core.f_any_from_any(vx_ui_ui.t_layout, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      return output
    }

    override fun vx_ui_addlayout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      return output
    }

  }

  val e_ui_addlayout_from_ui_layoutmap_else : vx_ui_ui.Func_ui_addlayout_from_ui_layoutmap_else = vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else()
  val t_ui_addlayout_from_ui_layoutmap_else : vx_ui_ui.Func_ui_addlayout_from_ui_layoutmap_else = vx_ui_ui.Class_ui_addlayout_from_ui_layoutmap_else()

  fun f_ui_addlayout_from_ui_layoutmap_else(ui : vx_ui_ui.Type_ui, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var layout1 : vx_ui_ui.Type_layout = vx_ui_ui.f_layout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        )
        var uimap2 : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_addlayout_from_uimap_layoutmap_else(
          uimap,
          layoutmap,
          layoutelse
        )
        var output_1 : vx_core.Type_any = vx_core.f_copy(
          ui,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":layout"),
            layout1,
            vx_core.vx_new_string(":uimap"),
            uimap2
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_addlayout_from_ui_uiengine : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_addlayout_from_ui_uiengine(ui : vx_ui_ui.Type_ui, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_ui
  }

  class Class_ui_addlayout_from_ui_uiengine : vx_core.Class_base, Func_ui_addlayout_from_ui_uiengine {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_uiengine = vx_ui_ui.Class_ui_addlayout_from_ui_uiengine()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_addlayout_from_ui_uiengine = vx_ui_ui.Class_ui_addlayout_from_ui_uiengine()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-uiengine", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_addlayout_from_ui_uiengine
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_addlayout_from_ui_uiengine
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var uiengine : vx_ui_ui.Type_uiengine = vx_core.f_any_from_any(vx_ui_ui.t_uiengine, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine)
      return output
    }

    override fun vx_ui_addlayout_from_ui_uiengine(ui : vx_ui_ui.Type_ui, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine)
      return output
    }

  }

  val e_ui_addlayout_from_ui_uiengine : vx_ui_ui.Func_ui_addlayout_from_ui_uiengine = vx_ui_ui.Class_ui_addlayout_from_ui_uiengine()
  val t_ui_addlayout_from_ui_uiengine : vx_ui_ui.Func_ui_addlayout_from_ui_uiengine = vx_ui_ui.Class_ui_addlayout_from_ui_uiengine()

  fun f_ui_addlayout_from_ui_uiengine(ui : vx_ui_ui.Type_ui, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var layoutengine : vx_ui_ui.Type_layoutengine = uiengine.layoutengine()
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_addlayout_from_ui_layoutengine(
          ui,
          layoutengine
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_child_from_ui_pos : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_child_from_ui_pos(ui : vx_ui_ui.Type_ui, pos : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_ui_child_from_ui_pos : vx_core.Class_base, Func_ui_child_from_ui_pos {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_child_from_ui_pos = vx_ui_ui.Class_ui_child_from_ui_pos()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_child_from_ui_pos = vx_ui_ui.Class_ui_child_from_ui_pos()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-pos", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_child_from_ui_pos
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_child_from_ui_pos
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var pos : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_child_from_ui_pos(ui, pos)
      return output
    }

    override fun vx_ui_child_from_ui_pos(ui : vx_ui_ui.Type_ui, pos : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_child_from_ui_pos(ui, pos)
      return output
    }

  }

  val e_ui_child_from_ui_pos : vx_ui_ui.Func_ui_child_from_ui_pos = vx_ui_ui.Class_ui_child_from_ui_pos()
  val t_ui_child_from_ui_pos : vx_ui_ui.Func_ui_child_from_ui_pos = vx_ui_ui.Class_ui_child_from_ui_pos()

  fun f_ui_child_from_ui_pos(ui : vx_ui_ui.Type_ui, pos : vx_core.Type_int) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var childmap : vx_ui_ui.Type_uimap = ui.uimap()
        var output_1 : vx_core.Type_any = vx_collection.f_any_from_map_pos(
          vx_ui_ui.t_ui,
          childmap,
          pos
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_child_from_ui_uid : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_ui_ui.Type_ui
  }

  class Class_ui_child_from_ui_uid : vx_core.Class_base, Func_ui_child_from_ui_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_child_from_ui_uid = vx_ui_ui.Class_ui_child_from_ui_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_child_from_ui_uid = vx_ui_ui.Class_ui_child_from_ui_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-uid", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_child_from_ui_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_child_from_ui_uid
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_child_from_ui_uid(ui, uid)
      return output
    }

    override fun vx_ui_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_child_from_ui_uid(ui, uid)
      return output
    }

  }

  val e_ui_child_from_ui_uid : vx_ui_ui.Func_ui_child_from_ui_uid = vx_ui_ui.Class_ui_child_from_ui_uid()
  val t_ui_child_from_ui_uid : vx_ui_ui.Func_ui_child_from_ui_uid = vx_ui_ui.Class_ui_child_from_ui_uid()

  fun f_ui_child_from_ui_uid(ui : vx_ui_ui.Type_ui, uid : vx_core.Type_string) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var childmap : vx_ui_ui.Type_uimap = ui.uimap()
        var output_1 : vx_core.Type_any = vx_core.f_any_from_map(
          vx_ui_ui.t_ui,
          childmap,
          uid
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_from_from_event : vx_core.Func_any_from_any_context {
    fun vx_ui_from_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_ui_ui.Type_ui
  }

  class Class_ui_from_from_event : vx_core.Class_base, Func_ui_from_from_event {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_from_event = vx_ui_ui.Class_ui_from_from_event()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_from_event = vx_ui_ui.Class_ui_from_from_event()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-from<-event", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_from_from_event
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_from_from_event
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_event.Type_event = value as vx_event.Type_event
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_from_from_event(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var evt : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_from_from_event(context, evt)
      return output
    }

    override fun vx_ui_from_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_from_event(context, evt)
      return output
    }

  }

  val e_ui_from_from_event : vx_ui_ui.Func_ui_from_from_event = vx_ui_ui.Class_ui_from_from_event()
  val t_ui_from_from_event : vx_ui_ui.Func_ui_from_from_event = vx_ui_ui.Class_ui_from_from_event()

  fun f_ui_from_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = evt.from()
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_readstate_from_uid(
          context,
          uid
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout : vx_core.Func_any_from_any {
    fun vx_ui_layout(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout : vx_core.Class_base, Func_ui_layout {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout = vx_ui_ui.Class_ui_layout()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout = vx_ui_ui.Class_ui_layout()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_layout
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_layout
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_layout(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_layout(uiarg)
      return output
    }

    override fun vx_ui_layout(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout(uiarg)
      return output
    }

  }

  val e_ui_layout : vx_ui_ui.Func_ui_layout = vx_ui_ui.Class_ui_layout()
  val t_ui_layout : vx_ui_ui.Func_ui_layout = vx_ui_ui.Class_ui_layout()

  fun f_ui_layout(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_ui_ui.f_ui_layout_from_ui_orig_parent(
      uiarg,
      vx_core.f_empty(
        vx_ui_ui.t_ui
      ),
      vx_core.f_empty(
        vx_ui_ui.t_ui
      )
    )
    return output
  }


  interface Func_ui_layout_from_fn_layout_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_from_fn_layout_ui_orig_parent(fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent, ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_from_fn_layout_ui_orig_parent : vx_core.Class_base, Func_ui_layout_from_fn_layout_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-fn-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_layout_from_fn_layout_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_layout_from_fn_layout_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = vx_core.f_any_from_any(vx_ui_ui.t_ui_layout_from_ui_orig_parent, arglist.vx_any(vx_core.vx_new_int(0)))
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_ui_ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_from_fn_layout_ui_orig_parent(fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent, ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_from_fn_layout_ui_orig_parent : vx_ui_ui.Func_ui_layout_from_fn_layout_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent()
  val t_ui_layout_from_fn_layout_ui_orig_parent : vx_ui_ui.Func_ui_layout_from_fn_layout_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_fn_layout_ui_orig_parent()

  fun f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent, ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.vx_any_from_func(
      vx_ui_ui.t_ui,
      fn_layout,
      ui,
      orig,
      parent
    )
    return output
  }


  interface Func_ui_layout_from_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_from_ui_orig_parent : vx_core.Class_base, Func_ui_layout_from_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_layout_from_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_layout_from_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var orig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent)
      return output
    }

    override fun vx_ui_layout_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent)
      return output
    }

  }

  val e_ui_layout_from_ui_orig_parent : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_ui_orig_parent()
  val t_ui_layout_from_ui_orig_parent : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = vx_ui_ui.Class_ui_layout_from_ui_orig_parent()

  fun f_ui_layout_from_ui_orig_parent(ui : vx_ui_ui.Type_ui, orig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_if_2(
      vx_ui_ui.t_ui,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_eqeq(
              ui,
              orig
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = orig
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_ui_ui.t_ui,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var uimap : vx_ui_ui.Type_uimap = ui.uimap()
                var layout : vx_ui_ui.Type_layout = ui.layout()
                var uiout : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_layout_ui_orig_parent(
                  layout,
                  ui,
                  orig,
                  parent
                )
                var output_4 : vx_core.Type_any = uiout
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


  interface Func_ui_layout_from_ui_parent_selected : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_from_ui_parent_selected(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_from_ui_parent_selected : vx_core.Class_base, Func_ui_layout_from_ui_parent_selected {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_parent_selected = vx_ui_ui.Class_ui_layout_from_ui_parent_selected()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_parent_selected = vx_ui_ui.Class_ui_layout_from_ui_parent_selected()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-selected", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_layout_from_ui_parent_selected
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_layout_from_ui_parent_selected
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var selected : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected)
      return output
    }

    override fun vx_ui_layout_from_ui_parent_selected(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected)
      return output
    }

  }

  val e_ui_layout_from_ui_parent_selected : vx_ui_ui.Func_ui_layout_from_ui_parent_selected = vx_ui_ui.Class_ui_layout_from_ui_parent_selected()
  val t_ui_layout_from_ui_parent_selected : vx_ui_ui.Func_ui_layout_from_ui_parent_selected = vx_ui_ui.Class_ui_layout_from_ui_parent_selected()

  fun f_ui_layout_from_ui_parent_selected(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uichg1 : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_ui_selected(
          ui,
          selected
        )
        var iswrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_write_from_ui_parent(
          uichg1,
          parent
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_layout_from_ui_orig_parent(
          uichg1,
          ui,
          parent
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_layout_from_ui_parent_visible : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_layout_from_ui_parent_visible(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_ui_layout_from_ui_parent_visible : vx_core.Class_base, Func_ui_layout_from_ui_parent_visible {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_parent_visible = vx_ui_ui.Class_ui_layout_from_ui_parent_visible()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_layout_from_ui_parent_visible = vx_ui_ui.Class_ui_layout_from_ui_parent_visible()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-visible", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_layout_from_ui_parent_visible
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_layout_from_ui_parent_visible
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var visible : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible)
      return output
    }

    override fun vx_ui_layout_from_ui_parent_visible(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible)
      return output
    }

  }

  val e_ui_layout_from_ui_parent_visible : vx_ui_ui.Func_ui_layout_from_ui_parent_visible = vx_ui_ui.Class_ui_layout_from_ui_parent_visible()
  val t_ui_layout_from_ui_parent_visible : vx_ui_ui.Func_ui_layout_from_ui_parent_visible = vx_ui_ui.Class_ui_layout_from_ui_parent_visible()

  fun f_ui_layout_from_ui_parent_visible(ui : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uichg : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_write_from_ui_visible(
          ui,
          visible
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_layout_from_ui_orig_parent(
          uichg,
          ui,
          parent
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_readstate_uiapp : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_readstate_uiapp(context : vx_core.Type_context) : vx_ui_ui.Type_ui
  }

  class Class_ui_readstate_uiapp : vx_core.Class_base, Func_ui_readstate_uiapp {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_readstate_uiapp = vx_ui_ui.Class_ui_readstate_uiapp()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_readstate_uiapp = vx_ui_ui.Class_ui_readstate_uiapp()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate-uiapp", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_readstate_uiapp
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_readstate_uiapp
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_readstate_uiapp(context)
      return output
    }

    override fun vx_ui_readstate_uiapp(context : vx_core.Type_context) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_readstate_uiapp(context)
      return output
    }

  }

  val e_ui_readstate_uiapp : vx_ui_ui.Func_ui_readstate_uiapp = vx_ui_ui.Class_ui_readstate_uiapp()
  val t_ui_readstate_uiapp : vx_ui_ui.Func_ui_readstate_uiapp = vx_ui_ui.Class_ui_readstate_uiapp()

  fun f_ui_readstate_uiapp(context : vx_core.Type_context) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_state.f_any_readstate_from_name(
      vx_ui_ui.t_ui,
      context,
      vx_core.vx_new_string(":uiapp")
    )
    return output
  }


  interface Func_ui_readstate_from_uid : vx_core.Func_any_from_any_context {
    fun vx_ui_readstate_from_uid(context : vx_core.Type_context, uid : vx_core.Type_string) : vx_ui_ui.Type_ui
  }

  class Class_ui_readstate_from_uid : vx_core.Class_base, Func_ui_readstate_from_uid {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_readstate_from_uid = vx_ui_ui.Class_ui_readstate_from_uid()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_readstate_from_uid = vx_ui_ui.Class_ui_readstate_from_uid()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_readstate_from_uid
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_readstate_from_uid
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_readstate_from_uid(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var uid : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_readstate_from_uid(context, uid)
      return output
    }

    override fun vx_ui_readstate_from_uid(context : vx_core.Type_context, uid : vx_core.Type_string) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_readstate_from_uid(context, uid)
      return output
    }

  }

  val e_ui_readstate_from_uid : vx_ui_ui.Func_ui_readstate_from_uid = vx_ui_ui.Class_ui_readstate_from_uid()
  val t_ui_readstate_from_uid : vx_ui_ui.Func_ui_readstate_from_uid = vx_ui_ui.Class_ui_readstate_from_uid()

  fun f_ui_readstate_from_uid(context : vx_core.Type_context, uid : vx_core.Type_string) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uiapp : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_readstate_uiapp(
          context
        )
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_from_ui_find(
          uiapp,
          uid
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_ui_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_selected_from_ui : vx_core.Class_base, Func_ui_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_selected_from_ui = vx_ui_ui.Class_ui_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_selected_from_ui = vx_ui_ui.Class_ui_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-selected<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_selected_from_ui(ui)
      return output
    }

    override fun vx_ui_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_selected_from_ui(ui)
      return output
    }

  }

  val e_ui_selected_from_ui : vx_ui_ui.Func_ui_selected_from_ui = vx_ui_ui.Class_ui_selected_from_ui()
  val t_ui_selected_from_ui : vx_ui_ui.Func_ui_selected_from_ui = vx_ui_ui.Class_ui_selected_from_ui()

  fun f_ui_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_selected_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_first_from_list(
          vx_ui_ui.t_ui,
          uilist
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_visible_from_ui : vx_core.Func_any_from_any {
    fun vx_ui_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_visible_from_ui : vx_core.Class_base, Func_ui_visible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_visible_from_ui = vx_ui_ui.Class_ui_visible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_visible_from_ui = vx_ui_ui.Class_ui_visible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-visible<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_visible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_visible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_ui_visible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_ui_visible_from_ui(ui)
      return output
    }

    override fun vx_ui_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_visible_from_ui(ui)
      return output
    }

  }

  val e_ui_visible_from_ui : vx_ui_ui.Func_ui_visible_from_ui = vx_ui_ui.Class_ui_visible_from_ui()
  val t_ui_visible_from_ui : vx_ui_ui.Func_ui_visible_from_ui = vx_ui_ui.Class_ui_visible_from_ui()

  fun f_ui_visible_from_ui(ui : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_visible_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_first_from_list(
          vx_ui_ui.t_ui,
          uilist
        )
        output_1
      })
    )
    return output
  }


  interface Func_ui_write_from_ui_child : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_write_from_ui_child(ui : vx_ui_ui.Type_ui, child : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_write_from_ui_child : vx_core.Class_base, Func_ui_write_from_ui_child {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_child = vx_ui_ui.Class_ui_write_from_ui_child()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_child = vx_ui_ui.Class_ui_write_from_ui_child()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-child", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_write_from_ui_child
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_write_from_ui_child
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var child : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_write_from_ui_child(ui, child)
      return output
    }

    override fun vx_ui_write_from_ui_child(ui : vx_ui_ui.Type_ui, child : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_write_from_ui_child(ui, child)
      return output
    }

  }

  val e_ui_write_from_ui_child : vx_ui_ui.Func_ui_write_from_ui_child = vx_ui_ui.Class_ui_write_from_ui_child()
  val t_ui_write_from_ui_child : vx_ui_ui.Func_ui_write_from_ui_child = vx_ui_ui.Class_ui_write_from_ui_child()

  fun f_ui_write_from_ui_child(ui : vx_ui_ui.Type_ui, child : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var childid : vx_core.Type_string = child.uid()
        var uimap : vx_ui_ui.Type_uimap = ui.uimap()
        var write : vx_core.Type_boolean = vx_core.f_boolean_write_from_map_name_value(
          uimap,
          childid,
          child
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  interface Func_ui_write_from_ui_childmap : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_write_from_ui_childmap(ui : vx_ui_ui.Type_ui, childmap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_ui
  }

  class Class_ui_write_from_ui_childmap : vx_core.Class_base, Func_ui_write_from_ui_childmap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_childmap = vx_ui_ui.Class_ui_write_from_ui_childmap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_childmap = vx_ui_ui.Class_ui_write_from_ui_childmap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-childmap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_write_from_ui_childmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_write_from_ui_childmap
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var childmap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_write_from_ui_childmap(ui, childmap)
      return output
    }

    override fun vx_ui_write_from_ui_childmap(ui : vx_ui_ui.Type_ui, childmap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_write_from_ui_childmap(ui, childmap)
      return output
    }

  }

  val e_ui_write_from_ui_childmap : vx_ui_ui.Func_ui_write_from_ui_childmap = vx_ui_ui.Class_ui_write_from_ui_childmap()
  val t_ui_write_from_ui_childmap : vx_ui_ui.Func_ui_write_from_ui_childmap = vx_ui_ui.Class_ui_write_from_ui_childmap()

  fun f_ui_write_from_ui_childmap(ui : vx_ui_ui.Type_ui, childmap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var workmap : vx_ui_ui.Type_uimap = vx_core.f_map_from_map_1(
          vx_ui_ui.t_uimap,
          childmap,
          vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
            var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
            var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
            var output_2 : vx_core.Type_any = vx_ui_ui.f_ui_write_from_ui_child(
              ui,
              value
            )
            output_2
          })
        )
        var output_1 : vx_core.Type_any = ui
        output_1
      })
    )
    return output
  }


  interface Func_ui_write_from_ui_visible : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_write_from_ui_visible(ui : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_ui_write_from_ui_visible : vx_core.Class_base, Func_ui_write_from_ui_visible {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_visible = vx_ui_ui.Class_ui_write_from_ui_visible()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_write_from_ui_visible = vx_ui_ui.Class_ui_write_from_ui_visible()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-visible", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_write_from_ui_visible
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_write_from_ui_visible
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var visible : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_write_from_ui_visible(ui, visible)
      return output
    }

    override fun vx_ui_write_from_ui_visible(ui : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_write_from_ui_visible(ui, visible)
      return output
    }

  }

  val e_ui_write_from_ui_visible : vx_ui_ui.Func_ui_write_from_ui_visible = vx_ui_ui.Class_ui_write_from_ui_visible()
  val t_ui_write_from_ui_visible : vx_ui_ui.Func_ui_write_from_ui_visible = vx_ui_ui.Class_ui_write_from_ui_visible()

  fun f_ui_write_from_ui_visible(ui : vx_ui_ui.Type_ui, visible : vx_core.Type_int) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_if_2(
      vx_ui_ui.t_ui,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_lt(
              visible,
              vx_core.vx_new_int(1)
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = ui
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_ui_ui.t_ui,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var uimap : vx_ui_ui.Type_uimap = ui.uimap()
                var uilist1 : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
                  uimap
                )
                var uilist2 : vx_ui_ui.Type_uilist = vx_core.f_list_from_list_intany(
                  vx_ui_ui.t_uilist,
                  uilist1,
                  vx_core.t_any_from_int_any.vx_fn_new({posval_any : vx_core.Type_any, uival_any : vx_core.Type_any ->
                    var posval : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, posval_any)
                    var uival : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, uival_any)
                    var output_5 : vx_core.Type_any = vx_core.f_if_2(
                      vx_ui_ui.t_ui,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_6 : vx_core.Type_any = vx_core.f_eq(
                              posval,
                              visible
                            )
                            output_6
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_7 : vx_core.Type_any = vx_ui_ui.f_ui_write_from_ui_child(
                              ui,
                              vx_core.f_copy(
                                uival,
                                vx_core.vx_new(
                                  vx_core.t_anylist,
                                  vx_core.vx_new_string(":hidden"),
                                  vx_core.vx_new_boolean(false)
                                )
                              )
                            )
                            output_7
                          })
                        ),
                        vx_core.f_else(
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_8 : vx_core.Type_any = vx_ui_ui.f_ui_write_from_ui_child(
                              ui,
                              vx_core.f_copy(
                                uival,
                                vx_core.vx_new(
                                  vx_core.t_anylist,
                                  vx_core.vx_new_string(":hidden"),
                                  vx_core.vx_new_boolean(true)
                                )
                              )
                            )
                            output_8
                          })
                        )
                      )
                    )
                    output_5
                  })
                )
                var output_4 : vx_core.Type_any = ui
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


  interface Func_ui_from_layout_ui_orig_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_from_layout_ui_orig_parent(layout : vx_ui_ui.Type_layout, uiarg : vx_ui_ui.Type_ui, uiorig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui
  }

  class Class_ui_from_layout_ui_orig_parent : vx_core.Class_base, Func_ui_from_layout_ui_orig_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_layout_ui_orig_parent = vx_ui_ui.Class_ui_from_layout_ui_orig_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_layout_ui_orig_parent = vx_ui_ui.Class_ui_from_layout_ui_orig_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_from_layout_ui_orig_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_from_layout_ui_orig_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var layout : vx_ui_ui.Type_layout = vx_core.f_any_from_any(vx_ui_ui.t_layout, arglist.vx_any(vx_core.vx_new_int(0)))
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      var uiorig : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(2)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(3)))
      output = vx_ui_ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent)
      return output
    }

    override fun vx_ui_from_layout_ui_orig_parent(layout : vx_ui_ui.Type_layout, uiarg : vx_ui_ui.Type_ui, uiorig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent)
      return output
    }

  }

  val e_ui_from_layout_ui_orig_parent : vx_ui_ui.Func_ui_from_layout_ui_orig_parent = vx_ui_ui.Class_ui_from_layout_ui_orig_parent()
  val t_ui_from_layout_ui_orig_parent : vx_ui_ui.Func_ui_from_layout_ui_orig_parent = vx_ui_ui.Class_ui_from_layout_ui_orig_parent()

  fun f_ui_from_layout_ui_orig_parent(layout : vx_ui_ui.Type_layout, uiarg : vx_ui_ui.Type_ui, uiorig : vx_ui_ui.Type_ui, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var name : vx_core.Type_string = layout.name()
        var fn_layout : vx_ui_ui.Func_ui_layout_from_ui_orig_parent = layout.fn_layout()
        var uichg : vx_ui_ui.Type_ui = vx_core.vx_any_from_func(
          vx_ui_ui.t_ui,
          fn_layout,
          uiarg,
          uiorig,
          parent
        )
        var output_1 : vx_core.Type_any = uichg
        output_1
      })
    )
    return output
  }


  interface Func_ui_from_ui_find : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_from_ui_find(uiarg : vx_ui_ui.Type_ui, find : vx_core.Type_string) : vx_ui_ui.Type_ui
  }

  class Class_ui_from_ui_find : vx_core.Class_base, Func_ui_from_ui_find {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_ui_find = vx_ui_ui.Class_ui_from_ui_find()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_ui_find = vx_ui_ui.Class_ui_from_ui_find()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-find", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_from_ui_find
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_from_ui_find
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var find : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_from_ui_find(uiarg, find)
      return output
    }

    override fun vx_ui_from_ui_find(uiarg : vx_ui_ui.Type_ui, find : vx_core.Type_string) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_ui_find(uiarg, find)
      return output
    }

  }

  val e_ui_from_ui_find : vx_ui_ui.Func_ui_from_ui_find = vx_ui_ui.Class_ui_from_ui_find()
  val t_ui_from_ui_find : vx_ui_ui.Func_ui_from_ui_find = vx_ui_ui.Class_ui_from_ui_find()

  fun f_ui_from_ui_find(uiarg : vx_ui_ui.Type_ui, find : vx_core.Type_string) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_let(
      vx_ui_ui.t_ui,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uid : vx_core.Type_string = uiarg.uid()
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_ui_ui.t_ui,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_eq(
                  uid,
                  vx_core.vx_new_string("")
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = vx_core.f_empty(
                  vx_ui_ui.t_ui
                )
                output_3
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_eq(
                  uid,
                  find
                )
                output_4
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_5 : vx_core.Type_any = uiarg
                output_5
              })
            ),
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_6 : vx_core.Type_any = vx_type.f_boolean_from_string_starts(
                  find,
                  vx_core.f_new(
                    vx_core.t_string,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      uid,
                      vx_core.vx_new_string("/")
                    )
                  )
                )
                output_6
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_7 : vx_core.Type_any = vx_core.f_let(
                  vx_ui_ui.t_ui,
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var afterpos : vx_core.Type_int = vx_core.f_plus(
                      vx_core.f_length(
                        uid
                      ),
                      vx_core.vx_new_int(2)
                    )
                    var after : vx_core.Type_string = vx_type.f_string_from_string_start(
                      find,
                      afterpos
                    )
                    var pos : vx_core.Type_int = vx_type.f_int_from_string_find(
                      after,
                      vx_core.vx_new_string("/")
                    )
                    var subpart : vx_core.Type_string = vx_core.f_if_2(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_12 : vx_core.Type_any = vx_core.f_gt(
                              pos,
                              vx_core.vx_new_int(0)
                            )
                            output_12
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_13 : vx_core.Type_any = vx_type.f_string_from_string_end(
                              after,
                              vx_core.f_minus(
                                pos,
                                vx_core.vx_new_int(1)
                              )
                            )
                            output_13
                          })
                        ),
                        vx_core.f_else(
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_14 : vx_core.Type_any = after
                            output_14
                          })
                        )
                      )
                    )
                    var subfind : vx_core.Type_string = vx_core.f_if_2(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_15 : vx_core.Type_any = vx_core.f_notempty(
                              subpart
                            )
                            output_15
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_16 : vx_core.Type_any = vx_core.f_new(
                              vx_core.t_string,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                uid,
                                vx_core.vx_new_string("/"),
                                subpart
                              )
                            )
                            output_16
                          })
                        )
                      )
                    )
                    var output_8 : vx_core.Type_any = vx_core.f_if_2(
                      vx_ui_ui.t_ui,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_9 : vx_core.Type_any = vx_core.f_notempty(
                              subfind
                            )
                            output_9
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_10 : vx_core.Type_any = vx_core.f_let(
                              vx_ui_ui.t_ui,
                              vx_core.t_any_from_func.vx_fn_new({ ->
                                var uimap : vx_ui_ui.Type_uimap = uiarg.uimap()
                                var subui : vx_ui_ui.Type_ui = vx_core.f_any_from_map(
                                  vx_ui_ui.t_ui,
                                  uimap,
                                  subfind
                                )
                                var output_11 : vx_core.Type_any = vx_ui_ui.f_ui_from_ui_find(
                                  subui,
                                  find
                                )
                                output_11
                              })
                            )
                            output_10
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


  interface Func_ui_from_ui_selected : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_ui_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui
  }

  class Class_ui_from_ui_selected : vx_core.Class_base, Func_ui_from_ui_selected {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_ui_selected = vx_ui_ui.Class_ui_from_ui_selected()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_ui_from_ui_selected = vx_ui_ui.Class_ui_from_ui_selected()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-selected", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_ui_from_ui_selected
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_ui_from_ui_selected
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      var selected : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_ui_from_ui_selected(ui, selected)
      return output
    }

    override fun vx_ui_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui {
      var output : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_from_ui_selected(ui, selected)
      return output
    }

  }

  val e_ui_from_ui_selected : vx_ui_ui.Func_ui_from_ui_selected = vx_ui_ui.Class_ui_from_ui_selected()
  val t_ui_from_ui_selected : vx_ui_ui.Func_ui_from_ui_selected = vx_ui_ui.Class_ui_from_ui_selected()

  fun f_ui_from_ui_selected(ui : vx_ui_ui.Type_ui, selected : vx_core.Type_int) : vx_ui_ui.Type_ui {
    var output : vx_ui_ui.Type_ui = vx_ui_ui.e_ui
    output = vx_core.f_if_2(
      vx_ui_ui.t_ui,
      vx_core.vx_new(
        vx_core.t_thenelselist,
        vx_core.f_then(
          vx_core.t_boolean_from_func.vx_fn_new({ ->
            var output_1 : vx_core.Type_any = vx_core.f_lt(
              selected,
              vx_core.vx_new_int(1)
            )
            output_1
          }),
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_2 : vx_core.Type_any = ui
            output_2
          })
        ),
        vx_core.f_else(
          vx_core.t_any_from_func.vx_fn_new({ ->
            var output_3 : vx_core.Type_any = vx_core.f_let(
              vx_ui_ui.t_ui,
              vx_core.t_any_from_func.vx_fn_new({ ->
                var uimap : vx_ui_ui.Type_uimap = ui.uimap()
                var uilist1 : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
                  uimap
                )
                var uilist2 : vx_ui_ui.Type_uilist = vx_core.f_list_from_list_intany(
                  vx_ui_ui.t_uilist,
                  uilist1,
                  vx_core.t_any_from_int_any.vx_fn_new({posval_any : vx_core.Type_any, uival_any : vx_core.Type_any ->
                    var posval : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, posval_any)
                    var uival : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, uival_any)
                    var output_5 : vx_core.Type_any = vx_core.f_if_2(
                      vx_ui_ui.t_ui,
                      vx_core.vx_new(
                        vx_core.t_thenelselist,
                        vx_core.f_then(
                          vx_core.t_boolean_from_func.vx_fn_new({ ->
                            var output_6 : vx_core.Type_any = vx_core.f_eq(
                              posval,
                              selected
                            )
                            output_6
                          }),
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_7 : vx_core.Type_any = vx_core.f_copy(
                              uival,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                vx_core.vx_new_string(":selected"),
                                vx_core.vx_new_boolean(true)
                              )
                            )
                            output_7
                          })
                        ),
                        vx_core.f_else(
                          vx_core.t_any_from_func.vx_fn_new({ ->
                            var output_8 : vx_core.Type_any = vx_core.f_copy(
                              uival,
                              vx_core.vx_new(
                                vx_core.t_anylist,
                                vx_core.vx_new_string(":selected"),
                                vx_core.vx_new_boolean(false)
                              )
                            )
                            output_8
                          })
                        )
                      )
                    )
                    output_5
                  })
                )
                var childmap : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_from_uilist(
                  uilist2
                )
                var output_4 : vx_core.Type_any = vx_core.f_copy(
                  ui,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":uimap"),
                    childmap
                  )
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


  interface Func_uid_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_uid_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string
  }

  class Class_uid_selected_from_ui : vx_core.Class_base, Func_uid_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uid_selected_from_ui = vx_ui_ui.Class_uid_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uid_selected_from_ui = vx_ui_ui.Class_uid_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uid-selected<-ui", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_uid_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uid_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_uid_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uid_selected_from_ui(ui)
      return output
    }

    override fun vx_uid_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_ui_ui.f_uid_selected_from_ui(ui)
      return output
    }

  }

  val e_uid_selected_from_ui : vx_ui_ui.Func_uid_selected_from_ui = vx_ui_ui.Class_uid_selected_from_ui()
  val t_uid_selected_from_ui : vx_ui_ui.Func_uid_selected_from_ui = vx_ui_ui.Class_uid_selected_from_ui()

  fun f_uid_selected_from_ui(ui : vx_ui_ui.Type_ui) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uidlist : vx_core.Type_stringlist = vx_ui_ui.f_stringlist_selected_from_ui(
          ui
        )
        var output_1 : vx_core.Type_any = vx_core.f_first_from_list(
          vx_core.t_string,
          uidlist
        )
        output_1
      })
    )
    return output
  }


  interface Func_uiengine_readstate : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_uiengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_uiengine
  }

  class Class_uiengine_readstate : vx_core.Class_base, Func_uiengine_readstate {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uiengine_readstate = vx_ui_ui.Class_uiengine_readstate()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uiengine_readstate = vx_ui_ui.Class_uiengine_readstate()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-readstate", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_uiengine_readstate
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uiengine_readstate
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uiengine_readstate(context)
      return output
    }

    override fun vx_uiengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_uiengine {
      var output : vx_ui_ui.Type_uiengine = vx_ui_ui.f_uiengine_readstate(context)
      return output
    }

  }

  val e_uiengine_readstate : vx_ui_ui.Func_uiengine_readstate = vx_ui_ui.Class_uiengine_readstate()
  val t_uiengine_readstate : vx_ui_ui.Func_uiengine_readstate = vx_ui_ui.Class_uiengine_readstate()

  fun f_uiengine_readstate(context : vx_core.Type_context) : vx_ui_ui.Type_uiengine {
    var output : vx_ui_ui.Type_uiengine = vx_ui_ui.e_uiengine
    output = vx_state.f_any_readstate_from_name(
      vx_ui_ui.t_uiengine,
      context,
      vx_core.vx_new_string(":uiengine")
    )
    return output
  }


  interface Func_uiengine_render : vx_core.Func_any_from_any_context {
    fun vx_uiengine_render(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_uiengine
  }

  class Class_uiengine_render : vx_core.Class_base, Func_uiengine_render {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uiengine_render = vx_ui_ui.Class_uiengine_render()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uiengine_render = vx_ui_ui.Class_uiengine_render()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-render", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
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
      var output : vx_core.Type_any = vx_ui_ui.e_uiengine_render
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uiengine_render
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uiengine = value as vx_ui_ui.Type_uiengine
      var outputval : vx_core.Type_any = vx_ui_ui.f_uiengine_render(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var uiengine : vx_ui_ui.Type_uiengine = vx_core.f_any_from_any(vx_ui_ui.t_uiengine, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uiengine_render(context, uiengine)
      return output
    }

    override fun vx_uiengine_render(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_uiengine {
      var output : vx_ui_ui.Type_uiengine = vx_ui_ui.f_uiengine_render(context, uiengine)
      return output
    }

  }

  val e_uiengine_render : vx_ui_ui.Func_uiengine_render = vx_ui_ui.Class_uiengine_render()
  val t_uiengine_render : vx_ui_ui.Func_uiengine_render = vx_ui_ui.Class_uiengine_render()

  fun f_uiengine_render(context : vx_core.Type_context, uiengine : vx_ui_ui.Type_uiengine) : vx_ui_ui.Type_uiengine {
    var output : vx_ui_ui.Type_uiengine = vx_ui_ui.e_uiengine
    output = vx_core.f_let(
      vx_ui_ui.t_uiengine,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var stylesheet : vx_ui_ui.Type_stylesheet = uiengine.stylesheet()
        var ui : vx_ui_ui.Type_ui = uiengine.ui()
        var layoutengine : vx_ui_ui.Type_layoutengine = uiengine.layoutengine()
        var issetstate : vx_core.Type_boolean = vx_ui_ui.f_boolean_writestate_from_uiengine(
          context,
          uiengine
        )
        var stylesheetrender : vx_ui_ui.Func_stylesheet_render = layoutengine.stylesheetrender()
        var stylesheetrend : vx_ui_ui.Type_stylesheet = vx_core.vx_any_from_func(
          vx_ui_ui.t_stylesheet,
          stylesheetrender,
          stylesheet
        )
        var uiaddlayout : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_addlayout_from_ui_layoutengine(
          ui,
          layoutengine
        )
        var isuiwrite : vx_core.Type_boolean = vx_ui_ui.f_boolean_writestate_from_uiapp(
          context,
          uiaddlayout
        )
        var uirendered : vx_ui_ui.Type_ui = vx_ui_ui.f_ui_layout(
          uiaddlayout
        )
        var output_1 : vx_core.Type_any = vx_core.f_copy(
          uiengine,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":ui"),
            uirendered
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_uilist_selected_from_ui : vx_core.Func_any_from_any {
    fun vx_uilist_selected_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist
  }

  class Class_uilist_selected_from_ui : vx_core.Class_base, Func_uilist_selected_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_selected_from_ui = vx_ui_ui.Class_uilist_selected_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_selected_from_ui = vx_ui_ui.Class_uilist_selected_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uilist_selected_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uilist_selected_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_uilist_selected_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uilist_selected_from_ui(uiarg)
      return output
    }

    override fun vx_uilist_selected_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist {
      var output : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_selected_from_ui(uiarg)
      return output
    }

  }

  val e_uilist_selected_from_ui : vx_ui_ui.Func_uilist_selected_from_ui = vx_ui_ui.Class_uilist_selected_from_ui()
  val t_uilist_selected_from_ui : vx_ui_ui.Func_uilist_selected_from_ui = vx_ui_ui.Class_uilist_selected_from_ui()

  fun f_uilist_selected_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist {
    var output : vx_ui_ui.Type_uilist = vx_ui_ui.e_uilist
    output = vx_core.f_let(
      vx_ui_ui.t_uilist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = uiarg.uimap()
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
          uimap
        )
        var output_1 : vx_core.Type_any = vx_collection.f_list_from_list_filter(
          vx_ui_ui.t_uilist,
          uilist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, item_any)
            var output_2 : vx_core.Type_any = vx_core.f_if(
              vx_ui_ui.t_ui,
              item.selected(),
              item
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_uilist_visible_from_ui : vx_core.Func_any_from_any {
    fun vx_uilist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist
  }

  class Class_uilist_visible_from_ui : vx_core.Class_base, Func_uilist_visible_from_ui {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_visible_from_ui = vx_ui_ui.Class_uilist_visible_from_ui()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_visible_from_ui = vx_ui_ui.Class_uilist_visible_from_ui()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-visible<-ui", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uilist_visible_from_ui
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uilist_visible_from_ui
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_ui = value as vx_ui_ui.Type_ui
      var outputval : vx_core.Type_any = vx_ui_ui.f_uilist_visible_from_ui(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uiarg : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uilist_visible_from_ui(uiarg)
      return output
    }

    override fun vx_uilist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist {
      var output : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_visible_from_ui(uiarg)
      return output
    }

  }

  val e_uilist_visible_from_ui : vx_ui_ui.Func_uilist_visible_from_ui = vx_ui_ui.Class_uilist_visible_from_ui()
  val t_uilist_visible_from_ui : vx_ui_ui.Func_uilist_visible_from_ui = vx_ui_ui.Class_uilist_visible_from_ui()

  fun f_uilist_visible_from_ui(uiarg : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uilist {
    var output : vx_ui_ui.Type_uilist = vx_ui_ui.e_uilist
    output = vx_core.f_let(
      vx_ui_ui.t_uilist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var uimap : vx_ui_ui.Type_uimap = uiarg.uimap()
        var uilist : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(
          uimap
        )
        var output_1 : vx_core.Type_any = vx_collection.f_list_from_list_filter(
          vx_ui_ui.t_uilist,
          uilist,
          vx_core.t_any_from_any.vx_fn_new({item_any : vx_core.Type_any ->
            var item : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, item_any)
            var output_2 : vx_core.Type_any = vx_core.f_if(
              vx_ui_ui.t_ui,
              vx_core.f_not(
                item.hidden()
              ),
              item
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_uilist_from_uimap : vx_core.Func_any_from_any {
    fun vx_uilist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_uilist
  }

  class Class_uilist_from_uimap : vx_core.Class_base, Func_uilist_from_uimap {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_from_uimap = vx_ui_ui.Class_uilist_from_uimap()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uilist_from_uimap = vx_ui_ui.Class_uilist_from_uimap()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uilist_from_uimap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uilist_from_uimap
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uimap = value as vx_ui_ui.Type_uimap
      var outputval : vx_core.Type_any = vx_ui_ui.f_uilist_from_uimap(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uilist_from_uimap(uimap)
      return output
    }

    override fun vx_uilist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_uilist {
      var output : vx_ui_ui.Type_uilist = vx_ui_ui.f_uilist_from_uimap(uimap)
      return output
    }

  }

  val e_uilist_from_uimap : vx_ui_ui.Func_uilist_from_uimap = vx_ui_ui.Class_uilist_from_uimap()
  val t_uilist_from_uimap : vx_ui_ui.Func_uilist_from_uimap = vx_ui_ui.Class_uilist_from_uimap()

  fun f_uilist_from_uimap(uimap : vx_ui_ui.Type_uimap) : vx_ui_ui.Type_uilist {
    var output : vx_ui_ui.Type_uilist = vx_ui_ui.e_uilist
    output = vx_core.f_list_from_map_1(
      vx_ui_ui.t_uilist,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, item_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var item : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, item_any)
        var output_1 : vx_core.Type_any = item
        output_1
      })
    )
    return output
  }


  interface Func_uimap_addlayout_from_uimap_layoutmap_else : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_uimap_addlayout_from_uimap_layoutmap_else(uimap : vx_ui_ui.Type_uimap, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_uimap
  }

  class Class_uimap_addlayout_from_uimap_layoutmap_else : vx_core.Class_base, Func_uimap_addlayout_from_uimap_layoutmap_else {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else = vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else = vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-addlayout<-uimap-layoutmap-else", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uimap_addlayout_from_uimap_layoutmap_else
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uimap_addlayout_from_uimap_layoutmap_else
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      var layoutmap : vx_ui_ui.Type_layoutmap = vx_core.f_any_from_any(vx_ui_ui.t_layoutmap, arglist.vx_any(vx_core.vx_new_int(1)))
      var layoutelse : vx_ui_ui.Type_layout = vx_core.f_any_from_any(vx_ui_ui.t_layout, arglist.vx_any(vx_core.vx_new_int(2)))
      output = vx_ui_ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse)
      return output
    }

    override fun vx_uimap_addlayout_from_uimap_layoutmap_else(uimap : vx_ui_ui.Type_uimap, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse)
      return output
    }

  }

  val e_uimap_addlayout_from_uimap_layoutmap_else : vx_ui_ui.Func_uimap_addlayout_from_uimap_layoutmap_else = vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else()
  val t_uimap_addlayout_from_uimap_layoutmap_else : vx_ui_ui.Func_uimap_addlayout_from_uimap_layoutmap_else = vx_ui_ui.Class_uimap_addlayout_from_uimap_layoutmap_else()

  fun f_uimap_addlayout_from_uimap_layoutmap_else(uimap : vx_ui_ui.Type_uimap, layoutmap : vx_ui_ui.Type_layoutmap, layoutelse : vx_ui_ui.Type_layout) : vx_ui_ui.Type_uimap {
    var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
    output = vx_core.f_map_from_map_1(
      vx_ui_ui.t_uimap,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, ui_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, ui_any)
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_addlayout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        )
        output_1
      })
    )
    return output
  }


  interface Func_uimap_layout_from_uimap_parent : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_uimap_layout_from_uimap_parent(uimap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uimap
  }

  class Class_uimap_layout_from_uimap_parent : vx_core.Class_base, Func_uimap_layout_from_uimap_parent {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_layout_from_uimap_parent = vx_ui_ui.Class_uimap_layout_from_uimap_parent()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_layout_from_uimap_parent = vx_ui_ui.Class_uimap_layout_from_uimap_parent()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-parent", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uimap_layout_from_uimap_parent
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uimap_layout_from_uimap_parent
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      var parent : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_uimap_layout_from_uimap_parent(uimap, parent)
      return output
    }

    override fun vx_uimap_layout_from_uimap_parent(uimap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_layout_from_uimap_parent(uimap, parent)
      return output
    }

  }

  val e_uimap_layout_from_uimap_parent : vx_ui_ui.Func_uimap_layout_from_uimap_parent = vx_ui_ui.Class_uimap_layout_from_uimap_parent()
  val t_uimap_layout_from_uimap_parent : vx_ui_ui.Func_uimap_layout_from_uimap_parent = vx_ui_ui.Class_uimap_layout_from_uimap_parent()

  fun f_uimap_layout_from_uimap_parent(uimap : vx_ui_ui.Type_uimap, parent : vx_ui_ui.Type_ui) : vx_ui_ui.Type_uimap {
    var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
    output = vx_core.f_map_from_map_1(
      vx_ui_ui.t_uimap,
      uimap,
      vx_core.t_any_from_key_value.vx_fn_new({key_any : vx_core.Type_any, value_any : vx_core.Type_any ->
        var key : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, key_any)
        var value : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, value_any)
        var output_1 : vx_core.Type_any = vx_ui_ui.f_ui_layout_from_ui_orig_parent(
          value,
          vx_core.f_empty(
            vx_ui_ui.t_ui
          ),
          parent
        )
        output_1
      })
    )
    return output
  }


  interface Func_uimap_from_uilist : vx_core.Func_any_from_any {
    fun vx_uimap_from_uilist(uilist : vx_ui_ui.Type_uilist) : vx_ui_ui.Type_uimap
  }

  class Class_uimap_from_uilist : vx_core.Class_base, Func_uimap_from_uilist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_from_uilist = vx_ui_ui.Class_uimap_from_uilist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_from_uilist = vx_ui_ui.Class_uimap_from_uilist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uimap_from_uilist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uimap_from_uilist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_ui_ui.Type_uilist = value as vx_ui_ui.Type_uilist
      var outputval : vx_core.Type_any = vx_ui_ui.f_uimap_from_uilist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uilist : vx_ui_ui.Type_uilist = vx_core.f_any_from_any(vx_ui_ui.t_uilist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_ui_ui.f_uimap_from_uilist(uilist)
      return output
    }

    override fun vx_uimap_from_uilist(uilist : vx_ui_ui.Type_uilist) : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_from_uilist(uilist)
      return output
    }

  }

  val e_uimap_from_uilist : vx_ui_ui.Func_uimap_from_uilist = vx_ui_ui.Class_uimap_from_uilist()
  val t_uimap_from_uilist : vx_ui_ui.Func_uimap_from_uilist = vx_ui_ui.Class_uimap_from_uilist()

  fun f_uimap_from_uilist(uilist : vx_ui_ui.Type_uilist) : vx_ui_ui.Type_uimap {
    var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
    output = vx_core.f_map_from_list(
      vx_ui_ui.t_uimap,
      uilist,
      vx_core.t_any_from_any.vx_fn_new({ui_any : vx_core.Type_any ->
        var ui : vx_ui_ui.Type_ui = vx_core.f_any_from_any(vx_ui_ui.t_ui, ui_any)
        var output_1 : vx_core.Type_any = ui.uid()
        output_1
      })
    )
    return output
  }


  interface Func_uimap_from_uimap_data : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_uimap_from_uimap_data(uimap : vx_ui_ui.Type_uimap, data : vx_core.Type_any) : vx_ui_ui.Type_uimap
  }

  class Class_uimap_from_uimap_data : vx_core.Class_base, Func_uimap_from_uimap_data {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_from_uimap_data = vx_ui_ui.Class_uimap_from_uimap_data()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_ui_ui.Class_uimap_from_uimap_data = vx_ui_ui.Class_uimap_from_uimap_data()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_ui_ui.t_ui), // allowtypes
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
      var output : vx_core.Type_any = vx_ui_ui.e_uimap_from_uimap_data
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_ui_ui.t_uimap_from_uimap_data
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var uimap : vx_ui_ui.Type_uimap = vx_core.f_any_from_any(vx_ui_ui.t_uimap, arglist.vx_any(vx_core.vx_new_int(0)))
      var data : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_ui_ui.f_uimap_from_uimap_data(uimap, data)
      return output
    }

    override fun vx_uimap_from_uimap_data(uimap : vx_ui_ui.Type_uimap, data : vx_core.Type_any) : vx_ui_ui.Type_uimap {
      var output : vx_ui_ui.Type_uimap = vx_ui_ui.f_uimap_from_uimap_data(uimap, data)
      return output
    }

  }

  val e_uimap_from_uimap_data : vx_ui_ui.Func_uimap_from_uimap_data = vx_ui_ui.Class_uimap_from_uimap_data()
  val t_uimap_from_uimap_data : vx_ui_ui.Func_uimap_from_uimap_data = vx_ui_ui.Class_uimap_from_uimap_data()

  fun f_uimap_from_uimap_data(uimap : vx_ui_ui.Type_uimap, data : vx_core.Type_any) : vx_ui_ui.Type_uimap {
    var output : vx_ui_ui.Type_uimap = vx_ui_ui.e_uimap
    return output
  }


  init {
    Const_align_center.const_new(c_align_center)
    Const_align_left.const_new(c_align_left)
    Const_align_right.const_new(c_align_right)
    Const_flip_x.const_new(c_flip_x)
    Const_flip_xy.const_new(c_flip_xy)
    Const_flip_y.const_new(c_flip_y)
    Const_layout_app.const_new(c_layout_app)
    Const_layout_background.const_new(c_layout_background)
    Const_layout_button.const_new(c_layout_button)
    Const_layout_combobox.const_new(c_layout_combobox)
    Const_layout_else.const_new(c_layout_else)
    Const_layout_flow_columns.const_new(c_layout_flow_columns)
    Const_layout_flow_item.const_new(c_layout_flow_item)
    Const_layout_flow_rows.const_new(c_layout_flow_rows)
    Const_layout_image.const_new(c_layout_image)
    Const_layout_label.const_new(c_layout_label)
    Const_layout_main.const_new(c_layout_main)
    Const_layout_maxpanel.const_new(c_layout_maxpanel)
    Const_layout_menubar.const_new(c_layout_menubar)
    Const_layout_menudrawer.const_new(c_layout_menudrawer)
    Const_layout_msgbox.const_new(c_layout_msgbox)
    Const_layout_navbar.const_new(c_layout_navbar)
    Const_layout_navdrawer.const_new(c_layout_navdrawer)
    Const_layout_panel.const_new(c_layout_panel)
    Const_layout_parallax.const_new(c_layout_parallax)
    Const_layout_statusbar.const_new(c_layout_statusbar)
    Const_layout_statusdrawer.const_new(c_layout_statusdrawer)
    Const_layout_text.const_new(c_layout_text)
    Const_layout_textentry.const_new(c_layout_textentry)
    Const_layout_titlebar.const_new(c_layout_titlebar)
    Const_pin_bottom.const_new(c_pin_bottom)
    Const_pin_center.const_new(c_pin_center)
    Const_pin_center_h.const_new(c_pin_center_h)
    Const_pin_center_v.const_new(c_pin_center_v)
    Const_pin_expand.const_new(c_pin_expand)
    Const_pin_left.const_new(c_pin_left)
    Const_pin_right.const_new(c_pin_right)
    Const_pin_top.const_new(c_pin_top)
    Const_point_center.const_new(c_point_center)
    Const_point_lefttop.const_new(c_point_lefttop)
    Const_point_rightbottom.const_new(c_point_rightbottom)
    Const_pointtype_absolute.const_new(c_pointtype_absolute)
    Const_pointtype_percent.const_new(c_pointtype_percent)
    Const_pointtype_relative.const_new(c_pointtype_relative)
    Const_styletype_custom.const_new(c_styletype_custom)
    Const_styletype_shared.const_new(c_styletype_shared)
    Const_styletype_system.const_new(c_styletype_system)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("align", vx_ui_ui.t_align)
    maptype.put("bounds", vx_ui_ui.t_bounds)
    maptype.put("cursor", vx_ui_ui.t_cursor)
    maptype.put("cursor-pointer", vx_ui_ui.t_cursor_pointer)
    maptype.put("flip", vx_ui_ui.t_flip)
    maptype.put("font", vx_ui_ui.t_font)
    maptype.put("fontface", vx_ui_ui.t_fontface)
    maptype.put("fontfacelist", vx_ui_ui.t_fontfacelist)
    maptype.put("fontfacemap", vx_ui_ui.t_fontfacemap)
    maptype.put("fontmap", vx_ui_ui.t_fontmap)
    maptype.put("fontstyle", vx_ui_ui.t_fontstyle)
    maptype.put("fontstylemap", vx_ui_ui.t_fontstylemap)
    maptype.put("image", vx_ui_ui.t_image)
    maptype.put("layout", vx_ui_ui.t_layout)
    maptype.put("layoutengine", vx_ui_ui.t_layoutengine)
    maptype.put("layoutlist", vx_ui_ui.t_layoutlist)
    maptype.put("layoutmap", vx_ui_ui.t_layoutmap)
    maptype.put("pin", vx_ui_ui.t_pin)
    maptype.put("point", vx_ui_ui.t_point)
    maptype.put("pointtype", vx_ui_ui.t_pointtype)
    maptype.put("style", vx_ui_ui.t_style)
    maptype.put("stylelist", vx_ui_ui.t_stylelist)
    maptype.put("stylemap", vx_ui_ui.t_stylemap)
    maptype.put("stylesheet", vx_ui_ui.t_stylesheet)
    maptype.put("styletype", vx_ui_ui.t_styletype)
    maptype.put("ui", vx_ui_ui.t_ui)
    maptype.put("uiengine", vx_ui_ui.t_uiengine)
    maptype.put("uilist", vx_ui_ui.t_uilist)
    maptype.put("uimap", vx_ui_ui.t_uimap)
    mapconst.put("align-center", vx_ui_ui.c_align_center)
    mapconst.put("align-left", vx_ui_ui.c_align_left)
    mapconst.put("align-right", vx_ui_ui.c_align_right)
    mapconst.put("flip-x", vx_ui_ui.c_flip_x)
    mapconst.put("flip-xy", vx_ui_ui.c_flip_xy)
    mapconst.put("flip-y", vx_ui_ui.c_flip_y)
    mapconst.put("layout-app", vx_ui_ui.c_layout_app)
    mapconst.put("layout-background", vx_ui_ui.c_layout_background)
    mapconst.put("layout-button", vx_ui_ui.c_layout_button)
    mapconst.put("layout-combobox", vx_ui_ui.c_layout_combobox)
    mapconst.put("layout-else", vx_ui_ui.c_layout_else)
    mapconst.put("layout-flow-columns", vx_ui_ui.c_layout_flow_columns)
    mapconst.put("layout-flow-item", vx_ui_ui.c_layout_flow_item)
    mapconst.put("layout-flow-rows", vx_ui_ui.c_layout_flow_rows)
    mapconst.put("layout-image", vx_ui_ui.c_layout_image)
    mapconst.put("layout-label", vx_ui_ui.c_layout_label)
    mapconst.put("layout-main", vx_ui_ui.c_layout_main)
    mapconst.put("layout-maxpanel", vx_ui_ui.c_layout_maxpanel)
    mapconst.put("layout-menubar", vx_ui_ui.c_layout_menubar)
    mapconst.put("layout-menudrawer", vx_ui_ui.c_layout_menudrawer)
    mapconst.put("layout-msgbox", vx_ui_ui.c_layout_msgbox)
    mapconst.put("layout-navbar", vx_ui_ui.c_layout_navbar)
    mapconst.put("layout-navdrawer", vx_ui_ui.c_layout_navdrawer)
    mapconst.put("layout-panel", vx_ui_ui.c_layout_panel)
    mapconst.put("layout-parallax", vx_ui_ui.c_layout_parallax)
    mapconst.put("layout-statusbar", vx_ui_ui.c_layout_statusbar)
    mapconst.put("layout-statusdrawer", vx_ui_ui.c_layout_statusdrawer)
    mapconst.put("layout-text", vx_ui_ui.c_layout_text)
    mapconst.put("layout-textentry", vx_ui_ui.c_layout_textentry)
    mapconst.put("layout-titlebar", vx_ui_ui.c_layout_titlebar)
    mapconst.put("pin-bottom", vx_ui_ui.c_pin_bottom)
    mapconst.put("pin-center", vx_ui_ui.c_pin_center)
    mapconst.put("pin-center-h", vx_ui_ui.c_pin_center_h)
    mapconst.put("pin-center-v", vx_ui_ui.c_pin_center_v)
    mapconst.put("pin-expand", vx_ui_ui.c_pin_expand)
    mapconst.put("pin-left", vx_ui_ui.c_pin_left)
    mapconst.put("pin-right", vx_ui_ui.c_pin_right)
    mapconst.put("pin-top", vx_ui_ui.c_pin_top)
    mapconst.put("point-center", vx_ui_ui.c_point_center)
    mapconst.put("point-lefttop", vx_ui_ui.c_point_lefttop)
    mapconst.put("point-rightbottom", vx_ui_ui.c_point_rightbottom)
    mapconst.put("pointtype-absolute", vx_ui_ui.c_pointtype_absolute)
    mapconst.put("pointtype-percent", vx_ui_ui.c_pointtype_percent)
    mapconst.put("pointtype-relative", vx_ui_ui.c_pointtype_relative)
    mapconst.put("styletype-custom", vx_ui_ui.c_styletype_custom)
    mapconst.put("styletype-shared", vx_ui_ui.c_styletype_shared)
    mapconst.put("styletype-system", vx_ui_ui.c_styletype_system)
    mapfunc.put("boolean-layout<-ui-parent-selected", vx_ui_ui.t_boolean_layout_from_ui_parent_selected)
    mapfunc.put("boolean-layout<-ui-parent-visible", vx_ui_ui.t_boolean_layout_from_ui_parent_visible)
    mapfunc.put("boolean-layoutaddchild<-ui-parent", vx_ui_ui.t_boolean_layoutaddchild_from_ui_parent)
    mapfunc.put("boolean-layoutremove<-ui", vx_ui_ui.t_boolean_layoutremove_from_ui)
    mapfunc.put("boolean-layoutremove<-ui-keys", vx_ui_ui.t_boolean_layoutremove_from_ui_keys)
    mapfunc.put("boolean-layoutremove<-ui-parent", vx_ui_ui.t_boolean_layoutremove_from_ui_parent)
    mapfunc.put("boolean-layoutremove<-ui-start-end", vx_ui_ui.t_boolean_layoutremove_from_ui_start_end)
    mapfunc.put("boolean-layoutselected<-ui", vx_ui_ui.t_boolean_layoutselected_from_ui)
    mapfunc.put("boolean-layoutselected<-ui-parent", vx_ui_ui.t_boolean_layoutselected_from_ui_parent)
    mapfunc.put("boolean-layoutselected<-ui-selected", vx_ui_ui.t_boolean_layoutselected_from_ui_selected)
    mapfunc.put("boolean-layoutvisible<-ui", vx_ui_ui.t_boolean_layoutvisible_from_ui)
    mapfunc.put("boolean-print", vx_ui_ui.t_boolean_print)
    mapfunc.put("boolean-removestate-uiapp", vx_ui_ui.t_boolean_removestate_uiapp)
    mapfunc.put("boolean-write<-ui-parent", vx_ui_ui.t_boolean_write_from_ui_parent)
    mapfunc.put("boolean-writeremove<-ui-uid", vx_ui_ui.t_boolean_writeremove_from_ui_uid)
    mapfunc.put("boolean-writestate<-ui", vx_ui_ui.t_boolean_writestate_from_ui)
    mapfunc.put("boolean-writestate<-uiapp", vx_ui_ui.t_boolean_writestate_from_uiapp)
    mapfunc.put("boolean-writestate<-uiengine", vx_ui_ui.t_boolean_writestate_from_uiengine)
    mapfunc.put("fontfacemap<-fontfacelist", vx_ui_ui.t_fontfacemap_from_fontfacelist)
    mapfunc.put("int-child<-ui-uid", vx_ui_ui.t_int_child_from_ui_uid)
    mapfunc.put("int-selected<-ui", vx_ui_ui.t_int_selected_from_ui)
    mapfunc.put("int-visible<-ui", vx_ui_ui.t_int_visible_from_ui)
    mapfunc.put("intlist-visible<-ui", vx_ui_ui.t_intlist_visible_from_ui)
    mapfunc.put("layout<-style", vx_ui_ui.t_layout_from_style)
    mapfunc.put("layout<-ui", vx_ui_ui.t_layout_from_ui)
    mapfunc.put("layout<-ui-layoutengine", vx_ui_ui.t_layout_from_ui_layoutengine)
    mapfunc.put("layout<-ui-layoutmap-else", vx_ui_ui.t_layout_from_ui_layoutmap_else)
    mapfunc.put("layoutengine-readstate", vx_ui_ui.t_layoutengine_readstate)
    mapfunc.put("layoutmap<-layoutlist", vx_ui_ui.t_layoutmap_from_layoutlist)
    mapfunc.put("string-parentuid<-uid", vx_ui_ui.t_string_parentuid_from_uid)
    mapfunc.put("string-selected<-ui", vx_ui_ui.t_string_selected_from_ui)
    mapfunc.put("stringlist-selected<-ui", vx_ui_ui.t_stringlist_selected_from_ui)
    mapfunc.put("stringlist<-ui", vx_ui_ui.t_stringlist_from_ui)
    mapfunc.put("stylemap<-stylelist", vx_ui_ui.t_stylemap_from_stylelist)
    mapfunc.put("stylesheet-readstate", vx_ui_ui.t_stylesheet_readstate)
    mapfunc.put("stylesheet-render", vx_ui_ui.t_stylesheet_render)
    mapfunc.put("ui-addlayout<-ui", vx_ui_ui.t_ui_addlayout_from_ui)
    mapfunc.put("ui-addlayout<-ui-layoutengine", vx_ui_ui.t_ui_addlayout_from_ui_layoutengine)
    mapfunc.put("ui-addlayout<-ui-layoutmap-else", vx_ui_ui.t_ui_addlayout_from_ui_layoutmap_else)
    mapfunc.put("ui-addlayout<-ui-uiengine", vx_ui_ui.t_ui_addlayout_from_ui_uiengine)
    mapfunc.put("ui-child<-ui-pos", vx_ui_ui.t_ui_child_from_ui_pos)
    mapfunc.put("ui-child<-ui-uid", vx_ui_ui.t_ui_child_from_ui_uid)
    mapfunc.put("ui-from<-event", vx_ui_ui.t_ui_from_from_event)
    mapfunc.put("ui-layout", vx_ui_ui.t_ui_layout)
    mapfunc.put("ui-layout<-fn-layout-ui-orig-parent", vx_ui_ui.t_ui_layout_from_fn_layout_ui_orig_parent)
    mapfunc.put("ui-layout<-ui-orig-parent", vx_ui_ui.t_ui_layout_from_ui_orig_parent)
    mapfunc.put("ui-layout<-ui-parent-selected", vx_ui_ui.t_ui_layout_from_ui_parent_selected)
    mapfunc.put("ui-layout<-ui-parent-visible", vx_ui_ui.t_ui_layout_from_ui_parent_visible)
    mapfunc.put("ui-readstate-uiapp", vx_ui_ui.t_ui_readstate_uiapp)
    mapfunc.put("ui-readstate<-uid", vx_ui_ui.t_ui_readstate_from_uid)
    mapfunc.put("ui-selected<-ui", vx_ui_ui.t_ui_selected_from_ui)
    mapfunc.put("ui-visible<-ui", vx_ui_ui.t_ui_visible_from_ui)
    mapfunc.put("ui-write<-ui-child", vx_ui_ui.t_ui_write_from_ui_child)
    mapfunc.put("ui-write<-ui-childmap", vx_ui_ui.t_ui_write_from_ui_childmap)
    mapfunc.put("ui-write<-ui-visible", vx_ui_ui.t_ui_write_from_ui_visible)
    mapfunc.put("ui<-layout-ui-orig-parent", vx_ui_ui.t_ui_from_layout_ui_orig_parent)
    mapfunc.put("ui<-ui-find", vx_ui_ui.t_ui_from_ui_find)
    mapfunc.put("ui<-ui-selected", vx_ui_ui.t_ui_from_ui_selected)
    mapfunc.put("uid-selected<-ui", vx_ui_ui.t_uid_selected_from_ui)
    mapfunc.put("uiengine-readstate", vx_ui_ui.t_uiengine_readstate)
    mapfunc.put("uiengine-render", vx_ui_ui.t_uiengine_render)
    mapfunc.put("uilist-selected<-ui", vx_ui_ui.t_uilist_selected_from_ui)
    mapfunc.put("uilist-visible<-ui", vx_ui_ui.t_uilist_visible_from_ui)
    mapfunc.put("uilist<-uimap", vx_ui_ui.t_uilist_from_uimap)
    mapfunc.put("uimap-addlayout<-uimap-layoutmap-else", vx_ui_ui.t_uimap_addlayout_from_uimap_layoutmap_else)
    mapfunc.put("uimap-layout<-uimap-parent", vx_ui_ui.t_uimap_layout_from_uimap_parent)
    mapfunc.put("uimap<-uilist", vx_ui_ui.t_uimap_from_uilist)
    mapfunc.put("uimap<-uimap-data", vx_ui_ui.t_uimap_from_uimap_data)
    vx_core.vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc)
  }

}
