package com.vxlisp.vx.ui;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class Ui {


  /**
   * type: align
   * Universal Alignment
   * (type align)
   */
  public interface Type_align extends Core.Type_struct {
  }

  public static class Class_align extends Core.Class_base implements Type_align {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_align output = Core.vx_copy(Ui.e_align, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_align output = this;
      boolean ischanged = false;
      Ui.Class_align value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_align work = new Ui.Class_align();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_align;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_align;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "align", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_align e_align = new Ui.Class_align();
  public static final Ui.Type_align t_align = new Ui.Class_align();

  /**
   * type: bounds
   * Universal Bounds
   * (type bounds)
   */
  public interface Type_bounds extends Core.Type_struct {
    public Core.Type_int left();
    public Core.Type_int right();
    public Core.Type_int top();
    public Core.Type_int bottom();
  }

  public static class Class_bounds extends Core.Class_base implements Type_bounds {

    public Core.Type_int vx_p_left = null;

    @Override
    public Core.Type_int left() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_left;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_right = null;

    @Override
    public Core.Type_int right() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_right;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_top = null;

    @Override
    public Core.Type_int top() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_top;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_bottom = null;

    @Override
    public Core.Type_int bottom() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_bottom;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":left"))) {
        output = this.left();
      } else if ((skey.equals(":right"))) {
        output = this.right();
      } else if ((skey.equals(":top"))) {
        output = this.top();
      } else if ((skey.equals(":bottom"))) {
        output = this.bottom();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":left", this.left());
      map.put(":right", this.right());
      map.put(":top", this.top());
      map.put(":bottom", this.bottom());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_bounds output = Core.vx_copy(Ui.e_bounds, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_bounds output = this;
      boolean ischanged = false;
      Ui.Class_bounds value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_int vx_p_left = value.left();
      Core.Type_int vx_p_right = value.right();
      Core.Type_int vx_p_top = value.top();
      Core.Type_int vx_p_bottom = value.bottom();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":left");
      validkeys.add(":right");
      validkeys.add(":top");
      validkeys.add(":bottom");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":left"))) {
            if (valsub == vx_p_left) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valleft = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_left = valleft;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_left = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("left"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":right"))) {
            if (valsub == vx_p_right) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valright = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_right = valright;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_right = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("right"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":top"))) {
            if (valsub == vx_p_top) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valtop = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_top = valtop;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_top = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("top"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":bottom"))) {
            if (valsub == vx_p_bottom) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valbottom = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_bottom = valbottom;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_bottom = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("bottom"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_bounds work = new Ui.Class_bounds();
        work.vx_p_left = vx_p_left;
        work.vx_p_right = vx_p_right;
        work.vx_p_top = vx_p_top;
        work.vx_p_bottom = vx_p_bottom;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_bounds;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_bounds;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "bounds", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_bounds e_bounds = new Ui.Class_bounds();
  public static final Ui.Type_bounds t_bounds = new Ui.Class_bounds();

  /**
   * type: cursor
   * Univeral Cursor Type
   * (type cursor)
   */
  public interface Type_cursor extends Core.Type_struct {
  }

  public static class Class_cursor extends Core.Class_base implements Type_cursor {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_cursor output = Core.vx_copy(Ui.e_cursor, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_cursor output = this;
      boolean ischanged = false;
      Ui.Class_cursor value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_cursor work = new Ui.Class_cursor();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_cursor;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_cursor;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_cursor e_cursor = new Ui.Class_cursor();
  public static final Ui.Type_cursor t_cursor = new Ui.Class_cursor();

  /**
   * type: cursor-pointer
   * (type cursor-pointer)
   */
  public interface Type_cursor_pointer extends Core.Type_any {
  }

  public static class Class_cursor_pointer extends Core.Class_base implements Type_cursor_pointer {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_cursor_pointer output = Core.vx_copy(Ui.e_cursor_pointer, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_cursor_pointer output = this;
      boolean ischanged = false;
      Ui.Class_cursor_pointer value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_cursor_pointer work = new Ui.Class_cursor_pointer();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_cursor_pointer;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_cursor_pointer;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor-pointer", // name
        ":cursor", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_cursor_pointer e_cursor_pointer = new Ui.Class_cursor_pointer();
  public static final Ui.Type_cursor_pointer t_cursor_pointer = new Ui.Class_cursor_pointer();

  /**
   * type: flip
   * Universal ui flip horizontal or vertical or both.
   * (type flip)
   */
  public interface Type_flip extends Core.Type_struct {
  }

  public static class Class_flip extends Core.Class_base implements Type_flip {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_flip output = Core.vx_copy(Ui.e_flip, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_flip output = this;
      boolean ischanged = false;
      Ui.Class_flip value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_flip work = new Ui.Class_flip();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_flip;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_flip;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "flip", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_flip e_flip = new Ui.Class_flip();
  public static final Ui.Type_flip t_flip = new Ui.Class_flip();

  /**
   * type: font
   * Univeral Font Type
   * (type font)
   */
  public interface Type_font extends Core.Type_struct {
    public Core.Type_string name();
    public Ui.Type_fontface fontface();
    public Core.Type_int fontsize();
    public Ui.Type_fontstyle fontstyle();
  }

  public static class Class_font extends Core.Class_base implements Type_font {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_fontface vx_p_fontface = null;

    @Override
    public Ui.Type_fontface fontface() {
      Ui.Type_fontface output = Ui.e_fontface;
      Ui.Type_fontface testnull = vx_p_fontface;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_fontsize = null;

    @Override
    public Core.Type_int fontsize() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_fontsize;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_fontstyle vx_p_fontstyle = null;

    @Override
    public Ui.Type_fontstyle fontstyle() {
      Ui.Type_fontstyle output = Ui.e_fontstyle;
      Ui.Type_fontstyle testnull = vx_p_fontstyle;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":fontface"))) {
        output = this.fontface();
      } else if ((skey.equals(":fontsize"))) {
        output = this.fontsize();
      } else if ((skey.equals(":fontstyle"))) {
        output = this.fontstyle();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":fontface", this.fontface());
      map.put(":fontsize", this.fontsize());
      map.put(":fontstyle", this.fontstyle());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_font output = Core.vx_copy(Ui.e_font, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_font output = this;
      boolean ischanged = false;
      Ui.Class_font value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Ui.Type_fontface vx_p_fontface = value.fontface();
      Core.Type_int vx_p_fontsize = value.fontsize();
      Ui.Type_fontstyle vx_p_fontstyle = value.fontstyle();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":fontface");
      validkeys.add(":fontsize");
      validkeys.add(":fontstyle");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fontface"))) {
            if (valsub == vx_p_fontface) {
            } else if (valsub instanceof Ui.Type_fontface) {
              Ui.Type_fontface valfontface = (Ui.Type_fontface)valsub;
              ischanged = true;
              vx_p_fontface = valfontface;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fontface"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fontsize"))) {
            if (valsub == vx_p_fontsize) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valfontsize = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_fontsize = valfontsize;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_fontsize = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fontsize"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fontstyle"))) {
            if (valsub == vx_p_fontstyle) {
            } else if (valsub instanceof Ui.Type_fontstyle) {
              Ui.Type_fontstyle valfontstyle = (Ui.Type_fontstyle)valsub;
              ischanged = true;
              vx_p_fontstyle = valfontstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fontstyle"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_font work = new Ui.Class_font();
        work.vx_p_name = vx_p_name;
        work.vx_p_fontface = vx_p_fontface;
        work.vx_p_fontsize = vx_p_fontsize;
        work.vx_p_fontstyle = vx_p_fontstyle;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_font;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_font;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "font", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_font e_font = new Ui.Class_font();
  public static final Ui.Type_font t_font = new Ui.Class_font();

  /**
   * type: fontface
   * Univeral Font Face Type
   * (type fontface)
   */
  public interface Type_fontface extends Core.Type_struct {
    public Core.Type_string name();
    public Core.Type_string weight();
    public Core.Type_string unicode();
    public File.Type_filelist filelist();
  }

  public static class Class_fontface extends Core.Class_base implements Type_fontface {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_weight = null;

    @Override
    public Core.Type_string weight() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_weight;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_unicode = null;

    @Override
    public Core.Type_string unicode() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_unicode;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public File.Type_filelist vx_p_filelist = null;

    @Override
    public File.Type_filelist filelist() {
      File.Type_filelist output = File.e_filelist;
      File.Type_filelist testnull = vx_p_filelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":weight"))) {
        output = this.weight();
      } else if ((skey.equals(":unicode"))) {
        output = this.unicode();
      } else if ((skey.equals(":filelist"))) {
        output = this.filelist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":weight", this.weight());
      map.put(":unicode", this.unicode());
      map.put(":filelist", this.filelist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontface output = Core.vx_copy(Ui.e_fontface, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontface output = this;
      boolean ischanged = false;
      Ui.Class_fontface value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Core.Type_string vx_p_weight = value.weight();
      Core.Type_string vx_p_unicode = value.unicode();
      File.Type_filelist vx_p_filelist = value.filelist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":weight");
      validkeys.add(":unicode");
      validkeys.add(":filelist");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":weight"))) {
            if (valsub == vx_p_weight) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valweight = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_weight = valweight;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_weight = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("weight"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":unicode"))) {
            if (valsub == vx_p_unicode) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valunicode = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_unicode = valunicode;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_unicode = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("unicode"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":filelist"))) {
            if (valsub == vx_p_filelist) {
            } else if (valsub instanceof File.Type_filelist) {
              File.Type_filelist valfilelist = (File.Type_filelist)valsub;
              ischanged = true;
              vx_p_filelist = valfilelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("filelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontface work = new Ui.Class_fontface();
        work.vx_p_name = vx_p_name;
        work.vx_p_weight = vx_p_weight;
        work.vx_p_unicode = vx_p_unicode;
        work.vx_p_filelist = vx_p_filelist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontface;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontface;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontface", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontface e_fontface = new Ui.Class_fontface();
  public static final Ui.Type_fontface t_fontface = new Ui.Class_fontface();

  /**
   * type: fontfacelist
   * List of fontface
   * (type fontfacelist)
   */
  public interface Type_fontfacelist extends Core.Type_list {
    public List<Ui.Type_fontface> vx_listfontface();
    public Ui.Type_fontface vx_fontface(final Core.Type_int index);
  }

  public static class Class_fontfacelist extends Core.Class_base implements Type_fontfacelist {

    public List<Ui.Type_fontface> vx_p_list = Core.immutablelist(
      new ArrayList<Ui.Type_fontface>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Ui.Type_fontface vx_fontface(final Core.Type_int index) {
      Ui.Type_fontface output = Ui.e_fontface;
      Ui.Class_fontfacelist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_fontface> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_fontface> vx_listfontface() {
      List<Ui.Type_fontface> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Ui.Type_fontface output = this.vx_fontface(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontfacelist output = Core.vx_copy(Ui.e_fontfacelist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontfacelist output = this;
      boolean ischanged = false;
      Ui.Class_fontfacelist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Ui.Type_fontface> listval = new ArrayList<Ui.Type_fontface>(value.vx_listfontface());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Ui.Type_fontfacelist) {
          Ui.Type_fontfacelist multi = (Ui.Type_fontfacelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfontface());
        } else if (valsub instanceof Ui.Type_fontface) {
          Ui.Type_fontface allowsub = (Ui.Type_fontface)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Ui.Type_fontface) {
          ischanged = true;
          listval.add((Ui.Type_fontface)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Ui.Type_fontface) {
              Ui.Type_fontface valitem = (Ui.Type_fontface)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontfacelist work = new Ui.Class_fontfacelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontfacelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontfacelist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_fontface), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontfacelist e_fontfacelist = new Ui.Class_fontfacelist();
  public static final Ui.Type_fontfacelist t_fontfacelist = new Ui.Class_fontfacelist();

  /**
   * type: fontfacemap
   * Map of fontface
   * (type fontfacemap)
   */
  public interface Type_fontfacemap extends Core.Type_map {
    public Map<String, Ui.Type_fontface> vx_mapfontface();
    public Ui.Type_fontface vx_fontface(final Core.Type_string key);
  }

  public static class Class_fontfacemap extends Core.Class_base implements Type_fontfacemap {

    public Map<String, Ui.Type_fontface> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_fontface>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_fontface) {
        Ui.Type_fontface castval = (Ui.Type_fontface)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_fontface> map = new LinkedHashMap<String, Ui.Type_fontface>(this.vx_p_map);
        if (castval == Ui.e_fontface) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_fontface vx_fontface(final Core.Type_string key) {
      Ui.Type_fontface output = Ui.e_fontface;
      Ui.Class_fontfacemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_fontface> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_fontface);
      return output;
    }

    @Override
    public Map<String, Ui.Type_fontface> vx_mapfontface() {
      Map<String, Ui.Type_fontface> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_fontface(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_fontfacemap output = new Ui.Class_fontfacemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_fontface> map = new LinkedHashMap<String, Ui.Type_fontface>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_fontface) {
          Ui.Type_fontface castval = (Ui.Type_fontface)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontfacemap output = Core.vx_copy(Ui.e_fontfacemap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontfacemap output = this;
      boolean ischanged = false;
      Ui.Class_fontfacemap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_fontface> mapval = new LinkedHashMap<String, Ui.Type_fontface>(value.vx_mapfontface());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_fontface valany = Ui.e_fontface;
          if (false) {
          } else if (valsub instanceof Ui.Type_fontface) {
            Ui.Type_fontface valallowed = (Ui.Type_fontface)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_fontface) {
            valany = (Ui.Type_fontface)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontfacemap work = new Ui.Class_fontfacemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontfacemap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontfacemap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_fontface), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontfacemap e_fontfacemap = new Ui.Class_fontfacemap();
  public static final Ui.Type_fontfacemap t_fontfacemap = new Ui.Class_fontfacemap();

  /**
   * type: fontmap
   * Map of font
   * (type fontmap)
   */
  public interface Type_fontmap extends Core.Type_map {
    public Map<String, Ui.Type_font> vx_mapfont();
    public Ui.Type_font vx_font(final Core.Type_string key);
  }

  public static class Class_fontmap extends Core.Class_base implements Type_fontmap {

    public Map<String, Ui.Type_font> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_font>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_font) {
        Ui.Type_font castval = (Ui.Type_font)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_font> map = new LinkedHashMap<String, Ui.Type_font>(this.vx_p_map);
        if (castval == Ui.e_font) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_font vx_font(final Core.Type_string key) {
      Ui.Type_font output = Ui.e_font;
      Ui.Class_fontmap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_font> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_font);
      return output;
    }

    @Override
    public Map<String, Ui.Type_font> vx_mapfont() {
      Map<String, Ui.Type_font> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_font(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_fontmap output = new Ui.Class_fontmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_font> map = new LinkedHashMap<String, Ui.Type_font>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_font) {
          Ui.Type_font castval = (Ui.Type_font)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontmap output = Core.vx_copy(Ui.e_fontmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontmap output = this;
      boolean ischanged = false;
      Ui.Class_fontmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_font> mapval = new LinkedHashMap<String, Ui.Type_font>(value.vx_mapfont());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_font valany = Ui.e_font;
          if (false) {
          } else if (valsub instanceof Ui.Type_font) {
            Ui.Type_font valallowed = (Ui.Type_font)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_font) {
            valany = (Ui.Type_font)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontmap work = new Ui.Class_fontmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_font), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontmap e_fontmap = new Ui.Class_fontmap();
  public static final Ui.Type_fontmap t_fontmap = new Ui.Class_fontmap();

  /**
   * type: fontstyle
   * Univeral Font Style Type
   * (type fontstyle)
   */
  public interface Type_fontstyle extends Core.Type_struct {
    public Core.Type_string name();
  }

  public static class Class_fontstyle extends Core.Class_base implements Type_fontstyle {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontstyle output = Core.vx_copy(Ui.e_fontstyle, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontstyle output = this;
      boolean ischanged = false;
      Ui.Class_fontstyle value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontstyle work = new Ui.Class_fontstyle();
        work.vx_p_name = vx_p_name;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontstyle;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontstyle;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstyle", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontstyle e_fontstyle = new Ui.Class_fontstyle();
  public static final Ui.Type_fontstyle t_fontstyle = new Ui.Class_fontstyle();

  /**
   * type: fontstylemap
   * Map of fontstyle
   * (type fontstylemap)
   */
  public interface Type_fontstylemap extends Core.Type_map {
    public Map<String, Ui.Type_fontstyle> vx_mapfontstyle();
    public Ui.Type_fontstyle vx_fontstyle(final Core.Type_string key);
  }

  public static class Class_fontstylemap extends Core.Class_base implements Type_fontstylemap {

    public Map<String, Ui.Type_fontstyle> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_fontstyle>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_fontstyle) {
        Ui.Type_fontstyle castval = (Ui.Type_fontstyle)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_fontstyle> map = new LinkedHashMap<String, Ui.Type_fontstyle>(this.vx_p_map);
        if (castval == Ui.e_fontstyle) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_fontstyle vx_fontstyle(final Core.Type_string key) {
      Ui.Type_fontstyle output = Ui.e_fontstyle;
      Ui.Class_fontstylemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_fontstyle> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_fontstyle);
      return output;
    }

    @Override
    public Map<String, Ui.Type_fontstyle> vx_mapfontstyle() {
      Map<String, Ui.Type_fontstyle> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_fontstyle(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_fontstylemap output = new Ui.Class_fontstylemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_fontstyle> map = new LinkedHashMap<String, Ui.Type_fontstyle>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_fontstyle) {
          Ui.Type_fontstyle castval = (Ui.Type_fontstyle)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_fontstylemap output = Core.vx_copy(Ui.e_fontstylemap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_fontstylemap output = this;
      boolean ischanged = false;
      Ui.Class_fontstylemap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_fontstyle> mapval = new LinkedHashMap<String, Ui.Type_fontstyle>(value.vx_mapfontstyle());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_fontstyle valany = Ui.e_fontstyle;
          if (false) {
          } else if (valsub instanceof Ui.Type_fontstyle) {
            Ui.Type_fontstyle valallowed = (Ui.Type_fontstyle)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_fontstyle) {
            valany = (Ui.Type_fontstyle)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_fontstylemap work = new Ui.Class_fontstylemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontstylemap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontstylemap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstylemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_fontstyle), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_fontstylemap e_fontstylemap = new Ui.Class_fontstylemap();
  public static final Ui.Type_fontstylemap t_fontstylemap = new Ui.Class_fontstylemap();

  /**
   * type: image
   * Univeral Image Type
   * (type image)
   */
  public interface Type_image extends Core.Type_struct {
    public Core.Type_string name();
    public Core.Type_string label();
    public File.Type_file file();
  }

  public static class Class_image extends Core.Class_base implements Type_image {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_label = null;

    @Override
    public Core.Type_string label() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_label;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public File.Type_file vx_p_file = null;

    @Override
    public File.Type_file file() {
      File.Type_file output = File.e_file;
      File.Type_file testnull = vx_p_file;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":label"))) {
        output = this.label();
      } else if ((skey.equals(":file"))) {
        output = this.file();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":label", this.label());
      map.put(":file", this.file());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_image output = Core.vx_copy(Ui.e_image, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_image output = this;
      boolean ischanged = false;
      Ui.Class_image value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Core.Type_string vx_p_label = value.label();
      File.Type_file vx_p_file = value.file();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":label");
      validkeys.add(":file");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":label"))) {
            if (valsub == vx_p_label) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string vallabel = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_label = vallabel;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_label = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("label"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":file"))) {
            if (valsub == vx_p_file) {
            } else if (valsub instanceof File.Type_file) {
              File.Type_file valfile = (File.Type_file)valsub;
              ischanged = true;
              vx_p_file = valfile;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("file"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_image work = new Ui.Class_image();
        work.vx_p_name = vx_p_name;
        work.vx_p_label = vx_p_label;
        work.vx_p_file = vx_p_file;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_image;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_image;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "image", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_image e_image = new Ui.Class_image();
  public static final Ui.Type_image t_image = new Ui.Class_image();

  /**
   * type: layout
   * Universal Layout
   * (type layout)
   */
  public interface Type_layout extends Core.Type_struct {
    public Core.Type_string name();
    public Ui.Func_ui_layout_from_ui_orig_parent fn_layout();
  }

  public static class Class_layout extends Core.Class_base implements Type_layout {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_ui_layout_from_ui_orig_parent vx_p_fn_layout = null;

    @Override
    public Ui.Func_ui_layout_from_ui_orig_parent fn_layout() {
      Ui.Func_ui_layout_from_ui_orig_parent output = Ui.e_ui_layout_from_ui_orig_parent;
      Ui.Func_ui_layout_from_ui_orig_parent testnull = vx_p_fn_layout;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":fn-layout"))) {
        output = this.fn_layout();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":fn-layout", this.fn_layout());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_layout output = Core.vx_copy(Ui.e_layout, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_layout output = this;
      boolean ischanged = false;
      Ui.Class_layout value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Ui.Func_ui_layout_from_ui_orig_parent vx_p_fn_layout = value.fn_layout();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":fn-layout");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fn-layout"))) {
            if (valsub == vx_p_fn_layout) {
            } else if (valsub instanceof Ui.Func_ui_layout_from_ui_orig_parent) {
              Ui.Func_ui_layout_from_ui_orig_parent valfn_layout = (Ui.Func_ui_layout_from_ui_orig_parent)valsub;
              ischanged = true;
              vx_p_fn_layout = valfn_layout;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fn-layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_layout work = new Ui.Class_layout();
        work.vx_p_name = vx_p_name;
        work.vx_p_fn_layout = vx_p_fn_layout;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layout;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layout;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layout", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_layout e_layout = new Ui.Class_layout();
  public static final Ui.Type_layout t_layout = new Ui.Class_layout();

  /**
   * type: layoutengine
   * Pluggable layoutengine
   * (type layoutengine)
   */
  public interface Type_layoutengine extends Core.Type_struct {
    public Core.Type_string name();
    public Ui.Func_boolean_print boolean_print();
    public Ui.Func_boolean_layoutremove_from_ui boolean_layoutremove();
    public Ui.Func_boolean_layoutselected_from_ui boolean_layoutselected();
    public Ui.Func_boolean_layoutvisible_from_ui boolean_layoutvisible();
    public Ui.Type_layoutmap layoutmap();
    public Ui.Type_layout layoutelse();
    public Ui.Func_stylesheet_render stylesheetrender();
  }

  public static class Class_layoutengine extends Core.Class_base implements Type_layoutengine {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_boolean_print vx_p_boolean_print = null;

    @Override
    public Ui.Func_boolean_print boolean_print() {
      Ui.Func_boolean_print output = Ui.e_boolean_print;
      Ui.Func_boolean_print testnull = vx_p_boolean_print;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_boolean_layoutremove_from_ui vx_p_boolean_layoutremove = null;

    @Override
    public Ui.Func_boolean_layoutremove_from_ui boolean_layoutremove() {
      Ui.Func_boolean_layoutremove_from_ui output = Ui.e_boolean_layoutremove_from_ui;
      Ui.Func_boolean_layoutremove_from_ui testnull = vx_p_boolean_layoutremove;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_boolean_layoutselected_from_ui vx_p_boolean_layoutselected = null;

    @Override
    public Ui.Func_boolean_layoutselected_from_ui boolean_layoutselected() {
      Ui.Func_boolean_layoutselected_from_ui output = Ui.e_boolean_layoutselected_from_ui;
      Ui.Func_boolean_layoutselected_from_ui testnull = vx_p_boolean_layoutselected;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_boolean_layoutvisible_from_ui vx_p_boolean_layoutvisible = null;

    @Override
    public Ui.Func_boolean_layoutvisible_from_ui boolean_layoutvisible() {
      Ui.Func_boolean_layoutvisible_from_ui output = Ui.e_boolean_layoutvisible_from_ui;
      Ui.Func_boolean_layoutvisible_from_ui testnull = vx_p_boolean_layoutvisible;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_layoutmap vx_p_layoutmap = null;

    @Override
    public Ui.Type_layoutmap layoutmap() {
      Ui.Type_layoutmap output = Ui.e_layoutmap;
      Ui.Type_layoutmap testnull = vx_p_layoutmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_layout vx_p_layoutelse = null;

    @Override
    public Ui.Type_layout layoutelse() {
      Ui.Type_layout output = Ui.e_layout;
      Ui.Type_layout testnull = vx_p_layoutelse;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Func_stylesheet_render vx_p_stylesheetrender = null;

    @Override
    public Ui.Func_stylesheet_render stylesheetrender() {
      Ui.Func_stylesheet_render output = Ui.e_stylesheet_render;
      Ui.Func_stylesheet_render testnull = vx_p_stylesheetrender;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":boolean-print"))) {
        output = this.boolean_print();
      } else if ((skey.equals(":boolean-layoutremove"))) {
        output = this.boolean_layoutremove();
      } else if ((skey.equals(":boolean-layoutselected"))) {
        output = this.boolean_layoutselected();
      } else if ((skey.equals(":boolean-layoutvisible"))) {
        output = this.boolean_layoutvisible();
      } else if ((skey.equals(":layoutmap"))) {
        output = this.layoutmap();
      } else if ((skey.equals(":layoutelse"))) {
        output = this.layoutelse();
      } else if ((skey.equals(":stylesheetrender"))) {
        output = this.stylesheetrender();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":boolean-print", this.boolean_print());
      map.put(":boolean-layoutremove", this.boolean_layoutremove());
      map.put(":boolean-layoutselected", this.boolean_layoutselected());
      map.put(":boolean-layoutvisible", this.boolean_layoutvisible());
      map.put(":layoutmap", this.layoutmap());
      map.put(":layoutelse", this.layoutelse());
      map.put(":stylesheetrender", this.stylesheetrender());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_layoutengine output = Core.vx_copy(Ui.e_layoutengine, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_layoutengine output = this;
      boolean ischanged = false;
      Ui.Class_layoutengine value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Ui.Func_boolean_print vx_p_boolean_print = value.boolean_print();
      Ui.Func_boolean_layoutremove_from_ui vx_p_boolean_layoutremove = value.boolean_layoutremove();
      Ui.Func_boolean_layoutselected_from_ui vx_p_boolean_layoutselected = value.boolean_layoutselected();
      Ui.Func_boolean_layoutvisible_from_ui vx_p_boolean_layoutvisible = value.boolean_layoutvisible();
      Ui.Type_layoutmap vx_p_layoutmap = value.layoutmap();
      Ui.Type_layout vx_p_layoutelse = value.layoutelse();
      Ui.Func_stylesheet_render vx_p_stylesheetrender = value.stylesheetrender();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":boolean-print");
      validkeys.add(":boolean-layoutremove");
      validkeys.add(":boolean-layoutselected");
      validkeys.add(":boolean-layoutvisible");
      validkeys.add(":layoutmap");
      validkeys.add(":layoutelse");
      validkeys.add(":stylesheetrender");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boolean-print"))) {
            if (valsub == vx_p_boolean_print) {
            } else if (valsub instanceof Ui.Func_boolean_print) {
              Ui.Func_boolean_print valboolean_print = (Ui.Func_boolean_print)valsub;
              ischanged = true;
              vx_p_boolean_print = valboolean_print;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boolean-print"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boolean-layoutremove"))) {
            if (valsub == vx_p_boolean_layoutremove) {
            } else if (valsub instanceof Ui.Func_boolean_layoutremove_from_ui) {
              Ui.Func_boolean_layoutremove_from_ui valboolean_layoutremove = (Ui.Func_boolean_layoutremove_from_ui)valsub;
              ischanged = true;
              vx_p_boolean_layoutremove = valboolean_layoutremove;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boolean-layoutremove"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boolean-layoutselected"))) {
            if (valsub == vx_p_boolean_layoutselected) {
            } else if (valsub instanceof Ui.Func_boolean_layoutselected_from_ui) {
              Ui.Func_boolean_layoutselected_from_ui valboolean_layoutselected = (Ui.Func_boolean_layoutselected_from_ui)valsub;
              ischanged = true;
              vx_p_boolean_layoutselected = valboolean_layoutselected;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boolean-layoutselected"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boolean-layoutvisible"))) {
            if (valsub == vx_p_boolean_layoutvisible) {
            } else if (valsub instanceof Ui.Func_boolean_layoutvisible_from_ui) {
              Ui.Func_boolean_layoutvisible_from_ui valboolean_layoutvisible = (Ui.Func_boolean_layoutvisible_from_ui)valsub;
              ischanged = true;
              vx_p_boolean_layoutvisible = valboolean_layoutvisible;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boolean-layoutvisible"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":layoutmap"))) {
            if (valsub == vx_p_layoutmap) {
            } else if (valsub instanceof Ui.Type_layoutmap) {
              Ui.Type_layoutmap vallayoutmap = (Ui.Type_layoutmap)valsub;
              ischanged = true;
              vx_p_layoutmap = vallayoutmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("layoutmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":layoutelse"))) {
            if (valsub == vx_p_layoutelse) {
            } else if (valsub instanceof Ui.Type_layout) {
              Ui.Type_layout vallayoutelse = (Ui.Type_layout)valsub;
              ischanged = true;
              vx_p_layoutelse = vallayoutelse;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("layoutelse"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylesheetrender"))) {
            if (valsub == vx_p_stylesheetrender) {
            } else if (valsub instanceof Ui.Func_stylesheet_render) {
              Ui.Func_stylesheet_render valstylesheetrender = (Ui.Func_stylesheet_render)valsub;
              ischanged = true;
              vx_p_stylesheetrender = valstylesheetrender;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylesheetrender"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_layoutengine work = new Ui.Class_layoutengine();
        work.vx_p_name = vx_p_name;
        work.vx_p_boolean_print = vx_p_boolean_print;
        work.vx_p_boolean_layoutremove = vx_p_boolean_layoutremove;
        work.vx_p_boolean_layoutselected = vx_p_boolean_layoutselected;
        work.vx_p_boolean_layoutvisible = vx_p_boolean_layoutvisible;
        work.vx_p_layoutmap = vx_p_layoutmap;
        work.vx_p_layoutelse = vx_p_layoutelse;
        work.vx_p_stylesheetrender = vx_p_stylesheetrender;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layoutengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layoutengine;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutengine", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_layoutengine e_layoutengine = new Ui.Class_layoutengine();
  public static final Ui.Type_layoutengine t_layoutengine = new Ui.Class_layoutengine();

  /**
   * type: layoutlist
   * Map of layout
   * (type layoutlist)
   */
  public interface Type_layoutlist extends Core.Type_list {
    public List<Ui.Type_layout> vx_listlayout();
    public Ui.Type_layout vx_layout(final Core.Type_int index);
  }

  public static class Class_layoutlist extends Core.Class_base implements Type_layoutlist {

    public List<Ui.Type_layout> vx_p_list = Core.immutablelist(
      new ArrayList<Ui.Type_layout>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout(final Core.Type_int index) {
      Ui.Type_layout output = Ui.e_layout;
      Ui.Class_layoutlist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_layout> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_layout> vx_listlayout() {
      List<Ui.Type_layout> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Ui.Type_layout output = this.vx_layout(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_layoutlist output = Core.vx_copy(Ui.e_layoutlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_layoutlist output = this;
      boolean ischanged = false;
      Ui.Class_layoutlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Ui.Type_layout> listval = new ArrayList<Ui.Type_layout>(value.vx_listlayout());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Ui.Type_layoutlist) {
          Ui.Type_layoutlist multi = (Ui.Type_layoutlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listlayout());
        } else if (valsub instanceof Ui.Type_layout) {
          Ui.Type_layout allowsub = (Ui.Type_layout)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Ui.Type_layout) {
          ischanged = true;
          listval.add((Ui.Type_layout)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Ui.Type_layout) {
              Ui.Type_layout valitem = (Ui.Type_layout)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_layoutlist work = new Ui.Class_layoutlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layoutlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layoutlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_layout), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_layoutlist e_layoutlist = new Ui.Class_layoutlist();
  public static final Ui.Type_layoutlist t_layoutlist = new Ui.Class_layoutlist();

  /**
   * type: layoutmap
   * Map of layout
   * (type layoutmap)
   */
  public interface Type_layoutmap extends Core.Type_map {
    public Map<String, Ui.Type_layout> vx_maplayout();
    public Ui.Type_layout vx_layout(final Core.Type_string key);
  }

  public static class Class_layoutmap extends Core.Class_base implements Type_layoutmap {

    public Map<String, Ui.Type_layout> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_layout>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_layout) {
        Ui.Type_layout castval = (Ui.Type_layout)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_layout> map = new LinkedHashMap<String, Ui.Type_layout>(this.vx_p_map);
        if (castval == Ui.e_layout) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout(final Core.Type_string key) {
      Ui.Type_layout output = Ui.e_layout;
      Ui.Class_layoutmap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_layout> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_layout);
      return output;
    }

    @Override
    public Map<String, Ui.Type_layout> vx_maplayout() {
      Map<String, Ui.Type_layout> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_layout(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_layoutmap output = new Ui.Class_layoutmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_layout> map = new LinkedHashMap<String, Ui.Type_layout>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_layout) {
          Ui.Type_layout castval = (Ui.Type_layout)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_layoutmap output = Core.vx_copy(Ui.e_layoutmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_layoutmap output = this;
      boolean ischanged = false;
      Ui.Class_layoutmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_layout> mapval = new LinkedHashMap<String, Ui.Type_layout>(value.vx_maplayout());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_layout valany = Ui.e_layout;
          if (false) {
          } else if (valsub instanceof Ui.Type_layout) {
            Ui.Type_layout valallowed = (Ui.Type_layout)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_layout) {
            valany = (Ui.Type_layout)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_layoutmap work = new Ui.Class_layoutmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layoutmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layoutmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_layout), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_layoutmap e_layoutmap = new Ui.Class_layoutmap();
  public static final Ui.Type_layoutmap t_layoutmap = new Ui.Class_layoutmap();

  /**
   * type: pin
   * Pin an element
   * (type pin)
   */
  public interface Type_pin extends Core.Type_struct {
    public Core.Type_string name();
  }

  public static class Class_pin extends Core.Class_base implements Type_pin {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_pin output = Core.vx_copy(Ui.e_pin, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_pin output = this;
      boolean ischanged = false;
      Ui.Class_pin value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_pin work = new Ui.Class_pin();
        work.vx_p_name = vx_p_name;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_pin;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_pin;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "pin", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_pin e_pin = new Ui.Class_pin();
  public static final Ui.Type_pin t_pin = new Ui.Class_pin();

  /**
   * type: point
   * Universal Point
   * (type point)
   */
  public interface Type_point extends Core.Type_struct {
    public Core.Type_int x();
    public Core.Type_int y();
    public Core.Type_int z();
    public Core.Type_int t();
    public Core.Type_int i();
    public Ui.Type_pointtype pointtype();
  }

  public static class Class_point extends Core.Class_base implements Type_point {

    public Core.Type_int vx_p_x = null;

    @Override
    public Core.Type_int x() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_x;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_y = null;

    @Override
    public Core.Type_int y() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_y;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_z = null;

    @Override
    public Core.Type_int z() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_z;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_t = null;

    @Override
    public Core.Type_int t() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_t;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_i = null;

    @Override
    public Core.Type_int i() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_i;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_pointtype vx_p_pointtype = null;

    @Override
    public Ui.Type_pointtype pointtype() {
      Ui.Type_pointtype output = Ui.e_pointtype;
      Ui.Type_pointtype testnull = vx_p_pointtype;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":x"))) {
        output = this.x();
      } else if ((skey.equals(":y"))) {
        output = this.y();
      } else if ((skey.equals(":z"))) {
        output = this.z();
      } else if ((skey.equals(":t"))) {
        output = this.t();
      } else if ((skey.equals(":i"))) {
        output = this.i();
      } else if ((skey.equals(":pointtype"))) {
        output = this.pointtype();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":x", this.x());
      map.put(":y", this.y());
      map.put(":z", this.z());
      map.put(":t", this.t());
      map.put(":i", this.i());
      map.put(":pointtype", this.pointtype());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_point output = Core.vx_copy(Ui.e_point, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_point output = this;
      boolean ischanged = false;
      Ui.Class_point value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_int vx_p_x = value.x();
      Core.Type_int vx_p_y = value.y();
      Core.Type_int vx_p_z = value.z();
      Core.Type_int vx_p_t = value.t();
      Core.Type_int vx_p_i = value.i();
      Ui.Type_pointtype vx_p_pointtype = value.pointtype();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":x");
      validkeys.add(":y");
      validkeys.add(":z");
      validkeys.add(":t");
      validkeys.add(":i");
      validkeys.add(":pointtype");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":x"))) {
            if (valsub == vx_p_x) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valx = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_x = valx;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_x = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("x"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":y"))) {
            if (valsub == vx_p_y) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valy = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_y = valy;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_y = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("y"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":z"))) {
            if (valsub == vx_p_z) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valz = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_z = valz;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_z = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("z"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":t"))) {
            if (valsub == vx_p_t) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valt = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_t = valt;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_t = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("t"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":i"))) {
            if (valsub == vx_p_i) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int vali = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_i = vali;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_i = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("i"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pointtype"))) {
            if (valsub == vx_p_pointtype) {
            } else if (valsub instanceof Ui.Type_pointtype) {
              Ui.Type_pointtype valpointtype = (Ui.Type_pointtype)valsub;
              ischanged = true;
              vx_p_pointtype = valpointtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pointtype"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_point work = new Ui.Class_point();
        work.vx_p_x = vx_p_x;
        work.vx_p_y = vx_p_y;
        work.vx_p_z = vx_p_z;
        work.vx_p_t = vx_p_t;
        work.vx_p_i = vx_p_i;
        work.vx_p_pointtype = vx_p_pointtype;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_point;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_point;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "point", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_point e_point = new Ui.Class_point();
  public static final Ui.Type_point t_point = new Ui.Class_point();

  /**
   * type: pointtype
   * Universal Point Scale
   * (type pointtype)
   */
  public interface Type_pointtype extends Core.Type_any {
  }

  public static class Class_pointtype extends Core.Class_base implements Type_pointtype {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_pointtype output = Core.vx_copy(Ui.e_pointtype, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_pointtype output = this;
      boolean ischanged = false;
      Ui.Class_pointtype value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_pointtype work = new Ui.Class_pointtype();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_pointtype;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_pointtype;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "pointtype", // name
        ":int", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_pointtype e_pointtype = new Ui.Class_pointtype();
  public static final Ui.Type_pointtype t_pointtype = new Ui.Class_pointtype();

  /**
   * type: style
   * Universal Style
   * (type style)
   */
  public interface Type_style extends Core.Type_struct {
    public Core.Type_string name();
    public Ui.Type_align align();
    public Ui.Type_bounds boundsmargin();
    public Ui.Type_bounds boundspadding();
    public Core.Type_string color_bkg();
    public Core.Type_string color_bkghover();
    public Core.Type_string color_border();
    public Core.Type_string color_font();
    public Ui.Type_cursor cursor();
    public Ui.Type_flip flip();
    public Ui.Type_font font();
    public Core.Type_boolean hidden();
    public Ui.Type_image image_bkg();
    public Ui.Type_layout layout();
    public Ui.Type_styletype type();
    public Ui.Type_pin pin();
    public Ui.Type_point pointorigin();
    public Ui.Type_point pointpos();
    public Ui.Type_point pointrotate();
    public Ui.Type_point pointsize();
    public Core.Type_boolean scroll_x();
    public Core.Type_boolean scroll_y();
  }

  public static class Class_style extends Core.Class_base implements Type_style {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_align vx_p_align = null;

    @Override
    public Ui.Type_align align() {
      Ui.Type_align output = Ui.e_align;
      Ui.Type_align testnull = vx_p_align;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_bounds vx_p_boundsmargin = null;

    @Override
    public Ui.Type_bounds boundsmargin() {
      Ui.Type_bounds output = Ui.e_bounds;
      Ui.Type_bounds testnull = vx_p_boundsmargin;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_bounds vx_p_boundspadding = null;

    @Override
    public Ui.Type_bounds boundspadding() {
      Ui.Type_bounds output = Ui.e_bounds;
      Ui.Type_bounds testnull = vx_p_boundspadding;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_color_bkg = null;

    @Override
    public Core.Type_string color_bkg() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_color_bkg;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_color_bkghover = null;

    @Override
    public Core.Type_string color_bkghover() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_color_bkghover;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_color_border = null;

    @Override
    public Core.Type_string color_border() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_color_border;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_color_font = null;

    @Override
    public Core.Type_string color_font() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_color_font;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_cursor vx_p_cursor = null;

    @Override
    public Ui.Type_cursor cursor() {
      Ui.Type_cursor output = Ui.e_cursor;
      Ui.Type_cursor testnull = vx_p_cursor;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_flip vx_p_flip = null;

    @Override
    public Ui.Type_flip flip() {
      Ui.Type_flip output = Ui.e_flip;
      Ui.Type_flip testnull = vx_p_flip;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_font vx_p_font = null;

    @Override
    public Ui.Type_font font() {
      Ui.Type_font output = Ui.e_font;
      Ui.Type_font testnull = vx_p_font;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_hidden = null;

    @Override
    public Core.Type_boolean hidden() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_hidden;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_image vx_p_image_bkg = null;

    @Override
    public Ui.Type_image image_bkg() {
      Ui.Type_image output = Ui.e_image;
      Ui.Type_image testnull = vx_p_image_bkg;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_layout vx_p_layout = null;

    @Override
    public Ui.Type_layout layout() {
      Ui.Type_layout output = Ui.e_layout;
      Ui.Type_layout testnull = vx_p_layout;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_styletype vx_p_type = null;

    @Override
    public Ui.Type_styletype type() {
      Ui.Type_styletype output = Ui.e_styletype;
      Ui.Type_styletype testnull = vx_p_type;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_pin vx_p_pin = null;

    @Override
    public Ui.Type_pin pin() {
      Ui.Type_pin output = Ui.e_pin;
      Ui.Type_pin testnull = vx_p_pin;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_point vx_p_pointorigin = null;

    @Override
    public Ui.Type_point pointorigin() {
      Ui.Type_point output = Ui.e_point;
      Ui.Type_point testnull = vx_p_pointorigin;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_point vx_p_pointpos = null;

    @Override
    public Ui.Type_point pointpos() {
      Ui.Type_point output = Ui.e_point;
      Ui.Type_point testnull = vx_p_pointpos;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_point vx_p_pointrotate = null;

    @Override
    public Ui.Type_point pointrotate() {
      Ui.Type_point output = Ui.e_point;
      Ui.Type_point testnull = vx_p_pointrotate;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_point vx_p_pointsize = null;

    @Override
    public Ui.Type_point pointsize() {
      Ui.Type_point output = Ui.e_point;
      Ui.Type_point testnull = vx_p_pointsize;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_scroll_x = null;

    @Override
    public Core.Type_boolean scroll_x() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_scroll_x;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_scroll_y = null;

    @Override
    public Core.Type_boolean scroll_y() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_scroll_y;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":align"))) {
        output = this.align();
      } else if ((skey.equals(":boundsmargin"))) {
        output = this.boundsmargin();
      } else if ((skey.equals(":boundspadding"))) {
        output = this.boundspadding();
      } else if ((skey.equals(":color-bkg"))) {
        output = this.color_bkg();
      } else if ((skey.equals(":color-bkghover"))) {
        output = this.color_bkghover();
      } else if ((skey.equals(":color-border"))) {
        output = this.color_border();
      } else if ((skey.equals(":color-font"))) {
        output = this.color_font();
      } else if ((skey.equals(":cursor"))) {
        output = this.cursor();
      } else if ((skey.equals(":flip"))) {
        output = this.flip();
      } else if ((skey.equals(":font"))) {
        output = this.font();
      } else if ((skey.equals(":hidden"))) {
        output = this.hidden();
      } else if ((skey.equals(":image-bkg"))) {
        output = this.image_bkg();
      } else if ((skey.equals(":layout"))) {
        output = this.layout();
      } else if ((skey.equals(":type"))) {
        output = this.type();
      } else if ((skey.equals(":pin"))) {
        output = this.pin();
      } else if ((skey.equals(":pointorigin"))) {
        output = this.pointorigin();
      } else if ((skey.equals(":pointpos"))) {
        output = this.pointpos();
      } else if ((skey.equals(":pointrotate"))) {
        output = this.pointrotate();
      } else if ((skey.equals(":pointsize"))) {
        output = this.pointsize();
      } else if ((skey.equals(":scroll-x"))) {
        output = this.scroll_x();
      } else if ((skey.equals(":scroll-y"))) {
        output = this.scroll_y();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":align", this.align());
      map.put(":boundsmargin", this.boundsmargin());
      map.put(":boundspadding", this.boundspadding());
      map.put(":color-bkg", this.color_bkg());
      map.put(":color-bkghover", this.color_bkghover());
      map.put(":color-border", this.color_border());
      map.put(":color-font", this.color_font());
      map.put(":cursor", this.cursor());
      map.put(":flip", this.flip());
      map.put(":font", this.font());
      map.put(":hidden", this.hidden());
      map.put(":image-bkg", this.image_bkg());
      map.put(":layout", this.layout());
      map.put(":type", this.type());
      map.put(":pin", this.pin());
      map.put(":pointorigin", this.pointorigin());
      map.put(":pointpos", this.pointpos());
      map.put(":pointrotate", this.pointrotate());
      map.put(":pointsize", this.pointsize());
      map.put(":scroll-x", this.scroll_x());
      map.put(":scroll-y", this.scroll_y());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_style output = Core.vx_copy(Ui.e_style, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_style output = this;
      boolean ischanged = false;
      Ui.Class_style value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Ui.Type_align vx_p_align = value.align();
      Ui.Type_bounds vx_p_boundsmargin = value.boundsmargin();
      Ui.Type_bounds vx_p_boundspadding = value.boundspadding();
      Core.Type_string vx_p_color_bkg = value.color_bkg();
      Core.Type_string vx_p_color_bkghover = value.color_bkghover();
      Core.Type_string vx_p_color_border = value.color_border();
      Core.Type_string vx_p_color_font = value.color_font();
      Ui.Type_cursor vx_p_cursor = value.cursor();
      Ui.Type_flip vx_p_flip = value.flip();
      Ui.Type_font vx_p_font = value.font();
      Core.Type_boolean vx_p_hidden = value.hidden();
      Ui.Type_image vx_p_image_bkg = value.image_bkg();
      Ui.Type_layout vx_p_layout = value.layout();
      Ui.Type_styletype vx_p_type = value.type();
      Ui.Type_pin vx_p_pin = value.pin();
      Ui.Type_point vx_p_pointorigin = value.pointorigin();
      Ui.Type_point vx_p_pointpos = value.pointpos();
      Ui.Type_point vx_p_pointrotate = value.pointrotate();
      Ui.Type_point vx_p_pointsize = value.pointsize();
      Core.Type_boolean vx_p_scroll_x = value.scroll_x();
      Core.Type_boolean vx_p_scroll_y = value.scroll_y();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":align");
      validkeys.add(":boundsmargin");
      validkeys.add(":boundspadding");
      validkeys.add(":color-bkg");
      validkeys.add(":color-bkghover");
      validkeys.add(":color-border");
      validkeys.add(":color-font");
      validkeys.add(":cursor");
      validkeys.add(":flip");
      validkeys.add(":font");
      validkeys.add(":hidden");
      validkeys.add(":image-bkg");
      validkeys.add(":layout");
      validkeys.add(":type");
      validkeys.add(":pin");
      validkeys.add(":pointorigin");
      validkeys.add(":pointpos");
      validkeys.add(":pointrotate");
      validkeys.add(":pointsize");
      validkeys.add(":scroll-x");
      validkeys.add(":scroll-y");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":align"))) {
            if (valsub == vx_p_align) {
            } else if (valsub instanceof Ui.Type_align) {
              Ui.Type_align valalign = (Ui.Type_align)valsub;
              ischanged = true;
              vx_p_align = valalign;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("align"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boundsmargin"))) {
            if (valsub == vx_p_boundsmargin) {
            } else if (valsub instanceof Ui.Type_bounds) {
              Ui.Type_bounds valboundsmargin = (Ui.Type_bounds)valsub;
              ischanged = true;
              vx_p_boundsmargin = valboundsmargin;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boundsmargin"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":boundspadding"))) {
            if (valsub == vx_p_boundspadding) {
            } else if (valsub instanceof Ui.Type_bounds) {
              Ui.Type_bounds valboundspadding = (Ui.Type_bounds)valsub;
              ischanged = true;
              vx_p_boundspadding = valboundspadding;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("boundspadding"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":color-bkg"))) {
            if (valsub == vx_p_color_bkg) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcolor_bkg = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_color_bkg = valcolor_bkg;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_bkg = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("color-bkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":color-bkghover"))) {
            if (valsub == vx_p_color_bkghover) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcolor_bkghover = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_color_bkghover = valcolor_bkghover;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_bkghover = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("color-bkghover"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":color-border"))) {
            if (valsub == vx_p_color_border) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcolor_border = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_color_border = valcolor_border;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_border = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("color-border"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":color-font"))) {
            if (valsub == vx_p_color_font) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcolor_font = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_color_font = valcolor_font;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_font = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("color-font"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":cursor"))) {
            if (valsub == vx_p_cursor) {
            } else if (valsub instanceof Ui.Type_cursor) {
              Ui.Type_cursor valcursor = (Ui.Type_cursor)valsub;
              ischanged = true;
              vx_p_cursor = valcursor;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("cursor"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":flip"))) {
            if (valsub == vx_p_flip) {
            } else if (valsub instanceof Ui.Type_flip) {
              Ui.Type_flip valflip = (Ui.Type_flip)valsub;
              ischanged = true;
              vx_p_flip = valflip;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("flip"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":font"))) {
            if (valsub == vx_p_font) {
            } else if (valsub instanceof Ui.Type_font) {
              Ui.Type_font valfont = (Ui.Type_font)valsub;
              ischanged = true;
              vx_p_font = valfont;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("font"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":hidden"))) {
            if (valsub == vx_p_hidden) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valhidden = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_hidden = valhidden;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_hidden = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":image-bkg"))) {
            if (valsub == vx_p_image_bkg) {
            } else if (valsub instanceof Ui.Type_image) {
              Ui.Type_image valimage_bkg = (Ui.Type_image)valsub;
              ischanged = true;
              vx_p_image_bkg = valimage_bkg;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("image-bkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":layout"))) {
            if (valsub == vx_p_layout) {
            } else if (valsub instanceof Ui.Type_layout) {
              Ui.Type_layout vallayout = (Ui.Type_layout)valsub;
              ischanged = true;
              vx_p_layout = vallayout;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":type"))) {
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Ui.Type_styletype) {
              Ui.Type_styletype valtype = (Ui.Type_styletype)valsub;
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pin"))) {
            if (valsub == vx_p_pin) {
            } else if (valsub instanceof Ui.Type_pin) {
              Ui.Type_pin valpin = (Ui.Type_pin)valsub;
              ischanged = true;
              vx_p_pin = valpin;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pin"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pointorigin"))) {
            if (valsub == vx_p_pointorigin) {
            } else if (valsub instanceof Ui.Type_point) {
              Ui.Type_point valpointorigin = (Ui.Type_point)valsub;
              ischanged = true;
              vx_p_pointorigin = valpointorigin;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pointorigin"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pointpos"))) {
            if (valsub == vx_p_pointpos) {
            } else if (valsub instanceof Ui.Type_point) {
              Ui.Type_point valpointpos = (Ui.Type_point)valsub;
              ischanged = true;
              vx_p_pointpos = valpointpos;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pointpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pointrotate"))) {
            if (valsub == vx_p_pointrotate) {
            } else if (valsub instanceof Ui.Type_point) {
              Ui.Type_point valpointrotate = (Ui.Type_point)valsub;
              ischanged = true;
              vx_p_pointrotate = valpointrotate;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pointrotate"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pointsize"))) {
            if (valsub == vx_p_pointsize) {
            } else if (valsub instanceof Ui.Type_point) {
              Ui.Type_point valpointsize = (Ui.Type_point)valsub;
              ischanged = true;
              vx_p_pointsize = valpointsize;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pointsize"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":scroll-x"))) {
            if (valsub == vx_p_scroll_x) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valscroll_x = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_scroll_x = valscroll_x;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_scroll_x = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("scroll-x"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":scroll-y"))) {
            if (valsub == vx_p_scroll_y) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valscroll_y = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_scroll_y = valscroll_y;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_scroll_y = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("scroll-y"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_style work = new Ui.Class_style();
        work.vx_p_name = vx_p_name;
        work.vx_p_align = vx_p_align;
        work.vx_p_boundsmargin = vx_p_boundsmargin;
        work.vx_p_boundspadding = vx_p_boundspadding;
        work.vx_p_color_bkg = vx_p_color_bkg;
        work.vx_p_color_bkghover = vx_p_color_bkghover;
        work.vx_p_color_border = vx_p_color_border;
        work.vx_p_color_font = vx_p_color_font;
        work.vx_p_cursor = vx_p_cursor;
        work.vx_p_flip = vx_p_flip;
        work.vx_p_font = vx_p_font;
        work.vx_p_hidden = vx_p_hidden;
        work.vx_p_image_bkg = vx_p_image_bkg;
        work.vx_p_layout = vx_p_layout;
        work.vx_p_type = vx_p_type;
        work.vx_p_pin = vx_p_pin;
        work.vx_p_pointorigin = vx_p_pointorigin;
        work.vx_p_pointpos = vx_p_pointpos;
        work.vx_p_pointrotate = vx_p_pointrotate;
        work.vx_p_pointsize = vx_p_pointsize;
        work.vx_p_scroll_x = vx_p_scroll_x;
        work.vx_p_scroll_y = vx_p_scroll_y;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_style;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_style;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "style", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_style e_style = new Ui.Class_style();
  public static final Ui.Type_style t_style = new Ui.Class_style();

  /**
   * type: stylelist
   * Universal Stylelist
   * (type stylelist)
   */
  public interface Type_stylelist extends Core.Type_list {
    public List<Ui.Type_style> vx_liststyle();
    public Ui.Type_style vx_style(final Core.Type_int index);
  }

  public static class Class_stylelist extends Core.Class_base implements Type_stylelist {

    public List<Ui.Type_style> vx_p_list = Core.immutablelist(
      new ArrayList<Ui.Type_style>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Ui.Type_style vx_style(final Core.Type_int index) {
      Ui.Type_style output = Ui.e_style;
      Ui.Class_stylelist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_style> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_style> vx_liststyle() {
      List<Ui.Type_style> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Ui.Type_style output = this.vx_style(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_stylelist output = Core.vx_copy(Ui.e_stylelist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_stylelist output = this;
      boolean ischanged = false;
      Ui.Class_stylelist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Ui.Type_style> listval = new ArrayList<Ui.Type_style>(value.vx_liststyle());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Ui.Type_stylelist) {
          Ui.Type_stylelist multi = (Ui.Type_stylelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststyle());
        } else if (valsub instanceof Ui.Type_style) {
          Ui.Type_style allowsub = (Ui.Type_style)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Ui.Type_style) {
          ischanged = true;
          listval.add((Ui.Type_style)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Ui.Type_style) {
              Ui.Type_style valitem = (Ui.Type_style)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_stylelist work = new Ui.Class_stylelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylelist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_style), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_stylelist e_stylelist = new Ui.Class_stylelist();
  public static final Ui.Type_stylelist t_stylelist = new Ui.Class_stylelist();

  /**
   * type: stylemap
   * Universal Stylemap
   * (type stylemap)
   */
  public interface Type_stylemap extends Core.Type_map {
    public Map<String, Ui.Type_style> vx_mapstyle();
    public Ui.Type_style vx_style(final Core.Type_string key);
  }

  public static class Class_stylemap extends Core.Class_base implements Type_stylemap {

    public Map<String, Ui.Type_style> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_style>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_style) {
        Ui.Type_style castval = (Ui.Type_style)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_style> map = new LinkedHashMap<String, Ui.Type_style>(this.vx_p_map);
        if (castval == Ui.e_style) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_style vx_style(final Core.Type_string key) {
      Ui.Type_style output = Ui.e_style;
      Ui.Class_stylemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_style> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_style);
      return output;
    }

    @Override
    public Map<String, Ui.Type_style> vx_mapstyle() {
      Map<String, Ui.Type_style> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_style(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_stylemap output = new Ui.Class_stylemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_style> map = new LinkedHashMap<String, Ui.Type_style>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_style) {
          Ui.Type_style castval = (Ui.Type_style)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_stylemap output = Core.vx_copy(Ui.e_stylemap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_stylemap output = this;
      boolean ischanged = false;
      Ui.Class_stylemap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_style> mapval = new LinkedHashMap<String, Ui.Type_style>(value.vx_mapstyle());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_style valany = Ui.e_style;
          if (false) {
          } else if (valsub instanceof Ui.Type_style) {
            Ui.Type_style valallowed = (Ui.Type_style)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_style) {
            valany = (Ui.Type_style)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_stylemap work = new Ui.Class_stylemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylemap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylemap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_style), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_stylemap e_stylemap = new Ui.Class_stylemap();
  public static final Ui.Type_stylemap t_stylemap = new Ui.Class_stylemap();

  /**
   * type: stylesheet
   * Universal Stylesheet
   * (type stylesheet)
   */
  public interface Type_stylesheet extends Core.Type_struct {
    public Ui.Type_fontfacemap fontfacemap();
    public Ui.Type_stylemap stylemap();
  }

  public static class Class_stylesheet extends Core.Class_base implements Type_stylesheet {

    public Ui.Type_fontfacemap vx_p_fontfacemap = null;

    @Override
    public Ui.Type_fontfacemap fontfacemap() {
      Ui.Type_fontfacemap output = Ui.e_fontfacemap;
      Ui.Type_fontfacemap testnull = vx_p_fontfacemap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_stylemap vx_p_stylemap = null;

    @Override
    public Ui.Type_stylemap stylemap() {
      Ui.Type_stylemap output = Ui.e_stylemap;
      Ui.Type_stylemap testnull = vx_p_stylemap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":fontfacemap"))) {
        output = this.fontfacemap();
      } else if ((skey.equals(":stylemap"))) {
        output = this.stylemap();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":fontfacemap", this.fontfacemap());
      map.put(":stylemap", this.stylemap());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_stylesheet output = Core.vx_copy(Ui.e_stylesheet, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_stylesheet output = this;
      boolean ischanged = false;
      Ui.Class_stylesheet value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Ui.Type_fontfacemap vx_p_fontfacemap = value.fontfacemap();
      Ui.Type_stylemap vx_p_stylemap = value.stylemap();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":fontfacemap");
      validkeys.add(":stylemap");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":fontfacemap"))) {
            if (valsub == vx_p_fontfacemap) {
            } else if (valsub instanceof Ui.Type_fontfacemap) {
              Ui.Type_fontfacemap valfontfacemap = (Ui.Type_fontfacemap)valsub;
              ischanged = true;
              vx_p_fontfacemap = valfontfacemap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fontfacemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylemap"))) {
            if (valsub == vx_p_stylemap) {
            } else if (valsub instanceof Ui.Type_stylemap) {
              Ui.Type_stylemap valstylemap = (Ui.Type_stylemap)valsub;
              ischanged = true;
              vx_p_stylemap = valstylemap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_stylesheet work = new Ui.Class_stylesheet();
        work.vx_p_fontfacemap = vx_p_fontfacemap;
        work.vx_p_stylemap = vx_p_stylemap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylesheet;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylesheet;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_stylesheet e_stylesheet = new Ui.Class_stylesheet();
  public static final Ui.Type_stylesheet t_stylesheet = new Ui.Class_stylesheet();

  /**
   * type: styletype
   * Universal Style Type
   * (type styletype)
   */
  public interface Type_styletype extends Core.Type_struct {
  }

  public static class Class_styletype extends Core.Class_base implements Type_styletype {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_styletype output = Core.vx_copy(Ui.e_styletype, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_styletype output = this;
      boolean ischanged = false;
      Ui.Class_styletype value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_styletype work = new Ui.Class_styletype();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_styletype;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_styletype;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "styletype", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_styletype e_styletype = new Ui.Class_styletype();
  public static final Ui.Type_styletype t_styletype = new Ui.Class_styletype();

  /**
   * type: ui
   * Universal UI Element
   * (type ui)
   */
  public interface Type_ui extends Core.Type_struct {
    public Core.Type_string uid();
    public Core.Type_string name();
    public Ui.Type_layout layout();
    public Core.Type_string path();
    public Core.Type_boolean hidden();
    public Core.Type_boolean selected();
    public Core.Type_boolean selectmulti();
    public Ui.Type_style style();
    public Ui.Type_stylelist stylelist();
    public Event.Type_eventmap eventmap();
    public Core.Type_any data();
    public Ui.Type_uimap uimap();
  }

  public static class Class_ui extends Core.Class_base implements Type_ui {

    public Core.Type_string vx_p_uid = null;

    @Override
    public Core.Type_string uid() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_uid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_layout vx_p_layout = null;

    @Override
    public Ui.Type_layout layout() {
      Ui.Type_layout output = Ui.e_layout;
      Ui.Type_layout testnull = vx_p_layout;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_path = null;

    @Override
    public Core.Type_string path() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_path;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_hidden = null;

    @Override
    public Core.Type_boolean hidden() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_hidden;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_selected = null;

    @Override
    public Core.Type_boolean selected() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_selected;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_selectmulti = null;

    @Override
    public Core.Type_boolean selectmulti() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_selectmulti;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_style vx_p_style = null;

    @Override
    public Ui.Type_style style() {
      Ui.Type_style output = Ui.e_style;
      Ui.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_stylelist vx_p_stylelist = null;

    @Override
    public Ui.Type_stylelist stylelist() {
      Ui.Type_stylelist output = Ui.e_stylelist;
      Ui.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_any vx_p_data = null;

    @Override
    public Core.Type_any data() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_data;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_uimap vx_p_uimap = null;

    @Override
    public Ui.Type_uimap uimap() {
      Ui.Type_uimap output = Ui.e_uimap;
      Ui.Type_uimap testnull = vx_p_uimap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":uid"))) {
        output = this.uid();
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":layout"))) {
        output = this.layout();
      } else if ((skey.equals(":path"))) {
        output = this.path();
      } else if ((skey.equals(":hidden"))) {
        output = this.hidden();
      } else if ((skey.equals(":selected"))) {
        output = this.selected();
      } else if ((skey.equals(":selectmulti"))) {
        output = this.selectmulti();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":data"))) {
        output = this.data();
      } else if ((skey.equals(":uimap"))) {
        output = this.uimap();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":uid", this.uid());
      map.put(":name", this.name());
      map.put(":layout", this.layout());
      map.put(":path", this.path());
      map.put(":hidden", this.hidden());
      map.put(":selected", this.selected());
      map.put(":selectmulti", this.selectmulti());
      map.put(":style", this.style());
      map.put(":stylelist", this.stylelist());
      map.put(":eventmap", this.eventmap());
      map.put(":data", this.data());
      map.put(":uimap", this.uimap());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_ui output = Core.vx_copy(Ui.e_ui, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_ui output = this;
      boolean ischanged = false;
      Ui.Class_ui value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_uid = value.uid();
      Core.Type_string vx_p_name = value.name();
      Ui.Type_layout vx_p_layout = value.layout();
      Core.Type_string vx_p_path = value.path();
      Core.Type_boolean vx_p_hidden = value.hidden();
      Core.Type_boolean vx_p_selected = value.selected();
      Core.Type_boolean vx_p_selectmulti = value.selectmulti();
      Ui.Type_style vx_p_style = value.style();
      Ui.Type_stylelist vx_p_stylelist = value.stylelist();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Core.Type_any vx_p_data = value.data();
      Ui.Type_uimap vx_p_uimap = value.uimap();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":uid");
      validkeys.add(":name");
      validkeys.add(":layout");
      validkeys.add(":path");
      validkeys.add(":hidden");
      validkeys.add(":selected");
      validkeys.add(":selectmulti");
      validkeys.add(":style");
      validkeys.add(":stylelist");
      validkeys.add(":eventmap");
      validkeys.add(":data");
      validkeys.add(":uimap");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":uid"))) {
            if (valsub == vx_p_uid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valuid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_uid = valuid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_uid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("uid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":layout"))) {
            if (valsub == vx_p_layout) {
            } else if (valsub instanceof Ui.Type_layout) {
              Ui.Type_layout vallayout = (Ui.Type_layout)valsub;
              ischanged = true;
              vx_p_layout = vallayout;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":path"))) {
            if (valsub == vx_p_path) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valpath = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_path = valpath;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_path = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":hidden"))) {
            if (valsub == vx_p_hidden) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valhidden = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_hidden = valhidden;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_hidden = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":selected"))) {
            if (valsub == vx_p_selected) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valselected = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_selected = valselected;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_selected = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("selected"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":selectmulti"))) {
            if (valsub == vx_p_selectmulti) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valselectmulti = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_selectmulti = valselectmulti;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_selectmulti = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("selectmulti"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Ui.Type_style) {
              Ui.Type_style valstyle = (Ui.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Ui.Type_stylelist) {
              Ui.Type_stylelist valstylelist = (Ui.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":data"))) {
            if (valsub == vx_p_data) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valdata = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_data = valdata;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("data"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":uimap"))) {
            if (valsub == vx_p_uimap) {
            } else if (valsub instanceof Ui.Type_uimap) {
              Ui.Type_uimap valuimap = (Ui.Type_uimap)valsub;
              ischanged = true;
              vx_p_uimap = valuimap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("uimap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_ui work = new Ui.Class_ui();
        work.vx_p_uid = vx_p_uid;
        work.vx_p_name = vx_p_name;
        work.vx_p_layout = vx_p_layout;
        work.vx_p_path = vx_p_path;
        work.vx_p_hidden = vx_p_hidden;
        work.vx_p_selected = vx_p_selected;
        work.vx_p_selectmulti = vx_p_selectmulti;
        work.vx_p_style = vx_p_style;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_data = vx_p_data;
        work.vx_p_uimap = vx_p_uimap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "ui", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_ui e_ui = new Ui.Class_ui();
  public static final Ui.Type_ui t_ui = new Ui.Class_ui();

  /**
   * type: uiengine
   * Template for uiengine
   * (type uiengine)
   */
  public interface Type_uiengine extends Core.Type_struct {
    public Ui.Type_uimap parentmap();
    public Ui.Type_layoutengine layoutengine();
    public Ui.Type_stylesheet stylesheet();
    public Ui.Type_ui ui();
  }

  public static class Class_uiengine extends Core.Class_base implements Type_uiengine {

    public Ui.Type_uimap vx_p_parentmap = null;

    @Override
    public Ui.Type_uimap parentmap() {
      Ui.Type_uimap output = Ui.e_uimap;
      Ui.Type_uimap testnull = vx_p_parentmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_layoutengine vx_p_layoutengine = null;

    @Override
    public Ui.Type_layoutengine layoutengine() {
      Ui.Type_layoutengine output = Ui.e_layoutengine;
      Ui.Type_layoutengine testnull = vx_p_layoutengine;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_stylesheet vx_p_stylesheet = null;

    @Override
    public Ui.Type_stylesheet stylesheet() {
      Ui.Type_stylesheet output = Ui.e_stylesheet;
      Ui.Type_stylesheet testnull = vx_p_stylesheet;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Ui.Type_ui vx_p_ui = null;

    @Override
    public Ui.Type_ui ui() {
      Ui.Type_ui output = Ui.e_ui;
      Ui.Type_ui testnull = vx_p_ui;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":parentmap"))) {
        output = this.parentmap();
      } else if ((skey.equals(":layoutengine"))) {
        output = this.layoutengine();
      } else if ((skey.equals(":stylesheet"))) {
        output = this.stylesheet();
      } else if ((skey.equals(":ui"))) {
        output = this.ui();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":parentmap", this.parentmap());
      map.put(":layoutengine", this.layoutengine());
      map.put(":stylesheet", this.stylesheet());
      map.put(":ui", this.ui());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_uiengine output = Core.vx_copy(Ui.e_uiengine, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_uiengine output = this;
      boolean ischanged = false;
      Ui.Class_uiengine value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Ui.Type_uimap vx_p_parentmap = value.parentmap();
      Ui.Type_layoutengine vx_p_layoutengine = value.layoutengine();
      Ui.Type_stylesheet vx_p_stylesheet = value.stylesheet();
      Ui.Type_ui vx_p_ui = value.ui();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":parentmap");
      validkeys.add(":layoutengine");
      validkeys.add(":stylesheet");
      validkeys.add(":ui");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":parentmap"))) {
            if (valsub == vx_p_parentmap) {
            } else if (valsub instanceof Ui.Type_uimap) {
              Ui.Type_uimap valparentmap = (Ui.Type_uimap)valsub;
              ischanged = true;
              vx_p_parentmap = valparentmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("parentmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":layoutengine"))) {
            if (valsub == vx_p_layoutengine) {
            } else if (valsub instanceof Ui.Type_layoutengine) {
              Ui.Type_layoutengine vallayoutengine = (Ui.Type_layoutengine)valsub;
              ischanged = true;
              vx_p_layoutengine = vallayoutengine;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("layoutengine"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylesheet"))) {
            if (valsub == vx_p_stylesheet) {
            } else if (valsub instanceof Ui.Type_stylesheet) {
              Ui.Type_stylesheet valstylesheet = (Ui.Type_stylesheet)valsub;
              ischanged = true;
              vx_p_stylesheet = valstylesheet;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylesheet"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":ui"))) {
            if (valsub == vx_p_ui) {
            } else if (valsub instanceof Ui.Type_ui) {
              Ui.Type_ui valui = (Ui.Type_ui)valsub;
              ischanged = true;
              vx_p_ui = valui;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("ui"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_uiengine work = new Ui.Class_uiengine();
        work.vx_p_parentmap = vx_p_parentmap;
        work.vx_p_layoutengine = vx_p_layoutengine;
        work.vx_p_stylesheet = vx_p_stylesheet;
        work.vx_p_ui = vx_p_ui;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uiengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uiengine;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_uiengine e_uiengine = new Ui.Class_uiengine();
  public static final Ui.Type_uiengine t_uiengine = new Ui.Class_uiengine();

  /**
   * type: uilist
   * List of ui
   * (type uilist)
   */
  public interface Type_uilist extends Core.Type_list {
    public List<Ui.Type_ui> vx_listui();
    public Ui.Type_ui vx_ui(final Core.Type_int index);
  }

  public static class Class_uilist extends Core.Class_base implements Type_uilist {

    public List<Ui.Type_ui> vx_p_list = Core.immutablelist(
      new ArrayList<Ui.Type_ui>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui(final Core.Type_int index) {
      Ui.Type_ui output = Ui.e_ui;
      Ui.Class_uilist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_ui> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_ui> vx_listui() {
      List<Ui.Type_ui> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Ui.Type_ui output = this.vx_ui(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_uilist output = Core.vx_copy(Ui.e_uilist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_uilist output = this;
      boolean ischanged = false;
      Ui.Class_uilist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Ui.Type_ui> listval = new ArrayList<Ui.Type_ui>(value.vx_listui());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Ui.Type_uilist) {
          Ui.Type_uilist multi = (Ui.Type_uilist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listui());
        } else if (valsub instanceof Ui.Type_ui) {
          Ui.Type_ui allowsub = (Ui.Type_ui)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Ui.Type_ui) {
          ischanged = true;
          listval.add((Ui.Type_ui)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Ui.Type_ui) {
              Ui.Type_ui valitem = (Ui.Type_ui)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_uilist work = new Ui.Class_uilist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uilist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uilist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uilist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_uilist e_uilist = new Ui.Class_uilist();
  public static final Ui.Type_uilist t_uilist = new Ui.Class_uilist();

  /**
   * type: uimap
   * Map of ui
   * (type uimap)
   */
  public interface Type_uimap extends Core.Type_map {
    public Map<String, Ui.Type_ui> vx_mapui();
    public Ui.Type_ui vx_ui(final Core.Type_string key);
  }

  public static class Class_uimap extends Core.Class_base implements Type_uimap {

    public Map<String, Ui.Type_ui> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_ui>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Ui.Type_ui) {
        Ui.Type_ui castval = (Ui.Type_ui)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Ui.Type_ui> map = new LinkedHashMap<String, Ui.Type_ui>(this.vx_p_map);
        if (castval == Ui.e_ui) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui(final Core.Type_string key) {
      Ui.Type_ui output = Ui.e_ui;
      Ui.Class_uimap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_ui> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_ui);
      return output;
    }

    @Override
    public Map<String, Ui.Type_ui> vx_mapui() {
      Map<String, Ui.Type_ui> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_ui(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Ui.Class_uimap output = new Ui.Class_uimap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_ui> map = new LinkedHashMap<String, Ui.Type_ui>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Ui.Type_ui) {
          Ui.Type_ui castval = (Ui.Type_ui)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Type_uimap output = Core.vx_copy(Ui.e_uimap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Type_uimap output = this;
      boolean ischanged = false;
      Ui.Class_uimap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Ui.Type_ui> mapval = new LinkedHashMap<String, Ui.Type_ui>(value.vx_mapui());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_ui valany = Ui.e_ui;
          if (false) {
          } else if (valsub instanceof Ui.Type_ui) {
            Ui.Type_ui valallowed = (Ui.Type_ui)valsub;
            valany = valallowed;
          } else if (valsub instanceof Ui.Type_ui) {
            valany = (Ui.Type_ui)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Ui.Class_uimap work = new Ui.Class_uimap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uimap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uimap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uimap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
      return output;
    }

  }

  public static final Ui.Type_uimap e_uimap = new Ui.Class_uimap();
  public static final Ui.Type_uimap t_uimap = new Ui.Class_uimap();

  /**
   * Constant: align-center
   * Logical Center Align in parent
   * {align}
   */
  public static class Const_align_center {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-center", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_align_center = new Ui.Class_align();


  /**
   * Constant: align-left
   * Logical Left Align in parent
   * {align}
   */
  public static class Const_align_left {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-left", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_align_left = new Ui.Class_align();


  /**
   * Constant: align-right
   * Logical Right Align in parent
   * {align}
   */
  public static class Const_align_right {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-right", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_align_right = new Ui.Class_align();


  /**
   * Constant: flip-x
   * Logical Flip Horizontally
   * {align}
   */
  public static class Const_flip_x {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-x", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_flip_x = new Ui.Class_align();


  /**
   * Constant: flip-xy
   * Logical Flip Vertically and Horizontally
   * {align}
   */
  public static class Const_flip_xy {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-xy", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_flip_xy = new Ui.Class_align();


  /**
   * Constant: flip-y
   * Logical Flip Vertically
   * {align}
   */
  public static class Const_flip_y {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-y", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_align output) {
      Ui.Class_align outval = (Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_align c_flip_y = new Ui.Class_align();


  /**
   * Constant: layout-app
   * {layout}
   */
  public static class Const_layout_app {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-app", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-app")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_app = new Ui.Class_layout();


  /**
   * Constant: layout-background
   * {layout}
   */
  public static class Const_layout_background {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-background", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-background")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_background = new Ui.Class_layout();


  /**
   * Constant: layout-button
   * {layout}
   */
  public static class Const_layout_button {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-button", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-button")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_button = new Ui.Class_layout();


  /**
   * Constant: layout-combobox
   * {layout}
   */
  public static class Const_layout_combobox {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-combobox", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-combobox")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_combobox = new Ui.Class_layout();


  /**
   * Constant: layout-else
   * {layout}
   */
  public static class Const_layout_else {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-else", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-else")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_else = new Ui.Class_layout();


  /**
   * Constant: layout-flow-columns
   * {layout}
   */
  public static class Const_layout_flow_columns {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-columns", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-flow-columns")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_flow_columns = new Ui.Class_layout();


  /**
   * Constant: layout-flow-item
   * {layout}
   */
  public static class Const_layout_flow_item {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-item", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-flow-item")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_flow_item = new Ui.Class_layout();


  /**
   * Constant: layout-flow-rows
   * {layout}
   */
  public static class Const_layout_flow_rows {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-rows", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-flow-rows")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_flow_rows = new Ui.Class_layout();


  /**
   * Constant: layout-image
   * {layout}
   */
  public static class Const_layout_image {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-image", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-image")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_image = new Ui.Class_layout();


  /**
   * Constant: layout-label
   * {layout}
   */
  public static class Const_layout_label {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-label", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-label")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_label = new Ui.Class_layout();


  /**
   * Constant: layout-main
   * {layout}
   */
  public static class Const_layout_main {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-main", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-main")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_main = new Ui.Class_layout();


  /**
   * Constant: layout-maxpanel
   * {layout}
   */
  public static class Const_layout_maxpanel {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-maxpanel", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-maxpanel")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_maxpanel = new Ui.Class_layout();


  /**
   * Constant: layout-menubar
   * {layout}
   */
  public static class Const_layout_menubar {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menubar", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-menubar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_menubar = new Ui.Class_layout();


  /**
   * Constant: layout-menudrawer
   * {layout}
   */
  public static class Const_layout_menudrawer {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menudrawer", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-menudrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_menudrawer = new Ui.Class_layout();


  /**
   * Constant: layout-msgbox
   * {layout}
   */
  public static class Const_layout_msgbox {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-msgbox", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-msgbox")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_msgbox = new Ui.Class_layout();


  /**
   * Constant: layout-navbar
   * {layout}
   */
  public static class Const_layout_navbar {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navbar", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-navbar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_navbar = new Ui.Class_layout();


  /**
   * Constant: layout-navdrawer
   * {layout}
   */
  public static class Const_layout_navdrawer {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navdrawer", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-navdrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_navdrawer = new Ui.Class_layout();


  /**
   * Constant: layout-panel
   * {layout}
   */
  public static class Const_layout_panel {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-panel", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-panel")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_panel = new Ui.Class_layout();


  /**
   * Constant: layout-parallax
   * {layout}
   */
  public static class Const_layout_parallax {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-parallax", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-parallax")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_parallax = new Ui.Class_layout();


  /**
   * Constant: layout-statusbar
   * {layout}
   */
  public static class Const_layout_statusbar {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusbar", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-statusbar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_statusbar = new Ui.Class_layout();


  /**
   * Constant: layout-statusdrawer
   * {layout}
   */
  public static class Const_layout_statusdrawer {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusdrawer", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-statusdrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_statusdrawer = new Ui.Class_layout();


  /**
   * Constant: layout-text
   * {layout}
   */
  public static class Const_layout_text {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-text", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-text")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_text = new Ui.Class_layout();


  /**
   * Constant: layout-textentry
   * {layout}
   */
  public static class Const_layout_textentry {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-textentry", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-textentry")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_textentry = new Ui.Class_layout();


  /**
   * Constant: layout-titlebar
   * {layout}
   */
  public static class Const_layout_titlebar {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-titlebar", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_layout output) {
      Ui.Class_layout outval = (Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Ui.Type_layout value = Core.f_new(
        Ui.t_layout,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("layout-titlebar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static final Ui.Type_layout c_layout_titlebar = new Ui.Class_layout();


  /**
   * Constant: pin-bottom
   * {pin}
   */
  public static class Const_pin_bottom {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-bottom", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_bottom = new Ui.Class_pin();


  /**
   * Constant: pin-center
   * {pin}
   */
  public static class Const_pin_center {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_center = new Ui.Class_pin();


  /**
   * Constant: pin-center-h
   * {pin}
   */
  public static class Const_pin_center_h {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-h", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_center_h = new Ui.Class_pin();


  /**
   * Constant: pin-center-v
   * {pin}
   */
  public static class Const_pin_center_v {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-v", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_center_v = new Ui.Class_pin();


  /**
   * Constant: pin-expand
   * {pin}
   */
  public static class Const_pin_expand {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-expand", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_expand = new Ui.Class_pin();


  /**
   * Constant: pin-left
   * {pin}
   */
  public static class Const_pin_left {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-left", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_left = new Ui.Class_pin();


  /**
   * Constant: pin-right
   * {pin}
   */
  public static class Const_pin_right {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-right", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_right = new Ui.Class_pin();


  /**
   * Constant: pin-top
   * {pin}
   */
  public static class Const_pin_top {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-top", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pin output) {
      Ui.Class_pin outval = (Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pin c_pin_top = new Ui.Class_pin();


  /**
   * Constant: point-center
   * {point}
   */
  public static class Const_point_center {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-center", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_point output) {
      Ui.Class_point outval = (Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_point c_point_center = new Ui.Class_point();


  /**
   * Constant: point-lefttop
   * {point}
   */
  public static class Const_point_lefttop {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-lefttop", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_point output) {
      Ui.Class_point outval = (Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_point c_point_lefttop = new Ui.Class_point();


  /**
   * Constant: point-rightbottom
   * {point}
   */
  public static class Const_point_rightbottom {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-rightbottom", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_point output) {
      Ui.Class_point outval = (Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_point c_point_rightbottom = new Ui.Class_point();


  /**
   * Constant: pointtype-absolute
   * {pointtype}
   */
  public static class Const_pointtype_absolute {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-absolute", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pointtype output) {
      Ui.Class_pointtype outval = (Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pointtype c_pointtype_absolute = new Ui.Class_pointtype();


  /**
   * Constant: pointtype-percent
   * {pointtype}
   */
  public static class Const_pointtype_percent {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-percent", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pointtype output) {
      Ui.Class_pointtype outval = (Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pointtype c_pointtype_percent = new Ui.Class_pointtype();


  /**
   * Constant: pointtype-relative
   * {pointtype}
   */
  public static class Const_pointtype_relative {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-relative", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_pointtype output) {
      Ui.Class_pointtype outval = (Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_pointtype c_pointtype_relative = new Ui.Class_pointtype();


  /**
   * Constant: styletype-custom
   * {styletype}
   */
  public static class Const_styletype_custom {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-custom", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_styletype output) {
      Ui.Class_styletype outval = (Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_styletype c_styletype_custom = new Ui.Class_styletype();


  /**
   * Constant: styletype-shared
   * {styletype}
   */
  public static class Const_styletype_shared {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-shared", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_styletype output) {
      Ui.Class_styletype outval = (Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_styletype c_styletype_shared = new Ui.Class_styletype();


  /**
   * Constant: styletype-system
   * {styletype}
   */
  public static class Const_styletype_system {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-system", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Ui.Type_styletype output) {
      Ui.Class_styletype outval = (Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Ui.Type_styletype c_styletype_system = new Ui.Class_styletype();

  /**
   * @function boolean_layout_from_ui_parent_selected
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {boolean} selected
   * @return {boolean}
   * (func boolean-layout<-ui-parent-selected)
   */
  public interface Func_boolean_layout_from_ui_parent_selected extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layout_from_ui_parent_selected(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean selected);
  }

  public static class Class_boolean_layout_from_ui_parent_selected extends Core.Class_base implements Func_boolean_layout_from_ui_parent_selected {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layout_from_ui_parent_selected output = new Ui.Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layout_from_ui_parent_selected output = new Ui.Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-selected", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layout_from_ui_parent_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layout_from_ui_parent_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_boolean selected = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layout_from_ui_parent_selected(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean selected) {
      Core.Type_boolean output = Ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected);
      return output;
    }

  }

  public static final Ui.Func_boolean_layout_from_ui_parent_selected e_boolean_layout_from_ui_parent_selected = new Ui.Class_boolean_layout_from_ui_parent_selected();
  public static final Ui.Func_boolean_layout_from_ui_parent_selected t_boolean_layout_from_ui_parent_selected = new Ui.Class_boolean_layout_from_ui_parent_selected();

  public static Core.Type_boolean f_boolean_layout_from_ui_parent_selected(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean selected) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Ui.Type_ui uiselected = Core.f_copy(
          ui,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":selected"),
            selected
          )
        );
        Core.Type_boolean iswrite = Ui.f_boolean_write_from_ui_parent(
          uiselected,
          parent
        );
        Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        Core.Type_any output_1 = Core.vx_any_from_func(
          Core.t_boolean,
          fn_layoutselected,
          uiselected
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layout_from_ui_parent_visible
   * Writes to an html node adding or removing the hidden class.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {boolean} visible
   * @return {boolean}
   * (func boolean-layout<-ui-parent-visible)
   */
  public interface Func_boolean_layout_from_ui_parent_visible extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layout_from_ui_parent_visible(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean visible);
  }

  public static class Class_boolean_layout_from_ui_parent_visible extends Core.Class_base implements Func_boolean_layout_from_ui_parent_visible {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layout_from_ui_parent_visible output = new Ui.Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layout_from_ui_parent_visible output = new Ui.Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-visible", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layout_from_ui_parent_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layout_from_ui_parent_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_boolean visible = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layout_from_ui_parent_visible(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean visible) {
      Core.Type_boolean output = Ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible);
      return output;
    }

  }

  public static final Ui.Func_boolean_layout_from_ui_parent_visible e_boolean_layout_from_ui_parent_visible = new Ui.Class_boolean_layout_from_ui_parent_visible();
  public static final Ui.Func_boolean_layout_from_ui_parent_visible t_boolean_layout_from_ui_parent_visible = new Ui.Class_boolean_layout_from_ui_parent_visible();

  public static Core.Type_boolean f_boolean_layout_from_ui_parent_visible(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_boolean visible) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Ui.Type_ui uivisible = Core.f_copy(
          ui,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":hidden"),
            Core.f_not(
              visible
            )
          )
        );
        Core.Type_boolean iswrite = Ui.f_boolean_write_from_ui_parent(
          uivisible,
          parent
        );
        Ui.Func_boolean_layoutvisible_from_ui fn_layoutvisible = layoutengine.boolean_layoutvisible();
        Core.Type_any output_1 = Core.vx_any_from_func(
          Core.t_boolean,
          fn_layoutvisible,
          uivisible
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutaddchild_from_ui_parent
   * Writes a new ui on an existing parent.
   * @param  {ui} uiarg
   * @param  {ui} parent
   * @return {boolean}
   * (func boolean-layoutaddchild<-ui-parent)
   */
  public interface Func_boolean_layoutaddchild_from_ui_parent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutaddchild_from_ui_parent(final Core.Type_context context, final Ui.Type_ui uiarg, final Ui.Type_ui parent);
  }

  public static class Class_boolean_layoutaddchild_from_ui_parent extends Core.Class_base implements Func_boolean_layoutaddchild_from_ui_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutaddchild_from_ui_parent output = new Ui.Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutaddchild_from_ui_parent output = new Ui.Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutaddchild<-ui-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutaddchild_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutaddchild_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutaddchild_from_ui_parent(final Core.Type_context context, final Ui.Type_ui uiarg, final Ui.Type_ui parent) {
      Core.Type_boolean output = Ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutaddchild_from_ui_parent e_boolean_layoutaddchild_from_ui_parent = new Ui.Class_boolean_layoutaddchild_from_ui_parent();
  public static final Ui.Func_boolean_layoutaddchild_from_ui_parent t_boolean_layoutaddchild_from_ui_parent = new Ui.Class_boolean_layoutaddchild_from_ui_parent();

  public static Core.Type_boolean f_boolean_layoutaddchild_from_ui_parent(final Core.Type_context context, final Ui.Type_ui uiarg, final Ui.Type_ui parent) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_ui ui2 = Ui.f_ui_addlayout_from_ui(
          context,
          uiarg
        );
        Core.Type_boolean iswrite = Ui.f_boolean_write_from_ui_parent(
          ui2,
          parent
        );
        Ui.Type_ui ui3 = Ui.f_ui_layout_from_ui_orig_parent(
          ui2,
          Core.f_empty(
            Ui.t_ui
          ),
          parent
        );
        Core.Type_any output_1 = iswrite;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutremove_from_ui
   * Removes html node with a given ui.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutremove<-ui)
   */
  public interface Func_boolean_layoutremove_from_ui extends Core.Func_any_from_any {
    public Core.Type_boolean vx_boolean_layoutremove_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_boolean_layoutremove_from_ui extends Core.Class_base implements Func_boolean_layoutremove_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui output = new Ui.Class_boolean_layoutremove_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui output = new Ui.Class_boolean_layoutremove_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutremove_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutremove_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_layoutremove_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_layoutremove_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutremove_from_ui(final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_layoutremove_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutremove_from_ui e_boolean_layoutremove_from_ui = new Ui.Class_boolean_layoutremove_from_ui();
  public static final Ui.Func_boolean_layoutremove_from_ui t_boolean_layoutremove_from_ui = new Ui.Class_boolean_layoutremove_from_ui();

  public static Core.Type_boolean f_boolean_layoutremove_from_ui(final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_layoutremove_from_ui_keys
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {stringlist} keys
   * @return {boolean}
   * (func boolean-layoutremove<-ui-keys)
   */
  public interface Func_boolean_layoutremove_from_ui_keys extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_keys(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_stringlist keys);
  }

  public static class Class_boolean_layoutremove_from_ui_keys extends Core.Class_base implements Func_boolean_layoutremove_from_ui_keys {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_keys output = new Ui.Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_keys output = new Ui.Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-keys", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutremove_from_ui_keys;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutremove_from_ui_keys;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_stringlist keys = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_keys(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_stringlist keys) {
      Core.Type_boolean output = Ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutremove_from_ui_keys e_boolean_layoutremove_from_ui_keys = new Ui.Class_boolean_layoutremove_from_ui_keys();
  public static final Ui.Func_boolean_layoutremove_from_ui_keys t_boolean_layoutremove_from_ui_keys = new Ui.Class_boolean_layoutremove_from_ui_keys();

  public static Core.Type_boolean f_boolean_layoutremove_from_ui_keys(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_stringlist keys) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Core.Type_booleanlist writelist = Core.f_list_from_list_1(
          Core.t_booleanlist,
          keys,
          Core.t_any_from_any.vx_fn_new((key_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Core.Type_any output_2 = Core.f_let(
              Core.t_boolean,
              Core.t_any_from_func.vx_fn_new(() -> {
                Ui.Type_ui childui = Core.f_any_from_map(
                  Ui.t_ui,
                  uimap,
                  key
                );
                Core.Type_any output_3 = Ui.f_boolean_layoutremove_from_ui_parent(
                  context,
                  childui,
                  ui
                );
                return output_3;
              })
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = Core.f_and_1(
          writelist
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutremove_from_ui_parent
   * Removes an html node given a ui.
   * @param  {ui} ui
   * @param  {ui} parent
   * @return {boolean}
   * (func boolean-layoutremove<-ui-parent)
   */
  public interface Func_boolean_layoutremove_from_ui_parent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent);
  }

  public static class Class_boolean_layoutremove_from_ui_parent extends Core.Class_base implements Func_boolean_layoutremove_from_ui_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_parent output = new Ui.Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_parent output = new Ui.Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutremove_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutremove_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent) {
      Core.Type_boolean output = Ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutremove_from_ui_parent e_boolean_layoutremove_from_ui_parent = new Ui.Class_boolean_layoutremove_from_ui_parent();
  public static final Ui.Func_boolean_layoutremove_from_ui_parent t_boolean_layoutremove_from_ui_parent = new Ui.Class_boolean_layoutremove_from_ui_parent();

  public static Core.Type_boolean f_boolean_layoutremove_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Core.Type_string uid = ui.uid();
        Core.Type_boolean iswrite = Ui.f_boolean_writeremove_from_ui_uid(
          parent,
          uid
        );
        Ui.Func_boolean_layoutremove_from_ui fn_layoutremove = layoutengine.boolean_layoutremove();
        Core.Type_any output_1 = Core.vx_any_from_func(
          Core.t_boolean,
          fn_layoutremove,
          ui
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutremove_from_ui_start_end
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {int} start
   * @param  {int} end
   * @return {boolean}
   * (func boolean-layoutremove<-ui-start-end)
   */
  public interface Func_boolean_layoutremove_from_ui_start_end extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_start_end(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_boolean_layoutremove_from_ui_start_end extends Core.Class_base implements Func_boolean_layoutremove_from_ui_start_end {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_start_end output = new Ui.Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutremove_from_ui_start_end output = new Ui.Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-start-end", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutremove_from_ui_start_end;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutremove_from_ui_start_end;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutremove_from_ui_start_end(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_int start, final Core.Type_int end) {
      Core.Type_boolean output = Ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutremove_from_ui_start_end e_boolean_layoutremove_from_ui_start_end = new Ui.Class_boolean_layoutremove_from_ui_start_end();
  public static final Ui.Func_boolean_layoutremove_from_ui_start_end t_boolean_layoutremove_from_ui_start_end = new Ui.Class_boolean_layoutremove_from_ui_start_end();

  public static Core.Type_boolean f_boolean_layoutremove_from_ui_start_end(final Core.Type_context context, final Ui.Type_ui ui, final Core.Type_int start, final Core.Type_int end) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Core.Type_stringlist keys = Core.f_stringlist_from_map(
          uimap
        );
        Core.Type_stringlist subkeys = Collection.f_list_from_list_start_end(
          Core.t_stringlist,
          keys,
          start,
          end
        );
        Core.Type_any output_1 = Ui.f_boolean_layoutremove_from_ui_keys(
          context,
          ui,
          subkeys
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutselected_from_ui
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutselected<-ui)
   */
  public interface Func_boolean_layoutselected_from_ui extends Core.Func_any_from_any {
    public Core.Type_boolean vx_boolean_layoutselected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_boolean_layoutselected_from_ui extends Core.Class_base implements Func_boolean_layoutselected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui output = new Ui.Class_boolean_layoutselected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui output = new Ui.Class_boolean_layoutselected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutselected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutselected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_layoutselected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_layoutselected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutselected_from_ui(final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_layoutselected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutselected_from_ui e_boolean_layoutselected_from_ui = new Ui.Class_boolean_layoutselected_from_ui();
  public static final Ui.Func_boolean_layoutselected_from_ui t_boolean_layoutselected_from_ui = new Ui.Class_boolean_layoutselected_from_ui();

  public static Core.Type_boolean f_boolean_layoutselected_from_ui(final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_layoutselected_from_ui_parent
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {ui} parent
   * @return {boolean}
   * (func boolean-layoutselected<-ui-parent)
   */
  public interface Func_boolean_layoutselected_from_ui_parent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutselected_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent);
  }

  public static class Class_boolean_layoutselected_from_ui_parent extends Core.Class_base implements Func_boolean_layoutselected_from_ui_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui_parent output = new Ui.Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui_parent output = new Ui.Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutselected_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutselected_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutselected_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent) {
      Core.Type_boolean output = Ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutselected_from_ui_parent e_boolean_layoutselected_from_ui_parent = new Ui.Class_boolean_layoutselected_from_ui_parent();
  public static final Ui.Func_boolean_layoutselected_from_ui_parent t_boolean_layoutselected_from_ui_parent = new Ui.Class_boolean_layoutselected_from_ui_parent();

  public static Core.Type_boolean f_boolean_layoutselected_from_ui_parent(final Core.Type_context context, final Ui.Type_ui ui, final Ui.Type_ui parent) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Core.Type_boolean iswrite = Ui.f_boolean_write_from_ui_parent(
          ui,
          parent
        );
        Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        Core.Type_any output_1 = Core.vx_any_from_func(
          Core.t_boolean,
          fn_layoutselected,
          ui
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutselected_from_ui_selected
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {int} selected
   * @return {boolean}
   * (func boolean-layoutselected<-ui-selected)
   */
  public interface Func_boolean_layoutselected_from_ui_selected extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_layoutselected_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected);
  }

  public static class Class_boolean_layoutselected_from_ui_selected extends Core.Class_base implements Func_boolean_layoutselected_from_ui_selected {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui_selected output = new Ui.Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutselected_from_ui_selected output = new Ui.Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-selected", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutselected_from_ui_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutselected_from_ui_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int selected = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_layoutselected_from_ui_selected(ui, selected);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutselected_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected) {
      Core.Type_boolean output = Ui.f_boolean_layoutselected_from_ui_selected(ui, selected);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutselected_from_ui_selected e_boolean_layoutselected_from_ui_selected = new Ui.Class_boolean_layoutselected_from_ui_selected();
  public static final Ui.Func_boolean_layoutselected_from_ui_selected t_boolean_layoutselected_from_ui_selected = new Ui.Class_boolean_layoutselected_from_ui_selected();

  public static Core.Type_boolean f_boolean_layoutselected_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_layoutvisible_from_ui
   * Writes to an html node adding or removing the hidden class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutvisible<-ui)
   */
  public interface Func_boolean_layoutvisible_from_ui extends Core.Func_any_from_any {
    public Core.Type_boolean vx_boolean_layoutvisible_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_boolean_layoutvisible_from_ui extends Core.Class_base implements Func_boolean_layoutvisible_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_layoutvisible_from_ui output = new Ui.Class_boolean_layoutvisible_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_layoutvisible_from_ui output = new Ui.Class_boolean_layoutvisible_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutvisible<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_layoutvisible_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_layoutvisible_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_layoutvisible_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_layoutvisible_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_layoutvisible_from_ui(final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_layoutvisible_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_layoutvisible_from_ui e_boolean_layoutvisible_from_ui = new Ui.Class_boolean_layoutvisible_from_ui();
  public static final Ui.Func_boolean_layoutvisible_from_ui t_boolean_layoutvisible_from_ui = new Ui.Class_boolean_layoutvisible_from_ui();

  public static Core.Type_boolean f_boolean_layoutvisible_from_ui(final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_print
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-print)
   */
  public interface Func_boolean_print extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_print(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_boolean_print extends Core.Class_base implements Func_boolean_print {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_print output = new Ui.Class_boolean_print();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_print output = new Ui.Class_boolean_print();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-print", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_print;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_print;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_print(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_print(context, ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_print(final Core.Type_context context, final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_print(context, ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_print e_boolean_print = new Ui.Class_boolean_print();
  public static final Ui.Func_boolean_print t_boolean_print = new Ui.Class_boolean_print();

  public static Core.Type_boolean f_boolean_print(final Core.Type_context context, final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Ui.Func_boolean_print fn_print = layoutengine.boolean_print();
        Core.Type_any output_1 = Core.vx_any_from_func(
          Core.t_boolean,
          fn_print,
          context,
          ui
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_removestate_uiapp
   * Returns true if uiapp was successfully removed from state.
   * @return {boolean}
   * (func boolean-removestate-uiapp)
   */
  public interface Func_boolean_removestate_uiapp extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_removestate_uiapp(final Core.Type_context context);
  }

  public static class Class_boolean_removestate_uiapp extends Core.Class_base implements Func_boolean_removestate_uiapp {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_removestate_uiapp output = new Ui.Class_boolean_removestate_uiapp();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_removestate_uiapp output = new Ui.Class_boolean_removestate_uiapp();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-removestate-uiapp", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_removestate_uiapp;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_removestate_uiapp;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_removestate_uiapp(context);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_removestate_uiapp(final Core.Type_context context) {
      Core.Type_boolean output = Ui.f_boolean_removestate_uiapp(context);
      return output;
    }

  }

  public static final Ui.Func_boolean_removestate_uiapp e_boolean_removestate_uiapp = new Ui.Class_boolean_removestate_uiapp();
  public static final Ui.Func_boolean_removestate_uiapp t_boolean_removestate_uiapp = new Ui.Class_boolean_removestate_uiapp();

  public static Core.Type_boolean f_boolean_removestate_uiapp(final Core.Type_context context) {
    Core.Type_boolean output = Core.e_boolean;
    output = State.f_boolean_removestate_from_name(
      context,
      Core.vx_new_string(":uiapp")
    );
    return output;
  }

  /**
   * @function boolean_write_from_ui_parent
   * Returns true if the given ui was added to parent uimap
   * @param  {ui} ui
   * @param  {ui} parent
   * @return {boolean}
   * (func boolean-write<-ui-parent)
   */
  public interface Func_boolean_write_from_ui_parent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_ui_parent(final Ui.Type_ui ui, final Ui.Type_ui parent);
  }

  public static class Class_boolean_write_from_ui_parent extends Core.Class_base implements Func_boolean_write_from_ui_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_write_from_ui_parent output = new Ui.Class_boolean_write_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_write_from_ui_parent output = new Ui.Class_boolean_write_from_ui_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-write<-ui-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_write_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_write_from_ui_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_write_from_ui_parent(ui, parent);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_ui_parent(final Ui.Type_ui ui, final Ui.Type_ui parent) {
      Core.Type_boolean output = Ui.f_boolean_write_from_ui_parent(ui, parent);
      return output;
    }

  }

  public static final Ui.Func_boolean_write_from_ui_parent e_boolean_write_from_ui_parent = new Ui.Class_boolean_write_from_ui_parent();
  public static final Ui.Func_boolean_write_from_ui_parent t_boolean_write_from_ui_parent = new Ui.Class_boolean_write_from_ui_parent();

  public static Core.Type_boolean f_boolean_write_from_ui_parent(final Ui.Type_ui ui, final Ui.Type_ui parent) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string uid = ui.uid();
        Ui.Type_uimap uimap = parent.uimap();
        Core.Type_any output_1 = Core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          ui
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeremove_from_ui_uid
   * Returns true if the given uid was removed from ui uimap
   * @param  {ui} uiarg
   * @param  {string} uid
   * @return {boolean}
   * (func boolean-writeremove<-ui-uid)
   */
  public interface Func_boolean_writeremove_from_ui_uid extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_writeremove_from_ui_uid(final Ui.Type_ui uiarg, final Core.Type_string uid);
  }

  public static class Class_boolean_writeremove_from_ui_uid extends Core.Class_base implements Func_boolean_writeremove_from_ui_uid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_writeremove_from_ui_uid output = new Ui.Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_writeremove_from_ui_uid output = new Ui.Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writeremove<-ui-uid", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_writeremove_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_writeremove_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_boolean_writeremove_from_ui_uid(uiarg, uid);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writeremove_from_ui_uid(final Ui.Type_ui uiarg, final Core.Type_string uid) {
      Core.Type_boolean output = Ui.f_boolean_writeremove_from_ui_uid(uiarg, uid);
      return output;
    }

  }

  public static final Ui.Func_boolean_writeremove_from_ui_uid e_boolean_writeremove_from_ui_uid = new Ui.Class_boolean_writeremove_from_ui_uid();
  public static final Ui.Func_boolean_writeremove_from_ui_uid t_boolean_writeremove_from_ui_uid = new Ui.Class_boolean_writeremove_from_ui_uid();

  public static Core.Type_boolean f_boolean_writeremove_from_ui_uid(final Ui.Type_ui uiarg, final Core.Type_string uid) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = uiarg.uimap();
        Core.Type_any output_1 = Core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          Core.f_empty(
            Ui.t_ui
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writestate<-ui)
   */
  public interface Func_boolean_writestate_from_ui extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_boolean_writestate_from_ui extends Core.Class_base implements Func_boolean_writestate_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_writestate_from_ui output = new Ui.Class_boolean_writestate_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_writestate_from_ui output = new Ui.Class_boolean_writestate_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_writestate_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_writestate_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_writestate_from_ui(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_writestate_from_ui(context, ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_writestate_from_ui(context, ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = new Ui.Class_boolean_writestate_from_ui();
  public static final Ui.Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = new Ui.Class_boolean_writestate_from_ui();

  public static Core.Type_boolean f_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string uid = ui.uid();
        Ui.Type_ui uiapp = Ui.f_ui_readstate_uiapp(
          context
        );
        Core.Type_string parentuid = Ui.f_string_parentuid_from_uid(
          uid
        );
        Ui.Type_ui parentui = Core.f_if_2(
          Ui.t_ui,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  Core.vx_new_string(""),
                  parentuid
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = uiapp;
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Ui.f_ui_from_ui_find(
                  uiapp,
                  parentuid
                );
                return output_4;
              })
            )
          )
        );
        Core.Type_boolean isfound = Core.f_notempty_1(
          parentui
        );
        Core.Type_boolean iswrite = Core.f_if_2(
          Core.t_boolean,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = isfound;
                return output_5;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Ui.f_boolean_write_from_ui_parent(
                  ui,
                  parentui
                );
                return output_6;
              })
            )
          )
        );
        Core.Type_any output_1 = isfound;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_uiapp
   * Returns true if successful write to :uiapp state
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writestate<-uiapp)
   */
  public interface Func_boolean_writestate_from_uiapp extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_writestate_from_uiapp(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_boolean_writestate_from_uiapp extends Core.Class_base implements Func_boolean_writestate_from_uiapp {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_writestate_from_uiapp output = new Ui.Class_boolean_writestate_from_uiapp();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_writestate_from_uiapp output = new Ui.Class_boolean_writestate_from_uiapp();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiapp", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_writestate_from_uiapp;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_writestate_from_uiapp;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_writestate_from_uiapp(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_writestate_from_uiapp(context, ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writestate_from_uiapp(final Core.Type_context context, final Ui.Type_ui ui) {
      Core.Type_boolean output = Ui.f_boolean_writestate_from_uiapp(context, ui);
      return output;
    }

  }

  public static final Ui.Func_boolean_writestate_from_uiapp e_boolean_writestate_from_uiapp = new Ui.Class_boolean_writestate_from_uiapp();
  public static final Ui.Func_boolean_writestate_from_uiapp t_boolean_writestate_from_uiapp = new Ui.Class_boolean_writestate_from_uiapp();

  public static Core.Type_boolean f_boolean_writestate_from_uiapp(final Core.Type_context context, final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    output = State.f_boolean_writestate_from_name_value(
      context,
      Core.vx_new_string(":uiapp"),
      ui
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_uiengine
   * Writes the uiengine to state
   * @param  {uiengine} uiengine
   * @return {boolean}
   * (func boolean-writestate<-uiengine)
   */
  public interface Func_boolean_writestate_from_uiengine extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine);
  }

  public static class Class_boolean_writestate_from_uiengine extends Core.Class_base implements Func_boolean_writestate_from_uiengine {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_boolean_writestate_from_uiengine output = new Ui.Class_boolean_writestate_from_uiengine();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_boolean_writestate_from_uiengine output = new Ui.Class_boolean_writestate_from_uiengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiengine", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_boolean_writestate_from_uiengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_boolean_writestate_from_uiengine;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uiengine inputval = (Ui.Type_uiengine)value;
      Core.Type_any outputval = Ui.f_boolean_writestate_from_uiengine(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_writestate_from_uiengine(context, uiengine);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
      Core.Type_boolean output = Ui.f_boolean_writestate_from_uiengine(context, uiengine);
      return output;
    }

  }

  public static final Ui.Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = new Ui.Class_boolean_writestate_from_uiengine();
  public static final Ui.Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = new Ui.Class_boolean_writestate_from_uiengine();

  public static Core.Type_boolean f_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
    Core.Type_boolean output = Core.e_boolean;
    output = State.f_boolean_writestate_from_name_value(
      context,
      Core.vx_new_string(":uiengine"),
      uiengine
    );
    return output;
  }

  /**
   * @function fontfacemap_from_fontfacelist
   * Returns a fontfacemap from a fontfacelist
   * @param  {fontfacelist} fontfacelist
   * @return {fontfacemap}
   * (func fontfacemap<-fontfacelist)
   */
  public interface Func_fontfacemap_from_fontfacelist extends Core.Func_any_from_any {
    public Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist);
  }

  public static class Class_fontfacemap_from_fontfacelist extends Core.Class_base implements Func_fontfacemap_from_fontfacelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_fontfacemap_from_fontfacelist output = new Ui.Class_fontfacemap_from_fontfacelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_fontfacemap_from_fontfacelist output = new Ui.Class_fontfacemap_from_fontfacelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "fontfacemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_fontface), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_fontfacemap_from_fontfacelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_fontfacemap_from_fontfacelist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_fontfacelist inputval = (Ui.Type_fontfacelist)value;
      Core.Type_any outputval = Ui.f_fontfacemap_from_fontfacelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_fontfacelist fontfacelist = Core.f_any_from_any(Ui.t_fontfacelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
      return output;
    }

    @Override
    public Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist) {
      Ui.Type_fontfacemap output = Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
      return output;
    }

  }

  public static final Ui.Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist = new Ui.Class_fontfacemap_from_fontfacelist();
  public static final Ui.Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist = new Ui.Class_fontfacemap_from_fontfacelist();

  public static Ui.Type_fontfacemap f_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist) {
    Ui.Type_fontfacemap output = Ui.e_fontfacemap;
    output = Core.f_map_from_list(
      Ui.t_fontfacemap,
      fontfacelist,
      Core.t_any_from_any.vx_fn_new((fontface_any) -> {
        Ui.Type_fontface fontface = Core.f_any_from_any(Ui.t_fontface, fontface_any);
        Core.Type_any output_1 = fontface.name();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function int_child_from_ui_uid
   * Returns the position of the currently selected subui
   * @param  {ui} ui
   * @param  {string} uid
   * @return {int}
   * (func int-child<-ui-uid)
   */
  public interface Func_int_child_from_ui_uid extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid);
  }

  public static class Class_int_child_from_ui_uid extends Core.Class_base implements Func_int_child_from_ui_uid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_int_child_from_ui_uid output = new Ui.Class_int_child_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_int_child_from_ui_uid output = new Ui.Class_int_child_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-child<-ui-uid", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_int_child_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_int_child_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_int_child_from_ui_uid(ui, uid);
      return output;
    }

    @Override
    public Core.Type_int vx_int_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
      Core.Type_int output = Ui.f_int_child_from_ui_uid(ui, uid);
      return output;
    }

  }

  public static final Ui.Func_int_child_from_ui_uid e_int_child_from_ui_uid = new Ui.Class_int_child_from_ui_uid();
  public static final Ui.Func_int_child_from_ui_uid t_int_child_from_ui_uid = new Ui.Class_int_child_from_ui_uid();

  public static Core.Type_int f_int_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
    Core.Type_int output = Core.e_int;
    output = Core.f_let(
      Core.t_int,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Core.Type_any output_1 = Collection.f_int_from_map_key(
          uimap,
          uid
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function int_selected_from_ui
   * Returns the position of the currently selected subui
   * @param  {ui} ui
   * @return {int}
   * (func int-selected<-ui)
   */
  public interface Func_int_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_int vx_int_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_int_selected_from_ui extends Core.Class_base implements Func_int_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_int_selected_from_ui output = new Ui.Class_int_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_int_selected_from_ui output = new Ui.Class_int_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_int_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_int_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_int_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_int_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_int vx_int_selected_from_ui(final Ui.Type_ui ui) {
      Core.Type_int output = Ui.f_int_selected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_int_selected_from_ui e_int_selected_from_ui = new Ui.Class_int_selected_from_ui();
  public static final Ui.Func_int_selected_from_ui t_int_selected_from_ui = new Ui.Class_int_selected_from_ui();

  public static Core.Type_int f_int_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_int output = Core.e_int;
    output = Core.f_let(
      Core.t_int,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string uid = Ui.f_string_selected_from_ui(
          ui
        );
        Core.Type_stringlist uidlist = Ui.f_stringlist_from_ui(
          ui
        );
        Core.Type_any output_1 = Collection.f_int_from_stringlist_find(
          uidlist,
          uid
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function int_visible_from_ui
   * Returns the position of the currently visible subui
   * @param  {ui} ui
   * @return {int}
   * (func int-visible<-ui)
   */
  public interface Func_int_visible_from_ui extends Core.Func_any_from_any {
    public Core.Type_int vx_int_visible_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_int_visible_from_ui extends Core.Class_base implements Func_int_visible_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_int_visible_from_ui output = new Ui.Class_int_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_int_visible_from_ui output = new Ui.Class_int_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-visible<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_int_visible_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_int_visible_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_int_visible_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_int_visible_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_int vx_int_visible_from_ui(final Ui.Type_ui ui) {
      Core.Type_int output = Ui.f_int_visible_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_int_visible_from_ui e_int_visible_from_ui = new Ui.Class_int_visible_from_ui();
  public static final Ui.Func_int_visible_from_ui t_int_visible_from_ui = new Ui.Class_int_visible_from_ui();

  public static Core.Type_int f_int_visible_from_ui(final Ui.Type_ui ui) {
    Core.Type_int output = Core.e_int;
    output = Core.f_let(
      Core.t_int,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_intlist intlist = Ui.f_intlist_visible_from_ui(
          ui
        );
        Core.Type_any output_1 = Core.f_first_from_list(
          Core.t_int,
          intlist
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function intlist_visible_from_ui
   * Return a uilist of the ui with selected=true
   * @param  {ui} uiarg
   * @return {intlist}
   * (func intlist-visible<-ui)
   */
  public interface Func_intlist_visible_from_ui extends Core.Func_any_from_any {
    public Core.Type_intlist vx_intlist_visible_from_ui(final Ui.Type_ui uiarg);
  }

  public static class Class_intlist_visible_from_ui extends Core.Class_base implements Func_intlist_visible_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_intlist_visible_from_ui output = new Ui.Class_intlist_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_intlist_visible_from_ui output = new Ui.Class_intlist_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "intlist-visible<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "intlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_int), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_intlist_visible_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_intlist_visible_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_intlist_visible_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_intlist_visible_from_ui(uiarg);
      return output;
    }

    @Override
    public Core.Type_intlist vx_intlist_visible_from_ui(final Ui.Type_ui uiarg) {
      Core.Type_intlist output = Ui.f_intlist_visible_from_ui(uiarg);
      return output;
    }

  }

  public static final Ui.Func_intlist_visible_from_ui e_intlist_visible_from_ui = new Ui.Class_intlist_visible_from_ui();
  public static final Ui.Func_intlist_visible_from_ui t_intlist_visible_from_ui = new Ui.Class_intlist_visible_from_ui();

  public static Core.Type_intlist f_intlist_visible_from_ui(final Ui.Type_ui uiarg) {
    Core.Type_intlist output = Core.e_intlist;
    output = Core.f_let(
      Core.t_intlist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = uiarg.uimap();
        Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(
          uimap
        );
        Ui.Type_uilist intlist = Core.f_list_from_list_intany(
          Ui.t_uilist,
          uilist,
          Core.t_any_from_int_any.vx_fn_new((pos_any, subui_any) -> {
            Core.Type_int pos = Core.f_any_from_any(Core.t_int, pos_any);
            Ui.Type_ui subui = Core.f_any_from_any(Ui.t_ui, subui_any);
            Core.Type_any output_3 = Core.f_if_2(
              Core.t_int,
              Core.vx_new(
                Core.t_thenelselist,
                Core.f_then(
                  Core.t_boolean_from_func.vx_fn_new(() -> {
                    Core.Type_any output_4 = Core.f_not(
                      subui.hidden()
                    );
                    return output_4;
                  }),
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Core.Type_any output_5 = pos;
                    return output_5;
                  })
                )
              )
            );
            return output_3;
          })
        );
        Core.Type_any output_1 = Collection.f_list_from_list_filter(
          Core.t_intlist,
          intlist,
          Core.t_any_from_any.vx_fn_new((pos_any) -> {
            Core.Type_int pos = Core.f_any_from_any(Core.t_int, pos_any);
            Core.Type_any output_2 = pos;
            return output_2;
          })
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function layout_from_style
   * @param  {style} style
   * @return {layout}
   * (func layout<-style)
   */
  public interface Func_layout_from_style extends Core.Func_any_from_any {
    public Ui.Type_layout vx_layout_from_style(final Ui.Type_style style);
  }

  public static class Class_layout_from_style extends Core.Class_base implements Func_layout_from_style {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layout_from_style output = new Ui.Class_layout_from_style();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layout_from_style output = new Ui.Class_layout_from_style();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-style", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layout_from_style;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layout_from_style;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_style inputval = (Ui.Type_style)value;
      Core.Type_any outputval = Ui.f_layout_from_style(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_style style = Core.f_any_from_any(Ui.t_style, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layout_from_style(style);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_style(final Ui.Type_style style) {
      Ui.Type_layout output = Ui.f_layout_from_style(style);
      return output;
    }

  }

  public static final Ui.Func_layout_from_style e_layout_from_style = new Ui.Class_layout_from_style();
  public static final Ui.Func_layout_from_style t_layout_from_style = new Ui.Class_layout_from_style();

  public static Ui.Type_layout f_layout_from_style(final Ui.Type_style style) {
    Ui.Type_layout output = Ui.e_layout;
    output = style.layout();
    return output;
  }

  /**
   * @function layout_from_ui
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @return {layout}
   * (func layout<-ui)
   */
  public interface Func_layout_from_ui extends Core.Func_any_from_any_context {
    public Ui.Type_layout vx_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_layout_from_ui extends Core.Class_base implements Func_layout_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layout_from_ui output = new Ui.Class_layout_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layout_from_ui output = new Ui.Class_layout_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layout_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layout_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_layout_from_ui(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layout_from_ui(context, ui);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      Ui.Type_layout output = Ui.f_layout_from_ui(context, ui);
      return output;
    }

  }

  public static final Ui.Func_layout_from_ui e_layout_from_ui = new Ui.Class_layout_from_ui();
  public static final Ui.Func_layout_from_ui t_layout_from_ui = new Ui.Class_layout_from_ui();

  public static Ui.Type_layout f_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(
          context
        );
        Core.Type_any output_1 = Ui.f_layout_from_ui_layoutengine(
          ui,
          layoutengine
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function layout_from_ui_layoutengine
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {layout}
   * (func layout<-ui-layoutengine)
   */
  public interface Func_layout_from_ui_layoutengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layout vx_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine);
  }

  public static class Class_layout_from_ui_layoutengine extends Core.Class_base implements Func_layout_from_ui_layoutengine {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layout_from_ui_layoutengine output = new Ui.Class_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layout_from_ui_layoutengine output = new Ui.Class_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutengine", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layout_from_ui_layoutengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layout_from_ui_layoutengine;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutengine layoutengine = Core.f_any_from_any(Ui.t_layoutengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
      Ui.Type_layout output = Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

  }

  public static final Ui.Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine = new Ui.Class_layout_from_ui_layoutengine();
  public static final Ui.Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine = new Ui.Class_layout_from_ui_layoutengine();

  public static Ui.Type_layout f_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Ui.Type_layout layoutelse = layoutengine.layoutelse();
        Core.Type_any output_1 = Ui.f_layout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function layout_from_ui_layoutmap_else
   * Returns a layout from a given ui, layoutmap, and layoutelse
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {layout}
   * (func layout<-ui-layoutmap-else)
   */
  public interface Func_layout_from_ui_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layout vx_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_layout_from_ui_layoutmap_else extends Core.Class_base implements Func_layout_from_ui_layoutmap_else {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layout_from_ui_layoutmap_else output = new Ui.Class_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layout_from_ui_layoutmap_else output = new Ui.Class_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layout_from_ui_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layout_from_ui_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutmap layoutmap = Core.f_any_from_any(Ui.t_layoutmap, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_layout layoutelse = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
      Ui.Type_layout output = Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

  }

  public static final Ui.Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else = new Ui.Class_layout_from_ui_layoutmap_else();
  public static final Ui.Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else = new Ui.Class_layout_from_ui_layoutmap_else();

  public static Ui.Type_layout f_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_style style = ui.style();
        Ui.Type_layout layout = Ui.f_layout_from_style(
          style
        );
        Core.Type_string layname = layout.name();
        Ui.Type_layout layout1 = Core.f_any_from_map(
          Ui.t_layout,
          layoutmap,
          layname
        );
        Ui.Type_layout layout2 = Core.f_if_1(
          Ui.t_layout,
          Core.f_notempty_1(
            layout1
          ),
          layout1,
          layoutelse
        );
        Core.Type_any output_1 = layout2;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function layoutengine_readstate
   * Returns the current layoutengine from state
   * @return {layoutengine}
   * (func layoutengine-readstate)
   */
  public interface Func_layoutengine_readstate extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layoutengine vx_layoutengine_readstate(final Core.Type_context context);
  }

  public static class Class_layoutengine_readstate extends Core.Class_base implements Func_layoutengine_readstate {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layoutengine_readstate output = new Ui.Class_layoutengine_readstate();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layoutengine_readstate output = new Ui.Class_layoutengine_readstate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutengine-readstate", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layoutengine_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layoutengine_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layoutengine_readstate(context);
      return output;
    }

    @Override
    public Ui.Type_layoutengine vx_layoutengine_readstate(final Core.Type_context context) {
      Ui.Type_layoutengine output = Ui.f_layoutengine_readstate(context);
      return output;
    }

  }

  public static final Ui.Func_layoutengine_readstate e_layoutengine_readstate = new Ui.Class_layoutengine_readstate();
  public static final Ui.Func_layoutengine_readstate t_layoutengine_readstate = new Ui.Class_layoutengine_readstate();

  public static Ui.Type_layoutengine f_layoutengine_readstate(final Core.Type_context context) {
    Ui.Type_layoutengine output = Ui.e_layoutengine;
    output = Core.f_let(
      Ui.t_layoutengine,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uiengine uiengine = Ui.f_uiengine_readstate(
          context
        );
        Core.Type_any output_1 = uiengine.layoutengine();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function layoutmap_from_layoutlist
   * Returns an layoutmap from an layoutlist
   * @param  {layoutlist} layoutlist
   * @return {layoutmap}
   * (func layoutmap<-layoutlist)
   */
  public interface Func_layoutmap_from_layoutlist extends Core.Func_any_from_any {
    public Ui.Type_layoutmap vx_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist);
  }

  public static class Class_layoutmap_from_layoutlist extends Core.Class_base implements Func_layoutmap_from_layoutlist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_layoutmap_from_layoutlist output = new Ui.Class_layoutmap_from_layoutlist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_layoutmap_from_layoutlist output = new Ui.Class_layoutmap_from_layoutlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_layout), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_layoutmap_from_layoutlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_layoutmap_from_layoutlist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_layoutlist inputval = (Ui.Type_layoutlist)value;
      Core.Type_any outputval = Ui.f_layoutmap_from_layoutlist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_layoutlist layoutlist = Core.f_any_from_any(Ui.t_layoutlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layoutmap_from_layoutlist(layoutlist);
      return output;
    }

    @Override
    public Ui.Type_layoutmap vx_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist) {
      Ui.Type_layoutmap output = Ui.f_layoutmap_from_layoutlist(layoutlist);
      return output;
    }

  }

  public static final Ui.Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = new Ui.Class_layoutmap_from_layoutlist();
  public static final Ui.Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = new Ui.Class_layoutmap_from_layoutlist();

  public static Ui.Type_layoutmap f_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist) {
    Ui.Type_layoutmap output = Ui.e_layoutmap;
    output = Core.f_map_from_list(
      Ui.t_layoutmap,
      layoutlist,
      Core.t_any_from_any.vx_fn_new((layout_any) -> {
        Ui.Type_layout layout = Core.f_any_from_any(Ui.t_layout, layout_any);
        Core.Type_any output_1 = layout.name();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_parentuid_from_uid
   * Returns the parent uid of a given uid
   * @param  {string} uid
   * @return {string}
   * (func string-parentuid<-uid)
   */
  public interface Func_string_parentuid_from_uid extends Core.Func_any_from_any {
    public Core.Type_string vx_string_parentuid_from_uid(final Core.Type_string uid);
  }

  public static class Class_string_parentuid_from_uid extends Core.Class_base implements Func_string_parentuid_from_uid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_string_parentuid_from_uid output = new Ui.Class_string_parentuid_from_uid();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_string_parentuid_from_uid output = new Ui.Class_string_parentuid_from_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-parentuid<-uid", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_string_parentuid_from_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_string_parentuid_from_uid;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Ui.f_string_parentuid_from_uid(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_string_parentuid_from_uid(uid);
      return output;
    }

    @Override
    public Core.Type_string vx_string_parentuid_from_uid(final Core.Type_string uid) {
      Core.Type_string output = Ui.f_string_parentuid_from_uid(uid);
      return output;
    }

  }

  public static final Ui.Func_string_parentuid_from_uid e_string_parentuid_from_uid = new Ui.Class_string_parentuid_from_uid();
  public static final Ui.Func_string_parentuid_from_uid t_string_parentuid_from_uid = new Ui.Class_string_parentuid_from_uid();

  public static Core.Type_string f_string_parentuid_from_uid(final Core.Type_string uid) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int lastpos = Type.f_int_from_string_findlast(
          uid,
          Core.vx_new_string("/")
        );
        Core.Type_any output_1 = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_gt(
                  lastpos,
                  Core.vx_new_int(0)
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Type.f_string_from_string_end(
                  uid,
                  Core.f_minus(
                    lastpos,
                    Core.vx_new_int(1)
                  )
                );
                return output_3;
              })
            )
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_selected_from_ui
   * Return the uid of the ui with selected=true
   * @param  {ui} ui
   * @return {string}
   * (func string-selected<-ui)
   */
  public interface Func_string_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_string vx_string_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_string_selected_from_ui extends Core.Class_base implements Func_string_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_string_selected_from_ui output = new Ui.Class_string_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_string_selected_from_ui output = new Ui.Class_string_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_string_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_string_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_string_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_string_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_string vx_string_selected_from_ui(final Ui.Type_ui ui) {
      Core.Type_string output = Ui.f_string_selected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_string_selected_from_ui e_string_selected_from_ui = new Ui.Class_string_selected_from_ui();
  public static final Ui.Func_string_selected_from_ui t_string_selected_from_ui = new Ui.Class_string_selected_from_ui();

  public static Core.Type_string f_string_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_ui selectedui = Ui.f_ui_selected_from_ui(
          ui
        );
        Core.Type_any output_1 = selectedui.uid();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stringlist_selected_from_ui
   * Return a list of uid of the ui with selected=true
   * @param  {ui} ui
   * @return {stringlist}
   * (func stringlist-selected<-ui)
   */
  public interface Func_stringlist_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_stringlist_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_stringlist_selected_from_ui extends Core.Class_base implements Func_stringlist_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_stringlist_selected_from_ui output = new Ui.Class_stringlist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_stringlist_selected_from_ui output = new Ui.Class_stringlist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_string), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stringlist_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stringlist_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_stringlist_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stringlist_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist_selected_from_ui(final Ui.Type_ui ui) {
      Core.Type_stringlist output = Ui.f_stringlist_selected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_stringlist_selected_from_ui e_stringlist_selected_from_ui = new Ui.Class_stringlist_selected_from_ui();
  public static final Ui.Func_stringlist_selected_from_ui t_stringlist_selected_from_ui = new Ui.Class_stringlist_selected_from_ui();

  public static Core.Type_stringlist f_stringlist_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_let(
      Core.t_stringlist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(
          uimap
        );
        Core.Type_any output_1 = Core.f_list_from_list_1(
          Core.t_stringlist,
          uilist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
            Core.Type_any output_2 = Core.f_if_1(
              Core.t_string,
              item.selected(),
              item.uid(),
              Core.vx_new_string("")
            );
            return output_2;
          })
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stringlist_from_ui
   * Return a list of uid of the ui
   * @param  {ui} ui
   * @return {stringlist}
   * (func stringlist<-ui)
   */
  public interface Func_stringlist_from_ui extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_stringlist_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_stringlist_from_ui extends Core.Class_base implements Func_stringlist_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_stringlist_from_ui output = new Ui.Class_stringlist_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_stringlist_from_ui output = new Ui.Class_stringlist_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_string), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stringlist_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stringlist_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_stringlist_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stringlist_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist_from_ui(final Ui.Type_ui ui) {
      Core.Type_stringlist output = Ui.f_stringlist_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_stringlist_from_ui e_stringlist_from_ui = new Ui.Class_stringlist_from_ui();
  public static final Ui.Func_stringlist_from_ui t_stringlist_from_ui = new Ui.Class_stringlist_from_ui();

  public static Core.Type_stringlist f_stringlist_from_ui(final Ui.Type_ui ui) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_let(
      Core.t_stringlist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Core.Type_any output_1 = Core.f_stringlist_from_map(
          uimap
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stylemap_from_stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   * (func stylemap<-stylelist)
   */
  public interface Func_stylemap_from_stylelist extends Core.Func_any_from_any {
    public Ui.Type_stylemap vx_stylemap_from_stylelist(final Ui.Type_stylelist stylelist);
  }

  public static class Class_stylemap_from_stylelist extends Core.Class_base implements Func_stylemap_from_stylelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_stylemap_from_stylelist output = new Ui.Class_stylemap_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_stylemap_from_stylelist output = new Ui.Class_stylemap_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_style), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylemap_from_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylemap_from_stylelist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylelist inputval = (Ui.Type_stylelist)value;
      Core.Type_any outputval = Ui.f_stylemap_from_stylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylelist stylelist = Core.f_any_from_any(Ui.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stylemap_from_stylelist(stylelist);
      return output;
    }

    @Override
    public Ui.Type_stylemap vx_stylemap_from_stylelist(final Ui.Type_stylelist stylelist) {
      Ui.Type_stylemap output = Ui.f_stylemap_from_stylelist(stylelist);
      return output;
    }

  }

  public static final Ui.Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Ui.Class_stylemap_from_stylelist();
  public static final Ui.Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Ui.Class_stylemap_from_stylelist();

  public static Ui.Type_stylemap f_stylemap_from_stylelist(final Ui.Type_stylelist stylelist) {
    Ui.Type_stylemap output = Ui.e_stylemap;
    output = Core.f_map_from_list(
      Ui.t_stylemap,
      stylelist,
      Core.t_any_from_any.vx_fn_new((style_any) -> {
        Ui.Type_style style = Core.f_any_from_any(Ui.t_style, style_any);
        Core.Type_any output_1 = style.name();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stylesheet_readstate
   * Returns the current uiengine from state
   * @return {stylesheet}
   * (func stylesheet-readstate)
   */
  public interface Func_stylesheet_readstate extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_stylesheet vx_stylesheet_readstate(final Core.Type_context context);
  }

  public static class Class_stylesheet_readstate extends Core.Class_base implements Func_stylesheet_readstate {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_stylesheet_readstate output = new Ui.Class_stylesheet_readstate();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_stylesheet_readstate output = new Ui.Class_stylesheet_readstate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-readstate", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylesheet_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylesheet_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stylesheet_readstate(context);
      return output;
    }

    @Override
    public Ui.Type_stylesheet vx_stylesheet_readstate(final Core.Type_context context) {
      Ui.Type_stylesheet output = Ui.f_stylesheet_readstate(context);
      return output;
    }

  }

  public static final Ui.Func_stylesheet_readstate e_stylesheet_readstate = new Ui.Class_stylesheet_readstate();
  public static final Ui.Func_stylesheet_readstate t_stylesheet_readstate = new Ui.Class_stylesheet_readstate();

  public static Ui.Type_stylesheet f_stylesheet_readstate(final Core.Type_context context) {
    Ui.Type_stylesheet output = Ui.e_stylesheet;
    output = Core.f_let(
      Ui.t_stylesheet,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uiengine uiengine = Ui.f_uiengine_readstate(
          context
        );
        Core.Type_any output_1 = uiengine.stylesheet();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stylesheet_render
   * Template for rendering stylesheet
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   * (func stylesheet-render)
   */
  public interface Func_stylesheet_render extends Core.Func_any_from_any {
    public Ui.Type_stylesheet vx_stylesheet_render(final Ui.Type_stylesheet stylesheetui);
  }

  public static class Class_stylesheet_render extends Core.Class_base implements Func_stylesheet_render {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_stylesheet_render output = new Ui.Class_stylesheet_render();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_stylesheet_render output = new Ui.Class_stylesheet_render();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-render", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_stylesheet_render;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_stylesheet_render;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylesheet inputval = (Ui.Type_stylesheet)value;
      Core.Type_any outputval = Ui.f_stylesheet_render(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylesheet stylesheetui = Core.f_any_from_any(Ui.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stylesheet_render(stylesheetui);
      return output;
    }

    @Override
    public Ui.Type_stylesheet vx_stylesheet_render(final Ui.Type_stylesheet stylesheetui) {
      Ui.Type_stylesheet output = Ui.f_stylesheet_render(stylesheetui);
      return output;
    }

  }

  public static final Ui.Func_stylesheet_render e_stylesheet_render = new Ui.Class_stylesheet_render();
  public static final Ui.Func_stylesheet_render t_stylesheet_render = new Ui.Class_stylesheet_render();

  public static Ui.Type_stylesheet f_stylesheet_render(final Ui.Type_stylesheet stylesheetui) {
    Ui.Type_stylesheet output = Ui.e_stylesheet;
    return output;
  }

  /**
   * @function ui_addlayout_from_ui
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @return {ui}
   * (func ui-addlayout<-ui)
   */
  public interface Func_ui_addlayout_from_ui extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_addlayout_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_ui_addlayout_from_ui extends Core.Class_base implements Func_ui_addlayout_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui output = new Ui.Class_ui_addlayout_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui output = new Ui.Class_ui_addlayout_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_addlayout_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_addlayout_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_addlayout_from_ui(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_addlayout_from_ui(context, ui);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_addlayout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      Ui.Type_ui output = Ui.f_ui_addlayout_from_ui(context, ui);
      return output;
    }

  }

  public static final Ui.Func_ui_addlayout_from_ui e_ui_addlayout_from_ui = new Ui.Class_ui_addlayout_from_ui();
  public static final Ui.Func_ui_addlayout_from_ui t_ui_addlayout_from_ui = new Ui.Class_ui_addlayout_from_ui();

  public static Ui.Type_ui f_ui_addlayout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uiengine uiengine = Ui.f_uiengine_readstate(
          context
        );
        Core.Type_any output_1 = Ui.f_ui_addlayout_from_ui_uiengine(
          ui,
          uiengine
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_addlayout_from_ui_layoutengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {ui}
   * (func ui-addlayout<-ui-layoutengine)
   */
  public interface Func_ui_addlayout_from_ui_layoutengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_addlayout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine);
  }

  public static class Class_ui_addlayout_from_ui_layoutengine extends Core.Class_base implements Func_ui_addlayout_from_ui_layoutengine {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_layoutengine output = new Ui.Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_layoutengine output = new Ui.Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutengine", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_addlayout_from_ui_layoutengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_addlayout_from_ui_layoutengine;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutengine layoutengine = Core.f_any_from_any(Ui.t_layoutengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_addlayout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
      Ui.Type_ui output = Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

  }

  public static final Ui.Func_ui_addlayout_from_ui_layoutengine e_ui_addlayout_from_ui_layoutengine = new Ui.Class_ui_addlayout_from_ui_layoutengine();
  public static final Ui.Func_ui_addlayout_from_ui_layoutengine t_ui_addlayout_from_ui_layoutengine = new Ui.Class_ui_addlayout_from_ui_layoutengine();

  public static Ui.Type_ui f_ui_addlayout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Ui.Type_layout layoutelse = layoutengine.layoutelse();
        Core.Type_any output_1 = Ui.f_ui_addlayout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_addlayout_from_ui_layoutmap_else
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {ui}
   * (func ui-addlayout<-ui-layoutmap-else)
   */
  public interface Func_ui_addlayout_from_ui_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_addlayout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_ui_addlayout_from_ui_layoutmap_else extends Core.Class_base implements Func_ui_addlayout_from_ui_layoutmap_else {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_layoutmap_else output = new Ui.Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_layoutmap_else output = new Ui.Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_addlayout_from_ui_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_addlayout_from_ui_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutmap layoutmap = Core.f_any_from_any(Ui.t_layoutmap, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_layout layoutelse = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_addlayout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
      Ui.Type_ui output = Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

  }

  public static final Ui.Func_ui_addlayout_from_ui_layoutmap_else e_ui_addlayout_from_ui_layoutmap_else = new Ui.Class_ui_addlayout_from_ui_layoutmap_else();
  public static final Ui.Func_ui_addlayout_from_ui_layoutmap_else t_ui_addlayout_from_ui_layoutmap_else = new Ui.Class_ui_addlayout_from_ui_layoutmap_else();

  public static Ui.Type_ui f_ui_addlayout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = ui.uimap();
        Ui.Type_layout layout1 = Ui.f_layout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        );
        Ui.Type_uimap uimap2 = Ui.f_uimap_addlayout_from_uimap_layoutmap_else(
          uimap,
          layoutmap,
          layoutelse
        );
        Core.Type_any output_1 = Core.f_copy(
          ui,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":layout"),
            layout1,
            Core.vx_new_string(":uimap"),
            uimap2
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_addlayout_from_ui_uiengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {uiengine} uiengine
   * @return {ui}
   * (func ui-addlayout<-ui-uiengine)
   */
  public interface Func_ui_addlayout_from_ui_uiengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_addlayout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine);
  }

  public static class Class_ui_addlayout_from_ui_uiengine extends Core.Class_base implements Func_ui_addlayout_from_ui_uiengine {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_uiengine output = new Ui.Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_addlayout_from_ui_uiengine output = new Ui.Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-uiengine", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_addlayout_from_ui_uiengine;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_addlayout_from_ui_uiengine;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_addlayout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine) {
      Ui.Type_ui output = Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
      return output;
    }

  }

  public static final Ui.Func_ui_addlayout_from_ui_uiengine e_ui_addlayout_from_ui_uiengine = new Ui.Class_ui_addlayout_from_ui_uiengine();
  public static final Ui.Func_ui_addlayout_from_ui_uiengine t_ui_addlayout_from_ui_uiengine = new Ui.Class_ui_addlayout_from_ui_uiengine();

  public static Ui.Type_ui f_ui_addlayout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        Core.Type_any output_1 = Ui.f_ui_addlayout_from_ui_layoutengine(
          ui,
          layoutengine
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_child_from_ui_pos
   * Returns then named child from a ui.
   * @param  {ui} ui
   * @param  {int} pos
   * @return {ui}
   * (func ui-child<-ui-pos)
   */
  public interface Func_ui_child_from_ui_pos extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_child_from_ui_pos(final Ui.Type_ui ui, final Core.Type_int pos);
  }

  public static class Class_ui_child_from_ui_pos extends Core.Class_base implements Func_ui_child_from_ui_pos {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_child_from_ui_pos output = new Ui.Class_ui_child_from_ui_pos();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_child_from_ui_pos output = new Ui.Class_ui_child_from_ui_pos();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-pos", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_child_from_ui_pos;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_child_from_ui_pos;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int pos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_child_from_ui_pos(ui, pos);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_child_from_ui_pos(final Ui.Type_ui ui, final Core.Type_int pos) {
      Ui.Type_ui output = Ui.f_ui_child_from_ui_pos(ui, pos);
      return output;
    }

  }

  public static final Ui.Func_ui_child_from_ui_pos e_ui_child_from_ui_pos = new Ui.Class_ui_child_from_ui_pos();
  public static final Ui.Func_ui_child_from_ui_pos t_ui_child_from_ui_pos = new Ui.Class_ui_child_from_ui_pos();

  public static Ui.Type_ui f_ui_child_from_ui_pos(final Ui.Type_ui ui, final Core.Type_int pos) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap childmap = ui.uimap();
        Core.Type_any output_1 = Collection.f_any_from_map_pos(
          Ui.t_ui,
          childmap,
          pos
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_child_from_ui_uid
   * Returns then named child from a ui.
   * @param  {ui} ui
   * @param  {string} uid
   * @return {ui}
   * (func ui-child<-ui-uid)
   */
  public interface Func_ui_child_from_ui_uid extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid);
  }

  public static class Class_ui_child_from_ui_uid extends Core.Class_base implements Func_ui_child_from_ui_uid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_child_from_ui_uid output = new Ui.Class_ui_child_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_child_from_ui_uid output = new Ui.Class_ui_child_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-uid", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_child_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_child_from_ui_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_child_from_ui_uid(ui, uid);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
      Ui.Type_ui output = Ui.f_ui_child_from_ui_uid(ui, uid);
      return output;
    }

  }

  public static final Ui.Func_ui_child_from_ui_uid e_ui_child_from_ui_uid = new Ui.Class_ui_child_from_ui_uid();
  public static final Ui.Func_ui_child_from_ui_uid t_ui_child_from_ui_uid = new Ui.Class_ui_child_from_ui_uid();

  public static Ui.Type_ui f_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap childmap = ui.uimap();
        Core.Type_any output_1 = Core.f_any_from_map(
          Ui.t_ui,
          childmap,
          uid
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_from_from_event
   * Returns (:from evt) cast as ui
   * @param  {event} evt
   * @return {ui}
   * (func ui-from<-event)
   */
  public interface Func_ui_from_from_event extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_from_from_event(final Core.Type_context context, final Event.Type_event evt);
  }

  public static class Class_ui_from_from_event extends Core.Class_base implements Func_ui_from_from_event {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_from_from_event output = new Ui.Class_ui_from_from_event();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_from_from_event output = new Ui.Class_ui_from_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-from<-event", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_from_from_event;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_from_from_event;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_event inputval = (Event.Type_event)value;
      Core.Type_any outputval = Ui.f_ui_from_from_event(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event evt = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_from_from_event(context, evt);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_from_from_event(final Core.Type_context context, final Event.Type_event evt) {
      Ui.Type_ui output = Ui.f_ui_from_from_event(context, evt);
      return output;
    }

  }

  public static final Ui.Func_ui_from_from_event e_ui_from_from_event = new Ui.Class_ui_from_from_event();
  public static final Ui.Func_ui_from_from_event t_ui_from_from_event = new Ui.Class_ui_from_from_event();

  public static Ui.Type_ui f_ui_from_from_event(final Core.Type_context context, final Event.Type_event evt) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string uid = evt.from();
        Core.Type_any output_1 = Ui.f_ui_readstate_from_uid(
          context,
          uid
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_layout
   * @param  {ui} uiarg
   * @return {ui}
   * (func ui-layout)
   */
  public interface Func_ui_layout extends Core.Func_any_from_any {
    public Ui.Type_ui vx_ui_layout(final Ui.Type_ui uiarg);
  }

  public static class Class_ui_layout extends Core.Class_base implements Func_ui_layout {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_layout output = new Ui.Class_ui_layout();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_layout output = new Ui.Class_ui_layout();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_layout;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_layout;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_layout(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_layout(uiarg);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout(final Ui.Type_ui uiarg) {
      Ui.Type_ui output = Ui.f_ui_layout(uiarg);
      return output;
    }

  }

  public static final Ui.Func_ui_layout e_ui_layout = new Ui.Class_ui_layout();
  public static final Ui.Func_ui_layout t_ui_layout = new Ui.Class_ui_layout();

  public static Ui.Type_ui f_ui_layout(final Ui.Type_ui uiarg) {
    Ui.Type_ui output = Ui.e_ui;
    output = Ui.f_ui_layout_from_ui_orig_parent(
      uiarg,
      Core.f_empty(
        Ui.t_ui
      ),
      Core.f_empty(
        Ui.t_ui
      )
    );
    return output;
  }

  /**
   * @function ui_layout_from_fn_layout_ui_orig_parent
   * Returns a rendered ui
   * @param  {ui-layout<-ui-orig-parent} fn-layout
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout<-fn-layout-ui-orig-parent)
   */
  public interface Func_ui_layout_from_fn_layout_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_fn_layout_ui_orig_parent(final Ui.Func_ui_layout_from_ui_orig_parent fn_layout, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_layout_from_fn_layout_ui_orig_parent extends Core.Class_base implements Func_ui_layout_from_fn_layout_ui_orig_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_layout_from_fn_layout_ui_orig_parent output = new Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_layout_from_fn_layout_ui_orig_parent output = new Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-fn-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_layout_from_fn_layout_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_layout_from_fn_layout_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Func_ui_layout_from_ui_orig_parent fn_layout = Core.f_any_from_any(Ui.t_ui_layout_from_ui_orig_parent, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(3)));
      output = Ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_fn_layout_ui_orig_parent(final Ui.Func_ui_layout_from_ui_orig_parent fn_layout, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      Ui.Type_ui output = Ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent);
      return output;
    }

  }

  public static final Ui.Func_ui_layout_from_fn_layout_ui_orig_parent e_ui_layout_from_fn_layout_ui_orig_parent = new Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
  public static final Ui.Func_ui_layout_from_fn_layout_ui_orig_parent t_ui_layout_from_fn_layout_ui_orig_parent = new Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();

  public static Ui.Type_ui f_ui_layout_from_fn_layout_ui_orig_parent(final Ui.Func_ui_layout_from_ui_orig_parent fn_layout, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.vx_any_from_func(
      Ui.t_ui,
      fn_layout,
      ui,
      orig,
      parent
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_orig_parent
   * Returns a rendered object from a UI Element.
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout<-ui-orig-parent)
   */
  public interface Func_ui_layout_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_layout_from_ui_orig_parent extends Core.Class_base implements Func_ui_layout_from_ui_orig_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_layout_from_ui_orig_parent output = new Ui.Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_layout_from_ui_orig_parent output = new Ui.Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_layout_from_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_layout_from_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      Ui.Type_ui output = Ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

  }

  public static final Ui.Func_ui_layout_from_ui_orig_parent e_ui_layout_from_ui_orig_parent = new Ui.Class_ui_layout_from_ui_orig_parent();
  public static final Ui.Func_ui_layout_from_ui_orig_parent t_ui_layout_from_ui_orig_parent = new Ui.Class_ui_layout_from_ui_orig_parent();

  public static Ui.Type_ui f_ui_layout_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_if_2(
      Ui.t_ui,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_eqeq(
              ui,
              orig
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = orig;
            return output_2;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_let(
              Ui.t_ui,
              Core.t_any_from_func.vx_fn_new(() -> {
                Ui.Type_uimap uimap = ui.uimap();
                Ui.Type_layout layout = ui.layout();
                Ui.Type_ui uiout = Ui.f_ui_from_layout_ui_orig_parent(
                  layout,
                  ui,
                  orig,
                  parent
                );
                Core.Type_any output_4 = uiout;
                return output_4;
              })
            );
            return output_3;
          })
        )
      )
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_parent_selected
   * Return a ui after changing selected item and rendering it.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {int} selected
   * @return {ui}
   * (func ui-layout<-ui-parent-selected)
   */
  public interface Func_ui_layout_from_ui_parent_selected extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_parent_selected(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int selected);
  }

  public static class Class_ui_layout_from_ui_parent_selected extends Core.Class_base implements Func_ui_layout_from_ui_parent_selected {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_layout_from_ui_parent_selected output = new Ui.Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_layout_from_ui_parent_selected output = new Ui.Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-selected", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_layout_from_ui_parent_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_layout_from_ui_parent_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int selected = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_parent_selected(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int selected) {
      Ui.Type_ui output = Ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected);
      return output;
    }

  }

  public static final Ui.Func_ui_layout_from_ui_parent_selected e_ui_layout_from_ui_parent_selected = new Ui.Class_ui_layout_from_ui_parent_selected();
  public static final Ui.Func_ui_layout_from_ui_parent_selected t_ui_layout_from_ui_parent_selected = new Ui.Class_ui_layout_from_ui_parent_selected();

  public static Ui.Type_ui f_ui_layout_from_ui_parent_selected(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int selected) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_ui uichg1 = Ui.f_ui_from_ui_selected(
          ui,
          selected
        );
        Core.Type_boolean iswrite = Ui.f_boolean_write_from_ui_parent(
          uichg1,
          parent
        );
        Core.Type_any output_1 = Ui.f_ui_layout_from_ui_orig_parent(
          uichg1,
          ui,
          parent
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_parent_visible
   * Return a ui after changing visible item and rendering it.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {int} visible
   * @return {ui}
   * (func ui-layout<-ui-parent-visible)
   */
  public interface Func_ui_layout_from_ui_parent_visible extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_parent_visible(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int visible);
  }

  public static class Class_ui_layout_from_ui_parent_visible extends Core.Class_base implements Func_ui_layout_from_ui_parent_visible {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_layout_from_ui_parent_visible output = new Ui.Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_layout_from_ui_parent_visible output = new Ui.Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-visible", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_layout_from_ui_parent_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_layout_from_ui_parent_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int visible = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_parent_visible(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int visible) {
      Ui.Type_ui output = Ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible);
      return output;
    }

  }

  public static final Ui.Func_ui_layout_from_ui_parent_visible e_ui_layout_from_ui_parent_visible = new Ui.Class_ui_layout_from_ui_parent_visible();
  public static final Ui.Func_ui_layout_from_ui_parent_visible t_ui_layout_from_ui_parent_visible = new Ui.Class_ui_layout_from_ui_parent_visible();

  public static Ui.Type_ui f_ui_layout_from_ui_parent_visible(final Ui.Type_ui ui, final Ui.Type_ui parent, final Core.Type_int visible) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_ui uichg = Ui.f_ui_write_from_ui_visible(
          ui,
          visible
        );
        Core.Type_any output_1 = Ui.f_ui_layout_from_ui_orig_parent(
          uichg,
          ui,
          parent
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_readstate_uiapp
   * Returns the top level uiapp from state
   * @return {ui}
   * (func ui-readstate-uiapp)
   */
  public interface Func_ui_readstate_uiapp extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_readstate_uiapp(final Core.Type_context context);
  }

  public static class Class_ui_readstate_uiapp extends Core.Class_base implements Func_ui_readstate_uiapp {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_readstate_uiapp output = new Ui.Class_ui_readstate_uiapp();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_readstate_uiapp output = new Ui.Class_ui_readstate_uiapp();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate-uiapp", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_readstate_uiapp;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_readstate_uiapp;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_readstate_uiapp(context);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_readstate_uiapp(final Core.Type_context context) {
      Ui.Type_ui output = Ui.f_ui_readstate_uiapp(context);
      return output;
    }

  }

  public static final Ui.Func_ui_readstate_uiapp e_ui_readstate_uiapp = new Ui.Class_ui_readstate_uiapp();
  public static final Ui.Func_ui_readstate_uiapp t_ui_readstate_uiapp = new Ui.Class_ui_readstate_uiapp();

  public static Ui.Type_ui f_ui_readstate_uiapp(final Core.Type_context context) {
    Ui.Type_ui output = Ui.e_ui;
    output = State.f_any_readstate_from_name(
      Ui.t_ui,
      context,
      Core.vx_new_string(":uiapp")
    );
    return output;
  }

  /**
   * @function ui_readstate_from_uid
   * Returns the named ui from state
   * @param  {string} uid
   * @return {ui}
   * (func ui-readstate<-uid)
   */
  public interface Func_ui_readstate_from_uid extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid);
  }

  public static class Class_ui_readstate_from_uid extends Core.Class_base implements Func_ui_readstate_from_uid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_readstate_from_uid output = new Ui.Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_readstate_from_uid output = new Ui.Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_readstate_from_uid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_readstate_from_uid;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Ui.f_ui_readstate_from_uid(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_readstate_from_uid(context, uid);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid) {
      Ui.Type_ui output = Ui.f_ui_readstate_from_uid(context, uid);
      return output;
    }

  }

  public static final Ui.Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Ui.Class_ui_readstate_from_uid();
  public static final Ui.Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Ui.Class_ui_readstate_from_uid();

  public static Ui.Type_ui f_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_ui uiapp = Ui.f_ui_readstate_uiapp(
          context
        );
        Core.Type_any output_1 = Ui.f_ui_from_ui_find(
          uiapp,
          uid
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_selected_from_ui
   * Returns the first child of ui with selected=true
   * @param  {ui} ui
   * @return {ui}
   * (func ui-selected<-ui)
   */
  public interface Func_ui_selected_from_ui extends Core.Func_any_from_any {
    public Ui.Type_ui vx_ui_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_ui_selected_from_ui extends Core.Class_base implements Func_ui_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_selected_from_ui output = new Ui.Class_ui_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_selected_from_ui output = new Ui.Class_ui_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_selected_from_ui(ui);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_selected_from_ui(final Ui.Type_ui ui) {
      Ui.Type_ui output = Ui.f_ui_selected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_ui_selected_from_ui e_ui_selected_from_ui = new Ui.Class_ui_selected_from_ui();
  public static final Ui.Func_ui_selected_from_ui t_ui_selected_from_ui = new Ui.Class_ui_selected_from_ui();

  public static Ui.Type_ui f_ui_selected_from_ui(final Ui.Type_ui ui) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uilist uilist = Ui.f_uilist_selected_from_ui(
          ui
        );
        Core.Type_any output_1 = Core.f_first_from_list(
          Ui.t_ui,
          uilist
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_visible_from_ui
   * Returns the first child of ui with hidden=false
   * @param  {ui} ui
   * @return {ui}
   * (func ui-visible<-ui)
   */
  public interface Func_ui_visible_from_ui extends Core.Func_any_from_any {
    public Ui.Type_ui vx_ui_visible_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_ui_visible_from_ui extends Core.Class_base implements Func_ui_visible_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_visible_from_ui output = new Ui.Class_ui_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_visible_from_ui output = new Ui.Class_ui_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-visible<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_visible_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_visible_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_visible_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_visible_from_ui(ui);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_visible_from_ui(final Ui.Type_ui ui) {
      Ui.Type_ui output = Ui.f_ui_visible_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_ui_visible_from_ui e_ui_visible_from_ui = new Ui.Class_ui_visible_from_ui();
  public static final Ui.Func_ui_visible_from_ui t_ui_visible_from_ui = new Ui.Class_ui_visible_from_ui();

  public static Ui.Type_ui f_ui_visible_from_ui(final Ui.Type_ui ui) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uilist uilist = Ui.f_uilist_visible_from_ui(
          ui
        );
        Core.Type_any output_1 = Core.f_first_from_list(
          Ui.t_ui,
          uilist
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_write_from_ui_child
   * Returns the given ui with the child added to uimap
   * @param  {ui} ui
   * @param  {ui} child
   * @return {ui}
   * (func ui-write<-ui-child)
   */
  public interface Func_ui_write_from_ui_child extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_write_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child);
  }

  public static class Class_ui_write_from_ui_child extends Core.Class_base implements Func_ui_write_from_ui_child {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_write_from_ui_child output = new Ui.Class_ui_write_from_ui_child();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_write_from_ui_child output = new Ui.Class_ui_write_from_ui_child();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-child", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_write_from_ui_child;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_write_from_ui_child;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui child = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_write_from_ui_child(ui, child);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_write_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child) {
      Ui.Type_ui output = Ui.f_ui_write_from_ui_child(ui, child);
      return output;
    }

  }

  public static final Ui.Func_ui_write_from_ui_child e_ui_write_from_ui_child = new Ui.Class_ui_write_from_ui_child();
  public static final Ui.Func_ui_write_from_ui_child t_ui_write_from_ui_child = new Ui.Class_ui_write_from_ui_child();

  public static Ui.Type_ui f_ui_write_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string childid = child.uid();
        Ui.Type_uimap uimap = ui.uimap();
        Core.Type_boolean write = Core.f_boolean_write_from_map_name_value(
          uimap,
          childid,
          child
        );
        Core.Type_any output_1 = ui;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_write_from_ui_childmap
   * Returns the given ui with the members of childmap added to uimap
   * @param  {ui} ui
   * @param  {uimap} childmap
   * @return {ui}
   * (func ui-write<-ui-childmap)
   */
  public interface Func_ui_write_from_ui_childmap extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_write_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap);
  }

  public static class Class_ui_write_from_ui_childmap extends Core.Class_base implements Func_ui_write_from_ui_childmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_write_from_ui_childmap output = new Ui.Class_ui_write_from_ui_childmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_write_from_ui_childmap output = new Ui.Class_ui_write_from_ui_childmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-childmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_write_from_ui_childmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_write_from_ui_childmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uimap childmap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_write_from_ui_childmap(ui, childmap);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_write_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap) {
      Ui.Type_ui output = Ui.f_ui_write_from_ui_childmap(ui, childmap);
      return output;
    }

  }

  public static final Ui.Func_ui_write_from_ui_childmap e_ui_write_from_ui_childmap = new Ui.Class_ui_write_from_ui_childmap();
  public static final Ui.Func_ui_write_from_ui_childmap t_ui_write_from_ui_childmap = new Ui.Class_ui_write_from_ui_childmap();

  public static Ui.Type_ui f_ui_write_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap workmap = Core.f_map_from_map_1(
          Ui.t_uimap,
          childmap,
          Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Ui.Type_ui value = Core.f_any_from_any(Ui.t_ui, value_any);
            Core.Type_any output_2 = Ui.f_ui_write_from_ui_child(
              ui,
              value
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = ui;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_write_from_ui_visible
   * Return a ui after changing hidden to all but one child.
   * @param  {ui} ui
   * @param  {int} visible
   * @return {ui}
   * (func ui-write<-ui-visible)
   */
  public interface Func_ui_write_from_ui_visible extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_write_from_ui_visible(final Ui.Type_ui ui, final Core.Type_int visible);
  }

  public static class Class_ui_write_from_ui_visible extends Core.Class_base implements Func_ui_write_from_ui_visible {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_write_from_ui_visible output = new Ui.Class_ui_write_from_ui_visible();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_write_from_ui_visible output = new Ui.Class_ui_write_from_ui_visible();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-visible", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_write_from_ui_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_write_from_ui_visible;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int visible = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_write_from_ui_visible(ui, visible);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_write_from_ui_visible(final Ui.Type_ui ui, final Core.Type_int visible) {
      Ui.Type_ui output = Ui.f_ui_write_from_ui_visible(ui, visible);
      return output;
    }

  }

  public static final Ui.Func_ui_write_from_ui_visible e_ui_write_from_ui_visible = new Ui.Class_ui_write_from_ui_visible();
  public static final Ui.Func_ui_write_from_ui_visible t_ui_write_from_ui_visible = new Ui.Class_ui_write_from_ui_visible();

  public static Ui.Type_ui f_ui_write_from_ui_visible(final Ui.Type_ui ui, final Core.Type_int visible) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_if_2(
      Ui.t_ui,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_lt(
              visible,
              Core.vx_new_int(1)
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = ui;
            return output_2;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_let(
              Ui.t_ui,
              Core.t_any_from_func.vx_fn_new(() -> {
                Ui.Type_uimap uimap = ui.uimap();
                Ui.Type_uilist uilist1 = Ui.f_uilist_from_uimap(
                  uimap
                );
                Ui.Type_uilist uilist2 = Core.f_list_from_list_intany(
                  Ui.t_uilist,
                  uilist1,
                  Core.t_any_from_int_any.vx_fn_new((posval_any, uival_any) -> {
                    Core.Type_int posval = Core.f_any_from_any(Core.t_int, posval_any);
                    Ui.Type_ui uival = Core.f_any_from_any(Ui.t_ui, uival_any);
                    Core.Type_any output_5 = Core.f_if_2(
                      Ui.t_ui,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_6 = Core.f_eq(
                              posval,
                              visible
                            );
                            return output_6;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_7 = Ui.f_ui_write_from_ui_child(
                              ui,
                              Core.f_copy(
                                uival,
                                Core.vx_new(
                                  Core.t_anylist,
                                  Core.vx_new_string(":hidden"),
                                  Core.vx_new_boolean(false)
                                )
                              )
                            );
                            return output_7;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_8 = Ui.f_ui_write_from_ui_child(
                              ui,
                              Core.f_copy(
                                uival,
                                Core.vx_new(
                                  Core.t_anylist,
                                  Core.vx_new_string(":hidden"),
                                  Core.vx_new_boolean(true)
                                )
                              )
                            );
                            return output_8;
                          })
                        )
                      )
                    );
                    return output_5;
                  })
                );
                Core.Type_any output_4 = ui;
                return output_4;
              })
            );
            return output_3;
          })
        )
      )
    );
    return output;
  }

  /**
   * @function ui_from_layout_ui_orig_parent
   * @param  {layout} layout
   * @param  {ui} uiarg
   * @param  {ui} uiorig
   * @param  {ui} parent
   * @return {ui}
   * (func ui<-layout-ui-orig-parent)
   */
  public interface Func_ui_from_layout_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_from_layout_ui_orig_parent(final Ui.Type_layout layout, final Ui.Type_ui uiarg, final Ui.Type_ui uiorig, final Ui.Type_ui parent);
  }

  public static class Class_ui_from_layout_ui_orig_parent extends Core.Class_base implements Func_ui_from_layout_ui_orig_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_from_layout_ui_orig_parent output = new Ui.Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_from_layout_ui_orig_parent output = new Ui.Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_from_layout_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_from_layout_ui_orig_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_layout layout = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui uiorig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(3)));
      output = Ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_from_layout_ui_orig_parent(final Ui.Type_layout layout, final Ui.Type_ui uiarg, final Ui.Type_ui uiorig, final Ui.Type_ui parent) {
      Ui.Type_ui output = Ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
      return output;
    }

  }

  public static final Ui.Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent = new Ui.Class_ui_from_layout_ui_orig_parent();
  public static final Ui.Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent = new Ui.Class_ui_from_layout_ui_orig_parent();

  public static Ui.Type_ui f_ui_from_layout_ui_orig_parent(final Ui.Type_layout layout, final Ui.Type_ui uiarg, final Ui.Type_ui uiorig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string name = layout.name();
        Ui.Func_ui_layout_from_ui_orig_parent fn_layout = layout.fn_layout();
        Ui.Type_ui uichg = Core.vx_any_from_func(
          Ui.t_ui,
          fn_layout,
          uiarg,
          uiorig,
          parent
        );
        Core.Type_any output_1 = uichg;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_from_ui_find
   * Returns a ui given a ui and a find uid.
   * @param  {ui} uiarg
   * @param  {string} find
   * @return {ui}
   * (func ui<-ui-find)
   */
  public interface Func_ui_from_ui_find extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_from_ui_find(final Ui.Type_ui uiarg, final Core.Type_string find);
  }

  public static class Class_ui_from_ui_find extends Core.Class_base implements Func_ui_from_ui_find {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_from_ui_find output = new Ui.Class_ui_from_ui_find();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_from_ui_find output = new Ui.Class_ui_from_ui_find();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-find", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_from_ui_find;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_from_ui_find;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_from_ui_find(uiarg, find);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_from_ui_find(final Ui.Type_ui uiarg, final Core.Type_string find) {
      Ui.Type_ui output = Ui.f_ui_from_ui_find(uiarg, find);
      return output;
    }

  }

  public static final Ui.Func_ui_from_ui_find e_ui_from_ui_find = new Ui.Class_ui_from_ui_find();
  public static final Ui.Func_ui_from_ui_find t_ui_from_ui_find = new Ui.Class_ui_from_ui_find();

  public static Ui.Type_ui f_ui_from_ui_find(final Ui.Type_ui uiarg, final Core.Type_string find) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string uid = uiarg.uid();
        Core.Type_any output_1 = Core.f_if_2(
          Ui.t_ui,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  uid,
                  Core.vx_new_string("")
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_empty(
                  Ui.t_ui
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_eq(
                  uid,
                  find
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = uiarg;
                return output_5;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Type.f_boolean_from_string_starts(
                  find,
                  Core.f_new(
                    Core.t_string,
                    Core.vx_new(
                      Core.t_anylist,
                      uid,
                      Core.vx_new_string("/")
                    )
                  )
                );
                return output_6;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Core.f_let(
                  Ui.t_ui,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Core.Type_int afterpos = Core.f_plus(
                      Core.f_length(
                        uid
                      ),
                      Core.vx_new_int(2)
                    );
                    Core.Type_string after = Type.f_string_from_string_start(
                      find,
                      afterpos
                    );
                    Core.Type_int pos = Type.f_int_from_string_find(
                      after,
                      Core.vx_new_string("/")
                    );
                    Core.Type_string subpart = Core.f_if_2(
                      Core.t_string,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_12 = Core.f_gt(
                              pos,
                              Core.vx_new_int(0)
                            );
                            return output_12;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_13 = Type.f_string_from_string_end(
                              after,
                              Core.f_minus(
                                pos,
                                Core.vx_new_int(1)
                              )
                            );
                            return output_13;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_14 = after;
                            return output_14;
                          })
                        )
                      )
                    );
                    Core.Type_string subfind = Core.f_if_2(
                      Core.t_string,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_15 = Core.f_notempty(
                              subpart
                            );
                            return output_15;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_16 = Core.f_new(
                              Core.t_string,
                              Core.vx_new(
                                Core.t_anylist,
                                uid,
                                Core.vx_new_string("/"),
                                subpart
                              )
                            );
                            return output_16;
                          })
                        )
                      )
                    );
                    Core.Type_any output_8 = Core.f_if_2(
                      Ui.t_ui,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_9 = Core.f_notempty(
                              subfind
                            );
                            return output_9;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_10 = Core.f_let(
                              Ui.t_ui,
                              Core.t_any_from_func.vx_fn_new(() -> {
                                Ui.Type_uimap uimap = uiarg.uimap();
                                Ui.Type_ui subui = Core.f_any_from_map(
                                  Ui.t_ui,
                                  uimap,
                                  subfind
                                );
                                Core.Type_any output_11 = Ui.f_ui_from_ui_find(
                                  subui,
                                  find
                                );
                                return output_11;
                              })
                            );
                            return output_10;
                          })
                        )
                      )
                    );
                    return output_8;
                  })
                );
                return output_7;
              })
            )
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_from_ui_selected
   * Return a ui after changing selected only one child.
   * @param  {ui} ui
   * @param  {int} selected
   * @return {ui}
   * (func ui<-ui-selected)
   */
  public interface Func_ui_from_ui_selected extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected);
  }

  public static class Class_ui_from_ui_selected extends Core.Class_base implements Func_ui_from_ui_selected {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_ui_from_ui_selected output = new Ui.Class_ui_from_ui_selected();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_ui_from_ui_selected output = new Ui.Class_ui_from_ui_selected();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-selected", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_ui_from_ui_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_ui_from_ui_selected;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int selected = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_from_ui_selected(ui, selected);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected) {
      Ui.Type_ui output = Ui.f_ui_from_ui_selected(ui, selected);
      return output;
    }

  }

  public static final Ui.Func_ui_from_ui_selected e_ui_from_ui_selected = new Ui.Class_ui_from_ui_selected();
  public static final Ui.Func_ui_from_ui_selected t_ui_from_ui_selected = new Ui.Class_ui_from_ui_selected();

  public static Ui.Type_ui f_ui_from_ui_selected(final Ui.Type_ui ui, final Core.Type_int selected) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_if_2(
      Ui.t_ui,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_lt(
              selected,
              Core.vx_new_int(1)
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = ui;
            return output_2;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_let(
              Ui.t_ui,
              Core.t_any_from_func.vx_fn_new(() -> {
                Ui.Type_uimap uimap = ui.uimap();
                Ui.Type_uilist uilist1 = Ui.f_uilist_from_uimap(
                  uimap
                );
                Ui.Type_uilist uilist2 = Core.f_list_from_list_intany(
                  Ui.t_uilist,
                  uilist1,
                  Core.t_any_from_int_any.vx_fn_new((posval_any, uival_any) -> {
                    Core.Type_int posval = Core.f_any_from_any(Core.t_int, posval_any);
                    Ui.Type_ui uival = Core.f_any_from_any(Ui.t_ui, uival_any);
                    Core.Type_any output_5 = Core.f_if_2(
                      Ui.t_ui,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_6 = Core.f_eq(
                              posval,
                              selected
                            );
                            return output_6;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_7 = Core.f_copy(
                              uival,
                              Core.vx_new(
                                Core.t_anylist,
                                Core.vx_new_string(":selected"),
                                Core.vx_new_boolean(true)
                              )
                            );
                            return output_7;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_8 = Core.f_copy(
                              uival,
                              Core.vx_new(
                                Core.t_anylist,
                                Core.vx_new_string(":selected"),
                                Core.vx_new_boolean(false)
                              )
                            );
                            return output_8;
                          })
                        )
                      )
                    );
                    return output_5;
                  })
                );
                Ui.Type_uimap childmap = Ui.f_uimap_from_uilist(
                  uilist2
                );
                Core.Type_any output_4 = Core.f_copy(
                  ui,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":uimap"),
                    childmap
                  )
                );
                return output_4;
              })
            );
            return output_3;
          })
        )
      )
    );
    return output;
  }

  /**
   * @function uid_selected_from_ui
   * Returns the uid of the first ui with selected=true
   * @param  {ui} ui
   * @return {string}
   * (func uid-selected<-ui)
   */
  public interface Func_uid_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_string vx_uid_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_uid_selected_from_ui extends Core.Class_base implements Func_uid_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uid_selected_from_ui output = new Ui.Class_uid_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uid_selected_from_ui output = new Ui.Class_uid_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uid-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uid_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uid_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_uid_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uid_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_string vx_uid_selected_from_ui(final Ui.Type_ui ui) {
      Core.Type_string output = Ui.f_uid_selected_from_ui(ui);
      return output;
    }

  }

  public static final Ui.Func_uid_selected_from_ui e_uid_selected_from_ui = new Ui.Class_uid_selected_from_ui();
  public static final Ui.Func_uid_selected_from_ui t_uid_selected_from_ui = new Ui.Class_uid_selected_from_ui();

  public static Core.Type_string f_uid_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_stringlist uidlist = Ui.f_stringlist_selected_from_ui(
          ui
        );
        Core.Type_any output_1 = Core.f_first_from_list(
          Core.t_string,
          uidlist
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uiengine_readstate
   * Returns the current uiengine from state
   * @return {uiengine}
   * (func uiengine-readstate)
   */
  public interface Func_uiengine_readstate extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uiengine vx_uiengine_readstate(final Core.Type_context context);
  }

  public static class Class_uiengine_readstate extends Core.Class_base implements Func_uiengine_readstate {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uiengine_readstate output = new Ui.Class_uiengine_readstate();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uiengine_readstate output = new Ui.Class_uiengine_readstate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-readstate", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uiengine_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uiengine_readstate;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uiengine_readstate(context);
      return output;
    }

    @Override
    public Ui.Type_uiengine vx_uiengine_readstate(final Core.Type_context context) {
      Ui.Type_uiengine output = Ui.f_uiengine_readstate(context);
      return output;
    }

  }

  public static final Ui.Func_uiengine_readstate e_uiengine_readstate = new Ui.Class_uiengine_readstate();
  public static final Ui.Func_uiengine_readstate t_uiengine_readstate = new Ui.Class_uiengine_readstate();

  public static Ui.Type_uiengine f_uiengine_readstate(final Core.Type_context context) {
    Ui.Type_uiengine output = Ui.e_uiengine;
    output = State.f_any_readstate_from_name(
      Ui.t_uiengine,
      context,
      Core.vx_new_string(":uiengine")
    );
    return output;
  }

  /**
   * @function uiengine_render
   * Returns a fully rendered ui for a given engine.
   * @param  {uiengine} uiengine
   * @return {uiengine}
   * (func uiengine-render)
   */
  public interface Func_uiengine_render extends Core.Func_any_from_any_context {
    public Ui.Type_uiengine vx_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine);
  }

  public static class Class_uiengine_render extends Core.Class_base implements Func_uiengine_render {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uiengine_render output = new Ui.Class_uiengine_render();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uiengine_render output = new Ui.Class_uiengine_render();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-render", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uiengine_render;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uiengine_render;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uiengine inputval = (Ui.Type_uiengine)value;
      Core.Type_any outputval = Ui.f_uiengine_render(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uiengine_render(context, uiengine);
      return output;
    }

    @Override
    public Ui.Type_uiengine vx_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
      Ui.Type_uiengine output = Ui.f_uiengine_render(context, uiengine);
      return output;
    }

  }

  public static final Ui.Func_uiengine_render e_uiengine_render = new Ui.Class_uiengine_render();
  public static final Ui.Func_uiengine_render t_uiengine_render = new Ui.Class_uiengine_render();

  public static Ui.Type_uiengine f_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
    Ui.Type_uiengine output = Ui.e_uiengine;
    output = Core.f_let(
      Ui.t_uiengine,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_stylesheet stylesheet = uiengine.stylesheet();
        Ui.Type_ui ui = uiengine.ui();
        Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        Core.Type_boolean issetstate = Ui.f_boolean_writestate_from_uiengine(
          context,
          uiengine
        );
        Ui.Func_stylesheet_render stylesheetrender = layoutengine.stylesheetrender();
        Ui.Type_stylesheet stylesheetrend = Core.vx_any_from_func(
          Ui.t_stylesheet,
          stylesheetrender,
          stylesheet
        );
        Ui.Type_ui uiaddlayout = Ui.f_ui_addlayout_from_ui_layoutengine(
          ui,
          layoutengine
        );
        Core.Type_boolean isuiwrite = Ui.f_boolean_writestate_from_uiapp(
          context,
          uiaddlayout
        );
        Ui.Type_ui uirendered = Ui.f_ui_layout(
          uiaddlayout
        );
        Core.Type_any output_1 = Core.f_copy(
          uiengine,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":ui"),
            uirendered
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uilist_selected_from_ui
   * Return a uilist of the ui with selected=true
   * @param  {ui} uiarg
   * @return {uilist}
   * (func uilist-selected<-ui)
   */
  public interface Func_uilist_selected_from_ui extends Core.Func_any_from_any {
    public Ui.Type_uilist vx_uilist_selected_from_ui(final Ui.Type_ui uiarg);
  }

  public static class Class_uilist_selected_from_ui extends Core.Class_base implements Func_uilist_selected_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uilist_selected_from_ui output = new Ui.Class_uilist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uilist_selected_from_ui output = new Ui.Class_uilist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uilist_selected_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uilist_selected_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_uilist_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uilist_selected_from_ui(uiarg);
      return output;
    }

    @Override
    public Ui.Type_uilist vx_uilist_selected_from_ui(final Ui.Type_ui uiarg) {
      Ui.Type_uilist output = Ui.f_uilist_selected_from_ui(uiarg);
      return output;
    }

  }

  public static final Ui.Func_uilist_selected_from_ui e_uilist_selected_from_ui = new Ui.Class_uilist_selected_from_ui();
  public static final Ui.Func_uilist_selected_from_ui t_uilist_selected_from_ui = new Ui.Class_uilist_selected_from_ui();

  public static Ui.Type_uilist f_uilist_selected_from_ui(final Ui.Type_ui uiarg) {
    Ui.Type_uilist output = Ui.e_uilist;
    output = Core.f_let(
      Ui.t_uilist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = uiarg.uimap();
        Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(
          uimap
        );
        Core.Type_any output_1 = Collection.f_list_from_list_filter(
          Ui.t_uilist,
          uilist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
            Core.Type_any output_2 = Core.f_if(
              Ui.t_ui,
              item.selected(),
              item
            );
            return output_2;
          })
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uilist_visible_from_ui
   * Return a uilist of the ui with hidden=false
   * @param  {ui} uiarg
   * @return {uilist}
   * (func uilist-visible<-ui)
   */
  public interface Func_uilist_visible_from_ui extends Core.Func_any_from_any {
    public Ui.Type_uilist vx_uilist_visible_from_ui(final Ui.Type_ui uiarg);
  }

  public static class Class_uilist_visible_from_ui extends Core.Class_base implements Func_uilist_visible_from_ui {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uilist_visible_from_ui output = new Ui.Class_uilist_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uilist_visible_from_ui output = new Ui.Class_uilist_visible_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-visible<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uilist_visible_from_ui;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uilist_visible_from_ui;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_uilist_visible_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uilist_visible_from_ui(uiarg);
      return output;
    }

    @Override
    public Ui.Type_uilist vx_uilist_visible_from_ui(final Ui.Type_ui uiarg) {
      Ui.Type_uilist output = Ui.f_uilist_visible_from_ui(uiarg);
      return output;
    }

  }

  public static final Ui.Func_uilist_visible_from_ui e_uilist_visible_from_ui = new Ui.Class_uilist_visible_from_ui();
  public static final Ui.Func_uilist_visible_from_ui t_uilist_visible_from_ui = new Ui.Class_uilist_visible_from_ui();

  public static Ui.Type_uilist f_uilist_visible_from_ui(final Ui.Type_ui uiarg) {
    Ui.Type_uilist output = Ui.e_uilist;
    output = Core.f_let(
      Ui.t_uilist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Ui.Type_uimap uimap = uiarg.uimap();
        Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(
          uimap
        );
        Core.Type_any output_1 = Collection.f_list_from_list_filter(
          Ui.t_uilist,
          uilist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
            Core.Type_any output_2 = Core.f_if(
              Ui.t_ui,
              Core.f_not(
                item.hidden()
              ),
              item
            );
            return output_2;
          })
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uilist_from_uimap
   * @param  {uimap} uimap
   * @return {uilist}
   * (func uilist<-uimap)
   */
  public interface Func_uilist_from_uimap extends Core.Func_any_from_any {
    public Ui.Type_uilist vx_uilist_from_uimap(final Ui.Type_uimap uimap);
  }

  public static class Class_uilist_from_uimap extends Core.Class_base implements Func_uilist_from_uimap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uilist_from_uimap output = new Ui.Class_uilist_from_uimap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uilist_from_uimap output = new Ui.Class_uilist_from_uimap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uilist_from_uimap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uilist_from_uimap;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uimap inputval = (Ui.Type_uimap)value;
      Core.Type_any outputval = Ui.f_uilist_from_uimap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uilist_from_uimap(uimap);
      return output;
    }

    @Override
    public Ui.Type_uilist vx_uilist_from_uimap(final Ui.Type_uimap uimap) {
      Ui.Type_uilist output = Ui.f_uilist_from_uimap(uimap);
      return output;
    }

  }

  public static final Ui.Func_uilist_from_uimap e_uilist_from_uimap = new Ui.Class_uilist_from_uimap();
  public static final Ui.Func_uilist_from_uimap t_uilist_from_uimap = new Ui.Class_uilist_from_uimap();

  public static Ui.Type_uilist f_uilist_from_uimap(final Ui.Type_uimap uimap) {
    Ui.Type_uilist output = Ui.e_uilist;
    output = Core.f_list_from_map_1(
      Ui.t_uilist,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, item_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
        Core.Type_any output_1 = item;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uimap_addlayout_from_uimap_layoutmap_else
   * Returns a uimap with a layout added to each ui.
   * @param  {uimap} uimap
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {uimap}
   * (func uimap-addlayout<-uimap-layoutmap-else)
   */
  public interface Func_uimap_addlayout_from_uimap_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_addlayout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_uimap_addlayout_from_uimap_layoutmap_else extends Core.Class_base implements Func_uimap_addlayout_from_uimap_layoutmap_else {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uimap_addlayout_from_uimap_layoutmap_else output = new Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uimap_addlayout_from_uimap_layoutmap_else output = new Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-addlayout<-uimap-layoutmap-else", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uimap_addlayout_from_uimap_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uimap_addlayout_from_uimap_layoutmap_else;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutmap layoutmap = Core.f_any_from_any(Ui.t_layoutmap, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_layout layoutelse = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_addlayout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
      Ui.Type_uimap output = Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
      return output;
    }

  }

  public static final Ui.Func_uimap_addlayout_from_uimap_layoutmap_else e_uimap_addlayout_from_uimap_layoutmap_else = new Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
  public static final Ui.Func_uimap_addlayout_from_uimap_layoutmap_else t_uimap_addlayout_from_uimap_layoutmap_else = new Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();

  public static Ui.Type_uimap f_uimap_addlayout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_map_1(
      Ui.t_uimap,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, ui_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, ui_any);
        Core.Type_any output_1 = Ui.f_ui_addlayout_from_ui_layoutmap_else(
          ui,
          layoutmap,
          layoutelse
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uimap_layout_from_uimap_parent
   * Renders a uimap and returns a rendered uimap.
   * @param  {uimap} uimap
   * @param  {ui} parent
   * @return {uimap}
   * (func uimap-layout<-uimap-parent)
   */
  public interface Func_uimap_layout_from_uimap_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_layout_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent);
  }

  public static class Class_uimap_layout_from_uimap_parent extends Core.Class_base implements Func_uimap_layout_from_uimap_parent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uimap_layout_from_uimap_parent output = new Ui.Class_uimap_layout_from_uimap_parent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uimap_layout_from_uimap_parent output = new Ui.Class_uimap_layout_from_uimap_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uimap_layout_from_uimap_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uimap_layout_from_uimap_parent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_uimap_layout_from_uimap_parent(uimap, parent);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_layout_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent) {
      Ui.Type_uimap output = Ui.f_uimap_layout_from_uimap_parent(uimap, parent);
      return output;
    }

  }

  public static final Ui.Func_uimap_layout_from_uimap_parent e_uimap_layout_from_uimap_parent = new Ui.Class_uimap_layout_from_uimap_parent();
  public static final Ui.Func_uimap_layout_from_uimap_parent t_uimap_layout_from_uimap_parent = new Ui.Class_uimap_layout_from_uimap_parent();

  public static Ui.Type_uimap f_uimap_layout_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_map_1(
      Ui.t_uimap,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui value = Core.f_any_from_any(Ui.t_ui, value_any);
        Core.Type_any output_1 = Ui.f_ui_layout_from_ui_orig_parent(
          value,
          Core.f_empty(
            Ui.t_ui
          ),
          parent
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uimap_from_uilist
   * @param  {uilist} uilist
   * @return {uimap}
   * (func uimap<-uilist)
   */
  public interface Func_uimap_from_uilist extends Core.Func_any_from_any {
    public Ui.Type_uimap vx_uimap_from_uilist(final Ui.Type_uilist uilist);
  }

  public static class Class_uimap_from_uilist extends Core.Class_base implements Func_uimap_from_uilist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uimap_from_uilist output = new Ui.Class_uimap_from_uilist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uimap_from_uilist output = new Ui.Class_uimap_from_uilist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uimap_from_uilist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uimap_from_uilist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uilist inputval = (Ui.Type_uilist)value;
      Core.Type_any outputval = Ui.f_uimap_from_uilist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uilist uilist = Core.f_any_from_any(Ui.t_uilist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uimap_from_uilist(uilist);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_from_uilist(final Ui.Type_uilist uilist) {
      Ui.Type_uimap output = Ui.f_uimap_from_uilist(uilist);
      return output;
    }

  }

  public static final Ui.Func_uimap_from_uilist e_uimap_from_uilist = new Ui.Class_uimap_from_uilist();
  public static final Ui.Func_uimap_from_uilist t_uimap_from_uilist = new Ui.Class_uimap_from_uilist();

  public static Ui.Type_uimap f_uimap_from_uilist(final Ui.Type_uilist uilist) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_list(
      Ui.t_uimap,
      uilist,
      Core.t_any_from_any.vx_fn_new((ui_any) -> {
        Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, ui_any);
        Core.Type_any output_1 = ui.uid();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function uimap_from_uimap_data
   * Template for creating uimap dynamically
   * @param  {uimap} uimap
   * @param  {any} data
   * @return {uimap}
   * (func uimap<-uimap-data)
   */
  public interface Func_uimap_from_uimap_data extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data);
  }

  public static class Class_uimap_from_uimap_data extends Core.Class_base implements Func_uimap_from_uimap_data {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Ui.Class_uimap_from_uimap_data output = new Ui.Class_uimap_from_uimap_data();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Ui.Class_uimap_from_uimap_data output = new Ui.Class_uimap_from_uimap_data();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Ui.e_uimap_from_uimap_data;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Ui.t_uimap_from_uimap_data;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any data = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_uimap_from_uimap_data(uimap, data);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data) {
      Ui.Type_uimap output = Ui.f_uimap_from_uimap_data(uimap, data);
      return output;
    }

  }

  public static final Ui.Func_uimap_from_uimap_data e_uimap_from_uimap_data = new Ui.Class_uimap_from_uimap_data();
  public static final Ui.Func_uimap_from_uimap_data t_uimap_from_uimap_data = new Ui.Class_uimap_from_uimap_data();

  public static Ui.Type_uimap f_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data) {
    Ui.Type_uimap output = Ui.e_uimap;
    return output;
  }


  static {
    Const_align_center.const_new(c_align_center);
    Const_align_left.const_new(c_align_left);
    Const_align_right.const_new(c_align_right);
    Const_flip_x.const_new(c_flip_x);
    Const_flip_xy.const_new(c_flip_xy);
    Const_flip_y.const_new(c_flip_y);
    Const_layout_app.const_new(c_layout_app);
    Const_layout_background.const_new(c_layout_background);
    Const_layout_button.const_new(c_layout_button);
    Const_layout_combobox.const_new(c_layout_combobox);
    Const_layout_else.const_new(c_layout_else);
    Const_layout_flow_columns.const_new(c_layout_flow_columns);
    Const_layout_flow_item.const_new(c_layout_flow_item);
    Const_layout_flow_rows.const_new(c_layout_flow_rows);
    Const_layout_image.const_new(c_layout_image);
    Const_layout_label.const_new(c_layout_label);
    Const_layout_main.const_new(c_layout_main);
    Const_layout_maxpanel.const_new(c_layout_maxpanel);
    Const_layout_menubar.const_new(c_layout_menubar);
    Const_layout_menudrawer.const_new(c_layout_menudrawer);
    Const_layout_msgbox.const_new(c_layout_msgbox);
    Const_layout_navbar.const_new(c_layout_navbar);
    Const_layout_navdrawer.const_new(c_layout_navdrawer);
    Const_layout_panel.const_new(c_layout_panel);
    Const_layout_parallax.const_new(c_layout_parallax);
    Const_layout_statusbar.const_new(c_layout_statusbar);
    Const_layout_statusdrawer.const_new(c_layout_statusdrawer);
    Const_layout_text.const_new(c_layout_text);
    Const_layout_textentry.const_new(c_layout_textentry);
    Const_layout_titlebar.const_new(c_layout_titlebar);
    Const_pin_bottom.const_new(c_pin_bottom);
    Const_pin_center.const_new(c_pin_center);
    Const_pin_center_h.const_new(c_pin_center_h);
    Const_pin_center_v.const_new(c_pin_center_v);
    Const_pin_expand.const_new(c_pin_expand);
    Const_pin_left.const_new(c_pin_left);
    Const_pin_right.const_new(c_pin_right);
    Const_pin_top.const_new(c_pin_top);
    Const_point_center.const_new(c_point_center);
    Const_point_lefttop.const_new(c_point_lefttop);
    Const_point_rightbottom.const_new(c_point_rightbottom);
    Const_pointtype_absolute.const_new(c_pointtype_absolute);
    Const_pointtype_percent.const_new(c_pointtype_percent);
    Const_pointtype_relative.const_new(c_pointtype_relative);
    Const_styletype_custom.const_new(c_styletype_custom);
    Const_styletype_shared.const_new(c_styletype_shared);
    Const_styletype_system.const_new(c_styletype_system);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("align", Ui.t_align);
    maptype.put("bounds", Ui.t_bounds);
    maptype.put("cursor", Ui.t_cursor);
    maptype.put("cursor-pointer", Ui.t_cursor_pointer);
    maptype.put("flip", Ui.t_flip);
    maptype.put("font", Ui.t_font);
    maptype.put("fontface", Ui.t_fontface);
    maptype.put("fontfacelist", Ui.t_fontfacelist);
    maptype.put("fontfacemap", Ui.t_fontfacemap);
    maptype.put("fontmap", Ui.t_fontmap);
    maptype.put("fontstyle", Ui.t_fontstyle);
    maptype.put("fontstylemap", Ui.t_fontstylemap);
    maptype.put("image", Ui.t_image);
    maptype.put("layout", Ui.t_layout);
    maptype.put("layoutengine", Ui.t_layoutengine);
    maptype.put("layoutlist", Ui.t_layoutlist);
    maptype.put("layoutmap", Ui.t_layoutmap);
    maptype.put("pin", Ui.t_pin);
    maptype.put("point", Ui.t_point);
    maptype.put("pointtype", Ui.t_pointtype);
    maptype.put("style", Ui.t_style);
    maptype.put("stylelist", Ui.t_stylelist);
    maptype.put("stylemap", Ui.t_stylemap);
    maptype.put("stylesheet", Ui.t_stylesheet);
    maptype.put("styletype", Ui.t_styletype);
    maptype.put("ui", Ui.t_ui);
    maptype.put("uiengine", Ui.t_uiengine);
    maptype.put("uilist", Ui.t_uilist);
    maptype.put("uimap", Ui.t_uimap);
    mapconst.put("align-center", Ui.c_align_center);
    mapconst.put("align-left", Ui.c_align_left);
    mapconst.put("align-right", Ui.c_align_right);
    mapconst.put("flip-x", Ui.c_flip_x);
    mapconst.put("flip-xy", Ui.c_flip_xy);
    mapconst.put("flip-y", Ui.c_flip_y);
    mapconst.put("layout-app", Ui.c_layout_app);
    mapconst.put("layout-background", Ui.c_layout_background);
    mapconst.put("layout-button", Ui.c_layout_button);
    mapconst.put("layout-combobox", Ui.c_layout_combobox);
    mapconst.put("layout-else", Ui.c_layout_else);
    mapconst.put("layout-flow-columns", Ui.c_layout_flow_columns);
    mapconst.put("layout-flow-item", Ui.c_layout_flow_item);
    mapconst.put("layout-flow-rows", Ui.c_layout_flow_rows);
    mapconst.put("layout-image", Ui.c_layout_image);
    mapconst.put("layout-label", Ui.c_layout_label);
    mapconst.put("layout-main", Ui.c_layout_main);
    mapconst.put("layout-maxpanel", Ui.c_layout_maxpanel);
    mapconst.put("layout-menubar", Ui.c_layout_menubar);
    mapconst.put("layout-menudrawer", Ui.c_layout_menudrawer);
    mapconst.put("layout-msgbox", Ui.c_layout_msgbox);
    mapconst.put("layout-navbar", Ui.c_layout_navbar);
    mapconst.put("layout-navdrawer", Ui.c_layout_navdrawer);
    mapconst.put("layout-panel", Ui.c_layout_panel);
    mapconst.put("layout-parallax", Ui.c_layout_parallax);
    mapconst.put("layout-statusbar", Ui.c_layout_statusbar);
    mapconst.put("layout-statusdrawer", Ui.c_layout_statusdrawer);
    mapconst.put("layout-text", Ui.c_layout_text);
    mapconst.put("layout-textentry", Ui.c_layout_textentry);
    mapconst.put("layout-titlebar", Ui.c_layout_titlebar);
    mapconst.put("pin-bottom", Ui.c_pin_bottom);
    mapconst.put("pin-center", Ui.c_pin_center);
    mapconst.put("pin-center-h", Ui.c_pin_center_h);
    mapconst.put("pin-center-v", Ui.c_pin_center_v);
    mapconst.put("pin-expand", Ui.c_pin_expand);
    mapconst.put("pin-left", Ui.c_pin_left);
    mapconst.put("pin-right", Ui.c_pin_right);
    mapconst.put("pin-top", Ui.c_pin_top);
    mapconst.put("point-center", Ui.c_point_center);
    mapconst.put("point-lefttop", Ui.c_point_lefttop);
    mapconst.put("point-rightbottom", Ui.c_point_rightbottom);
    mapconst.put("pointtype-absolute", Ui.c_pointtype_absolute);
    mapconst.put("pointtype-percent", Ui.c_pointtype_percent);
    mapconst.put("pointtype-relative", Ui.c_pointtype_relative);
    mapconst.put("styletype-custom", Ui.c_styletype_custom);
    mapconst.put("styletype-shared", Ui.c_styletype_shared);
    mapconst.put("styletype-system", Ui.c_styletype_system);
    mapfunc.put("boolean-layout<-ui-parent-selected", Ui.t_boolean_layout_from_ui_parent_selected);
    mapfunc.put("boolean-layout<-ui-parent-visible", Ui.t_boolean_layout_from_ui_parent_visible);
    mapfunc.put("boolean-layoutaddchild<-ui-parent", Ui.t_boolean_layoutaddchild_from_ui_parent);
    mapfunc.put("boolean-layoutremove<-ui", Ui.t_boolean_layoutremove_from_ui);
    mapfunc.put("boolean-layoutremove<-ui-keys", Ui.t_boolean_layoutremove_from_ui_keys);
    mapfunc.put("boolean-layoutremove<-ui-parent", Ui.t_boolean_layoutremove_from_ui_parent);
    mapfunc.put("boolean-layoutremove<-ui-start-end", Ui.t_boolean_layoutremove_from_ui_start_end);
    mapfunc.put("boolean-layoutselected<-ui", Ui.t_boolean_layoutselected_from_ui);
    mapfunc.put("boolean-layoutselected<-ui-parent", Ui.t_boolean_layoutselected_from_ui_parent);
    mapfunc.put("boolean-layoutselected<-ui-selected", Ui.t_boolean_layoutselected_from_ui_selected);
    mapfunc.put("boolean-layoutvisible<-ui", Ui.t_boolean_layoutvisible_from_ui);
    mapfunc.put("boolean-print", Ui.t_boolean_print);
    mapfunc.put("boolean-removestate-uiapp", Ui.t_boolean_removestate_uiapp);
    mapfunc.put("boolean-write<-ui-parent", Ui.t_boolean_write_from_ui_parent);
    mapfunc.put("boolean-writeremove<-ui-uid", Ui.t_boolean_writeremove_from_ui_uid);
    mapfunc.put("boolean-writestate<-ui", Ui.t_boolean_writestate_from_ui);
    mapfunc.put("boolean-writestate<-uiapp", Ui.t_boolean_writestate_from_uiapp);
    mapfunc.put("boolean-writestate<-uiengine", Ui.t_boolean_writestate_from_uiengine);
    mapfunc.put("fontfacemap<-fontfacelist", Ui.t_fontfacemap_from_fontfacelist);
    mapfunc.put("int-child<-ui-uid", Ui.t_int_child_from_ui_uid);
    mapfunc.put("int-selected<-ui", Ui.t_int_selected_from_ui);
    mapfunc.put("int-visible<-ui", Ui.t_int_visible_from_ui);
    mapfunc.put("intlist-visible<-ui", Ui.t_intlist_visible_from_ui);
    mapfunc.put("layout<-style", Ui.t_layout_from_style);
    mapfunc.put("layout<-ui", Ui.t_layout_from_ui);
    mapfunc.put("layout<-ui-layoutengine", Ui.t_layout_from_ui_layoutengine);
    mapfunc.put("layout<-ui-layoutmap-else", Ui.t_layout_from_ui_layoutmap_else);
    mapfunc.put("layoutengine-readstate", Ui.t_layoutengine_readstate);
    mapfunc.put("layoutmap<-layoutlist", Ui.t_layoutmap_from_layoutlist);
    mapfunc.put("string-parentuid<-uid", Ui.t_string_parentuid_from_uid);
    mapfunc.put("string-selected<-ui", Ui.t_string_selected_from_ui);
    mapfunc.put("stringlist-selected<-ui", Ui.t_stringlist_selected_from_ui);
    mapfunc.put("stringlist<-ui", Ui.t_stringlist_from_ui);
    mapfunc.put("stylemap<-stylelist", Ui.t_stylemap_from_stylelist);
    mapfunc.put("stylesheet-readstate", Ui.t_stylesheet_readstate);
    mapfunc.put("stylesheet-render", Ui.t_stylesheet_render);
    mapfunc.put("ui-addlayout<-ui", Ui.t_ui_addlayout_from_ui);
    mapfunc.put("ui-addlayout<-ui-layoutengine", Ui.t_ui_addlayout_from_ui_layoutengine);
    mapfunc.put("ui-addlayout<-ui-layoutmap-else", Ui.t_ui_addlayout_from_ui_layoutmap_else);
    mapfunc.put("ui-addlayout<-ui-uiengine", Ui.t_ui_addlayout_from_ui_uiengine);
    mapfunc.put("ui-child<-ui-pos", Ui.t_ui_child_from_ui_pos);
    mapfunc.put("ui-child<-ui-uid", Ui.t_ui_child_from_ui_uid);
    mapfunc.put("ui-from<-event", Ui.t_ui_from_from_event);
    mapfunc.put("ui-layout", Ui.t_ui_layout);
    mapfunc.put("ui-layout<-fn-layout-ui-orig-parent", Ui.t_ui_layout_from_fn_layout_ui_orig_parent);
    mapfunc.put("ui-layout<-ui-orig-parent", Ui.t_ui_layout_from_ui_orig_parent);
    mapfunc.put("ui-layout<-ui-parent-selected", Ui.t_ui_layout_from_ui_parent_selected);
    mapfunc.put("ui-layout<-ui-parent-visible", Ui.t_ui_layout_from_ui_parent_visible);
    mapfunc.put("ui-readstate-uiapp", Ui.t_ui_readstate_uiapp);
    mapfunc.put("ui-readstate<-uid", Ui.t_ui_readstate_from_uid);
    mapfunc.put("ui-selected<-ui", Ui.t_ui_selected_from_ui);
    mapfunc.put("ui-visible<-ui", Ui.t_ui_visible_from_ui);
    mapfunc.put("ui-write<-ui-child", Ui.t_ui_write_from_ui_child);
    mapfunc.put("ui-write<-ui-childmap", Ui.t_ui_write_from_ui_childmap);
    mapfunc.put("ui-write<-ui-visible", Ui.t_ui_write_from_ui_visible);
    mapfunc.put("ui<-layout-ui-orig-parent", Ui.t_ui_from_layout_ui_orig_parent);
    mapfunc.put("ui<-ui-find", Ui.t_ui_from_ui_find);
    mapfunc.put("ui<-ui-selected", Ui.t_ui_from_ui_selected);
    mapfunc.put("uid-selected<-ui", Ui.t_uid_selected_from_ui);
    mapfunc.put("uiengine-readstate", Ui.t_uiengine_readstate);
    mapfunc.put("uiengine-render", Ui.t_uiengine_render);
    mapfunc.put("uilist-selected<-ui", Ui.t_uilist_selected_from_ui);
    mapfunc.put("uilist-visible<-ui", Ui.t_uilist_visible_from_ui);
    mapfunc.put("uilist<-uimap", Ui.t_uilist_from_uimap);
    mapfunc.put("uimap-addlayout<-uimap-layoutmap-else", Ui.t_uimap_addlayout_from_uimap_layoutmap_else);
    mapfunc.put("uimap-layout<-uimap-parent", Ui.t_uimap_layout_from_uimap_parent);
    mapfunc.put("uimap<-uilist", Ui.t_uimap_from_uilist);
    mapfunc.put("uimap<-uimap-data", Ui.t_uimap_from_uimap_data);
    Core.vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc);
  }

}
