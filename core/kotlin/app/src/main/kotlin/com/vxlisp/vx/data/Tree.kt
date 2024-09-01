package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_tree {


  interface Type_branch : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun brancharrow() : vx_data_tree.Type_brancharrow
    fun branchlist() : vx_data_tree.Type_branchlist
    fun leaflist() : vx_data_tree.Type_leaflist
    fun parentbranch() : vx_data_tree.Type_branch
    fun tree() : vx_data_tree.Type_tree
  }

  class Class_branch : vx_core.Class_base, Type_branch {
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

    var vx_p_brancharrow : vx_data_tree.Type_brancharrow? = null

    override fun brancharrow() : vx_data_tree.Type_brancharrow {
      var output : vx_data_tree.Type_brancharrow = vx_data_tree.e_brancharrow
      var testnull : vx_data_tree.Type_brancharrow? = vx_p_brancharrow
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_branchlist : vx_data_tree.Type_branchlist? = null

    override fun branchlist() : vx_data_tree.Type_branchlist {
      var output : vx_data_tree.Type_branchlist = vx_data_tree.e_branchlist
      var testnull : vx_data_tree.Type_branchlist? = vx_p_branchlist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_leaflist : vx_data_tree.Type_leaflist? = null

    override fun leaflist() : vx_data_tree.Type_leaflist {
      var output : vx_data_tree.Type_leaflist = vx_data_tree.e_leaflist
      var testnull : vx_data_tree.Type_leaflist? = vx_p_leaflist
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_parentbranch : vx_data_tree.Type_branch? = null

    override fun parentbranch() : vx_data_tree.Type_branch {
      var output : vx_data_tree.Type_branch = vx_data_tree.e_branch
      var testnull : vx_data_tree.Type_branch? = vx_p_parentbranch
      if (testnull != null) {
        output = testnull
      }
      return output
    }

    var vx_p_tree : vx_data_tree.Type_tree? = null

    override fun tree() : vx_data_tree.Type_tree {
      var output : vx_data_tree.Type_tree = vx_data_tree.e_tree
      var testnull : vx_data_tree.Type_tree? = vx_p_tree
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
      } else if ((skey==":brancharrow")) {
        output = this.brancharrow()
      } else if ((skey==":branchlist")) {
        output = this.branchlist()
      } else if ((skey==":leaflist")) {
        output = this.leaflist()
      } else if ((skey==":parentbranch")) {
        output = this.parentbranch()
      } else if ((skey==":tree")) {
        output = this.tree()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":brancharrow", this.brancharrow())
      map.put(":branchlist", this.branchlist())
      map.put(":leaflist", this.leaflist())
      map.put(":parentbranch", this.parentbranch())
      map.put(":tree", this.tree())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_branch = vx_core.vx_copy(vx_data_tree.e_branch, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_branch = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_branch = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_brancharrow : vx_data_tree.Type_brancharrow = value.brancharrow()
      var vx_p_branchlist : vx_data_tree.Type_branchlist = value.branchlist()
      var vx_p_leaflist : vx_data_tree.Type_leaflist = value.leaflist()
      var vx_p_parentbranch : vx_data_tree.Type_branch = value.parentbranch()
      var vx_p_tree : vx_data_tree.Type_tree = value.tree()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":brancharrow")
      validkeys.add(":branchlist")
      validkeys.add(":leaflist")
      validkeys.add(":parentbranch")
      validkeys.add(":tree")
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
            msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":brancharrow")) {
            if (valsub == vx_p_brancharrow) {
            } else if (valsub is vx_data_tree.Type_brancharrow) {
              var valbrancharrow : vx_data_tree.Type_brancharrow = valsub as vx_data_tree.Type_brancharrow
              ischanged = true
              vx_p_brancharrow = valbrancharrow
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("brancharrow"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":branchlist")) {
            if (valsub == vx_p_branchlist) {
            } else if (valsub is vx_data_tree.Type_branchlist) {
              var valbranchlist : vx_data_tree.Type_branchlist = valsub as vx_data_tree.Type_branchlist
              ischanged = true
              vx_p_branchlist = valbranchlist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("branchlist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":leaflist")) {
            if (valsub == vx_p_leaflist) {
            } else if (valsub is vx_data_tree.Type_leaflist) {
              var valleaflist : vx_data_tree.Type_leaflist = valsub as vx_data_tree.Type_leaflist
              ischanged = true
              vx_p_leaflist = valleaflist
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("leaflist"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":parentbranch")) {
            if (valsub == vx_p_parentbranch) {
            } else if (valsub is vx_data_tree.Type_branch) {
              var valparentbranch : vx_data_tree.Type_branch = valsub as vx_data_tree.Type_branch
              ischanged = true
              vx_p_parentbranch = valparentbranch
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("parentbranch"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":tree")) {
            if (valsub == vx_p_tree) {
            } else if (valsub is vx_data_tree.Type_tree) {
              var valtree : vx_data_tree.Type_tree = valsub as vx_data_tree.Type_tree
              ischanged = true
              vx_p_tree = valtree
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("tree"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_branch = vx_data_tree.Class_branch()
        work.vx_p_id = vx_p_id
        work.vx_p_brancharrow = vx_p_brancharrow
        work.vx_p_branchlist = vx_p_branchlist
        work.vx_p_leaflist = vx_p_leaflist
        work.vx_p_parentbranch = vx_p_parentbranch
        work.vx_p_tree = vx_p_tree
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_branch
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_branch
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "branch", // name
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

  val e_branch : vx_data_tree.Type_branch = vx_data_tree.Class_branch()
  val t_branch : vx_data_tree.Type_branch = vx_data_tree.Class_branch()

  interface Type_brancharrow : vx_core.Type_any {
  }

  class Class_brancharrow : vx_core.Class_base, Type_brancharrow {
    constructor() {}

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_brancharrow = vx_core.vx_copy(vx_data_tree.e_brancharrow, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_brancharrow = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_brancharrow = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_brancharrow = vx_data_tree.Class_brancharrow()
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_brancharrow
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_brancharrow
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "brancharrow", // name
        "", // extends
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

  val e_brancharrow : vx_data_tree.Type_brancharrow = vx_data_tree.Class_brancharrow()
  val t_brancharrow : vx_data_tree.Type_brancharrow = vx_data_tree.Class_brancharrow()

  interface Type_branchlist : vx_core.Type_list {
    fun vx_listbranch() : List<vx_data_tree.Type_branch>
    fun vx_branch(index : vx_core.Type_int) : vx_data_tree.Type_branch
  }

  class Class_branchlist : vx_core.Class_base, Type_branchlist {
    constructor() {}

    var vx_p_list : List<vx_data_tree.Type_branch> = vx_core.immutablelist(
      ArrayList<vx_data_tree.Type_branch>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_branch(index : vx_core.Type_int) : vx_data_tree.Type_branch {
      var output : vx_data_tree.Type_branch = vx_data_tree.e_branch
      var list : vx_data_tree.Class_branchlist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_tree.Type_branch> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listbranch() : List<vx_data_tree.Type_branch> {
      var output : List<vx_data_tree.Type_branch> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_tree.Type_branch = this.vx_branch(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_branchlist = vx_core.vx_copy(vx_data_tree.e_branchlist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_branchlist = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_branchlist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_tree.Type_branch> = ArrayList<vx_data_tree.Type_branch>(value.vx_listbranch())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_tree.Type_branchlist) {
          var multi : vx_data_tree.Type_branchlist = valsub as vx_data_tree.Type_branchlist
          ischanged = true
          listval.addAll(multi.vx_listbranch())
        } else if (valsub is vx_data_tree.Type_branch) {
          var allowsub : vx_data_tree.Type_branch = valsub as vx_data_tree.Type_branch
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_tree.Type_branch) {
          ischanged = true
          listval.add(valsub as vx_data_tree.Type_branch)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_tree.Type_branch) {
              var valitem : vx_data_tree.Type_branch = item as vx_data_tree.Type_branch
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_branchlist = vx_data_tree.Class_branchlist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_branchlist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_branchlist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_tree.t_branch), // allowtypes
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

  val e_branchlist : vx_data_tree.Type_branchlist = vx_data_tree.Class_branchlist()
  val t_branchlist : vx_data_tree.Type_branchlist = vx_data_tree.Class_branchlist()

  interface Type_leaf : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun value() : vx_core.Type_any
  }

  class Class_leaf : vx_core.Class_base, Type_leaf {
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
      } else if ((skey==":name")) {
        output = this.name()
      } else if ((skey==":value")) {
        output = this.value()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":value", this.value())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_leaf = vx_core.vx_copy(vx_data_tree.e_leaf, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_leaf = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_leaf = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_value : vx_core.Type_any = value.value()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
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
            msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_leaf = vx_data_tree.Class_leaf()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_value = vx_p_value
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_leaf
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_leaf
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "leaf", // name
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

  val e_leaf : vx_data_tree.Type_leaf = vx_data_tree.Class_leaf()
  val t_leaf : vx_data_tree.Type_leaf = vx_data_tree.Class_leaf()

  interface Type_leaflist : vx_core.Type_list {
    fun vx_listleaf() : List<vx_data_tree.Type_leaf>
    fun vx_leaf(index : vx_core.Type_int) : vx_data_tree.Type_leaf
  }

  class Class_leaflist : vx_core.Class_base, Type_leaflist {
    constructor() {}

    var vx_p_list : List<vx_data_tree.Type_leaf> = vx_core.immutablelist(
      ArrayList<vx_data_tree.Type_leaf>()
    )

    override fun vx_list() : List<vx_core.Type_any> {
      var output : List<vx_core.Type_any> = vx_core.immutablelist(
        ArrayList<vx_core.Type_any>(this.vx_p_list)
      )
      return output
    }

    override fun vx_leaf(index : vx_core.Type_int) : vx_data_tree.Type_leaf {
      var output : vx_data_tree.Type_leaf = vx_data_tree.e_leaf
      var list : vx_data_tree.Class_leaflist = this
      var iindex : Int = index.vx_int()
      var listval : List<vx_data_tree.Type_leaf> = list.vx_p_list
      if (iindex < listval.size) {
        output = listval.get(iindex)
      }
      return output
    }

    override fun vx_listleaf() : List<vx_data_tree.Type_leaf> {
      var output : List<vx_data_tree.Type_leaf> = this.vx_p_list
      return output
    }

    override fun vx_any(index : vx_core.Type_int) : vx_core.Type_any {
      var output : vx_data_tree.Type_leaf = this.vx_leaf(index)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_leaflist = vx_core.vx_copy(vx_data_tree.e_leaflist, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_leaflist = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_leaflist = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var listval : MutableList<vx_data_tree.Type_leaf> = ArrayList<vx_data_tree.Type_leaf>(value.vx_listleaf())
      var msg : vx_core.Type_msg
      for (valsub : Any in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub)
        } else if (valsub is vx_data_tree.Type_leaflist) {
          var multi : vx_data_tree.Type_leaflist = valsub as vx_data_tree.Type_leaflist
          ischanged = true
          listval.addAll(multi.vx_listleaf())
        } else if (valsub is vx_data_tree.Type_leaf) {
          var allowsub : vx_data_tree.Type_leaf = valsub as vx_data_tree.Type_leaf
          ischanged = true
          listval.add(allowsub)
        } else if (valsub is vx_data_tree.Type_leaf) {
          ischanged = true
          listval.add(valsub as vx_data_tree.Type_leaf)
        } else if (valsub is List<*>) {
          var listunknown : List<Any> = valsub as List<Any>
          for (item : Any in listunknown) {
            if (false) {
            } else if (item is vx_data_tree.Type_leaf) {
              var valitem : vx_data_tree.Type_leaf = item as vx_data_tree.Type_leaf
              ischanged = true
              listval.add(valitem)
            }
          }
        } else if (valsub is vx_core.Type_any) {
          var anyinvalid : vx_core.Type_any = valsub as vx_core.Type_any
          msg = vx_core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", anyinvalid)
          msgblock = vx_core.vx_copy(msgblock, msg)
        } else {
          msg = vx_core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", vx_core.vx_new_string(valsub.toString()))
          msgblock = vx_core.vx_copy(msgblock, msg)
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_leaflist = vx_data_tree.Class_leaflist()
        work.vx_p_list = vx_core.immutablelist(listval)
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_leaflist
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_leaflist
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        vx_core.e_typelist, // traits
        vx_core.vx_new(vx_core.t_typelist, vx_data_tree.t_leaf), // allowtypes
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

  val e_leaflist : vx_data_tree.Type_leaflist = vx_data_tree.Class_leaflist()
  val t_leaflist : vx_data_tree.Type_leaflist = vx_data_tree.Class_leaflist()

  interface Type_tree : vx_core.Type_struct {
    fun id() : vx_core.Type_string
    fun name() : vx_core.Type_string
    fun branch() : vx_data_tree.Type_branch
  }

  class Class_tree : vx_core.Class_base, Type_tree {
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

    var vx_p_branch : vx_data_tree.Type_branch? = null

    override fun branch() : vx_data_tree.Type_branch {
      var output : vx_data_tree.Type_branch = vx_data_tree.e_branch
      var testnull : vx_data_tree.Type_branch? = vx_p_branch
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
      } else if ((skey==":branch")) {
        output = this.branch()
      }
      return output
    }

    override fun vx_map() : Map<String, vx_core.Type_any> {
      var map : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
      map.put(":id", this.id())
      map.put(":name", this.name())
      map.put(":branch", this.branch())
      var output : Map<String, vx_core.Type_any> = vx_core.immutablemap(map)
      return output
    }

    override fun vx_new(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_tree = vx_core.vx_copy(vx_data_tree.e_tree, *vals)
      return output
    }

    override fun vx_copy(vararg vals : Any) : vx_core.Type_any {
      var output : vx_data_tree.Type_tree = this
      var ischanged : Boolean = false
      var value : vx_data_tree.Class_tree = this
      var msgblock : vx_core.Type_msgblock = vx_core.vx_msgblock_from_copy_arrayval(value, vals)
      if (this.vx_constdef() != vx_core.e_constdef) {
        ischanged = true
      }
      var vx_p_id : vx_core.Type_string = value.id()
      var vx_p_name : vx_core.Type_string = value.name()
      var vx_p_branch : vx_data_tree.Type_branch = value.branch()
      var validkeys : MutableList<String> = ArrayList<String>()
      validkeys.add(":id")
      validkeys.add(":name")
      validkeys.add(":branch")
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
            msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidkeytype", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap)
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
              msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else if ((key==":branch")) {
            if (valsub == vx_p_branch) {
            } else if (valsub is vx_data_tree.Type_branch) {
              var valbranch : vx_data_tree.Type_branch = valsub as vx_data_tree.Type_branch
              ischanged = true
              vx_p_branch = valbranch
            } else {
              if (false) {
              } else if (valsub is vx_core.Type_any) {
                var valinvalid : vx_core.Type_any = valsub as vx_core.Type_any
                msgval = valinvalid
              } else {
                msgval = vx_core.vx_new_string(valsub.toString())
              }
              var mapany : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
              mapany.put("key", vx_core.vx_new_string("branch"))
              mapany.put("value", msgval)
              var msgmap : vx_core.Type_map = vx_core.t_anymap.vx_new_from_map(mapany)
              msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap)
              msgblock = vx_core.vx_copy(msgblock, msg)
            }
          } else {
            msgval = vx_core.vx_new_string(key)
            msg = vx_core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval)
            msgblock = vx_core.vx_copy(msgblock, msg)
          }
          key = ""
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        var work : vx_data_tree.Class_tree = vx_data_tree.Class_tree()
        work.vx_p_id = vx_p_id
        work.vx_p_name = vx_p_name
        work.vx_p_branch = vx_p_branch
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock
        }
        output = work
      }
      return output
    }

    override fun vx_empty() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.e_tree
      return output
    }

    override fun vx_type() : vx_core.Type_any {
      var output : vx_core.Type_any = vx_data_tree.t_tree
      return output
    }

    override fun vx_typedef() : vx_core.Type_typedef {
      var output : vx_core.Type_typedef = vx_core.typedef_new(
        "vx/data/tree", // pkgname
        "tree", // name
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

  val e_tree : vx_data_tree.Type_tree = vx_data_tree.Class_tree()
  val t_tree : vx_data_tree.Type_tree = vx_data_tree.Class_tree()

  class Const_brancharrow_down {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        vx_core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
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

    fun const_new(output : vx_data_tree.Type_brancharrow) : Unit {
      var outval : vx_data_tree.Class_brancharrow = output as vx_data_tree.Class_brancharrow
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_brancharrow_down : vx_data_tree.Type_brancharrow = vx_data_tree.Class_brancharrow()


  class Const_brancharrow_up {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        vx_core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
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

    fun const_new(output : vx_data_tree.Type_brancharrow) : Unit {
      var outval : vx_data_tree.Class_brancharrow = output as vx_data_tree.Class_brancharrow
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_brancharrow_up : vx_data_tree.Type_brancharrow = vx_data_tree.Class_brancharrow()


  class Const_brancharrow_updown {
    constructor() {}
    companion object {

    fun constdef() : vx_core.Type_constdef {
      var output : vx_core.Type_constdef = vx_core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        vx_core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
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

    fun const_new(output : vx_data_tree.Type_brancharrow) : Unit {
      var outval : vx_data_tree.Class_brancharrow = output as vx_data_tree.Class_brancharrow
      outval.vx_p_constdef = constdef()
    }

    }
  }

  val c_brancharrow_updown : vx_data_tree.Type_brancharrow = vx_data_tree.Class_brancharrow()


  init {
    Const_brancharrow_down.const_new(c_brancharrow_down)
    Const_brancharrow_up.const_new(c_brancharrow_up)
    Const_brancharrow_updown.const_new(c_brancharrow_updown)
    var maptype : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapconst : MutableMap<String, vx_core.Type_any> = LinkedHashMap<String, vx_core.Type_any>()
    var mapfunc : MutableMap<String, vx_core.Type_func> = LinkedHashMap<String, vx_core.Type_func>()
    maptype.put("branch", vx_data_tree.t_branch)
    maptype.put("brancharrow", vx_data_tree.t_brancharrow)
    maptype.put("branchlist", vx_data_tree.t_branchlist)
    maptype.put("leaf", vx_data_tree.t_leaf)
    maptype.put("leaflist", vx_data_tree.t_leaflist)
    maptype.put("tree", vx_data_tree.t_tree)
    mapconst.put("brancharrow-down", vx_data_tree.c_brancharrow_down)
    mapconst.put("brancharrow-up", vx_data_tree.c_brancharrow_up)
    mapconst.put("brancharrow-updown", vx_data_tree.c_brancharrow_updown)
    vx_core.vx_global_package_set("vx/data/tree", maptype, mapconst, mapfunc)
  }

}
