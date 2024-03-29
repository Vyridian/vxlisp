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
   * type: bounds
   * Universal Bounds
   * (type bounds)
   */
  public interface Type_bounds extends Core.Type_struct {
    public Ui.Type_bounds vx_new(final Object... vals);
    public Ui.Type_bounds vx_copy(final Object... vals);
    public Ui.Type_bounds vx_empty();
    public Ui.Type_bounds vx_type();
    public Core.Type_int left();
    public Core.Type_int right();
    public Core.Type_int top();
    public Core.Type_int bottom();
  }

  public static class Class_bounds extends Core.Class_base implements Type_bounds {

    protected Core.Type_int vx_p_left;

    @Override
    public Core.Type_int left() {
      return this.vx_p_left == null ? Core.e_int : this.vx_p_left;
    }

    protected Core.Type_int vx_p_right;

    @Override
    public Core.Type_int right() {
      return this.vx_p_right == null ? Core.e_int : this.vx_p_right;
    }

    protected Core.Type_int vx_p_top;

    @Override
    public Core.Type_int top() {
      return this.vx_p_top == null ? Core.e_int : this.vx_p_top;
    }

    protected Core.Type_int vx_p_bottom;

    @Override
    public Core.Type_int bottom() {
      return this.vx_p_bottom == null ? Core.e_int : this.vx_p_bottom;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":left":
        output = this.left();
        break;
      case ":right":
        output = this.right();
        break;
      case ":top":
        output = this.top();
        break;
      case ":bottom":
        output = this.bottom();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":left", this.left());
      output.put(":right", this.right());
      output.put(":top", this.top());
      output.put(":bottom", this.bottom());
      return Core.immutablemap(output);
    }

    @Override
    public Type_bounds vx_new(final Object... vals) {
      return e_bounds.vx_copy(vals);
    }

    @Override
    public Type_bounds vx_copy(final Object... vals) {
      Type_bounds output = this;
      boolean ischanged = false;
      Class_bounds val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_int vx_p_left = val.left();
      Core.Type_int vx_p_right = val.right();
      Core.Type_int vx_p_top = val.top();
      Core.Type_int vx_p_bottom = val.bottom();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":left");
      validkeys.add(":right");
      validkeys.add(":top");
      validkeys.add(":bottom");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":left":
            if (valsub == vx_p_left) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_left = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_left = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("left"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":right":
            if (valsub == vx_p_right) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_right = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_right = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("right"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":top":
            if (valsub == vx_p_top) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_top = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_top = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("top"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":bottom":
            if (valsub == vx_p_bottom) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_bottom = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_bottom = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("bottom"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_bounds work = new Class_bounds();
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
    public Type_bounds vx_empty() {return e_bounds;}
    @Override
    public Type_bounds vx_type() {return t_bounds;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_bounds e_bounds = new Class_bounds();
  public static final Type_bounds t_bounds = new Class_bounds();

  /**
   * type: cursor
   * Univeral Cursor Type
   * (type cursor)
   */
  public interface Type_cursor extends Core.Type_struct {
    public Ui.Type_cursor vx_new(final Object... vals);
    public Ui.Type_cursor vx_copy(final Object... vals);
    public Ui.Type_cursor vx_empty();
    public Ui.Type_cursor vx_type();
  }

  public static class Class_cursor extends Core.Class_base implements Type_cursor {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      return Core.immutablemap(output);
    }

    @Override
    public Type_cursor vx_new(final Object... vals) {
      return e_cursor.vx_copy(vals);
    }

    @Override
    public Type_cursor vx_copy(final Object... vals) {
      Type_cursor output = this;
      boolean ischanged = false;
      Class_cursor val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_cursor work = new Class_cursor();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_cursor vx_empty() {return e_cursor;}
    @Override
    public Type_cursor vx_type() {return t_cursor;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_cursor e_cursor = new Class_cursor();
  public static final Type_cursor t_cursor = new Class_cursor();

  /**
   * type: cursor-pointer
   * (type cursor-pointer)
   */
  public interface Type_cursor_pointer extends Core.Type_any {
    public Ui.Type_cursor_pointer vx_new(final Object... vals);
    public Ui.Type_cursor_pointer vx_copy(final Object... vals);
    public Ui.Type_cursor_pointer vx_empty();
    public Ui.Type_cursor_pointer vx_type();
  }

  public static class Class_cursor_pointer extends Core.Class_base implements Type_cursor_pointer {

    @Override
    public Type_cursor_pointer vx_new(final Object... vals) {
      return e_cursor_pointer.vx_copy(vals);
    }

    @Override
    public Type_cursor_pointer vx_copy(final Object... vals) {
      Type_cursor_pointer output = this;
      boolean ischanged = false;
      Class_cursor_pointer val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_cursor_pointer work = new Class_cursor_pointer();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_cursor_pointer vx_empty() {return e_cursor_pointer;}
    @Override
    public Type_cursor_pointer vx_type() {return t_cursor_pointer;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_cursor_pointer e_cursor_pointer = new Class_cursor_pointer();
  public static final Type_cursor_pointer t_cursor_pointer = new Class_cursor_pointer();

  /**
   * type: font
   * Univeral Font Type
   * (type font)
   */
  public interface Type_font extends Core.Type_struct {
    public Ui.Type_font vx_new(final Object... vals);
    public Ui.Type_font vx_copy(final Object... vals);
    public Ui.Type_font vx_empty();
    public Ui.Type_font vx_type();
    public Core.Type_string name();
    public Ui.Type_fontface fontface();
    public Core.Type_int fontsize();
    public Ui.Type_fontstyle fontstyle();
  }

  public static class Class_font extends Core.Class_base implements Type_font {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Ui.Type_fontface vx_p_fontface;

    @Override
    public Ui.Type_fontface fontface() {
      return this.vx_p_fontface == null ? Ui.e_fontface : this.vx_p_fontface;
    }

    protected Core.Type_int vx_p_fontsize;

    @Override
    public Core.Type_int fontsize() {
      return this.vx_p_fontsize == null ? Core.e_int : this.vx_p_fontsize;
    }

    protected Ui.Type_fontstyle vx_p_fontstyle;

    @Override
    public Ui.Type_fontstyle fontstyle() {
      return this.vx_p_fontstyle == null ? Ui.e_fontstyle : this.vx_p_fontstyle;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":fontface":
        output = this.fontface();
        break;
      case ":fontsize":
        output = this.fontsize();
        break;
      case ":fontstyle":
        output = this.fontstyle();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":fontface", this.fontface());
      output.put(":fontsize", this.fontsize());
      output.put(":fontstyle", this.fontstyle());
      return Core.immutablemap(output);
    }

    @Override
    public Type_font vx_new(final Object... vals) {
      return e_font.vx_copy(vals);
    }

    @Override
    public Type_font vx_copy(final Object... vals) {
      Type_font output = this;
      boolean ischanged = false;
      Class_font val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Ui.Type_fontface vx_p_fontface = val.fontface();
      Core.Type_int vx_p_fontsize = val.fontsize();
      Ui.Type_fontstyle vx_p_fontstyle = val.fontstyle();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":fontface");
      validkeys.add(":fontsize");
      validkeys.add(":fontstyle");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fontface":
            if (valsub == vx_p_fontface) {
            } else if (valsub instanceof Ui.Type_fontface) {
              ischanged = true;
              vx_p_fontface = (Ui.Type_fontface)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fontface"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fontsize":
            if (valsub == vx_p_fontsize) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_fontsize = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_fontsize = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fontsize"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fontstyle":
            if (valsub == vx_p_fontstyle) {
            } else if (valsub instanceof Ui.Type_fontstyle) {
              ischanged = true;
              vx_p_fontstyle = (Ui.Type_fontstyle)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fontstyle"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_font work = new Class_font();
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
    public Type_font vx_empty() {return e_font;}
    @Override
    public Type_font vx_type() {return t_font;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_font e_font = new Class_font();
  public static final Type_font t_font = new Class_font();

  /**
   * type: fontface
   * Univeral Font Face Type
   * (type fontface)
   */
  public interface Type_fontface extends Core.Type_struct {
    public Ui.Type_fontface vx_new(final Object... vals);
    public Ui.Type_fontface vx_copy(final Object... vals);
    public Ui.Type_fontface vx_empty();
    public Ui.Type_fontface vx_type();
    public Core.Type_string name();
    public File.Type_filelist filelist();
  }

  public static class Class_fontface extends Core.Class_base implements Type_fontface {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected File.Type_filelist vx_p_filelist;

    @Override
    public File.Type_filelist filelist() {
      return this.vx_p_filelist == null ? File.e_filelist : this.vx_p_filelist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":filelist":
        output = this.filelist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":filelist", this.filelist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_fontface vx_new(final Object... vals) {
      return e_fontface.vx_copy(vals);
    }

    @Override
    public Type_fontface vx_copy(final Object... vals) {
      Type_fontface output = this;
      boolean ischanged = false;
      Class_fontface val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      File.Type_filelist vx_p_filelist = val.filelist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":filelist");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":filelist":
            if (valsub == vx_p_filelist) {
            } else if (valsub instanceof File.Type_filelist) {
              ischanged = true;
              vx_p_filelist = (File.Type_filelist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("filelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fontface work = new Class_fontface();
        work.vx_p_name = vx_p_name;
        work.vx_p_filelist = vx_p_filelist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontface vx_empty() {return e_fontface;}
    @Override
    public Type_fontface vx_type() {return t_fontface;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_fontface e_fontface = new Class_fontface();
  public static final Type_fontface t_fontface = new Class_fontface();

  /**
   * type: fontfacelist
   * List of fontface
   * (type fontfacelist)
   */
  public interface Type_fontfacelist extends Core.Type_list {
    public Ui.Type_fontfacelist vx_new(final Object... vals);
    public Ui.Type_fontfacelist vx_copy(final Object... vals);
    public Ui.Type_fontfacelist vx_empty();
    public Ui.Type_fontfacelist vx_type();
    public List<Ui.Type_fontface> vx_listfontface();
    public Ui.Type_fontface vx_fontface(final Core.Type_int index);
  }

  public static class Class_fontfacelist extends Core.Class_base implements Type_fontfacelist {

    protected List<Ui.Type_fontface> vx_p_list = Core.immutablelist(new ArrayList<Ui.Type_fontface>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Ui.Type_fontface vx_fontface(final Core.Type_int index) {
      Ui.Type_fontface output = Ui.e_fontface;
      Class_fontfacelist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_fontface> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_fontface> vx_listfontface() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_fontface(index);
    }

    @Override
    public Type_fontfacelist vx_new(final Object... vals) {
      return e_fontfacelist.vx_copy(vals);
    }

    @Override
    public Type_fontfacelist vx_copy(final Object... vals) {
      Type_fontfacelist output = this;
      boolean ischanged = false;
      Class_fontfacelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Ui.Type_fontface> listval = new ArrayList<>(val.vx_listfontface());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Ui.Type_fontface) {
          ischanged = true;
          listval.add((Ui.Type_fontface)valsub);
        } else if (valsub instanceof Ui.Type_fontface) {
          ischanged = true;
          listval.add((Ui.Type_fontface)valsub);
        } else if (valsub instanceof Type_fontfacelist) {
          Type_fontfacelist multi = (Type_fontfacelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfontface());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Ui.Type_fontface) {
              Ui.Type_fontface valitem = (Ui.Type_fontface)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fontfacelist work = new Class_fontfacelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontfacelist vx_empty() {return e_fontfacelist;}
    @Override
    public Type_fontfacelist vx_type() {return t_fontfacelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_fontface), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fontfacelist e_fontfacelist = new Class_fontfacelist();
  public static final Type_fontfacelist t_fontfacelist = new Class_fontfacelist();

  /**
   * type: fontfacemap
   * Map of fontface
   * (type fontfacemap)
   */
  public interface Type_fontfacemap extends Core.Type_map {
    public Ui.Type_fontfacemap vx_new(final Object... vals);
    public Ui.Type_fontfacemap vx_copy(final Object... vals);
    public Ui.Type_fontfacemap vx_empty();
    public Ui.Type_fontfacemap vx_type();
    public Map<String, Ui.Type_fontface> vx_mapfontface();
    public Ui.Type_fontface vx_fontface(final Core.Type_string key);
  }

  public static class Class_fontfacemap extends Core.Class_base implements Type_fontfacemap {

    protected Map<String, Ui.Type_fontface> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_fontface>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_fontface vx_fontface(final Core.Type_string key) {
      Ui.Type_fontface output = Ui.e_fontface;
      Class_fontfacemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_fontface> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_fontface);
      return output;
    }

    @Override
    public Map<String, Ui.Type_fontface> vx_mapfontface() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_fontface(key);
    }

    @Override
    public Type_fontfacemap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_fontfacemap output = new Class_fontfacemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_fontface> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_fontface) {
          Ui.Type_fontface castval = (Ui.Type_fontface)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_fontfacemap vx_new(final Object... vals) {
      return e_fontfacemap.vx_copy(vals);
    }

    @Override
    public Type_fontfacemap vx_copy(final Object... vals) {
      Type_fontfacemap output = this;
      boolean ischanged = false;
      Class_fontfacemap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_fontface> mapval = new LinkedHashMap<>(val.vx_mapfontface());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_fontface valany = null;
          if (valsub instanceof Ui.Type_fontface) {
            valany = (Ui.Type_fontface)valsub;
          } else if (valsub instanceof Ui.Type_fontface) {
            valany = (Ui.Type_fontface)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_fontfacemap work = new Class_fontfacemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontfacemap vx_empty() {return e_fontfacemap;}
    @Override
    public Type_fontfacemap vx_type() {return t_fontfacemap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_fontface), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fontfacemap e_fontfacemap = new Class_fontfacemap();
  public static final Type_fontfacemap t_fontfacemap = new Class_fontfacemap();

  /**
   * type: fontmap
   * Map of font
   * (type fontmap)
   */
  public interface Type_fontmap extends Core.Type_map {
    public Ui.Type_fontmap vx_new(final Object... vals);
    public Ui.Type_fontmap vx_copy(final Object... vals);
    public Ui.Type_fontmap vx_empty();
    public Ui.Type_fontmap vx_type();
    public Map<String, Ui.Type_font> vx_mapfont();
    public Ui.Type_font vx_font(final Core.Type_string key);
  }

  public static class Class_fontmap extends Core.Class_base implements Type_fontmap {

    protected Map<String, Ui.Type_font> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_font>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_font vx_font(final Core.Type_string key) {
      Ui.Type_font output = Ui.e_font;
      Class_fontmap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_font> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_font);
      return output;
    }

    @Override
    public Map<String, Ui.Type_font> vx_mapfont() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_font(key);
    }

    @Override
    public Type_fontmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_fontmap output = new Class_fontmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_font> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_font) {
          Ui.Type_font castval = (Ui.Type_font)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_fontmap vx_new(final Object... vals) {
      return e_fontmap.vx_copy(vals);
    }

    @Override
    public Type_fontmap vx_copy(final Object... vals) {
      Type_fontmap output = this;
      boolean ischanged = false;
      Class_fontmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_font> mapval = new LinkedHashMap<>(val.vx_mapfont());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_font valany = null;
          if (valsub instanceof Ui.Type_font) {
            valany = (Ui.Type_font)valsub;
          } else if (valsub instanceof Ui.Type_font) {
            valany = (Ui.Type_font)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_fontmap work = new Class_fontmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontmap vx_empty() {return e_fontmap;}
    @Override
    public Type_fontmap vx_type() {return t_fontmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_font), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fontmap e_fontmap = new Class_fontmap();
  public static final Type_fontmap t_fontmap = new Class_fontmap();

  /**
   * type: fontstyle
   * Univeral Font Style Type
   * (type fontstyle)
   */
  public interface Type_fontstyle extends Core.Type_struct {
    public Ui.Type_fontstyle vx_new(final Object... vals);
    public Ui.Type_fontstyle vx_copy(final Object... vals);
    public Ui.Type_fontstyle vx_empty();
    public Ui.Type_fontstyle vx_type();
    public Core.Type_string name();
  }

  public static class Class_fontstyle extends Core.Class_base implements Type_fontstyle {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      return Core.immutablemap(output);
    }

    @Override
    public Type_fontstyle vx_new(final Object... vals) {
      return e_fontstyle.vx_copy(vals);
    }

    @Override
    public Type_fontstyle vx_copy(final Object... vals) {
      Type_fontstyle output = this;
      boolean ischanged = false;
      Class_fontstyle val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fontstyle work = new Class_fontstyle();
        work.vx_p_name = vx_p_name;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontstyle vx_empty() {return e_fontstyle;}
    @Override
    public Type_fontstyle vx_type() {return t_fontstyle;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_fontstyle e_fontstyle = new Class_fontstyle();
  public static final Type_fontstyle t_fontstyle = new Class_fontstyle();

  /**
   * type: fontstylemap
   * Map of fontstyle
   * (type fontstylemap)
   */
  public interface Type_fontstylemap extends Core.Type_map {
    public Ui.Type_fontstylemap vx_new(final Object... vals);
    public Ui.Type_fontstylemap vx_copy(final Object... vals);
    public Ui.Type_fontstylemap vx_empty();
    public Ui.Type_fontstylemap vx_type();
    public Map<String, Ui.Type_fontstyle> vx_mapfontstyle();
    public Ui.Type_fontstyle vx_fontstyle(final Core.Type_string key);
  }

  public static class Class_fontstylemap extends Core.Class_base implements Type_fontstylemap {

    protected Map<String, Ui.Type_fontstyle> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_fontstyle>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_fontstyle vx_fontstyle(final Core.Type_string key) {
      Ui.Type_fontstyle output = Ui.e_fontstyle;
      Class_fontstylemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_fontstyle> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_fontstyle);
      return output;
    }

    @Override
    public Map<String, Ui.Type_fontstyle> vx_mapfontstyle() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_fontstyle(key);
    }

    @Override
    public Type_fontstylemap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_fontstylemap output = new Class_fontstylemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_fontstyle> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_fontstyle) {
          Ui.Type_fontstyle castval = (Ui.Type_fontstyle)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_fontstylemap vx_new(final Object... vals) {
      return e_fontstylemap.vx_copy(vals);
    }

    @Override
    public Type_fontstylemap vx_copy(final Object... vals) {
      Type_fontstylemap output = this;
      boolean ischanged = false;
      Class_fontstylemap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_fontstyle> mapval = new LinkedHashMap<>(val.vx_mapfontstyle());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_fontstyle valany = null;
          if (valsub instanceof Ui.Type_fontstyle) {
            valany = (Ui.Type_fontstyle)valsub;
          } else if (valsub instanceof Ui.Type_fontstyle) {
            valany = (Ui.Type_fontstyle)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_fontstylemap work = new Class_fontstylemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fontstylemap vx_empty() {return e_fontstylemap;}
    @Override
    public Type_fontstylemap vx_type() {return t_fontstylemap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstylemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_fontstyle), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fontstylemap e_fontstylemap = new Class_fontstylemap();
  public static final Type_fontstylemap t_fontstylemap = new Class_fontstylemap();

  /**
   * type: layout
   * Universal Layout
   * (type layout)
   */
  public interface Type_layout extends Core.Type_struct {
    public Ui.Type_layout vx_new(final Object... vals);
    public Ui.Type_layout vx_copy(final Object... vals);
    public Ui.Type_layout vx_empty();
    public Ui.Type_layout vx_type();
    public Core.Type_string name();
    public Ui.Func_ui_render_from_ui_orig_parent fn_layout();
  }

  public static class Class_layout extends Core.Class_base implements Type_layout {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Ui.Func_ui_render_from_ui_orig_parent vx_p_fn_layout;

    @Override
    public Ui.Func_ui_render_from_ui_orig_parent fn_layout() {
      return this.vx_p_fn_layout == null ? Ui.e_ui_render_from_ui_orig_parent : this.vx_p_fn_layout;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":fn-layout":
        output = this.fn_layout();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":fn-layout", this.fn_layout());
      return Core.immutablemap(output);
    }

    @Override
    public Type_layout vx_new(final Object... vals) {
      return e_layout.vx_copy(vals);
    }

    @Override
    public Type_layout vx_copy(final Object... vals) {
      Type_layout output = this;
      boolean ischanged = false;
      Class_layout val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Ui.Func_ui_render_from_ui_orig_parent vx_p_fn_layout = val.fn_layout();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":fn-layout");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-layout":
            if (valsub == vx_p_fn_layout) {
            } else if (valsub instanceof Ui.Func_ui_render_from_ui_orig_parent) {
              ischanged = true;
              vx_p_fn_layout = (Ui.Func_ui_render_from_ui_orig_parent)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fn-layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_layout work = new Class_layout();
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
    public Type_layout vx_empty() {return e_layout;}
    @Override
    public Type_layout vx_type() {return t_layout;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_layout e_layout = new Class_layout();
  public static final Type_layout t_layout = new Class_layout();

  /**
   * type: layoutengine
   * Pluggable layoutengine
   * (type layoutengine)
   */
  public interface Type_layoutengine extends Core.Type_struct {
    public Ui.Type_layoutengine vx_new(final Object... vals);
    public Ui.Type_layoutengine vx_copy(final Object... vals);
    public Ui.Type_layoutengine vx_empty();
    public Ui.Type_layoutengine vx_type();
    public Core.Type_string name();
    public Ui.Type_layoutmap layoutmap();
    public Ui.Type_layout layoutelse();
    public Ui.Func_stylesheet_render stylesheetrender();
  }

  public static class Class_layoutengine extends Core.Class_base implements Type_layoutengine {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Ui.Type_layoutmap vx_p_layoutmap;

    @Override
    public Ui.Type_layoutmap layoutmap() {
      return this.vx_p_layoutmap == null ? Ui.e_layoutmap : this.vx_p_layoutmap;
    }

    protected Ui.Type_layout vx_p_layoutelse;

    @Override
    public Ui.Type_layout layoutelse() {
      return this.vx_p_layoutelse == null ? Ui.e_layout : this.vx_p_layoutelse;
    }

    protected Ui.Func_stylesheet_render vx_p_stylesheetrender;

    @Override
    public Ui.Func_stylesheet_render stylesheetrender() {
      return this.vx_p_stylesheetrender == null ? Ui.e_stylesheet_render : this.vx_p_stylesheetrender;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":layoutmap":
        output = this.layoutmap();
        break;
      case ":layoutelse":
        output = this.layoutelse();
        break;
      case ":stylesheetrender":
        output = this.stylesheetrender();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":layoutmap", this.layoutmap());
      output.put(":layoutelse", this.layoutelse());
      output.put(":stylesheetrender", this.stylesheetrender());
      return Core.immutablemap(output);
    }

    @Override
    public Type_layoutengine vx_new(final Object... vals) {
      return e_layoutengine.vx_copy(vals);
    }

    @Override
    public Type_layoutengine vx_copy(final Object... vals) {
      Type_layoutengine output = this;
      boolean ischanged = false;
      Class_layoutengine val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Ui.Type_layoutmap vx_p_layoutmap = val.layoutmap();
      Ui.Type_layout vx_p_layoutelse = val.layoutelse();
      Ui.Func_stylesheet_render vx_p_stylesheetrender = val.stylesheetrender();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":layoutmap");
      validkeys.add(":layoutelse");
      validkeys.add(":stylesheetrender");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":layoutmap":
            if (valsub == vx_p_layoutmap) {
            } else if (valsub instanceof Ui.Type_layoutmap) {
              ischanged = true;
              vx_p_layoutmap = (Ui.Type_layoutmap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("layoutmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":layoutelse":
            if (valsub == vx_p_layoutelse) {
            } else if (valsub instanceof Ui.Type_layout) {
              ischanged = true;
              vx_p_layoutelse = (Ui.Type_layout)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("layoutelse"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":stylesheetrender":
            if (valsub == vx_p_stylesheetrender) {
            } else if (valsub instanceof Ui.Func_stylesheet_render) {
              ischanged = true;
              vx_p_stylesheetrender = (Ui.Func_stylesheet_render)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("stylesheetrender"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_layoutengine work = new Class_layoutengine();
        work.vx_p_name = vx_p_name;
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
    public Type_layoutengine vx_empty() {return e_layoutengine;}
    @Override
    public Type_layoutengine vx_type() {return t_layoutengine;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_layoutengine e_layoutengine = new Class_layoutengine();
  public static final Type_layoutengine t_layoutengine = new Class_layoutengine();

  /**
   * type: layoutlist
   * Map of layout
   * (type layoutlist)
   */
  public interface Type_layoutlist extends Core.Type_list {
    public Ui.Type_layoutlist vx_new(final Object... vals);
    public Ui.Type_layoutlist vx_copy(final Object... vals);
    public Ui.Type_layoutlist vx_empty();
    public Ui.Type_layoutlist vx_type();
    public List<Ui.Type_layout> vx_listlayout();
    public Ui.Type_layout vx_layout(final Core.Type_int index);
  }

  public static class Class_layoutlist extends Core.Class_base implements Type_layoutlist {

    protected List<Ui.Type_layout> vx_p_list = Core.immutablelist(new ArrayList<Ui.Type_layout>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Ui.Type_layout vx_layout(final Core.Type_int index) {
      Ui.Type_layout output = Ui.e_layout;
      Class_layoutlist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_layout> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_layout> vx_listlayout() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_layout(index);
    }

    @Override
    public Type_layoutlist vx_new(final Object... vals) {
      return e_layoutlist.vx_copy(vals);
    }

    @Override
    public Type_layoutlist vx_copy(final Object... vals) {
      Type_layoutlist output = this;
      boolean ischanged = false;
      Class_layoutlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Ui.Type_layout> listval = new ArrayList<>(val.vx_listlayout());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Ui.Type_layout) {
          ischanged = true;
          listval.add((Ui.Type_layout)valsub);
        } else if (valsub instanceof Ui.Type_layout) {
          ischanged = true;
          listval.add((Ui.Type_layout)valsub);
        } else if (valsub instanceof Type_layoutlist) {
          Type_layoutlist multi = (Type_layoutlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listlayout());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Ui.Type_layout) {
              Ui.Type_layout valitem = (Ui.Type_layout)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_layoutlist work = new Class_layoutlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_layoutlist vx_empty() {return e_layoutlist;}
    @Override
    public Type_layoutlist vx_type() {return t_layoutlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_layout), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_layoutlist e_layoutlist = new Class_layoutlist();
  public static final Type_layoutlist t_layoutlist = new Class_layoutlist();

  /**
   * type: layoutmap
   * Map of layout
   * (type layoutmap)
   */
  public interface Type_layoutmap extends Core.Type_map {
    public Ui.Type_layoutmap vx_new(final Object... vals);
    public Ui.Type_layoutmap vx_copy(final Object... vals);
    public Ui.Type_layoutmap vx_empty();
    public Ui.Type_layoutmap vx_type();
    public Map<String, Ui.Type_layout> vx_maplayout();
    public Ui.Type_layout vx_layout(final Core.Type_string key);
  }

  public static class Class_layoutmap extends Core.Class_base implements Type_layoutmap {

    protected Map<String, Ui.Type_layout> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_layout>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_layout vx_layout(final Core.Type_string key) {
      Ui.Type_layout output = Ui.e_layout;
      Class_layoutmap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_layout> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_layout);
      return output;
    }

    @Override
    public Map<String, Ui.Type_layout> vx_maplayout() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_layout(key);
    }

    @Override
    public Type_layoutmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_layoutmap output = new Class_layoutmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_layout> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_layout) {
          Ui.Type_layout castval = (Ui.Type_layout)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_layoutmap vx_new(final Object... vals) {
      return e_layoutmap.vx_copy(vals);
    }

    @Override
    public Type_layoutmap vx_copy(final Object... vals) {
      Type_layoutmap output = this;
      boolean ischanged = false;
      Class_layoutmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_layout> mapval = new LinkedHashMap<>(val.vx_maplayout());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_layout valany = null;
          if (valsub instanceof Ui.Type_layout) {
            valany = (Ui.Type_layout)valsub;
          } else if (valsub instanceof Ui.Type_layout) {
            valany = (Ui.Type_layout)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_layoutmap work = new Class_layoutmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_layoutmap vx_empty() {return e_layoutmap;}
    @Override
    public Type_layoutmap vx_type() {return t_layoutmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_layout), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_layoutmap e_layoutmap = new Class_layoutmap();
  public static final Type_layoutmap t_layoutmap = new Class_layoutmap();

  /**
   * type: pin
   * Pin an element
   * (type pin)
   */
  public interface Type_pin extends Core.Type_struct {
    public Ui.Type_pin vx_new(final Object... vals);
    public Ui.Type_pin vx_copy(final Object... vals);
    public Ui.Type_pin vx_empty();
    public Ui.Type_pin vx_type();
    public Core.Type_string name();
  }

  public static class Class_pin extends Core.Class_base implements Type_pin {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      return Core.immutablemap(output);
    }

    @Override
    public Type_pin vx_new(final Object... vals) {
      return e_pin.vx_copy(vals);
    }

    @Override
    public Type_pin vx_copy(final Object... vals) {
      Type_pin output = this;
      boolean ischanged = false;
      Class_pin val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_pin work = new Class_pin();
        work.vx_p_name = vx_p_name;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_pin vx_empty() {return e_pin;}
    @Override
    public Type_pin vx_type() {return t_pin;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_pin e_pin = new Class_pin();
  public static final Type_pin t_pin = new Class_pin();

  /**
   * type: point
   * Universal Point
   * (type point)
   */
  public interface Type_point extends Core.Type_struct {
    public Ui.Type_point vx_new(final Object... vals);
    public Ui.Type_point vx_copy(final Object... vals);
    public Ui.Type_point vx_empty();
    public Ui.Type_point vx_type();
    public Core.Type_int x();
    public Core.Type_int y();
    public Core.Type_int z();
    public Core.Type_int t();
    public Core.Type_int i();
    public Core.Type_boolean ispercent();
    public Ui.Type_pointstyle pointstyle();
  }

  public static class Class_point extends Core.Class_base implements Type_point {

    protected Core.Type_int vx_p_x;

    @Override
    public Core.Type_int x() {
      return this.vx_p_x == null ? Core.e_int : this.vx_p_x;
    }

    protected Core.Type_int vx_p_y;

    @Override
    public Core.Type_int y() {
      return this.vx_p_y == null ? Core.e_int : this.vx_p_y;
    }

    protected Core.Type_int vx_p_z;

    @Override
    public Core.Type_int z() {
      return this.vx_p_z == null ? Core.e_int : this.vx_p_z;
    }

    protected Core.Type_int vx_p_t;

    @Override
    public Core.Type_int t() {
      return this.vx_p_t == null ? Core.e_int : this.vx_p_t;
    }

    protected Core.Type_int vx_p_i;

    @Override
    public Core.Type_int i() {
      return this.vx_p_i == null ? Core.e_int : this.vx_p_i;
    }

    protected Core.Type_boolean vx_p_ispercent;

    @Override
    public Core.Type_boolean ispercent() {
      return this.vx_p_ispercent == null ? Core.e_boolean : this.vx_p_ispercent;
    }

    protected Ui.Type_pointstyle vx_p_pointstyle;

    @Override
    public Ui.Type_pointstyle pointstyle() {
      return this.vx_p_pointstyle == null ? Ui.e_pointstyle : this.vx_p_pointstyle;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":x":
        output = this.x();
        break;
      case ":y":
        output = this.y();
        break;
      case ":z":
        output = this.z();
        break;
      case ":t":
        output = this.t();
        break;
      case ":i":
        output = this.i();
        break;
      case ":ispercent":
        output = this.ispercent();
        break;
      case ":pointstyle":
        output = this.pointstyle();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":x", this.x());
      output.put(":y", this.y());
      output.put(":z", this.z());
      output.put(":t", this.t());
      output.put(":i", this.i());
      output.put(":ispercent", this.ispercent());
      output.put(":pointstyle", this.pointstyle());
      return Core.immutablemap(output);
    }

    @Override
    public Type_point vx_new(final Object... vals) {
      return e_point.vx_copy(vals);
    }

    @Override
    public Type_point vx_copy(final Object... vals) {
      Type_point output = this;
      boolean ischanged = false;
      Class_point val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_int vx_p_x = val.x();
      Core.Type_int vx_p_y = val.y();
      Core.Type_int vx_p_z = val.z();
      Core.Type_int vx_p_t = val.t();
      Core.Type_int vx_p_i = val.i();
      Core.Type_boolean vx_p_ispercent = val.ispercent();
      Ui.Type_pointstyle vx_p_pointstyle = val.pointstyle();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":x");
      validkeys.add(":y");
      validkeys.add(":z");
      validkeys.add(":t");
      validkeys.add(":i");
      validkeys.add(":ispercent");
      validkeys.add(":pointstyle");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":x":
            if (valsub == vx_p_x) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_x = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_x = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("x"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":y":
            if (valsub == vx_p_y) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_y = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_y = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("y"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":z":
            if (valsub == vx_p_z) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_z = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_z = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("z"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":t":
            if (valsub == vx_p_t) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_t = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_t = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("t"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":i":
            if (valsub == vx_p_i) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_i = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_i = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("i"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":ispercent":
            if (valsub == vx_p_ispercent) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_ispercent = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_ispercent = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("ispercent"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":pointstyle":
            if (valsub == vx_p_pointstyle) {
            } else if (valsub instanceof Ui.Type_pointstyle) {
              ischanged = true;
              vx_p_pointstyle = (Ui.Type_pointstyle)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pointstyle"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_point work = new Class_point();
        work.vx_p_x = vx_p_x;
        work.vx_p_y = vx_p_y;
        work.vx_p_z = vx_p_z;
        work.vx_p_t = vx_p_t;
        work.vx_p_i = vx_p_i;
        work.vx_p_ispercent = vx_p_ispercent;
        work.vx_p_pointstyle = vx_p_pointstyle;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_point vx_empty() {return e_point;}
    @Override
    public Type_point vx_type() {return t_point;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_point e_point = new Class_point();
  public static final Type_point t_point = new Class_point();

  /**
   * type: pointstyle
   * Universal Point Style
   * (type pointstyle)
   */
  public interface Type_pointstyle extends Core.Type_struct {
    public Ui.Type_pointstyle vx_new(final Object... vals);
    public Ui.Type_pointstyle vx_copy(final Object... vals);
    public Ui.Type_pointstyle vx_empty();
    public Ui.Type_pointstyle vx_type();
  }

  public static class Class_pointstyle extends Core.Class_base implements Type_pointstyle {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      return Core.immutablemap(output);
    }

    @Override
    public Type_pointstyle vx_new(final Object... vals) {
      return e_pointstyle.vx_copy(vals);
    }

    @Override
    public Type_pointstyle vx_copy(final Object... vals) {
      Type_pointstyle output = this;
      boolean ischanged = false;
      Class_pointstyle val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_pointstyle work = new Class_pointstyle();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_pointstyle vx_empty() {return e_pointstyle;}
    @Override
    public Type_pointstyle vx_type() {return t_pointstyle;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "pointstyle", // name
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
    }

  }

  public static final Type_pointstyle e_pointstyle = new Class_pointstyle();
  public static final Type_pointstyle t_pointstyle = new Class_pointstyle();

  /**
   * type: style
   * Universal Style
   * (type style)
   */
  public interface Type_style extends Core.Type_struct {
    public Ui.Type_style vx_new(final Object... vals);
    public Ui.Type_style vx_copy(final Object... vals);
    public Ui.Type_style vx_empty();
    public Ui.Type_style vx_type();
    public Core.Type_string name();
    public Ui.Type_bounds boundsmargin();
    public Ui.Type_bounds boundspadding();
    public Core.Type_string color_background();
    public Core.Type_string color_hoverbkgrd();
    public Ui.Type_cursor cursor();
    public Ui.Type_font font();
    public Core.Type_boolean hidden();
    public File.Type_file image_background();
    public Ui.Type_layout layout();
    public Ui.Type_styletype type();
    public Ui.Type_pin pin();
    public Ui.Type_point pointpos();
    public Ui.Type_point pointsize();
  }

  public static class Class_style extends Core.Class_base implements Type_style {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Ui.Type_bounds vx_p_boundsmargin;

    @Override
    public Ui.Type_bounds boundsmargin() {
      return this.vx_p_boundsmargin == null ? Ui.e_bounds : this.vx_p_boundsmargin;
    }

    protected Ui.Type_bounds vx_p_boundspadding;

    @Override
    public Ui.Type_bounds boundspadding() {
      return this.vx_p_boundspadding == null ? Ui.e_bounds : this.vx_p_boundspadding;
    }

    protected Core.Type_string vx_p_color_background;

    @Override
    public Core.Type_string color_background() {
      return this.vx_p_color_background == null ? Core.e_string : this.vx_p_color_background;
    }

    protected Core.Type_string vx_p_color_hoverbkgrd;

    @Override
    public Core.Type_string color_hoverbkgrd() {
      return this.vx_p_color_hoverbkgrd == null ? Core.e_string : this.vx_p_color_hoverbkgrd;
    }

    protected Ui.Type_cursor vx_p_cursor;

    @Override
    public Ui.Type_cursor cursor() {
      return this.vx_p_cursor == null ? Ui.e_cursor : this.vx_p_cursor;
    }

    protected Ui.Type_font vx_p_font;

    @Override
    public Ui.Type_font font() {
      return this.vx_p_font == null ? Ui.e_font : this.vx_p_font;
    }

    protected Core.Type_boolean vx_p_hidden;

    @Override
    public Core.Type_boolean hidden() {
      return this.vx_p_hidden == null ? Core.e_boolean : this.vx_p_hidden;
    }

    protected File.Type_file vx_p_image_background;

    @Override
    public File.Type_file image_background() {
      return this.vx_p_image_background == null ? File.e_file : this.vx_p_image_background;
    }

    protected Ui.Type_layout vx_p_layout;

    @Override
    public Ui.Type_layout layout() {
      return this.vx_p_layout == null ? Ui.e_layout : this.vx_p_layout;
    }

    protected Ui.Type_styletype vx_p_type;

    @Override
    public Ui.Type_styletype type() {
      return this.vx_p_type == null ? Ui.e_styletype : this.vx_p_type;
    }

    protected Ui.Type_pin vx_p_pin;

    @Override
    public Ui.Type_pin pin() {
      return this.vx_p_pin == null ? Ui.e_pin : this.vx_p_pin;
    }

    protected Ui.Type_point vx_p_pointpos;

    @Override
    public Ui.Type_point pointpos() {
      return this.vx_p_pointpos == null ? Ui.e_point : this.vx_p_pointpos;
    }

    protected Ui.Type_point vx_p_pointsize;

    @Override
    public Ui.Type_point pointsize() {
      return this.vx_p_pointsize == null ? Ui.e_point : this.vx_p_pointsize;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":boundsmargin":
        output = this.boundsmargin();
        break;
      case ":boundspadding":
        output = this.boundspadding();
        break;
      case ":color-background":
        output = this.color_background();
        break;
      case ":color-hoverbkgrd":
        output = this.color_hoverbkgrd();
        break;
      case ":cursor":
        output = this.cursor();
        break;
      case ":font":
        output = this.font();
        break;
      case ":hidden":
        output = this.hidden();
        break;
      case ":image-background":
        output = this.image_background();
        break;
      case ":layout":
        output = this.layout();
        break;
      case ":type":
        output = this.type();
        break;
      case ":pin":
        output = this.pin();
        break;
      case ":pointpos":
        output = this.pointpos();
        break;
      case ":pointsize":
        output = this.pointsize();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":boundsmargin", this.boundsmargin());
      output.put(":boundspadding", this.boundspadding());
      output.put(":color-background", this.color_background());
      output.put(":color-hoverbkgrd", this.color_hoverbkgrd());
      output.put(":cursor", this.cursor());
      output.put(":font", this.font());
      output.put(":hidden", this.hidden());
      output.put(":image-background", this.image_background());
      output.put(":layout", this.layout());
      output.put(":type", this.type());
      output.put(":pin", this.pin());
      output.put(":pointpos", this.pointpos());
      output.put(":pointsize", this.pointsize());
      return Core.immutablemap(output);
    }

    @Override
    public Type_style vx_new(final Object... vals) {
      return e_style.vx_copy(vals);
    }

    @Override
    public Type_style vx_copy(final Object... vals) {
      Type_style output = this;
      boolean ischanged = false;
      Class_style val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Ui.Type_bounds vx_p_boundsmargin = val.boundsmargin();
      Ui.Type_bounds vx_p_boundspadding = val.boundspadding();
      Core.Type_string vx_p_color_background = val.color_background();
      Core.Type_string vx_p_color_hoverbkgrd = val.color_hoverbkgrd();
      Ui.Type_cursor vx_p_cursor = val.cursor();
      Ui.Type_font vx_p_font = val.font();
      Core.Type_boolean vx_p_hidden = val.hidden();
      File.Type_file vx_p_image_background = val.image_background();
      Ui.Type_layout vx_p_layout = val.layout();
      Ui.Type_styletype vx_p_type = val.type();
      Ui.Type_pin vx_p_pin = val.pin();
      Ui.Type_point vx_p_pointpos = val.pointpos();
      Ui.Type_point vx_p_pointsize = val.pointsize();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":boundsmargin");
      validkeys.add(":boundspadding");
      validkeys.add(":color-background");
      validkeys.add(":color-hoverbkgrd");
      validkeys.add(":cursor");
      validkeys.add(":font");
      validkeys.add(":hidden");
      validkeys.add(":image-background");
      validkeys.add(":layout");
      validkeys.add(":type");
      validkeys.add(":pin");
      validkeys.add(":pointpos");
      validkeys.add(":pointsize");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":boundsmargin":
            if (valsub == vx_p_boundsmargin) {
            } else if (valsub instanceof Ui.Type_bounds) {
              ischanged = true;
              vx_p_boundsmargin = (Ui.Type_bounds)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("boundsmargin"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":boundspadding":
            if (valsub == vx_p_boundspadding) {
            } else if (valsub instanceof Ui.Type_bounds) {
              ischanged = true;
              vx_p_boundspadding = (Ui.Type_bounds)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("boundspadding"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":color-background":
            if (valsub == vx_p_color_background) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_color_background = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_background = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("color-background"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":color-hoverbkgrd":
            if (valsub == vx_p_color_hoverbkgrd) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_color_hoverbkgrd = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_color_hoverbkgrd = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("color-hoverbkgrd"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":cursor":
            if (valsub == vx_p_cursor) {
            } else if (valsub instanceof Ui.Type_cursor) {
              ischanged = true;
              vx_p_cursor = (Ui.Type_cursor)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("cursor"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":font":
            if (valsub == vx_p_font) {
            } else if (valsub instanceof Ui.Type_font) {
              ischanged = true;
              vx_p_font = (Ui.Type_font)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("font"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":hidden":
            if (valsub == vx_p_hidden) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_hidden = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_hidden = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":image-background":
            if (valsub == vx_p_image_background) {
            } else if (valsub instanceof File.Type_file) {
              ischanged = true;
              vx_p_image_background = (File.Type_file)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("image-background"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":layout":
            if (valsub == vx_p_layout) {
            } else if (valsub instanceof Ui.Type_layout) {
              ischanged = true;
              vx_p_layout = (Ui.Type_layout)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Ui.Type_styletype) {
              ischanged = true;
              vx_p_type = (Ui.Type_styletype)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":pin":
            if (valsub == vx_p_pin) {
            } else if (valsub instanceof Ui.Type_pin) {
              ischanged = true;
              vx_p_pin = (Ui.Type_pin)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pin"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":pointpos":
            if (valsub == vx_p_pointpos) {
            } else if (valsub instanceof Ui.Type_point) {
              ischanged = true;
              vx_p_pointpos = (Ui.Type_point)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pointpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":pointsize":
            if (valsub == vx_p_pointsize) {
            } else if (valsub instanceof Ui.Type_point) {
              ischanged = true;
              vx_p_pointsize = (Ui.Type_point)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pointsize"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_style work = new Class_style();
        work.vx_p_name = vx_p_name;
        work.vx_p_boundsmargin = vx_p_boundsmargin;
        work.vx_p_boundspadding = vx_p_boundspadding;
        work.vx_p_color_background = vx_p_color_background;
        work.vx_p_color_hoverbkgrd = vx_p_color_hoverbkgrd;
        work.vx_p_cursor = vx_p_cursor;
        work.vx_p_font = vx_p_font;
        work.vx_p_hidden = vx_p_hidden;
        work.vx_p_image_background = vx_p_image_background;
        work.vx_p_layout = vx_p_layout;
        work.vx_p_type = vx_p_type;
        work.vx_p_pin = vx_p_pin;
        work.vx_p_pointpos = vx_p_pointpos;
        work.vx_p_pointsize = vx_p_pointsize;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_style vx_empty() {return e_style;}
    @Override
    public Type_style vx_type() {return t_style;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_style e_style = new Class_style();
  public static final Type_style t_style = new Class_style();

  /**
   * type: stylelist
   * Universal Stylelist
   * (type stylelist)
   */
  public interface Type_stylelist extends Core.Type_list {
    public Ui.Type_stylelist vx_new(final Object... vals);
    public Ui.Type_stylelist vx_copy(final Object... vals);
    public Ui.Type_stylelist vx_empty();
    public Ui.Type_stylelist vx_type();
    public List<Ui.Type_style> vx_liststyle();
    public Ui.Type_style vx_style(final Core.Type_int index);
  }

  public static class Class_stylelist extends Core.Class_base implements Type_stylelist {

    protected List<Ui.Type_style> vx_p_list = Core.immutablelist(new ArrayList<Ui.Type_style>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Ui.Type_style vx_style(final Core.Type_int index) {
      Ui.Type_style output = Ui.e_style;
      Class_stylelist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_style> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_style> vx_liststyle() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_style(index);
    }

    @Override
    public Type_stylelist vx_new(final Object... vals) {
      return e_stylelist.vx_copy(vals);
    }

    @Override
    public Type_stylelist vx_copy(final Object... vals) {
      Type_stylelist output = this;
      boolean ischanged = false;
      Class_stylelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Ui.Type_style> listval = new ArrayList<>(val.vx_liststyle());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Ui.Type_style) {
          ischanged = true;
          listval.add((Ui.Type_style)valsub);
        } else if (valsub instanceof Ui.Type_style) {
          ischanged = true;
          listval.add((Ui.Type_style)valsub);
        } else if (valsub instanceof Type_stylelist) {
          Type_stylelist multi = (Type_stylelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststyle());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Ui.Type_style) {
              Ui.Type_style valitem = (Ui.Type_style)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_stylelist work = new Class_stylelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_stylelist vx_empty() {return e_stylelist;}
    @Override
    public Type_stylelist vx_type() {return t_stylelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_style), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_stylelist e_stylelist = new Class_stylelist();
  public static final Type_stylelist t_stylelist = new Class_stylelist();

  /**
   * type: stylemap
   * Universal Stylemap
   * (type stylemap)
   */
  public interface Type_stylemap extends Core.Type_map {
    public Ui.Type_stylemap vx_new(final Object... vals);
    public Ui.Type_stylemap vx_copy(final Object... vals);
    public Ui.Type_stylemap vx_empty();
    public Ui.Type_stylemap vx_type();
    public Map<String, Ui.Type_style> vx_mapstyle();
    public Ui.Type_style vx_style(final Core.Type_string key);
  }

  public static class Class_stylemap extends Core.Class_base implements Type_stylemap {

    protected Map<String, Ui.Type_style> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_style>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_style vx_style(final Core.Type_string key) {
      Ui.Type_style output = Ui.e_style;
      Class_stylemap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_style> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_style);
      return output;
    }

    @Override
    public Map<String, Ui.Type_style> vx_mapstyle() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_style(key);
    }

    @Override
    public Type_stylemap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_stylemap output = new Class_stylemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_style> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_style) {
          Ui.Type_style castval = (Ui.Type_style)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_stylemap vx_new(final Object... vals) {
      return e_stylemap.vx_copy(vals);
    }

    @Override
    public Type_stylemap vx_copy(final Object... vals) {
      Type_stylemap output = this;
      boolean ischanged = false;
      Class_stylemap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_style> mapval = new LinkedHashMap<>(val.vx_mapstyle());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_style valany = null;
          if (valsub instanceof Ui.Type_style) {
            valany = (Ui.Type_style)valsub;
          } else if (valsub instanceof Ui.Type_style) {
            valany = (Ui.Type_style)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_stylemap work = new Class_stylemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_stylemap vx_empty() {return e_stylemap;}
    @Override
    public Type_stylemap vx_type() {return t_stylemap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_style), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_stylemap e_stylemap = new Class_stylemap();
  public static final Type_stylemap t_stylemap = new Class_stylemap();

  /**
   * type: stylesheet
   * Universal Stylesheet
   * (type stylesheet)
   */
  public interface Type_stylesheet extends Core.Type_struct {
    public Ui.Type_stylesheet vx_new(final Object... vals);
    public Ui.Type_stylesheet vx_copy(final Object... vals);
    public Ui.Type_stylesheet vx_empty();
    public Ui.Type_stylesheet vx_type();
    public Ui.Type_fontfacemap fontfacemap();
    public Ui.Type_stylemap stylemap();
  }

  public static class Class_stylesheet extends Core.Class_base implements Type_stylesheet {

    protected Ui.Type_fontfacemap vx_p_fontfacemap;

    @Override
    public Ui.Type_fontfacemap fontfacemap() {
      return this.vx_p_fontfacemap == null ? Ui.e_fontfacemap : this.vx_p_fontfacemap;
    }

    protected Ui.Type_stylemap vx_p_stylemap;

    @Override
    public Ui.Type_stylemap stylemap() {
      return this.vx_p_stylemap == null ? Ui.e_stylemap : this.vx_p_stylemap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":fontfacemap":
        output = this.fontfacemap();
        break;
      case ":stylemap":
        output = this.stylemap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":fontfacemap", this.fontfacemap());
      output.put(":stylemap", this.stylemap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_stylesheet vx_new(final Object... vals) {
      return e_stylesheet.vx_copy(vals);
    }

    @Override
    public Type_stylesheet vx_copy(final Object... vals) {
      Type_stylesheet output = this;
      boolean ischanged = false;
      Class_stylesheet val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Ui.Type_fontfacemap vx_p_fontfacemap = val.fontfacemap();
      Ui.Type_stylemap vx_p_stylemap = val.stylemap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":fontfacemap");
      validkeys.add(":stylemap");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":fontfacemap":
            if (valsub == vx_p_fontfacemap) {
            } else if (valsub instanceof Ui.Type_fontfacemap) {
              ischanged = true;
              vx_p_fontfacemap = (Ui.Type_fontfacemap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fontfacemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":stylemap":
            if (valsub == vx_p_stylemap) {
            } else if (valsub instanceof Ui.Type_stylemap) {
              ischanged = true;
              vx_p_stylemap = (Ui.Type_stylemap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("stylemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_stylesheet work = new Class_stylesheet();
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
    public Type_stylesheet vx_empty() {return e_stylesheet;}
    @Override
    public Type_stylesheet vx_type() {return t_stylesheet;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_stylesheet e_stylesheet = new Class_stylesheet();
  public static final Type_stylesheet t_stylesheet = new Class_stylesheet();

  /**
   * type: styletype
   * Universal Style Type
   * (type styletype)
   */
  public interface Type_styletype extends Core.Type_struct {
    public Ui.Type_styletype vx_new(final Object... vals);
    public Ui.Type_styletype vx_copy(final Object... vals);
    public Ui.Type_styletype vx_empty();
    public Ui.Type_styletype vx_type();
  }

  public static class Class_styletype extends Core.Class_base implements Type_styletype {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      return Core.immutablemap(output);
    }

    @Override
    public Type_styletype vx_new(final Object... vals) {
      return e_styletype.vx_copy(vals);
    }

    @Override
    public Type_styletype vx_copy(final Object... vals) {
      Type_styletype output = this;
      boolean ischanged = false;
      Class_styletype val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_styletype work = new Class_styletype();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_styletype vx_empty() {return e_styletype;}
    @Override
    public Type_styletype vx_type() {return t_styletype;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_styletype e_styletype = new Class_styletype();
  public static final Type_styletype t_styletype = new Class_styletype();

  /**
   * type: ui
   * Universal UI Element
   * (type ui)
   */
  public interface Type_ui extends Core.Type_struct {
    public Ui.Type_ui vx_new(final Object... vals);
    public Ui.Type_ui vx_copy(final Object... vals);
    public Ui.Type_ui vx_empty();
    public Ui.Type_ui vx_type();
    public Core.Type_string uid();
    public Core.Type_string name();
    public Ui.Type_layout layout();
    public Core.Type_string parent();
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

    protected Core.Type_string vx_p_uid;

    @Override
    public Core.Type_string uid() {
      return this.vx_p_uid == null ? Core.e_string : this.vx_p_uid;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Ui.Type_layout vx_p_layout;

    @Override
    public Ui.Type_layout layout() {
      return this.vx_p_layout == null ? Ui.e_layout : this.vx_p_layout;
    }

    protected Core.Type_string vx_p_parent;

    @Override
    public Core.Type_string parent() {
      return this.vx_p_parent == null ? Core.e_string : this.vx_p_parent;
    }

    protected Core.Type_string vx_p_path;

    @Override
    public Core.Type_string path() {
      return this.vx_p_path == null ? Core.e_string : this.vx_p_path;
    }

    protected Core.Type_boolean vx_p_hidden;

    @Override
    public Core.Type_boolean hidden() {
      return this.vx_p_hidden == null ? Core.e_boolean : this.vx_p_hidden;
    }

    protected Core.Type_boolean vx_p_selected;

    @Override
    public Core.Type_boolean selected() {
      return this.vx_p_selected == null ? Core.e_boolean : this.vx_p_selected;
    }

    protected Core.Type_boolean vx_p_selectmulti;

    @Override
    public Core.Type_boolean selectmulti() {
      return this.vx_p_selectmulti == null ? Core.e_boolean : this.vx_p_selectmulti;
    }

    protected Ui.Type_style vx_p_style;

    @Override
    public Ui.Type_style style() {
      return this.vx_p_style == null ? Ui.e_style : this.vx_p_style;
    }

    protected Ui.Type_stylelist vx_p_stylelist;

    @Override
    public Ui.Type_stylelist stylelist() {
      return this.vx_p_stylelist == null ? Ui.e_stylelist : this.vx_p_stylelist;
    }

    protected Event.Type_eventmap vx_p_eventmap;

    @Override
    public Event.Type_eventmap eventmap() {
      return this.vx_p_eventmap == null ? Event.e_eventmap : this.vx_p_eventmap;
    }

    protected Core.Type_any vx_p_data;

    @Override
    public Core.Type_any data() {
      return this.vx_p_data == null ? Core.e_any : this.vx_p_data;
    }

    protected Ui.Type_uimap vx_p_uimap;

    @Override
    public Ui.Type_uimap uimap() {
      return this.vx_p_uimap == null ? Ui.e_uimap : this.vx_p_uimap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":uid":
        output = this.uid();
        break;
      case ":name":
        output = this.name();
        break;
      case ":layout":
        output = this.layout();
        break;
      case ":parent":
        output = this.parent();
        break;
      case ":path":
        output = this.path();
        break;
      case ":hidden":
        output = this.hidden();
        break;
      case ":selected":
        output = this.selected();
        break;
      case ":selectmulti":
        output = this.selectmulti();
        break;
      case ":style":
        output = this.style();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":data":
        output = this.data();
        break;
      case ":uimap":
        output = this.uimap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":uid", this.uid());
      output.put(":name", this.name());
      output.put(":layout", this.layout());
      output.put(":parent", this.parent());
      output.put(":path", this.path());
      output.put(":hidden", this.hidden());
      output.put(":selected", this.selected());
      output.put(":selectmulti", this.selectmulti());
      output.put(":style", this.style());
      output.put(":stylelist", this.stylelist());
      output.put(":eventmap", this.eventmap());
      output.put(":data", this.data());
      output.put(":uimap", this.uimap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_ui vx_new(final Object... vals) {
      return e_ui.vx_copy(vals);
    }

    @Override
    public Type_ui vx_copy(final Object... vals) {
      Type_ui output = this;
      boolean ischanged = false;
      Class_ui val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_uid = val.uid();
      Core.Type_string vx_p_name = val.name();
      Ui.Type_layout vx_p_layout = val.layout();
      Core.Type_string vx_p_parent = val.parent();
      Core.Type_string vx_p_path = val.path();
      Core.Type_boolean vx_p_hidden = val.hidden();
      Core.Type_boolean vx_p_selected = val.selected();
      Core.Type_boolean vx_p_selectmulti = val.selectmulti();
      Ui.Type_style vx_p_style = val.style();
      Ui.Type_stylelist vx_p_stylelist = val.stylelist();
      Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Core.Type_any vx_p_data = val.data();
      Ui.Type_uimap vx_p_uimap = val.uimap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":uid");
      validkeys.add(":name");
      validkeys.add(":layout");
      validkeys.add(":parent");
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
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":uid":
            if (valsub == vx_p_uid) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_uid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_uid = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("uid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":layout":
            if (valsub == vx_p_layout) {
            } else if (valsub instanceof Ui.Type_layout) {
              ischanged = true;
              vx_p_layout = (Ui.Type_layout)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":parent":
            if (valsub == vx_p_parent) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_parent = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_parent = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("parent"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_path = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_path = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":hidden":
            if (valsub == vx_p_hidden) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_hidden = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_hidden = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":selected":
            if (valsub == vx_p_selected) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_selected = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_selected = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("selected"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":selectmulti":
            if (valsub == vx_p_selectmulti) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_selectmulti = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_selectmulti = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("selectmulti"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Ui.Type_style) {
              ischanged = true;
              vx_p_style = (Ui.Type_style)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Ui.Type_stylelist) {
              ischanged = true;
              vx_p_stylelist = (Ui.Type_stylelist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              ischanged = true;
              vx_p_eventmap = (Event.Type_eventmap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":data":
            if (valsub == vx_p_data) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_data = (Core.Type_any)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("data"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":uimap":
            if (valsub == vx_p_uimap) {
            } else if (valsub instanceof Ui.Type_uimap) {
              ischanged = true;
              vx_p_uimap = (Ui.Type_uimap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("uimap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_ui work = new Class_ui();
        work.vx_p_uid = vx_p_uid;
        work.vx_p_name = vx_p_name;
        work.vx_p_layout = vx_p_layout;
        work.vx_p_parent = vx_p_parent;
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
    public Type_ui vx_empty() {return e_ui;}
    @Override
    public Type_ui vx_type() {return t_ui;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_ui e_ui = new Class_ui();
  public static final Type_ui t_ui = new Class_ui();

  /**
   * type: uiengine
   * Template for uiengine
   * (type uiengine)
   */
  public interface Type_uiengine extends Core.Type_struct {
    public Ui.Type_uiengine vx_new(final Object... vals);
    public Ui.Type_uiengine vx_copy(final Object... vals);
    public Ui.Type_uiengine vx_empty();
    public Ui.Type_uiengine vx_type();
    public Ui.Type_uimap parentmap();
    public Ui.Type_layoutengine layoutengine();
    public Ui.Type_stylesheet stylesheet();
    public Ui.Type_ui ui();
  }

  public static class Class_uiengine extends Core.Class_base implements Type_uiengine {

    protected Ui.Type_uimap vx_p_parentmap;

    @Override
    public Ui.Type_uimap parentmap() {
      return this.vx_p_parentmap == null ? Ui.e_uimap : this.vx_p_parentmap;
    }

    protected Ui.Type_layoutengine vx_p_layoutengine;

    @Override
    public Ui.Type_layoutengine layoutengine() {
      return this.vx_p_layoutengine == null ? Ui.e_layoutengine : this.vx_p_layoutengine;
    }

    protected Ui.Type_stylesheet vx_p_stylesheet;

    @Override
    public Ui.Type_stylesheet stylesheet() {
      return this.vx_p_stylesheet == null ? Ui.e_stylesheet : this.vx_p_stylesheet;
    }

    protected Ui.Type_ui vx_p_ui;

    @Override
    public Ui.Type_ui ui() {
      return this.vx_p_ui == null ? Ui.e_ui : this.vx_p_ui;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":parentmap":
        output = this.parentmap();
        break;
      case ":layoutengine":
        output = this.layoutengine();
        break;
      case ":stylesheet":
        output = this.stylesheet();
        break;
      case ":ui":
        output = this.ui();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":parentmap", this.parentmap());
      output.put(":layoutengine", this.layoutengine());
      output.put(":stylesheet", this.stylesheet());
      output.put(":ui", this.ui());
      return Core.immutablemap(output);
    }

    @Override
    public Type_uiengine vx_new(final Object... vals) {
      return e_uiengine.vx_copy(vals);
    }

    @Override
    public Type_uiengine vx_copy(final Object... vals) {
      Type_uiengine output = this;
      boolean ischanged = false;
      Class_uiengine val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Ui.Type_uimap vx_p_parentmap = val.parentmap();
      Ui.Type_layoutengine vx_p_layoutengine = val.layoutengine();
      Ui.Type_stylesheet vx_p_stylesheet = val.stylesheet();
      Ui.Type_ui vx_p_ui = val.ui();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":parentmap");
      validkeys.add(":layoutengine");
      validkeys.add(":stylesheet");
      validkeys.add(":ui");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":parentmap":
            if (valsub == vx_p_parentmap) {
            } else if (valsub instanceof Ui.Type_uimap) {
              ischanged = true;
              vx_p_parentmap = (Ui.Type_uimap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("parentmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":layoutengine":
            if (valsub == vx_p_layoutengine) {
            } else if (valsub instanceof Ui.Type_layoutengine) {
              ischanged = true;
              vx_p_layoutengine = (Ui.Type_layoutengine)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("layoutengine"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":stylesheet":
            if (valsub == vx_p_stylesheet) {
            } else if (valsub instanceof Ui.Type_stylesheet) {
              ischanged = true;
              vx_p_stylesheet = (Ui.Type_stylesheet)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("stylesheet"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":ui":
            if (valsub == vx_p_ui) {
            } else if (valsub instanceof Ui.Type_ui) {
              ischanged = true;
              vx_p_ui = (Ui.Type_ui)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("ui"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_uiengine work = new Class_uiengine();
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
    public Type_uiengine vx_empty() {return e_uiengine;}
    @Override
    public Type_uiengine vx_type() {return t_uiengine;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_uiengine e_uiengine = new Class_uiengine();
  public static final Type_uiengine t_uiengine = new Class_uiengine();

  /**
   * type: uilist
   * List of ui
   * (type uilist)
   */
  public interface Type_uilist extends Core.Type_list {
    public Ui.Type_uilist vx_new(final Object... vals);
    public Ui.Type_uilist vx_copy(final Object... vals);
    public Ui.Type_uilist vx_empty();
    public Ui.Type_uilist vx_type();
    public List<Ui.Type_ui> vx_listui();
    public Ui.Type_ui vx_ui(final Core.Type_int index);
  }

  public static class Class_uilist extends Core.Class_base implements Type_uilist {

    protected List<Ui.Type_ui> vx_p_list = Core.immutablelist(new ArrayList<Ui.Type_ui>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Ui.Type_ui vx_ui(final Core.Type_int index) {
      Ui.Type_ui output = Ui.e_ui;
      Class_uilist list = this;
      int iindex = index.vx_int();
      List<Ui.Type_ui> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Ui.Type_ui> vx_listui() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_ui(index);
    }

    @Override
    public Type_uilist vx_new(final Object... vals) {
      return e_uilist.vx_copy(vals);
    }

    @Override
    public Type_uilist vx_copy(final Object... vals) {
      Type_uilist output = this;
      boolean ischanged = false;
      Class_uilist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Ui.Type_ui> listval = new ArrayList<>(val.vx_listui());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Ui.Type_ui) {
          ischanged = true;
          listval.add((Ui.Type_ui)valsub);
        } else if (valsub instanceof Ui.Type_ui) {
          ischanged = true;
          listval.add((Ui.Type_ui)valsub);
        } else if (valsub instanceof Type_uilist) {
          Type_uilist multi = (Type_uilist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listui());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Ui.Type_ui) {
              Ui.Type_ui valitem = (Ui.Type_ui)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_uilist work = new Class_uilist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_uilist vx_empty() {return e_uilist;}
    @Override
    public Type_uilist vx_type() {return t_uilist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uilist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_uilist e_uilist = new Class_uilist();
  public static final Type_uilist t_uilist = new Class_uilist();

  /**
   * type: uimap
   * Map of ui
   * (type uimap)
   */
  public interface Type_uimap extends Core.Type_map {
    public Ui.Type_uimap vx_new(final Object... vals);
    public Ui.Type_uimap vx_copy(final Object... vals);
    public Ui.Type_uimap vx_empty();
    public Ui.Type_uimap vx_type();
    public Map<String, Ui.Type_ui> vx_mapui();
    public Ui.Type_ui vx_ui(final Core.Type_string key);
  }

  public static class Class_uimap extends Core.Class_base implements Type_uimap {

    protected Map<String, Ui.Type_ui> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Ui.Type_ui>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Ui.Type_ui vx_ui(final Core.Type_string key) {
      Ui.Type_ui output = Ui.e_ui;
      Class_uimap map = this;
      String skey = key.vx_string();
      Map<String, Ui.Type_ui> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Ui.e_ui);
      return output;
    }

    @Override
    public Map<String, Ui.Type_ui> vx_mapui() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_ui(key);
    }

    @Override
    public Type_uimap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_uimap output = new Class_uimap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Ui.Type_ui> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Ui.Type_ui) {
          Ui.Type_ui castval = (Ui.Type_ui)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidvalue", val);
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_uimap vx_new(final Object... vals) {
      return e_uimap.vx_copy(vals);
    }

    @Override
    public Type_uimap vx_copy(final Object... vals) {
      Type_uimap output = this;
      boolean ischanged = false;
      Class_uimap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Ui.Type_ui> mapval = new LinkedHashMap<>(val.vx_mapui());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Ui.Type_ui valany = null;
          if (valsub instanceof Ui.Type_ui) {
            valany = (Ui.Type_ui)valsub;
          } else if (valsub instanceof Ui.Type_ui) {
            valany = (Ui.Type_ui)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidkeyvalue", msgmap);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_uimap work = new Class_uimap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_uimap vx_empty() {return e_uimap;}
    @Override
    public Type_uimap vx_type() {return t_uimap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uimap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_uimap e_uimap = new Class_uimap();
  public static final Type_uimap t_uimap = new Class_uimap();

  /**
   * Constant: layout-app
   * {layout}
   */
  public static class Const_layout_app extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_app output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-app")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_app c_layout_app = new Const_layout_app();


  /**
   * Constant: layout-background
   * {layout}
   */
  public static class Const_layout_background extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_background output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-background")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_background c_layout_background = new Const_layout_background();


  /**
   * Constant: layout-button
   * {layout}
   */
  public static class Const_layout_button extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_button output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-button")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_button c_layout_button = new Const_layout_button();


  /**
   * Constant: layout-combobox
   * {layout}
   */
  public static class Const_layout_combobox extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_combobox output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-combobox")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_combobox c_layout_combobox = new Const_layout_combobox();


  /**
   * Constant: layout-else
   * {layout}
   */
  public static class Const_layout_else extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_else output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-else")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_else c_layout_else = new Const_layout_else();


  /**
   * Constant: layout-flow-columns
   * {layout}
   */
  public static class Const_layout_flow_columns extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_columns output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-flow-columns")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_flow_columns c_layout_flow_columns = new Const_layout_flow_columns();


  /**
   * Constant: layout-flow-item
   * {layout}
   */
  public static class Const_layout_flow_item extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_item output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-flow-item")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_flow_item c_layout_flow_item = new Const_layout_flow_item();


  /**
   * Constant: layout-flow-rows
   * {layout}
   */
  public static class Const_layout_flow_rows extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_rows output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-flow-rows")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_flow_rows c_layout_flow_rows = new Const_layout_flow_rows();


  /**
   * Constant: layout-image
   * {layout}
   */
  public static class Const_layout_image extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_image output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-image")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_image c_layout_image = new Const_layout_image();


  /**
   * Constant: layout-label
   * {layout}
   */
  public static class Const_layout_label extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_label output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-label")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_label c_layout_label = new Const_layout_label();


  /**
   * Constant: layout-main
   * {layout}
   */
  public static class Const_layout_main extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_main output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-main")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_main c_layout_main = new Const_layout_main();


  /**
   * Constant: layout-maxpanel
   * {layout}
   */
  public static class Const_layout_maxpanel extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_maxpanel output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-maxpanel")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_maxpanel c_layout_maxpanel = new Const_layout_maxpanel();


  /**
   * Constant: layout-menubar
   * {layout}
   */
  public static class Const_layout_menubar extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_menubar output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-menubar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_menubar c_layout_menubar = new Const_layout_menubar();


  /**
   * Constant: layout-menudrawer
   * {layout}
   */
  public static class Const_layout_menudrawer extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_menudrawer output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-menudrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_menudrawer c_layout_menudrawer = new Const_layout_menudrawer();


  /**
   * Constant: layout-msgbox
   * {layout}
   */
  public static class Const_layout_msgbox extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_msgbox output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-msgbox")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_msgbox c_layout_msgbox = new Const_layout_msgbox();


  /**
   * Constant: layout-navbar
   * {layout}
   */
  public static class Const_layout_navbar extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_navbar output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-navbar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_navbar c_layout_navbar = new Const_layout_navbar();


  /**
   * Constant: layout-navdrawer
   * {layout}
   */
  public static class Const_layout_navdrawer extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_navdrawer output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-navdrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_navdrawer c_layout_navdrawer = new Const_layout_navdrawer();


  /**
   * Constant: layout-panel
   * {layout}
   */
  public static class Const_layout_panel extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_panel output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-panel")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_panel c_layout_panel = new Const_layout_panel();


  /**
   * Constant: layout-parallax
   * {layout}
   */
  public static class Const_layout_parallax extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_parallax output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-parallax")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_parallax c_layout_parallax = new Const_layout_parallax();


  /**
   * Constant: layout-statusbar
   * {layout}
   */
  public static class Const_layout_statusbar extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_statusbar output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-statusbar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_statusbar c_layout_statusbar = new Const_layout_statusbar();


  /**
   * Constant: layout-statusdrawer
   * {layout}
   */
  public static class Const_layout_statusdrawer extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_statusdrawer output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-statusdrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_statusdrawer c_layout_statusdrawer = new Const_layout_statusdrawer();


  /**
   * Constant: layout-text
   * {layout}
   */
  public static class Const_layout_text extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_text output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-text")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_text c_layout_text = new Const_layout_text();


  /**
   * Constant: layout-textentry
   * {layout}
   */
  public static class Const_layout_textentry extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_textentry output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-textentry")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_textentry c_layout_textentry = new Const_layout_textentry();


  /**
   * Constant: layout-titlebar
   * {layout}
   */
  public static class Const_layout_titlebar extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_layout_titlebar output) {
      Ui.Type_layout val = Core.f_new(
        Ui.t_layout,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("layout-titlebar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_titlebar c_layout_titlebar = new Const_layout_titlebar();


  /**
   * Constant: pin-bottom
   * {pin}
   */
  public static class Const_pin_bottom extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_bottom output) {
    }


  }

  public static final Const_pin_bottom c_pin_bottom = new Const_pin_bottom();


  /**
   * Constant: pin-center
   * {pin}
   */
  public static class Const_pin_center extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center output) {
    }


  }

  public static final Const_pin_center c_pin_center = new Const_pin_center();


  /**
   * Constant: pin-center-h
   * {pin}
   */
  public static class Const_pin_center_h extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center_h output) {
    }


  }

  public static final Const_pin_center_h c_pin_center_h = new Const_pin_center_h();


  /**
   * Constant: pin-center-v
   * {pin}
   */
  public static class Const_pin_center_v extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center_v output) {
    }


  }

  public static final Const_pin_center_v c_pin_center_v = new Const_pin_center_v();


  /**
   * Constant: pin-expand
   * {pin}
   */
  public static class Const_pin_expand extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_expand output) {
    }


  }

  public static final Const_pin_expand c_pin_expand = new Const_pin_expand();


  /**
   * Constant: pin-left
   * {pin}
   */
  public static class Const_pin_left extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_left output) {
    }


  }

  public static final Const_pin_left c_pin_left = new Const_pin_left();


  /**
   * Constant: pin-right
   * {pin}
   */
  public static class Const_pin_right extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_right output) {
    }


  }

  public static final Const_pin_right c_pin_right = new Const_pin_right();


  /**
   * Constant: pin-top
   * {pin}
   */
  public static class Const_pin_top extends Ui.Class_pin implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_pin_top output) {
    }


  }

  public static final Const_pin_top c_pin_top = new Const_pin_top();


  /**
   * Constant: styletype-custom
   * {styletype}
   */
  public static class Const_styletype_custom extends Ui.Class_styletype implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_custom output) {
    }


  }

  public static final Const_styletype_custom c_styletype_custom = new Const_styletype_custom();


  /**
   * Constant: styletype-shared
   * {styletype}
   */
  public static class Const_styletype_shared extends Ui.Class_styletype implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_shared output) {
    }


  }

  public static final Const_styletype_shared c_styletype_shared = new Const_styletype_shared();


  /**
   * Constant: styletype-system
   * {styletype}
   */
  public static class Const_styletype_system extends Ui.Class_styletype implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_system output) {
    }


  }

  public static final Const_styletype_system c_styletype_system = new Const_styletype_system();

  /**
   * @function boolean_writestate_from_ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writestate<-ui)
   */
  public static interface Func_boolean_writestate_from_ui extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_boolean_writestate_from_ui extends Core.Class_base implements Func_boolean_writestate_from_ui {

    @Override
    public Func_boolean_writestate_from_ui vx_new(Object... vals) {
      Class_boolean_writestate_from_ui output = new Class_boolean_writestate_from_ui();
      return output;
    }

    @Override
    public Func_boolean_writestate_from_ui vx_copy(Object... vals) {
      Class_boolean_writestate_from_ui output = new Class_boolean_writestate_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_writestate_from_ui vx_empty() {return e_boolean_writestate_from_ui;}
    @Override
    public Func_boolean_writestate_from_ui vx_type() {return t_boolean_writestate_from_ui;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_boolean_writestate_from_ui(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_writestate_from_ui(context, ui);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      return Ui.f_boolean_writestate_from_ui(context, ui);
    }

  }

  public static final Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = new Ui.Class_boolean_writestate_from_ui();
  public static final Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = new Ui.Class_boolean_writestate_from_ui();

  public static Core.Type_boolean f_boolean_writestate_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        return State.f_boolean_writestate_from_mapname_name_value(context, Core.vx_new_string(":uimap"), uid, ui);
      })
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
  public static interface Func_boolean_writestate_from_uiengine extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine);
  }

  public static class Class_boolean_writestate_from_uiengine extends Core.Class_base implements Func_boolean_writestate_from_uiengine {

    @Override
    public Func_boolean_writestate_from_uiengine vx_new(Object... vals) {
      Class_boolean_writestate_from_uiengine output = new Class_boolean_writestate_from_uiengine();
      return output;
    }

    @Override
    public Func_boolean_writestate_from_uiengine vx_copy(Object... vals) {
      Class_boolean_writestate_from_uiengine output = new Class_boolean_writestate_from_uiengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_writestate_from_uiengine vx_empty() {return e_boolean_writestate_from_uiengine;}
    @Override
    public Func_boolean_writestate_from_uiengine vx_type() {return t_boolean_writestate_from_uiengine;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uiengine inputval = (Ui.Type_uiengine)value;
      Core.Type_any outputval = Ui.f_boolean_writestate_from_uiengine(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_boolean_writestate_from_uiengine(context, uiengine);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
      return Ui.f_boolean_writestate_from_uiengine(context, uiengine);
    }

  }

  public static final Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = new Ui.Class_boolean_writestate_from_uiengine();
  public static final Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = new Ui.Class_boolean_writestate_from_uiengine();

  public static Core.Type_boolean f_boolean_writestate_from_uiengine(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
    Core.Type_boolean output = Core.e_boolean;
    output = State.f_boolean_writestate_from_name_value(context, Core.vx_new_string(":uiengine"), uiengine);
    return output;
  }

  /**
   * @function fontfacemap_from_fontfacelist
   * Returns a fontfacemap from a fontfacelist
   * @param  {fontfacelist} fontfacelist
   * @return {fontfacemap}
   * (func fontfacemap<-fontfacelist)
   */
  public static interface Func_fontfacemap_from_fontfacelist extends Core.Func_any_from_any {
    public Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist);
  }

  public static class Class_fontfacemap_from_fontfacelist extends Core.Class_base implements Func_fontfacemap_from_fontfacelist {

    @Override
    public Func_fontfacemap_from_fontfacelist vx_new(Object... vals) {
      Class_fontfacemap_from_fontfacelist output = new Class_fontfacemap_from_fontfacelist();
      return output;
    }

    @Override
    public Func_fontfacemap_from_fontfacelist vx_copy(Object... vals) {
      Class_fontfacemap_from_fontfacelist output = new Class_fontfacemap_from_fontfacelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "fontfacemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_fontface), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_fontfacemap_from_fontfacelist vx_empty() {return e_fontfacemap_from_fontfacelist;}
    @Override
    public Func_fontfacemap_from_fontfacelist vx_type() {return t_fontfacemap_from_fontfacelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_fontfacelist inputval = (Ui.Type_fontfacelist)value;
      Core.Type_any outputval = Ui.f_fontfacemap_from_fontfacelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_fontfacelist fontfacelist = Core.f_any_from_any(Ui.t_fontfacelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
      return output;
    }

    @Override
    public Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist) {
      return Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
    }

  }

  public static final Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist = new Ui.Class_fontfacemap_from_fontfacelist();
  public static final Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist = new Ui.Class_fontfacemap_from_fontfacelist();

  public static Ui.Type_fontfacemap f_fontfacemap_from_fontfacelist(final Ui.Type_fontfacelist fontfacelist) {
    Ui.Type_fontfacemap output = Ui.e_fontfacemap;
    output = Core.f_map_from_list(
      Ui.t_fontfacemap,
      fontfacelist,
      Core.t_any_from_any.vx_fn_new((fontface_any) -> {
        Ui.Type_fontface fontface = Core.f_any_from_any(Ui.t_fontface, fontface_any);
        return 
          fontface.name();
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
  public static interface Func_layout_from_style extends Core.Func_any_from_any {
    public Ui.Type_layout vx_layout_from_style(final Ui.Type_style style);
  }

  public static class Class_layout_from_style extends Core.Class_base implements Func_layout_from_style {

    @Override
    public Func_layout_from_style vx_new(Object... vals) {
      Class_layout_from_style output = new Class_layout_from_style();
      return output;
    }

    @Override
    public Func_layout_from_style vx_copy(Object... vals) {
      Class_layout_from_style output = new Class_layout_from_style();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_layout_from_style vx_empty() {return e_layout_from_style;}
    @Override
    public Func_layout_from_style vx_type() {return t_layout_from_style;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_style inputval = (Ui.Type_style)value;
      Core.Type_any outputval = Ui.f_layout_from_style(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_style style = Core.f_any_from_any(Ui.t_style, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layout_from_style(style);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_style(final Ui.Type_style style) {
      return Ui.f_layout_from_style(style);
    }

  }

  public static final Func_layout_from_style e_layout_from_style = new Ui.Class_layout_from_style();
  public static final Func_layout_from_style t_layout_from_style = new Ui.Class_layout_from_style();

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
  public static interface Func_layout_from_ui extends Core.Func_any_from_any_context {
    public Ui.Type_layout vx_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_layout_from_ui extends Core.Class_base implements Func_layout_from_ui {

    @Override
    public Func_layout_from_ui vx_new(Object... vals) {
      Class_layout_from_ui output = new Class_layout_from_ui();
      return output;
    }

    @Override
    public Func_layout_from_ui vx_copy(Object... vals) {
      Class_layout_from_ui output = new Class_layout_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_layout_from_ui vx_empty() {return e_layout_from_ui;}
    @Override
    public Func_layout_from_ui vx_type() {return t_layout_from_ui;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_layout_from_ui(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layout_from_ui(context, ui);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      return Ui.f_layout_from_ui(context, ui);
    }

  }

  public static final Func_layout_from_ui e_layout_from_ui = new Ui.Class_layout_from_ui();
  public static final Func_layout_from_ui t_layout_from_ui = new Ui.Class_layout_from_ui();

  public static Ui.Type_layout f_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_layoutengine layoutengine = Ui.f_layoutengine_readstate(context);
        return Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
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
  public static interface Func_layout_from_ui_layoutengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layout vx_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine);
  }

  public static class Class_layout_from_ui_layoutengine extends Core.Class_base implements Func_layout_from_ui_layoutengine {

    @Override
    public Func_layout_from_ui_layoutengine vx_new(Object... vals) {
      Class_layout_from_ui_layoutengine output = new Class_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Func_layout_from_ui_layoutengine vx_copy(Object... vals) {
      Class_layout_from_ui_layoutengine output = new Class_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_layout_from_ui_layoutengine vx_empty() {return e_layout_from_ui_layoutengine;}
    @Override
    public Func_layout_from_ui_layoutengine vx_type() {return t_layout_from_ui_layoutengine;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutengine layoutengine = Core.f_any_from_any(Ui.t_layoutengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    @Override
    public Ui.Type_layout vx_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
      return Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
    }

  }

  public static final Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine = new Ui.Class_layout_from_ui_layoutengine();
  public static final Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine = new Ui.Class_layout_from_ui_layoutengine();

  public static Ui.Type_layout f_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        final Ui.Type_layout layoutelse = layoutengine.layoutelse();
        return Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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
  public static interface Func_layout_from_ui_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layout vx_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_layout_from_ui_layoutmap_else extends Core.Class_base implements Func_layout_from_ui_layoutmap_else {

    @Override
    public Func_layout_from_ui_layoutmap_else vx_new(Object... vals) {
      Class_layout_from_ui_layoutmap_else output = new Class_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Func_layout_from_ui_layoutmap_else vx_copy(Object... vals) {
      Class_layout_from_ui_layoutmap_else output = new Class_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_layout_from_ui_layoutmap_else vx_empty() {return e_layout_from_ui_layoutmap_else;}
    @Override
    public Func_layout_from_ui_layoutmap_else vx_type() {return t_layout_from_ui_layoutmap_else;}

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
      return Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
    }

  }

  public static final Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else = new Ui.Class_layout_from_ui_layoutmap_else();
  public static final Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else = new Ui.Class_layout_from_ui_layoutmap_else();

  public static Ui.Type_layout f_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_layout output = Ui.e_layout;
    output = Core.f_let(
      Ui.t_layout,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_style style = ui.style();
        final Ui.Type_layout layout = Ui.f_layout_from_style(style);
        final Core.Type_string layname = layout.name();
        final Ui.Type_layout layout1 = Core.f_any_from_map(Ui.t_layout, layoutmap, layname);
        final Ui.Type_layout layout2 = Core.f_if_1(
          Ui.t_layout,
          Core.f_notempty_1(layout1),
          layout1,
          layoutelse
        );
        return layout2;
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
  public static interface Func_layoutengine_readstate extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_layoutengine vx_layoutengine_readstate(final Core.Type_context context);
  }

  public static class Class_layoutengine_readstate extends Core.Class_base implements Func_layoutengine_readstate {

    @Override
    public Func_layoutengine_readstate vx_new(Object... vals) {
      Class_layoutengine_readstate output = new Class_layoutengine_readstate();
      return output;
    }

    @Override
    public Func_layoutengine_readstate vx_copy(Object... vals) {
      Class_layoutengine_readstate output = new Class_layoutengine_readstate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_layoutengine_readstate vx_empty() {return e_layoutengine_readstate;}
    @Override
    public Func_layoutengine_readstate vx_type() {return t_layoutengine_readstate;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layoutengine_readstate(context);
      return output;
    }

    @Override
    public Ui.Type_layoutengine vx_layoutengine_readstate(final Core.Type_context context) {
      return Ui.f_layoutengine_readstate(context);
    }

  }

  public static final Func_layoutengine_readstate e_layoutengine_readstate = new Ui.Class_layoutengine_readstate();
  public static final Func_layoutengine_readstate t_layoutengine_readstate = new Ui.Class_layoutengine_readstate();

  public static Ui.Type_layoutengine f_layoutengine_readstate(final Core.Type_context context) {
    Ui.Type_layoutengine output = Ui.e_layoutengine;
    output = Core.f_let(
      Ui.t_layoutengine,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uiengine uiengine = Ui.f_uiengine_readstate(context);
        return uiengine.layoutengine();
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
  public static interface Func_layoutmap_from_layoutlist extends Core.Func_any_from_any {
    public Ui.Type_layoutmap vx_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist);
  }

  public static class Class_layoutmap_from_layoutlist extends Core.Class_base implements Func_layoutmap_from_layoutlist {

    @Override
    public Func_layoutmap_from_layoutlist vx_new(Object... vals) {
      Class_layoutmap_from_layoutlist output = new Class_layoutmap_from_layoutlist();
      return output;
    }

    @Override
    public Func_layoutmap_from_layoutlist vx_copy(Object... vals) {
      Class_layoutmap_from_layoutlist output = new Class_layoutmap_from_layoutlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_layout), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_layoutmap_from_layoutlist vx_empty() {return e_layoutmap_from_layoutlist;}
    @Override
    public Func_layoutmap_from_layoutlist vx_type() {return t_layoutmap_from_layoutlist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_layoutlist inputval = (Ui.Type_layoutlist)value;
      Core.Type_any outputval = Ui.f_layoutmap_from_layoutlist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_layoutlist layoutlist = Core.f_any_from_any(Ui.t_layoutlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_layoutmap_from_layoutlist(layoutlist);
      return output;
    }

    @Override
    public Ui.Type_layoutmap vx_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist) {
      return Ui.f_layoutmap_from_layoutlist(layoutlist);
    }

  }

  public static final Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = new Ui.Class_layoutmap_from_layoutlist();
  public static final Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = new Ui.Class_layoutmap_from_layoutlist();

  public static Ui.Type_layoutmap f_layoutmap_from_layoutlist(final Ui.Type_layoutlist layoutlist) {
    Ui.Type_layoutmap output = Ui.e_layoutmap;
    output = Core.f_map_from_list(
      Ui.t_layoutmap,
      layoutlist,
      Core.t_any_from_any.vx_fn_new((layout_any) -> {
        Ui.Type_layout layout = Core.f_any_from_any(Ui.t_layout, layout_any);
        return 
          layout.name();
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
  public static interface Func_stringlist_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_stringlist_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_stringlist_selected_from_ui extends Core.Class_base implements Func_stringlist_selected_from_ui {

    @Override
    public Func_stringlist_selected_from_ui vx_new(Object... vals) {
      Class_stringlist_selected_from_ui output = new Class_stringlist_selected_from_ui();
      return output;
    }

    @Override
    public Func_stringlist_selected_from_ui vx_copy(Object... vals) {
      Class_stringlist_selected_from_ui output = new Class_stringlist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_string), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stringlist_selected_from_ui vx_empty() {return e_stringlist_selected_from_ui;}
    @Override
    public Func_stringlist_selected_from_ui vx_type() {return t_stringlist_selected_from_ui;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_stringlist_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stringlist_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist_selected_from_ui(final Ui.Type_ui ui) {
      return Ui.f_stringlist_selected_from_ui(ui);
    }

  }

  public static final Func_stringlist_selected_from_ui e_stringlist_selected_from_ui = new Ui.Class_stringlist_selected_from_ui();
  public static final Func_stringlist_selected_from_ui t_stringlist_selected_from_ui = new Ui.Class_stringlist_selected_from_ui();

  public static Core.Type_stringlist f_stringlist_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_let(
      Core.t_stringlist,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uimap uimap = ui.uimap();
        final Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(uimap);
        return Core.f_list_from_list_1(
          Core.t_stringlist,
          uilist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
            return 
              Core.f_if_1(
                Core.t_string,
                item.selected(),
                item.uid(),
                Core.vx_new_string("")
              );
          })
        );
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
  public static interface Func_stylemap_from_stylelist extends Core.Func_any_from_any {
    public Ui.Type_stylemap vx_stylemap_from_stylelist(final Ui.Type_stylelist stylelist);
  }

  public static class Class_stylemap_from_stylelist extends Core.Class_base implements Func_stylemap_from_stylelist {

    @Override
    public Func_stylemap_from_stylelist vx_new(Object... vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    @Override
    public Func_stylemap_from_stylelist vx_copy(Object... vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_style), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylemap_from_stylelist vx_empty() {return e_stylemap_from_stylelist;}
    @Override
    public Func_stylemap_from_stylelist vx_type() {return t_stylemap_from_stylelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylelist inputval = (Ui.Type_stylelist)value;
      Core.Type_any outputval = Ui.f_stylemap_from_stylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylelist stylelist = Core.f_any_from_any(Ui.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stylemap_from_stylelist(stylelist);
      return output;
    }

    @Override
    public Ui.Type_stylemap vx_stylemap_from_stylelist(final Ui.Type_stylelist stylelist) {
      return Ui.f_stylemap_from_stylelist(stylelist);
    }

  }

  public static final Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Ui.Class_stylemap_from_stylelist();
  public static final Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Ui.Class_stylemap_from_stylelist();

  public static Ui.Type_stylemap f_stylemap_from_stylelist(final Ui.Type_stylelist stylelist) {
    Ui.Type_stylemap output = Ui.e_stylemap;
    output = Core.f_map_from_list(
      Ui.t_stylemap,
      stylelist,
      Core.t_any_from_any.vx_fn_new((style_any) -> {
        Ui.Type_style style = Core.f_any_from_any(Ui.t_style, style_any);
        return 
          style.name();
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
  public static interface Func_stylesheet_render extends Core.Func_any_from_any {
    public Ui.Type_stylesheet vx_stylesheet_render(final Ui.Type_stylesheet stylesheetui);
  }

  public static class Class_stylesheet_render extends Core.Class_base implements Func_stylesheet_render {

    @Override
    public Func_stylesheet_render vx_new(Object... vals) {
      Class_stylesheet_render output = new Class_stylesheet_render();
      return output;
    }

    @Override
    public Func_stylesheet_render vx_copy(Object... vals) {
      Class_stylesheet_render output = new Class_stylesheet_render();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_stylesheet_render vx_empty() {return e_stylesheet_render;}
    @Override
    public Func_stylesheet_render vx_type() {return t_stylesheet_render;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylesheet inputval = (Ui.Type_stylesheet)value;
      Core.Type_any outputval = Ui.f_stylesheet_render(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylesheet stylesheetui = Core.f_any_from_any(Ui.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_stylesheet_render(stylesheetui);
      return output;
    }

    @Override
    public Ui.Type_stylesheet vx_stylesheet_render(final Ui.Type_stylesheet stylesheetui) {
      return Ui.f_stylesheet_render(stylesheetui);
    }

  }

  public static final Func_stylesheet_render e_stylesheet_render = new Ui.Class_stylesheet_render();
  public static final Func_stylesheet_render t_stylesheet_render = new Ui.Class_stylesheet_render();

  public static Ui.Type_stylesheet f_stylesheet_render(final Ui.Type_stylesheet stylesheetui) {
    Ui.Type_stylesheet output = Ui.e_stylesheet;
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
  public static interface Func_ui_child_from_ui_uid extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid);
  }

  public static class Class_ui_child_from_ui_uid extends Core.Class_base implements Func_ui_child_from_ui_uid {

    @Override
    public Func_ui_child_from_ui_uid vx_new(Object... vals) {
      Class_ui_child_from_ui_uid output = new Class_ui_child_from_ui_uid();
      return output;
    }

    @Override
    public Func_ui_child_from_ui_uid vx_copy(Object... vals) {
      Class_ui_child_from_ui_uid output = new Class_ui_child_from_ui_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_ui_child_from_ui_uid vx_empty() {return e_ui_child_from_ui_uid;}
    @Override
    public Func_ui_child_from_ui_uid vx_type() {return t_ui_child_from_ui_uid;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_child_from_ui_uid(ui, uid);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
      return Ui.f_ui_child_from_ui_uid(ui, uid);
    }

  }

  public static final Func_ui_child_from_ui_uid e_ui_child_from_ui_uid = new Ui.Class_ui_child_from_ui_uid();
  public static final Func_ui_child_from_ui_uid t_ui_child_from_ui_uid = new Ui.Class_ui_child_from_ui_uid();

  public static Ui.Type_ui f_ui_child_from_ui_uid(final Ui.Type_ui ui, final Core.Type_string uid) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uimap childmap = ui.uimap();
        return Core.f_any_from_map(Ui.t_ui, childmap, uid);
      })
    );
    return output;
  }

  /**
   * @function ui_from_from_event
   * Returns (:from event) cast as ui
   * @param  {event} event
   * @return {ui}
   * (func ui-from<-event)
   */
  public static interface Func_ui_from_from_event extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_from_from_event(final Core.Type_context context, final Event.Type_event event);
  }

  public static class Class_ui_from_from_event extends Core.Class_base implements Func_ui_from_from_event {

    @Override
    public Func_ui_from_from_event vx_new(Object... vals) {
      Class_ui_from_from_event output = new Class_ui_from_from_event();
      return output;
    }

    @Override
    public Func_ui_from_from_event vx_copy(Object... vals) {
      Class_ui_from_from_event output = new Class_ui_from_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_ui_from_from_event vx_empty() {return e_ui_from_from_event;}
    @Override
    public Func_ui_from_from_event vx_type() {return t_ui_from_from_event;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_event inputval = (Event.Type_event)value;
      Core.Type_any outputval = Ui.f_ui_from_from_event(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event event = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_from_from_event(context, event);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_from_from_event(final Core.Type_context context, final Event.Type_event event) {
      return Ui.f_ui_from_from_event(context, event);
    }

  }

  public static final Func_ui_from_from_event e_ui_from_from_event = new Ui.Class_ui_from_from_event();
  public static final Func_ui_from_from_event t_ui_from_from_event = new Ui.Class_ui_from_from_event();

  public static Ui.Type_ui f_ui_from_from_event(final Core.Type_context context, final Event.Type_event event) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = event.from();
        return Ui.f_ui_readstate_from_uid(context, uid);
      })
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @return {ui}
   * (func ui-layout<-ui)
   */
  public static interface Func_ui_layout_from_ui extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui);
  }

  public static class Class_ui_layout_from_ui extends Core.Class_base implements Func_ui_layout_from_ui {

    @Override
    public Func_ui_layout_from_ui vx_new(Object... vals) {
      Class_ui_layout_from_ui output = new Class_ui_layout_from_ui();
      return output;
    }

    @Override
    public Func_ui_layout_from_ui vx_copy(Object... vals) {
      Class_ui_layout_from_ui output = new Class_ui_layout_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui", // name
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
    }

    @Override
    public Func_ui_layout_from_ui vx_empty() {return e_ui_layout_from_ui;}
    @Override
    public Func_ui_layout_from_ui vx_type() {return t_ui_layout_from_ui;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_layout_from_ui(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_layout_from_ui(context, ui);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
      return Ui.f_ui_layout_from_ui(context, ui);
    }

  }

  public static final Func_ui_layout_from_ui e_ui_layout_from_ui = new Ui.Class_ui_layout_from_ui();
  public static final Func_ui_layout_from_ui t_ui_layout_from_ui = new Ui.Class_ui_layout_from_ui();

  public static Ui.Type_ui f_ui_layout_from_ui(final Core.Type_context context, final Ui.Type_ui ui) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uiengine uiengine = Ui.f_uiengine_readstate(context);
        return Ui.f_ui_layout_from_ui_uiengine(ui, uiengine);
      })
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_layoutengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {ui}
   * (func ui-layout<-ui-layoutengine)
   */
  public static interface Func_ui_layout_from_ui_layoutengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine);
  }

  public static class Class_ui_layout_from_ui_layoutengine extends Core.Class_base implements Func_ui_layout_from_ui_layoutengine {

    @Override
    public Func_ui_layout_from_ui_layoutengine vx_new(Object... vals) {
      Class_ui_layout_from_ui_layoutengine output = new Class_ui_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Func_ui_layout_from_ui_layoutengine vx_copy(Object... vals) {
      Class_ui_layout_from_ui_layoutengine output = new Class_ui_layout_from_ui_layoutengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutengine", // name
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
    }

    @Override
    public Func_ui_layout_from_ui_layoutengine vx_empty() {return e_ui_layout_from_ui_layoutengine;}
    @Override
    public Func_ui_layout_from_ui_layoutengine vx_type() {return t_ui_layout_from_ui_layoutengine;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutengine layoutengine = Core.f_any_from_any(Ui.t_layoutengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
      return Ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine);
    }

  }

  public static final Func_ui_layout_from_ui_layoutengine e_ui_layout_from_ui_layoutengine = new Ui.Class_ui_layout_from_ui_layoutengine();
  public static final Func_ui_layout_from_ui_layoutengine t_ui_layout_from_ui_layoutengine = new Ui.Class_ui_layout_from_ui_layoutengine();

  public static Ui.Type_ui f_ui_layout_from_ui_layoutengine(final Ui.Type_ui ui, final Ui.Type_layoutengine layoutengine) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        final Ui.Type_layout layoutelse = layoutengine.layoutelse();
        return Ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      })
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_layoutmap_else
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {ui}
   * (func ui-layout<-ui-layoutmap-else)
   */
  public static interface Func_ui_layout_from_ui_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_ui_layout_from_ui_layoutmap_else extends Core.Class_base implements Func_ui_layout_from_ui_layoutmap_else {

    @Override
    public Func_ui_layout_from_ui_layoutmap_else vx_new(Object... vals) {
      Class_ui_layout_from_ui_layoutmap_else output = new Class_ui_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Func_ui_layout_from_ui_layoutmap_else vx_copy(Object... vals) {
      Class_ui_layout_from_ui_layoutmap_else output = new Class_ui_layout_from_ui_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutmap-else", // name
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
    }

    @Override
    public Func_ui_layout_from_ui_layoutmap_else vx_empty() {return e_ui_layout_from_ui_layoutmap_else;}
    @Override
    public Func_ui_layout_from_ui_layoutmap_else vx_type() {return t_ui_layout_from_ui_layoutmap_else;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutmap layoutmap = Core.f_any_from_any(Ui.t_layoutmap, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_layout layoutelse = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
      return Ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
    }

  }

  public static final Func_ui_layout_from_ui_layoutmap_else e_ui_layout_from_ui_layoutmap_else = new Ui.Class_ui_layout_from_ui_layoutmap_else();
  public static final Func_ui_layout_from_ui_layoutmap_else t_ui_layout_from_ui_layoutmap_else = new Ui.Class_ui_layout_from_ui_layoutmap_else();

  public static Ui.Type_ui f_ui_layout_from_ui_layoutmap_else(final Ui.Type_ui ui, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uimap uimap = ui.uimap();
        final Ui.Type_layout layout1 = Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        final Ui.Type_uimap uimap2 = Ui.f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
        return Core.f_copy(
          ui,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":layout"),
            layout1,
            Core.vx_new_string(":uimap"),
            uimap2
          )
        );
      })
    );
    return output;
  }

  /**
   * @function ui_layout_from_ui_uiengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {uiengine} uiengine
   * @return {ui}
   * (func ui-layout<-ui-uiengine)
   */
  public static interface Func_ui_layout_from_ui_uiengine extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_layout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine);
  }

  public static class Class_ui_layout_from_ui_uiengine extends Core.Class_base implements Func_ui_layout_from_ui_uiengine {

    @Override
    public Func_ui_layout_from_ui_uiengine vx_new(Object... vals) {
      Class_ui_layout_from_ui_uiengine output = new Class_ui_layout_from_ui_uiengine();
      return output;
    }

    @Override
    public Func_ui_layout_from_ui_uiengine vx_copy(Object... vals) {
      Class_ui_layout_from_ui_uiengine output = new Class_ui_layout_from_ui_uiengine();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-uiengine", // name
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
    }

    @Override
    public Func_ui_layout_from_ui_uiengine vx_empty() {return e_ui_layout_from_ui_uiengine;}
    @Override
    public Func_ui_layout_from_ui_uiengine vx_type() {return t_ui_layout_from_ui_uiengine;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_layout_from_ui_uiengine(ui, uiengine);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_layout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine) {
      return Ui.f_ui_layout_from_ui_uiengine(ui, uiengine);
    }

  }

  public static final Func_ui_layout_from_ui_uiengine e_ui_layout_from_ui_uiengine = new Ui.Class_ui_layout_from_ui_uiengine();
  public static final Func_ui_layout_from_ui_uiengine t_ui_layout_from_ui_uiengine = new Ui.Class_ui_layout_from_ui_uiengine();

  public static Ui.Type_ui f_ui_layout_from_ui_uiengine(final Ui.Type_ui ui, final Ui.Type_uiengine uiengine) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        return Ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine);
      })
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
  public static interface Func_ui_readstate_from_uid extends Core.Func_any_from_any_context {
    public Ui.Type_ui vx_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid);
  }

  public static class Class_ui_readstate_from_uid extends Core.Class_base implements Func_ui_readstate_from_uid {

    @Override
    public Func_ui_readstate_from_uid vx_new(Object... vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Func_ui_readstate_from_uid vx_copy(Object... vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_ui_readstate_from_uid vx_empty() {return e_ui_readstate_from_uid;}
    @Override
    public Func_ui_readstate_from_uid vx_type() {return t_ui_readstate_from_uid;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Ui.f_ui_readstate_from_uid(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_readstate_from_uid(context, uid);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid) {
      return Ui.f_ui_readstate_from_uid(context, uid);
    }

  }

  public static final Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Ui.Class_ui_readstate_from_uid();
  public static final Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Ui.Class_ui_readstate_from_uid();

  public static Ui.Type_ui f_ui_readstate_from_uid(final Core.Type_context context, final Core.Type_string uid) {
    Ui.Type_ui output = Ui.e_ui;
    output = State.f_any_readstate_from_mapname_name(Ui.t_ui, context, Core.vx_new_string(":uimap"), uid);
    return output;
  }

  /**
   * @function ui_render
   * @param  {ui} uiarg
   * @return {ui}
   * (func ui-render)
   */
  public static interface Func_ui_render extends Core.Func_any_from_any {
    public Ui.Type_ui vx_ui_render(final Ui.Type_ui uiarg);
  }

  public static class Class_ui_render extends Core.Class_base implements Func_ui_render {

    @Override
    public Func_ui_render vx_new(Object... vals) {
      Class_ui_render output = new Class_ui_render();
      return output;
    }

    @Override
    public Func_ui_render vx_copy(Object... vals) {
      Class_ui_render output = new Class_ui_render();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render", // name
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
    }

    @Override
    public Func_ui_render vx_empty() {return e_ui_render;}
    @Override
    public Func_ui_render vx_type() {return t_ui_render;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_render(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_render(uiarg);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render(final Ui.Type_ui uiarg) {
      return Ui.f_ui_render(uiarg);
    }

  }

  public static final Func_ui_render e_ui_render = new Ui.Class_ui_render();
  public static final Func_ui_render t_ui_render = new Ui.Class_ui_render();

  public static Ui.Type_ui f_ui_render(final Ui.Type_ui uiarg) {
    Ui.Type_ui output = Ui.e_ui;
    output = Ui.f_ui_render_from_ui_orig_parent(
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
   * @function ui_render_from_fn_render_ui_orig_parent
   * Returns a rendered ui
   * @param  {ui-render<-ui-orig-parent} fn-render
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render<-fn-render-ui-orig-parent)
   */
  public static interface Func_ui_render_from_fn_render_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_render_from_fn_render_ui_orig_parent(final Ui.Func_ui_render_from_ui_orig_parent fn_render, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_render_from_fn_render_ui_orig_parent extends Core.Class_base implements Func_ui_render_from_fn_render_ui_orig_parent {

    @Override
    public Func_ui_render_from_fn_render_ui_orig_parent vx_new(Object... vals) {
      Class_ui_render_from_fn_render_ui_orig_parent output = new Class_ui_render_from_fn_render_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_render_from_fn_render_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_render_from_fn_render_ui_orig_parent output = new Class_ui_render_from_fn_render_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-fn-render-ui-orig-parent", // name
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
    }

    @Override
    public Func_ui_render_from_fn_render_ui_orig_parent vx_empty() {return e_ui_render_from_fn_render_ui_orig_parent;}
    @Override
    public Func_ui_render_from_fn_render_ui_orig_parent vx_type() {return t_ui_render_from_fn_render_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Func_ui_render_from_ui_orig_parent fn_render = Core.f_any_from_any(Ui.t_ui_render_from_ui_orig_parent, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(3)));
      output = Ui.f_ui_render_from_fn_render_ui_orig_parent(fn_render, ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render_from_fn_render_ui_orig_parent(final Ui.Func_ui_render_from_ui_orig_parent fn_render, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Ui.f_ui_render_from_fn_render_ui_orig_parent(fn_render, ui, orig, parent);
    }

  }

  public static final Func_ui_render_from_fn_render_ui_orig_parent e_ui_render_from_fn_render_ui_orig_parent = new Ui.Class_ui_render_from_fn_render_ui_orig_parent();
  public static final Func_ui_render_from_fn_render_ui_orig_parent t_ui_render_from_fn_render_ui_orig_parent = new Ui.Class_ui_render_from_fn_render_ui_orig_parent();

  public static Ui.Type_ui f_ui_render_from_fn_render_ui_orig_parent(final Ui.Func_ui_render_from_ui_orig_parent fn_render, final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.vx_any_from_func(Ui.t_ui, fn_render, ui, orig, parent);
    return output;
  }

  /**
   * @function ui_render_from_ui_orig_parent
   * Returns a rendered object from a UI Element.
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render<-ui-orig-parent)
   */
  public static interface Func_ui_render_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_render_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_render_from_ui_orig_parent extends Core.Class_base implements Func_ui_render_from_ui_orig_parent {

    @Override
    public Func_ui_render_from_ui_orig_parent vx_new(Object... vals) {
      Class_ui_render_from_ui_orig_parent output = new Class_ui_render_from_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_render_from_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_render_from_ui_orig_parent output = new Class_ui_render_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-ui-orig-parent", // name
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
    }

    @Override
    public Func_ui_render_from_ui_orig_parent vx_empty() {return e_ui_render_from_ui_orig_parent;}
    @Override
    public Func_ui_render_from_ui_orig_parent vx_type() {return t_ui_render_from_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_ui_render_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Ui.f_ui_render_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static final Func_ui_render_from_ui_orig_parent e_ui_render_from_ui_orig_parent = new Ui.Class_ui_render_from_ui_orig_parent();
  public static final Func_ui_render_from_ui_orig_parent t_ui_render_from_ui_orig_parent = new Ui.Class_ui_render_from_ui_orig_parent();

  public static Ui.Type_ui f_ui_render_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_if_2(
      Ui.t_ui,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eqeq(ui, orig);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return orig;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Ui.t_ui,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Ui.Type_uimap uimap = ui.uimap();
                final Ui.Type_layout layout = ui.layout();
                final Ui.Type_ui uiout = Ui.f_ui_from_layout_ui_orig_parent(layout, ui, orig, parent);
                return uiout;
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function ui_selected_from_ui
   * Returns the ui of the first ui with selected=true
   * @param  {ui} ui
   * @return {ui}
   * (func ui-selected<-ui)
   */
  public static interface Func_ui_selected_from_ui extends Core.Func_any_from_any {
    public Ui.Type_ui vx_ui_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_ui_selected_from_ui extends Core.Class_base implements Func_ui_selected_from_ui {

    @Override
    public Func_ui_selected_from_ui vx_new(Object... vals) {
      Class_ui_selected_from_ui output = new Class_ui_selected_from_ui();
      return output;
    }

    @Override
    public Func_ui_selected_from_ui vx_copy(Object... vals) {
      Class_ui_selected_from_ui output = new Class_ui_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_ui_selected_from_ui vx_empty() {return e_ui_selected_from_ui;}
    @Override
    public Func_ui_selected_from_ui vx_type() {return t_ui_selected_from_ui;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_ui_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_ui_selected_from_ui(ui);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_selected_from_ui(final Ui.Type_ui ui) {
      return Ui.f_ui_selected_from_ui(ui);
    }

  }

  public static final Func_ui_selected_from_ui e_ui_selected_from_ui = new Ui.Class_ui_selected_from_ui();
  public static final Func_ui_selected_from_ui t_ui_selected_from_ui = new Ui.Class_ui_selected_from_ui();

  public static Ui.Type_ui f_ui_selected_from_ui(final Ui.Type_ui ui) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uilist uilist = Ui.f_uilist_selected_from_ui(ui);
        return Core.f_first_from_list(Ui.t_ui, uilist);
      })
    );
    return output;
  }

  /**
   * @function ui_writechild_from_ui_child
   * Returns the given ui with the child added to uimap
   * @param  {ui} ui
   * @param  {ui} child
   * @return {ui}
   * (func ui-writechild<-ui-child)
   */
  public static interface Func_ui_writechild_from_ui_child extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_writechild_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child);
  }

  public static class Class_ui_writechild_from_ui_child extends Core.Class_base implements Func_ui_writechild_from_ui_child {

    @Override
    public Func_ui_writechild_from_ui_child vx_new(Object... vals) {
      Class_ui_writechild_from_ui_child output = new Class_ui_writechild_from_ui_child();
      return output;
    }

    @Override
    public Func_ui_writechild_from_ui_child vx_copy(Object... vals) {
      Class_ui_writechild_from_ui_child output = new Class_ui_writechild_from_ui_child();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-writechild<-ui-child", // name
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
    }

    @Override
    public Func_ui_writechild_from_ui_child vx_empty() {return e_ui_writechild_from_ui_child;}
    @Override
    public Func_ui_writechild_from_ui_child vx_type() {return t_ui_writechild_from_ui_child;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui child = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_writechild_from_ui_child(ui, child);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_writechild_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child) {
      return Ui.f_ui_writechild_from_ui_child(ui, child);
    }

  }

  public static final Func_ui_writechild_from_ui_child e_ui_writechild_from_ui_child = new Ui.Class_ui_writechild_from_ui_child();
  public static final Func_ui_writechild_from_ui_child t_ui_writechild_from_ui_child = new Ui.Class_ui_writechild_from_ui_child();

  public static Ui.Type_ui f_ui_writechild_from_ui_child(final Ui.Type_ui ui, final Ui.Type_ui child) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string childid = child.uid();
        final Ui.Type_uimap uimap = ui.uimap();
        final Core.Type_boolean write = Core.f_boolean_write_from_map_name_value(uimap, childid, child);
        return ui;
      })
    );
    return output;
  }

  /**
   * @function ui_writechildmap_from_ui_childmap
   * Returns the given ui with the members of childmap added to uimap
   * @param  {ui} ui
   * @param  {uimap} childmap
   * @return {ui}
   * (func ui-writechildmap<-ui-childmap)
   */
  public static interface Func_ui_writechildmap_from_ui_childmap extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_writechildmap_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap);
  }

  public static class Class_ui_writechildmap_from_ui_childmap extends Core.Class_base implements Func_ui_writechildmap_from_ui_childmap {

    @Override
    public Func_ui_writechildmap_from_ui_childmap vx_new(Object... vals) {
      Class_ui_writechildmap_from_ui_childmap output = new Class_ui_writechildmap_from_ui_childmap();
      return output;
    }

    @Override
    public Func_ui_writechildmap_from_ui_childmap vx_copy(Object... vals) {
      Class_ui_writechildmap_from_ui_childmap output = new Class_ui_writechildmap_from_ui_childmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-writechildmap<-ui-childmap", // name
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
    }

    @Override
    public Func_ui_writechildmap_from_ui_childmap vx_empty() {return e_ui_writechildmap_from_ui_childmap;}
    @Override
    public Func_ui_writechildmap_from_ui_childmap vx_type() {return t_ui_writechildmap_from_ui_childmap;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uimap childmap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_ui_writechildmap_from_ui_childmap(ui, childmap);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_writechildmap_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap) {
      return Ui.f_ui_writechildmap_from_ui_childmap(ui, childmap);
    }

  }

  public static final Func_ui_writechildmap_from_ui_childmap e_ui_writechildmap_from_ui_childmap = new Ui.Class_ui_writechildmap_from_ui_childmap();
  public static final Func_ui_writechildmap_from_ui_childmap t_ui_writechildmap_from_ui_childmap = new Ui.Class_ui_writechildmap_from_ui_childmap();

  public static Ui.Type_ui f_ui_writechildmap_from_ui_childmap(final Ui.Type_ui ui, final Ui.Type_uimap childmap) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uimap workmap = Core.f_map_from_map_1(
          Ui.t_uimap,
          childmap,
          Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Ui.Type_ui value = Core.f_any_from_any(Ui.t_ui, value_any);
            return 
                Ui.f_ui_writechild_from_ui_child(ui, value);
          })
        );
        return ui;
      })
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
  public static interface Func_ui_from_layout_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_from_layout_ui_orig_parent(final Ui.Type_layout layout, final Ui.Type_ui uiarg, final Ui.Type_ui uiorig, final Ui.Type_ui parent);
  }

  public static class Class_ui_from_layout_ui_orig_parent extends Core.Class_base implements Func_ui_from_layout_ui_orig_parent {

    @Override
    public Func_ui_from_layout_ui_orig_parent vx_new(Object... vals) {
      Class_ui_from_layout_ui_orig_parent output = new Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_from_layout_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_from_layout_ui_orig_parent output = new Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_ui_from_layout_ui_orig_parent vx_empty() {return e_ui_from_layout_ui_orig_parent;}
    @Override
    public Func_ui_from_layout_ui_orig_parent vx_type() {return t_ui_from_layout_ui_orig_parent;}

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
      return Ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
    }

  }

  public static final Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent = new Ui.Class_ui_from_layout_ui_orig_parent();
  public static final Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent = new Ui.Class_ui_from_layout_ui_orig_parent();

  public static Ui.Type_ui f_ui_from_layout_ui_orig_parent(final Ui.Type_layout layout, final Ui.Type_ui uiarg, final Ui.Type_ui uiorig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Func_ui_render_from_ui_orig_parent fn_layout = layout.fn_layout();
        final Ui.Type_ui uichg = Core.vx_any_from_func(Ui.t_ui, fn_layout, uiarg, uiorig, parent);
        return uichg;
      })
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
  public static interface Func_uid_selected_from_ui extends Core.Func_any_from_any {
    public Core.Type_string vx_uid_selected_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_uid_selected_from_ui extends Core.Class_base implements Func_uid_selected_from_ui {

    @Override
    public Func_uid_selected_from_ui vx_new(Object... vals) {
      Class_uid_selected_from_ui output = new Class_uid_selected_from_ui();
      return output;
    }

    @Override
    public Func_uid_selected_from_ui vx_copy(Object... vals) {
      Class_uid_selected_from_ui output = new Class_uid_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_uid_selected_from_ui vx_empty() {return e_uid_selected_from_ui;}
    @Override
    public Func_uid_selected_from_ui vx_type() {return t_uid_selected_from_ui;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_uid_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uid_selected_from_ui(ui);
      return output;
    }

    @Override
    public Core.Type_string vx_uid_selected_from_ui(final Ui.Type_ui ui) {
      return Ui.f_uid_selected_from_ui(ui);
    }

  }

  public static final Func_uid_selected_from_ui e_uid_selected_from_ui = new Ui.Class_uid_selected_from_ui();
  public static final Func_uid_selected_from_ui t_uid_selected_from_ui = new Ui.Class_uid_selected_from_ui();

  public static Core.Type_string f_uid_selected_from_ui(final Ui.Type_ui ui) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_stringlist uidlist = Ui.f_stringlist_selected_from_ui(ui);
        return Core.f_first_from_list(Core.t_string, uidlist);
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
  public static interface Func_uiengine_readstate extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uiengine vx_uiengine_readstate(final Core.Type_context context);
  }

  public static class Class_uiengine_readstate extends Core.Class_base implements Func_uiengine_readstate {

    @Override
    public Func_uiengine_readstate vx_new(Object... vals) {
      Class_uiengine_readstate output = new Class_uiengine_readstate();
      return output;
    }

    @Override
    public Func_uiengine_readstate vx_copy(Object... vals) {
      Class_uiengine_readstate output = new Class_uiengine_readstate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_uiengine_readstate vx_empty() {return e_uiengine_readstate;}
    @Override
    public Func_uiengine_readstate vx_type() {return t_uiengine_readstate;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uiengine_readstate(context);
      return output;
    }

    @Override
    public Ui.Type_uiengine vx_uiengine_readstate(final Core.Type_context context) {
      return Ui.f_uiengine_readstate(context);
    }

  }

  public static final Func_uiengine_readstate e_uiengine_readstate = new Ui.Class_uiengine_readstate();
  public static final Func_uiengine_readstate t_uiengine_readstate = new Ui.Class_uiengine_readstate();

  public static Ui.Type_uiengine f_uiengine_readstate(final Core.Type_context context) {
    Ui.Type_uiengine output = Ui.e_uiengine;
    output = State.f_any_readstate_from_name(Ui.t_uiengine, context, Core.vx_new_string(":uiengine"));
    return output;
  }

  /**
   * @function uiengine_render
   * Returns a fully rendered ui for a given engine.
   * @param  {uiengine} uiengine
   * @return {uiengine}
   * (func uiengine-render)
   */
  public static interface Func_uiengine_render extends Core.Func_any_from_any_context {
    public Ui.Type_uiengine vx_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine);
  }

  public static class Class_uiengine_render extends Core.Class_base implements Func_uiengine_render {

    @Override
    public Func_uiengine_render vx_new(Object... vals) {
      Class_uiengine_render output = new Class_uiengine_render();
      return output;
    }

    @Override
    public Func_uiengine_render vx_copy(Object... vals) {
      Class_uiengine_render output = new Class_uiengine_render();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_uiengine_render vx_empty() {return e_uiengine_render;}
    @Override
    public Func_uiengine_render vx_type() {return t_uiengine_render;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uiengine inputval = (Ui.Type_uiengine)value;
      Core.Type_any outputval = Ui.f_uiengine_render(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_uiengine uiengine = Core.f_any_from_any(Ui.t_uiengine, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uiengine_render(context, uiengine);
      return output;
    }

    @Override
    public Ui.Type_uiengine vx_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
      return Ui.f_uiengine_render(context, uiengine);
    }

  }

  public static final Func_uiengine_render e_uiengine_render = new Ui.Class_uiengine_render();
  public static final Func_uiengine_render t_uiengine_render = new Ui.Class_uiengine_render();

  public static Ui.Type_uiengine f_uiengine_render(final Core.Type_context context, final Ui.Type_uiengine uiengine) {
    Ui.Type_uiengine output = Ui.e_uiengine;
    output = Core.f_let(
      Ui.t_uiengine,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_stylesheet stylesheet = uiengine.stylesheet();
        final Ui.Type_ui ui = uiengine.ui();
        final Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        final Ui.Func_stylesheet_render stylesheetrender = layoutengine.stylesheetrender();
        final Ui.Type_stylesheet stylesheetrend = Core.vx_any_from_func(Ui.t_stylesheet, stylesheetrender, stylesheet);
        final Ui.Type_ui uirenderer = Ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine);
        final Ui.Type_ui uirendered = Ui.f_ui_render(uirenderer);
        return Core.f_copy(
          uiengine,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":ui"),
            uirendered
          )
        );
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
  public static interface Func_uilist_selected_from_ui extends Core.Func_any_from_any {
    public Ui.Type_uilist vx_uilist_selected_from_ui(final Ui.Type_ui uiarg);
  }

  public static class Class_uilist_selected_from_ui extends Core.Class_base implements Func_uilist_selected_from_ui {

    @Override
    public Func_uilist_selected_from_ui vx_new(Object... vals) {
      Class_uilist_selected_from_ui output = new Class_uilist_selected_from_ui();
      return output;
    }

    @Override
    public Func_uilist_selected_from_ui vx_copy(Object... vals) {
      Class_uilist_selected_from_ui output = new Class_uilist_selected_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uilist_selected_from_ui vx_empty() {return e_uilist_selected_from_ui;}
    @Override
    public Func_uilist_selected_from_ui vx_type() {return t_uilist_selected_from_ui;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Ui.f_uilist_selected_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui uiarg = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uilist_selected_from_ui(uiarg);
      return output;
    }

    @Override
    public Ui.Type_uilist vx_uilist_selected_from_ui(final Ui.Type_ui uiarg) {
      return Ui.f_uilist_selected_from_ui(uiarg);
    }

  }

  public static final Func_uilist_selected_from_ui e_uilist_selected_from_ui = new Ui.Class_uilist_selected_from_ui();
  public static final Func_uilist_selected_from_ui t_uilist_selected_from_ui = new Ui.Class_uilist_selected_from_ui();

  public static Ui.Type_uilist f_uilist_selected_from_ui(final Ui.Type_ui uiarg) {
    Ui.Type_uilist output = Ui.e_uilist;
    output = Core.f_let(
      Ui.t_uilist,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_uimap uimap = uiarg.uimap();
        final Ui.Type_uilist uilist = Ui.f_uilist_from_uimap(uimap);
        return Core.f_list_from_list_1(
          Ui.t_uilist,
          uilist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
            return 
              Core.f_if(
                Ui.t_ui,
                item.selected(),
                item
              );
          })
        );
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
  public static interface Func_uilist_from_uimap extends Core.Func_any_from_any {
    public Ui.Type_uilist vx_uilist_from_uimap(final Ui.Type_uimap uimap);
  }

  public static class Class_uilist_from_uimap extends Core.Class_base implements Func_uilist_from_uimap {

    @Override
    public Func_uilist_from_uimap vx_new(Object... vals) {
      Class_uilist_from_uimap output = new Class_uilist_from_uimap();
      return output;
    }

    @Override
    public Func_uilist_from_uimap vx_copy(Object... vals) {
      Class_uilist_from_uimap output = new Class_uilist_from_uimap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uilist_from_uimap vx_empty() {return e_uilist_from_uimap;}
    @Override
    public Func_uilist_from_uimap vx_type() {return t_uilist_from_uimap;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uimap inputval = (Ui.Type_uimap)value;
      Core.Type_any outputval = Ui.f_uilist_from_uimap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uilist_from_uimap(uimap);
      return output;
    }

    @Override
    public Ui.Type_uilist vx_uilist_from_uimap(final Ui.Type_uimap uimap) {
      return Ui.f_uilist_from_uimap(uimap);
    }

  }

  public static final Func_uilist_from_uimap e_uilist_from_uimap = new Ui.Class_uilist_from_uimap();
  public static final Func_uilist_from_uimap t_uilist_from_uimap = new Ui.Class_uilist_from_uimap();

  public static Ui.Type_uilist f_uilist_from_uimap(final Ui.Type_uimap uimap) {
    Ui.Type_uilist output = Ui.e_uilist;
    output = Core.f_list_from_map_1(
      Ui.t_uilist,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, item_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui item = Core.f_any_from_any(Ui.t_ui, item_any);
        return item;
      })
    );
    return output;
  }

  /**
   * @function uimap_layout_from_uimap_layoutmap_else
   * Returns a uimap with a renderer added to each ui.
   * @param  {uimap} uimap
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {uimap}
   * (func uimap-layout<-uimap-layoutmap-else)
   */
  public static interface Func_uimap_layout_from_uimap_layoutmap_else extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_layout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse);
  }

  public static class Class_uimap_layout_from_uimap_layoutmap_else extends Core.Class_base implements Func_uimap_layout_from_uimap_layoutmap_else {

    @Override
    public Func_uimap_layout_from_uimap_layoutmap_else vx_new(Object... vals) {
      Class_uimap_layout_from_uimap_layoutmap_else output = new Class_uimap_layout_from_uimap_layoutmap_else();
      return output;
    }

    @Override
    public Func_uimap_layout_from_uimap_layoutmap_else vx_copy(Object... vals) {
      Class_uimap_layout_from_uimap_layoutmap_else output = new Class_uimap_layout_from_uimap_layoutmap_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-layoutmap-else", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uimap_layout_from_uimap_layoutmap_else vx_empty() {return e_uimap_layout_from_uimap_layoutmap_else;}
    @Override
    public Func_uimap_layout_from_uimap_layoutmap_else vx_type() {return t_uimap_layout_from_uimap_layoutmap_else;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_layoutmap layoutmap = Core.f_any_from_any(Ui.t_layoutmap, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_layout layoutelse = Core.f_any_from_any(Ui.t_layout, arglist.vx_any(Core.vx_new_int(2)));
      output = Ui.f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_layout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
      return Ui.f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
    }

  }

  public static final Func_uimap_layout_from_uimap_layoutmap_else e_uimap_layout_from_uimap_layoutmap_else = new Ui.Class_uimap_layout_from_uimap_layoutmap_else();
  public static final Func_uimap_layout_from_uimap_layoutmap_else t_uimap_layout_from_uimap_layoutmap_else = new Ui.Class_uimap_layout_from_uimap_layoutmap_else();

  public static Ui.Type_uimap f_uimap_layout_from_uimap_layoutmap_else(final Ui.Type_uimap uimap, final Ui.Type_layoutmap layoutmap, final Ui.Type_layout layoutelse) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_map_1(
      Ui.t_uimap,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, ui_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, ui_any);
        return 
          Ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      })
    );
    return output;
  }

  /**
   * @function uimap_render_from_uimap_parent
   * Renders a uimap and returns a rendered uimap.
   * @param  {uimap} uimap
   * @param  {ui} parent
   * @return {uimap}
   * (func uimap-render<-uimap-parent)
   */
  public static interface Func_uimap_render_from_uimap_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_render_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent);
  }

  public static class Class_uimap_render_from_uimap_parent extends Core.Class_base implements Func_uimap_render_from_uimap_parent {

    @Override
    public Func_uimap_render_from_uimap_parent vx_new(Object... vals) {
      Class_uimap_render_from_uimap_parent output = new Class_uimap_render_from_uimap_parent();
      return output;
    }

    @Override
    public Func_uimap_render_from_uimap_parent vx_copy(Object... vals) {
      Class_uimap_render_from_uimap_parent output = new Class_uimap_render_from_uimap_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-render<-uimap-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uimap_render_from_uimap_parent vx_empty() {return e_uimap_render_from_uimap_parent;}
    @Override
    public Func_uimap_render_from_uimap_parent vx_type() {return t_uimap_render_from_uimap_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_uimap_render_from_uimap_parent(uimap, parent);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_render_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent) {
      return Ui.f_uimap_render_from_uimap_parent(uimap, parent);
    }

  }

  public static final Func_uimap_render_from_uimap_parent e_uimap_render_from_uimap_parent = new Ui.Class_uimap_render_from_uimap_parent();
  public static final Func_uimap_render_from_uimap_parent t_uimap_render_from_uimap_parent = new Ui.Class_uimap_render_from_uimap_parent();

  public static Ui.Type_uimap f_uimap_render_from_uimap_parent(final Ui.Type_uimap uimap, final Ui.Type_ui parent) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_map_1(
      Ui.t_uimap,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, val_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui val = Core.f_any_from_any(Ui.t_ui, val_any);
        return 
          Ui.f_ui_render_from_ui_orig_parent(
            val,
            Core.f_empty(
              Ui.t_ui
            ),
            parent
          );
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
  public static interface Func_uimap_from_uilist extends Core.Func_any_from_any {
    public Ui.Type_uimap vx_uimap_from_uilist(final Ui.Type_uilist uilist);
  }

  public static class Class_uimap_from_uilist extends Core.Class_base implements Func_uimap_from_uilist {

    @Override
    public Func_uimap_from_uilist vx_new(Object... vals) {
      Class_uimap_from_uilist output = new Class_uimap_from_uilist();
      return output;
    }

    @Override
    public Func_uimap_from_uilist vx_copy(Object... vals) {
      Class_uimap_from_uilist output = new Class_uimap_from_uilist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uimap_from_uilist vx_empty() {return e_uimap_from_uilist;}
    @Override
    public Func_uimap_from_uilist vx_type() {return t_uimap_from_uilist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uilist inputval = (Ui.Type_uilist)value;
      Core.Type_any outputval = Ui.f_uimap_from_uilist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uilist uilist = Core.f_any_from_any(Ui.t_uilist, arglist.vx_any(Core.vx_new_int(0)));
      output = Ui.f_uimap_from_uilist(uilist);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_from_uilist(final Ui.Type_uilist uilist) {
      return Ui.f_uimap_from_uilist(uilist);
    }

  }

  public static final Func_uimap_from_uilist e_uimap_from_uilist = new Ui.Class_uimap_from_uilist();
  public static final Func_uimap_from_uilist t_uimap_from_uilist = new Ui.Class_uimap_from_uilist();

  public static Ui.Type_uimap f_uimap_from_uilist(final Ui.Type_uilist uilist) {
    Ui.Type_uimap output = Ui.e_uimap;
    output = Core.f_map_from_list(
      Ui.t_uimap,
      uilist,
      Core.t_any_from_any.vx_fn_new((ui_any) -> {
        Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, ui_any);
        return 
          ui.uid();
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
  public static interface Func_uimap_from_uimap_data extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_uimap vx_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data);
  }

  public static class Class_uimap_from_uimap_data extends Core.Class_base implements Func_uimap_from_uimap_data {

    @Override
    public Func_uimap_from_uimap_data vx_new(Object... vals) {
      Class_uimap_from_uimap_data output = new Class_uimap_from_uimap_data();
      return output;
    }

    @Override
    public Func_uimap_from_uimap_data vx_copy(Object... vals) {
      Class_uimap_from_uimap_data output = new Class_uimap_from_uimap_data();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Ui.t_ui), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_uimap_from_uimap_data vx_empty() {return e_uimap_from_uimap_data;}
    @Override
    public Func_uimap_from_uimap_data vx_type() {return t_uimap_from_uimap_data;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any data = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Ui.f_uimap_from_uimap_data(uimap, data);
      return output;
    }

    @Override
    public Ui.Type_uimap vx_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data) {
      return Ui.f_uimap_from_uimap_data(uimap, data);
    }

  }

  public static final Func_uimap_from_uimap_data e_uimap_from_uimap_data = new Ui.Class_uimap_from_uimap_data();
  public static final Func_uimap_from_uimap_data t_uimap_from_uimap_data = new Ui.Class_uimap_from_uimap_data();

  public static Ui.Type_uimap f_uimap_from_uimap_data(final Ui.Type_uimap uimap, final Core.Type_any data) {
    Ui.Type_uimap output = Ui.e_uimap;
    return output;
  }


  static {
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
    Const_styletype_custom.const_new(c_styletype_custom);
    Const_styletype_shared.const_new(c_styletype_shared);
    Const_styletype_system.const_new(c_styletype_system);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("bounds", Ui.t_bounds);
    maptype.put("cursor", Ui.t_cursor);
    maptype.put("cursor-pointer", Ui.t_cursor_pointer);
    maptype.put("font", Ui.t_font);
    maptype.put("fontface", Ui.t_fontface);
    maptype.put("fontfacelist", Ui.t_fontfacelist);
    maptype.put("fontfacemap", Ui.t_fontfacemap);
    maptype.put("fontmap", Ui.t_fontmap);
    maptype.put("fontstyle", Ui.t_fontstyle);
    maptype.put("fontstylemap", Ui.t_fontstylemap);
    maptype.put("layout", Ui.t_layout);
    maptype.put("layoutengine", Ui.t_layoutengine);
    maptype.put("layoutlist", Ui.t_layoutlist);
    maptype.put("layoutmap", Ui.t_layoutmap);
    maptype.put("pin", Ui.t_pin);
    maptype.put("point", Ui.t_point);
    maptype.put("pointstyle", Ui.t_pointstyle);
    maptype.put("style", Ui.t_style);
    maptype.put("stylelist", Ui.t_stylelist);
    maptype.put("stylemap", Ui.t_stylemap);
    maptype.put("stylesheet", Ui.t_stylesheet);
    maptype.put("styletype", Ui.t_styletype);
    maptype.put("ui", Ui.t_ui);
    maptype.put("uiengine", Ui.t_uiengine);
    maptype.put("uilist", Ui.t_uilist);
    maptype.put("uimap", Ui.t_uimap);
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
    mapconst.put("styletype-custom", Ui.c_styletype_custom);
    mapconst.put("styletype-shared", Ui.c_styletype_shared);
    mapconst.put("styletype-system", Ui.c_styletype_system);
    mapfunc.put("boolean-writestate<-ui", Ui.t_boolean_writestate_from_ui);
    mapfunc.put("boolean-writestate<-uiengine", Ui.t_boolean_writestate_from_uiengine);
    mapfunc.put("fontfacemap<-fontfacelist", Ui.t_fontfacemap_from_fontfacelist);
    mapfunc.put("layout<-style", Ui.t_layout_from_style);
    mapfunc.put("layout<-ui", Ui.t_layout_from_ui);
    mapfunc.put("layout<-ui-layoutengine", Ui.t_layout_from_ui_layoutengine);
    mapfunc.put("layout<-ui-layoutmap-else", Ui.t_layout_from_ui_layoutmap_else);
    mapfunc.put("layoutengine-readstate", Ui.t_layoutengine_readstate);
    mapfunc.put("layoutmap<-layoutlist", Ui.t_layoutmap_from_layoutlist);
    mapfunc.put("stringlist-selected<-ui", Ui.t_stringlist_selected_from_ui);
    mapfunc.put("stylemap<-stylelist", Ui.t_stylemap_from_stylelist);
    mapfunc.put("stylesheet-render", Ui.t_stylesheet_render);
    mapfunc.put("ui-child<-ui-uid", Ui.t_ui_child_from_ui_uid);
    mapfunc.put("ui-from<-event", Ui.t_ui_from_from_event);
    mapfunc.put("ui-layout<-ui", Ui.t_ui_layout_from_ui);
    mapfunc.put("ui-layout<-ui-layoutengine", Ui.t_ui_layout_from_ui_layoutengine);
    mapfunc.put("ui-layout<-ui-layoutmap-else", Ui.t_ui_layout_from_ui_layoutmap_else);
    mapfunc.put("ui-layout<-ui-uiengine", Ui.t_ui_layout_from_ui_uiengine);
    mapfunc.put("ui-readstate<-uid", Ui.t_ui_readstate_from_uid);
    mapfunc.put("ui-render", Ui.t_ui_render);
    mapfunc.put("ui-render<-fn-render-ui-orig-parent", Ui.t_ui_render_from_fn_render_ui_orig_parent);
    mapfunc.put("ui-render<-ui-orig-parent", Ui.t_ui_render_from_ui_orig_parent);
    mapfunc.put("ui-selected<-ui", Ui.t_ui_selected_from_ui);
    mapfunc.put("ui-writechild<-ui-child", Ui.t_ui_writechild_from_ui_child);
    mapfunc.put("ui-writechildmap<-ui-childmap", Ui.t_ui_writechildmap_from_ui_childmap);
    mapfunc.put("ui<-layout-ui-orig-parent", Ui.t_ui_from_layout_ui_orig_parent);
    mapfunc.put("uid-selected<-ui", Ui.t_uid_selected_from_ui);
    mapfunc.put("uiengine-readstate", Ui.t_uiengine_readstate);
    mapfunc.put("uiengine-render", Ui.t_uiengine_render);
    mapfunc.put("uilist-selected<-ui", Ui.t_uilist_selected_from_ui);
    mapfunc.put("uilist<-uimap", Ui.t_uilist_from_uimap);
    mapfunc.put("uimap-layout<-uimap-layoutmap-else", Ui.t_uimap_layout_from_uimap_layoutmap_else);
    mapfunc.put("uimap-render<-uimap-parent", Ui.t_uimap_render_from_uimap_parent);
    mapfunc.put("uimap<-uilist", Ui.t_uimap_from_uilist);
    mapfunc.put("uimap<-uimap-data", Ui.t_uimap_from_uimap_data);
    Core.vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc);
  }

}
