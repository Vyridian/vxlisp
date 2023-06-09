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
    public Table.Type_cell vx_new(final Object... vals);
    public Table.Type_cell vx_copy(final Object... vals);
    public Table.Type_cell vx_empty();
    public Table.Type_cell vx_type();
    public Core.Type_string id();
    public Core.Type_any value();
  }

  public static class Class_cell extends Core.Class_base implements Type_cell {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_any vx_p_value;

    @Override
    public Core.Type_any value() {
      return this.vx_p_value == null ? Core.e_any : this.vx_p_value;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Type_cell vx_new(final Object... vals) {return e_cell.vx_copy(vals);}

    @Override
    public Type_cell vx_copy(final Object... vals) {
      Class_cell output = new Class_cell();
      Type_cell val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_value = val.value();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":value");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new cell) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new cell :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_value = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new cell :value " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new cell) - Invalid Key: " + key);
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
    public Type_cell vx_empty() {return e_cell;}
    @Override
    public Type_cell vx_type() {return t_cell;}

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
    public Table.Type_celllist vx_new(final Object... vals);
    public Table.Type_celllist vx_copy(final Object... vals);
    public Table.Type_celllist vx_empty();
    public Table.Type_celllist vx_type();
    public List<Table.Type_cell> vx_listcell();
    public Table.Type_cell vx_cell(final Core.Type_int index);
  }

  public static class Class_celllist extends Core.Class_base implements Type_celllist {

    protected List<Table.Type_cell> vxlist = Core.immutablelist(new ArrayList<Table.Type_cell>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Table.Type_cell vx_cell(final Core.Type_int index) {
      Table.Type_cell output = Table.e_cell;
      Class_celllist list = this;
      int iindex = index.vx_int();
      List<Table.Type_cell> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_cell> vx_listcell() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_cell(index);
    }

    @Override
    public Type_celllist vx_new(final Object... vals) {return e_celllist.vx_copy(vals);}

    @Override
    public Type_celllist vx_copy(final Object... vals) {
      Class_celllist output = new Class_celllist();
      Type_celllist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Table.Type_cell> listval = new ArrayList<>(val.vx_listcell());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Table.Type_cell) {
          listval.add((Table.Type_cell)valsub);
        } else if (valsub instanceof Table.Type_cell) {
          listval.add((Table.Type_cell)valsub);
        } else if (valsub instanceof Type_celllist) {
          Type_celllist multi = (Type_celllist)valsub;
          listval.addAll(multi.vx_listcell());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_cell) {
              Table.Type_cell valitem = (Table.Type_cell)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new celllist) - Invalid Type: " + valsub.toString());
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
    public Type_celllist vx_empty() {return e_celllist;}
    @Override
    public Type_celllist vx_type() {return t_celllist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_cell), // allowtypes
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
    public Table.Type_cellmap vx_new(final Object... vals);
    public Table.Type_cellmap vx_copy(final Object... vals);
    public Table.Type_cellmap vx_empty();
    public Table.Type_cellmap vx_type();
    public Map<String, Table.Type_cell> vx_mapcell();
    public Table.Type_cell vx_cell(final Core.Type_string key);
  }

  public static class Class_cellmap extends Core.Class_base implements Type_cellmap {

    protected Map<String, Table.Type_cell> vxmap = Core.immutablemap(new LinkedHashMap<String, Table.Type_cell>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}

    @Override
    public Table.Type_cell vx_cell(final Core.Type_string key) {
      Table.Type_cell output = Table.e_cell;
      Class_cellmap map = this;
      String skey = key.vx_string();
      Map<String, Table.Type_cell> mapval = map.vxmap;
      output = mapval.getOrDefault(skey, Table.e_cell);
      return output;
    }

    @Override
    public Map<String, Table.Type_cell> vx_mapcell() {return vxmap;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_cell(key);
    }

    @Override
    public Type_cellmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_cellmap output = new Class_cellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_cell> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Table.Type_cell) {
          Table.Type_cell castval = (Table.Type_cell)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(cellmap) Invalid Value: " + val.toString() + "");
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
    public Type_cellmap vx_new(final Object... vals) {return e_cellmap.vx_copy(vals);}

    @Override
    public Type_cellmap vx_copy(final Object... vals) {
      Class_cellmap output = new Class_cellmap();
      Type_cellmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Table.Type_cell> mapval = new LinkedHashMap<>(valmap.vx_mapcell());
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
          Table.Type_cell valany = null;
          if (valsub instanceof Table.Type_cell) {
            valany = (Table.Type_cell)valsub;
          } else if (valsub instanceof Table.Type_cell) {
            valany = (Table.Type_cell)valsub;
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
    public Type_cellmap vx_empty() {return e_cellmap;}
    @Override
    public Type_cellmap vx_type() {return t_cellmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_cell), // allowtypes
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
    public Table.Type_field vx_new(final Object... vals);
    public Table.Type_field vx_copy(final Object... vals);
    public Table.Type_field vx_empty();
    public Table.Type_field vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any fldtype();
  }

  public static class Class_field extends Core.Class_base implements Type_field {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_any vx_p_fldtype;

    @Override
    public Core.Type_any fldtype() {
      return this.vx_p_fldtype == null ? Core.e_any : this.vx_p_fldtype;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":fldtype", this.fldtype());
      return Core.immutablemap(output);
    }

    @Override
    public Type_field vx_new(final Object... vals) {return e_field.vx_copy(vals);}

    @Override
    public Type_field vx_copy(final Object... vals) {
      Class_field output = new Class_field();
      Type_field val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_fldtype = val.fldtype();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fldtype");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new field) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new field :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new field :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fldtype":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_fldtype = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new field :fldtype " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new field) - Invalid Key: " + key);
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
    public Type_field vx_empty() {return e_field;}
    @Override
    public Type_field vx_type() {return t_field;}

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
    public Table.Type_fieldlist vx_new(final Object... vals);
    public Table.Type_fieldlist vx_copy(final Object... vals);
    public Table.Type_fieldlist vx_empty();
    public Table.Type_fieldlist vx_type();
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldlist extends Core.Class_base implements Type_fieldlist {

    protected List<Table.Type_field> vxlist = Core.immutablelist(new ArrayList<Table.Type_field>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Table.Type_field vx_field(final Core.Type_int index) {
      Table.Type_field output = Table.e_field;
      Class_fieldlist list = this;
      int iindex = index.vx_int();
      List<Table.Type_field> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_field> vx_listfield() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_field(index);
    }

    @Override
    public Type_fieldlist vx_new(final Object... vals) {return e_fieldlist.vx_copy(vals);}

    @Override
    public Type_fieldlist vx_copy(final Object... vals) {
      Class_fieldlist output = new Class_fieldlist();
      Type_fieldlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Table.Type_field> listval = new ArrayList<>(val.vx_listfield());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Table.Type_field) {
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_field) {
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Type_fieldlist) {
          Type_fieldlist multi = (Type_fieldlist)valsub;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new fieldlist) - Invalid Type: " + valsub.toString());
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
    public Type_fieldlist vx_empty() {return e_fieldlist;}
    @Override
    public Type_fieldlist vx_type() {return t_fieldlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_field), // allowtypes
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
    public Table.Type_fieldmap vx_new(final Object... vals);
    public Table.Type_fieldmap vx_copy(final Object... vals);
    public Table.Type_fieldmap vx_empty();
    public Table.Type_fieldmap vx_type();
    public List<Table.Type_field> vx_listfield();
    public Table.Type_field vx_field(final Core.Type_int index);
  }

  public static class Class_fieldmap extends Core.Class_base implements Type_fieldmap {

    protected List<Table.Type_field> vxlist = Core.immutablelist(new ArrayList<Table.Type_field>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Table.Type_field vx_field(final Core.Type_int index) {
      Table.Type_field output = Table.e_field;
      Class_fieldmap list = this;
      int iindex = index.vx_int();
      List<Table.Type_field> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_field> vx_listfield() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_field(index);
    }

    @Override
    public Type_fieldmap vx_new(final Object... vals) {return e_fieldmap.vx_copy(vals);}

    @Override
    public Type_fieldmap vx_copy(final Object... vals) {
      Class_fieldmap output = new Class_fieldmap();
      Type_fieldmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Table.Type_field> listval = new ArrayList<>(val.vx_listfield());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Table.Type_field) {
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Table.Type_field) {
          listval.add((Table.Type_field)valsub);
        } else if (valsub instanceof Type_fieldmap) {
          Type_fieldmap multi = (Type_fieldmap)valsub;
          listval.addAll(multi.vx_listfield());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_field) {
              Table.Type_field valitem = (Table.Type_field)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new fieldmap) - Invalid Type: " + valsub.toString());
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
    public Type_fieldmap vx_empty() {return e_fieldmap;}
    @Override
    public Type_fieldmap vx_type() {return t_fieldmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_field), // allowtypes
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
    public Table.Type_filter vx_new(final Object... vals);
    public Table.Type_filter vx_copy(final Object... vals);
    public Table.Type_filter vx_empty();
    public Table.Type_filter vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_filter extends Core.Class_base implements Type_filter {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_stringlist vx_p_idlist;

    @Override
    public Core.Type_stringlist idlist() {
      return this.vx_p_idlist == null ? Core.e_stringlist : this.vx_p_idlist;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_filter vx_new(final Object... vals) {return e_filter.vx_copy(vals);}

    @Override
    public Type_filter vx_copy(final Object... vals) {
      Class_filter output = new Class_filter();
      Type_filter val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_idlist = val.idlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new filter) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new filter :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new filter :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":idlist":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_idlist = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new filter :idlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new filter) - Invalid Key: " + key);
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
    public Type_filter vx_empty() {return e_filter;}
    @Override
    public Type_filter vx_type() {return t_filter;}

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
    public Table.Type_row vx_new(final Object... vals);
    public Table.Type_row vx_copy(final Object... vals);
    public Table.Type_row vx_empty();
    public Table.Type_row vx_type();
    public Core.Type_string id();
    public Table.Type_cellmap cellmap();
    public Table.Type_sort cellsort();
  }

  public static class Class_row extends Core.Class_base implements Type_row {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Table.Type_cellmap vx_p_cellmap;

    @Override
    public Table.Type_cellmap cellmap() {
      return this.vx_p_cellmap == null ? Table.e_cellmap : this.vx_p_cellmap;
    }

    protected Table.Type_sort vx_p_cellsort;

    @Override
    public Table.Type_sort cellsort() {
      return this.vx_p_cellsort == null ? Table.e_sort : this.vx_p_cellsort;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":cellmap", this.cellmap());
      output.put(":cellsort", this.cellsort());
      return Core.immutablemap(output);
    }

    @Override
    public Type_row vx_new(final Object... vals) {return e_row.vx_copy(vals);}

    @Override
    public Type_row vx_copy(final Object... vals) {
      Class_row output = new Class_row();
      Type_row val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_cellmap = val.cellmap();
      output.vx_p_cellsort = val.cellsort();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":cellmap");
      validkeys.add(":cellsort");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new row) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new row :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":cellmap":
            if (valsub instanceof Table.Type_cellmap) {
              output.vx_p_cellmap = (Table.Type_cellmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new row :cellmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":cellsort":
            if (valsub instanceof Table.Type_sort) {
              output.vx_p_cellsort = (Table.Type_sort)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new row :cellsort " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new row) - Invalid Key: " + key);
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
    public Type_row vx_empty() {return e_row;}
    @Override
    public Type_row vx_type() {return t_row;}

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
    public Table.Type_rowlist vx_new(final Object... vals);
    public Table.Type_rowlist vx_copy(final Object... vals);
    public Table.Type_rowlist vx_empty();
    public Table.Type_rowlist vx_type();
    public List<Table.Type_row> vx_listrow();
    public Table.Type_row vx_row(final Core.Type_int index);
  }

  public static class Class_rowlist extends Core.Class_base implements Type_rowlist {

    protected List<Table.Type_row> vxlist = Core.immutablelist(new ArrayList<Table.Type_row>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Table.Type_row vx_row(final Core.Type_int index) {
      Table.Type_row output = Table.e_row;
      Class_rowlist list = this;
      int iindex = index.vx_int();
      List<Table.Type_row> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Table.Type_row> vx_listrow() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_row(index);
    }

    @Override
    public Type_rowlist vx_new(final Object... vals) {return e_rowlist.vx_copy(vals);}

    @Override
    public Type_rowlist vx_copy(final Object... vals) {
      Class_rowlist output = new Class_rowlist();
      Type_rowlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Table.Type_row> listval = new ArrayList<>(val.vx_listrow());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Table.Type_row) {
          listval.add((Table.Type_row)valsub);
        } else if (valsub instanceof Table.Type_row) {
          listval.add((Table.Type_row)valsub);
        } else if (valsub instanceof Type_rowlist) {
          Type_rowlist multi = (Type_rowlist)valsub;
          listval.addAll(multi.vx_listrow());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Table.Type_row) {
              Table.Type_row valitem = (Table.Type_row)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new rowlist) - Invalid Type: " + valsub.toString());
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
    public Type_rowlist vx_empty() {return e_rowlist;}
    @Override
    public Type_rowlist vx_type() {return t_rowlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_row), // allowtypes
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
    public Table.Type_rowmap vx_new(final Object... vals);
    public Table.Type_rowmap vx_copy(final Object... vals);
    public Table.Type_rowmap vx_empty();
    public Table.Type_rowmap vx_type();
    public Map<String, Table.Type_row> vx_maprow();
    public Table.Type_row vx_row(final Core.Type_string key);
  }

  public static class Class_rowmap extends Core.Class_base implements Type_rowmap {

    protected Map<String, Table.Type_row> vxmap = Core.immutablemap(new LinkedHashMap<String, Table.Type_row>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}

    @Override
    public Table.Type_row vx_row(final Core.Type_string key) {
      Table.Type_row output = Table.e_row;
      Class_rowmap map = this;
      String skey = key.vx_string();
      Map<String, Table.Type_row> mapval = map.vxmap;
      output = mapval.getOrDefault(skey, Table.e_row);
      return output;
    }

    @Override
    public Map<String, Table.Type_row> vx_maprow() {return vxmap;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_row(key);
    }

    @Override
    public Type_rowmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_rowmap output = new Class_rowmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Table.Type_row> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Table.Type_row) {
          Table.Type_row castval = (Table.Type_row)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(rowmap) Invalid Value: " + val.toString() + "");
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
    public Type_rowmap vx_new(final Object... vals) {return e_rowmap.vx_copy(vals);}

    @Override
    public Type_rowmap vx_copy(final Object... vals) {
      Class_rowmap output = new Class_rowmap();
      Type_rowmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Table.Type_row> mapval = new LinkedHashMap<>(valmap.vx_maprow());
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
          Table.Type_row valany = null;
          if (valsub instanceof Table.Type_row) {
            valany = (Table.Type_row)valsub;
          } else if (valsub instanceof Table.Type_row) {
            valany = (Table.Type_row)valsub;
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
    public Type_rowmap vx_empty() {return e_rowmap;}
    @Override
    public Type_rowmap vx_type() {return t_rowmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Table.t_row), // allowtypes
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
    public Table.Type_sort vx_new(final Object... vals);
    public Table.Type_sort vx_copy(final Object... vals);
    public Table.Type_sort vx_empty();
    public Table.Type_sort vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_stringlist idlist();
  }

  public static class Class_sort extends Core.Class_base implements Type_sort {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_stringlist vx_p_idlist;

    @Override
    public Core.Type_stringlist idlist() {
      return this.vx_p_idlist == null ? Core.e_stringlist : this.vx_p_idlist;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_sort vx_new(final Object... vals) {return e_sort.vx_copy(vals);}

    @Override
    public Type_sort vx_copy(final Object... vals) {
      Class_sort output = new Class_sort();
      Type_sort val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_idlist = val.idlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":idlist");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new sort) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new sort :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new sort :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":idlist":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_idlist = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new sort :idlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new sort) - Invalid Key: " + key);
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
    public Type_sort vx_empty() {return e_sort;}
    @Override
    public Type_sort vx_type() {return t_sort;}

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
    public Table.Type_table vx_new(final Object... vals);
    public Table.Type_table vx_copy(final Object... vals);
    public Table.Type_table vx_empty();
    public Table.Type_table vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Table.Type_fieldmap fieldmap();
    public Table.Type_sort fieldsort();
    public Table.Type_rowmap rowmap();
    public Table.Type_filter rowfilter();
    public Table.Type_sort rowsort();
  }

  public static class Class_table extends Core.Class_base implements Type_table {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Table.Type_fieldmap vx_p_fieldmap;

    @Override
    public Table.Type_fieldmap fieldmap() {
      return this.vx_p_fieldmap == null ? Table.e_fieldmap : this.vx_p_fieldmap;
    }

    protected Table.Type_sort vx_p_fieldsort;

    @Override
    public Table.Type_sort fieldsort() {
      return this.vx_p_fieldsort == null ? Table.e_sort : this.vx_p_fieldsort;
    }

    protected Table.Type_rowmap vx_p_rowmap;

    @Override
    public Table.Type_rowmap rowmap() {
      return this.vx_p_rowmap == null ? Table.e_rowmap : this.vx_p_rowmap;
    }

    protected Table.Type_filter vx_p_rowfilter;

    @Override
    public Table.Type_filter rowfilter() {
      return this.vx_p_rowfilter == null ? Table.e_filter : this.vx_p_rowfilter;
    }

    protected Table.Type_sort vx_p_rowsort;

    @Override
    public Table.Type_sort rowsort() {
      return this.vx_p_rowsort == null ? Table.e_sort : this.vx_p_rowsort;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
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
    public Type_table vx_new(final Object... vals) {return e_table.vx_copy(vals);}

    @Override
    public Type_table vx_copy(final Object... vals) {
      Class_table output = new Class_table();
      Type_table val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_fieldmap = val.fieldmap();
      output.vx_p_fieldsort = val.fieldsort();
      output.vx_p_rowmap = val.rowmap();
      output.vx_p_rowfilter = val.rowfilter();
      output.vx_p_rowsort = val.rowsort();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":fieldmap");
      validkeys.add(":fieldsort");
      validkeys.add(":rowmap");
      validkeys.add(":rowfilter");
      validkeys.add(":rowsort");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new table) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fieldmap":
            if (valsub instanceof Table.Type_fieldmap) {
              output.vx_p_fieldmap = (Table.Type_fieldmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :fieldmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fieldsort":
            if (valsub instanceof Table.Type_sort) {
              output.vx_p_fieldsort = (Table.Type_sort)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :fieldsort " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rowmap":
            if (valsub instanceof Table.Type_rowmap) {
              output.vx_p_rowmap = (Table.Type_rowmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :rowmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rowfilter":
            if (valsub instanceof Table.Type_filter) {
              output.vx_p_rowfilter = (Table.Type_filter)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :rowfilter " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rowsort":
            if (valsub instanceof Table.Type_sort) {
              output.vx_p_rowsort = (Table.Type_sort)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new table :rowsort " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new table) - Invalid Key: " + key);
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
    public Type_table vx_empty() {return e_table;}
    @Override
    public Type_table vx_type() {return t_table;}

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

}
