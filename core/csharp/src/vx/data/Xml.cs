namespace Vx.Data;

public static class Xml {


  /**
   * type: xml
   * (type xml)
   */
  public interface Type_xml : Vx.Core.Type_struct {
    public Vx.Core.Type_string tag();
    public Vx.Core.Type_string text();
    public Vx.Core.Type_string prop();
    public Vx.Core.Type_stringmap propmap();
    public Vx.Data.Xml.Type_xmllist children();
    public Vx.Data.Xml.Type_xml parent();
  }

  public class Class_xml : Vx.Core.Class_base, Type_xml {

    public Vx.Core.Type_string? vx_p_tag = null;

    public Vx.Core.Type_string tag() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_tag;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_text;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_prop = null;

    public Vx.Core.Type_string prop() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_prop;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_stringmap? vx_p_propmap = null;

    public Vx.Core.Type_stringmap propmap() {
      Vx.Core.Type_stringmap output = Vx.Core.e_stringmap;
      Vx.Core.Type_stringmap? testnull = vx_p_propmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Xml.Type_xmllist? vx_p_children = null;

    public Vx.Data.Xml.Type_xmllist children() {
      Vx.Data.Xml.Type_xmllist output = Vx.Data.Xml.e_xmllist;
      Vx.Data.Xml.Type_xmllist? testnull = vx_p_children;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Xml.Type_xml? vx_p_parent = null;

    public Vx.Data.Xml.Type_xml parent() {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
      Vx.Data.Xml.Type_xml? testnull = vx_p_parent;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":tag")) {
        output = this.tag();
      } else if ((skey==":text")) {
        output = this.text();
      } else if ((skey==":prop")) {
        output = this.prop();
      } else if ((skey==":propmap")) {
        output = this.propmap();
      } else if ((skey==":children")) {
        output = this.children();
      } else if ((skey==":parent")) {
        output = this.parent();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":tag", this.tag());
      map.put(":text", this.text());
      map.put(":prop", this.prop());
      map.put(":propmap", this.propmap());
      map.put(":children", this.children());
      map.put(":parent", this.parent());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Xml.Type_xml vx_new(params object[] vals) {
      Vx.Data.Xml.Type_xml output = Vx.Core.vx_copy(Vx.Data.Xml.e_xml, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Type_xml output = this;
      bool ischanged = false;
      Vx.Data.Xml.Class_xml value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_tag = value.tag();
      Vx.Core.Type_string vx_p_text = value.text();
      Vx.Core.Type_string vx_p_prop = value.prop();
      Vx.Core.Type_stringmap vx_p_propmap = value.propmap();
      Vx.Data.Xml.Type_xmllist vx_p_children = value.children();
      Vx.Data.Xml.Type_xml vx_p_parent = value.parent();
      List<string> validkeys = new List<string>();
      validkeys.Add(":tag");
      validkeys.Add(":text");
      validkeys.Add(":prop");
      validkeys.Add(":propmap");
      validkeys.Add(":children");
      validkeys.Add(":parent");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":tag")) {
            if (valsub == vx_p_tag) {
            } else if (valsub is Vx.Core.Type_string valtag) {
              ischanged = true;
              vx_p_tag = valtag;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_tag = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("tag"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":text")) {
            if (valsub == vx_p_text) {
            } else if (valsub is Vx.Core.Type_string valtext) {
              ischanged = true;
              vx_p_text = valtext;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":prop")) {
            if (valsub == vx_p_prop) {
            } else if (valsub is Vx.Core.Type_string valprop) {
              ischanged = true;
              vx_p_prop = valprop;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_prop = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("prop"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":propmap")) {
            if (valsub == vx_p_propmap) {
            } else if (valsub is Vx.Core.Type_stringmap valpropmap) {
              ischanged = true;
              vx_p_propmap = valpropmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("propmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":children")) {
            if (valsub == vx_p_children) {
            } else if (valsub is Vx.Data.Xml.Type_xmllist valchildren) {
              ischanged = true;
              vx_p_children = valchildren;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("children"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":parent")) {
            if (valsub == vx_p_parent) {
            } else if (valsub is Vx.Data.Xml.Type_xml valparent) {
              ischanged = true;
              vx_p_parent = valparent;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("parent"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/xml/xml", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Xml.Class_xml work = new Vx.Data.Xml.Class_xml();
        work.vx_p_tag = vx_p_tag;
        work.vx_p_text = vx_p_text;
        work.vx_p_prop = vx_p_prop;
        work.vx_p_propmap = vx_p_propmap;
        work.vx_p_children = vx_p_children;
        work.vx_p_parent = vx_p_parent;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/xml", // pkgname
        "xml", // name
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

  public static Vx.Data.Xml.Type_xml e_xml = new Vx.Data.Xml.Class_xml();
  public static Vx.Data.Xml.Type_xml t_xml = new Vx.Data.Xml.Class_xml();

  /**
   * type: xmllist
   * (type xmllist)
   */
  public interface Type_xmllist : Vx.Core.Type_list {
    public List<Vx.Data.Xml.Type_xml> vx_listxml();
    public Vx.Data.Xml.Type_xml vx_xml(Vx.Core.Type_int index);
  }

  public class Class_xmllist : Vx.Core.Class_base, Type_xmllist {

    public List<Vx.Data.Xml.Type_xml> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Xml.Type_xml>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml(Vx.Core.Type_int index) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
      Vx.Data.Xml.Class_xmllist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Xml.Type_xml> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Xml.Type_xml> vx_listxml() {
      List<Vx.Data.Xml.Type_xml> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Xml.Type_xml output = this.vx_xml(index);
      return output;
    }

    public override Vx.Data.Xml.Type_xmllist vx_new(params object[] vals) {
      Vx.Data.Xml.Type_xmllist output = Vx.Core.vx_copy(Vx.Data.Xml.e_xmllist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Type_xmllist output = this;
      bool ischanged = false;
      Vx.Data.Xml.Class_xmllist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Xml.Type_xml> listval = new List<Vx.Data.Xml.Type_xml>(value.vx_listxml());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Xml.Type_xml allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Xml.Type_xml) {
          ischanged = true;
          listval.Add((Vx.Data.Xml.Type_xml)valsub);
        } else if (valsub is Vx.Data.Xml.Type_xmllist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listxml());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Xml.Type_xml valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/xml/xmllist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/xml/xmllist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Xml.Class_xmllist work = new Vx.Data.Xml.Class_xmllist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Xml.e_xmllist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xmllist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmllist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Xml.t_xml), // allowtypes
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

  public static Vx.Data.Xml.Type_xmllist e_xmllist = new Vx.Data.Xml.Class_xmllist();
  public static Vx.Data.Xml.Type_xmllist t_xmllist = new Vx.Data.Xml.Class_xmllist();

  /**
   * type: xmlpropmap
   * (type xmlpropmap)
   */
  public interface Type_xmlpropmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key);
  }

  public class Class_xmlpropmap : Vx.Core.Class_base, Type_xmlpropmap {

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Core.Type_string>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Core.Type_string castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(this.vx_p_map);
        if (castval == Vx.Core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key) {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Data.Xml.Class_xmlpropmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Core.e_string);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring() {
      Vx.Core.Map<string, Vx.Core.Type_string> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_string(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Xml.Class_xmlpropmap output = new Vx.Data.Xml.Class_xmlpropmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Core.Type_string castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Xml.Type_xmlpropmap vx_new(params object[] vals) {
      Vx.Data.Xml.Type_xmlpropmap output = Vx.Core.vx_copy(Vx.Data.Xml.e_xmlpropmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Type_xmlpropmap output = this;
      bool ischanged = false;
      Vx.Data.Xml.Class_xmlpropmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(value.vx_mapstring());
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_string valany = Vx.Core.e_string;
          if (false) {
          } else if (valsub is Vx.Core.Type_string valallowed) {
            valany = valallowed;
          } else if (valsub is string) {
            valany = Vx.Core.vx_new(Vx.Core.t_string, valsub);
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
            msg = Vx.Core.vx_msg_from_error("vx/data/xml/xmlpropmap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (valany != Vx.Core.e_any) {
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
        Vx.Data.Xml.Class_xmlpropmap work = new Vx.Data.Xml.Class_xmlpropmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Xml.e_xmlpropmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xmlpropmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/xml", // pkgname
        "xmlpropmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
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

  public static Vx.Data.Xml.Type_xmlpropmap e_xmlpropmap = new Vx.Data.Xml.Class_xmlpropmap();
  public static Vx.Data.Xml.Type_xmlpropmap t_xmlpropmap = new Vx.Data.Xml.Class_xmlpropmap();

  /**
   * Constant: delimxml
   * {delim}
   */
  public class Const_delimxml {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxml", // name
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
      return output;
    }

    public static void const_new(Vx.Data.Textblock.Type_delim output) {
      Vx.Data.Textblock.Class_delim outval = (Vx.Data.Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Vx.Data.Textblock.Type_delim value = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":delimlist"),
          Vx.Core.f_new(
            Vx.Data.Textblock.t_delimlist,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Data.Xml.c_delimxmlcomment,
              Vx.Data.Xml.c_delimxmlcdata,
              Vx.Core.f_copy(
                Vx.Data.Textblock.c_delimbracketangle,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":delimlist"),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_delimlist,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Data.Xml.c_delimxmlequal,
                      Vx.Data.Textblock.c_delimwhitespace,
                      Vx.Data.Textblock.c_delimquote
                    )
                  )
                )
              )
            )
          )
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static Vx.Data.Textblock.Type_delim c_delimxml = new Vx.Data.Textblock.Class_delim();


  /**
   * Constant: delimxmlcdata
   * {delim}
   */
  public class Const_delimxmlcdata {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcdata", // name
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
      return output;
    }

    public static void const_new(Vx.Data.Textblock.Type_delim output) {
      Vx.Data.Textblock.Class_delim outval = (Vx.Data.Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Vx.Data.Textblock.Type_delim value = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("delimxmlcomment"),
          Vx.Core.vx_new_string(":starttext"),
          Vx.Core.vx_new_string("<![CDATA["),
          Vx.Core.vx_new_string(":endtext"),
          Vx.Core.vx_new_string("]]>")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static Vx.Data.Textblock.Type_delim c_delimxmlcdata = new Vx.Data.Textblock.Class_delim();


  /**
   * Constant: delimxmlcomment
   * {delim}
   */
  public class Const_delimxmlcomment {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlcomment", // name
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
      return output;
    }

    public static void const_new(Vx.Data.Textblock.Type_delim output) {
      Vx.Data.Textblock.Class_delim outval = (Vx.Data.Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Vx.Data.Textblock.Type_delim value = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("delimxmlcomment"),
          Vx.Core.vx_new_string(":starttext"),
          Vx.Core.vx_new_string("<!--"),
          Vx.Core.vx_new_string(":endtext"),
          Vx.Core.vx_new_string("-->")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static Vx.Data.Textblock.Type_delim c_delimxmlcomment = new Vx.Data.Textblock.Class_delim();


  /**
   * Constant: delimxmlequal
   * {delim}
   */
  public class Const_delimxmlequal {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/xml", // pkgname
        "delimxmlequal", // name
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
      return output;
    }

    public static void const_new(Vx.Data.Textblock.Type_delim output) {
      Vx.Data.Textblock.Class_delim outval = (Vx.Data.Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Vx.Data.Textblock.Type_delim value = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":name"),
          Vx.Core.vx_new_string("delimxmlequal"),
          Vx.Core.vx_new_string(":starttext"),
          Vx.Core.vx_new_string("=")
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static Vx.Data.Textblock.Type_delim c_delimxmlequal = new Vx.Data.Textblock.Class_delim();

  /**
   * @function string_decodexml_from_string
   * Returns string decoded from xml encoding
   * @param  {string} text
   * @return {string}
   * (func string-decodexml<-string)
   */
  public interface Func_string_decodexml_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_decodexml_from_string(Vx.Core.Type_string text);
  }

  public class Class_string_decodexml_from_string : Vx.Core.Class_base, Func_string_decodexml_from_string {

    public override Vx.Data.Xml.Func_string_decodexml_from_string vx_new(params object[] vals) {
      Vx.Data.Xml.Class_string_decodexml_from_string output = new Vx.Data.Xml.Class_string_decodexml_from_string();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_string_decodexml_from_string output = new Vx.Data.Xml.Class_string_decodexml_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "string-decodexml<-string", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_string_decodexml_from_string;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_string_decodexml_from_string;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_string_decodexml_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_string_decodexml_from_string(text);
      return output;
    }

    public Vx.Core.Type_string vx_string_decodexml_from_string(Vx.Core.Type_string text) {
      Vx.Core.Type_string output = Vx.Data.Xml.f_string_decodexml_from_string(text);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_string_decodexml_from_string e_string_decodexml_from_string = new Vx.Data.Xml.Class_string_decodexml_from_string();
  public static Vx.Data.Xml.Func_string_decodexml_from_string t_string_decodexml_from_string = new Vx.Data.Xml.Class_string_decodexml_from_string();

  public static Vx.Core.Type_string f_string_decodexml_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string lt = Vx.Core.f_string_from_string_find_replace(
          text,
          Vx.Core.vx_new_string("&lt;"),
          Vx.Core.vx_new_string("<")
        );
        Vx.Core.Type_string gt = Vx.Core.f_string_from_string_find_replace(
          text,
          Vx.Core.vx_new_string("&gt;"),
          Vx.Core.vx_new_string(">")
        );
        Vx.Core.Type_string amp = Vx.Core.f_string_from_string_find_replace(
          gt,
          Vx.Core.vx_new_string("&amp;"),
          Vx.Core.vx_new_string("&")
        );
        Vx.Core.Type_string result = Vx.Core.f_string_from_string_find_replace(
          text,
          Vx.Core.c_quote,
          Vx.Core.vx_new_string("\\\"")
        );
        Vx.Core.Type_any output_1 = result;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_first_from_xml
   * Returns string from first child's text.
   * @param  {xml} xml
   * @return {string}
   * (func string-first<-xml)
   */
  public interface Func_string_first_from_xml : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_first_from_xml(Vx.Data.Xml.Type_xml xml);
  }

  public class Class_string_first_from_xml : Vx.Core.Class_base, Func_string_first_from_xml {

    public override Vx.Data.Xml.Func_string_first_from_xml vx_new(params object[] vals) {
      Vx.Data.Xml.Class_string_first_from_xml output = new Vx.Data.Xml.Class_string_first_from_xml();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_string_first_from_xml output = new Vx.Data.Xml.Class_string_first_from_xml();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "string-first<-xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_string_first_from_xml;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_string_first_from_xml;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Xml.Type_xml inputval = (Vx.Data.Xml.Type_xml)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_string_first_from_xml(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xml = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_string_first_from_xml(xml);
      return output;
    }

    public Vx.Core.Type_string vx_string_first_from_xml(Vx.Data.Xml.Type_xml xml) {
      Vx.Core.Type_string output = Vx.Data.Xml.f_string_first_from_xml(xml);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_string_first_from_xml e_string_first_from_xml = new Vx.Data.Xml.Class_string_first_from_xml();
  public static Vx.Data.Xml.Func_string_first_from_xml t_string_first_from_xml = new Vx.Data.Xml.Class_string_first_from_xml();

  public static Vx.Core.Type_string f_string_first_from_xml(Vx.Data.Xml.Type_xml xml) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Xml.Type_xmllist children = xml.children();
        Vx.Data.Xml.Type_xml first = Vx.Core.f_any_from_list(
          Vx.Data.Xml.t_xml,
          children,
          Vx.Core.vx_new_int(1)
        );
        Vx.Core.Type_string text = first.text();
        Vx.Core.Type_string decode = Vx.Data.Xml.f_string_decodexml_from_string(
          text
        );
        Vx.Core.Type_string outdent = Vx.Type.f_string_outdent(
          decode
        );
        Vx.Core.Type_string trim = Vx.Type.f_string_trim(
          outdent
        );
        Vx.Core.Type_any output_1 = trim;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function textblock_xml_from_string
   * Returns a parsed textblock from a string.
   * @param  {string} text
   * @return {textblock}
   * (func textblock-xml<-string)
   */
  public interface Func_textblock_xml_from_string : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_xml_from_string(Vx.Core.Type_string text);
  }

  public class Class_textblock_xml_from_string : Vx.Core.Class_base, Func_textblock_xml_from_string {

    public override Vx.Data.Xml.Func_textblock_xml_from_string vx_new(params object[] vals) {
      Vx.Data.Xml.Class_textblock_xml_from_string output = new Vx.Data.Xml.Class_textblock_xml_from_string();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_textblock_xml_from_string output = new Vx.Data.Xml.Class_textblock_xml_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "textblock-xml<-string", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Xml.e_textblock_xml_from_string;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_textblock_xml_from_string;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_textblock_xml_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_textblock_xml_from_string(text);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_xml_from_string(Vx.Core.Type_string text) {
      Vx.Data.Textblock.Type_textblock output = Vx.Data.Xml.f_textblock_xml_from_string(text);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_textblock_xml_from_string e_textblock_xml_from_string = new Vx.Data.Xml.Class_textblock_xml_from_string();
  public static Vx.Data.Xml.Func_textblock_xml_from_string t_textblock_xml_from_string = new Vx.Data.Xml.Class_textblock_xml_from_string();

  public static Vx.Data.Textblock.Type_textblock f_textblock_xml_from_string(Vx.Core.Type_string text) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Data.Textblock.f_textblock_parse_from_string_delim(
      text,
      Vx.Data.Xml.c_delimxml
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
  public interface Func_xml_angle_from_xml_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_angle_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb);
  }

  public class Class_xml_angle_from_xml_textblock : Vx.Core.Class_base, Func_xml_angle_from_xml_textblock {

    public override Vx.Data.Xml.Func_xml_angle_from_xml_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_angle_from_xml_textblock output = new Vx.Data.Xml.Class_xml_angle_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_angle_from_xml_textblock output = new Vx.Data.Xml.Class_xml_angle_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-angle<-xml-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_angle_from_xml_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_angle_from_xml_textblock;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_angle_from_xml_textblock(xmlarg, tb);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_angle_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_angle_from_xml_textblock(xmlarg, tb);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_angle_from_xml_textblock e_xml_angle_from_xml_textblock = new Vx.Data.Xml.Class_xml_angle_from_xml_textblock();
  public static Vx.Data.Xml.Func_xml_angle_from_xml_textblock t_xml_angle_from_xml_textblock = new Vx.Data.Xml.Class_xml_angle_from_xml_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_angle_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_if_2(
      Vx.Data.Xml.t_xml,
      Vx.Core.vx_new(
        Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            Vx.Core.Type_any output_1 = Vx.Core.f_eq(
              tb.text(),
              Vx.Core.f_new(
                Vx.Core.t_string,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string("</"),
                  xmlarg.tag(),
                  Vx.Core.vx_new_string(">")
                )
              )
            );
            return output_1;
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            Vx.Core.Type_any output_2 = Vx.Data.Xml.f_xml_close_from_xml_textblock(
              xmlarg,
              tb
            );
            return output_2;
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            Vx.Core.Type_any output_3 = Vx.Core.f_let(
              Vx.Data.Xml.t_xml,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Data.Textblock.Type_textblocklist children = tb.children();
                Vx.Data.Xml.Type_xml xmlchg = Vx.Core.f_new(
                  Vx.Data.Xml.t_xml,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":tag"),
                    Vx.Core.vx_new_string(":notag"),
                    Vx.Core.vx_new_string(":parent"),
                    xmlarg
                  )
                );
                Vx.Core.Type_any output_4 = Vx.Data.Xml.f_xml_properties_from_xml_textblocklist(
                  xmlchg,
                  children
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
   * @function xml_close_from_xml_textblock
   * Returns a modified xml from a closing tag.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-close<-xml-textblock)
   */
  public interface Func_xml_close_from_xml_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_close_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb);
  }

  public class Class_xml_close_from_xml_textblock : Vx.Core.Class_base, Func_xml_close_from_xml_textblock {

    public override Vx.Data.Xml.Func_xml_close_from_xml_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_close_from_xml_textblock output = new Vx.Data.Xml.Class_xml_close_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_close_from_xml_textblock output = new Vx.Data.Xml.Class_xml_close_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-close<-xml-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_close_from_xml_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_close_from_xml_textblock;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_close_from_xml_textblock(xmlarg, tb);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_close_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_close_from_xml_textblock(xmlarg, tb);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_close_from_xml_textblock e_xml_close_from_xml_textblock = new Vx.Data.Xml.Class_xml_close_from_xml_textblock();
  public static Vx.Data.Xml.Func_xml_close_from_xml_textblock t_xml_close_from_xml_textblock = new Vx.Data.Xml.Class_xml_close_from_xml_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_close_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string tag = xmlarg.tag();
        Vx.Core.Type_string text = tb.text();
        Vx.Data.Xml.Type_xml parent = xmlarg.parent();
        Vx.Core.Type_boolean isnoparent = Vx.Core.f_is_empty_1(
          parent
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Data.Xml.t_xml,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_2 = Vx.Core.f_or(
                  Vx.Core.f_eq(
                    Vx.Core.vx_new_string("/"),
                    text
                  ),
                  Vx.Core.f_eq(
                    text,
                    Vx.Core.f_new(
                      Vx.Core.t_string,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("</"),
                        tag,
                        Vx.Core.vx_new_string(">")
                      )
                    )
                  )
                );
                return output_2;
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_3 = Vx.Core.f_if_2(
                  Vx.Data.Xml.t_xml,
                  Vx.Core.vx_new(
                    Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_4 = isnoparent;
                        return output_4;
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_5 = xmlarg;
                        return output_5;
                      })
                    ),
                    Vx.Core.f_else(
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_6 = Vx.Core.f_copy(
                          parent,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":children"),
                            Vx.Core.f_new(
                              Vx.Data.Xml.t_xmllist,
                              Vx.Core.vx_new(
                                Vx.Core.t_anylist,
                                parent.children(),
                                Vx.Core.f_copy(
                                  xmlarg,
                                  Vx.Core.vx_new(
                                    Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":parent"),
                                    Vx.Core.f_empty(
                                      Vx.Data.Xml.t_xml
                                    )
                                  )
                                )
                              )
                            )
                          )
                        );
                        return output_6;
                      })
                    )
                  )
                );
                return output_3;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_7 = Vx.Core.f_copy(
                  xmlarg,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.f_msg_from_error_1(
                      Vx.Core.vx_new_string(":invalidxmlclosetag"),
                      Vx.Core.f_new(
                        Vx.Core.t_anymap,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":tag"),
                          text,
                          Vx.Core.vx_new_string(":startpos"),
                          tb.startpos(),
                          Vx.Core.vx_new_string(":endpos"),
                          tb.endpos(),
                          Vx.Core.vx_new_string(":line"),
                          tb.line(),
                          Vx.Core.vx_new_string(":column"),
                          tb.column()
                        )
                      )
                    )
                  )
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
   * @function xml_parse_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-parse<-xml-textblock)
   */
  public interface Func_xml_parse_from_xml_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_parse_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb);
  }

  public class Class_xml_parse_from_xml_textblock : Vx.Core.Class_base, Func_xml_parse_from_xml_textblock {

    public override Vx.Data.Xml.Func_xml_parse_from_xml_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_parse_from_xml_textblock output = new Vx.Data.Xml.Class_xml_parse_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_parse_from_xml_textblock output = new Vx.Data.Xml.Class_xml_parse_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_parse_from_xml_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_parse_from_xml_textblock;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_parse_from_xml_textblock(xmlarg, tb);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_parse_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_parse_from_xml_textblock(xmlarg, tb);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_parse_from_xml_textblock e_xml_parse_from_xml_textblock = new Vx.Data.Xml.Class_xml_parse_from_xml_textblock();
  public static Vx.Data.Xml.Func_xml_parse_from_xml_textblock t_xml_parse_from_xml_textblock = new Vx.Data.Xml.Class_xml_parse_from_xml_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_parse_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_delim delim = tb.delim();
        Vx.Core.Type_string text = tb.text();
        Vx.Core.Type_string starttext = delim.starttext();
        Vx.Core.Type_any output_1 = Vx.Core.f_switch(
          Vx.Data.Xml.t_xml,
          starttext,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_case_1(
              Vx.Core.vx_new_string(""),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_2 = Vx.Data.Xml.f_xml_text_from_xml_textblock(
                  xmlarg,
                  tb
                );
                return output_2;
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Textblock.c_delimbracketangle.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_3 = Vx.Data.Xml.f_xml_angle_from_xml_textblock(
                  xmlarg,
                  tb
                );
                return output_3;
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Textblock.c_delimwhitespace.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_4 = xmlarg;
                return output_4;
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Xml.c_delimxmlcomment.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_5 = xmlarg;
                return output_5;
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Xml.c_delimxmlcdata.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_6 = xmlarg;
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
   * @function xml_parse_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   * (func xml-parse<-xml-textblocklist)
   */
  public interface Func_xml_parse_from_xml_textblocklist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_parse_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist);
  }

  public class Class_xml_parse_from_xml_textblocklist : Vx.Core.Class_base, Func_xml_parse_from_xml_textblocklist {

    public override Vx.Data.Xml.Func_xml_parse_from_xml_textblocklist vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist output = new Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist output = new Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblocklist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_parse_from_xml_textblocklist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_parse_from_xml_textblocklist;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblocklist textblocklist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblocklist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_parse_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_parse_from_xml_textblocklist e_xml_parse_from_xml_textblocklist = new Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist();
  public static Vx.Data.Xml.Func_xml_parse_from_xml_textblocklist t_xml_parse_from_xml_textblocklist = new Vx.Data.Xml.Class_xml_parse_from_xml_textblocklist();

  public static Vx.Data.Xml.Type_xml f_xml_parse_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_any_from_list_start_reduce(
      Vx.Data.Xml.t_xml,
      textblocklist,
      xmlarg,
      Vx.Core.t_any_from_reduce.vx_fn_new((Vx.Core.Type_any xmlarg_lmb_any, Vx.Core.Type_any tb_lmb_any) => {
        Vx.Data.Xml.Type_xml xmlarg_lmb = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, xmlarg_lmb_any);
        Vx.Data.Textblock.Type_textblock tb_lmb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, tb_lmb_any);
        Vx.Core.Type_any output_1 = Vx.Data.Xml.f_xml_parse_from_xml_textblock(xmlarg_lmb, tb_lmb);
        return output_1;
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
  public interface Func_xml_properties_from_xml_textblocklist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_properties_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist);
  }

  public class Class_xml_properties_from_xml_textblocklist : Vx.Core.Class_base, Func_xml_properties_from_xml_textblocklist {

    public override Vx.Data.Xml.Func_xml_properties_from_xml_textblocklist vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist output = new Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist output = new Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-properties<-xml-textblocklist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_properties_from_xml_textblocklist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_properties_from_xml_textblocklist;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblocklist textblocklist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblocklist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_properties_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_properties_from_xml_textblocklist e_xml_properties_from_xml_textblocklist = new Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist();
  public static Vx.Data.Xml.Func_xml_properties_from_xml_textblocklist t_xml_properties_from_xml_textblocklist = new Vx.Data.Xml.Class_xml_properties_from_xml_textblocklist();

  public static Vx.Data.Xml.Type_xml f_xml_properties_from_xml_textblocklist(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblocklist textblocklist) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Xml.Type_xml xmlchg = Vx.Core.f_any_from_list_start_reduce(
          Vx.Data.Xml.t_xml,
          textblocklist,
          xmlarg,
          Vx.Core.t_any_from_reduce.vx_fn_new((reduce_any, current_any) => {
            Vx.Data.Xml.Type_xml reduce = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, reduce_any);
            Vx.Data.Textblock.Type_textblock current = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, current_any);
            Vx.Core.Type_any output_2 = Vx.Data.Xml.f_xml_property_from_xml_textblock(
              reduce,
              current
            );
            return output_2;
          })
        );
        Vx.Core.Type_any output_1 = xmlchg;
        return output_1;
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
  public interface Func_xml_property_from_xml_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_property_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tbarg);
  }

  public class Class_xml_property_from_xml_textblock : Vx.Core.Class_base, Func_xml_property_from_xml_textblock {

    public override Vx.Data.Xml.Func_xml_property_from_xml_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_property_from_xml_textblock output = new Vx.Data.Xml.Class_xml_property_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_property_from_xml_textblock output = new Vx.Data.Xml.Class_xml_property_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-property<-xml-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_property_from_xml_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_property_from_xml_textblock;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tbarg = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_property_from_xml_textblock(xmlarg, tbarg);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_property_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tbarg) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_property_from_xml_textblock(xmlarg, tbarg);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_property_from_xml_textblock e_xml_property_from_xml_textblock = new Vx.Data.Xml.Class_xml_property_from_xml_textblock();
  public static Vx.Data.Xml.Func_xml_property_from_xml_textblock t_xml_property_from_xml_textblock = new Vx.Data.Xml.Class_xml_property_from_xml_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_property_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tbarg) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_delim delim = tbarg.delim();
        Vx.Core.Type_string text = tbarg.text();
        Vx.Core.Type_string delimname = delim.name();
        Vx.Core.Type_string tag = xmlarg.tag();
        Vx.Core.Type_string prop = xmlarg.prop();
        Vx.Core.Type_stringmap propmap = xmlarg.propmap();
        Vx.Core.Type_any output_1 = Vx.Core.f_switch(
          Vx.Data.Xml.t_xml,
          delimname,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_case_1(
              Vx.Core.vx_new_string(""),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_2 = Vx.Core.f_if_2(
                  Vx.Data.Xml.t_xml,
                  Vx.Core.vx_new(
                    Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_3 = Vx.Type.f_boolean_from_string_starts(
                          text,
                          Vx.Core.vx_new_string("/")
                        );
                        return output_3;
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_4 = Vx.Data.Xml.f_xml_close_from_xml_textblock(
                          xmlarg,
                          tbarg
                        );
                        return output_4;
                      })
                    ),
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_5 = Vx.Core.f_eq(
                          Vx.Core.vx_new_string(":notag"),
                          tag
                        );
                        return output_5;
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_6 = Vx.Core.f_copy(
                          xmlarg,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":tag"),
                            text
                          )
                        );
                        return output_6;
                      })
                    ),
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_7 = Vx.Core.f_eq(
                          Vx.Core.vx_new_string(""),
                          prop
                        );
                        return output_7;
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Core.Type_any output_8 = Vx.Core.f_copy(
                          xmlarg,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":prop"),
                            text
                          )
                        );
                        return output_8;
                      })
                    )
                  )
                );
                return output_2;
              })
            ),
            Vx.Core.f_case_1(
              Vx.Core.vx_new_string("delimquote"),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_9 = Vx.Core.f_if_1(
                  Vx.Data.Xml.t_xml,
                  Vx.Core.f_eq(
                    Vx.Core.vx_new_string(""),
                    prop
                  ),
                  Vx.Core.f_copy(
                    xmlarg,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.f_msg_from_error(
                        Vx.Core.vx_new_string("Found quoted text with no matching attribute.")
                      )
                    )
                  ),
                  Vx.Core.f_copy(
                    xmlarg,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":prop"),
                      Vx.Core.vx_new_string(""),
                      Vx.Core.vx_new_string(":propmap"),
                      Vx.Core.f_copy(
                        propmap,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          prop,
                          Vx.Core.f_any_from_list(
                            Vx.Data.Textblock.t_textblock,
                            tbarg.children(),
                            Vx.Core.vx_new_int(1)
                          ).text()
                        )
                      )
                    )
                  )
                );
                return output_9;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_10 = xmlarg;
                return output_10;
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
   * @function xml_read_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml-read<-file)
   */
  public interface Func_xml_read_from_file : Vx.Core.Func_any_from_any_context {
    public Vx.Data.Xml.Type_xml vx_xml_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file);
  }

  public class Class_xml_read_from_file : Vx.Core.Class_base, Func_xml_read_from_file {

    public override Vx.Data.Xml.Func_xml_read_from_file vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_read_from_file output = new Vx.Data.Xml.Class_xml_read_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_read_from_file output = new Vx.Data.Xml.Class_xml_read_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-read<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_read_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_read_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_xml_read_from_file(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_xml_read_from_file(context, file);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_read_from_file(context, file);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_read_from_file e_xml_read_from_file = new Vx.Data.Xml.Class_xml_read_from_file();
  public static Vx.Data.Xml.Func_xml_read_from_file t_xml_read_from_file = new Vx.Data.Xml.Class_xml_read_from_file();

  public static Vx.Data.Xml.Type_xml f_xml_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.File.Type_file loaded = Vx.Data.File.f_file_read_from_file(
          context,
          file
        );
        Vx.Core.Type_any output_1 = Vx.Data.Xml.f_xml_from_file(
          loaded
        );
        return output_1;
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
  public interface Func_xml_text_from_xml_textblock : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.Xml.Type_xml vx_xml_text_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb);
  }

  public class Class_xml_text_from_xml_textblock : Vx.Core.Class_base, Func_xml_text_from_xml_textblock {

    public override Vx.Data.Xml.Func_xml_text_from_xml_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_text_from_xml_textblock output = new Vx.Data.Xml.Class_xml_text_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_text_from_xml_textblock output = new Vx.Data.Xml.Class_xml_text_from_xml_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml-text<-xml-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_text_from_xml_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_text_from_xml_textblock;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Xml.Type_xml xmlarg = Vx.Core.f_any_from_any(Vx.Data.Xml.t_xml, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.Xml.f_xml_text_from_xml_textblock(xmlarg, tb);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_text_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_text_from_xml_textblock(xmlarg, tb);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_text_from_xml_textblock e_xml_text_from_xml_textblock = new Vx.Data.Xml.Class_xml_text_from_xml_textblock();
  public static Vx.Data.Xml.Func_xml_text_from_xml_textblock t_xml_text_from_xml_textblock = new Vx.Data.Xml.Class_xml_text_from_xml_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_text_from_xml_textblock(Vx.Data.Xml.Type_xml xmlarg, Vx.Data.Textblock.Type_textblock tb) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = tb.text();
        Vx.Data.Xml.Type_xml xmlchg = Vx.Core.f_new(
          Vx.Data.Xml.t_xml,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            text
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Data.Xml.t_xml,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_2 = Vx.Core.f_is_empty_1(
                  xmlarg
                );
                return output_2;
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_3 = xmlchg;
                return output_3;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_4 = Vx.Core.f_copy(
                  xmlarg,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":children"),
                    Vx.Core.f_new(
                      Vx.Data.Xml.t_xmllist,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        xmlarg.children(),
                        xmlchg
                      )
                    )
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
   * @function xml_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml<-file)
   */
  public interface Func_xml_from_file : Vx.Core.Func_any_from_any {
    public Vx.Data.Xml.Type_xml vx_xml_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_xml_from_file : Vx.Core.Class_base, Func_xml_from_file {

    public override Vx.Data.Xml.Func_xml_from_file vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_file output = new Vx.Data.Xml.Class_xml_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_file output = new Vx.Data.Xml.Class_xml_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_xml_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_xml_from_file(file);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_from_file(Vx.Data.File.Type_file file) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_from_file(file);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_from_file e_xml_from_file = new Vx.Data.Xml.Class_xml_from_file();
  public static Vx.Data.Xml.Func_xml_from_file t_xml_from_file = new Vx.Data.Xml.Class_xml_from_file();

  public static Vx.Data.Xml.Type_xml f_xml_from_file(Vx.Data.File.Type_file file) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = file.text();
        Vx.Core.Type_any output_1 = Vx.Data.Xml.f_xml_from_string(
          text
        );
        return output_1;
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
  public interface Func_xml_from_string : Vx.Core.Func_any_from_any {
    public Vx.Data.Xml.Type_xml vx_xml_from_string(Vx.Core.Type_string text);
  }

  public class Class_xml_from_string : Vx.Core.Class_base, Func_xml_from_string {

    public override Vx.Data.Xml.Func_xml_from_string vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_string output = new Vx.Data.Xml.Class_xml_from_string();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_string output = new Vx.Data.Xml.Class_xml_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_from_string;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_from_string;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_xml_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_xml_from_string(text);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_from_string(Vx.Core.Type_string text) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_from_string(text);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_from_string e_xml_from_string = new Vx.Data.Xml.Class_xml_from_string();
  public static Vx.Data.Xml.Func_xml_from_string t_xml_from_string = new Vx.Data.Xml.Class_xml_from_string();

  public static Vx.Data.Xml.Type_xml f_xml_from_string(Vx.Core.Type_string text) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Core.f_let(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblock tb = Vx.Data.Xml.f_textblock_xml_from_string(
          text
        );
        Vx.Core.Type_any output_1 = Vx.Data.Xml.f_xml_from_textblock(
          tb
        );
        return output_1;
      })
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
  public interface Func_xml_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Data.Xml.Type_xml vx_xml_from_textblock(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_xml_from_textblock : Vx.Core.Class_base, Func_xml_from_textblock {

    public override Vx.Data.Xml.Func_xml_from_textblock vx_new(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_textblock output = new Vx.Data.Xml.Class_xml_from_textblock();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Xml.Class_xml_from_textblock output = new Vx.Data.Xml.Class_xml_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Data.Xml.e_xml_from_textblock;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Xml.t_xml_from_textblock;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Xml.f_xml_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Xml.f_xml_from_textblock(textblock);
      return output;
    }

    public Vx.Data.Xml.Type_xml vx_xml_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
      Vx.Data.Xml.Type_xml output = Vx.Data.Xml.f_xml_from_textblock(textblock);
      return output;
    }

  }

  public static Vx.Data.Xml.Func_xml_from_textblock e_xml_from_textblock = new Vx.Data.Xml.Class_xml_from_textblock();
  public static Vx.Data.Xml.Func_xml_from_textblock t_xml_from_textblock = new Vx.Data.Xml.Class_xml_from_textblock();

  public static Vx.Data.Xml.Type_xml f_xml_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Data.Xml.Type_xml output = Vx.Data.Xml.e_xml;
    output = Vx.Data.Xml.f_xml_parse_from_xml_textblocklist(
      Vx.Core.f_empty(
        Vx.Data.Xml.t_xml
      ),
      textblock.children()
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Const_delimxml.const_new(c_delimxml);
    Const_delimxmlcdata.const_new(c_delimxmlcdata);
    Const_delimxmlcomment.const_new(c_delimxmlcomment);
    Const_delimxmlequal.const_new(c_delimxmlequal);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("xml", Vx.Data.Xml.t_xml);
    maptype.put("xmllist", Vx.Data.Xml.t_xmllist);
    maptype.put("xmlpropmap", Vx.Data.Xml.t_xmlpropmap);
    mapconst.put("delimxml", Vx.Data.Xml.c_delimxml);
    mapconst.put("delimxmlcdata", Vx.Data.Xml.c_delimxmlcdata);
    mapconst.put("delimxmlcomment", Vx.Data.Xml.c_delimxmlcomment);
    mapconst.put("delimxmlequal", Vx.Data.Xml.c_delimxmlequal);
    mapfunc.put("string-decodexml<-string", Vx.Data.Xml.t_string_decodexml_from_string);
    mapfunc.put("string-first<-xml", Vx.Data.Xml.t_string_first_from_xml);
    mapfunc.put("textblock-xml<-string", Vx.Data.Xml.t_textblock_xml_from_string);
    mapfunc.put("xml-angle<-xml-textblock", Vx.Data.Xml.t_xml_angle_from_xml_textblock);
    mapfunc.put("xml-close<-xml-textblock", Vx.Data.Xml.t_xml_close_from_xml_textblock);
    mapfunc.put("xml-parse<-xml-textblock", Vx.Data.Xml.t_xml_parse_from_xml_textblock);
    mapfunc.put("xml-parse<-xml-textblocklist", Vx.Data.Xml.t_xml_parse_from_xml_textblocklist);
    mapfunc.put("xml-properties<-xml-textblocklist", Vx.Data.Xml.t_xml_properties_from_xml_textblocklist);
    mapfunc.put("xml-property<-xml-textblock", Vx.Data.Xml.t_xml_property_from_xml_textblock);
    mapfunc.put("xml-read<-file", Vx.Data.Xml.t_xml_read_from_file);
    mapfunc.put("xml-text<-xml-textblock", Vx.Data.Xml.t_xml_text_from_xml_textblock);
    mapfunc.put("xml<-file", Vx.Data.Xml.t_xml_from_file);
    mapfunc.put("xml<-string", Vx.Data.Xml.t_xml_from_string);
    mapfunc.put("xml<-textblock", Vx.Data.Xml.t_xml_from_textblock);
    Vx.Core.vx_global_package_set("vx/data/xml", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
