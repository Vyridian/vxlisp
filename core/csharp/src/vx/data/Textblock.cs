namespace Vx.Data;

public static class Textblock {


  /**
   * type: delim
   * A delimiter type supporting start and end delimiters and positions.
   * (type delim)
   */
  public interface Type_delim : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string starttext();
    public Vx.Core.Type_string endtext();
    public Vx.Core.Type_int pos();
    public Vx.Data.Textblock.Type_delimlist delimlist();
  }

  public class Class_delim : Vx.Core.Class_base, Type_delim {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_starttext;

    public Vx.Core.Type_string starttext() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_starttext != null) {
        output = this.vx_p_starttext;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_endtext;

    public Vx.Core.Type_string endtext() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_endtext != null) {
        output = this.vx_p_endtext;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_pos;

    public Vx.Core.Type_int pos() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_pos != null) {
        output = this.vx_p_pos;
      }
      return output;
    }

    public Vx.Data.Textblock.Type_delimlist vx_p_delimlist;

    public Vx.Data.Textblock.Type_delimlist delimlist() {
      Vx.Data.Textblock.Type_delimlist output = Vx.Data.Textblock.e_delimlist;
      if (this.vx_p_delimlist != null) {
        output = this.vx_p_delimlist;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":starttext", this.starttext());
      output.put(":endtext", this.endtext());
      output.put(":pos", this.pos());
      output.put(":delimlist", this.delimlist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Textblock.Type_delim vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_delim,
       vals);
    }

    public override Vx.Data.Textblock.Type_delim vx_copy(params Object[] vals) {
      Type_delim output = this;
      bool ischanged = false;
      Class_delim val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_starttext = val.starttext();
      Vx.Core.Type_string vx_p_endtext = val.endtext();
      Vx.Core.Type_int vx_p_pos = val.pos();
      Vx.Data.Textblock.Type_delimlist vx_p_delimlist = val.delimlist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":starttext");
      validkeys.Add(":endtext");
      validkeys.Add(":pos");
      validkeys.Add(":delimlist");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":starttext":
            if (valsub == vx_p_starttext) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_starttext = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_starttext = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("starttext"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":endtext":
            if (valsub == vx_p_endtext) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_endtext = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_endtext = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("endtext"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":pos":
            if (valsub == vx_p_pos) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_pos = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_pos = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pos"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":delimlist":
            if (valsub == vx_p_delimlist) {
            } else if (valsub is Vx.Data.Textblock.Type_delimlist) {
              ischanged = true;
              vx_p_delimlist = (Vx.Data.Textblock.Type_delimlist)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("delimlist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delim", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_delim work = new Class_delim();
        work.vx_p_name = vx_p_name;
        work.vx_p_starttext = vx_p_starttext;
        work.vx_p_endtext = vx_p_endtext;
        work.vx_p_pos = vx_p_pos;
        work.vx_p_delimlist = vx_p_delimlist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_delim;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_delim;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delim", // name
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

  public static Type_delim e_delim = new Class_delim();
  public static Type_delim t_delim = new Class_delim();

  /**
   * type: delimlist
   * A list of delim.
   * (type delimlist)
   */
  public interface Type_delimlist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Data.Textblock.Type_delim> vx_listdelim();
    public Vx.Data.Textblock.Type_delim vx_delim(Vx.Core.Type_int index);
  }

  public class Class_delimlist : Vx.Core.Class_base, Type_delimlist {

    public List<Vx.Data.Textblock.Type_delim> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Textblock.Type_delim>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_delim(Vx.Core.Type_int index) {
      Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
      Vx.Data.Textblock.Class_delimlist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Textblock.Type_delim> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Textblock.Type_delim> vx_listdelim() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_delim(index);
    }

    public override Vx.Data.Textblock.Type_delimlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_delimlist,
       vals);
    }

    public override Vx.Data.Textblock.Type_delimlist vx_copy(params Object[] vals) {
      Type_delimlist output = this;
      bool ischanged = false;
      Class_delimlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Textblock.Type_delim> listval = new List<Vx.Data.Textblock.Type_delim>(val.vx_listdelim());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Textblock.Type_delim) {
          Vx.Data.Textblock.Type_delim anysub = valsub as Vx.Data.Textblock.Type_delim;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Data.Textblock.Type_delim) {
          ischanged = true;
          listval.Add((Vx.Data.Textblock.Type_delim)valsub);
        } else if (valsub is Vx.Data.Textblock.Type_delimlist) {
          Type_delimlist multi = (Type_delimlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listdelim());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Data.Textblock.Type_delim) {
              Vx.Data.Textblock.Type_delim valitem = (Vx.Data.Textblock.Type_delim)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/textblock/delimlist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_delimlist work = new Class_delimlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_delimlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_delimlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delimlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_delim), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_delimlist e_delimlist = new Class_delimlist();
  public static Type_delimlist t_delimlist = new Class_delimlist();

  /**
   * type: textblock
   * A textblock is a tree of text used for parsing by delimter.
   * (type textblock)
   */
  public interface Type_textblock : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string text();
    public Vx.Core.Type_int startpos();
    public Vx.Core.Type_int endpos();
    public Vx.Core.Type_int curpos();
    public Vx.Core.Type_int line();
    public Vx.Core.Type_int column();
    public Vx.Data.Textblock.Type_delim delim();
    public Vx.Data.Textblock.Type_delim close();
    public Vx.Data.Textblock.Type_textblock parent();
    public Vx.Data.Textblock.Type_textblocklist children();
  }

  public class Class_textblock : Vx.Core.Class_base, Type_textblock {

    public Vx.Core.Type_string vx_p_name;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_text;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_startpos;

    public Vx.Core.Type_int startpos() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_startpos != null) {
        output = this.vx_p_startpos;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_endpos;

    public Vx.Core.Type_int endpos() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_endpos != null) {
        output = this.vx_p_endpos;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_curpos;

    public Vx.Core.Type_int curpos() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_curpos != null) {
        output = this.vx_p_curpos;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_line;

    public Vx.Core.Type_int line() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_line != null) {
        output = this.vx_p_line;
      }
      return output;
    }

    public Vx.Core.Type_int vx_p_column;

    public Vx.Core.Type_int column() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_column != null) {
        output = this.vx_p_column;
      }
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_p_delim;

    public Vx.Data.Textblock.Type_delim delim() {
      Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
      if (this.vx_p_delim != null) {
        output = this.vx_p_delim;
      }
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_p_close;

    public Vx.Data.Textblock.Type_delim close() {
      Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
      if (this.vx_p_close != null) {
        output = this.vx_p_close;
      }
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_p_parent;

    public Vx.Data.Textblock.Type_textblock parent() {
      Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
      if (this.vx_p_parent != null) {
        output = this.vx_p_parent;
      }
      return output;
    }

    public Vx.Data.Textblock.Type_textblocklist vx_p_children;

    public Vx.Data.Textblock.Type_textblocklist children() {
      Vx.Data.Textblock.Type_textblocklist output = Vx.Data.Textblock.e_textblocklist;
      if (this.vx_p_children != null) {
        output = this.vx_p_children;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
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
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Textblock.Type_textblock vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_textblock,
       vals);
    }

    public override Vx.Data.Textblock.Type_textblock vx_copy(params Object[] vals) {
      Type_textblock output = this;
      bool ischanged = false;
      Class_textblock val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_text = val.text();
      Vx.Core.Type_int vx_p_startpos = val.startpos();
      Vx.Core.Type_int vx_p_endpos = val.endpos();
      Vx.Core.Type_int vx_p_curpos = val.curpos();
      Vx.Core.Type_int vx_p_line = val.line();
      Vx.Core.Type_int vx_p_column = val.column();
      Vx.Data.Textblock.Type_delim vx_p_delim = val.delim();
      Vx.Data.Textblock.Type_delim vx_p_close = val.close();
      Vx.Data.Textblock.Type_textblock vx_p_parent = val.parent();
      Vx.Data.Textblock.Type_textblocklist vx_p_children = val.children();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":text");
      validkeys.Add(":startpos");
      validkeys.Add(":endpos");
      validkeys.Add(":curpos");
      validkeys.Add(":line");
      validkeys.Add(":column");
      validkeys.Add(":delim");
      validkeys.Add(":close");
      validkeys.Add(":parent");
      validkeys.Add(":children");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":startpos":
            if (valsub == vx_p_startpos) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_startpos = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_startpos = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("startpos"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":endpos":
            if (valsub == vx_p_endpos) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_endpos = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_endpos = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("endpos"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":curpos":
            if (valsub == vx_p_curpos) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_curpos = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_curpos = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("curpos"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":line":
            if (valsub == vx_p_line) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_line = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_line = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("line"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":column":
            if (valsub == vx_p_column) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_column = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_column = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("column"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":delim":
            if (valsub == vx_p_delim) {
            } else if (valsub is Vx.Data.Textblock.Type_delim) {
              ischanged = true;
              vx_p_delim = (Vx.Data.Textblock.Type_delim)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("delim"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":close":
            if (valsub == vx_p_close) {
            } else if (valsub is Vx.Data.Textblock.Type_delim) {
              ischanged = true;
              vx_p_close = (Vx.Data.Textblock.Type_delim)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("close"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":parent":
            if (valsub == vx_p_parent) {
            } else if (valsub is Vx.Data.Textblock.Type_textblock) {
              ischanged = true;
              vx_p_parent = (Vx.Data.Textblock.Type_textblock)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("parent"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":children":
            if (valsub == vx_p_children) {
            } else if (valsub is Vx.Data.Textblock.Type_textblocklist) {
              ischanged = true;
              vx_p_children = (Vx.Data.Textblock.Type_textblocklist)valsub;
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("children"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblock", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
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
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_textblock;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_textblock;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblock", // name
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

  public static Type_textblock e_textblock = new Class_textblock();
  public static Type_textblock t_textblock = new Class_textblock();

  /**
   * type: textblocklist
   * A list of textblock.
   * (type textblocklist)
   */
  public interface Type_textblocklist : Vx.Core.Type_list {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public List<Vx.Data.Textblock.Type_textblock> vx_listtextblock();
    public Vx.Data.Textblock.Type_textblock vx_textblock(Vx.Core.Type_int index);
  }

  public class Class_textblocklist : Vx.Core.Class_base, Type_textblocklist {

    public List<Vx.Data.Textblock.Type_textblock> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Textblock.Type_textblock>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock(Vx.Core.Type_int index) {
      Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
      Vx.Data.Textblock.Class_textblocklist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Textblock.Type_textblock> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Textblock.Type_textblock> vx_listtextblock() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_textblock(index);
    }

    public override Vx.Data.Textblock.Type_textblocklist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_textblocklist,
       vals);
    }

    public override Vx.Data.Textblock.Type_textblocklist vx_copy(params Object[] vals) {
      Type_textblocklist output = this;
      bool ischanged = false;
      Class_textblocklist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Textblock.Type_textblock> listval = new List<Vx.Data.Textblock.Type_textblock>(val.vx_listtextblock());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Textblock.Type_textblock) {
          Vx.Data.Textblock.Type_textblock anysub = valsub as Vx.Data.Textblock.Type_textblock;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx.Data.Textblock.Type_textblock) {
          ischanged = true;
          listval.Add((Vx.Data.Textblock.Type_textblock)valsub);
        } else if (valsub is Vx.Data.Textblock.Type_textblocklist) {
          Type_textblocklist multi = (Type_textblocklist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtextblock());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx.Data.Textblock.Type_textblock) {
              Vx.Data.Textblock.Type_textblock valitem = (Vx.Data.Textblock.Type_textblock)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any) {
          Vx.Core.Type_any anysub = valsub as Vx.Core.Type_any;
          msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", anysub);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/textblock/textblocklist", ":invalidtype", Vx.Core.vx_new_string(valsub.ToString()));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_textblocklist work = new Class_textblocklist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_textblocklist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_textblocklist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/textblock", // pkgname
        "textblocklist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_textblock), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_textblocklist e_textblocklist = new Class_textblocklist();
  public static Type_textblocklist t_textblocklist = new Class_textblocklist();

  /**
   * Constant: delimbracketangle
   * Angle Bracket Delimiter
   * {delim}
   */
  public class Const_delimbracketangle : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketangle", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketangle output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimbracketangle"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("<"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string(">")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimbracketangle c_delimbracketangle = new Const_delimbracketangle();


  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  public class Const_delimbracketcurly : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketcurly", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketcurly output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimbracketcurly"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("{"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string("}")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimbracketcurly c_delimbracketcurly = new Const_delimbracketcurly();


  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  public class Const_delimbracketsquare : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimbracketsquare", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimbracketsquare output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimbracketsquare"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("["),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string("]")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimbracketsquare c_delimbracketsquare = new Const_delimbracketsquare();


  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  public class Const_delimclose : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclose", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimclose output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimclose")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimclose c_delimclose = new Const_delimclose();


  /**
   * Constant: delimclosing
   * A placeholder delimiter used to mark the closing of whatever is the current delimiter.
   * {delim}
   */
  public class Const_delimclosing : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimclosing", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimclosing output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimclosing")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimclosing c_delimclosing = new Const_delimclosing();


  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  public class Const_delimcomma : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomma", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcomma output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimcomma"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string(",")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimcomma c_delimcomma = new Const_delimcomma();


  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  public class Const_delimcomment : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcomment", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcomment output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimcomment"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("//"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string("\n")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimcomment c_delimcomment = new Const_delimcomment();


  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  public class Const_delimcommentblock : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimcommentblock", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimcommentblock output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimcommentblock"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("/*"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string("*/")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimcommentblock c_delimcommentblock = new Const_delimcommentblock();


  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  public class Const_delimline : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimline", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimline output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimline"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("\n")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimline c_delimline = new Const_delimline();


  /**
   * Constant: delimlisttest1
   * A delimiter used for test suite
   * {delimlist}
   */
  public class Const_delimlisttest1 : Vx.Data.Textblock.Class_delimlist, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest1", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_delim), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_delimlisttest1 output) {
      Vx.Data.Textblock.Type_delimlist val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delimlist,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Data.Textblock.c_delimtest2
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static Const_delimlisttest1 c_delimlisttest1 = new Const_delimlisttest1();


  /**
   * Constant: delimlisttest2
   * A delimiter used for test suite
   * {delimlist}
   */
  public class Const_delimlisttest2 : Vx.Data.Textblock.Class_delimlist, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest2", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_delim), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_delimlisttest2 output) {
      Vx.Data.Textblock.Type_delimlist val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delimlist,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Data.Textblock.c_delimcomma,
                Vx.Data.Textblock.c_delimtest3
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static Const_delimlisttest2 c_delimlisttest2 = new Const_delimlisttest2();


  /**
   * Constant: delimlisttest3
   * A delimiter used for test suite
   * {delimlist}
   */
  public class Const_delimlisttest3 : Vx.Data.Textblock.Class_delimlist, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimlisttest3", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_delim), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_delimlisttest3 output) {
      Vx.Data.Textblock.Type_delimlist val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delimlist,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Data.Textblock.c_delimcomma,
                Vx.Data.Textblock.c_delimwhitespace
        )
      );
      output.vx_p_list = val.vx_listdelim();
    }


  }

  public static Const_delimlisttest3 c_delimlisttest3 = new Const_delimlisttest3();


  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  public class Const_delimnonwhitespace : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimnonwhitespace", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimnonwhitespace output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimnonwhitespace"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string(":nonwhitespace"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string(":whitespace")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimnonwhitespace c_delimnonwhitespace = new Const_delimnonwhitespace();


  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  public class Const_delimparen : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimparen", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimparen output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimparen"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("("),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string(")")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimparen c_delimparen = new Const_delimparen();


  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  public class Const_delimquote : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquote", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimquote output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimquote"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.c_quote,
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.c_quote
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimquote c_delimquote = new Const_delimquote();


  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  public class Const_delimquoteblock : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimquoteblock", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimquoteblock output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimquoteblock"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string("`"),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string("`")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimquoteblock c_delimquoteblock = new Const_delimquoteblock();


  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  public class Const_delimspace : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimspace", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimspace output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimspace"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string(" "),
                Vx.Core.vx_new_string(":endtext"),
                Vx.Core.vx_new_string(" ")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimspace c_delimspace = new Const_delimspace();


  /**
   * Constant: delimtest1
   * A delimiter used for test suite
   * {delim}
   */
  public class Const_delimtest1 : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest1", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimtest1 output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Data.Textblock.c_delimlisttest1
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimtest1 c_delimtest1 = new Const_delimtest1();


  /**
   * Constant: delimtest2
   * A delimiter used for test suite
   * {delim}
   */
  public class Const_delimtest2 : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest2", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimtest2 output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_copy(
        Vx.Data.Textblock.c_delimbracketangle,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Data.Textblock.c_delimlisttest2
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimtest2 c_delimtest2 = new Const_delimtest2();


  /**
   * Constant: delimtest3
   * A delimiter used for test suite
   * {delim}
   */
  public class Const_delimtest3 : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtest3", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimtest3 output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_copy(
        Vx.Data.Textblock.c_delimbracketcurly,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Data.Textblock.c_delimlisttest3
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimtest3 c_delimtest3 = new Const_delimtest3();


  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  public class Const_delimtext : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimtext", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimtext output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimtext")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimtext c_delimtext = new Const_delimtext();


  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  public class Const_delimwhitespace : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/textblock", // pkgname
        "delimwhitespace", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimwhitespace output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimwhitespace"),
                Vx.Core.vx_new_string(":starttext"),
                Vx.Core.vx_new_string(":whitespace")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimwhitespace c_delimwhitespace = new Const_delimwhitespace();

  /**
   * @function children_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} textblock
   * @return {textblocklist}
   * (func children<-textblock)
   */
  public interface Func_children_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblocklist vx_children_from_textblock(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_children_from_textblock : Vx.Core.Class_base, Func_children_from_textblock {

    public override Vx.Data.Textblock.Func_children_from_textblock vx_new(params Object[] vals) {
      Class_children_from_textblock output = new Class_children_from_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_children_from_textblock vx_copy(params Object[] vals) {
      Class_children_from_textblock output = new Class_children_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "children<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_textblock), // allowtypes
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
      return e_children_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_children_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_children_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_children_from_textblock(textblock);
      return output;
    }

    public Vx.Data.Textblock.Type_textblocklist vx_children_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
      return Vx.Data.Textblock.f_children_from_textblock(textblock);
    }

  }

  public static Func_children_from_textblock e_children_from_textblock = new Vx.Data.Textblock.Class_children_from_textblock();
  public static Func_children_from_textblock t_children_from_textblock = new Vx.Data.Textblock.Class_children_from_textblock();

  public static Vx.Data.Textblock.Type_textblocklist f_children_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Data.Textblock.Type_textblocklist output = Vx.Data.Textblock.e_textblocklist;
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
  public interface Func_delim_first_from_delim_delim : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_delim vx_delim_first_from_delim_delim(Vx.Data.Textblock.Type_delim delim1, Vx.Data.Textblock.Type_delim delim2);
  }

  public class Class_delim_first_from_delim_delim : Vx.Core.Class_base, Func_delim_first_from_delim_delim {

    public override Vx.Data.Textblock.Func_delim_first_from_delim_delim vx_new(params Object[] vals) {
      Class_delim_first_from_delim_delim output = new Class_delim_first_from_delim_delim();
      return output;
    }

    public override Vx.Data.Textblock.Func_delim_first_from_delim_delim vx_copy(params Object[] vals) {
      Class_delim_first_from_delim_delim output = new Class_delim_first_from_delim_delim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-delim-delim", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
      return e_delim_first_from_delim_delim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_delim_first_from_delim_delim;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim delim1 = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim2 = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_delim_first_from_delim_delim(delim1, delim2);
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_delim_first_from_delim_delim(Vx.Data.Textblock.Type_delim delim1, Vx.Data.Textblock.Type_delim delim2) {
      return Vx.Data.Textblock.f_delim_first_from_delim_delim(delim1, delim2);
    }

  }

  public static Func_delim_first_from_delim_delim e_delim_first_from_delim_delim = new Vx.Data.Textblock.Class_delim_first_from_delim_delim();
  public static Func_delim_first_from_delim_delim t_delim_first_from_delim_delim = new Vx.Data.Textblock.Class_delim_first_from_delim_delim();

  public static Vx.Data.Textblock.Type_delim f_delim_first_from_delim_delim(Vx.Data.Textblock.Type_delim delim1, Vx.Data.Textblock.Type_delim delim2) {
    Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_delim,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pos1 = delim1.pos();
        Vx.Core.Type_int pos2 = delim2.pos();
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_delim,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_int(0), pos2);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim1;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_int(0), pos1);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim2;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(delim2);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim1;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(delim1);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim2;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_lt(pos2, pos1);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim2;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
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
  public interface Func_delim_first_from_string_delimlist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_delim vx_delim_first_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist);
  }

  public class Class_delim_first_from_string_delimlist : Vx.Core.Class_base, Func_delim_first_from_string_delimlist {

    public override Vx.Data.Textblock.Func_delim_first_from_string_delimlist vx_new(params Object[] vals) {
      Class_delim_first_from_string_delimlist output = new Class_delim_first_from_string_delimlist();
      return output;
    }

    public override Vx.Data.Textblock.Func_delim_first_from_string_delimlist vx_copy(params Object[] vals) {
      Class_delim_first_from_string_delimlist output = new Class_delim_first_from_string_delimlist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-first<-string-delimlist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
      return e_delim_first_from_string_delimlist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_delim_first_from_string_delimlist;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delimlist delimlist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delimlist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_delim_first_from_string_delimlist(text, delimlist);
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_delim_first_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist) {
      return Vx.Data.Textblock.f_delim_first_from_string_delimlist(text, delimlist);
    }

  }

  public static Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist = new Vx.Data.Textblock.Class_delim_first_from_string_delimlist();
  public static Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist = new Vx.Data.Textblock.Class_delim_first_from_string_delimlist();

  public static Vx.Data.Textblock.Type_delim f_delim_first_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist) {
    Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
    output = Vx.Core.f_if_2(
      Vx.Data.Textblock.t_delim,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_empty_1(delimlist);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_empty(
              Vx.Data.Textblock.t_delim
            );
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Data.Textblock.t_delim,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Data.Textblock.Type_delimlist resolvedlist = Vx.Data.Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
                return Vx.Core.f_any_from_list_start_reduce(
                  Vx.Data.Textblock.t_delim,
                  resolvedlist,
                  Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delim
                  ),
                  Vx.Core.t_any_from_reduce.vx_fn_new((Vx.Core.Type_any delim1_lmb_any, Vx.Core.Type_any delim2_lmb_any) => {
                    Vx.Data.Textblock.Type_delim delim1_lmb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, delim1_lmb_any);
                    Vx.Data.Textblock.Type_delim delim2_lmb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, delim2_lmb_any);
                    Vx.Core.Type_any output_1 = Vx.Data.Textblock.f_delim_first_from_delim_delim(delim1_lmb, delim2_lmb);
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
  public interface Func_delim_pos_from_string_delim : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_delim vx_delim_pos_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim);
  }

  public class Class_delim_pos_from_string_delim : Vx.Core.Class_base, Func_delim_pos_from_string_delim {

    public override Vx.Data.Textblock.Func_delim_pos_from_string_delim vx_new(params Object[] vals) {
      Class_delim_pos_from_string_delim output = new Class_delim_pos_from_string_delim();
      return output;
    }

    public override Vx.Data.Textblock.Func_delim_pos_from_string_delim vx_copy(params Object[] vals) {
      Class_delim_pos_from_string_delim output = new Class_delim_pos_from_string_delim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delim-pos<-string-delim", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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
      return e_delim_pos_from_string_delim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_delim_pos_from_string_delim;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_delim_pos_from_string_delim(text, delim);
      return output;
    }

    public Vx.Data.Textblock.Type_delim vx_delim_pos_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
      return Vx.Data.Textblock.f_delim_pos_from_string_delim(text, delim);
    }

  }

  public static Func_delim_pos_from_string_delim e_delim_pos_from_string_delim = new Vx.Data.Textblock.Class_delim_pos_from_string_delim();
  public static Func_delim_pos_from_string_delim t_delim_pos_from_string_delim = new Vx.Data.Textblock.Class_delim_pos_from_string_delim();

  public static Vx.Data.Textblock.Type_delim f_delim_pos_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
    Vx.Data.Textblock.Type_delim output = Vx.Data.Textblock.e_delim;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_delim,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string find = delim.starttext();
        Vx.Core.Type_int pos = Vx.Type.f_int_from_string_findkeyword(text, find);
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_delim,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(pos, Vx.Core.vx_new_int(0));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return delim;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_copy(
                  delim,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":pos"),
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
  public interface Func_delimlist_pos_from_string_delimlist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist);
  }

  public class Class_delimlist_pos_from_string_delimlist : Vx.Core.Class_base, Func_delimlist_pos_from_string_delimlist {

    public override Vx.Data.Textblock.Func_delimlist_pos_from_string_delimlist vx_new(params Object[] vals) {
      Class_delimlist_pos_from_string_delimlist output = new Class_delimlist_pos_from_string_delimlist();
      return output;
    }

    public override Vx.Data.Textblock.Func_delimlist_pos_from_string_delimlist vx_copy(params Object[] vals) {
      Class_delimlist_pos_from_string_delimlist output = new Class_delimlist_pos_from_string_delimlist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "delimlist-pos<-string-delimlist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_delim), // allowtypes
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
      return e_delimlist_pos_from_string_delimlist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_delimlist_pos_from_string_delimlist;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delimlist delimlist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delimlist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
      return output;
    }

    public Vx.Data.Textblock.Type_delimlist vx_delimlist_pos_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist) {
      return Vx.Data.Textblock.f_delimlist_pos_from_string_delimlist(text, delimlist);
    }

  }

  public static Func_delimlist_pos_from_string_delimlist e_delimlist_pos_from_string_delimlist = new Vx.Data.Textblock.Class_delimlist_pos_from_string_delimlist();
  public static Func_delimlist_pos_from_string_delimlist t_delimlist_pos_from_string_delimlist = new Vx.Data.Textblock.Class_delimlist_pos_from_string_delimlist();

  public static Vx.Data.Textblock.Type_delimlist f_delimlist_pos_from_string_delimlist(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delimlist delimlist) {
    Vx.Data.Textblock.Type_delimlist output = Vx.Data.Textblock.e_delimlist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Data.Textblock.t_delimlist,
      delimlist,
      Vx.Core.t_any_from_any.vx_fn_new((delim_any) => {
        Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, delim_any);
        return 
        Vx.Data.Textblock.f_delim_pos_from_string_delim(text, delim);
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
  public interface Func_is_close : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_close(Vx.Data.Textblock.Type_delim delimarg);
  }

  public class Class_is_close : Vx.Core.Class_base, Func_is_close {

    public override Vx.Data.Textblock.Func_is_close vx_new(params Object[] vals) {
      Class_is_close output = new Class_is_close();
      return output;
    }

    public override Vx.Data.Textblock.Func_is_close vx_copy(params Object[] vals) {
      Class_is_close output = new Class_is_close();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-close", // name
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
      return e_is_close;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_close;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_delim inputval = (Vx.Data.Textblock.Type_delim)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_is_close(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim delimarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_is_close(delimarg);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_close(Vx.Data.Textblock.Type_delim delimarg) {
      return Vx.Data.Textblock.f_is_close(delimarg);
    }

  }

  public static Func_is_close e_is_close = new Vx.Data.Textblock.Class_is_close();
  public static Func_is_close t_is_close = new Vx.Data.Textblock.Class_is_close();

  public static Vx.Core.Type_boolean f_is_close(Vx.Data.Textblock.Type_delim delimarg) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_eq(
      delimarg.name(),
      Vx.Data.Textblock.c_delimclose.name()
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
  public interface Func_is_single : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_is_single(Vx.Data.Textblock.Type_delim delimarg);
  }

  public class Class_is_single : Vx.Core.Class_base, Func_is_single {

    public override Vx.Data.Textblock.Func_is_single vx_new(params Object[] vals) {
      Class_is_single output = new Class_is_single();
      return output;
    }

    public override Vx.Data.Textblock.Func_is_single vx_copy(params Object[] vals) {
      Class_is_single output = new Class_is_single();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "is-single", // name
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
      return e_is_single;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_is_single;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_delim inputval = (Vx.Data.Textblock.Type_delim)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_is_single(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim delimarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_is_single(delimarg);
      return output;
    }

    public Vx.Core.Type_boolean vx_is_single(Vx.Data.Textblock.Type_delim delimarg) {
      return Vx.Data.Textblock.f_is_single(delimarg);
    }

  }

  public static Func_is_single e_is_single = new Vx.Data.Textblock.Class_is_single();
  public static Func_is_single t_is_single = new Vx.Data.Textblock.Class_is_single();

  public static Vx.Core.Type_boolean f_is_single(Vx.Data.Textblock.Type_delim delimarg) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_and(
      Vx.Core.f_ne(
        Vx.Core.vx_new_string(""),
        delimarg.starttext()
      ),
      Vx.Core.f_eq(
        Vx.Core.vx_new_string(""),
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
  public interface Func_stringlist_from_textblocklist : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringlist vx_stringlist_from_textblocklist(Vx.Data.Textblock.Type_textblocklist textblocklist);
  }

  public class Class_stringlist_from_textblocklist : Vx.Core.Class_base, Func_stringlist_from_textblocklist {

    public override Vx.Data.Textblock.Func_stringlist_from_textblocklist vx_new(params Object[] vals) {
      Class_stringlist_from_textblocklist output = new Class_stringlist_from_textblocklist();
      return output;
    }

    public override Vx.Data.Textblock.Func_stringlist_from_textblocklist vx_copy(params Object[] vals) {
      Class_stringlist_from_textblocklist output = new Class_stringlist_from_textblocklist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "stringlist<-textblocklist", // name
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
      return e_stringlist_from_textblocklist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringlist_from_textblocklist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblocklist inputval = (Vx.Data.Textblock.Type_textblocklist)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_stringlist_from_textblocklist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblocklist textblocklist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblocklist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_stringlist_from_textblocklist(textblocklist);
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist_from_textblocklist(Vx.Data.Textblock.Type_textblocklist textblocklist) {
      return Vx.Data.Textblock.f_stringlist_from_textblocklist(textblocklist);
    }

  }

  public static Func_stringlist_from_textblocklist e_stringlist_from_textblocklist = new Vx.Data.Textblock.Class_stringlist_from_textblocklist();
  public static Func_stringlist_from_textblocklist t_stringlist_from_textblocklist = new Vx.Data.Textblock.Class_stringlist_from_textblocklist();

  public static Vx.Core.Type_stringlist f_stringlist_from_textblocklist(Vx.Data.Textblock.Type_textblocklist textblocklist) {
    Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Core.t_stringlist,
      textblocklist,
      Vx.Data.Textblock.t_text_from_textblock
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
  public interface Func_text_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_text_from_textblock(Vx.Data.Textblock.Type_textblock block);
  }

  public class Class_text_from_textblock : Vx.Core.Class_base, Func_text_from_textblock {

    public override Vx.Data.Textblock.Func_text_from_textblock vx_new(params Object[] vals) {
      Class_text_from_textblock output = new Class_text_from_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_text_from_textblock vx_copy(params Object[] vals) {
      Class_text_from_textblock output = new Class_text_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "text<-textblock", // name
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
      return e_text_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_text_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_text_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock block = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_text_from_textblock(block);
      return output;
    }

    public Vx.Core.Type_string vx_text_from_textblock(Vx.Data.Textblock.Type_textblock block) {
      return Vx.Data.Textblock.f_text_from_textblock(block);
    }

  }

  public static Func_text_from_textblock e_text_from_textblock = new Vx.Data.Textblock.Class_text_from_textblock();
  public static Func_text_from_textblock t_text_from_textblock = new Vx.Data.Textblock.Class_text_from_textblock();

  public static Vx.Core.Type_string f_text_from_textblock(Vx.Data.Textblock.Type_textblock block) {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_textblock_addchild_from_textblock_find_child : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_addchild_from_textblock_find_child(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock child);
  }

  public class Class_textblock_addchild_from_textblock_find_child : Vx.Core.Class_base, Func_textblock_addchild_from_textblock_find_child {

    public override Vx.Data.Textblock.Func_textblock_addchild_from_textblock_find_child vx_new(params Object[] vals) {
      Class_textblock_addchild_from_textblock_find_child output = new Class_textblock_addchild_from_textblock_find_child();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_addchild_from_textblock_find_child vx_copy(params Object[] vals) {
      Class_textblock_addchild_from_textblock_find_child output = new Class_textblock_addchild_from_textblock_find_child();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-addchild<-textblock-find-child", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_addchild_from_textblock_find_child;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_addchild_from_textblock_find_child;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock find = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Data.Textblock.Type_textblock child = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Data.Textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_addchild_from_textblock_find_child(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock child) {
      return Vx.Data.Textblock.f_textblock_addchild_from_textblock_find_child(textblockarg, find, child);
    }

  }

  public static Func_textblock_addchild_from_textblock_find_child e_textblock_addchild_from_textblock_find_child = new Vx.Data.Textblock.Class_textblock_addchild_from_textblock_find_child();
  public static Func_textblock_addchild_from_textblock_find_child t_textblock_addchild_from_textblock_find_child = new Vx.Data.Textblock.Class_textblock_addchild_from_textblock_find_child();

  public static Vx.Data.Textblock.Type_textblock f_textblock_addchild_from_textblock_find_child(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock child) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_if_2(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_empty_1(textblockarg);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_empty(
              Vx.Data.Textblock.t_textblock
            );
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_and_1(
              Vx.Core.vx_new(Vx.Core.t_booleanlist,
                  Vx.Core.f_eqeq(find, textblockarg)
              )
            );
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_copy(
              textblockarg,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":children"),
                  Vx.Core.f_copy(
                    textblockarg.children(),
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                      child
                    )
                  )
              )
            );
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_copy(
              textblockarg,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":parent"),
                  Vx.Data.Textblock.f_textblock_addchild_from_textblock_find_child(
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
  public interface Func_textblock_delimnotfound : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_delimnotfound(Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_delimnotfound : Vx.Core.Class_base, Func_textblock_delimnotfound {

    public override Vx.Data.Textblock.Func_textblock_delimnotfound vx_new(params Object[] vals) {
      Class_textblock_delimnotfound output = new Class_textblock_delimnotfound();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_delimnotfound vx_copy(params Object[] vals) {
      Class_textblock_delimnotfound output = new Class_textblock_delimnotfound();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-delimnotfound", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_delimnotfound;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_delimnotfound;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_textblock_delimnotfound(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_textblock_delimnotfound(textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_delimnotfound(Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_delimnotfound(textblockarg);
    }

  }

  public static Func_textblock_delimnotfound e_textblock_delimnotfound = new Vx.Data.Textblock.Class_textblock_delimnotfound();
  public static Func_textblock_delimnotfound t_textblock_delimnotfound = new Vx.Data.Textblock.Class_textblock_delimnotfound();

  public static Vx.Data.Textblock.Type_textblock f_textblock_delimnotfound(Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = textblockarg.text();
        Vx.Data.Textblock.Type_delim delima = textblockarg.delim();
        Vx.Data.Textblock.Type_delim close = textblockarg.close();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Data.Textblock.Type_textblocklist childp = parent.children();
        Vx.Data.Textblock.Type_delim delimp = parent.delim();
        Vx.Data.Textblock.Type_delimlist delims = delimp.delimlist();
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_not(
                  Vx.Core.f_is_empty_1(close)
                );
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_let(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Core.Type_msg msgerr = Vx.Core.f_msg_from_error_1(Vx.Core.vx_new_string("closedelimmissing"), close);
                    Vx.Data.Textblock.Type_textblock child = Vx.Core.f_copy(
                      textblockarg,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":delim"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_delim
                          ),
                          Vx.Core.vx_new_string(":close"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_delim
                          ),
                          Vx.Core.vx_new_string(":parent"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_textblock
                          )
                      )
                    );
                    Vx.Data.Textblock.Type_textblock find = Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent);
                    Vx.Data.Textblock.Type_textblocklist childrenf = find.children();
                    Vx.Data.Textblock.Type_textblocklist childrenr = Vx.Core.f_copy(childrenf, Vx.Core.vx_new(Vx.Core.t_anylist,
                      child));
                    Vx.Data.Textblock.Type_textblock replace = Vx.Core.f_copy(
                      find,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                          msgerr,
                          Vx.Core.vx_new_string(":children"),
                          childrenr
                      )
                    );
                    Vx.Data.Textblock.Type_textblock parent2 = Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
                    Vx.Data.Textblock.Type_textblock gparent = parent2.parent();
                    Vx.Data.Textblock.Type_textblock parent3 = Vx.Core.f_copy(
                      parent2,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":parent"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_textblock
                          )
                      )
                    );
                    Vx.Data.Textblock.Type_textblocklist childreng = gparent.children();
                    Vx.Data.Textblock.Type_textblocklist childrenc = Vx.Core.f_copy(childreng, Vx.Core.vx_new(Vx.Core.t_anylist,
                      parent3));
                    return Vx.Core.f_copy(
                      gparent,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":children"),
                        childrenc,
                        msgerr
                      )
                    );
                  })
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(parent);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return textblockarg;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_let(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Data.Textblock.Type_delim delimchg = Vx.Core.f_if_1(
                      Vx.Data.Textblock.t_delim,
                      Vx.Core.f_is_empty_1(
                        delima.delimlist()
                      ),
                      delima,
                      Vx.Core.f_copy(
                        delima,
                        Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":delimlist"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_delimlist
                          )
                        )
                      )
                    );
                    Vx.Data.Textblock.Type_textblock child = Vx.Core.f_if_1(
                      Vx.Data.Textblock.t_textblock,
                      Vx.Core.f_eq(Vx.Core.vx_new_string(""), text),
                      Vx.Core.f_empty(
                        Vx.Data.Textblock.t_textblock
                      ),
                      Vx.Core.f_copy(
                        textblockarg,
                        Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":delim"),
                          delimchg,
                          Vx.Core.vx_new_string(":parent"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_textblock
                          )
                        )
                      )
                    );
                    Vx.Data.Textblock.Type_textblock find = Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent);
                    Vx.Data.Textblock.Type_delim closef = find.close();
                    Vx.Core.Type_boolean closing = Vx.Core.f_if(
                      Vx.Core.t_boolean,
                      Vx.Core.f_eqeq(
                        closef,
                        Vx.Data.Textblock.c_delimclosing
                      ),
                      Vx.Core.vx_new_boolean(true)
                    );
                    return Vx.Core.f_if_2(
                      Vx.Data.Textblock.t_textblock,
                      Vx.Core.vx_new(Vx.Core.t_thenelselist,
                        Vx.Core.f_then(
                          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                            return closing;
                          }),
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Core.f_let(
                              Vx.Data.Textblock.t_textblock,
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                Vx.Data.Textblock.Type_textblock parent2 = find.parent();
                                Vx.Data.Textblock.Type_textblock find2 = Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent2);
                                Vx.Data.Textblock.Type_textblocklist children1 = Vx.Core.f_if_1(
                                  Vx.Data.Textblock.t_textblocklist,
                                  Vx.Core.f_is_empty_1(child),
                                  find.children(),
                                  Vx.Core.f_copy(
                                    find.children(),
                                    Vx.Core.vx_new(Vx.Core.t_anylist,
                                      child
                                    )
                                  )
                                );
                                Vx.Data.Textblock.Type_textblock replace1 = Vx.Core.f_copy(
                                  find,
                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                      Vx.Core.vx_new_string(":close"),
                                      Vx.Core.f_empty(
                                        Vx.Data.Textblock.t_delim
                                      ),
                                      Vx.Core.vx_new_string(":parent"),
                                      Vx.Core.f_empty(
                                        Vx.Data.Textblock.t_textblock
                                      ),
                                      Vx.Core.vx_new_string(":children"),
                                      children1
                                  )
                                );
                                return Vx.Core.f_if_2(
                                  Vx.Data.Textblock.t_textblock,
                                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                                    Vx.Core.f_then(
                                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                        return Vx.Core.f_is_empty_1(find2);
                                      }),
                                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                                        return Vx.Core.f_copy(
                                          parent,
                                          Vx.Core.vx_new(Vx.Core.t_anylist,
                                              Vx.Core.vx_new_string(":parent"),
                                              Vx.Core.f_copy(
                                                parent2,
                                                Vx.Core.vx_new(Vx.Core.t_anylist,
                                                  Vx.Core.vx_new_string(":children"),
                                                  Vx.Core.f_new(
                                                    Vx.Data.Textblock.t_textblocklist,
                                                    Vx.Core.vx_new(Vx.Core.t_anylist,
                                                      replace1
                                                    )
                                                  )
                                                )
                                              )
                                          )
                                        );
                                      })
                                    ),
                                    Vx.Core.f_else(
                                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                                        return Vx.Core.f_let(
                                          Vx.Data.Textblock.t_textblock,
                                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                                            Vx.Data.Textblock.Type_textblocklist children2 = Vx.Core.f_copy(
                                              find2.children(),
                                              Vx.Core.vx_new(Vx.Core.t_anylist,
                                                  replace1
                                              )
                                            );
                                            Vx.Data.Textblock.Type_textblock replace2 = Vx.Core.f_copy(
                                              find2,
                                              Vx.Core.vx_new(Vx.Core.t_anylist,
                                                  Vx.Core.vx_new_string(":close"),
                                                  Vx.Core.f_empty(
                                                    Vx.Data.Textblock.t_delim
                                                  ),
                                                  Vx.Core.vx_new_string(":children"),
                                                  children2
                                              )
                                            );
                                            Vx.Data.Textblock.Type_textblock replace = Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(parent2, find2, replace2);
                                            return Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
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
                        Vx.Core.f_then(
                          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                            return Vx.Core.f_is_empty_1(child);
                          }),
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return parent;
                          })
                        ),
                        Vx.Core.f_else(
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Data.Textblock.f_textblock_addchild_from_textblock_find_child(parent, find, child);
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
  public interface Func_textblock_findparent_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_findparent_from_textblock(Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_findparent_from_textblock : Vx.Core.Class_base, Func_textblock_findparent_from_textblock {

    public override Vx.Data.Textblock.Func_textblock_findparent_from_textblock vx_new(params Object[] vals) {
      Class_textblock_findparent_from_textblock output = new Class_textblock_findparent_from_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_findparent_from_textblock vx_copy(params Object[] vals) {
      Class_textblock_findparent_from_textblock output = new Class_textblock_findparent_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-findparent<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_findparent_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_findparent_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_textblock_findparent_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_textblock_findparent_from_textblock(textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_findparent_from_textblock(Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_findparent_from_textblock(textblockarg);
    }

  }

  public static Func_textblock_findparent_from_textblock e_textblock_findparent_from_textblock = new Vx.Data.Textblock.Class_textblock_findparent_from_textblock();
  public static Func_textblock_findparent_from_textblock t_textblock_findparent_from_textblock = new Vx.Data.Textblock.Class_textblock_findparent_from_textblock();

  public static Vx.Data.Textblock.Type_textblock f_textblock_findparent_from_textblock(Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_delim delimcurr = textblockarg.delim();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Data.Textblock.Type_textblocklist children = textblockarg.children();
        Vx.Core.Type_string starttext = delimcurr.starttext();
        Vx.Core.Type_string endtext = delimcurr.endtext();
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(textblockarg);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Data.Textblock.t_textblock
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_or(
                  Vx.Core.f_is_empty_1(parent),
                  Vx.Core.f_and(
                    Vx.Core.f_ne(Vx.Core.vx_new_string(""), starttext),
                    Vx.Core.f_ne(Vx.Core.vx_new_string(""), endtext)
                  )
                );
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return textblockarg;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent);
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
  public interface Func_textblock_init : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_init(Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_init : Vx.Core.Class_base, Func_textblock_init {

    public override Vx.Data.Textblock.Func_textblock_init vx_new(params Object[] vals) {
      Class_textblock_init output = new Class_textblock_init();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_init vx_copy(params Object[] vals) {
      Class_textblock_init output = new Class_textblock_init();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-init", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_init;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_init;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_textblock_init(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_textblock_init(textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_init(Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_init(textblockarg);
    }

  }

  public static Func_textblock_init e_textblock_init = new Vx.Data.Textblock.Class_textblock_init();
  public static Func_textblock_init t_textblock_init = new Vx.Data.Textblock.Class_textblock_init();

  public static Vx.Data.Textblock.Type_textblock f_textblock_init(Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = textblockarg.text();
        Vx.Core.Type_int startpos = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(Vx.Core.vx_new_string(""), text),
          Vx.Core.vx_new_int(0),
          Vx.Core.vx_new_int(1)
        );
        Vx.Core.Type_int endpos = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(Vx.Core.vx_new_string(""), text),
          Vx.Core.vx_new_int(0),
          Vx.Core.f_length(text)
        );
        return Vx.Core.f_copy(
          textblockarg,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":startpos"),
            startpos,
            Vx.Core.vx_new_string(":endpos"),
            endpos,
            Vx.Core.vx_new_string(":parent"),
            Vx.Core.f_copy(
              textblockarg,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":startpos"),
                startpos,
                Vx.Core.vx_new_string(":endpos"),
                endpos,
                Vx.Core.vx_new_string(":delim"),
                Vx.Core.f_empty(
                  Vx.Data.Textblock.t_delim
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
  public interface Func_textblock_parse : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_parse(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_textblock_parse : Vx.Core.Class_base, Func_textblock_parse {

    public override Vx.Data.Textblock.Func_textblock_parse vx_new(params Object[] vals) {
      Class_textblock_parse output = new Class_textblock_parse();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_parse vx_copy(params Object[] vals) {
      Class_textblock_parse output = new Class_textblock_parse();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_parse;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_parse;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_textblock_parse(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_textblock_parse(textblock);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_parse(Vx.Data.Textblock.Type_textblock textblock) {
      return Vx.Data.Textblock.f_textblock_parse(textblock);
    }

  }

  public static Func_textblock_parse e_textblock_parse = new Vx.Data.Textblock.Class_textblock_parse();
  public static Func_textblock_parse t_textblock_parse = new Vx.Data.Textblock.Class_textblock_parse();

  public static Vx.Data.Textblock.Type_textblock f_textblock_parse(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Collection.f_any_from_for_until_loop_max(
      Vx.Data.Textblock.t_textblock,
      textblock,
      Vx.Core.t_boolean_from_any.vx_fn_new((current_any) => {
        Vx.Data.Textblock.Type_textblock current = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, current_any);
        return 
        Vx.Core.f_is_empty_1(
          current.parent()
        );
      }),
      Vx.Core.t_any_from_any.vx_fn_new((current_any) => {
        Vx.Data.Textblock.Type_textblock current = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, current_any);
        return 
        Vx.Data.Textblock.f_textblock_parse_one(current);
      }),
      Vx.Core.vx_new_int(100000)
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
  public interface Func_textblock_parse_one : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_parse_one(Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_parse_one : Vx.Core.Class_base, Func_textblock_parse_one {

    public override Vx.Data.Textblock.Func_textblock_parse_one vx_new(params Object[] vals) {
      Class_textblock_parse_one output = new Class_textblock_parse_one();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_parse_one vx_copy(params Object[] vals) {
      Class_textblock_parse_one output = new Class_textblock_parse_one();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse-one", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_parse_one;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_parse_one;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Textblock.f_textblock_parse_one(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Textblock.f_textblock_parse_one(textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_parse_one(Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_parse_one(textblockarg);
    }

  }

  public static Func_textblock_parse_one e_textblock_parse_one = new Vx.Data.Textblock.Class_textblock_parse_one();
  public static Func_textblock_parse_one t_textblock_parse_one = new Vx.Data.Textblock.Class_textblock_parse_one();

  public static Vx.Data.Textblock.Type_textblock f_textblock_parse_one(Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_delim delimarg = textblockarg.delim();
        Vx.Data.Textblock.Type_delim close = textblockarg.close();
        Vx.Core.Type_int startpos = textblockarg.startpos();
        Vx.Core.Type_string textarg = textblockarg.text();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Core.Type_boolean is_init = Vx.Core.f_and(
          Vx.Core.f_is_empty_1(parent),
          Vx.Core.f_eq(startpos, Vx.Core.vx_new_int(0))
        );
        Vx.Core.Type_string starttext = delimarg.starttext();
        Vx.Core.Type_string endtext = delimarg.endtext();
        Vx.Data.Textblock.Type_delimlist delimlistarg = delimarg.delimlist();
        Vx.Core.Type_int startposchg = Vx.Core.f_if_2(
          Vx.Core.t_int,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eq(Vx.Core.vx_new_string(""), textarg);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return startpos;
                })
              ),
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eq(Vx.Core.vx_new_int(0), startpos);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(1);
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return startpos;
                })
              )
          )
        );
        Vx.Data.Textblock.Type_delimlist delimlistcl = Vx.Core.f_if_1(
          Vx.Data.Textblock.t_delimlist,
          Vx.Core.f_is_empty_1(close),
          delimlistarg,
          Vx.Core.f_copy(delimlistarg, Vx.Core.vx_new(Vx.Core.t_anylist,
            close))
        );
        Vx.Data.Textblock.Type_delim delimfirst = Vx.Data.Textblock.f_delim_first_from_string_delimlist(textarg, delimlistcl);
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return is_init;
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_init(textblockarg);
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(parent);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return textblockarg;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(delimfirst);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_delimnotfound(textblockarg);
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_is_close(delimfirst);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_from_close_textblock(delimfirst, textblockarg);
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_is_single(delimfirst);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_from_single_textblock(delimfirst, textblockarg);
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Data.Textblock.f_textblock_from_open_textblock(delimfirst, textblockarg);
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
  public interface Func_textblock_parse_from_string_delim : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_parse_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim);
  }

  public class Class_textblock_parse_from_string_delim : Vx.Core.Class_base, Func_textblock_parse_from_string_delim {

    public override Vx.Data.Textblock.Func_textblock_parse_from_string_delim vx_new(params Object[] vals) {
      Class_textblock_parse_from_string_delim output = new Class_textblock_parse_from_string_delim();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_parse_from_string_delim vx_copy(params Object[] vals) {
      Class_textblock_parse_from_string_delim output = new Class_textblock_parse_from_string_delim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-parse<-string-delim", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_parse_from_string_delim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_parse_from_string_delim;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_parse_from_string_delim(text, delim);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_parse_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
      return Vx.Data.Textblock.f_textblock_parse_from_string_delim(text, delim);
    }

  }

  public static Func_textblock_parse_from_string_delim e_textblock_parse_from_string_delim = new Vx.Data.Textblock.Class_textblock_parse_from_string_delim();
  public static Func_textblock_parse_from_string_delim t_textblock_parse_from_string_delim = new Vx.Data.Textblock.Class_textblock_parse_from_string_delim();

  public static Vx.Data.Textblock.Type_textblock f_textblock_parse_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblock textblockinit = Vx.Data.Textblock.f_textblock_from_string_delim(text, delim);
        return Vx.Data.Textblock.f_textblock_parse(textblockinit);
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
  public interface Func_textblock_replace_from_textblock_find_replace : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_replace_from_textblock_find_replace(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock replace);
  }

  public class Class_textblock_replace_from_textblock_find_replace : Vx.Core.Class_base, Func_textblock_replace_from_textblock_find_replace {

    public override Vx.Data.Textblock.Func_textblock_replace_from_textblock_find_replace vx_new(params Object[] vals) {
      Class_textblock_replace_from_textblock_find_replace output = new Class_textblock_replace_from_textblock_find_replace();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_replace_from_textblock_find_replace vx_copy(params Object[] vals) {
      Class_textblock_replace_from_textblock_find_replace output = new Class_textblock_replace_from_textblock_find_replace();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-replace<-textblock-find-replace", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_replace_from_textblock_find_replace;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_replace_from_textblock_find_replace;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock find = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Data.Textblock.Type_textblock replace = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_replace_from_textblock_find_replace(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock replace) {
      return Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace);
    }

  }

  public static Func_textblock_replace_from_textblock_find_replace e_textblock_replace_from_textblock_find_replace = new Vx.Data.Textblock.Class_textblock_replace_from_textblock_find_replace();
  public static Func_textblock_replace_from_textblock_find_replace t_textblock_replace_from_textblock_find_replace = new Vx.Data.Textblock.Class_textblock_replace_from_textblock_find_replace();

  public static Vx.Data.Textblock.Type_textblock f_textblock_replace_from_textblock_find_replace(Vx.Data.Textblock.Type_textblock textblockarg, Vx.Data.Textblock.Type_textblock find, Vx.Data.Textblock.Type_textblock replace) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_if_2(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_empty_1(textblockarg);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_empty(
              Vx.Data.Textblock.t_textblock
            );
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_and_1(
              Vx.Core.vx_new(Vx.Core.t_booleanlist,
                  Vx.Core.f_eqeq(find, textblockarg)
              )
            );
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return replace;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_copy(
              textblockarg,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":parent"),
                  Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(
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
  public interface Func_textblock_startleft_from_string_delim_offset : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_startleft_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim, Vx.Core.Type_int offset);
  }

  public class Class_textblock_startleft_from_string_delim_offset : Vx.Core.Class_base, Func_textblock_startleft_from_string_delim_offset {

    public override Vx.Data.Textblock.Func_textblock_startleft_from_string_delim_offset vx_new(params Object[] vals) {
      Class_textblock_startleft_from_string_delim_offset output = new Class_textblock_startleft_from_string_delim_offset();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_startleft_from_string_delim_offset vx_copy(params Object[] vals) {
      Class_textblock_startleft_from_string_delim_offset output = new Class_textblock_startleft_from_string_delim_offset();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startleft<-string-delim-offset", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_startleft_from_string_delim_offset;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_startleft_from_string_delim_offset;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int offset = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Data.Textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_startleft_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim, Vx.Core.Type_int offset) {
      return Vx.Data.Textblock.f_textblock_startleft_from_string_delim_offset(text, delim, offset);
    }

  }

  public static Func_textblock_startleft_from_string_delim_offset e_textblock_startleft_from_string_delim_offset = new Vx.Data.Textblock.Class_textblock_startleft_from_string_delim_offset();
  public static Func_textblock_startleft_from_string_delim_offset t_textblock_startleft_from_string_delim_offset = new Vx.Data.Textblock.Class_textblock_startleft_from_string_delim_offset();

  public static Vx.Data.Textblock.Type_textblock f_textblock_startleft_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim, Vx.Core.Type_int offset) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pos = delim.pos();
        Vx.Core.Type_int start = Vx.Core.vx_new_int(1);
        Vx.Core.Type_int end = Vx.Core.f_minus(pos, Vx.Core.vx_new_int(1));
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_string(""), text);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Data.Textblock.t_textblock
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(Vx.Core.vx_new_int(0), pos);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Data.Textblock.t_textblock
                );
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Type.f_string_from_string_start_end(text, start, end),
                      Vx.Core.vx_new_string(":startpos"),
                      Vx.Core.f_plus(offset, start),
                      Vx.Core.vx_new_string(":endpos"),
                      Vx.Core.f_plus(offset, end),
                      Vx.Core.vx_new_string(":curpos"),
                      Vx.Core.vx_new_int(0)
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
  public interface Func_textblock_startright_from_string_delim_offset : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_startright_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delimin, Vx.Core.Type_int offset);
  }

  public class Class_textblock_startright_from_string_delim_offset : Vx.Core.Class_base, Func_textblock_startright_from_string_delim_offset {

    public override Vx.Data.Textblock.Func_textblock_startright_from_string_delim_offset vx_new(params Object[] vals) {
      Class_textblock_startright_from_string_delim_offset output = new Class_textblock_startright_from_string_delim_offset();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_startright_from_string_delim_offset vx_copy(params Object[] vals) {
      Class_textblock_startright_from_string_delim_offset output = new Class_textblock_startright_from_string_delim_offset();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock-startright<-string-delim-offset", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_startright_from_string_delim_offset;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_startright_from_string_delim_offset;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delimin = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_int offset = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Data.Textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_startright_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delimin, Vx.Core.Type_int offset) {
      return Vx.Data.Textblock.f_textblock_startright_from_string_delim_offset(text, delimin, offset);
    }

  }

  public static Func_textblock_startright_from_string_delim_offset e_textblock_startright_from_string_delim_offset = new Vx.Data.Textblock.Class_textblock_startright_from_string_delim_offset();
  public static Func_textblock_startright_from_string_delim_offset t_textblock_startright_from_string_delim_offset = new Vx.Data.Textblock.Class_textblock_startright_from_string_delim_offset();

  public static Vx.Data.Textblock.Type_textblock f_textblock_startright_from_string_delim_offset(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delimin, Vx.Core.Type_int offset) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int startpos = delimin.pos();
        Vx.Core.Type_string starttext = delimin.starttext();
        Vx.Core.Type_string endtext = delimin.endtext();
        Vx.Data.Textblock.Type_delimlist delimlist = delimin.delimlist();
        Vx.Data.Textblock.Type_delim close = Vx.Core.f_if_2(
          Vx.Data.Textblock.t_delim,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eq(endtext, Vx.Core.vx_new_string(""));
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delim
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_copy(
                    Vx.Data.Textblock.c_delimclose,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":starttext"),
                        endtext
                    )
                  );
                })
              )
          )
        );
        Vx.Core.Type_int delimlen = Vx.Core.f_switch(
          Vx.Core.t_int,
          starttext,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.vx_new_string(":nonwhitespace"),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(0);
                })
              ),
              Vx.Core.f_case_1(
                Vx.Core.vx_new_string(":whitespace"),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(0);
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_length(starttext);
                })
              )
          )
        );
        Vx.Core.Type_int curpos = Vx.Core.vx_new_int(0);
        return Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(text, Vx.Core.vx_new_string(""));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Data.Textblock.t_textblock
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_lt(startpos, Vx.Core.vx_new_int(0));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_empty(
                  Vx.Data.Textblock.t_textblock
                );
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Type.f_string_from_string_start(text, startpos),
                      Vx.Core.vx_new_string(":startpos"),
                      Vx.Core.f_plus(offset, startpos),
                      Vx.Core.vx_new_string(":curpos"),
                      curpos,
                      Vx.Core.vx_new_string(":delim"),
                      delimin,
                      Vx.Core.vx_new_string(":close"),
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
  public interface Func_textblock_from_close_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_close_textblock(Vx.Data.Textblock.Type_delim close, Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_from_close_textblock : Vx.Core.Class_base, Func_textblock_from_close_textblock {

    public override Vx.Data.Textblock.Func_textblock_from_close_textblock vx_new(params Object[] vals) {
      Class_textblock_from_close_textblock output = new Class_textblock_from_close_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_close_textblock vx_copy(params Object[] vals) {
      Class_textblock_from_close_textblock output = new Class_textblock_from_close_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-close-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_close_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_close_textblock;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim close = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_close_textblock(close, textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_close_textblock(Vx.Data.Textblock.Type_delim close, Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_from_close_textblock(close, textblockarg);
    }

  }

  public static Func_textblock_from_close_textblock e_textblock_from_close_textblock = new Vx.Data.Textblock.Class_textblock_from_close_textblock();
  public static Func_textblock_from_close_textblock t_textblock_from_close_textblock = new Vx.Data.Textblock.Class_textblock_from_close_textblock();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_close_textblock(Vx.Data.Textblock.Type_delim close, Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = textblockarg.text();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Core.Type_int startpos = textblockarg.startpos();
        Vx.Core.Type_int endpos = textblockarg.endpos();
        Vx.Core.Type_int pos = close.pos();
        Vx.Core.Type_string textclose = close.starttext();
        Vx.Core.Type_int lenclose = Vx.Core.f_length(textclose);
        Vx.Core.Type_int posminus = Vx.Core.f_minus1(pos);
        Vx.Core.Type_int startleft = startpos;
        Vx.Core.Type_int startclose = Vx.Core.f_plus(startpos, posminus);
        Vx.Core.Type_int endclose = Vx.Core.f_switch(
          Vx.Core.t_int,
          textclose,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.vx_new_string(":whitespace"),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Type.f_int_from_string_findkeyword(text, Vx.Core.vx_new_string(":nonwhitespace"));
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_plus(
                    Vx.Core.f_minus1(startclose),
                    lenclose
                  );
                })
              )
          )
        );
        Vx.Core.Type_int endleft = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(Vx.Core.vx_new_int(1), pos),
          startclose,
          Vx.Core.f_minus1(startclose)
        );
        Vx.Core.Type_int startright = Vx.Core.f_plus1(endclose);
        Vx.Core.Type_int endright = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_lt(endpos, startright),
          startright,
          endpos
        );
        Vx.Core.Type_string textleft = Vx.Type.f_string_from_string_end(text, posminus);
        Vx.Core.Type_string textright = Vx.Type.f_string_from_string_start(
          text,
          Vx.Core.f_plus(pos, lenclose)
        );
        Vx.Data.Textblock.Type_textblock find = Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent);
        Vx.Data.Textblock.Type_delim closefind = find.close();
        Vx.Core.Type_string textfind = find.text();
        Vx.Core.Type_int startfind = find.startpos();
        Vx.Data.Textblock.Type_delim delimfind = find.delim();
        Vx.Data.Textblock.Type_delim delimright = Vx.Core.f_new(
          Vx.Data.Textblock.t_delim,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":delimlist"),
              delimfind.delimlist()
          )
        );
        Vx.Core.Type_int lenfind = Vx.Core.f_minus(
          Vx.Core.f_plus1(endclose),
          startfind
        );
        Vx.Core.Type_string textreplace = Vx.Type.f_string_from_string_end(textfind, lenfind);
        Vx.Data.Textblock.Type_textblock replace = Vx.Core.f_copy(
          find,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              textreplace,
              Vx.Core.vx_new_string(":endpos"),
              endclose,
              Vx.Core.vx_new_string(":delim"),
              Vx.Core.f_copy(
                delimfind,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":delimlist"),
                  Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delimlist
                  )
                )
              ),
              Vx.Core.vx_new_string(":close"),
              Vx.Data.Textblock.c_delimclosing
          )
        );
        Vx.Data.Textblock.Type_textblock parentchg = Vx.Data.Textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace);
        return Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            textleft,
            Vx.Core.vx_new_string(":startpos"),
            startleft,
            Vx.Core.vx_new_string(":endpos"),
            endleft,
            Vx.Core.vx_new_string(":parent"),
            Vx.Core.f_copy(
              textblockarg,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":text"),
                textright,
                Vx.Core.vx_new_string(":startpos"),
                startright,
                Vx.Core.vx_new_string(":endpos"),
                endright,
                Vx.Core.vx_new_string(":delim"),
                delimright,
                Vx.Core.vx_new_string(":close"),
                closefind,
                Vx.Core.vx_new_string(":parent"),
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
  public interface Func_textblock_from_empty_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_empty_textblock(Vx.Data.Textblock.Type_delim empty, Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_from_empty_textblock : Vx.Core.Class_base, Func_textblock_from_empty_textblock {

    public override Vx.Data.Textblock.Func_textblock_from_empty_textblock vx_new(params Object[] vals) {
      Class_textblock_from_empty_textblock output = new Class_textblock_from_empty_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_empty_textblock vx_copy(params Object[] vals) {
      Class_textblock_from_empty_textblock output = new Class_textblock_from_empty_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-empty-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_empty_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_empty_textblock;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim empty = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_empty_textblock(Vx.Data.Textblock.Type_delim empty, Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_from_empty_textblock(empty, textblockarg);
    }

  }

  public static Func_textblock_from_empty_textblock e_textblock_from_empty_textblock = new Vx.Data.Textblock.Class_textblock_from_empty_textblock();
  public static Func_textblock_from_empty_textblock t_textblock_from_empty_textblock = new Vx.Data.Textblock.Class_textblock_from_empty_textblock();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_empty_textblock(Vx.Data.Textblock.Type_delim empty, Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
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
  public interface Func_textblock_from_open_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_open_textblock(Vx.Data.Textblock.Type_delim open, Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_from_open_textblock : Vx.Core.Class_base, Func_textblock_from_open_textblock {

    public override Vx.Data.Textblock.Func_textblock_from_open_textblock vx_new(params Object[] vals) {
      Class_textblock_from_open_textblock output = new Class_textblock_from_open_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_open_textblock vx_copy(params Object[] vals) {
      Class_textblock_from_open_textblock output = new Class_textblock_from_open_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-open-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_open_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_open_textblock;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim open = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_open_textblock(open, textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_open_textblock(Vx.Data.Textblock.Type_delim open, Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_from_open_textblock(open, textblockarg);
    }

  }

  public static Func_textblock_from_open_textblock e_textblock_from_open_textblock = new Vx.Data.Textblock.Class_textblock_from_open_textblock();
  public static Func_textblock_from_open_textblock t_textblock_from_open_textblock = new Vx.Data.Textblock.Class_textblock_from_open_textblock();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_open_textblock(Vx.Data.Textblock.Type_delim open, Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = textblockarg.text();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Core.Type_int startpos = textblockarg.startpos();
        Vx.Core.Type_int endpos = textblockarg.endpos();
        Vx.Data.Textblock.Type_delim delima = textblockarg.delim();
        Vx.Core.Type_int pos = open.pos();
        Vx.Core.Type_string textopen = open.starttext();
        Vx.Core.Type_string textclose = open.endtext();
        Vx.Data.Textblock.Type_delimlist delimlistl = open.delimlist();
        Vx.Core.Type_int lenopen = Vx.Core.f_length(textopen);
        Vx.Core.Type_int posminus = Vx.Core.f_minus1(pos);
        Vx.Core.Type_int startleft = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(pos, Vx.Core.vx_new_int(1)),
          Vx.Core.f_minus1(startpos),
          startpos
        );
        Vx.Core.Type_int endleft = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(pos, Vx.Core.vx_new_int(1)),
          Vx.Core.f_minus1(startpos),
          Vx.Core.f_plus(
            Vx.Core.f_minus1(startleft),
            posminus
          )
        );
        Vx.Core.Type_int startright = Vx.Core.f_plus_2(
          Vx.Core.vx_new(Vx.Core.t_intlist,
              startpos,
              posminus,
              lenopen
          )
        );
        Vx.Core.Type_int startopen = Vx.Core.f_plus(startpos, posminus);
        Vx.Core.Type_string textleft = Vx.Type.f_string_from_string_end(text, posminus);
        Vx.Core.Type_string textpar = Vx.Type.f_string_from_string_start(text, pos);
        Vx.Core.Type_string textright = Vx.Type.f_string_from_string_start(
          text,
          Vx.Core.f_plus(pos, lenopen)
        );
        Vx.Data.Textblock.Type_delim close = Vx.Core.f_copy(
          Vx.Data.Textblock.c_delimclose,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":starttext"),
              textclose
          )
        );
        Vx.Data.Textblock.Type_textblock tbleft = Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eq(Vx.Core.vx_new_string(""), textleft);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_empty(
                    Vx.Data.Textblock.t_textblock
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":text"),
                        textleft,
                        Vx.Core.vx_new_string(":startpos"),
                        startleft,
                        Vx.Core.vx_new_string(":endpos"),
                        endleft
                    )
                  );
                })
              )
          )
        );
        Vx.Data.Textblock.Type_textblock tbpar1 = Vx.Core.f_copy(
          textblockarg,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              textpar,
              Vx.Core.vx_new_string(":startpos"),
              startopen,
              Vx.Core.vx_new_string(":delim"),
              Vx.Core.f_copy(
                open,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":pos"),
                  Vx.Core.vx_new_int(0),
                  Vx.Core.vx_new_string(":delimlist"),
                  delima.delimlist()
                )
              ),
              Vx.Core.vx_new_string(":parent"),
              parent
          )
        );
        Vx.Data.Textblock.Type_textblock tbfind = Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eq(Vx.Core.vx_new_string(""), textleft);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_empty(
                    Vx.Data.Textblock.t_textblock
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Data.Textblock.f_textblock_findparent_from_textblock(parent);
                })
              )
          )
        );
        Vx.Data.Textblock.Type_textblock tbparent = Vx.Core.f_if_2(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_is_empty_1(tbfind);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return tbpar1;
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Data.Textblock.f_textblock_addchild_from_textblock_find_child(tbpar1, tbfind, tbleft);
                })
              )
          )
        );
        return Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            textright,
            Vx.Core.vx_new_string(":startpos"),
            startright,
            Vx.Core.vx_new_string(":endpos"),
            endpos,
            Vx.Core.vx_new_string(":delim"),
            Vx.Core.f_new(
              Vx.Data.Textblock.t_delim,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            Vx.Core.vx_new_string(":close"),
            close,
            Vx.Core.vx_new_string(":parent"),
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
  public interface Func_textblock_from_single_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_single_textblock(Vx.Data.Textblock.Type_delim single, Vx.Data.Textblock.Type_textblock textblockarg);
  }

  public class Class_textblock_from_single_textblock : Vx.Core.Class_base, Func_textblock_from_single_textblock {

    public override Vx.Data.Textblock.Func_textblock_from_single_textblock vx_new(params Object[] vals) {
      Class_textblock_from_single_textblock output = new Class_textblock_from_single_textblock();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_single_textblock vx_copy(params Object[] vals) {
      Class_textblock_from_single_textblock output = new Class_textblock_from_single_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-single-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_single_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_single_textblock;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_delim single = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock textblockarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_single_textblock(single, textblockarg);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_single_textblock(Vx.Data.Textblock.Type_delim single, Vx.Data.Textblock.Type_textblock textblockarg) {
      return Vx.Data.Textblock.f_textblock_from_single_textblock(single, textblockarg);
    }

  }

  public static Func_textblock_from_single_textblock e_textblock_from_single_textblock = new Vx.Data.Textblock.Class_textblock_from_single_textblock();
  public static Func_textblock_from_single_textblock t_textblock_from_single_textblock = new Vx.Data.Textblock.Class_textblock_from_single_textblock();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_single_textblock(Vx.Data.Textblock.Type_delim single, Vx.Data.Textblock.Type_textblock textblockarg) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_let(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = textblockarg.text();
        Vx.Data.Textblock.Type_textblock parent = textblockarg.parent();
        Vx.Core.Type_int startpos = textblockarg.startpos();
        Vx.Core.Type_int endpos = textblockarg.endpos();
        Vx.Core.Type_int pos = single.pos();
        Vx.Core.Type_string origsingle = single.starttext();
        Vx.Core.Type_string textsingle = Vx.Core.f_switch(
          Vx.Core.t_string,
          origsingle,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.vx_new_string(":whitespace"),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_let(
                    Vx.Core.t_string,
                    Vx.Core.t_any_from_func.vx_fn_new(() => {
                      Vx.Core.Type_string text2 = Vx.Type.f_string_from_string_start(text, pos);
                      Vx.Core.Type_int pos2 = Vx.Type.f_int_from_string_findkeyword(text2, Vx.Core.vx_new_string(":nonwhitespace"));
                      Vx.Core.Type_int pos3 = Vx.Core.f_if_2(
                        Vx.Core.t_int,
                        Vx.Core.vx_new(Vx.Core.t_thenelselist,
                            Vx.Core.f_then(
                              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                return Vx.Core.f_eq(Vx.Core.vx_new_int(0), pos2);
                              }),
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Core.f_length(text2);
                              })
                            ),
                            Vx.Core.f_then(
                              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                return Vx.Core.f_eq(pos2, pos);
                              }),
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return pos2;
                              })
                            ),
                            Vx.Core.f_else(
                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                return Vx.Core.f_minus1(pos2);
                              })
                            )
                        )
                      );
                      return Vx.Type.f_string_from_string_start_end(text, pos, pos3);
                    })
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return origsingle;
                })
              )
          )
        );
        Vx.Data.Textblock.Type_delimlist delimlistl = single.delimlist();
        Vx.Core.Type_int lensingle = Vx.Core.f_length(textsingle);
        Vx.Core.Type_int posminus = Vx.Core.f_minus1(pos);
        Vx.Core.Type_int startleft = startpos;
        Vx.Core.Type_int startsingle = Vx.Core.f_plus(startpos, posminus);
        Vx.Core.Type_int endsingle = Vx.Core.f_switch(
          Vx.Core.t_int,
          textsingle,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.vx_new_string(":whitespace"),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Type.f_int_from_string_findkeyword(text, Vx.Core.vx_new_string(":nonwhitespace"));
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_plus(
                    Vx.Core.f_minus1(startsingle),
                    lensingle
                  );
                })
              )
          )
        );
        Vx.Core.Type_int endleft = Vx.Core.f_if_1(
          Vx.Core.t_int,
          Vx.Core.f_eq(startsingle, startpos),
          startsingle,
          Vx.Core.f_minus1(startsingle)
        );
        Vx.Core.Type_int startright = Vx.Core.f_plus1(endsingle);
        Vx.Core.Type_string textleft = Vx.Type.f_string_from_string_end(text, posminus);
        Vx.Core.Type_string textpar = Vx.Type.f_string_from_string_start(text, pos);
        Vx.Core.Type_string textright = Vx.Type.f_string_from_string_start(
          text,
          Vx.Core.f_plus(pos, lensingle)
        );
        return Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            textleft,
            Vx.Core.vx_new_string(":startpos"),
            startleft,
            Vx.Core.vx_new_string(":endpos"),
            endleft,
            Vx.Core.vx_new_string(":delim"),
            Vx.Core.f_new(
              Vx.Data.Textblock.t_delim,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":delimlist"),
                delimlistl
              )
            ),
            Vx.Core.vx_new_string(":parent"),
            Vx.Core.f_new(
              Vx.Data.Textblock.t_textblock,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":text"),
                textsingle,
                Vx.Core.vx_new_string(":startpos"),
                startsingle,
                Vx.Core.vx_new_string(":endpos"),
                endsingle,
                Vx.Core.vx_new_string(":delim"),
                Vx.Core.f_copy(
                  single,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":pos"),
                    Vx.Core.vx_new_int(0),
                    Vx.Core.vx_new_string(":delimlist"),
                    Vx.Core.f_empty(
                      Vx.Data.Textblock.t_delimlist
                    )
                  )
                ),
                Vx.Core.vx_new_string(":parent"),
                Vx.Core.f_copy(
                  textblockarg,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    textright,
                    Vx.Core.vx_new_string(":startpos"),
                    startright,
                    Vx.Core.vx_new_string(":endpos"),
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
  public interface Func_textblock_from_string_delim : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim);
  }

  public class Class_textblock_from_string_delim : Vx.Core.Class_base, Func_textblock_from_string_delim {

    public override Vx.Data.Textblock.Func_textblock_from_string_delim vx_new(params Object[] vals) {
      Class_textblock_from_string_delim output = new Class_textblock_from_string_delim();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_string_delim vx_copy(params Object[] vals) {
      Class_textblock_from_string_delim output = new Class_textblock_from_string_delim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-string-delim", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_string_delim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_string_delim;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_string_delim(text, delim);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
      return Vx.Data.Textblock.f_textblock_from_string_delim(text, delim);
    }

  }

  public static Func_textblock_from_string_delim e_textblock_from_string_delim = new Vx.Data.Textblock.Class_textblock_from_string_delim();
  public static Func_textblock_from_string_delim t_textblock_from_string_delim = new Vx.Data.Textblock.Class_textblock_from_string_delim();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_string_delim(Vx.Core.Type_string text, Vx.Data.Textblock.Type_delim delim) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_new(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":text"),
        text,
        Vx.Core.vx_new_string(":delim"),
        delim,
        Vx.Core.vx_new_string(":startpos"),
        Vx.Core.vx_new_int(0),
        Vx.Core.vx_new_string(":endpos"),
        Vx.Core.f_length(text)
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
  public interface Func_textblock_from_textblock_delim : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_textblock_delim(Vx.Data.Textblock.Type_textblock textblock, Vx.Data.Textblock.Type_delim delim);
  }

  public class Class_textblock_from_textblock_delim : Vx.Core.Class_base, Func_textblock_from_textblock_delim {

    public override Vx.Data.Textblock.Func_textblock_from_textblock_delim vx_new(params Object[] vals) {
      Class_textblock_from_textblock_delim output = new Class_textblock_from_textblock_delim();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblock_from_textblock_delim vx_copy(params Object[] vals) {
      Class_textblock_from_textblock_delim output = new Class_textblock_from_textblock_delim();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblock<-textblock-delim", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_textblock_delim;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_textblock_delim;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim delim = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblock_from_textblock_delim(textblock, delim);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_textblock_delim(Vx.Data.Textblock.Type_textblock textblock, Vx.Data.Textblock.Type_delim delim) {
      return Vx.Data.Textblock.f_textblock_from_textblock_delim(textblock, delim);
    }

  }

  public static Func_textblock_from_textblock_delim e_textblock_from_textblock_delim = new Vx.Data.Textblock.Class_textblock_from_textblock_delim();
  public static Func_textblock_from_textblock_delim t_textblock_from_textblock_delim = new Vx.Data.Textblock.Class_textblock_from_textblock_delim();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_textblock_delim(Vx.Data.Textblock.Type_textblock textblock, Vx.Data.Textblock.Type_delim delim) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
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
  public interface Func_textblocklist_from_textblocklist_remove : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(Vx.Data.Textblock.Type_textblocklist tblist, Vx.Data.Textblock.Type_delim remove);
  }

  public class Class_textblocklist_from_textblocklist_remove : Vx.Core.Class_base, Func_textblocklist_from_textblocklist_remove {

    public override Vx.Data.Textblock.Func_textblocklist_from_textblocklist_remove vx_new(params Object[] vals) {
      Class_textblocklist_from_textblocklist_remove output = new Class_textblocklist_from_textblocklist_remove();
      return output;
    }

    public override Vx.Data.Textblock.Func_textblocklist_from_textblocklist_remove vx_copy(params Object[] vals) {
      Class_textblocklist_from_textblocklist_remove output = new Class_textblocklist_from_textblocklist_remove();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "textblocklist<-textblocklist-remove", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblocklist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Textblock.t_textblock), // allowtypes
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
      return e_textblocklist_from_textblocklist_remove;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblocklist_from_textblocklist_remove;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblocklist tblist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblocklist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_delim remove = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_delim, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
      return output;
    }

    public Vx.Data.Textblock.Type_textblocklist vx_textblocklist_from_textblocklist_remove(Vx.Data.Textblock.Type_textblocklist tblist, Vx.Data.Textblock.Type_delim remove) {
      return Vx.Data.Textblock.f_textblocklist_from_textblocklist_remove(tblist, remove);
    }

  }

  public static Func_textblocklist_from_textblocklist_remove e_textblocklist_from_textblocklist_remove = new Vx.Data.Textblock.Class_textblocklist_from_textblocklist_remove();
  public static Func_textblocklist_from_textblocklist_remove t_textblocklist_from_textblocklist_remove = new Vx.Data.Textblock.Class_textblocklist_from_textblocklist_remove();

  public static Vx.Data.Textblock.Type_textblocklist f_textblocklist_from_textblocklist_remove(Vx.Data.Textblock.Type_textblocklist tblist, Vx.Data.Textblock.Type_delim remove) {
    Vx.Data.Textblock.Type_textblocklist output = Vx.Data.Textblock.e_textblocklist;
    output = Vx.Collection.f_list_from_list_filter(
      Vx.Data.Textblock.t_textblocklist,
      tblist,
      Vx.Core.t_any_from_any.vx_fn_new((textblock_any) => {
        Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, textblock_any);
        return 
        Vx.Core.f_let(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            Vx.Data.Textblock.Type_delim delimcurr = textblock.delim();
            Vx.Core.Type_string namecurr = delimcurr.name();
            Vx.Core.Type_string nameremove = remove.name();
            return Vx.Core.f_if(
              Vx.Data.Textblock.t_textblock,
              Vx.Core.f_ne(namecurr, nameremove),
              textblock
            );
          })
        );
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
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
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("delim", Vx.Data.Textblock.t_delim);
    maptype.put("delimlist", Vx.Data.Textblock.t_delimlist);
    maptype.put("textblock", Vx.Data.Textblock.t_textblock);
    maptype.put("textblocklist", Vx.Data.Textblock.t_textblocklist);
    mapconst.put("delimbracketangle", Vx.Data.Textblock.c_delimbracketangle);
    mapconst.put("delimbracketcurly", Vx.Data.Textblock.c_delimbracketcurly);
    mapconst.put("delimbracketsquare", Vx.Data.Textblock.c_delimbracketsquare);
    mapconst.put("delimclose", Vx.Data.Textblock.c_delimclose);
    mapconst.put("delimclosing", Vx.Data.Textblock.c_delimclosing);
    mapconst.put("delimcomma", Vx.Data.Textblock.c_delimcomma);
    mapconst.put("delimcomment", Vx.Data.Textblock.c_delimcomment);
    mapconst.put("delimcommentblock", Vx.Data.Textblock.c_delimcommentblock);
    mapconst.put("delimline", Vx.Data.Textblock.c_delimline);
    mapconst.put("delimlisttest1", Vx.Data.Textblock.c_delimlisttest1);
    mapconst.put("delimlisttest2", Vx.Data.Textblock.c_delimlisttest2);
    mapconst.put("delimlisttest3", Vx.Data.Textblock.c_delimlisttest3);
    mapconst.put("delimnonwhitespace", Vx.Data.Textblock.c_delimnonwhitespace);
    mapconst.put("delimparen", Vx.Data.Textblock.c_delimparen);
    mapconst.put("delimquote", Vx.Data.Textblock.c_delimquote);
    mapconst.put("delimquoteblock", Vx.Data.Textblock.c_delimquoteblock);
    mapconst.put("delimspace", Vx.Data.Textblock.c_delimspace);
    mapconst.put("delimtest1", Vx.Data.Textblock.c_delimtest1);
    mapconst.put("delimtest2", Vx.Data.Textblock.c_delimtest2);
    mapconst.put("delimtest3", Vx.Data.Textblock.c_delimtest3);
    mapconst.put("delimtext", Vx.Data.Textblock.c_delimtext);
    mapconst.put("delimwhitespace", Vx.Data.Textblock.c_delimwhitespace);
    mapfunc.put("children<-textblock", Vx.Data.Textblock.t_children_from_textblock);
    mapfunc.put("delim-first<-delim-delim", Vx.Data.Textblock.t_delim_first_from_delim_delim);
    mapfunc.put("delim-first<-string-delimlist", Vx.Data.Textblock.t_delim_first_from_string_delimlist);
    mapfunc.put("delim-pos<-string-delim", Vx.Data.Textblock.t_delim_pos_from_string_delim);
    mapfunc.put("delimlist-pos<-string-delimlist", Vx.Data.Textblock.t_delimlist_pos_from_string_delimlist);
    mapfunc.put("is-close", Vx.Data.Textblock.t_is_close);
    mapfunc.put("is-single", Vx.Data.Textblock.t_is_single);
    mapfunc.put("stringlist<-textblocklist", Vx.Data.Textblock.t_stringlist_from_textblocklist);
    mapfunc.put("text<-textblock", Vx.Data.Textblock.t_text_from_textblock);
    mapfunc.put("textblock-addchild<-textblock-find-child", Vx.Data.Textblock.t_textblock_addchild_from_textblock_find_child);
    mapfunc.put("textblock-delimnotfound", Vx.Data.Textblock.t_textblock_delimnotfound);
    mapfunc.put("textblock-findparent<-textblock", Vx.Data.Textblock.t_textblock_findparent_from_textblock);
    mapfunc.put("textblock-init", Vx.Data.Textblock.t_textblock_init);
    mapfunc.put("textblock-parse", Vx.Data.Textblock.t_textblock_parse);
    mapfunc.put("textblock-parse-one", Vx.Data.Textblock.t_textblock_parse_one);
    mapfunc.put("textblock-parse<-string-delim", Vx.Data.Textblock.t_textblock_parse_from_string_delim);
    mapfunc.put("textblock-replace<-textblock-find-replace", Vx.Data.Textblock.t_textblock_replace_from_textblock_find_replace);
    mapfunc.put("textblock-startleft<-string-delim-offset", Vx.Data.Textblock.t_textblock_startleft_from_string_delim_offset);
    mapfunc.put("textblock-startright<-string-delim-offset", Vx.Data.Textblock.t_textblock_startright_from_string_delim_offset);
    mapfunc.put("textblock<-close-textblock", Vx.Data.Textblock.t_textblock_from_close_textblock);
    mapfunc.put("textblock<-empty-textblock", Vx.Data.Textblock.t_textblock_from_empty_textblock);
    mapfunc.put("textblock<-open-textblock", Vx.Data.Textblock.t_textblock_from_open_textblock);
    mapfunc.put("textblock<-single-textblock", Vx.Data.Textblock.t_textblock_from_single_textblock);
    mapfunc.put("textblock<-string-delim", Vx.Data.Textblock.t_textblock_from_string_delim);
    mapfunc.put("textblock<-textblock-delim", Vx.Data.Textblock.t_textblock_from_textblock_delim);
    mapfunc.put("textblocklist<-textblocklist-remove", Vx.Data.Textblock.t_textblocklist_from_textblocklist_remove);
    Vx.Core.vx_global_package_set("vx/data/textblock", maptype, mapconst, mapfunc);
    }
  }

}
