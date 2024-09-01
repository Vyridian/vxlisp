package com.vxlisp.vx

import java.util.concurrent.CompletableFuture
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*

object vx_test {


  interface Type_testcase : vx_core.Type_struct {
    fun passfail() : vx_core.Type_boolean
    fun testpkg() : vx_core.Type_string
    fun casename() : vx_core.Type_string
    fun describelist() : vx_test.Type_testdescribelist
  }

  class Class_testcase : vx_core.Class_base, Type_testcase {
    constructor() {}

    var vx_p_passfail : vx_core.Type_boolean? = null

    override fun passfail() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_passfail
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_casename : vx_core.Type_string? = null

    override fun casename() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_casename
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_describelist : vx_test.Type_testdescribelist? = null

    override fun describelist() : vx_test.Type_testdescribelist {
      var output : vx_test.Type_testdescribelist = vx_test.e_testdescribelist
      var testnull : vx_test.Type_testdescribelist? = vx_p_describelist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":passfail")) {
        output = this.passfail()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      } else if ((skey==":casename")) {
        output = this.casename()
      } else if ((skey==":describelist")) {
        output = this.describelist()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":passfail", this.passfail())
      map.put(":testpkg", this.testpkg())
      map.put(":casename", this.casename())
      map.put(":describelist", this.describelist())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcase = vx_core.vx_copy(vx_test.e_testcase, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcase = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testcase = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_passfail : vx_core.Type_boolean = value.passfail()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var vx_p_casename : vx_core.Type_string = value.casename()
      var vx_p_describelist : vx_test.Type_testdescribelist = value.describelist()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":passfail")
      validkeys.add(":testpkg")
      validkeys.add(":casename")
      validkeys.add(":describelist")
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
            msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":passfail")) {
            if (valsub == vx_p_passfail) {
            } else if (valsub is vx_core.Type_boolean) {
              var valpassfail : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_passfail = valpassfail
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_passfail = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("passfail"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":casename")) {
            if (valsub == vx_p_casename) {
            } else if (valsub is vx_core.Type_string) {
              var valcasename : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_casename = valcasename
            } else if (valsub is String) {
              ischanged = true
              vx_p_casename = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("casename"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":describelist")) {
            if (valsub == vx_p_describelist) {
            } else if (valsub is vx_test.Type_testdescribelist) {
              var valdescribelist : vx_test.Type_testdescribelist = valsub as vx_test.Type_testdescribelist
              ischanged = true
              vx_p_describelist = valdescribelist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("describelist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testcase = vx_test.Class_testcase()
        work.vx_p_passfail = vx_p_passfail
        work.vx_p_testpkg = vx_p_testpkg
        work.vx_p_casename = vx_p_casename
        work.vx_p_describelist = vx_p_describelist
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testcase
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testcase
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testcase", // name
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

  val e_testcase : vx_test.Type_testcase = vx_test.Class_testcase()
  val t_testcase : vx_test.Type_testcase = vx_test.Class_testcase()

  interface Type_testcaselist : vx_core.Type_list {
    fun vx_listtestcase() : List<vx_test.Type_testcase>
    fun vx_testcase(index : vx_core.Type_int) : vx_test.Type_testcase
  }

  class Class_testcaselist : vx_core.Class_base, Type_testcaselist {
    constructor() {}

    var vx_p_list : List<vx_test.Type_testcase> = vx_core.immutablelist(
      ArrayList<vx_test.Type_testcase>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_testcase(index : vx_core.Type_int) : vx_test.Type_testcase {
      var output : vx_test.Type_testcase = vx_test.e_testcase
      var list : vx_test.Class_testcaselist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_test.Type_testcase> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtestcase() : List<vx_test.Type_testcase> {
      var output : List<vx_test.Type_testcase> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_test.Type_testcase = this.vx_testcase(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcaselist = vx_core.vx_copy(vx_test.e_testcaselist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcaselist = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testcaselist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_test.Type_testcase> = ArrayList<vx_test.Type_testcase>(value.vx_listtestcase())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_test.Type_testcaselist) {
          var multi : vx_test.Type_testcaselist = valsub as vx_test.Type_testcaselist
          ischanged = true
          listval.addAll(multi.vx_listtestcase())
        } else if (valsub is vx_test.Type_testcase) {
          var allowsub : vx_test.Type_testcase = valsub as vx_test.Type_testcase
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_test.Type_testcase) {
          ischanged = true
          listval.add(valsub as vx_test.Type_testcase)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_test.Type_testcase) {
              var valitem : vx_test.Type_testcase = item as vx_test.Type_testcase
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testcaselist = vx_test.Class_testcaselist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testcaselist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testcaselist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_test.t_testcase), // allowtypes
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

  val e_testcaselist : vx_test.Type_testcaselist = vx_test.Class_testcaselist()
  val t_testcaselist : vx_test.Type_testcaselist = vx_test.Class_testcaselist()

  interface Type_testcoveragedetail : vx_core.Type_struct {
    fun constmap() : vx_core.Type_intmap
    fun funcmap() : vx_core.Type_intmap
    fun testpkg() : vx_core.Type_string
    fun typemap() : vx_core.Type_intmap
  }

  class Class_testcoveragedetail : vx_core.Class_base, Type_testcoveragedetail {
    constructor() {}

    var vx_p_constmap : vx_core.Type_intmap? = null

    override fun constmap() : vx_core.Type_intmap {
      var output : vx_core.Type_intmap = vx_core.e_intmap
      var testnull : vx_core.Type_intmap? = vx_p_constmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_funcmap : vx_core.Type_intmap? = null

    override fun funcmap() : vx_core.Type_intmap {
      var output : vx_core.Type_intmap = vx_core.e_intmap
      var testnull : vx_core.Type_intmap? = vx_p_funcmap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_typemap : vx_core.Type_intmap? = null

    override fun typemap() : vx_core.Type_intmap {
      var output : vx_core.Type_intmap = vx_core.e_intmap
      var testnull : vx_core.Type_intmap? = vx_p_typemap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":constmap")) {
        output = this.constmap()
      } else if ((skey==":funcmap")) {
        output = this.funcmap()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      } else if ((skey==":typemap")) {
        output = this.typemap()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":constmap", this.constmap())
      map.put(":funcmap", this.funcmap())
      map.put(":testpkg", this.testpkg())
      map.put(":typemap", this.typemap())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragedetail = vx_core.vx_copy(vx_test.e_testcoveragedetail, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragedetail = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testcoveragedetail = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_constmap : vx_core.Type_intmap = value.constmap()
      var vx_p_funcmap : vx_core.Type_intmap = value.funcmap()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var vx_p_typemap : vx_core.Type_intmap = value.typemap()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":constmap")
      validkeys.add(":funcmap")
      validkeys.add(":testpkg")
      validkeys.add(":typemap")
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
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":constmap")) {
            if (valsub == vx_p_constmap) {
            } else if (valsub is vx_core.Type_intmap) {
              var valconstmap : vx_core.Type_intmap = valsub as vx_core.Type_intmap
              ischanged = true
              vx_p_constmap = valconstmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("constmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":funcmap")) {
            if (valsub == vx_p_funcmap) {
            } else if (valsub is vx_core.Type_intmap) {
              var valfuncmap : vx_core.Type_intmap = valsub as vx_core.Type_intmap
              ischanged = true
              vx_p_funcmap = valfuncmap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("funcmap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":typemap")) {
            if (valsub == vx_p_typemap) {
            } else if (valsub is vx_core.Type_intmap) {
              var valtypemap : vx_core.Type_intmap = valsub as vx_core.Type_intmap
              ischanged = true
              vx_p_typemap = valtypemap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("typemap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testcoveragedetail = vx_test.Class_testcoveragedetail()
        work.vx_p_constmap = vx_p_constmap
        work.vx_p_funcmap = vx_p_funcmap
        work.vx_p_testpkg = vx_p_testpkg
        work.vx_p_typemap = vx_p_typemap
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testcoveragedetail
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testcoveragedetail
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
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

  val e_testcoveragedetail : vx_test.Type_testcoveragedetail = vx_test.Class_testcoveragedetail()
  val t_testcoveragedetail : vx_test.Type_testcoveragedetail = vx_test.Class_testcoveragedetail()

  interface Type_testcoveragenums : vx_core.Type_struct {
    fun pct() : vx_core.Type_int
    fun testpkg() : vx_core.Type_string
    fun tests() : vx_core.Type_int
    fun total() : vx_core.Type_int
  }

  class Class_testcoveragenums : vx_core.Class_base, Type_testcoveragenums {
    constructor() {}

    var vx_p_pct : vx_core.Type_int? = null

    override fun pct() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_pct
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_tests : vx_core.Type_int? = null

    override fun tests() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_tests
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_total : vx_core.Type_int? = null

    override fun total() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_total
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":pct")) {
        output = this.pct()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      } else if ((skey==":tests")) {
        output = this.tests()
      } else if ((skey==":total")) {
        output = this.total()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":pct", this.pct())
      map.put(":testpkg", this.testpkg())
      map.put(":tests", this.tests())
      map.put(":total", this.total())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragenums = vx_core.vx_copy(vx_test.e_testcoveragenums, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragenums = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testcoveragenums = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_pct : vx_core.Type_int = value.pct()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var vx_p_tests : vx_core.Type_int = value.tests()
      var vx_p_total : vx_core.Type_int = value.total()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":pct")
      validkeys.add(":testpkg")
      validkeys.add(":tests")
      validkeys.add(":total")
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
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":pct")) {
            if (valsub == vx_p_pct) {
            } else if (valsub is vx_core.Type_int) {
              var valpct : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_pct = valpct
            } else if (valsub is Int) {
              ischanged = true
              vx_p_pct = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("pct"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":tests")) {
            if (valsub == vx_p_tests) {
            } else if (valsub is vx_core.Type_int) {
              var valtests : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_tests = valtests
            } else if (valsub is Int) {
              ischanged = true
              vx_p_tests = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("tests"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":total")) {
            if (valsub == vx_p_total) {
            } else if (valsub is vx_core.Type_int) {
              var valtotal : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_total = valtotal
            } else if (valsub is Int) {
              ischanged = true
              vx_p_total = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("total"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testcoveragenums = vx_test.Class_testcoveragenums()
        work.vx_p_pct = vx_p_pct
        work.vx_p_testpkg = vx_p_testpkg
        work.vx_p_tests = vx_p_tests
        work.vx_p_total = vx_p_total
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testcoveragenums
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testcoveragenums
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
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

  val e_testcoveragenums : vx_test.Type_testcoveragenums = vx_test.Class_testcoveragenums()
  val t_testcoveragenums : vx_test.Type_testcoveragenums = vx_test.Class_testcoveragenums()

  interface Type_testcoveragesummary : vx_core.Type_struct {
    fun bigospacenums() : vx_test.Type_testcoveragenums
    fun bigotimenums() : vx_test.Type_testcoveragenums
    fun constnums() : vx_test.Type_testcoveragenums
    fun docnums() : vx_test.Type_testcoveragenums
    fun funcnums() : vx_test.Type_testcoveragenums
    fun testpkg() : vx_core.Type_string
    fun totalnums() : vx_test.Type_testcoveragenums
    fun typenums() : vx_test.Type_testcoveragenums
  }

  class Class_testcoveragesummary : vx_core.Class_base, Type_testcoveragesummary {
    constructor() {}

    var vx_p_bigospacenums : vx_test.Type_testcoveragenums? = null

    override fun bigospacenums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_bigospacenums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_bigotimenums : vx_test.Type_testcoveragenums? = null

    override fun bigotimenums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_bigotimenums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_constnums : vx_test.Type_testcoveragenums? = null

    override fun constnums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_constnums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_docnums : vx_test.Type_testcoveragenums? = null

    override fun docnums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_docnums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_funcnums : vx_test.Type_testcoveragenums? = null

    override fun funcnums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_funcnums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_totalnums : vx_test.Type_testcoveragenums? = null

    override fun totalnums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_totalnums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_typenums : vx_test.Type_testcoveragenums? = null

    override fun typenums() : vx_test.Type_testcoveragenums {
      var output : vx_test.Type_testcoveragenums = vx_test.e_testcoveragenums
      var testnull : vx_test.Type_testcoveragenums? = vx_p_typenums
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":bigospacenums")) {
        output = this.bigospacenums()
      } else if ((skey==":bigotimenums")) {
        output = this.bigotimenums()
      } else if ((skey==":constnums")) {
        output = this.constnums()
      } else if ((skey==":docnums")) {
        output = this.docnums()
      } else if ((skey==":funcnums")) {
        output = this.funcnums()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      } else if ((skey==":totalnums")) {
        output = this.totalnums()
      } else if ((skey==":typenums")) {
        output = this.typenums()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":bigospacenums", this.bigospacenums())
      map.put(":bigotimenums", this.bigotimenums())
      map.put(":constnums", this.constnums())
      map.put(":docnums", this.docnums())
      map.put(":funcnums", this.funcnums())
      map.put(":testpkg", this.testpkg())
      map.put(":totalnums", this.totalnums())
      map.put(":typenums", this.typenums())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragesummary = vx_core.vx_copy(vx_test.e_testcoveragesummary, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testcoveragesummary = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testcoveragesummary = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_bigospacenums : vx_test.Type_testcoveragenums = value.bigospacenums()
      var vx_p_bigotimenums : vx_test.Type_testcoveragenums = value.bigotimenums()
      var vx_p_constnums : vx_test.Type_testcoveragenums = value.constnums()
      var vx_p_docnums : vx_test.Type_testcoveragenums = value.docnums()
      var vx_p_funcnums : vx_test.Type_testcoveragenums = value.funcnums()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var vx_p_totalnums : vx_test.Type_testcoveragenums = value.totalnums()
      var vx_p_typenums : vx_test.Type_testcoveragenums = value.typenums()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":bigospacenums")
      validkeys.add(":bigotimenums")
      validkeys.add(":constnums")
      validkeys.add(":docnums")
      validkeys.add(":funcnums")
      validkeys.add(":testpkg")
      validkeys.add(":totalnums")
      validkeys.add(":typenums")
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
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":bigospacenums")) {
            if (valsub == vx_p_bigospacenums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valbigospacenums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_bigospacenums = valbigospacenums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("bigospacenums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":bigotimenums")) {
            if (valsub == vx_p_bigotimenums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valbigotimenums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_bigotimenums = valbigotimenums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("bigotimenums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":constnums")) {
            if (valsub == vx_p_constnums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valconstnums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_constnums = valconstnums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("constnums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":docnums")) {
            if (valsub == vx_p_docnums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valdocnums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_docnums = valdocnums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("docnums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":funcnums")) {
            if (valsub == vx_p_funcnums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valfuncnums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_funcnums = valfuncnums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("funcnums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":totalnums")) {
            if (valsub == vx_p_totalnums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valtotalnums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_totalnums = valtotalnums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("totalnums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":typenums")) {
            if (valsub == vx_p_typenums) {
            } else if (valsub is vx_test.Type_testcoveragenums) {
              var valtypenums : vx_test.Type_testcoveragenums = valsub as vx_test.Type_testcoveragenums
              ischanged = true
              vx_p_typenums = valtypenums
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("typenums"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testcoveragesummary = vx_test.Class_testcoveragesummary()
        work.vx_p_bigospacenums = vx_p_bigospacenums
        work.vx_p_bigotimenums = vx_p_bigotimenums
        work.vx_p_constnums = vx_p_constnums
        work.vx_p_docnums = vx_p_docnums
        work.vx_p_funcnums = vx_p_funcnums
        work.vx_p_testpkg = vx_p_testpkg
        work.vx_p_totalnums = vx_p_totalnums
        work.vx_p_typenums = vx_p_typenums
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testcoveragesummary
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testcoveragesummary
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
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

  val e_testcoveragesummary : vx_test.Type_testcoveragesummary = vx_test.Class_testcoveragesummary()
  val t_testcoveragesummary : vx_test.Type_testcoveragesummary = vx_test.Class_testcoveragesummary()

  interface Type_testdescribe : vx_core.Type_struct {
    fun describename() : vx_core.Type_string
    fun testpkg() : vx_core.Type_string
    fun testresult() : vx_test.Type_testresult
  }

  class Class_testdescribe : vx_core.Class_base, Type_testdescribe {
    constructor() {}

    var vx_p_describename : vx_core.Type_string? = null

    override fun describename() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_describename
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testresult : vx_test.Type_testresult? = null

    override fun testresult() : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.e_testresult
      var testnull : vx_test.Type_testresult? = vx_p_testresult
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":describename")) {
        output = this.describename()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      } else if ((skey==":testresult")) {
        output = this.testresult()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":describename", this.describename())
      map.put(":testpkg", this.testpkg())
      map.put(":testresult", this.testresult())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testdescribe = vx_core.vx_copy(vx_test.e_testdescribe, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testdescribe = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testdescribe = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_describename : vx_core.Type_string = value.describename()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var vx_p_testresult : vx_test.Type_testresult = value.testresult()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":describename")
      validkeys.add(":testpkg")
      validkeys.add(":testresult")
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
            msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":describename")) {
            if (valsub == vx_p_describename) {
            } else if (valsub is vx_core.Type_string) {
              var valdescribename : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_describename = valdescribename
            } else if (valsub is String) {
              ischanged = true
              vx_p_describename = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("describename"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testresult")) {
            if (valsub == vx_p_testresult) {
            } else if (valsub is vx_test.Type_testresult) {
              var valtestresult : vx_test.Type_testresult = valsub as vx_test.Type_testresult
              ischanged = true
              vx_p_testresult = valtestresult
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testresult"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testdescribe = vx_test.Class_testdescribe()
        work.vx_p_describename = vx_p_describename
        work.vx_p_testpkg = vx_p_testpkg
        work.vx_p_testresult = vx_p_testresult
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testdescribe
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testdescribe
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
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

  val e_testdescribe : vx_test.Type_testdescribe = vx_test.Class_testdescribe()
  val t_testdescribe : vx_test.Type_testdescribe = vx_test.Class_testdescribe()

  interface Type_testdescribelist : vx_core.Type_list {
    fun vx_listtestdescribe() : List<vx_test.Type_testdescribe>
    fun vx_testdescribe(index : vx_core.Type_int) : vx_test.Type_testdescribe
  }

  class Class_testdescribelist : vx_core.Class_base, Type_testdescribelist {
    constructor() {}

    var vx_p_list : List<vx_test.Type_testdescribe> = vx_core.immutablelist(
      ArrayList<vx_test.Type_testdescribe>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_testdescribe(index : vx_core.Type_int) : vx_test.Type_testdescribe {
      var output : vx_test.Type_testdescribe = vx_test.e_testdescribe
      var list : vx_test.Class_testdescribelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_test.Type_testdescribe> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtestdescribe() : List<vx_test.Type_testdescribe> {
      var output : List<vx_test.Type_testdescribe> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_test.Type_testdescribe = this.vx_testdescribe(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testdescribelist = vx_core.vx_copy(vx_test.e_testdescribelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testdescribelist = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testdescribelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_test.Type_testdescribe> = ArrayList<vx_test.Type_testdescribe>(value.vx_listtestdescribe())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_test.Type_testdescribelist) {
          var multi : vx_test.Type_testdescribelist = valsub as vx_test.Type_testdescribelist
          ischanged = true
          listval.addAll(multi.vx_listtestdescribe())
        } else if (valsub is vx_test.Type_testdescribe) {
          var allowsub : vx_test.Type_testdescribe = valsub as vx_test.Type_testdescribe
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_test.Type_testdescribe) {
          ischanged = true
          listval.add(valsub as vx_test.Type_testdescribe)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_test.Type_testdescribe) {
              var valitem : vx_test.Type_testdescribe = item as vx_test.Type_testdescribe
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testdescribelist = vx_test.Class_testdescribelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testdescribelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testdescribelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_test.t_testdescribe), // allowtypes
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

  val e_testdescribelist : vx_test.Type_testdescribelist = vx_test.Class_testdescribelist()
  val t_testdescribelist : vx_test.Type_testdescribelist = vx_test.Class_testdescribelist()

  interface Type_testpackage : vx_core.Type_struct {
    fun caselist() : vx_test.Type_testcaselist
    fun coveragedetail() : vx_test.Type_testcoveragedetail
    fun coveragesummary() : vx_test.Type_testcoveragesummary
    fun passfail() : vx_core.Type_boolean
    fun testpkg() : vx_core.Type_string
  }

  class Class_testpackage : vx_core.Class_base, Type_testpackage {
    constructor() {}

    var vx_p_caselist : vx_test.Type_testcaselist? = null

    override fun caselist() : vx_test.Type_testcaselist {
      var output : vx_test.Type_testcaselist = vx_test.e_testcaselist
      var testnull : vx_test.Type_testcaselist? = vx_p_caselist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_coveragedetail : vx_test.Type_testcoveragedetail? = null

    override fun coveragedetail() : vx_test.Type_testcoveragedetail {
      var output : vx_test.Type_testcoveragedetail = vx_test.e_testcoveragedetail
      var testnull : vx_test.Type_testcoveragedetail? = vx_p_coveragedetail
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_coveragesummary : vx_test.Type_testcoveragesummary? = null

    override fun coveragesummary() : vx_test.Type_testcoveragesummary {
      var output : vx_test.Type_testcoveragesummary = vx_test.e_testcoveragesummary
      var testnull : vx_test.Type_testcoveragesummary? = vx_p_coveragesummary
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_passfail : vx_core.Type_boolean? = null

    override fun passfail() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_passfail
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_testpkg : vx_core.Type_string? = null

    override fun testpkg() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_testpkg
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":caselist")) {
        output = this.caselist()
      } else if ((skey==":coveragedetail")) {
        output = this.coveragedetail()
      } else if ((skey==":coveragesummary")) {
        output = this.coveragesummary()
      } else if ((skey==":passfail")) {
        output = this.passfail()
      } else if ((skey==":testpkg")) {
        output = this.testpkg()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":caselist", this.caselist())
      map.put(":coveragedetail", this.coveragedetail())
      map.put(":coveragesummary", this.coveragesummary())
      map.put(":passfail", this.passfail())
      map.put(":testpkg", this.testpkg())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testpackage = vx_core.vx_copy(vx_test.e_testpackage, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testpackage = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testpackage = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_caselist : vx_test.Type_testcaselist = value.caselist()
      var vx_p_coveragedetail : vx_test.Type_testcoveragedetail = value.coveragedetail()
      var vx_p_coveragesummary : vx_test.Type_testcoveragesummary = value.coveragesummary()
      var vx_p_passfail : vx_core.Type_boolean = value.passfail()
      var vx_p_testpkg : vx_core.Type_string = value.testpkg()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":caselist")
      validkeys.add(":coveragedetail")
      validkeys.add(":coveragesummary")
      validkeys.add(":passfail")
      validkeys.add(":testpkg")
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
            msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":caselist")) {
            if (valsub == vx_p_caselist) {
            } else if (valsub is vx_test.Type_testcaselist) {
              var valcaselist : vx_test.Type_testcaselist = valsub as vx_test.Type_testcaselist
              ischanged = true
              vx_p_caselist = valcaselist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("caselist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":coveragedetail")) {
            if (valsub == vx_p_coveragedetail) {
            } else if (valsub is vx_test.Type_testcoveragedetail) {
              var valcoveragedetail : vx_test.Type_testcoveragedetail = valsub as vx_test.Type_testcoveragedetail
              ischanged = true
              vx_p_coveragedetail = valcoveragedetail
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("coveragedetail"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":coveragesummary")) {
            if (valsub == vx_p_coveragesummary) {
            } else if (valsub is vx_test.Type_testcoveragesummary) {
              var valcoveragesummary : vx_test.Type_testcoveragesummary = valsub as vx_test.Type_testcoveragesummary
              ischanged = true
              vx_p_coveragesummary = valcoveragesummary
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("coveragesummary"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":passfail")) {
            if (valsub == vx_p_passfail) {
            } else if (valsub is vx_core.Type_boolean) {
              var valpassfail : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_passfail = valpassfail
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_passfail = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("passfail"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":testpkg")) {
            if (valsub == vx_p_testpkg) {
            } else if (valsub is vx_core.Type_string) {
              var valtestpkg : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_testpkg = valtestpkg
            } else if (valsub is String) {
              ischanged = true
              vx_p_testpkg = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("testpkg"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testpackage = vx_test.Class_testpackage()
        work.vx_p_caselist = vx_p_caselist
        work.vx_p_coveragedetail = vx_p_coveragedetail
        work.vx_p_coveragesummary = vx_p_coveragesummary
        work.vx_p_passfail = vx_p_passfail
        work.vx_p_testpkg = vx_p_testpkg
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testpackage
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testpackage
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
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

  val e_testpackage : vx_test.Type_testpackage = vx_test.Class_testpackage()
  val t_testpackage : vx_test.Type_testpackage = vx_test.Class_testpackage()

  interface Type_testpackagelist : vx_core.Type_list {
    fun vx_listtestpackage() : List<vx_test.Type_testpackage>
    fun vx_testpackage(index : vx_core.Type_int) : vx_test.Type_testpackage
  }

  class Class_testpackagelist : vx_core.Class_base, Type_testpackagelist {
    constructor() {}

    var vx_p_list : List<vx_test.Type_testpackage> = vx_core.immutablelist(
      ArrayList<vx_test.Type_testpackage>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_testpackage(index : vx_core.Type_int) : vx_test.Type_testpackage {
      var output : vx_test.Type_testpackage = vx_test.e_testpackage
      var list : vx_test.Class_testpackagelist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_test.Type_testpackage> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtestpackage() : List<vx_test.Type_testpackage> {
      var output : List<vx_test.Type_testpackage> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_test.Type_testpackage = this.vx_testpackage(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testpackagelist = vx_core.vx_copy(vx_test.e_testpackagelist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testpackagelist = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testpackagelist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_test.Type_testpackage> = ArrayList<vx_test.Type_testpackage>(value.vx_listtestpackage())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_test.Type_testpackagelist) {
          var multi : vx_test.Type_testpackagelist = valsub as vx_test.Type_testpackagelist
          ischanged = true
          listval.addAll(multi.vx_listtestpackage())
        } else if (valsub is vx_test.Type_testpackage) {
          var allowsub : vx_test.Type_testpackage = valsub as vx_test.Type_testpackage
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_test.Type_testpackage) {
          ischanged = true
          listval.add(valsub as vx_test.Type_testpackage)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_test.Type_testpackage) {
              var valitem : vx_test.Type_testpackage = item as vx_test.Type_testpackage
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testpackagelist = vx_test.Class_testpackagelist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testpackagelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testpackagelist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_test.t_testpackage), // allowtypes
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

  val e_testpackagelist : vx_test.Type_testpackagelist = vx_test.Class_testpackagelist()
  val t_testpackagelist : vx_test.Type_testpackagelist = vx_test.Class_testpackagelist()

  interface Type_testresult : vx_core.Type_struct {
    fun code() : vx_core.Type_string
    fun passfail() : vx_core.Type_boolean
    fun expected() : vx_core.Type_any
    fun actual() : vx_core.Type_any
    fun fn_actual() : vx_core.Func_any_from_func_async
  }

  class Class_testresult : vx_core.Class_base, Type_testresult {
    constructor() {}

    var vx_p_code : vx_core.Type_string? = null

    override fun code() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_code
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_passfail : vx_core.Type_boolean? = null

    override fun passfail() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_passfail
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_expected : vx_core.Type_any? = null

    override fun expected() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_expected
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_actual : vx_core.Type_any? = null

    override fun actual() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testnull : vx_core.Type_any? = vx_p_actual
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_fn_actual : vx_core.Func_any_from_func_async? = null

    override fun fn_actual() : vx_core.Func_any_from_func_async {
      var output : vx_core.Func_any_from_func_async = vx_core.e_any_from_func_async
      var testnull : vx_core.Func_any_from_func_async? = vx_p_fn_actual
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":code")) {
        output = this.code()
      } else if ((skey==":passfail")) {
        output = this.passfail()
      } else if ((skey==":expected")) {
        output = this.expected()
      } else if ((skey==":actual")) {
        output = this.actual()
      } else if ((skey==":fn-actual")) {
        output = this.fn_actual()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":code", this.code())
      map.put(":passfail", this.passfail())
      map.put(":expected", this.expected())
      map.put(":actual", this.actual())
      map.put(":fn-actual", this.fn_actual())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testresult = vx_core.vx_copy(vx_test.e_testresult, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testresult = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testresult = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_code : vx_core.Type_string = value.code()
      var vx_p_passfail : vx_core.Type_boolean = value.passfail()
      var vx_p_expected : vx_core.Type_any = value.expected()
      var vx_p_actual : vx_core.Type_any = value.actual()
      var vx_p_fn_actual : vx_core.Func_any_from_func_async = value.fn_actual()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":code")
      validkeys.add(":passfail")
      validkeys.add(":expected")
      validkeys.add(":actual")
      validkeys.add(":fn-actual")
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
            msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":code")) {
            if (valsub == vx_p_code) {
            } else if (valsub is vx_core.Type_string) {
              var valcode : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_code = valcode
            } else if (valsub is String) {
              ischanged = true
              vx_p_code = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("code"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":passfail")) {
            if (valsub == vx_p_passfail) {
            } else if (valsub is vx_core.Type_boolean) {
              var valpassfail : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_passfail = valpassfail
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_passfail = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("passfail"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":expected")) {
            if (valsub == vx_p_expected) {
            } else if (valsub is vx_core.Type_any) {
              var valexpected : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_expected = valexpected
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("expected"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":actual")) {
            if (valsub == vx_p_actual) {
            } else if (valsub is vx_core.Type_any) {
              var valactual : vx_core.Type_any = valsub as vx_core.Type_any
              ischanged = true
              vx_p_actual = valactual
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("actual"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":fn-actual")) {
            if (valsub == vx_p_fn_actual) {
            } else if (valsub is vx_core.Func_any_from_func_async) {
              var valfn_actual : vx_core.Func_any_from_func_async = valsub as vx_core.Func_any_from_func_async
              ischanged = true
              vx_p_fn_actual = valfn_actual
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("fn-actual"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testresult = vx_test.Class_testresult()
        work.vx_p_code = vx_p_code
        work.vx_p_passfail = vx_p_passfail
        work.vx_p_expected = vx_p_expected
        work.vx_p_actual = vx_p_actual
        work.vx_p_fn_actual = vx_p_fn_actual
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testresult
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testresult
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testresult", // name
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

  val e_testresult : vx_test.Type_testresult = vx_test.Class_testresult()
  val t_testresult : vx_test.Type_testresult = vx_test.Class_testresult()

  interface Type_testresultlist : vx_core.Type_list {
    fun vx_listtestresult() : List<vx_test.Type_testresult>
    fun vx_testresult(index : vx_core.Type_int) : vx_test.Type_testresult
  }

  class Class_testresultlist : vx_core.Class_base, Type_testresultlist {
    constructor() {}

    var vx_p_list : List<vx_test.Type_testresult> = vx_core.immutablelist(
      ArrayList<vx_test.Type_testresult>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_testresult(index : vx_core.Type_int) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.e_testresult
      var list : vx_test.Class_testresultlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_test.Type_testresult> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listtestresult() : List<vx_test.Type_testresult> {
      var output : List<vx_test.Type_testresult> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_test.Type_testresult = this.vx_testresult(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testresultlist = vx_core.vx_copy(vx_test.e_testresultlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_test.Type_testresultlist = this
      var ischanged : Boolean = false
      var value : vx_test.Class_testresultlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_test.Type_testresult> = ArrayList<vx_test.Type_testresult>(value.vx_listtestresult())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_test.Type_testresultlist) {
          var multi : vx_test.Type_testresultlist = valsub as vx_test.Type_testresultlist
          ischanged = true
          listval.addAll(multi.vx_listtestresult())
        } else if (valsub is vx_test.Type_testresult) {
          var allowsub : vx_test.Type_testresult = valsub as vx_test.Type_testresult
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_test.Type_testresult) {
          ischanged = true
          listval.add(valsub as vx_test.Type_testresult)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_test.Type_testresult) {
              var valitem : vx_test.Type_testresult = item as vx_test.Type_testresult
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_test.Class_testresultlist = vx_test.Class_testresultlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_testresultlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_testresultlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_test.t_testresult), // allowtypes
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

  val e_testresultlist : vx_test.Type_testresultlist = vx_test.Class_testresultlist()
  val t_testresultlist : vx_test.Type_testresultlist = vx_test.Class_testresultlist()

  class Const_stylesheet_test {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
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
        )
      )
      return output
    }

    fun const_new(output : vx_web_html.Type_stylesheet) : Unit {
      var outval : vx_web_html.Class_stylesheet = output as vx_web_html.Class_stylesheet
      outval.vx_p_constdef = constdef()
      var value : vx_web_html.Type_stylesheet = vx_web_html.f_stylesheet_loadmap(
        vx_core.f_new(
          vx_web_html.t_stylesheet,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("Test Suite"),
            vx_core.vx_new_string(":styles"),
            vx_core.f_new(
              vx_web_html.t_stylelist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("body"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("font-size"),
                        vx_core.vx_new_string("0.9em"),
                        vx_core.vx_new_string("font-family"),
                        vx_core.vx_new_string("sans-serif")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("details summary"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("cursor"),
                        vx_core.vx_new_string("pointer"),
                        vx_core.vx_new_string("display"),
                        vx_core.vx_new_string("inline-flex"),
                        vx_core.vx_new_string("gap"),
                        vx_core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("table"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("vertical-align"),
                        vx_core.vx_new_string("top"),
                        vx_core.vx_new_string("border-collapse"),
                        vx_core.vx_new_string("collapse"),
                        vx_core.vx_new_string("margin"),
                        vx_core.vx_new_string("25px 0"),
                        vx_core.vx_new_string("min-width"),
                        vx_core.vx_new_string("400px"),
                        vx_core.vx_new_string("box-shadow"),
                        vx_core.vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("thead tr"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("#009879"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("#ffffff"),
                        vx_core.vx_new_string("text-align"),
                        vx_core.vx_new_string("left")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("td"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("padding"),
                        vx_core.vx_new_string("10px 10px"),
                        vx_core.vx_new_string("vertical-align"),
                        vx_core.vx_new_string("top")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("tbody tr"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("border-bottom"),
                        vx_core.vx_new_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("tbody tr:nth-of-type(even)"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("#f3f3f3")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("tbody tr:last-of-type"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("border-bottom"),
                        vx_core.vx_new_string("2px solid #009879")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string("tbody tr.active-row"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("font-weight"),
                        vx_core.vx_new_string("bold"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("#009879")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".failflag"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("red"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("white"),
                        vx_core.vx_new_string("padding-left"),
                        vx_core.vx_new_string("4px"),
                        vx_core.vx_new_string("padding-right"),
                        vx_core.vx_new_string("4px"),
                        vx_core.vx_new_string("padding-top"),
                        vx_core.vx_new_string("1px"),
                        vx_core.vx_new_string("padding-bottom"),
                        vx_core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".passflag"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("green"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("white"),
                        vx_core.vx_new_string("padding-left"),
                        vx_core.vx_new_string("4px"),
                        vx_core.vx_new_string("padding-right"),
                        vx_core.vx_new_string("4px"),
                        vx_core.vx_new_string("padding-top"),
                        vx_core.vx_new_string("1px"),
                        vx_core.vx_new_string("padding-bottom"),
                        vx_core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".coveragenums"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("width"),
                        vx_core.vx_new_string("90px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".coveragepct"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("text-align"),
                        vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".coveragepctgreen"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("green"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("white"),
                        vx_core.vx_new_string("text-align"),
                        vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".coveragepctred"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("background-color"),
                        vx_core.vx_new_string("red"),
                        vx_core.vx_new_string("color"),
                        vx_core.vx_new_string("white"),
                        vx_core.vx_new_string("text-align"),
                        vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".pkgheader"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("display"),
                        vx_core.vx_new_string("inline-flex"),
                        vx_core.vx_new_string("gap"),
                        vx_core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".pkgname"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("font-weight"),
                        vx_core.vx_new_string("bold"),
                        vx_core.vx_new_string("width"),
                        vx_core.vx_new_string("180px")
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_style,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":name"),
                    vx_core.vx_new_string(".preformatted"),
                    vx_core.vx_new_string(":props"),
                    vx_core.f_new(
                      vx_web_html.t_propmap,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string("display"),
                        vx_core.vx_new_string("block"),
                        vx_core.vx_new_string("unicode-bidi"),
                        vx_core.vx_new_string("embed"),
                        vx_core.vx_new_string("font-family"),
                        vx_core.vx_new_string("monospace"),
                        vx_core.vx_new_string("white-space"),
                        vx_core.vx_new_string("pre")
                      )
                    )
                  )
                )
              )
            )
          )
        )
      )
      outval.vx_p_id = value.id()
      outval.vx_p_eventmap = value.eventmap()
      outval.vx_p_style = value.style()
      outval.vx_p_style_unique = value.style_unique()
      outval.vx_p_stylelist = value.stylelist()
      outval.vx_p_name = value.name()
      outval.vx_p_styles = value.styles()
      outval.vx_p_stylemap = value.stylemap()
    }

    }
  }

  val c_stylesheet_test : vx_web_html.Type_stylesheet = vx_web_html.Class_stylesheet()


  interface Func_context_test : vx_core.Func_any_from_any {
    fun vx_context_test(args : vx_core.Type_anylist) : vx_core.Type_context
  }

  class Class_context_test : vx_core.Class_base, Func_context_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_context_test = vx_test.Class_context_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_context_test = vx_test.Class_context_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      var output : vx_core.Type_any = vx_test.e_context_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_context_test
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_anylist = value as vx_core.Type_anylist
      var outputval : vx_core.Type_any = vx_test.f_context_test(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var args : vx_core.Type_anylist = vx_core.f_any_from_any(vx_core.t_anylist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_context_test(args)
      return output
    }

    override fun vx_context_test(args : vx_core.Type_anylist) : vx_core.Type_context {
      var output : vx_core.Type_context = vx_test.f_context_test(args)
      return output
    }

  }

  val e_context_test : vx_test.Func_context_test = vx_test.Class_context_test()
  val t_context_test : vx_test.Func_context_test = vx_test.Class_context_test()

  fun f_context_test(args : vx_core.Type_anylist) : vx_core.Type_context {
    var output : vx_core.Type_context = vx_core.e_context
    output = vx_core.f_new(
      vx_core.t_context,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":session"),
        vx_core.f_new(
          vx_core.t_session,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":user"),
            vx_core.f_new(
              vx_core.t_user,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":security"),
                vx_test.f_security_test()
              )
            )
          )
        )
      )
    )
    return output
  }


  interface Func_div_from_testcaselist : vx_core.Func_any_from_any {
    fun vx_div_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_div
  }

  class Class_div_from_testcaselist : vx_core.Class_base, Func_div_from_testcaselist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testcaselist = vx_test.Class_div_from_testcaselist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testcaselist = vx_test.Class_div_from_testcaselist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_div_from_testcaselist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_div_from_testcaselist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testcaselist = value as vx_test.Type_testcaselist
      var outputval : vx_core.Type_any = vx_test.f_div_from_testcaselist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testcaselist : vx_test.Type_testcaselist = vx_core.f_any_from_any(vx_test.t_testcaselist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_div_from_testcaselist(testcaselist)
      return output
    }

    override fun vx_div_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_div {
      var output : vx_web_html.Type_div = vx_test.f_div_from_testcaselist(testcaselist)
      return output
    }

  }

  val e_div_from_testcaselist : vx_test.Func_div_from_testcaselist = vx_test.Class_div_from_testcaselist()
  val t_div_from_testcaselist : vx_test.Func_div_from_testcaselist = vx_test.Class_div_from_testcaselist()

  fun f_div_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_div {
    var output : vx_web_html.Type_div = vx_web_html.e_div
    output = vx_core.f_new(
      vx_web_html.t_div,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.f_new(
          vx_web_html.t_table,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":thead"),
            vx_core.f_new(
              vx_web_html.t_thead,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_tr,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.f_new(
                      vx_web_html.t_td,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_web_html.t_p,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("Pass?")
                          )
                        )
                      )
                    ),
                    vx_core.f_new(
                      vx_web_html.t_td,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_web_html.t_p,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("Name")
                          )
                        )
                      )
                    ),
                    vx_core.f_new(
                      vx_web_html.t_td,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_web_html.t_p,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("Test")
                          )
                        )
                      )
                    ),
                    vx_core.f_new(
                      vx_web_html.t_td,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_web_html.t_p,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("Expected")
                          )
                        )
                      )
                    ),
                    vx_core.f_new(
                      vx_web_html.t_td,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_web_html.t_p,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            vx_core.vx_new_string(":tbody"),
            vx_core.f_new(
              vx_web_html.t_tbody,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_test.f_trlist_from_testcaselist(
                  testcaselist
                )
              )
            )
          )
        )
      )
    )
    return output
  }


  interface Func_div_from_testpackage : vx_core.Func_any_from_any {
    fun vx_div_from_testpackage(testpackage : vx_test.Type_testpackage) : vx_web_html.Type_div
  }

  class Class_div_from_testpackage : vx_core.Class_base, Func_div_from_testpackage {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testpackage = vx_test.Class_div_from_testpackage()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testpackage = vx_test.Class_div_from_testpackage()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_div_from_testpackage
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_div_from_testpackage
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testpackage = value as vx_test.Type_testpackage
      var outputval : vx_core.Type_any = vx_test.f_div_from_testpackage(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testpackage : vx_test.Type_testpackage = vx_core.f_any_from_any(vx_test.t_testpackage, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_div_from_testpackage(testpackage)
      return output
    }

    override fun vx_div_from_testpackage(testpackage : vx_test.Type_testpackage) : vx_web_html.Type_div {
      var output : vx_web_html.Type_div = vx_test.f_div_from_testpackage(testpackage)
      return output
    }

  }

  val e_div_from_testpackage : vx_test.Func_div_from_testpackage = vx_test.Class_div_from_testpackage()
  val t_div_from_testpackage : vx_test.Func_div_from_testpackage = vx_test.Class_div_from_testpackage()

  fun f_div_from_testpackage(testpackage : vx_test.Type_testpackage) : vx_web_html.Type_div {
    var output : vx_web_html.Type_div = vx_web_html.e_div
    output = vx_core.f_let(
      vx_web_html.t_div,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var testcoveragesummary : vx_test.Type_testcoveragesummary = testpackage.coveragesummary()
        var pkgname : vx_core.Type_string = testpackage.testpkg()
        var caselist : vx_test.Type_testcaselist = testpackage.caselist()
        var passfail : vx_core.Type_boolean = testpackage.passfail()
        var pkgnamestyle : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".pkgname")
        )
        var node : vx_web_html.Type_div = vx_test.f_div_from_testcaselist(
          caselist
        )
        var nodes : vx_web_html.Type_divchildlist = vx_core.f_new(
          vx_web_html.t_divchildlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            node
          )
        )
        var p_passfail : vx_web_html.Type_p = vx_test.f_p_from_passfail(
          passfail
        )
        var p_pkgname : vx_web_html.Type_p = vx_core.f_new(
          vx_web_html.t_p,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":style"),
            pkgnamestyle,
            vx_core.vx_new_string(":text"),
            pkgname
          )
        )
        var p_totalnums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.totalnums()
        )
        var p_coveragenums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.typenums()
        )
        var p_constnums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.constnums()
        )
        var p_funcnums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.funcnums()
        )
        var p_docnums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.docnums()
        )
        var p_bigospacenums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.bigospacenums()
        )
        var p_bigotimenums : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.bigotimenums()
        )
        var summary : vx_web_html.Type_divchildlist = vx_core.f_new(
          vx_web_html.t_divchildlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            p_passfail,
            p_pkgname,
            p_totalnums,
            p_coveragenums,
            p_constnums,
            p_funcnums,
            p_docnums,
            p_bigospacenums,
            p_bigotimenums
          )
        )
        var details : vx_web_html.Type_details = vx_core.f_new(
          vx_web_html.t_details,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":summary"),
            summary,
            vx_core.vx_new_string(":nodes"),
            nodes
          )
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_div,
          vx_core.vx_new(
            vx_core.t_anylist,
            details
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_div_from_testpackagelist : vx_core.Func_any_from_any {
    fun vx_div_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_div
  }

  class Class_div_from_testpackagelist : vx_core.Class_base, Func_div_from_testpackagelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testpackagelist = vx_test.Class_div_from_testpackagelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_div_from_testpackagelist = vx_test.Class_div_from_testpackagelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_div_from_testpackagelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_div_from_testpackagelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testpackagelist = value as vx_test.Type_testpackagelist
      var outputval : vx_core.Type_any = vx_test.f_div_from_testpackagelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testpackagelist : vx_test.Type_testpackagelist = vx_core.f_any_from_any(vx_test.t_testpackagelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_div_from_testpackagelist(testpackagelist)
      return output
    }

    override fun vx_div_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_div {
      var output : vx_web_html.Type_div = vx_test.f_div_from_testpackagelist(testpackagelist)
      return output
    }

  }

  val e_div_from_testpackagelist : vx_test.Func_div_from_testpackagelist = vx_test.Class_div_from_testpackagelist()
  val t_div_from_testpackagelist : vx_test.Func_div_from_testpackagelist = vx_test.Class_div_from_testpackagelist()

  fun f_div_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_div {
    var output : vx_web_html.Type_div = vx_web_html.e_div
    output = vx_core.f_let(
      vx_web_html.t_div,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var stylepassfail : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".passfail")
        )
        var stylepkgname : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".pkgname")
        )
        var stylepkgheader : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".pkgheader")
        )
        var stylecoveragenum : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".coveragenums")
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_div,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.f_new(
              vx_web_html.t_div,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":style"),
                stylepkgheader,
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylepassfail,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("Pass?")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylepkgname,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("Package Name")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("Coverage")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("(type)")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("(const)")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("(func)")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string(":doc")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string(":bigospace")
                  )
                ),
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string(":bigotime")
                  )
                )
              )
            ),
            vx_core.f_new(
              vx_web_html.t_div,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_test.f_divchildlist_from_testpackagelist(
                  testpackagelist
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


  interface Func_divchildlist_from_testpackagelist : vx_core.Func_any_from_any {
    fun vx_divchildlist_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_divchildlist
  }

  class Class_divchildlist_from_testpackagelist : vx_core.Class_base, Func_divchildlist_from_testpackagelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_divchildlist_from_testpackagelist = vx_test.Class_divchildlist_from_testpackagelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_divchildlist_from_testpackagelist = vx_test.Class_divchildlist_from_testpackagelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_divchildlist_from_testpackagelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_divchildlist_from_testpackagelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testpackagelist = value as vx_test.Type_testpackagelist
      var outputval : vx_core.Type_any = vx_test.f_divchildlist_from_testpackagelist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testpackagelist : vx_test.Type_testpackagelist = vx_core.f_any_from_any(vx_test.t_testpackagelist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_divchildlist_from_testpackagelist(testpackagelist)
      return output
    }

    override fun vx_divchildlist_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_divchildlist {
      var output : vx_web_html.Type_divchildlist = vx_test.f_divchildlist_from_testpackagelist(testpackagelist)
      return output
    }

  }

  val e_divchildlist_from_testpackagelist : vx_test.Func_divchildlist_from_testpackagelist = vx_test.Class_divchildlist_from_testpackagelist()
  val t_divchildlist_from_testpackagelist : vx_test.Func_divchildlist_from_testpackagelist = vx_test.Class_divchildlist_from_testpackagelist()

  fun f_divchildlist_from_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : vx_web_html.Type_divchildlist {
    var output : vx_web_html.Type_divchildlist = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_list_1(
      vx_web_html.t_divchildlist,
      testpackagelist,
      vx_test.t_div_from_testpackage
    )
    return output
  }


  interface Func_file_test : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_file_test() : vx_data_file.Type_file
  }

  class Class_file_test : vx_core.Class_base, Func_file_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_test = vx_test.Class_file_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_test = vx_test.Class_file_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
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
      var output : vx_core.Type_any = vx_test.e_file_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_file_test
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_test.f_file_test()
      return output
    }

    override fun vx_file_test() : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_test.f_file_test()
      return output
    }

  }

  val e_file_test : vx_test.Func_file_test = vx_test.Class_file_test()
  val t_file_test : vx_test.Func_file_test = vx_test.Class_file_test()

  fun f_file_test() : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_data_file.e_file
    output = vx_core.f_new(
      vx_data_file.t_file,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":name"),
        vx_core.vx_new_string("testsuite.vxlisp"),
        vx_core.vx_new_string(":path"),
        vx_core.c_path_test_resources
      )
    )
    return output
  }


  interface Func_file_testhtml : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_file_testhtml() : vx_data_file.Type_file
  }

  class Class_file_testhtml : vx_core.Class_base, Func_file_testhtml {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_testhtml = vx_test.Class_file_testhtml()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_testhtml = vx_test.Class_file_testhtml()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
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
      var output : vx_core.Type_any = vx_test.e_file_testhtml
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_file_testhtml
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_test.f_file_testhtml()
      return output
    }

    override fun vx_file_testhtml() : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_test.f_file_testhtml()
      return output
    }

  }

  val e_file_testhtml : vx_test.Func_file_testhtml = vx_test.Class_file_testhtml()
  val t_file_testhtml : vx_test.Func_file_testhtml = vx_test.Class_file_testhtml()

  fun f_file_testhtml() : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_data_file.e_file
    output = vx_core.f_new(
      vx_data_file.t_file,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":name"),
        vx_core.vx_new_string("testsuite.html"),
        vx_core.vx_new_string(":path"),
        vx_core.c_path_test_resources
      )
    )
    return output
  }


  interface Func_file_testnode : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_file_testnode() : vx_data_file.Type_file
  }

  class Class_file_testnode : vx_core.Class_base, Func_file_testnode {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_testnode = vx_test.Class_file_testnode()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_file_testnode = vx_test.Class_file_testnode()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
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
      var output : vx_core.Type_any = vx_test.e_file_testnode
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_file_testnode
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_test.f_file_testnode()
      return output
    }

    override fun vx_file_testnode() : vx_data_file.Type_file {
      var output : vx_data_file.Type_file = vx_test.f_file_testnode()
      return output
    }

  }

  val e_file_testnode : vx_test.Func_file_testnode = vx_test.Class_file_testnode()
  val t_file_testnode : vx_test.Func_file_testnode = vx_test.Class_file_testnode()

  fun f_file_testnode() : vx_data_file.Type_file {
    var output : vx_data_file.Type_file = vx_data_file.e_file
    output = vx_core.f_new(
      vx_data_file.t_file,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":name"),
        vx_core.vx_new_string("testsuitenode.vxlisp"),
        vx_core.vx_new_string(":path"),
        vx_core.c_path_test_resources
      )
    )
    return output
  }


  interface Func_html_from_divtest : vx_core.Func_any_from_any {
    fun vx_html_from_divtest(divtest : vx_web_html.Type_div) : vx_web_html.Type_html
  }

  class Class_html_from_divtest : vx_core.Class_base, Func_html_from_divtest {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_html_from_divtest = vx_test.Class_html_from_divtest()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_html_from_divtest = vx_test.Class_html_from_divtest()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_html_from_divtest
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_html_from_divtest
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_html.Type_div = value as vx_web_html.Type_div
      var outputval : vx_core.Type_any = vx_test.f_html_from_divtest(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var divtest : vx_web_html.Type_div = vx_core.f_any_from_any(vx_web_html.t_div, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_html_from_divtest(divtest)
      return output
    }

    override fun vx_html_from_divtest(divtest : vx_web_html.Type_div) : vx_web_html.Type_html {
      var output : vx_web_html.Type_html = vx_test.f_html_from_divtest(divtest)
      return output
    }

  }

  val e_html_from_divtest : vx_test.Func_html_from_divtest = vx_test.Class_html_from_divtest()
  val t_html_from_divtest : vx_test.Func_html_from_divtest = vx_test.Class_html_from_divtest()

  fun f_html_from_divtest(divtest : vx_web_html.Type_div) : vx_web_html.Type_html {
    var output : vx_web_html.Type_html = vx_web_html.e_html
    output = vx_core.f_new(
      vx_web_html.t_html,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":lang"),
        vx_core.vx_new_string("en"),
        vx_core.vx_new_string(":head"),
        vx_core.f_new(
          vx_web_html.t_head,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.f_new(
              vx_web_html.t_meta,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":charset"),
                vx_core.vx_new_string("utf-8")
              )
            ),
            vx_core.f_new(
              vx_web_html.t_meta,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":name"),
                vx_core.vx_new_string("viewport"),
                vx_core.vx_new_string(":content"),
                vx_core.vx_new_string("width=device-width, initial-scale=1.0")
              )
            ),
            vx_core.f_new(
              vx_web_html.t_title,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":text"),
                vx_core.vx_new_string("Test Suite")
              )
            ),
            vx_test.c_stylesheet_test
          )
        ),
        vx_core.vx_new_string(":body"),
        vx_core.f_new(
          vx_web_html.t_body,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.f_new(
              vx_web_html.t_div,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_h1,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string("Test Suite")
                  )
                )
              )
            ),
            divtest
          )
        )
      )
    )
    return output
  }


  interface Func_p_from_passfail : vx_core.Func_any_from_any {
    fun vx_p_from_passfail(passfail : vx_core.Type_boolean) : vx_web_html.Type_p
  }

  class Class_p_from_passfail : vx_core.Class_base, Func_p_from_passfail {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_p_from_passfail = vx_test.Class_p_from_passfail()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_p_from_passfail = vx_test.Class_p_from_passfail()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_p_from_passfail
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_p_from_passfail
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_boolean = value as vx_core.Type_boolean
      var outputval : vx_core.Type_any = vx_test.f_p_from_passfail(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var passfail : vx_core.Type_boolean = vx_core.f_any_from_any(vx_core.t_boolean, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_p_from_passfail(passfail)
      return output
    }

    override fun vx_p_from_passfail(passfail : vx_core.Type_boolean) : vx_web_html.Type_p {
      var output : vx_web_html.Type_p = vx_test.f_p_from_passfail(passfail)
      return output
    }

  }

  val e_p_from_passfail : vx_test.Func_p_from_passfail = vx_test.Class_p_from_passfail()
  val t_p_from_passfail : vx_test.Func_p_from_passfail = vx_test.Class_p_from_passfail()

  fun f_p_from_passfail(passfail : vx_core.Type_boolean) : vx_web_html.Type_p {
    var output : vx_web_html.Type_p = vx_web_html.e_p
    output = vx_core.f_let(
      vx_web_html.t_p,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var text : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          passfail,
          vx_core.vx_new_string("Pass"),
          vx_core.vx_new_string("Fail")
        )
        var stylename : vx_core.Type_string = vx_core.f_if_1(
          vx_core.t_string,
          passfail,
          vx_core.vx_new_string(".passflag"),
          vx_core.vx_new_string(".failflag")
        )
        var style : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          stylename
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_p,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":style"),
            style,
            vx_core.vx_new_string(":text"),
            text
          )
        )
        output_1
      })
    )
    return output
  }


  interface Func_p_from_testcoveragenums : vx_core.Func_any_from_any {
    fun vx_p_from_testcoveragenums(nums : vx_test.Type_testcoveragenums) : vx_web_html.Type_p
  }

  class Class_p_from_testcoveragenums : vx_core.Class_base, Func_p_from_testcoveragenums {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_p_from_testcoveragenums = vx_test.Class_p_from_testcoveragenums()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_p_from_testcoveragenums = vx_test.Class_p_from_testcoveragenums()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_p_from_testcoveragenums
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_p_from_testcoveragenums
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testcoveragenums = value as vx_test.Type_testcoveragenums
      var outputval : vx_core.Type_any = vx_test.f_p_from_testcoveragenums(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var nums : vx_test.Type_testcoveragenums = vx_core.f_any_from_any(vx_test.t_testcoveragenums, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_p_from_testcoveragenums(nums)
      return output
    }

    override fun vx_p_from_testcoveragenums(nums : vx_test.Type_testcoveragenums) : vx_web_html.Type_p {
      var output : vx_web_html.Type_p = vx_test.f_p_from_testcoveragenums(nums)
      return output
    }

  }

  val e_p_from_testcoveragenums : vx_test.Func_p_from_testcoveragenums = vx_test.Class_p_from_testcoveragenums()
  val t_p_from_testcoveragenums : vx_test.Func_p_from_testcoveragenums = vx_test.Class_p_from_testcoveragenums()

  fun f_p_from_testcoveragenums(nums : vx_test.Type_testcoveragenums) : vx_web_html.Type_p {
    var output : vx_web_html.Type_p = vx_web_html.e_p
    output = vx_core.f_new(
      vx_web_html.t_p,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":style"),
        vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".coveragenums")
        ),
        vx_core.vx_new_string(":text"),
        vx_core.f_new(
          vx_core.t_string,
          vx_core.vx_new(
            vx_core.t_anylist,
            nums.pct(),
            vx_core.vx_new_string("% "),
            nums.tests(),
            vx_core.vx_new_string("/"),
            nums.total()
          )
        )
      )
    )
    return output
  }


  interface Func_resolve_testcase : vx_core.Func_any_from_any_async {
    fun vx_resolve_testcase(testcase : vx_test.Type_testcase) : CompletableFuture<vx_test.Type_testcase>
  }

  class Class_resolve_testcase : vx_core.Class_base, Func_resolve_testcase {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testcase = vx_test.Class_resolve_testcase()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testcase = vx_test.Class_resolve_testcase()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testcase", // name
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
      var output : vx_core.Type_any = vx_test.e_resolve_testcase
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testcase
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testcase = vx_core.f_any_from_any(vx_test.t_testcase, value)
      var future : CompletableFuture<vx_test.Type_testcase> = vx_test.f_resolve_testcase(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testcase : vx_test.Type_testcase = vx_core.f_any_from_any(vx_test.t_testcase, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testcase> = vx_test.f_resolve_testcase(testcase)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testcase(testcase : vx_test.Type_testcase) : CompletableFuture<vx_test.Type_testcase> {
      var output : CompletableFuture<vx_test.Type_testcase> = vx_test.f_resolve_testcase(testcase)
      return output
    }

  }

  val e_resolve_testcase : vx_test.Func_resolve_testcase = vx_test.Class_resolve_testcase()
  val t_resolve_testcase : vx_test.Func_resolve_testcase = vx_test.Class_resolve_testcase()

  fun f_resolve_testcase(testcase : vx_test.Type_testcase) : CompletableFuture<vx_test.Type_testcase> {
    var output : CompletableFuture<vx_test.Type_testcase> = vx_core.vx_async_new_from_value(vx_test.e_testcase)
    output = vx_core.f_let_async(
      vx_test.t_testcase,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var describelist : vx_test.Type_testdescribelist = testcase.describelist()
        var future_resolvedlist : CompletableFuture<vx_test.Type_testdescribelist> = vx_test.f_resolve_testdescribelist(
          describelist
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_resolvedlist, {resolvedlist ->
          var passfaillist : vx_core.Type_booleanlist = vx_core.f_list_from_list_1(
            vx_core.t_booleanlist,
            resolvedlist,
            vx_core.t_any_from_any.vx_fn_new({testdescribe_any : vx_core.Type_any ->
              var testdescribe : vx_test.Type_testdescribe = vx_core.f_any_from_any(vx_test.t_testdescribe, testdescribe_any)
              var output_3 : vx_core.Type_any = vx_core.f_let(
                vx_core.t_boolean,
                vx_core.t_any_from_func.vx_fn_new({ ->
                  var testresult : vx_test.Type_testresult = testdescribe.testresult()
                  var output_4 : vx_core.Type_any = testresult.passfail()
                  output_4
                })
              )
              output_3
            })
          )
          var passfail : vx_core.Type_boolean = vx_core.f_and_1(
            passfaillist
          )
          var output_2 : vx_core.Type_any = vx_core.f_copy(
            testcase,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":passfail"),
              passfail,
              vx_core.vx_new_string(":describelist"),
              resolvedlist
            )
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_resolve_testcaselist : vx_core.Func_any_from_any_async {
    fun vx_resolve_testcaselist(testcaselist : vx_test.Type_testcaselist) : CompletableFuture<vx_test.Type_testcaselist>
  }

  class Class_resolve_testcaselist : vx_core.Class_base, Func_resolve_testcaselist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testcaselist = vx_test.Class_resolve_testcaselist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testcaselist = vx_test.Class_resolve_testcaselist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testcaselist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_test.t_testcase), // allowtypes
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
      var output : vx_core.Type_any = vx_test.e_resolve_testcaselist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testcaselist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testcaselist = vx_core.f_any_from_any(vx_test.t_testcaselist, value)
      var future : CompletableFuture<vx_test.Type_testcaselist> = vx_test.f_resolve_testcaselist(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testcaselist : vx_test.Type_testcaselist = vx_core.f_any_from_any(vx_test.t_testcaselist, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testcaselist> = vx_test.f_resolve_testcaselist(testcaselist)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testcaselist(testcaselist : vx_test.Type_testcaselist) : CompletableFuture<vx_test.Type_testcaselist> {
      var output : CompletableFuture<vx_test.Type_testcaselist> = vx_test.f_resolve_testcaselist(testcaselist)
      return output
    }

  }

  val e_resolve_testcaselist : vx_test.Func_resolve_testcaselist = vx_test.Class_resolve_testcaselist()
  val t_resolve_testcaselist : vx_test.Func_resolve_testcaselist = vx_test.Class_resolve_testcaselist()

  fun f_resolve_testcaselist(testcaselist : vx_test.Type_testcaselist) : CompletableFuture<vx_test.Type_testcaselist> {
    var output : CompletableFuture<vx_test.Type_testcaselist> = vx_core.vx_async_new_from_value(vx_test.e_testcaselist)
    output = vx_core.f_list_from_list_async(
      vx_test.t_testcaselist,
      testcaselist,
      vx_test.t_resolve_testcase
    )
    return output
  }


  interface Func_resolve_testdescribe : vx_core.Func_any_from_any_async {
    fun vx_resolve_testdescribe(testdescribe : vx_test.Type_testdescribe) : CompletableFuture<vx_test.Type_testdescribe>
  }

  class Class_resolve_testdescribe : vx_core.Class_base, Func_resolve_testdescribe {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testdescribe = vx_test.Class_resolve_testdescribe()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testdescribe = vx_test.Class_resolve_testdescribe()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testdescribe", // name
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
      var output : vx_core.Type_any = vx_test.e_resolve_testdescribe
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testdescribe
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testdescribe = vx_core.f_any_from_any(vx_test.t_testdescribe, value)
      var future : CompletableFuture<vx_test.Type_testdescribe> = vx_test.f_resolve_testdescribe(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testdescribe : vx_test.Type_testdescribe = vx_core.f_any_from_any(vx_test.t_testdescribe, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testdescribe> = vx_test.f_resolve_testdescribe(testdescribe)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testdescribe(testdescribe : vx_test.Type_testdescribe) : CompletableFuture<vx_test.Type_testdescribe> {
      var output : CompletableFuture<vx_test.Type_testdescribe> = vx_test.f_resolve_testdescribe(testdescribe)
      return output
    }

  }

  val e_resolve_testdescribe : vx_test.Func_resolve_testdescribe = vx_test.Class_resolve_testdescribe()
  val t_resolve_testdescribe : vx_test.Func_resolve_testdescribe = vx_test.Class_resolve_testdescribe()

  fun f_resolve_testdescribe(testdescribe : vx_test.Type_testdescribe) : CompletableFuture<vx_test.Type_testdescribe> {
    var output : CompletableFuture<vx_test.Type_testdescribe> = vx_core.vx_async_new_from_value(vx_test.e_testdescribe)
    output = vx_core.f_let_async(
      vx_test.t_testdescribe,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var testresult : vx_test.Type_testresult = testdescribe.testresult()
        var future_resolved : CompletableFuture<vx_test.Type_testresult> = vx_test.f_resolve_testresult(
          testresult
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_resolved, {resolved ->
          var output_2 : vx_core.Type_any = vx_core.f_copy(
            testdescribe,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":testresult"),
              resolved
            )
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_resolve_testdescribelist : vx_core.Func_any_from_any_async {
    fun vx_resolve_testdescribelist(testdescribelist : vx_test.Type_testdescribelist) : CompletableFuture<vx_test.Type_testdescribelist>
  }

  class Class_resolve_testdescribelist : vx_core.Class_base, Func_resolve_testdescribelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testdescribelist = vx_test.Class_resolve_testdescribelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testdescribelist = vx_test.Class_resolve_testdescribelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testdescribelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_test.t_testdescribe), // allowtypes
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
      var output : vx_core.Type_any = vx_test.e_resolve_testdescribelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testdescribelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testdescribelist = vx_core.f_any_from_any(vx_test.t_testdescribelist, value)
      var future : CompletableFuture<vx_test.Type_testdescribelist> = vx_test.f_resolve_testdescribelist(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testdescribelist : vx_test.Type_testdescribelist = vx_core.f_any_from_any(vx_test.t_testdescribelist, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testdescribelist> = vx_test.f_resolve_testdescribelist(testdescribelist)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testdescribelist(testdescribelist : vx_test.Type_testdescribelist) : CompletableFuture<vx_test.Type_testdescribelist> {
      var output : CompletableFuture<vx_test.Type_testdescribelist> = vx_test.f_resolve_testdescribelist(testdescribelist)
      return output
    }

  }

  val e_resolve_testdescribelist : vx_test.Func_resolve_testdescribelist = vx_test.Class_resolve_testdescribelist()
  val t_resolve_testdescribelist : vx_test.Func_resolve_testdescribelist = vx_test.Class_resolve_testdescribelist()

  fun f_resolve_testdescribelist(testdescribelist : vx_test.Type_testdescribelist) : CompletableFuture<vx_test.Type_testdescribelist> {
    var output : CompletableFuture<vx_test.Type_testdescribelist> = vx_core.vx_async_new_from_value(vx_test.e_testdescribelist)
    output = vx_core.f_list_from_list_async(
      vx_test.t_testdescribelist,
      testdescribelist,
      vx_test.t_resolve_testdescribe
    )
    return output
  }


  interface Func_resolve_testpackage : vx_core.Func_any_from_any_async {
    fun vx_resolve_testpackage(testpackage : vx_test.Type_testpackage) : CompletableFuture<vx_test.Type_testpackage>
  }

  class Class_resolve_testpackage : vx_core.Class_base, Func_resolve_testpackage {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testpackage = vx_test.Class_resolve_testpackage()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testpackage = vx_test.Class_resolve_testpackage()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testpackage", // name
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
      var output : vx_core.Type_any = vx_test.e_resolve_testpackage
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testpackage
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testpackage = vx_core.f_any_from_any(vx_test.t_testpackage, value)
      var future : CompletableFuture<vx_test.Type_testpackage> = vx_test.f_resolve_testpackage(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testpackage : vx_test.Type_testpackage = vx_core.f_any_from_any(vx_test.t_testpackage, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testpackage> = vx_test.f_resolve_testpackage(testpackage)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testpackage(testpackage : vx_test.Type_testpackage) : CompletableFuture<vx_test.Type_testpackage> {
      var output : CompletableFuture<vx_test.Type_testpackage> = vx_test.f_resolve_testpackage(testpackage)
      return output
    }

  }

  val e_resolve_testpackage : vx_test.Func_resolve_testpackage = vx_test.Class_resolve_testpackage()
  val t_resolve_testpackage : vx_test.Func_resolve_testpackage = vx_test.Class_resolve_testpackage()

  fun f_resolve_testpackage(testpackage : vx_test.Type_testpackage) : CompletableFuture<vx_test.Type_testpackage> {
    var output : CompletableFuture<vx_test.Type_testpackage> = vx_core.vx_async_new_from_value(vx_test.e_testpackage)
    output = vx_core.f_let_async(
      vx_test.t_testpackage,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var testcaselist : vx_test.Type_testcaselist = testpackage.caselist()
        var future_resolvedlist : CompletableFuture<vx_test.Type_testcaselist> = vx_test.f_resolve_testcaselist(
          testcaselist
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_resolvedlist, {resolvedlist ->
          var passfaillist : vx_core.Type_booleanlist = vx_core.f_list_from_list_1(
            vx_core.t_booleanlist,
            resolvedlist,
            vx_core.t_any_from_any.vx_fn_new({testcase_any : vx_core.Type_any ->
              var testcase : vx_test.Type_testcase = vx_core.f_any_from_any(vx_test.t_testcase, testcase_any)
              var output_3 : vx_core.Type_any = testcase.passfail()
              output_3
            })
          )
          var passfail : vx_core.Type_boolean = vx_core.f_and_1(
            passfaillist
          )
          var output_2 : vx_core.Type_any = vx_core.f_copy(
            testpackage,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":passfail"),
              passfail,
              vx_core.vx_new_string(":caselist"),
              resolvedlist
            )
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_resolve_testpackagelist : vx_core.Func_any_from_any_async {
    fun vx_resolve_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : CompletableFuture<vx_test.Type_testpackagelist>
  }

  class Class_resolve_testpackagelist : vx_core.Class_base, Func_resolve_testpackagelist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testpackagelist = vx_test.Class_resolve_testpackagelist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testpackagelist = vx_test.Class_resolve_testpackagelist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testpackagelist", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_test.t_testpackage), // allowtypes
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
      var output : vx_core.Type_any = vx_test.e_resolve_testpackagelist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testpackagelist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testpackagelist = vx_core.f_any_from_any(vx_test.t_testpackagelist, value)
      var future : CompletableFuture<vx_test.Type_testpackagelist> = vx_test.f_resolve_testpackagelist(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testpackagelist : vx_test.Type_testpackagelist = vx_core.f_any_from_any(vx_test.t_testpackagelist, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testpackagelist> = vx_test.f_resolve_testpackagelist(testpackagelist)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : CompletableFuture<vx_test.Type_testpackagelist> {
      var output : CompletableFuture<vx_test.Type_testpackagelist> = vx_test.f_resolve_testpackagelist(testpackagelist)
      return output
    }

  }

  val e_resolve_testpackagelist : vx_test.Func_resolve_testpackagelist = vx_test.Class_resolve_testpackagelist()
  val t_resolve_testpackagelist : vx_test.Func_resolve_testpackagelist = vx_test.Class_resolve_testpackagelist()

  fun f_resolve_testpackagelist(testpackagelist : vx_test.Type_testpackagelist) : CompletableFuture<vx_test.Type_testpackagelist> {
    var output : CompletableFuture<vx_test.Type_testpackagelist> = vx_core.vx_async_new_from_value(vx_test.e_testpackagelist)
    output = vx_core.f_list_from_list_async(
      vx_test.t_testpackagelist,
      testpackagelist,
      vx_test.t_resolve_testpackage
    )
    return output
  }


  interface Func_resolve_testresult : vx_core.Func_any_from_any_async {
    fun vx_resolve_testresult(testresult : vx_test.Type_testresult) : CompletableFuture<vx_test.Type_testresult>
  }

  class Class_resolve_testresult : vx_core.Class_base, Func_resolve_testresult {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testresult = vx_test.Class_resolve_testresult()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_resolve_testresult = vx_test.Class_resolve_testresult()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_resolve_testresult
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_resolve_testresult
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_test.Type_testresult = vx_core.f_any_from_any(vx_test.t_testresult, value)
      var future : CompletableFuture<vx_test.Type_testresult> = vx_test.f_resolve_testresult(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var testresult : vx_test.Type_testresult = vx_core.f_any_from_any(vx_test.t_testresult, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_test.Type_testresult> = vx_test.f_resolve_testresult(testresult)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_resolve_testresult(testresult : vx_test.Type_testresult) : CompletableFuture<vx_test.Type_testresult> {
      var output : CompletableFuture<vx_test.Type_testresult> = vx_test.f_resolve_testresult(testresult)
      return output
    }

  }

  val e_resolve_testresult : vx_test.Func_resolve_testresult = vx_test.Class_resolve_testresult()
  val t_resolve_testresult : vx_test.Func_resolve_testresult = vx_test.Class_resolve_testresult()

  fun f_resolve_testresult(testresult : vx_test.Type_testresult) : CompletableFuture<vx_test.Type_testresult> {
    var output : CompletableFuture<vx_test.Type_testresult> = vx_core.vx_async_new_from_value(vx_test.e_testresult)
    output = vx_core.f_let_async(
      vx_test.t_testresult,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var fn_actual : vx_core.Func_any_from_func_async = testresult.fn_actual()
        var expected : vx_core.Type_any = testresult.expected()
        var future_actual : CompletableFuture<vx_core.Type_any> = vx_core.f_resolve_async(
          vx_core.t_any,
          fn_actual
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_actual, {actual ->
          var output_6 : vx_core.Type_any = vx_core.f_if_2(
            vx_test.t_testresult,
            vx_core.vx_new(
              vx_core.t_thenelselist,
              vx_core.f_then(
                vx_core.t_boolean_from_func.vx_fn_new({ ->
                  var output_2 : vx_core.Type_any = vx_core.f_is_empty_1(
                    fn_actual
                  )
                  output_2
                }),
                vx_core.t_any_from_func.vx_fn_new({ ->
                  var output_3 : vx_core.Type_any = testresult
                  output_3
                })
              ),
              vx_core.f_else(
                vx_core.t_any_from_func.vx_fn_new({ ->
                  var output_4 : vx_core.Type_any = vx_core.f_let(
                    vx_test.t_testresult,
                    vx_core.t_any_from_func.vx_fn_new({ ->
                      var passfail : vx_core.Type_boolean = vx_core.f_eq(
                        expected,
                        actual
                      )
                      var output_5 : vx_core.Type_any = vx_core.f_copy(
                        testresult,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":passfail"),
                          passfail,
                          vx_core.vx_new_string(":actual"),
                          actual
                        )
                      )
                      output_5
                    })
                  )
                  output_4
                })
              )
            )
          )
          output_6
        })
        output_1
      })
    )
    return output
  }


  interface Func_security_test : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_security_test() : vx_core.Type_security
  }

  class Class_security_test : vx_core.Class_base, Func_security_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_security_test = vx_test.Class_security_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_security_test = vx_test.Class_security_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "security-test", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      var output : vx_core.Type_any = vx_test.e_security_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_security_test
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      output = vx_test.f_security_test()
      return output
    }

    override fun vx_security_test() : vx_core.Type_security {
      var output : vx_core.Type_security = vx_test.f_security_test()
      return output
    }

  }

  val e_security_test : vx_test.Func_security_test = vx_test.Class_security_test()
  val t_security_test : vx_test.Func_security_test = vx_test.Class_security_test()

  fun f_security_test() : vx_core.Type_security {
    var output : vx_core.Type_security = vx_core.e_security
    output = vx_core.f_new(
      vx_core.t_security,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":allowfuncs"),
        vx_core.f_new(
          vx_core.t_funclist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_data_file.t_boolean_write_from_file_any,
            vx_data_file.t_boolean_write_from_file_string,
            vx_data_file.t_file_read_from_file,
            vx_data_file.t_string_read_from_file
          )
        )
      )
    )
    return output
  }


  interface Func_test : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test : vx_core.Class_base, Func_test {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test = vx_test.Class_test()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test = vx_test.Class_test()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test(context, expected, actual)
      return output
    }

    override fun vx_test(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test(context, expected, actual)
      return output
    }

  }

  val e_test : vx_test.Func_test = vx_test.Class_test()
  val t_test : vx_test.Func_test = vx_test.Class_test()

  fun f_test(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":eq"),
          vx_core.vx_new_string(":passfail"),
          vx_core.f_eq(
            expected,
            actual
          ),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_1 : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_1 : vx_core.Class_base, Func_test_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_1 = vx_test.Class_test_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_1 = vx_test.Class_test_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_1
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_1(context, expected, fn_actual)
      return output
    }

    override fun vx_test_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_1(context, expected, fn_actual)
      return output
    }

  }

  val e_test_1 : vx_test.Func_test_1 = vx_test.Class_test_1()
  val t_test_1 : vx_test.Func_test_1 = vx_test.Class_test_1()

  fun f_test_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":eq"),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_false : vx_core.Func_any_from_any_context {
    fun vx_test_false(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test_false : vx_core.Class_base, Func_test_false {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_false = vx_test.Class_test_false()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_false = vx_test.Class_test_false()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_false
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_false
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_test.f_test_false(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_test_false(context, actual)
      return output
    }

    override fun vx_test_false(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_false(context, actual)
      return output
    }

  }

  val e_test_false : vx_test.Func_test_false = vx_test.Class_test_false()
  val t_test_false : vx_test.Func_test_false = vx_test.Class_test_false()

  fun f_test_false(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":false"),
          vx_core.vx_new_string(":passfail"),
          vx_core.f_eq(
            vx_core.vx_new_boolean(false),
            actual
          ),
          vx_core.vx_new_string(":expected"),
          vx_core.vx_new_boolean(false),
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-false", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_false_1 : vx_core.Func_any_from_any_context {
    fun vx_test_false_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_false_1 : vx_core.Class_base, Func_test_false_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_false_1 = vx_test.Class_test_false_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_false_1 = vx_test.Class_test_false_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_false_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_false_1
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Func_any_from_func_async = value as vx_core.Func_any_from_func_async
      var outputval : vx_core.Type_any = vx_test.f_test_false_1(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_test_false_1(context, fn_actual)
      return output
    }

    override fun vx_test_false_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_false_1(context, fn_actual)
      return output
    }

  }

  val e_test_false_1 : vx_test.Func_test_false_1 = vx_test.Class_test_false_1()
  val t_test_false_1 : vx_test.Func_test_false_1 = vx_test.Class_test_false_1()

  fun f_test_false_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":false"),
          vx_core.vx_new_string(":expected"),
          vx_core.vx_new_boolean(false),
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-false", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_gt : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_gt(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test_gt : vx_core.Class_base, Func_test_gt {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_gt = vx_test.Class_test_gt()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_gt = vx_test.Class_test_gt()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_gt
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_gt
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_gt(context, expected, actual)
      return output
    }

    override fun vx_test_gt(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_gt(context, expected, actual)
      return output
    }

  }

  val e_test_gt : vx_test.Func_test_gt = vx_test.Class_test_gt()
  val t_test_gt : vx_test.Func_test_gt = vx_test.Class_test_gt()

  fun f_test_gt(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":gt"),
          vx_core.vx_new_string(":passfail"),
          vx_core.f_gt(
            expected,
            actual
          ),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-gt", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_gt_1 : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_gt_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_gt_1 : vx_core.Class_base, Func_test_gt_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_gt_1 = vx_test.Class_test_gt_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_gt_1 = vx_test.Class_test_gt_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_gt_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_gt_1
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_gt_1(context, expected, fn_actual)
      return output
    }

    override fun vx_test_gt_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_gt_1(context, expected, fn_actual)
      return output
    }

  }

  val e_test_gt_1 : vx_test.Func_test_gt_1 = vx_test.Class_test_gt_1()
  val t_test_gt_1 : vx_test.Func_test_gt_1 = vx_test.Class_test_gt_1()

  fun f_test_gt_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":gt"),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-gt", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_ne : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_ne(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test_ne : vx_core.Class_base, Func_test_ne {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_ne = vx_test.Class_test_ne()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_ne = vx_test.Class_test_ne()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_ne
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_ne
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_ne(context, expected, actual)
      return output
    }

    override fun vx_test_ne(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_ne(context, expected, actual)
      return output
    }

  }

  val e_test_ne : vx_test.Func_test_ne = vx_test.Class_test_ne()
  val t_test_ne : vx_test.Func_test_ne = vx_test.Class_test_ne()

  fun f_test_ne(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":ne"),
          vx_core.vx_new_string(":passfail"),
          vx_core.f_ne(
            expected,
            actual
          ),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-ne", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_ne_1 : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_ne_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_ne_1 : vx_core.Class_base, Func_test_ne_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_ne_1 = vx_test.Class_test_ne_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_ne_1 = vx_test.Class_test_ne_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_ne_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_ne_1
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_ne_1(context, expected, fn_actual)
      return output
    }

    override fun vx_test_ne_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_ne_1(context, expected, fn_actual)
      return output
    }

  }

  val e_test_ne_1 : vx_test.Func_test_ne_1 = vx_test.Class_test_ne_1()
  val t_test_ne_1 : vx_test.Func_test_ne_1 = vx_test.Class_test_ne_1()

  fun f_test_ne_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":ne"),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-ne", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_string : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_string(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test_string : vx_core.Class_base, Func_test_string {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_string = vx_test.Class_test_string()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_string = vx_test.Class_test_string()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_string
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_string
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_string(context, expected, actual)
      return output
    }

    override fun vx_test_string(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_string(context, expected, actual)
      return output
    }

  }

  val e_test_string : vx_test.Func_test_string = vx_test.Class_test_string()
  val t_test_string : vx_test.Func_test_string = vx_test.Class_test_string()

  fun f_test_string(context : vx_core.Type_context, expected : vx_core.Type_any, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":passfail"),
          vx_core.f_eq(
            vx_core.f_string_from_any(
              expected
            ),
            vx_core.f_string_from_any(
              actual
            )
          ),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-string", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_string_1 : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_test_string_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_string_1 : vx_core.Class_base, Func_test_string_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_string_1 = vx_test.Class_test_string_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_string_1 = vx_test.Class_test_string_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_string_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_string_1
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var expected : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_test_string_1(context, expected, fn_actual)
      return output
    }

    override fun vx_test_string_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_string_1(context, expected, fn_actual)
      return output
    }

  }

  val e_test_string_1 : vx_test.Func_test_string_1 = vx_test.Class_test_string_1()
  val t_test_string_1 : vx_test.Func_test_string_1 = vx_test.Class_test_string_1()

  fun f_test_string_1(context : vx_core.Type_context, expected : vx_core.Type_any, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":string"),
          vx_core.vx_new_string(":expected"),
          expected,
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-string", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_true : vx_core.Func_any_from_any_context {
    fun vx_test_true(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult
  }

  class Class_test_true : vx_core.Class_base, Func_test_true {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_true = vx_test.Class_test_true()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_true = vx_test.Class_test_true()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_true
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_true
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Type_any = value as vx_core.Type_any
      var outputval : vx_core.Type_any = vx_test.f_test_true(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var actual : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_test_true(context, actual)
      return output
    }

    override fun vx_test_true(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_true(context, actual)
      return output
    }

  }

  val e_test_true : vx_test.Func_test_true = vx_test.Class_test_true()
  val t_test_true : vx_test.Func_test_true = vx_test.Class_test_true()

  fun f_test_true(context : vx_core.Type_context, actual : vx_core.Type_any) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":true"),
          vx_core.vx_new_string(":passfail"),
          vx_core.f_eq(
            vx_core.vx_new_boolean(true),
            actual
          ),
          vx_core.vx_new_string(":expected"),
          vx_core.vx_new_boolean(true),
          vx_core.vx_new_string(":actual"),
          actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-true", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_test_true_1 : vx_core.Func_any_from_any_context {
    fun vx_test_true_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult
  }

  class Class_test_true_1 : vx_core.Class_base, Func_test_true_1 {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_true_1 = vx_test.Class_test_true_1()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_test_true_1 = vx_test.Class_test_true_1()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      var output : vx_core.Type_any = vx_test.e_test_true_1
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_test_true_1
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_core.Func_any_from_func_async = value as vx_core.Func_any_from_func_async
      var outputval : vx_core.Type_any = vx_test.f_test_true_1(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var fn_actual : vx_core.Func_any_from_func_async = vx_core.f_any_from_any(vx_core.t_any_from_func_async, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_test_true_1(context, fn_actual)
      return output
    }

    override fun vx_test_true_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
      var output : vx_test.Type_testresult = vx_test.f_test_true_1(context, fn_actual)
      return output
    }

  }

  val e_test_true_1 : vx_test.Func_test_true_1 = vx_test.Class_test_true_1()
  val t_test_true_1 : vx_test.Func_test_true_1 = vx_test.Class_test_true_1()

  fun f_test_true_1(context : vx_core.Type_context, fn_actual : vx_core.Func_any_from_func_async) : vx_test.Type_testresult {
    var output : vx_test.Type_testresult = vx_test.e_testresult
    try {
      output = vx_core.f_new(
        vx_test.t_testresult,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":code"),
          vx_core.vx_new_string(":true"),
          vx_core.vx_new_string(":expected"),
          vx_core.vx_new_boolean(true),
          vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      )
    } catch (err : Exception) {
      var msg : vx_core.Type_msg = vx_core.vx_msg_from_exception("vx/test/test-true", err)
      output = vx_core.vx_copy(output, msg)
    }
    return output
  }


  interface Func_tr_from_testdescribe_casename : vx_core.Type_func, vx_core.Type_replfunc {
    fun vx_tr_from_testdescribe_casename(testdescribe : vx_test.Type_testdescribe, casename : vx_core.Type_string) : vx_web_html.Type_tr
  }

  class Class_tr_from_testdescribe_casename : vx_core.Class_base, Func_tr_from_testdescribe_casename {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_tr_from_testdescribe_casename = vx_test.Class_tr_from_testdescribe_casename()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_tr_from_testdescribe_casename = vx_test.Class_tr_from_testdescribe_casename()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_tr_from_testdescribe_casename
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_tr_from_testdescribe_casename
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testdescribe : vx_test.Type_testdescribe = vx_core.f_any_from_any(vx_test.t_testdescribe, arglist.vx_any(vx_core.vx_new_int(0)))
      var casename : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      output = vx_test.f_tr_from_testdescribe_casename(testdescribe, casename)
      return output
    }

    override fun vx_tr_from_testdescribe_casename(testdescribe : vx_test.Type_testdescribe, casename : vx_core.Type_string) : vx_web_html.Type_tr {
      var output : vx_web_html.Type_tr = vx_test.f_tr_from_testdescribe_casename(testdescribe, casename)
      return output
    }

  }

  val e_tr_from_testdescribe_casename : vx_test.Func_tr_from_testdescribe_casename = vx_test.Class_tr_from_testdescribe_casename()
  val t_tr_from_testdescribe_casename : vx_test.Func_tr_from_testdescribe_casename = vx_test.Class_tr_from_testdescribe_casename()

  fun f_tr_from_testdescribe_casename(testdescribe : vx_test.Type_testdescribe, casename : vx_core.Type_string) : vx_web_html.Type_tr {
    var output : vx_web_html.Type_tr = vx_web_html.e_tr
    output = vx_core.f_let(
      vx_web_html.t_tr,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var describename : vx_core.Type_string = testdescribe.describename()
        var result : vx_test.Type_testresult = testdescribe.testresult()
        var passfail : vx_core.Type_boolean = result.passfail()
        var expected : vx_core.Type_string = vx_core.f_string_from_any(
          result.expected()
        )
        var actual : vx_core.Type_string = vx_core.f_string_from_any(
          result.actual()
        )
        var prestyle : vx_web_html.Type_style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          vx_core.vx_new_string(".preformatted")
        )
        var output_1 : vx_core.Type_any = vx_core.f_new(
          vx_web_html.t_tr,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_test.f_p_from_passfail(
                  passfail
                )
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    prestyle,
                    vx_core.vx_new_string(":text"),
                    casename
                  )
                )
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    prestyle,
                    vx_core.vx_new_string(":text"),
                    describename
                  )
                )
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    prestyle,
                    vx_core.vx_new_string(":text"),
                    expected
                  )
                )
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_web_html.t_p,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":style"),
                    prestyle,
                    vx_core.vx_new_string(":text"),
                    actual
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


  interface Func_trlist_from_testcase : vx_core.Func_any_from_any {
    fun vx_trlist_from_testcase(testcase : vx_test.Type_testcase) : vx_web_html.Type_trlist
  }

  class Class_trlist_from_testcase : vx_core.Class_base, Func_trlist_from_testcase {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_trlist_from_testcase = vx_test.Class_trlist_from_testcase()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_trlist_from_testcase = vx_test.Class_trlist_from_testcase()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_trlist_from_testcase
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_trlist_from_testcase
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testcase = value as vx_test.Type_testcase
      var outputval : vx_core.Type_any = vx_test.f_trlist_from_testcase(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testcase : vx_test.Type_testcase = vx_core.f_any_from_any(vx_test.t_testcase, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_trlist_from_testcase(testcase)
      return output
    }

    override fun vx_trlist_from_testcase(testcase : vx_test.Type_testcase) : vx_web_html.Type_trlist {
      var output : vx_web_html.Type_trlist = vx_test.f_trlist_from_testcase(testcase)
      return output
    }

  }

  val e_trlist_from_testcase : vx_test.Func_trlist_from_testcase = vx_test.Class_trlist_from_testcase()
  val t_trlist_from_testcase : vx_test.Func_trlist_from_testcase = vx_test.Class_trlist_from_testcase()

  fun f_trlist_from_testcase(testcase : vx_test.Type_testcase) : vx_web_html.Type_trlist {
    var output : vx_web_html.Type_trlist = vx_web_html.e_trlist
    output = vx_core.f_let(
      vx_web_html.t_trlist,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var describelist : vx_test.Type_testdescribelist = testcase.describelist()
        var casename : vx_core.Type_string = testcase.casename()
        var output_1 : vx_core.Type_any = vx_core.f_list_from_list_1(
          vx_web_html.t_trlist,
          describelist,
          vx_core.t_any_from_any.vx_fn_new({testdescribe_any : vx_core.Type_any ->
            var testdescribe : vx_test.Type_testdescribe = vx_core.f_any_from_any(vx_test.t_testdescribe, testdescribe_any)
            var output_2 : vx_core.Type_any = vx_test.f_tr_from_testdescribe_casename(
              testdescribe,
              casename
            )
            output_2
          })
        )
        output_1
      })
    )
    return output
  }


  interface Func_trlist_from_testcaselist : vx_core.Func_any_from_any {
    fun vx_trlist_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_trlist
  }

  class Class_trlist_from_testcaselist : vx_core.Class_base, Func_trlist_from_testcaselist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_trlist_from_testcaselist = vx_test.Class_trlist_from_testcaselist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_test.Class_trlist_from_testcaselist = vx_test.Class_trlist_from_testcaselist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
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
        ) // typedef
      )
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.e_trlist_from_testcaselist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_test.t_trlist_from_testcaselist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_test.Type_testcaselist = value as vx_test.Type_testcaselist
      var outputval : vx_core.Type_any = vx_test.f_trlist_from_testcaselist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var testcaselist : vx_test.Type_testcaselist = vx_core.f_any_from_any(vx_test.t_testcaselist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_test.f_trlist_from_testcaselist(testcaselist)
      return output
    }

    override fun vx_trlist_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_trlist {
      var output : vx_web_html.Type_trlist = vx_test.f_trlist_from_testcaselist(testcaselist)
      return output
    }

  }

  val e_trlist_from_testcaselist : vx_test.Func_trlist_from_testcaselist = vx_test.Class_trlist_from_testcaselist()
  val t_trlist_from_testcaselist : vx_test.Func_trlist_from_testcaselist = vx_test.Class_trlist_from_testcaselist()

  fun f_trlist_from_testcaselist(testcaselist : vx_test.Type_testcaselist) : vx_web_html.Type_trlist {
    var output : vx_web_html.Type_trlist = vx_web_html.e_trlist
    output = vx_core.f_list_join_from_list_1(
      vx_web_html.t_trlist,
      testcaselist,
      vx_test.t_trlist_from_testcase
    )
    return output
  }


  init {
    Const_stylesheet_test.const_new(c_stylesheet_test)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("testcase", vx_test.t_testcase)
    maptype.put("testcaselist", vx_test.t_testcaselist)
    maptype.put("testcoveragedetail", vx_test.t_testcoveragedetail)
    maptype.put("testcoveragenums", vx_test.t_testcoveragenums)
    maptype.put("testcoveragesummary", vx_test.t_testcoveragesummary)
    maptype.put("testdescribe", vx_test.t_testdescribe)
    maptype.put("testdescribelist", vx_test.t_testdescribelist)
    maptype.put("testpackage", vx_test.t_testpackage)
    maptype.put("testpackagelist", vx_test.t_testpackagelist)
    maptype.put("testresult", vx_test.t_testresult)
    maptype.put("testresultlist", vx_test.t_testresultlist)
    mapconst.put("stylesheet-test", vx_test.c_stylesheet_test)
    mapfunc.put("context-test", vx_test.t_context_test)
    mapfunc.put("div<-testcaselist", vx_test.t_div_from_testcaselist)
    mapfunc.put("div<-testpackage", vx_test.t_div_from_testpackage)
    mapfunc.put("div<-testpackagelist", vx_test.t_div_from_testpackagelist)
    mapfunc.put("divchildlist<-testpackagelist", vx_test.t_divchildlist_from_testpackagelist)
    mapfunc.put("file-test", vx_test.t_file_test)
    mapfunc.put("file-testhtml", vx_test.t_file_testhtml)
    mapfunc.put("file-testnode", vx_test.t_file_testnode)
    mapfunc.put("html<-divtest", vx_test.t_html_from_divtest)
    mapfunc.put("p<-passfail", vx_test.t_p_from_passfail)
    mapfunc.put("p<-testcoveragenums", vx_test.t_p_from_testcoveragenums)
    mapfunc.put("resolve-testcase", vx_test.t_resolve_testcase)
    mapfunc.put("resolve-testcaselist", vx_test.t_resolve_testcaselist)
    mapfunc.put("resolve-testdescribe", vx_test.t_resolve_testdescribe)
    mapfunc.put("resolve-testdescribelist", vx_test.t_resolve_testdescribelist)
    mapfunc.put("resolve-testpackage", vx_test.t_resolve_testpackage)
    mapfunc.put("resolve-testpackagelist", vx_test.t_resolve_testpackagelist)
    mapfunc.put("resolve-testresult", vx_test.t_resolve_testresult)
    mapfunc.put("security-test", vx_test.t_security_test)
    mapfunc.put("test", vx_test.t_test)
    mapfunc.put("test_1", vx_test.t_test_1)
    mapfunc.put("test-false", vx_test.t_test_false)
    mapfunc.put("test-false_1", vx_test.t_test_false_1)
    mapfunc.put("test-gt", vx_test.t_test_gt)
    mapfunc.put("test-gt_1", vx_test.t_test_gt_1)
    mapfunc.put("test-ne", vx_test.t_test_ne)
    mapfunc.put("test-ne_1", vx_test.t_test_ne_1)
    mapfunc.put("test-string", vx_test.t_test_string)
    mapfunc.put("test-string_1", vx_test.t_test_string_1)
    mapfunc.put("test-true", vx_test.t_test_true)
    mapfunc.put("test-true_1", vx_test.t_test_true_1)
    mapfunc.put("tr<-testdescribe-casename", vx_test.t_tr_from_testdescribe_casename)
    mapfunc.put("trlist<-testcase", vx_test.t_trlist_from_testcase)
    mapfunc.put("trlist<-testcaselist", vx_test.t_trlist_from_testcaselist)
    vx_core.vx_global_package_set("vx/test", maptype, mapconst, mapfunc)
  }

}
