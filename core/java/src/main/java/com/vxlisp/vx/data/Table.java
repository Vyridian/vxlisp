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
    public Core.Type_string id();
    public Core.Type_any value();
  }

  public static class Class_cell extends Core.Class_base implements Type_cell {

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

    public Core.Type_any vx_p_value = null;

    @Override
    public Core.Type_any value() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_value;
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
      } else if ((skey.equals(":value"))) {
        output = this.value();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":value", this.value());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_cell output = Core.vx_copy(Table.e_cell, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_cell output = this;
      boolean ischanged = false;
      Table.Class_cell value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_any vx_p_value = value.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":value");
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
              msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":value"))) {
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valvalue = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_cell work = new Table.Class_cell();
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
      Core.Type_any output = Table.e_cell;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_cell;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_cell e_cell = new Table.Class_cell();
  public static final Table.Type_cell t_cell = new Table.Class_cell();

  /**
   * type: celllist
   * (type celllist)
   */
  public interface Type_celllist extends Core.Type_list {
    public List<Table.Type_cell> vx_listcell();
    public Table.Type_cell vx_cell(final Core.Type_int index);
  }

  public static class Class_celllist extends Core.Class_base implements Type_celllist {

    public List<Table.Type_cell> vx_p_list = Core.immutablelist(
      new ArrayList<Table.Type_cell>()
    );

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
      List<Table.Type_cell> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Table.Type_cell output = this.vx_cell(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_celllist output = Core.vx_copy(Table.e_celllist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_celllist output = this;
      boolean ischanged = false;
      Table.Class_celllist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Table.Type_cell> listval = new ArrayList<Table.Type_cell>(value.vx_listcell());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_cell) {
          Table.Type_cell allowsub = (Table.Type_cell)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Table.Type_cell) {
          ischanged = true;
          listval.add((Table.Type_cell)valsub);
        } else if (valsub instanceof Table.Type_celllist) {
          Table.Type_celllist multi = (Table.Type_celllist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listcell());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Table.Type_cell) {
              Table.Type_cell valitem = (Table.Type_cell)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_celllist work = new Table.Class_celllist();
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
      Core.Type_any output = Table.e_celllist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_celllist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_celllist e_celllist = new Table.Class_celllist();
  public static final Table.Type_celllist t_celllist = new Table.Class_celllist();

  /**
   * type: cellmap
   * (type cellmap)
   */
  public interface Type_cellmap extends Core.Type_map {
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
      if (false) {
      } else if (value instanceof Table.Type_cell) {
        Table.Type_cell castval = (Table.Type_cell)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
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
      Map<String, Table.Type_cell> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_cell(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Table.Class_cellmap output = new Table.Class_cellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_cell> map = new LinkedHashMap<String, Table.Type_cell>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Table.Type_cell) {
          Table.Type_cell castval = (Table.Type_cell)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidvalue", value);
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
      Table.Type_cellmap output = Core.vx_copy(Table.e_cellmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_cellmap output = this;
      boolean ischanged = false;
      Table.Class_cellmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Table.Type_cell> mapval = new LinkedHashMap<String, Table.Type_cell>(value.vx_mapcell());
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
            msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Table.Type_cell valany = Table.e_cell;
          if (false) {
          } else if (valsub instanceof Table.Type_cell) {
            Table.Type_cell valallowed = (Table.Type_cell)valsub;
            valany = valallowed;
          } else if (valsub instanceof Table.Type_cell) {
            valany = (Table.Type_cell)valsub;
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
            msg = Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidkeyvalue", msgmap);
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
        Table.Class_cellmap work = new Table.Class_cellmap();
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
      Core.Type_any output = Table.e_cellmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_cellmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_cellmap e_cellmap = new Table.Class_cellmap();
  public static final Table.Type_cellmap t_cellmap = new Table.Class_cellmap();

  /**
   * type: field
   * (type field)
   */
  public interface Type_field extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any fldtype();
  }

  public static class Class_field extends Core.Class_base implements Type_field {

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

    public Core.Type_any vx_p_fldtype = null;

    @Override
    public Core.Type_any fldtype() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_fldtype;
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
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":fldtype"))) {
        output = this.fldtype();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":fldtype", this.fldtype());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_field output = Core.vx_copy(Table.e_field, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_field output = this;
      boolean ischanged = false;
      Table.Class_field value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Core.Type_any vx_p_fldtype = value.fldtype();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fldtype");
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
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fldtype"))) {
            if (valsub == vx_p_fldtype) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valfldtype = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_fldtype = valfldtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_field work = new Table.Class_field();
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
      Core.Type_any output = Table.e_field;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_field;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_field e_field = new Table.Class_field();
  public static final Table.Type_field t_field = new Table.Class_field();

  /**
   * type: fieldlist
   * (type fieldlist)
   */
  public interface Type_fieldlist extends Core.Type_list {
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldlist extends Core.Class_base implements Type_fieldlist {

    public List<Table.Type_field> vx_p_list = Core.immutablelist(
      new ArrayList<Table.Type_field>()
    );

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
      List<Table.Type_field> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Table.Type_field output = this.vx_field(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_fieldlist output = Core.vx_copy(Table.e_fieldlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_fieldlist output = this;
      boolean ischanged = false;
      Table.Class_fieldlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Table.Type_field> listval = new ArrayList<Table.Type_field>(value.vx_listfield());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_field) {
          Table.Type_field allowsub = (Table.Type_field)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Table.Type_field) {
          ischanged = true;
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_fieldlist) {
          Table.Type_fieldlist multi = (Table.Type_fieldlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_fieldlist work = new Table.Class_fieldlist();
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
      Core.Type_any output = Table.e_fieldlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_fieldlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_fieldlist e_fieldlist = new Table.Class_fieldlist();
  public static final Table.Type_fieldlist t_fieldlist = new Table.Class_fieldlist();

  /**
   * type: fieldmap
   * (type fieldmap)
   */
  public interface Type_fieldmap extends Core.Type_list {
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldmap extends Core.Class_base implements Type_fieldmap {

    public List<Table.Type_field> vx_p_list = Core.immutablelist(
      new ArrayList<Table.Type_field>()
    );

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
      List<Table.Type_field> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Table.Type_field output = this.vx_field(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_fieldmap output = Core.vx_copy(Table.e_fieldmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_fieldmap output = this;
      boolean ischanged = false;
      Table.Class_fieldmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Table.Type_field> listval = new ArrayList<Table.Type_field>(value.vx_listfield());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_field) {
          Table.Type_field allowsub = (Table.Type_field)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Table.Type_field) {
          ischanged = true;
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_fieldmap) {
          Table.Type_fieldmap multi = (Table.Type_fieldmap)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_fieldmap work = new Table.Class_fieldmap();
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
      Core.Type_any output = Table.e_fieldmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_fieldmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_fieldmap e_fieldmap = new Table.Class_fieldmap();
  public static final Table.Type_fieldmap t_fieldmap = new Table.Class_fieldmap();

  /**
   * type: filter
   * (type filter)
   */
  public interface Type_filter extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_filter extends Core.Class_base implements Type_filter {

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

    public Core.Type_stringlist vx_p_idlist = null;

    @Override
    public Core.Type_stringlist idlist() {
      Core.Type_stringlist output = Core.e_stringlist;
      Core.Type_stringlist testnull = vx_p_idlist;
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
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":idlist"))) {
        output = this.idlist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":idlist", this.idlist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_filter output = Core.vx_copy(Table.e_filter, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_filter output = this;
      boolean ischanged = false;
      Table.Class_filter value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Core.Type_stringlist vx_p_idlist = value.idlist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
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
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":idlist"))) {
            if (valsub == vx_p_idlist) {
            } else if (valsub instanceof Core.Type_stringlist) {
              Core.Type_stringlist validlist = (Core.Type_stringlist)valsub;
              ischanged = true;
              vx_p_idlist = validlist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_filter work = new Table.Class_filter();
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
      Core.Type_any output = Table.e_filter;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_filter;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_filter e_filter = new Table.Class_filter();
  public static final Table.Type_filter t_filter = new Table.Class_filter();

  /**
   * type: row
   * (type row)
   */
  public interface Type_row extends Core.Type_struct {
    public Core.Type_string id();
    public Table.Type_cellmap cellmap();
    public Table.Type_sort cellsort();
  }

  public static class Class_row extends Core.Class_base implements Type_row {

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

    public Table.Type_cellmap vx_p_cellmap = null;

    @Override
    public Table.Type_cellmap cellmap() {
      Table.Type_cellmap output = Table.e_cellmap;
      Table.Type_cellmap testnull = vx_p_cellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Table.Type_sort vx_p_cellsort = null;

    @Override
    public Table.Type_sort cellsort() {
      Table.Type_sort output = Table.e_sort;
      Table.Type_sort testnull = vx_p_cellsort;
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
      } else if ((skey.equals(":cellmap"))) {
        output = this.cellmap();
      } else if ((skey.equals(":cellsort"))) {
        output = this.cellsort();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":cellmap", this.cellmap());
      map.put(":cellsort", this.cellsort());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_row output = Core.vx_copy(Table.e_row, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_row output = this;
      boolean ischanged = false;
      Table.Class_row value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Table.Type_cellmap vx_p_cellmap = value.cellmap();
      Table.Type_sort vx_p_cellsort = value.cellsort();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":cellmap");
      validkeys.add(":cellsort");
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
              msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":cellmap"))) {
            if (valsub == vx_p_cellmap) {
            } else if (valsub instanceof Table.Type_cellmap) {
              Table.Type_cellmap valcellmap = (Table.Type_cellmap)valsub;
              ischanged = true;
              vx_p_cellmap = valcellmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":cellsort"))) {
            if (valsub == vx_p_cellsort) {
            } else if (valsub instanceof Table.Type_sort) {
              Table.Type_sort valcellsort = (Table.Type_sort)valsub;
              ischanged = true;
              vx_p_cellsort = valcellsort;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_row work = new Table.Class_row();
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
      Core.Type_any output = Table.e_row;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_row;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_row e_row = new Table.Class_row();
  public static final Table.Type_row t_row = new Table.Class_row();

  /**
   * type: rowlist
   * (type rowlist)
   */
  public interface Type_rowlist extends Core.Type_list {
    public List<Table.Type_row> vx_listrow();
    public Table.Type_row vx_row(final Core.Type_int index);
  }

  public static class Class_rowlist extends Core.Class_base implements Type_rowlist {

    public List<Table.Type_row> vx_p_list = Core.immutablelist(
      new ArrayList<Table.Type_row>()
    );

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
      List<Table.Type_row> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Table.Type_row output = this.vx_row(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_rowlist output = Core.vx_copy(Table.e_rowlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_rowlist output = this;
      boolean ischanged = false;
      Table.Class_rowlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Table.Type_row> listval = new ArrayList<Table.Type_row>(value.vx_listrow());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Table.Type_row) {
          Table.Type_row allowsub = (Table.Type_row)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Table.Type_row) {
          ischanged = true;
          listval.add((Table.Type_row)valsub);
        } else if (valsub instanceof Table.Type_rowlist) {
          Table.Type_rowlist multi = (Table.Type_rowlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listrow());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Table.Type_row) {
              Table.Type_row valitem = (Table.Type_row)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_rowlist work = new Table.Class_rowlist();
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
      Core.Type_any output = Table.e_rowlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_rowlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_rowlist e_rowlist = new Table.Class_rowlist();
  public static final Table.Type_rowlist t_rowlist = new Table.Class_rowlist();

  /**
   * type: rowmap
   * (type rowmap)
   */
  public interface Type_rowmap extends Core.Type_map {
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
      if (false) {
      } else if (value instanceof Table.Type_row) {
        Table.Type_row castval = (Table.Type_row)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
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
      Map<String, Table.Type_row> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_row(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Table.Class_rowmap output = new Table.Class_rowmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_row> map = new LinkedHashMap<String, Table.Type_row>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Table.Type_row) {
          Table.Type_row castval = (Table.Type_row)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidvalue", value);
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
      Table.Type_rowmap output = Core.vx_copy(Table.e_rowmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_rowmap output = this;
      boolean ischanged = false;
      Table.Class_rowmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Table.Type_row> mapval = new LinkedHashMap<String, Table.Type_row>(value.vx_maprow());
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
            msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Table.Type_row valany = Table.e_row;
          if (false) {
          } else if (valsub instanceof Table.Type_row) {
            Table.Type_row valallowed = (Table.Type_row)valsub;
            valany = valallowed;
          } else if (valsub instanceof Table.Type_row) {
            valany = (Table.Type_row)valsub;
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
            msg = Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidkeyvalue", msgmap);
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
        Table.Class_rowmap work = new Table.Class_rowmap();
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
      Core.Type_any output = Table.e_rowmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_rowmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_rowmap e_rowmap = new Table.Class_rowmap();
  public static final Table.Type_rowmap t_rowmap = new Table.Class_rowmap();

  /**
   * type: sort
   * (type sort)
   */
  public interface Type_sort extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_sort extends Core.Class_base implements Type_sort {

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

    public Core.Type_stringlist vx_p_idlist = null;

    @Override
    public Core.Type_stringlist idlist() {
      Core.Type_stringlist output = Core.e_stringlist;
      Core.Type_stringlist testnull = vx_p_idlist;
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
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":idlist"))) {
        output = this.idlist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":idlist", this.idlist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_sort output = Core.vx_copy(Table.e_sort, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_sort output = this;
      boolean ischanged = false;
      Table.Class_sort value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Core.Type_stringlist vx_p_idlist = value.idlist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
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
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":idlist"))) {
            if (valsub == vx_p_idlist) {
            } else if (valsub instanceof Core.Type_stringlist) {
              Core.Type_stringlist validlist = (Core.Type_stringlist)valsub;
              ischanged = true;
              vx_p_idlist = validlist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_sort work = new Table.Class_sort();
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
      Core.Type_any output = Table.e_sort;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_sort;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_sort e_sort = new Table.Class_sort();
  public static final Table.Type_sort t_sort = new Table.Class_sort();

  /**
   * type: table
   * (type table)
   */
  public interface Type_table extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Table.Type_fieldmap fieldmap();
    public Table.Type_sort fieldsort();
    public Table.Type_rowmap rowmap();
    public Table.Type_filter rowfilter();
    public Table.Type_sort rowsort();
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

    public Table.Type_fieldmap vx_p_fieldmap = null;

    @Override
    public Table.Type_fieldmap fieldmap() {
      Table.Type_fieldmap output = Table.e_fieldmap;
      Table.Type_fieldmap testnull = vx_p_fieldmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Table.Type_sort vx_p_fieldsort = null;

    @Override
    public Table.Type_sort fieldsort() {
      Table.Type_sort output = Table.e_sort;
      Table.Type_sort testnull = vx_p_fieldsort;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Table.Type_rowmap vx_p_rowmap = null;

    @Override
    public Table.Type_rowmap rowmap() {
      Table.Type_rowmap output = Table.e_rowmap;
      Table.Type_rowmap testnull = vx_p_rowmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Table.Type_filter vx_p_rowfilter = null;

    @Override
    public Table.Type_filter rowfilter() {
      Table.Type_filter output = Table.e_filter;
      Table.Type_filter testnull = vx_p_rowfilter;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Table.Type_sort vx_p_rowsort = null;

    @Override
    public Table.Type_sort rowsort() {
      Table.Type_sort output = Table.e_sort;
      Table.Type_sort testnull = vx_p_rowsort;
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
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":fieldmap"))) {
        output = this.fieldmap();
      } else if ((skey.equals(":fieldsort"))) {
        output = this.fieldsort();
      } else if ((skey.equals(":rowmap"))) {
        output = this.rowmap();
      } else if ((skey.equals(":rowfilter"))) {
        output = this.rowfilter();
      } else if ((skey.equals(":rowsort"))) {
        output = this.rowsort();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":fieldmap", this.fieldmap());
      map.put(":fieldsort", this.fieldsort());
      map.put(":rowmap", this.rowmap());
      map.put(":rowfilter", this.rowfilter());
      map.put(":rowsort", this.rowsort());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Table.Type_table output = Core.vx_copy(Table.e_table, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Table.Type_table output = this;
      boolean ischanged = false;
      Table.Class_table value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Table.Type_fieldmap vx_p_fieldmap = value.fieldmap();
      Table.Type_sort vx_p_fieldsort = value.fieldsort();
      Table.Type_rowmap vx_p_rowmap = value.rowmap();
      Table.Type_filter vx_p_rowfilter = value.rowfilter();
      Table.Type_sort vx_p_rowsort = value.rowsort();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fieldmap");
      validkeys.add(":fieldsort");
      validkeys.add(":rowmap");
      validkeys.add(":rowfilter");
      validkeys.add(":rowsort");
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
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
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
              msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":fieldmap"))) {
            if (valsub == vx_p_fieldmap) {
            } else if (valsub instanceof Table.Type_fieldmap) {
              Table.Type_fieldmap valfieldmap = (Table.Type_fieldmap)valsub;
              ischanged = true;
              vx_p_fieldmap = valfieldmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":fieldsort"))) {
            if (valsub == vx_p_fieldsort) {
            } else if (valsub instanceof Table.Type_sort) {
              Table.Type_sort valfieldsort = (Table.Type_sort)valsub;
              ischanged = true;
              vx_p_fieldsort = valfieldsort;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":rowmap"))) {
            if (valsub == vx_p_rowmap) {
            } else if (valsub instanceof Table.Type_rowmap) {
              Table.Type_rowmap valrowmap = (Table.Type_rowmap)valsub;
              ischanged = true;
              vx_p_rowmap = valrowmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":rowfilter"))) {
            if (valsub == vx_p_rowfilter) {
            } else if (valsub instanceof Table.Type_filter) {
              Table.Type_filter valrowfilter = (Table.Type_filter)valsub;
              ischanged = true;
              vx_p_rowfilter = valrowfilter;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":rowsort"))) {
            if (valsub == vx_p_rowsort) {
            } else if (valsub instanceof Table.Type_sort) {
              Table.Type_sort valrowsort = (Table.Type_sort)valsub;
              ischanged = true;
              vx_p_rowsort = valrowsort;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Table.Class_table work = new Table.Class_table();
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
      Core.Type_any output = Table.e_table;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Table.t_table;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Table.Type_table e_table = new Table.Class_table();
  public static final Table.Type_table t_table = new Table.Class_table();

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
