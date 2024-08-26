package com.vxlisp.vx.web;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;

public final class Html {


  /**
   * type: body
   * Body Tag
   * (type body)
   */
  public interface Type_body extends Core.Type_struct {
    public Html.Type_divchildlist nodes();
  }

  public static class Class_body extends Core.Class_base implements Type_body {

    public Html.Type_divchildlist vx_p_nodes = null;

    @Override
    public Html.Type_divchildlist nodes() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_body output = Core.vx_copy(Html.e_body, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_body output = this;
      boolean ischanged = false;
      Html.Class_body value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Html.Type_divchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_divchildlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_divchildlist)valsub;
          } else if (valsub instanceof Html.Type_divchild) {
            Html.Type_divchild valdefault = (Html.Type_divchild)valsub;
            Html.Type_divchildlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_divchildlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/body", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valnodes = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/body", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/body", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_body work = new Html.Class_body();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_body;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_body;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "body", // name
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

  public static final Html.Type_body e_body = new Html.Class_body();
  public static final Html.Type_body t_body = new Html.Class_body();

  /**
   * type: details
   * Details Tag
   * (type details)
   */
  public interface Type_details extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_divchildlist summary();
    public Html.Type_divchildlist nodes();
  }

  public static class Class_details extends Core.Class_base implements Type_details {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_divchildlist vx_p_summary = null;

    @Override
    public Html.Type_divchildlist summary() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_summary;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_divchildlist vx_p_nodes = null;

    @Override
    public Html.Type_divchildlist nodes() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":summary"))) {
        output = this.summary();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":summary", this.summary());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_details output = Core.vx_copy(Html.e_details, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_details output = this;
      boolean ischanged = false;
      Html.Class_details value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_divchildlist vx_p_summary = value.summary();
      Html.Type_divchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":summary");
      validkeys.add(":nodes");
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
            msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":summary"))) {
            if (valsub == vx_p_summary) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valsummary = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_summary = valsummary;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("summary"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valnodes = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/details", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_details work = new Html.Class_details();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_summary = vx_p_summary;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_details;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_details;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_details e_details = new Html.Class_details();
  public static final Html.Type_details t_details = new Html.Class_details();

  /**
   * type: div
   * Div Tag
   * (type div)
   */
  public interface Type_div extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_divchildlist nodes();
  }

  public static class Class_div extends Core.Class_base implements Type_div {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_divchildlist vx_p_nodes = null;

    @Override
    public Html.Type_divchildlist nodes() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_div output = Core.vx_copy(Html.e_div, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_div output = this;
      boolean ischanged = false;
      Html.Class_div value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_divchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_divchildlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_divchildlist)valsub;
          } else if (valsub instanceof Html.Type_divchild) {
            Html.Type_divchild valdefault = (Html.Type_divchild)valsub;
            Html.Type_divchildlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_divchildlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valnodes = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/div", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_div work = new Html.Class_div();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_div;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_div;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_div e_div = new Html.Class_div();
  public static final Html.Type_div t_div = new Html.Class_div();

  /**
   * type: divchild
   * Div Child Trait
   * (type divchild)
   */
  public interface Type_divchild extends Core.Type_struct {
  }

  public static class Class_divchild extends Core.Class_base implements Type_divchild {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_divchild output = Core.vx_copy(Html.e_divchild, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_divchild output = this;
      boolean ischanged = false;
      Html.Class_divchild value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_divchild work = new Html.Class_divchild();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_divchild;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_divchild;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "divchild", // name
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

  public static final Html.Type_divchild e_divchild = new Html.Class_divchild();
  public static final Html.Type_divchild t_divchild = new Html.Class_divchild();

  /**
   * type: divchildlist
   * List of divchild
   * (type divchildlist)
   */
  public interface Type_divchildlist extends Core.Type_list {
    public List<Html.Type_divchild> vx_listdivchild();
    public Html.Type_divchild vx_divchild(final Core.Type_int index);
  }

  public static class Class_divchildlist extends Core.Class_base implements Type_divchildlist {

    public List<Html.Type_divchild> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_divchild>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_divchild vx_divchild(final Core.Type_int index) {
      Html.Type_divchild output = Html.e_divchild;
      Html.Class_divchildlist list = this;
      int iindex = index.vx_int();
      List<Html.Type_divchild> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_divchild> vx_listdivchild() {
      List<Html.Type_divchild> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_divchild output = this.vx_divchild(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_divchildlist output = Core.vx_copy(Html.e_divchildlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_divchildlist output = this;
      boolean ischanged = false;
      Html.Class_divchildlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_divchild> listval = new ArrayList<Html.Type_divchild>(value.vx_listdivchild());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_divchildlist) {
          Html.Type_divchildlist multi = (Html.Type_divchildlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdivchild());
        } else if (valsub instanceof Html.Type_divchild) {
          Html.Type_divchild allowsub = (Html.Type_divchild)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_divchild) {
          ischanged = true;
          listval.add((Html.Type_divchild)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_divchild) {
              Html.Type_divchild valitem = (Html.Type_divchild)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/divchildlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_divchildlist work = new Html.Class_divchildlist();
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
      Core.Type_any output = Html.e_divchildlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_divchildlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_divchild), // allowtypes
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

  public static final Html.Type_divchildlist e_divchildlist = new Html.Class_divchildlist();
  public static final Html.Type_divchildlist t_divchildlist = new Html.Class_divchildlist();

  /**
   * type: divlist
   * List of div
   * (type divlist)
   */
  public interface Type_divlist extends Core.Type_list {
    public List<Html.Type_div> vx_listdiv();
    public Html.Type_div vx_div(final Core.Type_int index);
  }

  public static class Class_divlist extends Core.Class_base implements Type_divlist {

    public List<Html.Type_div> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_div>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_div vx_div(final Core.Type_int index) {
      Html.Type_div output = Html.e_div;
      Html.Class_divlist list = this;
      int iindex = index.vx_int();
      List<Html.Type_div> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_div> vx_listdiv() {
      List<Html.Type_div> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_div output = this.vx_div(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_divlist output = Core.vx_copy(Html.e_divlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_divlist output = this;
      boolean ischanged = false;
      Html.Class_divlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_div> listval = new ArrayList<Html.Type_div>(value.vx_listdiv());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_divlist) {
          Html.Type_divlist multi = (Html.Type_divlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdiv());
        } else if (valsub instanceof Html.Type_div) {
          Html.Type_div allowsub = (Html.Type_div)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_div) {
          ischanged = true;
          listval.add((Html.Type_div)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_div) {
              Html.Type_div valitem = (Html.Type_div)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/divlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_divlist work = new Html.Class_divlist();
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
      Core.Type_any output = Html.e_divlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_divlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_div), // allowtypes
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

  public static final Html.Type_divlist e_divlist = new Html.Class_divlist();
  public static final Html.Type_divlist t_divlist = new Html.Class_divlist();

  /**
   * type: footer
   * Body Tag
   * (type footer)
   */
  public interface Type_footer extends Core.Type_struct {
    public Html.Type_divchildlist nodes();
  }

  public static class Class_footer extends Core.Class_base implements Type_footer {

    public Html.Type_divchildlist vx_p_nodes = null;

    @Override
    public Html.Type_divchildlist nodes() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_footer output = Core.vx_copy(Html.e_footer, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_footer output = this;
      boolean ischanged = false;
      Html.Class_footer value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Html.Type_divchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_divchildlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_divchildlist)valsub;
          } else if (valsub instanceof Html.Type_divchild) {
            Html.Type_divchild valdefault = (Html.Type_divchild)valsub;
            Html.Type_divchildlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_divchildlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/footer", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valnodes = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/footer", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/footer", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_footer work = new Html.Class_footer();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_footer;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_footer;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "footer", // name
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

  public static final Html.Type_footer e_footer = new Html.Class_footer();
  public static final Html.Type_footer t_footer = new Html.Class_footer();

  /**
   * type: h1
   * Header 1 Tag
   * (type h1)
   */
  public interface Type_h1 extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string text();
  }

  public static class Class_h1 extends Core.Class_base implements Type_h1 {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_h1 output = Core.vx_copy(Html.e_h1, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_h1 output = this;
      boolean ischanged = false;
      Html.Class_h1 value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":text");
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
          } else if (valsub instanceof Core.Type_string) {
            ischanged = true;
            vx_p_text = (Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valstr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/h1", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_h1 work = new Html.Class_h1();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_h1;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_h1;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_h1 e_h1 = new Html.Class_h1();
  public static final Html.Type_h1 t_h1 = new Html.Class_h1();

  /**
   * type: h2
   * Header 2 Tag
   * (type h2)
   */
  public interface Type_h2 extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string text();
  }

  public static class Class_h2 extends Core.Class_base implements Type_h2 {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_h2 output = Core.vx_copy(Html.e_h2, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_h2 output = this;
      boolean ischanged = false;
      Html.Class_h2 value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":text");
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
          } else if (valsub instanceof Core.Type_string) {
            ischanged = true;
            vx_p_text = (Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valstr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/h2", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_h2 work = new Html.Class_h2();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_h2;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_h2;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_h2 e_h2 = new Html.Class_h2();
  public static final Html.Type_h2 t_h2 = new Html.Class_h2();

  /**
   * type: h3
   * Header 3 Tag
   * (type h3)
   */
  public interface Type_h3 extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string text();
  }

  public static class Class_h3 extends Core.Class_base implements Type_h3 {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_h3 output = Core.vx_copy(Html.e_h3, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_h3 output = this;
      boolean ischanged = false;
      Html.Class_h3 value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":text");
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
          } else if (valsub instanceof Core.Type_string) {
            ischanged = true;
            vx_p_text = (Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valstr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/h3", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_h3 work = new Html.Class_h3();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_h3;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_h3;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_h3 e_h3 = new Html.Class_h3();
  public static final Html.Type_h3 t_h3 = new Html.Class_h3();

  /**
   * type: head
   * Head Tag
   * (type head)
   */
  public interface Type_head extends Core.Type_struct {
    public Html.Type_headchildlist nodes();
  }

  public static class Class_head extends Core.Class_base implements Type_head {

    public Html.Type_headchildlist vx_p_nodes = null;

    @Override
    public Html.Type_headchildlist nodes() {
      Html.Type_headchildlist output = Html.e_headchildlist;
      Html.Type_headchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_head output = Core.vx_copy(Html.e_head, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_head output = this;
      boolean ischanged = false;
      Html.Class_head value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Html.Type_headchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_headchildlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_headchildlist)valsub;
          } else if (valsub instanceof Html.Type_headchild) {
            Html.Type_headchild valdefault = (Html.Type_headchild)valsub;
            Html.Type_headchildlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_headchildlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/head", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_headchildlist) {
              Html.Type_headchildlist valnodes = (Html.Type_headchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/head", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/head", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_head work = new Html.Class_head();
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_head;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_head;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "head", // name
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

  public static final Html.Type_head e_head = new Html.Class_head();
  public static final Html.Type_head t_head = new Html.Class_head();

  /**
   * type: headchild
   * Head Child Trait
   * (type headchild)
   */
  public interface Type_headchild extends Core.Type_struct {
  }

  public static class Class_headchild extends Core.Class_base implements Type_headchild {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_headchild output = Core.vx_copy(Html.e_headchild, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_headchild output = this;
      boolean ischanged = false;
      Html.Class_headchild value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_headchild work = new Html.Class_headchild();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_headchild;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_headchild;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "headchild", // name
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

  public static final Html.Type_headchild e_headchild = new Html.Class_headchild();
  public static final Html.Type_headchild t_headchild = new Html.Class_headchild();

  /**
   * type: headchildlist
   * List of headchild
   * (type headchildlist)
   */
  public interface Type_headchildlist extends Core.Type_list {
    public List<Html.Type_headchild> vx_listheadchild();
    public Html.Type_headchild vx_headchild(final Core.Type_int index);
  }

  public static class Class_headchildlist extends Core.Class_base implements Type_headchildlist {

    public List<Html.Type_headchild> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_headchild>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_headchild vx_headchild(final Core.Type_int index) {
      Html.Type_headchild output = Html.e_headchild;
      Html.Class_headchildlist list = this;
      int iindex = index.vx_int();
      List<Html.Type_headchild> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_headchild> vx_listheadchild() {
      List<Html.Type_headchild> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_headchild output = this.vx_headchild(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_headchildlist output = Core.vx_copy(Html.e_headchildlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_headchildlist output = this;
      boolean ischanged = false;
      Html.Class_headchildlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_headchild> listval = new ArrayList<Html.Type_headchild>(value.vx_listheadchild());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_headchildlist) {
          Html.Type_headchildlist multi = (Html.Type_headchildlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listheadchild());
        } else if (valsub instanceof Html.Type_headchild) {
          Html.Type_headchild allowsub = (Html.Type_headchild)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_headchild) {
          ischanged = true;
          listval.add((Html.Type_headchild)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_headchild) {
              Html.Type_headchild valitem = (Html.Type_headchild)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/headchildlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_headchildlist work = new Html.Class_headchildlist();
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
      Core.Type_any output = Html.e_headchildlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_headchildlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_headchild), // allowtypes
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

  public static final Html.Type_headchildlist e_headchildlist = new Html.Class_headchildlist();
  public static final Html.Type_headchildlist t_headchildlist = new Html.Class_headchildlist();

  /**
   * type: html
   * Html Tag
   * (type html)
   */
  public interface Type_html extends Core.Type_struct {
    public Core.Type_string lang();
    public Html.Type_head head();
    public Html.Type_body body();
    public Html.Type_footer footer();
  }

  public static class Class_html extends Core.Class_base implements Type_html {

    public Core.Type_string vx_p_lang = null;

    @Override
    public Core.Type_string lang() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_lang;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_head vx_p_head = null;

    @Override
    public Html.Type_head head() {
      Html.Type_head output = Html.e_head;
      Html.Type_head testnull = vx_p_head;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_body vx_p_body = null;

    @Override
    public Html.Type_body body() {
      Html.Type_body output = Html.e_body;
      Html.Type_body testnull = vx_p_body;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_footer vx_p_footer = null;

    @Override
    public Html.Type_footer footer() {
      Html.Type_footer output = Html.e_footer;
      Html.Type_footer testnull = vx_p_footer;
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
      } else if ((skey.equals(":lang"))) {
        output = this.lang();
      } else if ((skey.equals(":head"))) {
        output = this.head();
      } else if ((skey.equals(":body"))) {
        output = this.body();
      } else if ((skey.equals(":footer"))) {
        output = this.footer();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":lang", this.lang());
      map.put(":head", this.head());
      map.put(":body", this.body());
      map.put(":footer", this.footer());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_html output = Core.vx_copy(Html.e_html, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_html output = this;
      boolean ischanged = false;
      Html.Class_html value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_lang = value.lang();
      Html.Type_head vx_p_head = value.head();
      Html.Type_body vx_p_body = value.body();
      Html.Type_footer vx_p_footer = value.footer();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":lang");
      validkeys.add(":head");
      validkeys.add(":body");
      validkeys.add(":footer");
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
            msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":lang"))) {
            if (valsub == vx_p_lang) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string vallang = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_lang = vallang;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_lang = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("lang"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":head"))) {
            if (valsub == vx_p_head) {
            } else if (valsub instanceof Html.Type_head) {
              Html.Type_head valhead = (Html.Type_head)valsub;
              ischanged = true;
              vx_p_head = valhead;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("head"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":body"))) {
            if (valsub == vx_p_body) {
            } else if (valsub instanceof Html.Type_body) {
              Html.Type_body valbody = (Html.Type_body)valsub;
              ischanged = true;
              vx_p_body = valbody;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("body"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":footer"))) {
            if (valsub == vx_p_footer) {
            } else if (valsub instanceof Html.Type_footer) {
              Html.Type_footer valfooter = (Html.Type_footer)valsub;
              ischanged = true;
              vx_p_footer = valfooter;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("footer"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/html", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_html work = new Html.Class_html();
        work.vx_p_lang = vx_p_lang;
        work.vx_p_head = vx_p_head;
        work.vx_p_body = vx_p_body;
        work.vx_p_footer = vx_p_footer;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_html;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_html;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "html", // name
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

  public static final Html.Type_html e_html = new Html.Class_html();
  public static final Html.Type_html t_html = new Html.Class_html();

  /**
   * type: img
   * Image Tag
   * (type img)
   */
  public interface Type_img extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string src();
  }

  public static class Class_img extends Core.Class_base implements Type_img {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_src = null;

    @Override
    public Core.Type_string src() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_src;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":src"))) {
        output = this.src();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":src", this.src());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_img output = Core.vx_copy(Html.e_img, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_img output = this;
      boolean ischanged = false;
      Html.Class_img value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_src = value.src();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":src");
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
          } else if (valsub instanceof Core.Type_string) {
            ischanged = true;
            vx_p_src = (Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_src = valstr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_src = Core.vx_new(Core.t_string, valsub);
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":src"))) {
            if (valsub == vx_p_src) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valsrc = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_src = valsrc;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_src = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("src"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/img", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_img work = new Html.Class_img();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_src = vx_p_src;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_img;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_img;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "img", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_img e_img = new Html.Class_img();
  public static final Html.Type_img t_img = new Html.Class_img();

  /**
   * type: meta
   * Meta Tag
   * (type meta)
   */
  public interface Type_meta extends Core.Type_struct, Html.Type_node, Html.Type_headchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string charset();
    public Core.Type_string name();
    public Core.Type_string content();
  }

  public static class Class_meta extends Core.Class_base implements Type_meta {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_charset = null;

    @Override
    public Core.Type_string charset() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_charset;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

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

    public Core.Type_string vx_p_content = null;

    @Override
    public Core.Type_string content() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_content;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":charset"))) {
        output = this.charset();
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":content"))) {
        output = this.content();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":charset", this.charset());
      map.put(":name", this.name());
      map.put(":content", this.content());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_meta output = Core.vx_copy(Html.e_meta, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_meta output = this;
      boolean ischanged = false;
      Html.Class_meta value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_charset = value.charset();
      Core.Type_string vx_p_name = value.name();
      Core.Type_string vx_p_content = value.content();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":charset");
      validkeys.add(":name");
      validkeys.add(":content");
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
            msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":charset"))) {
            if (valsub == vx_p_charset) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcharset = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_charset = valcharset;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_charset = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("charset"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
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
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":content"))) {
            if (valsub == vx_p_content) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valcontent = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_content = valcontent;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_content = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("content"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/meta", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_meta work = new Html.Class_meta();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_charset = vx_p_charset;
        work.vx_p_name = vx_p_name;
        work.vx_p_content = vx_p_content;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_meta;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_meta;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_headchild), // traits
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

  public static final Html.Type_meta e_meta = new Html.Class_meta();
  public static final Html.Type_meta t_meta = new Html.Class_meta();

  /**
   * type: node
   * Common Html Node Trait
   * (type node)
   */
  public interface Type_node extends Core.Type_struct {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
  }

  public static class Class_node extends Core.Class_base implements Type_node {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_node output = Core.vx_copy(Html.e_node, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_node output = this;
      boolean ischanged = false;
      Html.Class_node value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
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
            msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/node", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_node work = new Html.Class_node();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_node;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_node;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "node", // name
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

  public static final Html.Type_node e_node = new Html.Class_node();
  public static final Html.Type_node t_node = new Html.Class_node();

  /**
   * type: nodelist
   * List of node
   * (type nodelist)
   */
  public interface Type_nodelist extends Core.Type_list {
    public List<Html.Type_node> vx_listnode();
    public Html.Type_node vx_node(final Core.Type_int index);
  }

  public static class Class_nodelist extends Core.Class_base implements Type_nodelist {

    public List<Html.Type_node> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_node>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_node vx_node(final Core.Type_int index) {
      Html.Type_node output = Html.e_node;
      Html.Class_nodelist list = this;
      int iindex = index.vx_int();
      List<Html.Type_node> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_node> vx_listnode() {
      List<Html.Type_node> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_node output = this.vx_node(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_nodelist output = Core.vx_copy(Html.e_nodelist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_nodelist output = this;
      boolean ischanged = false;
      Html.Class_nodelist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_node> listval = new ArrayList<Html.Type_node>(value.vx_listnode());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_nodelist) {
          Html.Type_nodelist multi = (Html.Type_nodelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listnode());
        } else if (valsub instanceof Html.Type_node) {
          Html.Type_node allowsub = (Html.Type_node)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_node) {
          ischanged = true;
          listval.add((Html.Type_node)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_node) {
              Html.Type_node valitem = (Html.Type_node)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/nodelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_nodelist work = new Html.Class_nodelist();
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
      Core.Type_any output = Html.e_nodelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_nodelist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_node), // allowtypes
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

  public static final Html.Type_nodelist e_nodelist = new Html.Class_nodelist();
  public static final Html.Type_nodelist t_nodelist = new Html.Class_nodelist();

  /**
   * type: p
   * Paragraph Tag
   * (type p)
   */
  public interface Type_p extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string text();
  }

  public static class Class_p extends Core.Class_base implements Type_p {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_p output = Core.vx_copy(Html.e_p, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_p output = this;
      boolean ischanged = false;
      Html.Class_p value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":text");
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
          } else if (valsub instanceof Core.Type_string) {
            ischanged = true;
            vx_p_text = (Core.Type_string)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valstr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valstr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/p", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_p work = new Html.Class_p();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_p;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_p;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_p e_p = new Html.Class_p();
  public static final Html.Type_p t_p = new Html.Class_p();

  /**
   * type: propmap
   * Map of props
   * (type propmap)
   */
  public interface Type_propmap extends Core.Type_map {
    public Map<String, Core.Type_string> vx_mapstring();
    public Core.Type_string vx_string(final Core.Type_string key);
  }

  public static class Class_propmap extends Core.Class_base implements Type_propmap {

    public Map<String, Core.Type_string> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_string>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Core.Type_string) {
        Core.Type_string castval = (Core.Type_string)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Core.Type_string> map = new LinkedHashMap<String, Core.Type_string>(this.vx_p_map);
        if (castval == Core.e_string) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Core.Type_string vx_string(final Core.Type_string key) {
      Core.Type_string output = Core.e_string;
      Html.Class_propmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_string);
      return output;
    }

    @Override
    public Map<String, Core.Type_string> vx_mapstring() {
      Map<String, Core.Type_string> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_string(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Html.Class_propmap output = new Html.Class_propmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_string> map = new LinkedHashMap<String, Core.Type_string>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Core.Type_string) {
          Core.Type_string castval = (Core.Type_string)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/web/html/propmap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_propmap output = Core.vx_copy(Html.e_propmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_propmap output = this;
      boolean ischanged = false;
      Html.Class_propmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Core.Type_string> mapval = new LinkedHashMap<String, Core.Type_string>(value.vx_mapstring());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/propmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_string valany = Core.e_string;
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valallowed = (Core.Type_string)valsub;
            valany = valallowed;
          } else if (valsub instanceof String) {
            valany = Core.vx_new(Core.t_string, valsub);
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/web/html/propmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
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
        Html.Class_propmap work = new Html.Class_propmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_propmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_propmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Core.t_string), // allowtypes
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

  public static final Html.Type_propmap e_propmap = new Html.Class_propmap();
  public static final Html.Type_propmap t_propmap = new Html.Class_propmap();

  /**
   * type: style
   * Programmable Cascading Style
   * (type style)
   */
  public interface Type_style extends Core.Type_struct {
    public Core.Type_string name();
    public Html.Type_propmap props();
    public Html.Type_stylelist stylelist();
  }

  public static class Class_style extends Core.Class_base implements Type_style {

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

    public Html.Type_propmap vx_p_props = null;

    @Override
    public Html.Type_propmap props() {
      Html.Type_propmap output = Html.e_propmap;
      Html.Type_propmap testnull = vx_p_props;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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
      } else if ((skey.equals(":props"))) {
        output = this.props();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":props", this.props());
      map.put(":stylelist", this.stylelist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_style output = Core.vx_copy(Html.e_style, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_style output = this;
      boolean ischanged = false;
      Html.Class_style value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Html.Type_propmap vx_p_props = value.props();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":props");
      validkeys.add(":stylelist");
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
            msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":props"))) {
            if (valsub == vx_p_props) {
            } else if (valsub instanceof Html.Type_propmap) {
              Html.Type_propmap valprops = (Html.Type_propmap)valsub;
              ischanged = true;
              vx_p_props = valprops;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("props"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/style", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_style work = new Html.Class_style();
        work.vx_p_name = vx_p_name;
        work.vx_p_props = vx_p_props;
        work.vx_p_stylelist = vx_p_stylelist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_style;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_style;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "style", // name
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

  public static final Html.Type_style e_style = new Html.Class_style();
  public static final Html.Type_style t_style = new Html.Class_style();

  /**
   * type: stylelist
   * List of style
   * (type stylelist)
   */
  public interface Type_stylelist extends Core.Type_list {
    public List<Html.Type_style> vx_liststyle();
    public Html.Type_style vx_style(final Core.Type_int index);
  }

  public static class Class_stylelist extends Core.Class_base implements Type_stylelist {

    public List<Html.Type_style> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_style>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_style vx_style(final Core.Type_int index) {
      Html.Type_style output = Html.e_style;
      Html.Class_stylelist list = this;
      int iindex = index.vx_int();
      List<Html.Type_style> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_style> vx_liststyle() {
      List<Html.Type_style> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_style output = this.vx_style(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_stylelist output = Core.vx_copy(Html.e_stylelist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_stylelist output = this;
      boolean ischanged = false;
      Html.Class_stylelist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_style> listval = new ArrayList<Html.Type_style>(value.vx_liststyle());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_stylelist) {
          Html.Type_stylelist multi = (Html.Type_stylelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststyle());
        } else if (valsub instanceof Html.Type_style) {
          Html.Type_style allowsub = (Html.Type_style)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_style) {
          ischanged = true;
          listval.add((Html.Type_style)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_style) {
              Html.Type_style valitem = (Html.Type_style)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/stylelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_stylelist work = new Html.Class_stylelist();
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
      Core.Type_any output = Html.e_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylelist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_style), // allowtypes
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

  public static final Html.Type_stylelist e_stylelist = new Html.Class_stylelist();
  public static final Html.Type_stylelist t_stylelist = new Html.Class_stylelist();

  /**
   * type: stylemap
   * Map of style
   * (type stylemap)
   */
  public interface Type_stylemap extends Core.Type_map {
    public Map<String, Html.Type_style> vx_mapstyle();
    public Html.Type_style vx_style(final Core.Type_string key);
  }

  public static class Class_stylemap extends Core.Class_base implements Type_stylemap {

    public Map<String, Html.Type_style> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Html.Type_style>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Html.Type_style) {
        Html.Type_style castval = (Html.Type_style)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Html.Type_style> map = new LinkedHashMap<String, Html.Type_style>(this.vx_p_map);
        if (castval == Html.e_style) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Html.Type_style vx_style(final Core.Type_string key) {
      Html.Type_style output = Html.e_style;
      Html.Class_stylemap map = this;
      String skey = key.vx_string();
      Map<String, Html.Type_style> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Html.e_style);
      return output;
    }

    @Override
    public Map<String, Html.Type_style> vx_mapstyle() {
      Map<String, Html.Type_style> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_style(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Html.Class_stylemap output = new Html.Class_stylemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Html.Type_style> map = new LinkedHashMap<String, Html.Type_style>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Html.Type_style) {
          Html.Type_style castval = (Html.Type_style)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/web/html/stylemap", ":invalidvalue", value);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_stylemap output = Core.vx_copy(Html.e_stylemap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_stylemap output = this;
      boolean ischanged = false;
      Html.Class_stylemap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Html.Type_style> mapval = new LinkedHashMap<String, Html.Type_style>(value.vx_mapstyle());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/stylemap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Html.Type_style valany = Html.e_style;
          if (false) {
          } else if (valsub instanceof Html.Type_style) {
            Html.Type_style valallowed = (Html.Type_style)valsub;
            valany = valallowed;
          } else if (valsub instanceof Html.Type_style) {
            valany = (Html.Type_style)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/web/html/stylemap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
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
        Html.Class_stylemap work = new Html.Class_stylemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_stylemap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylemap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_style), // allowtypes
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

  public static final Html.Type_stylemap e_stylemap = new Html.Class_stylemap();
  public static final Html.Type_stylemap t_stylemap = new Html.Class_stylemap();

  /**
   * type: stylesheet
   * Programmable Cascading Style Sheet CSS type
   * (type stylesheet)
   */
  public interface Type_stylesheet extends Core.Type_struct, Html.Type_node, Html.Type_headchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string name();
    public Html.Type_stylelist styles();
    public Html.Type_stylemap stylemap();
  }

  public static class Class_stylesheet extends Core.Class_base implements Type_stylesheet {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

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

    public Html.Type_stylelist vx_p_styles = null;

    @Override
    public Html.Type_stylelist styles() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_styles;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylemap vx_p_stylemap = null;

    @Override
    public Html.Type_stylemap stylemap() {
      Html.Type_stylemap output = Html.e_stylemap;
      Html.Type_stylemap testnull = vx_p_stylemap;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":styles"))) {
        output = this.styles();
      } else if ((skey.equals(":stylemap"))) {
        output = this.stylemap();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":name", this.name());
      map.put(":styles", this.styles());
      map.put(":stylemap", this.stylemap());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_stylesheet output = Core.vx_copy(Html.e_stylesheet, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_stylesheet output = this;
      boolean ischanged = false;
      Html.Class_stylesheet value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_name = value.name();
      Html.Type_stylelist vx_p_styles = value.styles();
      Html.Type_stylemap vx_p_stylemap = value.stylemap();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":name");
      validkeys.add(":styles");
      validkeys.add(":stylemap");
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
            msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
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
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":styles"))) {
            if (valsub == vx_p_styles) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstyles = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_styles = valstyles;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("styles"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylemap"))) {
            if (valsub == vx_p_stylemap) {
            } else if (valsub instanceof Html.Type_stylemap) {
              Html.Type_stylemap valstylemap = (Html.Type_stylemap)valsub;
              ischanged = true;
              vx_p_stylemap = valstylemap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/stylesheet", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_stylesheet work = new Html.Class_stylesheet();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_name = vx_p_name;
        work.vx_p_styles = vx_p_styles;
        work.vx_p_stylemap = vx_p_stylemap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_stylesheet;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylesheet;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_headchild), // traits
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

  public static final Html.Type_stylesheet e_stylesheet = new Html.Class_stylesheet();
  public static final Html.Type_stylesheet t_stylesheet = new Html.Class_stylesheet();

  /**
   * type: table
   * <table> Tag
   * (type table)
   */
  public interface Type_table extends Core.Type_struct, Html.Type_node, Html.Type_divchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_tbody tbody();
    public Html.Type_thead thead();
  }

  public static class Class_table extends Core.Class_base implements Type_table {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_tbody vx_p_tbody = null;

    @Override
    public Html.Type_tbody tbody() {
      Html.Type_tbody output = Html.e_tbody;
      Html.Type_tbody testnull = vx_p_tbody;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_thead vx_p_thead = null;

    @Override
    public Html.Type_thead thead() {
      Html.Type_thead output = Html.e_thead;
      Html.Type_thead testnull = vx_p_thead;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":tbody"))) {
        output = this.tbody();
      } else if ((skey.equals(":thead"))) {
        output = this.thead();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":tbody", this.tbody());
      map.put(":thead", this.thead());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_table output = Core.vx_copy(Html.e_table, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_table output = this;
      boolean ischanged = false;
      Html.Class_table value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_tbody vx_p_tbody = value.tbody();
      Html.Type_thead vx_p_thead = value.thead();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":tbody");
      validkeys.add(":thead");
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
            msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":tbody"))) {
            if (valsub == vx_p_tbody) {
            } else if (valsub instanceof Html.Type_tbody) {
              Html.Type_tbody valtbody = (Html.Type_tbody)valsub;
              ischanged = true;
              vx_p_tbody = valtbody;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("tbody"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":thead"))) {
            if (valsub == vx_p_thead) {
            } else if (valsub instanceof Html.Type_thead) {
              Html.Type_thead valthead = (Html.Type_thead)valsub;
              ischanged = true;
              vx_p_thead = valthead;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("thead"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/table", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_table work = new Html.Class_table();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_tbody = vx_p_tbody;
        work.vx_p_thead = vx_p_thead;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_table;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_table;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_divchild), // traits
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

  public static final Html.Type_table e_table = new Html.Class_table();
  public static final Html.Type_table t_table = new Html.Class_table();

  /**
   * type: tbody
   * <tbody> Tag
   * (type tbody)
   */
  public interface Type_tbody extends Core.Type_struct, Html.Type_node {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_trlist nodes();
  }

  public static class Class_tbody extends Core.Class_base implements Type_tbody {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_trlist vx_p_nodes = null;

    @Override
    public Html.Type_trlist nodes() {
      Html.Type_trlist output = Html.e_trlist;
      Html.Type_trlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_tbody output = Core.vx_copy(Html.e_tbody, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_tbody output = this;
      boolean ischanged = false;
      Html.Class_tbody value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_trlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_trlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_trlist)valsub;
          } else if (valsub instanceof Html.Type_tr) {
            Html.Type_tr valdefault = (Html.Type_tr)valsub;
            Html.Type_trlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_trlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_trlist) {
              Html.Type_trlist valnodes = (Html.Type_trlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/tbody", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_tbody work = new Html.Class_tbody();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_tbody;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_tbody;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node), // traits
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

  public static final Html.Type_tbody e_tbody = new Html.Class_tbody();
  public static final Html.Type_tbody t_tbody = new Html.Class_tbody();

  /**
   * type: td
   * <tr> Tag
   * (type td)
   */
  public interface Type_td extends Core.Type_struct, Html.Type_node {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_divchildlist nodes();
  }

  public static class Class_td extends Core.Class_base implements Type_td {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_divchildlist vx_p_nodes = null;

    @Override
    public Html.Type_divchildlist nodes() {
      Html.Type_divchildlist output = Html.e_divchildlist;
      Html.Type_divchildlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_td output = Core.vx_copy(Html.e_td, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_td output = this;
      boolean ischanged = false;
      Html.Class_td value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_divchildlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_divchildlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_divchildlist)valsub;
          } else if (valsub instanceof Html.Type_divchild) {
            Html.Type_divchild valdefault = (Html.Type_divchild)valsub;
            Html.Type_divchildlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_divchildlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_divchildlist) {
              Html.Type_divchildlist valnodes = (Html.Type_divchildlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/td", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_td work = new Html.Class_td();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_td;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_td;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node), // traits
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

  public static final Html.Type_td e_td = new Html.Class_td();
  public static final Html.Type_td t_td = new Html.Class_td();

  /**
   * type: tdlist
   * List of td
   * (type tdlist)
   */
  public interface Type_tdlist extends Core.Type_list {
    public List<Html.Type_td> vx_listtd();
    public Html.Type_td vx_td(final Core.Type_int index);
  }

  public static class Class_tdlist extends Core.Class_base implements Type_tdlist {

    public List<Html.Type_td> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_td>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_td vx_td(final Core.Type_int index) {
      Html.Type_td output = Html.e_td;
      Html.Class_tdlist list = this;
      int iindex = index.vx_int();
      List<Html.Type_td> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_td> vx_listtd() {
      List<Html.Type_td> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_td output = this.vx_td(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_tdlist output = Core.vx_copy(Html.e_tdlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_tdlist output = this;
      boolean ischanged = false;
      Html.Class_tdlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_td> listval = new ArrayList<Html.Type_td>(value.vx_listtd());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_tdlist) {
          Html.Type_tdlist multi = (Html.Type_tdlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtd());
        } else if (valsub instanceof Html.Type_td) {
          Html.Type_td allowsub = (Html.Type_td)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_td) {
          ischanged = true;
          listval.add((Html.Type_td)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_td) {
              Html.Type_td valitem = (Html.Type_td)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/tdlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_tdlist work = new Html.Class_tdlist();
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
      Core.Type_any output = Html.e_tdlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_tdlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_td), // allowtypes
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

  public static final Html.Type_tdlist e_tdlist = new Html.Class_tdlist();
  public static final Html.Type_tdlist t_tdlist = new Html.Class_tdlist();

  /**
   * type: thead
   * <thead> Tag
   * (type thead)
   */
  public interface Type_thead extends Core.Type_struct, Html.Type_node {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_trlist nodes();
  }

  public static class Class_thead extends Core.Class_base implements Type_thead {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_trlist vx_p_nodes = null;

    @Override
    public Html.Type_trlist nodes() {
      Html.Type_trlist output = Html.e_trlist;
      Html.Type_trlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_thead output = Core.vx_copy(Html.e_thead, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_thead output = this;
      boolean ischanged = false;
      Html.Class_thead value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_trlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_trlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_trlist)valsub;
          } else if (valsub instanceof Html.Type_tr) {
            Html.Type_tr valdefault = (Html.Type_tr)valsub;
            Html.Type_trlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_trlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_trlist) {
              Html.Type_trlist valnodes = (Html.Type_trlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/thead", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_thead work = new Html.Class_thead();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_thead;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_thead;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node), // traits
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

  public static final Html.Type_thead e_thead = new Html.Class_thead();
  public static final Html.Type_thead t_thead = new Html.Class_thead();

  /**
   * type: title
   * Title Tag
   * (type title)
   */
  public interface Type_title extends Core.Type_struct, Html.Type_node, Html.Type_headchild {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Core.Type_string text();
  }

  public static class Class_title extends Core.Class_base implements Type_title {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
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

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_title output = Core.vx_copy(Html.e_title, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_title output = this;
      boolean ischanged = false;
      Html.Class_title value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":text");
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
            msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/title", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_title work = new Html.Class_title();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_title;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_title;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node, Html.t_headchild), // traits
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

  public static final Html.Type_title e_title = new Html.Class_title();
  public static final Html.Type_title t_title = new Html.Class_title();

  /**
   * type: tr
   * <tr> Tag
   * (type tr)
   */
  public interface Type_tr extends Core.Type_struct, Html.Type_node {
    public Core.Type_string id();
    public Event.Type_eventmap eventmap();
    public Html.Type_style style();
    public Html.Type_style style_unique();
    public Html.Type_stylelist stylelist();
    public Html.Type_tdlist nodes();
  }

  public static class Class_tr extends Core.Class_base implements Type_tr {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Event.Type_eventmap vx_p_eventmap = null;

    @Override
    public Event.Type_eventmap eventmap() {
      Event.Type_eventmap output = Event.e_eventmap;
      Event.Type_eventmap testnull = vx_p_eventmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style = null;

    @Override
    public Html.Type_style style() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_style vx_p_style_unique = null;

    @Override
    public Html.Type_style style_unique() {
      Html.Type_style output = Html.e_style;
      Html.Type_style testnull = vx_p_style_unique;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_stylelist vx_p_stylelist = null;

    @Override
    public Html.Type_stylelist stylelist() {
      Html.Type_stylelist output = Html.e_stylelist;
      Html.Type_stylelist testnull = vx_p_stylelist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Html.Type_tdlist vx_p_nodes = null;

    @Override
    public Html.Type_tdlist nodes() {
      Html.Type_tdlist output = Html.e_tdlist;
      Html.Type_tdlist testnull = vx_p_nodes;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":eventmap"))) {
        output = this.eventmap();
      } else if ((skey.equals(":style"))) {
        output = this.style();
      } else if ((skey.equals(":style-unique"))) {
        output = this.style_unique();
      } else if ((skey.equals(":stylelist"))) {
        output = this.stylelist();
      } else if ((skey.equals(":nodes"))) {
        output = this.nodes();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":eventmap", this.eventmap());
      map.put(":style", this.style());
      map.put(":style-unique", this.style_unique());
      map.put(":stylelist", this.stylelist());
      map.put(":nodes", this.nodes());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_tr output = Core.vx_copy(Html.e_tr, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_tr output = this;
      boolean ischanged = false;
      Html.Class_tr value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Event.Type_eventmap vx_p_eventmap = value.eventmap();
      Html.Type_style vx_p_style = value.style();
      Html.Type_style vx_p_style_unique = value.style_unique();
      Html.Type_stylelist vx_p_stylelist = value.stylelist();
      Html.Type_tdlist vx_p_nodes = value.nodes();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":eventmap");
      validkeys.add(":style");
      validkeys.add(":style-unique");
      validkeys.add(":stylelist");
      validkeys.add(":nodes");
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
          } else if (valsub instanceof Html.Type_tdlist) {
            ischanged = true;
            vx_p_nodes = (Html.Type_tdlist)valsub;
          } else if (valsub instanceof Html.Type_td) {
            Html.Type_td valdefault = (Html.Type_td)valsub;
            Html.Type_tdlist vallist;
            vallist = vx_p_nodes;
            if (vallist == null) {
              vallist = Core.vx_new(Html.t_tdlist, valdefault);
            } else {
              vallist = Core.vx_copy(vallist, valdefault);
            }
            ischanged = true;
            vx_p_nodes = vallist;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":eventmap"))) {
            if (valsub == vx_p_eventmap) {
            } else if (valsub instanceof Event.Type_eventmap) {
              Event.Type_eventmap valeventmap = (Event.Type_eventmap)valsub;
              ischanged = true;
              vx_p_eventmap = valeventmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("eventmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style"))) {
            if (valsub == vx_p_style) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style = valstyle;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":style-unique"))) {
            if (valsub == vx_p_style_unique) {
            } else if (valsub instanceof Html.Type_style) {
              Html.Type_style valstyle_unique = (Html.Type_style)valsub;
              ischanged = true;
              vx_p_style_unique = valstyle_unique;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("style-unique"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":stylelist"))) {
            if (valsub == vx_p_stylelist) {
            } else if (valsub instanceof Html.Type_stylelist) {
              Html.Type_stylelist valstylelist = (Html.Type_stylelist)valsub;
              ischanged = true;
              vx_p_stylelist = valstylelist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("stylelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":nodes"))) {
            if (valsub == vx_p_nodes) {
            } else if (valsub instanceof Html.Type_tdlist) {
              Html.Type_tdlist valnodes = (Html.Type_tdlist)valsub;
              ischanged = true;
              vx_p_nodes = valnodes;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("nodes"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/web/html/tr", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_tr work = new Html.Class_tr();
        work.vx_p_id = vx_p_id;
        work.vx_p_eventmap = vx_p_eventmap;
        work.vx_p_style = vx_p_style;
        work.vx_p_style_unique = vx_p_style_unique;
        work.vx_p_stylelist = vx_p_stylelist;
        work.vx_p_nodes = vx_p_nodes;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Html.e_tr;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_tr;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        Core.vx_new(Core.t_typelist, Html.t_node), // traits
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

  public static final Html.Type_tr e_tr = new Html.Class_tr();
  public static final Html.Type_tr t_tr = new Html.Class_tr();

  /**
   * type: trlist
   * List of tr
   * (type trlist)
   */
  public interface Type_trlist extends Core.Type_list {
    public List<Html.Type_tr> vx_listtr();
    public Html.Type_tr vx_tr(final Core.Type_int index);
  }

  public static class Class_trlist extends Core.Class_base implements Type_trlist {

    public List<Html.Type_tr> vx_p_list = Core.immutablelist(
      new ArrayList<Html.Type_tr>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Html.Type_tr vx_tr(final Core.Type_int index) {
      Html.Type_tr output = Html.e_tr;
      Html.Class_trlist list = this;
      int iindex = index.vx_int();
      List<Html.Type_tr> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Html.Type_tr> vx_listtr() {
      List<Html.Type_tr> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Html.Type_tr output = this.vx_tr(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Type_trlist output = Core.vx_copy(Html.e_trlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Type_trlist output = this;
      boolean ischanged = false;
      Html.Class_trlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Html.Type_tr> listval = new ArrayList<Html.Type_tr>(value.vx_listtr());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Html.Type_trlist) {
          Html.Type_trlist multi = (Html.Type_trlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtr());
        } else if (valsub instanceof Html.Type_tr) {
          Html.Type_tr allowsub = (Html.Type_tr)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Html.Type_tr) {
          ischanged = true;
          listval.add((Html.Type_tr)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Html.Type_tr) {
              Html.Type_tr valitem = (Html.Type_tr)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/web/html/trlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Html.Class_trlist work = new Html.Class_trlist();
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
      Core.Type_any output = Html.e_trlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_trlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Html.t_tr), // allowtypes
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

  public static final Html.Type_trlist e_trlist = new Html.Class_trlist();
  public static final Html.Type_trlist t_trlist = new Html.Class_trlist();
  /**
   * @function htmlstring_from_string
   * Convert text to HTML string
   * @param  {string} text
   * @return {string}
   * (func htmlstring<-string)
   */
  public interface Func_htmlstring_from_string extends Core.Func_any_from_any {
    public Core.Type_string vx_htmlstring_from_string(final Core.Type_string text);
  }

  public static class Class_htmlstring_from_string extends Core.Class_base implements Func_htmlstring_from_string {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_htmlstring_from_string output = new Html.Class_htmlstring_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_htmlstring_from_string output = new Html.Class_htmlstring_from_string();
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
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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
      Core.Type_any output = Html.e_htmlstring_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_htmlstring_from_string;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Html.f_htmlstring_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_htmlstring_from_string(text);
      return output;
    }

    @Override
    public Core.Type_string vx_htmlstring_from_string(final Core.Type_string text) {
      Core.Type_string output = Html.f_htmlstring_from_string(text);
      return output;
    }

  }

  public static final Html.Func_htmlstring_from_string e_htmlstring_from_string = new Html.Class_htmlstring_from_string();
  public static final Html.Func_htmlstring_from_string t_htmlstring_from_string = new Html.Class_htmlstring_from_string();

  public static Core.Type_string f_htmlstring_from_string(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    String str = text.vx_string();
    str = str
      .replaceAll("&", "&amp;")
      .replaceAll("'", "\'")
      .replaceAll(">", "&gt;")   
      .replaceAll("<", "&lt;");
    output = Core.vx_new_string(str);
    return output;
  }

  /**
   * @function string_indent
   * @param  {int} indent
   * @return {string}
   * (func string-indent)
   */
  public interface Func_string_indent extends Core.Func_any_from_any {
    public Core.Type_string vx_string_indent(final Core.Type_int indent);
  }

  public static class Class_string_indent extends Core.Class_base implements Func_string_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_indent output = new Html.Class_string_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_indent output = new Html.Class_string_indent();
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
        "vx/web/html", // pkgname
        "string-indent", // name
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
      Core.Type_any output = Html.e_string_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_indent;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Html.f_string_indent(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_indent(indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_indent(final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_indent(indent);
      return output;
    }

  }

  public static final Html.Func_string_indent e_string_indent = new Html.Class_string_indent();
  public static final Html.Func_string_indent t_string_indent = new Html.Class_string_indent();

  public static Core.Type_string f_string_indent(final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_string_repeat(
      Core.vx_new_string("  "),
      indent
    );
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
  public interface Func_string_from_body_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_body_indent(final Html.Type_body body, final Core.Type_int indent);
  }

  public static class Class_string_from_body_indent extends Core.Class_base implements Func_string_from_body_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_body_indent output = new Html.Class_string_from_body_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_body_indent output = new Html.Class_string_from_body_indent();
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
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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
      Core.Type_any output = Html.e_string_from_body_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_body_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_body body = Core.f_any_from_any(Html.t_body, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_body_indent(body, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_body_indent(final Html.Type_body body, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_body_indent(body, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_body_indent e_string_from_body_indent = new Html.Class_string_from_body_indent();
  public static final Html.Func_string_from_body_indent t_string_from_body_indent = new Html.Class_string_from_body_indent();

  public static Core.Type_string f_string_from_body_indent(final Html.Type_body body, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_divchildlist nodes = body.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("body"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_details_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_details_indent(final Html.Type_details details, final Core.Type_int indent);
  }

  public static class Class_string_from_details_indent extends Core.Class_base implements Func_string_from_details_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_details_indent output = new Html.Class_string_from_details_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_details_indent output = new Html.Class_string_from_details_indent();
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
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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
      Core.Type_any output = Html.e_string_from_details_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_details_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_details details = Core.f_any_from_any(Html.t_details, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_details_indent(details, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_details_indent(final Html.Type_details details, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_details_indent(details, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_details_indent e_string_from_details_indent = new Html.Class_string_from_details_indent();
  public static final Html.Func_string_from_details_indent t_string_from_details_indent = new Html.Class_string_from_details_indent();

  public static Core.Type_string f_string_from_details_indent(final Html.Type_details details, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Html.Type_divchildlist summary = details.summary();
        Html.Type_divchildlist nodes = details.nodes();
        Core.Type_string ssummary = Html.f_string_from_nodelist_indent(
          summary,
          Core.f_plus(
            indent,
            Core.vx_new_int(2)
          )
        );
        Core.Type_string snodes = Html.f_string_from_nodelist_indent(
          nodes,
          Core.f_plus(
            indent,
            Core.vx_new_int(1)
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<details>"),
            sindent,
            Core.vx_new_string("  <summary>"),
            ssummary,
            sindent,
            Core.vx_new_string("  </summary>"),
            snodes,
            sindent,
            Core.vx_new_string("</details>")
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
  public interface Func_string_from_div_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_div_indent(final Html.Type_div div, final Core.Type_int indent);
  }

  public static class Class_string_from_div_indent extends Core.Class_base implements Func_string_from_div_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_div_indent output = new Html.Class_string_from_div_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_div_indent output = new Html.Class_string_from_div_indent();
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
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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
      Core.Type_any output = Html.e_string_from_div_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_div_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_div div = Core.f_any_from_any(Html.t_div, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_div_indent(div, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_div_indent(final Html.Type_div div, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_div_indent(div, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_div_indent e_string_from_div_indent = new Html.Class_string_from_div_indent();
  public static final Html.Func_string_from_div_indent t_string_from_div_indent = new Html.Class_string_from_div_indent();

  public static Core.Type_string f_string_from_div_indent(final Html.Type_div div, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_divchildlist nodes = div.nodes();
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          div.id()
        );
        Core.Type_string sclass = Html.f_string_from_propstyle_stylelist(
          div.style(),
          div.stylelist()
        );
        Core.Type_string sstyle = Html.f_string_from_propstyleunique(
          div.style_unique()
        );
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("div"),
          Core.f_new(
            Core.t_string,
            Core.vx_new(
              Core.t_anylist,
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
  public interface Func_string_from_footer_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_footer_indent(final Html.Type_footer footer, final Core.Type_int indent);
  }

  public static class Class_string_from_footer_indent extends Core.Class_base implements Func_string_from_footer_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_footer_indent output = new Html.Class_string_from_footer_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_footer_indent output = new Html.Class_string_from_footer_indent();
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
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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
      Core.Type_any output = Html.e_string_from_footer_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_footer_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_footer footer = Core.f_any_from_any(Html.t_footer, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_footer_indent(footer, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_footer_indent(final Html.Type_footer footer, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_footer_indent(footer, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_footer_indent e_string_from_footer_indent = new Html.Class_string_from_footer_indent();
  public static final Html.Func_string_from_footer_indent t_string_from_footer_indent = new Html.Class_string_from_footer_indent();

  public static Core.Type_string f_string_from_footer_indent(final Html.Type_footer footer, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_divchildlist nodes = footer.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("footer"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_h1_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_h1_indent(final Html.Type_h1 h1, final Core.Type_int indent);
  }

  public static class Class_string_from_h1_indent extends Core.Class_base implements Func_string_from_h1_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_h1_indent output = new Html.Class_string_from_h1_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_h1_indent output = new Html.Class_string_from_h1_indent();
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
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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
      Core.Type_any output = Html.e_string_from_h1_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_h1_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_h1 h1 = Core.f_any_from_any(Html.t_h1, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_h1_indent(h1, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_h1_indent(final Html.Type_h1 h1, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_h1_indent(h1, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_h1_indent e_string_from_h1_indent = new Html.Class_string_from_h1_indent();
  public static final Html.Func_string_from_h1_indent t_string_from_h1_indent = new Html.Class_string_from_h1_indent();

  public static Core.Type_string f_string_from_h1_indent(final Html.Type_h1 h1, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string text = h1.text();
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          h1.id()
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<h1"),
            sid,
            Core.vx_new_string(">"),
            text,
            Core.vx_new_string("</h1>")
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
  public interface Func_string_from_h2_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_h2_indent(final Html.Type_h2 h2, final Core.Type_int indent);
  }

  public static class Class_string_from_h2_indent extends Core.Class_base implements Func_string_from_h2_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_h2_indent output = new Html.Class_string_from_h2_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_h2_indent output = new Html.Class_string_from_h2_indent();
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
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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
      Core.Type_any output = Html.e_string_from_h2_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_h2_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_h2 h2 = Core.f_any_from_any(Html.t_h2, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_h2_indent(h2, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_h2_indent(final Html.Type_h2 h2, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_h2_indent(h2, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_h2_indent e_string_from_h2_indent = new Html.Class_string_from_h2_indent();
  public static final Html.Func_string_from_h2_indent t_string_from_h2_indent = new Html.Class_string_from_h2_indent();

  public static Core.Type_string f_string_from_h2_indent(final Html.Type_h2 h2, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = h2.text();
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          h2.id()
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<h2"),
            sid,
            Core.vx_new_string(">"),
            text,
            Core.vx_new_string("</h2>")
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
  public interface Func_string_from_h3_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_h3_indent(final Html.Type_h3 h3, final Core.Type_int indent);
  }

  public static class Class_string_from_h3_indent extends Core.Class_base implements Func_string_from_h3_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_h3_indent output = new Html.Class_string_from_h3_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_h3_indent output = new Html.Class_string_from_h3_indent();
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
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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
      Core.Type_any output = Html.e_string_from_h3_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_h3_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_h3 h3 = Core.f_any_from_any(Html.t_h3, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_h3_indent(h3, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_h3_indent(final Html.Type_h3 h3, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_h3_indent(h3, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_h3_indent e_string_from_h3_indent = new Html.Class_string_from_h3_indent();
  public static final Html.Func_string_from_h3_indent t_string_from_h3_indent = new Html.Class_string_from_h3_indent();

  public static Core.Type_string f_string_from_h3_indent(final Html.Type_h3 h3, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = h3.text();
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          h3.id()
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<h3"),
            sid,
            Core.vx_new_string(">"),
            text,
            Core.vx_new_string("</h3>")
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
  public interface Func_string_from_head_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_head_indent(final Html.Type_head head, final Core.Type_int indent);
  }

  public static class Class_string_from_head_indent extends Core.Class_base implements Func_string_from_head_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_head_indent output = new Html.Class_string_from_head_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_head_indent output = new Html.Class_string_from_head_indent();
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
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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
      Core.Type_any output = Html.e_string_from_head_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_head_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_head head = Core.f_any_from_any(Html.t_head, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_head_indent(head, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_head_indent(final Html.Type_head head, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_head_indent(head, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_head_indent e_string_from_head_indent = new Html.Class_string_from_head_indent();
  public static final Html.Func_string_from_head_indent t_string_from_head_indent = new Html.Class_string_from_head_indent();

  public static Core.Type_string f_string_from_head_indent(final Html.Type_head head, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_headchildlist nodes = head.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("head"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_html extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_html(final Html.Type_html html);
  }

  public static class Class_string_from_html extends Core.Class_base implements Func_string_from_html {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_html output = new Html.Class_string_from_html();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_html output = new Html.Class_string_from_html();
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
        "vx/web/html", // pkgname
        "string<-html", // name
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
      Core.Type_any output = Html.e_string_from_html;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_html;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_html inputval = (Html.Type_html)value;
      Core.Type_any outputval = Html.f_string_from_html(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_html html = Core.f_any_from_any(Html.t_html, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_html(html);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_html(final Html.Type_html html) {
      Core.Type_string output = Html.f_string_from_html(html);
      return output;
    }

  }

  public static final Html.Func_string_from_html e_string_from_html = new Html.Class_string_from_html();
  public static final Html.Func_string_from_html t_string_from_html = new Html.Class_string_from_html();

  public static Core.Type_string f_string_from_html(final Html.Type_html html) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string lang = Html.f_string_from_propname_val(
          Core.vx_new_string("lang"),
          html.lang()
        );
        Html.Type_head head = html.head();
        Html.Type_body body = html.body();
        Html.Type_footer footer = html.footer();
        Core.Type_string shead = Html.f_string_from_head_indent(
          head,
          Core.vx_new_int(1)
        );
        Core.Type_string sbody = Html.f_string_from_body_indent(
          body,
          Core.vx_new_int(1)
        );
        Core.Type_string sfooter = Html.f_string_from_footer_indent(
          footer,
          Core.vx_new_int(1)
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string("<!DOCTYPE html>"),
            Core.c_newline,
            Core.vx_new_string("<html"),
            lang,
            Core.vx_new_string(">"),
            shead,
            sbody,
            sfooter,
            Core.c_newline,
            Core.vx_new_string("</html>")
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
  public interface Func_string_from_img_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_img_indent(final Html.Type_img img, final Core.Type_int indent);
  }

  public static class Class_string_from_img_indent extends Core.Class_base implements Func_string_from_img_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_img_indent output = new Html.Class_string_from_img_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_img_indent output = new Html.Class_string_from_img_indent();
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
        "vx/web/html", // pkgname
        "string<-img-indent", // name
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
      Core.Type_any output = Html.e_string_from_img_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_img_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_img img = Core.f_any_from_any(Html.t_img, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_img_indent(img, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_img_indent(final Html.Type_img img, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_img_indent(img, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_img_indent e_string_from_img_indent = new Html.Class_string_from_img_indent();
  public static final Html.Func_string_from_img_indent t_string_from_img_indent = new Html.Class_string_from_img_indent();

  public static Core.Type_string f_string_from_img_indent(final Html.Type_img img, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string ssrc = Html.f_string_from_propname_val(
          Core.vx_new_string("src"),
          img.src()
        );
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          img.id()
        );
        Core.Type_string sclass = Html.f_string_from_propstyle_stylelist(
          img.style(),
          img.stylelist()
        );
        Core.Type_string sstyle = Html.f_string_from_propstyleunique(
          img.style_unique()
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<img"),
            sid,
            sclass,
            sstyle,
            ssrc,
            Core.vx_new_string(" />")
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
  public interface Func_string_from_indent extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_indent(final Core.Type_int indent);
  }

  public static class Class_string_from_indent extends Core.Class_base implements Func_string_from_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_indent output = new Html.Class_string_from_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_indent output = new Html.Class_string_from_indent();
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
        "vx/web/html", // pkgname
        "string<-indent", // name
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
      Core.Type_any output = Html.e_string_from_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_indent;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Html.f_string_from_indent(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_indent(indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_indent(final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_indent(indent);
      return output;
    }

  }

  public static final Html.Func_string_from_indent e_string_from_indent = new Html.Class_string_from_indent();
  public static final Html.Func_string_from_indent t_string_from_indent = new Html.Class_string_from_indent();

  public static Core.Type_string f_string_from_indent(final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_1(
      Core.t_string,
      Core.f_eq(
        indent,
        Core.vx_new_int(0)
      ),
      Core.vx_new_string(""),
      Core.f_new(
        Core.t_string,
        Core.vx_new(
          Core.t_anylist,
          Core.c_newline,
          Html.f_string_indent(
            indent
          )
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
  public interface Func_string_from_meta_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_meta_indent(final Html.Type_meta meta, final Core.Type_int indent);
  }

  public static class Class_string_from_meta_indent extends Core.Class_base implements Func_string_from_meta_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_meta_indent output = new Html.Class_string_from_meta_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_meta_indent output = new Html.Class_string_from_meta_indent();
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
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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
      Core.Type_any output = Html.e_string_from_meta_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_meta_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_meta meta = Core.f_any_from_any(Html.t_meta, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_meta_indent(meta, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_meta_indent(final Html.Type_meta meta, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_meta_indent(meta, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_meta_indent e_string_from_meta_indent = new Html.Class_string_from_meta_indent();
  public static final Html.Func_string_from_meta_indent t_string_from_meta_indent = new Html.Class_string_from_meta_indent();

  public static Core.Type_string f_string_from_meta_indent(final Html.Type_meta meta, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string charset = meta.charset();
        Core.Type_string name = meta.name();
        Core.Type_string content = meta.content();
        Core.Type_string scharset = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_ne(
                  Core.vx_new_string(""),
                  charset
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Html.f_string_from_propname_val(
                  Core.vx_new_string("charset"),
                  charset
                );
                return output_3;
              })
            )
          )
        );
        Core.Type_string sname = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_ne(
                  Core.vx_new_string(""),
                  name
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Html.f_string_from_propname_val(
                  Core.vx_new_string("name"),
                  name
                );
                return output_5;
              })
            )
          )
        );
        Core.Type_string scontext = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_ne(
                  Core.vx_new_string(""),
                  content
                );
                return output_6;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = Html.f_string_from_propname_val(
                  Core.vx_new_string("content"),
                  content
                );
                return output_7;
              })
            )
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<meta"),
            scharset,
            sname,
            scontext,
            Core.vx_new_string(" />")
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
  public interface Func_string_from_node_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_node_indent(final Core.Type_any node, final Core.Type_int indent);
  }

  public static class Class_string_from_node_indent extends Core.Class_base implements Func_string_from_node_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_node_indent output = new Html.Class_string_from_node_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_node_indent output = new Html.Class_string_from_node_indent();
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
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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
      Core.Type_any output = Html.e_string_from_node_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_node_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any node = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_node_indent(node, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_node_indent(final Core.Type_any node, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_node_indent(node, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_node_indent e_string_from_node_indent = new Html.Class_string_from_node_indent();
  public static final Html.Func_string_from_node_indent t_string_from_node_indent = new Html.Class_string_from_node_indent();

  public static Core.Type_string f_string_from_node_indent(final Core.Type_any node, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_switch(
      Core.t_string,
      Core.f_type_from_any(
        node
      ),
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_case_1(
          Html.t_body,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Html.f_string_from_body_indent(
              Core.f_any_from_any(
                Html.t_body,
                node
              ),
              indent
            );
            return output_1;
          })
        ),
        Core.f_case_1(
          Html.t_details,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Html.f_string_from_details_indent(
              Core.f_any_from_any(
                Html.t_details,
                node
              ),
              indent
            );
            return output_2;
          })
        ),
        Core.f_case_1(
          Html.t_div,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Html.f_string_from_div_indent(
              Core.f_any_from_any(
                Html.t_div,
                node
              ),
              indent
            );
            return output_3;
          })
        ),
        Core.f_case_1(
          Html.t_h1,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_4 = Html.f_string_from_h1_indent(
              Core.f_any_from_any(
                Html.t_h1,
                node
              ),
              indent
            );
            return output_4;
          })
        ),
        Core.f_case_1(
          Html.t_h2,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_5 = Html.f_string_from_h2_indent(
              Core.f_any_from_any(
                Html.t_h2,
                node
              ),
              indent
            );
            return output_5;
          })
        ),
        Core.f_case_1(
          Html.t_h3,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_6 = Html.f_string_from_h3_indent(
              Core.f_any_from_any(
                Html.t_h3,
                node
              ),
              indent
            );
            return output_6;
          })
        ),
        Core.f_case_1(
          Html.t_head,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_7 = Html.f_string_from_head_indent(
              Core.f_any_from_any(
                Html.t_head,
                node
              ),
              indent
            );
            return output_7;
          })
        ),
        Core.f_case_1(
          Html.t_footer,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_8 = Html.f_string_from_footer_indent(
              Core.f_any_from_any(
                Html.t_footer,
                node
              ),
              indent
            );
            return output_8;
          })
        ),
        Core.f_case_1(
          Html.t_img,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_9 = Html.f_string_from_img_indent(
              Core.f_any_from_any(
                Html.t_img,
                node
              ),
              indent
            );
            return output_9;
          })
        ),
        Core.f_case_1(
          Html.t_meta,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_10 = Html.f_string_from_meta_indent(
              Core.f_any_from_any(
                Html.t_meta,
                node
              ),
              indent
            );
            return output_10;
          })
        ),
        Core.f_case_1(
          Html.t_p,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_11 = Html.f_string_from_p_indent(
              Core.f_any_from_any(
                Html.t_p,
                node
              ),
              indent
            );
            return output_11;
          })
        ),
        Core.f_case_1(
          Html.t_stylesheet,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_12 = Html.f_string_from_stylesheet_indent(
              Core.f_any_from_any(
                Html.t_stylesheet,
                node
              ),
              indent
            );
            return output_12;
          })
        ),
        Core.f_case_1(
          Html.t_table,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_13 = Html.f_string_from_table_indent(
              Core.f_any_from_any(
                Html.t_table,
                node
              ),
              indent
            );
            return output_13;
          })
        ),
        Core.f_case_1(
          Html.t_title,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_14 = Html.f_string_from_title_indent(
              Core.f_any_from_any(
                Html.t_title,
                node
              ),
              indent
            );
            return output_14;
          })
        ),
        Core.f_case_1(
          Html.t_tbody,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_15 = Html.f_string_from_tbody_indent(
              Core.f_any_from_any(
                Html.t_tbody,
                node
              ),
              indent
            );
            return output_15;
          })
        ),
        Core.f_case_1(
          Html.t_thead,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_16 = Html.f_string_from_thead_indent(
              Core.f_any_from_any(
                Html.t_thead,
                node
              ),
              indent
            );
            return output_16;
          })
        ),
        Core.f_case_1(
          Html.t_td,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_17 = Html.f_string_from_td_indent(
              Core.f_any_from_any(
                Html.t_td,
                node
              ),
              indent
            );
            return output_17;
          })
        ),
        Core.f_case_1(
          Html.t_tr,
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_18 = Html.f_string_from_tr_indent(
              Core.f_any_from_any(
                Html.t_tr,
                node
              ),
              indent
            );
            return output_18;
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
  public interface Func_string_from_nodelist_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_nodelist_indent(final Core.Type_list nodelist, final Core.Type_int indent);
  }

  public static class Class_string_from_nodelist_indent extends Core.Class_base implements Func_string_from_nodelist_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_nodelist_indent output = new Html.Class_string_from_nodelist_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_nodelist_indent output = new Html.Class_string_from_nodelist_indent();
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
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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
      Core.Type_any output = Html.e_string_from_nodelist_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_nodelist_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list nodelist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_nodelist_indent(nodelist, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_nodelist_indent(final Core.Type_list nodelist, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_nodelist_indent(nodelist, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_nodelist_indent e_string_from_nodelist_indent = new Html.Class_string_from_nodelist_indent();
  public static final Html.Func_string_from_nodelist_indent t_string_from_nodelist_indent = new Html.Class_string_from_nodelist_indent();

  public static Core.Type_string f_string_from_nodelist_indent(final Core.Type_list nodelist, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_stringlist textlist = Core.f_list_from_list_1(
          Core.t_stringlist,
          nodelist,
          Core.t_any_from_any.vx_fn_new((node_any) -> {
            Html.Type_node node = Core.f_any_from_any(Html.t_node, node_any);
            Core.Type_any output_2 = Html.f_string_from_node_indent(
              node,
              indent
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = Type.f_string_from_stringlist_join(
          textlist,
          Core.vx_new_string("")
        );
        return output_1;
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
  public interface Func_string_from_nodelist_tag_prop_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_nodelist_tag_prop_indent(final Core.Type_list nodes, final Core.Type_string tag, final Core.Type_string prop, final Core.Type_int indent);
  }

  public static class Class_string_from_nodelist_tag_prop_indent extends Core.Class_base implements Func_string_from_nodelist_tag_prop_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_nodelist_tag_prop_indent output = new Html.Class_string_from_nodelist_tag_prop_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_nodelist_tag_prop_indent output = new Html.Class_string_from_nodelist_tag_prop_indent();
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
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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
      Core.Type_any output = Html.e_string_from_nodelist_tag_prop_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_nodelist_tag_prop_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list nodes = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string tag = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_string prop = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(2)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(3)));
      output = Html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_nodelist_tag_prop_indent(final Core.Type_list nodes, final Core.Type_string tag, final Core.Type_string prop, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent = new Html.Class_string_from_nodelist_tag_prop_indent();
  public static final Html.Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent = new Html.Class_string_from_nodelist_tag_prop_indent();

  public static Core.Type_string f_string_from_nodelist_tag_prop_indent(final Core.Type_list nodes, final Core.Type_string tag, final Core.Type_string prop, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = Html.f_string_from_nodelist_indent(
          nodes,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string eindent = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_is_empty(
                  text
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.vx_new_string("");
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_is_empty(
                  sindent
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Core.c_newline;
                return output_5;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = sindent;
                return output_6;
              })
            )
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<"),
            tag,
            prop,
            Core.vx_new_string(">"),
            text,
            eindent,
            Core.vx_new_string("</"),
            tag,
            Core.vx_new_string(">")
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
  public interface Func_string_from_p_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_p_indent(final Html.Type_p p, final Core.Type_int indent);
  }

  public static class Class_string_from_p_indent extends Core.Class_base implements Func_string_from_p_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_p_indent output = new Html.Class_string_from_p_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_p_indent output = new Html.Class_string_from_p_indent();
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
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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
      Core.Type_any output = Html.e_string_from_p_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_p_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_p p = Core.f_any_from_any(Html.t_p, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_p_indent(p, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_p_indent(final Html.Type_p p, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_p_indent(p, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_p_indent e_string_from_p_indent = new Html.Class_string_from_p_indent();
  public static final Html.Func_string_from_p_indent t_string_from_p_indent = new Html.Class_string_from_p_indent();

  public static Core.Type_string f_string_from_p_indent(final Html.Type_p p, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string text = Html.f_htmlstring_from_string(
          p.text()
        );
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          p.id()
        );
        Core.Type_string sclass = Html.f_string_from_propstyle_stylelist(
          p.style(),
          p.stylelist()
        );
        Core.Type_string sstyle = Html.f_string_from_propstyleunique(
          p.style_unique()
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<p"),
            sid,
            sclass,
            sstyle,
            Core.vx_new_string(">"),
            text,
            Core.vx_new_string("</p>")
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
  public interface Func_string_from_propname_val extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_propname_val(final Core.Type_string key, final Core.Type_string val);
  }

  public static class Class_string_from_propname_val extends Core.Class_base implements Func_string_from_propname_val {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_propname_val output = new Html.Class_string_from_propname_val();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_propname_val output = new Html.Class_string_from_propname_val();
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
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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
      Core.Type_any output = Html.e_string_from_propname_val;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_propname_val;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string val = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_propname_val(key, val);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_propname_val(final Core.Type_string key, final Core.Type_string val) {
      Core.Type_string output = Html.f_string_from_propname_val(key, val);
      return output;
    }

  }

  public static final Html.Func_string_from_propname_val e_string_from_propname_val = new Html.Class_string_from_propname_val();
  public static final Html.Func_string_from_propname_val t_string_from_propname_val = new Html.Class_string_from_propname_val();

  public static Core.Type_string f_string_from_propname_val(final Core.Type_string key, final Core.Type_string val) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if(
      Core.t_string,
      Core.f_notempty(
        val
      ),
      Core.f_new(
        Core.t_string,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(" "),
          key,
          Core.vx_new_string("="),
          Core.c_quote,
          val,
          Core.c_quote
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
  public interface Func_string_from_propstyle extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_propstyle(final Html.Type_style style);
  }

  public static class Class_string_from_propstyle extends Core.Class_base implements Func_string_from_propstyle {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_propstyle output = new Html.Class_string_from_propstyle();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_propstyle output = new Html.Class_string_from_propstyle();
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
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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
      Core.Type_any output = Html.e_string_from_propstyle;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_propstyle;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_style inputval = (Html.Type_style)value;
      Core.Type_any outputval = Html.f_string_from_propstyle(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_style style = Core.f_any_from_any(Html.t_style, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_propstyle(style);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_propstyle(final Html.Type_style style) {
      Core.Type_string output = Html.f_string_from_propstyle(style);
      return output;
    }

  }

  public static final Html.Func_string_from_propstyle e_string_from_propstyle = new Html.Class_string_from_propstyle();
  public static final Html.Func_string_from_propstyle t_string_from_propstyle = new Html.Class_string_from_propstyle();

  public static Core.Type_string f_string_from_propstyle(final Html.Type_style style) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_2(
      Core.t_string,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_notempty_1(
              style
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_new(
              Core.t_string,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(" class="),
                Core.c_quote,
                Type.f_string_from_string_start(
                  style.name(),
                  Core.vx_new_int(2)
                ),
                Core.c_quote
              )
            );
            return output_2;
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
  public interface Func_string_from_propstyle_stylelist extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_propstyle_stylelist(final Html.Type_style style, final Html.Type_stylelist stylelist);
  }

  public static class Class_string_from_propstyle_stylelist extends Core.Class_base implements Func_string_from_propstyle_stylelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_propstyle_stylelist output = new Html.Class_string_from_propstyle_stylelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_propstyle_stylelist output = new Html.Class_string_from_propstyle_stylelist();
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
        "vx/web/html", // pkgname
        "string<-propstyle-stylelist", // name
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
      Core.Type_any output = Html.e_string_from_propstyle_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_propstyle_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_style style = Core.f_any_from_any(Html.t_style, arglist.vx_any(Core.vx_new_int(0)));
      Html.Type_stylelist stylelist = Core.f_any_from_any(Html.t_stylelist, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_propstyle_stylelist(style, stylelist);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_propstyle_stylelist(final Html.Type_style style, final Html.Type_stylelist stylelist) {
      Core.Type_string output = Html.f_string_from_propstyle_stylelist(style, stylelist);
      return output;
    }

  }

  public static final Html.Func_string_from_propstyle_stylelist e_string_from_propstyle_stylelist = new Html.Class_string_from_propstyle_stylelist();
  public static final Html.Func_string_from_propstyle_stylelist t_string_from_propstyle_stylelist = new Html.Class_string_from_propstyle_stylelist();

  public static Core.Type_string f_string_from_propstyle_stylelist(final Html.Type_style style, final Html.Type_stylelist stylelist) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_2(
      Core.t_string,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_notempty_1(
              style
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Html.f_string_from_propstyle(
              style
            );
            return output_2;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_notempty_1(
              stylelist
            );
            return output_3;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_4 = Html.f_string_from_propstylelist(
              stylelist
            );
            return output_4;
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
  public interface Func_string_from_propstylelist extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_propstylelist(final Html.Type_stylelist stylelist);
  }

  public static class Class_string_from_propstylelist extends Core.Class_base implements Func_string_from_propstylelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_propstylelist output = new Html.Class_string_from_propstylelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_propstylelist output = new Html.Class_string_from_propstylelist();
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
        "vx/web/html", // pkgname
        "string<-propstylelist", // name
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
      Core.Type_any output = Html.e_string_from_propstylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_propstylelist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylelist inputval = (Html.Type_stylelist)value;
      Core.Type_any outputval = Html.f_string_from_propstylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylelist stylelist = Core.f_any_from_any(Html.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_propstylelist(stylelist);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_propstylelist(final Html.Type_stylelist stylelist) {
      Core.Type_string output = Html.f_string_from_propstylelist(stylelist);
      return output;
    }

  }

  public static final Html.Func_string_from_propstylelist e_string_from_propstylelist = new Html.Class_string_from_propstylelist();
  public static final Html.Func_string_from_propstylelist t_string_from_propstylelist = new Html.Class_string_from_propstylelist();

  public static Core.Type_string f_string_from_propstylelist(final Html.Type_stylelist stylelist) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_2(
      Core.t_string,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_notempty_1(
              stylelist
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_let(
              Core.t_string,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_string joined = Html.f_string_from_stylelist(
                  stylelist
                );
                Core.Type_any output_3 = Core.f_if(
                  Core.t_string,
                  Core.f_ne(
                    Core.vx_new_string(""),
                    joined
                  ),
                  Core.f_new(
                    Core.t_string,
                    Core.vx_new(
                      Core.t_anylist,
                      Core.vx_new_string(" class="),
                      Core.c_quote,
                      joined,
                      Core.c_quote
                    )
                  )
                );
                return output_3;
              })
            );
            return output_2;
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
  public interface Func_string_from_propstyleunique extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_propstyleunique(final Html.Type_style style);
  }

  public static class Class_string_from_propstyleunique extends Core.Class_base implements Func_string_from_propstyleunique {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_propstyleunique output = new Html.Class_string_from_propstyleunique();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_propstyleunique output = new Html.Class_string_from_propstyleunique();
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
        "vx/web/html", // pkgname
        "string<-propstyleunique", // name
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
      Core.Type_any output = Html.e_string_from_propstyleunique;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_propstyleunique;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_style inputval = (Html.Type_style)value;
      Core.Type_any outputval = Html.f_string_from_propstyleunique(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_style style = Core.f_any_from_any(Html.t_style, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_propstyleunique(style);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_propstyleunique(final Html.Type_style style) {
      Core.Type_string output = Html.f_string_from_propstyleunique(style);
      return output;
    }

  }

  public static final Html.Func_string_from_propstyleunique e_string_from_propstyleunique = new Html.Class_string_from_propstyleunique();
  public static final Html.Func_string_from_propstyleunique t_string_from_propstyleunique = new Html.Class_string_from_propstyleunique();

  public static Core.Type_string f_string_from_propstyleunique(final Html.Type_style style) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_2(
      Core.t_string,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_notempty_1(
              style
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_let(
              Core.t_string,
              Core.t_any_from_func.vx_fn_new(() -> {
                Html.Type_propmap props = style.props();
                Core.Type_string text = Html.f_string_from_stylepropmap_indent(
                  props,
                  Core.vx_new_int(0)
                );
                Core.Type_any output_3 = Core.f_if_2(
                  Core.t_string,
                  Core.vx_new(
                    Core.t_thenelselist,
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        Core.Type_any output_4 = Core.f_notempty(
                          text
                        );
                        return output_4;
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_5 = Core.f_new(
                          Core.t_string,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(" style="),
                            Core.c_quote,
                            text,
                            Core.c_quote
                          )
                        );
                        return output_5;
                      })
                    )
                  )
                );
                return output_3;
              })
            );
            return output_2;
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
  public interface Func_string_from_style_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_style_indent(final Html.Type_style style, final Core.Type_int indent);
  }

  public static class Class_string_from_style_indent extends Core.Class_base implements Func_string_from_style_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_style_indent output = new Html.Class_string_from_style_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_style_indent output = new Html.Class_string_from_style_indent();
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
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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
      Core.Type_any output = Html.e_string_from_style_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_style_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_style style = Core.f_any_from_any(Html.t_style, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_style_indent(style, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_style_indent(final Html.Type_style style, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_style_indent(style, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_style_indent e_string_from_style_indent = new Html.Class_string_from_style_indent();
  public static final Html.Func_string_from_style_indent t_string_from_style_indent = new Html.Class_string_from_style_indent();

  public static Core.Type_string f_string_from_style_indent(final Html.Type_style style, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string name = style.name();
        Html.Type_propmap propmap = style.props();
        Html.Type_stylelist sublist = style.stylelist();
        Core.Type_string stext = Html.f_string_from_stylepropmap_indent(
          propmap,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_string subtext = Html.f_string_from_stylelist_indent(
          sublist,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            name,
            Core.vx_new_string(" {"),
            stext,
            subtext,
            sindent,
            Core.vx_new_string("}")
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
  public interface Func_string_from_stylelist extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_stylelist(final Html.Type_stylelist stylelist);
  }

  public static class Class_string_from_stylelist extends Core.Class_base implements Func_string_from_stylelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_stylelist output = new Html.Class_string_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_stylelist output = new Html.Class_string_from_stylelist();
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
        "vx/web/html", // pkgname
        "string<-stylelist", // name
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
      Core.Type_any output = Html.e_string_from_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_stylelist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylelist inputval = (Html.Type_stylelist)value;
      Core.Type_any outputval = Html.f_string_from_stylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylelist stylelist = Core.f_any_from_any(Html.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_stylelist(stylelist);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_stylelist(final Html.Type_stylelist stylelist) {
      Core.Type_string output = Html.f_string_from_stylelist(stylelist);
      return output;
    }

  }

  public static final Html.Func_string_from_stylelist e_string_from_stylelist = new Html.Class_string_from_stylelist();
  public static final Html.Func_string_from_stylelist t_string_from_stylelist = new Html.Class_string_from_stylelist();

  public static Core.Type_string f_string_from_stylelist(final Html.Type_stylelist stylelist) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_stringlist namelist = Core.f_list_from_list_1(
          Core.t_stringlist,
          stylelist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Html.Type_style item = Core.f_any_from_any(Html.t_style, item_any);
            Core.Type_any output_2 = Type.f_string_from_string_start(
              item.name(),
              Core.vx_new_int(2)
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = Type.f_string_from_stringlist_join(
          namelist,
          Core.vx_new_string(" ")
        );
        return output_1;
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
  public interface Func_string_from_stylelist_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_stylelist_indent(final Html.Type_stylelist stylelist, final Core.Type_int indent);
  }

  public static class Class_string_from_stylelist_indent extends Core.Class_base implements Func_string_from_stylelist_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_stylelist_indent output = new Html.Class_string_from_stylelist_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_stylelist_indent output = new Html.Class_string_from_stylelist_indent();
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
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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
      Core.Type_any output = Html.e_string_from_stylelist_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_stylelist_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylelist stylelist = Core.f_any_from_any(Html.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_stylelist_indent(stylelist, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_stylelist_indent(final Html.Type_stylelist stylelist, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_stylelist_indent(stylelist, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_stylelist_indent e_string_from_stylelist_indent = new Html.Class_string_from_stylelist_indent();
  public static final Html.Func_string_from_stylelist_indent t_string_from_stylelist_indent = new Html.Class_string_from_stylelist_indent();

  public static Core.Type_string f_string_from_stylelist_indent(final Html.Type_stylelist stylelist, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_stringlist sstyles = Core.f_list_from_list_1(
          Core.t_stringlist,
          stylelist,
          Core.t_any_from_any.vx_fn_new((substyle_any) -> {
            Html.Type_style substyle = Core.f_any_from_any(Html.t_style, substyle_any);
            Core.Type_any output_2 = Html.f_string_from_style_indent(
              substyle,
              indent
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = Type.f_string_from_stringlist_join(
          sstyles,
          Core.c_newline
        );
        return output_1;
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
  public interface Func_string_from_stylepropmap_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_stylepropmap_indent(final Html.Type_propmap propmap, final Core.Type_int indent);
  }

  public static class Class_string_from_stylepropmap_indent extends Core.Class_base implements Func_string_from_stylepropmap_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_stylepropmap_indent output = new Html.Class_string_from_stylepropmap_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_stylepropmap_indent output = new Html.Class_string_from_stylepropmap_indent();
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
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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
      Core.Type_any output = Html.e_string_from_stylepropmap_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_stylepropmap_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_propmap propmap = Core.f_any_from_any(Html.t_propmap, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_stylepropmap_indent(propmap, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_stylepropmap_indent(final Html.Type_propmap propmap, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_stylepropmap_indent(propmap, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent = new Html.Class_string_from_stylepropmap_indent();
  public static final Html.Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent = new Html.Class_string_from_stylepropmap_indent();

  public static Core.Type_string f_string_from_stylepropmap_indent(final Html.Type_propmap propmap, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_stringlist sprops = Core.f_list_from_map_1(
          Core.t_stringlist,
          propmap,
          Core.t_any_from_key_value.vx_fn_new((key_any, val_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Core.Type_string val = Core.f_any_from_any(Core.t_string, val_any);
            Core.Type_any output_2 = Core.f_new(
              Core.t_string,
              Core.vx_new(
                Core.t_anylist,
                sindent,
                key,
                Core.vx_new_string(": "),
                val,
                Core.vx_new_string(";")
              )
            );
            return output_2;
          })
        );
        Core.Type_any output_1 = Type.f_string_from_stringlist_join(
          sprops,
          Core.vx_new_string("")
        );
        return output_1;
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
  public interface Func_string_from_stylesheet_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_stylesheet_indent(final Html.Type_stylesheet stylesheet, final Core.Type_int indent);
  }

  public static class Class_string_from_stylesheet_indent extends Core.Class_base implements Func_string_from_stylesheet_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_stylesheet_indent output = new Html.Class_string_from_stylesheet_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_stylesheet_indent output = new Html.Class_string_from_stylesheet_indent();
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
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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
      Core.Type_any output = Html.e_string_from_stylesheet_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_stylesheet_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_stylesheet_indent(stylesheet, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_stylesheet_indent(final Html.Type_stylesheet stylesheet, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_stylesheet_indent(stylesheet, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_stylesheet_indent e_string_from_stylesheet_indent = new Html.Class_string_from_stylesheet_indent();
  public static final Html.Func_string_from_stylesheet_indent t_string_from_stylesheet_indent = new Html.Class_string_from_stylesheet_indent();

  public static Core.Type_string f_string_from_stylesheet_indent(final Html.Type_stylesheet stylesheet, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_stylelist styles = stylesheet.styles();
        Core.Type_string sstyles = Html.f_string_from_stylelist_indent(
          styles,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string eindent = Core.f_if(
          Core.t_string,
          Core.f_notempty(
            sstyles
          ),
          sindent
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<style>"),
            sstyles,
            eindent,
            Core.vx_new_string("</style>")
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
  public interface Func_string_from_table_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_table_indent(final Html.Type_table table, final Core.Type_int indent);
  }

  public static class Class_string_from_table_indent extends Core.Class_base implements Func_string_from_table_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_table_indent output = new Html.Class_string_from_table_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_table_indent output = new Html.Class_string_from_table_indent();
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
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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
      Core.Type_any output = Html.e_string_from_table_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_table_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_table table = Core.f_any_from_any(Html.t_table, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_table_indent(table, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_table_indent(final Html.Type_table table, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_table_indent(table, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_table_indent e_string_from_table_indent = new Html.Class_string_from_table_indent();
  public static final Html.Func_string_from_table_indent t_string_from_table_indent = new Html.Class_string_from_table_indent();

  public static Core.Type_string f_string_from_table_indent(final Html.Type_table table, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string sid = Html.f_string_from_propname_val(
          Core.vx_new_string("id"),
          table.id()
        );
        Html.Type_thead thead = table.thead();
        Html.Type_tbody tbody = table.tbody();
        Core.Type_string shead = Html.f_string_from_thead_indent(
          thead,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_string sbody = Html.f_string_from_tbody_indent(
          tbody,
          Core.f_plus1(
            indent
          )
        );
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<table"),
            sid,
            Core.vx_new_string(">"),
            shead,
            sbody,
            sindent,
            Core.vx_new_string("</table>")
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
  public interface Func_string_from_tbody_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_tbody_indent(final Html.Type_tbody tbody, final Core.Type_int indent);
  }

  public static class Class_string_from_tbody_indent extends Core.Class_base implements Func_string_from_tbody_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_tbody_indent output = new Html.Class_string_from_tbody_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_tbody_indent output = new Html.Class_string_from_tbody_indent();
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
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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
      Core.Type_any output = Html.e_string_from_tbody_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_tbody_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_tbody tbody = Core.f_any_from_any(Html.t_tbody, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_tbody_indent(tbody, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_tbody_indent(final Html.Type_tbody tbody, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_tbody_indent(tbody, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_tbody_indent e_string_from_tbody_indent = new Html.Class_string_from_tbody_indent();
  public static final Html.Func_string_from_tbody_indent t_string_from_tbody_indent = new Html.Class_string_from_tbody_indent();

  public static Core.Type_string f_string_from_tbody_indent(final Html.Type_tbody tbody, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_trlist nodes = tbody.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("tbody"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_td_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_td_indent(final Html.Type_td td, final Core.Type_int indent);
  }

  public static class Class_string_from_td_indent extends Core.Class_base implements Func_string_from_td_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_td_indent output = new Html.Class_string_from_td_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_td_indent output = new Html.Class_string_from_td_indent();
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
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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
      Core.Type_any output = Html.e_string_from_td_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_td_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_td td = Core.f_any_from_any(Html.t_td, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_td_indent(td, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_td_indent(final Html.Type_td td, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_td_indent(td, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_td_indent e_string_from_td_indent = new Html.Class_string_from_td_indent();
  public static final Html.Func_string_from_td_indent t_string_from_td_indent = new Html.Class_string_from_td_indent();

  public static Core.Type_string f_string_from_td_indent(final Html.Type_td td, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_divchildlist nodes = td.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("td"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_thead_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_thead_indent(final Html.Type_thead thead, final Core.Type_int indent);
  }

  public static class Class_string_from_thead_indent extends Core.Class_base implements Func_string_from_thead_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_thead_indent output = new Html.Class_string_from_thead_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_thead_indent output = new Html.Class_string_from_thead_indent();
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
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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
      Core.Type_any output = Html.e_string_from_thead_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_thead_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_thead thead = Core.f_any_from_any(Html.t_thead, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_thead_indent(thead, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_thead_indent(final Html.Type_thead thead, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_thead_indent(thead, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_thead_indent e_string_from_thead_indent = new Html.Class_string_from_thead_indent();
  public static final Html.Func_string_from_thead_indent t_string_from_thead_indent = new Html.Class_string_from_thead_indent();

  public static Core.Type_string f_string_from_thead_indent(final Html.Type_thead thead, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_trlist nodes = thead.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("thead"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_title_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_title_indent(final Html.Type_title title, final Core.Type_int indent);
  }

  public static class Class_string_from_title_indent extends Core.Class_base implements Func_string_from_title_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_title_indent output = new Html.Class_string_from_title_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_title_indent output = new Html.Class_string_from_title_indent();
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
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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
      Core.Type_any output = Html.e_string_from_title_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_title_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_title title = Core.f_any_from_any(Html.t_title, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_title_indent(title, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_title_indent(final Html.Type_title title, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_title_indent(title, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_title_indent e_string_from_title_indent = new Html.Class_string_from_title_indent();
  public static final Html.Func_string_from_title_indent t_string_from_title_indent = new Html.Class_string_from_title_indent();

  public static Core.Type_string f_string_from_title_indent(final Html.Type_title title, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string sindent = Html.f_string_from_indent(
          indent
        );
        Core.Type_string text = title.text();
        Core.Type_any output_1 = Core.f_new(
          Core.t_string,
          Core.vx_new(
            Core.t_anylist,
            sindent,
            Core.vx_new_string("<title>"),
            text,
            Core.vx_new_string("</title>")
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
  public interface Func_string_from_tr_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_from_tr_indent(final Html.Type_tr tr, final Core.Type_int indent);
  }

  public static class Class_string_from_tr_indent extends Core.Class_base implements Func_string_from_tr_indent {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_tr_indent output = new Html.Class_string_from_tr_indent();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_tr_indent output = new Html.Class_string_from_tr_indent();
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
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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
      Core.Type_any output = Html.e_string_from_tr_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_tr_indent;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_tr tr = Core.f_any_from_any(Html.t_tr, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_string_from_tr_indent(tr, indent);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_tr_indent(final Html.Type_tr tr, final Core.Type_int indent) {
      Core.Type_string output = Html.f_string_from_tr_indent(tr, indent);
      return output;
    }

  }

  public static final Html.Func_string_from_tr_indent e_string_from_tr_indent = new Html.Class_string_from_tr_indent();
  public static final Html.Func_string_from_tr_indent t_string_from_tr_indent = new Html.Class_string_from_tr_indent();

  public static Core.Type_string f_string_from_tr_indent(final Html.Type_tr tr, final Core.Type_int indent) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Html.Type_tdlist nodes = tr.nodes();
        Core.Type_any output_1 = Html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          Core.vx_new_string("tr"),
          Core.vx_new_string(""),
          indent
        );
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
  public interface Func_string_from_uri extends Core.Func_any_from_any {
    public Core.Type_string vx_string_from_uri(final Core.Type_string uri);
  }

  public static class Class_string_from_uri extends Core.Class_base implements Func_string_from_uri {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_string_from_uri output = new Html.Class_string_from_uri();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_string_from_uri output = new Html.Class_string_from_uri();
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
        "vx/web/html", // pkgname
        "string<-uri", // name
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
      Core.Type_any output = Html.e_string_from_uri;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_string_from_uri;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Html.f_string_from_uri(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string uri = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_string_from_uri(uri);
      return output;
    }

    @Override
    public Core.Type_string vx_string_from_uri(final Core.Type_string uri) {
      Core.Type_string output = Html.f_string_from_uri(uri);
      return output;
    }

  }

  public static final Html.Func_string_from_uri e_string_from_uri = new Html.Class_string_from_uri();
  public static final Html.Func_string_from_uri t_string_from_uri = new Html.Class_string_from_uri();

  public static Core.Type_string f_string_from_uri(final Core.Type_string uri) {
    Core.Type_string output = Core.e_string;
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
  public interface Func_style_from_stylesheet_name extends Core.Type_func, Core.Type_replfunc {
    public Html.Type_style vx_style_from_stylesheet_name(final Html.Type_stylesheet stylesheet, final Core.Type_string name);
  }

  public static class Class_style_from_stylesheet_name extends Core.Class_base implements Func_style_from_stylesheet_name {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_style_from_stylesheet_name output = new Html.Class_style_from_stylesheet_name();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_style_from_stylesheet_name output = new Html.Class_style_from_stylesheet_name();
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
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
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
      Core.Type_any output = Html.e_style_from_stylesheet_name;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_style_from_stylesheet_name;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Html.f_style_from_stylesheet_name(stylesheet, name);
      return output;
    }

    @Override
    public Html.Type_style vx_style_from_stylesheet_name(final Html.Type_stylesheet stylesheet, final Core.Type_string name) {
      Html.Type_style output = Html.f_style_from_stylesheet_name(stylesheet, name);
      return output;
    }

  }

  public static final Html.Func_style_from_stylesheet_name e_style_from_stylesheet_name = new Html.Class_style_from_stylesheet_name();
  public static final Html.Func_style_from_stylesheet_name t_style_from_stylesheet_name = new Html.Class_style_from_stylesheet_name();

  public static Html.Type_style f_style_from_stylesheet_name(final Html.Type_stylesheet stylesheet, final Core.Type_string name) {
    Html.Type_style output = Html.e_style;
    output = Core.f_any_from_map(
      Html.t_style,
      Html.f_stylemap_from_stylesheet(
        stylesheet
      ),
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
  public interface Func_stylemap_from_stylelist extends Core.Func_any_from_any {
    public Html.Type_stylemap vx_stylemap_from_stylelist(final Html.Type_stylelist stylelist);
  }

  public static class Class_stylemap_from_stylelist extends Core.Class_base implements Func_stylemap_from_stylelist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_stylemap_from_stylelist output = new Html.Class_stylemap_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_stylemap_from_stylelist output = new Html.Class_stylemap_from_stylelist();
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
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Html.t_style), // allowtypes
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
      Core.Type_any output = Html.e_stylemap_from_stylelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylemap_from_stylelist;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylelist inputval = (Html.Type_stylelist)value;
      Core.Type_any outputval = Html.f_stylemap_from_stylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylelist stylelist = Core.f_any_from_any(Html.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_stylemap_from_stylelist(stylelist);
      return output;
    }

    @Override
    public Html.Type_stylemap vx_stylemap_from_stylelist(final Html.Type_stylelist stylelist) {
      Html.Type_stylemap output = Html.f_stylemap_from_stylelist(stylelist);
      return output;
    }

  }

  public static final Html.Func_stylemap_from_stylelist e_stylemap_from_stylelist = new Html.Class_stylemap_from_stylelist();
  public static final Html.Func_stylemap_from_stylelist t_stylemap_from_stylelist = new Html.Class_stylemap_from_stylelist();

  public static Html.Type_stylemap f_stylemap_from_stylelist(final Html.Type_stylelist stylelist) {
    Html.Type_stylemap output = Html.e_stylemap;
    output = Core.f_map_from_list(
      Html.t_stylemap,
      stylelist,
      Core.t_any_from_any.vx_fn_new((style_any) -> {
        Html.Type_style style = Core.f_any_from_any(Html.t_style, style_any);
        Core.Type_any output_1 = style.name();
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
  public interface Func_stylemap_from_stylesheet extends Core.Func_any_from_any {
    public Html.Type_stylemap vx_stylemap_from_stylesheet(final Html.Type_stylesheet stylesheet);
  }

  public static class Class_stylemap_from_stylesheet extends Core.Class_base implements Func_stylemap_from_stylesheet {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_stylemap_from_stylesheet output = new Html.Class_stylemap_from_stylesheet();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_stylemap_from_stylesheet output = new Html.Class_stylemap_from_stylesheet();
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
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Html.t_style), // allowtypes
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
      Core.Type_any output = Html.e_stylemap_from_stylesheet;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylemap_from_stylesheet;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylesheet inputval = (Html.Type_stylesheet)value;
      Core.Type_any outputval = Html.f_stylemap_from_stylesheet(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_stylemap_from_stylesheet(stylesheet);
      return output;
    }

    @Override
    public Html.Type_stylemap vx_stylemap_from_stylesheet(final Html.Type_stylesheet stylesheet) {
      Html.Type_stylemap output = Html.f_stylemap_from_stylesheet(stylesheet);
      return output;
    }

  }

  public static final Html.Func_stylemap_from_stylesheet e_stylemap_from_stylesheet = new Html.Class_stylemap_from_stylesheet();
  public static final Html.Func_stylemap_from_stylesheet t_stylemap_from_stylesheet = new Html.Class_stylemap_from_stylesheet();

  public static Html.Type_stylemap f_stylemap_from_stylesheet(final Html.Type_stylesheet stylesheet) {
    Html.Type_stylemap output = Html.e_stylemap;
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
  public interface Func_styles_from_stylesheet extends Core.Func_any_from_any {
    public Html.Type_stylelist vx_styles_from_stylesheet(final Html.Type_stylesheet stylesheet);
  }

  public static class Class_styles_from_stylesheet extends Core.Class_base implements Func_styles_from_stylesheet {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_styles_from_stylesheet output = new Html.Class_styles_from_stylesheet();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_styles_from_stylesheet output = new Html.Class_styles_from_stylesheet();
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
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Html.t_style), // allowtypes
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
      Core.Type_any output = Html.e_styles_from_stylesheet;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_styles_from_stylesheet;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylesheet inputval = (Html.Type_stylesheet)value;
      Core.Type_any outputval = Html.f_styles_from_stylesheet(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_styles_from_stylesheet(stylesheet);
      return output;
    }

    @Override
    public Html.Type_stylelist vx_styles_from_stylesheet(final Html.Type_stylesheet stylesheet) {
      Html.Type_stylelist output = Html.f_styles_from_stylesheet(stylesheet);
      return output;
    }

  }

  public static final Html.Func_styles_from_stylesheet e_styles_from_stylesheet = new Html.Class_styles_from_stylesheet();
  public static final Html.Func_styles_from_stylesheet t_styles_from_stylesheet = new Html.Class_styles_from_stylesheet();

  public static Html.Type_stylelist f_styles_from_stylesheet(final Html.Type_stylesheet stylesheet) {
    Html.Type_stylelist output = Html.e_stylelist;
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
  public interface Func_stylesheet_loadmap extends Core.Func_any_from_any {
    public Html.Type_stylesheet vx_stylesheet_loadmap(final Html.Type_stylesheet stylesheet);
  }

  public static class Class_stylesheet_loadmap extends Core.Class_base implements Func_stylesheet_loadmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_stylesheet_loadmap output = new Html.Class_stylesheet_loadmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_stylesheet_loadmap output = new Html.Class_stylesheet_loadmap();
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
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.vx_new(Core.t_typelist, Html.t_node, Html.t_headchild), // traits
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
      Core.Type_any output = Html.e_stylesheet_loadmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_stylesheet_loadmap;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_stylesheet inputval = (Html.Type_stylesheet)value;
      Core.Type_any outputval = Html.f_stylesheet_loadmap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_stylesheet_loadmap(stylesheet);
      return output;
    }

    @Override
    public Html.Type_stylesheet vx_stylesheet_loadmap(final Html.Type_stylesheet stylesheet) {
      Html.Type_stylesheet output = Html.f_stylesheet_loadmap(stylesheet);
      return output;
    }

  }

  public static final Html.Func_stylesheet_loadmap e_stylesheet_loadmap = new Html.Class_stylesheet_loadmap();
  public static final Html.Func_stylesheet_loadmap t_stylesheet_loadmap = new Html.Class_stylesheet_loadmap();

  public static Html.Type_stylesheet f_stylesheet_loadmap(final Html.Type_stylesheet stylesheet) {
    Html.Type_stylesheet output = Html.e_stylesheet;
    output = Core.f_copy(
      stylesheet,
      Core.vx_new(
        Core.t_anylist,
        Core.vx_new_string(":stylemap"),
        Html.f_stylemap_from_stylelist(
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
  public interface Func_uri_from_string extends Core.Func_any_from_any {
    public Core.Type_string vx_uri_from_string(final Core.Type_string text);
  }

  public static class Class_uri_from_string extends Core.Class_base implements Func_uri_from_string {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Html.Class_uri_from_string output = new Html.Class_uri_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Html.Class_uri_from_string output = new Html.Class_uri_from_string();
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
        "vx/web/html", // pkgname
        "uri<-string", // name
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
      Core.Type_any output = Html.e_uri_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Html.t_uri_from_string;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Html.f_uri_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Html.f_uri_from_string(text);
      return output;
    }

    @Override
    public Core.Type_string vx_uri_from_string(final Core.Type_string text) {
      Core.Type_string output = Html.f_uri_from_string(text);
      return output;
    }

  }

  public static final Html.Func_uri_from_string e_uri_from_string = new Html.Class_uri_from_string();
  public static final Html.Func_uri_from_string t_uri_from_string = new Html.Class_uri_from_string();

  public static Core.Type_string f_uri_from_string(final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("body", Html.t_body);
    maptype.put("details", Html.t_details);
    maptype.put("div", Html.t_div);
    maptype.put("divchild", Html.t_divchild);
    maptype.put("divchildlist", Html.t_divchildlist);
    maptype.put("divlist", Html.t_divlist);
    maptype.put("footer", Html.t_footer);
    maptype.put("h1", Html.t_h1);
    maptype.put("h2", Html.t_h2);
    maptype.put("h3", Html.t_h3);
    maptype.put("head", Html.t_head);
    maptype.put("headchild", Html.t_headchild);
    maptype.put("headchildlist", Html.t_headchildlist);
    maptype.put("html", Html.t_html);
    maptype.put("img", Html.t_img);
    maptype.put("meta", Html.t_meta);
    maptype.put("node", Html.t_node);
    maptype.put("nodelist", Html.t_nodelist);
    maptype.put("p", Html.t_p);
    maptype.put("propmap", Html.t_propmap);
    maptype.put("style", Html.t_style);
    maptype.put("stylelist", Html.t_stylelist);
    maptype.put("stylemap", Html.t_stylemap);
    maptype.put("stylesheet", Html.t_stylesheet);
    maptype.put("table", Html.t_table);
    maptype.put("tbody", Html.t_tbody);
    maptype.put("td", Html.t_td);
    maptype.put("tdlist", Html.t_tdlist);
    maptype.put("thead", Html.t_thead);
    maptype.put("title", Html.t_title);
    maptype.put("tr", Html.t_tr);
    maptype.put("trlist", Html.t_trlist);
    mapfunc.put("htmlstring<-string", Html.t_htmlstring_from_string);
    mapfunc.put("string-indent", Html.t_string_indent);
    mapfunc.put("string<-body-indent", Html.t_string_from_body_indent);
    mapfunc.put("string<-details-indent", Html.t_string_from_details_indent);
    mapfunc.put("string<-div-indent", Html.t_string_from_div_indent);
    mapfunc.put("string<-footer-indent", Html.t_string_from_footer_indent);
    mapfunc.put("string<-h1-indent", Html.t_string_from_h1_indent);
    mapfunc.put("string<-h2-indent", Html.t_string_from_h2_indent);
    mapfunc.put("string<-h3-indent", Html.t_string_from_h3_indent);
    mapfunc.put("string<-head-indent", Html.t_string_from_head_indent);
    mapfunc.put("string<-html", Html.t_string_from_html);
    mapfunc.put("string<-img-indent", Html.t_string_from_img_indent);
    mapfunc.put("string<-indent", Html.t_string_from_indent);
    mapfunc.put("string<-meta-indent", Html.t_string_from_meta_indent);
    mapfunc.put("string<-node-indent", Html.t_string_from_node_indent);
    mapfunc.put("string<-nodelist-indent", Html.t_string_from_nodelist_indent);
    mapfunc.put("string<-nodelist-tag-prop-indent", Html.t_string_from_nodelist_tag_prop_indent);
    mapfunc.put("string<-p-indent", Html.t_string_from_p_indent);
    mapfunc.put("string<-propname-val", Html.t_string_from_propname_val);
    mapfunc.put("string<-propstyle", Html.t_string_from_propstyle);
    mapfunc.put("string<-propstyle-stylelist", Html.t_string_from_propstyle_stylelist);
    mapfunc.put("string<-propstylelist", Html.t_string_from_propstylelist);
    mapfunc.put("string<-propstyleunique", Html.t_string_from_propstyleunique);
    mapfunc.put("string<-style-indent", Html.t_string_from_style_indent);
    mapfunc.put("string<-stylelist", Html.t_string_from_stylelist);
    mapfunc.put("string<-stylelist-indent", Html.t_string_from_stylelist_indent);
    mapfunc.put("string<-stylepropmap-indent", Html.t_string_from_stylepropmap_indent);
    mapfunc.put("string<-stylesheet-indent", Html.t_string_from_stylesheet_indent);
    mapfunc.put("string<-table-indent", Html.t_string_from_table_indent);
    mapfunc.put("string<-tbody-indent", Html.t_string_from_tbody_indent);
    mapfunc.put("string<-td-indent", Html.t_string_from_td_indent);
    mapfunc.put("string<-thead-indent", Html.t_string_from_thead_indent);
    mapfunc.put("string<-title-indent", Html.t_string_from_title_indent);
    mapfunc.put("string<-tr-indent", Html.t_string_from_tr_indent);
    mapfunc.put("string<-uri", Html.t_string_from_uri);
    mapfunc.put("style<-stylesheet-name", Html.t_style_from_stylesheet_name);
    mapfunc.put("stylemap<-stylelist", Html.t_stylemap_from_stylelist);
    mapfunc.put("stylemap<-stylesheet", Html.t_stylemap_from_stylesheet);
    mapfunc.put("styles<-stylesheet", Html.t_styles_from_stylesheet);
    mapfunc.put("stylesheet-loadmap", Html.t_stylesheet_loadmap);
    mapfunc.put("uri<-string", Html.t_uri_from_string);
    Core.vx_global_package_set("vx/web/html", maptype, mapconst, mapfunc);
  }

}
