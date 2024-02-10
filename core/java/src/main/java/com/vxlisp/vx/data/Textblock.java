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
    public Core.Type_int pos();
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

    protected Core.Type_int vx_p_pos;

    @Override
    public Core.Type_int pos() {
      return this.vx_p_pos == null ? Core.e_int : this.vx_p_pos;
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
      case ":pos":
        output = this.pos();
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
      output.put(":pos", this.pos());
      output.put(":delimlist", this.delimlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_delim vx_new(final Object... vals) {return e_delim.vx_copy(vals);}

    @Override
    public Type_delim vx_copy(final Object... vals) {
      Type_delim output = this;
      boolean ischanged = false;
      Class_delim val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Core.Type_string vx_p_starttext = val.starttext();
      Core.Type_string vx_p_endtext = val.endtext();
      Core.Type_int vx_p_pos = val.pos();
      Textblock.Type_delimlist vx_p_delimlist = val.delimlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":starttext");
      validkeys.add(":endtext");
      validkeys.add(":pos");
      validkeys.add(":delimlist");
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
            msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":starttext":
            if (valsub == vx_p_starttext) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_starttext = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_starttext = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("starttext"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":endtext":
            if (valsub == vx_p_endtext) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_endtext = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_endtext = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("endtext"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":pos":
            if (valsub == vx_p_pos) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_pos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_pos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":delimlist":
            if (valsub == vx_p_delimlist) {
            } else if (valsub instanceof Textblock.Type_delimlist) {
              ischanged = true;
              vx_p_delimlist = (Textblock.Type_delimlist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("delimlist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_delim work = new Class_delim();
        work.vx_p_name = vx_p_name;
        work.vx_p_starttext = vx_p_starttext;
        work.vx_p_endtext = vx_p_endtext;
        work.vx_p_pos = vx_p_pos;
        work.vx_p_delimlist = vx_p_delimlist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
      Type_delimlist output = this;
      boolean ischanged = false;
      Class_delimlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Textblock.Type_delim> listval = new ArrayList<>(val.vx_listdelim());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Textblock.Type_delim) {
          ischanged = true;
          listval.add((Textblock.Type_delim)valsub);
        } else if (valsub instanceof Textblock.Type_delim) {
          ischanged = true;
          listval.add((Textblock.Type_delim)valsub);
        } else if (valsub instanceof Type_delimlist) {
          Type_delimlist multi = (Type_delimlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdelim());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Textblock.Type_delim) {
              Textblock.Type_delim valitem = (Textblock.Type_delim)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_delimlist work = new Class_delimlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
      Type_textblock output = this;
      boolean ischanged = false;
      Class_textblock val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Core.Type_string vx_p_text = val.text();
      Core.Type_int vx_p_startpos = val.startpos();
      Core.Type_int vx_p_endpos = val.endpos();
      Core.Type_int vx_p_curpos = val.curpos();
      Core.Type_int vx_p_line = val.line();
      Core.Type_int vx_p_column = val.column();
      Textblock.Type_delim vx_p_delim = val.delim();
      Textblock.Type_delim vx_p_close = val.close();
      Textblock.Type_textblock vx_p_parent = val.parent();
      Textblock.Type_textblocklist vx_p_children = val.children();
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
            msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":startpos":
            if (valsub == vx_p_startpos) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_startpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_startpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("startpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":endpos":
            if (valsub == vx_p_endpos) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_endpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_endpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("endpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":curpos":
            if (valsub == vx_p_curpos) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_curpos = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_curpos = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("curpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":line":
            if (valsub == vx_p_line) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_line = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_line = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("line"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":column":
            if (valsub == vx_p_column) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_column = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_column = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("column"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":delim":
            if (valsub == vx_p_delim) {
            } else if (valsub instanceof Textblock.Type_delim) {
              ischanged = true;
              vx_p_delim = (Textblock.Type_delim)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("delim"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":close":
            if (valsub == vx_p_close) {
            } else if (valsub instanceof Textblock.Type_delim) {
              ischanged = true;
              vx_p_close = (Textblock.Type_delim)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("close"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":parent":
            if (valsub == vx_p_parent) {
            } else if (valsub instanceof Textblock.Type_textblock) {
              ischanged = true;
              vx_p_parent = (Textblock.Type_textblock)valsub;
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
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":children":
            if (valsub == vx_p_children) {
            } else if (valsub instanceof Textblock.Type_textblocklist) {
              ischanged = true;
              vx_p_children = (Textblock.Type_textblocklist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("children"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_textblock work = new Class_textblock();
        work.vx_p_name = vx_p_name;
        work.vx_p_text = vx_p_text;
        work.vx_p_startpos = vx_p_startpos;
        work.vx_p_endpos = vx_p_endpos;
        work.vx_p_curpos = vx_p_curpos;
        work.vx_p_line = vx_p_line;
        work.vx_p_column = vx_p_column;
        work.vx_p_delim = vx_p_delim;
        work.vx_p_close = vx_p_close;
        work.vx_p_parent = vx_p_parent;
        work.vx_p_children = vx_p_children;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
      Type_textblocklist output = this;
      boolean ischanged = false;
      Class_textblocklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Textblock.Type_textblock> listval = new ArrayList<>(val.vx_listtextblock());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Textblock.Type_textblock) {
          ischanged = true;
          listval.add((Textblock.Type_textblock)valsub);
        } else if (valsub instanceof Textblock.Type_textblock) {
          ischanged = true;
          listval.add((Textblock.Type_textblock)valsub);
        } else if (valsub instanceof Type_textblocklist) {
          Type_textblocklist multi = (Type_textblocklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtextblock());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Textblock.Type_textblock) {
              Textblock.Type_textblock valitem = (Textblock.Type_textblock)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_textblocklist work = new Class_textblocklist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
  public static class Const_delimbracketangle extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketangle c_delimbracketangle = new Const_delimbracketangle();


  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketcurly extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketcurly c_delimbracketcurly = new Const_delimbracketcurly();


  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketsquare extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimbracketsquare c_delimbracketsquare = new Const_delimbracketsquare();


  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  public static class Const_delimclose extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
                Core.vx_new_string("delimclose")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimclose c_delimclose = new Const_delimclose();


  /**
   * Constant: delimclosing
   * A placeholder delimiter used to mark the closing of whatever is the current delimiter.
   * {delim}
   */
  public static class Const_delimclosing extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclosing", // name
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

    public static void const_new(Const_delimclosing output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimclosing")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimclosing c_delimclosing = new Const_delimclosing();


  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  public static class Const_delimcomma extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcomma c_delimcomma = new Const_delimcomma();


  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  public static class Const_delimcomment extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcomment c_delimcomment = new Const_delimcomment();


  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  public static class Const_delimcommentblock extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimcommentblock c_delimcommentblock = new Const_delimcommentblock();


  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  public static class Const_delimline extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimline c_delimline = new Const_delimline();


  /**
   * Constant: delimlisttest1
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest1 extends Textblock.Class_delimlist implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest1", // name
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
        )
      );
    }

    public static void const_new(Const_delimlisttest1 output) {
      Textblock.Type_delimlist val = Core.f_new(
        Textblock.t_delimlist,
        Core.t_anylist.vx_new(
                Textblock.c_delimtest2
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static final Const_delimlisttest1 c_delimlisttest1 = new Const_delimlisttest1();


  /**
   * Constant: delimlisttest2
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest2 extends Textblock.Class_delimlist implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest2", // name
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
        )
      );
    }

    public static void const_new(Const_delimlisttest2 output) {
      Textblock.Type_delimlist val = Core.f_new(
        Textblock.t_delimlist,
        Core.t_anylist.vx_new(
                Textblock.c_delimcomma,
                Textblock.c_delimtest3
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static final Const_delimlisttest2 c_delimlisttest2 = new Const_delimlisttest2();


  /**
   * Constant: delimlisttest3
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest3 extends Textblock.Class_delimlist implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest3", // name
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
        )
      );
    }

    public static void const_new(Const_delimlisttest3 output) {
      Textblock.Type_delimlist val = Core.f_new(
        Textblock.t_delimlist,
        Core.t_anylist.vx_new(
                Textblock.c_delimcomma,
                Textblock.c_delimwhitespace
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static final Const_delimlisttest3 c_delimlisttest3 = new Const_delimlisttest3();


  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  public static class Const_delimnonwhitespace extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimnonwhitespace c_delimnonwhitespace = new Const_delimnonwhitespace();


  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  public static class Const_delimparen extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimparen c_delimparen = new Const_delimparen();


  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  public static class Const_delimquote extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimquote c_delimquote = new Const_delimquote();


  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  public static class Const_delimquoteblock extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimquoteblock c_delimquoteblock = new Const_delimquoteblock();


  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  public static class Const_delimspace extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimspace c_delimspace = new Const_delimspace();


  /**
   * Constant: delimtest1
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest1 extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest1", // name
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

    public static void const_new(Const_delimtest1 output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                Textblock.c_delimlisttest1
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimtest1 c_delimtest1 = new Const_delimtest1();


  /**
   * Constant: delimtest2
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest2 extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest2", // name
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

    public static void const_new(Const_delimtest2 output) {
      Textblock.Type_delim val = Core.f_copy(
        Textblock.c_delimbracketangle,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                Textblock.c_delimlisttest2
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimtest2 c_delimtest2 = new Const_delimtest2();


  /**
   * Constant: delimtest3
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest3 extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest3", // name
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

    public static void const_new(Const_delimtest3 output) {
      Textblock.Type_delim val = Core.f_copy(
        Textblock.c_delimbracketcurly,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                Textblock.c_delimlisttest3
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimtest3 c_delimtest3 = new Const_delimtest3();


  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  public static class Const_delimtext extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimtext c_delimtext = new Const_delimtext();


  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  public static class Const_delimwhitespace extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
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
                Core.vx_new_string(":whitespace")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
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
    public Textblock.Type_textblocklist vx_children_from_textblock(final Textblock.Type_textblock textblock);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Textblock.Type_textblocklist vx_children_from_textblock(final Textblock.Type_textblock textblock) {
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
   * @function delim_first_from_delim_delim
   * Returns non-empty delim with lowest, non-negative startpos found in string.
   * @param  {delim} delim1
   * @param  {delim} delim2
   * @return {delim}
   * (func delim-first<-delim-delim)
   */
  public static interface Func_delim_first_from_delim_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2);
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
    public Textblock.Type_delim vx_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2) {
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
        final Core.Type_int pos1 = delim1.pos();
        final Core.Type_int pos2 = delim2.pos();
        return Core.f_if_2(
          Textblock.t_delim,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_int(0), pos2);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return delim1;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_int(0), pos1);
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
   * @function delim_first_from_string_delimlist
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delim}
   * (func delim-first<-string-delimlist)
   */
  public static interface Func_delim_first_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
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
    public Textblock.Type_delim vx_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      return Textblock.f_delim_first_from_string_delimlist(text, delimlist);
    }

  }

  public static final Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();
  public static final Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();

  public static Textblock.Type_delim f_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
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
                final Textblock.Type_delimlist resolvedlist = Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
                return Core.f_any_from_list_start_reduce(
                  Textblock.t_delim,
                  resolvedlist,
                  Core.f_empty(
                    Textblock.t_delim
                  ),
                  Core.t_any_from_reduce.vx_fn_new((Core.Type_any delim1_lmb_any, Core.Type_any delim2_lmb_any) -> {
                    Textblock.Type_delim delim1_lmb = Core.f_any_from_any(Textblock.t_delim, delim1_lmb_any);
                    Textblock.Type_delim delim2_lmb = Core.f_any_from_any(Textblock.t_delim, delim2_lmb_any);
                    Core.Type_any output_1 = Textblock.f_delim_first_from_delim_delim(delim1_lmb, delim2_lmb);
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
   * @function delim_pos_from_string_delim
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @return {delim}
   * (func delim-pos<-string-delim)
   */
  public static interface Func_delim_pos_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_delim_pos_from_string_delim extends Core.Class_base implements Func_delim_pos_from_string_delim {

    @Override
    public Func_delim_pos_from_string_delim vx_new(Object... vals) {
      Class_delim_pos_from_string_delim output = new Class_delim_pos_from_string_delim();
      return output;
    }

    @Override
    public Func_delim_pos_from_string_delim vx_copy(Object... vals) {
      Class_delim_pos_from_string_delim output = new Class_delim_pos_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim", // name
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
    public Func_delim_pos_from_string_delim vx_empty() {return e_delim_pos_from_string_delim;}
    @Override
    public Func_delim_pos_from_string_delim vx_type() {return t_delim_pos_from_string_delim;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_pos_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_delim vx_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      return Textblock.f_delim_pos_from_string_delim(text, delim);
    }

  }

  public static final Func_delim_pos_from_string_delim e_delim_pos_from_string_delim = new Textblock.Class_delim_pos_from_string_delim();
  public static final Func_delim_pos_from_string_delim t_delim_pos_from_string_delim = new Textblock.Class_delim_pos_from_string_delim();

  public static Textblock.Type_delim f_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string find = delim.starttext();
        final Core.Type_int pos = Type.f_int_from_string_findkeyword(text, find);
        return Core.f_if_2(
          Textblock.t_delim,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(pos, Core.vx_new_int(0));
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
                      Core.vx_new_string(":pos"),
                      pos
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
   * @function delimlist_pos_from_string_delimlist
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delimlist}
   * (func delimlist-pos<-string-delimlist)
   */
  public static interface Func_delimlist_pos_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_delimlist_pos_from_string_delimlist extends Core.Class_base implements Func_delimlist_pos_from_string_delimlist {

    @Override
    public Func_delimlist_pos_from_string_delimlist vx_new(Object... vals) {
      Class_delimlist_pos_from_string_delimlist output = new Class_delimlist_pos_from_string_delimlist();
      return output;
    }

    @Override
    public Func_delimlist_pos_from_string_delimlist vx_copy(Object... vals) {
      Class_delimlist_pos_from_string_delimlist output = new Class_delimlist_pos_from_string_delimlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
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
    public Func_delimlist_pos_from_string_delimlist vx_empty() {return e_delimlist_pos_from_string_delimlist;}
    @Override
    public Func_delimlist_pos_from_string_delimlist vx_type() {return t_delimlist_pos_from_string_delimlist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      return Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
    }

  }

  public static final Func_delimlist_pos_from_string_delimlist e_delimlist_pos_from_string_delimlist = new Textblock.Class_delimlist_pos_from_string_delimlist();
  public static final Func_delimlist_pos_from_string_delimlist t_delimlist_pos_from_string_delimlist = new Textblock.Class_delimlist_pos_from_string_delimlist();

  public static Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_delimlist output = Textblock.e_delimlist;
    output = Core.f_list_from_list(
      Textblock.t_delimlist,
      delimlist,
      Core.t_any_from_any.vx_fn_new((delim_any) -> {
        Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, delim_any);
        return 
          Textblock.f_delim_pos_from_string_delim(text, delim);
      })
    );
    return output;
  }

  /**
   * @function is_close
   * Return true if the given delim is a close delim.
   * @param  {delim} delimarg
   * @return {boolean}
   * (func is-close)
   */
  public static interface Func_is_close extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_close(final Textblock.Type_delim delimarg);
  }

  public static class Class_is_close extends Core.Class_base implements Func_is_close {

    @Override
    public Func_is_close vx_new(Object... vals) {
      Class_is_close output = new Class_is_close();
      return output;
    }

    @Override
    public Func_is_close vx_copy(Object... vals) {
      Class_is_close output = new Class_is_close();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-close", // name
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
    public Func_is_close vx_empty() {return e_is_close;}
    @Override
    public Func_is_close vx_type() {return t_is_close;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_delim inputval = (Textblock.Type_delim)value;
      Core.Type_any outputval = Textblock.f_is_close(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_is_close(delimarg);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_close(final Textblock.Type_delim delimarg) {
      return Textblock.f_is_close(delimarg);
    }

  }

  public static final Func_is_close e_is_close = new Textblock.Class_is_close();
  public static final Func_is_close t_is_close = new Textblock.Class_is_close();

  public static Core.Type_boolean f_is_close(final Textblock.Type_delim delimarg) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      delimarg.name(),
      Textblock.c_delimclose.name()
    );
    return output;
  }

  /**
   * @function is_single
   * Return true if the given delim is a single text delim.
   * @param  {delim} delimarg
   * @return {boolean}
   * (func is-single)
   */
  public static interface Func_is_single extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_single(final Textblock.Type_delim delimarg);
  }

  public static class Class_is_single extends Core.Class_base implements Func_is_single {

    @Override
    public Func_is_single vx_new(Object... vals) {
      Class_is_single output = new Class_is_single();
      return output;
    }

    @Override
    public Func_is_single vx_copy(Object... vals) {
      Class_is_single output = new Class_is_single();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-single", // name
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
    public Func_is_single vx_empty() {return e_is_single;}
    @Override
    public Func_is_single vx_type() {return t_is_single;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_delim inputval = (Textblock.Type_delim)value;
      Core.Type_any outputval = Textblock.f_is_single(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_is_single(delimarg);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_single(final Textblock.Type_delim delimarg) {
      return Textblock.f_is_single(delimarg);
    }

  }

  public static final Func_is_single e_is_single = new Textblock.Class_is_single();
  public static final Func_is_single t_is_single = new Textblock.Class_is_single();

  public static Core.Type_boolean f_is_single(final Textblock.Type_delim delimarg) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_and(
      Core.f_ne(
        Core.vx_new_string(""),
        delimarg.starttext()
      ),
      Core.f_eq(
        Core.vx_new_string(""),
        delimarg.endtext()
      )
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
    public Core.Type_stringlist vx_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Core.Type_stringlist vx_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist) {
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
    public Core.Type_string vx_text_from_textblock(final Textblock.Type_textblock block);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Core.Type_string vx_text_from_textblock(final Textblock.Type_textblock block) {
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
    public Textblock.Type_textblock vx_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child);
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
    public Textblock.Type_textblock vx_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child) {
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
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-delimnotfound)
   */
  public static interface Func_textblock_delimnotfound extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_delimnotfound(final Textblock.Type_textblock textblockarg);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_delimnotfound(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_delimnotfound(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_delimnotfound(final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_delimnotfound(textblockarg);
    }

  }

  public static final Func_textblock_delimnotfound e_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();
  public static final Func_textblock_delimnotfound t_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();

  public static Textblock.Type_textblock f_textblock_delimnotfound(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockarg.text();
        final Textblock.Type_delim delima = textblockarg.delim();
        final Textblock.Type_delim close = textblockarg.close();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Textblock.Type_textblocklist childp = parent.children();
        final Textblock.Type_delim delimp = parent.delim();
        final Textblock.Type_delimlist delims = delimp.delimlist();
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_not(
                  Core.f_is_empty_1(close)
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_let(
                  Textblock.t_textblock,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    final Core.Type_msg msgerr = Core.f_msg_from_error_1(Core.vx_new_string("closedelimmissing"), close);
                    final Textblock.Type_textblock child = Core.f_copy(
                      textblockarg,
                      Core.t_anylist.vx_new(
                          Core.vx_new_string(":delim"),
                          Core.f_empty(
                            Textblock.t_delim
                          ),
                          Core.vx_new_string(":close"),
                          Core.f_empty(
                            Textblock.t_delim
                          ),
                          Core.vx_new_string(":parent"),
                          Core.f_empty(
                            Textblock.t_textblock
                          )
                      )
                    );
                    final Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(parent);
                    final Textblock.Type_textblocklist childrenf = find.children();
                    final Textblock.Type_textblocklist childrenr = Core.f_copy(childrenf, Core.t_anylist.vx_new(
                      child));
                    final Textblock.Type_textblock replace = Core.f_copy(
                      find,
                      Core.t_anylist.vx_new(
                          msgerr,
                          Core.vx_new_string(":children"),
                          childrenr
                      )
                    );
                    final Textblock.Type_textblock parent2 = Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
                    final Textblock.Type_textblock gparent = parent2.parent();
                    final Textblock.Type_textblock parent3 = Core.f_copy(
                      parent2,
                      Core.t_anylist.vx_new(
                          Core.vx_new_string(":parent"),
                          Core.f_empty(
                            Textblock.t_textblock
                          )
                      )
                    );
                    final Textblock.Type_textblocklist childreng = gparent.children();
                    final Textblock.Type_textblocklist childrenc = Core.f_copy(childreng, Core.t_anylist.vx_new(
                      parent3));
                    return Core.f_copy(
                      gparent,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":children"),
                        childrenc,
                        msgerr
                      )
                    );
                  })
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(parent);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return textblockarg;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_let(
                  Textblock.t_textblock,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    final Textblock.Type_delim delimchg = Core.f_if_1(
                      Textblock.t_delim,
                      Core.f_is_empty_1(
                        delima.delimlist()
                      ),
                      delima,
                      Core.f_copy(
                        delima,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":delimlist"),
                          Core.f_empty(
                            Textblock.t_delimlist
                          )
                        )
                      )
                    );
                    final Textblock.Type_textblock child = Core.f_if_1(
                      Textblock.t_textblock,
                      Core.f_eq(Core.vx_new_string(""), text),
                      Core.f_empty(
                        Textblock.t_textblock
                      ),
                      Core.f_copy(
                        textblockarg,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":delim"),
                          delimchg,
                          Core.vx_new_string(":parent"),
                          Core.f_empty(
                            Textblock.t_textblock
                          )
                        )
                      )
                    );
                    final Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(parent);
                    final Textblock.Type_delim closef = find.close();
                    final Core.Type_boolean closing = Core.f_if(
                      Core.t_boolean,
                      Core.f_eqeq(
                        closef,
                        Textblock.c_delimclosing
                      ),
                      Core.vx_new_boolean(true)
                    );
                    return Core.f_if_2(
                      Textblock.t_textblock,
                      Core.t_thenelselist.vx_new(
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            return closing;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            return Core.f_let(
                              Textblock.t_textblock,
                              Core.t_any_from_func.vx_fn_new(() -> {
                                final Textblock.Type_textblock parent2 = find.parent();
                                final Textblock.Type_textblock find2 = Textblock.f_textblock_findparent_from_textblock(parent2);
                                final Textblock.Type_textblocklist children1 = Core.f_if_1(
                                  Textblock.t_textblocklist,
                                  Core.f_is_empty_1(child),
                                  find.children(),
                                  Core.f_copy(
                                    find.children(),
                                    Core.t_anylist.vx_new(
                                      child
                                    )
                                  )
                                );
                                final Textblock.Type_textblock replace1 = Core.f_copy(
                                  find,
                                  Core.t_anylist.vx_new(
                                      Core.vx_new_string(":close"),
                                      Core.f_empty(
                                        Textblock.t_delim
                                      ),
                                      Core.vx_new_string(":parent"),
                                      Core.f_empty(
                                        Textblock.t_textblock
                                      ),
                                      Core.vx_new_string(":children"),
                                      children1
                                  )
                                );
                                return Core.f_if_2(
                                  Textblock.t_textblock,
                                  Core.t_thenelselist.vx_new(
                                    Core.f_then(
                                      Core.t_boolean_from_func.vx_fn_new(() -> {
                                        return Core.f_is_empty_1(find2);
                                      }),
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        return Core.f_copy(
                                          parent,
                                          Core.t_anylist.vx_new(
                                              Core.vx_new_string(":parent"),
                                              Core.f_copy(
                                                parent2,
                                                Core.t_anylist.vx_new(
                                                  Core.vx_new_string(":children"),
                                                  Core.f_new(
                                                    Textblock.t_textblocklist,
                                                    Core.t_anylist.vx_new(
                                                      replace1
                                                    )
                                                  )
                                                )
                                              )
                                          )
                                        );
                                      })
                                    ),
                                    Core.f_else(
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        return Core.f_let(
                                          Textblock.t_textblock,
                                          Core.t_any_from_func.vx_fn_new(() -> {
                                            final Textblock.Type_textblocklist children2 = Core.f_copy(
                                              find2.children(),
                                              Core.t_anylist.vx_new(
                                                  replace1
                                              )
                                            );
                                            final Textblock.Type_textblock replace2 = Core.f_copy(
                                              find2,
                                              Core.t_anylist.vx_new(
                                                  Core.vx_new_string(":close"),
                                                  Core.f_empty(
                                                    Textblock.t_delim
                                                  ),
                                                  Core.vx_new_string(":children"),
                                                  children2
                                              )
                                            );
                                            final Textblock.Type_textblock replace = Textblock.f_textblock_replace_from_textblock_find_replace(parent2, find2, replace2);
                                            return Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
                                          })
                                        );
                                      })
                                    )
                                  )
                                );
                              })
                            );
                          })
                        ),
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            return Core.f_is_empty_1(child);
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            return parent;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            return Textblock.f_textblock_addchild_from_textblock_find_child(parent, find, child);
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
   * @function textblock_findparent_from_textblock
   * Find a parent that accepts a child.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-findparent<-textblock)
   */
  public static interface Func_textblock_findparent_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Textblock.Type_textblock vx_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg) {
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
                return Core.f_or(
                  Core.f_is_empty_1(parent),
                  Core.f_and(
                    Core.f_ne(Core.vx_new_string(""), starttext),
                    Core.f_ne(Core.vx_new_string(""), endtext)
                  )
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
   * @function textblock_init
   * Returns a textblock ready for parsing.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-init)
   */
  public static interface Func_textblock_init extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_init(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_init extends Core.Class_base implements Func_textblock_init {

    @Override
    public Func_textblock_init vx_new(Object... vals) {
      Class_textblock_init output = new Class_textblock_init();
      return output;
    }

    @Override
    public Func_textblock_init vx_copy(Object... vals) {
      Class_textblock_init output = new Class_textblock_init();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-init", // name
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
    public Func_textblock_init vx_empty() {return e_textblock_init;}
    @Override
    public Func_textblock_init vx_type() {return t_textblock_init;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_init(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_init(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_init(final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_init(textblockarg);
    }

  }

  public static final Func_textblock_init e_textblock_init = new Textblock.Class_textblock_init();
  public static final Func_textblock_init t_textblock_init = new Textblock.Class_textblock_init();

  public static Textblock.Type_textblock f_textblock_init(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockarg.text();
        final Core.Type_int startpos = Core.f_if_1(
          Core.t_int,
          Core.f_eq(Core.vx_new_string(""), text),
          Core.vx_new_int(0),
          Core.vx_new_int(1)
        );
        final Core.Type_int endpos = Core.f_if_1(
          Core.t_int,
          Core.f_eq(Core.vx_new_string(""), text),
          Core.vx_new_int(0),
          Type.f_length_from_string(text)
        );
        return Core.f_copy(
          textblockarg,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":startpos"),
            startpos,
            Core.vx_new_string(":endpos"),
            endpos,
            Core.vx_new_string(":parent"),
            Core.f_copy(
              textblockarg,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":startpos"),
                startpos,
                Core.vx_new_string(":endpos"),
                endpos,
                Core.vx_new_string(":delim"),
                Core.f_empty(
                  Textblock.t_delim
                )
              )
            )
          )
        );
      })
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
    public Textblock.Type_textblock vx_textblock_parse(final Textblock.Type_textblock textblock);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Textblock.Type_textblock vx_textblock_parse(final Textblock.Type_textblock textblock) {
      return Textblock.f_textblock_parse(textblock);
    }

  }

  public static final Func_textblock_parse e_textblock_parse = new Textblock.Class_textblock_parse();
  public static final Func_textblock_parse t_textblock_parse = new Textblock.Class_textblock_parse();

  public static Textblock.Type_textblock f_textblock_parse(final Textblock.Type_textblock textblock) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Collection.f_any_from_for_until_loop_max(
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
      }),
      Core.vx_new_int(100000)
    );
    return output;
  }

  /**
   * @function textblock_parse_one
   * Returns a textblock that has been parse a single level.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-parse-one)
   */
  public static interface Func_textblock_parse_one extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_parse_one(final Textblock.Type_textblock textblockarg);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_parse_one(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_parse_one(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_parse_one(final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_parse_one(textblockarg);
    }

  }

  public static final Func_textblock_parse_one e_textblock_parse_one = new Textblock.Class_textblock_parse_one();
  public static final Func_textblock_parse_one t_textblock_parse_one = new Textblock.Class_textblock_parse_one();

  public static Textblock.Type_textblock f_textblock_parse_one(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delimarg = textblockarg.delim();
        final Textblock.Type_delim close = textblockarg.close();
        final Core.Type_int startpos = textblockarg.startpos();
        final Core.Type_string textarg = textblockarg.text();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Core.Type_boolean is_init = Core.f_and(
          Core.f_is_empty_1(parent),
          Core.f_eq(startpos, Core.vx_new_int(0))
        );
        final Core.Type_string starttext = delimarg.starttext();
        final Core.Type_string endtext = delimarg.endtext();
        final Textblock.Type_delimlist delimlistarg = delimarg.delimlist();
        final Core.Type_int startposchg = Core.f_if_2(
          Core.t_int,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(Core.vx_new_string(""), textarg);
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return startpos;
                })
              ),
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(Core.vx_new_int(0), startpos);
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(1);
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return startpos;
                })
              )
          )
        );
        final Textblock.Type_delimlist delimlistcl = Core.f_if_1(
          Textblock.t_delimlist,
          Core.f_is_empty_1(close),
          delimlistarg,
          Core.f_copy(delimlistarg, Core.t_anylist.vx_new(
            close))
        );
        final Textblock.Type_delim delimfirst = Textblock.f_delim_first_from_string_delimlist(textarg, delimlistcl);
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return is_init;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_init(textblockarg);
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(parent);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return textblockarg;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(delimfirst);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_delimnotfound(textblockarg);
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Textblock.f_is_close(delimfirst);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_from_close_textblock(delimfirst, textblockarg);
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Textblock.f_is_single(delimfirst);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_from_single_textblock(delimfirst, textblockarg);
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Textblock.f_textblock_from_open_textblock(delimfirst, textblockarg);
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
    public Textblock.Type_textblock vx_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
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
    public Textblock.Type_textblock vx_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
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
   * @function textblock_replace_from_textblock_find_replace
   * Replace the given parent textblock.
   * @param  {textblock} textblockarg
   * @param  {textblock} find
   * @param  {textblock} replace
   * @return {textblock}
   * (func textblock-replace<-textblock-find-replace)
   */
  public static interface Func_textblock_replace_from_textblock_find_replace extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_replace_from_textblock_find_replace(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock replace);
  }

  public static class Class_textblock_replace_from_textblock_find_replace extends Core.Class_base implements Func_textblock_replace_from_textblock_find_replace {

    @Override
    public Func_textblock_replace_from_textblock_find_replace vx_new(Object... vals) {
      Class_textblock_replace_from_textblock_find_replace output = new Class_textblock_replace_from_textblock_find_replace();
      return output;
    }

    @Override
    public Func_textblock_replace_from_textblock_find_replace vx_copy(Object... vals) {
      Class_textblock_replace_from_textblock_find_replace output = new Class_textblock_replace_from_textblock_find_replace();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-replace<-textblock-find-replace", // name
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
    public Func_textblock_replace_from_textblock_find_replace vx_empty() {return e_textblock_replace_from_textblock_find_replace;}
    @Override
    public Func_textblock_replace_from_textblock_find_replace vx_type() {return t_textblock_replace_from_textblock_find_replace;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock find = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      Textblock.Type_textblock replace = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(2)));
      output = Textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_replace_from_textblock_find_replace(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock replace) {
      return Textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
    }

  }

  public static final Func_textblock_replace_from_textblock_find_replace e_textblock_replace_from_textblock_find_replace = new Textblock.Class_textblock_replace_from_textblock_find_replace();
  public static final Func_textblock_replace_from_textblock_find_replace t_textblock_replace_from_textblock_find_replace = new Textblock.Class_textblock_replace_from_textblock_find_replace();

  public static Textblock.Type_textblock f_textblock_replace_from_textblock_find_replace(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock replace) {
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
            return replace;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_copy(
              textblockarg,
              Core.t_anylist.vx_new(
                  Core.vx_new_string(":parent"),
                  Textblock.f_textblock_replace_from_textblock_find_replace(
                    textblockarg.parent(),
                    find,
                    replace
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
   * @function textblock_startleft_from_string_delim_offset
   * Returns a textblock constructed from the text before the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @param  {int} offset
   * @return {textblock}
   * (func textblock-startleft<-string-delim-offset)
   */
  public static interface Func_textblock_startleft_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset);
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
    public Textblock.Type_textblock vx_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset) {
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
        final Core.Type_int pos = delim.pos();
        final Core.Type_int start = Core.vx_new_int(1);
        final Core.Type_int end = Core.f_minus(pos, Core.vx_new_int(1));
        return Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_string(""), text);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_empty(
                  Textblock.t_textblock
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(Core.vx_new_int(0), pos);
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
                      Type.f_string_from_string_start_end(text, start, end),
                      Core.vx_new_string(":startpos"),
                      Core.f_plus(offset, start),
                      Core.vx_new_string(":endpos"),
                      Core.f_plus(offset, end),
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
    public Textblock.Type_textblock vx_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset);
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
    public Textblock.Type_textblock vx_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset) {
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
        final Core.Type_int startpos = delimin.pos();
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
        final Core.Type_int delimlen = Core.f_switch(
          Core.t_int,
          starttext,
          Core.t_thenelselist.vx_new(
              Core.f_case_1(
                Core.vx_new_string(":nonwhitespace"),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(0);
                })
              ),
              Core.f_case_1(
                Core.vx_new_string(":whitespace"),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(0);
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Type.f_length_from_string(starttext);
                })
              )
          )
        );
        final Core.Type_int curpos = Core.vx_new_int(0);
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
   * @function textblock_from_close_textblock
   * Returns a textblock after a close delim found.
   * @param  {delim} close
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock<-close-textblock)
   */
  public static interface Func_textblock_from_close_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_close_textblock extends Core.Class_base implements Func_textblock_from_close_textblock {

    @Override
    public Func_textblock_from_close_textblock vx_new(Object... vals) {
      Class_textblock_from_close_textblock output = new Class_textblock_from_close_textblock();
      return output;
    }

    @Override
    public Func_textblock_from_close_textblock vx_copy(Object... vals) {
      Class_textblock_from_close_textblock output = new Class_textblock_from_close_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-close-textblock", // name
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
    public Func_textblock_from_close_textblock vx_empty() {return e_textblock_from_close_textblock;}
    @Override
    public Func_textblock_from_close_textblock vx_type() {return t_textblock_from_close_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim close = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_close_textblock(close, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_from_close_textblock(close, textblockarg);
    }

  }

  public static final Func_textblock_from_close_textblock e_textblock_from_close_textblock = new Textblock.Class_textblock_from_close_textblock();
  public static final Func_textblock_from_close_textblock t_textblock_from_close_textblock = new Textblock.Class_textblock_from_close_textblock();

  public static Textblock.Type_textblock f_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockarg.text();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Core.Type_int startpos = textblockarg.startpos();
        final Core.Type_int endpos = textblockarg.endpos();
        final Core.Type_int pos = close.pos();
        final Core.Type_string textclose = close.starttext();
        final Core.Type_int lenclose = Type.f_length_from_string(textclose);
        final Core.Type_int posminus = Core.f_minus1(pos);
        final Core.Type_int startleft = startpos;
        final Core.Type_int startclose = Core.f_plus(startpos, posminus);
        final Core.Type_int endclose = Core.f_switch(
          Core.t_int,
          textclose,
          Core.t_thenelselist.vx_new(
              Core.f_case_1(
                Core.vx_new_string(":whitespace"),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Type.f_int_from_string_findkeyword(text, Core.vx_new_string(":nonwhitespace"));
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_plus(
                    Core.f_minus1(startclose),
                    lenclose
                  );
                })
              )
          )
        );
        final Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(Core.vx_new_int(1), pos),
          startclose,
          Core.f_minus1(startclose)
        );
        final Core.Type_int startright = Core.f_plus1(endclose);
        final Core.Type_int endright = Core.f_if_1(
          Core.t_int,
          Core.f_lt(endpos, startright),
          startright,
          endpos
        );
        final Core.Type_string textleft = Type.f_string_from_string_end(text, posminus);
        final Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(pos, lenclose)
        );
        final Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(parent);
        final Textblock.Type_delim closefind = find.close();
        final Core.Type_string textfind = find.text();
        final Core.Type_int startfind = find.startpos();
        final Textblock.Type_delim delimfind = find.delim();
        final Textblock.Type_delim delimright = Core.f_new(
          Textblock.t_delim,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":delimlist"),
              delimfind.delimlist()
          )
        );
        final Core.Type_int lenfind = Core.f_minus(
          Core.f_plus1(endclose),
          startfind
        );
        final Core.Type_string textreplace = Type.f_string_from_string_end(textfind, lenfind);
        final Textblock.Type_textblock replace = Core.f_copy(
          find,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":text"),
              textreplace,
              Core.vx_new_string(":endpos"),
              endclose,
              Core.vx_new_string(":delim"),
              Core.f_copy(
                delimfind,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":delimlist"),
                  Core.f_empty(
                    Textblock.t_delimlist
                  )
                )
              ),
              Core.vx_new_string(":close"),
              Textblock.c_delimclosing
          )
        );
        final Textblock.Type_textblock parentchg = Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
        return Core.f_new(
          Textblock.t_textblock,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":text"),
            textleft,
            Core.vx_new_string(":startpos"),
            startleft,
            Core.vx_new_string(":endpos"),
            endleft,
            Core.vx_new_string(":parent"),
            Core.f_copy(
              textblockarg,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":text"),
                textright,
                Core.vx_new_string(":startpos"),
                startright,
                Core.vx_new_string(":endpos"),
                endright,
                Core.vx_new_string(":delim"),
                delimright,
                Core.vx_new_string(":close"),
                closefind,
                Core.vx_new_string(":parent"),
                parentchg
              )
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_from_empty_textblock
   * Returns a textblock after an empty delim found.
   * @param  {delim} empty
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock<-empty-textblock)
   */
  public static interface Func_textblock_from_empty_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_empty_textblock(final Textblock.Type_delim empty, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_empty_textblock extends Core.Class_base implements Func_textblock_from_empty_textblock {

    @Override
    public Func_textblock_from_empty_textblock vx_new(Object... vals) {
      Class_textblock_from_empty_textblock output = new Class_textblock_from_empty_textblock();
      return output;
    }

    @Override
    public Func_textblock_from_empty_textblock vx_copy(Object... vals) {
      Class_textblock_from_empty_textblock output = new Class_textblock_from_empty_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-empty-textblock", // name
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
    public Func_textblock_from_empty_textblock vx_empty() {return e_textblock_from_empty_textblock;}
    @Override
    public Func_textblock_from_empty_textblock vx_type() {return t_textblock_from_empty_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim empty = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_empty_textblock(final Textblock.Type_delim empty, final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
    }

  }

  public static final Func_textblock_from_empty_textblock e_textblock_from_empty_textblock = new Textblock.Class_textblock_from_empty_textblock();
  public static final Func_textblock_from_empty_textblock t_textblock_from_empty_textblock = new Textblock.Class_textblock_from_empty_textblock();

  public static Textblock.Type_textblock f_textblock_from_empty_textblock(final Textblock.Type_delim empty, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    return output;
  }

  /**
   * @function textblock_from_open_textblock
   * Returns a textblock after a close delim found.
   * @param  {delim} open
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock<-open-textblock)
   */
  public static interface Func_textblock_from_open_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_open_textblock extends Core.Class_base implements Func_textblock_from_open_textblock {

    @Override
    public Func_textblock_from_open_textblock vx_new(Object... vals) {
      Class_textblock_from_open_textblock output = new Class_textblock_from_open_textblock();
      return output;
    }

    @Override
    public Func_textblock_from_open_textblock vx_copy(Object... vals) {
      Class_textblock_from_open_textblock output = new Class_textblock_from_open_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-open-textblock", // name
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
    public Func_textblock_from_open_textblock vx_empty() {return e_textblock_from_open_textblock;}
    @Override
    public Func_textblock_from_open_textblock vx_type() {return t_textblock_from_open_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim open = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_open_textblock(open, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_from_open_textblock(open, textblockarg);
    }

  }

  public static final Func_textblock_from_open_textblock e_textblock_from_open_textblock = new Textblock.Class_textblock_from_open_textblock();
  public static final Func_textblock_from_open_textblock t_textblock_from_open_textblock = new Textblock.Class_textblock_from_open_textblock();

  public static Textblock.Type_textblock f_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockarg.text();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Core.Type_int startpos = textblockarg.startpos();
        final Core.Type_int endpos = textblockarg.endpos();
        final Textblock.Type_delim delima = textblockarg.delim();
        final Core.Type_int pos = open.pos();
        final Core.Type_string textopen = open.starttext();
        final Core.Type_string textclose = open.endtext();
        final Textblock.Type_delimlist delimlistl = open.delimlist();
        final Core.Type_int lenopen = Type.f_length_from_string(textopen);
        final Core.Type_int posminus = Core.f_minus1(pos);
        final Core.Type_int startleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(pos, Core.vx_new_int(1)),
          Core.f_minus1(startpos),
          startpos
        );
        final Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(pos, Core.vx_new_int(1)),
          Core.f_minus1(startpos),
          Core.f_plus(
            Core.f_minus1(startleft),
            posminus
          )
        );
        final Core.Type_int startright = Core.f_plus_2(
          Core.t_intlist.vx_new(
              startpos,
              posminus,
              lenopen
          )
        );
        final Core.Type_int startopen = Core.f_plus(startpos, posminus);
        final Core.Type_string textleft = Type.f_string_from_string_end(text, posminus);
        final Core.Type_string textpar = Type.f_string_from_string_start(text, pos);
        final Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(pos, lenopen)
        );
        final Textblock.Type_delim close = Core.f_copy(
          Textblock.c_delimclose,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":starttext"),
              textclose
          )
        );
        final Textblock.Type_textblock tbleft = Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(Core.vx_new_string(""), textleft);
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
                        textleft,
                        Core.vx_new_string(":startpos"),
                        startleft,
                        Core.vx_new_string(":endpos"),
                        endleft
                    )
                  );
                })
              )
          )
        );
        final Textblock.Type_textblock tbpar1 = Core.f_copy(
          textblockarg,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":text"),
              textpar,
              Core.vx_new_string(":startpos"),
              startopen,
              Core.vx_new_string(":delim"),
              Core.f_copy(
                open,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":pos"),
                  Core.vx_new_int(0),
                  Core.vx_new_string(":delimlist"),
                  delima.delimlist()
                )
              ),
              Core.vx_new_string(":parent"),
              parent
          )
        );
        final Textblock.Type_textblock tbfind = Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(Core.vx_new_string(""), textleft);
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_empty(
                    Textblock.t_textblock
                  );
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Textblock.f_textblock_findparent_from_textblock(parent);
                })
              )
          )
        );
        final Textblock.Type_textblock tbparent = Core.f_if_2(
          Textblock.t_textblock,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_is_empty_1(tbfind);
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return tbpar1;
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Textblock.f_textblock_addchild_from_textblock_find_child(tbpar1, tbfind, tbleft);
                })
              )
          )
        );
        return Core.f_new(
          Textblock.t_textblock,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":text"),
            textright,
            Core.vx_new_string(":startpos"),
            startright,
            Core.vx_new_string(":endpos"),
            endpos,
            Core.vx_new_string(":delim"),
            Core.f_new(
              Textblock.t_delim,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            Core.vx_new_string(":close"),
            close,
            Core.vx_new_string(":parent"),
            tbparent
          )
        );
      })
    );
    return output;
  }

  /**
   * @function textblock_from_single_textblock
   * Returns a textblock after a single value delim found.
   * @param  {delim} single
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock<-single-textblock)
   */
  public static interface Func_textblock_from_single_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_single_textblock extends Core.Class_base implements Func_textblock_from_single_textblock {

    @Override
    public Func_textblock_from_single_textblock vx_new(Object... vals) {
      Class_textblock_from_single_textblock output = new Class_textblock_from_single_textblock();
      return output;
    }

    @Override
    public Func_textblock_from_single_textblock vx_copy(Object... vals) {
      Class_textblock_from_single_textblock output = new Class_textblock_from_single_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-single-textblock", // name
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
    public Func_textblock_from_single_textblock vx_empty() {return e_textblock_from_single_textblock;}
    @Override
    public Func_textblock_from_single_textblock vx_type() {return t_textblock_from_single_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim single = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_single_textblock(single, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg) {
      return Textblock.f_textblock_from_single_textblock(single, textblockarg);
    }

  }

  public static final Func_textblock_from_single_textblock e_textblock_from_single_textblock = new Textblock.Class_textblock_from_single_textblock();
  public static final Func_textblock_from_single_textblock t_textblock_from_single_textblock = new Textblock.Class_textblock_from_single_textblock();

  public static Textblock.Type_textblock f_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = textblockarg.text();
        final Textblock.Type_textblock parent = textblockarg.parent();
        final Core.Type_int startpos = textblockarg.startpos();
        final Core.Type_int endpos = textblockarg.endpos();
        final Core.Type_int pos = single.pos();
        final Core.Type_string origsingle = single.starttext();
        final Core.Type_string textsingle = Core.f_switch(
          Core.t_string,
          origsingle,
          Core.t_thenelselist.vx_new(
              Core.f_case_1(
                Core.vx_new_string(":whitespace"),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_let(
                    Core.t_string,
                    Core.t_any_from_func.vx_fn_new(() -> {
                      final Core.Type_string text2 = Type.f_string_from_string_start(text, pos);
                      final Core.Type_int pos2 = Type.f_int_from_string_findkeyword(text2, Core.vx_new_string(":nonwhitespace"));
                      final Core.Type_int pos3 = Core.f_if_2(
                        Core.t_int,
                        Core.t_thenelselist.vx_new(
                            Core.f_then(
                              Core.t_boolean_from_func.vx_fn_new(() -> {
                                return Core.f_eq(Core.vx_new_int(0), pos2);
                              }),
                              Core.t_any_from_func.vx_fn_new(() -> {
                                return Type.f_length_from_string(text2);
                              })
                            ),
                            Core.f_then(
                              Core.t_boolean_from_func.vx_fn_new(() -> {
                                return Core.f_eq(pos2, pos);
                              }),
                              Core.t_any_from_func.vx_fn_new(() -> {
                                return pos2;
                              })
                            ),
                            Core.f_else(
                              Core.t_any_from_func.vx_fn_new(() -> {
                                return Core.f_minus1(pos2);
                              })
                            )
                        )
                      );
                      return Type.f_string_from_string_start_end(text, pos, pos3);
                    })
                  );
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return origsingle;
                })
              )
          )
        );
        final Textblock.Type_delimlist delimlistl = single.delimlist();
        final Core.Type_int lensingle = Type.f_length_from_string(textsingle);
        final Core.Type_int posminus = Core.f_minus1(pos);
        final Core.Type_int startleft = startpos;
        final Core.Type_int startsingle = Core.f_plus(startpos, posminus);
        final Core.Type_int endsingle = Core.f_switch(
          Core.t_int,
          textsingle,
          Core.t_thenelselist.vx_new(
              Core.f_case_1(
                Core.vx_new_string(":whitespace"),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Type.f_int_from_string_findkeyword(text, Core.vx_new_string(":nonwhitespace"));
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_plus(
                    Core.f_minus1(startsingle),
                    lensingle
                  );
                })
              )
          )
        );
        final Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(startsingle, startpos),
          startsingle,
          Core.f_minus1(startsingle)
        );
        final Core.Type_int startright = Core.f_plus1(endsingle);
        final Core.Type_string textleft = Type.f_string_from_string_end(text, posminus);
        final Core.Type_string textpar = Type.f_string_from_string_start(text, pos);
        final Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(pos, lensingle)
        );
        return Core.f_new(
          Textblock.t_textblock,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":text"),
            textleft,
            Core.vx_new_string(":startpos"),
            startleft,
            Core.vx_new_string(":endpos"),
            endleft,
            Core.vx_new_string(":delim"),
            Core.f_new(
              Textblock.t_delim,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            Core.vx_new_string(":parent"),
            Core.f_new(
              Textblock.t_textblock,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":text"),
                textsingle,
                Core.vx_new_string(":startpos"),
                startsingle,
                Core.vx_new_string(":endpos"),
                endsingle,
                Core.vx_new_string(":delim"),
                Core.f_copy(
                  single,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":pos"),
                    Core.vx_new_int(0),
                    Core.vx_new_string(":delimlist"),
                    Core.f_empty(
                      Textblock.t_delimlist
                    )
                  )
                ),
                Core.vx_new_string(":parent"),
                Core.f_copy(
                  textblockarg,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    textright,
                    Core.vx_new_string(":startpos"),
                    startright,
                    Core.vx_new_string(":endpos"),
                    endpos
                  )
                )
              )
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
    public Textblock.Type_textblock vx_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
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
    public Textblock.Type_textblock vx_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
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
    public Textblock.Type_textblock vx_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim);
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
    public Textblock.Type_textblock vx_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim) {
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
   * @function textblocklist_from_textblocklist_remove
   * Return a textblocklist with all removedelims removed.
   * @param  {textblocklist} tblist
   * @param  {delim} remove
   * @return {textblocklist}
   * (func textblocklist<-textblocklist-remove)
   */
  public static interface Func_textblocklist_from_textblocklist_remove extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove);
  }

  public static class Class_textblocklist_from_textblocklist_remove extends Core.Class_base implements Func_textblocklist_from_textblocklist_remove {

    @Override
    public Func_textblocklist_from_textblocklist_remove vx_new(Object... vals) {
      Class_textblocklist_from_textblocklist_remove output = new Class_textblocklist_from_textblocklist_remove();
      return output;
    }

    @Override
    public Func_textblocklist_from_textblocklist_remove vx_copy(Object... vals) {
      Class_textblocklist_from_textblocklist_remove output = new Class_textblocklist_from_textblocklist_remove();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
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
    public Func_textblocklist_from_textblocklist_remove vx_empty() {return e_textblocklist_from_textblocklist_remove;}
    @Override
    public Func_textblocklist_from_textblocklist_remove vx_type() {return t_textblocklist_from_textblocklist_remove;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist tblist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim remove = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
      return output;
    }

    @Override
    public Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove) {
      return Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
    }

  }

  public static final Func_textblocklist_from_textblocklist_remove e_textblocklist_from_textblocklist_remove = new Textblock.Class_textblocklist_from_textblocklist_remove();
  public static final Func_textblocklist_from_textblocklist_remove t_textblocklist_from_textblocklist_remove = new Textblock.Class_textblocklist_from_textblocklist_remove();

  public static Textblock.Type_textblocklist f_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove) {
    Textblock.Type_textblocklist output = Textblock.e_textblocklist;
    output = Collection.f_list_from_list_filter(
      Textblock.t_textblocklist,
      tblist,
      Core.t_any_from_any.vx_fn_new((textblock_any) -> {
        Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, textblock_any);
        return 
          Core.f_let(
            Textblock.t_textblock,
            Core.t_any_from_func.vx_fn_new(() -> {
              final Textblock.Type_delim delimcurr = textblock.delim();
              final Core.Type_string namecurr = delimcurr.name();
              final Core.Type_string nameremove = remove.name();
              return Core.f_if(
                Textblock.t_textblock,
                Core.f_ne(namecurr, nameremove),
                textblock
              );
            })
          );
      })
    );
    return output;
  }


  static {
    Const_delimbracketangle.const_new(c_delimbracketangle);
    Const_delimbracketcurly.const_new(c_delimbracketcurly);
    Const_delimbracketsquare.const_new(c_delimbracketsquare);
    Const_delimclose.const_new(c_delimclose);
    Const_delimclosing.const_new(c_delimclosing);
    Const_delimcomma.const_new(c_delimcomma);
    Const_delimcomment.const_new(c_delimcomment);
    Const_delimcommentblock.const_new(c_delimcommentblock);
    Const_delimline.const_new(c_delimline);
    Const_delimlisttest1.const_new(c_delimlisttest1);
    Const_delimlisttest2.const_new(c_delimlisttest2);
    Const_delimlisttest3.const_new(c_delimlisttest3);
    Const_delimnonwhitespace.const_new(c_delimnonwhitespace);
    Const_delimparen.const_new(c_delimparen);
    Const_delimquote.const_new(c_delimquote);
    Const_delimquoteblock.const_new(c_delimquoteblock);
    Const_delimspace.const_new(c_delimspace);
    Const_delimtest1.const_new(c_delimtest1);
    Const_delimtest2.const_new(c_delimtest2);
    Const_delimtest3.const_new(c_delimtest3);
    Const_delimtext.const_new(c_delimtext);
    Const_delimwhitespace.const_new(c_delimwhitespace);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("delim", Textblock.t_delim);
    maptype.put("delimlist", Textblock.t_delimlist);
    maptype.put("textblock", Textblock.t_textblock);
    maptype.put("textblocklist", Textblock.t_textblocklist);
    mapconst.put("delimbracketangle", Textblock.c_delimbracketangle);
    mapconst.put("delimbracketcurly", Textblock.c_delimbracketcurly);
    mapconst.put("delimbracketsquare", Textblock.c_delimbracketsquare);
    mapconst.put("delimclose", Textblock.c_delimclose);
    mapconst.put("delimclosing", Textblock.c_delimclosing);
    mapconst.put("delimcomma", Textblock.c_delimcomma);
    mapconst.put("delimcomment", Textblock.c_delimcomment);
    mapconst.put("delimcommentblock", Textblock.c_delimcommentblock);
    mapconst.put("delimline", Textblock.c_delimline);
    mapconst.put("delimlisttest1", Textblock.c_delimlisttest1);
    mapconst.put("delimlisttest2", Textblock.c_delimlisttest2);
    mapconst.put("delimlisttest3", Textblock.c_delimlisttest3);
    mapconst.put("delimnonwhitespace", Textblock.c_delimnonwhitespace);
    mapconst.put("delimparen", Textblock.c_delimparen);
    mapconst.put("delimquote", Textblock.c_delimquote);
    mapconst.put("delimquoteblock", Textblock.c_delimquoteblock);
    mapconst.put("delimspace", Textblock.c_delimspace);
    mapconst.put("delimtest1", Textblock.c_delimtest1);
    mapconst.put("delimtest2", Textblock.c_delimtest2);
    mapconst.put("delimtest3", Textblock.c_delimtest3);
    mapconst.put("delimtext", Textblock.c_delimtext);
    mapconst.put("delimwhitespace", Textblock.c_delimwhitespace);
    mapfunc.put("children<-textblock", Textblock.t_children_from_textblock);
    mapfunc.put("delim-first<-delim-delim", Textblock.t_delim_first_from_delim_delim);
    mapfunc.put("delim-first<-string-delimlist", Textblock.t_delim_first_from_string_delimlist);
    mapfunc.put("delim-pos<-string-delim", Textblock.t_delim_pos_from_string_delim);
    mapfunc.put("delimlist-pos<-string-delimlist", Textblock.t_delimlist_pos_from_string_delimlist);
    mapfunc.put("is-close", Textblock.t_is_close);
    mapfunc.put("is-single", Textblock.t_is_single);
    mapfunc.put("stringlist<-textblocklist", Textblock.t_stringlist_from_textblocklist);
    mapfunc.put("text<-textblock", Textblock.t_text_from_textblock);
    mapfunc.put("textblock-addchild<-textblock-find-child", Textblock.t_textblock_addchild_from_textblock_find_child);
    mapfunc.put("textblock-delimnotfound", Textblock.t_textblock_delimnotfound);
    mapfunc.put("textblock-findparent<-textblock", Textblock.t_textblock_findparent_from_textblock);
    mapfunc.put("textblock-init", Textblock.t_textblock_init);
    mapfunc.put("textblock-parse", Textblock.t_textblock_parse);
    mapfunc.put("textblock-parse-one", Textblock.t_textblock_parse_one);
    mapfunc.put("textblock-parse<-string-delim", Textblock.t_textblock_parse_from_string_delim);
    mapfunc.put("textblock-replace<-textblock-find-replace", Textblock.t_textblock_replace_from_textblock_find_replace);
    mapfunc.put("textblock-startleft<-string-delim-offset", Textblock.t_textblock_startleft_from_string_delim_offset);
    mapfunc.put("textblock-startright<-string-delim-offset", Textblock.t_textblock_startright_from_string_delim_offset);
    mapfunc.put("textblock<-close-textblock", Textblock.t_textblock_from_close_textblock);
    mapfunc.put("textblock<-empty-textblock", Textblock.t_textblock_from_empty_textblock);
    mapfunc.put("textblock<-open-textblock", Textblock.t_textblock_from_open_textblock);
    mapfunc.put("textblock<-single-textblock", Textblock.t_textblock_from_single_textblock);
    mapfunc.put("textblock<-string-delim", Textblock.t_textblock_from_string_delim);
    mapfunc.put("textblock<-textblock-delim", Textblock.t_textblock_from_textblock_delim);
    mapfunc.put("textblocklist<-textblocklist-remove", Textblock.t_textblocklist_from_textblocklist_remove);
    Core.vx_global_package_set("vx/data/textblock", maptype, mapconst, mapfunc);
  }

}
