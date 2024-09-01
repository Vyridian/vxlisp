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
    public Core.Type_string name();
    public Core.Type_string starttext();
    public Core.Type_string endtext();
    public Core.Type_int pos();
    public Textblock.Type_delimlist delimlist();
  }

  public static class Class_delim extends Core.Class_base implements Type_delim {

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

    public Core.Type_string vx_p_starttext = null;

    @Override
    public Core.Type_string starttext() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_starttext;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_endtext = null;

    @Override
    public Core.Type_string endtext() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_endtext;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_pos = null;

    @Override
    public Core.Type_int pos() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_pos;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Textblock.Type_delimlist vx_p_delimlist = null;

    @Override
    public Textblock.Type_delimlist delimlist() {
      Textblock.Type_delimlist output = Textblock.e_delimlist;
      Textblock.Type_delimlist testnull = vx_p_delimlist;
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
      } else if ((skey.equals(":starttext"))) {
        output = this.starttext();
      } else if ((skey.equals(":endtext"))) {
        output = this.endtext();
      } else if ((skey.equals(":pos"))) {
        output = this.pos();
      } else if ((skey.equals(":delimlist"))) {
        output = this.delimlist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":starttext", this.starttext());
      map.put(":endtext", this.endtext());
      map.put(":pos", this.pos());
      map.put(":delimlist", this.delimlist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Type_delim output = Core.vx_copy(Textblock.e_delim, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Type_delim output = this;
      boolean ischanged = false;
      Textblock.Class_delim value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Core.Type_string vx_p_starttext = value.starttext();
      Core.Type_string vx_p_endtext = value.endtext();
      Core.Type_int vx_p_pos = value.pos();
      Textblock.Type_delimlist vx_p_delimlist = value.delimlist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":starttext");
      validkeys.add(":endtext");
      validkeys.add(":pos");
      validkeys.add(":delimlist");
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
            msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":starttext"))) {
            if (valsub == vx_p_starttext) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstarttext = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_starttext = valstarttext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_starttext = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("starttext"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":endtext"))) {
            if (valsub == vx_p_endtext) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valendtext = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_endtext = valendtext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_endtext = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("endtext"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":pos"))) {
            if (valsub == vx_p_pos) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valpos = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_pos = valpos;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_pos = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("pos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":delimlist"))) {
            if (valsub == vx_p_delimlist) {
            } else if (valsub instanceof Textblock.Type_delimlist) {
              Textblock.Type_delimlist valdelimlist = (Textblock.Type_delimlist)valsub;
              ischanged = true;
              vx_p_delimlist = valdelimlist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("delimlist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Textblock.Class_delim work = new Textblock.Class_delim();
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
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delim;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Textblock.Type_delim e_delim = new Textblock.Class_delim();
  public static final Textblock.Type_delim t_delim = new Textblock.Class_delim();

  /**
   * type: delimlist
   * A list of delim.
   * (type delimlist)
   */
  public interface Type_delimlist extends Core.Type_list {
    public List<Textblock.Type_delim> vx_listdelim();
    public Textblock.Type_delim vx_delim(final Core.Type_int index);
  }

  public static class Class_delimlist extends Core.Class_base implements Type_delimlist {

    public List<Textblock.Type_delim> vx_p_list = Core.immutablelist(
      new ArrayList<Textblock.Type_delim>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Textblock.Type_delim vx_delim(final Core.Type_int index) {
      Textblock.Type_delim output = Textblock.e_delim;
      Textblock.Class_delimlist list = this;
      int iindex = index.vx_int();
      List<Textblock.Type_delim> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Textblock.Type_delim> vx_listdelim() {
      List<Textblock.Type_delim> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Textblock.Type_delim output = this.vx_delim(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Type_delimlist output = Core.vx_copy(Textblock.e_delimlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Type_delimlist output = this;
      boolean ischanged = false;
      Textblock.Class_delimlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Textblock.Type_delim> listval = new ArrayList<Textblock.Type_delim>(value.vx_listdelim());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Textblock.Type_delimlist) {
          Textblock.Type_delimlist multi = (Textblock.Type_delimlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdelim());
        } else if (valsub instanceof Textblock.Type_delim) {
          Textblock.Type_delim allowsub = (Textblock.Type_delim)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Textblock.Type_delim) {
          ischanged = true;
          listval.add((Textblock.Type_delim)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Textblock.Type_delim) {
              Textblock.Type_delim valitem = (Textblock.Type_delim)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Textblock.Class_delimlist work = new Textblock.Class_delimlist();
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
      Core.Type_any output = Textblock.e_delimlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delimlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Textblock.t_delim), // allowtypes
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

  public static final Textblock.Type_delimlist e_delimlist = new Textblock.Class_delimlist();
  public static final Textblock.Type_delimlist t_delimlist = new Textblock.Class_delimlist();

  /**
   * type: textblock
   * A textblock is a tree of text used for parsing by delimter.
   * (type textblock)
   */
  public interface Type_textblock extends Core.Type_struct {
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

    public Core.Type_string vx_p_text = null;

    @Override
    public Core.Type_string text() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_text;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_startpos = null;

    @Override
    public Core.Type_int startpos() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_startpos;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_endpos = null;

    @Override
    public Core.Type_int endpos() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_endpos;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_curpos = null;

    @Override
    public Core.Type_int curpos() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_curpos;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_line = null;

    @Override
    public Core.Type_int line() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_line;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_int vx_p_column = null;

    @Override
    public Core.Type_int column() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_column;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Textblock.Type_delim vx_p_delim = null;

    @Override
    public Textblock.Type_delim delim() {
      Textblock.Type_delim output = Textblock.e_delim;
      Textblock.Type_delim testnull = vx_p_delim;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Textblock.Type_delim vx_p_close = null;

    @Override
    public Textblock.Type_delim close() {
      Textblock.Type_delim output = Textblock.e_delim;
      Textblock.Type_delim testnull = vx_p_close;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Textblock.Type_textblock vx_p_parent = null;

    @Override
    public Textblock.Type_textblock parent() {
      Textblock.Type_textblock output = Textblock.e_textblock;
      Textblock.Type_textblock testnull = vx_p_parent;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Textblock.Type_textblocklist vx_p_children = null;

    @Override
    public Textblock.Type_textblocklist children() {
      Textblock.Type_textblocklist output = Textblock.e_textblocklist;
      Textblock.Type_textblocklist testnull = vx_p_children;
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
      } else if ((skey.equals(":text"))) {
        output = this.text();
      } else if ((skey.equals(":startpos"))) {
        output = this.startpos();
      } else if ((skey.equals(":endpos"))) {
        output = this.endpos();
      } else if ((skey.equals(":curpos"))) {
        output = this.curpos();
      } else if ((skey.equals(":line"))) {
        output = this.line();
      } else if ((skey.equals(":column"))) {
        output = this.column();
      } else if ((skey.equals(":delim"))) {
        output = this.delim();
      } else if ((skey.equals(":close"))) {
        output = this.close();
      } else if ((skey.equals(":parent"))) {
        output = this.parent();
      } else if ((skey.equals(":children"))) {
        output = this.children();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":text", this.text());
      map.put(":startpos", this.startpos());
      map.put(":endpos", this.endpos());
      map.put(":curpos", this.curpos());
      map.put(":line", this.line());
      map.put(":column", this.column());
      map.put(":delim", this.delim());
      map.put(":close", this.close());
      map.put(":parent", this.parent());
      map.put(":children", this.children());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Type_textblock output = Core.vx_copy(Textblock.e_textblock, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Type_textblock output = this;
      boolean ischanged = false;
      Textblock.Class_textblock value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Core.Type_string vx_p_text = value.text();
      Core.Type_int vx_p_startpos = value.startpos();
      Core.Type_int vx_p_endpos = value.endpos();
      Core.Type_int vx_p_curpos = value.curpos();
      Core.Type_int vx_p_line = value.line();
      Core.Type_int vx_p_column = value.column();
      Textblock.Type_delim vx_p_delim = value.delim();
      Textblock.Type_delim vx_p_close = value.close();
      Textblock.Type_textblock vx_p_parent = value.parent();
      Textblock.Type_textblocklist vx_p_children = value.children();
      List<String> validkeys = new ArrayList<String>();
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
            msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":text"))) {
            if (valsub == vx_p_text) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valtext = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valtext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":startpos"))) {
            if (valsub == vx_p_startpos) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valstartpos = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_startpos = valstartpos;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_startpos = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("startpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":endpos"))) {
            if (valsub == vx_p_endpos) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valendpos = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_endpos = valendpos;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_endpos = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("endpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":curpos"))) {
            if (valsub == vx_p_curpos) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valcurpos = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_curpos = valcurpos;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_curpos = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("curpos"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":line"))) {
            if (valsub == vx_p_line) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valline = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_line = valline;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_line = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("line"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":column"))) {
            if (valsub == vx_p_column) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valcolumn = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_column = valcolumn;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_column = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("column"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":delim"))) {
            if (valsub == vx_p_delim) {
            } else if (valsub instanceof Textblock.Type_delim) {
              Textblock.Type_delim valdelim = (Textblock.Type_delim)valsub;
              ischanged = true;
              vx_p_delim = valdelim;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("delim"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":close"))) {
            if (valsub == vx_p_close) {
            } else if (valsub instanceof Textblock.Type_delim) {
              Textblock.Type_delim valclose = (Textblock.Type_delim)valsub;
              ischanged = true;
              vx_p_close = valclose;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("close"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":parent"))) {
            if (valsub == vx_p_parent) {
            } else if (valsub instanceof Textblock.Type_textblock) {
              Textblock.Type_textblock valparent = (Textblock.Type_textblock)valsub;
              ischanged = true;
              vx_p_parent = valparent;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("parent"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":children"))) {
            if (valsub == vx_p_children) {
            } else if (valsub instanceof Textblock.Type_textblocklist) {
              Textblock.Type_textblocklist valchildren = (Textblock.Type_textblocklist)valsub;
              ischanged = true;
              vx_p_children = valchildren;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("children"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Textblock.Class_textblock work = new Textblock.Class_textblock();
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
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Textblock.Type_textblock e_textblock = new Textblock.Class_textblock();
  public static final Textblock.Type_textblock t_textblock = new Textblock.Class_textblock();

  /**
   * type: textblocklist
   * A list of textblock.
   * (type textblocklist)
   */
  public interface Type_textblocklist extends Core.Type_list {
    public List<Textblock.Type_textblock> vx_listtextblock();
    public Textblock.Type_textblock vx_textblock(final Core.Type_int index);
  }

  public static class Class_textblocklist extends Core.Class_base implements Type_textblocklist {

    public List<Textblock.Type_textblock> vx_p_list = Core.immutablelist(
      new ArrayList<Textblock.Type_textblock>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock(final Core.Type_int index) {
      Textblock.Type_textblock output = Textblock.e_textblock;
      Textblock.Class_textblocklist list = this;
      int iindex = index.vx_int();
      List<Textblock.Type_textblock> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Textblock.Type_textblock> vx_listtextblock() {
      List<Textblock.Type_textblock> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Textblock.Type_textblock output = this.vx_textblock(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Type_textblocklist output = Core.vx_copy(Textblock.e_textblocklist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Type_textblocklist output = this;
      boolean ischanged = false;
      Textblock.Class_textblocklist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Textblock.Type_textblock> listval = new ArrayList<Textblock.Type_textblock>(value.vx_listtextblock());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Textblock.Type_textblocklist) {
          Textblock.Type_textblocklist multi = (Textblock.Type_textblocklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtextblock());
        } else if (valsub instanceof Textblock.Type_textblock) {
          Textblock.Type_textblock allowsub = (Textblock.Type_textblock)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Textblock.Type_textblock) {
          ischanged = true;
          listval.add((Textblock.Type_textblock)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Textblock.Type_textblock) {
              Textblock.Type_textblock valitem = (Textblock.Type_textblock)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Textblock.Class_textblocklist work = new Textblock.Class_textblocklist();
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
      Core.Type_any output = Textblock.e_textblocklist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblocklist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Textblock.t_textblock), // allowtypes
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

  public static final Textblock.Type_textblocklist e_textblocklist = new Textblock.Class_textblocklist();
  public static final Textblock.Type_textblocklist t_textblocklist = new Textblock.Class_textblocklist();

  /**
   * Constant: delimbracketangle
   * Angle Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketangle {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimbracketangle"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("<"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string(">")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimbracketangle = new Textblock.Class_delim();


  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketcurly {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimbracketcurly"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("{"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string("}")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimbracketcurly = new Textblock.Class_delim();


  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  public static class Const_delimbracketsquare {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimbracketsquare"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("["),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string("]")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimbracketsquare = new Textblock.Class_delim();


  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  public static class Const_delimclose {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimclose")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimclose = new Textblock.Class_delim();


  /**
   * Constant: delimclosing
   * A placeholder delimiter used to mark the closing of whatever is the current delimiter.
   * {delim}
   */
  public static class Const_delimclosing {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimclosing")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimclosing = new Textblock.Class_delim();


  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  public static class Const_delimcomma {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimcomma"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string(",")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimcomma = new Textblock.Class_delim();


  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  public static class Const_delimcomment {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimcomment"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("//"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string("\n")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimcomment = new Textblock.Class_delim();


  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  public static class Const_delimcommentblock {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimcommentblock"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("/*"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string("*/")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimcommentblock = new Textblock.Class_delim();


  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  public static class Const_delimline {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimline"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("\n")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimline = new Textblock.Class_delim();


  /**
   * Constant: delimlisttest1
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest1 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest1", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_delim), // allowtypes
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

    public static void const_new(Textblock.Type_delimlist output) {
      Textblock.Class_delimlist outval = (Textblock.Class_delimlist)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delimlist value = Core.f_new(
        Textblock.t_delimlist,
        Core.vx_new(
          Core.t_anylist,
          Textblock.c_delimtest2
        )
      );
      outval.vx_p_list = value.vx_listdelim();
    }

  }

  public static final Textblock.Type_delimlist c_delimlisttest1 = new Textblock.Class_delimlist();


  /**
   * Constant: delimlisttest2
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest2 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest2", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_delim), // allowtypes
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

    public static void const_new(Textblock.Type_delimlist output) {
      Textblock.Class_delimlist outval = (Textblock.Class_delimlist)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delimlist value = Core.f_new(
        Textblock.t_delimlist,
        Core.vx_new(
          Core.t_anylist,
          Textblock.c_delimcomma,
          Textblock.c_delimtest3
        )
      );
      outval.vx_p_list = value.vx_listdelim();
    }

  }

  public static final Textblock.Type_delimlist c_delimlisttest2 = new Textblock.Class_delimlist();


  /**
   * Constant: delimlisttest3
   * A delimiter used for test suite
   * {delimlist}
   */
  public static class Const_delimlisttest3 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest3", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_delim), // allowtypes
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

    public static void const_new(Textblock.Type_delimlist output) {
      Textblock.Class_delimlist outval = (Textblock.Class_delimlist)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delimlist value = Core.f_new(
        Textblock.t_delimlist,
        Core.vx_new(
          Core.t_anylist,
          Textblock.c_delimcomma,
          Textblock.c_delimwhitespace
        )
      );
      outval.vx_p_list = value.vx_listdelim();
    }

  }

  public static final Textblock.Type_delimlist c_delimlisttest3 = new Textblock.Class_delimlist();


  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  public static class Const_delimnonwhitespace {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimnonwhitespace"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string(":nonwhitespace"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string(":whitespace")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimnonwhitespace = new Textblock.Class_delim();


  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  public static class Const_delimparen {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimparen"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("("),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string(")")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimparen = new Textblock.Class_delim();


  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  public static class Const_delimquote {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimquote"),
          Core.vx_new_string(":starttext"),
          Core.c_quote,
          Core.vx_new_string(":endtext"),
          Core.c_quote
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimquote = new Textblock.Class_delim();


  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  public static class Const_delimquoteblock {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimquoteblock"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string("`"),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string("`")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimquoteblock = new Textblock.Class_delim();


  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  public static class Const_delimspace {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimspace"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string(" "),
          Core.vx_new_string(":endtext"),
          Core.vx_new_string(" ")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimspace = new Textblock.Class_delim();


  /**
   * Constant: delimtest1
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest1 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":delimlist"),
          Textblock.c_delimlisttest1
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimtest1 = new Textblock.Class_delim();


  /**
   * Constant: delimtest2
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest2 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_copy(
        Textblock.c_delimbracketangle,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":delimlist"),
          Textblock.c_delimlisttest2
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimtest2 = new Textblock.Class_delim();


  /**
   * Constant: delimtest3
   * A delimiter used for test suite
   * {delim}
   */
  public static class Const_delimtest3 {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_copy(
        Textblock.c_delimbracketcurly,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":delimlist"),
          Textblock.c_delimlisttest3
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimtest3 = new Textblock.Class_delim();


  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  public static class Const_delimtext {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimtext")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimtext = new Textblock.Class_delim();


  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  public static class Const_delimwhitespace {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimwhitespace"),
          Core.vx_new_string(":starttext"),
          Core.vx_new_string(":whitespace")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimwhitespace = new Textblock.Class_delim();

  /**
   * @function children_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} textblock
   * @return {textblocklist}
   * (func children<-textblock)
   */
  public interface Func_children_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblocklist vx_children_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_children_from_textblock extends Core.Class_base implements Func_children_from_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_children_from_textblock output = new Textblock.Class_children_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_children_from_textblock output = new Textblock.Class_children_from_textblock();
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
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_textblock), // allowtypes
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
      Core.Type_any output = Textblock.e_children_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_children_from_textblock;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_children_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_children_from_textblock(textblock);
      return output;
    }

    @Override
    public Textblock.Type_textblocklist vx_children_from_textblock(final Textblock.Type_textblock textblock) {
      Textblock.Type_textblocklist output = Textblock.f_children_from_textblock(textblock);
      return output;
    }

  }

  public static final Textblock.Func_children_from_textblock e_children_from_textblock = new Textblock.Class_children_from_textblock();
  public static final Textblock.Func_children_from_textblock t_children_from_textblock = new Textblock.Class_children_from_textblock();

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
  public interface Func_delim_first_from_delim_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2);
  }

  public static class Class_delim_first_from_delim_delim extends Core.Class_base implements Func_delim_first_from_delim_delim {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_delim_first_from_delim_delim output = new Textblock.Class_delim_first_from_delim_delim();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_delim_first_from_delim_delim output = new Textblock.Class_delim_first_from_delim_delim();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_delim_first_from_delim_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delim_first_from_delim_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delim1 = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim2 = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_first_from_delim_delim(delim1, delim2);
      return output;
    }

    @Override
    public Textblock.Type_delim vx_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2) {
      Textblock.Type_delim output = Textblock.f_delim_first_from_delim_delim(delim1, delim2);
      return output;
    }

  }

  public static final Textblock.Func_delim_first_from_delim_delim e_delim_first_from_delim_delim = new Textblock.Class_delim_first_from_delim_delim();
  public static final Textblock.Func_delim_first_from_delim_delim t_delim_first_from_delim_delim = new Textblock.Class_delim_first_from_delim_delim();

  public static Textblock.Type_delim f_delim_first_from_delim_delim(final Textblock.Type_delim delim1, final Textblock.Type_delim delim2) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int pos1 = delim1.pos();
        Core.Type_int pos2 = delim2.pos();
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_delim,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  Core.vx_new_int(0),
                  pos2
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = delim1;
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_eq(
                  Core.vx_new_int(0),
                  pos1
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = delim2;
                return output_5;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_is_empty_1(
                  delim2
                );
                return output_6;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = delim1;
                return output_7;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_8 = Core.f_is_empty_1(
                  delim1
                );
                return output_8;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_9 = delim2;
                return output_9;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_10 = Core.f_lt(
                  pos2,
                  pos1
                );
                return output_10;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_11 = delim2;
                return output_11;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_12 = delim1;
                return output_12;
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
   * @function delim_first_from_string_delimlist
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delim}
   * (func delim-first<-string-delimlist)
   */
  public interface Func_delim_first_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_delim_first_from_string_delimlist extends Core.Class_base implements Func_delim_first_from_string_delimlist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_delim_first_from_string_delimlist output = new Textblock.Class_delim_first_from_string_delimlist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_delim_first_from_string_delimlist output = new Textblock.Class_delim_first_from_string_delimlist();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_delim_first_from_string_delimlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delim_first_from_string_delimlist;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_first_from_string_delimlist(text, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_delim vx_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      Textblock.Type_delim output = Textblock.f_delim_first_from_string_delimlist(text, delimlist);
      return output;
    }

  }

  public static final Textblock.Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();
  public static final Textblock.Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist = new Textblock.Class_delim_first_from_string_delimlist();

  public static Textblock.Type_delim f_delim_first_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_if_2(
      Textblock.t_delim,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_is_empty_1(
              delimlist
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_empty(
              Textblock.t_delim
            );
            return output_2;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_let(
              Textblock.t_delim,
              Core.t_any_from_func.vx_fn_new(() -> {
                Textblock.Type_delimlist resolvedlist = Textblock.f_delimlist_pos_from_string_delimlist(
                  text,
                  delimlist
                );
                Core.Type_any output_4 = Core.f_any_from_list_start_reduce(
                  Textblock.t_delim,
                  resolvedlist,
                  Core.f_empty(
                    Textblock.t_delim
                  ),
                  Core.t_any_from_reduce.vx_fn_new((Core.Type_any delim1_lmb_any, Core.Type_any delim2_lmb_any) -> {
                    final Textblock.Type_delim delim1_lmb = Core.f_any_from_any(Textblock.t_delim, delim1_lmb_any);
                    final Textblock.Type_delim delim2_lmb = Core.f_any_from_any(Textblock.t_delim, delim2_lmb_any);
                    Core.Type_any output_5 = Textblock.f_delim_first_from_delim_delim(delim1_lmb, delim2_lmb);
                    return output_5;
                  })
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
   * @function delim_pos_from_string_delim
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @return {delim}
   * (func delim-pos<-string-delim)
   */
  public interface Func_delim_pos_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delim vx_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_delim_pos_from_string_delim extends Core.Class_base implements Func_delim_pos_from_string_delim {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_delim_pos_from_string_delim output = new Textblock.Class_delim_pos_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_delim_pos_from_string_delim output = new Textblock.Class_delim_pos_from_string_delim();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_delim_pos_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delim_pos_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delim_pos_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_delim vx_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      Textblock.Type_delim output = Textblock.f_delim_pos_from_string_delim(text, delim);
      return output;
    }

  }

  public static final Textblock.Func_delim_pos_from_string_delim e_delim_pos_from_string_delim = new Textblock.Class_delim_pos_from_string_delim();
  public static final Textblock.Func_delim_pos_from_string_delim t_delim_pos_from_string_delim = new Textblock.Class_delim_pos_from_string_delim();

  public static Textblock.Type_delim f_delim_pos_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_delim output = Textblock.e_delim;
    output = Core.f_let(
      Textblock.t_delim,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string find = delim.starttext();
        Core.Type_int pos = Type.f_int_from_string_findkeyword(
          text,
          find
        );
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_delim,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  pos,
                  Core.vx_new_int(0)
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = delim;
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_copy(
                  delim,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":pos"),
                    pos
                  )
                );
                return output_4;
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
   * @function delimlist_pos_from_string_delimlist
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delimlist}
   * (func delimlist-pos<-string-delimlist)
   */
  public interface Func_delimlist_pos_from_string_delimlist extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist);
  }

  public static class Class_delimlist_pos_from_string_delimlist extends Core.Class_base implements Func_delimlist_pos_from_string_delimlist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_delimlist_pos_from_string_delimlist output = new Textblock.Class_delimlist_pos_from_string_delimlist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_delimlist_pos_from_string_delimlist output = new Textblock.Class_delimlist_pos_from_string_delimlist();
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
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_delim), // allowtypes
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
      Core.Type_any output = Textblock.e_delimlist_pos_from_string_delimlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_delimlist_pos_from_string_delimlist;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delimlist delimlist = Core.f_any_from_any(Textblock.t_delimlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
      return output;
    }

    @Override
    public Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
      Textblock.Type_delimlist output = Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
      return output;
    }

  }

  public static final Textblock.Func_delimlist_pos_from_string_delimlist e_delimlist_pos_from_string_delimlist = new Textblock.Class_delimlist_pos_from_string_delimlist();
  public static final Textblock.Func_delimlist_pos_from_string_delimlist t_delimlist_pos_from_string_delimlist = new Textblock.Class_delimlist_pos_from_string_delimlist();

  public static Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist(final Core.Type_string text, final Textblock.Type_delimlist delimlist) {
    Textblock.Type_delimlist output = Textblock.e_delimlist;
    output = Core.f_list_from_list_1(
      Textblock.t_delimlist,
      delimlist,
      Core.t_any_from_any.vx_fn_new((delim_any) -> {
        Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, delim_any);
        Core.Type_any output_1 = Textblock.f_delim_pos_from_string_delim(
          text,
          delim
        );
        return output_1;
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
  public interface Func_is_close extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_close(final Textblock.Type_delim delimarg);
  }

  public static class Class_is_close extends Core.Class_base implements Func_is_close {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_is_close output = new Textblock.Class_is_close();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_is_close output = new Textblock.Class_is_close();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_is_close;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_is_close;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_delim inputval = (Textblock.Type_delim)value;
      Core.Type_any outputval = Textblock.f_is_close(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_is_close(delimarg);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_close(final Textblock.Type_delim delimarg) {
      Core.Type_boolean output = Textblock.f_is_close(delimarg);
      return output;
    }

  }

  public static final Textblock.Func_is_close e_is_close = new Textblock.Class_is_close();
  public static final Textblock.Func_is_close t_is_close = new Textblock.Class_is_close();

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
  public interface Func_is_single extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_single(final Textblock.Type_delim delimarg);
  }

  public static class Class_is_single extends Core.Class_base implements Func_is_single {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_is_single output = new Textblock.Class_is_single();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_is_single output = new Textblock.Class_is_single();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_is_single;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_is_single;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_delim inputval = (Textblock.Type_delim)value;
      Core.Type_any outputval = Textblock.f_is_single(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim delimarg = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_is_single(delimarg);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_single(final Textblock.Type_delim delimarg) {
      Core.Type_boolean output = Textblock.f_is_single(delimarg);
      return output;
    }

  }

  public static final Textblock.Func_is_single e_is_single = new Textblock.Class_is_single();
  public static final Textblock.Func_is_single t_is_single = new Textblock.Class_is_single();

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
  public interface Func_stringlist_from_textblocklist extends Core.Func_any_from_any {
    public Core.Type_stringlist vx_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist);
  }

  public static class Class_stringlist_from_textblocklist extends Core.Class_base implements Func_stringlist_from_textblocklist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_stringlist_from_textblocklist output = new Textblock.Class_stringlist_from_textblocklist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_stringlist_from_textblocklist output = new Textblock.Class_stringlist_from_textblocklist();
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
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
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
      Core.Type_any output = Textblock.e_stringlist_from_textblocklist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_stringlist_from_textblocklist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblocklist inputval = (Textblock.Type_textblocklist)value;
      Core.Type_any outputval = Textblock.f_stringlist_from_textblocklist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_stringlist_from_textblocklist(textblocklist);
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist) {
      Core.Type_stringlist output = Textblock.f_stringlist_from_textblocklist(textblocklist);
      return output;
    }

  }

  public static final Textblock.Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();
  public static final Textblock.Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = new Textblock.Class_stringlist_from_textblocklist();

  public static Core.Type_stringlist f_stringlist_from_textblocklist(final Textblock.Type_textblocklist textblocklist) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_list_from_list_1(
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
  public interface Func_text_from_textblock extends Core.Func_any_from_any {
    public Core.Type_string vx_text_from_textblock(final Textblock.Type_textblock block);
  }

  public static class Class_text_from_textblock extends Core.Class_base implements Func_text_from_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_text_from_textblock output = new Textblock.Class_text_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_text_from_textblock output = new Textblock.Class_text_from_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_text_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_text_from_textblock;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_text_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_text_from_textblock(block);
      return output;
    }

    @Override
    public Core.Type_string vx_text_from_textblock(final Textblock.Type_textblock block) {
      Core.Type_string output = Textblock.f_text_from_textblock(block);
      return output;
    }

  }

  public static final Textblock.Func_text_from_textblock e_text_from_textblock = new Textblock.Class_text_from_textblock();
  public static final Textblock.Func_text_from_textblock t_text_from_textblock = new Textblock.Class_text_from_textblock();

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
  public interface Func_textblock_addchild_from_textblock_find_child extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child);
  }

  public static class Class_textblock_addchild_from_textblock_find_child extends Core.Class_base implements Func_textblock_addchild_from_textblock_find_child {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_addchild_from_textblock_find_child output = new Textblock.Class_textblock_addchild_from_textblock_find_child();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_addchild_from_textblock_find_child output = new Textblock.Class_textblock_addchild_from_textblock_find_child();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_addchild_from_textblock_find_child;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_addchild_from_textblock_find_child;
      return output;
    }

    @Override
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
      Textblock.Type_textblock output = Textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
      return output;
    }

  }

  public static final Textblock.Func_textblock_addchild_from_textblock_find_child e_textblock_addchild_from_textblock_find_child = new Textblock.Class_textblock_addchild_from_textblock_find_child();
  public static final Textblock.Func_textblock_addchild_from_textblock_find_child t_textblock_addchild_from_textblock_find_child = new Textblock.Class_textblock_addchild_from_textblock_find_child();

  public static Textblock.Type_textblock f_textblock_addchild_from_textblock_find_child(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock child) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_if_2(
      Textblock.t_textblock,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_is_empty_1(
              textblockarg
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_empty(
              Textblock.t_textblock
            );
            return output_2;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_and_1(
              Core.vx_new(
                Core.t_booleanlist,
                Core.f_eqeq(
                  find,
                  textblockarg
                )
              )
            );
            return output_3;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_4 = Core.f_copy(
              textblockarg,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":children"),
                Core.f_copy(
                  textblockarg.children(),
                  Core.vx_new(
                    Core.t_anylist,
                    child
                  )
                )
              )
            );
            return output_4;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_5 = Core.f_copy(
              textblockarg,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":parent"),
                Textblock.f_textblock_addchild_from_textblock_find_child(
                  textblockarg.parent(),
                  find,
                  child
                )
              )
            );
            return output_5;
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
  public interface Func_textblock_delimnotfound extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_delimnotfound(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_delimnotfound extends Core.Class_base implements Func_textblock_delimnotfound {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_delimnotfound output = new Textblock.Class_textblock_delimnotfound();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_delimnotfound output = new Textblock.Class_textblock_delimnotfound();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_delimnotfound;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_delimnotfound;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_delimnotfound(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_delimnotfound(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_delimnotfound(final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_delimnotfound(textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_delimnotfound e_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();
  public static final Textblock.Func_textblock_delimnotfound t_textblock_delimnotfound = new Textblock.Class_textblock_delimnotfound();

  public static Textblock.Type_textblock f_textblock_delimnotfound(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = textblockarg.text();
        Textblock.Type_delim delima = textblockarg.delim();
        Textblock.Type_delim close = textblockarg.close();
        Textblock.Type_textblock parent = textblockarg.parent();
        Textblock.Type_textblocklist childp = parent.children();
        Textblock.Type_delim delimp = parent.delim();
        Textblock.Type_delimlist delims = delimp.delimlist();
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_not(
                  Core.f_is_empty_1(
                    close
                  )
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_let(
                  Textblock.t_textblock,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Core.Type_msg msgerr = Core.f_msg_from_error_1(
                      Core.vx_new_string("closedelimmissing"),
                      close
                    );
                    Textblock.Type_textblock child = Core.f_copy(
                      textblockarg,
                      Core.vx_new(
                        Core.t_anylist,
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
                    Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(
                      parent
                    );
                    Textblock.Type_textblocklist childrenf = find.children();
                    Textblock.Type_textblocklist childrenr = Core.f_copy(
                      childrenf,
                      Core.vx_new(
                        Core.t_anylist,
                        child
                      )
                    );
                    Textblock.Type_textblock replace = Core.f_copy(
                      find,
                      Core.vx_new(
                        Core.t_anylist,
                        msgerr,
                        Core.vx_new_string(":children"),
                        childrenr
                      )
                    );
                    Textblock.Type_textblock parent2 = Textblock.f_textblock_replace_from_textblock_find_replace(
                      parent,
                      find,
                      replace
                    );
                    Textblock.Type_textblock gparent = parent2.parent();
                    Textblock.Type_textblock parent3 = Core.f_copy(
                      parent2,
                      Core.vx_new(
                        Core.t_anylist,
                        Core.vx_new_string(":parent"),
                        Core.f_empty(
                          Textblock.t_textblock
                        )
                      )
                    );
                    Textblock.Type_textblocklist childreng = gparent.children();
                    Textblock.Type_textblocklist childrenc = Core.f_copy(
                      childreng,
                      Core.vx_new(
                        Core.t_anylist,
                        parent3
                      )
                    );
                    Core.Type_any output_4 = Core.f_copy(
                      gparent,
                      Core.vx_new(
                        Core.t_anylist,
                        Core.vx_new_string(":children"),
                        childrenc,
                        msgerr
                      )
                    );
                    return output_4;
                  })
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Core.f_is_empty_1(
                  parent
                );
                return output_5;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = textblockarg;
                return output_6;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Core.f_let(
                  Textblock.t_textblock,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Textblock.Type_delim delimchg = Core.f_if_1(
                      Textblock.t_delim,
                      Core.f_is_empty_1(
                        delima.delimlist()
                      ),
                      delima,
                      Core.f_copy(
                        delima,
                        Core.vx_new(
                          Core.t_anylist,
                          Core.vx_new_string(":delimlist"),
                          Core.f_empty(
                            Textblock.t_delimlist
                          )
                        )
                      )
                    );
                    Textblock.Type_textblock child = Core.f_if_1(
                      Textblock.t_textblock,
                      Core.f_eq(
                        Core.vx_new_string(""),
                        text
                      ),
                      Core.f_empty(
                        Textblock.t_textblock
                      ),
                      Core.f_copy(
                        textblockarg,
                        Core.vx_new(
                          Core.t_anylist,
                          Core.vx_new_string(":delim"),
                          delimchg,
                          Core.vx_new_string(":parent"),
                          Core.f_empty(
                            Textblock.t_textblock
                          )
                        )
                      )
                    );
                    Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(
                      parent
                    );
                    Textblock.Type_delim closef = find.close();
                    Core.Type_boolean closing = Core.f_if(
                      Core.t_boolean,
                      Core.f_eqeq(
                        closef,
                        Textblock.c_delimclosing
                      ),
                      Core.vx_new_boolean(true)
                    );
                    Core.Type_any output_8 = Core.f_if_2(
                      Textblock.t_textblock,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_9 = closing;
                            return output_9;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_10 = Core.f_let(
                              Textblock.t_textblock,
                              Core.t_any_from_func.vx_fn_new(() -> {
                                Textblock.Type_textblock parent2 = find.parent();
                                Textblock.Type_textblock find2 = Textblock.f_textblock_findparent_from_textblock(
                                  parent2
                                );
                                Textblock.Type_textblocklist children1 = Core.f_if_1(
                                  Textblock.t_textblocklist,
                                  Core.f_is_empty_1(
                                    child
                                  ),
                                  find.children(),
                                  Core.f_copy(
                                    find.children(),
                                    Core.vx_new(
                                      Core.t_anylist,
                                      child
                                    )
                                  )
                                );
                                Textblock.Type_textblock replace1 = Core.f_copy(
                                  find,
                                  Core.vx_new(
                                    Core.t_anylist,
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
                                Core.Type_any output_11 = Core.f_if_2(
                                  Textblock.t_textblock,
                                  Core.vx_new(
                                    Core.t_thenelselist,
                                    Core.f_then(
                                      Core.t_boolean_from_func.vx_fn_new(() -> {
                                        Core.Type_any output_12 = Core.f_is_empty_1(
                                          find2
                                        );
                                        return output_12;
                                      }),
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        Core.Type_any output_13 = Core.f_copy(
                                          parent,
                                          Core.vx_new(
                                            Core.t_anylist,
                                            Core.vx_new_string(":parent"),
                                            Core.f_copy(
                                              parent2,
                                              Core.vx_new(
                                                Core.t_anylist,
                                                Core.vx_new_string(":children"),
                                                Core.f_new(
                                                  Textblock.t_textblocklist,
                                                  Core.vx_new(
                                                    Core.t_anylist,
                                                    replace1
                                                  )
                                                )
                                              )
                                            )
                                          )
                                        );
                                        return output_13;
                                      })
                                    ),
                                    Core.f_else(
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        Core.Type_any output_14 = Core.f_let(
                                          Textblock.t_textblock,
                                          Core.t_any_from_func.vx_fn_new(() -> {
                                            Textblock.Type_textblocklist children2 = Core.f_copy(
                                              find2.children(),
                                              Core.vx_new(
                                                Core.t_anylist,
                                                replace1
                                              )
                                            );
                                            Textblock.Type_textblock replace2 = Core.f_copy(
                                              find2,
                                              Core.vx_new(
                                                Core.t_anylist,
                                                Core.vx_new_string(":close"),
                                                Core.f_empty(
                                                  Textblock.t_delim
                                                ),
                                                Core.vx_new_string(":children"),
                                                children2
                                              )
                                            );
                                            Textblock.Type_textblock replace = Textblock.f_textblock_replace_from_textblock_find_replace(
                                              parent2,
                                              find2,
                                              replace2
                                            );
                                            Core.Type_any output_15 = Textblock.f_textblock_replace_from_textblock_find_replace(
                                              parent,
                                              find,
                                              replace
                                            );
                                            return output_15;
                                          })
                                        );
                                        return output_14;
                                      })
                                    )
                                  )
                                );
                                return output_11;
                              })
                            );
                            return output_10;
                          })
                        ),
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_16 = Core.f_is_empty_1(
                              child
                            );
                            return output_16;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_17 = parent;
                            return output_17;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_18 = Textblock.f_textblock_addchild_from_textblock_find_child(
                              parent,
                              find,
                              child
                            );
                            return output_18;
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
   * @function textblock_findparent_from_textblock
   * Find a parent that accepts a child.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-findparent<-textblock)
   */
  public interface Func_textblock_findparent_from_textblock extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_findparent_from_textblock extends Core.Class_base implements Func_textblock_findparent_from_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_findparent_from_textblock output = new Textblock.Class_textblock_findparent_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_findparent_from_textblock output = new Textblock.Class_textblock_findparent_from_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_findparent_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_findparent_from_textblock;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_findparent_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_findparent_from_textblock(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_findparent_from_textblock(textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_findparent_from_textblock e_textblock_findparent_from_textblock = new Textblock.Class_textblock_findparent_from_textblock();
  public static final Textblock.Func_textblock_findparent_from_textblock t_textblock_findparent_from_textblock = new Textblock.Class_textblock_findparent_from_textblock();

  public static Textblock.Type_textblock f_textblock_findparent_from_textblock(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_delim delimcurr = textblockarg.delim();
        Textblock.Type_textblock parent = textblockarg.parent();
        Textblock.Type_textblocklist children = textblockarg.children();
        Core.Type_string starttext = delimcurr.starttext();
        Core.Type_string endtext = delimcurr.endtext();
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_is_empty_1(
                  textblockarg
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_or(
                  Core.f_is_empty_1(
                    parent
                  ),
                  Core.f_and(
                    Core.f_ne(
                      Core.vx_new_string(""),
                      starttext
                    ),
                    Core.f_ne(
                      Core.vx_new_string(""),
                      endtext
                    )
                  )
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = textblockarg;
                return output_5;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Textblock.f_textblock_findparent_from_textblock(
                  parent
                );
                return output_6;
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
   * @function textblock_init
   * Returns a textblock ready for parsing.
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock-init)
   */
  public interface Func_textblock_init extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_init(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_init extends Core.Class_base implements Func_textblock_init {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_init output = new Textblock.Class_textblock_init();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_init output = new Textblock.Class_textblock_init();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_init;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_init;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_init(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_init(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_init(final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_init(textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_init e_textblock_init = new Textblock.Class_textblock_init();
  public static final Textblock.Func_textblock_init t_textblock_init = new Textblock.Class_textblock_init();

  public static Textblock.Type_textblock f_textblock_init(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = textblockarg.text();
        Core.Type_int startpos = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            Core.vx_new_string(""),
            text
          ),
          Core.vx_new_int(0),
          Core.vx_new_int(1)
        );
        Core.Type_int endpos = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            Core.vx_new_string(""),
            text
          ),
          Core.vx_new_int(0),
          Core.f_length(
            text
          )
        );
        Core.Type_any output_1 = Core.f_copy(
          textblockarg,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":startpos"),
            startpos,
            Core.vx_new_string(":endpos"),
            endpos,
            Core.vx_new_string(":parent"),
            Core.f_copy(
              textblockarg,
              Core.vx_new(
                Core.t_anylist,
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
        return output_1;
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
  public interface Func_textblock_parse extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_parse(final Textblock.Type_textblock textblock);
  }

  public static class Class_textblock_parse extends Core.Class_base implements Func_textblock_parse {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_parse output = new Textblock.Class_textblock_parse();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_parse output = new Textblock.Class_textblock_parse();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_parse;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_parse;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_parse(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_parse(textblock);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_parse(final Textblock.Type_textblock textblock) {
      Textblock.Type_textblock output = Textblock.f_textblock_parse(textblock);
      return output;
    }

  }

  public static final Textblock.Func_textblock_parse e_textblock_parse = new Textblock.Class_textblock_parse();
  public static final Textblock.Func_textblock_parse t_textblock_parse = new Textblock.Class_textblock_parse();

  public static Textblock.Type_textblock f_textblock_parse(final Textblock.Type_textblock textblock) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Collection.f_any_from_for_until_loop_max(
      Textblock.t_textblock,
      textblock,
      Core.t_boolean_from_any.vx_fn_new((current_any) -> {
        Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
        Core.Type_any output_1 = Core.f_is_empty_1(
          current.parent()
        );
        return output_1;
      }),
      Core.t_any_from_any.vx_fn_new((current_any) -> {
        Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
        Core.Type_any output_2 = Textblock.f_textblock_parse_one(
          current
        );
        return output_2;
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
  public interface Func_textblock_parse_one extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_parse_one(final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_parse_one extends Core.Class_base implements Func_textblock_parse_one {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_parse_one output = new Textblock.Class_textblock_parse_one();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_parse_one output = new Textblock.Class_textblock_parse_one();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_parse_one;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_parse_one;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Textblock.f_textblock_parse_one(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Textblock.f_textblock_parse_one(textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_parse_one(final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_parse_one(textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_parse_one e_textblock_parse_one = new Textblock.Class_textblock_parse_one();
  public static final Textblock.Func_textblock_parse_one t_textblock_parse_one = new Textblock.Class_textblock_parse_one();

  public static Textblock.Type_textblock f_textblock_parse_one(final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_delim delimarg = textblockarg.delim();
        Textblock.Type_delim close = textblockarg.close();
        Core.Type_int startpos = textblockarg.startpos();
        Core.Type_string textarg = textblockarg.text();
        Textblock.Type_textblock parent = textblockarg.parent();
        Core.Type_boolean is_init = Core.f_and(
          Core.f_is_empty_1(
            parent
          ),
          Core.f_eq(
            startpos,
            Core.vx_new_int(0)
          )
        );
        Core.Type_string starttext = delimarg.starttext();
        Core.Type_string endtext = delimarg.endtext();
        Textblock.Type_delimlist delimlistarg = delimarg.delimlist();
        Core.Type_int startposchg = Core.f_if_2(
          Core.t_int,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_13 = Core.f_eq(
                  Core.vx_new_string(""),
                  textarg
                );
                return output_13;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_14 = startpos;
                return output_14;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_15 = Core.f_eq(
                  Core.vx_new_int(0),
                  startpos
                );
                return output_15;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_16 = Core.vx_new_int(1);
                return output_16;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_17 = startpos;
                return output_17;
              })
            )
          )
        );
        Textblock.Type_delimlist delimlistcl = Core.f_if_1(
          Textblock.t_delimlist,
          Core.f_is_empty_1(
            close
          ),
          delimlistarg,
          Core.f_copy(
            delimlistarg,
            Core.vx_new(
              Core.t_anylist,
              close
            )
          )
        );
        Textblock.Type_delim delimfirst = Textblock.f_delim_first_from_string_delimlist(
          textarg,
          delimlistcl
        );
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = is_init;
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Textblock.f_textblock_init(
                  textblockarg
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_is_empty_1(
                  parent
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = textblockarg;
                return output_5;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_is_empty_1(
                  delimfirst
                );
                return output_6;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Textblock.f_textblock_delimnotfound(
                  textblockarg
                );
                return output_7;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_8 = Textblock.f_is_close(
                  delimfirst
                );
                return output_8;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_9 = Textblock.f_textblock_from_close_textblock(
                  delimfirst,
                  textblockarg
                );
                return output_9;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_10 = Textblock.f_is_single(
                  delimfirst
                );
                return output_10;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_11 = Textblock.f_textblock_from_single_textblock(
                  delimfirst,
                  textblockarg
                );
                return output_11;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_12 = Textblock.f_textblock_from_open_textblock(
                  delimfirst,
                  textblockarg
                );
                return output_12;
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
   * @function textblock_parse_from_string_delim
   * Returns a fully parsed textblock from a string and delim.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   * (func textblock-parse<-string-delim)
   */
  public interface Func_textblock_parse_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_parse_from_string_delim extends Core.Class_base implements Func_textblock_parse_from_string_delim {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_parse_from_string_delim output = new Textblock.Class_textblock_parse_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_parse_from_string_delim output = new Textblock.Class_textblock_parse_from_string_delim();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_parse_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_parse_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_parse_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      Textblock.Type_textblock output = Textblock.f_textblock_parse_from_string_delim(text, delim);
      return output;
    }

  }

  public static final Textblock.Func_textblock_parse_from_string_delim e_textblock_parse_from_string_delim = new Textblock.Class_textblock_parse_from_string_delim();
  public static final Textblock.Func_textblock_parse_from_string_delim t_textblock_parse_from_string_delim = new Textblock.Class_textblock_parse_from_string_delim();

  public static Textblock.Type_textblock f_textblock_parse_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblock textblockinit = Textblock.f_textblock_from_string_delim(
          text,
          delim
        );
        Core.Type_any output_1 = Textblock.f_textblock_parse(
          textblockinit
        );
        return output_1;
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
  public interface Func_textblock_replace_from_textblock_find_replace extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_replace_from_textblock_find_replace(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock replace);
  }

  public static class Class_textblock_replace_from_textblock_find_replace extends Core.Class_base implements Func_textblock_replace_from_textblock_find_replace {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_replace_from_textblock_find_replace output = new Textblock.Class_textblock_replace_from_textblock_find_replace();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_replace_from_textblock_find_replace output = new Textblock.Class_textblock_replace_from_textblock_find_replace();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_replace_from_textblock_find_replace;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_replace_from_textblock_find_replace;
      return output;
    }

    @Override
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
      Textblock.Type_textblock output = Textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
      return output;
    }

  }

  public static final Textblock.Func_textblock_replace_from_textblock_find_replace e_textblock_replace_from_textblock_find_replace = new Textblock.Class_textblock_replace_from_textblock_find_replace();
  public static final Textblock.Func_textblock_replace_from_textblock_find_replace t_textblock_replace_from_textblock_find_replace = new Textblock.Class_textblock_replace_from_textblock_find_replace();

  public static Textblock.Type_textblock f_textblock_replace_from_textblock_find_replace(final Textblock.Type_textblock textblockarg, final Textblock.Type_textblock find, final Textblock.Type_textblock replace) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_if_2(
      Textblock.t_textblock,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_is_empty_1(
              textblockarg
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_empty(
              Textblock.t_textblock
            );
            return output_2;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_and_1(
              Core.vx_new(
                Core.t_booleanlist,
                Core.f_eqeq(
                  find,
                  textblockarg
                )
              )
            );
            return output_3;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_4 = replace;
            return output_4;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_5 = Core.f_copy(
              textblockarg,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":parent"),
                Textblock.f_textblock_replace_from_textblock_find_replace(
                  textblockarg.parent(),
                  find,
                  replace
                )
              )
            );
            return output_5;
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
  public interface Func_textblock_startleft_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset);
  }

  public static class Class_textblock_startleft_from_string_delim_offset extends Core.Class_base implements Func_textblock_startleft_from_string_delim_offset {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_startleft_from_string_delim_offset output = new Textblock.Class_textblock_startleft_from_string_delim_offset();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_startleft_from_string_delim_offset output = new Textblock.Class_textblock_startleft_from_string_delim_offset();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_startleft_from_string_delim_offset;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_startleft_from_string_delim_offset;
      return output;
    }

    @Override
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
      Textblock.Type_textblock output = Textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset);
      return output;
    }

  }

  public static final Textblock.Func_textblock_startleft_from_string_delim_offset e_textblock_startleft_from_string_delim_offset = new Textblock.Class_textblock_startleft_from_string_delim_offset();
  public static final Textblock.Func_textblock_startleft_from_string_delim_offset t_textblock_startleft_from_string_delim_offset = new Textblock.Class_textblock_startleft_from_string_delim_offset();

  public static Textblock.Type_textblock f_textblock_startleft_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delim, final Core.Type_int offset) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int pos = delim.pos();
        Core.Type_int start = Core.vx_new_int(1);
        Core.Type_int end = Core.f_minus(
          pos,
          Core.vx_new_int(1)
        );
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  Core.vx_new_string(""),
                  text
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_eq(
                  Core.vx_new_int(0),
                  pos
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_5;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Type.f_string_from_string_start_end(
                      text,
                      start,
                      end
                    ),
                    Core.vx_new_string(":startpos"),
                    Core.f_plus(
                      offset,
                      start
                    ),
                    Core.vx_new_string(":endpos"),
                    Core.f_plus(
                      offset,
                      end
                    ),
                    Core.vx_new_string(":curpos"),
                    Core.vx_new_int(0)
                  )
                );
                return output_6;
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
   * @function textblock_startright_from_string_delim_offset
   * Returns a textblock constructed from the text after the current delimiter start.
   * @param  {string} text
   * @param  {delim} delimin
   * @param  {int} offset
   * @return {textblock}
   * (func textblock-startright<-string-delim-offset)
   */
  public interface Func_textblock_startright_from_string_delim_offset extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset);
  }

  public static class Class_textblock_startright_from_string_delim_offset extends Core.Class_base implements Func_textblock_startright_from_string_delim_offset {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_startright_from_string_delim_offset output = new Textblock.Class_textblock_startright_from_string_delim_offset();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_startright_from_string_delim_offset output = new Textblock.Class_textblock_startright_from_string_delim_offset();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_startright_from_string_delim_offset;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_startright_from_string_delim_offset;
      return output;
    }

    @Override
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
      Textblock.Type_textblock output = Textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset);
      return output;
    }

  }

  public static final Textblock.Func_textblock_startright_from_string_delim_offset e_textblock_startright_from_string_delim_offset = new Textblock.Class_textblock_startright_from_string_delim_offset();
  public static final Textblock.Func_textblock_startright_from_string_delim_offset t_textblock_startright_from_string_delim_offset = new Textblock.Class_textblock_startright_from_string_delim_offset();

  public static Textblock.Type_textblock f_textblock_startright_from_string_delim_offset(final Core.Type_string text, final Textblock.Type_delim delimin, final Core.Type_int offset) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int startpos = delimin.pos();
        Core.Type_string starttext = delimin.starttext();
        Core.Type_string endtext = delimin.endtext();
        Textblock.Type_delimlist delimlist = delimin.delimlist();
        Textblock.Type_delim close = Core.f_if_2(
          Textblock.t_delim,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Core.f_eq(
                  endtext,
                  Core.vx_new_string("")
                );
                return output_7;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_8 = Core.f_empty(
                  Textblock.t_delim
                );
                return output_8;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_9 = Core.f_copy(
                  Textblock.c_delimclose,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":starttext"),
                    endtext
                  )
                );
                return output_9;
              })
            )
          )
        );
        Core.Type_int delimlen = Core.f_switch(
          Core.t_int,
          starttext,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(":nonwhitespace"),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_10 = Core.vx_new_int(0);
                return output_10;
              })
            ),
            Core.f_case_1(
              Core.vx_new_string(":whitespace"),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_11 = Core.vx_new_int(0);
                return output_11;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_12 = Core.f_length(
                  starttext
                );
                return output_12;
              })
            )
          )
        );
        Core.Type_int curpos = Core.vx_new_int(0);
        Core.Type_any output_1 = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  text,
                  Core.vx_new_string("")
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_lt(
                  startpos,
                  Core.vx_new_int(0)
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_5;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Type.f_string_from_string_start(
                      text,
                      startpos
                    ),
                    Core.vx_new_string(":startpos"),
                    Core.f_plus(
                      offset,
                      startpos
                    ),
                    Core.vx_new_string(":curpos"),
                    curpos,
                    Core.vx_new_string(":delim"),
                    delimin,
                    Core.vx_new_string(":close"),
                    close
                  )
                );
                return output_6;
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
   * @function textblock_from_close_textblock
   * Returns a textblock after a close delim found.
   * @param  {delim} close
   * @param  {textblock} textblockarg
   * @return {textblock}
   * (func textblock<-close-textblock)
   */
  public interface Func_textblock_from_close_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_close_textblock extends Core.Class_base implements Func_textblock_from_close_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_close_textblock output = new Textblock.Class_textblock_from_close_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_close_textblock output = new Textblock.Class_textblock_from_close_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_close_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_close_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim close = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_close_textblock(close, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_close_textblock(close, textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_close_textblock e_textblock_from_close_textblock = new Textblock.Class_textblock_from_close_textblock();
  public static final Textblock.Func_textblock_from_close_textblock t_textblock_from_close_textblock = new Textblock.Class_textblock_from_close_textblock();

  public static Textblock.Type_textblock f_textblock_from_close_textblock(final Textblock.Type_delim close, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = textblockarg.text();
        Textblock.Type_textblock parent = textblockarg.parent();
        Core.Type_int startpos = textblockarg.startpos();
        Core.Type_int endpos = textblockarg.endpos();
        Core.Type_int pos = close.pos();
        Core.Type_string textclose = close.starttext();
        Core.Type_int lenclose = Core.f_length(
          textclose
        );
        Core.Type_int posminus = Core.f_minus1(
          pos
        );
        Core.Type_int startleft = startpos;
        Core.Type_int startclose = Core.f_plus(
          startpos,
          posminus
        );
        Core.Type_int endclose = Core.f_switch(
          Core.t_int,
          textclose,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(":whitespace"),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Type.f_int_from_string_findkeyword(
                  text,
                  Core.vx_new_string(":nonwhitespace")
                );
                return output_2;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_plus(
                  Core.f_minus1(
                    startclose
                  ),
                  lenclose
                );
                return output_3;
              })
            )
          )
        );
        Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            Core.vx_new_int(1),
            pos
          ),
          startclose,
          Core.f_minus1(
            startclose
          )
        );
        Core.Type_int startright = Core.f_plus1(
          endclose
        );
        Core.Type_int endright = Core.f_if_1(
          Core.t_int,
          Core.f_lt(
            endpos,
            startright
          ),
          startright,
          endpos
        );
        Core.Type_string textleft = Type.f_string_from_string_end(
          text,
          posminus
        );
        Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(
            pos,
            lenclose
          )
        );
        Textblock.Type_textblock find = Textblock.f_textblock_findparent_from_textblock(
          parent
        );
        Textblock.Type_delim closefind = find.close();
        Core.Type_string textfind = find.text();
        Core.Type_int startfind = find.startpos();
        Textblock.Type_delim delimfind = find.delim();
        Textblock.Type_delim delimright = Core.f_new(
          Textblock.t_delim,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":delimlist"),
            delimfind.delimlist()
          )
        );
        Core.Type_int lenfind = Core.f_minus(
          Core.f_plus1(
            endclose
          ),
          startfind
        );
        Core.Type_string textreplace = Type.f_string_from_string_end(
          textfind,
          lenfind
        );
        Textblock.Type_textblock replace = Core.f_copy(
          find,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":text"),
            textreplace,
            Core.vx_new_string(":endpos"),
            endclose,
            Core.vx_new_string(":delim"),
            Core.f_copy(
              delimfind,
              Core.vx_new(
                Core.t_anylist,
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
        Textblock.Type_textblock parentchg = Textblock.f_textblock_replace_from_textblock_find_replace(
          parent,
          find,
          replace
        );
        Core.Type_any output_1 = Core.f_new(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":text"),
            textleft,
            Core.vx_new_string(":startpos"),
            startleft,
            Core.vx_new_string(":endpos"),
            endleft,
            Core.vx_new_string(":parent"),
            Core.f_copy(
              textblockarg,
              Core.vx_new(
                Core.t_anylist,
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
        return output_1;
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
  public interface Func_textblock_from_empty_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_empty_textblock(final Textblock.Type_delim empty, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_empty_textblock extends Core.Class_base implements Func_textblock_from_empty_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_empty_textblock output = new Textblock.Class_textblock_from_empty_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_empty_textblock output = new Textblock.Class_textblock_from_empty_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_empty_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_empty_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim empty = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_empty_textblock(final Textblock.Type_delim empty, final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_empty_textblock e_textblock_from_empty_textblock = new Textblock.Class_textblock_from_empty_textblock();
  public static final Textblock.Func_textblock_from_empty_textblock t_textblock_from_empty_textblock = new Textblock.Class_textblock_from_empty_textblock();

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
  public interface Func_textblock_from_open_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_open_textblock extends Core.Class_base implements Func_textblock_from_open_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_open_textblock output = new Textblock.Class_textblock_from_open_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_open_textblock output = new Textblock.Class_textblock_from_open_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_open_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_open_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim open = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_open_textblock(open, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_open_textblock(open, textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_open_textblock e_textblock_from_open_textblock = new Textblock.Class_textblock_from_open_textblock();
  public static final Textblock.Func_textblock_from_open_textblock t_textblock_from_open_textblock = new Textblock.Class_textblock_from_open_textblock();

  public static Textblock.Type_textblock f_textblock_from_open_textblock(final Textblock.Type_delim open, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = textblockarg.text();
        Textblock.Type_textblock parent = textblockarg.parent();
        Core.Type_int startpos = textblockarg.startpos();
        Core.Type_int endpos = textblockarg.endpos();
        Textblock.Type_delim delima = textblockarg.delim();
        Core.Type_int pos = open.pos();
        Core.Type_string textopen = open.starttext();
        Core.Type_string textclose = open.endtext();
        Textblock.Type_delimlist delimlistl = open.delimlist();
        Core.Type_int lenopen = Core.f_length(
          textopen
        );
        Core.Type_int posminus = Core.f_minus1(
          pos
        );
        Core.Type_int startleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            pos,
            Core.vx_new_int(1)
          ),
          Core.f_minus1(
            startpos
          ),
          startpos
        );
        Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            pos,
            Core.vx_new_int(1)
          ),
          Core.f_minus1(
            startpos
          ),
          Core.f_plus(
            Core.f_minus1(
              startleft
            ),
            posminus
          )
        );
        Core.Type_int startright = Core.f_plus_2(
          Core.vx_new(
            Core.t_intlist,
            startpos,
            posminus,
            lenopen
          )
        );
        Core.Type_int startopen = Core.f_plus(
          startpos,
          posminus
        );
        Core.Type_string textleft = Type.f_string_from_string_end(
          text,
          posminus
        );
        Core.Type_string textpar = Type.f_string_from_string_start(
          text,
          pos
        );
        Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(
            pos,
            lenopen
          )
        );
        Textblock.Type_delim close = Core.f_copy(
          Textblock.c_delimclose,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":starttext"),
            textclose
          )
        );
        Textblock.Type_textblock tbleft = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  Core.vx_new_string(""),
                  textleft
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":text"),
                    textleft,
                    Core.vx_new_string(":startpos"),
                    startleft,
                    Core.vx_new_string(":endpos"),
                    endleft
                  )
                );
                return output_4;
              })
            )
          )
        );
        Textblock.Type_textblock tbpar1 = Core.f_copy(
          textblockarg,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":text"),
            textpar,
            Core.vx_new_string(":startpos"),
            startopen,
            Core.vx_new_string(":delim"),
            Core.f_copy(
              open,
              Core.vx_new(
                Core.t_anylist,
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
        Textblock.Type_textblock tbfind = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Core.f_eq(
                  Core.vx_new_string(""),
                  textleft
                );
                return output_5;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_empty(
                  Textblock.t_textblock
                );
                return output_6;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Textblock.f_textblock_findparent_from_textblock(
                  parent
                );
                return output_7;
              })
            )
          )
        );
        Textblock.Type_textblock tbparent = Core.f_if_2(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_8 = Core.f_is_empty_1(
                  tbfind
                );
                return output_8;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_9 = tbpar1;
                return output_9;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_10 = Textblock.f_textblock_addchild_from_textblock_find_child(
                  tbpar1,
                  tbfind,
                  tbleft
                );
                return output_10;
              })
            )
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":text"),
            textright,
            Core.vx_new_string(":startpos"),
            startright,
            Core.vx_new_string(":endpos"),
            endpos,
            Core.vx_new_string(":delim"),
            Core.f_new(
              Textblock.t_delim,
              Core.vx_new(
                Core.t_anylist,
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
        return output_1;
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
  public interface Func_textblock_from_single_textblock extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg);
  }

  public static class Class_textblock_from_single_textblock extends Core.Class_base implements Func_textblock_from_single_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_single_textblock output = new Textblock.Class_textblock_from_single_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_single_textblock output = new Textblock.Class_textblock_from_single_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_single_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_single_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_delim single = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock textblockarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_single_textblock(single, textblockarg);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_single_textblock(single, textblockarg);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_single_textblock e_textblock_from_single_textblock = new Textblock.Class_textblock_from_single_textblock();
  public static final Textblock.Func_textblock_from_single_textblock t_textblock_from_single_textblock = new Textblock.Class_textblock_from_single_textblock();

  public static Textblock.Type_textblock f_textblock_from_single_textblock(final Textblock.Type_delim single, final Textblock.Type_textblock textblockarg) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_let(
      Textblock.t_textblock,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = textblockarg.text();
        Textblock.Type_textblock parent = textblockarg.parent();
        Core.Type_int startpos = textblockarg.startpos();
        Core.Type_int endpos = textblockarg.endpos();
        Core.Type_int pos = single.pos();
        Core.Type_string origsingle = single.starttext();
        Core.Type_string textsingle = Core.f_switch(
          Core.t_string,
          origsingle,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(":whitespace"),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_let(
                  Core.t_string,
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Core.Type_string text2 = Type.f_string_from_string_start(
                      text,
                      pos
                    );
                    Core.Type_int pos2 = Type.f_int_from_string_findkeyword(
                      text2,
                      Core.vx_new_string(":nonwhitespace")
                    );
                    Core.Type_int pos3 = Core.f_if_2(
                      Core.t_int,
                      Core.vx_new(
                        Core.t_thenelselist,
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_4 = Core.f_eq(
                              Core.vx_new_int(0),
                              pos2
                            );
                            return output_4;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_5 = Core.f_length(
                              text2
                            );
                            return output_5;
                          })
                        ),
                        Core.f_then(
                          Core.t_boolean_from_func.vx_fn_new(() -> {
                            Core.Type_any output_6 = Core.f_eq(
                              pos2,
                              pos
                            );
                            return output_6;
                          }),
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_7 = pos2;
                            return output_7;
                          })
                        ),
                        Core.f_else(
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any output_8 = Core.f_minus1(
                              pos2
                            );
                            return output_8;
                          })
                        )
                      )
                    );
                    Core.Type_any output_3 = Type.f_string_from_string_start_end(
                      text,
                      pos,
                      pos3
                    );
                    return output_3;
                  })
                );
                return output_2;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_9 = origsingle;
                return output_9;
              })
            )
          )
        );
        Textblock.Type_delimlist delimlistl = single.delimlist();
        Core.Type_int lensingle = Core.f_length(
          textsingle
        );
        Core.Type_int posminus = Core.f_minus1(
          pos
        );
        Core.Type_int startleft = startpos;
        Core.Type_int startsingle = Core.f_plus(
          startpos,
          posminus
        );
        Core.Type_int endsingle = Core.f_switch(
          Core.t_int,
          textsingle,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(":whitespace"),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_10 = Type.f_int_from_string_findkeyword(
                  text,
                  Core.vx_new_string(":nonwhitespace")
                );
                return output_10;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_11 = Core.f_plus(
                  Core.f_minus1(
                    startsingle
                  ),
                  lensingle
                );
                return output_11;
              })
            )
          )
        );
        Core.Type_int endleft = Core.f_if_1(
          Core.t_int,
          Core.f_eq(
            startsingle,
            startpos
          ),
          startsingle,
          Core.f_minus1(
            startsingle
          )
        );
        Core.Type_int startright = Core.f_plus1(
          endsingle
        );
        Core.Type_string textleft = Type.f_string_from_string_end(
          text,
          posminus
        );
        Core.Type_string textpar = Type.f_string_from_string_start(
          text,
          pos
        );
        Core.Type_string textright = Type.f_string_from_string_start(
          text,
          Core.f_plus(
            pos,
            lensingle
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Textblock.t_textblock,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":text"),
            textleft,
            Core.vx_new_string(":startpos"),
            startleft,
            Core.vx_new_string(":endpos"),
            endleft,
            Core.vx_new_string(":delim"),
            Core.f_new(
              Textblock.t_delim,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            Core.vx_new_string(":parent"),
            Core.f_new(
              Textblock.t_textblock,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":text"),
                textsingle,
                Core.vx_new_string(":startpos"),
                startsingle,
                Core.vx_new_string(":endpos"),
                endsingle,
                Core.vx_new_string(":delim"),
                Core.f_copy(
                  single,
                  Core.vx_new(
                    Core.t_anylist,
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
                  Core.vx_new(
                    Core.t_anylist,
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
        return output_1;
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
  public interface Func_textblock_from_string_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_from_string_delim extends Core.Class_base implements Func_textblock_from_string_delim {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_string_delim output = new Textblock.Class_textblock_from_string_delim();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_string_delim output = new Textblock.Class_textblock_from_string_delim();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_string_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_string_delim(text, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_string_delim(text, delim);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_string_delim e_textblock_from_string_delim = new Textblock.Class_textblock_from_string_delim();
  public static final Textblock.Func_textblock_from_string_delim t_textblock_from_string_delim = new Textblock.Class_textblock_from_string_delim();

  public static Textblock.Type_textblock f_textblock_from_string_delim(final Core.Type_string text, final Textblock.Type_delim delim) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_new(
      Textblock.t_textblock,
      Core.vx_new(
        Core.t_anylist,
        Core.vx_new_string(":text"),
        text,
        Core.vx_new_string(":delim"),
        delim,
        Core.vx_new_string(":startpos"),
        Core.vx_new_int(0),
        Core.vx_new_string(":endpos"),
        Core.f_length(
          text
        )
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
  public interface Func_textblock_from_textblock_delim extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock vx_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim);
  }

  public static class Class_textblock_from_textblock_delim extends Core.Class_base implements Func_textblock_from_textblock_delim {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblock_from_textblock_delim output = new Textblock.Class_textblock_from_textblock_delim();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblock_from_textblock_delim output = new Textblock.Class_textblock_from_textblock_delim();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Textblock.e_textblock_from_textblock_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblock_from_textblock_delim;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim delim = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblock_from_textblock_delim(textblock, delim);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_textblock_delim(final Textblock.Type_textblock textblock, final Textblock.Type_delim delim) {
      Textblock.Type_textblock output = Textblock.f_textblock_from_textblock_delim(textblock, delim);
      return output;
    }

  }

  public static final Textblock.Func_textblock_from_textblock_delim e_textblock_from_textblock_delim = new Textblock.Class_textblock_from_textblock_delim();
  public static final Textblock.Func_textblock_from_textblock_delim t_textblock_from_textblock_delim = new Textblock.Class_textblock_from_textblock_delim();

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
  public interface Func_textblocklist_from_textblocklist_remove extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove);
  }

  public static class Class_textblocklist_from_textblocklist_remove extends Core.Class_base implements Func_textblocklist_from_textblocklist_remove {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Textblock.Class_textblocklist_from_textblocklist_remove output = new Textblock.Class_textblocklist_from_textblocklist_remove();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Textblock.Class_textblocklist_from_textblocklist_remove output = new Textblock.Class_textblocklist_from_textblocklist_remove();
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
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Textblock.t_textblock), // allowtypes
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
      Core.Type_any output = Textblock.e_textblocklist_from_textblocklist_remove;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Textblock.t_textblocklist_from_textblocklist_remove;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist tblist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_delim remove = Core.f_any_from_any(Textblock.t_delim, arglist.vx_any(Core.vx_new_int(1)));
      output = Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
      return output;
    }

    @Override
    public Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove) {
      Textblock.Type_textblocklist output = Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
      return output;
    }

  }

  public static final Textblock.Func_textblocklist_from_textblocklist_remove e_textblocklist_from_textblocklist_remove = new Textblock.Class_textblocklist_from_textblocklist_remove();
  public static final Textblock.Func_textblocklist_from_textblocklist_remove t_textblocklist_from_textblocklist_remove = new Textblock.Class_textblocklist_from_textblocklist_remove();

  public static Textblock.Type_textblocklist f_textblocklist_from_textblocklist_remove(final Textblock.Type_textblocklist tblist, final Textblock.Type_delim remove) {
    Textblock.Type_textblocklist output = Textblock.e_textblocklist;
    output = Collection.f_list_from_list_filter(
      Textblock.t_textblocklist,
      tblist,
      Core.t_any_from_any.vx_fn_new((textblock_any) -> {
        Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, textblock_any);
        Core.Type_any output_1 = Core.f_let(
          Textblock.t_textblock,
          Core.t_any_from_func.vx_fn_new(() -> {
            Textblock.Type_delim delimcurr = textblock.delim();
            Core.Type_string namecurr = delimcurr.name();
            Core.Type_string nameremove = remove.name();
            Core.Type_any output_2 = Core.f_if(
              Textblock.t_textblock,
              Core.f_ne(
                namecurr,
                nameremove
              ),
              textblock
            );
            return output_2;
          })
        );
        return output_1;
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
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
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
