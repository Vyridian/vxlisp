package com.vxlisp.vx.ui.svg;

import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import com.vxlisp.vx.ui.*;

public final class Uisvg {


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    Core.vx_global_package_set("vx/ui/svg/uisvg", maptype, mapconst, mapfunc);
  }

}
