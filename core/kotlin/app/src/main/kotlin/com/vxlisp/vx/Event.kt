package com.vxlisp.vx

import java.util.concurrent.CompletableFuture

object vx_event {


  interface Type_event : vx_core.Type_struct {
    fun name() : vx_core.Type_string
    fun from() : vx_core.Type_string
    fun to() : vx_core.Type_string
    fun datamap() : vx_core.Type_anymap
    fun event_from_event() : vx_event.Func_event_from_event
    fun event_from_event_async() : vx_event.Func_event_from_event_async
  }

  class Class_event : vx_core.Class_base, Type_event {
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

    var vx_p_from : vx_core.Type_string? = null

    override fun from() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_from
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_to : vx_core.Type_string? = null

    override fun to() : vx_core.Type_string {
      var output : vx_core.Type_string = vx_core.e_string
      var testnull : vx_core.Type_string? = vx_p_to
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_datamap : vx_core.Type_anymap? = null

    override fun datamap() : vx_core.Type_anymap {
      var output : vx_core.Type_anymap = vx_core.e_anymap
      var testnull : vx_core.Type_anymap? = vx_p_datamap
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_event_from_event : vx_event.Func_event_from_event? = null

    override fun event_from_event() : vx_event.Func_event_from_event {
      var output : vx_event.Func_event_from_event = vx_event.e_event_from_event
      var testnull : vx_event.Func_event_from_event? = vx_p_event_from_event
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_event_from_event_async : vx_event.Func_event_from_event_async? = null

    override fun event_from_event_async() : vx_event.Func_event_from_event_async {
      var output : vx_event.Func_event_from_event_async = vx_event.e_event_from_event_async
      var testnull : vx_event.Func_event_from_event_async? = vx_p_event_from_event_async
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
      } else if ((skey==":from")) {
        output = this.from()
      } else if ((skey==":to")) {
        output = this.to()
      } else if ((skey==":datamap")) {
        output = this.datamap()
      } else if ((skey==":event<-event")) {
        output = this.event_from_event()
      } else if ((skey==":event<-event-async")) {
        output = this.event_from_event_async()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":name", this.name())
      map.put(":from", this.from())
      map.put(":to", this.to())
      map.put(":datamap", this.datamap())
      map.put(":event<-event", this.event_from_event())
      map.put(":event<-event-async", this.event_from_event_async())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_event.Type_event = vx_core.vx_copy(vx_event.e_event, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_event.Type_event = this
      var ischanged : Boolean = false
      var value : vx_event.Class_event = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_from : vx_core.Type_string = value.from()
      var vx_p_to : vx_core.Type_string = value.to()
      var vx_p_datamap : vx_core.Type_anymap = value.datamap()
      var vx_p_event_from_event : vx_event.Func_event_from_event = value.event_from_event()
      var vx_p_event_from_event_async : vx_event.Func_event_from_event_async = value.event_from_event_async()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":name")
      validkeys.add(":from")
      validkeys.add(":to")
      validkeys.add(":datamap")
      validkeys.add(":event<-event")
      validkeys.add(":event<-event-async")
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
            msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":from")) {
            if (valsub == vx_p_from) {
            } else if (valsub is vx_core.Type_string) {
              var valfrom : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_from = valfrom
            } else if (valsub is String) {
              ischanged = true
              vx_p_from = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("from"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":to")) {
            if (valsub == vx_p_to) {
            } else if (valsub is vx_core.Type_string) {
              var valto : vx_core.Type_string = valsub as vx_core.Type_string
              ischanged = true
              vx_p_to = valto
            } else if (valsub is String) {
              ischanged = true
              vx_p_to = vx_core.vx_new(vx_core.t_string, valsub)
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("to"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":datamap")) {
            if (valsub == vx_p_datamap) {
            } else if (valsub is vx_core.Type_anymap) {
              var valdatamap : vx_core.Type_anymap = valsub as vx_core.Type_anymap
              ischanged = true
              vx_p_datamap = valdatamap
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("datamap"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":event<-event")) {
            if (valsub == vx_p_event_from_event) {
            } else if (valsub is vx_event.Func_event_from_event) {
              var valevent_from_event : vx_event.Func_event_from_event = valsub as vx_event.Func_event_from_event
              ischanged = true
              vx_p_event_from_event = valevent_from_event
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("event<-event"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":event<-event-async")) {
            if (valsub == vx_p_event_from_event_async) {
            } else if (valsub is vx_event.Func_event_from_event_async) {
              var valevent_from_event_async : vx_event.Func_event_from_event_async = valsub as vx_event.Func_event_from_event_async
              ischanged = true
              vx_p_event_from_event_async = valevent_from_event_async
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("event<-event-async"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_event.Class_event = vx_event.Class_event()
        work.vx_p_name = vx_p_name
        work.vx_p_from = vx_p_from
        work.vx_p_to = vx_p_to
        work.vx_p_datamap = vx_p_datamap
        work.vx_p_event_from_event = vx_p_event_from_event
        work.vx_p_event_from_event_async = vx_p_event_from_event_async
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.e_event
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_event
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/event", // pkgname
        "event", // name
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

  val e_event : vx_event.Type_event = vx_event.Class_event()
  val t_event : vx_event.Type_event = vx_event.Class_event()

  interface Type_eventlist : vx_core.Type_list {
    fun vx_listevent() : List<vx_event.Type_event>
    fun vx_event(index : vx_core.Type_int) : vx_event.Type_event
  }

  class Class_eventlist : vx_core.Class_base, Type_eventlist {
    constructor() {}

    var vx_p_list : List<vx_event.Type_event> = vx_core.immutablelist(
      ArrayList<vx_event.Type_event>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_event(index : vx_core.Type_int) : vx_event.Type_event {
      var output : vx_event.Type_event = vx_event.e_event
      var list : vx_event.Class_eventlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_event.Type_event> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listevent() : List<vx_event.Type_event> {
      var output : List<vx_event.Type_event> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_event.Type_event = this.vx_event(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_event.Type_eventlist = vx_core.vx_copy(vx_event.e_eventlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_event.Type_eventlist = this
      var ischanged : Boolean = false
      var value : vx_event.Class_eventlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_event.Type_event> = ArrayList<vx_event.Type_event>(value.vx_listevent())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_event.Type_eventlist) {
          var multi : vx_event.Type_eventlist = valsub as vx_event.Type_eventlist
          ischanged = true
          listval.addAll(multi.vx_listevent())
        } else if (valsub is vx_event.Type_event) {
          var allowsub : vx_event.Type_event = valsub as vx_event.Type_event
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_event.Type_event) {
          ischanged = true
          listval.add(valsub as vx_event.Type_event)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_event.Type_event) {
              var valitem : vx_event.Type_event = item as vx_event.Type_event
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_event.Class_eventlist = vx_event.Class_eventlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.e_eventlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_eventlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_event.t_event), // allowtypes
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

  val e_eventlist : vx_event.Type_eventlist = vx_event.Class_eventlist()
  val t_eventlist : vx_event.Type_eventlist = vx_event.Class_eventlist()

  interface Type_eventmap : vx_core.Type_map {
    fun vx_mapevent() : Map<String, vx_event.Type_event>
    fun vx_event(key : vx_core.Type_string) : vx_event.Type_event
  }

  class Class_eventmap : vx_core.Class_base, Type_eventmap {
    constructor() {}

    var vx_p_map : Map<String, vx_event.Type_event> = vx_core.immutablemap(LinkedHashMap<String, vx_event.Type_event>())

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>(this.vx_p_map)
      return vx_core.immutablemap(map)
    }

    override fun vx_set(name : vx_core.Type_string, value : vx_core.Type_any) : vx_core.Type_boolean {
      var output : vx_core.Type_boolean = vx_core.c_false
      if (false) {
      } else if (value is vx_event.Type_event) {
        var castval : vx_event.Type_event = value as vx_event.Type_event
        var key : String = name.vx_string()
        if (key.startsWith(":")) {
          key = key.substring(1)
        }
        var map : MutableMap<String, vx_event.Type_event> = LinkedHashMap<String, vx_event.Type_event>(this.vx_p_map)
        if (castval == vx_event.e_event) {
          map.remove(key)
        } else {
          map.put(key, castval)
        }
        this.vx_p_map = vx_core.immutablemap(map)
        output = vx_core.c_true
      }
      return output
    }

    override fun vx_event(key : vx_core.Type_string) : vx_event.Type_event {
      var output : vx_event.Type_event = vx_event.e_event
      var map : vx_event.Class_eventmap = this
      var skey : String = key.vx_string()
      var mapval : Map<String, vx_event.Type_event> = map.vx_p_map
      output = mapval.getOrDefault(skey, vx_event.e_event)
      return output
    }

    override fun vx_mapevent() : Map<String, vx_event.Type_event> {
      var output : Map<String, vx_event.Type_event> = this.vx_p_map
      return output
    }

    override fun vx_any(key : vx_core.Type_string) : vx_core.Type_any {
      var output : vx_core.Type_any = this.vx_event(key)
      return output
    }


    override fun vx_new_from_map(mapval : Map<String, vx_core.Type_any>) : vx_core.Type_map {
      var output : vx_event.Class_eventmap = vx_event.Class_eventmap()
      var msgblock : vx_core.Type_msgblock = vx_core.e_msgblock
      var map : MutableMap<String, vx_event.Type_event> = LinkedHashMap<String, vx_event.Type_event>()
      val keys : Set<String> = mapval.keys
      for (key : String in keys) {
        var value : vx_core.Type_any = mapval.getOrDefault(key, vx_core.e_any)
        if (false) {
        } else if (value is vx_event.Type_event) {
          var castval : vx_event.Type_event = value as vx_event.Type_event
          map.put(key, castval)
        } else {
          var msg : vx_core.Type_msg = vx_core.vx_msg_from_error("vx/event/eventmap", ":invalidvalue", value)
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
      var output : vx_event.Type_eventmap = vx_core.vx_copy(vx_event.e_eventmap, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_event.Type_eventmap = this
      var ischanged : Boolean = false
      var value : vx_event.Class_eventmap = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var mapval : MutableMap<String, vx_event.Type_event> = LinkedHashMap<String, vx_event.Type_event>(value.vx_mapevent())
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
            msg = vx_core.vx_msg_from_error("vx/event/eventmap", ":keyexpected", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
        } else {
          var valany : vx_event.Type_event = vx_event.e_event
          if (false) {
          } else if (valsub is vx_event.Type_event) {
            var valallowed : vx_event.Type_event = valsub as vx_event.Type_event
            valany = valallowed
          } else if (valsub is vx_event.Type_event) {
            valany = valsub as vx_event.Type_event
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
            msg = vx_core.vx_msg_from_error("vx/event/eventmap", ":invalidkeyvalue", msgmap)
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
        var work : vx_event.Class_eventmap = vx_event.Class_eventmap()
        work.vx_p_map = vx_core.immutablemap(mapval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.e_eventmap
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_eventmap
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_event.t_event), // allowtypes
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

  val e_eventmap : vx_event.Type_eventmap = vx_event.Class_eventmap()
  val t_eventmap : vx_event.Type_eventmap = vx_event.Class_eventmap()

  class Const_event_change {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/event", // pkgname
        "event-change", // name
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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

    fun const_new(output : vx_event.Type_event) : Unit {
      var outval : vx_event.Class_event = output as vx_event.Class_event
      outval.vx_p_constdef = constdef()
      var value : vx_event.Type_event = vx_core.f_new(
        vx_event.t_event,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("change")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_from = value.from()
      outval.vx_p_to = value.to()
      outval.vx_p_datamap = value.datamap()
      outval.vx_p_event_from_event = value.event_from_event()
      outval.vx_p_event_from_event_async = value.event_from_event_async()
    }

    }
  }

  val c_event_change : vx_event.Type_event = vx_event.Class_event()


  class Const_event_click {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/event", // pkgname
        "event-click", // name
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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

    fun const_new(output : vx_event.Type_event) : Unit {
      var outval : vx_event.Class_event = output as vx_event.Class_event
      outval.vx_p_constdef = constdef()
      var value : vx_event.Type_event = vx_core.f_new(
        vx_event.t_event,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("click")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_from = value.from()
      outval.vx_p_to = value.to()
      outval.vx_p_datamap = value.datamap()
      outval.vx_p_event_from_event = value.event_from_event()
      outval.vx_p_event_from_event_async = value.event_from_event_async()
    }

    }
  }

  val c_event_click : vx_event.Type_event = vx_event.Class_event()


  class Const_event_move {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/event", // pkgname
        "event-move", // name
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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

    fun const_new(output : vx_event.Type_event) : Unit {
      var outval : vx_event.Class_event = output as vx_event.Class_event
      outval.vx_p_constdef = constdef()
      var value : vx_event.Type_event = vx_core.f_new(
        vx_event.t_event,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("move")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_from = value.from()
      outval.vx_p_to = value.to()
      outval.vx_p_datamap = value.datamap()
      outval.vx_p_event_from_event = value.event_from_event()
      outval.vx_p_event_from_event_async = value.event_from_event_async()
    }

    }
  }

  val c_event_move : vx_event.Type_event = vx_event.Class_event()


  class Const_event_select {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/event", // pkgname
        "event-select", // name
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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

    fun const_new(output : vx_event.Type_event) : Unit {
      var outval : vx_event.Class_event = output as vx_event.Class_event
      outval.vx_p_constdef = constdef()
      var value : vx_event.Type_event = vx_core.f_new(
        vx_event.t_event,
        vx_core.vx_new(
          vx_core.t_anylist,
          vx_core.vx_new_string(":name"),
          vx_core.vx_new_string("move")
        )
      )
      outval.vx_p_name = value.name()
      outval.vx_p_from = value.from()
      outval.vx_p_to = value.to()
      outval.vx_p_datamap = value.datamap()
      outval.vx_p_event_from_event = value.event_from_event()
      outval.vx_p_event_from_event_async = value.event_from_event_async()
    }

    }
  }

  val c_event_select : vx_event.Type_event = vx_event.Class_event()


  interface Func_any_from_from_event : vx_core.Func_any_from_any {
    fun <T : vx_core.Type_any> vx_any_from_from_event(generic_any_1 : T, evt : vx_event.Type_event) : T
  }

  class Class_any_from_from_event : vx_core.Class_base, Func_any_from_from_event {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_any_from_from_event = vx_event.Class_any_from_from_event()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_any_from_from_event = vx_event.Class_any_from_from_event()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/event", // pkgname
        "any-from<-event", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
      var output : vx_core.Type_any = vx_event.e_any_from_from_event
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_any_from_from_event
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_event.Type_event = value as vx_event.Type_event
      var outputval : vx_core.Type_any = vx_event.f_any_from_from_event(vx_core.t_any, inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var generic_any_1 : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)))
      var evt : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_event.f_any_from_from_event(generic_any_1, evt)
      return output
    }

    override fun <T : vx_core.Type_any> vx_any_from_from_event(generic_any_1 : T, evt : vx_event.Type_event) : T {
      var output : T = vx_event.f_any_from_from_event(generic_any_1, evt)
      return output
    }

  }

  val e_any_from_from_event : vx_event.Func_any_from_from_event = vx_event.Class_any_from_from_event()
  val t_any_from_from_event : vx_event.Func_any_from_from_event = vx_event.Class_any_from_from_event()

  fun <T : vx_core.Type_any> f_any_from_from_event(generic_any_1 : T, evt : vx_event.Type_event) : T {
    var output : T = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new({ ->
        var value : vx_core.Type_any = evt.from()
        var output_1 : vx_core.Type_any = vx_core.f_any_from_any(
          generic_any_1,
          value
        )
        output_1
      })
    )
    return output
  }


  interface Func_event_from_event : vx_core.Func_any_from_any_context {
    fun vx_event_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_event.Type_event
  }

  class Class_event_from_event : vx_core.Class_base, Func_event_from_event {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_event_from_event = vx_event.Class_event_from_event()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_event_from_event = vx_event.Class_event_from_event()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/event", // pkgname
        "event<-event", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      var output : vx_core.Type_any = vx_event.e_event_from_event
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_event_from_event
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context.IFn) : vx_core.Func_any_from_any_context {
      return vx_core.e_any_from_any_context
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context(generic_any_1 : T, context : vx_core.Type_context, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_event.Type_event = value as vx_event.Type_event
      var outputval : vx_core.Type_any = vx_event.f_event_from_event(context, inputval)
      output = vx_core.f_any_from_any_context(generic_any_1, context, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var evt : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_event.f_event_from_event(context, evt)
      return output
    }

    override fun vx_event_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_event.Type_event {
      var output : vx_event.Type_event = vx_event.f_event_from_event(context, evt)
      return output
    }

  }

  val e_event_from_event : vx_event.Func_event_from_event = vx_event.Class_event_from_event()
  val t_event_from_event : vx_event.Func_event_from_event = vx_event.Class_event_from_event()

  fun f_event_from_event(context : vx_core.Type_context, evt : vx_event.Type_event) : vx_event.Type_event {
    var output : vx_event.Type_event = vx_event.e_event
    output = evt
    return output
  }


  interface Func_event_from_event_async : vx_core.Func_any_from_any_context_async {
    fun vx_event_from_event_async(context : vx_core.Type_context, evt : vx_event.Type_event) : CompletableFuture<vx_event.Type_event>
  }

  class Class_event_from_event_async : vx_core.Class_base, Func_event_from_event_async {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_event_from_event_async = vx_event.Class_event_from_event_async()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_event_from_event_async = vx_event.Class_event_from_event_async()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/event", // pkgname
        "event<-event-async", // name
        0, // idx
        true, // async
        vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      var output : vx_core.Type_any = vx_event.e_event_from_event_async
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_event_from_event_async
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any_context_async.IFn) : vx_core.Func_any_from_any_context_async {
      return vx_core.e_any_from_any_context_async
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any_context_async(generic_any_1 : T, context : vx_core.Type_context, value : U) : CompletableFuture<T> {
      var inputval : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, value)
      var future : CompletableFuture<vx_event.Type_event> = vx_event.f_event_from_event_async(context, inputval)
      var output : CompletableFuture<T> = future as (CompletableFuture<T>)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : CompletableFuture<vx_core.Type_any> {
      var output : CompletableFuture<vx_core.Type_any> = vx_core.vx_async_new_from_value(vx_core.e_any)
      var context : vx_core.Type_context = vx_core.f_any_from_any(vx_core.t_context, arglist.vx_any(vx_core.vx_new_int(0)))
      var evt : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, arglist.vx_any(vx_core.vx_new_int(0)))
      var future : CompletableFuture<vx_event.Type_event> = vx_event.f_event_from_event_async(context, evt)
      output = vx_core.vx_async_from_async(vx_core.t_any, future)
      return output
    }

    override fun vx_event_from_event_async(context : vx_core.Type_context, evt : vx_event.Type_event) : CompletableFuture<vx_event.Type_event> {
      var output : CompletableFuture<vx_event.Type_event> = vx_event.f_event_from_event_async(context, evt)
      return output
    }

  }

  val e_event_from_event_async : vx_event.Func_event_from_event_async = vx_event.Class_event_from_event_async()
  val t_event_from_event_async : vx_event.Func_event_from_event_async = vx_event.Class_event_from_event_async()

  fun f_event_from_event_async(context : vx_core.Type_context, evt : vx_event.Type_event) : CompletableFuture<vx_event.Type_event> {
    var output : CompletableFuture<vx_event.Type_event> = vx_core.vx_async_new_from_value(vx_event.e_event)
    return output
  }


  interface Func_eventmap_from_eventlist : vx_core.Func_any_from_any {
    fun vx_eventmap_from_eventlist(eventlist : vx_event.Type_eventlist) : vx_event.Type_eventmap
  }

  class Class_eventmap_from_eventlist : vx_core.Class_base, Func_eventmap_from_eventlist {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_eventmap_from_eventlist = vx_event.Class_eventmap_from_eventlist()
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      val output : vx_event.Class_eventmap_from_eventlist = vx_event.Class_eventmap_from_eventlist()
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.t_func.vx_typedef()
      return output
    }

    override fun vx_funcdef() : vx_core.Type_funcdef {
      var output : vx_core.Type_funcdef = vx_core.funcdef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/event", // pkgname
          "eventmap", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_event.t_event), // allowtypes
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
      var output : vx_core.Type_any = vx_event.e_eventmap_from_eventlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_event.t_eventmap_from_eventlist
      return output
    }

    override fun vx_fn_new(fn : vx_core.Class_any_from_any.IFn) : vx_core.Func_any_from_any {
      return vx_core.e_any_from_any
    }

    override fun <T : vx_core.Type_any, U : vx_core.Type_any> vx_any_from_any(generic_any_1 : T, value : U) : T {
      var output : T = vx_core.f_empty(generic_any_1)
      var inputval : vx_event.Type_eventlist = value as vx_event.Type_eventlist
      var outputval : vx_core.Type_any = vx_event.f_eventmap_from_eventlist(inputval)
      output = vx_core.f_any_from_any(generic_any_1, outputval)
      return output
    }

    override fun vx_repl(arglist : vx_core.Type_anylist) : vx_core.Type_any {
      var output : vx_core.Type_any = vx_core.e_any
      var eventlist : vx_event.Type_eventlist = vx_core.f_any_from_any(vx_event.t_eventlist, arglist.vx_any(vx_core.vx_new_int(0)))
      output = vx_event.f_eventmap_from_eventlist(eventlist)
      return output
    }

    override fun vx_eventmap_from_eventlist(eventlist : vx_event.Type_eventlist) : vx_event.Type_eventmap {
      var output : vx_event.Type_eventmap = vx_event.f_eventmap_from_eventlist(eventlist)
      return output
    }

  }

  val e_eventmap_from_eventlist : vx_event.Func_eventmap_from_eventlist = vx_event.Class_eventmap_from_eventlist()
  val t_eventmap_from_eventlist : vx_event.Func_eventmap_from_eventlist = vx_event.Class_eventmap_from_eventlist()

  fun f_eventmap_from_eventlist(eventlist : vx_event.Type_eventlist) : vx_event.Type_eventmap {
    var output : vx_event.Type_eventmap = vx_event.e_eventmap
    output = vx_core.f_map_from_list(
      vx_event.t_eventmap,
      eventlist,
      vx_core.t_any_from_any.vx_fn_new({evt_any : vx_core.Type_any ->
        var evt : vx_event.Type_event = vx_core.f_any_from_any(vx_event.t_event, evt_any)
        var output_1 : vx_core.Type_any = evt.name()
        output_1
      })
    )
    return output
  }


  init {
    Const_event_change.const_new(c_event_change)
    Const_event_click.const_new(c_event_click)
    Const_event_move.const_new(c_event_move)
    Const_event_select.const_new(c_event_select)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("event", vx_event.t_event)
    maptype.put("eventlist", vx_event.t_eventlist)
    maptype.put("eventmap", vx_event.t_eventmap)
    mapconst.put("event-change", vx_event.c_event_change)
    mapconst.put("event-click", vx_event.c_event_click)
    mapconst.put("event-move", vx_event.c_event_move)
    mapconst.put("event-select", vx_event.c_event_select)
    mapfunc.put("any-from<-event", vx_event.t_any_from_from_event)
    mapfunc.put("event<-event", vx_event.t_event_from_event)
    mapfunc.put("event<-event-async", vx_event.t_event_from_event_async)
    mapfunc.put("eventmap<-eventlist", vx_event.t_eventmap_from_eventlist)
    vx_core.vx_global_package_set("vx/event", maptype, mapconst, mapfunc)
  }

}
