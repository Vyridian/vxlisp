/**
 * App
 */

import com.vxlisp.vx.Core as vx_core

package App

  fun main(args : Array<String>) {
    try {
      var output : String
      val arglist : vx_core.Type_anylist = vx_core.vx_anylist_from_arraystring(args)
      val context : vx_core.Type_context = vx_core.f_context_main(arglist)
      val mainstring : vx_core.Type_string = vx_core.f_main(arglist)
      output = mainstring.vx_string()
      println(output)
    } catch (e : Exception) {
      println(e.toString())
    }
  }
