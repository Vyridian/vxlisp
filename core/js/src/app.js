'strict mode'

import vx_core from "../src/vx/core.js"
import vx_type from "../src/vx/type.js"
import vx_web_htmldoc from "../src/vx/web/htmldoc.js"
import vx_translation_en from "../src/vx/translation/en.js"

export default class app {

  static async f_main(arglist) {
    const context = vx_translation_en.f_context_en(...arglist)
    const output = vx_core.f_main(...arglist)
    return output
  }

  static async f_htmlmain() {
    const argtext = vx_web_htmldoc.f_string_from_id("args")
    const elem = document.getElementById("args")
    const arglist = vx_type.f_stringlist_from_string_split(argtext, " ")
    const mainstring = await app.f_main(arglist)
    vx_web_htmldoc.f_boolean_write_from_id_htmltext("display", mainstring)
  }

}

