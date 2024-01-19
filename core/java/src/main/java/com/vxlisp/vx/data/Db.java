package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
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
      Type_db output = this;
      boolean ischanged = false;
      Class_db val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbid = val.dbid();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbid");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new db) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new db) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_dbid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbid = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new db :dbid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new db) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_db work = new Class_db();
        work.vx_p_dbid = vx_p_dbid;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
      Type_dbcell output = this;
      boolean ischanged = false;
      Class_dbcell val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbcellid = val.dbcellid();
      Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      Db.Type_dbcell vx_p_dbparent = val.dbparent();
      Db.Type_dbtable vx_p_dbtable = val.dbtable();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbcellid");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
      validkeys.add(":dbparent");
      validkeys.add(":dbtable");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbcell) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbcell) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbcellid":
            if (valsub == vx_p_dbcellid) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_dbcellid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbcellid = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbcell :dbcellid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = (Db.Type_dbcellmap)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbcell :dbcellmap " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = (Db.Type_dbfieldmap)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbcell :dbfieldmap " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbparent":
            if (valsub == vx_p_dbparent) {
            } else if (valsub instanceof Db.Type_dbcell) {
              ischanged = true;
              vx_p_dbparent = (Db.Type_dbcell)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbcell :dbparent " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbtable":
            if (valsub == vx_p_dbtable) {
            } else if (valsub instanceof Db.Type_dbtable) {
              ischanged = true;
              vx_p_dbtable = (Db.Type_dbtable)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbcell :dbtable " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbcell) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbcell work = new Class_dbcell();
        work.vx_p_dbcellid = vx_p_dbcellid;
        work.vx_p_dbcellmap = vx_p_dbcellmap;
        work.vx_p_dbfieldmap = vx_p_dbfieldmap;
        work.vx_p_dbparent = vx_p_dbparent;
        work.vx_p_dbtable = vx_p_dbtable;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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

    protected Map<String, Db.Type_dbcell> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbcell>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Db.Type_dbcell vx_dbcell(final Core.Type_string key) {
      Db.Type_dbcell output = Db.e_dbcell;
      Class_dbcellmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbcell> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Db.e_dbcell);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbcell> vx_mapdbcell() {return vx_p_map;}

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
          Core.Type_msg msg = Core.vx_msg_from_error("(dbcellmap) Invalid Value: " + val.toString() + "");
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
    public Type_dbcellmap vx_new(final Object... vals) {return e_dbcellmap.vx_copy(vals);}

    @Override
    public Type_dbcellmap vx_copy(final Object... vals) {
      Type_dbcellmap output = this;
      boolean ischanged = false;
      Class_dbcellmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Db.Type_dbcell> mapval = new LinkedHashMap<>(val.vx_mapdbcell());
      Core.Type_msg msg;
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
            msg = Core.vx_msg_from_error(":keyexpected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbcell valany = null;
          if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
          } else if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
          } else {
            msg = Core.vx_msg_from_error(":invalidkeyvalue: " + key + " "  + valsub.toString() + "");
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
        Class_dbcellmap work = new Class_dbcellmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
      Type_dbfield output = this;
      boolean ischanged = false;
      Class_dbfield val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbfieldid = val.dbfieldid();
      Core.Type_any vx_p_type = val.type();
      Core.Type_any vx_p_value = val.value();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbfieldid");
      validkeys.add(":type");
      validkeys.add(":value");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbfield) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbfield) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbfieldid":
            if (valsub == vx_p_dbfieldid) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_dbfieldid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbfieldid = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbfield :dbfieldid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_type = (Core.Type_any)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbfield :type " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_value = (Core.Type_any)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbfield :value " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbfield) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbfield work = new Class_dbfield();
        work.vx_p_dbfieldid = vx_p_dbfieldid;
        work.vx_p_type = vx_p_type;
        work.vx_p_value = vx_p_value;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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

    protected Map<String, Db.Type_dbfield> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbfield>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Db.Type_dbfield vx_dbfield(final Core.Type_string key) {
      Db.Type_dbfield output = Db.e_dbfield;
      Class_dbfieldmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbfield> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Db.e_dbfield);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbfield> vx_mapdbfield() {return vx_p_map;}

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
          Core.Type_msg msg = Core.vx_msg_from_error("(dbfieldmap) Invalid Value: " + val.toString() + "");
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
    public Type_dbfieldmap vx_new(final Object... vals) {return e_dbfieldmap.vx_copy(vals);}

    @Override
    public Type_dbfieldmap vx_copy(final Object... vals) {
      Type_dbfieldmap output = this;
      boolean ischanged = false;
      Class_dbfieldmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Db.Type_dbfield> mapval = new LinkedHashMap<>(val.vx_mapdbfield());
      Core.Type_msg msg;
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
            msg = Core.vx_msg_from_error(":keyexpected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbfield valany = null;
          if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
          } else if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
          } else {
            msg = Core.vx_msg_from_error(":invalidkeyvalue: " + key + " "  + valsub.toString() + "");
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
        Class_dbfieldmap work = new Class_dbfieldmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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
   * type: dbid
   * Database id
   * (type dbid)
   */
  public interface Type_dbid extends Core.Type_any {
    public Db.Type_dbid vx_new(final Object... vals);
    public Db.Type_dbid vx_copy(final Object... vals);
    public Db.Type_dbid vx_empty();
    public Db.Type_dbid vx_type();
  }

  public static class Class_dbid extends Core.Class_base implements Type_dbid {

    @Override
    public Type_dbid vx_new(final Object... vals) {return e_dbid.vx_copy(vals);}

    @Override
    public Type_dbid vx_copy(final Object... vals) {
      Type_dbid output = this;
      boolean ischanged = false;
      Class_dbid val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbid work = new Class_dbid();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dbid vx_empty() {return e_dbid;}
    @Override
    public Type_dbid vx_type() {return t_dbid;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbid", // name
        ":string", // extends
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

  public static final Type_dbid e_dbid = new Class_dbid();
  public static final Type_dbid t_dbid = new Class_dbid();

  /**
   * type: dblink
   * Database link
   * (type dblink)
   */
  public interface Type_dblink extends Core.Type_struct {
    public Db.Type_dblink vx_new(final Object... vals);
    public Db.Type_dblink vx_copy(final Object... vals);
    public Db.Type_dblink vx_empty();
    public Db.Type_dblink vx_type();
    public Db.Type_dbid fromid();
    public Db.Type_dbid toid();
  }

  public static class Class_dblink extends Core.Class_base implements Type_dblink {

    protected Db.Type_dbid vx_p_fromid;

    @Override
    public Db.Type_dbid fromid() {
      return this.vx_p_fromid == null ? Db.e_dbid : this.vx_p_fromid;
    }

    protected Db.Type_dbid vx_p_toid;

    @Override
    public Db.Type_dbid toid() {
      return this.vx_p_toid == null ? Db.e_dbid : this.vx_p_toid;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":fromid":
        output = this.fromid();
        break;
      case ":toid":
        output = this.toid();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dblink vx_new(final Object... vals) {return e_dblink.vx_copy(vals);}

    @Override
    public Type_dblink vx_copy(final Object... vals) {
      Type_dblink output = this;
      boolean ischanged = false;
      Class_dblink val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_fromid = val.fromid();
      Db.Type_dbid vx_p_toid = val.toid();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":fromid");
      validkeys.add(":toid");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dblink) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dblink) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_fromid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dblink :fromid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_toid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dblink :toid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dblink) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dblink work = new Class_dblink();
        work.vx_p_fromid = vx_p_fromid;
        work.vx_p_toid = vx_p_toid;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dblink vx_empty() {return e_dblink;}
    @Override
    public Type_dblink vx_type() {return t_dblink;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dblink", // name
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

  public static final Type_dblink e_dblink = new Class_dblink();
  public static final Type_dblink t_dblink = new Class_dblink();

  /**
   * type: dblinklist
   * Database link
   * (type dblinklist)
   */
  public interface Type_dblinklist extends Core.Type_list {
    public Db.Type_dblinklist vx_new(final Object... vals);
    public Db.Type_dblinklist vx_copy(final Object... vals);
    public Db.Type_dblinklist vx_empty();
    public Db.Type_dblinklist vx_type();
    public List<Db.Type_dblink> vx_listdblink();
    public Db.Type_dblink vx_dblink(final Core.Type_int index);
  }

  public static class Class_dblinklist extends Core.Class_base implements Type_dblinklist {

    protected List<Db.Type_dblink> vx_p_list = Core.immutablelist(new ArrayList<Db.Type_dblink>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Db.Type_dblink vx_dblink(final Core.Type_int index) {
      Db.Type_dblink output = Db.e_dblink;
      Class_dblinklist list = this;
      int iindex = index.vx_int();
      List<Db.Type_dblink> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Db.Type_dblink> vx_listdblink() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_dblink(index);
    }

    @Override
    public Type_dblinklist vx_new(final Object... vals) {return e_dblinklist.vx_copy(vals);}

    @Override
    public Type_dblinklist vx_copy(final Object... vals) {
      Type_dblinklist output = this;
      boolean ischanged = false;
      Class_dblinklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Db.Type_dblink> listval = new ArrayList<>(val.vx_listdblink());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Db.Type_dblink) {
          ischanged = true;
          listval.add((Db.Type_dblink)valsub);
        } else if (valsub instanceof Db.Type_dblink) {
          ischanged = true;
          listval.add((Db.Type_dblink)valsub);
        } else if (valsub instanceof Type_dblinklist) {
          Type_dblinklist multi = (Type_dblinklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdblink());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Db.Type_dblink) {
              Db.Type_dblink valitem = (Db.Type_dblink)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", "invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", "invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dblinklist work = new Class_dblinklist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dblinklist vx_empty() {return e_dblinklist;}
    @Override
    public Type_dblinklist vx_type() {return t_dblinklist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dblinklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Db.t_dblink), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_dblinklist e_dblinklist = new Class_dblinklist();
  public static final Type_dblinklist t_dblinklist = new Class_dblinklist();

  /**
   * type: dbnode
   * Database node
   * (type dbnode)
   */
  public interface Type_dbnode extends Core.Type_struct {
    public Db.Type_dbnode vx_new(final Object... vals);
    public Db.Type_dbnode vx_copy(final Object... vals);
    public Db.Type_dbnode vx_empty();
    public Db.Type_dbnode vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dblinklist links();
  }

  public static class Class_dbnode extends Core.Class_base implements Type_dbnode {

    protected Db.Type_dbid vx_p_dbid;

    @Override
    public Db.Type_dbid dbid() {
      return this.vx_p_dbid == null ? Db.e_dbid : this.vx_p_dbid;
    }

    protected Db.Type_dblinklist vx_p_links;

    @Override
    public Db.Type_dblinklist links() {
      return this.vx_p_links == null ? Db.e_dblinklist : this.vx_p_links;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbid":
        output = this.dbid();
        break;
      case ":links":
        output = this.links();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":dbid", this.dbid());
      output.put(":links", this.links());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbnode vx_new(final Object... vals) {return e_dbnode.vx_copy(vals);}

    @Override
    public Type_dbnode vx_copy(final Object... vals) {
      Type_dbnode output = this;
      boolean ischanged = false;
      Class_dbnode val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dblinklist vx_p_links = val.links();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbid");
      validkeys.add(":links");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbnode) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbnode) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_dbid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnode :dbid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":links":
            if (valsub == vx_p_links) {
            } else if (valsub instanceof Db.Type_dblinklist) {
              ischanged = true;
              vx_p_links = (Db.Type_dblinklist)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnode :links " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbnode) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbnode work = new Class_dbnode();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_links = vx_p_links;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dbnode vx_empty() {return e_dbnode;}
    @Override
    public Type_dbnode vx_type() {return t_dbnode;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbnode", // name
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

  public static final Type_dbnode e_dbnode = new Class_dbnode();
  public static final Type_dbnode t_dbnode = new Class_dbnode();

  /**
   * type: dbnote
   * Database Value
   * (type dbnote)
   */
  public interface Type_dbnote extends Core.Type_struct {
    public Db.Type_dbnote vx_new(final Object... vals);
    public Db.Type_dbnote vx_copy(final Object... vals);
    public Db.Type_dbnote vx_empty();
    public Db.Type_dbnote vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dbid valid();
    public Db.Type_dbid noteid();
    public Db.Type_dbid valueid();
    public Core.Type_string value();
  }

  public static class Class_dbnote extends Core.Class_base implements Type_dbnote {

    protected Db.Type_dbid vx_p_dbid;

    @Override
    public Db.Type_dbid dbid() {
      return this.vx_p_dbid == null ? Db.e_dbid : this.vx_p_dbid;
    }

    protected Db.Type_dbid vx_p_valid;

    @Override
    public Db.Type_dbid valid() {
      return this.vx_p_valid == null ? Db.e_dbid : this.vx_p_valid;
    }

    protected Db.Type_dbid vx_p_noteid;

    @Override
    public Db.Type_dbid noteid() {
      return this.vx_p_noteid == null ? Db.e_dbid : this.vx_p_noteid;
    }

    protected Db.Type_dbid vx_p_valueid;

    @Override
    public Db.Type_dbid valueid() {
      return this.vx_p_valueid == null ? Db.e_dbid : this.vx_p_valueid;
    }

    protected Core.Type_string vx_p_value;

    @Override
    public Core.Type_string value() {
      return this.vx_p_value == null ? Core.e_string : this.vx_p_value;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbid":
        output = this.dbid();
        break;
      case ":valid":
        output = this.valid();
        break;
      case ":noteid":
        output = this.noteid();
        break;
      case ":valueid":
        output = this.valueid();
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
      output.put(":dbid", this.dbid());
      output.put(":valid", this.valid());
      output.put(":noteid", this.noteid());
      output.put(":valueid", this.valueid());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbnote vx_new(final Object... vals) {return e_dbnote.vx_copy(vals);}

    @Override
    public Type_dbnote vx_copy(final Object... vals) {
      Type_dbnote output = this;
      boolean ischanged = false;
      Class_dbnote val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dbid vx_p_valid = val.valid();
      Db.Type_dbid vx_p_noteid = val.noteid();
      Db.Type_dbid vx_p_valueid = val.valueid();
      Core.Type_string vx_p_value = val.value();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbid");
      validkeys.add(":valid");
      validkeys.add(":noteid");
      validkeys.add(":valueid");
      validkeys.add(":value");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbnote) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbnote) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_dbid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnote :dbid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_valid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnote :valid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_noteid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnote :noteid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":valueid":
            if (valsub == vx_p_valueid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_valueid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnote :valueid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_value = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_value = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbnote :value " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbnote) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbnote work = new Class_dbnote();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_valid = vx_p_valid;
        work.vx_p_noteid = vx_p_noteid;
        work.vx_p_valueid = vx_p_valueid;
        work.vx_p_value = vx_p_value;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dbnote vx_empty() {return e_dbnote;}
    @Override
    public Type_dbnote vx_type() {return t_dbnote;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbnote", // name
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

  public static final Type_dbnote e_dbnote = new Class_dbnote();
  public static final Type_dbnote t_dbnote = new Class_dbnote();

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
      Type_dbtable output = this;
      boolean ischanged = false;
      Class_dbtable val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbtableid = val.dbtableid();
      Db.Type_db vx_p_db = val.db();
      Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbtableid");
      validkeys.add(":db");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbtable) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbtable) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbtableid":
            if (valsub == vx_p_dbtableid) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_dbtableid = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbtableid = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbtable :dbtableid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":db":
            if (valsub == vx_p_db) {
            } else if (valsub instanceof Db.Type_db) {
              ischanged = true;
              vx_p_db = (Db.Type_db)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbtable :db " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = (Db.Type_dbcellmap)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbtable :dbcellmap " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = (Db.Type_dbfieldmap)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbtable :dbfieldmap " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbtable) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbtable work = new Class_dbtable();
        work.vx_p_dbtableid = vx_p_dbtableid;
        work.vx_p_db = vx_p_db;
        work.vx_p_dbcellmap = vx_p_dbcellmap;
        work.vx_p_dbfieldmap = vx_p_dbfieldmap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
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

  /**
   * type: dbvalue
   * Database Value
   * (type dbvalue)
   */
  public interface Type_dbvalue extends Core.Type_struct {
    public Db.Type_dbvalue vx_new(final Object... vals);
    public Db.Type_dbvalue vx_copy(final Object... vals);
    public Db.Type_dbvalue vx_empty();
    public Db.Type_dbvalue vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dbid fromid();
    public Db.Type_dbid toid();
    public Db.Type_dbid noteid();
    public Db.Type_dbid valid();
    public Core.Type_string valtext();
  }

  public static class Class_dbvalue extends Core.Class_base implements Type_dbvalue {

    protected Db.Type_dbid vx_p_dbid;

    @Override
    public Db.Type_dbid dbid() {
      return this.vx_p_dbid == null ? Db.e_dbid : this.vx_p_dbid;
    }

    protected Db.Type_dbid vx_p_fromid;

    @Override
    public Db.Type_dbid fromid() {
      return this.vx_p_fromid == null ? Db.e_dbid : this.vx_p_fromid;
    }

    protected Db.Type_dbid vx_p_toid;

    @Override
    public Db.Type_dbid toid() {
      return this.vx_p_toid == null ? Db.e_dbid : this.vx_p_toid;
    }

    protected Db.Type_dbid vx_p_noteid;

    @Override
    public Db.Type_dbid noteid() {
      return this.vx_p_noteid == null ? Db.e_dbid : this.vx_p_noteid;
    }

    protected Db.Type_dbid vx_p_valid;

    @Override
    public Db.Type_dbid valid() {
      return this.vx_p_valid == null ? Db.e_dbid : this.vx_p_valid;
    }

    protected Core.Type_string vx_p_valtext;

    @Override
    public Core.Type_string valtext() {
      return this.vx_p_valtext == null ? Core.e_string : this.vx_p_valtext;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":dbid":
        output = this.dbid();
        break;
      case ":fromid":
        output = this.fromid();
        break;
      case ":toid":
        output = this.toid();
        break;
      case ":noteid":
        output = this.noteid();
        break;
      case ":valid":
        output = this.valid();
        break;
      case ":valtext":
        output = this.valtext();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":dbid", this.dbid());
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      output.put(":noteid", this.noteid());
      output.put(":valid", this.valid());
      output.put(":valtext", this.valtext());
      return Core.immutablemap(output);
    }

    @Override
    public Type_dbvalue vx_new(final Object... vals) {return e_dbvalue.vx_copy(vals);}

    @Override
    public Type_dbvalue vx_copy(final Object... vals) {
      Type_dbvalue output = this;
      boolean ischanged = false;
      Class_dbvalue val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dbid vx_p_fromid = val.fromid();
      Db.Type_dbid vx_p_toid = val.toid();
      Db.Type_dbid vx_p_noteid = val.noteid();
      Db.Type_dbid vx_p_valid = val.valid();
      Core.Type_string vx_p_valtext = val.valtext();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":dbid");
      validkeys.add(":fromid");
      validkeys.add(":toid");
      validkeys.add(":noteid");
      validkeys.add(":valid");
      validkeys.add(":valtext");
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
            msg = Core.vx_msg_from_error(":invalidkeytype (new dbvalue) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new dbvalue) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_dbid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :dbid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_fromid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :fromid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_toid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :toid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_noteid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :noteid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              ischanged = true;
              vx_p_valid = (Db.Type_dbid)valsub;
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :valid " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":valtext":
            if (valsub == vx_p_valtext) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_valtext = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_valtext = Core.t_string.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new dbvalue :valtext " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new dbvalue) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_dbvalue work = new Class_dbvalue();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_fromid = vx_p_fromid;
        work.vx_p_toid = vx_p_toid;
        work.vx_p_noteid = vx_p_noteid;
        work.vx_p_valid = vx_p_valid;
        work.vx_p_valtext = vx_p_valtext;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_dbvalue vx_empty() {return e_dbvalue;}
    @Override
    public Type_dbvalue vx_type() {return t_dbvalue;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbvalue", // name
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

  public static final Type_dbvalue e_dbvalue = new Class_dbvalue();
  public static final Type_dbvalue t_dbvalue = new Class_dbvalue();

  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("db", Db.t_db);
    maptype.put("dbcell", Db.t_dbcell);
    maptype.put("dbcellmap", Db.t_dbcellmap);
    maptype.put("dbfield", Db.t_dbfield);
    maptype.put("dbfieldmap", Db.t_dbfieldmap);
    maptype.put("dbid", Db.t_dbid);
    maptype.put("dblink", Db.t_dblink);
    maptype.put("dblinklist", Db.t_dblinklist);
    maptype.put("dbnode", Db.t_dbnode);
    maptype.put("dbnote", Db.t_dbnote);
    maptype.put("dbtable", Db.t_dbtable);
    maptype.put("dbvalue", Db.t_dbvalue);
    Core.vx_global_package_set("vx/data/db", maptype, mapconst, mapfunc);
  }

}
