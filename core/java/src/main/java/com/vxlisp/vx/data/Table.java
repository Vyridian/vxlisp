package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;

public final class Table {


  /**
   * type: cell
   * (type cell)
   */
  public interface Type_cell extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_any value();
  }

  public static class Class_cell extends Core.Class_base implements Type_cell {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_any vx_p_value;

    @Override
    public Core.Type_any value() {
      Core.Type_any output = Core.e_any;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":value":
        output = this.value();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_cell vx_new(final Object... vals) {
      return Core.vx_copy(
       e_cell,
       vals);
    }

    @Override
    public Table.Type_cell vx_copy(final Object... vals) {
      Type_cell output = this;
      boolean ischanged = false;
      Class_cell val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_any vx_p_value = val.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":value");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_value = (Core.Type_any)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_cell work = new Class_cell();
        work.vx_p_id = vx_p_id;
        work.vx_p_value = vx_p_value;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_cell;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_cell;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "cell", // name
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

  public static final Type_cell e_cell = new Class_cell();
  public static final Type_cell t_cell = new Class_cell();

  /**
   * type: celllist
   * (type celllist)
   */
  public interface Type_celllist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Table.Type_cell> vx_listcell();
    public Table.Type_cell vx_cell(final Core.Type_int index);
  }

  public static class Class_celllist extends Core.Class_base implements Type_celllist {

    public List<Table.Type_cell> vx_p_list = Core.immutablelist(new ArrayList<Table.Type_cell>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Table.Type_cell vx_cell(final Core.Type_int index) {
      Table.Type_cell output = Table.e_cell;
      Table.Class_celllist list = this;
      int iindex = index.vx_int();
      List<Table.Type_cell> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_cell> vx_listcell() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_cell(index);
    }

    @Override
    public Table.Type_celllist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_celllist,
       vals);
    }

    @Override
    public Table.Type_celllist vx_copy(final Object... vals) {
      Type_celllist output = this;
      boolean ischanged = false;
      Class_celllist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Table.Type_cell> listval = new ArrayList<Table.Type_cell>(val.vx_listcell());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_cell) {
          Table.Type_cell anysub = (Table.Type_cell)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Table.Type_cell) {
          ischanged = true;
          listval.add((Table.Type_cell)valsub);
        } else if (valsub instanceof Table.Type_celllist) {
          Type_celllist multi = (Type_celllist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listcell());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_cell) {
              Table.Type_cell valitem = (Table.Type_cell)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_celllist work = new Class_celllist();
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
      return e_celllist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_celllist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_cell), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_celllist e_celllist = new Class_celllist();
  public static final Type_celllist t_celllist = new Class_celllist();

  /**
   * type: cellmap
   * (type cellmap)
   */
  public interface Type_cellmap extends Core.Type_map {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Table.Type_cell> vx_mapcell();
    public Table.Type_cell vx_cell(final Core.Type_string key);
  }

  public static class Class_cellmap extends Core.Class_base implements Type_cellmap {

    public Map<String, Table.Type_cell> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Table.Type_cell>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (value instanceof Table.Type_cell) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Table.Type_cell castval = (Table.Type_cell)value;
        Map<String, Table.Type_cell> map = new LinkedHashMap<String, Table.Type_cell>(this.vx_p_map);
        if (castval == Table.e_cell) {
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
    public Table.Type_cell vx_cell(final Core.Type_string key) {
      Table.Type_cell output = Table.e_cell;
      Table.Class_cellmap map = this;
      String skey = key.vx_string();
      Map<String, Table.Type_cell> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Table.e_cell);
      return output;
    }

    @Override
    public Map<String, Table.Type_cell> vx_mapcell() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_cell(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Table.Class_cellmap output = new Table.Class_cellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_cell> map = new LinkedHashMap<String, Table.Type_cell>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Table.Type_cell) {
          Table.Type_cell castval = (Table.Type_cell)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidvalue", val);
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
    public Table.Type_cellmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_cellmap,
       vals);
    }

    @Override
    public Table.Type_cellmap vx_copy(final Object... vals) {
      Type_cellmap output = this;
      boolean ischanged = false;
      Class_cellmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Table.Type_cell> mapval = new LinkedHashMap<String, Table.Type_cell>(val.vx_mapcell());
      Core.Type_msg msg;
      String key = "";
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Table.Type_cell valany = null;
          if (valsub instanceof Table.Type_cell) {
            valany = (Table.Type_cell)valsub;
          } else if (valsub instanceof Table.Type_cell) {
            valany = (Table.Type_cell)valsub;
          } else {
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
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
        Class_cellmap work = new Class_cellmap();
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
      return e_cellmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_cellmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_cell), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_cellmap e_cellmap = new Class_cellmap();
  public static final Type_cellmap t_cellmap = new Class_cellmap();

  /**
   * type: field
   * (type field)
   */
  public interface Type_field extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any fldtype();
  }

  public static class Class_field extends Core.Class_base implements Type_field {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Core.Type_any vx_p_fldtype;

    @Override
    public Core.Type_any fldtype() {
      Core.Type_any output = Core.e_any;
      if (this.vx_p_fldtype != null) {
        output = this.vx_p_fldtype;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":fldtype":
        output = this.fldtype();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":fldtype", this.fldtype());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_field vx_new(final Object... vals) {
      return Core.vx_copy(
       e_field,
       vals);
    }

    @Override
    public Table.Type_field vx_copy(final Object... vals) {
      Type_field output = this;
      boolean ischanged = false;
      Class_field val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Core.Type_any vx_p_fldtype = val.fldtype();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fldtype");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fldtype":
            if (valsub == vx_p_fldtype) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_fldtype = (Core.Type_any)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fldtype"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_field work = new Class_field();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_fldtype = vx_p_fldtype;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_field;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_field;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "field", // name
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

  public static final Type_field e_field = new Class_field();
  public static final Type_field t_field = new Class_field();

  /**
   * type: fieldlist
   * (type fieldlist)
   */
  public interface Type_fieldlist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldlist extends Core.Class_base implements Type_fieldlist {

    public List<Table.Type_field> vx_p_list = Core.immutablelist(new ArrayList<Table.Type_field>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Table.Type_field vx_field(final Core.Type_int index) {
      Table.Type_field output = Table.e_field;
      Table.Class_fieldlist list = this;
      int iindex = index.vx_int();
      List<Table.Type_field> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_field> vx_listfield() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_field(index);
    }

    @Override
    public Table.Type_fieldlist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_fieldlist,
       vals);
    }

    @Override
    public Table.Type_fieldlist vx_copy(final Object... vals) {
      Type_fieldlist output = this;
      boolean ischanged = false;
      Class_fieldlist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Table.Type_field> listval = new ArrayList<Table.Type_field>(val.vx_listfield());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_field) {
          Table.Type_field anysub = (Table.Type_field)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Table.Type_field) {
          ischanged = true;
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_fieldlist) {
          Type_fieldlist multi = (Type_fieldlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fieldlist work = new Class_fieldlist();
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
      return e_fieldlist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_fieldlist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_field), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fieldlist e_fieldlist = new Class_fieldlist();
  public static final Type_fieldlist t_fieldlist = new Class_fieldlist();

  /**
   * type: fieldmap
   * (type fieldmap)
   */
  public interface Type_fieldmap extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldmap extends Core.Class_base implements Type_fieldmap {

    public List<Table.Type_field> vx_p_list = Core.immutablelist(new ArrayList<Table.Type_field>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Table.Type_field vx_field(final Core.Type_int index) {
      Table.Type_field output = Table.e_field;
      Table.Class_fieldmap list = this;
      int iindex = index.vx_int();
      List<Table.Type_field> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_field> vx_listfield() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_field(index);
    }

    @Override
    public Table.Type_fieldmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_fieldmap,
       vals);
    }

    @Override
    public Table.Type_fieldmap vx_copy(final Object... vals) {
      Type_fieldmap output = this;
      boolean ischanged = false;
      Class_fieldmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Table.Type_field> listval = new ArrayList<Table.Type_field>(val.vx_listfield());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_field) {
          Table.Type_field anysub = (Table.Type_field)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Table.Type_field) {
          ischanged = true;
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_fieldmap) {
          Type_fieldmap multi = (Type_fieldmap)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fieldmap work = new Class_fieldmap();
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
      return e_fieldmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_fieldmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_field), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_fieldmap e_fieldmap = new Class_fieldmap();
  public static final Type_fieldmap t_fieldmap = new Class_fieldmap();

  /**
   * type: filter
   * (type filter)
   */
  public interface Type_filter extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_filter extends Core.Class_base implements Type_filter {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Core.Type_stringlist vx_p_idlist;

    @Override
    public Core.Type_stringlist idlist() {
      Core.Type_stringlist output = Core.e_stringlist;
      if (this.vx_p_idlist != null) {
        output = this.vx_p_idlist;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":idlist":
        output = this.idlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_filter vx_new(final Object... vals) {
      return Core.vx_copy(
       e_filter,
       vals);
    }

    @Override
    public Table.Type_filter vx_copy(final Object... vals) {
      Type_filter output = this;
      boolean ischanged = false;
      Class_filter val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Core.Type_stringlist vx_p_idlist = val.idlist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":idlist":
            if (valsub == vx_p_idlist) {
            } else if (valsub instanceof Core.Type_stringlist) {
              ischanged = true;
              vx_p_idlist = (Core.Type_stringlist)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("idlist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_filter work = new Class_filter();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_idlist = vx_p_idlist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_filter;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_filter;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "filter", // name
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

  public static final Type_filter e_filter = new Class_filter();
  public static final Type_filter t_filter = new Class_filter();

  /**
   * type: row
   * (type row)
   */
  public interface Type_row extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Table.Type_cellmap cellmap();
    public Table.Type_sort cellsort();
  }

  public static class Class_row extends Core.Class_base implements Type_row {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Table.Type_cellmap vx_p_cellmap;

    @Override
    public Table.Type_cellmap cellmap() {
      Table.Type_cellmap output = Table.e_cellmap;
      if (this.vx_p_cellmap != null) {
        output = this.vx_p_cellmap;
      }
      return output;
    }

    public Table.Type_sort vx_p_cellsort;

    @Override
    public Table.Type_sort cellsort() {
      Table.Type_sort output = Table.e_sort;
      if (this.vx_p_cellsort != null) {
        output = this.vx_p_cellsort;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":cellmap":
        output = this.cellmap();
        break;
      case ":cellsort":
        output = this.cellsort();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":cellmap", this.cellmap());
      output.put(":cellsort", this.cellsort());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_row vx_new(final Object... vals) {
      return Core.vx_copy(
       e_row,
       vals);
    }

    @Override
    public Table.Type_row vx_copy(final Object... vals) {
      Type_row output = this;
      boolean ischanged = false;
      Class_row val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Table.Type_cellmap vx_p_cellmap = val.cellmap();
      Table.Type_sort vx_p_cellsort = val.cellsort();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":cellmap");
      validkeys.add(":cellsort");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":cellmap":
            if (valsub == vx_p_cellmap) {
            } else if (valsub instanceof Table.Type_cellmap) {
              ischanged = true;
              vx_p_cellmap = (Table.Type_cellmap)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("cellmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":cellsort":
            if (valsub == vx_p_cellsort) {
            } else if (valsub instanceof Table.Type_sort) {
              ischanged = true;
              vx_p_cellsort = (Table.Type_sort)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("cellsort"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_row work = new Class_row();
        work.vx_p_id = vx_p_id;
        work.vx_p_cellmap = vx_p_cellmap;
        work.vx_p_cellsort = vx_p_cellsort;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_row;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_row;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "row", // name
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

  public static final Type_row e_row = new Class_row();
  public static final Type_row t_row = new Class_row();

  /**
   * type: rowlist
   * (type rowlist)
   */
  public interface Type_rowlist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Table.Type_row> vx_listrow();
    public Table.Type_row vx_row(final Core.Type_int index);
  }

  public static class Class_rowlist extends Core.Class_base implements Type_rowlist {

    public List<Table.Type_row> vx_p_list = Core.immutablelist(new ArrayList<Table.Type_row>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Table.Type_row vx_row(final Core.Type_int index) {
      Table.Type_row output = Table.e_row;
      Table.Class_rowlist list = this;
      int iindex = index.vx_int();
      List<Table.Type_row> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_row> vx_listrow() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_row(index);
    }

    @Override
    public Table.Type_rowlist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_rowlist,
       vals);
    }

    @Override
    public Table.Type_rowlist vx_copy(final Object... vals) {
      Type_rowlist output = this;
      boolean ischanged = false;
      Class_rowlist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Table.Type_row> listval = new ArrayList<Table.Type_row>(val.vx_listrow());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_row) {
          Table.Type_row anysub = (Table.Type_row)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Table.Type_row) {
          ischanged = true;
          listval.add((Table.Type_row)valsub);
        } else if (valsub instanceof Table.Type_rowlist) {
          Type_rowlist multi = (Type_rowlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listrow());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_row) {
              Table.Type_row valitem = (Table.Type_row)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_rowlist work = new Class_rowlist();
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
      return e_rowlist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_rowlist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_row), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rowlist e_rowlist = new Class_rowlist();
  public static final Type_rowlist t_rowlist = new Class_rowlist();

  /**
   * type: rowmap
   * (type rowmap)
   */
  public interface Type_rowmap extends Core.Type_map {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Table.Type_row> vx_maprow();
    public Table.Type_row vx_row(final Core.Type_string key);
  }

  public static class Class_rowmap extends Core.Class_base implements Type_rowmap {

    public Map<String, Table.Type_row> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Table.Type_row>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (value instanceof Table.Type_row) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Table.Type_row castval = (Table.Type_row)value;
        Map<String, Table.Type_row> map = new LinkedHashMap<String, Table.Type_row>(this.vx_p_map);
        if (castval == Table.e_row) {
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
    public Table.Type_row vx_row(final Core.Type_string key) {
      Table.Type_row output = Table.e_row;
      Table.Class_rowmap map = this;
      String skey = key.vx_string();
      Map<String, Table.Type_row> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Table.e_row);
      return output;
    }

    @Override
    public Map<String, Table.Type_row> vx_maprow() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_row(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Table.Class_rowmap output = new Table.Class_rowmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_row> map = new LinkedHashMap<String, Table.Type_row>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Table.Type_row) {
          Table.Type_row castval = (Table.Type_row)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidvalue", val);
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
    public Table.Type_rowmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_rowmap,
       vals);
    }

    @Override
    public Table.Type_rowmap vx_copy(final Object... vals) {
      Type_rowmap output = this;
      boolean ischanged = false;
      Class_rowmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Table.Type_row> mapval = new LinkedHashMap<String, Table.Type_row>(val.vx_maprow());
      Core.Type_msg msg;
      String key = "";
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Table.Type_row valany = null;
          if (valsub instanceof Table.Type_row) {
            valany = (Table.Type_row)valsub;
          } else if (valsub instanceof Table.Type_row) {
            valany = (Table.Type_row)valsub;
          } else {
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
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
        Class_rowmap work = new Class_rowmap();
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
      return e_rowmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_rowmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Table.t_row), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rowmap e_rowmap = new Class_rowmap();
  public static final Type_rowmap t_rowmap = new Class_rowmap();

  /**
   * type: sort
   * (type sort)
   */
  public interface Type_sort extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_sort extends Core.Class_base implements Type_sort {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Core.Type_stringlist vx_p_idlist;

    @Override
    public Core.Type_stringlist idlist() {
      Core.Type_stringlist output = Core.e_stringlist;
      if (this.vx_p_idlist != null) {
        output = this.vx_p_idlist;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":idlist":
        output = this.idlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_sort vx_new(final Object... vals) {
      return Core.vx_copy(
       e_sort,
       vals);
    }

    @Override
    public Table.Type_sort vx_copy(final Object... vals) {
      Type_sort output = this;
      boolean ischanged = false;
      Class_sort val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Core.Type_stringlist vx_p_idlist = val.idlist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":idlist":
            if (valsub == vx_p_idlist) {
            } else if (valsub instanceof Core.Type_stringlist) {
              ischanged = true;
              vx_p_idlist = (Core.Type_stringlist)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("idlist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_sort work = new Class_sort();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_idlist = vx_p_idlist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_sort;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_sort;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "sort", // name
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

  public static final Type_sort e_sort = new Class_sort();
  public static final Type_sort t_sort = new Class_sort();

  /**
   * type: table
   * (type table)
   */
  public interface Type_table extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Table.Type_fieldmap fieldmap();
    public Table.Type_sort fieldsort();
    public Table.Type_rowmap rowmap();
    public Table.Type_filter rowfilter();
    public Table.Type_sort rowsort();
  }

  public static class Class_table extends Core.Class_base implements Type_table {

    public Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Table.Type_fieldmap vx_p_fieldmap;

    @Override
    public Table.Type_fieldmap fieldmap() {
      Table.Type_fieldmap output = Table.e_fieldmap;
      if (this.vx_p_fieldmap != null) {
        output = this.vx_p_fieldmap;
      }
      return output;
    }

    public Table.Type_sort vx_p_fieldsort;

    @Override
    public Table.Type_sort fieldsort() {
      Table.Type_sort output = Table.e_sort;
      if (this.vx_p_fieldsort != null) {
        output = this.vx_p_fieldsort;
      }
      return output;
    }

    public Table.Type_rowmap vx_p_rowmap;

    @Override
    public Table.Type_rowmap rowmap() {
      Table.Type_rowmap output = Table.e_rowmap;
      if (this.vx_p_rowmap != null) {
        output = this.vx_p_rowmap;
      }
      return output;
    }

    public Table.Type_filter vx_p_rowfilter;

    @Override
    public Table.Type_filter rowfilter() {
      Table.Type_filter output = Table.e_filter;
      if (this.vx_p_rowfilter != null) {
        output = this.vx_p_rowfilter;
      }
      return output;
    }

    public Table.Type_sort vx_p_rowsort;

    @Override
    public Table.Type_sort rowsort() {
      Table.Type_sort output = Table.e_sort;
      if (this.vx_p_rowsort != null) {
        output = this.vx_p_rowsort;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":fieldmap":
        output = this.fieldmap();
        break;
      case ":fieldsort":
        output = this.fieldsort();
        break;
      case ":rowmap":
        output = this.rowmap();
        break;
      case ":rowfilter":
        output = this.rowfilter();
        break;
      case ":rowsort":
        output = this.rowsort();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":fieldmap", this.fieldmap());
      output.put(":fieldsort", this.fieldsort());
      output.put(":rowmap", this.rowmap());
      output.put(":rowfilter", this.rowfilter());
      output.put(":rowsort", this.rowsort());
      return Core.immutablemap(output);
    }

    @Override
    public Table.Type_table vx_new(final Object... vals) {
      return Core.vx_copy(
       e_table,
       vals);
    }

    @Override
    public Table.Type_table vx_copy(final Object... vals) {
      Type_table output = this;
      boolean ischanged = false;
      Class_table val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Table.Type_fieldmap vx_p_fieldmap = val.fieldmap();
      Table.Type_sort vx_p_fieldsort = val.fieldsort();
      Table.Type_rowmap vx_p_rowmap = val.rowmap();
      Table.Type_filter vx_p_rowfilter = val.rowfilter();
      Table.Type_sort vx_p_rowsort = val.rowsort();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fieldmap");
      validkeys.add(":fieldsort");
      validkeys.add(":rowmap");
      validkeys.add(":rowfilter");
      validkeys.add(":rowsort");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fieldmap":
            if (valsub == vx_p_fieldmap) {
            } else if (valsub instanceof Table.Type_fieldmap) {
              ischanged = true;
              vx_p_fieldmap = (Table.Type_fieldmap)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fieldmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fieldsort":
            if (valsub == vx_p_fieldsort) {
            } else if (valsub instanceof Table.Type_sort) {
              ischanged = true;
              vx_p_fieldsort = (Table.Type_sort)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fieldsort"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":rowmap":
            if (valsub == vx_p_rowmap) {
            } else if (valsub instanceof Table.Type_rowmap) {
              ischanged = true;
              vx_p_rowmap = (Table.Type_rowmap)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("rowmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":rowfilter":
            if (valsub == vx_p_rowfilter) {
            } else if (valsub instanceof Table.Type_filter) {
              ischanged = true;
              vx_p_rowfilter = (Table.Type_filter)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("rowfilter"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":rowsort":
            if (valsub == vx_p_rowsort) {
            } else if (valsub instanceof Table.Type_sort) {
              ischanged = true;
              vx_p_rowsort = (Table.Type_sort)valsub;
            } else {
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("rowsort"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_table work = new Class_table();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_fieldmap = vx_p_fieldmap;
        work.vx_p_fieldsort = vx_p_fieldsort;
        work.vx_p_rowmap = vx_p_rowmap;
        work.vx_p_rowfilter = vx_p_rowfilter;
        work.vx_p_rowsort = vx_p_rowsort;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_table;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_table;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "table", // name
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

  public static final Type_table e_table = new Class_table();
  public static final Type_table t_table = new Class_table();

  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("cell", Table.t_cell);
    maptype.put("celllist", Table.t_celllist);
    maptype.put("cellmap", Table.t_cellmap);
    maptype.put("field", Table.t_field);
    maptype.put("fieldlist", Table.t_fieldlist);
    maptype.put("fieldmap", Table.t_fieldmap);
    maptype.put("filter", Table.t_filter);
    maptype.put("row", Table.t_row);
    maptype.put("rowlist", Table.t_rowlist);
    maptype.put("rowmap", Table.t_rowmap);
    maptype.put("sort", Table.t_sort);
    maptype.put("table", Table.t_table);
    Core.vx_global_package_set("vx/data/table", maptype, mapconst, mapfunc);
  }

}
