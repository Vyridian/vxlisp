namespace Vx.Ui;

public static class Ui {


  /**
   * type: align
   * Universal Alignment
   * (type align)
   */
  public interface Type_align : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_align : Vx.Core.Class_base, Type_align {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_align vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_align,
       vals);
    }

    public override Vx.Ui.Ui.Type_align vx_copy(params Object[] vals) {
      Type_align output = this;
      bool ischanged = false;
      Class_align val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_align work = new Class_align();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_align;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_align;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_align e_align = new Class_align();
  public static Type_align t_align = new Class_align();

  /**
   * type: bounds
   * Universal Bounds
   * (type bounds)
   */
  public interface Type_bounds : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_int left();
    public Vx.Core.Type_int right();
    public Vx.Core.Type_int top();
    public Vx.Core.Type_int bottom();
  }

  public class Class_bounds : Vx.Core.Class_base, Type_bounds {

    public Vx.Core.Type_int vx_p_left;

    public Vx.Core.Type_int left() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_left != null) {
        output = this.vx_p_left;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_right;

    public Vx.Core.Type_int right() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_right != null) {
        output = this.vx_p_right;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_top;

    public Vx.Core.Type_int top() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_top != null) {
        output = this.vx_p_top;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_bottom;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_bounds vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_bounds,
       vals);
    }

    public override Vx.Ui.Ui.Type_bounds vx_copy(params Object[] vals) {
      Type_bounds output = this;
      bool ischanged = false;
      Class_bounds val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_left = val.left();
      Vx.Core.Type_int vx_p_right = val.right();
      Vx.Core.Type_int vx_p_top = val.top();
      Vx.Core.Type_int vx_p_bottom = val.bottom();
      List<string> validkeys = new List<string>();
      validkeys.Add(":left");
      validkeys.Add(":right");
      validkeys.Add(":top");
      validkeys.Add(":bottom");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_left = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_left = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_right = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_right = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_top = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_top = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_bottom = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_bottom = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_bounds work = new Class_bounds();
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
      return e_bounds;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_bounds;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_bounds e_bounds = new Class_bounds();
  public static Type_bounds t_bounds = new Class_bounds();

  /**
   * type: cursor
   * Univeral Cursor Type
   * (type cursor)
   */
  public interface Type_cursor : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_cursor : Vx.Core.Class_base, Type_cursor {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_cursor vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_cursor,
       vals);
    }

    public override Vx.Ui.Ui.Type_cursor vx_copy(params Object[] vals) {
      Type_cursor output = this;
      bool ischanged = false;
      Class_cursor val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_cursor work = new Class_cursor();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_cursor;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_cursor;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_cursor e_cursor = new Class_cursor();
  public static Type_cursor t_cursor = new Class_cursor();

  /**
   * type: cursor-pointer
   * (type cursor-pointer)
   */
  public interface Type_cursor_pointer : Vx.Core.Type_any {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_cursor_pointer : Vx.Core.Class_base, Type_cursor_pointer {

    public override Vx.Ui.Ui.Type_cursor_pointer vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_cursor_pointer,
       vals);
    }

    public override Vx.Ui.Ui.Type_cursor_pointer vx_copy(params Object[] vals) {
      Type_cursor_pointer output = this;
      bool ischanged = false;
      Class_cursor_pointer val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_cursor_pointer work = new Class_cursor_pointer();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_cursor_pointer;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_cursor_pointer;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_cursor_pointer e_cursor_pointer = new Class_cursor_pointer();
  public static Type_cursor_pointer t_cursor_pointer = new Class_cursor_pointer();

  /**
   * type: flip
   * Universal ui flip horizontal or vertical or both.
   * (type flip)
   */
  public interface Type_flip : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_flip : Vx.Core.Class_base, Type_flip {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_flip vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_flip,
       vals);
    }

    public override Vx.Ui.Ui.Type_flip vx_copy(params Object[] vals) {
      Type_flip output = this;
      bool ischanged = false;
      Class_flip val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_flip work = new Class_flip();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_flip;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_flip;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_flip e_flip = new Class_flip();
  public static Type_flip t_flip = new Class_flip();

  /**
   * type: font
   * Univeral Font Type
   * (type font)
   */
  public interface Type_font : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Type_fontface fontface();
    public Vx.Core.Type_int fontsize();
    public Vx.Ui.Ui.Type_fontstyle fontstyle();
  }

  public class Class_font : Vx.Core.Class_base, Type_font {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontface vx_p_fontface;

    public Vx.Ui.Ui.Type_fontface fontface() {
      Vx.Ui.Ui.Type_fontface output = Vx.Ui.Ui.e_fontface;
      if (this.vx_p_fontface != null) {
        output = this.vx_p_fontface;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_fontsize;

    public Vx.Core.Type_int fontsize() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_fontsize != null) {
        output = this.vx_p_fontsize;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_fontstyle vx_p_fontstyle;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_font vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_font,
       vals);
    }

    public override Vx.Ui.Ui.Type_font vx_copy(params Object[] vals) {
      Type_font output = this;
      bool ischanged = false;
      Class_font val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Ui.Ui.Type_fontface vx_p_fontface = val.fontface();
      Vx.Core.Type_int vx_p_fontsize = val.fontsize();
      Vx.Ui.Ui.Type_fontstyle vx_p_fontstyle = val.fontstyle();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":fontface");
      validkeys.Add(":fontsize");
      validkeys.Add(":fontstyle");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_fontface) {
              ischanged = true;
              vx_p_fontface = (Vx.Ui.Ui.Type_fontface)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_fontsize = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_fontsize = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_fontstyle) {
              ischanged = true;
              vx_p_fontstyle = (Vx.Ui.Ui.Type_fontstyle)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_font work = new Class_font();
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
      return e_font;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_font;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_font e_font = new Class_font();
  public static Type_font t_font = new Class_font();

  /**
   * type: fontface
   * Univeral Font Face Type
   * (type fontface)
   */
  public interface Type_fontface : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string weight();
    public Vx.Core.Type_string unicode();
    public Vx.Data.File.Type_filelist filelist();
  }

  public class Class_fontface : Vx.Core.Class_base, Type_fontface {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_weight;

    public Vx.Core.Type_string weight() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_weight != null) {
        output = this.vx_p_weight;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_unicode;

    public Vx.Core.Type_string unicode() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_unicode != null) {
        output = this.vx_p_unicode;
      }
      return output;
    }

    public Vx.Data.File.Type_filelist vx_p_filelist;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_fontface vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontface,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontface vx_copy(params Object[] vals) {
      Type_fontface output = this;
      bool ischanged = false;
      Class_fontface val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_weight = val.weight();
      Vx.Core.Type_string vx_p_unicode = val.unicode();
      Vx.Data.File.Type_filelist vx_p_filelist = val.filelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":weight");
      validkeys.Add(":unicode");
      validkeys.Add(":filelist");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_weight = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_weight = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_unicode = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_unicode = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Data.File.Type_filelist) {
              ischanged = true;
              vx_p_filelist = (Vx.Data.File.Type_filelist)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_fontface work = new Class_fontface();
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
      return e_fontface;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontface;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontface e_fontface = new Class_fontface();
  public static Type_fontface t_fontface = new Class_fontface();

  /**
   * type: fontfacelist
   * List of fontface
   * (type fontfacelist)
   */
  public interface Type_fontfacelist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Ui.Ui.Type_fontface> vx_listfontface();
    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_int index);
  }

  public class Class_fontfacelist : Vx.Core.Class_base, Type_fontfacelist {

    public List<Vx.Ui.Ui.Type_fontface> vx_p_list = Vx.Core.immutablelist(new List<Vx.Ui.Ui.Type_fontface>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_fontface(index);
    }

    public override Vx.Ui.Ui.Type_fontfacelist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontfacelist,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontfacelist vx_copy(params Object[] vals) {
      Type_fontfacelist output = this;
      bool ischanged = false;
      Class_fontfacelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_fontface> listval = new List<Vx.Ui.Ui.Type_fontface>(val.vx_listfontface());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_fontface) {
          Vx.Ui.Ui.Type_fontface anysub = valsub as Vx.Ui.Ui.Type_fontface;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Ui.Ui.Type_fontface) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_fontface)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_fontfacelist) {
          Type_fontfacelist multi = (Type_fontfacelist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listfontface());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Ui.Ui.Type_fontface) {
              Vx.Ui.Ui.Type_fontface valitem = (Vx.Ui.Ui.Type_fontface)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacelist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_fontfacelist work = new Class_fontfacelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontfacelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontfacelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontfacelist e_fontfacelist = new Class_fontfacelist();
  public static Type_fontfacelist t_fontfacelist = new Class_fontfacelist();

  /**
   * type: fontfacemap
   * Map of fontface
   * (type fontfacemap)
   */
  public interface Type_fontfacemap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_mapfontface();
    public Vx.Ui.Ui.Type_fontface vx_fontface(Vx.Core.Type_string key);
  }

  public class Class_fontfacemap : Vx.Core.Class_base, Type_fontfacemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_fontface) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_fontface castval = (Vx.Ui.Ui.Type_fontface)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_fontface);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> vx_mapfontface() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_fontface(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontfacemap output = new Vx.Ui.Ui.Class_fontfacemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_fontface) {
          Vx.Ui.Ui.Type_fontface castval = (Vx.Ui.Ui.Type_fontface)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontfacemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontfacemap,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontfacemap vx_copy(params Object[] vals) {
      Type_fontfacemap output = this;
      bool ischanged = false;
      Class_fontfacemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontface> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontface>(val.vx_mapfontface());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontfacemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_fontface valany = null;
          if (valsub is Vx.Ui.Ui.Type_fontface) {
            valany = (Vx.Ui.Ui.Type_fontface)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_fontface) {
            valany = valsub as Vx.Ui.Ui.Type_fontface;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_fontfacemap work = new Class_fontfacemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontfacemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontfacemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontfacemap e_fontfacemap = new Class_fontfacemap();
  public static Type_fontfacemap t_fontfacemap = new Class_fontfacemap();

  /**
   * type: fontmap
   * Map of font
   * (type fontmap)
   */
  public interface Type_fontmap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_mapfont();
    public Vx.Ui.Ui.Type_font vx_font(Vx.Core.Type_string key);
  }

  public class Class_fontmap : Vx.Core.Class_base, Type_fontmap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_font) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_font castval = (Vx.Ui.Ui.Type_font)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_font);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_font> vx_mapfont() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_font(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontmap output = new Vx.Ui.Ui.Class_fontmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_font) {
          Vx.Ui.Ui.Type_font castval = (Vx.Ui.Ui.Type_font)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontmap,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontmap vx_copy(params Object[] vals) {
      Type_fontmap output = this;
      bool ischanged = false;
      Class_fontmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_font> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_font>(val.vx_mapfont());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_font valany = null;
          if (valsub is Vx.Ui.Ui.Type_font) {
            valany = (Vx.Ui.Ui.Type_font)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_font) {
            valany = valsub as Vx.Ui.Ui.Type_font;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_fontmap work = new Class_fontmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontmap e_fontmap = new Class_fontmap();
  public static Type_fontmap t_fontmap = new Class_fontmap();

  /**
   * type: fontstyle
   * Univeral Font Style Type
   * (type fontstyle)
   */
  public interface Type_fontstyle : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
  }

  public class Class_fontstyle : Vx.Core.Class_base, Type_fontstyle {

    public Vx.Core.Type_string vx_p_name;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_fontstyle vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontstyle,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontstyle vx_copy(params Object[] vals) {
      Type_fontstyle output = this;
      bool ischanged = false;
      Class_fontstyle val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_fontstyle work = new Class_fontstyle();
        work.vx_p_name = vx_p_name;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontstyle;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontstyle;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontstyle e_fontstyle = new Class_fontstyle();
  public static Type_fontstyle t_fontstyle = new Class_fontstyle();

  /**
   * type: fontstylemap
   * Map of fontstyle
   * (type fontstylemap)
   */
  public interface Type_fontstylemap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_mapfontstyle();
    public Vx.Ui.Ui.Type_fontstyle vx_fontstyle(Vx.Core.Type_string key);
  }

  public class Class_fontstylemap : Vx.Core.Class_base, Type_fontstylemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_fontstyle) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_fontstyle castval = (Vx.Ui.Ui.Type_fontstyle)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_fontstyle);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> vx_mapfontstyle() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_fontstyle(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_fontstylemap output = new Vx.Ui.Ui.Class_fontstylemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_fontstyle) {
          Vx.Ui.Ui.Type_fontstyle castval = (Vx.Ui.Ui.Type_fontstyle)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_fontstylemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fontstylemap,
       vals);
    }

    public override Vx.Ui.Ui.Type_fontstylemap vx_copy(params Object[] vals) {
      Type_fontstylemap output = this;
      bool ischanged = false;
      Class_fontstylemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_fontstyle> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_fontstyle>(val.vx_mapfontstyle());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/fontstylemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_fontstyle valany = null;
          if (valsub is Vx.Ui.Ui.Type_fontstyle) {
            valany = (Vx.Ui.Ui.Type_fontstyle)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_fontstyle) {
            valany = valsub as Vx.Ui.Ui.Type_fontstyle;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_fontstylemap work = new Class_fontstylemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontstylemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fontstylemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fontstylemap e_fontstylemap = new Class_fontstylemap();
  public static Type_fontstylemap t_fontstylemap = new Class_fontstylemap();

  /**
   * type: image
   * Univeral Image Type
   * (type image)
   */
  public interface Type_image : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string label();
    public Vx.Data.File.Type_file file();
  }

  public class Class_image : Vx.Core.Class_base, Type_image {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_label;

    public Vx.Core.Type_string label() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_label != null) {
        output = this.vx_p_label;
      }
      return output;
    }

    public Vx.Data.File.Type_file vx_p_file;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_image vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_image,
       vals);
    }

    public override Vx.Ui.Ui.Type_image vx_copy(params Object[] vals) {
      Type_image output = this;
      bool ischanged = false;
      Class_image val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_label = val.label();
      Vx.Data.File.Type_file vx_p_file = val.file();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":label");
      validkeys.Add(":file");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_label = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_label = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Data.File.Type_file) {
              ischanged = true;
              vx_p_file = (Vx.Data.File.Type_file)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_image work = new Class_image();
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
      return e_image;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_image;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_image e_image = new Class_image();
  public static Type_image t_image = new Class_image();

  /**
   * type: layout
   * Universal Layout
   * (type layout)
   */
  public interface Type_layout : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout();
  }

  public class Class_layout : Vx.Core.Class_base, Type_layout {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_p_fn_layout;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_layout vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_layout,
       vals);
    }

    public override Vx.Ui.Ui.Type_layout vx_copy(params Object[] vals) {
      Type_layout output = this;
      bool ischanged = false;
      Class_layout val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_p_fn_layout = val.fn_layout();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":fn-layout");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent) {
              ischanged = true;
              vx_p_fn_layout = (Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_layout work = new Class_layout();
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
      return e_layout;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_layout;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_layout e_layout = new Class_layout();
  public static Type_layout t_layout = new Class_layout();

  /**
   * type: layoutengine
   * Pluggable layoutengine
   * (type layoutengine)
   */
  public interface Type_layoutengine : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
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

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_print vx_p_boolean_print;

    public Vx.Ui.Ui.Func_boolean_print boolean_print() {
      Vx.Ui.Ui.Func_boolean_print output = Vx.Ui.Ui.e_boolean_print;
      if (this.vx_p_boolean_print != null) {
        output = this.vx_p_boolean_print;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_p_boolean_layoutremove;

    public Vx.Ui.Ui.Func_boolean_layoutremove_from_ui boolean_layoutremove() {
      Vx.Ui.Ui.Func_boolean_layoutremove_from_ui output = Vx.Ui.Ui.e_boolean_layoutremove_from_ui;
      if (this.vx_p_boolean_layoutremove != null) {
        output = this.vx_p_boolean_layoutremove;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_p_boolean_layoutselected;

    public Vx.Ui.Ui.Func_boolean_layoutselected_from_ui boolean_layoutselected() {
      Vx.Ui.Ui.Func_boolean_layoutselected_from_ui output = Vx.Ui.Ui.e_boolean_layoutselected_from_ui;
      if (this.vx_p_boolean_layoutselected != null) {
        output = this.vx_p_boolean_layoutselected;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_p_boolean_layoutvisible;

    public Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui boolean_layoutvisible() {
      Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui output = Vx.Ui.Ui.e_boolean_layoutvisible_from_ui;
      if (this.vx_p_boolean_layoutvisible != null) {
        output = this.vx_p_boolean_layoutvisible;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layoutmap vx_p_layoutmap;

    public Vx.Ui.Ui.Type_layoutmap layoutmap() {
      Vx.Ui.Ui.Type_layoutmap output = Vx.Ui.Ui.e_layoutmap;
      if (this.vx_p_layoutmap != null) {
        output = this.vx_p_layoutmap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_p_layoutelse;

    public Vx.Ui.Ui.Type_layout layoutelse() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layoutelse != null) {
        output = this.vx_p_layoutelse;
      }
      return output;
    }

    public Vx.Ui.Ui.Func_stylesheet_render vx_p_stylesheetrender;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_layoutengine vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_layoutengine,
       vals);
    }

    public override Vx.Ui.Ui.Type_layoutengine vx_copy(params Object[] vals) {
      Type_layoutengine output = this;
      bool ischanged = false;
      Class_layoutengine val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Ui.Ui.Func_boolean_print vx_p_boolean_print = val.boolean_print();
      Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_p_boolean_layoutremove = val.boolean_layoutremove();
      Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_p_boolean_layoutselected = val.boolean_layoutselected();
      Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_p_boolean_layoutvisible = val.boolean_layoutvisible();
      Vx.Ui.Ui.Type_layoutmap vx_p_layoutmap = val.layoutmap();
      Vx.Ui.Ui.Type_layout vx_p_layoutelse = val.layoutelse();
      Vx.Ui.Ui.Func_stylesheet_render vx_p_stylesheetrender = val.stylesheetrender();
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
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_boolean_print) {
              ischanged = true;
              vx_p_boolean_print = (Vx.Ui.Ui.Func_boolean_print)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutremove_from_ui) {
              ischanged = true;
              vx_p_boolean_layoutremove = (Vx.Ui.Ui.Func_boolean_layoutremove_from_ui)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutselected_from_ui) {
              ischanged = true;
              vx_p_boolean_layoutselected = (Vx.Ui.Ui.Func_boolean_layoutselected_from_ui)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui) {
              ischanged = true;
              vx_p_boolean_layoutvisible = (Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_layoutmap) {
              ischanged = true;
              vx_p_layoutmap = (Vx.Ui.Ui.Type_layoutmap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_layout) {
              ischanged = true;
              vx_p_layoutelse = (Vx.Ui.Ui.Type_layout)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Func_stylesheet_render) {
              ischanged = true;
              vx_p_stylesheetrender = (Vx.Ui.Ui.Func_stylesheet_render)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_layoutengine work = new Class_layoutengine();
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
      return e_layoutengine;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_layoutengine;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_layoutengine e_layoutengine = new Class_layoutengine();
  public static Type_layoutengine t_layoutengine = new Class_layoutengine();

  /**
   * type: layoutlist
   * Map of layout
   * (type layoutlist)
   */
  public interface Type_layoutlist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Ui.Ui.Type_layout> vx_listlayout();
    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_int index);
  }

  public class Class_layoutlist : Vx.Core.Class_base, Type_layoutlist {

    public List<Vx.Ui.Ui.Type_layout> vx_p_list = Vx.Core.immutablelist(new List<Vx.Ui.Ui.Type_layout>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_layout(index);
    }

    public override Vx.Ui.Ui.Type_layoutlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_layoutlist,
       vals);
    }

    public override Vx.Ui.Ui.Type_layoutlist vx_copy(params Object[] vals) {
      Type_layoutlist output = this;
      bool ischanged = false;
      Class_layoutlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_layout> listval = new List<Vx.Ui.Ui.Type_layout>(val.vx_listlayout());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_layout) {
          Vx.Ui.Ui.Type_layout anysub = valsub as Vx.Ui.Ui.Type_layout;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Ui.Ui.Type_layout) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_layout)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_layoutlist) {
          Type_layoutlist multi = (Type_layoutlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listlayout());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Ui.Ui.Type_layout) {
              Vx.Ui.Ui.Type_layout valitem = (Vx.Ui.Ui.Type_layout)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutlist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_layoutlist work = new Class_layoutlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layoutlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_layoutlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_layoutlist e_layoutlist = new Class_layoutlist();
  public static Type_layoutlist t_layoutlist = new Class_layoutlist();

  /**
   * type: layoutmap
   * Map of layout
   * (type layoutmap)
   */
  public interface Type_layoutmap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_maplayout();
    public Vx.Ui.Ui.Type_layout vx_layout(Vx.Core.Type_string key);
  }

  public class Class_layoutmap : Vx.Core.Class_base, Type_layoutmap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_layout) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_layout castval = (Vx.Ui.Ui.Type_layout)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_layout);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> vx_maplayout() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_layout(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_layoutmap output = new Vx.Ui.Ui.Class_layoutmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_layout) {
          Vx.Ui.Ui.Type_layout castval = (Vx.Ui.Ui.Type_layout)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_layoutmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_layoutmap,
       vals);
    }

    public override Vx.Ui.Ui.Type_layoutmap vx_copy(params Object[] vals) {
      Type_layoutmap output = this;
      bool ischanged = false;
      Class_layoutmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_layout> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_layout>(val.vx_maplayout());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/layoutmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_layout valany = null;
          if (valsub is Vx.Ui.Ui.Type_layout) {
            valany = (Vx.Ui.Ui.Type_layout)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_layout) {
            valany = valsub as Vx.Ui.Ui.Type_layout;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_layoutmap work = new Class_layoutmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layoutmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_layoutmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_layoutmap e_layoutmap = new Class_layoutmap();
  public static Type_layoutmap t_layoutmap = new Class_layoutmap();

  /**
   * type: pin
   * Pin an element
   * (type pin)
   */
  public interface Type_pin : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
  }

  public class Class_pin : Vx.Core.Class_base, Type_pin {

    public Vx.Core.Type_string vx_p_name;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_pin vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_pin,
       vals);
    }

    public override Vx.Ui.Ui.Type_pin vx_copy(params Object[] vals) {
      Type_pin output = this;
      bool ischanged = false;
      Class_pin val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_pin work = new Class_pin();
        work.vx_p_name = vx_p_name;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_pin;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_pin;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_pin e_pin = new Class_pin();
  public static Type_pin t_pin = new Class_pin();

  /**
   * type: point
   * Universal Point
   * (type point)
   */
  public interface Type_point : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_int x();
    public Vx.Core.Type_int y();
    public Vx.Core.Type_int z();
    public Vx.Core.Type_int t();
    public Vx.Core.Type_int i();
    public Vx.Ui.Ui.Type_pointtype pointtype();
  }

  public class Class_point : Vx.Core.Class_base, Type_point {

    public Vx.Core.Type_int vx_p_x;

    public Vx.Core.Type_int x() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_x != null) {
        output = this.vx_p_x;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_y;

    public Vx.Core.Type_int y() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_y != null) {
        output = this.vx_p_y;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_z;

    public Vx.Core.Type_int z() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_z != null) {
        output = this.vx_p_z;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_t;

    public Vx.Core.Type_int t() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_t != null) {
        output = this.vx_p_t;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_i;

    public Vx.Core.Type_int i() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_i != null) {
        output = this.vx_p_i;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_pointtype vx_p_pointtype;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_point vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_point,
       vals);
    }

    public override Vx.Ui.Ui.Type_point vx_copy(params Object[] vals) {
      Type_point output = this;
      bool ischanged = false;
      Class_point val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_x = val.x();
      Vx.Core.Type_int vx_p_y = val.y();
      Vx.Core.Type_int vx_p_z = val.z();
      Vx.Core.Type_int vx_p_t = val.t();
      Vx.Core.Type_int vx_p_i = val.i();
      Vx.Ui.Ui.Type_pointtype vx_p_pointtype = val.pointtype();
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
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_x = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_x = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_y = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_y = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_z = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_z = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_t = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_t = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_i = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_i = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_pointtype) {
              ischanged = true;
              vx_p_pointtype = (Vx.Ui.Ui.Type_pointtype)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_point work = new Class_point();
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
      return e_point;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_point;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_point e_point = new Class_point();
  public static Type_point t_point = new Class_point();

  /**
   * type: pointtype
   * Universal Point Scale
   * (type pointtype)
   */
  public interface Type_pointtype : Vx.Core.Type_any {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_pointtype : Vx.Core.Class_base, Type_pointtype {

    public override Vx.Ui.Ui.Type_pointtype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_pointtype,
       vals);
    }

    public override Vx.Ui.Ui.Type_pointtype vx_copy(params Object[] vals) {
      Type_pointtype output = this;
      bool ischanged = false;
      Class_pointtype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_pointtype work = new Class_pointtype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_pointtype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_pointtype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_pointtype e_pointtype = new Class_pointtype();
  public static Type_pointtype t_pointtype = new Class_pointtype();

  /**
   * type: style
   * Universal Style
   * (type style)
   */
  public interface Type_style : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
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

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_align vx_p_align;

    public Vx.Ui.Ui.Type_align align() {
      Vx.Ui.Ui.Type_align output = Vx.Ui.Ui.e_align;
      if (this.vx_p_align != null) {
        output = this.vx_p_align;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_bounds vx_p_boundsmargin;

    public Vx.Ui.Ui.Type_bounds boundsmargin() {
      Vx.Ui.Ui.Type_bounds output = Vx.Ui.Ui.e_bounds;
      if (this.vx_p_boundsmargin != null) {
        output = this.vx_p_boundsmargin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_bounds vx_p_boundspadding;

    public Vx.Ui.Ui.Type_bounds boundspadding() {
      Vx.Ui.Ui.Type_bounds output = Vx.Ui.Ui.e_bounds;
      if (this.vx_p_boundspadding != null) {
        output = this.vx_p_boundspadding;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_color_bkg;

    public Vx.Core.Type_string color_bkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_bkg != null) {
        output = this.vx_p_color_bkg;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_color_bkghover;

    public Vx.Core.Type_string color_bkghover() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_bkghover != null) {
        output = this.vx_p_color_bkghover;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_color_border;

    public Vx.Core.Type_string color_border() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_border != null) {
        output = this.vx_p_color_border;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_color_font;

    public Vx.Core.Type_string color_font() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_color_font != null) {
        output = this.vx_p_color_font;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_cursor vx_p_cursor;

    public Vx.Ui.Ui.Type_cursor cursor() {
      Vx.Ui.Ui.Type_cursor output = Vx.Ui.Ui.e_cursor;
      if (this.vx_p_cursor != null) {
        output = this.vx_p_cursor;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_flip vx_p_flip;

    public Vx.Ui.Ui.Type_flip flip() {
      Vx.Ui.Ui.Type_flip output = Vx.Ui.Ui.e_flip;
      if (this.vx_p_flip != null) {
        output = this.vx_p_flip;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_font vx_p_font;

    public Vx.Ui.Ui.Type_font font() {
      Vx.Ui.Ui.Type_font output = Vx.Ui.Ui.e_font;
      if (this.vx_p_font != null) {
        output = this.vx_p_font;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_hidden;

    public Vx.Core.Type_boolean hidden() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_hidden != null) {
        output = this.vx_p_hidden;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_image vx_p_image_bkg;

    public Vx.Ui.Ui.Type_image image_bkg() {
      Vx.Ui.Ui.Type_image output = Vx.Ui.Ui.e_image;
      if (this.vx_p_image_bkg != null) {
        output = this.vx_p_image_bkg;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_p_layout;

    public Vx.Ui.Ui.Type_layout layout() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layout != null) {
        output = this.vx_p_layout;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_styletype vx_p_type;

    public Vx.Ui.Ui.Type_styletype type() {
      Vx.Ui.Ui.Type_styletype output = Vx.Ui.Ui.e_styletype;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_pin vx_p_pin;

    public Vx.Ui.Ui.Type_pin pin() {
      Vx.Ui.Ui.Type_pin output = Vx.Ui.Ui.e_pin;
      if (this.vx_p_pin != null) {
        output = this.vx_p_pin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point vx_p_pointorigin;

    public Vx.Ui.Ui.Type_point pointorigin() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointorigin != null) {
        output = this.vx_p_pointorigin;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point vx_p_pointpos;

    public Vx.Ui.Ui.Type_point pointpos() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointpos != null) {
        output = this.vx_p_pointpos;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point vx_p_pointrotate;

    public Vx.Ui.Ui.Type_point pointrotate() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointrotate != null) {
        output = this.vx_p_pointrotate;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_point vx_p_pointsize;

    public Vx.Ui.Ui.Type_point pointsize() {
      Vx.Ui.Ui.Type_point output = Vx.Ui.Ui.e_point;
      if (this.vx_p_pointsize != null) {
        output = this.vx_p_pointsize;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_scroll_x;

    public Vx.Core.Type_boolean scroll_x() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_scroll_x != null) {
        output = this.vx_p_scroll_x;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_scroll_y;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_style vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_style,
       vals);
    }

    public override Vx.Ui.Ui.Type_style vx_copy(params Object[] vals) {
      Type_style output = this;
      bool ischanged = false;
      Class_style val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Ui.Ui.Type_align vx_p_align = val.align();
      Vx.Ui.Ui.Type_bounds vx_p_boundsmargin = val.boundsmargin();
      Vx.Ui.Ui.Type_bounds vx_p_boundspadding = val.boundspadding();
      Vx.Core.Type_string vx_p_color_bkg = val.color_bkg();
      Vx.Core.Type_string vx_p_color_bkghover = val.color_bkghover();
      Vx.Core.Type_string vx_p_color_border = val.color_border();
      Vx.Core.Type_string vx_p_color_font = val.color_font();
      Vx.Ui.Ui.Type_cursor vx_p_cursor = val.cursor();
      Vx.Ui.Ui.Type_flip vx_p_flip = val.flip();
      Vx.Ui.Ui.Type_font vx_p_font = val.font();
      Vx.Core.Type_boolean vx_p_hidden = val.hidden();
      Vx.Ui.Ui.Type_image vx_p_image_bkg = val.image_bkg();
      Vx.Ui.Ui.Type_layout vx_p_layout = val.layout();
      Vx.Ui.Ui.Type_styletype vx_p_type = val.type();
      Vx.Ui.Ui.Type_pin vx_p_pin = val.pin();
      Vx.Ui.Ui.Type_point vx_p_pointorigin = val.pointorigin();
      Vx.Ui.Ui.Type_point vx_p_pointpos = val.pointpos();
      Vx.Ui.Ui.Type_point vx_p_pointrotate = val.pointrotate();
      Vx.Ui.Ui.Type_point vx_p_pointsize = val.pointsize();
      Vx.Core.Type_boolean vx_p_scroll_x = val.scroll_x();
      Vx.Core.Type_boolean vx_p_scroll_y = val.scroll_y();
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
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_align) {
              ischanged = true;
              vx_p_align = (Vx.Ui.Ui.Type_align)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_bounds) {
              ischanged = true;
              vx_p_boundsmargin = (Vx.Ui.Ui.Type_bounds)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_bounds) {
              ischanged = true;
              vx_p_boundspadding = (Vx.Ui.Ui.Type_bounds)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_color_bkg = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_bkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_color_bkghover = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_bkghover = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_color_border = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_border = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_color_font = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_color_font = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_cursor) {
              ischanged = true;
              vx_p_cursor = (Vx.Ui.Ui.Type_cursor)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_flip) {
              ischanged = true;
              vx_p_flip = (Vx.Ui.Ui.Type_flip)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_font) {
              ischanged = true;
              vx_p_font = (Vx.Ui.Ui.Type_font)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_hidden = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_hidden = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_image) {
              ischanged = true;
              vx_p_image_bkg = (Vx.Ui.Ui.Type_image)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_layout) {
              ischanged = true;
              vx_p_layout = (Vx.Ui.Ui.Type_layout)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_styletype) {
              ischanged = true;
              vx_p_type = (Vx.Ui.Ui.Type_styletype)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_pin) {
              ischanged = true;
              vx_p_pin = (Vx.Ui.Ui.Type_pin)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_point) {
              ischanged = true;
              vx_p_pointorigin = (Vx.Ui.Ui.Type_point)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_point) {
              ischanged = true;
              vx_p_pointpos = (Vx.Ui.Ui.Type_point)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_point) {
              ischanged = true;
              vx_p_pointrotate = (Vx.Ui.Ui.Type_point)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_point) {
              ischanged = true;
              vx_p_pointsize = (Vx.Ui.Ui.Type_point)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_scroll_x = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_scroll_x = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_scroll_y = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_scroll_y = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_style work = new Class_style();
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
      return e_style;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_style;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_style e_style = new Class_style();
  public static Type_style t_style = new Class_style();

  /**
   * type: stylelist
   * Universal Stylelist
   * (type stylelist)
   */
  public interface Type_stylelist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Ui.Ui.Type_style> vx_liststyle();
    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_int index);
  }

  public class Class_stylelist : Vx.Core.Class_base, Type_stylelist {

    public List<Vx.Ui.Ui.Type_style> vx_p_list = Vx.Core.immutablelist(new List<Vx.Ui.Ui.Type_style>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_style(index);
    }

    public override Vx.Ui.Ui.Type_stylelist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylelist,
       vals);
    }

    public override Vx.Ui.Ui.Type_stylelist vx_copy(params Object[] vals) {
      Type_stylelist output = this;
      bool ischanged = false;
      Class_stylelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_style> listval = new List<Vx.Ui.Ui.Type_style>(val.vx_liststyle());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_style) {
          Vx.Ui.Ui.Type_style anysub = valsub as Vx.Ui.Ui.Type_style;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Ui.Ui.Type_style) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_style)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_stylelist) {
          Type_stylelist multi = (Type_stylelist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_liststyle());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Ui.Ui.Type_style) {
              Vx.Ui.Ui.Type_style valitem = (Vx.Ui.Ui.Type_style)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylelist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_stylelist work = new Class_stylelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stylelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_stylelist e_stylelist = new Class_stylelist();
  public static Type_stylelist t_stylelist = new Class_stylelist();

  /**
   * type: stylemap
   * Universal Stylemap
   * (type stylemap)
   */
  public interface Type_stylemap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_mapstyle();
    public Vx.Ui.Ui.Type_style vx_style(Vx.Core.Type_string key);
  }

  public class Class_stylemap : Vx.Core.Class_base, Type_stylemap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_style) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_style castval = (Vx.Ui.Ui.Type_style)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_style);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_style> vx_mapstyle() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_style(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_stylemap output = new Vx.Ui.Ui.Class_stylemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_style) {
          Vx.Ui.Ui.Type_style castval = (Vx.Ui.Ui.Type_style)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_stylemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylemap,
       vals);
    }

    public override Vx.Ui.Ui.Type_stylemap vx_copy(params Object[] vals) {
      Type_stylemap output = this;
      bool ischanged = false;
      Class_stylemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_style> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_style>(val.vx_mapstyle());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/stylemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_style valany = null;
          if (valsub is Vx.Ui.Ui.Type_style) {
            valany = (Vx.Ui.Ui.Type_style)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_style) {
            valany = valsub as Vx.Ui.Ui.Type_style;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_stylemap work = new Class_stylemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stylemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_stylemap e_stylemap = new Class_stylemap();
  public static Type_stylemap t_stylemap = new Class_stylemap();

  /**
   * type: stylesheet
   * Universal Stylesheet
   * (type stylesheet)
   */
  public interface Type_stylesheet : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Ui.Ui.Type_fontfacemap fontfacemap();
    public Vx.Ui.Ui.Type_stylemap stylemap();
  }

  public class Class_stylesheet : Vx.Core.Class_base, Type_stylesheet {

    public Vx.Ui.Ui.Type_fontfacemap vx_p_fontfacemap;

    public Vx.Ui.Ui.Type_fontfacemap fontfacemap() {
      Vx.Ui.Ui.Type_fontfacemap output = Vx.Ui.Ui.e_fontfacemap;
      if (this.vx_p_fontfacemap != null) {
        output = this.vx_p_fontfacemap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylemap vx_p_stylemap;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_stylesheet vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylesheet,
       vals);
    }

    public override Vx.Ui.Ui.Type_stylesheet vx_copy(params Object[] vals) {
      Type_stylesheet output = this;
      bool ischanged = false;
      Class_stylesheet val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Ui.Ui.Type_fontfacemap vx_p_fontfacemap = val.fontfacemap();
      Vx.Ui.Ui.Type_stylemap vx_p_stylemap = val.stylemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":fontfacemap");
      validkeys.Add(":stylemap");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_fontfacemap) {
              ischanged = true;
              vx_p_fontfacemap = (Vx.Ui.Ui.Type_fontfacemap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_stylemap) {
              ischanged = true;
              vx_p_stylemap = (Vx.Ui.Ui.Type_stylemap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_stylesheet work = new Class_stylesheet();
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
      return e_stylesheet;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_stylesheet e_stylesheet = new Class_stylesheet();
  public static Type_stylesheet t_stylesheet = new Class_stylesheet();

  /**
   * type: styletype
   * Universal Style Type
   * (type styletype)
   */
  public interface Type_styletype : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
  }

  public class Class_styletype : Vx.Core.Class_base, Type_styletype {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_styletype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_styletype,
       vals);
    }

    public override Vx.Ui.Ui.Type_styletype vx_copy(params Object[] vals) {
      Type_styletype output = this;
      bool ischanged = false;
      Class_styletype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_styletype work = new Class_styletype();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_styletype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_styletype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_styletype e_styletype = new Class_styletype();
  public static Type_styletype t_styletype = new Class_styletype();

  /**
   * type: ui
   * Universal UI Element
   * (type ui)
   */
  public interface Type_ui : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
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

    public Vx.Core.Type_string vx_p_uid;

    public Vx.Core.Type_string uid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_uid != null) {
        output = this.vx_p_uid;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layout vx_p_layout;

    public Vx.Ui.Ui.Type_layout layout() {
      Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
      if (this.vx_p_layout != null) {
        output = this.vx_p_layout;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_path;

    public Vx.Core.Type_string path() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_path != null) {
        output = this.vx_p_path;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_hidden;

    public Vx.Core.Type_boolean hidden() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_hidden != null) {
        output = this.vx_p_hidden;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_selected;

    public Vx.Core.Type_boolean selected() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_selected != null) {
        output = this.vx_p_selected;
      }
      return output;
    }

    public Vx.Core.Type_boolean vx_p_selectmulti;

    public Vx.Core.Type_boolean selectmulti() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_selectmulti != null) {
        output = this.vx_p_selectmulti;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_style vx_p_style;

    public Vx.Ui.Ui.Type_style style() {
      Vx.Ui.Ui.Type_style output = Vx.Ui.Ui.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylelist vx_p_stylelist;

    public Vx.Ui.Ui.Type_stylelist stylelist() {
      Vx.Ui.Ui.Type_stylelist output = Vx.Ui.Ui.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Event.Type_eventmap vx_p_eventmap;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_p_data;

    public Vx.Core.Type_any data() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_data != null) {
        output = this.vx_p_data;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_uimap vx_p_uimap;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_ui vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_ui,
       vals);
    }

    public override Vx.Ui.Ui.Type_ui vx_copy(params Object[] vals) {
      Type_ui output = this;
      bool ischanged = false;
      Class_ui val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_uid = val.uid();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Ui.Ui.Type_layout vx_p_layout = val.layout();
      Vx.Core.Type_string vx_p_path = val.path();
      Vx.Core.Type_boolean vx_p_hidden = val.hidden();
      Vx.Core.Type_boolean vx_p_selected = val.selected();
      Vx.Core.Type_boolean vx_p_selectmulti = val.selectmulti();
      Vx.Ui.Ui.Type_style vx_p_style = val.style();
      Vx.Ui.Ui.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Core.Type_any vx_p_data = val.data();
      Vx.Ui.Ui.Type_uimap vx_p_uimap = val.uimap();
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
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_uid = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_uid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_layout) {
              ischanged = true;
              vx_p_layout = (Vx.Ui.Ui.Type_layout)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_path = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_path = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_hidden = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_hidden = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_selected = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_selected = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_boolean) {
              ischanged = true;
              vx_p_selectmulti = (Vx.Core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_selectmulti = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_style) {
              ischanged = true;
              vx_p_style = (Vx.Ui.Ui.Type_style)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_stylelist) {
              ischanged = true;
              vx_p_stylelist = (Vx.Ui.Ui.Type_stylelist)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Event.Type_eventmap) {
              ischanged = true;
              vx_p_eventmap = (Vx.Event.Type_eventmap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Core.Type_any) {
              ischanged = true;
              vx_p_data = (Vx.Core.Type_any)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_uimap) {
              ischanged = true;
              vx_p_uimap = (Vx.Ui.Ui.Type_uimap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_ui work = new Class_ui();
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
      return e_ui;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_ui;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_ui e_ui = new Class_ui();
  public static Type_ui t_ui = new Class_ui();

  /**
   * type: uiengine
   * Template for uiengine
   * (type uiengine)
   */
  public interface Type_uiengine : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Ui.Ui.Type_uimap parentmap();
    public Vx.Ui.Ui.Type_layoutengine layoutengine();
    public Vx.Ui.Ui.Type_stylesheet stylesheet();
    public Vx.Ui.Ui.Type_ui ui();
  }

  public class Class_uiengine : Vx.Core.Class_base, Type_uiengine {

    public Vx.Ui.Ui.Type_uimap vx_p_parentmap;

    public Vx.Ui.Ui.Type_uimap parentmap() {
      Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
      if (this.vx_p_parentmap != null) {
        output = this.vx_p_parentmap;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_layoutengine vx_p_layoutengine;

    public Vx.Ui.Ui.Type_layoutengine layoutengine() {
      Vx.Ui.Ui.Type_layoutengine output = Vx.Ui.Ui.e_layoutengine;
      if (this.vx_p_layoutengine != null) {
        output = this.vx_p_layoutengine;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_stylesheet vx_p_stylesheet;

    public Vx.Ui.Ui.Type_stylesheet stylesheet() {
      Vx.Ui.Ui.Type_stylesheet output = Vx.Ui.Ui.e_stylesheet;
      if (this.vx_p_stylesheet != null) {
        output = this.vx_p_stylesheet;
      }
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_p_ui;

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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Ui.Ui.Type_uiengine vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_uiengine,
       vals);
    }

    public override Vx.Ui.Ui.Type_uiengine vx_copy(params Object[] vals) {
      Type_uiengine output = this;
      bool ischanged = false;
      Class_uiengine val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Ui.Ui.Type_uimap vx_p_parentmap = val.parentmap();
      Vx.Ui.Ui.Type_layoutengine vx_p_layoutengine = val.layoutengine();
      Vx.Ui.Ui.Type_stylesheet vx_p_stylesheet = val.stylesheet();
      Vx.Ui.Ui.Type_ui vx_p_ui = val.ui();
      List<string> validkeys = new List<string>();
      validkeys.Add(":parentmap");
      validkeys.Add(":layoutengine");
      validkeys.Add(":stylesheet");
      validkeys.Add(":ui");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_uimap) {
              ischanged = true;
              vx_p_parentmap = (Vx.Ui.Ui.Type_uimap)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_layoutengine) {
              ischanged = true;
              vx_p_layoutengine = (Vx.Ui.Ui.Type_layoutengine)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_stylesheet) {
              ischanged = true;
              vx_p_stylesheet = (Vx.Ui.Ui.Type_stylesheet)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
            } else if (valsub is Vx.Ui.Ui.Type_ui) {
              ischanged = true;
              vx_p_ui = (Vx.Ui.Ui.Type_ui)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_uiengine work = new Class_uiengine();
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
      return e_uiengine;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_uiengine;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_uiengine e_uiengine = new Class_uiengine();
  public static Type_uiengine t_uiengine = new Class_uiengine();

  /**
   * type: uilist
   * List of ui
   * (type uilist)
   */
  public interface Type_uilist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Ui.Ui.Type_ui> vx_listui();
    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_int index);
  }

  public class Class_uilist : Vx.Core.Class_base, Type_uilist {

    public List<Vx.Ui.Ui.Type_ui> vx_p_list = Vx.Core.immutablelist(new List<Vx.Ui.Ui.Type_ui>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_ui(index);
    }

    public override Vx.Ui.Ui.Type_uilist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_uilist,
       vals);
    }

    public override Vx.Ui.Ui.Type_uilist vx_copy(params Object[] vals) {
      Type_uilist output = this;
      bool ischanged = false;
      Class_uilist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Ui.Ui.Type_ui> listval = new List<Vx.Ui.Ui.Type_ui>(val.vx_listui());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Ui.Ui.Type_ui) {
          Vx.Ui.Ui.Type_ui anysub = valsub as Vx.Ui.Ui.Type_ui;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Ui.Ui.Type_ui) {
          ischanged = true;
          listval.Add((Vx.Ui.Ui.Type_ui)valsub);
        } else if (valsub is Vx.Ui.Ui.Type_uilist) {
          Type_uilist multi = (Type_uilist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listui());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Ui.Ui.Type_ui) {
              Vx.Ui.Ui.Type_ui valitem = (Vx.Ui.Ui.Type_ui)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uilist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_uilist work = new Class_uilist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uilist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_uilist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_uilist e_uilist = new Class_uilist();
  public static Type_uilist t_uilist = new Class_uilist();

  /**
   * type: uimap
   * Map of ui
   * (type uimap)
   */
  public interface Type_uimap : Vx.Core.Type_map {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_mapui();
    public Vx.Ui.Ui.Type_ui vx_ui(Vx.Core.Type_string key);
  }

  public class Class_uimap : Vx.Core.Class_base, Type_uimap {

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (value is Vx.Ui.Ui.Type_ui) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Ui.Ui.Type_ui castval = (Vx.Ui.Ui.Type_ui)value;
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
      output = mapval.getOrDefault(skey, Vx.Ui.Ui.e_ui);
      return output;
    }

    public Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> vx_mapui() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_ui(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Ui.Ui.Class_uimap output = new Vx.Ui.Ui.Class_uimap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> map = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (val is Vx.Ui.Ui.Type_ui) {
          Vx.Ui.Ui.Type_ui castval = (Vx.Ui.Ui.Type_ui)val;
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uimap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Ui.Ui.Type_uimap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_uimap,
       vals);
    }

    public override Vx.Ui.Ui.Type_uimap vx_copy(params Object[] vals) {
      Type_uimap output = this;
      bool ischanged = false;
      Class_uimap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Ui.Ui.Type_ui> mapval = new Vx.Core.LinkedHashMap<string, Vx.Ui.Ui.Type_ui>(val.vx_mapui());
      Vx.Core.Type_msg msg;
      string key = "";
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstring = valsub as Vx.Core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/ui/ui/uimap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Ui.Ui.Type_ui valany = null;
          if (valsub is Vx.Ui.Ui.Type_ui) {
            valany = (Vx.Ui.Ui.Type_ui)valsub;
          } else if (valsub is Vx.Ui.Ui.Type_ui) {
            valany = valsub as Vx.Ui.Ui.Type_ui;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = valsub as Vx.Core.Type_any;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
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
        Class_uimap work = new Class_uimap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uimap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_uimap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_uimap e_uimap = new Class_uimap();
  public static Type_uimap t_uimap = new Class_uimap();

  /**
   * Constant: align-center
   * Logical Center Align in parent
   * {align}
   */
  public class Const_align_center : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_align_center output) {
    }


  }

  public static Const_align_center c_align_center = new Const_align_center();


  /**
   * Constant: align-left
   * Logical Left Align in parent
   * {align}
   */
  public class Const_align_left : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_align_left output) {
    }


  }

  public static Const_align_left c_align_left = new Const_align_left();


  /**
   * Constant: align-right
   * Logical Right Align in parent
   * {align}
   */
  public class Const_align_right : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_align_right output) {
    }


  }

  public static Const_align_right c_align_right = new Const_align_right();


  /**
   * Constant: flip-x
   * Logical Flip Horizontally
   * {align}
   */
  public class Const_flip_x : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_flip_x output) {
    }


  }

  public static Const_flip_x c_flip_x = new Const_flip_x();


  /**
   * Constant: flip-xy
   * Logical Flip Vertically and Horizontally
   * {align}
   */
  public class Const_flip_xy : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_flip_xy output) {
    }


  }

  public static Const_flip_xy c_flip_xy = new Const_flip_xy();


  /**
   * Constant: flip-y
   * Logical Flip Vertically
   * {align}
   */
  public class Const_flip_y : Vx.Ui.Ui.Class_align, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_flip_y output) {
    }


  }

  public static Const_flip_y c_flip_y = new Const_flip_y();


  /**
   * Constant: layout-app
   * {layout}
   */
  public class Const_layout_app : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_app output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-app")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_app c_layout_app = new Const_layout_app();


  /**
   * Constant: layout-background
   * {layout}
   */
  public class Const_layout_background : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_background output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-background")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_background c_layout_background = new Const_layout_background();


  /**
   * Constant: layout-button
   * {layout}
   */
  public class Const_layout_button : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_button output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-button")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_button c_layout_button = new Const_layout_button();


  /**
   * Constant: layout-combobox
   * {layout}
   */
  public class Const_layout_combobox : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_combobox output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-combobox")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_combobox c_layout_combobox = new Const_layout_combobox();


  /**
   * Constant: layout-else
   * {layout}
   */
  public class Const_layout_else : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_else output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-else")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_else c_layout_else = new Const_layout_else();


  /**
   * Constant: layout-flow-columns
   * {layout}
   */
  public class Const_layout_flow_columns : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_columns output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-flow-columns")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_flow_columns c_layout_flow_columns = new Const_layout_flow_columns();


  /**
   * Constant: layout-flow-item
   * {layout}
   */
  public class Const_layout_flow_item : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_item output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-flow-item")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_flow_item c_layout_flow_item = new Const_layout_flow_item();


  /**
   * Constant: layout-flow-rows
   * {layout}
   */
  public class Const_layout_flow_rows : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_flow_rows output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-flow-rows")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_flow_rows c_layout_flow_rows = new Const_layout_flow_rows();


  /**
   * Constant: layout-image
   * {layout}
   */
  public class Const_layout_image : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_image output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-image")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_image c_layout_image = new Const_layout_image();


  /**
   * Constant: layout-label
   * {layout}
   */
  public class Const_layout_label : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_label output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-label")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_label c_layout_label = new Const_layout_label();


  /**
   * Constant: layout-main
   * {layout}
   */
  public class Const_layout_main : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_main output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-main")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_main c_layout_main = new Const_layout_main();


  /**
   * Constant: layout-maxpanel
   * {layout}
   */
  public class Const_layout_maxpanel : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_maxpanel output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-maxpanel")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_maxpanel c_layout_maxpanel = new Const_layout_maxpanel();


  /**
   * Constant: layout-menubar
   * {layout}
   */
  public class Const_layout_menubar : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_menubar output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-menubar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_menubar c_layout_menubar = new Const_layout_menubar();


  /**
   * Constant: layout-menudrawer
   * {layout}
   */
  public class Const_layout_menudrawer : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_menudrawer output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-menudrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_menudrawer c_layout_menudrawer = new Const_layout_menudrawer();


  /**
   * Constant: layout-msgbox
   * {layout}
   */
  public class Const_layout_msgbox : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_msgbox output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-msgbox")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_msgbox c_layout_msgbox = new Const_layout_msgbox();


  /**
   * Constant: layout-navbar
   * {layout}
   */
  public class Const_layout_navbar : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_navbar output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-navbar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_navbar c_layout_navbar = new Const_layout_navbar();


  /**
   * Constant: layout-navdrawer
   * {layout}
   */
  public class Const_layout_navdrawer : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_navdrawer output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-navdrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_navdrawer c_layout_navdrawer = new Const_layout_navdrawer();


  /**
   * Constant: layout-panel
   * {layout}
   */
  public class Const_layout_panel : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_panel output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-panel")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_panel c_layout_panel = new Const_layout_panel();


  /**
   * Constant: layout-parallax
   * {layout}
   */
  public class Const_layout_parallax : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_parallax output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-parallax")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_parallax c_layout_parallax = new Const_layout_parallax();


  /**
   * Constant: layout-statusbar
   * {layout}
   */
  public class Const_layout_statusbar : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_statusbar output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-statusbar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_statusbar c_layout_statusbar = new Const_layout_statusbar();


  /**
   * Constant: layout-statusdrawer
   * {layout}
   */
  public class Const_layout_statusdrawer : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_statusdrawer output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-statusdrawer")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_statusdrawer c_layout_statusdrawer = new Const_layout_statusdrawer();


  /**
   * Constant: layout-text
   * {layout}
   */
  public class Const_layout_text : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_text output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-text")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_text c_layout_text = new Const_layout_text();


  /**
   * Constant: layout-textentry
   * {layout}
   */
  public class Const_layout_textentry : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_textentry output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-textentry")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_textentry c_layout_textentry = new Const_layout_textentry();


  /**
   * Constant: layout-titlebar
   * {layout}
   */
  public class Const_layout_titlebar : Vx.Ui.Ui.Class_layout, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_layout_titlebar output) {
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layout,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("layout-titlebar")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static Const_layout_titlebar c_layout_titlebar = new Const_layout_titlebar();


  /**
   * Constant: pin-bottom
   * {pin}
   */
  public class Const_pin_bottom : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_bottom output) {
    }


  }

  public static Const_pin_bottom c_pin_bottom = new Const_pin_bottom();


  /**
   * Constant: pin-center
   * {pin}
   */
  public class Const_pin_center : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center output) {
    }


  }

  public static Const_pin_center c_pin_center = new Const_pin_center();


  /**
   * Constant: pin-center-h
   * {pin}
   */
  public class Const_pin_center_h : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center_h output) {
    }


  }

  public static Const_pin_center_h c_pin_center_h = new Const_pin_center_h();


  /**
   * Constant: pin-center-v
   * {pin}
   */
  public class Const_pin_center_v : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_center_v output) {
    }


  }

  public static Const_pin_center_v c_pin_center_v = new Const_pin_center_v();


  /**
   * Constant: pin-expand
   * {pin}
   */
  public class Const_pin_expand : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_expand output) {
    }


  }

  public static Const_pin_expand c_pin_expand = new Const_pin_expand();


  /**
   * Constant: pin-left
   * {pin}
   */
  public class Const_pin_left : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_left output) {
    }


  }

  public static Const_pin_left c_pin_left = new Const_pin_left();


  /**
   * Constant: pin-right
   * {pin}
   */
  public class Const_pin_right : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_right output) {
    }


  }

  public static Const_pin_right c_pin_right = new Const_pin_right();


  /**
   * Constant: pin-top
   * {pin}
   */
  public class Const_pin_top : Vx.Ui.Ui.Class_pin, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pin_top output) {
    }


  }

  public static Const_pin_top c_pin_top = new Const_pin_top();


  /**
   * Constant: point-center
   * {point}
   */
  public class Const_point_center : Vx.Ui.Ui.Class_point, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_point_center output) {
    }


  }

  public static Const_point_center c_point_center = new Const_point_center();


  /**
   * Constant: point-lefttop
   * {point}
   */
  public class Const_point_lefttop : Vx.Ui.Ui.Class_point, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_point_lefttop output) {
    }


  }

  public static Const_point_lefttop c_point_lefttop = new Const_point_lefttop();


  /**
   * Constant: point-rightbottom
   * {point}
   */
  public class Const_point_rightbottom : Vx.Ui.Ui.Class_point, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_point_rightbottom output) {
    }


  }

  public static Const_point_rightbottom c_point_rightbottom = new Const_point_rightbottom();


  /**
   * Constant: pointtype-absolute
   * {pointtype}
   */
  public class Const_pointtype_absolute : Vx.Ui.Ui.Class_pointtype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pointtype_absolute output) {
    }


  }

  public static Const_pointtype_absolute c_pointtype_absolute = new Const_pointtype_absolute();


  /**
   * Constant: pointtype-percent
   * {pointtype}
   */
  public class Const_pointtype_percent : Vx.Ui.Ui.Class_pointtype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pointtype_percent output) {
    }


  }

  public static Const_pointtype_percent c_pointtype_percent = new Const_pointtype_percent();


  /**
   * Constant: pointtype-relative
   * {pointtype}
   */
  public class Const_pointtype_relative : Vx.Ui.Ui.Class_pointtype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_pointtype_relative output) {
    }


  }

  public static Const_pointtype_relative c_pointtype_relative = new Const_pointtype_relative();


  /**
   * Constant: styletype-custom
   * {styletype}
   */
  public class Const_styletype_custom : Vx.Ui.Ui.Class_styletype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_custom output) {
    }


  }

  public static Const_styletype_custom c_styletype_custom = new Const_styletype_custom();


  /**
   * Constant: styletype-shared
   * {styletype}
   */
  public class Const_styletype_shared : Vx.Ui.Ui.Class_styletype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_shared output) {
    }


  }

  public static Const_styletype_shared c_styletype_shared = new Const_styletype_shared();


  /**
   * Constant: styletype-system
   * {styletype}
   */
  public class Const_styletype_system : Vx.Ui.Ui.Class_styletype, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
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
    }

    public static void const_new(Const_styletype_system output) {
    }


  }

  public static Const_styletype_system c_styletype_system = new Const_styletype_system();

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

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_selected vx_new(params Object[] vals) {
      Class_boolean_layout_from_ui_parent_selected output = new Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_selected vx_copy(params Object[] vals) {
      Class_boolean_layout_from_ui_parent_selected output = new Class_boolean_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layout_from_ui_parent_selected;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layout_from_ui_parent_selected;
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

  public static Func_boolean_layout_from_ui_parent_selected e_boolean_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();
  public static Func_boolean_layout_from_ui_parent_selected t_boolean_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_selected();

  public static Vx.Core.Type_boolean f_boolean_layout_from_ui_parent_selected(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean selected) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Type_ui uiselected = Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":selected"),
              selected
          )
        );
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uiselected, parent);
        Vx.Ui.Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        return Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutselected, uiselected);
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

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_visible vx_new(params Object[] vals) {
      Class_boolean_layout_from_ui_parent_visible output = new Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layout_from_ui_parent_visible vx_copy(params Object[] vals) {
      Class_boolean_layout_from_ui_parent_visible output = new Class_boolean_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layout_from_ui_parent_visible;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layout_from_ui_parent_visible;
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

  public static Func_boolean_layout_from_ui_parent_visible e_boolean_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();
  public static Func_boolean_layout_from_ui_parent_visible t_boolean_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_boolean_layout_from_ui_parent_visible();

  public static Vx.Core.Type_boolean f_boolean_layout_from_ui_parent_visible(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_boolean visible) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Type_ui uivisible = Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":hidden"),
              Vx.Core.f_not(visible)
          )
        );
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uivisible, parent);
        Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui fn_layoutvisible = layoutengine.boolean_layoutvisible();
        return Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutvisible, uivisible);
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

    public override Vx.Ui.Ui.Func_boolean_layoutaddchild_from_ui_parent vx_new(params Object[] vals) {
      Class_boolean_layoutaddchild_from_ui_parent output = new Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutaddchild_from_ui_parent vx_copy(params Object[] vals) {
      Class_boolean_layoutaddchild_from_ui_parent output = new Class_boolean_layoutaddchild_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutaddchild_from_ui_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutaddchild_from_ui_parent;
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

  public static Func_boolean_layoutaddchild_from_ui_parent e_boolean_layoutaddchild_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();
  public static Func_boolean_layoutaddchild_from_ui_parent t_boolean_layoutaddchild_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutaddchild_from_ui_parent();

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
        return iswrite;
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

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_new(params Object[] vals) {
      Class_boolean_layoutremove_from_ui output = new Class_boolean_layoutremove_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui vx_copy(params Object[] vals) {
      Class_boolean_layoutremove_from_ui output = new Class_boolean_layoutremove_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutremove_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutremove_from_ui;
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

  public static Func_boolean_layoutremove_from_ui e_boolean_layoutremove_from_ui = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();
  public static Func_boolean_layoutremove_from_ui t_boolean_layoutremove_from_ui = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui();

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

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_keys vx_new(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_keys output = new Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_keys vx_copy(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_keys output = new Class_boolean_layoutremove_from_ui_keys();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutremove_from_ui_keys;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutremove_from_ui_keys;
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

  public static Func_boolean_layoutremove_from_ui_keys e_boolean_layoutremove_from_ui_keys = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();
  public static Func_boolean_layoutremove_from_ui_keys t_boolean_layoutremove_from_ui_keys = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_keys();

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
            return 
              Vx.Core.f_let(
                Vx.Core.t_boolean,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  Vx.Ui.Ui.Type_ui childui = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, uimap, key);
                  return Vx.Ui.Ui.f_boolean_layoutremove_from_ui_parent(context, childui, ui);
                })
              );
          })
        );
        return Vx.Core.f_and_1(writelist);
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

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_parent vx_new(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_parent output = new Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_parent vx_copy(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_parent output = new Class_boolean_layoutremove_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutremove_from_ui_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutremove_from_ui_parent;
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

  public static Func_boolean_layoutremove_from_ui_parent e_boolean_layoutremove_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();
  public static Func_boolean_layoutremove_from_ui_parent t_boolean_layoutremove_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Core.Type_string uid = ui.uid();
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_writeremove_from_ui_uid(parent, uid);
        Vx.Ui.Ui.Func_boolean_layoutremove_from_ui fn_layoutremove = layoutengine.boolean_layoutremove();
        return Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutremove, ui);
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

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_start_end vx_new(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_start_end output = new Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutremove_from_ui_start_end vx_copy(params Object[] vals) {
      Class_boolean_layoutremove_from_ui_start_end output = new Class_boolean_layoutremove_from_ui_start_end();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutremove_from_ui_start_end;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutremove_from_ui_start_end;
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

  public static Func_boolean_layoutremove_from_ui_start_end e_boolean_layoutremove_from_ui_start_end = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();
  public static Func_boolean_layoutremove_from_ui_start_end t_boolean_layoutremove_from_ui_start_end = new Vx.Ui.Ui.Class_boolean_layoutremove_from_ui_start_end();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_from_ui_start_end(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int start, Vx.Core.Type_int end) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_stringlist keys = Vx.Core.f_stringlist_from_map(uimap);
        Vx.Core.Type_stringlist subkeys = Vx.Collection.f_list_from_list_start_end(Vx.Core.t_stringlist, keys, start, end);
        return Vx.Ui.Ui.f_boolean_layoutremove_from_ui_keys(context, ui, subkeys);
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

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_new(params Object[] vals) {
      Class_boolean_layoutselected_from_ui output = new Class_boolean_layoutselected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui vx_copy(params Object[] vals) {
      Class_boolean_layoutselected_from_ui output = new Class_boolean_layoutselected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutselected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutselected_from_ui;
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

  public static Func_boolean_layoutselected_from_ui e_boolean_layoutselected_from_ui = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();
  public static Func_boolean_layoutselected_from_ui t_boolean_layoutselected_from_ui = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui();

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

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_parent vx_new(params Object[] vals) {
      Class_boolean_layoutselected_from_ui_parent output = new Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_parent vx_copy(params Object[] vals) {
      Class_boolean_layoutselected_from_ui_parent output = new Class_boolean_layoutselected_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutselected_from_ui_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutselected_from_ui_parent;
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

  public static Func_boolean_layoutselected_from_ui_parent e_boolean_layoutselected_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();
  public static Func_boolean_layoutselected_from_ui_parent t_boolean_layoutselected_from_ui_parent = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_layoutselected_from_ui_parent(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(ui, parent);
        Vx.Ui.Ui.Func_boolean_layoutselected_from_ui fn_layoutselected = layoutengine.boolean_layoutselected();
        return Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_layoutselected, ui);
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

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_selected vx_new(params Object[] vals) {
      Class_boolean_layoutselected_from_ui_selected output = new Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutselected_from_ui_selected vx_copy(params Object[] vals) {
      Class_boolean_layoutselected_from_ui_selected output = new Class_boolean_layoutselected_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutselected_from_ui_selected;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutselected_from_ui_selected;
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

  public static Func_boolean_layoutselected_from_ui_selected e_boolean_layoutselected_from_ui_selected = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();
  public static Func_boolean_layoutselected_from_ui_selected t_boolean_layoutselected_from_ui_selected = new Vx.Ui.Ui.Class_boolean_layoutselected_from_ui_selected();

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

    public override Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_new(params Object[] vals) {
      Class_boolean_layoutvisible_from_ui output = new Class_boolean_layoutvisible_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_layoutvisible_from_ui vx_copy(params Object[] vals) {
      Class_boolean_layoutvisible_from_ui output = new Class_boolean_layoutvisible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutvisible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutvisible_from_ui;
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

  public static Func_boolean_layoutvisible_from_ui e_boolean_layoutvisible_from_ui = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();
  public static Func_boolean_layoutvisible_from_ui t_boolean_layoutvisible_from_ui = new Vx.Ui.Ui.Class_boolean_layoutvisible_from_ui();

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

    public override Vx.Ui.Ui.Func_boolean_print vx_new(params Object[] vals) {
      Class_boolean_print output = new Class_boolean_print();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_print vx_copy(params Object[] vals) {
      Class_boolean_print output = new Class_boolean_print();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_print;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_print;
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

  public static Func_boolean_print e_boolean_print = new Vx.Ui.Ui.Class_boolean_print();
  public static Func_boolean_print t_boolean_print = new Vx.Ui.Ui.Class_boolean_print();

  public static Vx.Core.Type_boolean f_boolean_print(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        Vx.Ui.Ui.Func_boolean_print fn_print = layoutengine.boolean_print();
        return Vx.Core.vx_any_from_func(Vx.Core.t_boolean, fn_print, context, ui);
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

    public override Vx.Ui.Ui.Func_boolean_removestate_uiapp vx_new(params Object[] vals) {
      Class_boolean_removestate_uiapp output = new Class_boolean_removestate_uiapp();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_removestate_uiapp vx_copy(params Object[] vals) {
      Class_boolean_removestate_uiapp output = new Class_boolean_removestate_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_removestate_uiapp;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_removestate_uiapp;
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

  public static Func_boolean_removestate_uiapp e_boolean_removestate_uiapp = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();
  public static Func_boolean_removestate_uiapp t_boolean_removestate_uiapp = new Vx.Ui.Ui.Class_boolean_removestate_uiapp();

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

    public override Vx.Ui.Ui.Func_boolean_write_from_ui_parent vx_new(params Object[] vals) {
      Class_boolean_write_from_ui_parent output = new Class_boolean_write_from_ui_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_write_from_ui_parent vx_copy(params Object[] vals) {
      Class_boolean_write_from_ui_parent output = new Class_boolean_write_from_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_write_from_ui_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_write_from_ui_parent;
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

  public static Func_boolean_write_from_ui_parent e_boolean_write_from_ui_parent = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();
  public static Func_boolean_write_from_ui_parent t_boolean_write_from_ui_parent = new Vx.Ui.Ui.Class_boolean_write_from_ui_parent();

  public static Vx.Core.Type_boolean f_boolean_write_from_ui_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_uimap uimap = parent.uimap();
        return Vx.Core.f_boolean_write_from_map_name_value(uimap, uid, ui);
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

    public override Vx.Ui.Ui.Func_boolean_writeremove_from_ui_uid vx_new(params Object[] vals) {
      Class_boolean_writeremove_from_ui_uid output = new Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_writeremove_from_ui_uid vx_copy(params Object[] vals) {
      Class_boolean_writeremove_from_ui_uid output = new Class_boolean_writeremove_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writeremove_from_ui_uid;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writeremove_from_ui_uid;
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

  public static Func_boolean_writeremove_from_ui_uid e_boolean_writeremove_from_ui_uid = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();
  public static Func_boolean_writeremove_from_ui_uid t_boolean_writeremove_from_ui_uid = new Vx.Ui.Ui.Class_boolean_writeremove_from_ui_uid();

  public static Vx.Core.Type_boolean f_boolean_writeremove_from_ui_uid(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string uid) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        return Vx.Core.f_boolean_write_from_map_name_value(
          uimap,
          uid,
          Vx.Core.f_empty(
            Vx.Ui.Ui.t_ui
          )
        );
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

    public override Vx.Ui.Ui.Func_boolean_writestate_from_ui vx_new(params Object[] vals) {
      Class_boolean_writestate_from_ui output = new Class_boolean_writestate_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_writestate_from_ui vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_ui output = new Class_boolean_writestate_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_ui;
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

  public static Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();
  public static Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = new Vx.Ui.Ui.Class_boolean_writestate_from_ui();

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
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
        return isfound;
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

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiapp vx_new(params Object[] vals) {
      Class_boolean_writestate_from_uiapp output = new Class_boolean_writestate_from_uiapp();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiapp vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_uiapp output = new Class_boolean_writestate_from_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_uiapp;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_uiapp;
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

  public static Func_boolean_writestate_from_uiapp e_boolean_writestate_from_uiapp = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();
  public static Func_boolean_writestate_from_uiapp t_boolean_writestate_from_uiapp = new Vx.Ui.Ui.Class_boolean_writestate_from_uiapp();

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

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiengine vx_new(params Object[] vals) {
      Class_boolean_writestate_from_uiengine output = new Class_boolean_writestate_from_uiengine();
      return output;
    }

    public override Vx.Ui.Ui.Func_boolean_writestate_from_uiengine vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_uiengine output = new Class_boolean_writestate_from_uiengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_uiengine;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_uiengine;
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

  public static Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();
  public static Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = new Vx.Ui.Ui.Class_boolean_writestate_from_uiengine();

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

    public override Vx.Ui.Ui.Func_fontfacemap_from_fontfacelist vx_new(params Object[] vals) {
      Class_fontfacemap_from_fontfacelist output = new Class_fontfacemap_from_fontfacelist();
      return output;
    }

    public override Vx.Ui.Ui.Func_fontfacemap_from_fontfacelist vx_copy(params Object[] vals) {
      Class_fontfacemap_from_fontfacelist output = new Class_fontfacemap_from_fontfacelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fontfacemap_from_fontfacelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_fontfacemap_from_fontfacelist;
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

  public static Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();
  public static Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist = new Vx.Ui.Ui.Class_fontfacemap_from_fontfacelist();

  public static Vx.Ui.Ui.Type_fontfacemap f_fontfacemap_from_fontfacelist(Vx.Ui.Ui.Type_fontfacelist fontfacelist) {
    Vx.Ui.Ui.Type_fontfacemap output = Vx.Ui.Ui.e_fontfacemap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_fontfacemap,
      fontfacelist,
      Vx.Core.t_any_from_any.vx_fn_new((fontface_any) => {
        Vx.Ui.Ui.Type_fontface fontface = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontface, fontface_any);
        return 
        fontface.name();
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

    public override Vx.Ui.Ui.Func_int_child_from_ui_uid vx_new(params Object[] vals) {
      Class_int_child_from_ui_uid output = new Class_int_child_from_ui_uid();
      return output;
    }

    public override Vx.Ui.Ui.Func_int_child_from_ui_uid vx_copy(params Object[] vals) {
      Class_int_child_from_ui_uid output = new Class_int_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_int_child_from_ui_uid;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_child_from_ui_uid;
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

  public static Func_int_child_from_ui_uid e_int_child_from_ui_uid = new Vx.Ui.Ui.Class_int_child_from_ui_uid();
  public static Func_int_child_from_ui_uid t_int_child_from_ui_uid = new Vx.Ui.Ui.Class_int_child_from_ui_uid();

  public static Vx.Core.Type_int f_int_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        return Vx.Collection.f_int_from_map_key(uimap, uid);
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

    public override Vx.Ui.Ui.Func_int_selected_from_ui vx_new(params Object[] vals) {
      Class_int_selected_from_ui output = new Class_int_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_int_selected_from_ui vx_copy(params Object[] vals) {
      Class_int_selected_from_ui output = new Class_int_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_int_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_selected_from_ui;
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

  public static Func_int_selected_from_ui e_int_selected_from_ui = new Vx.Ui.Ui.Class_int_selected_from_ui();
  public static Func_int_selected_from_ui t_int_selected_from_ui = new Vx.Ui.Ui.Class_int_selected_from_ui();

  public static Vx.Core.Type_int f_int_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = Vx.Ui.Ui.f_string_selected_from_ui(ui);
        Vx.Core.Type_stringlist uidlist = Vx.Ui.Ui.f_stringlist_from_ui(ui);
        return Vx.Collection.f_int_from_stringlist_find(uidlist, uid);
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

    public override Vx.Ui.Ui.Func_int_visible_from_ui vx_new(params Object[] vals) {
      Class_int_visible_from_ui output = new Class_int_visible_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_int_visible_from_ui vx_copy(params Object[] vals) {
      Class_int_visible_from_ui output = new Class_int_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_int_visible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_int_visible_from_ui;
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

  public static Func_int_visible_from_ui e_int_visible_from_ui = new Vx.Ui.Ui.Class_int_visible_from_ui();
  public static Func_int_visible_from_ui t_int_visible_from_ui = new Vx.Ui.Ui.Class_int_visible_from_ui();

  public static Vx.Core.Type_int f_int_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_let(
      Vx.Core.t_int,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_intlist intlist = Vx.Ui.Ui.f_intlist_visible_from_ui(ui);
        return Vx.Core.f_first_from_list(Vx.Core.t_int, intlist);
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

    public override Vx.Ui.Ui.Func_intlist_visible_from_ui vx_new(params Object[] vals) {
      Class_intlist_visible_from_ui output = new Class_intlist_visible_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_intlist_visible_from_ui vx_copy(params Object[] vals) {
      Class_intlist_visible_from_ui output = new Class_intlist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_intlist_visible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_intlist_visible_from_ui;
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

  public static Func_intlist_visible_from_ui e_intlist_visible_from_ui = new Vx.Ui.Ui.Class_intlist_visible_from_ui();
  public static Func_intlist_visible_from_ui t_intlist_visible_from_ui = new Vx.Ui.Ui.Class_intlist_visible_from_ui();

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
            return 
              Vx.Core.f_if_2(
                Vx.Core.t_int,
                Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
          })
        );
        return Vx.Collection.f_list_from_list_filter(
          Vx.Core.t_intlist,
          intlist,
          Vx.Core.t_any_from_any.vx_fn_new((pos_any) => {
            Vx.Core.Type_int pos = Vx.Core.f_any_from_any(Vx.Core.t_int, pos_any);
            return pos;
          })
        );
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

    public override Vx.Ui.Ui.Func_layout_from_style vx_new(params Object[] vals) {
      Class_layout_from_style output = new Class_layout_from_style();
      return output;
    }

    public override Vx.Ui.Ui.Func_layout_from_style vx_copy(params Object[] vals) {
      Class_layout_from_style output = new Class_layout_from_style();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layout_from_style;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layout_from_style;
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

  public static Func_layout_from_style e_layout_from_style = new Vx.Ui.Ui.Class_layout_from_style();
  public static Func_layout_from_style t_layout_from_style = new Vx.Ui.Ui.Class_layout_from_style();

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

    public override Vx.Ui.Ui.Func_layout_from_ui vx_new(params Object[] vals) {
      Class_layout_from_ui output = new Class_layout_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_layout_from_ui vx_copy(params Object[] vals) {
      Class_layout_from_ui output = new Class_layout_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layout_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layout_from_ui;
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

  public static Func_layout_from_ui e_layout_from_ui = new Vx.Ui.Ui.Class_layout_from_ui();
  public static Func_layout_from_ui t_layout_from_ui = new Vx.Ui.Ui.Class_layout_from_ui();

  public static Vx.Ui.Ui.Type_layout f_layout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layout,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = Vx.Ui.Ui.f_layoutengine_readstate(context);
        return Vx.Ui.Ui.f_layout_from_ui_layoutengine(ui, layoutengine);
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

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutengine vx_new(params Object[] vals) {
      Class_layout_from_ui_layoutengine output = new Class_layout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutengine vx_copy(params Object[] vals) {
      Class_layout_from_ui_layoutengine output = new Class_layout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layout_from_ui_layoutengine;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layout_from_ui_layoutengine;
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

  public static Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();
  public static Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine = new Vx.Ui.Ui.Class_layout_from_ui_layoutengine();

  public static Vx.Ui.Ui.Type_layout f_layout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
    Vx.Ui.Ui.Type_layout output = Vx.Ui.Ui.e_layout;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layout,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Vx.Ui.Ui.Type_layout layoutelse = layoutengine.layoutelse();
        return Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutmap_else vx_new(params Object[] vals) {
      Class_layout_from_ui_layoutmap_else output = new Class_layout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Ui.Ui.Func_layout_from_ui_layoutmap_else vx_copy(params Object[] vals) {
      Class_layout_from_ui_layoutmap_else output = new Class_layout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layout_from_ui_layoutmap_else;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layout_from_ui_layoutmap_else;
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

  public static Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();
  public static Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_layout_from_ui_layoutmap_else();

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
  public interface Func_layoutengine_readstate : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_layoutengine vx_layoutengine_readstate(Vx.Core.Type_context context);
  }

  public class Class_layoutengine_readstate : Vx.Core.Class_base, Func_layoutengine_readstate {

    public override Vx.Ui.Ui.Func_layoutengine_readstate vx_new(params Object[] vals) {
      Class_layoutengine_readstate output = new Class_layoutengine_readstate();
      return output;
    }

    public override Vx.Ui.Ui.Func_layoutengine_readstate vx_copy(params Object[] vals) {
      Class_layoutengine_readstate output = new Class_layoutengine_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layoutengine_readstate;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layoutengine_readstate;
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

  public static Func_layoutengine_readstate e_layoutengine_readstate = new Vx.Ui.Ui.Class_layoutengine_readstate();
  public static Func_layoutengine_readstate t_layoutengine_readstate = new Vx.Ui.Ui.Class_layoutengine_readstate();

  public static Vx.Ui.Ui.Type_layoutengine f_layoutengine_readstate(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_layoutengine output = Vx.Ui.Ui.e_layoutengine;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_layoutengine,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
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
  public interface Func_layoutmap_from_layoutlist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_layoutmap vx_layoutmap_from_layoutlist(Vx.Ui.Ui.Type_layoutlist layoutlist);
  }

  public class Class_layoutmap_from_layoutlist : Vx.Core.Class_base, Func_layoutmap_from_layoutlist {

    public override Vx.Ui.Ui.Func_layoutmap_from_layoutlist vx_new(params Object[] vals) {
      Class_layoutmap_from_layoutlist output = new Class_layoutmap_from_layoutlist();
      return output;
    }

    public override Vx.Ui.Ui.Func_layoutmap_from_layoutlist vx_copy(params Object[] vals) {
      Class_layoutmap_from_layoutlist output = new Class_layoutmap_from_layoutlist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_layoutmap_from_layoutlist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_layoutmap_from_layoutlist;
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

  public static Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();
  public static Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = new Vx.Ui.Ui.Class_layoutmap_from_layoutlist();

  public static Vx.Ui.Ui.Type_layoutmap f_layoutmap_from_layoutlist(Vx.Ui.Ui.Type_layoutlist layoutlist) {
    Vx.Ui.Ui.Type_layoutmap output = Vx.Ui.Ui.e_layoutmap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_layoutmap,
      layoutlist,
      Vx.Core.t_any_from_any.vx_fn_new((layout_any) => {
        Vx.Ui.Ui.Type_layout layout = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_layout, layout_any);
        return 
        layout.name();
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

    public override Vx.Ui.Ui.Func_string_parentuid_from_uid vx_new(params Object[] vals) {
      Class_string_parentuid_from_uid output = new Class_string_parentuid_from_uid();
      return output;
    }

    public override Vx.Ui.Ui.Func_string_parentuid_from_uid vx_copy(params Object[] vals) {
      Class_string_parentuid_from_uid output = new Class_string_parentuid_from_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_parentuid_from_uid;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_parentuid_from_uid;
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

  public static Func_string_parentuid_from_uid e_string_parentuid_from_uid = new Vx.Ui.Ui.Class_string_parentuid_from_uid();
  public static Func_string_parentuid_from_uid t_string_parentuid_from_uid = new Vx.Ui.Ui.Class_string_parentuid_from_uid();

  public static Vx.Core.Type_string f_string_parentuid_from_uid(Vx.Core.Type_string uid) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int lastpos = Vx.Type.f_int_from_string_findlast(uid, Vx.Core.vx_new_string("/"));
        return Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
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

    public override Vx.Ui.Ui.Func_string_selected_from_ui vx_new(params Object[] vals) {
      Class_string_selected_from_ui output = new Class_string_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_string_selected_from_ui vx_copy(params Object[] vals) {
      Class_string_selected_from_ui output = new Class_string_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_selected_from_ui;
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

  public static Func_string_selected_from_ui e_string_selected_from_ui = new Vx.Ui.Ui.Class_string_selected_from_ui();
  public static Func_string_selected_from_ui t_string_selected_from_ui = new Vx.Ui.Ui.Class_string_selected_from_ui();

  public static Vx.Core.Type_string f_string_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui selectedui = Vx.Ui.Ui.f_ui_selected_from_ui(ui);
        return selectedui.uid();
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

    public override Vx.Ui.Ui.Func_stringlist_selected_from_ui vx_new(params Object[] vals) {
      Class_stringlist_selected_from_ui output = new Class_stringlist_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_stringlist_selected_from_ui vx_copy(params Object[] vals) {
      Class_stringlist_selected_from_ui output = new Class_stringlist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringlist_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringlist_selected_from_ui;
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

  public static Func_stringlist_selected_from_ui e_stringlist_selected_from_ui = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();
  public static Func_stringlist_selected_from_ui t_stringlist_selected_from_ui = new Vx.Ui.Ui.Class_stringlist_selected_from_ui();

  public static Vx.Core.Type_stringlist f_stringlist_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_let(
      Vx.Core.t_stringlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        return Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            return 
            Vx.Core.f_if_1(
              Vx.Core.t_string,
              item.selected(),
              item.uid(),
              Vx.Core.vx_new_string("")
            );
          })
        );
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

    public override Vx.Ui.Ui.Func_stringlist_from_ui vx_new(params Object[] vals) {
      Class_stringlist_from_ui output = new Class_stringlist_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_stringlist_from_ui vx_copy(params Object[] vals) {
      Class_stringlist_from_ui output = new Class_stringlist_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringlist_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringlist_from_ui;
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

  public static Func_stringlist_from_ui e_stringlist_from_ui = new Vx.Ui.Ui.Class_stringlist_from_ui();
  public static Func_stringlist_from_ui t_stringlist_from_ui = new Vx.Ui.Ui.Class_stringlist_from_ui();

  public static Vx.Core.Type_stringlist f_stringlist_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_let(
      Vx.Core.t_stringlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        return Vx.Core.f_stringlist_from_map(uimap);
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

    public override Vx.Ui.Ui.Func_stylemap_from_stylelist vx_new(params Object[] vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Ui.Ui.Func_stylemap_from_stylelist vx_copy(params Object[] vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylemap_from_stylelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylemap_from_stylelist;
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

  public static Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Vx.Ui.Ui.Class_stylemap_from_stylelist();
  public static Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Vx.Ui.Ui.Class_stylemap_from_stylelist();

  public static Vx.Ui.Ui.Type_stylemap f_stylemap_from_stylelist(Vx.Ui.Ui.Type_stylelist stylelist) {
    Vx.Ui.Ui.Type_stylemap output = Vx.Ui.Ui.e_stylemap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_stylemap,
      stylelist,
      Vx.Core.t_any_from_any.vx_fn_new((style_any) => {
        Vx.Ui.Ui.Type_style style = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, style_any);
        return 
        style.name();
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

    public override Vx.Ui.Ui.Func_stylesheet_readstate vx_new(params Object[] vals) {
      Class_stylesheet_readstate output = new Class_stylesheet_readstate();
      return output;
    }

    public override Vx.Ui.Ui.Func_stylesheet_readstate vx_copy(params Object[] vals) {
      Class_stylesheet_readstate output = new Class_stylesheet_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylesheet_readstate;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet_readstate;
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

  public static Func_stylesheet_readstate e_stylesheet_readstate = new Vx.Ui.Ui.Class_stylesheet_readstate();
  public static Func_stylesheet_readstate t_stylesheet_readstate = new Vx.Ui.Ui.Class_stylesheet_readstate();

  public static Vx.Ui.Ui.Type_stylesheet f_stylesheet_readstate(Vx.Core.Type_context context) {
    Vx.Ui.Ui.Type_stylesheet output = Vx.Ui.Ui.e_stylesheet;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_stylesheet,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
        return uiengine.stylesheet();
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

    public override Vx.Ui.Ui.Func_stylesheet_render vx_new(params Object[] vals) {
      Class_stylesheet_render output = new Class_stylesheet_render();
      return output;
    }

    public override Vx.Ui.Ui.Func_stylesheet_render vx_copy(params Object[] vals) {
      Class_stylesheet_render output = new Class_stylesheet_render();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylesheet_render;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet_render;
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

  public static Func_stylesheet_render e_stylesheet_render = new Vx.Ui.Ui.Class_stylesheet_render();
  public static Func_stylesheet_render t_stylesheet_render = new Vx.Ui.Ui.Class_stylesheet_render();

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

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui vx_new(params Object[] vals) {
      Class_ui_addlayout_from_ui output = new Class_ui_addlayout_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui vx_copy(params Object[] vals) {
      Class_ui_addlayout_from_ui output = new Class_ui_addlayout_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_addlayout_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_addlayout_from_ui;
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

  public static Func_ui_addlayout_from_ui e_ui_addlayout_from_ui = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();
  public static Func_ui_addlayout_from_ui t_ui_addlayout_from_ui = new Vx.Ui.Ui.Class_ui_addlayout_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uiengine uiengine = Vx.Ui.Ui.f_uiengine_readstate(context);
        return Vx.Ui.Ui.f_ui_addlayout_from_ui_uiengine(ui, uiengine);
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

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutengine vx_new(params Object[] vals) {
      Class_ui_addlayout_from_ui_layoutengine output = new Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutengine vx_copy(params Object[] vals) {
      Class_ui_addlayout_from_ui_layoutengine output = new Class_ui_addlayout_from_ui_layoutengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_addlayout_from_ui_layoutengine;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_addlayout_from_ui_layoutengine;
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

  public static Func_ui_addlayout_from_ui_layoutengine e_ui_addlayout_from_ui_layoutengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();
  public static Func_ui_addlayout_from_ui_layoutengine t_ui_addlayout_from_ui_layoutengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutengine();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_layoutengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutengine layoutengine) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutmap layoutmap = layoutengine.layoutmap();
        Vx.Ui.Ui.Type_layout layoutelse = layoutengine.layoutelse();
        return Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutmap_else vx_new(params Object[] vals) {
      Class_ui_addlayout_from_ui_layoutmap_else output = new Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_layoutmap_else vx_copy(params Object[] vals) {
      Class_ui_addlayout_from_ui_layoutmap_else output = new Class_ui_addlayout_from_ui_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_addlayout_from_ui_layoutmap_else;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_addlayout_from_ui_layoutmap_else;
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

  public static Func_ui_addlayout_from_ui_layoutmap_else e_ui_addlayout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();
  public static Func_ui_addlayout_from_ui_layoutmap_else t_ui_addlayout_from_ui_layoutmap_else = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_layoutmap_else();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_layoutmap_else(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_layout layout1 = Vx.Ui.Ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        Vx.Ui.Ui.Type_uimap uimap2 = Vx.Ui.Ui.f_uimap_addlayout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
        return Vx.Core.f_copy(
          ui,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":layout"),
            layout1,
            Vx.Core.vx_new_string(":uimap"),
            uimap2
          )
        );
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

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_uiengine vx_new(params Object[] vals) {
      Class_ui_addlayout_from_ui_uiengine output = new Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_addlayout_from_ui_uiengine vx_copy(params Object[] vals) {
      Class_ui_addlayout_from_ui_uiengine output = new Class_ui_addlayout_from_ui_uiengine();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_addlayout_from_ui_uiengine;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_addlayout_from_ui_uiengine;
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

  public static Func_ui_addlayout_from_ui_uiengine e_ui_addlayout_from_ui_uiengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();
  public static Func_ui_addlayout_from_ui_uiengine t_ui_addlayout_from_ui_uiengine = new Vx.Ui.Ui.Class_ui_addlayout_from_ui_uiengine();

  public static Vx.Ui.Ui.Type_ui f_ui_addlayout_from_ui_uiengine(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_uiengine uiengine) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_layoutengine layoutengine = uiengine.layoutengine();
        return Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutengine(ui, layoutengine);
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

    public override Vx.Ui.Ui.Func_ui_child_from_ui_pos vx_new(params Object[] vals) {
      Class_ui_child_from_ui_pos output = new Class_ui_child_from_ui_pos();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_child_from_ui_pos vx_copy(params Object[] vals) {
      Class_ui_child_from_ui_pos output = new Class_ui_child_from_ui_pos();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_child_from_ui_pos;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_child_from_ui_pos;
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

  public static Func_ui_child_from_ui_pos e_ui_child_from_ui_pos = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();
  public static Func_ui_child_from_ui_pos t_ui_child_from_ui_pos = new Vx.Ui.Ui.Class_ui_child_from_ui_pos();

  public static Vx.Ui.Ui.Type_ui f_ui_child_from_ui_pos(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int pos) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap childmap = ui.uimap();
        return Vx.Collection.f_any_from_map_pos(Vx.Ui.Ui.t_ui, childmap, pos);
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

    public override Vx.Ui.Ui.Func_ui_child_from_ui_uid vx_new(params Object[] vals) {
      Class_ui_child_from_ui_uid output = new Class_ui_child_from_ui_uid();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_child_from_ui_uid vx_copy(params Object[] vals) {
      Class_ui_child_from_ui_uid output = new Class_ui_child_from_ui_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_child_from_ui_uid;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_child_from_ui_uid;
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

  public static Func_ui_child_from_ui_uid e_ui_child_from_ui_uid = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();
  public static Func_ui_child_from_ui_uid t_ui_child_from_ui_uid = new Vx.Ui.Ui.Class_ui_child_from_ui_uid();

  public static Vx.Ui.Ui.Type_ui f_ui_child_from_ui_uid(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_string uid) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap childmap = ui.uimap();
        return Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, childmap, uid);
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

    public override Vx.Ui.Ui.Func_ui_from_from_event vx_new(params Object[] vals) {
      Class_ui_from_from_event output = new Class_ui_from_from_event();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_from_from_event vx_copy(params Object[] vals) {
      Class_ui_from_from_event output = new Class_ui_from_from_event();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_from_from_event;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_from_from_event;
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

  public static Func_ui_from_from_event e_ui_from_from_event = new Vx.Ui.Ui.Class_ui_from_from_event();
  public static Func_ui_from_from_event t_ui_from_from_event = new Vx.Ui.Ui.Class_ui_from_from_event();

  public static Vx.Ui.Ui.Type_ui f_ui_from_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = evt.from();
        return Vx.Ui.Ui.f_ui_readstate_from_uid(context, uid);
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

    public override Vx.Ui.Ui.Func_ui_layout vx_new(params Object[] vals) {
      Class_ui_layout output = new Class_ui_layout();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_layout vx_copy(params Object[] vals) {
      Class_ui_layout output = new Class_ui_layout();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout;
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

  public static Func_ui_layout e_ui_layout = new Vx.Ui.Ui.Class_ui_layout();
  public static Func_ui_layout t_ui_layout = new Vx.Ui.Ui.Class_ui_layout();

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

    public override Vx.Ui.Ui.Func_ui_layout_from_fn_layout_ui_orig_parent vx_new(params Object[] vals) {
      Class_ui_layout_from_fn_layout_ui_orig_parent output = new Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_layout_from_fn_layout_ui_orig_parent vx_copy(params Object[] vals) {
      Class_ui_layout_from_fn_layout_ui_orig_parent output = new Class_ui_layout_from_fn_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_from_fn_layout_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_from_fn_layout_ui_orig_parent;
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

  public static Func_ui_layout_from_fn_layout_ui_orig_parent e_ui_layout_from_fn_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();
  public static Func_ui_layout_from_fn_layout_ui_orig_parent t_ui_layout_from_fn_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_fn_layout_ui_orig_parent();

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

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_new(params Object[] vals) {
      Class_ui_layout_from_ui_orig_parent output = new Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent vx_copy(params Object[] vals) {
      Class_ui_layout_from_ui_orig_parent output = new Class_ui_layout_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_from_ui_orig_parent;
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

  public static Func_ui_layout_from_ui_orig_parent e_ui_layout_from_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();
  public static Func_ui_layout_from_ui_orig_parent t_ui_layout_from_ui_orig_parent = new Vx.Ui.Ui.Class_ui_layout_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
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

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_selected vx_new(params Object[] vals) {
      Class_ui_layout_from_ui_parent_selected output = new Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_selected vx_copy(params Object[] vals) {
      Class_ui_layout_from_ui_parent_selected output = new Class_ui_layout_from_ui_parent_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_from_ui_parent_selected;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_from_ui_parent_selected;
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

  public static Func_ui_layout_from_ui_parent_selected e_ui_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();
  public static Func_ui_layout_from_ui_parent_selected t_ui_layout_from_ui_parent_selected = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_selected();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_parent_selected(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int selected) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uichg1 = Vx.Ui.Ui.f_ui_from_ui_selected(ui, selected);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_write_from_ui_parent(uichg1, parent);
        return Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(uichg1, ui, parent);
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

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_visible vx_new(params Object[] vals) {
      Class_ui_layout_from_ui_parent_visible output = new Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_layout_from_ui_parent_visible vx_copy(params Object[] vals) {
      Class_ui_layout_from_ui_parent_visible output = new Class_ui_layout_from_ui_parent_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_from_ui_parent_visible;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_from_ui_parent_visible;
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

  public static Func_ui_layout_from_ui_parent_visible e_ui_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();
  public static Func_ui_layout_from_ui_parent_visible t_ui_layout_from_ui_parent_visible = new Vx.Ui.Ui.Class_ui_layout_from_ui_parent_visible();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_from_ui_parent_visible(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent, Vx.Core.Type_int visible) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uichg = Vx.Ui.Ui.f_ui_write_from_ui_visible(ui, visible);
        return Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(uichg, ui, parent);
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

    public override Vx.Ui.Ui.Func_ui_readstate_uiapp vx_new(params Object[] vals) {
      Class_ui_readstate_uiapp output = new Class_ui_readstate_uiapp();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_readstate_uiapp vx_copy(params Object[] vals) {
      Class_ui_readstate_uiapp output = new Class_ui_readstate_uiapp();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_readstate_uiapp;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_readstate_uiapp;
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

  public static Func_ui_readstate_uiapp e_ui_readstate_uiapp = new Vx.Ui.Ui.Class_ui_readstate_uiapp();
  public static Func_ui_readstate_uiapp t_ui_readstate_uiapp = new Vx.Ui.Ui.Class_ui_readstate_uiapp();

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

    public override Vx.Ui.Ui.Func_ui_readstate_from_uid vx_new(params Object[] vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_readstate_from_uid vx_copy(params Object[] vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_readstate_from_uid;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_readstate_from_uid;
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

  public static Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Vx.Ui.Ui.Class_ui_readstate_from_uid();
  public static Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Vx.Ui.Ui.Class_ui_readstate_from_uid();

  public static Vx.Ui.Ui.Type_ui f_ui_readstate_from_uid(Vx.Core.Type_context context, Vx.Core.Type_string uid) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_ui uiapp = Vx.Ui.Ui.f_ui_readstate_uiapp(context);
        return Vx.Ui.Ui.f_ui_from_ui_find(uiapp, uid);
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

    public override Vx.Ui.Ui.Func_ui_selected_from_ui vx_new(params Object[] vals) {
      Class_ui_selected_from_ui output = new Class_ui_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_selected_from_ui vx_copy(params Object[] vals) {
      Class_ui_selected_from_ui output = new Class_ui_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_selected_from_ui;
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

  public static Func_ui_selected_from_ui e_ui_selected_from_ui = new Vx.Ui.Ui.Class_ui_selected_from_ui();
  public static Func_ui_selected_from_ui t_ui_selected_from_ui = new Vx.Ui.Ui.Class_ui_selected_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_selected_from_ui(ui);
        return Vx.Core.f_first_from_list(Vx.Ui.Ui.t_ui, uilist);
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

    public override Vx.Ui.Ui.Func_ui_visible_from_ui vx_new(params Object[] vals) {
      Class_ui_visible_from_ui output = new Class_ui_visible_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_visible_from_ui vx_copy(params Object[] vals) {
      Class_ui_visible_from_ui output = new Class_ui_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_visible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_visible_from_ui;
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

  public static Func_ui_visible_from_ui e_ui_visible_from_ui = new Vx.Ui.Ui.Class_ui_visible_from_ui();
  public static Func_ui_visible_from_ui t_ui_visible_from_ui = new Vx.Ui.Ui.Class_ui_visible_from_ui();

  public static Vx.Ui.Ui.Type_ui f_ui_visible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_visible_from_ui(ui);
        return Vx.Core.f_first_from_list(Vx.Ui.Ui.t_ui, uilist);
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

    public override Vx.Ui.Ui.Func_ui_write_from_ui_child vx_new(params Object[] vals) {
      Class_ui_write_from_ui_child output = new Class_ui_write_from_ui_child();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_write_from_ui_child vx_copy(params Object[] vals) {
      Class_ui_write_from_ui_child output = new Class_ui_write_from_ui_child();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_write_from_ui_child;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_write_from_ui_child;
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

  public static Func_ui_write_from_ui_child e_ui_write_from_ui_child = new Vx.Ui.Ui.Class_ui_write_from_ui_child();
  public static Func_ui_write_from_ui_child t_ui_write_from_ui_child = new Vx.Ui.Ui.Class_ui_write_from_ui_child();

  public static Vx.Ui.Ui.Type_ui f_ui_write_from_ui_child(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui child) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string childid = child.uid();
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_boolean write = Vx.Core.f_boolean_write_from_map_name_value(uimap, childid, child);
        return ui;
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

    public override Vx.Ui.Ui.Func_ui_write_from_ui_childmap vx_new(params Object[] vals) {
      Class_ui_write_from_ui_childmap output = new Class_ui_write_from_ui_childmap();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_write_from_ui_childmap vx_copy(params Object[] vals) {
      Class_ui_write_from_ui_childmap output = new Class_ui_write_from_ui_childmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_write_from_ui_childmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_write_from_ui_childmap;
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

  public static Func_ui_write_from_ui_childmap e_ui_write_from_ui_childmap = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();
  public static Func_ui_write_from_ui_childmap t_ui_write_from_ui_childmap = new Vx.Ui.Ui.Class_ui_write_from_ui_childmap();

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
            return 
              Vx.Ui.Ui.f_ui_write_from_ui_child(ui, value);
          })
        );
        return ui;
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

    public override Vx.Ui.Ui.Func_ui_write_from_ui_visible vx_new(params Object[] vals) {
      Class_ui_write_from_ui_visible output = new Class_ui_write_from_ui_visible();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_write_from_ui_visible vx_copy(params Object[] vals) {
      Class_ui_write_from_ui_visible output = new Class_ui_write_from_ui_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_write_from_ui_visible;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_write_from_ui_visible;
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

  public static Func_ui_write_from_ui_visible e_ui_write_from_ui_visible = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();
  public static Func_ui_write_from_ui_visible t_ui_write_from_ui_visible = new Vx.Ui.Ui.Class_ui_write_from_ui_visible();

  public static Vx.Ui.Ui.Type_ui f_ui_write_from_ui_visible(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int visible) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
                    return 
                      Vx.Core.f_if_2(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(Vx.Core.t_thenelselist,
                          Vx.Core.f_then(
                            Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                              return Vx.Core.f_eq(posval, visible);
                            }),
                            Vx.Core.t_any_from_func.vx_fn_new(() => {
                              return Vx.Ui.Ui.f_ui_write_from_ui_child(
                                ui,
                                Vx.Core.f_copy(
                                  uival,
                                  Vx.Core.vx_new(Vx.Core.t_anylist,
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
                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":hidden"),
                                    Vx.Core.vx_new_boolean(true)
                                  )
                                )
                              );
                            })
                          )
                        )
                      );
                  })
                );
                return ui;
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

    public override Vx.Ui.Ui.Func_ui_from_layout_ui_orig_parent vx_new(params Object[] vals) {
      Class_ui_from_layout_ui_orig_parent output = new Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_from_layout_ui_orig_parent vx_copy(params Object[] vals) {
      Class_ui_from_layout_ui_orig_parent output = new Class_ui_from_layout_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_from_layout_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_from_layout_ui_orig_parent;
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

  public static Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();
  public static Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent = new Vx.Ui.Ui.Class_ui_from_layout_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_from_layout_ui_orig_parent(Vx.Ui.Ui.Type_layout layout, Vx.Ui.Ui.Type_ui uiarg, Vx.Ui.Ui.Type_ui uiorig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string name = layout.name();
        Vx.Ui.Ui.Func_ui_layout_from_ui_orig_parent fn_layout = layout.fn_layout();
        Vx.Ui.Ui.Type_ui uichg = Vx.Core.vx_any_from_func(Vx.Ui.Ui.t_ui, fn_layout, uiarg, uiorig, parent);
        return uichg;
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

    public override Vx.Ui.Ui.Func_ui_from_ui_find vx_new(params Object[] vals) {
      Class_ui_from_ui_find output = new Class_ui_from_ui_find();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_from_ui_find vx_copy(params Object[] vals) {
      Class_ui_from_ui_find output = new Class_ui_from_ui_find();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_from_ui_find;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_from_ui_find;
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

  public static Func_ui_from_ui_find e_ui_from_ui_find = new Vx.Ui.Ui.Class_ui_from_ui_find();
  public static Func_ui_from_ui_find t_ui_from_ui_find = new Vx.Ui.Ui.Class_ui_from_ui_find();

  public static Vx.Ui.Ui.Type_ui f_ui_from_ui_find(Vx.Ui.Ui.Type_ui uiarg, Vx.Core.Type_string find) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = uiarg.uid();
        return Vx.Core.f_if_2(
          Vx.Ui.Ui.t_ui,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
                    Vx.Core.vx_new(Vx.Core.t_anylist,
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
                      Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
                      Vx.Core.vx_new(Vx.Core.t_thenelselist,
                          Vx.Core.f_then(
                            Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                              return Vx.Core.f_notempty(subpart);
                            }),
                            Vx.Core.t_any_from_func.vx_fn_new(() => {
                              return Vx.Core.f_new(
                                Vx.Core.t_string,
                                Vx.Core.vx_new(Vx.Core.t_anylist,
                                    uid,
                                    Vx.Core.vx_new_string("/"),
                                    subpart
                                )
                              );
                            })
                          )
                      )
                    );
                    return Vx.Core.f_if_2(
                      Vx.Ui.Ui.t_ui,
                      Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
                                return Vx.Ui.Ui.f_ui_from_ui_find(subui, find);
                              })
                            );
                          })
                        )
                      )
                    );
                  })
                );
              })
            )
          )
        );
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

    public override Vx.Ui.Ui.Func_ui_from_ui_selected vx_new(params Object[] vals) {
      Class_ui_from_ui_selected output = new Class_ui_from_ui_selected();
      return output;
    }

    public override Vx.Ui.Ui.Func_ui_from_ui_selected vx_copy(params Object[] vals) {
      Class_ui_from_ui_selected output = new Class_ui_from_ui_selected();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_from_ui_selected;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_from_ui_selected;
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

  public static Func_ui_from_ui_selected e_ui_from_ui_selected = new Vx.Ui.Ui.Class_ui_from_ui_selected();
  public static Func_ui_from_ui_selected t_ui_from_ui_selected = new Vx.Ui.Ui.Class_ui_from_ui_selected();

  public static Vx.Ui.Ui.Type_ui f_ui_from_ui_selected(Vx.Ui.Ui.Type_ui ui, Vx.Core.Type_int selected) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_if_2(
      Vx.Ui.Ui.t_ui,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
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
                    return 
                      Vx.Core.f_if_2(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(Vx.Core.t_thenelselist,
                          Vx.Core.f_then(
                            Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                              return Vx.Core.f_eq(posval, selected);
                            }),
                            Vx.Core.t_any_from_func.vx_fn_new(() => {
                              return Vx.Core.f_copy(
                                uival,
                                Vx.Core.vx_new(Vx.Core.t_anylist,
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
                                Vx.Core.vx_new(Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":selected"),
                                    Vx.Core.vx_new_boolean(false)
                                )
                              );
                            })
                          )
                        )
                      );
                  })
                );
                Vx.Ui.Ui.Type_uimap childmap = Vx.Ui.Ui.f_uimap_from_uilist(uilist2);
                return Vx.Core.f_copy(
                  ui,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":uimap"),
                    childmap
                  )
                );
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

    public override Vx.Ui.Ui.Func_uid_selected_from_ui vx_new(params Object[] vals) {
      Class_uid_selected_from_ui output = new Class_uid_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_uid_selected_from_ui vx_copy(params Object[] vals) {
      Class_uid_selected_from_ui output = new Class_uid_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uid_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uid_selected_from_ui;
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

  public static Func_uid_selected_from_ui e_uid_selected_from_ui = new Vx.Ui.Ui.Class_uid_selected_from_ui();
  public static Func_uid_selected_from_ui t_uid_selected_from_ui = new Vx.Ui.Ui.Class_uid_selected_from_ui();

  public static Vx.Core.Type_string f_uid_selected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist uidlist = Vx.Ui.Ui.f_stringlist_selected_from_ui(ui);
        return Vx.Core.f_first_from_list(Vx.Core.t_string, uidlist);
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

    public override Vx.Ui.Ui.Func_uiengine_readstate vx_new(params Object[] vals) {
      Class_uiengine_readstate output = new Class_uiengine_readstate();
      return output;
    }

    public override Vx.Ui.Ui.Func_uiengine_readstate vx_copy(params Object[] vals) {
      Class_uiengine_readstate output = new Class_uiengine_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uiengine_readstate;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uiengine_readstate;
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

  public static Func_uiengine_readstate e_uiengine_readstate = new Vx.Ui.Ui.Class_uiengine_readstate();
  public static Func_uiengine_readstate t_uiengine_readstate = new Vx.Ui.Ui.Class_uiengine_readstate();

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

    public override Vx.Ui.Ui.Func_uiengine_render vx_new(params Object[] vals) {
      Class_uiengine_render output = new Class_uiengine_render();
      return output;
    }

    public override Vx.Ui.Ui.Func_uiengine_render vx_copy(params Object[] vals) {
      Class_uiengine_render output = new Class_uiengine_render();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uiengine_render;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uiengine_render;
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

  public static Func_uiengine_render e_uiengine_render = new Vx.Ui.Ui.Class_uiengine_render();
  public static Func_uiengine_render t_uiengine_render = new Vx.Ui.Ui.Class_uiengine_render();

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
        return Vx.Core.f_copy(
          uiengine,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":ui"),
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
  public interface Func_uilist_selected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uilist vx_uilist_selected_from_ui(Vx.Ui.Ui.Type_ui uiarg);
  }

  public class Class_uilist_selected_from_ui : Vx.Core.Class_base, Func_uilist_selected_from_ui {

    public override Vx.Ui.Ui.Func_uilist_selected_from_ui vx_new(params Object[] vals) {
      Class_uilist_selected_from_ui output = new Class_uilist_selected_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_uilist_selected_from_ui vx_copy(params Object[] vals) {
      Class_uilist_selected_from_ui output = new Class_uilist_selected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uilist_selected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uilist_selected_from_ui;
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

  public static Func_uilist_selected_from_ui e_uilist_selected_from_ui = new Vx.Ui.Ui.Class_uilist_selected_from_ui();
  public static Func_uilist_selected_from_ui t_uilist_selected_from_ui = new Vx.Ui.Ui.Class_uilist_selected_from_ui();

  public static Vx.Ui.Ui.Type_uilist f_uilist_selected_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_uilist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        return Vx.Collection.f_list_from_list_filter(
          Vx.Ui.Ui.t_uilist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            return 
            Vx.Core.f_if(
              Vx.Ui.Ui.t_ui,
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

    public override Vx.Ui.Ui.Func_uilist_visible_from_ui vx_new(params Object[] vals) {
      Class_uilist_visible_from_ui output = new Class_uilist_visible_from_ui();
      return output;
    }

    public override Vx.Ui.Ui.Func_uilist_visible_from_ui vx_copy(params Object[] vals) {
      Class_uilist_visible_from_ui output = new Class_uilist_visible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uilist_visible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uilist_visible_from_ui;
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

  public static Func_uilist_visible_from_ui e_uilist_visible_from_ui = new Vx.Ui.Ui.Class_uilist_visible_from_ui();
  public static Func_uilist_visible_from_ui t_uilist_visible_from_ui = new Vx.Ui.Ui.Class_uilist_visible_from_ui();

  public static Vx.Ui.Ui.Type_uilist f_uilist_visible_from_ui(Vx.Ui.Ui.Type_ui uiarg) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_uilist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = uiarg.uimap();
        Vx.Ui.Ui.Type_uilist uilist = Vx.Ui.Ui.f_uilist_from_uimap(uimap);
        return Vx.Collection.f_list_from_list_filter(
          Vx.Ui.Ui.t_uilist,
          uilist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
            return 
            Vx.Core.f_if(
              Vx.Ui.Ui.t_ui,
              Vx.Core.f_not(
                item.hidden()
              ),
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
  public interface Func_uilist_from_uimap : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uilist vx_uilist_from_uimap(Vx.Ui.Ui.Type_uimap uimap);
  }

  public class Class_uilist_from_uimap : Vx.Core.Class_base, Func_uilist_from_uimap {

    public override Vx.Ui.Ui.Func_uilist_from_uimap vx_new(params Object[] vals) {
      Class_uilist_from_uimap output = new Class_uilist_from_uimap();
      return output;
    }

    public override Vx.Ui.Ui.Func_uilist_from_uimap vx_copy(params Object[] vals) {
      Class_uilist_from_uimap output = new Class_uilist_from_uimap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uilist_from_uimap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uilist_from_uimap;
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

  public static Func_uilist_from_uimap e_uilist_from_uimap = new Vx.Ui.Ui.Class_uilist_from_uimap();
  public static Func_uilist_from_uimap t_uilist_from_uimap = new Vx.Ui.Ui.Class_uilist_from_uimap();

  public static Vx.Ui.Ui.Type_uilist f_uilist_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
    Vx.Ui.Ui.Type_uilist output = Vx.Ui.Ui.e_uilist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Ui.Ui.t_uilist,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, item_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui item = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, item_any);
        return item;
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

    public override Vx.Ui.Ui.Func_uimap_addlayout_from_uimap_layoutmap_else vx_new(params Object[] vals) {
      Class_uimap_addlayout_from_uimap_layoutmap_else output = new Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    public override Vx.Ui.Ui.Func_uimap_addlayout_from_uimap_layoutmap_else vx_copy(params Object[] vals) {
      Class_uimap_addlayout_from_uimap_layoutmap_else output = new Class_uimap_addlayout_from_uimap_layoutmap_else();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uimap_addlayout_from_uimap_layoutmap_else;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uimap_addlayout_from_uimap_layoutmap_else;
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

  public static Func_uimap_addlayout_from_uimap_layoutmap_else e_uimap_addlayout_from_uimap_layoutmap_else = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();
  public static Func_uimap_addlayout_from_uimap_layoutmap_else t_uimap_addlayout_from_uimap_layoutmap_else = new Vx.Ui.Ui.Class_uimap_addlayout_from_uimap_layoutmap_else();

  public static Vx.Ui.Ui.Type_uimap f_uimap_addlayout_from_uimap_layoutmap_else(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_layoutmap layoutmap, Vx.Ui.Ui.Type_layout layoutelse) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_map_1(
      Vx.Ui.Ui.t_uimap,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, ui_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, ui_any);
        return 
        Vx.Ui.Ui.f_ui_addlayout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
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

    public override Vx.Ui.Ui.Func_uimap_layout_from_uimap_parent vx_new(params Object[] vals) {
      Class_uimap_layout_from_uimap_parent output = new Class_uimap_layout_from_uimap_parent();
      return output;
    }

    public override Vx.Ui.Ui.Func_uimap_layout_from_uimap_parent vx_copy(params Object[] vals) {
      Class_uimap_layout_from_uimap_parent output = new Class_uimap_layout_from_uimap_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uimap_layout_from_uimap_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uimap_layout_from_uimap_parent;
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

  public static Func_uimap_layout_from_uimap_parent e_uimap_layout_from_uimap_parent = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();
  public static Func_uimap_layout_from_uimap_parent t_uimap_layout_from_uimap_parent = new Vx.Ui.Ui.Class_uimap_layout_from_uimap_parent();

  public static Vx.Ui.Ui.Type_uimap f_uimap_layout_from_uimap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_map_1(
      Vx.Ui.Ui.t_uimap,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, val_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui val = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, val_any);
        return 
        Vx.Ui.Ui.f_ui_layout_from_ui_orig_parent(
          val,
          Vx.Core.f_empty(
            Vx.Ui.Ui.t_ui
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
  public interface Func_uimap_from_uilist : Vx.Core.Func_any_from_any {
    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uilist(Vx.Ui.Ui.Type_uilist uilist);
  }

  public class Class_uimap_from_uilist : Vx.Core.Class_base, Func_uimap_from_uilist {

    public override Vx.Ui.Ui.Func_uimap_from_uilist vx_new(params Object[] vals) {
      Class_uimap_from_uilist output = new Class_uimap_from_uilist();
      return output;
    }

    public override Vx.Ui.Ui.Func_uimap_from_uilist vx_copy(params Object[] vals) {
      Class_uimap_from_uilist output = new Class_uimap_from_uilist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uimap_from_uilist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uimap_from_uilist;
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

  public static Func_uimap_from_uilist e_uimap_from_uilist = new Vx.Ui.Ui.Class_uimap_from_uilist();
  public static Func_uimap_from_uilist t_uimap_from_uilist = new Vx.Ui.Ui.Class_uimap_from_uilist();

  public static Vx.Ui.Ui.Type_uimap f_uimap_from_uilist(Vx.Ui.Ui.Type_uilist uilist) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    output = Vx.Core.f_map_from_list(
      Vx.Ui.Ui.t_uimap,
      uilist,
      Vx.Core.t_any_from_any.vx_fn_new((ui_any) => {
        Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, ui_any);
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
  public interface Func_uimap_from_uimap_data : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_uimap vx_uimap_from_uimap_data(Vx.Ui.Ui.Type_uimap uimap, Vx.Core.Type_any data);
  }

  public class Class_uimap_from_uimap_data : Vx.Core.Class_base, Func_uimap_from_uimap_data {

    public override Vx.Ui.Ui.Func_uimap_from_uimap_data vx_new(params Object[] vals) {
      Class_uimap_from_uimap_data output = new Class_uimap_from_uimap_data();
      return output;
    }

    public override Vx.Ui.Ui.Func_uimap_from_uimap_data vx_copy(params Object[] vals) {
      Class_uimap_from_uimap_data output = new Class_uimap_from_uimap_data();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
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
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_uimap_from_uimap_data;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uimap_from_uimap_data;
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

  public static Func_uimap_from_uimap_data e_uimap_from_uimap_data = new Vx.Ui.Ui.Class_uimap_from_uimap_data();
  public static Func_uimap_from_uimap_data t_uimap_from_uimap_data = new Vx.Ui.Ui.Class_uimap_from_uimap_data();

  public static Vx.Ui.Ui.Type_uimap f_uimap_from_uimap_data(Vx.Ui.Ui.Type_uimap uimap, Vx.Core.Type_any data) {
    Vx.Ui.Ui.Type_uimap output = Vx.Ui.Ui.e_uimap;
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
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
    }
  }

}
