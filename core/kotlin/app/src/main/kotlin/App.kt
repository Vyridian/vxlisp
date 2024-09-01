/**
 * App
 */
import com.vxlisp.vx.*
import com.vxlisp.vx.translation.*

  fun main(args : Array<String>) {
    try {
      var output : String = ""
      val arglist : vx_core.Type_anylist = vx_core.vx_anylist_from_arraystring(*args)
      val context : vx_core.Type_context = vx_translation_en.f_context_en(arglist)
      val mainstring : vx_core.Type_string = vx_core.f_main(arglist)
      output = mainstring.vx_string()
      println(output)
    } catch (e : Exception) {
      println(e.toString())
    }
  }
