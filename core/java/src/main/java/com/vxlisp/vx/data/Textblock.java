package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;


public final class Textblock {


  /**
   * type: delim
   * A delimiter type supporting start and end delimiters and positions.
   * (type delim)
   */
  public interface Type_delim extends Core.Type_struct {
    public Textblock.Type_delim vx_new(final Object... vals);
    public Textblock.Type_delim vx_copy(final Object... vals);
    public Textblock.Type_delim vx_empty();
    public Textblock.Type_delim vx_type();
    public Core.Type_string name();
    public Core.Type_string starttext();
    public Core.Type_string endtext();
    public Core.Type_int startpos();
    public Core.Type_int endpos();
    public Textblock.Type_delimlist delimlist();
  }

  public static class Class_delim extends Core.Class_base implements Type_delim {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_starttext;

    @Override
    public Core.Type_string starttext() {
      return this.vx_p_starttext == null ? Core.e_string : this.vx_p_starttext;
    }

    protected Core.Type_string vx_p_endtext;

    @Override
    public Core.Type_string endtext() {
      return this.vx_p_endtext == null ? Core.e_string : this.vx_p_endtext;
    }

    protected Core.Type_int vx_p_startpos;

    @Override
    public Core.Type_int startpos() {
      return this.vx_p_startpos == null ? Core.e_int : this.vx_p_startpos;
    }

    protected Core.Type_int vx_p_endpos;

    @Override
    public Core.Type_int endpos() {
      return this.vx_p_endpos == null ? Core.e_int : this.vx_p_endpos;
    }

    protected Textblock.Type_delimlist vx_p_delimlist;

    @Override
    public Textblock.Type_delimlist delimlist() {
      return this.vx_p_delimlist == null ? Textblock.e_delimlist : this.vx_p_delimlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":starttext":
        output = this.starttext();
        break;
      case ":endtext":
        output = this.endtext();
        break;
      case ":startpos":
        output = this.startpos();
        break;
      case ":endpos":
        output = this.endpos();
        break;
      case ":delimlist":
        output = this.delimlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":starttext", this.starttext());
      output.put(":endtext", this.endtext());
      output.put(":startpos", this.startpos());
      output.put(":endpos", this.endpos());
      output.put(":delimlist", this.delimlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_delim vx_new(final Object... vals) {return e_delim.vx_copy(vals);}

    @Override
    public Type_delim vx_copy(final Object... vals) {
      Class_delim output = new Class_delim();
      Type_delim val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":starttext");
      validkeys.add(":endtext");
      validkeys.add(":startpos");
      validkeys.add(":endpos");
      validkeys.add(":delimlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("(new delim) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":starttext":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_starttext = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_starttext = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :starttext " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":endtext":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_endtext = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_endtext = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :endtext " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":startpos":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_startpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_startpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :startpos " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":endpos":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_endpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_endpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :endpos " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":delimlist":
            if (valsub instanceof Textblock.Type_delimlist) {
              output.vx_p_delimlist = (Textblock.Type_delimlist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new delim :delimlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new delim) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_delim vx_empty() {return e_delim;}
    @Override
    public Type_delim vx_type() {return t_delim;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delim", // name
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

  public static final Type_delim e_delim = new Class_delim();
  public static final Type_delim t_delim = new Class_delim();

  /**
   * type: delimlist
   * A list of delim.
   * (type delimlist)
   */
  public interface Type_delimlist extends Core.Type_list {
    public Textblock.Type_delimlist vx_new(final Object... vals);
    public Textblock.Type_delimlist vx_copy(final Object... vals);
    public Textblock.Type_delimlist vx_empty();
    public Textblock.Type_delimlist vx_type();
    public List<Textblock.Type_delim> vx_listdelim();
    public Textblock.Type_delim vx_delim(final Core.Type_int index);
  }

  public static class Class_delimlist extends Core.Class_base implements Type_delimlist {

    protected List<Textblock.Type_delim> vx_p_list = Core.immutablelist(new ArrayList<Textblock.Type_delim>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Textblock.Type_delim vx_delim(final Core.Type_int index) {
      Textblock.Type_delim output = Textblock.e_delim;
      Class_delimlist list = this;
      int iindex = index.vx_int();
      List<Textblock.Type_delim> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Textblock.Type_delim> vx_listdelim() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_delim(index);
    }

    @Override
    public Type_delimlist vx_new(final Object... vals) {return e_delimlist.vx_copy(vals);}

    @Override
    public Type_delimlist vx_copy(final Object... vals) {
      Class_delimlist output = new Class_delimlist();
      Type_delimlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Textblock.Type_delim> listval = new ArrayList<>(val.vx_listdelim());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Textblock.Type_delim) {
          listval.add((Textblock.Type_delim)valsub);
        } else if (valsub instanceof Textblock.Type_delim) {
          listval.add((Textblock.Type_delim)valsub);
        } else if (valsub instanceof Type_delimlist) {
          Type_delimlist multi = (Type_delimlist)valsub;
          listval.addAll(multi.vx_listdelim());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Textblock.Type_delim) {
              Textblock.Type_delim valitem = (Textblock.Type_delim)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new delimlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vx_p_list = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_delimlist vx_empty() {return e_delimlist;}
    @Override
    public Type_delimlist vx_type() {return t_delimlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Textblock.t_delim), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_delimlist e_delimlist = new Class_delimlist();
  public static final Type_delimlist t_delimlist = new Class_delimlist();

  /**
   * type: textblock
   * A textblock is a tree of text used for parsing by delimter.
   * (type textblock)
   */
  public interface Type_textblock extends Core.Type_struct {
    public Textblock.Type_textblock vx_new(final Object... vals);
    public Textblock.Type_textblock vx_copy(final Object... vals);
    public Textblock.Type_textblock vx_empty();
    public Textblock.Type_textblock vx_type();
    public Core.Type_string name();
    public Core.Type_string text();
    public Core.Type_int startpos();
    public Core.Type_int endpos();
    public Core.Type_int curpos();
    public Core.Type_int line();
    public Core.Type_int column();
    public Textblock.Type_delim delim();
    public Textblock.Type_delim close();
    public Textblock.Type_textblock parent();
    public Textblock.Type_textblocklist children();
  }

  public static class Class_textblock extends Core.Class_base implements Type_textblock {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_text;

    @Override
    public Core.Type_string text() {
      return this.vx_p_text == null ? Core.e_string : this.vx_p_text;
    }

    protected Core.Type_int vx_p_startpos;

    @Override
    public Core.Type_int startpos() {
      return this.vx_p_startpos == null ? Core.e_int : this.vx_p_startpos;
    }

    protected Core.Type_int vx_p_endpos;

    @Override
    public Core.Type_int endpos() {
      return this.vx_p_endpos == null ? Core.e_int : this.vx_p_endpos;
    }

    protected Core.Type_int vx_p_curpos;

    @Override
    public Core.Type_int curpos() {
      return this.vx_p_curpos == null ? Core.e_int : this.vx_p_curpos;
    }

    protected Core.Type_int vx_p_line;

    @Override
    public Core.Type_int line() {
      return this.vx_p_line == null ? Core.e_int : this.vx_p_line;
    }

    protected Core.Type_int vx_p_column;

    @Override
    public Core.Type_int column() {
      return this.vx_p_column == null ? Core.e_int : this.vx_p_column;
    }

    protected Textblock.Type_delim vx_p_delim;

    @Override
    public Textblock.Type_delim delim() {
      return this.vx_p_delim == null ? Textblock.e_delim : this.vx_p_delim;
    }

    protected Textblock.Type_delim vx_p_close;

    @Override
    public Textblock.Type_delim close() {
      return this.vx_p_close == null ? Textblock.e_delim : this.vx_p_close;
    }

    protected Textblock.Type_textblock vx_p_parent;

    @Override
    public Textblock.Type_textblock parent() {
      return this.vx_p_parent == null ? Textblock.e_textblock : this.vx_p_parent;
    }

    protected Textblock.Type_textblocklist vx_p_children;

    @Override
    public Textblock.Type_textblocklist children() {
      return this.vx_p_children == null ? Textblock.e_textblocklist : this.vx_p_children;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":text":
        output = this.text();
        break;
      case ":startpos":
        output = this.startpos();
        break;
      case ":endpos":
        output = this.endpos();
        break;
      case ":curpos":
        output = this.curpos();
        break;
      case ":line":
        output = this.line();
        break;
      case ":column":
        output = this.column();
        break;
      case ":delim":
        output = this.delim();
        break;
      case ":close":
        output = this.close();
        break;
      case ":parent":
        output = this.parent();
        break;
      case ":children":
        output = this.children();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":text", this.text());
      output.put(":startpos", this.startpos());
      output.put(":endpos", this.endpos());
      output.put(":curpos", this.curpos());
      output.put(":line", this.line());
      output.put(":column", this.column());
      output.put(":delim", this.delim());
      output.put(":close", this.close());
      output.put(":parent", this.parent());
      output.put(":children", this.children());
      return Core.immutablemap(output);
    }

    @Override
    public Type_textblock vx_new(final Object... vals) {return e_textblock.vx_copy(vals);}

    @Override
    public Type_textblock vx_copy(final Object... vals) {
      Class_textblock output = new Class_textblock();
      Type_textblock val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_text = val.text();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_curpos = val.curpos();
      output.vx_p_line = val.line();
      output.vx_p_column = val.column();
      output.vx_p_delim = val.delim();
      output.vx_p_close = val.close();
      output.vx_p_parent = val.parent();
      output.vx_p_children = val.children();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":text");
      validkeys.add(":startpos");
      validkeys.add(":endpos");
      validkeys.add(":curpos");
      validkeys.add(":line");
      validkeys.add(":column");
      validkeys.add(":delim");
      validkeys.add(":close");
      validkeys.add(":parent");
      validkeys.add(":children");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("(new textblock) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":startpos":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_startpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_startpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :startpos " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":endpos":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_endpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_endpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :endpos " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":curpos":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_curpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_curpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :curpos " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":line":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_line = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_line = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :line " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":column":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_column = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_column = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :column " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":delim":
            if (valsub instanceof Textblock.Type_delim) {
              output.vx_p_delim = (Textblock.Type_delim)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :delim " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":close":
            if (valsub instanceof Textblock.Type_delim) {
              output.vx_p_close = (Textblock.Type_delim)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :close " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":parent":
            if (valsub instanceof Textblock.Type_textblock) {
              output.vx_p_parent = (Textblock.Type_textblock)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :parent " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":children":
            if (valsub instanceof Textblock.Type_textblocklist) {
              output.vx_p_children = (Textblock.Type_textblocklist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :children " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new textblock) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_textblock vx_empty() {return e_textblock;}
    @Override
    public Type_textblock vx_type() {return t_textblock;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblock", // name
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

  public static final Type_textblock e_textblock = new Class_textblock();
  public static final Type_textblock t_textblock = new Class_textblock();

  /**
   * type: textblocklist
   * A list of textblock.
   * (type textblocklist)
   */
  public interface Type_textblocklist extends Core.Type_list {
    public Textblock.Type_textblocklist vx_new(final Object... vals);
    public Textblock.Type_textblocklist vx_copy(final Object... vals);
    public Textblock.Type_textblocklist vx_empty();
    public Textblock.Type_textblocklist vx_type();
    public List<Textblock.Type_textblock> vx_listtextblock();
    public Textblock.Type_textblock vx_textblock(final Core.Type_int index);
  }

  public static class Class_textblocklist extends Core.Class_base implements Type_textblocklist {

    protected List<Textblock.Type_textblock> vx_p_list = Core.immutablelist(new ArrayList<Textblock.Type_textblock>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Textblock.Type_textblock vx_textblock(final Core.Type_int index) {
      Textblock.Type_textblock output = Textblock.e_textblock;
      Class_textblocklist list = this;
      int iindex = index.vx_int();
      List<Textblock.Type_textblock> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Textblock.Type_textblock> vx_listtextblock() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_textblock(index);
    }

    @Override
    public Type_textblocklist vx_new(final Object... vals) {return e_textblocklist.vx_copy(vals);}

    @Override
    public Type_textblocklist vx_copy(final Object... vals) {
      Class_textblocklist output = new Class_textblocklist();
      Type_textblocklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Textblock.Type_textblock> listval = new ArrayList<>(val.vx_listtextblock());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Textblock.Type_textblock) {
          listval.add((Textblock.Type_textblock)valsub);
        } else if (valsub instanceof Textblock.Type_textblock) {
          listval.add((Textblock.Type_textblock)valsub);
        } else if (valsub instanceof Type_textblocklist) {
          Type_textblocklist multi = (Type_textblocklist)valsub;
          listval.addAll(multi.vx_listtextblock());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Textblock.Type_textblock) {
              Textblock.Type_textblock valitem = (Textblock.Type_textblock)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new textblocklist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vx_p_list = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_textblocklist vx_empty() {return e_textblocklist;}
    @Override
    public Type_textblocklist vx_type() {return t_textblocklist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Textblock.t_textblock), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_textblocklist e_textblocklist = new Class_textblocklist();
  public static final Type_textblocklist t_textblocklist = new Class_textblocklist();

  /**
   * Constant: delimbracketangle
   * Angle Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketangle extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketangle", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketangle output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimbracketangle"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("<"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(">")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketangle c_delimbracketangle = new Const_delimbracketangle();


  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketcurly extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketcurly", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketcurly output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimbracketcurly"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("{"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("}")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketcurly c_delimbracketcurly = new Const_delimbracketcurly();


  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketsquare extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketsquare", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketsquare output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimbracketsquare"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("["),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("]")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketsquare c_delimbracketsquare = new Const_delimbracketsquare();


  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  public static class Const_delimclose extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclose", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimclose output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimclose"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string(""),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimclose c_delimclose = new Const_delimclose();


  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  public static class Const_delimcomma extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomma", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcomma output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimcomma"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string(",")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcomma c_delimcomma = new Const_delimcomma();


  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  public static class Const_delimcomment extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomment", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcomment output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimcomment"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("//"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("\n")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcomment c_delimcomment = new Const_delimcomment();


  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  public static class Const_delimcommentblock extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcommentblock", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcommentblock output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimcommentblock"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("/*"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("*/")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcommentblock c_delimcommentblock = new Const_delimcommentblock();


  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  public static class Const_delimline extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimline", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimline output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimline"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("\n")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimline c_delimline = new Const_delimline();


  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  public static class Const_delimnonwhitespace extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimnonwhitespace", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimnonwhitespace output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimnonwhitespace"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string(":nonwhitespace"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(":whitespace")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimnonwhitespace c_delimnonwhitespace = new Const_delimnonwhitespace();


  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  public static class Const_delimparen extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimparen", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimparen output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimparen"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("("),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(")")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimparen c_delimparen = new Const_delimparen();


  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  public static class Const_delimquote extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquote", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimquote output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimquote"),
                Core.vx_new_string(":starttext"),
                Core.c_quote,
                Core.vx_new_string(":endtext"),
                Core.c_quote
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimquote c_delimquote = new Const_delimquote();


  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  public static class Const_delimquoteblock extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquoteblock", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimquoteblock output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimquoteblock"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("`"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("`")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimquoteblock c_delimquoteblock = new Const_delimquoteblock();


  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  public static class Const_delimspace extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimspace", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimspace output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimspace"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string(" "),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(" ")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimspace c_delimspace = new Const_delimspace();


  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  public static class Const_delimtext extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtext", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimtext output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimtext")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimtext c_delimtext = new Const_delimtext();


  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  public static class Const_delimwhitespace extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimwhitespace", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimwhitespace output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimwhitespace"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string(":whitespace"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(":nonwhitespace")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_startpos = val.startpos();
      output.vx_p_endpos = val.endpos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimwhitespace c_delimwhitespace = new Const_delimwhitespace();

  /**
   * @function children_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} textblock
   * @return {textblocklist}
   * (func children<-textblock)
   */
  public static interface Func_children_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblocklist f_children_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_children_from_textblock extends Core.Class_base implements Func_children_from_textblock {

    @Override
    public Func_children_from_textblock vx_new(Object... vals) {
      Class_children_from_textblock output = new Class_children_from_textblock();
      return output;
    }

    @Override
    public Func_children_from_textblock vx_copy(Object... vals) {
      Class_children_from_textblock output = new Class_children_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Textblock.t_textblock), // allowtypes
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
    public Func_children_from_textblock vx_empty() {return e_children_from_textblock;}
    @Override
    public Func_children_from_textblock vx_type() {return t_children_from_textblock;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_children_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_children_from_textblock(textblock);
      return output;
    }

    @Override
    public Textblock.Type_textblocklist f_children_from_textblock(final Textblock.Type_textblock textblock) {
      return Textblock.f_children_from_textblock(textblock);
    }

  }

  public static final Func_children_from_textblock e_children_from_textblock = new Textblock.Class_children_from_textblock();
  public static final Func_children_from_textblock t_children_from_textblock = new Textblock.Class_children_from_textblock();

  public static Textblock.Type_textblocklist f_children_from_textblock(final Textblock.Type_textblock textblock) {
    Textblock.Type_textblocklist output = Textblock.e_textblocklist;
    output = textblock.children();
    return output;
  }

  /**
   * @function delim_close_from_delim
   * Returns delim with a close delim added.
   * @param  {delim} delim
   * @return {delim}
   * (func delim-close<-delim)
   */
  public static interface Func_delim_close_from_delim extends Core.Func_any_from_any {
    public Textblock.Type_delim f_delim_close_from_delim(final Textblock.Type_delim delim);
  }

  public static class Class_delim_close_from_delim extends Core.Class_base implements Func_delim_close_from_delim {

    @Override
    public Func_delim_close_from_delim vx_new(Object... vals) {
      Class_delim_close_from_delim output = new Class_delim_close_from_delim();
      return output;
    }

    @Override
    public Func_delim_close_from_delim vx_copy(Object... vals) {
      Class_delim_close_from_delim output = new Class_delim_close_from_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-close<-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
    public Func_delim_close_from_delim vx_empty() {return e_delim_close_from_delim;}
    @Override
    public Func_delim_close_from_delim vx_type() {return t_delim_close_from_delim;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_delim inputval = (Textblock.Type_delim)value;
      Core.Type_any outputval = Textblock.f_delim_close_from_delim(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_delim_close_from_delim(delim);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_close_from_delim(final Textblock.Type_delim delim) {
      return Textblock.f_delim_close_from_delim(delim);
    }

  }

  public static final Func_delim_close_from_delim e_delim_close_from_delim = new Textblock.Class_delim_close_from_delim();
  public static final Func_delim_close_from_delim t_delim_close_from_delim = new Textblock.Class_delim_close_from_delim();

  public static Textblock.Type_delim f_delim_close_from_delim(final Textblock.Type_delim delim) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delimlist delimlist = delim.delimlist();
        final Core.Type_string endtext = delim.endtext();
        final Textblock.Type_delimlist addlist = Core.f_if_2(
          Textblock.t_delimlist,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(Core.vx_new_string(""), endtext);
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return delimlist;
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_copy(
                    delimlist,
                    Core.t_anylist.vx_new(
                        Core.f_copy(
                          Textblock.c_delimclose,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":starttext"),
                            endtext
                          )
                        )
                    )
                  );
                })
              )
          )
        );
        return Core.f_if_2(
          Textblock.t_delim,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(addlist);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  delim,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":delimlist"),
                      addlist
                  )
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
   * @function delim_first_from_delim_delim
   * Returns non-empty delim with lowest, non-negative startpos found in string.
   * @param  {delim} delim1
   * @param  {delim} delim2
   * @return {delim}
   * (func delim-first<-delim-delim)
   */
  public static interface Func_delim_first_from_delim_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim f_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2);
  }

  public static class Class_delim_first_from_delim_delim extends Core.Class_base implements Func_delim_first_from_delim_delim {

    @Override
    public Func_delim_first_from_delim_delim vx_new(Object... vals) {
      Class_delim_first_from_delim_delim output = new Class_delim_first_from_delim_delim();
      return output;
    }

    @Override
    public Func_delim_first_from_delim_delim vx_copy(Object... vals) {
      Class_delim_first_from_delim_delim output = new Class_delim_first_from_delim_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-delim-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
    public Func_delim_first_from_delim_delim vx_empty() {return e_delim_first_from_delim_delim;}
    @Override
    public Func_delim_first_from_delim_delim vx_type() {return t_delim_first_from_delim_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delim1 = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim2 = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_first_from_delim_delim(delim1, delim2);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2) {
      return Textblock.f_delim_first_from_delim_delim(delim1, delim2);
    }

  }

  public static final Func_delim_first_from_delim_delim e_delim_first_from_delim_delim = new Textblock.Class_delim_first_from_delim_delim();
  public static final Func_delim_first_from_delim_delim t_delim_first_from_delim_delim = new Textblock.Class_delim_first_from_delim_delim();

  public static Textblock.Type_delim f_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int pos1 = delim1.startpos();
        final Core.Type_int pos2 = delim2.startpos();
        return Core.f_if_2(
          Textblock.t_delim,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_lt(pos2, Core.vx_new_int(0));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim1;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_lt(pos1, Core.vx_new_int(0));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim2;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(delim2);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim1;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(delim1);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim2;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_lt(pos2, pos1);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim2;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim1;
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function delim_first_from_string_delimlist_offset
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @param  {int} start
   * @return {delim}
   * (func delim-first<-string-delimlist-offset)
   */
  public static interface Func_delim_first_from_string_delimlist_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim f_delim_first_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start);
  }

  public static class Class_delim_first_from_string_delimlist_offset extends Core.Class_base implements Func_delim_first_from_string_delimlist_offset {

    @Override
    public Func_delim_first_from_string_delimlist_offset vx_new(Object... vals) {
      Class_delim_first_from_string_delimlist_offset output = new Class_delim_first_from_string_delimlist_offset();
      return output;
    }

    @Override
    public Func_delim_first_from_string_delimlist_offset vx_copy(Object... vals) {
      Class_delim_first_from_string_delimlist_offset output = new Class_delim_first_from_string_delimlist_offset();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist-offset", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
    public Func_delim_first_from_string_delimlist_offset vx_empty() {return e_delim_first_from_string_delimlist_offset;}
    @Override
    public Func_delim_first_from_string_delimlist_offset vx_type() {return t_delim_first_from_string_delimlist_offset;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_delim_first_from_string_delimlist_offset(text, delimlist, start);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_first_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start) {
      return Textblock.f_delim_first_from_string_delimlist_offset(text, delimlist, start);
    }

  }

  public static final Func_delim_first_from_string_delimlist_offset e_delim_first_from_string_delimlist_offset = new Textblock.Class_delim_first_from_string_delimlist_offset();
  public static final Func_delim_first_from_string_delimlist_offset t_delim_first_from_string_delimlist_offset = new Textblock.Class_delim_first_from_string_delimlist_offset();

  public static Textblock.Type_delim f_delim_first_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_if_2(
      Textblock.t_delim,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_empty_1(delimlist);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_empty(
              Textblock.t_delim
            );
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Textblock.t_delim,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Textblock.Type_delimlist resolvedlist = Textblock.f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start);
                return Core.f_any_from_list_reduce(
                  Textblock.t_delim,
                  resolvedlist,
                  Core.f_empty(
                    Textblock.t_delim
                  ),
                  Core.t_any_from_reduce.vx_fn_new((Core.Type_any delim1_any, Core.Type_any delim2_any) -> {
                    Textblock.Type_delim delim1 = Core.f_any_from_any(Textblock.t_delim, delim1_any);
                    Textblock.Type_delim delim2 = Core.f_any_from_any(Textblock.t_delim, delim2_any);
                    Core.Type_any output_1 = Textblock.f_delim_first_from_delim_delim(delim1, delim2);
                    return output_1;
                  })
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
   * @function delim_pos_from_string_delim_offset
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @param  {int} start
   * @return {delim}
   * (func delim-pos<-string-delim-offset)
   */
  public static interface Func_delim_pos_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim f_delim_pos_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int start);
  }

  public static class Class_delim_pos_from_string_delim_offset extends Core.Class_base implements Func_delim_pos_from_string_delim_offset {

    @Override
    public Func_delim_pos_from_string_delim_offset vx_new(Object... vals) {
      Class_delim_pos_from_string_delim_offset output = new Class_delim_pos_from_string_delim_offset();
      return output;
    }

    @Override
    public Func_delim_pos_from_string_delim_offset vx_copy(Object... vals) {
      Class_delim_pos_from_string_delim_offset output = new Class_delim_pos_from_string_delim_offset();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim-offset", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
    public Func_delim_pos_from_string_delim_offset vx_empty() {return e_delim_pos_from_string_delim_offset;}
    @Override
    public Func_delim_pos_from_string_delim_offset vx_type() {return t_delim_pos_from_string_delim_offset;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_delim_pos_from_string_delim_offset(text, delim, start);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_pos_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int start) {
      return Textblock.f_delim_pos_from_string_delim_offset(text, delim, start);
    }

  }

  public static final Func_delim_pos_from_string_delim_offset e_delim_pos_from_string_delim_offset = new Textblock.Class_delim_pos_from_string_delim_offset();
  public static final Func_delim_pos_from_string_delim_offset t_delim_pos_from_string_delim_offset = new Textblock.Class_delim_pos_from_string_delim_offset();

  public static Textblock.Type_delim f_delim_pos_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int start) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string find = delim.starttext();
        final Core.Type_string work = Type.f_string_from_string_start(text, start);
        final Core.Type_int pos = Type.f_int_from_string_findkeyword(work, find);
        return Core.f_if_1(
          Textblock.t_delim,
          Core.f_eq(pos, Core.vx_new_int(-1)),
          Core.f_copy(
            delim,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":startpos"),
              Core.vx_new_int(-1)
            )
          ),
          Core.f_copy(
            delim,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":startpos"),
              Core.f_plus(pos, start)
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function delimlist_pos_from_string_delimlist_offset
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @param  {int} start
   * @return {delimlist}
   * (func delimlist-pos<-string-delimlist-offset)
   */
  public static interface Func_delimlist_pos_from_string_delimlist_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start);
  }

  public static class Class_delimlist_pos_from_string_delimlist_offset extends Core.Class_base implements Func_delimlist_pos_from_string_delimlist_offset {

    @Override
    public Func_delimlist_pos_from_string_delimlist_offset vx_new(Object... vals) {
      Class_delimlist_pos_from_string_delimlist_offset output = new Class_delimlist_pos_from_string_delimlist_offset();
      return output;
    }

    @Override
    public Func_delimlist_pos_from_string_delimlist_offset vx_copy(Object... vals) {
      Class_delimlist_pos_from_string_delimlist_offset output = new Class_delimlist_pos_from_string_delimlist_offset();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist-offset", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Textblock.t_delim), // allowtypes
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
    public Func_delimlist_pos_from_string_delimlist_offset vx_empty() {return e_delimlist_pos_from_string_delimlist_offset;}
    @Override
    public Func_delimlist_pos_from_string_delimlist_offset vx_type() {return t_delimlist_pos_from_string_delimlist_offset;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start);
      return output;
    }

    @Override
    public Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start) {
      return Textblock.f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start);
    }

  }

  public static final Func_delimlist_pos_from_string_delimlist_offset e_delimlist_pos_from_string_delimlist_offset = new Textblock.Class_delimlist_pos_from_string_delimlist_offset();
  public static final Func_delimlist_pos_from_string_delimlist_offset t_delimlist_pos_from_string_delimlist_offset = new Textblock.Class_delimlist_pos_from_string_delimlist_offset();

  public static Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist_offset(final Core.Type_string text, final Textblock.Type_delimlist delimlist, final Core.Type_int start) {
    Textblock.Type_delimlist output = Textblock.e_delimlist;
    output = Core.f_list_from_list(
      Textblock.t_delimlist,
      delimlist,
      Core.t_any_from_any.vx_fn_new((delim_any) -> {
        Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, delim_any);
        return 
          Textblock.f_delim_pos_from_string_delim_offset(text, delim, start);
      })
    );
    return output;
  }

  /**
   * @function stringlist_from_textblocklist
   * Returns a stringlist from each (:text textblock).
   * @param  {textblocklist} textblocklist
   * @return {stringlist}
   * (func stringlist<-textblocklist)
   */
  public static interface Func_stringlist_from_textblocklist extends Core.Func_any_from_any {
    public Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist);
  }

  public static class Class_stringlist_from_textblocklist extends Core.Class_base implements Func_stringlist_from_textblocklist {

    @Override
    public Func_stringlist_from_textblocklist vx_new(Object... vals) {
      Class_stringlist_from_textblocklist output = new Class_stringlist_from_textblocklist();
      return output;
    }

    @Override
    public Func_stringlist_from_textblocklist vx_copy(Object... vals) {
      Class_stringlist_from_textblocklist output = new Class_stringlist_from_textblocklist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
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
    public Func_stringlist_from_textblocklist vx_empty() {return e_stringlist_from_textblocklist;}
    @Override
    public Func_stringlist_from_textblocklist vx_type() {return t_stringlist_from_textblocklist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblocklist inputval = (Textblock.Type_textblocklist)value;
      Core.Type_any outputval = Textblock.f_stringlist_from_textblocklist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_stringlist_from_textblocklist(textblocklist);
      return output;
    }

    @Override
    public Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist) {
      return Textblock.f_stringlist_from_textblocklist(textblocklist);
    }

  }

  public static final Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();
  public static final Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();

  public static Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_list_from_list(
      Core.t_stringlist,
      textblocklist,
      Textblock.t_text_from_textblock
    );
    return output;
  }

  /**
   * @function text_from_textblock
   * Returns the text from a given textblock.
   * @param  {textblock} block
   * @return {string}
   * (func text<-textblock)
   */
  public static interface Func_text_from_textblock extends Core.Func_any_from_any {
    public Core.Type_string f_text_from_textblock(final Textblock.Type_textblock block);
  }

  public static class Class_text_from_textblock extends Core.Class_base implements Func_text_from_textblock {

    @Override
    public Func_text_from_textblock vx_new(Object... vals) {
      Class_text_from_textblock output = new Class_text_from_textblock();
      return output;
    }

    @Override
    public Func_text_from_textblock vx_copy(Object... vals) {
      Class_text_from_textblock output = new Class_text_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
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
    public Func_text_from_textblock vx_empty() {return e_text_from_textblock;}
    @Override
    public Func_text_from_textblock vx_type() {return t_text_from_textblock;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_text_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_text_from_textblock(block);
      return output;
    }

    @Override
    public Core.Type_string f_text_from_textblock(final Textblock.Type_textblock block) {
      return Textblock.f_text_from_textblock(block);
    }

  }

  public static final Func_text_from_textblock e_text_from_textblock = new Textblock.Class_text_from_textblock();
  public static final Func_text_from_textblock t_text_from_textblock = new Textblock.Class_text_from_textblock();

  public static Core.Type_string f_text_from_textblock(final Textblock.Type_textblock block) {
    Core.Type_string output = Core.e_string;
    output = block.text();
    return output;
  }

  /**
   * @function textblock_addchild_from_textblock_find_child
   * Add the child to the given parent textblock.
   * @param  {textblock} textblockarg
   * @param  {textblock} find
   * @param  {textblock} child
   * @return {textblock}
   * (func textblock-addchild<-textblock-find-child)
   */
  public static interface Func_textblock_addchild_from_textblock_find_child extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child);
  }

  public static class Class_textblock_addchild_from_textblock_find_child extends Core.Class_base implements Func_textblock_addchild_from_textblock_find_child {

    @Override
    public Func_textblock_addchild_from_textblock_find_child vx_new(Object... vals) {
      Class_textblock_addchild_from_textblock_find_child output = new Class_textblock_addchild_from_textblock_find_child();
      return output;
    }

    @Override
    public Func_textblock_addchild_from_textblock_find_child vx_copy(Object... vals) {
      Class_textblock_addchild_from_textblock_find_child output = new Class_textblock_addchild_from_textblock_find_child();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-find-child", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_addchild_from_textblock_find_child vx_empty() {return e_textblock_addchild_from_textblock_find_child;}
    @Override
    public Func_textblock_addchild_from_textblock_find_child vx_type() {return t_textblock_addchild_from_textblock_find_child;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock find = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      Textblock.Type_textblock child = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child) {
      return Textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
    }

  }

  public static final Func_textblock_addchild_from_textblock_find_child e_textblock_addchild_from_textblock_find_child = new Textblock.Class_textblock_addchild_from_textblock_find_child();
  public static final Func_textblock_addchild_from_textblock_find_child t_textblock_addchild_from_textblock_find_child = new Textblock.Class_textblock_addchild_from_textblock_find_child();

  public static Textblock.Type_textblock f_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_if_2(
      Textblock.t_textblock,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_empty_1(textblockarg);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_empty(
              Textblock.t_textblock
            );
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_and_1(
              Core.t_booleanlist.vx_new(
                  Core.f_eqeq(find, textblockarg)
              )
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_copy(
              textblockarg,
              Core.t_anylist.vx_new(
                  Core.vx_new_string(":children"),
                  Core.f_copy(
                    textblockarg.children(),
                    Core.t_anylist.vx_new(
                      child
                    )
                  )
              )
            );
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_copy(
              textblockarg,
              Core.t_anylist.vx_new(
                  Core.vx_new_string(":parent"),
                  Textblock.f_textblock_addchild_from_textblock_find_child(
                    textblockarg.parent(),
                    find,
                    child
                  )
              )
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function textblock_delimnotfound
   * Returns a textblock when a delim is not found.
   * @param  {textblock} textblockin
   * @return {textblock}
   * (func textblock-delimnotfound)
   */
  public static interface Func_textblock_delimnotfound extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_delimnotfound(final Textblock.Type_textblock textblockin);
  }

  public static class Class_textblock_delimnotfound extends Core.Class_base implements Func_textblock_delimnotfound {

    @Override
    public Func_textblock_delimnotfound vx_new(Object... vals) {
      Class_textblock_delimnotfound output = new Class_textblock_delimnotfound();
      return output;
    }

    @Override
    public Func_textblock_delimnotfound vx_copy(Object... vals) {
      Class_textblock_delimnotfound output = new Class_textblock_delimnotfound();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-delimnotfound", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_delimnotfound vx_empty() {return e_textblock_delimnotfound;}
    @Override
    public Func_textblock_delimnotfound vx_type() {return t_textblock_delimnotfound;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_delimnotfound(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockin = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_delimnotfound(textblockin);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_delimnotfound(final Textblock.Type_textblock textblockin) {
      return Textblock.f_textblock_delimnotfound(textblockin);
    }

  }

  public static final Func_textblock_delimnotfound e_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();
  public static final Func_textblock_delimnotfound t_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();

  public static Textblock.Type_textblock f_textblock_delimnotfound(final Textblock.Type_textblock textblockin) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delimin = textblockin.delim();
        final Core.Type_string endtext = delimin.endtext();
        final Textblock.Type_textblock parent = textblockin.parent();
        final Textblock.Type_delim delimp = parent.delim();
        final Textblock.Type_delimlist delims = delimp.delimlist();
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_ne(Core.vx_new_string(""), endtext);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  parent,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":delimlist"),
                      Core.f_copy(
                        delims,
                        Core.t_anylist.vx_new(
                          Core.f_copy(
                            textblockin,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":parent"),
                              Core.f_empty(
                                Textblock.t_textblock
                              ),
                              Core.vx_new_string(":msg"),
                              Core.f_msg_from_error(
                                Core.f_new(
                                  Core.t_string,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string("Close delim not found: "),
                                    delimin.name()
                                  )
                                )
                              )
                            )
                          )
                        )
                      )
                  )
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(
                  parent,
                  Core.f_empty(
                    Textblock.t_textblock
                  )
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return textblockin;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_pop(textblockin);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_findparent_from_textblock
   * Find a parent that accepts a child.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-findparent<-textblock)
   */
  public static interface Func_textblock_findparent_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_findparent_from_textblock extends Core.Class_base implements Func_textblock_findparent_from_textblock {

    @Override
    public Func_textblock_findparent_from_textblock vx_new(Object... vals) {
      Class_textblock_findparent_from_textblock output = new Class_textblock_findparent_from_textblock();
      return output;
    }

    @Override
    public Func_textblock_findparent_from_textblock vx_copy(Object... vals) {
      Class_textblock_findparent_from_textblock output = new Class_textblock_findparent_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-findparent<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_findparent_from_textblock vx_empty() {return e_textblock_findparent_from_textblock;}
    @Override
    public Func_textblock_findparent_from_textblock vx_type() {return t_textblock_findparent_from_textblock;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_findparent_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_findparent_from_textblock(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_findparent_from_textblock(textblockarg);
    }

  }

  public static final Func_textblock_findparent_from_textblock e_textblock_findparent_from_textblock = new Textblock.Class_textblock_findparent_from_textblock();
  public static final Func_textblock_findparent_from_textblock t_textblock_findparent_from_textblock = new Textblock.Class_textblock_findparent_from_textblock();

  public static Textblock.Type_textblock f_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delimcurr = textblockarg.delim();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Textblock.Type_textblocklist children = textblockarg.children();
        final Core.Type_string starttext = delimcurr.starttext();
        final Core.Type_string endtext = delimcurr.endtext();
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(textblockarg);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_and(
                  Core.f_eq(starttext, Core.vx_new_string("")),
                  Core.f_eq(endtext, Core.vx_new_string(""))
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return textblockarg;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_findparent_from_textblock(parent);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_groupby_from_textblock_delim
   * Returns a textblock grouped by the given delim.
   * @param  {textblock} textblockarg
   * @param  {delim} delimarg
   * @return {textblock}
   * (func textblock-groupby<-textblock-delim)
   */
  public static interface Func_textblock_groupby_from_textblock_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_groupby_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg);
  }

  public static class Class_textblock_groupby_from_textblock_delim extends Core.Class_base implements Func_textblock_groupby_from_textblock_delim {

    @Override
    public Func_textblock_groupby_from_textblock_delim vx_new(Object... vals) {
      Class_textblock_groupby_from_textblock_delim output = new Class_textblock_groupby_from_textblock_delim();
      return output;
    }

    @Override
    public Func_textblock_groupby_from_textblock_delim vx_copy(Object... vals) {
      Class_textblock_groupby_from_textblock_delim output = new Class_textblock_groupby_from_textblock_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-groupby<-textblock-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_groupby_from_textblock_delim vx_empty() {return e_textblock_groupby_from_textblock_delim;}
    @Override
    public Func_textblock_groupby_from_textblock_delim vx_type() {return t_textblock_groupby_from_textblock_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_groupby_from_textblock_delim(textblockarg, delimarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_groupby_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg) {
      return Textblock.f_textblock_groupby_from_textblock_delim(textblockarg, delimarg);
    }

  }

  public static final Func_textblock_groupby_from_textblock_delim e_textblock_groupby_from_textblock_delim = new Textblock.Class_textblock_groupby_from_textblock_delim();
  public static final Func_textblock_groupby_from_textblock_delim t_textblock_groupby_from_textblock_delim = new Textblock.Class_textblock_groupby_from_textblock_delim();

  public static Textblock.Type_textblock f_textblock_groupby_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_new(
      Textblock.t_textblock,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":delim"),
        delimarg
      )
    );
    return output;
  }

  /**
   * @function textblock_parse
   * Returns a fully parsed textblock from an initialized textblock.
   * @param  {textblock} textblock
   * @return {textblock}
   * (func textblock-parse)
   */
  public static interface Func_textblock_parse extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_parse(final Textblock.Type_textblock textblock);
  }

  public static class Class_textblock_parse extends Core.Class_base implements Func_textblock_parse {

    @Override
    public Func_textblock_parse vx_new(Object... vals) {
      Class_textblock_parse output = new Class_textblock_parse();
      return output;
    }

    @Override
    public Func_textblock_parse vx_copy(Object... vals) {
      Class_textblock_parse output = new Class_textblock_parse();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_parse vx_empty() {return e_textblock_parse;}
    @Override
    public Func_textblock_parse vx_type() {return t_textblock_parse;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_parse(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_parse(textblock);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_parse(final Textblock.Type_textblock textblock) {
      return Textblock.f_textblock_parse(textblock);
    }

  }

  public static final Func_textblock_parse e_textblock_parse = new Textblock.Class_textblock_parse();
  public static final Func_textblock_parse t_textblock_parse = new Textblock.Class_textblock_parse();

  public static Textblock.Type_textblock f_textblock_parse(final Textblock.Type_textblock textblock) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Collection.f_any_from_for_until_loop(
      Textblock.t_textblock,
      textblock,
      Core.t_boolean_from_any.vx_fn_new((current_any) -> {
        Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
        return 
          Core.f_is_empty_1(
            current.parent()
          );
      }),
      Core.t_any_from_any.vx_fn_new((current_any) -> {
        Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
        return 
          Textblock.f_textblock_parse_one(current);
      })
    );
    return output;
  }

  /**
   * @function textblock_parse_one
   * Returns a textblock that has been parse a single level.
   * @param  {textblock} textblockin
   * @return {textblock}
   * (func textblock-parse-one)
   */
  public static interface Func_textblock_parse_one extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_parse_one(final Textblock.Type_textblock textblockin);
  }

  public static class Class_textblock_parse_one extends Core.Class_base implements Func_textblock_parse_one {

    @Override
    public Func_textblock_parse_one vx_new(Object... vals) {
      Class_textblock_parse_one output = new Class_textblock_parse_one();
      return output;
    }

    @Override
    public Func_textblock_parse_one vx_copy(Object... vals) {
      Class_textblock_parse_one output = new Class_textblock_parse_one();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse-one", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_parse_one vx_empty() {return e_textblock_parse_one;}
    @Override
    public Func_textblock_parse_one vx_type() {return t_textblock_parse_one;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_parse_one(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockin = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_parse_one(textblockin);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_parse_one(final Textblock.Type_textblock textblockin) {
      return Textblock.f_textblock_parse_one(textblockin);
    }

  }

  public static final Func_textblock_parse_one e_textblock_parse_one = new Textblock.Class_textblock_parse_one();
  public static final Func_textblock_parse_one t_textblock_parse_one = new Textblock.Class_textblock_parse_one();

  public static Textblock.Type_textblock f_textblock_parse_one(final Textblock.Type_textblock textblockin) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delimin = textblockin.delim();
        final Textblock.Type_delim close = textblockin.close();
        final Core.Type_int startpos = textblockin.startpos();
        final Core.Type_int curpos = textblockin.curpos();
        final Core.Type_string textin = textblockin.text();
        final Textblock.Type_textblock parent = textblockin.parent();
        final Core.Type_string starttext = delimin.starttext();
        final Core.Type_string endtext = delimin.endtext();
        final Textblock.Type_delimlist delimlistin = delimin.delimlist();
        final Textblock.Type_textblock tbchg = Core.f_copy(
          textblockin,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":endpos"),
              Core.f_plus(
                startpos,
                Type.f_length_from_string(textin)
              )
          )
        );
        final Textblock.Type_delimlist delimlistcl = Core.f_if_1(
          Textblock.t_delimlist,
          Core.f_is_empty_1(close),
          delimlistin,
          Core.f_copy(delimlistin, Core.t_anylist.vx_new(
            close))
        );
        final Textblock.Type_delim delimfirst = Textblock.f_delim_first_from_string_delimlist_offset(textin, delimlistcl, curpos);
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_string(""), textin);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return parent;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_and(
                  Core.f_ne(Core.vx_new_string(""), starttext),
                  Core.f_eq(Core.vx_new_string(""), endtext)
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_push(tbchg);
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(delimlistcl);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_if_2(
                  Textblock.t_textblock,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq(
                            parent,
                            Core.f_empty(
                              Textblock.t_textblock
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return tbchg;
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Textblock.f_textblock_pop(tbchg);
                        })
                      )
                  )
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(
                  delimfirst,
                  Core.f_empty(
                    Textblock.t_delim
                  )
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_delimnotfound(tbchg);
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(
                  delimfirst.name(),
                  Textblock.c_delimclose.name()
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_pop_from_textblock_delim(tbchg, delimfirst);
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_push_from_textblock_delim(tbchg, delimfirst);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_parse_from_string_delim
   * Returns a fully parsed textblock from a string and delim.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock-parse<-string-delim)
   */
  public static interface Func_textblock_parse_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_parse_from_string_delim extends Core.Class_base implements Func_textblock_parse_from_string_delim {

    @Override
    public Func_textblock_parse_from_string_delim vx_new(Object... vals) {
      Class_textblock_parse_from_string_delim output = new Class_textblock_parse_from_string_delim();
      return output;
    }

    @Override
    public Func_textblock_parse_from_string_delim vx_copy(Object... vals) {
      Class_textblock_parse_from_string_delim output = new Class_textblock_parse_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse<-string-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_parse_from_string_delim vx_empty() {return e_textblock_parse_from_string_delim;}
    @Override
    public Func_textblock_parse_from_string_delim vx_type() {return t_textblock_parse_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_parse_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_textblock_parse_from_string_delim(text, delim);
    }

  }

  public static final Func_textblock_parse_from_string_delim e_textblock_parse_from_string_delim = new Textblock.Class_textblock_parse_from_string_delim();
  public static final Func_textblock_parse_from_string_delim t_textblock_parse_from_string_delim = new Textblock.Class_textblock_parse_from_string_delim();

  public static Textblock.Type_textblock f_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblock textblockinit = Textblock.f_textblock_from_string_delim(text, delim);
        return Textblock.f_textblock_parse(textblockinit);
      })
    );
    return output;
  }

  /**
   * @function textblock_pop
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-pop)
   */
  public static interface Func_textblock_pop extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_pop(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_pop extends Core.Class_base implements Func_textblock_pop {

    @Override
    public Func_textblock_pop vx_new(Object... vals) {
      Class_textblock_pop output = new Class_textblock_pop();
      return output;
    }

    @Override
    public Func_textblock_pop vx_copy(Object... vals) {
      Class_textblock_pop output = new Class_textblock_pop();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_pop vx_empty() {return e_textblock_pop;}
    @Override
    public Func_textblock_pop vx_type() {return t_textblock_pop;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_pop(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_pop(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_pop(final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_pop(textblockarg);
    }

  }

  public static final Func_textblock_pop e_textblock_pop = new Textblock.Class_textblock_pop();
  public static final Func_textblock_pop t_textblock_pop = new Textblock.Class_textblock_pop();

  public static Textblock.Type_textblock f_textblock_pop(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Core.Type_string text = textblockarg.text();
        final Core.Type_int startpos = textblockarg.startpos();
        final Core.Type_int endpos = Core.f_plus(
          startpos,
          Type.f_length_from_string(text)
        );
        final Textblock.Type_delim delimpar = parent.delim();
        final Textblock.Type_textblock child = Core.f_copy(
          textblockarg,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":endpos"),
              endpos,
              Core.vx_new_string(":delim"),
              Core.f_empty(
                Textblock.t_delim
              ),
              Core.vx_new_string(":parent"),
              Core.f_empty(
                Textblock.t_textblock
              )
          )
        );
        final Textblock.Type_textblock parenttgt = Textblock.f_textblock_findparent_from_textblock(parent);
        return Textblock.f_textblock_addchild_from_textblock_find_child(parent, parenttgt, child);
      })
    );
    return output;
  }

  /**
   * @function textblock_pop_from_textblock_delim
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockarg
   * @param  {delim} delimarg
   * @return {textblock}
   * (func textblock-pop<-textblock-delim)
   */
  public static interface Func_textblock_pop_from_textblock_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_pop_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg);
  }

  public static class Class_textblock_pop_from_textblock_delim extends Core.Class_base implements Func_textblock_pop_from_textblock_delim {

    @Override
    public Func_textblock_pop_from_textblock_delim vx_new(Object... vals) {
      Class_textblock_pop_from_textblock_delim output = new Class_textblock_pop_from_textblock_delim();
      return output;
    }

    @Override
    public Func_textblock_pop_from_textblock_delim vx_copy(Object... vals) {
      Class_textblock_pop_from_textblock_delim output = new Class_textblock_pop_from_textblock_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-pop<-textblock-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_pop_from_textblock_delim vx_empty() {return e_textblock_pop_from_textblock_delim;}
    @Override
    public Func_textblock_pop_from_textblock_delim vx_type() {return t_textblock_pop_from_textblock_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_pop_from_textblock_delim(textblockarg, delimarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_pop_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg) {
      return Textblock.f_textblock_pop_from_textblock_delim(textblockarg, delimarg);
    }

  }

  public static final Func_textblock_pop_from_textblock_delim e_textblock_pop_from_textblock_delim = new Textblock.Class_textblock_pop_from_textblock_delim();
  public static final Func_textblock_pop_from_textblock_delim t_textblock_pop_from_textblock_delim = new Textblock.Class_textblock_pop_from_textblock_delim();

  public static Textblock.Type_textblock f_textblock_pop_from_textblock_delim(final Textblock.Type_textblock textblockarg, final Textblock.Type_delim delimarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_if_2(
      Textblock.t_textblock,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_empty_1(delimarg);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return textblockarg;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eq(
              delimarg.name(),
              Textblock.c_delimclose.name()
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Textblock.t_textblock,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Textblock.Type_textblock parentcur = textblockarg.parent();
                final Textblock.Type_delim delimcur = textblockarg.delim();
                final Core.Type_string starttext = delimcur.starttext();
                final Core.Type_string endtext = delimcur.endtext();
                final Core.Type_int delimpos = delimarg.startpos();
                final Core.Type_int startpos = textblockarg.startpos();
                final Core.Type_int startsub = Type.f_length_from_string(starttext);
                final Core.Type_int endpos = Core.f_plus(
                  delimpos,
                  Type.f_length_from_string(endtext)
                );
                final Core.Type_int endsub = delimpos;
                final Core.Type_string textcur = textblockarg.text();
                final Core.Type_string textout = Type.f_string_from_string_start(textcur, endpos);
                final Core.Type_string textsub = Type.f_string_from_string_start_end(textcur, startsub, endsub);
                final Core.Type_string textdelim = Type.f_string_from_string_start_end(textcur, Core.vx_new_int(0), endpos);
                final Textblock.Type_textblock childchg = Core.f_copy(
                  textblockarg,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":text"),
                      textdelim,
                      Core.vx_new_string(":endpos"),
                      Core.f_plus(startpos, endpos),
                      Core.vx_new_string(":curpos"),
                      Core.vx_new_int(0),
                      Core.vx_new_string(":delim"),
                      Core.f_copy(
                        delimcur,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(0),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(0),
                          Core.vx_new_string(":delimlist"),
                          Core.f_empty(
                            Textblock.t_delimlist
                          )
                        )
                      ),
                      Core.vx_new_string(":close"),
                      Core.f_empty(
                        Textblock.t_delim
                      ),
                      Core.vx_new_string(":parent"),
                      Core.f_empty(
                        Textblock.t_textblock
                      ),
                      Core.vx_new_string(":children"),
                      Core.f_new(
                        Textblock.t_textblocklist,
                        Core.t_anylist.vx_new(
                          Core.f_new(
                            Textblock.t_textblock,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":text"),
                              textsub,
                              Core.vx_new_string(":startpos"),
                              Core.f_plus(startpos, startsub),
                              Core.vx_new_string(":endpos"),
                              Core.f_plus(startpos, endsub),
                              Core.vx_new_string(":curpos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      )
                  )
                );
                final Textblock.Type_textblock parenttgt = Textblock.f_textblock_findparent_from_textblock(parentcur);
                final Textblock.Type_textblock parentchg = Textblock.f_textblock_addchild_from_textblock_find_child(parentcur, parenttgt, childchg);
                return Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    textout,
                    Core.vx_new_string(":delim"),
                    parenttgt.delim(),
                    Core.vx_new_string(":startpos"),
                    Core.f_plus(startpos, endpos),
                    Core.vx_new_string(":parent"),
                    parentchg
                  )
                );
              })
            );
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Textblock.t_textblock,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Textblock.Type_textblock parentcur = textblockarg.parent();
                final Textblock.Type_textblocklist childrenpar = parentcur.children();
                final Textblock.Type_textblock childchg = Core.f_copy(
                  textblockarg,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":delim"),
                      delimarg,
                      Core.vx_new_string(":parent"),
                      Core.f_empty(
                        Textblock.t_textblock
                      )
                  )
                );
                final Textblock.Type_textblocklist childrenchg = Core.f_copy(childrenpar, Core.t_anylist.vx_new(
                  childchg));
                return Core.f_copy(
                  parentcur,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":children"),
                    childrenchg
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
   * @function textblock_push
   * Returns a a textblock using the textblocks current delim.
   * @param  {textblock} textblockin
   * @return {textblock}
   * (func textblock-push)
   */
  public static interface Func_textblock_push extends Core.Func_any_from_any {
    public Textblock.Type_textblock f_textblock_push(final Textblock.Type_textblock textblockin);
  }

  public static class Class_textblock_push extends Core.Class_base implements Func_textblock_push {

    @Override
    public Func_textblock_push vx_new(Object... vals) {
      Class_textblock_push output = new Class_textblock_push();
      return output;
    }

    @Override
    public Func_textblock_push vx_copy(Object... vals) {
      Class_textblock_push output = new Class_textblock_push();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-push", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_push vx_empty() {return e_textblock_push;}
    @Override
    public Func_textblock_push vx_type() {return t_textblock_push;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_push(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockin = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_push(textblockin);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_push(final Textblock.Type_textblock textblockin) {
      return Textblock.f_textblock_push(textblockin);
    }

  }

  public static final Func_textblock_push e_textblock_push = new Textblock.Class_textblock_push();
  public static final Func_textblock_push t_textblock_push = new Textblock.Class_textblock_push();

  public static Textblock.Type_textblock f_textblock_push(final Textblock.Type_textblock textblockin) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockin.text();
        final Textblock.Type_delim delimcur = textblockin.delim();
        final Core.Type_int offset = textblockin.startpos();
        final Core.Type_string starttext = delimcur.starttext();
        final Core.Type_string endtext = delimcur.endtext();
        final Core.Type_int startlen = Type.f_length_from_string(starttext);
        final Core.Type_boolean issingle = Core.f_and(
          Core.f_ne(Core.vx_new_string(""), starttext),
          Core.f_eq(Core.vx_new_string(""), endtext)
        );
        final Textblock.Type_delim delimsplit = Core.f_if_1(
          Textblock.t_delim,
          issingle,
          Core.f_copy(
            delimcur,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":startpos"),
              startlen,
              Core.vx_new_string(":delimlist"),
              Core.f_empty(
                Textblock.t_delimlist
              )
            )
          ),
          delimcur
        );
        final Textblock.Type_delim delimchg = Core.f_if_1(
          Textblock.t_delim,
          issingle,
          Core.f_copy(
            delimsplit,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":startpos"),
              Core.vx_new_int(0)
            )
          ),
          delimsplit
        );
        final Textblock.Type_textblock tbleft = Textblock.f_textblock_startleft_from_string_delim_offset(text, delimsplit, offset);
        final Textblock.Type_textblock tbright = Textblock.f_textblock_startright_from_string_delim_offset(text, delimsplit, offset);
        final Textblock.Type_textblock tbchg = Core.f_copy(
          tbleft,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":delim"),
              delimchg
          )
        );
        final Textblock.Type_textblock parent = textblockin.parent();
        final Textblock.Type_textblock parenttgt = Textblock.f_textblock_findparent_from_textblock(parent);
        final Textblock.Type_textblock parentchg = Textblock.f_textblock_addchild_from_textblock_find_child(parent, parenttgt, tbchg);
        final Textblock.Type_delim delimright = Core.f_if_1(
          Textblock.t_delim,
          issingle,
          Core.f_new(
            Textblock.t_delim,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":delimlist"),
              delimcur.delimlist()
            )
          ),
          Core.f_empty(
            Textblock.t_delim
          )
        );
        return Core.f_copy(
          tbright,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":curpos"),
            Core.vx_new_int(0),
            Core.vx_new_string(":delim"),
            delimright,
            Core.vx_new_string(":parent"),
            parentchg
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_push_from_textblock_delim
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockin
   * @param  {delim} delimin
   * @return {textblock}
   * (func textblock-push<-textblock-delim)
   */
  public static interface Func_textblock_push_from_textblock_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_push_from_textblock_delim(final Textblock.Type_textblock textblockin, final Textblock.Type_delim delimin);
  }

  public static class Class_textblock_push_from_textblock_delim extends Core.Class_base implements Func_textblock_push_from_textblock_delim {

    @Override
    public Func_textblock_push_from_textblock_delim vx_new(Object... vals) {
      Class_textblock_push_from_textblock_delim output = new Class_textblock_push_from_textblock_delim();
      return output;
    }

    @Override
    public Func_textblock_push_from_textblock_delim vx_copy(Object... vals) {
      Class_textblock_push_from_textblock_delim output = new Class_textblock_push_from_textblock_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-push<-textblock-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_push_from_textblock_delim vx_empty() {return e_textblock_push_from_textblock_delim;}
    @Override
    public Func_textblock_push_from_textblock_delim vx_type() {return t_textblock_push_from_textblock_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockin = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delimin = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_push_from_textblock_delim(textblockin, delimin);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_push_from_textblock_delim(final Textblock.Type_textblock textblockin, final Textblock.Type_delim delimin) {
      return Textblock.f_textblock_push_from_textblock_delim(textblockin, delimin);
    }

  }

  public static final Func_textblock_push_from_textblock_delim e_textblock_push_from_textblock_delim = new Textblock.Class_textblock_push_from_textblock_delim();
  public static final Func_textblock_push_from_textblock_delim t_textblock_push_from_textblock_delim = new Textblock.Class_textblock_push_from_textblock_delim();

  public static Textblock.Type_textblock f_textblock_push_from_textblock_delim(final Textblock.Type_textblock textblockin, final Textblock.Type_delim delimin) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_if_2(
      Textblock.t_textblock,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_empty_1(delimin);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Textblock.f_textblock_push(textblockin);
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Textblock.t_textblock,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Core.Type_string text = textblockin.text();
                final Core.Type_int offset = textblockin.startpos();
                final Textblock.Type_delim delimcur = textblockin.delim();
                final Textblock.Type_textblock parent = textblockin.parent();
                final Core.Type_int startpos = delimin.startpos();
                final Core.Type_string starttext = delimin.starttext();
                final Core.Type_string endtext = delimin.endtext();
                final Core.Type_boolean issingle = Core.f_and(
                  Core.f_ne(Core.vx_new_string(""), starttext),
                  Core.f_eq(Core.vx_new_string(""), endtext)
                );
                final Textblock.Type_textblock tbleft = Textblock.f_textblock_startleft_from_string_delim_offset(text, delimin, offset);
                final Textblock.Type_delimlist delimsr = delimcur.delimlist();
                final Textblock.Type_delim delimr = Core.f_if_1(
                  Textblock.t_delim,
                  issingle,
                  Core.f_copy(
                    delimin,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":delimlist"),
                      delimsr
                    )
                  ),
                  delimin
                );
                final Textblock.Type_textblock tbright = Textblock.f_textblock_startright_from_string_delim_offset(text, delimr, offset);
                final Textblock.Type_textblock tbparent = Core.f_copy(
                  tbright,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":parent"),
                      Core.f_if_1(
                        Textblock.t_textblock,
                        Core.f_is_empty_1(parent),
                        textblockin,
                        parent
                      )
                  )
                );
                final Textblock.Type_delimlist delims = delimin.delimlist();
                final Textblock.Type_delim delimchg = Core.f_if_1(
                  Textblock.t_delim,
                  Core.f_is_empty_1(delims),
                  Core.f_empty(
                    Textblock.t_delim
                  ),
                  Core.f_new(
                    Textblock.t_delim,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":delimlist"),
                      delims
                    )
                  )
                );
                return Core.f_if_2(
                  Textblock.t_textblock,
                  Core.t_thenelselist.vx_new(
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        return Core.f_eq(Core.vx_new_int(0), startpos);
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        return tbparent;
                      })
                    ),
                    Core.f_else(
                      Core.t_any_from_func.vx_fn_new(() -> {
                        return Core.f_copy(
                          tbleft,
                          Core.t_anylist.vx_new(
                              Core.vx_new_string(":delim"),
                              delimchg,
                              Core.vx_new_string(":parent"),
                              tbparent
                          )
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
    return output;
  }

  /**
   * @function textblock_startleft_from_string_delim_offset
   * Returns a textblock constructed from the text before the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @param  {int} offset
   * @return {textblock}
   * (func textblock-startleft<-string-delim-offset)
   */
  public static interface Func_textblock_startleft_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset);
  }

  public static class Class_textblock_startleft_from_string_delim_offset extends Core.Class_base implements Func_textblock_startleft_from_string_delim_offset {

    @Override
    public Func_textblock_startleft_from_string_delim_offset vx_new(Object... vals) {
      Class_textblock_startleft_from_string_delim_offset output = new Class_textblock_startleft_from_string_delim_offset();
      return output;
    }

    @Override
    public Func_textblock_startleft_from_string_delim_offset vx_copy(Object... vals) {
      Class_textblock_startleft_from_string_delim_offset output = new Class_textblock_startleft_from_string_delim_offset();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startleft<-string-delim-offset", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_startleft_from_string_delim_offset vx_empty() {return e_textblock_startleft_from_string_delim_offset;}
    @Override
    public Func_textblock_startleft_from_string_delim_offset vx_type() {return t_textblock_startleft_from_string_delim_offset;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int offset = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset) {
      return Textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset);
    }

  }

  public static final Func_textblock_startleft_from_string_delim_offset e_textblock_startleft_from_string_delim_offset = new Textblock.Class_textblock_startleft_from_string_delim_offset();
  public static final Func_textblock_startleft_from_string_delim_offset t_textblock_startleft_from_string_delim_offset = new Textblock.Class_textblock_startleft_from_string_delim_offset();

  public static Textblock.Type_textblock f_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int startpos = delim.startpos();
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(text, Core.vx_new_string(""));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_lt(startpos, Core.vx_new_int(0));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":text"),
                      Type.f_string_from_string_start_end(text, Core.vx_new_int(0), startpos),
                      Core.vx_new_string(":startpos"),
                      offset,
                      Core.vx_new_string(":endpos"),
                      Core.f_plus(offset, startpos),
                      Core.vx_new_string(":curpos"),
                      Core.vx_new_int(0)
                  )
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
   * @function textblock_startright_from_string_delim_offset
   * Returns a textblock constructed from the text after the current delimiter start.
   * @param  {string} text
   * @param  {delim} delimin
   * @param  {int} offset
   * @return {textblock}
   * (func textblock-startright<-string-delim-offset)
   */
  public static interface Func_textblock_startright_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset);
  }

  public static class Class_textblock_startright_from_string_delim_offset extends Core.Class_base implements Func_textblock_startright_from_string_delim_offset {

    @Override
    public Func_textblock_startright_from_string_delim_offset vx_new(Object... vals) {
      Class_textblock_startright_from_string_delim_offset output = new Class_textblock_startright_from_string_delim_offset();
      return output;
    }

    @Override
    public Func_textblock_startright_from_string_delim_offset vx_copy(Object... vals) {
      Class_textblock_startright_from_string_delim_offset output = new Class_textblock_startright_from_string_delim_offset();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startright<-string-delim-offset", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_startright_from_string_delim_offset vx_empty() {return e_textblock_startright_from_string_delim_offset;}
    @Override
    public Func_textblock_startright_from_string_delim_offset vx_type() {return t_textblock_startright_from_string_delim_offset;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delimin = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int offset = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset) {
      return Textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset);
    }

  }

  public static final Func_textblock_startright_from_string_delim_offset e_textblock_startright_from_string_delim_offset = new Textblock.Class_textblock_startright_from_string_delim_offset();
  public static final Func_textblock_startright_from_string_delim_offset t_textblock_startright_from_string_delim_offset = new Textblock.Class_textblock_startright_from_string_delim_offset();

  public static Textblock.Type_textblock f_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int startpos = delimin.startpos();
        final Core.Type_string starttext = delimin.starttext();
        final Core.Type_string endtext = delimin.endtext();
        final Textblock.Type_delimlist delimlist = delimin.delimlist();
        final Textblock.Type_delim close = Core.f_if_2(
          Textblock.t_delim,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(endtext, Core.vx_new_string(""));
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_empty(
                    Textblock.t_delim
                  );
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_copy(
                    Textblock.c_delimclose,
                    Core.t_anylist.vx_new(
                        Core.vx_new_string(":starttext"),
                        endtext
                    )
                  );
                })
              )
          )
        );
        final Core.Type_int delimlen = Type.f_length_from_string(starttext);
        final Core.Type_int curpos = delimlen;
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(text, Core.vx_new_string(""));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_lt(startpos, Core.vx_new_int(0));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":text"),
                      Type.f_string_from_string_start(text, startpos),
                      Core.vx_new_string(":startpos"),
                      Core.f_plus(offset, startpos),
                      Core.vx_new_string(":curpos"),
                      curpos,
                      Core.vx_new_string(":delim"),
                      delimin,
                      Core.vx_new_string(":close"),
                      close
                  )
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
   * @function textblock_from_string_delim
   * Returns a textblock from a string and delim.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock<-string-delim)
   */
  public static interface Func_textblock_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_from_string_delim extends Core.Class_base implements Func_textblock_from_string_delim {

    @Override
    public Func_textblock_from_string_delim vx_new(Object... vals) {
      Class_textblock_from_string_delim output = new Class_textblock_from_string_delim();
      return output;
    }

    @Override
    public Func_textblock_from_string_delim vx_copy(Object... vals) {
      Class_textblock_from_string_delim output = new Class_textblock_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-string-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_from_string_delim vx_empty() {return e_textblock_from_string_delim;}
    @Override
    public Func_textblock_from_string_delim vx_type() {return t_textblock_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_textblock_from_string_delim(text, delim);
    }

  }

  public static final Func_textblock_from_string_delim e_textblock_from_string_delim = new Textblock.Class_textblock_from_string_delim();
  public static final Func_textblock_from_string_delim t_textblock_from_string_delim = new Textblock.Class_textblock_from_string_delim();

  public static Textblock.Type_textblock f_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_new(
      Textblock.t_textblock,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":text"),
        text,
        Core.vx_new_string(":delim"),
        delim,
        Core.vx_new_string(":startpos"),
        Core.vx_new_int(0),
        Core.vx_new_string(":endpos"),
        Type.f_length_from_string(text)
      )
    );
    return output;
  }

  /**
   * @function textblock_from_textblock_delim
   * Returns a parsed textblock from an unparsed one.
   * @param  {textblock} textblock
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock<-textblock-delim)
   */
  public static interface Func_textblock_from_textblock_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_from_textblock_delim extends Core.Class_base implements Func_textblock_from_textblock_delim {

    @Override
    public Func_textblock_from_textblock_delim vx_new(Object... vals) {
      Class_textblock_from_textblock_delim output = new Class_textblock_from_textblock_delim();
      return output;
    }

    @Override
    public Func_textblock_from_textblock_delim vx_copy(Object... vals) {
      Class_textblock_from_textblock_delim output = new Class_textblock_from_textblock_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-textblock-delim", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_from_textblock_delim vx_empty() {return e_textblock_from_textblock_delim;}
    @Override
    public Func_textblock_from_textblock_delim vx_type() {return t_textblock_from_textblock_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_textblock_delim(textblock, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim) {
      return Textblock.f_textblock_from_textblock_delim(textblock, delim);
    }

  }

  public static final Func_textblock_from_textblock_delim e_textblock_from_textblock_delim = new Textblock.Class_textblock_from_textblock_delim();
  public static final Func_textblock_from_textblock_delim t_textblock_from_textblock_delim = new Textblock.Class_textblock_from_textblock_delim();

  public static Textblock.Type_textblock f_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    return output;
  }


  static {
    Const_delimbracketangle.const_new(c_delimbracketangle);
    Const_delimbracketcurly.const_new(c_delimbracketcurly);
    Const_delimbracketsquare.const_new(c_delimbracketsquare);
    Const_delimclose.const_new(c_delimclose);
    Const_delimcomma.const_new(c_delimcomma);
    Const_delimcomment.const_new(c_delimcomment);
    Const_delimcommentblock.const_new(c_delimcommentblock);
    Const_delimline.const_new(c_delimline);
    Const_delimnonwhitespace.const_new(c_delimnonwhitespace);
    Const_delimparen.const_new(c_delimparen);
    Const_delimquote.const_new(c_delimquote);
    Const_delimquoteblock.const_new(c_delimquoteblock);
    Const_delimspace.const_new(c_delimspace);
    Const_delimtext.const_new(c_delimtext);
    Const_delimwhitespace.const_new(c_delimwhitespace);
  }

}
