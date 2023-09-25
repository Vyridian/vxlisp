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
    public Core.Type_int line();
    public Core.Type_int column();
    public Textblock.Type_delim delim();
    public Textblock.Type_textblocklist textblocks();
    public Textblock.Type_textblock parent();
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

    protected Textblock.Type_textblocklist vx_p_textblocks;

    @Override
    public Textblock.Type_textblocklist textblocks() {
      return this.vx_p_textblocks == null ? Textblock.e_textblocklist : this.vx_p_textblocks;
    }

    protected Textblock.Type_textblock vx_p_parent;

    @Override
    public Textblock.Type_textblock parent() {
      return this.vx_p_parent == null ? Textblock.e_textblock : this.vx_p_parent;
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
      case ":line":
        output = this.line();
        break;
      case ":column":
        output = this.column();
        break;
      case ":delim":
        output = this.delim();
        break;
      case ":textblocks":
        output = this.textblocks();
        break;
      case ":parent":
        output = this.parent();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":text", this.text());
      output.put(":line", this.line());
      output.put(":column", this.column());
      output.put(":delim", this.delim());
      output.put(":textblocks", this.textblocks());
      output.put(":parent", this.parent());
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
      output.vx_p_line = val.line();
      output.vx_p_column = val.column();
      output.vx_p_delim = val.delim();
      output.vx_p_textblocks = val.textblocks();
      output.vx_p_parent = val.parent();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":text");
      validkeys.add(":line");
      validkeys.add(":column");
      validkeys.add(":delim");
      validkeys.add(":textblocks");
      validkeys.add(":parent");
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
          case ":textblocks":
            if (valsub instanceof Textblock.Type_textblocklist) {
              output.vx_p_textblocks = (Textblock.Type_textblocklist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new textblock :textblocks " + valsub.toString() + ") - Invalid Value");
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
                Core.vx_new_string(","),
                Core.vx_new_string(":endtext"),
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
                Core.vx_new_string("\n"),
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
   * Constant: delimparenline
   * Parenthesis with newline Delimiter
   * {delim}
   */
  public static class Const_delimparenline extends Textblock.Class_delim {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimparenline", // name
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

    public static void const_new(Const_delimparenline output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimparenline"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("\n("),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string(")\n")
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

  public static final Const_delimparenline c_delimparenline = new Const_delimparenline();


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
                Core.vx_new_string("\""),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("\"")
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
   * @function delim_first_from_string_delimlist
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delim}
   * (func delim-first<-string-delimlist)
   */
  public static interface Func_delim_first_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim f_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_delim_first_from_string_delimlist extends Core.Class_base implements Func_delim_first_from_string_delimlist {

    @Override
    public Func_delim_first_from_string_delimlist vx_new(Object... vals) {
      Class_delim_first_from_string_delimlist output = new Class_delim_first_from_string_delimlist();
      return output;
    }

    @Override
    public Func_delim_first_from_string_delimlist vx_copy(Object... vals) {
      Class_delim_first_from_string_delimlist output = new Class_delim_first_from_string_delimlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist", // name
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
    public Func_delim_first_from_string_delimlist vx_empty() {return e_delim_first_from_string_delimlist;}
    @Override
    public Func_delim_first_from_string_delimlist vx_type() {return t_delim_first_from_string_delimlist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_first_from_string_delimlist(text, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      return Textblock.f_delim_first_from_string_delimlist(text, delimlist);
    }

  }

  public static final Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();
  public static final Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();

  public static Textblock.Type_delim f_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delimlist resolvedlist = Textblock.f_delimlist_startpos_from_string_delimlist(text, delimlist);
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
    return output;
  }

  /**
   * @function delim_startpos_from_string_delim
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @return {delim}
   * (func delim-startpos<-string-delim)
   */
  public static interface Func_delim_startpos_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim f_delim_startpos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_delim_startpos_from_string_delim extends Core.Class_base implements Func_delim_startpos_from_string_delim {

    @Override
    public Func_delim_startpos_from_string_delim vx_new(Object... vals) {
      Class_delim_startpos_from_string_delim output = new Class_delim_startpos_from_string_delim();
      return output;
    }

    @Override
    public Func_delim_startpos_from_string_delim vx_copy(Object... vals) {
      Class_delim_startpos_from_string_delim output = new Class_delim_startpos_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-startpos<-string-delim", // name
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
    public Func_delim_startpos_from_string_delim vx_empty() {return e_delim_startpos_from_string_delim;}
    @Override
    public Func_delim_startpos_from_string_delim vx_type() {return t_delim_startpos_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_startpos_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_delim f_delim_startpos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_delim_startpos_from_string_delim(text, delim);
    }

  }

  public static final Func_delim_startpos_from_string_delim e_delim_startpos_from_string_delim = new Textblock.Class_delim_startpos_from_string_delim();
  public static final Func_delim_startpos_from_string_delim t_delim_startpos_from_string_delim = new Textblock.Class_delim_startpos_from_string_delim();

  public static Textblock.Type_delim f_delim_startpos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string find = delim.starttext();
        final Core.Type_int pos = Core.f_if_2(
          Core.t_int,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(find, Core.vx_new_string(""));
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(-1);
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Type.f_int_from_string_findkeyword(text, find);
                })
              )
          )
        );
        return Core.f_copy(
          delim,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":startpos"),
            pos
          )
        );
      })
    );
    return output;
  }

  /**
   * @function delimlist_startpos_from_string_delimlist
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delimlist}
   * (func delimlist-startpos<-string-delimlist)
   */
  public static interface Func_delimlist_startpos_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delimlist f_delimlist_startpos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_delimlist_startpos_from_string_delimlist extends Core.Class_base implements Func_delimlist_startpos_from_string_delimlist {

    @Override
    public Func_delimlist_startpos_from_string_delimlist vx_new(Object... vals) {
      Class_delimlist_startpos_from_string_delimlist output = new Class_delimlist_startpos_from_string_delimlist();
      return output;
    }

    @Override
    public Func_delimlist_startpos_from_string_delimlist vx_copy(Object... vals) {
      Class_delimlist_startpos_from_string_delimlist output = new Class_delimlist_startpos_from_string_delimlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-startpos<-string-delimlist", // name
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
    public Func_delimlist_startpos_from_string_delimlist vx_empty() {return e_delimlist_startpos_from_string_delimlist;}
    @Override
    public Func_delimlist_startpos_from_string_delimlist vx_type() {return t_delimlist_startpos_from_string_delimlist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delimlist_startpos_from_string_delimlist(text, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_delimlist f_delimlist_startpos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      return Textblock.f_delimlist_startpos_from_string_delimlist(text, delimlist);
    }

  }

  public static final Func_delimlist_startpos_from_string_delimlist e_delimlist_startpos_from_string_delimlist = new Textblock.Class_delimlist_startpos_from_string_delimlist();
  public static final Func_delimlist_startpos_from_string_delimlist t_delimlist_startpos_from_string_delimlist = new Textblock.Class_delimlist_startpos_from_string_delimlist();

  public static Textblock.Type_delimlist f_delimlist_startpos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_delimlist output = Textblock.e_delimlist;
    output = Core.f_list_from_list(
      Textblock.t_delimlist,
      delimlist,
      Core.t_any_from_any.vx_fn_new((delim_any) -> {
        Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, delim_any);
        return 
          Textblock.f_delim_startpos_from_string_delim(text, delim);
      })
    );
    return output;
  }

  /**
   * @function stringlist_from_textblocklist
   * Returns the child textblocks from a given textblock.
   * @param  {textblocklist} textblocks
   * @return {stringlist}
   * (func stringlist<-textblocklist)
   */
  public static interface Func_stringlist_from_textblocklist extends Core.Func_any_from_any {
    public Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocks);
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
      Textblock.Type_textblocklist textblocks = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_stringlist_from_textblocklist(textblocks);
      return output;
    }

    @Override
    public Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocks) {
      return Textblock.f_stringlist_from_textblocklist(textblocks);
    }

  }

  public static final Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();
  public static final Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();

  public static Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocks) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_list_from_list(
      Core.t_stringlist,
      textblocks,
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
   * @function textblock_firstdelim_from_textblock_delimlist
   * Returns textblock with delim with lowest startpos found in text.
   * @param  {textblock} textblock
   * @param  {delimlist} delimlist
   * @return {textblock}
   * (func textblock-firstdelim<-textblock-delimlist)
   */
  public static interface Func_textblock_firstdelim_from_textblock_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_firstdelim_from_textblock_delimlist(final Textblock.Type_textblock textblock, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_textblock_firstdelim_from_textblock_delimlist extends Core.Class_base implements Func_textblock_firstdelim_from_textblock_delimlist {

    @Override
    public Func_textblock_firstdelim_from_textblock_delimlist vx_new(Object... vals) {
      Class_textblock_firstdelim_from_textblock_delimlist output = new Class_textblock_firstdelim_from_textblock_delimlist();
      return output;
    }

    @Override
    public Func_textblock_firstdelim_from_textblock_delimlist vx_copy(Object... vals) {
      Class_textblock_firstdelim_from_textblock_delimlist output = new Class_textblock_firstdelim_from_textblock_delimlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-firstdelim<-textblock-delimlist", // name
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
    public Func_textblock_firstdelim_from_textblock_delimlist vx_empty() {return e_textblock_firstdelim_from_textblock_delimlist;}
    @Override
    public Func_textblock_firstdelim_from_textblock_delimlist vx_type() {return t_textblock_firstdelim_from_textblock_delimlist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_firstdelim_from_textblock_delimlist(textblock, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_firstdelim_from_textblock_delimlist(final Textblock.Type_textblock textblock, final Textblock.Type_delimlist delimlist) {
      return Textblock.f_textblock_firstdelim_from_textblock_delimlist(textblock, delimlist);
    }

  }

  public static final Func_textblock_firstdelim_from_textblock_delimlist e_textblock_firstdelim_from_textblock_delimlist = new Textblock.Class_textblock_firstdelim_from_textblock_delimlist();
  public static final Func_textblock_firstdelim_from_textblock_delimlist t_textblock_firstdelim_from_textblock_delimlist = new Textblock.Class_textblock_firstdelim_from_textblock_delimlist();

  public static Textblock.Type_textblock f_textblock_firstdelim_from_textblock_delimlist(final Textblock.Type_textblock textblock, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblock.text();
        final Textblock.Type_delim delim = Textblock.f_delim_first_from_string_delimlist(text, delimlist);
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(delim);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return textblock;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_let(
                  Textblock.t_textblock,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    final Textblock.Type_textblock textblockbefore = Textblock.f_textblock_startbefore_from_string_delim(text, delim);
                    final Textblock.Type_textblock textblockafter = Textblock.f_textblock_startafter_from_string_delim(text, delim);
                    final Textblock.Type_textblocklist textblocks = textblock.textblocks();
                    final Textblock.Type_textblocklist addtextblocks = Core.f_if_2(
                      Textblock.t_textblocklist,
                      Core.t_thenelselist.vx_new(
                          Core.f_then(
                            Core.t_boolean_from_func.vx_fn_new(() -> {
                              return Core.f_is_empty_1(textblockbefore);
                            }),
                            Core.t_any_from_func.vx_fn_new(() -> {
                              return textblocks;
                            })
                          ),
                          Core.f_then(
                            Core.t_boolean_from_func.vx_fn_new(() -> {
                              return Core.f_is_empty_1(textblocks);
                            }),
                            Core.t_any_from_func.vx_fn_new(() -> {
                              return Core.f_new(
                                Textblock.t_textblocklist,
                                Core.t_anylist.vx_new(
                                    textblockbefore
                                )
                              );
                            })
                          ),
                          Core.f_else(
                            Core.t_any_from_func.vx_fn_new(() -> {
                              return Core.f_copy(textblocks, Core.t_anylist.vx_new(
                                textblockbefore));
                            })
                          )
                      )
                    );
                    final Textblock.Type_textblock parent = Core.f_copy(
                      textblock,
                      Core.t_anylist.vx_new(
                          Core.vx_new_string(":textblocks"),
                          addtextblocks
                      )
                    );
                    return Core.f_copy(
                      textblockafter,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":delim"),
                        delim,
                        Core.vx_new_string(":parent"),
                        parent
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
   * @function textblock_startafter_from_string_delim
   * Returns a textblock constructed from the text after the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock-startafter<-string-delim)
   */
  public static interface Func_textblock_startafter_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_startafter_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_startafter_from_string_delim extends Core.Class_base implements Func_textblock_startafter_from_string_delim {

    @Override
    public Func_textblock_startafter_from_string_delim vx_new(Object... vals) {
      Class_textblock_startafter_from_string_delim output = new Class_textblock_startafter_from_string_delim();
      return output;
    }

    @Override
    public Func_textblock_startafter_from_string_delim vx_copy(Object... vals) {
      Class_textblock_startafter_from_string_delim output = new Class_textblock_startafter_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startafter<-string-delim", // name
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
    public Func_textblock_startafter_from_string_delim vx_empty() {return e_textblock_startafter_from_string_delim;}
    @Override
    public Func_textblock_startafter_from_string_delim vx_type() {return t_textblock_startafter_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_startafter_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_startafter_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_textblock_startafter_from_string_delim(text, delim);
    }

  }

  public static final Func_textblock_startafter_from_string_delim e_textblock_startafter_from_string_delim = new Textblock.Class_textblock_startafter_from_string_delim();
  public static final Func_textblock_startafter_from_string_delim t_textblock_startafter_from_string_delim = new Textblock.Class_textblock_startafter_from_string_delim();

  public static Textblock.Type_textblock f_textblock_startafter_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int startpos = delim.startpos();
        final Core.Type_string starttext = delim.starttext();
        final Core.Type_int delimlen = Type.f_length_from_string(starttext);
        final Core.Type_int beginpos = Core.f_plus(startpos, delimlen);
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
                      Type.f_string_from_string_start(text, beginpos)
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
   * @function textblock_startbefore_from_string_delim
   * Returns a textblock constructed from the text before the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock-startbefore<-string-delim)
   */
  public static interface Func_textblock_startbefore_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_textblock_startbefore_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_startbefore_from_string_delim extends Core.Class_base implements Func_textblock_startbefore_from_string_delim {

    @Override
    public Func_textblock_startbefore_from_string_delim vx_new(Object... vals) {
      Class_textblock_startbefore_from_string_delim output = new Class_textblock_startbefore_from_string_delim();
      return output;
    }

    @Override
    public Func_textblock_startbefore_from_string_delim vx_copy(Object... vals) {
      Class_textblock_startbefore_from_string_delim output = new Class_textblock_startbefore_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startbefore<-string-delim", // name
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
    public Func_textblock_startbefore_from_string_delim vx_empty() {return e_textblock_startbefore_from_string_delim;}
    @Override
    public Func_textblock_startbefore_from_string_delim vx_type() {return t_textblock_startbefore_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_startbefore_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_textblock_startbefore_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_textblock_startbefore_from_string_delim(text, delim);
    }

  }

  public static final Func_textblock_startbefore_from_string_delim e_textblock_startbefore_from_string_delim = new Textblock.Class_textblock_startbefore_from_string_delim();
  public static final Func_textblock_startbefore_from_string_delim t_textblock_startbefore_from_string_delim = new Textblock.Class_textblock_startbefore_from_string_delim();

  public static Textblock.Type_textblock f_textblock_startbefore_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
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
                      Type.f_string_from_string_start_end(text, Core.vx_new_int(0), startpos)
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

  /**
   * @function textblocks_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} block
   * @return {textblocklist}
   * (func textblocks<-textblock)
   */
  public static interface Func_textblocks_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblocklist f_textblocks_from_textblock(final Textblock.Type_textblock block);
  }

  public static class Class_textblocks_from_textblock extends Core.Class_base implements Func_textblocks_from_textblock {

    @Override
    public Func_textblocks_from_textblock vx_new(Object... vals) {
      Class_textblocks_from_textblock output = new Class_textblocks_from_textblock();
      return output;
    }

    @Override
    public Func_textblocks_from_textblock vx_copy(Object... vals) {
      Class_textblocks_from_textblock output = new Class_textblocks_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocks<-textblock", // name
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
    public Func_textblocks_from_textblock vx_empty() {return e_textblocks_from_textblock;}
    @Override
    public Func_textblocks_from_textblock vx_type() {return t_textblocks_from_textblock;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblocks_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblocks_from_textblock(block);
      return output;
    }

    @Override
    public Textblock.Type_textblocklist f_textblocks_from_textblock(final Textblock.Type_textblock block) {
      return Textblock.f_textblocks_from_textblock(block);
    }

  }

  public static final Func_textblocks_from_textblock e_textblocks_from_textblock = new Textblock.Class_textblocks_from_textblock();
  public static final Func_textblocks_from_textblock t_textblocks_from_textblock = new Textblock.Class_textblocks_from_textblock();

  public static Textblock.Type_textblocklist f_textblocks_from_textblock(final Textblock.Type_textblock block) {
    Textblock.Type_textblocklist output = Textblock.e_textblocklist;
    output = block.textblocks();
    return output;
  }


  static {
    Const_delimbracketcurly.const_new(c_delimbracketcurly);
    Const_delimbracketsquare.const_new(c_delimbracketsquare);
    Const_delimclose.const_new(c_delimclose);
    Const_delimcomma.const_new(c_delimcomma);
    Const_delimcomment.const_new(c_delimcomment);
    Const_delimcommentblock.const_new(c_delimcommentblock);
    Const_delimline.const_new(c_delimline);
    Const_delimnonwhitespace.const_new(c_delimnonwhitespace);
    Const_delimparen.const_new(c_delimparen);
    Const_delimparenline.const_new(c_delimparenline);
    Const_delimquote.const_new(c_delimquote);
    Const_delimquoteblock.const_new(c_delimquoteblock);
    Const_delimspace.const_new(c_delimspace);
    Const_delimtext.const_new(c_delimtext);
    Const_delimwhitespace.const_new(c_delimwhitespace);
  }

}
