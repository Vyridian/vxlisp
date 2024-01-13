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
    public Core.Type_string tag();
    public Core.Type_string text();
    public Core.Type_string prop();
    public Core.Type_stringmap propmap();
    public Xml.Type_xmllist children();
    public Xml.Type_xml parent();
  }

  public static class Class_xml extends Core.Class_base implements Type_xml {

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

    protected Core.Type_string vx_p_prop;

    @Override
    public Core.Type_string prop() {
      return this.vx_p_prop == null ? Core.e_string : this.vx_p_prop;
    }

    protected Core.Type_stringmap vx_p_propmap;

    @Override
    public Core.Type_stringmap propmap() {
      return this.vx_p_propmap == null ? Core.e_stringmap : this.vx_p_propmap;
    }

    protected Xml.Type_xmllist vx_p_children;

    @Override
    public Xml.Type_xmllist children() {
      return this.vx_p_children == null ? Xml.e_xmllist : this.vx_p_children;
    }

    protected Xml.Type_xml vx_p_parent;

    @Override
    public Xml.Type_xml parent() {
      return this.vx_p_parent == null ? Xml.e_xml : this.vx_p_parent;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":tag":
        output = this.tag();
        break;
      case ":text":
        output = this.text();
        break;
      case ":prop":
        output = this.prop();
        break;
      case ":propmap":
        output = this.propmap();
        break;
      case ":children":
        output = this.children();
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
      output.put(":tag", this.tag());
      output.put(":text", this.text());
      output.put(":prop", this.prop());
      output.put(":propmap", this.propmap());
      output.put(":children", this.children());
      output.put(":parent", this.parent());
      return Core.immutablemap(output);
    }

    @Override
    public Type_xml vx_new(final Object... vals) {return e_xml.vx_copy(vals);}

    @Override
    public Type_xml vx_copy(final Object... vals) {
      Type_xml output = this;
      boolean ischanged = false;
      Class_xml val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_tag = val.tag();
      Core.Type_string vx_p_text = val.text();
      Core.Type_string vx_p_prop = val.prop();
      Core.Type_stringmap vx_p_propmap = val.propmap();
      Xml.Type_xmllist vx_p_children = val.children();
      Xml.Type_xml vx_p_parent = val.parent();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":tag");
      validkeys.add(":text");
      validkeys.add(":prop");
      validkeys.add(":propmap");
      validkeys.add(":children");
      validkeys.add(":parent");
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
            String svalsub;
            if (valsub instanceof Core.Type_any) {
              Core.Type_any anyvalsub = (Core.Type_any)valsub;
              svalsub = Core.vx_string_from_any(anyvalsub);
            } else {
              svalsub = valsub.toString();
            }
            msg = Core.vx_msg_error("(new xml) - Invalid Key Type: " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_error("(new xml) - Invalid Key: " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":tag":
            if (valsub == vx_p_tag) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_tag = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_tag = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_error("(new xml :tag " + valsub.toString() + ") - Invalid Value");
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
              msg = Core.vx_msg_error("(new xml :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":prop":
            if (valsub == vx_p_prop) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_prop = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_prop = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_error("(new xml :prop " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":propmap":
            if (valsub == vx_p_propmap) {
            } else if (valsub instanceof Core.Type_stringmap) {
              ischanged = true;
              vx_p_propmap = (Core.Type_stringmap)valsub;
            } else {
              msg = Core.vx_msg_error("(new xml :propmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":children":
            if (valsub == vx_p_children) {
            } else if (valsub instanceof Xml.Type_xmllist) {
              ischanged = true;
              vx_p_children = (Xml.Type_xmllist)valsub;
            } else {
              msg = Core.vx_msg_error("(new xml :children " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":parent":
            if (valsub == vx_p_parent) {
            } else if (valsub instanceof Xml.Type_xml) {
              ischanged = true;
              vx_p_parent = (Xml.Type_xml)valsub;
            } else {
              msg = Core.vx_msg_error("(new xml :parent " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_error("(new xml) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_xml work = new Class_xml();
        work.vx_p_tag = vx_p_tag;
        work.vx_p_text = vx_p_text;
        work.vx_p_prop = vx_p_prop;
        work.vx_p_propmap = vx_p_propmap;
        work.vx_p_children = vx_p_children;
        work.vx_p_parent = vx_p_parent;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
   * type: xmllist
   * (type xmllist)
   */
  public interface Type_xmllist extends Core.Type_list {
    public Xml.Type_xmllist vx_new(final Object... vals);
    public Xml.Type_xmllist vx_copy(final Object... vals);
    public Xml.Type_xmllist vx_empty();
    public Xml.Type_xmllist vx_type();
    public List<Xml.Type_xml> vx_listxml();
    public Xml.Type_xml vx_xml(final Core.Type_int index);
  }

  public static class Class_xmllist extends Core.Class_base implements Type_xmllist {

    protected List<Xml.Type_xml> vx_p_list = Core.immutablelist(new ArrayList<Xml.Type_xml>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Xml.Type_xml vx_xml(final Core.Type_int index) {
      Xml.Type_xml output = Xml.e_xml;
      Class_xmllist list = this;
      int iindex = index.vx_int();
      List<Xml.Type_xml> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Xml.Type_xml> vx_listxml() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_xml(index);
    }

    @Override
    public Type_xmllist vx_new(final Object... vals) {return e_xmllist.vx_copy(vals);}

    @Override
    public Type_xmllist vx_copy(final Object... vals) {
      Type_xmllist output = this;
      boolean ischanged = false;
      Class_xmllist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Xml.Type_xml> listval = new ArrayList<>(val.vx_listxml());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Xml.Type_xml) {
          ischanged = true;
          listval.add((Xml.Type_xml)valsub);
        } else if (valsub instanceof Xml.Type_xml) {
          ischanged = true;
          listval.add((Xml.Type_xml)valsub);
        } else if (valsub instanceof Type_xmllist) {
          Type_xmllist multi = (Type_xmllist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listxml());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Xml.Type_xml) {
              Xml.Type_xml valitem = (Xml.Type_xml)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new xmllist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_xmllist work = new Class_xmllist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_xmllist vx_empty() {return e_xmllist;}
    @Override
    public Type_xmllist vx_type() {return t_xmllist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Xml.t_xml), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_xmllist e_xmllist = new Class_xmllist();
  public static final Type_xmllist t_xmllist = new Class_xmllist();

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

    protected Map<String, Core.Type_string> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_string>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_string vx_string(final Core.Type_string key) {
      Core.Type_string output = Core.e_string;
      Class_xmlpropmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_string);
      return output;
    }

    @Override
    public Map<String, Core.Type_string> vx_mapstring() {return vx_p_map;}

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
          Core.Type_msg msg = Core.vx_msg_error("(xmlpropmap) Invalid Value: " + val.toString() + "");
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
    public Type_xmlpropmap vx_new(final Object... vals) {return e_xmlpropmap.vx_copy(vals);}

    @Override
    public Type_xmlpropmap vx_copy(final Object... vals) {
      Type_xmlpropmap output = this;
      boolean ischanged = false;
      Class_xmlpropmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Core.Type_string> mapval = new LinkedHashMap<>(val.vx_mapstring());
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
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_string valany = null;
          if (valsub instanceof Core.Type_string) {
            valany = (Core.Type_string)valsub;
          } else if (valsub instanceof String) {
            valany = Core.t_string.vx_new(valsub);;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
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
        Class_xmlpropmap work = new Class_xmlpropmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
   * Constant: delimxml
   * {delim}
   */
  public static class Const_delimxml extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxml", // name
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

    public static void const_new(Const_delimxml output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":delimlist"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.t_anylist.vx_new(
                    Xml.c_delimxmlcomment,
                    Xml.c_delimxmlcdata,
                    Core.f_copy(
                      Textblock.c_delimbracketangle,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":delimlist"),
                        Core.f_new(
                          Textblock.t_delimlist,
                          Core.t_anylist.vx_new(
                            Xml.c_delimxmlequal,
                            Textblock.c_delimwhitespace,
                            Textblock.c_delimquote
                          )
                        )
                      )
                    )
                  )
                )
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimxml c_delimxml = new Const_delimxml();


  /**
   * Constant: delimxmlcdata
   * {delim}
   */
  public static class Const_delimxmlcdata extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcdata", // name
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

    public static void const_new(Const_delimxmlcdata output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimxmlcomment"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("<![CDATA["),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("]]>")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimxmlcdata c_delimxmlcdata = new Const_delimxmlcdata();


  /**
   * Constant: delimxmlcomment
   * {delim}
   */
  public static class Const_delimxmlcomment extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcomment", // name
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

    public static void const_new(Const_delimxmlcomment output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimxmlcomment"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("<!--"),
                Core.vx_new_string(":endtext"),
                Core.vx_new_string("-->")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimxmlcomment c_delimxmlcomment = new Const_delimxmlcomment();


  /**
   * Constant: delimxmlequal
   * {delim}
   */
  public static class Const_delimxmlequal extends Textblock.Class_delim implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlequal", // name
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

    public static void const_new(Const_delimxmlequal output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimxmlequal"),
                Core.vx_new_string(":starttext"),
                Core.vx_new_string("=")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static final Const_delimxmlequal c_delimxmlequal = new Const_delimxmlequal();

  /**
   * @function textblock_xml_from_string
   * Returns a parsed textblock from a string.
   * @param  {string} text
   * @return {textblock}
   * (func textblock-xml<-string)
   */
  public static interface Func_textblock_xml_from_string extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_xml_from_string(final Core.Type_string text);
  }

  public static class Class_textblock_xml_from_string extends Core.Class_base implements Func_textblock_xml_from_string {

    @Override
    public Func_textblock_xml_from_string vx_new(Object... vals) {
      Class_textblock_xml_from_string output = new Class_textblock_xml_from_string();
      return output;
    }

    @Override
    public Func_textblock_xml_from_string vx_copy(Object... vals) {
      Class_textblock_xml_from_string output = new Class_textblock_xml_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "textblock-xml<-string", // name
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
    public Func_textblock_xml_from_string vx_empty() {return e_textblock_xml_from_string;}
    @Override
    public Func_textblock_xml_from_string vx_type() {return t_textblock_xml_from_string;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Xml.f_textblock_xml_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Xml.f_textblock_xml_from_string(text);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_xml_from_string(final Core.Type_string text) {
      return Xml.f_textblock_xml_from_string(text);
    }

  }

  public static final Func_textblock_xml_from_string e_textblock_xml_from_string = new Xml.Class_textblock_xml_from_string();
  public static final Func_textblock_xml_from_string t_textblock_xml_from_string = new Xml.Class_textblock_xml_from_string();

  public static Textblock.Type_textblock f_textblock_xml_from_string(final Core.Type_string text) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Textblock.f_textblock_parse_from_string_delim(
      text,
      Xml.c_delimxml
    );
    return output;
  }

  /**
   * @function xml_angle_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-angle<-xml-textblock)
   */
  public static interface Func_xml_angle_from_xml_textblock extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_angle_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb);
  }

  public static class Class_xml_angle_from_xml_textblock extends Core.Class_base implements Func_xml_angle_from_xml_textblock {

    @Override
    public Func_xml_angle_from_xml_textblock vx_new(Object... vals) {
      Class_xml_angle_from_xml_textblock output = new Class_xml_angle_from_xml_textblock();
      return output;
    }

    @Override
    public Func_xml_angle_from_xml_textblock vx_copy(Object... vals) {
      Class_xml_angle_from_xml_textblock output = new Class_xml_angle_from_xml_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-angle<-xml-textblock", // name
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
    public Func_xml_angle_from_xml_textblock vx_empty() {return e_xml_angle_from_xml_textblock;}
    @Override
    public Func_xml_angle_from_xml_textblock vx_type() {return t_xml_angle_from_xml_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tb = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_angle_from_xml_textblock(xmlarg, tb);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_angle_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
      return Xml.f_xml_angle_from_xml_textblock(xmlarg, tb);
    }

  }

  public static final Func_xml_angle_from_xml_textblock e_xml_angle_from_xml_textblock = new Xml.Class_xml_angle_from_xml_textblock();
  public static final Func_xml_angle_from_xml_textblock t_xml_angle_from_xml_textblock = new Xml.Class_xml_angle_from_xml_textblock();

  public static Xml.Type_xml f_xml_angle_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_if_2(
      Xml.t_xml,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eq(
              tb.text(),
              Core.f_new(
                Core.t_string,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("</"),
                  xmlarg.tag(),
                  Core.vx_new_string(">")
                )
              )
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Xml.f_xml_close_from_xml_textblock(xmlarg, tb);
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Xml.t_xml,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Textblock.Type_textblocklist children = tb.children();
                final Xml.Type_xml xmlchg = Core.f_new(
                  Xml.t_xml,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":tag"),
                      Core.vx_new_string(":notag"),
                      Core.vx_new_string(":parent"),
                      xmlarg
                  )
                );
                return Xml.f_xml_properties_from_xml_textblocklist(xmlchg, children);
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function xml_close_from_xml_textblock
   * Returns a modified xml from a closing tag.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-close<-xml-textblock)
   */
  public static interface Func_xml_close_from_xml_textblock extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_close_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb);
  }

  public static class Class_xml_close_from_xml_textblock extends Core.Class_base implements Func_xml_close_from_xml_textblock {

    @Override
    public Func_xml_close_from_xml_textblock vx_new(Object... vals) {
      Class_xml_close_from_xml_textblock output = new Class_xml_close_from_xml_textblock();
      return output;
    }

    @Override
    public Func_xml_close_from_xml_textblock vx_copy(Object... vals) {
      Class_xml_close_from_xml_textblock output = new Class_xml_close_from_xml_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-close<-xml-textblock", // name
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
    public Func_xml_close_from_xml_textblock vx_empty() {return e_xml_close_from_xml_textblock;}
    @Override
    public Func_xml_close_from_xml_textblock vx_type() {return t_xml_close_from_xml_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tb = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_close_from_xml_textblock(xmlarg, tb);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_close_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
      return Xml.f_xml_close_from_xml_textblock(xmlarg, tb);
    }

  }

  public static final Func_xml_close_from_xml_textblock e_xml_close_from_xml_textblock = new Xml.Class_xml_close_from_xml_textblock();
  public static final Func_xml_close_from_xml_textblock t_xml_close_from_xml_textblock = new Xml.Class_xml_close_from_xml_textblock();

  public static Xml.Type_xml f_xml_close_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string tag = xmlarg.tag();
        final Core.Type_string text = tb.text();
        final Xml.Type_xml parent = xmlarg.parent();
        final Core.Type_boolean isnoparent = Core.f_is_empty_1(parent);
        return Core.f_if_2(
          Xml.t_xml,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_or(
                  Core.f_eq(Core.vx_new_string("/"), text),
                  Core.f_eq(
                    text,
                    Core.f_new(
                      Core.t_string,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("</"),
                        tag,
                        Core.vx_new_string(">")
                      )
                    )
                  )
                );
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_if_2(
                  Xml.t_xml,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return isnoparent;
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return xmlarg;
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            parent,
                            Core.t_anylist.vx_new(
                                Core.vx_new_string(":children"),
                                Core.f_new(
                                  Xml.t_xmllist,
                                  Core.t_anylist.vx_new(
                                    parent.children(),
                                    Core.f_copy(
                                      xmlarg,
                                      Core.t_anylist.vx_new(
                                        Core.vx_new_string(":parent"),
                                        Core.f_empty(
                                          Xml.t_xml
                                        )
                                      )
                                    )
                                  )
                                )
                            )
                          );
                        })
                      )
                  )
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  xmlarg,
                  Core.t_anylist.vx_new(
                      Core.f_msg_from_error(
                        Core.f_new(
                          Core.t_string,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string("Invalid Xml Close tag: "),
                            text
                          )
                        )
                      )
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
   * @function xml_parse_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-parse<-xml-textblock)
   */
  public static interface Func_xml_parse_from_xml_textblock extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_parse_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb);
  }

  public static class Class_xml_parse_from_xml_textblock extends Core.Class_base implements Func_xml_parse_from_xml_textblock {

    @Override
    public Func_xml_parse_from_xml_textblock vx_new(Object... vals) {
      Class_xml_parse_from_xml_textblock output = new Class_xml_parse_from_xml_textblock();
      return output;
    }

    @Override
    public Func_xml_parse_from_xml_textblock vx_copy(Object... vals) {
      Class_xml_parse_from_xml_textblock output = new Class_xml_parse_from_xml_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblock", // name
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
    public Func_xml_parse_from_xml_textblock vx_empty() {return e_xml_parse_from_xml_textblock;}
    @Override
    public Func_xml_parse_from_xml_textblock vx_type() {return t_xml_parse_from_xml_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tb = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_parse_from_xml_textblock(xmlarg, tb);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_parse_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
      return Xml.f_xml_parse_from_xml_textblock(xmlarg, tb);
    }

  }

  public static final Func_xml_parse_from_xml_textblock e_xml_parse_from_xml_textblock = new Xml.Class_xml_parse_from_xml_textblock();
  public static final Func_xml_parse_from_xml_textblock t_xml_parse_from_xml_textblock = new Xml.Class_xml_parse_from_xml_textblock();

  public static Xml.Type_xml f_xml_parse_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delim = tb.delim();
        final Core.Type_string text = tb.text();
        final Core.Type_string starttext = delim.starttext();
        return Core.f_switch(
          Xml.t_xml,
          starttext,
          Core.t_thenelselist.vx_new(
            Core.f_case_1(
              Core.vx_new_string(""),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Xml.f_xml_text_from_xml_textblock(xmlarg, tb);
              })
            ),
            Core.f_case_1(
              Textblock.c_delimbracketangle.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Xml.f_xml_angle_from_xml_textblock(xmlarg, tb);
              })
            ),
            Core.f_case_1(
              Textblock.c_delimwhitespace.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return xmlarg;
              })
            ),
            Core.f_case_1(
              Xml.c_delimxmlcomment.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return xmlarg;
              })
            ),
            Core.f_case_1(
              Xml.c_delimxmlcdata.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return xmlarg;
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function xml_parse_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   * (func xml-parse<-xml-textblocklist)
   */
  public static interface Func_xml_parse_from_xml_textblocklist extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_parse_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist);
  }

  public static class Class_xml_parse_from_xml_textblocklist extends Core.Class_base implements Func_xml_parse_from_xml_textblocklist {

    @Override
    public Func_xml_parse_from_xml_textblocklist vx_new(Object... vals) {
      Class_xml_parse_from_xml_textblocklist output = new Class_xml_parse_from_xml_textblocklist();
      return output;
    }

    @Override
    public Func_xml_parse_from_xml_textblocklist vx_copy(Object... vals) {
      Class_xml_parse_from_xml_textblocklist output = new Class_xml_parse_from_xml_textblocklist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblocklist", // name
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
    public Func_xml_parse_from_xml_textblocklist vx_empty() {return e_xml_parse_from_xml_textblocklist;}
    @Override
    public Func_xml_parse_from_xml_textblocklist vx_type() {return t_xml_parse_from_xml_textblocklist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_parse_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist) {
      return Xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist);
    }

  }

  public static final Func_xml_parse_from_xml_textblocklist e_xml_parse_from_xml_textblocklist = new Xml.Class_xml_parse_from_xml_textblocklist();
  public static final Func_xml_parse_from_xml_textblocklist t_xml_parse_from_xml_textblocklist = new Xml.Class_xml_parse_from_xml_textblocklist();

  public static Xml.Type_xml f_xml_parse_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_any_from_list_start_reduce(
      Xml.t_xml,
      textblocklist,
      xmlarg,
      Core.t_any_from_reduce.vx_fn_new((reduce_any, current_any) -> {
        Xml.Type_xml reduce = Core.f_any_from_any(Xml.t_xml, reduce_any);
        Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
        return 
          Xml.f_xml_parse_from_xml_textblock(reduce, current);
      })
    );
    return output;
  }

  /**
   * @function xml_properties_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   * (func xml-properties<-xml-textblocklist)
   */
  public static interface Func_xml_properties_from_xml_textblocklist extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_properties_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist);
  }

  public static class Class_xml_properties_from_xml_textblocklist extends Core.Class_base implements Func_xml_properties_from_xml_textblocklist {

    @Override
    public Func_xml_properties_from_xml_textblocklist vx_new(Object... vals) {
      Class_xml_properties_from_xml_textblocklist output = new Class_xml_properties_from_xml_textblocklist();
      return output;
    }

    @Override
    public Func_xml_properties_from_xml_textblocklist vx_copy(Object... vals) {
      Class_xml_properties_from_xml_textblocklist output = new Class_xml_properties_from_xml_textblocklist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-properties<-xml-textblocklist", // name
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
    public Func_xml_properties_from_xml_textblocklist vx_empty() {return e_xml_properties_from_xml_textblocklist;}
    @Override
    public Func_xml_properties_from_xml_textblocklist vx_type() {return t_xml_properties_from_xml_textblocklist;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_properties_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist) {
      return Xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist);
    }

  }

  public static final Func_xml_properties_from_xml_textblocklist e_xml_properties_from_xml_textblocklist = new Xml.Class_xml_properties_from_xml_textblocklist();
  public static final Func_xml_properties_from_xml_textblocklist t_xml_properties_from_xml_textblocklist = new Xml.Class_xml_properties_from_xml_textblocklist();

  public static Xml.Type_xml f_xml_properties_from_xml_textblocklist(final Xml.Type_xml xmlarg, final Textblock.Type_textblocklist textblocklist) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Xml.Type_xml xmlchg = Core.f_any_from_list_start_reduce(
          Xml.t_xml,
          textblocklist,
          xmlarg,
          Core.t_any_from_reduce.vx_fn_new((reduce_any, current_any) -> {
            Xml.Type_xml reduce = Core.f_any_from_any(Xml.t_xml, reduce_any);
            Textblock.Type_textblock current = Core.f_any_from_any(Textblock.t_textblock, current_any);
            return 
                Xml.f_xml_property_from_xml_textblock(reduce, current);
          })
        );
        return xmlchg;
      })
    );
    return output;
  }

  /**
   * @function xml_property_from_xml_textblock
   * Returns a modified xml from a single property.
   * @param  {xml} xmlarg
   * @param  {textblock} tbarg
   * @return {xml}
   * (func xml-property<-xml-textblock)
   */
  public static interface Func_xml_property_from_xml_textblock extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_property_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tbarg);
  }

  public static class Class_xml_property_from_xml_textblock extends Core.Class_base implements Func_xml_property_from_xml_textblock {

    @Override
    public Func_xml_property_from_xml_textblock vx_new(Object... vals) {
      Class_xml_property_from_xml_textblock output = new Class_xml_property_from_xml_textblock();
      return output;
    }

    @Override
    public Func_xml_property_from_xml_textblock vx_copy(Object... vals) {
      Class_xml_property_from_xml_textblock output = new Class_xml_property_from_xml_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-property<-xml-textblock", // name
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
    public Func_xml_property_from_xml_textblock vx_empty() {return e_xml_property_from_xml_textblock;}
    @Override
    public Func_xml_property_from_xml_textblock vx_type() {return t_xml_property_from_xml_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tbarg = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_property_from_xml_textblock(xmlarg, tbarg);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_property_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tbarg) {
      return Xml.f_xml_property_from_xml_textblock(xmlarg, tbarg);
    }

  }

  public static final Func_xml_property_from_xml_textblock e_xml_property_from_xml_textblock = new Xml.Class_xml_property_from_xml_textblock();
  public static final Func_xml_property_from_xml_textblock t_xml_property_from_xml_textblock = new Xml.Class_xml_property_from_xml_textblock();

  public static Xml.Type_xml f_xml_property_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tbarg) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delim = tbarg.delim();
        final Core.Type_string text = tbarg.text();
        final Core.Type_string delimname = delim.name();
        final Core.Type_string tag = xmlarg.tag();
        final Core.Type_string prop = xmlarg.prop();
        final Core.Type_stringmap propmap = xmlarg.propmap();
        return Core.f_switch(
          Xml.t_xml,
          delimname,
          Core.t_thenelselist.vx_new(
            Core.f_case_1(
              Core.vx_new_string(""),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_if_2(
                  Xml.t_xml,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Type.f_boolean_from_string_starts(text, Core.vx_new_string("/"));
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Xml.f_xml_close_from_xml_textblock(xmlarg, tbarg);
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq(Core.vx_new_string(":notag"), tag);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            xmlarg,
                            Core.t_anylist.vx_new(
                                Core.vx_new_string(":tag"),
                                text
                            )
                          );
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq(Core.vx_new_string(""), prop);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            xmlarg,
                            Core.t_anylist.vx_new(
                                Core.vx_new_string(":prop"),
                                text
                            )
                          );
                        })
                      )
                  )
                );
              })
            ),
            Core.f_case_1(
              Core.vx_new_string("delimquote"),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_if_1(
                  Xml.t_xml,
                  Core.f_eq(Core.vx_new_string(""), prop),
                  Core.f_copy(
                    xmlarg,
                    Core.t_anylist.vx_new(
                      Core.f_msg_from_error(Core.vx_new_string("Found quoted text with no matching attribute."))
                    )
                  ),
                  Core.f_copy(
                    xmlarg,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":prop"),
                      Core.vx_new_string(""),
                      Core.vx_new_string(":propmap"),
                      Core.f_copy(
                        propmap,
                        Core.t_anylist.vx_new(
                          prop,
                          Core.f_any_from_list(
                            Textblock.t_textblock,
                            tbarg.children(),
                            Core.vx_new_int(1)
                          ).text()
                        )
                      )
                    )
                  )
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return xmlarg;
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function xml_read_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml-read<-file)
   */
  public static interface Func_xml_read_from_file extends Core.Func_any_from_any_context {
    public Xml.Type_xml vx_xml_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_xml_read_from_file extends Core.Class_base implements Func_xml_read_from_file {

    @Override
    public Func_xml_read_from_file vx_new(Object... vals) {
      Class_xml_read_from_file output = new Class_xml_read_from_file();
      return output;
    }

    @Override
    public Func_xml_read_from_file vx_copy(Object... vals) {
      Class_xml_read_from_file output = new Class_xml_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-read<-file", // name
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
    public Func_xml_read_from_file vx_empty() {return e_xml_read_from_file;}
    @Override
    public Func_xml_read_from_file vx_type() {return t_xml_read_from_file;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = Xml.f_xml_read_from_file(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Xml.f_xml_read_from_file(context, file);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_read_from_file(final Core.Type_context context, final File.Type_file file) {
      return Xml.f_xml_read_from_file(context, file);
    }

  }

  public static final Func_xml_read_from_file e_xml_read_from_file = new Xml.Class_xml_read_from_file();
  public static final Func_xml_read_from_file t_xml_read_from_file = new Xml.Class_xml_read_from_file();

  public static Xml.Type_xml f_xml_read_from_file(final Core.Type_context context, final File.Type_file file) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final File.Type_file loaded = File.f_file_read_from_file(context, file);
        return Xml.f_xml_from_file(loaded);
      })
    );
    return output;
  }

  /**
   * @function xml_text_from_xml_textblock
   * Returns a modified xml from text.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-text<-xml-textblock)
   */
  public static interface Func_xml_text_from_xml_textblock extends Core.Type_func, Core.Type_replfunc {
    public Xml.Type_xml vx_xml_text_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb);
  }

  public static class Class_xml_text_from_xml_textblock extends Core.Class_base implements Func_xml_text_from_xml_textblock {

    @Override
    public Func_xml_text_from_xml_textblock vx_new(Object... vals) {
      Class_xml_text_from_xml_textblock output = new Class_xml_text_from_xml_textblock();
      return output;
    }

    @Override
    public Func_xml_text_from_xml_textblock vx_copy(Object... vals) {
      Class_xml_text_from_xml_textblock output = new Class_xml_text_from_xml_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-text<-xml-textblock", // name
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
    public Func_xml_text_from_xml_textblock vx_empty() {return e_xml_text_from_xml_textblock;}
    @Override
    public Func_xml_text_from_xml_textblock vx_type() {return t_xml_text_from_xml_textblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Xml.Type_xml xmlarg = Core.f_any_from_any(Xml.t_xml, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tb = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Xml.f_xml_text_from_xml_textblock(xmlarg, tb);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_text_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
      return Xml.f_xml_text_from_xml_textblock(xmlarg, tb);
    }

  }

  public static final Func_xml_text_from_xml_textblock e_xml_text_from_xml_textblock = new Xml.Class_xml_text_from_xml_textblock();
  public static final Func_xml_text_from_xml_textblock t_xml_text_from_xml_textblock = new Xml.Class_xml_text_from_xml_textblock();

  public static Xml.Type_xml f_xml_text_from_xml_textblock(final Xml.Type_xml xmlarg, final Textblock.Type_textblock tb) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = tb.text();
        final Xml.Type_xml xmlchg = Core.f_new(
          Xml.t_xml,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":text"),
              text
          )
        );
        return Core.f_if_2(
          Xml.t_xml,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_empty_1(xmlarg);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return xmlchg;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  xmlarg,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":children"),
                      Core.f_new(
                        Xml.t_xmllist,
                        Core.t_anylist.vx_new(
                          xmlarg.children(),
                          xmlchg
                        )
                      )
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
   * @function xml_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml<-file)
   */
  public static interface Func_xml_from_file extends Core.Func_any_from_any {
    public Xml.Type_xml vx_xml_from_file(final File.Type_file file);
  }

  public static class Class_xml_from_file extends Core.Class_base implements Func_xml_from_file {

    @Override
    public Func_xml_from_file vx_new(Object... vals) {
      Class_xml_from_file output = new Class_xml_from_file();
      return output;
    }

    @Override
    public Func_xml_from_file vx_copy(Object... vals) {
      Class_xml_from_file output = new Class_xml_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-file", // name
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
    public Func_xml_from_file vx_empty() {return e_xml_from_file;}
    @Override
    public Func_xml_from_file vx_type() {return t_xml_from_file;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = Xml.f_xml_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Xml.f_xml_from_file(file);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_from_file(final File.Type_file file) {
      return Xml.f_xml_from_file(file);
    }

  }

  public static final Func_xml_from_file e_xml_from_file = new Xml.Class_xml_from_file();
  public static final Func_xml_from_file t_xml_from_file = new Xml.Class_xml_from_file();

  public static Xml.Type_xml f_xml_from_file(final File.Type_file file) {
    Xml.Type_xml output = Xml.e_xml;
    output = Core.f_let(
      Xml.t_xml,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = file.text();
        return Xml.f_xml_from_string(text);
      })
    );
    return output;
  }

  /**
   * @function xml_from_string
   * Returns a parsed xml from a string.
   * @param  {string} text
   * @return {xml}
   * (func xml<-string)
   */
  public static interface Func_xml_from_string extends Core.Func_any_from_any {
    public Xml.Type_xml vx_xml_from_string(final Core.Type_string text);
  }

  public static class Class_xml_from_string extends Core.Class_base implements Func_xml_from_string {

    @Override
    public Func_xml_from_string vx_new(Object... vals) {
      Class_xml_from_string output = new Class_xml_from_string();
      return output;
    }

    @Override
    public Func_xml_from_string vx_copy(Object... vals) {
      Class_xml_from_string output = new Class_xml_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-string", // name
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
    public Func_xml_from_string vx_empty() {return e_xml_from_string;}
    @Override
    public Func_xml_from_string vx_type() {return t_xml_from_string;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Xml.f_xml_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Xml.f_xml_from_string(text);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_from_string(final Core.Type_string text) {
      return Xml.f_xml_from_string(text);
    }

  }

  public static final Func_xml_from_string e_xml_from_string = new Xml.Class_xml_from_string();
  public static final Func_xml_from_string t_xml_from_string = new Xml.Class_xml_from_string();

  public static Xml.Type_xml f_xml_from_string(final Core.Type_string text) {
    Xml.Type_xml output = Xml.e_xml;
    output = Xml.f_xml_from_textblock(
      Xml.f_textblock_xml_from_string(text)
    );
    return output;
  }

  /**
   * @function xml_from_textblock
   * Returns a parsed xml from a textblock.
   * @param  {textblock} textblock
   * @return {xml}
   * (func xml<-textblock)
   */
  public static interface Func_xml_from_textblock extends Core.Func_any_from_any {
    public Xml.Type_xml vx_xml_from_textblock(final Textblock.Type_textblock textblock);
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
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Xml.f_xml_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Xml.f_xml_from_textblock(textblock);
      return output;
    }

    @Override
    public Xml.Type_xml vx_xml_from_textblock(final Textblock.Type_textblock textblock) {
      return Xml.f_xml_from_textblock(textblock);
    }

  }

  public static final Func_xml_from_textblock e_xml_from_textblock = new Xml.Class_xml_from_textblock();
  public static final Func_xml_from_textblock t_xml_from_textblock = new Xml.Class_xml_from_textblock();

  public static Xml.Type_xml f_xml_from_textblock(final Textblock.Type_textblock textblock) {
    Xml.Type_xml output = Xml.e_xml;
    output = Xml.f_xml_parse_from_xml_textblocklist(
      Core.f_empty(
        Xml.t_xml
      ),
      textblock.children()
    );
    return output;
  }


  static {
    Const_delimxml.const_new(c_delimxml);
    Const_delimxmlcdata.const_new(c_delimxmlcdata);
    Const_delimxmlcomment.const_new(c_delimxmlcomment);
    Const_delimxmlequal.const_new(c_delimxmlequal);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("xml", Xml.t_xml);
    maptype.put("xmllist", Xml.t_xmllist);
    maptype.put("xmlpropmap", Xml.t_xmlpropmap);
    mapconst.put("delimxml", Xml.c_delimxml);
    mapconst.put("delimxmlcdata", Xml.c_delimxmlcdata);
    mapconst.put("delimxmlcomment", Xml.c_delimxmlcomment);
    mapconst.put("delimxmlequal", Xml.c_delimxmlequal);
    mapfunc.put("textblock-xml<-string", Xml.t_textblock_xml_from_string);
    mapfunc.put("xml-angle<-xml-textblock", Xml.t_xml_angle_from_xml_textblock);
    mapfunc.put("xml-close<-xml-textblock", Xml.t_xml_close_from_xml_textblock);
    mapfunc.put("xml-parse<-xml-textblock", Xml.t_xml_parse_from_xml_textblock);
    mapfunc.put("xml-parse<-xml-textblocklist", Xml.t_xml_parse_from_xml_textblocklist);
    mapfunc.put("xml-properties<-xml-textblocklist", Xml.t_xml_properties_from_xml_textblocklist);
    mapfunc.put("xml-property<-xml-textblock", Xml.t_xml_property_from_xml_textblock);
    mapfunc.put("xml-read<-file", Xml.t_xml_read_from_file);
    mapfunc.put("xml-text<-xml-textblock", Xml.t_xml_text_from_xml_textblock);
    mapfunc.put("xml<-file", Xml.t_xml_from_file);
    mapfunc.put("xml<-string", Xml.t_xml_from_string);
    mapfunc.put("xml<-textblock", Xml.t_xml_from_textblock);
    Core.vx_global_package_set("vx/data/xml", maptype, mapconst, mapfunc);
  }

}
