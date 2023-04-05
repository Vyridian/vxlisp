package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;


public final class Db {


  /**
   * type: db
   * Database trait
   * (type db)
   */
  public interface Type_db extends Core.Type_struct {
    public Db.Type_db vx_new(final Object... vals);
    public Db.Type_db vx_copy(final Object... vals);
    public Db.Type_db vx_empty();
    public Db.Type_db vx_type();
    public Core.Type_string dbid();
  }

  public static class Class_db extends Core.Class_base implements Type_db {

    protected Core.Type_string vx_p_dbid;

    @Override
    public Core.Type_string dbid() {
      return this.vx_p_dbid == null ? Core.e_string : this.vx_p_dbid;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbid":
        output = this.dbid();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":dbid", this.dbid());
      return Core.immutablemap(output);
    }

    @Override
    public Type_db vx_new(final Object... vals) {return e_db.vx_copy(vals);}

    @Override
    public Type_db vx_copy(final Object... vals) {
      Class_db output = new Class_db();
      Type_db val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_dbid = val.dbid();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbid");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new db) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_dbid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_dbid = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new db :dbid " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new db) - Invalid Key: " + key);
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
    public Type_db vx_empty() {return e_db;}
    @Override
    public Type_db vx_type() {return t_db;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "db", // name
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

  public static final Type_db e_db = new Class_db();
  public static final Type_db t_db = new Class_db();

  /**
   * type: dbcell
   * Database Cell trait
   * (type dbcell)
   */
  public interface Type_dbcell extends Core.Type_struct {
    public Db.Type_dbcell vx_new(final Object... vals);
    public Db.Type_dbcell vx_copy(final Object... vals);
    public Db.Type_dbcell vx_empty();
    public Db.Type_dbcell vx_type();
    public Core.Type_string dbcellid();
    public Db.Type_dbcellmap dbcellmap();
    public Db.Type_dbfieldmap dbfieldmap();
    public Db.Type_dbcell dbparent();
    public Db.Type_dbtable dbtable();
  }

  public static class Class_dbcell extends Core.Class_base implements Type_dbcell {

    protected Core.Type_string vx_p_dbcellid;

    @Override
    public Core.Type_string dbcellid() {
      return this.vx_p_dbcellid == null ? Core.e_string : this.vx_p_dbcellid;
    }

    protected Db.Type_dbcellmap vx_p_dbcellmap;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      return this.vx_p_dbcellmap == null ? Db.e_dbcellmap : this.vx_p_dbcellmap;
    }

    protected Db.Type_dbfieldmap vx_p_dbfieldmap;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      return this.vx_p_dbfieldmap == null ? Db.e_dbfieldmap : this.vx_p_dbfieldmap;
    }

    protected Db.Type_dbcell vx_p_dbparent;

    @Override
    public Db.Type_dbcell dbparent() {
      return this.vx_p_dbparent == null ? Db.e_dbcell : this.vx_p_dbparent;
    }

    protected Db.Type_dbtable vx_p_dbtable;

    @Override
    public Db.Type_dbtable dbtable() {
      return this.vx_p_dbtable == null ? Db.e_dbtable : this.vx_p_dbtable;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbcellid":
        output = this.dbcellid();
        break;
      case ":dbcellmap":
        output = this.dbcellmap();
        break;
      case ":dbfieldmap":
        output = this.dbfieldmap();
        break;
      case ":dbparent":
        output = this.dbparent();
        break;
      case ":dbtable":
        output = this.dbtable();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":dbcellid", this.dbcellid());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      output.put(":dbparent", this.dbparent());
      output.put(":dbtable", this.dbtable());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbcell vx_new(final Object... vals) {return e_dbcell.vx_copy(vals);}

    @Override
    public Type_dbcell vx_copy(final Object... vals) {
      Class_dbcell output = new Class_dbcell();
      Type_dbcell val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_dbcellid = val.dbcellid();
      output.vx_p_dbcellmap = val.dbcellmap();
      output.vx_p_dbfieldmap = val.dbfieldmap();
      output.vx_p_dbparent = val.dbparent();
      output.vx_p_dbtable = val.dbtable();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbcellid");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
      validkeys.add(":dbparent");
      validkeys.add(":dbtable");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":dbcellid":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_dbcellid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_dbcellid = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell :dbcellid " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbcellmap":
            if (valsub instanceof Db.Type_dbcellmap) {
              output.vx_p_dbcellmap = (Db.Type_dbcellmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell :dbcellmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub instanceof Db.Type_dbfieldmap) {
              output.vx_p_dbfieldmap = (Db.Type_dbfieldmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell :dbfieldmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbparent":
            if (valsub instanceof Db.Type_dbcell) {
              output.vx_p_dbparent = (Db.Type_dbcell)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell :dbparent " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbtable":
            if (valsub instanceof Db.Type_dbtable) {
              output.vx_p_dbtable = (Db.Type_dbtable)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell :dbtable " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbcell) - Invalid Key: " + key);
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
    public Type_dbcell vx_empty() {return e_dbcell;}
    @Override
    public Type_dbcell vx_type() {return t_dbcell;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbcell", // name
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

  public static final Type_dbcell e_dbcell = new Class_dbcell();
  public static final Type_dbcell t_dbcell = new Class_dbcell();

  /**
   * type: dbcellmap
   * Database Cell Map
   * (type dbcellmap)
   */
  public interface Type_dbcellmap extends Core.Type_map {
    public Db.Type_dbcellmap vx_new(final Object... vals);
    public Db.Type_dbcellmap vx_copy(final Object... vals);
    public Db.Type_dbcellmap vx_empty();
    public Db.Type_dbcellmap vx_type();
    public Map<String, Db.Type_dbcell> vx_mapdbcell();
    public Db.Type_dbcell vx_dbcell(final Core.Type_string key);
  }

  public static class Class_dbcellmap extends Core.Class_base implements Type_dbcellmap {

    protected Map<String, Db.Type_dbcell> vxmap = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbcell>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}

    @Override
    public Db.Type_dbcell vx_dbcell(final Core.Type_string key) {
      Db.Type_dbcell output = Db.e_dbcell;
      Class_dbcellmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbcell> mapval = map.vxmap;
      output = mapval.getOrDefault(skey, Db.e_dbcell);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbcell> vx_mapdbcell() {return vxmap;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_dbcell(key);
    }

    @Override
    public Type_dbcellmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_dbcellmap output = new Class_dbcellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbcell> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Db.Type_dbcell) {
          Db.Type_dbcell castval = (Db.Type_dbcell)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(dbcellmap) Invalid Value: " + val.toString() + "");
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
    public Type_dbcellmap vx_new(final Object... vals) {return e_dbcellmap.vx_copy(vals);}

    @Override
    public Type_dbcellmap vx_copy(final Object... vals) {
      Class_dbcellmap output = new Class_dbcellmap();
      Type_dbcellmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Db.Type_dbcell> mapval = new LinkedHashMap<>(valmap.vx_mapdbcell());
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
          Db.Type_dbcell valany = null;
          if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
          } else if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
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
    public Type_dbcellmap vx_empty() {return e_dbcellmap;}
    @Override
    public Type_dbcellmap vx_type() {return t_dbcellmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Db.t_dbcell), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_dbcellmap e_dbcellmap = new Class_dbcellmap();
  public static final Type_dbcellmap t_dbcellmap = new Class_dbcellmap();

  /**
   * type: dbfield
   * Database Field trait
   * (type dbfield)
   */
  public interface Type_dbfield extends Core.Type_struct {
    public Db.Type_dbfield vx_new(final Object... vals);
    public Db.Type_dbfield vx_copy(final Object... vals);
    public Db.Type_dbfield vx_empty();
    public Db.Type_dbfield vx_type();
    public Core.Type_string dbfieldid();
    public Core.Type_any type();
    public Core.Type_any value();
  }

  public static class Class_dbfield extends Core.Class_base implements Type_dbfield {

    protected Core.Type_string vx_p_dbfieldid;

    @Override
    public Core.Type_string dbfieldid() {
      return this.vx_p_dbfieldid == null ? Core.e_string : this.vx_p_dbfieldid;
    }

    protected Core.Type_any vx_p_type;

    @Override
    public Core.Type_any type() {
      return this.vx_p_type == null ? Core.e_any : this.vx_p_type;
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
      case ":dbfieldid":
        output = this.dbfieldid();
        break;
      case ":type":
        output = this.type();
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
      output.put(":dbfieldid", this.dbfieldid());
      output.put(":type", this.type());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbfield vx_new(final Object... vals) {return e_dbfield.vx_copy(vals);}

    @Override
    public Type_dbfield vx_copy(final Object... vals) {
      Class_dbfield output = new Class_dbfield();
      Type_dbfield val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_dbfieldid = val.dbfieldid();
      output.vx_p_type = val.type();
      output.vx_p_value = val.value();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbfieldid");
      validkeys.add(":type");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbfield) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":dbfieldid":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_dbfieldid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_dbfieldid = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbfield :dbfieldid " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":type":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_type = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbfield :type " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_value = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbfield :value " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbfield) - Invalid Key: " + key);
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
    public Type_dbfield vx_empty() {return e_dbfield;}
    @Override
    public Type_dbfield vx_type() {return t_dbfield;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbfield", // name
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

  public static final Type_dbfield e_dbfield = new Class_dbfield();
  public static final Type_dbfield t_dbfield = new Class_dbfield();

  /**
   * type: dbfieldmap
   * Database Field Map
   * (type dbfieldmap)
   */
  public interface Type_dbfieldmap extends Core.Type_map {
    public Db.Type_dbfieldmap vx_new(final Object... vals);
    public Db.Type_dbfieldmap vx_copy(final Object... vals);
    public Db.Type_dbfieldmap vx_empty();
    public Db.Type_dbfieldmap vx_type();
    public Map<String, Db.Type_dbfield> vx_mapdbfield();
    public Db.Type_dbfield vx_dbfield(final Core.Type_string key);
  }

  public static class Class_dbfieldmap extends Core.Class_base implements Type_dbfieldmap {

    protected Map<String, Db.Type_dbfield> vxmap = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbfield>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}

    @Override
    public Db.Type_dbfield vx_dbfield(final Core.Type_string key) {
      Db.Type_dbfield output = Db.e_dbfield;
      Class_dbfieldmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbfield> mapval = map.vxmap;
      output = mapval.getOrDefault(skey, Db.e_dbfield);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbfield> vx_mapdbfield() {return vxmap;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_dbfield(key);
    }

    @Override
    public Type_dbfieldmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_dbfieldmap output = new Class_dbfieldmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbfield> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Db.Type_dbfield) {
          Db.Type_dbfield castval = (Db.Type_dbfield)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(dbfieldmap) Invalid Value: " + val.toString() + "");
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
    public Type_dbfieldmap vx_new(final Object... vals) {return e_dbfieldmap.vx_copy(vals);}

    @Override
    public Type_dbfieldmap vx_copy(final Object... vals) {
      Class_dbfieldmap output = new Class_dbfieldmap();
      Type_dbfieldmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Db.Type_dbfield> mapval = new LinkedHashMap<>(valmap.vx_mapdbfield());
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
          Db.Type_dbfield valany = null;
          if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
          } else if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
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
    public Type_dbfieldmap vx_empty() {return e_dbfieldmap;}
    @Override
    public Type_dbfieldmap vx_type() {return t_dbfieldmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Db.t_dbfield), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_dbfieldmap e_dbfieldmap = new Class_dbfieldmap();
  public static final Type_dbfieldmap t_dbfieldmap = new Class_dbfieldmap();

  /**
   * type: dbtable
   * Database Table trait
   * (type dbtable)
   */
  public interface Type_dbtable extends Core.Type_struct {
    public Db.Type_dbtable vx_new(final Object... vals);
    public Db.Type_dbtable vx_copy(final Object... vals);
    public Db.Type_dbtable vx_empty();
    public Db.Type_dbtable vx_type();
    public Core.Type_string dbtableid();
    public Db.Type_db db();
    public Db.Type_dbcellmap dbcellmap();
    public Db.Type_dbfieldmap dbfieldmap();
  }

  public static class Class_dbtable extends Core.Class_base implements Type_dbtable {

    protected Core.Type_string vx_p_dbtableid;

    @Override
    public Core.Type_string dbtableid() {
      return this.vx_p_dbtableid == null ? Core.e_string : this.vx_p_dbtableid;
    }

    protected Db.Type_db vx_p_db;

    @Override
    public Db.Type_db db() {
      return this.vx_p_db == null ? Db.e_db : this.vx_p_db;
    }

    protected Db.Type_dbcellmap vx_p_dbcellmap;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      return this.vx_p_dbcellmap == null ? Db.e_dbcellmap : this.vx_p_dbcellmap;
    }

    protected Db.Type_dbfieldmap vx_p_dbfieldmap;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      return this.vx_p_dbfieldmap == null ? Db.e_dbfieldmap : this.vx_p_dbfieldmap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbtableid":
        output = this.dbtableid();
        break;
      case ":db":
        output = this.db();
        break;
      case ":dbcellmap":
        output = this.dbcellmap();
        break;
      case ":dbfieldmap":
        output = this.dbfieldmap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":dbtableid", this.dbtableid());
      output.put(":db", this.db());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbtable vx_new(final Object... vals) {return e_dbtable.vx_copy(vals);}

    @Override
    public Type_dbtable vx_copy(final Object... vals) {
      Class_dbtable output = new Class_dbtable();
      Type_dbtable val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_dbtableid = val.dbtableid();
      output.vx_p_db = val.db();
      output.vx_p_dbcellmap = val.dbcellmap();
      output.vx_p_dbfieldmap = val.dbfieldmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbtableid");
      validkeys.add(":db");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":dbtableid":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_dbtableid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_dbtableid = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable :dbtableid " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":db":
            if (valsub instanceof Db.Type_db) {
              output.vx_p_db = (Db.Type_db)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable :db " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbcellmap":
            if (valsub instanceof Db.Type_dbcellmap) {
              output.vx_p_dbcellmap = (Db.Type_dbcellmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable :dbcellmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub instanceof Db.Type_dbfieldmap) {
              output.vx_p_dbfieldmap = (Db.Type_dbfieldmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable :dbfieldmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new dbtable) - Invalid Key: " + key);
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
    public Type_dbtable vx_empty() {return e_dbtable;}
    @Override
    public Type_dbtable vx_type() {return t_dbtable;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbtable", // name
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

  public static final Type_dbtable e_dbtable = new Class_dbtable();
  public static final Type_dbtable t_dbtable = new Class_dbtable();

}
