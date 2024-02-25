'strict mode'

import vx_core from "../../../vx/core.js"
import vx_ui_ui from "../../../vx/ui/ui.js"


export default class vx_ui_svg_uisvg {



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/ui/svg/uisvg",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

  }
}
