package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_file {

  fun vx_boolean_exists_from_file(
    file : vx_data_file.Type_file) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    val fullpath : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
    val sfullpath : String = fullpath.vx_string()
    val file : java.io.File = java.io.File(sfullpath)
    if (file.exists()) {
      output = vx_core.c_true
    }
    return output
  }

  fun vx_boolean_write_from_file_string(
    context : vx_core.Type_context,
    file : vx_data_file.Type_file,
    text : vx_core.Type_string) : vx_core.Type_boolean {
    var output = vx_core.c_false
    val fullpath : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
    val sfullpath : String = fullpath.vx_string()
    val stext : String = text.vx_string()
    val path : java.nio.file.Path = java.nio.file.Paths.get(sfullpath)
    try {
      val bytes : ByteArray = stext.toByteArray()
      java.nio.file.Files.write(path, bytes)
      output = vx_core.c_true
    } catch (ex : Exception) {
      val msg : vx_core.Type_msg = vx_core.vx_msg_from_exception(
        "boolean-write<-file-string", ex
      )
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }

  fun vx_pathcurrent_from_os() : vx_core.Type_string {
    val stext : String = vx_spathcurrent_from_os()
    val output : vx_core.Type_string = vx_core.vx_new_string(stext)
    return output
  }

  fun vx_spathcurrent_from_os() : String {
    var path : java.nio.file.Path = java.nio.file.Paths.get("")
    path = path.toAbsolutePath()
    val output = path.toString()
    return output
  }

  fun vx_string_read_from_file(
    file : vx_data_file.Type_file) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    var fullpath : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
    var sfullpath : String = fullpath.vx_string()
    val path : java.nio.file.Path = java.nio.file.Paths.get(sfullpath)
    if (java.nio.file.Files.exists(path)) {
      try {
        val bytes : ByteArray = java.nio.file.Files.readAllBytes(path)
        val scontent : String = String(bytes)
        val valcontent : vx_core.Type_string = vx_core.vx_new_string(scontent)
        output = valcontent
      } catch (ex : Exception) {
        val msg : vx_core.Type_msg = vx_core.vx_msg_from_exception(
          "string-read<-file", ex
        )
        output = vx_core.vx_copy(output, msg)
      }
    } else {
      val msg : vx_core.Type_msg = vx_core.vx_msg_from_error(
        "string-read<-file", ":filenotfound", file
      )
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }

  fun vx_string_read_from_file(
    context : vx_core.Type_context,
    file : vx_data_file.Type_file) : vx_core.Type_string {
    return vx_string_read_from_file(file)
  }

  interface Type_file : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun format() : vx_data_file.Type_fileformat
    fun path() : vx_core.Type_string
    fun permission() : vx_core.Type_permission
    fun text() : vx_core.Type_string
  }

  class Class_file : vx_core.Class_base, Type_file {
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

    var vx_p_format : vx_data_file.Type_fileformat? = null

    override fun format() : vx_data_file.Type_fileformat {
      var output : vx_data_file.Type_fileformat = vx_data_file.e_fileformat
      var testnull : vx_data_file.Type_fileformat? = vx_p_format
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

    var vx_p_permission : vx_core.Type_permission? = null

    override fun permission() : vx_core.Type_permission {
      var output : vx_core.Type_permission = vx_core.e_permission
      var testnull : vx_core.Type_permission? = vx_p_permission
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
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":format")) {
        output = this.format()
      } else if ((skey==":path")) {
        output = this.path()
      } else if ((skey==":permission")) {
        output = this.permission()
      } else if ((skey==":text")) {
        output = this.text()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":format", this.format())
      map.put(":path", this.path())
      map.put(":permission", this.permission())
      map.put(":text", this.text())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_file = vx_core.vx_copy(vx_data_file.e_file, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_file = this
      var ischanged : Boolean = false
      var value : vx_data_file.Class_file = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_format : vx_data_file.Type_fileformat = value.format()
      var vx_p_path : vx_core.Type_string = value.path()
      var vx_p_permission : vx_core.Type_permission = value.permission()
      var vx_p_text : vx_core.Type_string = value.text()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":format")
      validkeys.add(":path")
      validkeys.add(":permission")
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
            msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":format")) {
            if (valsub == vx_p_format) {
            } else if (valsub is vx_data_file.Type_fileformat) {
              var valformat : vx_data_file.Type_fileformat = valsub as vx_data_file.Type_fileformat
              ischanged = true
              vx_p_format = valformat
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("format"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":permission")) {
            if (valsub == vx_p_permission) {
            } else if (valsub is vx_core.Type_permission) {
              var valpermission : vx_core.Type_permission = valsub as vx_core.Type_permission
              ischanged = true
              vx_p_permission = valpermission
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("permission"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_file.Class_file = vx_data_file.Class_file()
        work.vx_p_name = vx_p_name
        work.vx_p_format = vx_p_format
        work.vx_p_path = vx_p_path
        work.vx_p_permission = vx_p_permission
        work.vx_p_text = vx_p_text
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.e_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_file
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/file", // pkgname
        "file", // name
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

  val e_file : vx_data_file.Type_file = vx_data_file.Class_file()
  val t_file : vx_data_file.Type_file = vx_data_file.Class_file()

  interface Type_fileformat : vx_core.Type_any {
  }

  class Class_fileformat : vx_core.Class_base, Type_fileformat {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_fileformat = vx_core.vx_copy(vx_data_file.e_fileformat, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_fileformat = this
      var ischanged : Boolean = false
      var value : vx_data_file.Class_fileformat = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_file.Class_fileformat = vx_data_file.Class_fileformat()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.e_fileformat
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_fileformat
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/file", // pkgname
        "fileformat", // name
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

  val e_fileformat : vx_data_file.Type_fileformat = vx_data_file.Class_fileformat()
  val t_fileformat : vx_data_file.Type_fileformat = vx_data_file.Class_fileformat()

  interface Type_filelist : vx_core.Type_list {
    fun vx_listfile() : List<vx_data_file.Type_file>
    fun vx_file(index : vx_core.Type_int) : vx_data_file.Type_file
  }

  class Class_filelist : vx_core.Class_base, Type_filelist {
    constructor() {}

    var vx_p_list : List<vx_data_file.Type_file> = vx_core.immutablelist(
      ArrayList<vx_data_file.Type_file>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_file(index : vx_core.Type_int) : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_data_file.e_file
      var list : vx_data_file.Class_filelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_file.Type_file> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listfile() : List<vx_data_file.Type_file> {
      var output : List<vx_data_file.Type_file> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_file.Type_file = this.vx_file(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_filelist = vx_core.vx_copy(vx_data_file.e_filelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_file.Type_filelist = this
      var ischanged : Boolean = false
      var value : vx_data_file.Class_filelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_file.Type_file> = ArrayList<vx_data_file.Type_file>(value.vx_listfile())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_file.Type_filelist) {
          var multi : vx_data_file.Type_filelist = valsub as vx_data_file.Type_filelist
          ischanged = true
          listval.addAll(multi.vx_listfile())
        } else if (valsub is vx_data_file.Type_file) {
          var allowsub : vx_data_file.Type_file = valsub as vx_data_file.Type_file
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_file.Type_file) {
          ischanged = true
          listval.add(valsub as vx_data_file.Type_file)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_file.Type_file) {
              var valitem : vx_data_file.Type_file = item as vx_data_file.Type_file
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_file.Class_filelist = vx_data_file.Class_filelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.e_filelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_filelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/file", // pkgname
        "filelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_file.t_file), // allowtypes
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

  val e_filelist : vx_data_file.Type_filelist = vx_data_file.Class_filelist()
  val t_filelist : vx_data_file.Type_filelist = vx_data_file.Class_filelist()

  interface Func_boolean_exists_from_file : vx_core.Func_any_from_any {
    fun vx_boolean_exists_from_file(file : vx_data_file.Type_file) : vx_core.Type_boolean
  }

  class Class_boolean_exists_from_file : vx_core.Class_base, Func_boolean_exists_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_exists_from_file = vx_data_file.Class_boolean_exists_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_exists_from_file = vx_data_file.Class_boolean_exists_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_boolean_exists_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_boolean_exists_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_boolean_exists_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_boolean_exists_from_file(file)
      return output
    }

    override fun vx_boolean_exists_from_file(file : vx_data_file.Type_file) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_file.f_boolean_exists_from_file(file)
      return output
    }

  }

  val e_boolean_exists_from_file : vx_data_file.Func_boolean_exists_from_file = vx_data_file.Class_boolean_exists_from_file()
  val t_boolean_exists_from_file : vx_data_file.Func_boolean_exists_from_file = vx_data_file.Class_boolean_exists_from_file()

  fun f_boolean_exists_from_file(file : vx_data_file.Type_file) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_data_file.vx_boolean_exists_from_file(file)
    return output
  }


  interface Func_boolean_write_from_file : vx_core.Func_any_from_any_context {
    fun vx_boolean_write_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_file : vx_core.Class_base, Func_boolean_write_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file = vx_data_file.Class_boolean_write_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file = vx_data_file.Class_boolean_write_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_boolean_write_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_boolean_write_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_boolean_write_from_file(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_boolean_write_from_file(context, file)
      return output
    }

    override fun vx_boolean_write_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_file.f_boolean_write_from_file(context, file)
      return output
    }

  }

  val e_boolean_write_from_file : vx_data_file.Func_boolean_write_from_file = vx_data_file.Class_boolean_write_from_file()
  val t_boolean_write_from_file : vx_data_file.Func_boolean_write_from_file = vx_data_file.Class_boolean_write_from_file()

  fun f_boolean_write_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_data_file.f_boolean_write_from_file_string(
      context,
      file,
      file.text()
    )
    return output
  }


  interface Func_boolean_write_from_file_any : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_file_any(context : vx_core.Type_context, file : vx_data_file.Type_file, value : vx_core.Type_any) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_file_any : vx_core.Class_base, Func_boolean_write_from_file_any {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file_any = vx_data_file.Class_boolean_write_from_file_any()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file_any = vx_data_file.Class_boolean_write_from_file_any()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
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
      var output : vx_core.Type_any = vx_data_file.e_boolean_write_from_file_any
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_boolean_write_from_file_any
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_file.f_boolean_write_from_file_any(context, file, value)
      return output
    }

    override fun vx_boolean_write_from_file_any(context : vx_core.Type_context, file : vx_data_file.Type_file, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_file.f_boolean_write_from_file_any(context, file, value)
      return output
    }

  }

  val e_boolean_write_from_file_any : vx_data_file.Func_boolean_write_from_file_any = vx_data_file.Class_boolean_write_from_file_any()
  val t_boolean_write_from_file_any : vx_data_file.Func_boolean_write_from_file_any = vx_data_file.Class_boolean_write_from_file_any()

  fun f_boolean_write_from_file_any(context : vx_core.Type_context, file : vx_data_file.Type_file, value : vx_core.Type_any) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    output = vx_data_file.f_boolean_write_from_file_string(
      context,
      file,
      vx_core.f_string_from_any(
        value
      )
    )
    return output
  }


  interface Func_boolean_write_from_file_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_boolean_write_from_file_string(context : vx_core.Type_context, file : vx_data_file.Type_file, text : vx_core.Type_string) : vx_core.Type_boolean
  }

  class Class_boolean_write_from_file_string : vx_core.Class_base, Func_boolean_write_from_file_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file_string = vx_data_file.Class_boolean_write_from_file_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_boolean_write_from_file_string = vx_data_file.Class_boolean_write_from_file_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
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
      var output : vx_core.Type_any = vx_data_file.e_boolean_write_from_file_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_boolean_write_from_file_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      var text : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_data_file.f_boolean_write_from_file_string(context, file, text)
      return output
    }

    override fun vx_boolean_write_from_file_string(context : vx_core.Type_context, file : vx_data_file.Type_file, text : vx_core.Type_string) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_data_file.f_boolean_write_from_file_string(context, file, text)
      return output
    }

  }

  val e_boolean_write_from_file_string : vx_data_file.Func_boolean_write_from_file_string = vx_data_file.Class_boolean_write_from_file_string()
  val t_boolean_write_from_file_string : vx_data_file.Func_boolean_write_from_file_string = vx_data_file.Class_boolean_write_from_file_string()

  fun f_boolean_write_from_file_string(context : vx_core.Type_context, file : vx_data_file.Type_file, text : vx_core.Type_string) : vx_core.Type_boolean {
    var output : vx_core.Type_boolean = vx_core.e_boolean
    if (vx_core.f_boolean_permission_from_func(context, vx_data_file.t_boolean_write_from_file_string).vx_boolean()) {
      try {
        output = vx_data_file.vx_boolean_write_from_file_string(context, file, text)
      } catch (err : Exception) {
        var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/data/file/boolean-write<-file-string", err)
        output = vx_core.vx_copy(output, msg)
      }
    } else {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/core/func", ":permissiondenied", vx_core.vx_new_string("boolean-write<-file-string"))
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_file_read_from_file : vx_core.Func_any_from_any_context {
    fun vx_file_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_file.Type_file
  }

  class Class_file_read_from_file : vx_core.Class_base, Func_file_read_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_file_read_from_file = vx_data_file.Class_file_read_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_file_read_from_file = vx_data_file.Class_file_read_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_file_read_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_file_read_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_file_read_from_file(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_file_read_from_file(context, file)
      return output
    }

    override fun vx_file_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_data_file.f_file_read_from_file(context, file)
      return output
    }

  }

  val e_file_read_from_file : vx_data_file.Func_file_read_from_file = vx_data_file.Class_file_read_from_file()
  val t_file_read_from_file : vx_data_file.Func_file_read_from_file = vx_data_file.Class_file_read_from_file()

  fun f_file_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_data_file.e_file
    if (vx_core.f_boolean_permission_from_func(context, vx_data_file.t_file_read_from_file).vx_boolean()) {
      output = vx_core.f_copy(
        file,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":text"),
          vx_data_file.f_string_read_from_file(
            context,
            file
          )
        )
      )
    } else {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/core/func", ":permissiondenied", vx_core.vx_new_string("file-read<-file"))
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_file_from_path : vx_core.Func_any_from_any {
    fun vx_file_from_path(path : vx_core.Type_string) : vx_data_file.Type_file
  }

  class Class_file_from_path : vx_core.Class_base, Func_file_from_path {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_file_from_path = vx_data_file.Class_file_from_path()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_file_from_path = vx_data_file.Class_file_from_path()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "file<-path", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_file_from_path
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_file_from_path
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_string = value as vx_core.Type_string
      var outputval : vx_core.Type_any = vx_data_file.f_file_from_path(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var path : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_file_from_path(path)
      return output
    }

    override fun vx_file_from_path(path : vx_core.Type_string) : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_data_file.f_file_from_path(path)
      return output
    }

  }

  val e_file_from_path : vx_data_file.Func_file_from_path = vx_data_file.Class_file_from_path()
  val t_file_from_path : vx_data_file.Func_file_from_path = vx_data_file.Class_file_from_path()

  fun f_file_from_path(path : vx_core.Type_string) : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_data_file.e_file
    output = vx_core.f_let(
      vx_data_file.t_file,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var pos : vx_core.Type_int = vx_type.f_int_from_string_findlast(
          path,
          vx_core.vx_new_string("/")
        )
        var name : vx_core.Type_string = vx_type.f_string_from_string_start(
          path,
          vx_core.f_plus1(
            pos
          )
        )
        var pth : vx_core.Type_string = vx_type.f_string_from_string_end(
          path,
          vx_core.f_minus1(
            pos
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_data_file.t_file,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            name,
            vx_core.vx_new_string(":path"),
            pth
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_name_from_file : vx_core.Func_any_from_any {
    fun vx_name_from_file(file : vx_data_file.Type_file) : vx_core.Type_string
  }

  class Class_name_from_file : vx_core.Class_base, Func_name_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_name_from_file = vx_data_file.Class_name_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_name_from_file = vx_data_file.Class_name_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_name_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_name_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_name_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_name_from_file(file)
      return output
    }

    override fun vx_name_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_file.f_name_from_file(file)
      return output
    }

  }

  val e_name_from_file : vx_data_file.Func_name_from_file = vx_data_file.Class_name_from_file()
  val t_name_from_file : vx_data_file.Func_name_from_file = vx_data_file.Class_name_from_file()

  fun f_name_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = file.name()
    return output
  }


  interface Func_path_from_file : vx_core.Func_any_from_any {
    fun vx_path_from_file(file : vx_data_file.Type_file) : vx_core.Type_string
  }

  class Class_path_from_file : vx_core.Class_base, Func_path_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_path_from_file = vx_data_file.Class_path_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_path_from_file = vx_data_file.Class_path_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_path_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_path_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_path_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_path_from_file(file)
      return output
    }

    override fun vx_path_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_file.f_path_from_file(file)
      return output
    }

  }

  val e_path_from_file : vx_data_file.Func_path_from_file = vx_data_file.Class_path_from_file()
  val t_path_from_file : vx_data_file.Func_path_from_file = vx_data_file.Class_path_from_file()

  fun f_path_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = file.path()
    return output
  }


  interface Func_pathcurrent_from_os : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_pathcurrent_from_os() : vx_core.Type_string
  }

  class Class_pathcurrent_from_os : vx_core.Class_base, Func_pathcurrent_from_os {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_pathcurrent_from_os = vx_data_file.Class_pathcurrent_from_os()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_pathcurrent_from_os = vx_data_file.Class_pathcurrent_from_os()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
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
      var output : vx_core.Type_any = vx_data_file.e_pathcurrent_from_os
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_pathcurrent_from_os
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_data_file.f_pathcurrent_from_os()
      return output
    }

    override fun vx_pathcurrent_from_os() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_file.f_pathcurrent_from_os()
      return output
    }

  }

  val e_pathcurrent_from_os : vx_data_file.Func_pathcurrent_from_os = vx_data_file.Class_pathcurrent_from_os()
  val t_pathcurrent_from_os : vx_data_file.Func_pathcurrent_from_os = vx_data_file.Class_pathcurrent_from_os()

  fun f_pathcurrent_from_os() : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_data_file.vx_pathcurrent_from_os()
    return output
  }


  interface Func_pathfull_from_file : vx_core.Func_any_from_any {
    fun vx_pathfull_from_file(file : vx_data_file.Type_file) : vx_core.Type_string
  }

  class Class_pathfull_from_file : vx_core.Class_base, Func_pathfull_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_pathfull_from_file = vx_data_file.Class_pathfull_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_pathfull_from_file = vx_data_file.Class_pathfull_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_pathfull_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_pathfull_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_pathfull_from_file(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_pathfull_from_file(file)
      return output
    }

    override fun vx_pathfull_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_file.f_pathfull_from_file(file)
      return output
    }

  }

  val e_pathfull_from_file : vx_data_file.Func_pathfull_from_file = vx_data_file.Class_pathfull_from_file()
  val t_pathfull_from_file : vx_data_file.Func_pathfull_from_file = vx_data_file.Class_pathfull_from_file()

  fun f_pathfull_from_file(file : vx_data_file.Type_file) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    output = vx_core.f_let(
      vx_core.t_string,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var path : vx_core.Type_string = vx_data_file.f_path_from_file(
          file
        )
        var name : vx_core.Type_string = vx_data_file.f_name_from_file(
          file
        )
        var output_1 : vx_core.Type_any = vx_core.f_if_2(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_thenelselist,
            vx_core.f_then(
              vx_core.t_boolean_from_func.vx_fn_new({ ->
                var output_2 : vx_core.Type_any = vx_core.f_is_empty(
                  path
                )
                output_2
              }),
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_3 : vx_core.Type_any = name
                output_3
              })
            ),
            vx_core.f_else(
              vx_core.t_any_from_func.vx_fn_new({ ->
                var output_4 : vx_core.Type_any = vx_core.f_new(
                  vx_core.t_string,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    path,
                    vx_core.vx_new_string("/"),
                    name
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


  interface Func_string_read_from_file : vx_core.Func_any_from_any_context {
    fun vx_string_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_string
  }

  class Class_string_read_from_file : vx_core.Class_base, Func_string_read_from_file {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_string_read_from_file = vx_data_file.Class_string_read_from_file()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_data_file.Class_string_read_from_file = vx_data_file.Class_string_read_from_file()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
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
      var output : vx_core.Type_any = vx_data_file.e_string_read_from_file
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_file.t_string_read_from_file
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_data_file.Type_file = value as vx_data_file.Type_file
      var outputval : vx_core.Type_any = vx_data_file.f_string_read_from_file(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var file : vx_data_file.Type_file = vx_core.f_any_from_any(vx_data_file.t_file, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_data_file.f_string_read_from_file(context, file)
      return output
    }

    override fun vx_string_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_data_file.f_string_read_from_file(context, file)
      return output
    }

  }

  val e_string_read_from_file : vx_data_file.Func_string_read_from_file = vx_data_file.Class_string_read_from_file()
  val t_string_read_from_file : vx_data_file.Func_string_read_from_file = vx_data_file.Class_string_read_from_file()

  fun f_string_read_from_file(context : vx_core.Type_context, file : vx_data_file.Type_file) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    if (vx_core.f_boolean_permission_from_func(context, vx_data_file.t_string_read_from_file).vx_boolean()) {
      try {
        output = vx_data_file.vx_string_read_from_file(context, file)
      } catch (err : Exception) {
        var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/data/file/string-read<-file", err)
        output = vx_core.vx_copy(output, msg)
      }
    } else {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/core/func", ":permissiondenied", vx_core.vx_new_string("string-read<-file"))
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("file", vx_data_file.t_file)
    maptype.put("fileformat", vx_data_file.t_fileformat)
    maptype.put("filelist", vx_data_file.t_filelist)
    mapfunc.put("boolean-exists<-file", vx_data_file.t_boolean_exists_from_file)
    mapfunc.put("boolean-write<-file", vx_data_file.t_boolean_write_from_file)
    mapfunc.put("boolean-write<-file-any", vx_data_file.t_boolean_write_from_file_any)
    mapfunc.put("boolean-write<-file-string", vx_data_file.t_boolean_write_from_file_string)
    mapfunc.put("file-read<-file", vx_data_file.t_file_read_from_file)
    mapfunc.put("file<-path", vx_data_file.t_file_from_path)
    mapfunc.put("name<-file", vx_data_file.t_name_from_file)
    mapfunc.put("path<-file", vx_data_file.t_path_from_file)
    mapfunc.put("pathcurrent<-os", vx_data_file.t_pathcurrent_from_os)
    mapfunc.put("pathfull<-file", vx_data_file.t_pathfull_from_file)
    mapfunc.put("string-read<-file", vx_data_file.t_string_read_from_file)
    vx_core.vx_global_package_set("vx/data/file", maptype, mapconst, mapfunc)
  }

}
