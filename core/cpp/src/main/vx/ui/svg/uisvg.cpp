#include "../../../vx/core.hpp"
#include "../../../vx/ui/ui.hpp"
#include "uisvg.hpp"

namespace vx_ui_svg_uisvg {




  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      vx_core::vx_global_package_set("vx/ui/svg/uisvg", maptype, mapconst, mapfunc);
	   }
  // }

}
