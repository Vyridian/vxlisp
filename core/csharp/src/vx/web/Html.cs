namespace Vx.Web;

public static class Html {


  /**
   * type: body
   * Body Tag
   * (type body)
   */
  public interface Type_body : Vx.Core.Type_struct {
    public Vx.Web.Html.Type_divchildlist nodes();
  }

  public class Class_body : Vx.Core.Class_base, Type_body {

    public Vx.Web.Html.Type_divchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_divchildlist nodes() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_body vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_body,
       vals);
    }

    public override Vx.Web.Html.Type_body vx_copy(params Object[] vals) {
      Type_body output = this;
      bool ischanged = false;
      Class_body val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Web.Html.Type_divchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_divchildlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_divchild) { // default property
            Vx.Web.Html.Type_divchild valdefault = (Vx.Web.Html.Type_divchild)valsub;
            Vx.Web.Html.Type_divchildlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_divchildlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/body", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/body", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_body work = new Class_body();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_body;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_body;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "body", // name
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

  public static Type_body e_body = new Class_body();
  public static Type_body t_body = new Class_body();

  /**
   * type: details
   * Details Tag
   * (type details)
   */
  public interface Type_details : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Web.Html.Type_divchildlist summary();
    public Vx.Web.Html.Type_divchildlist nodes();
  }

  public class Class_details : Vx.Core.Class_base, Type_details {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_divchildlist? vx_p_summary = null;

    public Vx.Web.Html.Type_divchildlist summary() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_summary != null) {
        output = this.vx_p_summary;
      }
      return output;
    }

    public Vx.Web.Html.Type_divchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_divchildlist nodes() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":summary", this.summary());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_details vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_details,
       vals);
    }

    public override Vx.Web.Html.Type_details vx_copy(params Object[] vals) {
      Type_details output = this;
      bool ischanged = false;
      Class_details val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_divchildlist vx_p_summary = val.summary();
      Vx.Web.Html.Type_divchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":summary");
      validkeys.Add(":nodes");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":summary":
            if (valsub == vx_p_summary) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valsummary) {
              ischanged = true;
              vx_p_summary = valsummary;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("summary"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_details work = new Class_details();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_summary = vx_p_summary;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_details;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_details;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_details e_details = new Class_details();
  public static Type_details t_details = new Class_details();

  /**
   * type: div
   * Div Tag
   * (type div)
   */
  public interface Type_div : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Web.Html.Type_divchildlist nodes();
  }

  public class Class_div : Vx.Core.Class_base, Type_div {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_divchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_divchildlist nodes() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_div vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_div,
       vals);
    }

    public override Vx.Web.Html.Type_div vx_copy(params Object[] vals) {
      Type_div output = this;
      bool ischanged = false;
      Class_div val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_divchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_divchildlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_divchild) { // default property
            Vx.Web.Html.Type_divchild valdefault = (Vx.Web.Html.Type_divchild)valsub;
            Vx.Web.Html.Type_divchildlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_divchildlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_div work = new Class_div();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_div;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_div;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_div e_div = new Class_div();
  public static Type_div t_div = new Class_div();

  /**
   * type: divchild
   * Div Child Trait
   * (type divchild)
   */
  public interface Type_divchild : Vx.Core.Type_struct {
  }

  public class Class_divchild : Vx.Core.Class_base, Type_divchild {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_divchild vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_divchild,
       vals);
    }

    public override Vx.Web.Html.Type_divchild vx_copy(params Object[] vals) {
      Type_divchild output = this;
      bool ischanged = false;
      Class_divchild val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_divchild work = new Class_divchild();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchild;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_divchild;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "divchild", // name
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

  public static Type_divchild e_divchild = new Class_divchild();
  public static Type_divchild t_divchild = new Class_divchild();

  /**
   * type: divchildlist
   * List of divchild
   * (type divchildlist)
   */
  public interface Type_divchildlist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_divchild> vx_listdivchild();
    public Vx.Web.Html.Type_divchild vx_divchild(Vx.Core.Type_int index);
  }

  public class Class_divchildlist : Vx.Core.Class_base, Type_divchildlist {

    public List<Vx.Web.Html.Type_divchild> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_divchild>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_divchild vx_divchild(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_divchild output = Vx.Web.Html.e_divchild;
      Vx.Web.Html.Class_divchildlist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_divchild> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_divchild> vx_listdivchild() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_divchild(index);
    }

    public override Vx.Web.Html.Type_divchildlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_divchildlist,
       vals);
    }

    public override Vx.Web.Html.Type_divchildlist vx_copy(params Object[] vals) {
      Type_divchildlist output = this;
      bool ischanged = false;
      Class_divchildlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_divchild> listval = new List<Vx.Web.Html.Type_divchild>(val.vx_listdivchild());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_divchild allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_divchild) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_divchild)valsub);
        } else if (valsub is Vx.Web.Html.Type_divchildlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listdivchild());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_divchild valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_divchildlist work = new Class_divchildlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchildlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_divchildlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_divchild), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_divchildlist e_divchildlist = new Class_divchildlist();
  public static Type_divchildlist t_divchildlist = new Class_divchildlist();

  /**
   * type: divlist
   * List of div
   * (type divlist)
   */
  public interface Type_divlist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_div> vx_listdiv();
    public Vx.Web.Html.Type_div vx_div(Vx.Core.Type_int index);
  }

  public class Class_divlist : Vx.Core.Class_base, Type_divlist {

    public List<Vx.Web.Html.Type_div> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_div>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_div vx_div(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_div output = Vx.Web.Html.e_div;
      Vx.Web.Html.Class_divlist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_div> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_div> vx_listdiv() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_div(index);
    }

    public override Vx.Web.Html.Type_divlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_divlist,
       vals);
    }

    public override Vx.Web.Html.Type_divlist vx_copy(params Object[] vals) {
      Type_divlist output = this;
      bool ischanged = false;
      Class_divlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_div> listval = new List<Vx.Web.Html.Type_div>(val.vx_listdiv());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_div allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_div) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_div)valsub);
        } else if (valsub is Vx.Web.Html.Type_divlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listdiv());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_div valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_divlist work = new Class_divlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_divlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_div), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_divlist e_divlist = new Class_divlist();
  public static Type_divlist t_divlist = new Class_divlist();

  /**
   * type: footer
   * Body Tag
   * (type footer)
   */
  public interface Type_footer : Vx.Core.Type_struct {
    public Vx.Web.Html.Type_divchildlist nodes();
  }

  public class Class_footer : Vx.Core.Class_base, Type_footer {

    public Vx.Web.Html.Type_divchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_divchildlist nodes() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_footer vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_footer,
       vals);
    }

    public override Vx.Web.Html.Type_footer vx_copy(params Object[] vals) {
      Type_footer output = this;
      bool ischanged = false;
      Class_footer val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Web.Html.Type_divchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_divchildlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_divchild) { // default property
            Vx.Web.Html.Type_divchild valdefault = (Vx.Web.Html.Type_divchild)valsub;
            Vx.Web.Html.Type_divchildlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_divchildlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/footer", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/footer", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_footer work = new Class_footer();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_footer;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_footer;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "footer", // name
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

  public static Type_footer e_footer = new Class_footer();
  public static Type_footer t_footer = new Class_footer();

  /**
   * type: h1
   * Header 1 Tag
   * (type h1)
   */
  public interface Type_h1 : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Core.Type_string text();
  }

  public class Class_h1 : Vx.Core.Class_base, Type_h1 {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_h1 vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_h1,
       vals);
    }

    public override Vx.Web.Html.Type_h1 vx_copy(params Object[] vals) {
      Type_h1 output = this;
      bool ischanged = false;
      Class_h1 val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_text = val.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":text");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Core.Type_string) { // default property
            ischanged = true;
            vx_p_text = (Vx.Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub is Vx.Core.Type_string) { // default property
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) { // default property
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_h1 work = new Class_h1();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_h1;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_h1;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_h1 e_h1 = new Class_h1();
  public static Type_h1 t_h1 = new Class_h1();

  /**
   * type: h2
   * Header 2 Tag
   * (type h2)
   */
  public interface Type_h2 : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Core.Type_string text();
  }

  public class Class_h2 : Vx.Core.Class_base, Type_h2 {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_h2 vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_h2,
       vals);
    }

    public override Vx.Web.Html.Type_h2 vx_copy(params Object[] vals) {
      Type_h2 output = this;
      bool ischanged = false;
      Class_h2 val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_text = val.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":text");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Core.Type_string) { // default property
            ischanged = true;
            vx_p_text = (Vx.Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub is Vx.Core.Type_string) { // default property
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) { // default property
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_h2 work = new Class_h2();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_h2;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_h2;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_h2 e_h2 = new Class_h2();
  public static Type_h2 t_h2 = new Class_h2();

  /**
   * type: h3
   * Header 3 Tag
   * (type h3)
   */
  public interface Type_h3 : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Core.Type_string text();
  }

  public class Class_h3 : Vx.Core.Class_base, Type_h3 {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_h3 vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_h3,
       vals);
    }

    public override Vx.Web.Html.Type_h3 vx_copy(params Object[] vals) {
      Type_h3 output = this;
      bool ischanged = false;
      Class_h3 val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_text = val.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":text");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Core.Type_string) { // default property
            ischanged = true;
            vx_p_text = (Vx.Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub is Vx.Core.Type_string) { // default property
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) { // default property
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_h3 work = new Class_h3();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_h3;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_h3;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_h3 e_h3 = new Class_h3();
  public static Type_h3 t_h3 = new Class_h3();

  /**
   * type: head
   * Head Tag
   * (type head)
   */
  public interface Type_head : Vx.Core.Type_struct {
    public Vx.Web.Html.Type_headchildlist nodes();
  }

  public class Class_head : Vx.Core.Class_base, Type_head {

    public Vx.Web.Html.Type_headchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_headchildlist nodes() {
      Vx.Web.Html.Type_headchildlist output = Vx.Web.Html.e_headchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_head vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_head,
       vals);
    }

    public override Vx.Web.Html.Type_head vx_copy(params Object[] vals) {
      Type_head output = this;
      bool ischanged = false;
      Class_head val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Web.Html.Type_headchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_headchildlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_headchildlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_headchild) { // default property
            Vx.Web.Html.Type_headchild valdefault = (Vx.Web.Html.Type_headchild)valsub;
            Vx.Web.Html.Type_headchildlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_headchildlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/head", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_headchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/head", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_head work = new Class_head();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_head;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_head;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "head", // name
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

  public static Type_head e_head = new Class_head();
  public static Type_head t_head = new Class_head();

  /**
   * type: headchild
   * Head Child Trait
   * (type headchild)
   */
  public interface Type_headchild : Vx.Core.Type_struct {
  }

  public class Class_headchild : Vx.Core.Class_base, Type_headchild {

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_headchild vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_headchild,
       vals);
    }

    public override Vx.Web.Html.Type_headchild vx_copy(params Object[] vals) {
      Type_headchild output = this;
      bool ischanged = false;
      Class_headchild val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_headchild work = new Class_headchild();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_headchild;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_headchild;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "headchild", // name
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

  public static Type_headchild e_headchild = new Class_headchild();
  public static Type_headchild t_headchild = new Class_headchild();

  /**
   * type: headchildlist
   * List of headchild
   * (type headchildlist)
   */
  public interface Type_headchildlist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_headchild> vx_listheadchild();
    public Vx.Web.Html.Type_headchild vx_headchild(Vx.Core.Type_int index);
  }

  public class Class_headchildlist : Vx.Core.Class_base, Type_headchildlist {

    public List<Vx.Web.Html.Type_headchild> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_headchild>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_headchild vx_headchild(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_headchild output = Vx.Web.Html.e_headchild;
      Vx.Web.Html.Class_headchildlist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_headchild> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_headchild> vx_listheadchild() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_headchild(index);
    }

    public override Vx.Web.Html.Type_headchildlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_headchildlist,
       vals);
    }

    public override Vx.Web.Html.Type_headchildlist vx_copy(params Object[] vals) {
      Type_headchildlist output = this;
      bool ischanged = false;
      Class_headchildlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_headchild> listval = new List<Vx.Web.Html.Type_headchild>(val.vx_listheadchild());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_headchild allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_headchild) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_headchild)valsub);
        } else if (valsub is Vx.Web.Html.Type_headchildlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listheadchild());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_headchild valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_headchildlist work = new Class_headchildlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_headchildlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_headchildlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_headchild), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_headchildlist e_headchildlist = new Class_headchildlist();
  public static Type_headchildlist t_headchildlist = new Class_headchildlist();

  /**
   * type: html
   * Html Tag
   * (type html)
   */
  public interface Type_html : Vx.Core.Type_struct {
    public Vx.Core.Type_string lang();
    public Vx.Web.Html.Type_head head();
    public Vx.Web.Html.Type_body body();
    public Vx.Web.Html.Type_footer footer();
  }

  public class Class_html : Vx.Core.Class_base, Type_html {

    public Vx.Core.Type_string? vx_p_lang = null;

    public Vx.Core.Type_string lang() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_lang != null) {
        output = this.vx_p_lang;
      }
      return output;
    }

    public Vx.Web.Html.Type_head? vx_p_head = null;

    public Vx.Web.Html.Type_head head() {
      Vx.Web.Html.Type_head output = Vx.Web.Html.e_head;
      if (this.vx_p_head != null) {
        output = this.vx_p_head;
      }
      return output;
    }

    public Vx.Web.Html.Type_body? vx_p_body = null;

    public Vx.Web.Html.Type_body body() {
      Vx.Web.Html.Type_body output = Vx.Web.Html.e_body;
      if (this.vx_p_body != null) {
        output = this.vx_p_body;
      }
      return output;
    }

    public Vx.Web.Html.Type_footer? vx_p_footer = null;

    public Vx.Web.Html.Type_footer footer() {
      Vx.Web.Html.Type_footer output = Vx.Web.Html.e_footer;
      if (this.vx_p_footer != null) {
        output = this.vx_p_footer;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":lang":
        output = this.lang();
        break;
      case ":head":
        output = this.head();
        break;
      case ":body":
        output = this.body();
        break;
      case ":footer":
        output = this.footer();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":lang", this.lang());
      output.put(":head", this.head());
      output.put(":body", this.body());
      output.put(":footer", this.footer());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_html vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_html,
       vals);
    }

    public override Vx.Web.Html.Type_html vx_copy(params Object[] vals) {
      Type_html output = this;
      bool ischanged = false;
      Class_html val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_lang = val.lang();
      Vx.Web.Html.Type_head vx_p_head = val.head();
      Vx.Web.Html.Type_body vx_p_body = val.body();
      Vx.Web.Html.Type_footer vx_p_footer = val.footer();
      List<string> validkeys = new List<string>();
      validkeys.Add(":lang");
      validkeys.Add(":head");
      validkeys.Add(":body");
      validkeys.Add(":footer");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":lang":
            if (valsub == vx_p_lang) {
            } else if (valsub is Vx.Core.Type_string vallang) {
              ischanged = true;
              vx_p_lang = vallang;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_lang = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("lang"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":head":
            if (valsub == vx_p_head) {
            } else if (valsub is Vx.Web.Html.Type_head valhead) {
              ischanged = true;
              vx_p_head = valhead;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("head"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":body":
            if (valsub == vx_p_body) {
            } else if (valsub is Vx.Web.Html.Type_body valbody) {
              ischanged = true;
              vx_p_body = valbody;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("body"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":footer":
            if (valsub == vx_p_footer) {
            } else if (valsub is Vx.Web.Html.Type_footer valfooter) {
              ischanged = true;
              vx_p_footer = valfooter;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("footer"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_html work = new Class_html();
        work.vx_p_lang = vx_p_lang;
        work.vx_p_head = vx_p_head;
        work.vx_p_body = vx_p_body;
        work.vx_p_footer = vx_p_footer;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_html;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_html;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "html", // name
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

  public static Type_html e_html = new Class_html();
  public static Type_html t_html = new Class_html();

  /**
   * type: img
   * Image Tag
   * (type img)
   */
  public interface Type_img : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Core.Type_string src();
  }

  public class Class_img : Vx.Core.Class_base, Type_img {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_src = null;

    public Vx.Core.Type_string src() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_src != null) {
        output = this.vx_p_src;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":src":
        output = this.src();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":src", this.src());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_img vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_img,
       vals);
    }

    public override Vx.Web.Html.Type_img vx_copy(params Object[] vals) {
      Type_img output = this;
      bool ischanged = false;
      Class_img val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_src = val.src();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":src");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Core.Type_string) { // default property
            ischanged = true;
            vx_p_src = (Vx.Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub is Vx.Core.Type_string) { // default property
              ischanged = true;
              vx_p_src = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) { // default property
              ischanged = true;
              vx_p_src = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":src":
            if (valsub == vx_p_src) {
            } else if (valsub is Vx.Core.Type_string valsrc) {
              ischanged = true;
              vx_p_src = valsrc;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_src = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("src"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_img work = new Class_img();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_src = vx_p_src;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_img;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_img;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "img", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_img e_img = new Class_img();
  public static Type_img t_img = new Class_img();

  /**
   * type: meta
   * Meta Tag
   * (type meta)
   */
  public interface Type_meta : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_headchild {
    public Vx.Core.Type_string charset();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string content();
  }

  public class Class_meta : Vx.Core.Class_base, Type_meta {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_charset = null;

    public Vx.Core.Type_string charset() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_charset != null) {
        output = this.vx_p_charset;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_content = null;

    public Vx.Core.Type_string content() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_content != null) {
        output = this.vx_p_content;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":charset":
        output = this.charset();
        break;
      case ":name":
        output = this.name();
        break;
      case ":content":
        output = this.content();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":charset", this.charset());
      output.put(":name", this.name());
      output.put(":content", this.content());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_meta vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_meta,
       vals);
    }

    public override Vx.Web.Html.Type_meta vx_copy(params Object[] vals) {
      Type_meta output = this;
      bool ischanged = false;
      Class_meta val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_charset = val.charset();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_content = val.content();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":charset");
      validkeys.Add(":name");
      validkeys.Add(":content");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":charset":
            if (valsub == vx_p_charset) {
            } else if (valsub is Vx.Core.Type_string valcharset) {
              ischanged = true;
              vx_p_charset = valcharset;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_charset = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("charset"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":content":
            if (valsub == vx_p_content) {
            } else if (valsub is Vx.Core.Type_string valcontent) {
              ischanged = true;
              vx_p_content = valcontent;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_content = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("content"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_meta work = new Class_meta();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_charset = vx_p_charset;
        work.vx_p_name = vx_p_name;
        work.vx_p_content = vx_p_content;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_meta;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_meta;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
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

  public static Type_meta e_meta = new Class_meta();
  public static Type_meta t_meta = new Class_meta();

  /**
   * type: node
   * Common Html Node Trait
   * (type node)
   */
  public interface Type_node : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Event.Type_eventmap eventmap();
    public Vx.Web.Html.Type_style style();
    public Vx.Web.Html.Type_style style_unique();
    public Vx.Web.Html.Type_stylelist stylelist();
  }

  public class Class_node : Vx.Core.Class_base, Type_node {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_node vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_node,
       vals);
    }

    public override Vx.Web.Html.Type_node vx_copy(params Object[] vals) {
      Type_node output = this;
      bool ischanged = false;
      Class_node val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_node work = new Class_node();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_node;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "node", // name
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

  public static Type_node e_node = new Class_node();
  public static Type_node t_node = new Class_node();

  /**
   * type: nodelist
   * List of node
   * (type nodelist)
   */
  public interface Type_nodelist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_node> vx_listnode();
    public Vx.Web.Html.Type_node vx_node(Vx.Core.Type_int index);
  }

  public class Class_nodelist : Vx.Core.Class_base, Type_nodelist {

    public List<Vx.Web.Html.Type_node> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_node>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_node vx_node(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
      Vx.Web.Html.Class_nodelist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_node> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_node> vx_listnode() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_node(index);
    }

    public override Vx.Web.Html.Type_nodelist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_nodelist,
       vals);
    }

    public override Vx.Web.Html.Type_nodelist vx_copy(params Object[] vals) {
      Type_nodelist output = this;
      bool ischanged = false;
      Class_nodelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_node> listval = new List<Vx.Web.Html.Type_node>(val.vx_listnode());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_node allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_node) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_node)valsub);
        } else if (valsub is Vx.Web.Html.Type_nodelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listnode());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_node valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_nodelist work = new Class_nodelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_nodelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_nodelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_nodelist e_nodelist = new Class_nodelist();
  public static Type_nodelist t_nodelist = new Class_nodelist();

  /**
   * type: p
   * Paragraph Tag
   * (type p)
   */
  public interface Type_p : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Core.Type_string text();
  }

  public class Class_p : Vx.Core.Class_base, Type_p {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_p vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_p,
       vals);
    }

    public override Vx.Web.Html.Type_p vx_copy(params Object[] vals) {
      Type_p output = this;
      bool ischanged = false;
      Class_p val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_text = val.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":text");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Core.Type_string) { // default property
            ischanged = true;
            vx_p_text = (Vx.Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub is Vx.Core.Type_string) { // default property
              ischanged = true;
              vx_p_text = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) { // default property
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_p work = new Class_p();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_p;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_p;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_p e_p = new Class_p();
  public static Type_p t_p = new Class_p();

  /**
   * type: propmap
   * Map of props
   * (type propmap)
   */
  public interface Type_propmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_string key);
  }

  public class Class_propmap : Vx.Core.Class_base, Type_propmap {

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)Convert.ChangeType(this.vx_p_map, typeof(Vx.Core.Map<string, Vx.Core.Type_any>));
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
      Vx.Web.Html.Class_propmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_string);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_string> vx_mapstring() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_string(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Web.Html.Class_propmap output = new Vx.Web.Html.Class_propmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_string> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_string castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/web/html/propmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Web.Html.Type_propmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_propmap,
       vals);
    }

    public override Vx.Web.Html.Type_propmap vx_copy(params Object[] vals) {
      Type_propmap output = this;
      bool ischanged = false;
      Class_propmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_string> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_string>(val.vx_mapstring());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (Object valsub in vals) {
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/propmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_string? valany = null;
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/propmap", ":invalidkeyvalue", msgmap);
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
        Class_propmap work = new Class_propmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_propmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_propmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
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
    }

  }

  public static Type_propmap e_propmap = new Class_propmap();
  public static Type_propmap t_propmap = new Class_propmap();

  /**
   * type: style
   * Programmable Cascading Style
   * (type style)
   */
  public interface Type_style : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Web.Html.Type_propmap props();
    public Vx.Web.Html.Type_stylelist stylelist();
  }

  public class Class_style : Vx.Core.Class_base, Type_style {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Web.Html.Type_propmap? vx_p_props = null;

    public Vx.Web.Html.Type_propmap props() {
      Vx.Web.Html.Type_propmap output = Vx.Web.Html.e_propmap;
      if (this.vx_p_props != null) {
        output = this.vx_p_props;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
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
      case ":props":
        output = this.props();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":props", this.props());
      output.put(":stylelist", this.stylelist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_style vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_style,
       vals);
    }

    public override Vx.Web.Html.Type_style vx_copy(params Object[] vals) {
      Type_style output = this;
      bool ischanged = false;
      Class_style val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Web.Html.Type_propmap vx_p_props = val.props();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":props");
      validkeys.Add(":stylelist");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":props":
            if (valsub == vx_p_props) {
            } else if (valsub is Vx.Web.Html.Type_propmap valprops) {
              ischanged = true;
              vx_p_props = valprops;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("props"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_style work = new Class_style();
        work.vx_p_name = vx_p_name;
        work.vx_p_props = vx_p_props;
        work.vx_p_stylelist = vx_p_stylelist;
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
        "vx/web/html", // pkgname
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
   * List of style
   * (type stylelist)
   */
  public interface Type_stylelist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_style> vx_liststyle();
    public Vx.Web.Html.Type_style vx_style(Vx.Core.Type_int index);
  }

  public class Class_stylelist : Vx.Core.Class_base, Type_stylelist {

    public List<Vx.Web.Html.Type_style> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_style>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_style vx_style(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      Vx.Web.Html.Class_stylelist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_style> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_style> vx_liststyle() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_style(index);
    }

    public override Vx.Web.Html.Type_stylelist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylelist,
       vals);
    }

    public override Vx.Web.Html.Type_stylelist vx_copy(params Object[] vals) {
      Type_stylelist output = this;
      bool ischanged = false;
      Class_stylelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_style> listval = new List<Vx.Web.Html.Type_style>(val.vx_liststyle());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_style allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_style) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_style)valsub);
        } else if (valsub is Vx.Web.Html.Type_stylelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_liststyle());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_style valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
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
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
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
   * Map of style
   * (type stylemap)
   */
  public interface Type_stylemap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Web.Html.Type_style> vx_mapstyle();
    public Vx.Web.Html.Type_style vx_style(Vx.Core.Type_string key);
  }

  public class Class_stylemap : Vx.Core.Class_base, Type_stylemap {

    public Vx.Core.Map<string, Vx.Web.Html.Type_style> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Web.Html.Type_style>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)Convert.ChangeType(this.vx_p_map, typeof(Vx.Core.Map<string, Vx.Core.Type_any>));
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Web.Html.Type_style castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Web.Html.Type_style> map = new Vx.Core.LinkedHashMap<string, Vx.Web.Html.Type_style>(this.vx_p_map);
        if (castval == Vx.Web.Html.e_style) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Web.Html.Type_style vx_style(Vx.Core.Type_string key) {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      Vx.Web.Html.Class_stylemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Web.Html.Type_style> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Web.Html.e_style);
      return output;
    }

    public Vx.Core.Map<string, Vx.Web.Html.Type_style> vx_mapstyle() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_style(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Web.Html.Class_stylemap output = new Vx.Web.Html.Class_stylemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Web.Html.Type_style> map = new Vx.Core.LinkedHashMap<string, Vx.Web.Html.Type_style>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Web.Html.Type_style castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/web/html/stylemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Web.Html.Type_stylemap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylemap,
       vals);
    }

    public override Vx.Web.Html.Type_stylemap vx_copy(params Object[] vals) {
      Type_stylemap output = this;
      bool ischanged = false;
      Class_stylemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Web.Html.Type_style> mapval = new Vx.Core.LinkedHashMap<string, Vx.Web.Html.Type_style>(val.vx_mapstyle());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (Object valsub in vals) {
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/stylemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Web.Html.Type_style? valany = null;
          if (false) {
          } else if (valsub is Vx.Web.Html.Type_style valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Web.Html.Type_style) {
            valany = valsub as Vx.Web.Html.Type_style;
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/stylemap", ":invalidkeyvalue", msgmap);
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
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
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
   * Programmable Cascading Style Sheet CSS type
   * (type stylesheet)
   */
  public interface Type_stylesheet : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_headchild {
    public Vx.Core.Type_string name();
    public Vx.Web.Html.Type_stylelist styles();
    public Vx.Web.Html.Type_stylemap stylemap();
  }

  public class Class_stylesheet : Vx.Core.Class_base, Type_stylesheet {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_styles = null;

    public Vx.Web.Html.Type_stylelist styles() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_styles != null) {
        output = this.vx_p_styles;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylemap? vx_p_stylemap = null;

    public Vx.Web.Html.Type_stylemap stylemap() {
      Vx.Web.Html.Type_stylemap output = Vx.Web.Html.e_stylemap;
      if (this.vx_p_stylemap != null) {
        output = this.vx_p_stylemap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":name":
        output = this.name();
        break;
      case ":styles":
        output = this.styles();
        break;
      case ":stylemap":
        output = this.stylemap();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":name", this.name());
      output.put(":styles", this.styles());
      output.put(":stylemap", this.stylemap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_stylesheet vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_stylesheet,
       vals);
    }

    public override Vx.Web.Html.Type_stylesheet vx_copy(params Object[] vals) {
      Type_stylesheet output = this;
      bool ischanged = false;
      Class_stylesheet val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Web.Html.Type_stylelist vx_p_styles = val.styles();
      Vx.Web.Html.Type_stylemap vx_p_stylemap = val.stylemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":name");
      validkeys.Add(":styles");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":styles":
            if (valsub == vx_p_styles) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstyles) {
              ischanged = true;
              vx_p_styles = valstyles;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("styles"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylemap":
            if (valsub == vx_p_stylemap) {
            } else if (valsub is Vx.Web.Html.Type_stylemap valstylemap) {
              ischanged = true;
              vx_p_stylemap = valstylemap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_stylesheet work = new Class_stylesheet();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_name = vx_p_name;
        work.vx_p_styles = vx_p_styles;
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
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
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
   * type: table
   * <table> Tag
   * (type table)
   */
  public interface Type_table : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_divchild {
    public Vx.Web.Html.Type_tbody tbody();
    public Vx.Web.Html.Type_thead thead();
  }

  public class Class_table : Vx.Core.Class_base, Type_table {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_tbody? vx_p_tbody = null;

    public Vx.Web.Html.Type_tbody tbody() {
      Vx.Web.Html.Type_tbody output = Vx.Web.Html.e_tbody;
      if (this.vx_p_tbody != null) {
        output = this.vx_p_tbody;
      }
      return output;
    }

    public Vx.Web.Html.Type_thead? vx_p_thead = null;

    public Vx.Web.Html.Type_thead thead() {
      Vx.Web.Html.Type_thead output = Vx.Web.Html.e_thead;
      if (this.vx_p_thead != null) {
        output = this.vx_p_thead;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":tbody":
        output = this.tbody();
        break;
      case ":thead":
        output = this.thead();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":tbody", this.tbody());
      output.put(":thead", this.thead());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_table vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_table,
       vals);
    }

    public override Vx.Web.Html.Type_table vx_copy(params Object[] vals) {
      Type_table output = this;
      bool ischanged = false;
      Class_table val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_tbody vx_p_tbody = val.tbody();
      Vx.Web.Html.Type_thead vx_p_thead = val.thead();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":tbody");
      validkeys.Add(":thead");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":tbody":
            if (valsub == vx_p_tbody) {
            } else if (valsub is Vx.Web.Html.Type_tbody valtbody) {
              ischanged = true;
              vx_p_tbody = valtbody;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("tbody"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":thead":
            if (valsub == vx_p_thead) {
            } else if (valsub is Vx.Web.Html.Type_thead valthead) {
              ischanged = true;
              vx_p_thead = valthead;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("thead"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_table work = new Class_table();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_tbody = vx_p_tbody;
        work.vx_p_thead = vx_p_thead;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_table;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_table;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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

  public static Type_table e_table = new Class_table();
  public static Type_table t_table = new Class_table();

  /**
   * type: tbody
   * <tbody> Tag
   * (type tbody)
   */
  public interface Type_tbody : Vx.Core.Type_struct, Vx.Web.Html.Type_node {
    public Vx.Web.Html.Type_trlist nodes();
  }

  public class Class_tbody : Vx.Core.Class_base, Type_tbody {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_trlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_trlist nodes() {
      Vx.Web.Html.Type_trlist output = Vx.Web.Html.e_trlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_tbody vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_tbody,
       vals);
    }

    public override Vx.Web.Html.Type_tbody vx_copy(params Object[] vals) {
      Type_tbody output = this;
      bool ischanged = false;
      Class_tbody val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_trlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_trlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_trlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_tr) { // default property
            Vx.Web.Html.Type_tr valdefault = (Vx.Web.Html.Type_tr)valsub;
            Vx.Web.Html.Type_trlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_trlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_trlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_tbody work = new Class_tbody();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_tbody;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_tbody;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // traits
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

  public static Type_tbody e_tbody = new Class_tbody();
  public static Type_tbody t_tbody = new Class_tbody();

  /**
   * type: td
   * <tr> Tag
   * (type td)
   */
  public interface Type_td : Vx.Core.Type_struct, Vx.Web.Html.Type_node {
    public Vx.Web.Html.Type_divchildlist nodes();
  }

  public class Class_td : Vx.Core.Class_base, Type_td {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_divchildlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_divchildlist nodes() {
      Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_td vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_td,
       vals);
    }

    public override Vx.Web.Html.Type_td vx_copy(params Object[] vals) {
      Type_td output = this;
      bool ischanged = false;
      Class_td val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_divchildlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_divchildlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_divchild) { // default property
            Vx.Web.Html.Type_divchild valdefault = (Vx.Web.Html.Type_divchild)valsub;
            Vx.Web.Html.Type_divchildlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_divchildlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_divchildlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_td work = new Class_td();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_td;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_td;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // traits
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

  public static Type_td e_td = new Class_td();
  public static Type_td t_td = new Class_td();

  /**
   * type: tdlist
   * List of td
   * (type tdlist)
   */
  public interface Type_tdlist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_td> vx_listtd();
    public Vx.Web.Html.Type_td vx_td(Vx.Core.Type_int index);
  }

  public class Class_tdlist : Vx.Core.Class_base, Type_tdlist {

    public List<Vx.Web.Html.Type_td> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_td>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_td vx_td(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_td output = Vx.Web.Html.e_td;
      Vx.Web.Html.Class_tdlist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_td> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_td> vx_listtd() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_td(index);
    }

    public override Vx.Web.Html.Type_tdlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_tdlist,
       vals);
    }

    public override Vx.Web.Html.Type_tdlist vx_copy(params Object[] vals) {
      Type_tdlist output = this;
      bool ischanged = false;
      Class_tdlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_td> listval = new List<Vx.Web.Html.Type_td>(val.vx_listtd());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_td allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_td) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_td)valsub);
        } else if (valsub is Vx.Web.Html.Type_tdlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtd());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_td valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_tdlist work = new Class_tdlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_tdlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_tdlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_td), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_tdlist e_tdlist = new Class_tdlist();
  public static Type_tdlist t_tdlist = new Class_tdlist();

  /**
   * type: thead
   * <thead> Tag
   * (type thead)
   */
  public interface Type_thead : Vx.Core.Type_struct, Vx.Web.Html.Type_node {
    public Vx.Web.Html.Type_trlist nodes();
  }

  public class Class_thead : Vx.Core.Class_base, Type_thead {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_trlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_trlist nodes() {
      Vx.Web.Html.Type_trlist output = Vx.Web.Html.e_trlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_thead vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_thead,
       vals);
    }

    public override Vx.Web.Html.Type_thead vx_copy(params Object[] vals) {
      Type_thead output = this;
      bool ischanged = false;
      Class_thead val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_trlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_trlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_trlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_tr) { // default property
            Vx.Web.Html.Type_tr valdefault = (Vx.Web.Html.Type_tr)valsub;
            Vx.Web.Html.Type_trlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_trlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_trlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_thead work = new Class_thead();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_thead;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_thead;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // traits
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

  public static Type_thead e_thead = new Class_thead();
  public static Type_thead t_thead = new Class_thead();

  /**
   * type: title
   * Title Tag
   * (type title)
   */
  public interface Type_title : Vx.Core.Type_struct, Vx.Web.Html.Type_node, Vx.Web.Html.Type_headchild {
    public Vx.Core.Type_string text();
  }

  public class Class_title : Vx.Core.Class_base, Type_title {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":text", this.text());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_title vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_title,
       vals);
    }

    public override Vx.Web.Html.Type_title vx_copy(params Object[] vals) {
      Type_title output = this;
      bool ischanged = false;
      Class_title val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Core.Type_string vx_p_text = val.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":text");
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
            msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_title work = new Class_title();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_title;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_title;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
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

  public static Type_title e_title = new Class_title();
  public static Type_title t_title = new Class_title();

  /**
   * type: tr
   * <tr> Tag
   * (type tr)
   */
  public interface Type_tr : Vx.Core.Type_struct, Vx.Web.Html.Type_node {
    public Vx.Web.Html.Type_tdlist nodes();
  }

  public class Class_tr : Vx.Core.Class_base, Type_tr {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Event.Type_eventmap? vx_p_eventmap = null;

    public Vx.Event.Type_eventmap eventmap() {
      Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
      if (this.vx_p_eventmap != null) {
        output = this.vx_p_eventmap;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style = null;

    public Vx.Web.Html.Type_style style() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style != null) {
        output = this.vx_p_style;
      }
      return output;
    }

    public Vx.Web.Html.Type_style? vx_p_style_unique = null;

    public Vx.Web.Html.Type_style style_unique() {
      Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
      if (this.vx_p_style_unique != null) {
        output = this.vx_p_style_unique;
      }
      return output;
    }

    public Vx.Web.Html.Type_stylelist? vx_p_stylelist = null;

    public Vx.Web.Html.Type_stylelist stylelist() {
      Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
      if (this.vx_p_stylelist != null) {
        output = this.vx_p_stylelist;
      }
      return output;
    }

    public Vx.Web.Html.Type_tdlist? vx_p_nodes = null;

    public Vx.Web.Html.Type_tdlist nodes() {
      Vx.Web.Html.Type_tdlist output = Vx.Web.Html.e_tdlist;
      if (this.vx_p_nodes != null) {
        output = this.vx_p_nodes;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":eventmap":
        output = this.eventmap();
        break;
      case ":style":
        output = this.style();
        break;
      case ":style-unique":
        output = this.style_unique();
        break;
      case ":stylelist":
        output = this.stylelist();
        break;
      case ":nodes":
        output = this.nodes();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":eventmap", this.eventmap());
      output.put(":style", this.style());
      output.put(":style-unique", this.style_unique());
      output.put(":stylelist", this.stylelist());
      output.put(":nodes", this.nodes());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Web.Html.Type_tr vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_tr,
       vals);
    }

    public override Vx.Web.Html.Type_tr vx_copy(params Object[] vals) {
      Type_tr output = this;
      bool ischanged = false;
      Class_tr val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Event.Type_eventmap vx_p_eventmap = val.eventmap();
      Vx.Web.Html.Type_style vx_p_style = val.style();
      Vx.Web.Html.Type_style vx_p_style_unique = val.style_unique();
      Vx.Web.Html.Type_stylelist vx_p_stylelist = val.stylelist();
      Vx.Web.Html.Type_tdlist vx_p_nodes = val.nodes();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":eventmap");
      validkeys.Add(":style");
      validkeys.Add(":style-unique");
      validkeys.Add(":stylelist");
      validkeys.Add(":nodes");
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
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else if (valsub is Vx.Web.Html.Type_tdlist) { // default property
            ischanged = true;
            vx_p_nodes = (Vx.Web.Html.Type_tdlist)valsub;
          } else if (valsub is Vx.Web.Html.Type_td) { // default property
            Vx.Web.Html.Type_td valdefault = (Vx.Web.Html.Type_td)valsub;
            Vx.Web.Html.Type_tdlist vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Vx.Core.vx_new(Vx.Web.Html.t_tdlist, valdefault);
            } else {
              vallist = Vx.Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":eventmap":
            if (valsub == vx_p_eventmap) {
            } else if (valsub is Vx.Event.Type_eventmap valeventmap) {
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style":
            if (valsub == vx_p_style) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle) {
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":style-unique":
            if (valsub == vx_p_style_unique) {
            } else if (valsub is Vx.Web.Html.Type_style valstyle_unique) {
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":stylelist":
            if (valsub == vx_p_stylelist) {
            } else if (valsub is Vx.Web.Html.Type_stylelist valstylelist) {
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":nodes":
            if (valsub == vx_p_nodes) {
            } else if (valsub is Vx.Web.Html.Type_tdlist valnodes) {
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_tr work = new Class_tr();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_tr;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_tr;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // traits
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

  public static Type_tr e_tr = new Class_tr();
  public static Type_tr t_tr = new Class_tr();

  /**
   * type: trlist
   * List of tr
   * (type trlist)
   */
  public interface Type_trlist : Vx.Core.Type_list {
    public List<Vx.Web.Html.Type_tr> vx_listtr();
    public Vx.Web.Html.Type_tr vx_tr(Vx.Core.Type_int index);
  }

  public class Class_trlist : Vx.Core.Class_base, Type_trlist {

    public List<Vx.Web.Html.Type_tr> vx_p_list = Vx.Core.immutablelist(new List<Vx.Web.Html.Type_tr>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Web.Html.Type_tr vx_tr(Vx.Core.Type_int index) {
      Vx.Web.Html.Type_tr output = Vx.Web.Html.e_tr;
      Vx.Web.Html.Class_trlist list = this;
      int iindex = index.vx_int();
      List<Vx.Web.Html.Type_tr> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Web.Html.Type_tr> vx_listtr() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_tr(index);
    }

    public override Vx.Web.Html.Type_trlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_trlist,
       vals);
    }

    public override Vx.Web.Html.Type_trlist vx_copy(params Object[] vals) {
      Type_trlist output = this;
      bool ischanged = false;
      Class_trlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Web.Html.Type_tr> listval = new List<Vx.Web.Html.Type_tr>(val.vx_listtr());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Web.Html.Type_tr allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Web.Html.Type_tr) {
          ischanged = true;
          listval.Add((Vx.Web.Html.Type_tr)valsub);
        } else if (valsub is Vx.Web.Html.Type_trlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtr());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Web.Html.Type_tr valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_trlist work = new Class_trlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_trlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_trlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_tr), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_trlist e_trlist = new Class_trlist();
  public static Type_trlist t_trlist = new Class_trlist();
  /**
   * @function htmlstring_from_string
   * Convert text to HTML string
   * @param  {string} text
   * @return {string}
   * (func htmlstring<-string)
   */
  public interface Func_htmlstring_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_htmlstring_from_string(Vx.Core.Type_string text);
  }

  public class Class_htmlstring_from_string : Vx.Core.Class_base, Func_htmlstring_from_string {

    public override Vx.Web.Html.Func_htmlstring_from_string vx_new(params Object[] vals) {
      Class_htmlstring_from_string output = new Class_htmlstring_from_string();
      return output;
    }

    public override Vx.Web.Html.Func_htmlstring_from_string vx_copy(params Object[] vals) {
      Class_htmlstring_from_string output = new Class_htmlstring_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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
      return e_htmlstring_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_htmlstring_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_htmlstring_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_htmlstring_from_string(text);
      return output;
    }

    public Vx.Core.Type_string vx_htmlstring_from_string(Vx.Core.Type_string text) {
      return Vx.Web.Html.f_htmlstring_from_string(text);
    }

  }

  public static Func_htmlstring_from_string e_htmlstring_from_string = new Vx.Web.Html.Class_htmlstring_from_string();
  public static Func_htmlstring_from_string t_htmlstring_from_string = new Vx.Web.Html.Class_htmlstring_from_string();

  public static Vx.Core.Type_string f_htmlstring_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function string_indent
   * @param  {int} indent
   * @return {string}
   * (func string-indent)
   */
  public interface Func_string_indent : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_indent(Vx.Core.Type_int indent);
  }

  public class Class_string_indent : Vx.Core.Class_base, Func_string_indent {

    public override Vx.Web.Html.Func_string_indent vx_new(params Object[] vals) {
      Class_string_indent output = new Class_string_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_indent vx_copy(params Object[] vals) {
      Class_string_indent output = new Class_string_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
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
      return e_string_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_indent;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_indent(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_indent(indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_indent(Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_indent(indent);
    }

  }

  public static Func_string_indent e_string_indent = new Vx.Web.Html.Class_string_indent();
  public static Func_string_indent t_string_indent = new Vx.Web.Html.Class_string_indent();

  public static Vx.Core.Type_string f_string_indent(Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_string_repeat(Vx.Core.vx_new_string("  "), indent);
    return output;
  }

  /**
   * @function string_from_body_indent
   * Returns string from body
   * @param  {body} body
   * @param  {int} indent
   * @return {string}
   * (func string<-body-indent)
   */
  public interface Func_string_from_body_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_body_indent(Vx.Web.Html.Type_body body, Vx.Core.Type_int indent);
  }

  public class Class_string_from_body_indent : Vx.Core.Class_base, Func_string_from_body_indent {

    public override Vx.Web.Html.Func_string_from_body_indent vx_new(params Object[] vals) {
      Class_string_from_body_indent output = new Class_string_from_body_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_body_indent vx_copy(params Object[] vals) {
      Class_string_from_body_indent output = new Class_string_from_body_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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
      return e_string_from_body_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_body_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_body body = Vx.Core.f_any_from_any(Vx.Web.Html.t_body, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_body_indent(body, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_body_indent(Vx.Web.Html.Type_body body, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_body_indent(body, indent);
    }

  }

  public static Func_string_from_body_indent e_string_from_body_indent = new Vx.Web.Html.Class_string_from_body_indent();
  public static Func_string_from_body_indent t_string_from_body_indent = new Vx.Web.Html.Class_string_from_body_indent();

  public static Vx.Core.Type_string f_string_from_body_indent(Vx.Web.Html.Type_body body, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_divchildlist nodes = body.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("body"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_details_indent
   * Returns string from details
   * @param  {details} details
   * @param  {int} indent
   * @return {string}
   * (func string<-details-indent)
   */
  public interface Func_string_from_details_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_details_indent(Vx.Web.Html.Type_details details, Vx.Core.Type_int indent);
  }

  public class Class_string_from_details_indent : Vx.Core.Class_base, Func_string_from_details_indent {

    public override Vx.Web.Html.Func_string_from_details_indent vx_new(params Object[] vals) {
      Class_string_from_details_indent output = new Class_string_from_details_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_details_indent vx_copy(params Object[] vals) {
      Class_string_from_details_indent output = new Class_string_from_details_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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
      return e_string_from_details_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_details_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_details details = Vx.Core.f_any_from_any(Vx.Web.Html.t_details, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_details_indent(details, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_details_indent(Vx.Web.Html.Type_details details, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_details_indent(details, indent);
    }

  }

  public static Func_string_from_details_indent e_string_from_details_indent = new Vx.Web.Html.Class_string_from_details_indent();
  public static Func_string_from_details_indent t_string_from_details_indent = new Vx.Web.Html.Class_string_from_details_indent();

  public static Vx.Core.Type_string f_string_from_details_indent(Vx.Web.Html.Type_details details, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Web.Html.Type_divchildlist summary = details.summary();
        Vx.Web.Html.Type_divchildlist nodes = details.nodes();
        Vx.Core.Type_string ssummary = Vx.Web.Html.f_string_from_nodelist_indent(
          summary,
          Vx.Core.f_plus(indent, Vx.Core.vx_new_int(2))
        );
        Vx.Core.Type_string snodes = Vx.Web.Html.f_string_from_nodelist_indent(
          nodes,
          Vx.Core.f_plus(indent, Vx.Core.vx_new_int(1))
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<details>"),
            sindent,
            Vx.Core.vx_new_string("  <summary>"),
            ssummary,
            sindent,
            Vx.Core.vx_new_string("  </summary>"),
            snodes,
            sindent,
            Vx.Core.vx_new_string("</details>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_div_indent
   * Returns string from div
   * @param  {div} div
   * @param  {int} indent
   * @return {string}
   * (func string<-div-indent)
   */
  public interface Func_string_from_div_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_div_indent(Vx.Web.Html.Type_div div, Vx.Core.Type_int indent);
  }

  public class Class_string_from_div_indent : Vx.Core.Class_base, Func_string_from_div_indent {

    public override Vx.Web.Html.Func_string_from_div_indent vx_new(params Object[] vals) {
      Class_string_from_div_indent output = new Class_string_from_div_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_div_indent vx_copy(params Object[] vals) {
      Class_string_from_div_indent output = new Class_string_from_div_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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
      return e_string_from_div_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_div_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_div div = Vx.Core.f_any_from_any(Vx.Web.Html.t_div, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_div_indent(div, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_div_indent(Vx.Web.Html.Type_div div, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_div_indent(div, indent);
    }

  }

  public static Func_string_from_div_indent e_string_from_div_indent = new Vx.Web.Html.Class_string_from_div_indent();
  public static Func_string_from_div_indent t_string_from_div_indent = new Vx.Web.Html.Class_string_from_div_indent();

  public static Vx.Core.Type_string f_string_from_div_indent(Vx.Web.Html.Type_div div, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_divchildlist nodes = div.nodes();
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          div.id()
        );
        Vx.Core.Type_string sclass = Vx.Web.Html.f_string_from_propstyle_stylelist(
          div.style(),
          div.stylelist()
        );
        Vx.Core.Type_string sstyle = Vx.Web.Html.f_string_from_propstyleunique(
          div.style_unique()
        );
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Vx.Core.vx_new_string("div"),
          Vx.Core.f_new(
            Vx.Core.t_string,
            Vx.Core.vx_new(Vx.Core.t_anylist,
              sid,
              sclass,
              sstyle
            )
          ),
          indent
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_footer_indent
   * Returns string from footer
   * @param  {footer} footer
   * @param  {int} indent
   * @return {string}
   * (func string<-footer-indent)
   */
  public interface Func_string_from_footer_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_footer_indent(Vx.Web.Html.Type_footer footer, Vx.Core.Type_int indent);
  }

  public class Class_string_from_footer_indent : Vx.Core.Class_base, Func_string_from_footer_indent {

    public override Vx.Web.Html.Func_string_from_footer_indent vx_new(params Object[] vals) {
      Class_string_from_footer_indent output = new Class_string_from_footer_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_footer_indent vx_copy(params Object[] vals) {
      Class_string_from_footer_indent output = new Class_string_from_footer_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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
      return e_string_from_footer_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_footer_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_footer footer = Vx.Core.f_any_from_any(Vx.Web.Html.t_footer, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_footer_indent(footer, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_footer_indent(Vx.Web.Html.Type_footer footer, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_footer_indent(footer, indent);
    }

  }

  public static Func_string_from_footer_indent e_string_from_footer_indent = new Vx.Web.Html.Class_string_from_footer_indent();
  public static Func_string_from_footer_indent t_string_from_footer_indent = new Vx.Web.Html.Class_string_from_footer_indent();

  public static Vx.Core.Type_string f_string_from_footer_indent(Vx.Web.Html.Type_footer footer, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_divchildlist nodes = footer.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("footer"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_h1_indent
   * Returns string from h1
   * @param  {h1} h1
   * @param  {int} indent
   * @return {string}
   * (func string<-h1-indent)
   */
  public interface Func_string_from_h1_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_h1_indent(Vx.Web.Html.Type_h1 h1, Vx.Core.Type_int indent);
  }

  public class Class_string_from_h1_indent : Vx.Core.Class_base, Func_string_from_h1_indent {

    public override Vx.Web.Html.Func_string_from_h1_indent vx_new(params Object[] vals) {
      Class_string_from_h1_indent output = new Class_string_from_h1_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_h1_indent vx_copy(params Object[] vals) {
      Class_string_from_h1_indent output = new Class_string_from_h1_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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
      return e_string_from_h1_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_h1_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_h1 h1 = Vx.Core.f_any_from_any(Vx.Web.Html.t_h1, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_h1_indent(h1, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_h1_indent(Vx.Web.Html.Type_h1 h1, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_h1_indent(h1, indent);
    }

  }

  public static Func_string_from_h1_indent e_string_from_h1_indent = new Vx.Web.Html.Class_string_from_h1_indent();
  public static Func_string_from_h1_indent t_string_from_h1_indent = new Vx.Web.Html.Class_string_from_h1_indent();

  public static Vx.Core.Type_string f_string_from_h1_indent(Vx.Web.Html.Type_h1 h1, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string text = h1.text();
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          h1.id()
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<h1"),
            sid,
            Vx.Core.vx_new_string(">"),
            text,
            Vx.Core.vx_new_string("</h1>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_h2_indent
   * Returns string from h2
   * @param  {h2} h2
   * @param  {int} indent
   * @return {string}
   * (func string<-h2-indent)
   */
  public interface Func_string_from_h2_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_h2_indent(Vx.Web.Html.Type_h2 h2, Vx.Core.Type_int indent);
  }

  public class Class_string_from_h2_indent : Vx.Core.Class_base, Func_string_from_h2_indent {

    public override Vx.Web.Html.Func_string_from_h2_indent vx_new(params Object[] vals) {
      Class_string_from_h2_indent output = new Class_string_from_h2_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_h2_indent vx_copy(params Object[] vals) {
      Class_string_from_h2_indent output = new Class_string_from_h2_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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
      return e_string_from_h2_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_h2_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_h2 h2 = Vx.Core.f_any_from_any(Vx.Web.Html.t_h2, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_h2_indent(h2, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_h2_indent(Vx.Web.Html.Type_h2 h2, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_h2_indent(h2, indent);
    }

  }

  public static Func_string_from_h2_indent e_string_from_h2_indent = new Vx.Web.Html.Class_string_from_h2_indent();
  public static Func_string_from_h2_indent t_string_from_h2_indent = new Vx.Web.Html.Class_string_from_h2_indent();

  public static Vx.Core.Type_string f_string_from_h2_indent(Vx.Web.Html.Type_h2 h2, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = h2.text();
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          h2.id()
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<h2"),
            sid,
            Vx.Core.vx_new_string(">"),
            text,
            Vx.Core.vx_new_string("</h2>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_h3_indent
   * Returns string from h3
   * @param  {h3} h3
   * @param  {int} indent
   * @return {string}
   * (func string<-h3-indent)
   */
  public interface Func_string_from_h3_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_h3_indent(Vx.Web.Html.Type_h3 h3, Vx.Core.Type_int indent);
  }

  public class Class_string_from_h3_indent : Vx.Core.Class_base, Func_string_from_h3_indent {

    public override Vx.Web.Html.Func_string_from_h3_indent vx_new(params Object[] vals) {
      Class_string_from_h3_indent output = new Class_string_from_h3_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_h3_indent vx_copy(params Object[] vals) {
      Class_string_from_h3_indent output = new Class_string_from_h3_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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
      return e_string_from_h3_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_h3_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_h3 h3 = Vx.Core.f_any_from_any(Vx.Web.Html.t_h3, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_h3_indent(h3, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_h3_indent(Vx.Web.Html.Type_h3 h3, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_h3_indent(h3, indent);
    }

  }

  public static Func_string_from_h3_indent e_string_from_h3_indent = new Vx.Web.Html.Class_string_from_h3_indent();
  public static Func_string_from_h3_indent t_string_from_h3_indent = new Vx.Web.Html.Class_string_from_h3_indent();

  public static Vx.Core.Type_string f_string_from_h3_indent(Vx.Web.Html.Type_h3 h3, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = h3.text();
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          h3.id()
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<h3"),
            sid,
            Vx.Core.vx_new_string(">"),
            text,
            Vx.Core.vx_new_string("</h3>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_head_indent
   * Returns string from head
   * @param  {head} head
   * @param  {int} indent
   * @return {string}
   * (func string<-head-indent)
   */
  public interface Func_string_from_head_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_head_indent(Vx.Web.Html.Type_head head, Vx.Core.Type_int indent);
  }

  public class Class_string_from_head_indent : Vx.Core.Class_base, Func_string_from_head_indent {

    public override Vx.Web.Html.Func_string_from_head_indent vx_new(params Object[] vals) {
      Class_string_from_head_indent output = new Class_string_from_head_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_head_indent vx_copy(params Object[] vals) {
      Class_string_from_head_indent output = new Class_string_from_head_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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
      return e_string_from_head_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_head_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_head head = Vx.Core.f_any_from_any(Vx.Web.Html.t_head, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_head_indent(head, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_head_indent(Vx.Web.Html.Type_head head, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_head_indent(head, indent);
    }

  }

  public static Func_string_from_head_indent e_string_from_head_indent = new Vx.Web.Html.Class_string_from_head_indent();
  public static Func_string_from_head_indent t_string_from_head_indent = new Vx.Web.Html.Class_string_from_head_indent();

  public static Vx.Core.Type_string f_string_from_head_indent(Vx.Web.Html.Type_head head, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_headchildlist nodes = head.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("head"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_html
   * Returns string from html
   * @param  {html} html
   * @return {string}
   * (func string<-html)
   */
  public interface Func_string_from_html : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_html(Vx.Web.Html.Type_html html);
  }

  public class Class_string_from_html : Vx.Core.Class_base, Func_string_from_html {

    public override Vx.Web.Html.Func_string_from_html vx_new(params Object[] vals) {
      Class_string_from_html output = new Class_string_from_html();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_html vx_copy(params Object[] vals) {
      Class_string_from_html output = new Class_string_from_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
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
      return e_string_from_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_html;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_html inputval = (Vx.Web.Html.Type_html)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_html(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_html html = Vx.Core.f_any_from_any(Vx.Web.Html.t_html, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_html(html);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_html(Vx.Web.Html.Type_html html) {
      return Vx.Web.Html.f_string_from_html(html);
    }

  }

  public static Func_string_from_html e_string_from_html = new Vx.Web.Html.Class_string_from_html();
  public static Func_string_from_html t_string_from_html = new Vx.Web.Html.Class_string_from_html();

  public static Vx.Core.Type_string f_string_from_html(Vx.Web.Html.Type_html html) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string lang = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("lang"),
          html.lang()
        );
        Vx.Web.Html.Type_head head = html.head();
        Vx.Web.Html.Type_body body = html.body();
        Vx.Web.Html.Type_footer footer = html.footer();
        Vx.Core.Type_string shead = Vx.Web.Html.f_string_from_head_indent(head, Vx.Core.vx_new_int(1));
        Vx.Core.Type_string sbody = Vx.Web.Html.f_string_from_body_indent(body, Vx.Core.vx_new_int(1));
        Vx.Core.Type_string sfooter = Vx.Web.Html.f_string_from_footer_indent(footer, Vx.Core.vx_new_int(1));
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string("<!DOCTYPE html>"),
            Vx.Core.c_newline,
            Vx.Core.vx_new_string("<html"),
            lang,
            Vx.Core.vx_new_string(">"),
            shead,
            sbody,
            sfooter,
            Vx.Core.c_newline,
            Vx.Core.vx_new_string("</html>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_img_indent
   * Returns string from img
   * @param  {img} img
   * @param  {int} indent
   * @return {string}
   * (func string<-img-indent)
   */
  public interface Func_string_from_img_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_img_indent(Vx.Web.Html.Type_img img, Vx.Core.Type_int indent);
  }

  public class Class_string_from_img_indent : Vx.Core.Class_base, Func_string_from_img_indent {

    public override Vx.Web.Html.Func_string_from_img_indent vx_new(params Object[] vals) {
      Class_string_from_img_indent output = new Class_string_from_img_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_img_indent vx_copy(params Object[] vals) {
      Class_string_from_img_indent output = new Class_string_from_img_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-img-indent", // name
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
      return e_string_from_img_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_img_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_img img = Vx.Core.f_any_from_any(Vx.Web.Html.t_img, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_img_indent(img, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_img_indent(Vx.Web.Html.Type_img img, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_img_indent(img, indent);
    }

  }

  public static Func_string_from_img_indent e_string_from_img_indent = new Vx.Web.Html.Class_string_from_img_indent();
  public static Func_string_from_img_indent t_string_from_img_indent = new Vx.Web.Html.Class_string_from_img_indent();

  public static Vx.Core.Type_string f_string_from_img_indent(Vx.Web.Html.Type_img img, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string ssrc = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("src"),
          img.src()
        );
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          img.id()
        );
        Vx.Core.Type_string sclass = Vx.Web.Html.f_string_from_propstyle_stylelist(
          img.style(),
          img.stylelist()
        );
        Vx.Core.Type_string sstyle = Vx.Web.Html.f_string_from_propstyleunique(
          img.style_unique()
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<img"),
            sid,
            sclass,
            sstyle,
            ssrc,
            Vx.Core.vx_new_string(" />")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_indent
   * Returns a string to do indentation for a given indent count.
   * @param  {int} indent
   * @return {string}
   * (func string<-indent)
   */
  public interface Func_string_from_indent : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_indent(Vx.Core.Type_int indent);
  }

  public class Class_string_from_indent : Vx.Core.Class_base, Func_string_from_indent {

    public override Vx.Web.Html.Func_string_from_indent vx_new(params Object[] vals) {
      Class_string_from_indent output = new Class_string_from_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_indent vx_copy(params Object[] vals) {
      Class_string_from_indent output = new Class_string_from_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
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
      return e_string_from_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_indent;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_indent(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_indent(indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_indent(Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_indent(indent);
    }

  }

  public static Func_string_from_indent e_string_from_indent = new Vx.Web.Html.Class_string_from_indent();
  public static Func_string_from_indent t_string_from_indent = new Vx.Web.Html.Class_string_from_indent();

  public static Vx.Core.Type_string f_string_from_indent(Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_1(
      Vx.Core.t_string,
      Vx.Core.f_eq(indent, Vx.Core.vx_new_int(0)),
      Vx.Core.vx_new_string(""),
      Vx.Core.f_new(
        Vx.Core.t_string,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.c_newline,
          Vx.Web.Html.f_string_indent(indent)
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_meta_indent
   * Returns string from head
   * @param  {meta} meta
   * @param  {int} indent
   * @return {string}
   * (func string<-meta-indent)
   */
  public interface Func_string_from_meta_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_meta_indent(Vx.Web.Html.Type_meta meta, Vx.Core.Type_int indent);
  }

  public class Class_string_from_meta_indent : Vx.Core.Class_base, Func_string_from_meta_indent {

    public override Vx.Web.Html.Func_string_from_meta_indent vx_new(params Object[] vals) {
      Class_string_from_meta_indent output = new Class_string_from_meta_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_meta_indent vx_copy(params Object[] vals) {
      Class_string_from_meta_indent output = new Class_string_from_meta_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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
      return e_string_from_meta_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_meta_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_meta meta = Vx.Core.f_any_from_any(Vx.Web.Html.t_meta, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_meta_indent(meta, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_meta_indent(Vx.Web.Html.Type_meta meta, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_meta_indent(meta, indent);
    }

  }

  public static Func_string_from_meta_indent e_string_from_meta_indent = new Vx.Web.Html.Class_string_from_meta_indent();
  public static Func_string_from_meta_indent t_string_from_meta_indent = new Vx.Web.Html.Class_string_from_meta_indent();

  public static Vx.Core.Type_string f_string_from_meta_indent(Vx.Web.Html.Type_meta meta, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string charset = meta.charset();
        Vx.Core.Type_string name = meta.name();
        Vx.Core.Type_string content = meta.content();
        Vx.Core.Type_string scharset = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_ne(Vx.Core.vx_new_string(""), charset);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Web.Html.f_string_from_propname_val(Vx.Core.vx_new_string("charset"), charset);
                })
              )
          )
        );
        Vx.Core.Type_string sname = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_ne(Vx.Core.vx_new_string(""), name);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Web.Html.f_string_from_propname_val(Vx.Core.vx_new_string("name"), name);
                })
              )
          )
        );
        Vx.Core.Type_string scontext = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_ne(Vx.Core.vx_new_string(""), content);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Web.Html.f_string_from_propname_val(Vx.Core.vx_new_string("content"), content);
                })
              )
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<meta"),
            scharset,
            sname,
            scontext,
            Vx.Core.vx_new_string(" />")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_node_indent
   * Returns a string from any node
   * @param  {any-1} node
   * @param  {int} indent
   * @return {string}
   * (func string<-node-indent)
   */
  public interface Func_string_from_node_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_node_indent(Vx.Core.Type_any node, Vx.Core.Type_int indent);
  }

  public class Class_string_from_node_indent : Vx.Core.Class_base, Func_string_from_node_indent {

    public override Vx.Web.Html.Func_string_from_node_indent vx_new(params Object[] vals) {
      Class_string_from_node_indent output = new Class_string_from_node_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_node_indent vx_copy(params Object[] vals) {
      Class_string_from_node_indent output = new Class_string_from_node_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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
      return e_string_from_node_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_node_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any node = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_node_indent(node, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_node_indent(Vx.Core.Type_any node, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_node_indent(node, indent);
    }

  }

  public static Func_string_from_node_indent e_string_from_node_indent = new Vx.Web.Html.Class_string_from_node_indent();
  public static Func_string_from_node_indent t_string_from_node_indent = new Vx.Web.Html.Class_string_from_node_indent();

  public static Vx.Core.Type_string f_string_from_node_indent(Vx.Core.Type_any node, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_switch(
      Vx.Core.t_string,
      Vx.Core.f_type_from_any(node),
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_case_1(
          Vx.Web.Html.t_body,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_body_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_body, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_details,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_details_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_details, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_div,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_div_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_div, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_h1,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_h1_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_h1, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_h2,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_h2_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_h2, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_h3,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_h3_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_h3, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_head,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_head_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_head, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_footer,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_footer_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_footer, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_img,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_img_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_img, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_meta,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_meta_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_meta, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_p,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_p_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_p, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_stylesheet,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_stylesheet_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_table,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_table_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_table, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_title,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_title_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_title, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_tbody,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_tbody_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_tbody, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_thead,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_thead_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_thead, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_td,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_td_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_td, node),
              indent
            );
          })
        ),
        Vx.Core.f_case_1(
          Vx.Web.Html.t_tr,
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_tr_indent(
              Vx.Core.f_any_from_any(Vx.Web.Html.t_tr, node),
              indent
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_nodelist_indent
   * Returns a string from any node
   * @param  {list-1} nodelist
   * @param  {int} indent
   * @return {string}
   * (func string<-nodelist-indent)
   */
  public interface Func_string_from_nodelist_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_nodelist_indent(Vx.Core.Type_list nodelist, Vx.Core.Type_int indent);
  }

  public class Class_string_from_nodelist_indent : Vx.Core.Class_base, Func_string_from_nodelist_indent {

    public override Vx.Web.Html.Func_string_from_nodelist_indent vx_new(params Object[] vals) {
      Class_string_from_nodelist_indent output = new Class_string_from_nodelist_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_nodelist_indent vx_copy(params Object[] vals) {
      Class_string_from_nodelist_indent output = new Class_string_from_nodelist_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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
      return e_string_from_nodelist_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_nodelist_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list nodelist = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_nodelist_indent(nodelist, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_nodelist_indent(Vx.Core.Type_list nodelist, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_nodelist_indent(nodelist, indent);
    }

  }

  public static Func_string_from_nodelist_indent e_string_from_nodelist_indent = new Vx.Web.Html.Class_string_from_nodelist_indent();
  public static Func_string_from_nodelist_indent t_string_from_nodelist_indent = new Vx.Web.Html.Class_string_from_nodelist_indent();

  public static Vx.Core.Type_string f_string_from_nodelist_indent(Vx.Core.Type_list nodelist, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist textlist = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          nodelist,
          Vx.Core.t_any_from_any.vx_fn_new((node_any) => {
            Vx.Web.Html.Type_node node = Vx.Core.f_any_from_any(Vx.Web.Html.t_node, node_any);
            Vx.Core.Type_any output_1 = 
                Vx.Web.Html.f_string_from_node_indent(node, indent);
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = Vx.Type.f_string_from_stringlist_join(textlist, Vx.Core.vx_new_string(""));
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function string_from_nodelist_tag_prop_indent
   * Returns string from generic nodelist
   * @param  {list-1} nodes
   * @param  {string} tag
   * @param  {string} prop
   * @param  {int} indent
   * @return {string}
   * (func string<-nodelist-tag-prop-indent)
   */
  public interface Func_string_from_nodelist_tag_prop_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_nodelist_tag_prop_indent(Vx.Core.Type_list nodes, Vx.Core.Type_string tag, Vx.Core.Type_string prop, Vx.Core.Type_int indent);
  }

  public class Class_string_from_nodelist_tag_prop_indent : Vx.Core.Class_base, Func_string_from_nodelist_tag_prop_indent {

    public override Vx.Web.Html.Func_string_from_nodelist_tag_prop_indent vx_new(params Object[] vals) {
      Class_string_from_nodelist_tag_prop_indent output = new Class_string_from_nodelist_tag_prop_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_nodelist_tag_prop_indent vx_copy(params Object[] vals) {
      Class_string_from_nodelist_tag_prop_indent output = new Class_string_from_nodelist_tag_prop_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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
      return e_string_from_nodelist_tag_prop_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_nodelist_tag_prop_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_list nodes = Vx.Core.f_any_from_any(Vx.Core.t_list, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string tag = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string prop = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(3)));
      output = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_nodelist_tag_prop_indent(Vx.Core.Type_list nodes, Vx.Core.Type_string tag, Vx.Core.Type_string prop, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
    }

  }

  public static Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent = new Vx.Web.Html.Class_string_from_nodelist_tag_prop_indent();
  public static Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent = new Vx.Web.Html.Class_string_from_nodelist_tag_prop_indent();

  public static Vx.Core.Type_string f_string_from_nodelist_tag_prop_indent(Vx.Core.Type_list nodes, Vx.Core.Type_string tag, Vx.Core.Type_string prop, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = Vx.Web.Html.f_string_from_nodelist_indent(
          nodes,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string eindent = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_is_empty(text);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_string("");
                })
              ),
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_is_empty(sindent);
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.c_newline;
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return sindent;
                })
              )
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<"),
            tag,
            prop,
            Vx.Core.vx_new_string(">"),
            text,
            eindent,
            Vx.Core.vx_new_string("</"),
            tag,
            Vx.Core.vx_new_string(">")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_p_indent
   * Returns string from p
   * @param  {p} p
   * @param  {int} indent
   * @return {string}
   * (func string<-p-indent)
   */
  public interface Func_string_from_p_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_p_indent(Vx.Web.Html.Type_p p, Vx.Core.Type_int indent);
  }

  public class Class_string_from_p_indent : Vx.Core.Class_base, Func_string_from_p_indent {

    public override Vx.Web.Html.Func_string_from_p_indent vx_new(params Object[] vals) {
      Class_string_from_p_indent output = new Class_string_from_p_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_p_indent vx_copy(params Object[] vals) {
      Class_string_from_p_indent output = new Class_string_from_p_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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
      return e_string_from_p_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_p_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_p p = Vx.Core.f_any_from_any(Vx.Web.Html.t_p, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_p_indent(p, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_p_indent(Vx.Web.Html.Type_p p, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_p_indent(p, indent);
    }

  }

  public static Func_string_from_p_indent e_string_from_p_indent = new Vx.Web.Html.Class_string_from_p_indent();
  public static Func_string_from_p_indent t_string_from_p_indent = new Vx.Web.Html.Class_string_from_p_indent();

  public static Vx.Core.Type_string f_string_from_p_indent(Vx.Web.Html.Type_p p, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string text = Vx.Web.Html.f_htmlstring_from_string(
          p.text()
        );
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          p.id()
        );
        Vx.Core.Type_string sclass = Vx.Web.Html.f_string_from_propstyle_stylelist(
          p.style(),
          p.stylelist()
        );
        Vx.Core.Type_string sstyle = Vx.Web.Html.f_string_from_propstyleunique(
          p.style_unique()
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<p"),
            sid,
            sclass,
            sstyle,
            Vx.Core.vx_new_string(">"),
            text,
            Vx.Core.vx_new_string("</p>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_propname_val
   * Returns ' key=\"val\"' if val is not blank.
   * @param  {string} key
   * @param  {string} val
   * @return {string}
   * (func string<-propname-val)
   */
  public interface Func_string_from_propname_val : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_propname_val(Vx.Core.Type_string key, Vx.Core.Type_string val);
  }

  public class Class_string_from_propname_val : Vx.Core.Class_base, Func_string_from_propname_val {

    public override Vx.Web.Html.Func_string_from_propname_val vx_new(params Object[] vals) {
      Class_string_from_propname_val output = new Class_string_from_propname_val();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_propname_val vx_copy(params Object[] vals) {
      Class_string_from_propname_val output = new Class_string_from_propname_val();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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
      return e_string_from_propname_val;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_propname_val;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string val = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_propname_val(key, val);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_propname_val(Vx.Core.Type_string key, Vx.Core.Type_string val) {
      return Vx.Web.Html.f_string_from_propname_val(key, val);
    }

  }

  public static Func_string_from_propname_val e_string_from_propname_val = new Vx.Web.Html.Class_string_from_propname_val();
  public static Func_string_from_propname_val t_string_from_propname_val = new Vx.Web.Html.Class_string_from_propname_val();

  public static Vx.Core.Type_string f_string_from_propname_val(Vx.Core.Type_string key, Vx.Core.Type_string val) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if(
      Vx.Core.t_string,
      Vx.Core.f_notempty(val),
      Vx.Core.f_new(
        Vx.Core.t_string,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(" "),
          key,
          Vx.Core.vx_new_string("="),
          Vx.Core.c_quote,
          val,
          Vx.Core.c_quote
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_propstyle
   * Returns ' class=\"style.name\"' if style is not empty.
   * @param  {style} style
   * @return {string}
   * (func string<-propstyle)
   */
  public interface Func_string_from_propstyle : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_propstyle(Vx.Web.Html.Type_style style);
  }

  public class Class_string_from_propstyle : Vx.Core.Class_base, Func_string_from_propstyle {

    public override Vx.Web.Html.Func_string_from_propstyle vx_new(params Object[] vals) {
      Class_string_from_propstyle output = new Class_string_from_propstyle();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_propstyle vx_copy(params Object[] vals) {
      Class_string_from_propstyle output = new Class_string_from_propstyle();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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
      return e_string_from_propstyle;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_propstyle;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_style inputval = (Vx.Web.Html.Type_style)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_propstyle(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_style style = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_propstyle(style);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_propstyle(Vx.Web.Html.Type_style style) {
      return Vx.Web.Html.f_string_from_propstyle(style);
    }

  }

  public static Func_string_from_propstyle e_string_from_propstyle = new Vx.Web.Html.Class_string_from_propstyle();
  public static Func_string_from_propstyle t_string_from_propstyle = new Vx.Web.Html.Class_string_from_propstyle();

  public static Vx.Core.Type_string f_string_from_propstyle(Vx.Web.Html.Type_style style) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(style);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Core.t_string,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(" class="),
                  Vx.Core.c_quote,
                  Vx.Type.f_string_from_string_start(
                    style.name(),
                    Vx.Core.vx_new_int(2)
                  ),
                  Vx.Core.c_quote
              )
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_propstyle_stylelist
   * Returns ' class=\"style.name\"' if style is not empty.
   * @param  {style} style
   * @param  {stylelist} stylelist
   * @return {string}
   * (func string<-propstyle-stylelist)
   */
  public interface Func_string_from_propstyle_stylelist : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_propstyle_stylelist(Vx.Web.Html.Type_style style, Vx.Web.Html.Type_stylelist stylelist);
  }

  public class Class_string_from_propstyle_stylelist : Vx.Core.Class_base, Func_string_from_propstyle_stylelist {

    public override Vx.Web.Html.Func_string_from_propstyle_stylelist vx_new(params Object[] vals) {
      Class_string_from_propstyle_stylelist output = new Class_string_from_propstyle_stylelist();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_propstyle_stylelist vx_copy(params Object[] vals) {
      Class_string_from_propstyle_stylelist output = new Class_string_from_propstyle_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle-stylelist", // name
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
      return e_string_from_propstyle_stylelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_propstyle_stylelist;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_style style = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Web.Html.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_propstyle_stylelist(style, stylelist);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_propstyle_stylelist(Vx.Web.Html.Type_style style, Vx.Web.Html.Type_stylelist stylelist) {
      return Vx.Web.Html.f_string_from_propstyle_stylelist(style, stylelist);
    }

  }

  public static Func_string_from_propstyle_stylelist e_string_from_propstyle_stylelist = new Vx.Web.Html.Class_string_from_propstyle_stylelist();
  public static Func_string_from_propstyle_stylelist t_string_from_propstyle_stylelist = new Vx.Web.Html.Class_string_from_propstyle_stylelist();

  public static Vx.Core.Type_string f_string_from_propstyle_stylelist(Vx.Web.Html.Type_style style, Vx.Web.Html.Type_stylelist stylelist) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(style);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_propstyle(style);
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(stylelist);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Web.Html.f_string_from_propstylelist(stylelist);
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_propstylelist
   * Returns ' class=\"style1.name style2.name\"' if stylelist is not empty.
   * @param  {stylelist} stylelist
   * @return {string}
   * (func string<-propstylelist)
   */
  public interface Func_string_from_propstylelist : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_propstylelist(Vx.Web.Html.Type_stylelist stylelist);
  }

  public class Class_string_from_propstylelist : Vx.Core.Class_base, Func_string_from_propstylelist {

    public override Vx.Web.Html.Func_string_from_propstylelist vx_new(params Object[] vals) {
      Class_string_from_propstylelist output = new Class_string_from_propstylelist();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_propstylelist vx_copy(params Object[] vals) {
      Class_string_from_propstylelist output = new Class_string_from_propstylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstylelist", // name
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
      return e_string_from_propstylelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_propstylelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylelist inputval = (Vx.Web.Html.Type_stylelist)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_propstylelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_propstylelist(stylelist);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_propstylelist(Vx.Web.Html.Type_stylelist stylelist) {
      return Vx.Web.Html.f_string_from_propstylelist(stylelist);
    }

  }

  public static Func_string_from_propstylelist e_string_from_propstylelist = new Vx.Web.Html.Class_string_from_propstylelist();
  public static Func_string_from_propstylelist t_string_from_propstylelist = new Vx.Web.Html.Class_string_from_propstylelist();

  public static Vx.Core.Type_string f_string_from_propstylelist(Vx.Web.Html.Type_stylelist stylelist) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(stylelist);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Core.t_string,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_string joined = Vx.Web.Html.f_string_from_stylelist(stylelist);
                Vx.Core.Type_any output_1 = Vx.Core.f_if(
                  Vx.Core.t_string,
                  Vx.Core.f_ne(Vx.Core.vx_new_string(""), joined),
                  Vx.Core.f_new(
                    Vx.Core.t_string,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(" class="),
                      Vx.Core.c_quote,
                      joined,
                      Vx.Core.c_quote
                    )
                  )
                );
                return output_1;
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_propstyleunique
   * Returns ' style=\"{style.propmap}\"' if style is not empty.
   * @param  {style} style
   * @return {string}
   * (func string<-propstyleunique)
   */
  public interface Func_string_from_propstyleunique : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_propstyleunique(Vx.Web.Html.Type_style style);
  }

  public class Class_string_from_propstyleunique : Vx.Core.Class_base, Func_string_from_propstyleunique {

    public override Vx.Web.Html.Func_string_from_propstyleunique vx_new(params Object[] vals) {
      Class_string_from_propstyleunique output = new Class_string_from_propstyleunique();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_propstyleunique vx_copy(params Object[] vals) {
      Class_string_from_propstyleunique output = new Class_string_from_propstyleunique();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyleunique", // name
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
      return e_string_from_propstyleunique;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_propstyleunique;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_style inputval = (Vx.Web.Html.Type_style)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_propstyleunique(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_style style = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_propstyleunique(style);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_propstyleunique(Vx.Web.Html.Type_style style) {
      return Vx.Web.Html.f_string_from_propstyleunique(style);
    }

  }

  public static Func_string_from_propstyleunique e_string_from_propstyleunique = new Vx.Web.Html.Class_string_from_propstyleunique();
  public static Func_string_from_propstyleunique t_string_from_propstyleunique = new Vx.Web.Html.Class_string_from_propstyleunique();

  public static Vx.Core.Type_string f_string_from_propstyleunique(Vx.Web.Html.Type_style style) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(style);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Core.t_string,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Web.Html.Type_propmap props = style.props();
                Vx.Core.Type_string text = Vx.Web.Html.f_string_from_stylepropmap_indent(props, Vx.Core.vx_new_int(0));
                Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        return Vx.Core.f_notempty(text);
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        return Vx.Core.f_new(
                          Vx.Core.t_string,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(" style="),
                              Vx.Core.c_quote,
                              text,
                              Vx.Core.c_quote
                          )
                        );
                      })
                    )
                  )
                );
                return output_1;
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_style_indent
   * Returns indent'name {key: val;}' for each style.
   * @param  {style} style
   * @param  {int} indent
   * @return {string}
   * (func string<-style-indent)
   */
  public interface Func_string_from_style_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_style_indent(Vx.Web.Html.Type_style style, Vx.Core.Type_int indent);
  }

  public class Class_string_from_style_indent : Vx.Core.Class_base, Func_string_from_style_indent {

    public override Vx.Web.Html.Func_string_from_style_indent vx_new(params Object[] vals) {
      Class_string_from_style_indent output = new Class_string_from_style_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_style_indent vx_copy(params Object[] vals) {
      Class_string_from_style_indent output = new Class_string_from_style_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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
      return e_string_from_style_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_style_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_style style = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_style_indent(style, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_style_indent(Vx.Web.Html.Type_style style, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_style_indent(style, indent);
    }

  }

  public static Func_string_from_style_indent e_string_from_style_indent = new Vx.Web.Html.Class_string_from_style_indent();
  public static Func_string_from_style_indent t_string_from_style_indent = new Vx.Web.Html.Class_string_from_style_indent();

  public static Vx.Core.Type_string f_string_from_style_indent(Vx.Web.Html.Type_style style, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string name = style.name();
        Vx.Web.Html.Type_propmap propmap = style.props();
        Vx.Web.Html.Type_stylelist sublist = style.stylelist();
        Vx.Core.Type_string stext = Vx.Web.Html.f_string_from_stylepropmap_indent(
          propmap,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_string subtext = Vx.Web.Html.f_string_from_stylelist_indent(
          sublist,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            name,
            Vx.Core.vx_new_string(" {"),
            stext,
            subtext,
            sindent,
            Vx.Core.vx_new_string("}")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_stylelist
   * Returns classnames separated by spaces for each style.
   * @param  {stylelist} stylelist
   * @return {string}
   * (func string<-stylelist)
   */
  public interface Func_string_from_stylelist : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_stylelist(Vx.Web.Html.Type_stylelist stylelist);
  }

  public class Class_string_from_stylelist : Vx.Core.Class_base, Func_string_from_stylelist {

    public override Vx.Web.Html.Func_string_from_stylelist vx_new(params Object[] vals) {
      Class_string_from_stylelist output = new Class_string_from_stylelist();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_stylelist vx_copy(params Object[] vals) {
      Class_string_from_stylelist output = new Class_string_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist", // name
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
      return e_string_from_stylelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_stylelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylelist inputval = (Vx.Web.Html.Type_stylelist)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_stylelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_stylelist(stylelist);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stylelist(Vx.Web.Html.Type_stylelist stylelist) {
      return Vx.Web.Html.f_string_from_stylelist(stylelist);
    }

  }

  public static Func_string_from_stylelist e_string_from_stylelist = new Vx.Web.Html.Class_string_from_stylelist();
  public static Func_string_from_stylelist t_string_from_stylelist = new Vx.Web.Html.Class_string_from_stylelist();

  public static Vx.Core.Type_string f_string_from_stylelist(Vx.Web.Html.Type_stylelist stylelist) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist namelist = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          stylelist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Web.Html.Type_style item = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, item_any);
            Vx.Core.Type_any output_1 = 
                Vx.Type.f_string_from_string_start(
                  item.name(),
                  Vx.Core.vx_new_int(2)
                );
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = Vx.Type.f_string_from_stringlist_join(namelist, Vx.Core.vx_new_string(" "));
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function string_from_stylelist_indent
   * Return a string from a stylelist
   * @param  {stylelist} stylelist
   * @param  {int} indent
   * @return {string}
   * (func string<-stylelist-indent)
   */
  public interface Func_string_from_stylelist_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_stylelist_indent(Vx.Web.Html.Type_stylelist stylelist, Vx.Core.Type_int indent);
  }

  public class Class_string_from_stylelist_indent : Vx.Core.Class_base, Func_string_from_stylelist_indent {

    public override Vx.Web.Html.Func_string_from_stylelist_indent vx_new(params Object[] vals) {
      Class_string_from_stylelist_indent output = new Class_string_from_stylelist_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_stylelist_indent vx_copy(params Object[] vals) {
      Class_string_from_stylelist_indent output = new Class_string_from_stylelist_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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
      return e_string_from_stylelist_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_stylelist_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_stylelist_indent(stylelist, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stylelist_indent(Vx.Web.Html.Type_stylelist stylelist, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_stylelist_indent(stylelist, indent);
    }

  }

  public static Func_string_from_stylelist_indent e_string_from_stylelist_indent = new Vx.Web.Html.Class_string_from_stylelist_indent();
  public static Func_string_from_stylelist_indent t_string_from_stylelist_indent = new Vx.Web.Html.Class_string_from_stylelist_indent();

  public static Vx.Core.Type_string f_string_from_stylelist_indent(Vx.Web.Html.Type_stylelist stylelist, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist sstyles = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          stylelist,
          Vx.Core.t_any_from_any.vx_fn_new((substyle_any) => {
            Vx.Web.Html.Type_style substyle = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, substyle_any);
            Vx.Core.Type_any output_1 = 
                Vx.Web.Html.f_string_from_style_indent(substyle, indent);
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = Vx.Type.f_string_from_stringlist_join(
          sstyles,
          Vx.Core.c_newline
        );
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function string_from_stylepropmap_indent
   * Returns indent'key: val;' for each prop.
   * @param  {propmap} propmap
   * @param  {int} indent
   * @return {string}
   * (func string<-stylepropmap-indent)
   */
  public interface Func_string_from_stylepropmap_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_stylepropmap_indent(Vx.Web.Html.Type_propmap propmap, Vx.Core.Type_int indent);
  }

  public class Class_string_from_stylepropmap_indent : Vx.Core.Class_base, Func_string_from_stylepropmap_indent {

    public override Vx.Web.Html.Func_string_from_stylepropmap_indent vx_new(params Object[] vals) {
      Class_string_from_stylepropmap_indent output = new Class_string_from_stylepropmap_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_stylepropmap_indent vx_copy(params Object[] vals) {
      Class_string_from_stylepropmap_indent output = new Class_string_from_stylepropmap_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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
      return e_string_from_stylepropmap_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_stylepropmap_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_propmap propmap = Vx.Core.f_any_from_any(Vx.Web.Html.t_propmap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_stylepropmap_indent(propmap, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stylepropmap_indent(Vx.Web.Html.Type_propmap propmap, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_stylepropmap_indent(propmap, indent);
    }

  }

  public static Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent = new Vx.Web.Html.Class_string_from_stylepropmap_indent();
  public static Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent = new Vx.Web.Html.Class_string_from_stylepropmap_indent();

  public static Vx.Core.Type_string f_string_from_stylepropmap_indent(Vx.Web.Html.Type_propmap propmap, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_stringlist sprops = Vx.Core.f_list_from_map_1(
          Vx.Core.t_stringlist,
          propmap,
          Vx.Core.t_any_from_key_value.vx_fn_new((key_any, val_any) => {
            Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
            Vx.Core.Type_string val = Vx.Core.f_any_from_any(Vx.Core.t_string, val_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_new(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    sindent,
                    key,
                    Vx.Core.vx_new_string(": "),
                    val,
                    Vx.Core.vx_new_string(";")
                  )
                );
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = Vx.Type.f_string_from_stringlist_join(sprops, Vx.Core.vx_new_string(""));
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function string_from_stylesheet_indent
   * Returns string representation of given stylesheet.
   * @param  {stylesheet} stylesheet
   * @param  {int} indent
   * @return {string}
   * (func string<-stylesheet-indent)
   */
  public interface Func_string_from_stylesheet_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_stylesheet_indent(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_int indent);
  }

  public class Class_string_from_stylesheet_indent : Vx.Core.Class_base, Func_string_from_stylesheet_indent {

    public override Vx.Web.Html.Func_string_from_stylesheet_indent vx_new(params Object[] vals) {
      Class_string_from_stylesheet_indent output = new Class_string_from_stylesheet_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_stylesheet_indent vx_copy(params Object[] vals) {
      Class_string_from_stylesheet_indent output = new Class_string_from_stylesheet_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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
      return e_string_from_stylesheet_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_stylesheet_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_stylesheet_indent(stylesheet, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stylesheet_indent(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_stylesheet_indent(stylesheet, indent);
    }

  }

  public static Func_string_from_stylesheet_indent e_string_from_stylesheet_indent = new Vx.Web.Html.Class_string_from_stylesheet_indent();
  public static Func_string_from_stylesheet_indent t_string_from_stylesheet_indent = new Vx.Web.Html.Class_string_from_stylesheet_indent();

  public static Vx.Core.Type_string f_string_from_stylesheet_indent(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_stylelist styles = stylesheet.styles();
        Vx.Core.Type_string sstyles = Vx.Web.Html.f_string_from_stylelist_indent(
          styles,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string eindent = Vx.Core.f_if(
          Vx.Core.t_string,
          Vx.Core.f_notempty(sstyles),
          sindent
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<style>"),
            sstyles,
            eindent,
            Vx.Core.vx_new_string("</style>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_table_indent
   * Returns string from table
   * @param  {table} table
   * @param  {int} indent
   * @return {string}
   * (func string<-table-indent)
   */
  public interface Func_string_from_table_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_table_indent(Vx.Web.Html.Type_table table, Vx.Core.Type_int indent);
  }

  public class Class_string_from_table_indent : Vx.Core.Class_base, Func_string_from_table_indent {

    public override Vx.Web.Html.Func_string_from_table_indent vx_new(params Object[] vals) {
      Class_string_from_table_indent output = new Class_string_from_table_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_table_indent vx_copy(params Object[] vals) {
      Class_string_from_table_indent output = new Class_string_from_table_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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
      return e_string_from_table_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_table_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_table table = Vx.Core.f_any_from_any(Vx.Web.Html.t_table, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_table_indent(table, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_table_indent(Vx.Web.Html.Type_table table, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_table_indent(table, indent);
    }

  }

  public static Func_string_from_table_indent e_string_from_table_indent = new Vx.Web.Html.Class_string_from_table_indent();
  public static Func_string_from_table_indent t_string_from_table_indent = new Vx.Web.Html.Class_string_from_table_indent();

  public static Vx.Core.Type_string f_string_from_table_indent(Vx.Web.Html.Type_table table, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string sid = Vx.Web.Html.f_string_from_propname_val(
          Vx.Core.vx_new_string("id"),
          table.id()
        );
        Vx.Web.Html.Type_thead thead = table.thead();
        Vx.Web.Html.Type_tbody tbody = table.tbody();
        Vx.Core.Type_string shead = Vx.Web.Html.f_string_from_thead_indent(
          thead,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_string sbody = Vx.Web.Html.f_string_from_tbody_indent(
          tbody,
          Vx.Core.f_plus1(indent)
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<table"),
            sid,
            Vx.Core.vx_new_string(">"),
            shead,
            sbody,
            sindent,
            Vx.Core.vx_new_string("</table>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_tbody_indent
   * Returns string from tbody
   * @param  {tbody} tbody
   * @param  {int} indent
   * @return {string}
   * (func string<-tbody-indent)
   */
  public interface Func_string_from_tbody_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_tbody_indent(Vx.Web.Html.Type_tbody tbody, Vx.Core.Type_int indent);
  }

  public class Class_string_from_tbody_indent : Vx.Core.Class_base, Func_string_from_tbody_indent {

    public override Vx.Web.Html.Func_string_from_tbody_indent vx_new(params Object[] vals) {
      Class_string_from_tbody_indent output = new Class_string_from_tbody_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_tbody_indent vx_copy(params Object[] vals) {
      Class_string_from_tbody_indent output = new Class_string_from_tbody_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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
      return e_string_from_tbody_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_tbody_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_tbody tbody = Vx.Core.f_any_from_any(Vx.Web.Html.t_tbody, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_tbody_indent(tbody, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_tbody_indent(Vx.Web.Html.Type_tbody tbody, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_tbody_indent(tbody, indent);
    }

  }

  public static Func_string_from_tbody_indent e_string_from_tbody_indent = new Vx.Web.Html.Class_string_from_tbody_indent();
  public static Func_string_from_tbody_indent t_string_from_tbody_indent = new Vx.Web.Html.Class_string_from_tbody_indent();

  public static Vx.Core.Type_string f_string_from_tbody_indent(Vx.Web.Html.Type_tbody tbody, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_trlist nodes = tbody.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("tbody"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_td_indent
   * Returns string from td
   * @param  {td} td
   * @param  {int} indent
   * @return {string}
   * (func string<-td-indent)
   */
  public interface Func_string_from_td_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_td_indent(Vx.Web.Html.Type_td td, Vx.Core.Type_int indent);
  }

  public class Class_string_from_td_indent : Vx.Core.Class_base, Func_string_from_td_indent {

    public override Vx.Web.Html.Func_string_from_td_indent vx_new(params Object[] vals) {
      Class_string_from_td_indent output = new Class_string_from_td_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_td_indent vx_copy(params Object[] vals) {
      Class_string_from_td_indent output = new Class_string_from_td_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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
      return e_string_from_td_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_td_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_td td = Vx.Core.f_any_from_any(Vx.Web.Html.t_td, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_td_indent(td, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_td_indent(Vx.Web.Html.Type_td td, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_td_indent(td, indent);
    }

  }

  public static Func_string_from_td_indent e_string_from_td_indent = new Vx.Web.Html.Class_string_from_td_indent();
  public static Func_string_from_td_indent t_string_from_td_indent = new Vx.Web.Html.Class_string_from_td_indent();

  public static Vx.Core.Type_string f_string_from_td_indent(Vx.Web.Html.Type_td td, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_divchildlist nodes = td.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("td"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_thead_indent
   * Returns string from thead
   * @param  {thead} thead
   * @param  {int} indent
   * @return {string}
   * (func string<-thead-indent)
   */
  public interface Func_string_from_thead_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_thead_indent(Vx.Web.Html.Type_thead thead, Vx.Core.Type_int indent);
  }

  public class Class_string_from_thead_indent : Vx.Core.Class_base, Func_string_from_thead_indent {

    public override Vx.Web.Html.Func_string_from_thead_indent vx_new(params Object[] vals) {
      Class_string_from_thead_indent output = new Class_string_from_thead_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_thead_indent vx_copy(params Object[] vals) {
      Class_string_from_thead_indent output = new Class_string_from_thead_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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
      return e_string_from_thead_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_thead_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_thead thead = Vx.Core.f_any_from_any(Vx.Web.Html.t_thead, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_thead_indent(thead, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_thead_indent(Vx.Web.Html.Type_thead thead, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_thead_indent(thead, indent);
    }

  }

  public static Func_string_from_thead_indent e_string_from_thead_indent = new Vx.Web.Html.Class_string_from_thead_indent();
  public static Func_string_from_thead_indent t_string_from_thead_indent = new Vx.Web.Html.Class_string_from_thead_indent();

  public static Vx.Core.Type_string f_string_from_thead_indent(Vx.Web.Html.Type_thead thead, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_trlist nodes = thead.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("thead"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_title_indent
   * Returns string from h2
   * @param  {title} title
   * @param  {int} indent
   * @return {string}
   * (func string<-title-indent)
   */
  public interface Func_string_from_title_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_title_indent(Vx.Web.Html.Type_title title, Vx.Core.Type_int indent);
  }

  public class Class_string_from_title_indent : Vx.Core.Class_base, Func_string_from_title_indent {

    public override Vx.Web.Html.Func_string_from_title_indent vx_new(params Object[] vals) {
      Class_string_from_title_indent output = new Class_string_from_title_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_title_indent vx_copy(params Object[] vals) {
      Class_string_from_title_indent output = new Class_string_from_title_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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
      return e_string_from_title_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_title_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_title title = Vx.Core.f_any_from_any(Vx.Web.Html.t_title, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_title_indent(title, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_title_indent(Vx.Web.Html.Type_title title, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_title_indent(title, indent);
    }

  }

  public static Func_string_from_title_indent e_string_from_title_indent = new Vx.Web.Html.Class_string_from_title_indent();
  public static Func_string_from_title_indent t_string_from_title_indent = new Vx.Web.Html.Class_string_from_title_indent();

  public static Vx.Core.Type_string f_string_from_title_indent(Vx.Web.Html.Type_title title, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string sindent = Vx.Web.Html.f_string_from_indent(indent);
        Vx.Core.Type_string text = title.text();
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            sindent,
            Vx.Core.vx_new_string("<title>"),
            text,
            Vx.Core.vx_new_string("</title>")
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_tr_indent
   * Returns string from tr
   * @param  {tr} tr
   * @param  {int} indent
   * @return {string}
   * (func string<-tr-indent)
   */
  public interface Func_string_from_tr_indent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_from_tr_indent(Vx.Web.Html.Type_tr tr, Vx.Core.Type_int indent);
  }

  public class Class_string_from_tr_indent : Vx.Core.Class_base, Func_string_from_tr_indent {

    public override Vx.Web.Html.Func_string_from_tr_indent vx_new(params Object[] vals) {
      Class_string_from_tr_indent output = new Class_string_from_tr_indent();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_tr_indent vx_copy(params Object[] vals) {
      Class_string_from_tr_indent output = new Class_string_from_tr_indent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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
      return e_string_from_tr_indent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_tr_indent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_tr tr = Vx.Core.f_any_from_any(Vx.Web.Html.t_tr, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_int indent = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_string_from_tr_indent(tr, indent);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_tr_indent(Vx.Web.Html.Type_tr tr, Vx.Core.Type_int indent) {
      return Vx.Web.Html.f_string_from_tr_indent(tr, indent);
    }

  }

  public static Func_string_from_tr_indent e_string_from_tr_indent = new Vx.Web.Html.Class_string_from_tr_indent();
  public static Func_string_from_tr_indent t_string_from_tr_indent = new Vx.Web.Html.Class_string_from_tr_indent();

  public static Vx.Core.Type_string f_string_from_tr_indent(Vx.Web.Html.Type_tr tr, Vx.Core.Type_int indent) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_tdlist nodes = tr.nodes();
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_nodelist_tag_prop_indent(nodes, Vx.Core.vx_new_string("tr"), Vx.Core.vx_new_string(""), indent);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_from_uri
   * Decode a URI string
   * @param  {string} uri
   * @return {string}
   * (func string<-uri)
   */
  public interface Func_string_from_uri : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_uri(Vx.Core.Type_string uri);
  }

  public class Class_string_from_uri : Vx.Core.Class_base, Func_string_from_uri {

    public override Vx.Web.Html.Func_string_from_uri vx_new(params Object[] vals) {
      Class_string_from_uri output = new Class_string_from_uri();
      return output;
    }

    public override Vx.Web.Html.Func_string_from_uri vx_copy(params Object[] vals) {
      Class_string_from_uri output = new Class_string_from_uri();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
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
      return e_string_from_uri;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_from_uri;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_string_from_uri(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string uri = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_string_from_uri(uri);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_uri(Vx.Core.Type_string uri) {
      return Vx.Web.Html.f_string_from_uri(uri);
    }

  }

  public static Func_string_from_uri e_string_from_uri = new Vx.Web.Html.Class_string_from_uri();
  public static Func_string_from_uri t_string_from_uri = new Vx.Web.Html.Class_string_from_uri();

  public static Vx.Core.Type_string f_string_from_uri(Vx.Core.Type_string uri) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function style_from_stylesheet_name
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @param  {string} name
   * @return {style}
   * (func style<-stylesheet-name)
   */
  public interface Func_style_from_stylesheet_name : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_style vx_style_from_stylesheet_name(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_string name);
  }

  public class Class_style_from_stylesheet_name : Vx.Core.Class_base, Func_style_from_stylesheet_name {

    public override Vx.Web.Html.Func_style_from_stylesheet_name vx_new(params Object[] vals) {
      Class_style_from_stylesheet_name output = new Class_style_from_stylesheet_name();
      return output;
    }

    public override Vx.Web.Html.Func_style_from_stylesheet_name vx_copy(params Object[] vals) {
      Class_style_from_stylesheet_name output = new Class_style_from_stylesheet_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
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
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_style_from_stylesheet_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_style_from_stylesheet_name;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Html.f_style_from_stylesheet_name(stylesheet, name);
      return output;
    }

    public Vx.Web.Html.Type_style vx_style_from_stylesheet_name(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_string name) {
      return Vx.Web.Html.f_style_from_stylesheet_name(stylesheet, name);
    }

  }

  public static Func_style_from_stylesheet_name e_style_from_stylesheet_name = new Vx.Web.Html.Class_style_from_stylesheet_name();
  public static Func_style_from_stylesheet_name t_style_from_stylesheet_name = new Vx.Web.Html.Class_style_from_stylesheet_name();

  public static Vx.Web.Html.Type_style f_style_from_stylesheet_name(Vx.Web.Html.Type_stylesheet stylesheet, Vx.Core.Type_string name) {
    Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
    output = Vx.Core.f_any_from_map(
      Vx.Web.Html.t_style,
      Vx.Web.Html.f_stylemap_from_stylesheet(stylesheet),
      name
    );
    return output;
  }

  /**
   * @function stylemap_from_stylelist
   * Returns a stylemap from a given stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   * (func stylemap<-stylelist)
   */
  public interface Func_stylemap_from_stylelist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylelist(Vx.Web.Html.Type_stylelist stylelist);
  }

  public class Class_stylemap_from_stylelist : Vx.Core.Class_base, Func_stylemap_from_stylelist {

    public override Vx.Web.Html.Func_stylemap_from_stylelist vx_new(params Object[] vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Web.Html.Func_stylemap_from_stylelist vx_copy(params Object[] vals) {
      Class_stylemap_from_stylelist output = new Class_stylemap_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
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
      Vx.Web.Html.Type_stylelist inputval = (Vx.Web.Html.Type_stylelist)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_stylemap_from_stylelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylelist stylelist = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_stylemap_from_stylelist(stylelist);
      return output;
    }

    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylelist(Vx.Web.Html.Type_stylelist stylelist) {
      return Vx.Web.Html.f_stylemap_from_stylelist(stylelist);
    }

  }

  public static Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Vx.Web.Html.Class_stylemap_from_stylelist();
  public static Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Vx.Web.Html.Class_stylemap_from_stylelist();

  public static Vx.Web.Html.Type_stylemap f_stylemap_from_stylelist(Vx.Web.Html.Type_stylelist stylelist) {
    Vx.Web.Html.Type_stylemap output = Vx.Web.Html.e_stylemap;
    output = Vx.Core.f_map_from_list(
      Vx.Web.Html.t_stylemap,
      stylelist,
      Vx.Core.t_any_from_any.vx_fn_new((style_any) => {
        Vx.Web.Html.Type_style style = Vx.Core.f_any_from_any(Vx.Web.Html.t_style, style_any);
        Vx.Core.Type_any output_1 = 
          style.name();
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stylemap_from_stylesheet
   * Return stylemap from stylesheet
   * @param  {stylesheet} stylesheet
   * @return {stylemap}
   * (func stylemap<-stylesheet)
   */
  public interface Func_stylemap_from_stylesheet : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet);
  }

  public class Class_stylemap_from_stylesheet : Vx.Core.Class_base, Func_stylemap_from_stylesheet {

    public override Vx.Web.Html.Func_stylemap_from_stylesheet vx_new(params Object[] vals) {
      Class_stylemap_from_stylesheet output = new Class_stylemap_from_stylesheet();
      return output;
    }

    public override Vx.Web.Html.Func_stylemap_from_stylesheet vx_copy(params Object[] vals) {
      Class_stylemap_from_stylesheet output = new Class_stylemap_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
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
      return e_stylemap_from_stylesheet;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylemap_from_stylesheet;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylesheet inputval = (Vx.Web.Html.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_stylemap_from_stylesheet(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_stylemap_from_stylesheet(stylesheet);
      return output;
    }

    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
      return Vx.Web.Html.f_stylemap_from_stylesheet(stylesheet);
    }

  }

  public static Func_stylemap_from_stylesheet e_stylemap_from_stylesheet = new Vx.Web.Html.Class_stylemap_from_stylesheet();
  public static Func_stylemap_from_stylesheet t_stylemap_from_stylesheet = new Vx.Web.Html.Class_stylemap_from_stylesheet();

  public static Vx.Web.Html.Type_stylemap f_stylemap_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
    Vx.Web.Html.Type_stylemap output = Vx.Web.Html.e_stylemap;
    output = stylesheet.stylemap();
    return output;
  }

  /**
   * @function styles_from_stylesheet
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @return {stylelist}
   * (func styles<-stylesheet)
   */
  public interface Func_styles_from_stylesheet : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylelist vx_styles_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet);
  }

  public class Class_styles_from_stylesheet : Vx.Core.Class_base, Func_styles_from_stylesheet {

    public override Vx.Web.Html.Func_styles_from_stylesheet vx_new(params Object[] vals) {
      Class_styles_from_stylesheet output = new Class_styles_from_stylesheet();
      return output;
    }

    public override Vx.Web.Html.Func_styles_from_stylesheet vx_copy(params Object[] vals) {
      Class_styles_from_stylesheet output = new Class_styles_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
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
      return e_styles_from_stylesheet;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_styles_from_stylesheet;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylesheet inputval = (Vx.Web.Html.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_styles_from_stylesheet(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_styles_from_stylesheet(stylesheet);
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_styles_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
      return Vx.Web.Html.f_styles_from_stylesheet(stylesheet);
    }

  }

  public static Func_styles_from_stylesheet e_styles_from_stylesheet = new Vx.Web.Html.Class_styles_from_stylesheet();
  public static Func_styles_from_stylesheet t_styles_from_stylesheet = new Vx.Web.Html.Class_styles_from_stylesheet();

  public static Vx.Web.Html.Type_stylelist f_styles_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = stylesheet.styles();
    return output;
  }

  /**
   * @function stylesheet_loadmap
   * Decode a URI string
   * @param  {stylesheet} stylesheet
   * @return {stylesheet}
   * (func stylesheet-loadmap)
   */
  public interface Func_stylesheet_loadmap : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylesheet vx_stylesheet_loadmap(Vx.Web.Html.Type_stylesheet stylesheet);
  }

  public class Class_stylesheet_loadmap : Vx.Core.Class_base, Func_stylesheet_loadmap {

    public override Vx.Web.Html.Func_stylesheet_loadmap vx_new(params Object[] vals) {
      Class_stylesheet_loadmap output = new Class_stylesheet_loadmap();
      return output;
    }

    public override Vx.Web.Html.Func_stylesheet_loadmap vx_copy(params Object[] vals) {
      Class_stylesheet_loadmap output = new Class_stylesheet_loadmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
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
      return e_stylesheet_loadmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet_loadmap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylesheet inputval = (Vx.Web.Html.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_stylesheet_loadmap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_stylesheet_loadmap(stylesheet);
      return output;
    }

    public Vx.Web.Html.Type_stylesheet vx_stylesheet_loadmap(Vx.Web.Html.Type_stylesheet stylesheet) {
      return Vx.Web.Html.f_stylesheet_loadmap(stylesheet);
    }

  }

  public static Func_stylesheet_loadmap e_stylesheet_loadmap = new Vx.Web.Html.Class_stylesheet_loadmap();
  public static Func_stylesheet_loadmap t_stylesheet_loadmap = new Vx.Web.Html.Class_stylesheet_loadmap();

  public static Vx.Web.Html.Type_stylesheet f_stylesheet_loadmap(Vx.Web.Html.Type_stylesheet stylesheet) {
    Vx.Web.Html.Type_stylesheet output = Vx.Web.Html.e_stylesheet;
    output = Vx.Core.f_copy(
      stylesheet,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":stylemap"),
        Vx.Web.Html.f_stylemap_from_stylelist(
          stylesheet.styles()
        )
      )
    );
    return output;
  }

  /**
   * @function uri_from_string
   * Encode a URI string
   * @param  {string} text
   * @return {string}
   * (func uri<-string)
   */
  public interface Func_uri_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_uri_from_string(Vx.Core.Type_string text);
  }

  public class Class_uri_from_string : Vx.Core.Class_base, Func_uri_from_string {

    public override Vx.Web.Html.Func_uri_from_string vx_new(params Object[] vals) {
      Class_uri_from_string output = new Class_uri_from_string();
      return output;
    }

    public override Vx.Web.Html.Func_uri_from_string vx_copy(params Object[] vals) {
      Class_uri_from_string output = new Class_uri_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
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
      return e_uri_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_uri_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Html.f_uri_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Html.f_uri_from_string(text);
      return output;
    }

    public Vx.Core.Type_string vx_uri_from_string(Vx.Core.Type_string text) {
      return Vx.Web.Html.f_uri_from_string(text);
    }

  }

  public static Func_uri_from_string e_uri_from_string = new Vx.Web.Html.Class_uri_from_string();
  public static Func_uri_from_string t_uri_from_string = new Vx.Web.Html.Class_uri_from_string();

  public static Vx.Core.Type_string f_uri_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("body", Vx.Web.Html.t_body);
    maptype.put("details", Vx.Web.Html.t_details);
    maptype.put("div", Vx.Web.Html.t_div);
    maptype.put("divchild", Vx.Web.Html.t_divchild);
    maptype.put("divchildlist", Vx.Web.Html.t_divchildlist);
    maptype.put("divlist", Vx.Web.Html.t_divlist);
    maptype.put("footer", Vx.Web.Html.t_footer);
    maptype.put("h1", Vx.Web.Html.t_h1);
    maptype.put("h2", Vx.Web.Html.t_h2);
    maptype.put("h3", Vx.Web.Html.t_h3);
    maptype.put("head", Vx.Web.Html.t_head);
    maptype.put("headchild", Vx.Web.Html.t_headchild);
    maptype.put("headchildlist", Vx.Web.Html.t_headchildlist);
    maptype.put("html", Vx.Web.Html.t_html);
    maptype.put("img", Vx.Web.Html.t_img);
    maptype.put("meta", Vx.Web.Html.t_meta);
    maptype.put("node", Vx.Web.Html.t_node);
    maptype.put("nodelist", Vx.Web.Html.t_nodelist);
    maptype.put("p", Vx.Web.Html.t_p);
    maptype.put("propmap", Vx.Web.Html.t_propmap);
    maptype.put("style", Vx.Web.Html.t_style);
    maptype.put("stylelist", Vx.Web.Html.t_stylelist);
    maptype.put("stylemap", Vx.Web.Html.t_stylemap);
    maptype.put("stylesheet", Vx.Web.Html.t_stylesheet);
    maptype.put("table", Vx.Web.Html.t_table);
    maptype.put("tbody", Vx.Web.Html.t_tbody);
    maptype.put("td", Vx.Web.Html.t_td);
    maptype.put("tdlist", Vx.Web.Html.t_tdlist);
    maptype.put("thead", Vx.Web.Html.t_thead);
    maptype.put("title", Vx.Web.Html.t_title);
    maptype.put("tr", Vx.Web.Html.t_tr);
    maptype.put("trlist", Vx.Web.Html.t_trlist);
    mapfunc.put("htmlstring<-string", Vx.Web.Html.t_htmlstring_from_string);
    mapfunc.put("string-indent", Vx.Web.Html.t_string_indent);
    mapfunc.put("string<-body-indent", Vx.Web.Html.t_string_from_body_indent);
    mapfunc.put("string<-details-indent", Vx.Web.Html.t_string_from_details_indent);
    mapfunc.put("string<-div-indent", Vx.Web.Html.t_string_from_div_indent);
    mapfunc.put("string<-footer-indent", Vx.Web.Html.t_string_from_footer_indent);
    mapfunc.put("string<-h1-indent", Vx.Web.Html.t_string_from_h1_indent);
    mapfunc.put("string<-h2-indent", Vx.Web.Html.t_string_from_h2_indent);
    mapfunc.put("string<-h3-indent", Vx.Web.Html.t_string_from_h3_indent);
    mapfunc.put("string<-head-indent", Vx.Web.Html.t_string_from_head_indent);
    mapfunc.put("string<-html", Vx.Web.Html.t_string_from_html);
    mapfunc.put("string<-img-indent", Vx.Web.Html.t_string_from_img_indent);
    mapfunc.put("string<-indent", Vx.Web.Html.t_string_from_indent);
    mapfunc.put("string<-meta-indent", Vx.Web.Html.t_string_from_meta_indent);
    mapfunc.put("string<-node-indent", Vx.Web.Html.t_string_from_node_indent);
    mapfunc.put("string<-nodelist-indent", Vx.Web.Html.t_string_from_nodelist_indent);
    mapfunc.put("string<-nodelist-tag-prop-indent", Vx.Web.Html.t_string_from_nodelist_tag_prop_indent);
    mapfunc.put("string<-p-indent", Vx.Web.Html.t_string_from_p_indent);
    mapfunc.put("string<-propname-val", Vx.Web.Html.t_string_from_propname_val);
    mapfunc.put("string<-propstyle", Vx.Web.Html.t_string_from_propstyle);
    mapfunc.put("string<-propstyle-stylelist", Vx.Web.Html.t_string_from_propstyle_stylelist);
    mapfunc.put("string<-propstylelist", Vx.Web.Html.t_string_from_propstylelist);
    mapfunc.put("string<-propstyleunique", Vx.Web.Html.t_string_from_propstyleunique);
    mapfunc.put("string<-style-indent", Vx.Web.Html.t_string_from_style_indent);
    mapfunc.put("string<-stylelist", Vx.Web.Html.t_string_from_stylelist);
    mapfunc.put("string<-stylelist-indent", Vx.Web.Html.t_string_from_stylelist_indent);
    mapfunc.put("string<-stylepropmap-indent", Vx.Web.Html.t_string_from_stylepropmap_indent);
    mapfunc.put("string<-stylesheet-indent", Vx.Web.Html.t_string_from_stylesheet_indent);
    mapfunc.put("string<-table-indent", Vx.Web.Html.t_string_from_table_indent);
    mapfunc.put("string<-tbody-indent", Vx.Web.Html.t_string_from_tbody_indent);
    mapfunc.put("string<-td-indent", Vx.Web.Html.t_string_from_td_indent);
    mapfunc.put("string<-thead-indent", Vx.Web.Html.t_string_from_thead_indent);
    mapfunc.put("string<-title-indent", Vx.Web.Html.t_string_from_title_indent);
    mapfunc.put("string<-tr-indent", Vx.Web.Html.t_string_from_tr_indent);
    mapfunc.put("string<-uri", Vx.Web.Html.t_string_from_uri);
    mapfunc.put("style<-stylesheet-name", Vx.Web.Html.t_style_from_stylesheet_name);
    mapfunc.put("stylemap<-stylelist", Vx.Web.Html.t_stylemap_from_stylelist);
    mapfunc.put("stylemap<-stylesheet", Vx.Web.Html.t_stylemap_from_stylesheet);
    mapfunc.put("styles<-stylesheet", Vx.Web.Html.t_styles_from_stylesheet);
    mapfunc.put("stylesheet-loadmap", Vx.Web.Html.t_stylesheet_loadmap);
    mapfunc.put("uri<-string", Vx.Web.Html.t_uri_from_string);
    Vx.Core.vx_global_package_set("vx/web/html", maptype, mapconst, mapfunc);
    }
  }

}
