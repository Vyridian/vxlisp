package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;


public final class Textblock {


  /**
   * type: delimset
   * (type delimset)
   */
  public interface Type_delimset extends Core.Type_struct {
    public Textblock.Type_delimset vx_new(final Object... vals);
    public Textblock.Type_delimset vx_copy(final Object... vals);
    public Textblock.Type_delimset vx_empty();
    public Textblock.Type_delimset vx_type();
    public Core.Type_stringlist start();
    public Core.Type_stringlist end();
    public Core.Type_stringlist split();
    public Textblock.Type_delimset subset();
  }

  public static class Class_delimset extends Core.Class_base implements Type_delimset {

    protected Core.Type_stringlist vx_p_start;

    @Override
    public Core.Type_stringlist start() {
      return this.vx_p_start == null ? Core.e_stringlist : this.vx_p_start;
    }

    protected Core.Type_stringlist vx_p_end;

    @Override
    public Core.Type_stringlist end() {
      return this.vx_p_end == null ? Core.e_stringlist : this.vx_p_end;
    }

    protected Core.Type_stringlist vx_p_split;

    @Override
    public Core.Type_stringlist split() {
      return this.vx_p_split == null ? Core.e_stringlist : this.vx_p_split;
    }

    protected Textblock.Type_delimset vx_p_subset;

    @Override
    public Textblock.Type_delimset subset() {
      return this.vx_p_subset == null ? Textblock.e_delimset : this.vx_p_subset;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":start":
        output = this.start();
        break;
      case ":end":
        output = this.end();
        break;
      case ":split":
        output = this.split();
        break;
      case ":subset":
        output = this.subset();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":start", this.start());
      output.put(":end", this.end());
      output.put(":split", this.split());
      output.put(":subset", this.subset());
      return Core.immutablemap(output);
    }

    @Override
    public Type_delimset vx_new(final Object... vals) {return e_delimset.vx_copy(vals);}

    @Override
    public Type_delimset vx_copy(final Object... vals) {
      Class_delimset output = new Class_delimset();
      Type_delimset val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_start = val.start();
      output.vx_p_end = val.end();
      output.vx_p_split = val.split();
      output.vx_p_subset = val.subset();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":start");
      validkeys.add(":end");
      validkeys.add(":split");
      validkeys.add(":subset");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":start":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_start = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset :start " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":end":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_end = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset :end " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":split":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_split = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset :split " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":subset":
            if (valsub instanceof Textblock.Type_delimset) {
              output.vx_p_subset = (Textblock.Type_delimset)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset :subset " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new delimset) - Invalid Key: " + key);
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
    public Type_delimset vx_empty() {return e_delimset;}
    @Override
    public Type_delimset vx_type() {return t_delimset;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/textblock", // pkgname
        "delimset", // name
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

  public static final Type_delimset e_delimset = new Class_delimset();
  public static final Type_delimset t_delimset = new Class_delimset();

  /**
   * type: textblock
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
    public Textblock.Type_textblocklist textblocks();
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

    protected Textblock.Type_textblocklist vx_p_textblocks;

    @Override
    public Textblock.Type_textblocklist textblocks() {
      return this.vx_p_textblocks == null ? Textblock.e_textblocklist : this.vx_p_textblocks;
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
      case ":textblocks":
        output = this.textblocks();
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
      output.put(":textblocks", this.textblocks());
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
      output.vx_p_textblocks = val.textblocks();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":text");
      validkeys.add(":line");
      validkeys.add(":column");
      validkeys.add(":textblocks");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock) - Invalid Key Type: " + valsub.toString());
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
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":line":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_line = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_line = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock :line " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":column":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_column = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_column = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock :column " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":textblocks":
            if (valsub instanceof Textblock.Type_textblocklist) {
              output.vx_p_textblocks = (Textblock.Type_textblocklist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock :textblocks " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblock) - Invalid Key: " + key);
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

    protected List<Textblock.Type_textblock> vxlist = Core.immutablelist(new ArrayList<Textblock.Type_textblock>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Textblock.Type_textblock vx_textblock(final Core.Type_int index) {
      Textblock.Type_textblock output = Textblock.e_textblock;
      Class_textblocklist list = this;
      int iindex = index.vx_int();
      List<Textblock.Type_textblock> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Textblock.Type_textblock> vx_listtextblock() {return vxlist;}

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
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new textblocklist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
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
   * @function parse
   * @param  {textblock} block
   * @param  {delimset} delimpairlist
   * @return {textblock}
   * (func parse)
   */
  public static interface Func_parse extends Core.Type_func, Core.Type_replfunc {
    public Textblock.Type_textblock f_parse(final Textblock.Type_textblock block, final Textblock.Type_delimset delimpairlist);
  }

  public static class Class_parse extends Core.Class_base implements Func_parse {

    @Override
    public Func_parse vx_new(Object... vals) {
      Class_parse output = new Class_parse();
      return output;
    }

    @Override
    public Func_parse vx_copy(Object... vals) {
      Class_parse output = new Class_parse();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/textblock", // pkgname
        "parse", // name
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
    public Func_parse vx_empty() {return e_parse;}
    @Override
    public Func_parse vx_type() {return t_parse;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Textblock.Type_delimset delimpairlist = Core.f_any_from_any(Textblock.t_delimset, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Textblock.f_parse(block, delimpairlist);
      return output;
    }

    @Override
    public Textblock.Type_textblock f_parse(final Textblock.Type_textblock block, final Textblock.Type_delimset delimpairlist) {
      return Textblock.f_parse(block, delimpairlist);
    }

  }

  public static final Func_parse e_parse = new Textblock.Class_parse();
  public static final Func_parse t_parse = new Textblock.Class_parse();

  public static Textblock.Type_textblock f_parse(final Textblock.Type_textblock block, final Textblock.Type_delimset delimpairlist) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = block;
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

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
      Textblock.Type_textblocklist textblocks = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
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
          "string", // extends
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

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
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

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
      Textblock.Type_textblock block = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
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


}
