package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;


public final class Xml {


  /**
   * type: xml
   * (type xml)
   */
  public interface Type_xml extends Core.Type_struct {
    public Xml.Type_xml vx_new(final Object... vals);
    public Xml.Type_xml vx_copy(final Object... vals);
    public Xml.Type_xml vx_empty();
    public Xml.Type_xml vx_type();
    public Xml.Type_xmlnodelist nodes();
  }

  public static class Class_xml extends Core.Class_base implements Type_xml {

    protected Xml.Type_xmlnodelist vx_p_nodes;

    @Override
    public Xml.Type_xmlnodelist nodes() {
      return this.vx_p_nodes == null ? Xml.e_xmlnodelist : this.vx_p_nodes;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":nodes", this.nodes());
      return Core.immutablemap(output);
    }

    @Override
    public Type_xml vx_new(final Object... vals) {return e_xml.vx_copy(vals);}

    @Override
    public Type_xml vx_copy(final Object... vals) {
      Class_xml output = new Class_xml();
      Type_xml val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_nodes = val.nodes();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":nodes");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new xml) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":nodes":
            if (valsub instanceof Xml.Type_xmlnodelist) {
              output.vx_p_nodes = (Xml.Type_xmlnodelist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new xml :nodes " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new xml) - Invalid Key: " + key);
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
    public Type_xml vx_empty() {return e_xml;}
    @Override
    public Type_xml vx_type() {return t_xml;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/xml", // pkgname
        "xml", // name
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

  public static final Type_xml e_xml = new Class_xml();
  public static final Type_xml t_xml = new Class_xml();

  /**
   * type: xmlnode
   * (type xmlnode)
   */
  public interface Type_xmlnode extends Core.Type_struct {
    public Xml.Type_xmlnode vx_new(final Object... vals);
    public Xml.Type_xmlnode vx_copy(final Object... vals);
    public Xml.Type_xmlnode vx_empty();
    public Xml.Type_xmlnode vx_type();
    public Xml.Type_xmlnode nodes();
    public Xml.Type_xmlpropmap props();
    public Core.Type_string tag();
    public Core.Type_string text();
  }

  public static class Class_xmlnode extends Core.Class_base implements Type_xmlnode {

    protected Xml.Type_xmlnode vx_p_nodes;

    @Override
    public Xml.Type_xmlnode nodes() {
      return this.vx_p_nodes == null ? Xml.e_xmlnode : this.vx_p_nodes;
    }

    protected Xml.Type_xmlpropmap vx_p_props;

    @Override
    public Xml.Type_xmlpropmap props() {
      return this.vx_p_props == null ? Xml.e_xmlpropmap : this.vx_p_props;
    }

    protected Core.Type_string vx_p_tag;

    @Override
    public Core.Type_string tag() {
      return this.vx_p_tag == null ? Core.e_string : this.vx_p_tag;
    }

    protected Core.Type_string vx_p_text;

    @Override
    public Core.Type_string text() {
      return this.vx_p_text == null ? Core.e_string : this.vx_p_text;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":nodes":
        output = this.nodes();
        break;
      case ":props":
        output = this.props();
        break;
      case ":tag":
        output = this.tag();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":nodes", this.nodes());
      output.put(":props", this.props());
      output.put(":tag", this.tag());
      output.put(":text", this.text());
      return Core.immutablemap(output);
    }

    @Override
    public Type_xmlnode vx_new(final Object... vals) {return e_xmlnode.vx_copy(vals);}

    @Override
    public Type_xmlnode vx_copy(final Object... vals) {
      Class_xmlnode output = new Class_xmlnode();
      Type_xmlnode val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_nodes = val.nodes();
      output.vx_p_props = val.props();
      output.vx_p_tag = val.tag();
      output.vx_p_text = val.text();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":nodes");
      validkeys.add(":props");
      validkeys.add(":tag");
      validkeys.add(":text");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":nodes":
            if (valsub instanceof Xml.Type_xmlnode) {
              output.vx_p_nodes = (Xml.Type_xmlnode)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode :nodes " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":props":
            if (valsub instanceof Xml.Type_xmlpropmap) {
              output.vx_p_props = (Xml.Type_xmlpropmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode :props " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":tag":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_tag = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_tag = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode :tag " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnode) - Invalid Key: " + key);
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
    public Type_xmlnode vx_empty() {return e_xmlnode;}
    @Override
    public Type_xmlnode vx_type() {return t_xmlnode;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmlnode", // name
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

  public static final Type_xmlnode e_xmlnode = new Class_xmlnode();
  public static final Type_xmlnode t_xmlnode = new Class_xmlnode();

  /**
   * type: xmlnodelist
   * (type xmlnodelist)
   */
  public interface Type_xmlnodelist extends Core.Type_list {
    public Xml.Type_xmlnodelist vx_new(final Object... vals);
    public Xml.Type_xmlnodelist vx_copy(final Object... vals);
    public Xml.Type_xmlnodelist vx_empty();
    public Xml.Type_xmlnodelist vx_type();
    public List<Xml.Type_xmlnode> vx_listxmlnode();
    public Xml.Type_xmlnode vx_xmlnode(final Core.Type_int index);
  }

  public static class Class_xmlnodelist extends Core.Class_base implements Type_xmlnodelist {

    protected List<Xml.Type_xmlnode> vxlist = Core.immutablelist(new ArrayList<Xml.Type_xmlnode>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Xml.Type_xmlnode vx_xmlnode(final Core.Type_int index) {
      Xml.Type_xmlnode output = Xml.e_xmlnode;
      Class_xmlnodelist list = this;
      int iindex = index.vx_int();
      List<Xml.Type_xmlnode> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Xml.Type_xmlnode> vx_listxmlnode() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_xmlnode(index);
    }

    @Override
    public Type_xmlnodelist vx_new(final Object... vals) {return e_xmlnodelist.vx_copy(vals);}

    @Override
    public Type_xmlnodelist vx_copy(final Object... vals) {
      Class_xmlnodelist output = new Class_xmlnodelist();
      Type_xmlnodelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Xml.Type_xmlnode> listval = new ArrayList<>(val.vx_listxmlnode());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Xml.Type_xmlnode) {
          listval.add((Xml.Type_xmlnode)valsub);
        } else if (valsub instanceof Xml.Type_xmlnode) {
          listval.add((Xml.Type_xmlnode)valsub);
        } else if (valsub instanceof Type_xmlnodelist) {
          Type_xmlnodelist multi = (Type_xmlnodelist)valsub;
          listval.addAll(multi.vx_listxmlnode());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Xml.Type_xmlnode) {
              Xml.Type_xmlnode valitem = (Xml.Type_xmlnode)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new xmlnodelist) - Invalid Type: " + valsub.toString());
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
    public Type_xmlnodelist vx_empty() {return e_xmlnodelist;}
    @Override
    public Type_xmlnodelist vx_type() {return t_xmlnodelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmlnodelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Xml.t_xmlnode), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_xmlnodelist e_xmlnodelist = new Class_xmlnodelist();
  public static final Type_xmlnodelist t_xmlnodelist = new Class_xmlnodelist();

  /**
   * type: xmlpropmap
   * (type xmlpropmap)
   */
  public interface Type_xmlpropmap extends Core.Type_map {
    public Xml.Type_xmlpropmap vx_new(final Object... vals);
    public Xml.Type_xmlpropmap vx_copy(final Object... vals);
    public Xml.Type_xmlpropmap vx_empty();
    public Xml.Type_xmlpropmap vx_type();
    public Map<String, Core.Type_string> vx_mapstring();
    public Core.Type_string vx_string(final Core.Type_string key);
  }

  public static class Class_xmlpropmap extends Core.Class_base implements Type_xmlpropmap {

    protected Map<String, Core.Type_string> vxmap = Core.immutablemap(new LinkedHashMap<String, Core.Type_string>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}

    @Override
    public Core.Type_string vx_string(final Core.Type_string key) {
      Core.Type_string output = Core.e_string;
      Class_xmlpropmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_string> mapval = map.vxmap;
      output = mapval.getOrDefault(skey, Core.e_string);
      return output;
    }

    @Override
    public Map<String, Core.Type_string> vx_mapstring() {return vxmap;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_string(key);
    }

    @Override
    public Type_xmlpropmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_xmlpropmap output = new Class_xmlpropmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_string> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_string) {
          Core.Type_string castval = (Core.Type_string)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(xmlpropmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vxmap = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_xmlpropmap vx_new(final Object... vals) {return e_xmlpropmap.vx_copy(vals);}

    @Override
    public Type_xmlpropmap vx_copy(final Object... vals) {
      Class_xmlpropmap output = new Class_xmlpropmap();
      Type_xmlpropmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_string> mapval = new LinkedHashMap<>(valmap.vx_mapstring());
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_string valany = null;
          if (valsub instanceof Core.Type_string) {
            valany = (Core.Type_string)valsub;
          } else if (valsub instanceof String) {
            valany = Core.t_string.vx_new(valsub);;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      output.vxmap = Core.immutablemap(mapval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_xmlpropmap vx_empty() {return e_xmlpropmap;}
    @Override
    public Type_xmlpropmap vx_type() {return t_xmlpropmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmlpropmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_string), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_xmlpropmap e_xmlpropmap = new Class_xmlpropmap();
  public static final Type_xmlpropmap t_xmlpropmap = new Class_xmlpropmap();
  /**
   * @function xml_from_textblock
   * @param  {textblock} textblock
   * @return {xml}
   * (func xml<-textblock)
   */
  public static interface Func_xml_from_textblock extends Core.Func_any_from_any {
    public Xml.Type_xml f_xml_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_xml_from_textblock extends Core.Class_base implements Func_xml_from_textblock {

    @Override
    public Func_xml_from_textblock vx_new(Object... vals) {
      Class_xml_from_textblock output = new Class_xml_from_textblock();
      return output;
    }

    @Override
    public Func_xml_from_textblock vx_copy(Object... vals) {
      Class_xml_from_textblock output = new Class_xml_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
    public Func_xml_from_textblock vx_empty() {return e_xml_from_textblock;}
    @Override
    public Func_xml_from_textblock vx_type() {return t_xml_from_textblock;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Xml.f_xml_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Xml.f_xml_from_textblock(textblock);
      return output;
    }

    @Override
    public Xml.Type_xml f_xml_from_textblock(final Textblock.Type_textblock textblock) {
      return Xml.f_xml_from_textblock(textblock);
    }

  }

  public static final Func_xml_from_textblock e_xml_from_textblock = new Xml.Class_xml_from_textblock();
  public static final Func_xml_from_textblock t_xml_from_textblock = new Xml.Class_xml_from_textblock();

  public static Xml.Type_xml f_xml_from_textblock(final Textblock.Type_textblock textblock) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_empty(
      Xml.t_xml
    );
    return output;
  }


}
