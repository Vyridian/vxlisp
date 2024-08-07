namespace Vx.Ui;

public static class Ui {


  /**
   * type: align
   * Universal Alignment
   * (type align)
   */
  public interface Type_align : Vx.Core.Type_struct {
  }

  public class Class_align : Vx.Core.Class_base, Type_align {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_align vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_align output = Vx.Core.vx_copy(Vx.Ui.Ui.e_align, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_align output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_align value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_align work = new Vx.Ui.Ui.Class_align();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_align;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_align;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "align", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_align e_align = new Vx.Ui.Ui.Class_align();
  public static Vx.Ui.Ui.Type_align t_align = new Vx.Ui.Ui.Class_align();

  /**
   * type: bounds
   * Universal Bounds
   * (type bounds)
   */
  public interface Type_bounds : Vx.Core.Type_struct {
    public Vx.Core.Type_int left();
    public Vx.Core.Type_int right();
    public Vx.Core.Type_int top();
    public Vx.Core.Type_int bottom();
  }

  public class Class_bounds : Vx.Core.Class_base, Type_bounds {

    public Vx.Core.Type_int? vx_p_left = null;

    public Vx.Core.Type_int left() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_left != null) {
        output = this.vx_p_left;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_right = null;

    public Vx.Core.Type_int right() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_right != null) {
        output = this.vx_p_right;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_top = null;

    public Vx.Core.Type_int top() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_top != null) {
        output = this.vx_p_top;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_bottom = null;

    public Vx.Core.Type_int bottom() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_bottom != null) {
        output = this.vx_p_bottom;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":left", this.left());
      output.put(":right", this.right());
      output.put(":top", this.top());
      output.put(":bottom", this.bottom());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_bounds vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_bounds output = Vx.Core.vx_copy(Vx.Ui.Ui.e_bounds, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_bounds output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_bounds value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_left = value.left();
      Vx.Core.Type_int vx_p_right = value.right();
      Vx.Core.Type_int vx_p_top = value.top();
      Vx.Core.Type_int vx_p_bottom = value.bottom();
      List<string> validkeys = new List<string>();
      validkeys.Add(":left");
      validkeys.Add(":right");
      validkeys.Add(":top");
      validkeys.Add(":bottom");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":left":
            if (valsub == vx_p_left) {
            } else if (valsub is Vx.Core.Type_int valleft) {
              ischanged = true;
              vx_p_left = valleft;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_left = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("left"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":right":
            if (valsub == vx_p_right) {
            } else if (valsub is Vx.Core.Type_int valright) {
              ischanged = true;
              vx_p_right = valright;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_right = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("right"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":top":
            if (valsub == vx_p_top) {
            } else if (valsub is Vx.Core.Type_int valtop) {
              ischanged = true;
              vx_p_top = valtop;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_top = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("top"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":bottom":
            if (valsub == vx_p_bottom) {
            } else if (valsub is Vx.Core.Type_int valbottom) {
              ischanged = true;
              vx_p_bottom = valbottom;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_bottom = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("bottom"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/bounds", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_bounds work = new Vx.Ui.Ui.Class_bounds();
        work.vx_p_left = vx_p_left;
        work.vx_p_right = vx_p_right;
        work.vx_p_top = vx_p_top;
        work.vx_p_bottom = vx_p_bottom;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_bounds;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_bounds;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "bounds", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_bounds e_bounds = new Vx.Ui.Ui.Class_bounds();
  public static Vx.Ui.Ui.Type_bounds t_bounds = new Vx.Ui.Ui.Class_bounds();

  /**
   * type: cursor
   * Univeral Cursor Type
   * (type cursor)
   */
  public interface Type_cursor : Vx.Core.Type_struct {
  }

  public class Class_cursor : Vx.Core.Class_base, Type_cursor {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_cursor vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_cursor output = Vx.Core.vx_copy(Vx.Ui.Ui.e_cursor, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_cursor output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_cursor value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_cursor work = new Vx.Ui.Ui.Class_cursor();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_cursor;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_cursor;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_cursor e_cursor = new Vx.Ui.Ui.Class_cursor();
  public static Vx.Ui.Ui.Type_cursor t_cursor = new Vx.Ui.Ui.Class_cursor();

  /**
   * type: cursor-pointer
   * (type cursor-pointer)
   */
  public interface Type_cursor_pointer : Vx.Core.Type_any {
  }

  public class Class_cursor_pointer : Vx.Core.Class_base, Type_cursor_pointer {

    public override Vx.Ui.Ui.Type_cursor_pointer vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_cursor_pointer output = Vx.Core.vx_copy(Vx.Ui.Ui.e_cursor_pointer, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_cursor_pointer output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_cursor_pointer value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_cursor_pointer work = new Vx.Ui.Ui.Class_cursor_pointer();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_cursor_pointer;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_cursor_pointer;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "cursor-pointer", // name
        ":cursor", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_cursor_pointer e_cursor_pointer = new Vx.Ui.Ui.Class_cursor_pointer();
  public static Vx.Ui.Ui.Type_cursor_pointer t_cursor_pointer = new Vx.Ui.Ui.Class_cursor_pointer();

  /**
   * type: flip
   * Universal ui flip horizontal or vertical or both.
   * (type flip)
   */
  public interface Type_flip : Vx.Core.Type_struct {
  }

  public class Class_flip : Vx.Core.Class_base, Type_flip {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_flip vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_flip output = Vx.Core.vx_copy(Vx.Ui.Ui.e_flip, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_flip output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_flip value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_flip work = new Vx.Ui.Ui.Class_flip();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_flip;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_flip;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "flip", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_flip e_flip = new Vx.Ui.Ui.Class_flip();
  public static Vx.Ui.Ui.Type_flip t_flip = new Vx.Ui.Ui.Class_flip();

  /**
   * type: font
   * Univeral Font Type
   * (type font)
   */
  public interface Type_font : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Type_fontface fontface();
    public Vx.Core.Type_int fontsize();
    public Vx.Ui.Ui.Type_fontstyle fontstyle();
  }

  public class Class_font : Vx.Core.Class_base, Type_font {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontface? vx_p_fontface = null;

    public Vx.Ui.Ui.Type_fontface fontface() {
      Vx.Ui.Ui.Type_fontface output = Vx.Ui.Ui.e_fontface;
      if (this.vx_p_fontface != null) {
        output = this.vx_p_fontface;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_fontsize = null;

    public Vx.Core.Type_int fontsize() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_fontsize != null) {
        output = this.vx_p_fontsize;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontstyle? vx_p_fontstyle = null;

    public Vx.Ui.Ui.Type_fontstyle fontstyle() {
      Vx.Ui.Ui.Type_fontstyle output = Vx.Ui.Ui.e_fontstyle;
      if (this.vx_p_fontstyle != null) {
        output = this.vx_p_fontstyle;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":fontface", this.fontface());
      output.put(":fontsize", this.fontsize());
      output.put(":fontstyle", this.fontstyle());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_font vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_font output = Vx.Core.vx_copy(Vx.Ui.Ui.e_font, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_font output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_font value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Ui.Ui.Type_fontface vx_p_fontface = value.fontface();
      Vx.Core.Type_int vx_p_fontsize = value.fontsize();
      Vx.Ui.Ui.Type_fontstyle vx_p_fontstyle = value.fontstyle();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":fontface");
      validkeys.Add(":fontsize");
      validkeys.Add(":fontstyle");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fontface":
            if (valsub == vx_p_fontface) {
            } else if (valsub is Vx.Ui.Ui.Type_fontface valfontface) {
              ischanged = true;
              vx_p_fontface = valfontface;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fontface"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fontsize":
            if (valsub == vx_p_fontsize) {
            } else if (valsub is Vx.Core.Type_int valfontsize) {
              ischanged = true;
              vx_p_fontsize = valfontsize;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_fontsize = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fontsize"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fontstyle":
            if (valsub == vx_p_fontstyle) {
            } else if (valsub is Vx.Ui.Ui.Type_fontstyle valfontstyle) {
              ischanged = true;
              vx_p_fontstyle = valfontstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fontstyle"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/font", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_font work = new Vx.Ui.Ui.Class_font();
        work.vx_p_name = vx_p_name;
        work.vx_p_fontface = vx_p_fontface;
        work.vx_p_fontsize = vx_p_fontsize;
        work.vx_p_fontstyle = vx_p_fontstyle;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_font;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_font;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "font", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_font e_font = new Vx.Ui.Ui.Class_font();
  public static Vx.Ui.Ui.Type_font t_font = new Vx.Ui.Ui.Class_font();

  /**
   * type: fontface
   * Univeral Font Face Type
   * (type fontface)
   */
  public interface Type_fontface : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string weight();
    public Vx.Core.Type_string unicode();
    public Vx.Data.File.Type_filelist filelist();
  }

  public class Class_fontface : Vx.Core.Class_base, Type_fontface {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_weight = null;

    public Vx.Core.Type_string weight() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_weight != null) {
        output = this.vx_p_weight;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_unicode = null;

    public Vx.Core.Type_string unicode() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_unicode != null) {
        output = this.vx_p_unicode;
      }
      return output;
    }

    public Vx.Data.File.Type_filelist? vx_p_filelist = null;

    public Vx.Data.File.Type_filelist filelist() {
      Vx.Data.File.Type_filelist output = Vx.Data.File.e_filelist;
      if (this.vx_p_filelist != null) {
        output = this.vx_p_filelist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":weight":
        output = this.weight();
        break;
      case ":unicode":
        output = this.unicode();
        break;
      case ":filelist":
        output = this.filelist();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":weight", this.weight());
      output.put(":unicode", this.unicode());
      output.put(":filelist", this.filelist());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_fontface vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontface output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontface, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontface output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontface value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_string vx_p_weight = value.weight();
      Vx.Core.Type_string vx_p_unicode = value.unicode();
      Vx.Data.File.Type_filelist vx_p_filelist = value.filelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":weight");
      validkeys.Add(":unicode");
      validkeys.Add(":filelist");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":weight":
            if (valsub == vx_p_weight) {
            } else if (valsub is Vx.Core.Type_string valweight) {
              ischanged = true;
              vx_p_weight = valweight;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_weight = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("weight"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":unicode":
            if (valsub == vx_p_unicode) {
            } else if (valsub is Vx.Core.Type_string valunicode) {
              ischanged = true;
              vx_p_unicode = valunicode;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_unicode = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("unicode"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":filelist":
            if (valsub == vx_p_filelist) {
            } else if (valsub is Vx.Data.File.Type_filelist valfilelist) {
              ischanged = true;
              vx_p_filelist = valfilelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("filelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontface", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontface work = new Vx.Ui.Ui.Class_fontface();
        work.vx_p_name = vx_p_name;
        work.vx_p_weight = vx_p_weight;
        work.vx_p_unicode = vx_p_unicode;
        work.vx_p_filelist = vx_p_filelist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontface;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontface;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontface", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontface e_fontface = new Vx.Ui.Ui.Class_fontface();
  public static Vx.Ui.Ui.Type_fontface t_fontface = new Vx.Ui.Ui.Class_fontface();

  /**
   * type: fontfacelist
   * List of fontface
   * (type fontfacelist)
   */
  public interface Type_fontfacelist : Vx.Core.Type_list {
    public List<Vx.Ui.Ui.Type_fontface> vx_listfontface();
    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_int index);
  }

  public class Class_fontfacelist : Vx.Core.Class_base, Type_fontfacelist {

    public List<Vx.Ui.Ui.Type_fontface> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Ui.Ui.Type_fontface>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_fontface output = Vx.Ui.Ui.e_fontface;
      Vx.Ui.Ui.Class_fontfacelist list = this;
      int iindex = index.vx_int();
      List<Vx.Ui.Ui.Type_fontface> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Ui.Ui.Type_fontface> vx_listfontface() {
      List<Vx.Ui.Ui.Type_fontface> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_fontface output = this.vx_fontface(index);
      return output;
    }

    public override Vx.Ui.Ui.Type_fontfacelist vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontfacelist output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontfacelist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontfacelist output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontfacelist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_fontface> listval = new List<Vx.Ui.Ui.Type_fontface>(value.vx_listfontface());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_fontface allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Ui.Ui.Type_fontface) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_fontface)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_fontfacelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfontface());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Ui.Ui.Type_fontface valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontfacelist work = new Vx.Ui.Ui.Class_fontfacelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontfacelist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontfacelist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_fontface), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontfacelist e_fontfacelist = new Vx.Ui.Ui.Class_fontfacelist();
  public static Vx.Ui.Ui.Type_fontfacelist t_fontfacelist = new Vx.Ui.Ui.Class_fontfacelist();

  /**
   * type: fontfacemap
   * Map of fontface
   * (type fontfacemap)
   */
  public interface Type_fontfacemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_mapfontface();
    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_string key);
  }

  public class Class_fontfacemap : Vx.Core.Class_base, Type_fontfacemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_fontface>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_fontface castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_fontface) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_fontface output = Vx.Ui.Ui.e_fontface;
      Vx.Ui.Ui.Class_fontfacemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_fontface);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_mapfontface() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_fontface(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontfacemap output = new Vx.Ui.Ui.Class_fontfacemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_fontface castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontfacemap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontfacemap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontfacemap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontfacemap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontfacemap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>(value.vx_mapfontface());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_fontface? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_fontface valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_fontface) {
            valany = (Vx.Ui.Ui.Type_fontface)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontfacemap work = new Vx.Ui.Ui.Class_fontfacemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontfacemap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontfacemap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_fontface), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontfacemap e_fontfacemap = new Vx.Ui.Ui.Class_fontfacemap();
  public static Vx.Ui.Ui.Type_fontfacemap t_fontfacemap = new Vx.Ui.Ui.Class_fontfacemap();

  /**
   * type: fontmap
   * Map of font
   * (type fontmap)
   */
  public interface Type_fontmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_mapfont();
    public Vx.Ui.Ui.Type_font vx_font(Vx.Core.Type_string key);
  }

  public class Class_fontmap : Vx.Core.Class_base, Type_fontmap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_font>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_font castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_font> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_font) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_font vx_font(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_font output = Vx.Ui.Ui.e_font;
      Vx.Ui.Ui.Class_fontmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_font);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_mapfont() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_font(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontmap output = new Vx.Ui.Ui.Class_fontmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_font castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontmap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontmap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontmap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>(value.vx_mapfont());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_font? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_font valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_font) {
            valany = (Vx.Ui.Ui.Type_font)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontmap work = new Vx.Ui.Ui.Class_fontmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_font), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontmap e_fontmap = new Vx.Ui.Ui.Class_fontmap();
  public static Vx.Ui.Ui.Type_fontmap t_fontmap = new Vx.Ui.Ui.Class_fontmap();

  /**
   * type: fontstyle
   * Univeral Font Style Type
   * (type fontstyle)
   */
  public interface Type_fontstyle : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
  }

  public class Class_fontstyle : Vx.Core.Class_base, Type_fontstyle {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_fontstyle vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontstyle output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontstyle, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontstyle output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontstyle value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstyle", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontstyle work = new Vx.Ui.Ui.Class_fontstyle();
        work.vx_p_name = vx_p_name;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontstyle;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontstyle;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstyle", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontstyle e_fontstyle = new Vx.Ui.Ui.Class_fontstyle();
  public static Vx.Ui.Ui.Type_fontstyle t_fontstyle = new Vx.Ui.Ui.Class_fontstyle();

  /**
   * type: fontstylemap
   * Map of fontstyle
   * (type fontstylemap)
   */
  public interface Type_fontstylemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_mapfontstyle();
    public Vx.Ui.Ui.Type_fontstyle vx_fontstyle(Vx.Core.Type_string key);
  }

  public class Class_fontstylemap : Vx.Core.Class_base, Type_fontstylemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_fontstyle>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_fontstyle castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_fontstyle) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontstyle vx_fontstyle(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_fontstyle output = Vx.Ui.Ui.e_fontstyle;
      Vx.Ui.Ui.Class_fontstylemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_fontstyle);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_mapfontstyle() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_fontstyle(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontstylemap output = new Vx.Ui.Ui.Class_fontstylemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_fontstyle castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontstylemap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_fontstylemap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_fontstylemap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_fontstylemap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_fontstylemap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>(value.vx_mapfontstyle());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_fontstyle? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_fontstyle valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_fontstyle) {
            valany = (Vx.Ui.Ui.Type_fontstyle)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_fontstylemap work = new Vx.Ui.Ui.Class_fontstylemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontstylemap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontstylemap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "fontstylemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_fontstyle), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_fontstylemap e_fontstylemap = new Vx.Ui.Ui.Class_fontstylemap();
  public static Vx.Ui.Ui.Type_fontstylemap t_fontstylemap = new Vx.Ui.Ui.Class_fontstylemap();

  /**
   * type: image
   * Univeral Image Type
   * (type image)
   */
  public interface Type_image : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string label();
    public Vx.Data.File.Type_file file();
  }

  public class Class_image : Vx.Core.Class_base, Type_image {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_label = null;

    public Vx.Core.Type_string label() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_label != null) {
        output = this.vx_p_label;
      }
      return output;
    }

    public Vx.Data.File.Type_file? vx_p_file = null;

    public Vx.Data.File.Type_file file() {
      Vx.Data.File.Type_file output = Vx.Data.File.e_file;
      if (this.vx_p_file != null) {
        output = this.vx_p_file;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":label":
        output = this.label();
        break;
      case ":file":
        output = this.file();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":label", this.label());
      output.put(":file", this.file());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_image vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_image output = Vx.Core.vx_copy(Vx.Ui.Ui.e_image, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_image output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_image value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_string vx_p_label = value.label();
      Vx.Data.File.Type_file vx_p_file = value.file();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":label");
      validkeys.Add(":file");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":label":
            if (valsub == vx_p_label) {
            } else if (valsub is Vx.Core.Type_string vallabel) {
              ischanged = true;
              vx_p_label = vallabel;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_label = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("label"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":file":
            if (valsub == vx_p_file) {
            } else if (valsub is Vx.Data.File.Type_file valfile) {
              ischanged = true;
              vx_p_file = valfile;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("file"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/image", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_image work = new Vx.Ui.Ui.Class_image();
        work.vx_p_name = vx_p_name;
        work.vx_p_label = vx_p_label;
        work.vx_p_file = vx_p_file;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_image;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_image;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "image", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_image e_image = new Vx.Ui.Ui.Class_image();
  public static Vx.Ui.Ui.Type_image t_image = new Vx.Ui.Ui.Class_image();

  /**
   * type: layout
   * Universal Layout
   * (type layout)
   */
  public interface Type_layout : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout();
  }

  public class Class_layout : Vx.Core.Class_base, Type_layout {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent? vx_p_fn_layout = null;

    public Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout() {
      Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent output = Vx.Ui.Ui.e_ui_layout_from_ui_orig_parent;
      if (this.vx_p_fn_layout != null) {
        output = this.vx_p_fn_layout;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":fn-layout", this.fn_layout());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_layout vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_layout output = Vx.Core.vx_copy(Vx.Ui.Ui.e_layout, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_layout output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_layout value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_p_fn_layout = value.fn_layout();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":fn-layout");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-layout":
            if (valsub == vx_p_fn_layout) {
            } else if (valsub is Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent valfn_layout) {
              ischanged = true;
              vx_p_fn_layout = valfn_layout;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-layout"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layout", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_layout work = new Vx.Ui.Ui.Class_layout();
        work.vx_p_name = vx_p_name;
        work.vx_p_fn_layout = vx_p_fn_layout;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layout;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layout;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layout", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_layout e_layout = new Vx.Ui.Ui.Class_layout();
  public static Vx.Ui.Ui.Type_layout t_layout = new Vx.Ui.Ui.Class_layout();

  /**
   * type: layoutengine
   * Pluggable layoutengine
   * (type layoutengine)
   */
  public interface Type_layoutengine : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Func_boolean_print boolean_print();
    public Vx.Ui.Ui.Func_boolean_layoutremove_from_ui boolean_layoutremove();
    public Vx.Ui.Ui.Func_boolean_layoutselected_from_ui boolean_layoutselected();
    public Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui boolean_layoutvisible();
    public Vx.Ui.Ui.Type_layoutmap layoutmap();
    public Vx.Ui.Ui.Type_layout layoutelse();
    public Vx.Ui.Ui.Func_stylesheet_render stylesheetrender();
  }

  public class Class_layoutengine : Vx.Core.Class_base, Type_layoutengine {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_print? vx_p_boolean_print = null;

    public Vx.Ui.Ui.Func_boolean_print boolean_print() {
      Vx.Ui.Ui.Func_boolean_print output = Vx.Ui.Ui.e_boolean_print;
      if (this.vx_p_boolean_print != null) {
        output = this.vx_p_boolean_print;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutremove_from_ui? vx_p_boolean_layoutremove = null;

    public Vx.Ui.Ui.Func_boolean_layoutremove_from_ui boolean_layoutremove() {
      Vx.Ui.Ui.Func_boolean_layoutremove_from_ui output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui;
      if (this.vx_p_boolean_layoutremove != null) {
        output = this.vx_p_boolean_layoutremove;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutselected_from_ui? vx_p_boolean_layoutselected = null;

    public Vx.Ui.Ui.Func_boolean_layoutselected_from_ui boolean_layoutselected() {
      Vx.Ui.Ui.Func_boolean_layoutselected_from_ui output = Vx.Ui.Ui.e_boolean_layoutselected_from_ui;
      if (this.vx_p_boolean_layoutselected != null) {
        output = this.vx_p_boolean_layoutselected;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui? vx_p_boolean_layoutvisible = null;

    public Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui boolean_layoutvisible() {
      Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui output = Vx.Ui.Ui.e_boolean_layoutvisible_from_ui;
      if (this.vx_p_boolean_layoutvisible != null) {
        output = this.vx_p_boolean_layoutvisible;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layoutmap? vx_p_layoutmap = null;

    public Vx.Ui.Ui.Type_layoutmap layoutmap() {
      Vx.Ui.Ui.Type_layoutmap output = Vx.Ui.Ui.e_layoutmap;
      if (this.vx_p_layoutmap != null) {
        output = this.vx_p_layoutmap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout? vx_p_layoutelse = null;

    public Vx.Ui.Ui.Type_layout layoutelse() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layoutelse != null) {
        output = this.vx_p_layoutelse;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_stylesheet_render? vx_p_stylesheetrender = null;

    public Vx.Ui.Ui.Func_stylesheet_render stylesheetrender() {
      Vx.Ui.Ui.Func_stylesheet_render output = Vx.Ui.Ui.e_stylesheet_render;
      if (this.vx_p_stylesheetrender != null) {
        output = this.vx_p_stylesheetrender;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":boolean-print":
        output = this.boolean_print();
        break;
      case ":boolean-layoutremove":
        output = this.boolean_layoutremove();
        break;
      case ":boolean-layoutselected":
        output = this.boolean_layoutselected();
        break;
      case ":boolean-layoutvisible":
        output = this.boolean_layoutvisible();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":boolean-print", this.boolean_print());
      output.put(":boolean-layoutremove", this.boolean_layoutremove());
      output.put(":boolean-layoutselected", this.boolean_layoutselected());
      output.put(":boolean-layoutvisible", this.boolean_layoutvisible());
      output.put(":layoutmap", this.layoutmap());
      output.put(":layoutelse", this.layoutelse());
      output.put(":stylesheetrender", this.stylesheetrender());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_layoutengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_layoutengine output = Vx.Core.vx_copy(Vx.Ui.Ui.e_layoutengine, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_layoutengine output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_layoutengine value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Ui.Ui.Func_boolean_print vx_p_boolean_print = value.boolean_print();
      Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_p_boolean_layoutremove = value.boolean_layoutremove();
      Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_p_boolean_layoutselected = value.boolean_layoutselected();
      Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_p_boolean_layoutvisible = value.boolean_layoutvisible();
      Vx.Ui.Ui.Type_layoutmap vx_p_layoutmap = value.layoutmap();
      Vx.Ui.Ui.Type_layout vx_p_layoutelse = value.layoutelse();
      Vx.Ui.Ui.Func_stylesheet_render vx_p_stylesheetrender = value.stylesheetrender();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":boolean-print");
      validkeys.Add(":boolean-layoutremove");
      validkeys.Add(":boolean-layoutselected");
      validkeys.Add(":boolean-layoutvisible");
      validkeys.Add(":layoutmap");
      validkeys.Add(":layoutelse");
      validkeys.Add(":stylesheetrender");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boolean-print":
            if (valsub == vx_p_boolean_print) {
            } else if (valsub is Vx.Ui.Ui.Func_boolean_print valboolean_print) {
              ischanged = true;
              vx_p_boolean_print = valboolean_print;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boolean-print"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boolean-layoutremove":
            if (valsub == vx_p_boolean_layoutremove) {
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutremove_from_ui valboolean_layoutremove) {
              ischanged = true;
              vx_p_boolean_layoutremove = valboolean_layoutremove;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boolean-layoutremove"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boolean-layoutselected":
            if (valsub == vx_p_boolean_layoutselected) {
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutselected_from_ui valboolean_layoutselected) {
              ischanged = true;
              vx_p_boolean_layoutselected = valboolean_layoutselected;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boolean-layoutselected"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boolean-layoutvisible":
            if (valsub == vx_p_boolean_layoutvisible) {
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui valboolean_layoutvisible) {
              ischanged = true;
              vx_p_boolean_layoutvisible = valboolean_layoutvisible;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boolean-layoutvisible"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":layoutmap":
            if (valsub == vx_p_layoutmap) {
            } else if (valsub is Vx.Ui.Ui.Type_layoutmap vallayoutmap) {
              ischanged = true;
              vx_p_layoutmap = vallayoutmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("layoutmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":layoutelse":
            if (valsub == vx_p_layoutelse) {
            } else if (valsub is Vx.Ui.Ui.Type_layout vallayoutelse) {
              ischanged = true;
              vx_p_layoutelse = vallayoutelse;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("layoutelse"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylesheetrender":
            if (valsub == vx_p_stylesheetrender) {
            } else if (valsub is Vx.Ui.Ui.Func_stylesheet_render valstylesheetrender) {
              ischanged = true;
              vx_p_stylesheetrender = valstylesheetrender;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylesheetrender"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutengine", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_layoutengine work = new Vx.Ui.Ui.Class_layoutengine();
        work.vx_p_name = vx_p_name;
        work.vx_p_boolean_print = vx_p_boolean_print;
        work.vx_p_boolean_layoutremove = vx_p_boolean_layoutremove;
        work.vx_p_boolean_layoutselected = vx_p_boolean_layoutselected;
        work.vx_p_boolean_layoutvisible = vx_p_boolean_layoutvisible;
        work.vx_p_layoutmap = vx_p_layoutmap;
        work.vx_p_layoutelse = vx_p_layoutelse;
        work.vx_p_stylesheetrender = vx_p_stylesheetrender;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layoutengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layoutengine;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutengine", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_layoutengine e_layoutengine = new Vx.Ui.Ui.Class_layoutengine();
  public static Vx.Ui.Ui.Type_layoutengine t_layoutengine = new Vx.Ui.Ui.Class_layoutengine();

  /**
   * type: layoutlist
   * Map of layout
   * (type layoutlist)
   */
  public interface Type_layoutlist : Vx.Core.Type_list {
    public List<Vx.Ui.Ui.Type_layout> vx_listlayout();
    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_int index);
  }

  public class Class_layoutlist : Vx.Core.Class_base, Type_layoutlist {

    public List<Vx.Ui.Ui.Type_layout> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Ui.Ui.Type_layout>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      Vx.Ui.Ui.Class_layoutlist list = this;
      int iindex = index.vx_int();
      List<Vx.Ui.Ui.Type_layout> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Ui.Ui.Type_layout> vx_listlayout() {
      List<Vx.Ui.Ui.Type_layout> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_layout output = this.vx_layout(index);
      return output;
    }

    public override Vx.Ui.Ui.Type_layoutlist vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_layoutlist output = Vx.Core.vx_copy(Vx.Ui.Ui.e_layoutlist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_layoutlist output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_layoutlist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_layout> listval = new List<Vx.Ui.Ui.Type_layout>(value.vx_listlayout());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_layout allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Ui.Ui.Type_layout) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_layout)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_layoutlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listlayout());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Ui.Ui.Type_layout valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_layoutlist work = new Vx.Ui.Ui.Class_layoutlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layoutlist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layoutlist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_layout), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_layoutlist e_layoutlist = new Vx.Ui.Ui.Class_layoutlist();
  public static Vx.Ui.Ui.Type_layoutlist t_layoutlist = new Vx.Ui.Ui.Class_layoutlist();

  /**
   * type: layoutmap
   * Map of layout
   * (type layoutmap)
   */
  public interface Type_layoutmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_maplayout();
    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_string key);
  }

  public class Class_layoutmap : Vx.Core.Class_base, Type_layoutmap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_layout>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_layout castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_layout) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      Vx.Ui.Ui.Class_layoutmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_layout);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_maplayout() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_layout(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_layoutmap output = new Vx.Ui.Ui.Class_layoutmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_layout castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_layoutmap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_layoutmap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_layoutmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_layoutmap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_layoutmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>(value.vx_maplayout());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_layout? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_layout valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_layout) {
            valany = (Vx.Ui.Ui.Type_layout)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_layoutmap work = new Vx.Ui.Ui.Class_layoutmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layoutmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layoutmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_layout), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_layoutmap e_layoutmap = new Vx.Ui.Ui.Class_layoutmap();
  public static Vx.Ui.Ui.Type_layoutmap t_layoutmap = new Vx.Ui.Ui.Class_layoutmap();

  /**
   * type: pin
   * Pin an element
   * (type pin)
   */
  public interface Type_pin : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
  }

  public class Class_pin : Vx.Core.Class_base, Type_pin {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_pin vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_pin output = Vx.Core.vx_copy(Vx.Ui.Ui.e_pin, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_pin output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_pin value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/pin", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_pin work = new Vx.Ui.Ui.Class_pin();
        work.vx_p_name = vx_p_name;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_pin;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_pin;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "pin", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_pin e_pin = new Vx.Ui.Ui.Class_pin();
  public static Vx.Ui.Ui.Type_pin t_pin = new Vx.Ui.Ui.Class_pin();

  /**
   * type: point
   * Universal Point
   * (type point)
   */
  public interface Type_point : Vx.Core.Type_struct {
    public Vx.Core.Type_int x();
    public Vx.Core.Type_int y();
    public Vx.Core.Type_int z();
    public Vx.Core.Type_int t();
    public Vx.Core.Type_int i();
    public Vx.Ui.Ui.Type_pointtype pointtype();
  }

  public class Class_point : Vx.Core.Class_base, Type_point {

    public Vx.Core.Type_int? vx_p_x = null;

    public Vx.Core.Type_int x() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_x != null) {
        output = this.vx_p_x;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_y = null;

    public Vx.Core.Type_int y() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_y != null) {
        output = this.vx_p_y;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_z = null;

    public Vx.Core.Type_int z() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_z != null) {
        output = this.vx_p_z;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_t = null;

    public Vx.Core.Type_int t() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_t != null) {
        output = this.vx_p_t;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_i = null;

    public Vx.Core.Type_int i() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_i != null) {
        output = this.vx_p_i;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_pointtype? vx_p_pointtype = null;

    public Vx.Ui.Ui.Type_pointtype pointtype() {
      Vx.Ui.Ui.Type_pointtype output = Vx.Ui.Ui.e_pointtype;
      if (this.vx_p_pointtype != null) {
        output = this.vx_p_pointtype;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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
      case ":pointtype":
        output = this.pointtype();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":x", this.x());
      output.put(":y", this.y());
      output.put(":z", this.z());
      output.put(":t", this.t());
      output.put(":i", this.i());
      output.put(":pointtype", this.pointtype());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_point vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_point output = Vx.Core.vx_copy(Vx.Ui.Ui.e_point, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_point output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_point value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_x = value.x();
      Vx.Core.Type_int vx_p_y = value.y();
      Vx.Core.Type_int vx_p_z = value.z();
      Vx.Core.Type_int vx_p_t = value.t();
      Vx.Core.Type_int vx_p_i = value.i();
      Vx.Ui.Ui.Type_pointtype vx_p_pointtype = value.pointtype();
      List<string> validkeys = new List<string>();
      validkeys.Add(":x");
      validkeys.Add(":y");
      validkeys.Add(":z");
      validkeys.Add(":t");
      validkeys.Add(":i");
      validkeys.Add(":pointtype");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":x":
            if (valsub == vx_p_x) {
            } else if (valsub is Vx.Core.Type_int valx) {
              ischanged = true;
              vx_p_x = valx;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_x = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("x"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":y":
            if (valsub == vx_p_y) {
            } else if (valsub is Vx.Core.Type_int valy) {
              ischanged = true;
              vx_p_y = valy;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_y = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("y"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":z":
            if (valsub == vx_p_z) {
            } else if (valsub is Vx.Core.Type_int valz) {
              ischanged = true;
              vx_p_z = valz;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_z = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("z"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":t":
            if (valsub == vx_p_t) {
            } else if (valsub is Vx.Core.Type_int valt) {
              ischanged = true;
              vx_p_t = valt;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_t = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("t"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":i":
            if (valsub == vx_p_i) {
            } else if (valsub is Vx.Core.Type_int vali) {
              ischanged = true;
              vx_p_i = vali;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_i = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("i"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pointtype":
            if (valsub == vx_p_pointtype) {
            } else if (valsub is Vx.Ui.Ui.Type_pointtype valpointtype) {
              ischanged = true;
              vx_p_pointtype = valpointtype;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pointtype"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/point", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_point work = new Vx.Ui.Ui.Class_point();
        work.vx_p_x = vx_p_x;
        work.vx_p_y = vx_p_y;
        work.vx_p_z = vx_p_z;
        work.vx_p_t = vx_p_t;
        work.vx_p_i = vx_p_i;
        work.vx_p_pointtype = vx_p_pointtype;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_point;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_point;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "point", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_point e_point = new Vx.Ui.Ui.Class_point();
  public static Vx.Ui.Ui.Type_point t_point = new Vx.Ui.Ui.Class_point();

  /**
   * type: pointtype
   * Universal Point Scale
   * (type pointtype)
   */
  public interface Type_pointtype : Vx.Core.Type_any {
  }

  public class Class_pointtype : Vx.Core.Class_base, Type_pointtype {

    public override Vx.Ui.Ui.Type_pointtype vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_pointtype output = Vx.Core.vx_copy(Vx.Ui.Ui.e_pointtype, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_pointtype output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_pointtype value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_pointtype work = new Vx.Ui.Ui.Class_pointtype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_pointtype;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_pointtype;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "pointtype", // name
        ":int", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_pointtype e_pointtype = new Vx.Ui.Ui.Class_pointtype();
  public static Vx.Ui.Ui.Type_pointtype t_pointtype = new Vx.Ui.Ui.Class_pointtype();

  /**
   * type: style
   * Universal Style
   * (type style)
   */
  public interface Type_style : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Type_align align();
    public Vx.Ui.Ui.Type_bounds boundsmargin();
    public Vx.Ui.Ui.Type_bounds boundspadding();
    public Vx.Core.Type_string color_bkg();
    public Vx.Core.Type_string color_bkghover();
    public Vx.Core.Type_string color_border();
    public Vx.Core.Type_string color_font();
    public Vx.Ui.Ui.Type_cursor cursor();
    public Vx.Ui.Ui.Type_flip flip();
    public Vx.Ui.Ui.Type_font font();
    public Vx.Core.Type_boolean hidden();
    public Vx.Ui.Ui.Type_image image_bkg();
    public Vx.Ui.Ui.Type_layout layout();
    public Vx.Ui.Ui.Type_styletype type();
    public Vx.Ui.Ui.Type_pin pin();
    public Vx.Ui.Ui.Type_point pointorigin();
    public Vx.Ui.Ui.Type_point pointpos();
    public Vx.Ui.Ui.Type_point pointrotate();
    public Vx.Ui.Ui.Type_point pointsize();
    public Vx.Core.Type_boolean scroll_x();
    public Vx.Core.Type_boolean scroll_y();
  }

  public class Class_style : Vx.Core.Class_base, Type_style {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_align? vx_p_align = null;

    public Vx.Ui.Ui.Type_align align() {
      Vx.Ui.Ui.Type_align output = Vx.Ui.Ui.e_align;
      if (this.vx_p_align != null) {
        output = this.vx_p_align;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_bounds? vx_p_boundsmargin = null;

    public Vx.Ui.Ui.Type_bounds boundsmargin() {
      Vx.Ui.Ui.Type_bounds output = Vx.Ui.Ui.e_bounds;
      if (this.vx_p_boundsmargin != null) {
        output = this.vx_p_boundsmargin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_bounds? vx_p_boundspadding = null;

    public Vx.Ui.Ui.Type_bounds boundspadding() {
      Vx.Ui.Ui.Type_bounds output = Vx.Ui.Ui.e_bounds;
      if (this.vx_p_boundspadding != null) {
        output = this.vx_p_boundspadding;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_color_bkg = null;

    public Vx.Core.Type_string color_bkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_bkg != null) {
        output = this.vx_p_color_bkg;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_color_bkghover = null;

    public Vx.Core.Type_string color_bkghover() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_bkghover != null) {
        output = this.vx_p_color_bkghover;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_color_border = null;

    public Vx.Core.Type_string color_border() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_border != null) {
        output = this.vx_p_color_border;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_color_font = null;

    public Vx.Core.Type_string color_font() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_font != null) {
        output = this.vx_p_color_font;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_cursor? vx_p_cursor = null;

    public Vx.Ui.Ui.Type_cursor cursor() {
      Vx.Ui.Ui.Type_cursor output = Vx.Ui.Ui.e_cursor;
      if (this.vx_p_cursor != null) {
        output = this.vx_p_cursor;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_flip? vx_p_flip = null;

    public Vx.Ui.Ui.Type_flip flip() {
      Vx.Ui.Ui.Type_flip output = Vx.Ui.Ui.e_flip;
      if (this.vx_p_flip != null) {
        output = this.vx_p_flip;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_font? vx_p_font = null;

    public Vx.Ui.Ui.Type_font font() {
      Vx.Ui.Ui.Type_font output = Vx.Ui.Ui.e_font;
      if (this.vx_p_font != null) {
        output = this.vx_p_font;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_hidden = null;

    public Vx.Core.Type_boolean hidden() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_hidden != null) {
        output = this.vx_p_hidden;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_image? vx_p_image_bkg = null;

    public Vx.Ui.Ui.Type_image image_bkg() {
      Vx.Ui.Ui.Type_image output = Vx.Ui.Ui.e_image;
      if (this.vx_p_image_bkg != null) {
        output = this.vx_p_image_bkg;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout? vx_p_layout = null;

    public Vx.Ui.Ui.Type_layout layout() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layout != null) {
        output = this.vx_p_layout;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_styletype? vx_p_type = null;

    public Vx.Ui.Ui.Type_styletype type() {
      Vx.Ui.Ui.Type_styletype output = Vx.Ui.Ui.e_styletype;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_pin? vx_p_pin = null;

    public Vx.Ui.Ui.Type_pin pin() {
      Vx.Ui.Ui.Type_pin output = Vx.Ui.Ui.e_pin;
      if (this.vx_p_pin != null) {
        output = this.vx_p_pin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point? vx_p_pointorigin = null;

    public Vx.Ui.Ui.Type_point pointorigin() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointorigin != null) {
        output = this.vx_p_pointorigin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point? vx_p_pointpos = null;

    public Vx.Ui.Ui.Type_point pointpos() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointpos != null) {
        output = this.vx_p_pointpos;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point? vx_p_pointrotate = null;

    public Vx.Ui.Ui.Type_point pointrotate() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointrotate != null) {
        output = this.vx_p_pointrotate;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point? vx_p_pointsize = null;

    public Vx.Ui.Ui.Type_point pointsize() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointsize != null) {
        output = this.vx_p_pointsize;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_scroll_x = null;

    public Vx.Core.Type_boolean scroll_x() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_scroll_x != null) {
        output = this.vx_p_scroll_x;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_scroll_y = null;

    public Vx.Core.Type_boolean scroll_y() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_scroll_y != null) {
        output = this.vx_p_scroll_y;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":align":
        output = this.align();
        break;
      case ":boundsmargin":
        output = this.boundsmargin();
        break;
      case ":boundspadding":
        output = this.boundspadding();
        break;
      case ":color-bkg":
        output = this.color_bkg();
        break;
      case ":color-bkghover":
        output = this.color_bkghover();
        break;
      case ":color-border":
        output = this.color_border();
        break;
      case ":color-font":
        output = this.color_font();
        break;
      case ":cursor":
        output = this.cursor();
        break;
      case ":flip":
        output = this.flip();
        break;
      case ":font":
        output = this.font();
        break;
      case ":hidden":
        output = this.hidden();
        break;
      case ":image-bkg":
        output = this.image_bkg();
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
      case ":pointorigin":
        output = this.pointorigin();
        break;
      case ":pointpos":
        output = this.pointpos();
        break;
      case ":pointrotate":
        output = this.pointrotate();
        break;
      case ":pointsize":
        output = this.pointsize();
        break;
      case ":scroll-x":
        output = this.scroll_x();
        break;
      case ":scroll-y":
        output = this.scroll_y();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":align", this.align());
      output.put(":boundsmargin", this.boundsmargin());
      output.put(":boundspadding", this.boundspadding());
      output.put(":color-bkg", this.color_bkg());
      output.put(":color-bkghover", this.color_bkghover());
      output.put(":color-border", this.color_border());
      output.put(":color-font", this.color_font());
      output.put(":cursor", this.cursor());
      output.put(":flip", this.flip());
      output.put(":font", this.font());
      output.put(":hidden", this.hidden());
      output.put(":image-bkg", this.image_bkg());
      output.put(":layout", this.layout());
      output.put(":type", this.type());
      output.put(":pin", this.pin());
      output.put(":pointorigin", this.pointorigin());
      output.put(":pointpos", this.pointpos());
      output.put(":pointrotate", this.pointrotate());
      output.put(":pointsize", this.pointsize());
      output.put(":scroll-x", this.scroll_x());
      output.put(":scroll-y", this.scroll_y());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_style vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_style output = Vx.Core.vx_copy(Vx.Ui.Ui.e_style, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_style output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_style value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Ui.Ui.Type_align vx_p_align = value.align();
      Vx.Ui.Ui.Type_bounds vx_p_boundsmargin = value.boundsmargin();
      Vx.Ui.Ui.Type_bounds vx_p_boundspadding = value.boundspadding();
      Vx.Core.Type_string vx_p_color_bkg = value.color_bkg();
      Vx.Core.Type_string vx_p_color_bkghover = value.color_bkghover();
      Vx.Core.Type_string vx_p_color_border = value.color_border();
      Vx.Core.Type_string vx_p_color_font = value.color_font();
      Vx.Ui.Ui.Type_cursor vx_p_cursor = value.cursor();
      Vx.Ui.Ui.Type_flip vx_p_flip = value.flip();
      Vx.Ui.Ui.Type_font vx_p_font = value.font();
      Vx.Core.Type_boolean vx_p_hidden = value.hidden();
      Vx.Ui.Ui.Type_image vx_p_image_bkg = value.image_bkg();
      Vx.Ui.Ui.Type_layout vx_p_layout = value.layout();
      Vx.Ui.Ui.Type_styletype vx_p_type = value.type();
      Vx.Ui.Ui.Type_pin vx_p_pin = value.pin();
      Vx.Ui.Ui.Type_point vx_p_pointorigin = value.pointorigin();
      Vx.Ui.Ui.Type_point vx_p_pointpos = value.pointpos();
      Vx.Ui.Ui.Type_point vx_p_pointrotate = value.pointrotate();
      Vx.Ui.Ui.Type_point vx_p_pointsize = value.pointsize();
      Vx.Core.Type_boolean vx_p_scroll_x = value.scroll_x();
      Vx.Core.Type_boolean vx_p_scroll_y = value.scroll_y();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":align");
      validkeys.Add(":boundsmargin");
      validkeys.Add(":boundspadding");
      validkeys.Add(":color-bkg");
      validkeys.Add(":color-bkghover");
      validkeys.Add(":color-border");
      validkeys.Add(":color-font");
      validkeys.Add(":cursor");
      validkeys.Add(":flip");
      validkeys.Add(":font");
      validkeys.Add(":hidden");
      validkeys.Add(":image-bkg");
      validkeys.Add(":layout");
      validkeys.Add(":type");
      validkeys.Add(":pin");
      validkeys.Add(":pointorigin");
      validkeys.Add(":pointpos");
      validkeys.Add(":pointrotate");
      validkeys.Add(":pointsize");
      validkeys.Add(":scroll-x");
      validkeys.Add(":scroll-y");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":align":
            if (valsub == vx_p_align) {
            } else if (valsub is Vx.Ui.Ui.Type_align valalign) {
              ischanged = true;
              vx_p_align = valalign;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("align"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boundsmargin":
            if (valsub == vx_p_boundsmargin) {
            } else if (valsub is Vx.Ui.Ui.Type_bounds valboundsmargin) {
              ischanged = true;
              vx_p_boundsmargin = valboundsmargin;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boundsmargin"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":boundspadding":
            if (valsub == vx_p_boundspadding) {
            } else if (valsub is Vx.Ui.Ui.Type_bounds valboundspadding) {
              ischanged = true;
              vx_p_boundspadding = valboundspadding;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("boundspadding"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":color-bkg":
            if (valsub == vx_p_color_bkg) {
            } else if (valsub is Vx.Core.Type_string valcolor_bkg) {
              ischanged = true;
              vx_p_color_bkg = valcolor_bkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_bkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("color-bkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":color-bkghover":
            if (valsub == vx_p_color_bkghover) {
            } else if (valsub is Vx.Core.Type_string valcolor_bkghover) {
              ischanged = true;
              vx_p_color_bkghover = valcolor_bkghover;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_bkghover = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("color-bkghover"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":color-border":
            if (valsub == vx_p_color_border) {
            } else if (valsub is Vx.Core.Type_string valcolor_border) {
              ischanged = true;
              vx_p_color_border = valcolor_border;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_border = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("color-border"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":color-font":
            if (valsub == vx_p_color_font) {
            } else if (valsub is Vx.Core.Type_string valcolor_font) {
              ischanged = true;
              vx_p_color_font = valcolor_font;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_font = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("color-font"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":cursor":
            if (valsub == vx_p_cursor) {
            } else if (valsub is Vx.Ui.Ui.Type_cursor valcursor) {
              ischanged = true;
              vx_p_cursor = valcursor;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("cursor"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":flip":
            if (valsub == vx_p_flip) {
            } else if (valsub is Vx.Ui.Ui.Type_flip valflip) {
              ischanged = true;
              vx_p_flip = valflip;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("flip"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":font":
            if (valsub == vx_p_font) {
            } else if (valsub is Vx.Ui.Ui.Type_font valfont) {
              ischanged = true;
              vx_p_font = valfont;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("font"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":hidden":
            if (valsub == vx_p_hidden) {
            } else if (valsub is Vx.Core.Type_boolean valhidden) {
              ischanged = true;
              vx_p_hidden = valhidden;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_hidden = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":image-bkg":
            if (valsub == vx_p_image_bkg) {
            } else if (valsub is Vx.Ui.Ui.Type_image valimage_bkg) {
              ischanged = true;
              vx_p_image_bkg = valimage_bkg;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("image-bkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":layout":
            if (valsub == vx_p_layout) {
            } else if (valsub is Vx.Ui.Ui.Type_layout vallayout) {
              ischanged = true;
              vx_p_layout = vallayout;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx.Ui.Ui.Type_styletype valtype) {
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pin":
            if (valsub == vx_p_pin) {
            } else if (valsub is Vx.Ui.Ui.Type_pin valpin) {
              ischanged = true;
              vx_p_pin = valpin;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pin"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pointorigin":
            if (valsub == vx_p_pointorigin) {
            } else if (valsub is Vx.Ui.Ui.Type_point valpointorigin) {
              ischanged = true;
              vx_p_pointorigin = valpointorigin;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pointorigin"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pointpos":
            if (valsub == vx_p_pointpos) {
            } else if (valsub is Vx.Ui.Ui.Type_point valpointpos) {
              ischanged = true;
              vx_p_pointpos = valpointpos;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pointpos"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pointrotate":
            if (valsub == vx_p_pointrotate) {
            } else if (valsub is Vx.Ui.Ui.Type_point valpointrotate) {
              ischanged = true;
              vx_p_pointrotate = valpointrotate;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pointrotate"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pointsize":
            if (valsub == vx_p_pointsize) {
            } else if (valsub is Vx.Ui.Ui.Type_point valpointsize) {
              ischanged = true;
              vx_p_pointsize = valpointsize;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pointsize"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":scroll-x":
            if (valsub == vx_p_scroll_x) {
            } else if (valsub is Vx.Core.Type_boolean valscroll_x) {
              ischanged = true;
              vx_p_scroll_x = valscroll_x;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_scroll_x = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("scroll-x"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":scroll-y":
            if (valsub == vx_p_scroll_y) {
            } else if (valsub is Vx.Core.Type_boolean valscroll_y) {
              ischanged = true;
              vx_p_scroll_y = valscroll_y;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_scroll_y = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("scroll-y"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/style", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_style work = new Vx.Ui.Ui.Class_style();
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
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_style;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_style;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "style", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_style e_style = new Vx.Ui.Ui.Class_style();
  public static Vx.Ui.Ui.Type_style t_style = new Vx.Ui.Ui.Class_style();

  /**
   * type: stylelist
   * Universal Stylelist
   * (type stylelist)
   */
  public interface Type_stylelist : Vx.Core.Type_list {
    public List<Vx.Ui.Ui.Type_style> vx_liststyle();
    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_int index);
  }

  public class Class_stylelist : Vx.Core.Class_base, Type_stylelist {

    public List<Vx.Ui.Ui.Type_style> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Ui.Ui.Type_style>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_style output = Vx.Ui.Ui.e_style;
      Vx.Ui.Ui.Class_stylelist list = this;
      int iindex = index.vx_int();
      List<Vx.Ui.Ui.Type_style> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Ui.Ui.Type_style> vx_liststyle() {
      List<Vx.Ui.Ui.Type_style> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_style output = this.vx_style(index);
      return output;
    }

    public override Vx.Ui.Ui.Type_stylelist vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_stylelist output = Vx.Core.vx_copy(Vx.Ui.Ui.e_stylelist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_stylelist output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_stylelist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_style> listval = new List<Vx.Ui.Ui.Type_style>(value.vx_liststyle());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_style allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Ui.Ui.Type_style) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_style)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_stylelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_liststyle());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Ui.Ui.Type_style valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_stylelist work = new Vx.Ui.Ui.Class_stylelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylelist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylelist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_style), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_stylelist e_stylelist = new Vx.Ui.Ui.Class_stylelist();
  public static Vx.Ui.Ui.Type_stylelist t_stylelist = new Vx.Ui.Ui.Class_stylelist();

  /**
   * type: stylemap
   * Universal Stylemap
   * (type stylemap)
   */
  public interface Type_stylemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_mapstyle();
    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_string key);
  }

  public class Class_stylemap : Vx.Core.Class_base, Type_stylemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_style>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_style castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_style> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_style) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_style output = Vx.Ui.Ui.e_style;
      Vx.Ui.Ui.Class_stylemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_style);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_mapstyle() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_style(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_stylemap output = new Vx.Ui.Ui.Class_stylemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_style castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_stylemap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_stylemap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_stylemap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_stylemap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_stylemap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>(value.vx_mapstyle());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_style? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_style valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_style) {
            valany = (Vx.Ui.Ui.Type_style)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_stylemap work = new Vx.Ui.Ui.Class_stylemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylemap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylemap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_style), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_stylemap e_stylemap = new Vx.Ui.Ui.Class_stylemap();
  public static Vx.Ui.Ui.Type_stylemap t_stylemap = new Vx.Ui.Ui.Class_stylemap();

  /**
   * type: stylesheet
   * Universal Stylesheet
   * (type stylesheet)
   */
  public interface Type_stylesheet : Vx.Core.Type_struct {
    public Vx.Ui.Ui.Type_fontfacemap fontfacemap();
    public Vx.Ui.Ui.Type_stylemap stylemap();
  }

  public class Class_stylesheet : Vx.Core.Class_base, Type_stylesheet {

    public Vx.Ui.Ui.Type_fontfacemap? vx_p_fontfacemap = null;

    public Vx.Ui.Ui.Type_fontfacemap fontfacemap() {
      Vx.Ui.Ui.Type_fontfacemap output = Vx.Ui.Ui.e_fontfacemap;
      if (this.vx_p_fontfacemap != null) {
        output = this.vx_p_fontfacemap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylemap? vx_p_stylemap = null;

    public Vx.Ui.Ui.Type_stylemap stylemap() {
      Vx.Ui.Ui.Type_stylemap output = Vx.Ui.Ui.e_stylemap;
      if (this.vx_p_stylemap != null) {
        output = this.vx_p_stylemap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":fontfacemap", this.fontfacemap());
      output.put(":stylemap", this.stylemap());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_stylesheet vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_stylesheet output = Vx.Core.vx_copy(Vx.Ui.Ui.e_stylesheet, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_stylesheet output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_stylesheet value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Ui.Ui.Type_fontfacemap vx_p_fontfacemap = value.fontfacemap();
      Vx.Ui.Ui.Type_stylemap vx_p_stylemap = value.stylemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":fontfacemap");
      validkeys.Add(":stylemap");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":fontfacemap":
            if (valsub == vx_p_fontfacemap) {
            } else if (valsub is Vx.Ui.Ui.Type_fontfacemap valfontfacemap) {
              ischanged = true;
              vx_p_fontfacemap = valfontfacemap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fontfacemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylemap":
            if (valsub == vx_p_stylemap) {
            } else if (valsub is Vx.Ui.Ui.Type_stylemap valstylemap) {
              ischanged = true;
              vx_p_stylemap = valstylemap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylesheet", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_stylesheet work = new Vx.Ui.Ui.Class_stylesheet();
        work.vx_p_fontfacemap = vx_p_fontfacemap;
        work.vx_p_stylemap = vx_p_stylemap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylesheet;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylesheet;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_stylesheet e_stylesheet = new Vx.Ui.Ui.Class_stylesheet();
  public static Vx.Ui.Ui.Type_stylesheet t_stylesheet = new Vx.Ui.Ui.Class_stylesheet();

  /**
   * type: styletype
   * Universal Style Type
   * (type styletype)
   */
  public interface Type_styletype : Vx.Core.Type_struct {
  }

  public class Class_styletype : Vx.Core.Class_base, Type_styletype {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_styletype vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_styletype output = Vx.Core.vx_copy(Vx.Ui.Ui.e_styletype, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_styletype output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_styletype value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_styletype work = new Vx.Ui.Ui.Class_styletype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_styletype;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_styletype;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "styletype", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_styletype e_styletype = new Vx.Ui.Ui.Class_styletype();
  public static Vx.Ui.Ui.Type_styletype t_styletype = new Vx.Ui.Ui.Class_styletype();

  /**
   * type: ui
   * Universal UI Element
   * (type ui)
   */
  public interface Type_ui : Vx.Core.Type_struct {
    public Vx.Core.Type_string uid();
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Type_layout layout();
    public Vx.Core.Type_string path();
    public Vx.Core.Type_boolean hidden();
    public Vx.Core.Type_boolean selected();
    public Vx.Core.Type_boolean selectmulti();
    public Vx.Ui.Ui.Type_style style();
    public Vx.Ui.Ui.Type_stylelist stylelist();
    public Vx.Event.Type_eventmap eventmap();
    public Vx.Core.Type_any data();
    public Vx.Ui.Ui.Type_uimap uimap();
  }

  public class Class_ui : Vx.Core.Class_base, Type_ui {

    public Vx.Core.Type_string? vx_p_uid = null;

    public Vx.Core.Type_string uid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_uid != null) {
        output = this.vx_p_uid;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout? vx_p_layout = null;

    public Vx.Ui.Ui.Type_layout layout() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layout != null) {
        output = this.vx_p_layout;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_path = null;

    public Vx.Core.Type_string path() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_path != null) {
        output = this.vx_p_path;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_hidden = null;

    public Vx.Core.Type_boolean hidden() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_hidden != null) {
        output = this.vx_p_hidden;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_selected = null;

    public Vx.Core.Type_boolean selected() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_selected != null) {
        output = this.vx_p_selected;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_selectmulti = null;

    public Vx.Core.Type_boolean selectmulti() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_selectmulti != null) {
        output = this.vx_p_selectmulti;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_style? vx_p_style = null;

    public Vx.Ui.Ui.Type_style style() {
      Vx.Ui.Ui.Type_style output = Vx.Ui.Ui.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylelist? vx_p_stylelist = null;

    public Vx.Ui.Ui.Type_stylelist stylelist() {
      Vx.Ui.Ui.Type_stylelist output = Vx.Ui.Ui.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_data = null;

    public Vx.Core.Type_any data() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_data != null) {
        output = this.vx_p_data;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_uimap? vx_p_uimap = null;

    public Vx.Ui.Ui.Type_uimap uimap() {
      Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
      if (this.vx_p_uimap != null) {
        output = this.vx_p_uimap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":uid", this.uid());
      output.put(":name", this.name());
      output.put(":layout", this.layout());
      output.put(":path", this.path());
      output.put(":hidden", this.hidden());
      output.put(":selected", this.selected());
      output.put(":selectmulti", this.selectmulti());
      output.put(":style", this.style());
      output.put(":stylelist", this.stylelist());
      output.put(":eventmap", this.eventmap());
      output.put(":data", this.data());
      output.put(":uimap", this.uimap());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_ui output = Vx.Core.vx_copy(Vx.Ui.Ui.e_ui, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_ui output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_ui value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_uid = value.uid();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Ui.Ui.Type_layout vx_p_layout = value.layout();
      Vx.Core.Type_string vx_p_path = value.path();
      Vx.Core.Type_boolean vx_p_hidden = value.hidden();
      Vx.Core.Type_boolean vx_p_selected = value.selected();
      Vx.Core.Type_boolean vx_p_selectmulti = value.selectmulti();
      Vx.Ui.Ui.Type_style vx_p_style = value.style();
      Vx.Ui.Ui.Type_stylelist vx_p_stylelist = value.stylelist();
      Vx.Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Vx.Core.Type_any vx_p_data = value.data();
      Vx.Ui.Ui.Type_uimap vx_p_uimap = value.uimap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":uid");
      validkeys.Add(":name");
      validkeys.Add(":layout");
      validkeys.Add(":path");
      validkeys.Add(":hidden");
      validkeys.Add(":selected");
      validkeys.Add(":selectmulti");
      validkeys.Add(":style");
      validkeys.Add(":stylelist");
      validkeys.Add(":eventmap");
      validkeys.Add(":data");
      validkeys.Add(":uimap");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":uid":
            if (valsub == vx_p_uid) {
            } else if (valsub is Vx.Core.Type_string valuid) {
              ischanged = true;
              vx_p_uid = valuid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_uid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("uid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":layout":
            if (valsub == vx_p_layout) {
            } else if (valsub is Vx.Ui.Ui.Type_layout vallayout) {
              ischanged = true;
              vx_p_layout = vallayout;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("layout"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub is Vx.Core.Type_string valpath) {
              ischanged = true;
              vx_p_path = valpath;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_path = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":hidden":
            if (valsub == vx_p_hidden) {
            } else if (valsub is Vx.Core.Type_boolean valhidden) {
              ischanged = true;
              vx_p_hidden = valhidden;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_hidden = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("hidden"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":selected":
            if (valsub == vx_p_selected) {
            } else if (valsub is Vx.Core.Type_boolean valselected) {
              ischanged = true;
              vx_p_selected = valselected;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_selected = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("selected"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":selectmulti":
            if (valsub == vx_p_selectmulti) {
            } else if (valsub is Vx.Core.Type_boolean valselectmulti) {
              ischanged = true;
              vx_p_selectmulti = valselectmulti;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_selectmulti = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("selectmulti"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Ui.Ui.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Ui.Ui.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":data":
            if (valsub == vx_p_data) {
            } else if (valsub is Vx.Core.Type_any valdata) {
              ischanged = true;
              vx_p_data = valdata;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("data"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":uimap":
            if (valsub == vx_p_uimap) {
            } else if (valsub is Vx.Ui.Ui.Type_uimap valuimap) {
              ischanged = true;
              vx_p_uimap = valuimap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("uimap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/ui", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_ui work = new Vx.Ui.Ui.Class_ui();
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
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "ui", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_ui e_ui = new Vx.Ui.Ui.Class_ui();
  public static Vx.Ui.Ui.Type_ui t_ui = new Vx.Ui.Ui.Class_ui();

  /**
   * type: uiengine
   * Template for uiengine
   * (type uiengine)
   */
  public interface Type_uiengine : Vx.Core.Type_struct {
    public Vx.Ui.Ui.Type_uimap parentmap();
    public Vx.Ui.Ui.Type_layoutengine layoutengine();
    public Vx.Ui.Ui.Type_stylesheet stylesheet();
    public Vx.Ui.Ui.Type_ui ui();
  }

  public class Class_uiengine : Vx.Core.Class_base, Type_uiengine {

    public Vx.Ui.Ui.Type_uimap? vx_p_parentmap = null;

    public Vx.Ui.Ui.Type_uimap parentmap() {
      Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
      if (this.vx_p_parentmap != null) {
        output = this.vx_p_parentmap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layoutengine? vx_p_layoutengine = null;

    public Vx.Ui.Ui.Type_layoutengine layoutengine() {
      Vx.Ui.Ui.Type_layoutengine output = Vx.Ui.Ui.e_layoutengine;
      if (this.vx_p_layoutengine != null) {
        output = this.vx_p_layoutengine;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylesheet? vx_p_stylesheet = null;

    public Vx.Ui.Ui.Type_stylesheet stylesheet() {
      Vx.Ui.Ui.Type_stylesheet output = Vx.Ui.Ui.e_stylesheet;
      if (this.vx_p_stylesheet != null) {
        output = this.vx_p_stylesheet;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_ui? vx_p_ui = null;

    public Vx.Ui.Ui.Type_ui ui() {
      Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
      if (this.vx_p_ui != null) {
        output = this.vx_p_ui;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":parentmap", this.parentmap());
      output.put(":layoutengine", this.layoutengine());
      output.put(":stylesheet", this.stylesheet());
      output.put(":ui", this.ui());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Ui.Ui.Type_uiengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_uiengine output = Vx.Core.vx_copy(Vx.Ui.Ui.e_uiengine, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_uiengine output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_uiengine value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Ui.Ui.Type_uimap vx_p_parentmap = value.parentmap();
      Vx.Ui.Ui.Type_layoutengine vx_p_layoutengine = value.layoutengine();
      Vx.Ui.Ui.Type_stylesheet vx_p_stylesheet = value.stylesheet();
      Vx.Ui.Ui.Type_ui vx_p_ui = value.ui();
      List<string> validkeys = new List<string>();
      validkeys.Add(":parentmap");
      validkeys.Add(":layoutengine");
      validkeys.Add(":stylesheet");
      validkeys.Add(":ui");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":parentmap":
            if (valsub == vx_p_parentmap) {
            } else if (valsub is Vx.Ui.Ui.Type_uimap valparentmap) {
              ischanged = true;
              vx_p_parentmap = valparentmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("parentmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":layoutengine":
            if (valsub == vx_p_layoutengine) {
            } else if (valsub is Vx.Ui.Ui.Type_layoutengine vallayoutengine) {
              ischanged = true;
              vx_p_layoutengine = vallayoutengine;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("layoutengine"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylesheet":
            if (valsub == vx_p_stylesheet) {
            } else if (valsub is Vx.Ui.Ui.Type_stylesheet valstylesheet) {
              ischanged = true;
              vx_p_stylesheet = valstylesheet;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylesheet"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":ui":
            if (valsub == vx_p_ui) {
            } else if (valsub is Vx.Ui.Ui.Type_ui valui) {
              ischanged = true;
              vx_p_ui = valui;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("ui"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uiengine", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_uiengine work = new Vx.Ui.Ui.Class_uiengine();
        work.vx_p_parentmap = vx_p_parentmap;
        work.vx_p_layoutengine = vx_p_layoutengine;
        work.vx_p_stylesheet = vx_p_stylesheet;
        work.vx_p_ui = vx_p_ui;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uiengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uiengine;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_uiengine e_uiengine = new Vx.Ui.Ui.Class_uiengine();
  public static Vx.Ui.Ui.Type_uiengine t_uiengine = new Vx.Ui.Ui.Class_uiengine();

  /**
   * type: uilist
   * List of ui
   * (type uilist)
   */
  public interface Type_uilist : Vx.Core.Type_list {
    public List<Vx.Ui.Ui.Type_ui> vx_listui();
    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_int index);
  }

  public class Class_uilist : Vx.Core.Class_base, Type_uilist {

    public List<Vx.Ui.Ui.Type_ui> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Ui.Ui.Type_ui>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
      Vx.Ui.Ui.Class_uilist list = this;
      int iindex = index.vx_int();
      List<Vx.Ui.Ui.Type_ui> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Ui.Ui.Type_ui> vx_listui() {
      List<Vx.Ui.Ui.Type_ui> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Ui.Ui.Type_ui output = this.vx_ui(index);
      return output;
    }

    public override Vx.Ui.Ui.Type_uilist vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_uilist output = Vx.Core.vx_copy(Vx.Ui.Ui.e_uilist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_uilist output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_uilist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_ui> listval = new List<Vx.Ui.Ui.Type_ui>(value.vx_listui());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_ui allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Ui.Ui.Type_ui) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_ui)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_uilist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listui());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Ui.Ui.Type_ui valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_uilist work = new Vx.Ui.Ui.Class_uilist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uilist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uilist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uilist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_uilist e_uilist = new Vx.Ui.Ui.Class_uilist();
  public static Vx.Ui.Ui.Type_uilist t_uilist = new Vx.Ui.Ui.Class_uilist();

  /**
   * type: uimap
   * Map of ui
   * (type uimap)
   */
  public interface Type_uimap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_mapui();
    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_string key);
  }

  public class Class_uimap : Vx.Core.Class_base, Type_uimap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Ui.Ui.Type_ui>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Ui.Ui.Type_ui castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>(this.vx_p_map);
        if (castval == Vx.Ui.Ui.e_ui) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_string key) {
      Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
      Vx.Ui.Ui.Class_uimap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Ui.Ui.e_ui);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_mapui() {
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_ui(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_uimap output = new Vx.Ui.Ui.Class_uimap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Ui.Ui.Type_ui castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_uimap vx_new(params object[] vals) {
      Vx.Ui.Ui.Type_uimap output = Vx.Core.vx_copy(Vx.Ui.Ui.e_uimap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Type_uimap output = this;
      bool ischanged = false;
      Vx.Ui.Ui.Class_uimap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>(value.vx_mapui());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uimap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_ui? valany = null;
          if (false) {
          } else if (valsub is Vx.Ui.Ui.Type_ui valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Ui.Ui.Type_ui) {
            valany = (Vx.Ui.Ui.Type_ui)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Ui.Ui.Class_uimap work = new Vx.Ui.Ui.Class_uimap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uimap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uimap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/ui/ui", // pkgname
        "uimap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Ui.Ui.Type_uimap e_uimap = new Vx.Ui.Ui.Class_uimap();
  public static Vx.Ui.Ui.Type_uimap t_uimap = new Vx.Ui.Ui.Class_uimap();

  /**
   * Constant: align-center
   * Logical Center Align in parent
   * {align}
   */
  public class Const_align_center {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-center", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_align_center = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: align-left
   * Logical Left Align in parent
   * {align}
   */
  public class Const_align_left {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-left", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_align_left = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: align-right
   * Logical Right Align in parent
   * {align}
   */
  public class Const_align_right {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "align-right", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_align_right = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: flip-x
   * Logical Flip Horizontally
   * {align}
   */
  public class Const_flip_x {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-x", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_flip_x = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: flip-xy
   * Logical Flip Vertically and Horizontally
   * {align}
   */
  public class Const_flip_xy {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-xy", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_flip_xy = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: flip-y
   * Logical Flip Vertically
   * {align}
   */
  public class Const_flip_y {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "flip-y", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "align", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_align output) {
      Vx.Ui.Ui.Class_align outval = (Vx.Ui.Ui.Class_align)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_align c_flip_y = new Vx.Ui.Ui.Class_align();


  /**
   * Constant: layout-app
   * {layout}
   */
  public class Const_layout_app {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-app", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-app")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_app = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-background
   * {layout}
   */
  public class Const_layout_background {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-background", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-background")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_background = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-button
   * {layout}
   */
  public class Const_layout_button {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-button", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-button")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_button = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-combobox
   * {layout}
   */
  public class Const_layout_combobox {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-combobox", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-combobox")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_combobox = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-else
   * {layout}
   */
  public class Const_layout_else {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-else", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-else")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_else = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-flow-columns
   * {layout}
   */
  public class Const_layout_flow_columns {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-columns", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-flow-columns")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_flow_columns = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-flow-item
   * {layout}
   */
  public class Const_layout_flow_item {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-item", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-flow-item")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_flow_item = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-flow-rows
   * {layout}
   */
  public class Const_layout_flow_rows {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-flow-rows", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-flow-rows")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_flow_rows = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-image
   * {layout}
   */
  public class Const_layout_image {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-image", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-image")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_image = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-label
   * {layout}
   */
  public class Const_layout_label {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-label", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-label")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_label = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-main
   * {layout}
   */
  public class Const_layout_main {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-main", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-main")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_main = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-maxpanel
   * {layout}
   */
  public class Const_layout_maxpanel {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-maxpanel", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-maxpanel")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_maxpanel = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-menubar
   * {layout}
   */
  public class Const_layout_menubar {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menubar", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-menubar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_menubar = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-menudrawer
   * {layout}
   */
  public class Const_layout_menudrawer {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-menudrawer", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-menudrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_menudrawer = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-msgbox
   * {layout}
   */
  public class Const_layout_msgbox {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-msgbox", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-msgbox")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_msgbox = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-navbar
   * {layout}
   */
  public class Const_layout_navbar {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navbar", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-navbar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_navbar = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-navdrawer
   * {layout}
   */
  public class Const_layout_navdrawer {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-navdrawer", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-navdrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_navdrawer = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-panel
   * {layout}
   */
  public class Const_layout_panel {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-panel", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-panel")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_panel = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-parallax
   * {layout}
   */
  public class Const_layout_parallax {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-parallax", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-parallax")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_parallax = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-statusbar
   * {layout}
   */
  public class Const_layout_statusbar {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusbar", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-statusbar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_statusbar = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-statusdrawer
   * {layout}
   */
  public class Const_layout_statusdrawer {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-statusdrawer", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-statusdrawer")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_statusdrawer = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-text
   * {layout}
   */
  public class Const_layout_text {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-text", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-text")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_text = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-textentry
   * {layout}
   */
  public class Const_layout_textentry {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-textentry", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-textentry")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_textentry = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-titlebar
   * {layout}
   */
  public class Const_layout_titlebar {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "layout-titlebar", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout value = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("layout-titlebar")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_fn_layout = value.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_titlebar = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: pin-bottom
   * {pin}
   */
  public class Const_pin_bottom {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-bottom", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_bottom = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-center
   * {pin}
   */
  public class Const_pin_center {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_center = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-center-h
   * {pin}
   */
  public class Const_pin_center_h {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-h", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_center_h = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-center-v
   * {pin}
   */
  public class Const_pin_center_v {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-center-v", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_center_v = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-expand
   * {pin}
   */
  public class Const_pin_expand {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-expand", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_expand = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-left
   * {pin}
   */
  public class Const_pin_left {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-left", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_left = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-right
   * {pin}
   */
  public class Const_pin_right {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-right", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_right = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: pin-top
   * {pin}
   */
  public class Const_pin_top {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pin-top", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pin", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pin output) {
      Vx.Ui.Ui.Class_pin outval = (Vx.Ui.Ui.Class_pin)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pin c_pin_top = new Vx.Ui.Ui.Class_pin();


  /**
   * Constant: point-center
   * {point}
   */
  public class Const_point_center {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-center", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_point output) {
      Vx.Ui.Ui.Class_point outval = (Vx.Ui.Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_point c_point_center = new Vx.Ui.Ui.Class_point();


  /**
   * Constant: point-lefttop
   * {point}
   */
  public class Const_point_lefttop {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-lefttop", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_point output) {
      Vx.Ui.Ui.Class_point outval = (Vx.Ui.Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_point c_point_lefttop = new Vx.Ui.Ui.Class_point();


  /**
   * Constant: point-rightbottom
   * {point}
   */
  public class Const_point_rightbottom {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "point-rightbottom", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "point", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_point output) {
      Vx.Ui.Ui.Class_point outval = (Vx.Ui.Ui.Class_point)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_point c_point_rightbottom = new Vx.Ui.Ui.Class_point();


  /**
   * Constant: pointtype-absolute
   * {pointtype}
   */
  public class Const_pointtype_absolute {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-absolute", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pointtype output) {
      Vx.Ui.Ui.Class_pointtype outval = (Vx.Ui.Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pointtype c_pointtype_absolute = new Vx.Ui.Ui.Class_pointtype();


  /**
   * Constant: pointtype-percent
   * {pointtype}
   */
  public class Const_pointtype_percent {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-percent", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pointtype output) {
      Vx.Ui.Ui.Class_pointtype outval = (Vx.Ui.Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pointtype c_pointtype_percent = new Vx.Ui.Ui.Class_pointtype();


  /**
   * Constant: pointtype-relative
   * {pointtype}
   */
  public class Const_pointtype_relative {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "pointtype-relative", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "pointtype", // name
          ":int", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_pointtype output) {
      Vx.Ui.Ui.Class_pointtype outval = (Vx.Ui.Ui.Class_pointtype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_pointtype c_pointtype_relative = new Vx.Ui.Ui.Class_pointtype();


  /**
   * Constant: styletype-custom
   * {styletype}
   */
  public class Const_styletype_custom {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-custom", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_styletype output) {
      Vx.Ui.Ui.Class_styletype outval = (Vx.Ui.Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_styletype c_styletype_custom = new Vx.Ui.Ui.Class_styletype();


  /**
   * Constant: styletype-shared
   * {styletype}
   */
  public class Const_styletype_shared {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-shared", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_styletype output) {
      Vx.Ui.Ui.Class_styletype outval = (Vx.Ui.Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_styletype c_styletype_shared = new Vx.Ui.Ui.Class_styletype();


  /**
   * Constant: styletype-system
   * {styletype}
   */
  public class Const_styletype_system {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/ui/ui", // pkgname
        "styletype-system", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "styletype", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
      return output;
    }

    public static void const_new(Vx.Ui.Ui.Type_styletype output) {
      Vx.Ui.Ui.Class_styletype outval = (Vx.Ui.Ui.Class_styletype)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Ui.Ui.Type_styletype c_styletype_system = new Vx.Ui.Ui.Class_styletype();

  /**
   * @function boolean_layout_from_ui_parent_selected
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {boolean} selected
   * @return {boolean}
   * (func boolean-layout<-ui-parent-selected)
   */
  public interface Func_boolean_layout_from_ui_parent_selected : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layout_from_ui_parent_selected(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean selected);
  }

  public class Class_boolean_layout_from_ui_parent_selected : Vx.Core.Class_base, Func_boolean_layout_from_ui_parent_selected {

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_selected vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected output = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected output = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-selected", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layout_from_ui_parent_selected;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layout_from_ui_parent_selected;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_boolean selected = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layout_from_ui_parent_selected(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean selected) {
      return Vx.Ui.Ui.f_boolean_layout_from_ui_parent_selected(context, ui, parent, selected);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_selected e_boolean_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();
  public static Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_selected t_boolean_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();

  public static Vx.Core.Type_boolean f_boolean_layout_from_ui_parent_selected(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean selected) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Type_ui uiselected = Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":selected"),
            selected
          )
        );
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uiselected, parent);
        Vx.Ui.Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        Vx.Core.Type_any output_1 = Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutselected, uiselected);
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
  public interface Func_boolean_layout_from_ui_parent_visible : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layout_from_ui_parent_visible(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean visible);
  }

  public class Class_boolean_layout_from_ui_parent_visible : Vx.Core.Class_base, Func_boolean_layout_from_ui_parent_visible {

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_visible vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible output = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible output = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layout<-ui-parent-visible", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layout_from_ui_parent_visible;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layout_from_ui_parent_visible;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_boolean visible = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layout_from_ui_parent_visible(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean visible) {
      return Vx.Ui.Ui.f_boolean_layout_from_ui_parent_visible(context, ui, parent, visible);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_visible e_boolean_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();
  public static Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_visible t_boolean_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();

  public static Vx.Core.Type_boolean f_boolean_layout_from_ui_parent_visible(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean visible) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Type_ui uivisible = Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":hidden"),
            Vx.Core.f_not(visible)
          )
        );
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uivisible, parent);
        Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui fn_layoutvisible = layoutengine.boolean_layoutvisible();
        Vx.Core.Type_any output_1 = Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutvisible, uivisible);
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
  public interface Func_boolean_layoutaddchild_from_ui_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutaddchild_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_boolean_layoutaddchild_from_ui_parent : Vx.Core.Class_base, Func_boolean_layoutaddchild_from_ui_parent {

    public override Vx.Ui.Ui.Func_boolean_layoutaddchild_from_ui_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutaddchild<-ui-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutaddchild_from_ui_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutaddchild_from_ui_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutaddchild_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_boolean_layoutaddchild_from_ui_parent(context, uiarg, parent);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutaddchild_from_ui_parent e_boolean_layoutaddchild_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();
  public static Vx.Ui.Ui.Func_boolean_layoutaddchild_from_ui_parent t_boolean_layoutaddchild_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_layoutaddchild_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui ui2 = Vx.Ui.Ui.f_ui_addlayout_from_ui(context, uiarg);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui2, parent);
        Vx.Ui.Ui.Type_ui ui3 = Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(
          ui2,
          Vx.Core.f_empty(
            Vx.Ui.Ui.t_ui
          ),
          parent
        );
        Vx.Core.Type_any output_1 = iswrite;
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
  public interface Func_boolean_layoutremove_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutremove_from_ui : Vx.Core.Class_base, Func_boolean_layoutremove_from_ui {

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutremove_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_layoutremove_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_layoutremove_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_layoutremove_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui e_boolean_layoutremove_from_ui = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();
  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui t_boolean_layoutremove_from_ui = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
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
  public interface Func_boolean_layoutremove_from_ui_keys : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_keys(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_stringlist keys);
  }

  public class Class_boolean_layoutremove_from_ui_keys : Vx.Core.Class_base, Func_boolean_layoutremove_from_ui_keys {

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_keys vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-keys", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui_keys;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutremove_from_ui_keys;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_stringlist keys = Vx.Core.f_any_from_any(Vx.Core.t_stringlist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_keys(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_stringlist keys) {
      return Vx.Ui.Ui.f_boolean_layoutremove_from_ui_keys(context, ui, keys);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_keys e_boolean_layoutremove_from_ui_keys = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();
  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_keys t_boolean_layoutremove_from_ui_keys = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui_keys(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_stringlist keys) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_booleanlist writelist = Vx.Core.f_list_from_list_1(
          Vx.Core.t_booleanlist,
          keys,
          Vx.Core.t_any_from_any.vx_fn_new((key_any) => {
            Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_let(
                  Vx.Core.t_boolean,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Ui.Ui.Type_ui childui = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, uimap, key);
                    Vx.Core.Type_any output_2 = Vx.Ui.Ui.f_boolean_layoutremove_from_ui_parent(context, childui, ui);
                    return output_2;
                  })
                );
            return output_1;
          })
        );
        Vx.Core.Type_any output_3 = Vx.Core.f_and_1(writelist);
        return output_3;
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
  public interface Func_boolean_layoutremove_from_ui_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_boolean_layoutremove_from_ui_parent : Vx.Core.Class_base, Func_boolean_layoutremove_from_ui_parent {

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutremove_from_ui_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_boolean_layoutremove_from_ui_parent(context, ui, parent);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_parent e_boolean_layoutremove_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();
  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_parent t_boolean_layoutremove_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Core.Type_string uid = ui.uid();
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_writeremove_from_ui_uid(parent, uid);
        Vx.Ui.Ui.Func_boolean_layoutremove_from_ui fn_layoutremove = layoutengine.boolean_layoutremove();
        Vx.Core.Type_any output_1 = Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutremove, ui);
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
  public interface Func_boolean_layoutremove_from_ui_start_end : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_start_end(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int start, Vx.Core.Type_int end);
  }

  public class Class_boolean_layoutremove_from_ui_start_end : Vx.Core.Class_base, Func_boolean_layoutremove_from_ui_start_end {

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_start_end vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end output = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutremove<-ui-start-end", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui_start_end;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutremove_from_ui_start_end;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int start = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int end = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutremove_from_ui_start_end(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int start, Vx.Core.Type_int end) {
      return Vx.Ui.Ui.f_boolean_layoutremove_from_ui_start_end(context, ui, start, end);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_start_end e_boolean_layoutremove_from_ui_start_end = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();
  public static Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_start_end t_boolean_layoutremove_from_ui_start_end = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui_start_end(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int start, Vx.Core.Type_int end) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_stringlist keys = Vx.Core.f_stringlist_from_map(uimap);
        Vx.Core.Type_stringlist subkeys = Vx.Collection.f_list_from_list_start_end(Vx.Core.t_stringlist, keys, start, end);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_boolean_layoutremove_from_ui_keys(context, ui, subkeys);
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
  public interface Func_boolean_layoutselected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutselected_from_ui : Vx.Core.Class_base, Func_boolean_layoutselected_from_ui {

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutselected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutselected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_layoutselected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_layoutselected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_layoutselected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui e_boolean_layoutselected_from_ui = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();
  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui t_boolean_layoutselected_from_ui = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();

  public static Vx.Core.Type_boolean f_boolean_layoutselected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
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
  public interface Func_boolean_layoutselected_from_ui_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_boolean_layoutselected_from_ui_parent : Vx.Core.Class_base, Func_boolean_layoutselected_from_ui_parent {

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutselected_from_ui_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutselected_from_ui_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_boolean_layoutselected_from_ui_parent(context, ui, parent);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_parent e_boolean_layoutselected_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();
  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_parent t_boolean_layoutselected_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_layoutselected_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui, parent);
        Vx.Ui.Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        Vx.Core.Type_any output_1 = Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutselected, ui);
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
  public interface Func_boolean_layoutselected_from_ui_selected : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected);
  }

  public class Class_boolean_layoutselected_from_ui_selected : Vx.Core.Class_base, Func_boolean_layoutselected_from_ui_selected {

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_selected vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected output = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutselected<-ui-selected", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutselected_from_ui_selected;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutselected_from_ui_selected;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int selected = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_layoutselected_from_ui_selected(ui, selected);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutselected_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected) {
      return Vx.Ui.Ui.f_boolean_layoutselected_from_ui_selected(ui, selected);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_selected e_boolean_layoutselected_from_ui_selected = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();
  public static Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_selected t_boolean_layoutselected_from_ui_selected = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();

  public static Vx.Core.Type_boolean f_boolean_layoutselected_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_layoutvisible_from_ui
   * Writes to an html node adding or removing the hidden class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutvisible<-ui)
   */
  public interface Func_boolean_layoutvisible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutvisible_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutvisible_from_ui : Vx.Core.Class_base, Func_boolean_layoutvisible_from_ui {

    public override Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui output = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-layoutvisible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_layoutvisible_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_layoutvisible_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_layoutvisible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_layoutvisible_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutvisible_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_layoutvisible_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui e_boolean_layoutvisible_from_ui = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();
  public static Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui t_boolean_layoutvisible_from_ui = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();

  public static Vx.Core.Type_boolean f_boolean_layoutvisible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_print
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-print)
   */
  public interface Func_boolean_print : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_print(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_print : Vx.Core.Class_base, Func_boolean_print {

    public override Vx.Ui.Ui.Func_boolean_print vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_print output = new Vx.Ui.Ui.Class_boolean_print();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_print output = new Vx.Ui.Ui.Class_boolean_print();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-print", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_print;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_print;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_print(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_print(context, ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_print(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_print(context, ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_print e_boolean_print = new Vx.Ui.Ui.Class_boolean_print();
  public static Vx.Ui.Ui.Func_boolean_print t_boolean_print = new Vx.Ui.Ui.Class_boolean_print();

  public static Vx.Core.Type_boolean f_boolean_print(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Func_boolean_print fn_print = layoutengine.boolean_print();
        Vx.Core.Type_any output_1 = Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_print, context, ui);
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
  public interface Func_boolean_removestate_uiapp : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_removestate_uiapp(Vx.Core.Type_context context);
  }

  public class Class_boolean_removestate_uiapp : Vx.Core.Class_base, Func_boolean_removestate_uiapp {

    public override Vx.Ui.Ui.Func_boolean_removestate_uiapp vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_removestate_uiapp output = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_removestate_uiapp output = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-removestate-uiapp", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_removestate_uiapp;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_removestate_uiapp;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_removestate_uiapp(context);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_removestate_uiapp(Vx.Core.Type_context context) {
      return Vx.Ui.Ui.f_boolean_removestate_uiapp(context);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_removestate_uiapp e_boolean_removestate_uiapp = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();
  public static Vx.Ui.Ui.Func_boolean_removestate_uiapp t_boolean_removestate_uiapp = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();

  public static Vx.Core.Type_boolean f_boolean_removestate_uiapp(Vx.Core.Type_context context) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.State.f_boolean_removestate_from_name(context, Vx.Core.vx_new_string(":uiapp"));
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
  public interface Func_boolean_write_from_ui_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_ui_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_boolean_write_from_ui_parent : Vx.Core.Class_base, Func_boolean_write_from_ui_parent {

    public override Vx.Ui.Ui.Func_boolean_write_from_ui_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_write_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_write_from_ui_parent output = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-write<-ui-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_write_from_ui_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_write_from_ui_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui, parent);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_ui_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui, parent);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_write_from_ui_parent e_boolean_write_from_ui_parent = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();
  public static Vx.Ui.Ui.Func_boolean_write_from_ui_parent t_boolean_write_from_ui_parent = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_write_from_ui_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_uimap uimap = parent.uimap();
        Vx.Core.Type_any output_1 = Vx.Core.f_boolean_write_from_map_name_value(uimap, uid, ui);
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
  public interface Func_boolean_writeremove_from_ui_uid : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_writeremove_from_ui_uid(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string uid);
  }

  public class Class_boolean_writeremove_from_ui_uid : Vx.Core.Class_base, Func_boolean_writeremove_from_ui_uid {

    public override Vx.Ui.Ui.Func_boolean_writeremove_from_ui_uid vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid output = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid output = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writeremove<-ui-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_writeremove_from_ui_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_writeremove_from_ui_uid;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_boolean_writeremove_from_ui_uid(uiarg, uid);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeremove_from_ui_uid(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string uid) {
      return Vx.Ui.Ui.f_boolean_writeremove_from_ui_uid(uiarg, uid);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_writeremove_from_ui_uid e_boolean_writeremove_from_ui_uid = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();
  public static Vx.Ui.Ui.Func_boolean_writeremove_from_ui_uid t_boolean_writeremove_from_ui_uid = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();

  public static Vx.Core.Type_boolean f_boolean_writeremove_from_ui_uid(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string uid) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Core.Type_any output_1 = Vx.Core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          Vx.Core.f_empty(
            Vx.Ui.Ui.t_ui
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
  public interface Func_boolean_writestate_from_ui : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writestate_from_ui : Vx.Core.Class_base, Func_boolean_writestate_from_ui {

    public override Vx.Ui.Ui.Func_boolean_writestate_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_ui output = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_ui output = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_writestate_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_writestate_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_writestate_from_ui(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_writestate_from_ui(context, ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_writestate_from_ui(context, ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();
  public static Vx.Ui.Ui.Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_ui uiapp = Vx.Ui.Ui.f_ui_readstate_uiapp(context);
        Vx.Core.Type_string parentuid = Vx.Ui.Ui.f_string_parentuid_from_uid(uid);
        Vx.Ui.Ui.Type_ui parentui = Vx.Core.f_if_2(
          Vx.Ui.Ui.t_ui,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_string(""), parentuid);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return uiapp;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Ui.Ui.f_ui_from_ui_find(uiapp, parentuid);
              })
            )
          )
        );
        Vx.Core.Type_boolean isfound = Vx.Core.f_notempty_1(parentui);
        Vx.Core.Type_boolean iswrite = Vx.Core.f_if_2(
          Vx.Core.t_boolean,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return isfound;
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui, parentui);
              })
            )
          )
        );
        Vx.Core.Type_any output_1 = isfound;
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
  public interface Func_boolean_writestate_from_uiapp : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_uiapp(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writestate_from_uiapp : Vx.Core.Class_base, Func_boolean_writestate_from_uiapp {

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiapp vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_uiapp output = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_uiapp output = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiapp", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_writestate_from_uiapp;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_writestate_from_uiapp;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(context, ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_uiapp(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_boolean_writestate_from_uiapp(context, ui);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_writestate_from_uiapp e_boolean_writestate_from_uiapp = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();
  public static Vx.Ui.Ui.Func_boolean_writestate_from_uiapp t_boolean_writestate_from_uiapp = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_uiapp(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.State.f_boolean_writestate_from_name_value(context, Vx.Core.vx_new_string(":uiapp"), ui);
    return output;
  }

  /**
   * @function boolean_writestate_from_uiengine
   * Writes the uiengine to state
   * @param  {uiengine} uiengine
   * @return {boolean}
   * (func boolean-writestate<-uiengine)
   */
  public interface Func_boolean_writestate_from_uiengine : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_uiengine(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine);
  }

  public class Class_boolean_writestate_from_uiengine : Vx.Core.Class_base, Func_boolean_writestate_from_uiengine {

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_uiengine output = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_boolean_writestate_from_uiengine output = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiengine", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_boolean_writestate_from_uiengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_boolean_writestate_from_uiengine;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uiengine inputval = (Vx.Ui.Ui.Type_uiengine)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_boolean_writestate_from_uiengine(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_uiengine uiengine = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uiengine, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_boolean_writestate_from_uiengine(context, uiengine);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_uiengine(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine) {
      return Vx.Ui.Ui.f_boolean_writestate_from_uiengine(context, uiengine);
    }

  }

  public static Vx.Ui.Ui.Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();
  public static Vx.Ui.Ui.Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_uiengine(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.State.f_boolean_writestate_from_name_value(context, Vx.Core.vx_new_string(":uiengine"), uiengine);
    return output;
  }

  /**
   * @function fontfacemap_from_fontfacelist
   * Returns a fontfacemap from a fontfacelist
   * @param  {fontfacelist} fontfacelist
   * @return {fontfacemap}
   * (func fontfacemap<-fontfacelist)
   */
  public interface Func_fontfacemap_from_fontfacelist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(Vx.Ui.Ui.Type_fontfacelist fontfacelist);
  }

  public class Class_fontfacemap_from_fontfacelist : Vx.Core.Class_base, Func_fontfacemap_from_fontfacelist {

    public override Vx.Ui.Ui.Func_fontfacemap_from_fontfacelist vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist output = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist output = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "fontfacemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_fontface), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_fontfacemap_from_fontfacelist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_fontfacemap_from_fontfacelist;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_fontfacelist inputval = (Vx.Ui.Ui.Type_fontfacelist)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_fontfacemap_from_fontfacelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_fontfacelist fontfacelist = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontfacelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
      return output;
    }

    public Vx.Ui.Ui.Type_fontfacemap vx_fontfacemap_from_fontfacelist(Vx.Ui.Ui.Type_fontfacelist fontfacelist) {
      return Vx.Ui.Ui.f_fontfacemap_from_fontfacelist(fontfacelist);
    }

  }

  public static Vx.Ui.Ui.Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();
  public static Vx.Ui.Ui.Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();

  public static Vx.Ui.Ui.Type_fontfacemap f_fontfacemap_from_fontfacelist(Vx.Ui.Ui.Type_fontfacelist fontfacelist) {
    Vx.Ui.Ui.Type_fontfacemap output = Vx.Ui.Ui.e_fontfacemap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_fontfacemap,
      fontfacelist,
      Vx.Core.t_any_from_any.vx_fn_new((fontface_any) => {
        Vx.Ui.Ui.Type_fontface fontface = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontface, fontface_any);
        Vx.Core.Type_any output_1 = 
          fontface.name();
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
  public interface Func_int_child_from_ui_uid : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_int vx_int_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid);
  }

  public class Class_int_child_from_ui_uid : Vx.Core.Class_base, Func_int_child_from_ui_uid {

    public override Vx.Ui.Ui.Func_int_child_from_ui_uid vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_int_child_from_ui_uid output = new Vx.Ui.Ui.Class_int_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_int_child_from_ui_uid output = new Vx.Ui.Ui.Class_int_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-child<-ui-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_int_child_from_ui_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_int_child_from_ui_uid;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_int_child_from_ui_uid(ui, uid);
      return output;
    }

    public Vx.Core.Type_int vx_int_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
      return Vx.Ui.Ui.f_int_child_from_ui_uid(ui, uid);
    }

  }

  public static Vx.Ui.Ui.Func_int_child_from_ui_uid e_int_child_from_ui_uid = new Vx.Ui.Ui.Class_int_child_from_ui_uid();
  public static Vx.Ui.Ui.Func_int_child_from_ui_uid t_int_child_from_ui_uid = new Vx.Ui.Ui.Class_int_child_from_ui_uid();

  public static Vx.Core.Type_int f_int_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_any output_1 = Vx.Collection.f_int_from_map_key(uimap, uid);
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
  public interface Func_int_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_int_selected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_int_selected_from_ui : Vx.Core.Class_base, Func_int_selected_from_ui {

    public override Vx.Ui.Ui.Func_int_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_int_selected_from_ui output = new Vx.Ui.Ui.Class_int_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_int_selected_from_ui output = new Vx.Ui.Ui.Class_int_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_int_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_int_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_int_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_int_selected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_int vx_int_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_int_selected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_int_selected_from_ui e_int_selected_from_ui = new Vx.Ui.Ui.Class_int_selected_from_ui();
  public static Vx.Ui.Ui.Func_int_selected_from_ui t_int_selected_from_ui = new Vx.Ui.Ui.Class_int_selected_from_ui();

  public static Vx.Core.Type_int f_int_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = Vx.Ui.Ui.f_string_selected_from_ui(ui);
        Vx.Core.Type_stringlist uidlist = Vx.Ui.Ui.f_stringlist_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Collection.f_int_from_stringlist_find(uidlist, uid);
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
  public interface Func_int_visible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_int_visible_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_int_visible_from_ui : Vx.Core.Class_base, Func_int_visible_from_ui {

    public override Vx.Ui.Ui.Func_int_visible_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_int_visible_from_ui output = new Vx.Ui.Ui.Class_int_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_int_visible_from_ui output = new Vx.Ui.Ui.Class_int_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "int-visible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_int_visible_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_int_visible_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_int_visible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_int_visible_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_int vx_int_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_int_visible_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_int_visible_from_ui e_int_visible_from_ui = new Vx.Ui.Ui.Class_int_visible_from_ui();
  public static Vx.Ui.Ui.Func_int_visible_from_ui t_int_visible_from_ui = new Vx.Ui.Ui.Class_int_visible_from_ui();

  public static Vx.Core.Type_int f_int_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_intlist intlist = Vx.Ui.Ui.f_intlist_visible_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_first_from_list(Vx.Core.t_int, intlist);
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
  public interface Func_intlist_visible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_intlist vx_intlist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg);
  }

  public class Class_intlist_visible_from_ui : Vx.Core.Class_base, Func_intlist_visible_from_ui {

    public override Vx.Ui.Ui.Func_intlist_visible_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_intlist_visible_from_ui output = new Vx.Ui.Ui.Class_intlist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_intlist_visible_from_ui output = new Vx.Ui.Ui.Class_intlist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "intlist-visible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "intlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_int), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_intlist_visible_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_intlist_visible_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_intlist_visible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_intlist_visible_from_ui(uiarg);
      return output;
    }

    public Vx.Core.Type_intlist vx_intlist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
      return Vx.Ui.Ui.f_intlist_visible_from_ui(uiarg);
    }

  }

  public static Vx.Ui.Ui.Func_intlist_visible_from_ui e_intlist_visible_from_ui = new Vx.Ui.Ui.Class_intlist_visible_from_ui();
  public static Vx.Ui.Ui.Func_intlist_visible_from_ui t_intlist_visible_from_ui = new Vx.Ui.Ui.Class_intlist_visible_from_ui();

  public static Vx.Core.Type_intlist f_intlist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Core.Type_intlist output = Vx.Core.e_intlist;
    output = Vx.Core.f_let(
      Vx.Core.t_intlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        Vx.Ui.Ui.Type_uilist intlist = Vx.Core.f_list_from_list_intany(
          Vx.Ui.Ui.t_uilist,
          uilist,
          Vx.Core.t_any_from_int_any.vx_fn_new((pos_any, subui_any) => {
            Vx.Core.Type_int pos = Vx.Core.f_any_from_any(Vx.Core.t_int, pos_any);
            Vx.Ui.Ui.Type_ui subui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, subui_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_if_2(
                  Vx.Core.t_int,
                  Vx.Core.vx_new(
                    Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        return Vx.Core.f_not(
                          subui.hidden()
                        );
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        return pos;
                      })
                    )
                  )
                );
            return output_1;
          })
        );
        Vx.Core.Type_any output_3 = Vx.Collection.f_list_from_list_filter(
          Vx.Core.t_intlist,
          intlist,
          Vx.Core.t_any_from_any.vx_fn_new((pos_any) => {
            Vx.Core.Type_int pos = Vx.Core.f_any_from_any(Vx.Core.t_int, pos_any);
            Vx.Core.Type_any output_2 = pos;
            return output_2;
          })
        );
        return output_3;
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
  public interface Func_layout_from_style : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_layout vx_layout_from_style(Vx.Ui.Ui.Type_style style);
  }

  public class Class_layout_from_style : Vx.Core.Class_base, Func_layout_from_style {

    public override Vx.Ui.Ui.Func_layout_from_style vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_style output = new Vx.Ui.Ui.Class_layout_from_style();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_style output = new Vx.Ui.Ui.Class_layout_from_style();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-style", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layout_from_style;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layout_from_style;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_style inputval = (Vx.Ui.Ui.Type_style)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_layout_from_style(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_style style = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_layout_from_style(style);
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout_from_style(Vx.Ui.Ui.Type_style style) {
      return Vx.Ui.Ui.f_layout_from_style(style);
    }

  }

  public static Vx.Ui.Ui.Func_layout_from_style e_layout_from_style = new Vx.Ui.Ui.Class_layout_from_style();
  public static Vx.Ui.Ui.Func_layout_from_style t_layout_from_style = new Vx.Ui.Ui.Class_layout_from_style();

  public static Vx.Ui.Ui.Type_layout f_layout_from_style(Vx.Ui.Ui.Type_style style) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
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
  public interface Func_layout_from_ui : Vx.Core.Func_any_from_any_context {
    public Vx.Ui.Ui.Type_layout vx_layout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_layout_from_ui : Vx.Core.Class_base, Func_layout_from_ui {

    public override Vx.Ui.Ui.Func_layout_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui output = new Vx.Ui.Ui.Class_layout_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui output = new Vx.Ui.Ui.Class_layout_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layout_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layout_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_layout_from_ui(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_layout_from_ui(context, ui);
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_layout_from_ui(context, ui);
    }

  }

  public static Vx.Ui.Ui.Func_layout_from_ui e_layout_from_ui = new Vx.Ui.Ui.Class_layout_from_ui();
  public static Vx.Ui.Ui.Func_layout_from_ui t_layout_from_ui = new Vx.Ui.Ui.Class_layout_from_ui();

  public static Vx.Ui.Ui.Type_layout f_layout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layout,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
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
  public interface Func_layout_from_ui_layoutengine : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_layout vx_layout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine);
  }

  public class Class_layout_from_ui_layoutengine : Vx.Core.Class_base, Func_layout_from_ui_layoutengine {

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui_layoutengine output = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui_layoutengine output = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutengine", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layout_from_ui_layoutengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layout_from_ui_layoutengine;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutengine, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
      return Vx.Ui.Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
    }

  }

  public static Vx.Ui.Ui.Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();
  public static Vx.Ui.Ui.Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();

  public static Vx.Ui.Ui.Type_layout f_layout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layout,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Vx.Ui.Ui.Type_layout layoutelse = layoutengine.layoutelse();
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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
  public interface Func_layout_from_ui_layoutmap_else : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_layout vx_layout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse);
  }

  public class Class_layout_from_ui_layoutmap_else : Vx.Core.Class_base, Func_layout_from_ui_layoutmap_else {

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutmap_else vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else output = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else output = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layout_from_ui_layoutmap_else;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layout_from_ui_layoutmap_else;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_layoutmap layoutmap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_layout layoutelse = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_layout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
      return Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
    }

  }

  public static Vx.Ui.Ui.Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();
  public static Vx.Ui.Ui.Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();

  public static Vx.Ui.Ui.Type_layout f_layout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layout,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_style style = ui.style();
        Vx.Ui.Ui.Type_layout layout = Vx.Ui.Ui.f_layout_from_style(style);
        Vx.Core.Type_string layname = layout.name();
        Vx.Ui.Ui.Type_layout layout1 = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_layout, layoutmap, layname);
        Vx.Ui.Ui.Type_layout layout2 = Vx.Core.f_if_1(
          Vx.Ui.Ui.t_layout,
          Vx.Core.f_notempty_1(layout1),
          layout1,
          layoutelse
        );
        Vx.Core.Type_any output_1 = layout2;
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
  public interface Func_layoutengine_readstate : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_layoutengine vx_layoutengine_readstate(Vx.Core.Type_context context);
  }

  public class Class_layoutengine_readstate : Vx.Core.Class_base, Func_layoutengine_readstate {

    public override Vx.Ui.Ui.Func_layoutengine_readstate vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layoutengine_readstate output = new Vx.Ui.Ui.Class_layoutengine_readstate();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layoutengine_readstate output = new Vx.Ui.Ui.Class_layoutengine_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutengine-readstate", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layoutengine_readstate;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layoutengine_readstate;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_layoutengine_readstate(context);
      return output;
    }

    public Vx.Ui.Ui.Type_layoutengine vx_layoutengine_readstate(Vx.Core.Type_context context) {
      return Vx.Ui.Ui.f_layoutengine_readstate(context);
    }

  }

  public static Vx.Ui.Ui.Func_layoutengine_readstate e_layoutengine_readstate = new Vx.Ui.Ui.Class_layoutengine_readstate();
  public static Vx.Ui.Ui.Func_layoutengine_readstate t_layoutengine_readstate = new Vx.Ui.Ui.Class_layoutengine_readstate();

  public static Vx.Ui.Ui.Type_layoutengine f_layoutengine_readstate(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_layoutengine output = Vx.Ui.Ui.e_layoutengine;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layoutengine,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
        Vx.Core.Type_any output_1 = uiengine.layoutengine();
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
  public interface Func_layoutmap_from_layoutlist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_layoutmap vx_layoutmap_from_layoutlist(Vx.Ui.Ui.Type_layoutlist layoutlist);
  }

  public class Class_layoutmap_from_layoutlist : Vx.Core.Class_base, Func_layoutmap_from_layoutlist {

    public override Vx.Ui.Ui.Func_layoutmap_from_layoutlist vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_layoutmap_from_layoutlist output = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_layoutmap_from_layoutlist output = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_layout), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_layoutmap_from_layoutlist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_layoutmap_from_layoutlist;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_layoutlist inputval = (Vx.Ui.Ui.Type_layoutlist)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_layoutmap_from_layoutlist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_layoutlist layoutlist = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_layoutmap_from_layoutlist(layoutlist);
      return output;
    }

    public Vx.Ui.Ui.Type_layoutmap vx_layoutmap_from_layoutlist(Vx.Ui.Ui.Type_layoutlist layoutlist) {
      return Vx.Ui.Ui.f_layoutmap_from_layoutlist(layoutlist);
    }

  }

  public static Vx.Ui.Ui.Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();
  public static Vx.Ui.Ui.Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();

  public static Vx.Ui.Ui.Type_layoutmap f_layoutmap_from_layoutlist(Vx.Ui.Ui.Type_layoutlist layoutlist) {
    Vx.Ui.Ui.Type_layoutmap output = Vx.Ui.Ui.e_layoutmap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_layoutmap,
      layoutlist,
      Vx.Core.t_any_from_any.vx_fn_new((layout_any) => {
        Vx.Ui.Ui.Type_layout layout = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, layout_any);
        Vx.Core.Type_any output_1 = 
          layout.name();
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
  public interface Func_string_parentuid_from_uid : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_parentuid_from_uid(Vx.Core.Type_string uid);
  }

  public class Class_string_parentuid_from_uid : Vx.Core.Class_base, Func_string_parentuid_from_uid {

    public override Vx.Ui.Ui.Func_string_parentuid_from_uid vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_string_parentuid_from_uid output = new Vx.Ui.Ui.Class_string_parentuid_from_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_string_parentuid_from_uid output = new Vx.Ui.Ui.Class_string_parentuid_from_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-parentuid<-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_string_parentuid_from_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_string_parentuid_from_uid;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_string_parentuid_from_uid(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_string_parentuid_from_uid(uid);
      return output;
    }

    public Vx.Core.Type_string vx_string_parentuid_from_uid(Vx.Core.Type_string uid) {
      return Vx.Ui.Ui.f_string_parentuid_from_uid(uid);
    }

  }

  public static Vx.Ui.Ui.Func_string_parentuid_from_uid e_string_parentuid_from_uid = new Vx.Ui.Ui.Class_string_parentuid_from_uid();
  public static Vx.Ui.Ui.Func_string_parentuid_from_uid t_string_parentuid_from_uid = new Vx.Ui.Ui.Class_string_parentuid_from_uid();

  public static Vx.Core.Type_string f_string_parentuid_from_uid(Vx.Core.Type_string uid) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int lastpos = Vx.Type.f_int_from_string_findlast(uid, Vx.Core.vx_new_string("/"));
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_gt(lastpos, Vx.Core.vx_new_int(0));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Type.f_string_from_string_end(
                  uid,
                  Vx.Core.f_minus(lastpos, Vx.Core.vx_new_int(1))
                );
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
  public interface Func_string_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_selected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_string_selected_from_ui : Vx.Core.Class_base, Func_string_selected_from_ui {

    public override Vx.Ui.Ui.Func_string_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_string_selected_from_ui output = new Vx.Ui.Ui.Class_string_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_string_selected_from_ui output = new Vx.Ui.Ui.Class_string_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "string-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_string_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_string_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_string_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_string_selected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_string vx_string_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_string_selected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_string_selected_from_ui e_string_selected_from_ui = new Vx.Ui.Ui.Class_string_selected_from_ui();
  public static Vx.Ui.Ui.Func_string_selected_from_ui t_string_selected_from_ui = new Vx.Ui.Ui.Class_string_selected_from_ui();

  public static Vx.Core.Type_string f_string_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui selectedui = Vx.Ui.Ui.f_ui_selected_from_ui(ui);
        Vx.Core.Type_any output_1 = selectedui.uid();
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
  public interface Func_stringlist_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_stringlist_selected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_stringlist_selected_from_ui : Vx.Core.Class_base, Func_stringlist_selected_from_ui {

    public override Vx.Ui.Ui.Func_stringlist_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_stringlist_selected_from_ui output = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_stringlist_selected_from_ui output = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stringlist_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stringlist_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_stringlist_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_stringlist_selected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_stringlist_selected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_stringlist_selected_from_ui e_stringlist_selected_from_ui = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();
  public static Vx.Ui.Ui.Func_stringlist_selected_from_ui t_stringlist_selected_from_ui = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();

  public static Vx.Core.Type_stringlist f_stringlist_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_let(
      Vx.Core.t_stringlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        Vx.Core.Type_any output_2 = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            Vx.Core.Type_any output_1 = 
              Vx.Core.f_if_1(
                Vx.Core.t_string,
                item.selected(),
                item.uid(),
                Vx.Core.vx_new_string("")
              );
            return output_1;
          })
        );
        return output_2;
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
  public interface Func_stringlist_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_stringlist_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_stringlist_from_ui : Vx.Core.Class_base, Func_stringlist_from_ui {

    public override Vx.Ui.Ui.Func_stringlist_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_stringlist_from_ui output = new Vx.Ui.Ui.Class_stringlist_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_stringlist_from_ui output = new Vx.Ui.Ui.Class_stringlist_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stringlist_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stringlist_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_stringlist_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_stringlist_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_stringlist_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_stringlist_from_ui e_stringlist_from_ui = new Vx.Ui.Ui.Class_stringlist_from_ui();
  public static Vx.Ui.Ui.Func_stringlist_from_ui t_stringlist_from_ui = new Vx.Ui.Ui.Class_stringlist_from_ui();

  public static Vx.Core.Type_stringlist f_stringlist_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_let(
      Vx.Core.t_stringlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_any output_1 = Vx.Core.f_stringlist_from_map(uimap);
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
  public interface Func_stylemap_from_stylelist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_stylemap vx_stylemap_from_stylelist(Vx.Ui.Ui.Type_stylelist stylelist);
  }

  public class Class_stylemap_from_stylelist : Vx.Core.Class_base, Func_stylemap_from_stylelist {

    public override Vx.Ui.Ui.Func_stylemap_from_stylelist vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_stylemap_from_stylelist output = new Vx.Ui.Ui.Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_stylemap_from_stylelist output = new Vx.Ui.Ui.Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylemap_from_stylelist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylemap_from_stylelist;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylelist inputval = (Vx.Ui.Ui.Type_stylelist)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_stylemap_from_stylelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_stylemap_from_stylelist(stylelist);
      return output;
    }

    public Vx.Ui.Ui.Type_stylemap vx_stylemap_from_stylelist(Vx.Ui.Ui.Type_stylelist stylelist) {
      return Vx.Ui.Ui.f_stylemap_from_stylelist(stylelist);
    }

  }

  public static Vx.Ui.Ui.Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Vx.Ui.Ui.Class_stylemap_from_stylelist();
  public static Vx.Ui.Ui.Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Vx.Ui.Ui.Class_stylemap_from_stylelist();

  public static Vx.Ui.Ui.Type_stylemap f_stylemap_from_stylelist(Vx.Ui.Ui.Type_stylelist stylelist) {
    Vx.Ui.Ui.Type_stylemap output = Vx.Ui.Ui.e_stylemap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_stylemap,
      stylelist,
      Vx.Core.t_any_from_any.vx_fn_new((style_any) => {
        Vx.Ui.Ui.Type_style style = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, style_any);
        Vx.Core.Type_any output_1 = 
          style.name();
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
  public interface Func_stylesheet_readstate : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_stylesheet vx_stylesheet_readstate(Vx.Core.Type_context context);
  }

  public class Class_stylesheet_readstate : Vx.Core.Class_base, Func_stylesheet_readstate {

    public override Vx.Ui.Ui.Func_stylesheet_readstate vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_stylesheet_readstate output = new Vx.Ui.Ui.Class_stylesheet_readstate();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_stylesheet_readstate output = new Vx.Ui.Ui.Class_stylesheet_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-readstate", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylesheet_readstate;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylesheet_readstate;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_stylesheet_readstate(context);
      return output;
    }

    public Vx.Ui.Ui.Type_stylesheet vx_stylesheet_readstate(Vx.Core.Type_context context) {
      return Vx.Ui.Ui.f_stylesheet_readstate(context);
    }

  }

  public static Vx.Ui.Ui.Func_stylesheet_readstate e_stylesheet_readstate = new Vx.Ui.Ui.Class_stylesheet_readstate();
  public static Vx.Ui.Ui.Func_stylesheet_readstate t_stylesheet_readstate = new Vx.Ui.Ui.Class_stylesheet_readstate();

  public static Vx.Ui.Ui.Type_stylesheet f_stylesheet_readstate(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_stylesheet output = Vx.Ui.Ui.e_stylesheet;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_stylesheet,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
        Vx.Core.Type_any output_1 = uiengine.stylesheet();
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
  public interface Func_stylesheet_render : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_stylesheet vx_stylesheet_render(Vx.Ui.Ui.Type_stylesheet stylesheetui);
  }

  public class Class_stylesheet_render : Vx.Core.Class_base, Func_stylesheet_render {

    public override Vx.Ui.Ui.Func_stylesheet_render vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_stylesheet_render output = new Vx.Ui.Ui.Class_stylesheet_render();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_stylesheet_render output = new Vx.Ui.Ui.Class_stylesheet_render();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-render", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_stylesheet_render;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_stylesheet_render;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylesheet inputval = (Vx.Ui.Ui.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_stylesheet_render(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylesheet stylesheetui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_stylesheet_render(stylesheetui);
      return output;
    }

    public Vx.Ui.Ui.Type_stylesheet vx_stylesheet_render(Vx.Ui.Ui.Type_stylesheet stylesheetui) {
      return Vx.Ui.Ui.f_stylesheet_render(stylesheetui);
    }

  }

  public static Vx.Ui.Ui.Func_stylesheet_render e_stylesheet_render = new Vx.Ui.Ui.Class_stylesheet_render();
  public static Vx.Ui.Ui.Func_stylesheet_render t_stylesheet_render = new Vx.Ui.Ui.Class_stylesheet_render();

  public static Vx.Ui.Ui.Type_stylesheet f_stylesheet_render(Vx.Ui.Ui.Type_stylesheet stylesheetui) {
    Vx.Ui.Ui.Type_stylesheet output = Vx.Ui.Ui.e_stylesheet;
    return output;
  }

  /**
   * @function ui_addlayout_from_ui
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @return {ui}
   * (func ui-addlayout<-ui)
   */
  public interface Func_ui_addlayout_from_ui : Vx.Core.Func_any_from_any_context {
    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_ui_addlayout_from_ui : Vx.Core.Class_base, Func_ui_addlayout_from_ui {

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_addlayout_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_addlayout_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_addlayout_from_ui(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_addlayout_from_ui(context, ui);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_ui_addlayout_from_ui(context, ui);
    }

  }

  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui e_ui_addlayout_from_ui = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();
  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui t_ui_addlayout_from_ui = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
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
  public interface Func_ui_addlayout_from_ui_layoutengine : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine);
  }

  public class Class_ui_addlayout_from_ui_layoutengine : Vx.Core.Class_base, Func_ui_addlayout_from_ui_layoutengine {

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutengine", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_addlayout_from_ui_layoutengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_addlayout_from_ui_layoutengine;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutengine, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
      return Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
    }

  }

  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutengine e_ui_addlayout_from_ui_layoutengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();
  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutengine t_ui_addlayout_from_ui_layoutengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Vx.Ui.Ui.Type_layout layoutelse = layoutengine.layoutelse();
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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
  public interface Func_ui_addlayout_from_ui_layoutmap_else : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse);
  }

  public class Class_ui_addlayout_from_ui_layoutmap_else : Vx.Core.Class_base, Func_ui_addlayout_from_ui_layoutmap_else {

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutmap_else vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_addlayout_from_ui_layoutmap_else;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_addlayout_from_ui_layoutmap_else;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_layoutmap layoutmap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_layout layoutelse = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
      return Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
    }

  }

  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutmap_else e_ui_addlayout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();
  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutmap_else t_ui_addlayout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_layout layout1 = Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        Vx.Ui.Ui.Type_uimap uimap2 = Vx.Ui.Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
        Vx.Core.Type_any output_1 = Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":layout"),
            layout1,
            Vx.Core.vx_new_string(":uimap"),
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
  public interface Func_ui_addlayout_from_ui_uiengine : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_uiengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uiengine uiengine);
  }

  public class Class_ui_addlayout_from_ui_uiengine : Vx.Core.Class_base, Func_ui_addlayout_from_ui_uiengine {

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_uiengine vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine output = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-addlayout<-ui-uiengine", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_addlayout_from_ui_uiengine;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_addlayout_from_ui_uiengine;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_uiengine uiengine = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uiengine, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_addlayout_from_ui_uiengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uiengine uiengine) {
      return Vx.Ui.Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
    }

  }

  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_uiengine e_ui_addlayout_from_ui_uiengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();
  public static Vx.Ui.Ui.Func_ui_addlayout_from_ui_uiengine t_ui_addlayout_from_ui_uiengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_uiengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uiengine uiengine) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
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
  public interface Func_ui_child_from_ui_pos : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_child_from_ui_pos(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int pos);
  }

  public class Class_ui_child_from_ui_pos : Vx.Core.Class_base, Func_ui_child_from_ui_pos {

    public override Vx.Ui.Ui.Func_ui_child_from_ui_pos vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_child_from_ui_pos output = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_child_from_ui_pos output = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-pos", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_child_from_ui_pos;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_child_from_ui_pos;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int pos = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_child_from_ui_pos(ui, pos);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_child_from_ui_pos(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int pos) {
      return Vx.Ui.Ui.f_ui_child_from_ui_pos(ui, pos);
    }

  }

  public static Vx.Ui.Ui.Func_ui_child_from_ui_pos e_ui_child_from_ui_pos = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();
  public static Vx.Ui.Ui.Func_ui_child_from_ui_pos t_ui_child_from_ui_pos = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();

  public static Vx.Ui.Ui.Type_ui f_ui_child_from_ui_pos(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int pos) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap childmap = ui.uimap();
        Vx.Core.Type_any output_1 = Vx.Collection.f_any_from_map_pos(Vx.Ui.Ui.t_ui, childmap, pos);
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
  public interface Func_ui_child_from_ui_uid : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid);
  }

  public class Class_ui_child_from_ui_uid : Vx.Core.Class_base, Func_ui_child_from_ui_uid {

    public override Vx.Ui.Ui.Func_ui_child_from_ui_uid vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_child_from_ui_uid output = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_child_from_ui_uid output = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_child_from_ui_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_child_from_ui_uid;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_child_from_ui_uid(ui, uid);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
      return Vx.Ui.Ui.f_ui_child_from_ui_uid(ui, uid);
    }

  }

  public static Vx.Ui.Ui.Func_ui_child_from_ui_uid e_ui_child_from_ui_uid = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();
  public static Vx.Ui.Ui.Func_ui_child_from_ui_uid t_ui_child_from_ui_uid = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();

  public static Vx.Ui.Ui.Type_ui f_ui_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap childmap = ui.uimap();
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, childmap, uid);
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
  public interface Func_ui_from_from_event : Vx.Core.Func_any_from_any_context {
    public Vx.Ui.Ui.Type_ui vx_ui_from_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt);
  }

  public class Class_ui_from_from_event : Vx.Core.Class_base, Func_ui_from_from_event {

    public override Vx.Ui.Ui.Func_ui_from_from_event vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_from_event output = new Vx.Ui.Ui.Class_ui_from_from_event();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_from_event output = new Vx.Ui.Ui.Class_ui_from_from_event();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-from<-event", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_from_from_event;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_from_from_event;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Event.Type_event inputval = (Vx.Event.Type_event)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_from_from_event(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Event.Type_event evt = Vx.Core.f_any_from_any(Vx.Event.t_event, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_from_from_event(context, evt);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_from_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
      return Vx.Ui.Ui.f_ui_from_from_event(context, evt);
    }

  }

  public static Vx.Ui.Ui.Func_ui_from_from_event e_ui_from_from_event = new Vx.Ui.Ui.Class_ui_from_from_event();
  public static Vx.Ui.Ui.Func_ui_from_from_event t_ui_from_from_event = new Vx.Ui.Ui.Class_ui_from_from_event();

  public static Vx.Ui.Ui.Type_ui f_ui_from_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = evt.from();
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_readstate_from_uid(context, uid);
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
  public interface Func_ui_layout : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_ui vx_ui_layout(Vx.Ui.Ui.Type_ui uiarg);
  }

  public class Class_ui_layout : Vx.Core.Class_base, Func_ui_layout {

    public override Vx.Ui.Ui.Func_ui_layout vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout output = new Vx.Ui.Ui.Class_ui_layout();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout output = new Vx.Ui.Ui.Class_ui_layout();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_layout;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_layout;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_layout(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_layout(uiarg);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout(Vx.Ui.Ui.Type_ui uiarg) {
      return Vx.Ui.Ui.f_ui_layout(uiarg);
    }

  }

  public static Vx.Ui.Ui.Func_ui_layout e_ui_layout = new Vx.Ui.Ui.Class_ui_layout();
  public static Vx.Ui.Ui.Func_ui_layout t_ui_layout = new Vx.Ui.Ui.Class_ui_layout();

  public static Vx.Ui.Ui.Type_ui f_ui_layout(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(
      uiarg,
      Vx.Core.f_empty(
        Vx.Ui.Ui.t_ui
      ),
      Vx.Core.f_empty(
        Vx.Ui.Ui.t_ui
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
  public interface Func_ui_layout_from_fn_layout_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_fn_layout_ui_orig_parent(Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_from_fn_layout_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_from_fn_layout_ui_orig_parent {

    public override Vx.Ui.Ui.Func_ui_layout_from_fn_layout_ui_orig_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-fn-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_layout_from_fn_layout_ui_orig_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_layout_from_fn_layout_ui_orig_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui_layout_from_ui_orig_parent, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(3)));
      output = Vx.Ui.Ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_fn_layout_ui_orig_parent(Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_ui_layout_from_fn_layout_ui_orig_parent(fn_layout, ui, orig, parent);
    }

  }

  public static Vx.Ui.Ui.Func_ui_layout_from_fn_layout_ui_orig_parent e_ui_layout_from_fn_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
  public static Vx.Ui.Ui.Func_ui_layout_from_fn_layout_ui_orig_parent t_ui_layout_from_fn_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_fn_layout_ui_orig_parent(Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.vx_any_from_func(Vx.Ui.Ui.t_ui, fn_layout, ui, orig, parent);
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
  public interface Func_ui_layout_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_from_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_from_ui_orig_parent {

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_layout_from_ui_orig_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_layout_from_ui_orig_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent e_ui_layout_from_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();
  public static Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent t_ui_layout_from_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(
        Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_eqeq(ui, orig);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return orig;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Ui.Ui.t_ui,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
                Vx.Ui.Ui.Type_layout layout = ui.layout();
                Vx.Ui.Ui.Type_ui uiout = Vx.Ui.Ui.f_ui_from_layout_ui_orig_parent(layout, ui, orig, parent);
                Vx.Core.Type_any output_1 = uiout;
                return output_1;
              })
            );
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
  public interface Func_ui_layout_from_ui_parent_selected : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_parent_selected(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int selected);
  }

  public class Class_ui_layout_from_ui_parent_selected : Vx.Core.Class_base, Func_ui_layout_from_ui_parent_selected {

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_selected vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected output = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected output = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-selected", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_layout_from_ui_parent_selected;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_layout_from_ui_parent_selected;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int selected = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_parent_selected(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int selected) {
      return Vx.Ui.Ui.f_ui_layout_from_ui_parent_selected(ui, parent, selected);
    }

  }

  public static Vx.Ui.Ui.Func_ui_layout_from_ui_parent_selected e_ui_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();
  public static Vx.Ui.Ui.Func_ui_layout_from_ui_parent_selected t_ui_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_parent_selected(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int selected) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uichg1 = Vx.Ui.Ui.f_ui_from_ui_selected(ui, selected);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uichg1, parent);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(uichg1, ui, parent);
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
  public interface Func_ui_layout_from_ui_parent_visible : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_parent_visible(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int visible);
  }

  public class Class_ui_layout_from_ui_parent_visible : Vx.Core.Class_base, Func_ui_layout_from_ui_parent_visible {

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_visible vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible output = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible output = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-parent-visible", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_layout_from_ui_parent_visible;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_layout_from_ui_parent_visible;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int visible = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_from_ui_parent_visible(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int visible) {
      return Vx.Ui.Ui.f_ui_layout_from_ui_parent_visible(ui, parent, visible);
    }

  }

  public static Vx.Ui.Ui.Func_ui_layout_from_ui_parent_visible e_ui_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();
  public static Vx.Ui.Ui.Func_ui_layout_from_ui_parent_visible t_ui_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_parent_visible(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int visible) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uichg = Vx.Ui.Ui.f_ui_write_from_ui_visible(ui, visible);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(uichg, ui, parent);
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
  public interface Func_ui_readstate_uiapp : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_readstate_uiapp(Vx.Core.Type_context context);
  }

  public class Class_ui_readstate_uiapp : Vx.Core.Class_base, Func_ui_readstate_uiapp {

    public override Vx.Ui.Ui.Func_ui_readstate_uiapp vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_readstate_uiapp output = new Vx.Ui.Ui.Class_ui_readstate_uiapp();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_readstate_uiapp output = new Vx.Ui.Ui.Class_ui_readstate_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate-uiapp", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_readstate_uiapp;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_readstate_uiapp;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_readstate_uiapp(context);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_readstate_uiapp(Vx.Core.Type_context context) {
      return Vx.Ui.Ui.f_ui_readstate_uiapp(context);
    }

  }

  public static Vx.Ui.Ui.Func_ui_readstate_uiapp e_ui_readstate_uiapp = new Vx.Ui.Ui.Class_ui_readstate_uiapp();
  public static Vx.Ui.Ui.Func_ui_readstate_uiapp t_ui_readstate_uiapp = new Vx.Ui.Ui.Class_ui_readstate_uiapp();

  public static Vx.Ui.Ui.Type_ui f_ui_readstate_uiapp(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.State.f_any_readstate_from_name(Vx.Ui.Ui.t_ui, context, Vx.Core.vx_new_string(":uiapp"));
    return output;
  }

  /**
   * @function ui_readstate_from_uid
   * Returns the named ui from state
   * @param  {string} uid
   * @return {ui}
   * (func ui-readstate<-uid)
   */
  public interface Func_ui_readstate_from_uid : Vx.Core.Func_any_from_any_context {
    public Vx.Ui.Ui.Type_ui vx_ui_readstate_from_uid(Vx.Core.Type_context context, Vx.Core.Type_string uid);
  }

  public class Class_ui_readstate_from_uid : Vx.Core.Class_base, Func_ui_readstate_from_uid {

    public override Vx.Ui.Ui.Func_ui_readstate_from_uid vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_readstate_from_uid output = new Vx.Ui.Ui.Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_readstate_from_uid output = new Vx.Ui.Ui.Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_readstate_from_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_readstate_from_uid;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_readstate_from_uid(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_readstate_from_uid(context, uid);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_readstate_from_uid(Vx.Core.Type_context context, Vx.Core.Type_string uid) {
      return Vx.Ui.Ui.f_ui_readstate_from_uid(context, uid);
    }

  }

  public static Vx.Ui.Ui.Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Vx.Ui.Ui.Class_ui_readstate_from_uid();
  public static Vx.Ui.Ui.Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Vx.Ui.Ui.Class_ui_readstate_from_uid();

  public static Vx.Ui.Ui.Type_ui f_ui_readstate_from_uid(Vx.Core.Type_context context, Vx.Core.Type_string uid) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uiapp = Vx.Ui.Ui.f_ui_readstate_uiapp(context);
        Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_from_ui_find(uiapp, uid);
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
  public interface Func_ui_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_ui vx_ui_selected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_ui_selected_from_ui : Vx.Core.Class_base, Func_ui_selected_from_ui {

    public override Vx.Ui.Ui.Func_ui_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_selected_from_ui output = new Vx.Ui.Ui.Class_ui_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_selected_from_ui output = new Vx.Ui.Ui.Class_ui_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_selected_from_ui(ui);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_ui_selected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_ui_selected_from_ui e_ui_selected_from_ui = new Vx.Ui.Ui.Class_ui_selected_from_ui();
  public static Vx.Ui.Ui.Func_ui_selected_from_ui t_ui_selected_from_ui = new Vx.Ui.Ui.Class_ui_selected_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_selected_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_first_from_list(Vx.Ui.Ui.t_ui, uilist);
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
  public interface Func_ui_visible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_ui vx_ui_visible_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_ui_visible_from_ui : Vx.Core.Class_base, Func_ui_visible_from_ui {

    public override Vx.Ui.Ui.Func_ui_visible_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_visible_from_ui output = new Vx.Ui.Ui.Class_ui_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_visible_from_ui output = new Vx.Ui.Ui.Class_ui_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-visible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_visible_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_visible_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_ui_visible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_ui_visible_from_ui(ui);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_ui_visible_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_ui_visible_from_ui e_ui_visible_from_ui = new Vx.Ui.Ui.Class_ui_visible_from_ui();
  public static Vx.Ui.Ui.Func_ui_visible_from_ui t_ui_visible_from_ui = new Vx.Ui.Ui.Class_ui_visible_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_visible_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_first_from_list(Vx.Ui.Ui.t_ui, uilist);
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
  public interface Func_ui_write_from_ui_child : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_child(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui child);
  }

  public class Class_ui_write_from_ui_child : Vx.Core.Class_base, Func_ui_write_from_ui_child {

    public override Vx.Ui.Ui.Func_ui_write_from_ui_child vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_child output = new Vx.Ui.Ui.Class_ui_write_from_ui_child();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_child output = new Vx.Ui.Ui.Class_ui_write_from_ui_child();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-child", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_write_from_ui_child;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_write_from_ui_child;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui child = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_write_from_ui_child(ui, child);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_child(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui child) {
      return Vx.Ui.Ui.f_ui_write_from_ui_child(ui, child);
    }

  }

  public static Vx.Ui.Ui.Func_ui_write_from_ui_child e_ui_write_from_ui_child = new Vx.Ui.Ui.Class_ui_write_from_ui_child();
  public static Vx.Ui.Ui.Func_ui_write_from_ui_child t_ui_write_from_ui_child = new Vx.Ui.Ui.Class_ui_write_from_ui_child();

  public static Vx.Ui.Ui.Type_ui f_ui_write_from_ui_child(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui child) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string childid = child.uid();
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_boolean write = Vx.Core.f_boolean_write_from_map_name_value(uimap, childid, child);
        Vx.Core.Type_any output_1 = ui;
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
  public interface Func_ui_write_from_ui_childmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_childmap(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uimap childmap);
  }

  public class Class_ui_write_from_ui_childmap : Vx.Core.Class_base, Func_ui_write_from_ui_childmap {

    public override Vx.Ui.Ui.Func_ui_write_from_ui_childmap vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_childmap output = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_childmap output = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-childmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_write_from_ui_childmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_write_from_ui_childmap;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_uimap childmap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_write_from_ui_childmap(ui, childmap);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_childmap(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uimap childmap) {
      return Vx.Ui.Ui.f_ui_write_from_ui_childmap(ui, childmap);
    }

  }

  public static Vx.Ui.Ui.Func_ui_write_from_ui_childmap e_ui_write_from_ui_childmap = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();
  public static Vx.Ui.Ui.Func_ui_write_from_ui_childmap t_ui_write_from_ui_childmap = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();

  public static Vx.Ui.Ui.Type_ui f_ui_write_from_ui_childmap(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uimap childmap) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap workmap = Vx.Core.f_map_from_map_1(
          Vx.Ui.Ui.t_uimap,
          childmap,
          Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
            Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
            Vx.Ui.Ui.Type_ui value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, value_any);
            Vx.Core.Type_any output_1 = 
                Vx.Ui.Ui.f_ui_write_from_ui_child(ui, value);
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = ui;
        return output_2;
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
  public interface Func_ui_write_from_ui_visible : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_visible(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int visible);
  }

  public class Class_ui_write_from_ui_visible : Vx.Core.Class_base, Func_ui_write_from_ui_visible {

    public override Vx.Ui.Ui.Func_ui_write_from_ui_visible vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_visible output = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_write_from_ui_visible output = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-write<-ui-visible", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_write_from_ui_visible;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_write_from_ui_visible;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int visible = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_write_from_ui_visible(ui, visible);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_write_from_ui_visible(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int visible) {
      return Vx.Ui.Ui.f_ui_write_from_ui_visible(ui, visible);
    }

  }

  public static Vx.Ui.Ui.Func_ui_write_from_ui_visible e_ui_write_from_ui_visible = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();
  public static Vx.Ui.Ui.Func_ui_write_from_ui_visible t_ui_write_from_ui_visible = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();

  public static Vx.Ui.Ui.Type_ui f_ui_write_from_ui_visible(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int visible) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(
        Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_lt(visible, Vx.Core.vx_new_int(1));
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return ui;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Ui.Ui.t_ui,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
                Vx.Ui.Ui.Type_uilist uilist1 = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
                Vx.Ui.Ui.Type_uilist uilist2 = Vx.Core.f_list_from_list_intany(
                  Vx.Ui.Ui.t_uilist,
                  uilist1,
                  Vx.Core.t_any_from_int_any.vx_fn_new((posval_any, uival_any) => {
                    Vx.Core.Type_int posval = Vx.Core.f_any_from_any(Vx.Core.t_int, posval_any);
                    Vx.Ui.Ui.Type_ui uival = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, uival_any);
                    Vx.Core.Type_any output_1 = 
                        Vx.Core.f_if_2(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_thenelselist,
                            Vx.Core.f_then(
                              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                return Vx.Core.f_eq(posval, visible);
                              }),
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Ui.Ui.f_ui_write_from_ui_child(
                                  ui,
                                  Vx.Core.f_copy(
                                    uival,
                                    Vx.Core.vx_new(
                                      Vx.Core.t_anylist,
                                      Vx.Core.vx_new_string(":hidden"),
                                      Vx.Core.vx_new_boolean(false)
                                    )
                                  )
                                );
                              })
                            ),
                            Vx.Core.f_else(
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Ui.Ui.f_ui_write_from_ui_child(
                                  ui,
                                  Vx.Core.f_copy(
                                    uival,
                                    Vx.Core.vx_new(
                                      Vx.Core.t_anylist,
                                      Vx.Core.vx_new_string(":hidden"),
                                      Vx.Core.vx_new_boolean(true)
                                    )
                                  )
                                );
                              })
                            )
                          )
                        );
                    return output_1;
                  })
                );
                Vx.Core.Type_any output_2 = ui;
                return output_2;
              })
            );
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
  public interface Func_ui_from_layout_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_from_layout_ui_orig_parent(Vx.Ui.Ui.Type_layout layout, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui uiorig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_from_layout_ui_orig_parent : Vx.Core.Class_base, Func_ui_from_layout_ui_orig_parent {

    public override Vx.Ui.Ui.Func_ui_from_layout_ui_orig_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent output = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_from_layout_ui_orig_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_from_layout_ui_orig_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_layout layout = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui uiorig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(3)));
      output = Vx.Ui.Ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_from_layout_ui_orig_parent(Vx.Ui.Ui.Type_layout layout, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui uiorig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
    }

  }

  public static Vx.Ui.Ui.Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();
  public static Vx.Ui.Ui.Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_from_layout_ui_orig_parent(Vx.Ui.Ui.Type_layout layout, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui uiorig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string name = layout.name();
        Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout = layout.fn_layout();
        Vx.Ui.Ui.Type_ui uichg = Vx.Core.vx_any_from_func(Vx.Ui.Ui.t_ui, fn_layout, uiarg, uiorig, parent);
        Vx.Core.Type_any output_1 = uichg;
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
  public interface Func_ui_from_ui_find : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_from_ui_find(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string find);
  }

  public class Class_ui_from_ui_find : Vx.Core.Class_base, Func_ui_from_ui_find {

    public override Vx.Ui.Ui.Func_ui_from_ui_find vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_ui_find output = new Vx.Ui.Ui.Class_ui_from_ui_find();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_ui_find output = new Vx.Ui.Ui.Class_ui_from_ui_find();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-find", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_from_ui_find;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_from_ui_find;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string find = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_from_ui_find(uiarg, find);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_from_ui_find(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string find) {
      return Vx.Ui.Ui.f_ui_from_ui_find(uiarg, find);
    }

  }

  public static Vx.Ui.Ui.Func_ui_from_ui_find e_ui_from_ui_find = new Vx.Ui.Ui.Class_ui_from_ui_find();
  public static Vx.Ui.Ui.Func_ui_from_ui_find t_ui_from_ui_find = new Vx.Ui.Ui.Class_ui_from_ui_find();

  public static Vx.Ui.Ui.Type_ui f_ui_from_ui_find(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string find) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = uiarg.uid();
        Vx.Core.Type_any output_3 = Vx.Core.f_if_2(
          Vx.Ui.Ui.t_ui,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(uid, Vx.Core.vx_new_string(""));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Ui.Ui.t_ui
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(uid, find);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return uiarg;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Type.f_boolean_from_string_starts(
                  find,
                  Vx.Core.f_new(
                    Vx.Core.t_string,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      uid,
                      Vx.Core.vx_new_string("/")
                    )
                  )
                );
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_let(
                  Vx.Ui.Ui.t_ui,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Core.Type_int afterpos = Vx.Core.f_plus(
                      Vx.Core.f_length(uid),
                      Vx.Core.vx_new_int(2)
                    );
                    Vx.Core.Type_string after = Vx.Type.f_string_from_string_start(find, afterpos);
                    Vx.Core.Type_int pos = Vx.Type.f_int_from_string_find(after, Vx.Core.vx_new_string("/"));
                    Vx.Core.Type_string subpart = Vx.Core.f_if_2(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(
                        Vx.Core.t_thenelselist,
                        Vx.Core.f_then(
                          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                            return Vx.Core.f_gt(pos, Vx.Core.vx_new_int(0));
                          }),
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Type.f_string_from_string_end(
                              after,
                              Vx.Core.f_minus(pos, Vx.Core.vx_new_int(1))
                            );
                          })
                        ),
                        Vx.Core.f_else(
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return after;
                          })
                        )
                      )
                    );
                    Vx.Core.Type_string subfind = Vx.Core.f_if_2(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(
                        Vx.Core.t_thenelselist,
                        Vx.Core.f_then(
                          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                            return Vx.Core.f_notempty(subpart);
                          }),
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Core.f_new(
                              Vx.Core.t_string,
                              Vx.Core.vx_new(
                                Vx.Core.t_anylist,
                                uid,
                                Vx.Core.vx_new_string("/"),
                                subpart
                              )
                            );
                          })
                        )
                      )
                    );
                    Vx.Core.Type_any output_2 = Vx.Core.f_if_2(
                      Vx.Ui.Ui.t_ui,
                      Vx.Core.vx_new(
                        Vx.Core.t_thenelselist,
                        Vx.Core.f_then(
                          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                            return Vx.Core.f_notempty(subfind);
                          }),
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Core.f_let(
                              Vx.Ui.Ui.t_ui,
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
                                Vx.Ui.Ui.Type_ui subui = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, uimap, subfind);
                                Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_from_ui_find(subui, find);
                                return output_1;
                              })
                            );
                          })
                        )
                      )
                    );
                    return output_2;
                  })
                );
              })
            )
          )
        );
        return output_3;
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
  public interface Func_ui_from_ui_selected : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected);
  }

  public class Class_ui_from_ui_selected : Vx.Core.Class_base, Func_ui_from_ui_selected {

    public override Vx.Ui.Ui.Func_ui_from_ui_selected vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_ui_selected output = new Vx.Ui.Ui.Class_ui_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_ui_from_ui_selected output = new Vx.Ui.Ui.Class_ui_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-ui-selected", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_ui_from_ui_selected;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_ui_from_ui_selected;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int selected = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_ui_from_ui_selected(ui, selected);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected) {
      return Vx.Ui.Ui.f_ui_from_ui_selected(ui, selected);
    }

  }

  public static Vx.Ui.Ui.Func_ui_from_ui_selected e_ui_from_ui_selected = new Vx.Ui.Ui.Class_ui_from_ui_selected();
  public static Vx.Ui.Ui.Func_ui_from_ui_selected t_ui_from_ui_selected = new Vx.Ui.Ui.Class_ui_from_ui_selected();

  public static Vx.Ui.Ui.Type_ui f_ui_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(
        Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_lt(selected, Vx.Core.vx_new_int(1));
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return ui;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Ui.Ui.t_ui,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
                Vx.Ui.Ui.Type_uilist uilist1 = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
                Vx.Ui.Ui.Type_uilist uilist2 = Vx.Core.f_list_from_list_intany(
                  Vx.Ui.Ui.t_uilist,
                  uilist1,
                  Vx.Core.t_any_from_int_any.vx_fn_new((posval_any, uival_any) => {
                    Vx.Core.Type_int posval = Vx.Core.f_any_from_any(Vx.Core.t_int, posval_any);
                    Vx.Ui.Ui.Type_ui uival = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, uival_any);
                    Vx.Core.Type_any output_1 = 
                        Vx.Core.f_if_2(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_thenelselist,
                            Vx.Core.f_then(
                              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                return Vx.Core.f_eq(posval, selected);
                              }),
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Core.f_copy(
                                  uival,
                                  Vx.Core.vx_new(
                                    Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":selected"),
                                    Vx.Core.vx_new_boolean(true)
                                  )
                                );
                              })
                            ),
                            Vx.Core.f_else(
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Core.f_copy(
                                  uival,
                                  Vx.Core.vx_new(
                                    Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":selected"),
                                    Vx.Core.vx_new_boolean(false)
                                  )
                                );
                              })
                            )
                          )
                        );
                    return output_1;
                  })
                );
                Vx.Ui.Ui.Type_uimap childmap = Vx.Ui.Ui.f_uimap_from_uilist(uilist2);
                Vx.Core.Type_any output_2 = Vx.Core.f_copy(
                  ui,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":uimap"),
                    childmap
                  )
                );
                return output_2;
              })
            );
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
  public interface Func_uid_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_uid_selected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_uid_selected_from_ui : Vx.Core.Class_base, Func_uid_selected_from_ui {

    public override Vx.Ui.Ui.Func_uid_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uid_selected_from_ui output = new Vx.Ui.Ui.Class_uid_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uid_selected_from_ui output = new Vx.Ui.Ui.Class_uid_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uid-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uid_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uid_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uid_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uid_selected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_string vx_uid_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Ui.f_uid_selected_from_ui(ui);
    }

  }

  public static Vx.Ui.Ui.Func_uid_selected_from_ui e_uid_selected_from_ui = new Vx.Ui.Ui.Class_uid_selected_from_ui();
  public static Vx.Ui.Ui.Func_uid_selected_from_ui t_uid_selected_from_ui = new Vx.Ui.Ui.Class_uid_selected_from_ui();

  public static Vx.Core.Type_string f_uid_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist uidlist = Vx.Ui.Ui.f_stringlist_selected_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_first_from_list(Vx.Core.t_string, uidlist);
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
  public interface Func_uiengine_readstate : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_uiengine vx_uiengine_readstate(Vx.Core.Type_context context);
  }

  public class Class_uiengine_readstate : Vx.Core.Class_base, Func_uiengine_readstate {

    public override Vx.Ui.Ui.Func_uiengine_readstate vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uiengine_readstate output = new Vx.Ui.Ui.Class_uiengine_readstate();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uiengine_readstate output = new Vx.Ui.Ui.Class_uiengine_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-readstate", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uiengine_readstate;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uiengine_readstate;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uiengine_readstate(context);
      return output;
    }

    public Vx.Ui.Ui.Type_uiengine vx_uiengine_readstate(Vx.Core.Type_context context) {
      return Vx.Ui.Ui.f_uiengine_readstate(context);
    }

  }

  public static Vx.Ui.Ui.Func_uiengine_readstate e_uiengine_readstate = new Vx.Ui.Ui.Class_uiengine_readstate();
  public static Vx.Ui.Ui.Func_uiengine_readstate t_uiengine_readstate = new Vx.Ui.Ui.Class_uiengine_readstate();

  public static Vx.Ui.Ui.Type_uiengine f_uiengine_readstate(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_uiengine output = Vx.Ui.Ui.e_uiengine;
    output = Vx.State.f_any_readstate_from_name(Vx.Ui.Ui.t_uiengine, context, Vx.Core.vx_new_string(":uiengine"));
    return output;
  }

  /**
   * @function uiengine_render
   * Returns a fully rendered ui for a given engine.
   * @param  {uiengine} uiengine
   * @return {uiengine}
   * (func uiengine-render)
   */
  public interface Func_uiengine_render : Vx.Core.Func_any_from_any_context {
    public Vx.Ui.Ui.Type_uiengine vx_uiengine_render(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine);
  }

  public class Class_uiengine_render : Vx.Core.Class_base, Func_uiengine_render {

    public override Vx.Ui.Ui.Func_uiengine_render vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uiengine_render output = new Vx.Ui.Ui.Class_uiengine_render();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uiengine_render output = new Vx.Ui.Ui.Class_uiengine_render();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-render", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uiengine", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uiengine_render;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uiengine_render;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uiengine inputval = (Vx.Ui.Ui.Type_uiengine)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uiengine_render(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_uiengine uiengine = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uiengine, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uiengine_render(context, uiengine);
      return output;
    }

    public Vx.Ui.Ui.Type_uiengine vx_uiengine_render(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine) {
      return Vx.Ui.Ui.f_uiengine_render(context, uiengine);
    }

  }

  public static Vx.Ui.Ui.Func_uiengine_render e_uiengine_render = new Vx.Ui.Ui.Class_uiengine_render();
  public static Vx.Ui.Ui.Func_uiengine_render t_uiengine_render = new Vx.Ui.Ui.Class_uiengine_render();

  public static Vx.Ui.Ui.Type_uiengine f_uiengine_render(Vx.Core.Type_context context, Vx.Ui.Ui.Type_uiengine uiengine) {
    Vx.Ui.Ui.Type_uiengine output = Vx.Ui.Ui.e_uiengine;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_uiengine,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_stylesheet stylesheet = uiengine.stylesheet();
        Vx.Ui.Ui.Type_ui ui = uiengine.ui();
        Vx.Ui.Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        Vx.Core.Type_boolean issetstate = Vx.Ui.Ui.f_boolean_writestate_from_uiengine(context, uiengine);
        Vx.Ui.Ui.Func_stylesheet_render stylesheetrender = layoutengine.stylesheetrender();
        Vx.Ui.Ui.Type_stylesheet stylesheetrend = Vx.Core.vx_any_from_func(Vx.Ui.Ui.t_stylesheet, stylesheetrender, stylesheet);
        Vx.Ui.Ui.Type_ui uiaddlayout = Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
        Vx.Core.Type_boolean isuiwrite = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(context, uiaddlayout);
        Vx.Ui.Ui.Type_ui uirendered = Vx.Ui.Ui.f_ui_layout(uiaddlayout);
        Vx.Core.Type_any output_1 = Vx.Core.f_copy(
          uiengine,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":ui"),
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
  public interface Func_uilist_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uilist vx_uilist_selected_from_ui(Vx.Ui.Ui.Type_ui uiarg);
  }

  public class Class_uilist_selected_from_ui : Vx.Core.Class_base, Func_uilist_selected_from_ui {

    public override Vx.Ui.Ui.Func_uilist_selected_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_selected_from_ui output = new Vx.Ui.Ui.Class_uilist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_selected_from_ui output = new Vx.Ui.Ui.Class_uilist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uilist_selected_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uilist_selected_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uilist_selected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uilist_selected_from_ui(uiarg);
      return output;
    }

    public Vx.Ui.Ui.Type_uilist vx_uilist_selected_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
      return Vx.Ui.Ui.f_uilist_selected_from_ui(uiarg);
    }

  }

  public static Vx.Ui.Ui.Func_uilist_selected_from_ui e_uilist_selected_from_ui = new Vx.Ui.Ui.Class_uilist_selected_from_ui();
  public static Vx.Ui.Ui.Func_uilist_selected_from_ui t_uilist_selected_from_ui = new Vx.Ui.Ui.Class_uilist_selected_from_ui();

  public static Vx.Ui.Ui.Type_uilist f_uilist_selected_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_uilist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        Vx.Core.Type_any output_2 = Vx.Collection.f_list_from_list_filter(
          Vx.Ui.Ui.t_uilist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            Vx.Core.Type_any output_1 = 
              Vx.Core.f_if(
                Vx.Ui.Ui.t_ui,
                item.selected(),
                item
              );
            return output_1;
          })
        );
        return output_2;
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
  public interface Func_uilist_visible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uilist vx_uilist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg);
  }

  public class Class_uilist_visible_from_ui : Vx.Core.Class_base, Func_uilist_visible_from_ui {

    public override Vx.Ui.Ui.Func_uilist_visible_from_ui vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_visible_from_ui output = new Vx.Ui.Ui.Class_uilist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_visible_from_ui output = new Vx.Ui.Ui.Class_uilist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-visible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uilist_visible_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uilist_visible_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uilist_visible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui uiarg = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uilist_visible_from_ui(uiarg);
      return output;
    }

    public Vx.Ui.Ui.Type_uilist vx_uilist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
      return Vx.Ui.Ui.f_uilist_visible_from_ui(uiarg);
    }

  }

  public static Vx.Ui.Ui.Func_uilist_visible_from_ui e_uilist_visible_from_ui = new Vx.Ui.Ui.Class_uilist_visible_from_ui();
  public static Vx.Ui.Ui.Func_uilist_visible_from_ui t_uilist_visible_from_ui = new Vx.Ui.Ui.Class_uilist_visible_from_ui();

  public static Vx.Ui.Ui.Type_uilist f_uilist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_uilist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        Vx.Core.Type_any output_2 = Vx.Collection.f_list_from_list_filter(
          Vx.Ui.Ui.t_uilist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            Vx.Core.Type_any output_1 = 
              Vx.Core.f_if(
                Vx.Ui.Ui.t_ui,
                Vx.Core.f_not(
                  item.hidden()
                ),
                item
              );
            return output_1;
          })
        );
        return output_2;
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
  public interface Func_uilist_from_uimap : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uilist vx_uilist_from_uimap(Vx.Ui.Ui.Type_uimap uimap);
  }

  public class Class_uilist_from_uimap : Vx.Core.Class_base, Func_uilist_from_uimap {

    public override Vx.Ui.Ui.Func_uilist_from_uimap vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_from_uimap output = new Vx.Ui.Ui.Class_uilist_from_uimap();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uilist_from_uimap output = new Vx.Ui.Ui.Class_uilist_from_uimap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uilist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uilist_from_uimap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uilist_from_uimap;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uimap inputval = (Vx.Ui.Ui.Type_uimap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uilist_from_uimap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
      return output;
    }

    public Vx.Ui.Ui.Type_uilist vx_uilist_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
      return Vx.Ui.Ui.f_uilist_from_uimap(uimap);
    }

  }

  public static Vx.Ui.Ui.Func_uilist_from_uimap e_uilist_from_uimap = new Vx.Ui.Ui.Class_uilist_from_uimap();
  public static Vx.Ui.Ui.Func_uilist_from_uimap t_uilist_from_uimap = new Vx.Ui.Ui.Class_uilist_from_uimap();

  public static Vx.Ui.Ui.Type_uilist f_uilist_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Ui.Ui.t_uilist,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, item_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
        Vx.Core.Type_any output_1 = item;
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
  public interface Func_uimap_addlayout_from_uimap_layoutmap_else : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_uimap vx_uimap_addlayout_from_uimap_layoutmap_else(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse);
  }

  public class Class_uimap_addlayout_from_uimap_layoutmap_else : Vx.Core.Class_base, Func_uimap_addlayout_from_uimap_layoutmap_else {

    public override Vx.Ui.Ui.Func_uimap_addlayout_from_uimap_layoutmap_else vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else output = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else output = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-addlayout<-uimap-layoutmap-else", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uimap_addlayout_from_uimap_layoutmap_else;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uimap_addlayout_from_uimap_layoutmap_else;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_layoutmap layoutmap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layoutmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_layout layoutelse = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
      return output;
    }

    public Vx.Ui.Ui.Type_uimap vx_uimap_addlayout_from_uimap_layoutmap_else(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
      return Vx.Ui.Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
    }

  }

  public static Vx.Ui.Ui.Func_uimap_addlayout_from_uimap_layoutmap_else e_uimap_addlayout_from_uimap_layoutmap_else = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
  public static Vx.Ui.Ui.Func_uimap_addlayout_from_uimap_layoutmap_else t_uimap_addlayout_from_uimap_layoutmap_else = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();

  public static Vx.Ui.Ui.Type_uimap f_uimap_addlayout_from_uimap_layoutmap_else(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_map_1(
      Vx.Ui.Ui.t_uimap,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, ui_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, ui_any);
        Vx.Core.Type_any output_1 = 
          Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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
  public interface Func_uimap_layout_from_uimap_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_uimap vx_uimap_layout_from_uimap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_uimap_layout_from_uimap_parent : Vx.Core.Class_base, Func_uimap_layout_from_uimap_parent {

    public override Vx.Ui.Ui.Func_uimap_layout_from_uimap_parent vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent output = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent output = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uimap_layout_from_uimap_parent;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uimap_layout_from_uimap_parent;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_uimap_layout_from_uimap_parent(uimap, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_uimap vx_uimap_layout_from_uimap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Ui.f_uimap_layout_from_uimap_parent(uimap, parent);
    }

  }

  public static Vx.Ui.Ui.Func_uimap_layout_from_uimap_parent e_uimap_layout_from_uimap_parent = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();
  public static Vx.Ui.Ui.Func_uimap_layout_from_uimap_parent t_uimap_layout_from_uimap_parent = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();

  public static Vx.Ui.Ui.Type_uimap f_uimap_layout_from_uimap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_map_1(
      Vx.Ui.Ui.t_uimap,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, val_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui val = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, val_any);
        Vx.Core.Type_any output_1 = 
          Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(
            val,
            Vx.Core.f_empty(
              Vx.Ui.Ui.t_ui
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
  public interface Func_uimap_from_uilist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uilist(Vx.Ui.Ui.Type_uilist uilist);
  }

  public class Class_uimap_from_uilist : Vx.Core.Class_base, Func_uimap_from_uilist {

    public override Vx.Ui.Ui.Func_uimap_from_uilist vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_from_uilist output = new Vx.Ui.Ui.Class_uimap_from_uilist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_from_uilist output = new Vx.Ui.Ui.Class_uimap_from_uilist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uimap_from_uilist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uimap_from_uilist;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uilist inputval = (Vx.Ui.Ui.Type_uilist)value;
      Vx.Core.Type_any outputval = Vx.Ui.Ui.f_uimap_from_uilist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uilist uilist = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uilist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Ui.f_uimap_from_uilist(uilist);
      return output;
    }

    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uilist(Vx.Ui.Ui.Type_uilist uilist) {
      return Vx.Ui.Ui.f_uimap_from_uilist(uilist);
    }

  }

  public static Vx.Ui.Ui.Func_uimap_from_uilist e_uimap_from_uilist = new Vx.Ui.Ui.Class_uimap_from_uilist();
  public static Vx.Ui.Ui.Func_uimap_from_uilist t_uimap_from_uilist = new Vx.Ui.Ui.Class_uimap_from_uilist();

  public static Vx.Ui.Ui.Type_uimap f_uimap_from_uilist(Vx.Ui.Ui.Type_uilist uilist) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_uimap,
      uilist,
      Vx.Core.t_any_from_any.vx_fn_new((ui_any) => {
        Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, ui_any);
        Vx.Core.Type_any output_1 = 
          ui.uid();
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
  public interface Func_uimap_from_uimap_data : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uimap_data(Vx.Ui.Ui.Type_uimap uimap, Vx.Core.Type_any data);
  }

  public class Class_uimap_from_uimap_data : Vx.Core.Class_base, Func_uimap_from_uimap_data {

    public override Vx.Ui.Ui.Func_uimap_from_uimap_data vx_new(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_from_uimap_data output = new Vx.Ui.Ui.Class_uimap_from_uimap_data();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Ui.Ui.Class_uimap_from_uimap_data output = new Vx.Ui.Ui.Class_uimap_from_uimap_data();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "uimap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Ui.Ui.t_ui), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Ui.Ui.e_uimap_from_uimap_data;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Ui.Ui.t_uimap_from_uimap_data;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any data = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Ui.f_uimap_from_uimap_data(uimap, data);
      return output;
    }

    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uimap_data(Vx.Ui.Ui.Type_uimap uimap, Vx.Core.Type_any data) {
      return Vx.Ui.Ui.f_uimap_from_uimap_data(uimap, data);
    }

  }

  public static Vx.Ui.Ui.Func_uimap_from_uimap_data e_uimap_from_uimap_data = new Vx.Ui.Ui.Class_uimap_from_uimap_data();
  public static Vx.Ui.Ui.Func_uimap_from_uimap_data t_uimap_from_uimap_data = new Vx.Ui.Ui.Class_uimap_from_uimap_data();

  public static Vx.Ui.Ui.Type_uimap f_uimap_from_uimap_data(Vx.Ui.Ui.Type_uimap uimap, Vx.Core.Type_any data) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
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
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("align", Vx.Ui.Ui.t_align);
    maptype.put("bounds", Vx.Ui.Ui.t_bounds);
    maptype.put("cursor", Vx.Ui.Ui.t_cursor);
    maptype.put("cursor-pointer", Vx.Ui.Ui.t_cursor_pointer);
    maptype.put("flip", Vx.Ui.Ui.t_flip);
    maptype.put("font", Vx.Ui.Ui.t_font);
    maptype.put("fontface", Vx.Ui.Ui.t_fontface);
    maptype.put("fontfacelist", Vx.Ui.Ui.t_fontfacelist);
    maptype.put("fontfacemap", Vx.Ui.Ui.t_fontfacemap);
    maptype.put("fontmap", Vx.Ui.Ui.t_fontmap);
    maptype.put("fontstyle", Vx.Ui.Ui.t_fontstyle);
    maptype.put("fontstylemap", Vx.Ui.Ui.t_fontstylemap);
    maptype.put("image", Vx.Ui.Ui.t_image);
    maptype.put("layout", Vx.Ui.Ui.t_layout);
    maptype.put("layoutengine", Vx.Ui.Ui.t_layoutengine);
    maptype.put("layoutlist", Vx.Ui.Ui.t_layoutlist);
    maptype.put("layoutmap", Vx.Ui.Ui.t_layoutmap);
    maptype.put("pin", Vx.Ui.Ui.t_pin);
    maptype.put("point", Vx.Ui.Ui.t_point);
    maptype.put("pointtype", Vx.Ui.Ui.t_pointtype);
    maptype.put("style", Vx.Ui.Ui.t_style);
    maptype.put("stylelist", Vx.Ui.Ui.t_stylelist);
    maptype.put("stylemap", Vx.Ui.Ui.t_stylemap);
    maptype.put("stylesheet", Vx.Ui.Ui.t_stylesheet);
    maptype.put("styletype", Vx.Ui.Ui.t_styletype);
    maptype.put("ui", Vx.Ui.Ui.t_ui);
    maptype.put("uiengine", Vx.Ui.Ui.t_uiengine);
    maptype.put("uilist", Vx.Ui.Ui.t_uilist);
    maptype.put("uimap", Vx.Ui.Ui.t_uimap);
    mapconst.put("align-center", Vx.Ui.Ui.c_align_center);
    mapconst.put("align-left", Vx.Ui.Ui.c_align_left);
    mapconst.put("align-right", Vx.Ui.Ui.c_align_right);
    mapconst.put("flip-x", Vx.Ui.Ui.c_flip_x);
    mapconst.put("flip-xy", Vx.Ui.Ui.c_flip_xy);
    mapconst.put("flip-y", Vx.Ui.Ui.c_flip_y);
    mapconst.put("layout-app", Vx.Ui.Ui.c_layout_app);
    mapconst.put("layout-background", Vx.Ui.Ui.c_layout_background);
    mapconst.put("layout-button", Vx.Ui.Ui.c_layout_button);
    mapconst.put("layout-combobox", Vx.Ui.Ui.c_layout_combobox);
    mapconst.put("layout-else", Vx.Ui.Ui.c_layout_else);
    mapconst.put("layout-flow-columns", Vx.Ui.Ui.c_layout_flow_columns);
    mapconst.put("layout-flow-item", Vx.Ui.Ui.c_layout_flow_item);
    mapconst.put("layout-flow-rows", Vx.Ui.Ui.c_layout_flow_rows);
    mapconst.put("layout-image", Vx.Ui.Ui.c_layout_image);
    mapconst.put("layout-label", Vx.Ui.Ui.c_layout_label);
    mapconst.put("layout-main", Vx.Ui.Ui.c_layout_main);
    mapconst.put("layout-maxpanel", Vx.Ui.Ui.c_layout_maxpanel);
    mapconst.put("layout-menubar", Vx.Ui.Ui.c_layout_menubar);
    mapconst.put("layout-menudrawer", Vx.Ui.Ui.c_layout_menudrawer);
    mapconst.put("layout-msgbox", Vx.Ui.Ui.c_layout_msgbox);
    mapconst.put("layout-navbar", Vx.Ui.Ui.c_layout_navbar);
    mapconst.put("layout-navdrawer", Vx.Ui.Ui.c_layout_navdrawer);
    mapconst.put("layout-panel", Vx.Ui.Ui.c_layout_panel);
    mapconst.put("layout-parallax", Vx.Ui.Ui.c_layout_parallax);
    mapconst.put("layout-statusbar", Vx.Ui.Ui.c_layout_statusbar);
    mapconst.put("layout-statusdrawer", Vx.Ui.Ui.c_layout_statusdrawer);
    mapconst.put("layout-text", Vx.Ui.Ui.c_layout_text);
    mapconst.put("layout-textentry", Vx.Ui.Ui.c_layout_textentry);
    mapconst.put("layout-titlebar", Vx.Ui.Ui.c_layout_titlebar);
    mapconst.put("pin-bottom", Vx.Ui.Ui.c_pin_bottom);
    mapconst.put("pin-center", Vx.Ui.Ui.c_pin_center);
    mapconst.put("pin-center-h", Vx.Ui.Ui.c_pin_center_h);
    mapconst.put("pin-center-v", Vx.Ui.Ui.c_pin_center_v);
    mapconst.put("pin-expand", Vx.Ui.Ui.c_pin_expand);
    mapconst.put("pin-left", Vx.Ui.Ui.c_pin_left);
    mapconst.put("pin-right", Vx.Ui.Ui.c_pin_right);
    mapconst.put("pin-top", Vx.Ui.Ui.c_pin_top);
    mapconst.put("point-center", Vx.Ui.Ui.c_point_center);
    mapconst.put("point-lefttop", Vx.Ui.Ui.c_point_lefttop);
    mapconst.put("point-rightbottom", Vx.Ui.Ui.c_point_rightbottom);
    mapconst.put("pointtype-absolute", Vx.Ui.Ui.c_pointtype_absolute);
    mapconst.put("pointtype-percent", Vx.Ui.Ui.c_pointtype_percent);
    mapconst.put("pointtype-relative", Vx.Ui.Ui.c_pointtype_relative);
    mapconst.put("styletype-custom", Vx.Ui.Ui.c_styletype_custom);
    mapconst.put("styletype-shared", Vx.Ui.Ui.c_styletype_shared);
    mapconst.put("styletype-system", Vx.Ui.Ui.c_styletype_system);
    mapfunc.put("boolean-layout<-ui-parent-selected", Vx.Ui.Ui.t_boolean_layout_from_ui_parent_selected);
    mapfunc.put("boolean-layout<-ui-parent-visible", Vx.Ui.Ui.t_boolean_layout_from_ui_parent_visible);
    mapfunc.put("boolean-layoutaddchild<-ui-parent", Vx.Ui.Ui.t_boolean_layoutaddchild_from_ui_parent);
    mapfunc.put("boolean-layoutremove<-ui", Vx.Ui.Ui.t_boolean_layoutremove_from_ui);
    mapfunc.put("boolean-layoutremove<-ui-keys", Vx.Ui.Ui.t_boolean_layoutremove_from_ui_keys);
    mapfunc.put("boolean-layoutremove<-ui-parent", Vx.Ui.Ui.t_boolean_layoutremove_from_ui_parent);
    mapfunc.put("boolean-layoutremove<-ui-start-end", Vx.Ui.Ui.t_boolean_layoutremove_from_ui_start_end);
    mapfunc.put("boolean-layoutselected<-ui", Vx.Ui.Ui.t_boolean_layoutselected_from_ui);
    mapfunc.put("boolean-layoutselected<-ui-parent", Vx.Ui.Ui.t_boolean_layoutselected_from_ui_parent);
    mapfunc.put("boolean-layoutselected<-ui-selected", Vx.Ui.Ui.t_boolean_layoutselected_from_ui_selected);
    mapfunc.put("boolean-layoutvisible<-ui", Vx.Ui.Ui.t_boolean_layoutvisible_from_ui);
    mapfunc.put("boolean-print", Vx.Ui.Ui.t_boolean_print);
    mapfunc.put("boolean-removestate-uiapp", Vx.Ui.Ui.t_boolean_removestate_uiapp);
    mapfunc.put("boolean-write<-ui-parent", Vx.Ui.Ui.t_boolean_write_from_ui_parent);
    mapfunc.put("boolean-writeremove<-ui-uid", Vx.Ui.Ui.t_boolean_writeremove_from_ui_uid);
    mapfunc.put("boolean-writestate<-ui", Vx.Ui.Ui.t_boolean_writestate_from_ui);
    mapfunc.put("boolean-writestate<-uiapp", Vx.Ui.Ui.t_boolean_writestate_from_uiapp);
    mapfunc.put("boolean-writestate<-uiengine", Vx.Ui.Ui.t_boolean_writestate_from_uiengine);
    mapfunc.put("fontfacemap<-fontfacelist", Vx.Ui.Ui.t_fontfacemap_from_fontfacelist);
    mapfunc.put("int-child<-ui-uid", Vx.Ui.Ui.t_int_child_from_ui_uid);
    mapfunc.put("int-selected<-ui", Vx.Ui.Ui.t_int_selected_from_ui);
    mapfunc.put("int-visible<-ui", Vx.Ui.Ui.t_int_visible_from_ui);
    mapfunc.put("intlist-visible<-ui", Vx.Ui.Ui.t_intlist_visible_from_ui);
    mapfunc.put("layout<-style", Vx.Ui.Ui.t_layout_from_style);
    mapfunc.put("layout<-ui", Vx.Ui.Ui.t_layout_from_ui);
    mapfunc.put("layout<-ui-layoutengine", Vx.Ui.Ui.t_layout_from_ui_layoutengine);
    mapfunc.put("layout<-ui-layoutmap-else", Vx.Ui.Ui.t_layout_from_ui_layoutmap_else);
    mapfunc.put("layoutengine-readstate", Vx.Ui.Ui.t_layoutengine_readstate);
    mapfunc.put("layoutmap<-layoutlist", Vx.Ui.Ui.t_layoutmap_from_layoutlist);
    mapfunc.put("string-parentuid<-uid", Vx.Ui.Ui.t_string_parentuid_from_uid);
    mapfunc.put("string-selected<-ui", Vx.Ui.Ui.t_string_selected_from_ui);
    mapfunc.put("stringlist-selected<-ui", Vx.Ui.Ui.t_stringlist_selected_from_ui);
    mapfunc.put("stringlist<-ui", Vx.Ui.Ui.t_stringlist_from_ui);
    mapfunc.put("stylemap<-stylelist", Vx.Ui.Ui.t_stylemap_from_stylelist);
    mapfunc.put("stylesheet-readstate", Vx.Ui.Ui.t_stylesheet_readstate);
    mapfunc.put("stylesheet-render", Vx.Ui.Ui.t_stylesheet_render);
    mapfunc.put("ui-addlayout<-ui", Vx.Ui.Ui.t_ui_addlayout_from_ui);
    mapfunc.put("ui-addlayout<-ui-layoutengine", Vx.Ui.Ui.t_ui_addlayout_from_ui_layoutengine);
    mapfunc.put("ui-addlayout<-ui-layoutmap-else", Vx.Ui.Ui.t_ui_addlayout_from_ui_layoutmap_else);
    mapfunc.put("ui-addlayout<-ui-uiengine", Vx.Ui.Ui.t_ui_addlayout_from_ui_uiengine);
    mapfunc.put("ui-child<-ui-pos", Vx.Ui.Ui.t_ui_child_from_ui_pos);
    mapfunc.put("ui-child<-ui-uid", Vx.Ui.Ui.t_ui_child_from_ui_uid);
    mapfunc.put("ui-from<-event", Vx.Ui.Ui.t_ui_from_from_event);
    mapfunc.put("ui-layout", Vx.Ui.Ui.t_ui_layout);
    mapfunc.put("ui-layout<-fn-layout-ui-orig-parent", Vx.Ui.Ui.t_ui_layout_from_fn_layout_ui_orig_parent);
    mapfunc.put("ui-layout<-ui-orig-parent", Vx.Ui.Ui.t_ui_layout_from_ui_orig_parent);
    mapfunc.put("ui-layout<-ui-parent-selected", Vx.Ui.Ui.t_ui_layout_from_ui_parent_selected);
    mapfunc.put("ui-layout<-ui-parent-visible", Vx.Ui.Ui.t_ui_layout_from_ui_parent_visible);
    mapfunc.put("ui-readstate-uiapp", Vx.Ui.Ui.t_ui_readstate_uiapp);
    mapfunc.put("ui-readstate<-uid", Vx.Ui.Ui.t_ui_readstate_from_uid);
    mapfunc.put("ui-selected<-ui", Vx.Ui.Ui.t_ui_selected_from_ui);
    mapfunc.put("ui-visible<-ui", Vx.Ui.Ui.t_ui_visible_from_ui);
    mapfunc.put("ui-write<-ui-child", Vx.Ui.Ui.t_ui_write_from_ui_child);
    mapfunc.put("ui-write<-ui-childmap", Vx.Ui.Ui.t_ui_write_from_ui_childmap);
    mapfunc.put("ui-write<-ui-visible", Vx.Ui.Ui.t_ui_write_from_ui_visible);
    mapfunc.put("ui<-layout-ui-orig-parent", Vx.Ui.Ui.t_ui_from_layout_ui_orig_parent);
    mapfunc.put("ui<-ui-find", Vx.Ui.Ui.t_ui_from_ui_find);
    mapfunc.put("ui<-ui-selected", Vx.Ui.Ui.t_ui_from_ui_selected);
    mapfunc.put("uid-selected<-ui", Vx.Ui.Ui.t_uid_selected_from_ui);
    mapfunc.put("uiengine-readstate", Vx.Ui.Ui.t_uiengine_readstate);
    mapfunc.put("uiengine-render", Vx.Ui.Ui.t_uiengine_render);
    mapfunc.put("uilist-selected<-ui", Vx.Ui.Ui.t_uilist_selected_from_ui);
    mapfunc.put("uilist-visible<-ui", Vx.Ui.Ui.t_uilist_visible_from_ui);
    mapfunc.put("uilist<-uimap", Vx.Ui.Ui.t_uilist_from_uimap);
    mapfunc.put("uimap-addlayout<-uimap-layoutmap-else", Vx.Ui.Ui.t_uimap_addlayout_from_uimap_layoutmap_else);
    mapfunc.put("uimap-layout<-uimap-parent", Vx.Ui.Ui.t_uimap_layout_from_uimap_parent);
    mapfunc.put("uimap<-uilist", Vx.Ui.Ui.t_uimap_from_uilist);
    mapfunc.put("uimap<-uimap-data", Vx.Ui.Ui.t_uimap_from_uimap_data);
    Vx.Core.vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
