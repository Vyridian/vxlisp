package com.vxlisp.vx.web

import java.util.concurrent.CompletableFuture
import com.vxlisp.vx.*
import com.vxlisp.vx.data.*

object vx_web_http {


  interface Type_response : vx_core.Type_struct {
    fun ok() : vx_core.Type_boolean
    fun status() : vx_core.Type_int
  }

  class Class_response : vx_core.Class_base, Type_response {
    constructor() {}

    var vx_p_ok : vx_core.Type_boolean? = null

    override fun ok() : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.e_boolean
      var testnull : vx_core.Type_boolean? = vx_p_ok
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_status : vx_core.Type_int? = null

    override fun status() : vx_core.Type_int {
      var output : vx_core.Type_int = vx_core.e_int
      var testnull : vx_core.Type_int? = vx_p_status
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var skey : String = key.vx_string()
      if (false) {
      } else if ((skey==":ok")) {
        output = this.ok()
      } else if ((skey==":status")) {
        output = this.status()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":ok", this.ok())
      map.put(":status", this.status())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_http.Type_response = vx_core.vx_copy(vx_web_http.e_response, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_web_http.Type_response = this
      var ischanged : Boolean = false
      var value : vx_web_http.Class_response = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_ok : vx_core.Type_boolean = value.ok()
      var vx_p_status : vx_core.Type_int = value.status()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":ok")
      validkeys.add(":status")
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
            msg = vx_core.vx_msg_from_error("vx/web/http/response", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/web/http/response", ":invalidkey", msgval)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          }
        } else {
          if (false) {
          } else if ((key==":ok")) {
            if (valsub == vx_p_ok) {
            } else if (valsub is vx_core.Type_boolean) {
              var valok : vx_core.Type_boolean = valsub as vx_core.Type_boolean
              ischanged = true
              vx_p_ok = valok
            } else if (valsub is Boolean) {
              ischanged = true
              vx_p_ok = vx_core.vx_new(vx_core.t_boolean, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("ok"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/http/response", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":status")) {
            if (valsub == vx_p_status) {
            } else if (valsub is vx_core.Type_int) {
              var valstatus : vx_core.Type_int = valsub as vx_core.Type_int
              ischanged = true
              vx_p_status = valstatus
            } else if (valsub is Int) {
              ischanged = true
              vx_p_status = vx_core.vx_new(vx_core.t_int, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("status"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/web/http/response", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/web/http/response", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_web_http.Class_response = vx_web_http.Class_response()
        work.vx_p_ok = vx_p_ok
        work.vx_p_status = vx_p_status
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.e_response
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_response
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/web/http", // pkgname
        "response", // name
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

  val e_response : vx_web_http.Type_response = vx_web_http.Class_response()
  val t_response : vx_web_http.Type_response = vx_web_http.Class_response()

  interface Func_csv_from_httpget : vx_core.Func_any_from_any_async {
    fun vx_csv_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_csv.Type_csv>
  }

  class Class_csv_from_httpget : vx_core.Class_base, Func_csv_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_csv_from_httpget = vx_web_http.Class_csv_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_csv_from_httpget = vx_web_http.Class_csv_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
        0, // idx
        true, // async
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
      var output : vx_core.Type_any = vx_web_http.e_csv_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_csv_from_httpget
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value)
      var future : CompletableFuture<vx_data_csv.Type_csv> = vx_web_http.f_csv_from_httpget(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_data_csv.Type_csv> = vx_web_http.f_csv_from_httpget(url)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_csv_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_csv.Type_csv> {
      var output : CompletableFuture<vx_data_csv.Type_csv> = vx_web_http.f_csv_from_httpget(url)
      return output
    }

  }

  val e_csv_from_httpget : vx_web_http.Func_csv_from_httpget = vx_web_http.Class_csv_from_httpget()
  val t_csv_from_httpget : vx_web_http.Func_csv_from_httpget = vx_web_http.Class_csv_from_httpget()

  fun f_csv_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_csv.Type_csv> {
    var output : CompletableFuture<vx_data_csv.Type_csv> = vx_core.vx_async_new_from_value(vx_data_csv.e_csv)
    output = vx_core.f_let_async(
      vx_data_csv.t_csv,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var future_textblock : CompletableFuture<vx_data_textblock.Type_textblock> = vx_web_http.f_textblock_from_httpget(
          url,
          vx_core.vx_new_string("text/csv")
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_textblock, {textblock ->
          var output_2 : vx_core.Type_any = vx_data_csv.f_csv_from_textblock(
            textblock
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_json_from_httpget : vx_core.Func_any_from_any_async {
    fun vx_json_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response>
  }

  class Class_json_from_httpget : vx_core.Class_base, Func_json_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_json_from_httpget = vx_web_http.Class_json_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_json_from_httpget = vx_web_http.Class_json_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
      var output : vx_core.Type_any = vx_web_http.e_json_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_json_from_httpget
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value)
      var future : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_json_from_httpget(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_json_from_httpget(url)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_json_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response> {
      var output : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_json_from_httpget(url)
      return output
    }

  }

  val e_json_from_httpget : vx_web_http.Func_json_from_httpget = vx_web_http.Class_json_from_httpget()
  val t_json_from_httpget : vx_web_http.Func_json_from_httpget = vx_web_http.Class_json_from_httpget()

  fun f_json_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response> {
    var output : CompletableFuture<vx_web_http.Type_response> = vx_core.vx_async_new_from_value(vx_web_http.e_response)
    output = vx_core.f_let_async(
      vx_web_http.t_response,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var future_response : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_response_from_httpget(
          url,
          vx_core.vx_new_string("application/json")
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_response, {response ->
          var output_2 : vx_core.Type_any = response
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_response_from_httpget : vx_core.Type_func, vx_core.Type_replfunc_async {
    fun vx_response_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response>
  }

  class Class_response_from_httpget : vx_core.Class_base, Func_response_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_response_from_httpget = vx_web_http.Class_response_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_response_from_httpget = vx_web_http.Class_response_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
      var output : vx_core.Type_any = vx_web_http.e_response_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_response_from_httpget
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var contenttype : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var future : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_response_from_httpget(url, contenttype)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_response_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response> {
      var output : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_response_from_httpget(url, contenttype)
      return output
    }

  }

  val e_response_from_httpget : vx_web_http.Func_response_from_httpget = vx_web_http.Class_response_from_httpget()
  val t_response_from_httpget : vx_web_http.Func_response_from_httpget = vx_web_http.Class_response_from_httpget()

  fun f_response_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_web_http.Type_response> {
    var output : CompletableFuture<vx_web_http.Type_response> = vx_core.vx_async_new_from_value(vx_web_http.e_response)
    return output
  }


  interface Func_text_from_httpget : vx_core.Func_any_from_any_async {
    fun vx_text_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_core.Type_string>
  }

  class Class_text_from_httpget : vx_core.Class_base, Func_text_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_text_from_httpget = vx_web_http.Class_text_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_text_from_httpget = vx_web_http.Class_text_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
        0, // idx
        true, // async
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
      var output : vx_core.Type_any = vx_web_http.e_text_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_text_from_httpget
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value)
      var future : CompletableFuture<vx_core.Type_string> = vx_web_http.f_text_from_httpget(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_core.Type_string> = vx_web_http.f_text_from_httpget(url)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_text_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_core.Type_string> {
      var output : CompletableFuture<vx_core.Type_string> = vx_web_http.f_text_from_httpget(url)
      return output
    }

  }

  val e_text_from_httpget : vx_web_http.Func_text_from_httpget = vx_web_http.Class_text_from_httpget()
  val t_text_from_httpget : vx_web_http.Func_text_from_httpget = vx_web_http.Class_text_from_httpget()

  fun f_text_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_core.Type_string> {
    var output : CompletableFuture<vx_core.Type_string> = vx_core.vx_async_new_from_value(vx_core.e_string)
    output = vx_core.f_let_async(
      vx_core.t_string,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var future_response : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_response_from_httpget(
          url,
          vx_core.vx_new_string("text/plain")
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_response, {response ->
          var output_2 : vx_core.Type_any = vx_web_http.f_text_from_response(
            response
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_text_from_response : vx_core.Func_any_from_any {
    fun vx_text_from_response(response : vx_web_http.Type_response) : vx_core.Type_string
  }

  class Class_text_from_response : vx_core.Class_base, Func_text_from_response {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_text_from_response = vx_web_http.Class_text_from_response()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_text_from_response = vx_web_http.Class_text_from_response()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
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
      var output : vx_core.Type_any = vx_web_http.e_text_from_response
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_text_from_response
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_http.Type_response = value as vx_web_http.Type_response
      var outputval : vx_core.Type_any = vx_web_http.f_text_from_response(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var response : vx_web_http.Type_response = vx_core.f_any_from_any(vx_web_http.t_response, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_http.f_text_from_response(response)
      return output
    }

    override fun vx_text_from_response(response : vx_web_http.Type_response) : vx_core.Type_string {
      var output : vx_core.Type_string = vx_web_http.f_text_from_response(response)
      return output
    }

  }

  val e_text_from_response : vx_web_http.Func_text_from_response = vx_web_http.Class_text_from_response()
  val t_text_from_response : vx_web_http.Func_text_from_response = vx_web_http.Class_text_from_response()

  fun f_text_from_response(response : vx_web_http.Type_response) : vx_core.Type_string {
    var output : vx_core.Type_string = vx_core.e_string
    return output
  }


  interface Func_textblock_from_httpget : vx_core.Type_func, vx_core.Type_replfunc_async {
    fun vx_textblock_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_data_textblock.Type_textblock>
  }

  class Class_textblock_from_httpget : vx_core.Class_base, Func_textblock_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_textblock_from_httpget = vx_web_http.Class_textblock_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_textblock_from_httpget = vx_web_http.Class_textblock_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
        0, // idx
        true, // async
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
      var output : vx_core.Type_any = vx_web_http.e_textblock_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_textblock_from_httpget
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var contenttype : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)))
      var future : CompletableFuture<vx_data_textblock.Type_textblock> = vx_web_http.f_textblock_from_httpget(url, contenttype)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_textblock_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_data_textblock.Type_textblock> {
      var output : CompletableFuture<vx_data_textblock.Type_textblock> = vx_web_http.f_textblock_from_httpget(url, contenttype)
      return output
    }

  }

  val e_textblock_from_httpget : vx_web_http.Func_textblock_from_httpget = vx_web_http.Class_textblock_from_httpget()
  val t_textblock_from_httpget : vx_web_http.Func_textblock_from_httpget = vx_web_http.Class_textblock_from_httpget()

  fun f_textblock_from_httpget(url : vx_core.Type_string, contenttype : vx_core.Type_string) : CompletableFuture<vx_data_textblock.Type_textblock> {
    var output : CompletableFuture<vx_data_textblock.Type_textblock> = vx_core.vx_async_new_from_value(vx_data_textblock.e_textblock)
    output = vx_core.f_let_async(
      vx_data_textblock.t_textblock,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var future_response : CompletableFuture<vx_web_http.Type_response> = vx_web_http.f_response_from_httpget(
          url,
          contenttype
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_response, {response ->
          var output_2 : vx_core.Type_any = vx_web_http.f_textblock_from_response(
            response
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  interface Func_textblock_from_response : vx_core.Func_any_from_any {
    fun vx_textblock_from_response(response : vx_web_http.Type_response) : vx_data_textblock.Type_textblock
  }

  class Class_textblock_from_response : vx_core.Class_base, Func_textblock_from_response {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_textblock_from_response = vx_web_http.Class_textblock_from_response()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_textblock_from_response = vx_web_http.Class_textblock_from_response()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
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
      var output : vx_core.Type_any = vx_web_http.e_textblock_from_response
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_textblock_from_response
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_web_http.Type_response = value as vx_web_http.Type_response
      var outputval : vx_core.Type_any = vx_web_http.f_textblock_from_response(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var response : vx_web_http.Type_response = vx_core.f_any_from_any(vx_web_http.t_response, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_web_http.f_textblock_from_response(response)
      return output
    }

    override fun vx_textblock_from_response(response : vx_web_http.Type_response) : vx_data_textblock.Type_textblock {
      var output : vx_data_textblock.Type_textblock = vx_web_http.f_textblock_from_response(response)
      return output
    }

  }

  val e_textblock_from_response : vx_web_http.Func_textblock_from_response = vx_web_http.Class_textblock_from_response()
  val t_textblock_from_response : vx_web_http.Func_textblock_from_response = vx_web_http.Class_textblock_from_response()

  fun f_textblock_from_response(response : vx_web_http.Type_response) : vx_data_textblock.Type_textblock {
    var output : vx_data_textblock.Type_textblock = vx_data_textblock.e_textblock
    output = vx_core.f_new(
      vx_data_textblock.t_textblock,
      vx_core.vx_new(
        vx_core.t_anylist,
        vx_core.vx_new_string(":text"),
        vx_web_http.f_text_from_response(
          response
        )
      )
    )
    return output
  }


  interface Func_xml_from_httpget : vx_core.Func_any_from_any_async {
    fun vx_xml_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_xml.Type_xml>
  }

  class Class_xml_from_httpget : vx_core.Class_base, Func_xml_from_httpget {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_xml_from_httpget = vx_web_http.Class_xml_from_httpget()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_web_http.Class_xml_from_httpget = vx_web_http.Class_xml_from_httpget()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
        0, // idx
        true, // async
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
      var output : vx_core.Type_any = vx_web_http.e_xml_from_httpget
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_web_http.t_xml_from_httpget
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_async.IFn) : vx_core.Func_any_from_any_async {
      return vx_core.e_any_from_any_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_async(generic_any_1 : T, value : U) : CompletableFuture<T> {
      var inputval : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, value)
      var future : CompletableFuture<vx_data_xml.Type_xml> = vx_web_http.f_xml_from_httpget(inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var url : vx_core.Type_string = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_data_xml.Type_xml> = vx_web_http.f_xml_from_httpget(url)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_xml_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_xml.Type_xml> {
      var output : CompletableFuture<vx_data_xml.Type_xml> = vx_web_http.f_xml_from_httpget(url)
      return output
    }

  }

  val e_xml_from_httpget : vx_web_http.Func_xml_from_httpget = vx_web_http.Class_xml_from_httpget()
  val t_xml_from_httpget : vx_web_http.Func_xml_from_httpget = vx_web_http.Class_xml_from_httpget()

  fun f_xml_from_httpget(url : vx_core.Type_string) : CompletableFuture<vx_data_xml.Type_xml> {
    var output : CompletableFuture<vx_data_xml.Type_xml> = vx_core.vx_async_new_from_value(vx_data_xml.e_xml)
    output = vx_core.f_let_async(
      vx_data_xml.t_xml,
      vx_core.t_any_from_func_async.vx_fn_new({ ->
        var future_textblock : CompletableFuture<vx_data_textblock.Type_textblock> = vx_web_http.f_textblock_from_httpget(
          url,
          vx_core.vx_new_string("text/xml")
        )
        var output_1 : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_from_async_fn(future_textblock, {textblock ->
          var output_2 : vx_core.Type_any = vx_data_xml.f_xml_from_textblock(
            textblock
          )
          output_2
        })
        output_1
      })
    )
    return output
  }


  init {
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("response", vx_web_http.t_response)
    mapfunc.put("csv<-httpget", vx_web_http.t_csv_from_httpget)
    mapfunc.put("json<-httpget", vx_web_http.t_json_from_httpget)
    mapfunc.put("response<-httpget", vx_web_http.t_response_from_httpget)
    mapfunc.put("text<-httpget", vx_web_http.t_text_from_httpget)
    mapfunc.put("text<-response", vx_web_http.t_text_from_response)
    mapfunc.put("textblock<-httpget", vx_web_http.t_textblock_from_httpget)
    mapfunc.put("textblock<-response", vx_web_http.t_textblock_from_response)
    mapfunc.put("xml<-httpget", vx_web_http.t_xml_from_httpget)
    vx_core.vx_global_package_set("vx/web/http", maptype, mapconst, mapfunc)
  }

}
