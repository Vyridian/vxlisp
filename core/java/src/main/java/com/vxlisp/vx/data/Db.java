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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string dbid();
  }

  public static class Class_db extends Core.Class_base implements Type_db {

    public Core.Type_string vx_p_dbid = null;

    @Override
    public Core.Type_string dbid() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbid", this.dbid());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_db vx_new(final Object... vals) {
      return Core.vx_copy(
       e_db,
       vals);
    }

    @Override
    public Db.Type_db vx_copy(final Object... vals) {
      Type_db output = this;
      boolean ischanged = false;
      Class_db val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbid = val.dbid();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/db", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbid = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/db", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_db;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_db;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string dbcellid();
    public Db.Type_dbcellmap dbcellmap();
    public Db.Type_dbfieldmap dbfieldmap();
    public Db.Type_dbcell dbparent();
    public Db.Type_dbtable dbtable();
  }

  public static class Class_dbcell extends Core.Class_base implements Type_dbcell {

    public Core.Type_string vx_p_dbcellid = null;

    @Override
    public Core.Type_string dbcellid() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_dbcellid != null) {
        output = this.vx_p_dbcellid;
      }
      return output;
    }

    public Db.Type_dbcellmap vx_p_dbcellmap = null;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      Db.Type_dbcellmap output = Db.e_dbcellmap;
      if (this.vx_p_dbcellmap != null) {
        output = this.vx_p_dbcellmap;
      }
      return output;
    }

    public Db.Type_dbfieldmap vx_p_dbfieldmap = null;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      Db.Type_dbfieldmap output = Db.e_dbfieldmap;
      if (this.vx_p_dbfieldmap != null) {
        output = this.vx_p_dbfieldmap;
      }
      return output;
    }

    public Db.Type_dbcell vx_p_dbparent = null;

    @Override
    public Db.Type_dbcell dbparent() {
      Db.Type_dbcell output = Db.e_dbcell;
      if (this.vx_p_dbparent != null) {
        output = this.vx_p_dbparent;
      }
      return output;
    }

    public Db.Type_dbtable vx_p_dbtable = null;

    @Override
    public Db.Type_dbtable dbtable() {
      Db.Type_dbtable output = Db.e_dbtable;
      if (this.vx_p_dbtable != null) {
        output = this.vx_p_dbtable;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbcellid", this.dbcellid());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      output.put(":dbparent", this.dbparent());
      output.put(":dbtable", this.dbtable());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbcell vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbcell,
       vals);
    }

    @Override
    public Db.Type_dbcell vx_copy(final Object... vals) {
      Type_dbcell output = this;
      boolean ischanged = false;
      Class_dbcell val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbcellid = val.dbcellid();
      Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      Db.Type_dbcell vx_p_dbparent = val.dbparent();
      Db.Type_dbtable vx_p_dbtable = val.dbtable();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbcellid");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
      validkeys.add(":dbparent");
      validkeys.add(":dbtable");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbcellid":
            if (valsub == vx_p_dbcellid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbcellid = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_dbcellid = valdbcellid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbcellid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbcellid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              Db.Type_dbcellmap valdbcellmap = (Db.Type_dbcellmap)valsub;;
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbcellmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              Db.Type_dbfieldmap valdbfieldmap = (Db.Type_dbfieldmap)valsub;;
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbfieldmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbparent":
            if (valsub == vx_p_dbparent) {
            } else if (valsub instanceof Db.Type_dbcell) {
              Db.Type_dbcell valdbparent = (Db.Type_dbcell)valsub;;
              ischanged = true;
              vx_p_dbparent = valdbparent;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbparent"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbtable":
            if (valsub == vx_p_dbtable) {
            } else if (valsub instanceof Db.Type_dbtable) {
              Db.Type_dbtable valdbtable = (Db.Type_dbtable)valsub;;
              ischanged = true;
              vx_p_dbtable = valdbtable;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbtable"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbcell;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbcell;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Db.Type_dbcell> vx_mapdbcell();
    public Db.Type_dbcell vx_dbcell(final Core.Type_string key);
  }

  public static class Class_dbcellmap extends Core.Class_base implements Type_dbcellmap {

    public Map<String, Db.Type_dbcell> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbcell>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Db.Type_dbcell) {
        Db.Type_dbcell castval = (Db.Type_dbcell)value;;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Db.Type_dbcell> map = new LinkedHashMap<String, Db.Type_dbcell>(this.vx_p_map);
        if (castval == Db.e_dbcell) {
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
    public Db.Type_dbcell vx_dbcell(final Core.Type_string key) {
      Db.Type_dbcell output = Db.e_dbcell;
      Db.Class_dbcellmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbcell> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Db.e_dbcell);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbcell> vx_mapdbcell() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_dbcell(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Db.Class_dbcellmap output = new Db.Class_dbcellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbcell> map = new LinkedHashMap<String, Db.Type_dbcell>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val instanceof Db.Type_dbcell) {
          Db.Type_dbcell castval = (Db.Type_dbcell)val;;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidvalue", val);
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
    public Db.Type_dbcellmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbcellmap,
       vals);
    }

    @Override
    public Db.Type_dbcellmap vx_copy(final Object... vals) {
      Type_dbcellmap output = this;
      boolean ischanged = false;
      Class_dbcellmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Db.Type_dbcell> mapval = new LinkedHashMap<String, Db.Type_dbcell>(val.vx_mapdbcell());
      Core.Type_msg msg = null;
      String key = "";
      Core.Type_any msgval = null;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbcell valany = null;
          if (false) {
          } else if (valsub instanceof Db.Type_dbcell) {
            Db.Type_dbcell valallowed = (Db.Type_dbcell)valsub;;
            valany = valallowed;
          } else if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidkeyvalue", msgmap);
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
    public Core.Type_any vx_empty() {
      return e_dbcellmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbcellmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Db.t_dbcell), // allowtypes
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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string dbfieldid();
    public Core.Type_any type();
    public Core.Type_any value();
  }

  public static class Class_dbfield extends Core.Class_base implements Type_dbfield {

    public Core.Type_string vx_p_dbfieldid = null;

    @Override
    public Core.Type_string dbfieldid() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_dbfieldid != null) {
        output = this.vx_p_dbfieldid;
      }
      return output;
    }

    public Core.Type_any vx_p_type = null;

    @Override
    public Core.Type_any type() {
      Core.Type_any output = Core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Core.Type_any vx_p_value = null;

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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbfieldid", this.dbfieldid());
      output.put(":type", this.type());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbfield vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbfield,
       vals);
    }

    @Override
    public Db.Type_dbfield vx_copy(final Object... vals) {
      Type_dbfield output = this;
      boolean ischanged = false;
      Class_dbfield val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbfieldid = val.dbfieldid();
      Core.Type_any vx_p_type = val.type();
      Core.Type_any vx_p_value = val.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbfieldid");
      validkeys.add(":type");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbfieldid":
            if (valsub == vx_p_dbfieldid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbfieldid = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_dbfieldid = valdbfieldid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbfieldid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbfieldid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valtype = (Core.Type_any)valsub;;
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valvalue = (Core.Type_any)valsub;;
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbfield;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbfield;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Db.Type_dbfield> vx_mapdbfield();
    public Db.Type_dbfield vx_dbfield(final Core.Type_string key);
  }

  public static class Class_dbfieldmap extends Core.Class_base implements Type_dbfieldmap {

    public Map<String, Db.Type_dbfield> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Db.Type_dbfield>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Db.Type_dbfield) {
        Db.Type_dbfield castval = (Db.Type_dbfield)value;;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Db.Type_dbfield> map = new LinkedHashMap<String, Db.Type_dbfield>(this.vx_p_map);
        if (castval == Db.e_dbfield) {
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
    public Db.Type_dbfield vx_dbfield(final Core.Type_string key) {
      Db.Type_dbfield output = Db.e_dbfield;
      Db.Class_dbfieldmap map = this;
      String skey = key.vx_string();
      Map<String, Db.Type_dbfield> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Db.e_dbfield);
      return output;
    }

    @Override
    public Map<String, Db.Type_dbfield> vx_mapdbfield() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_dbfield(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Db.Class_dbfieldmap output = new Db.Class_dbfieldmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbfield> map = new LinkedHashMap<String, Db.Type_dbfield>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val instanceof Db.Type_dbfield) {
          Db.Type_dbfield castval = (Db.Type_dbfield)val;;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidvalue", val);
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
    public Db.Type_dbfieldmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbfieldmap,
       vals);
    }

    @Override
    public Db.Type_dbfieldmap vx_copy(final Object... vals) {
      Type_dbfieldmap output = this;
      boolean ischanged = false;
      Class_dbfieldmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Db.Type_dbfield> mapval = new LinkedHashMap<String, Db.Type_dbfield>(val.vx_mapdbfield());
      Core.Type_msg msg = null;
      String key = "";
      Core.Type_any msgval = null;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbfield valany = null;
          if (false) {
          } else if (valsub instanceof Db.Type_dbfield) {
            Db.Type_dbfield valallowed = (Db.Type_dbfield)valsub;;
            valany = valallowed;
          } else if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidkeyvalue", msgmap);
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
    public Core.Type_any vx_empty() {
      return e_dbfieldmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbfieldmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Db.t_dbfield), // allowtypes
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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
  }

  public static class Class_dbid extends Core.Class_base implements Type_dbid {

    @Override
    public Db.Type_dbid vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbid,
       vals);
    }

    @Override
    public Db.Type_dbid vx_copy(final Object... vals) {
      Type_dbid output = this;
      boolean ischanged = false;
      Class_dbid val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
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
    public Core.Type_any vx_empty() {
      return e_dbid;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbid;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Db.Type_dbid fromid();
    public Db.Type_dbid toid();
  }

  public static class Class_dblink extends Core.Class_base implements Type_dblink {

    public Db.Type_dbid vx_p_fromid = null;

    @Override
    public Db.Type_dbid fromid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_fromid != null) {
        output = this.vx_p_fromid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_toid = null;

    @Override
    public Db.Type_dbid toid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_toid != null) {
        output = this.vx_p_toid;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dblink vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dblink,
       vals);
    }

    @Override
    public Db.Type_dblink vx_copy(final Object... vals) {
      Type_dblink output = this;
      boolean ischanged = false;
      Class_dblink val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_fromid = val.fromid();
      Db.Type_dbid vx_p_toid = val.toid();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":fromid");
      validkeys.add(":toid");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valfromid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fromid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valtoid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("toid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dblink;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dblink;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Db.Type_dblink> vx_listdblink();
    public Db.Type_dblink vx_dblink(final Core.Type_int index);
  }

  public static class Class_dblinklist extends Core.Class_base implements Type_dblinklist {

    public List<Db.Type_dblink> vx_p_list = Core.immutablelist(new ArrayList<Db.Type_dblink>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Db.Type_dblink vx_dblink(final Core.Type_int index) {
      Db.Type_dblink output = Db.e_dblink;
      Db.Class_dblinklist list = this;
      int iindex = index.vx_int();
      List<Db.Type_dblink> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Db.Type_dblink> vx_listdblink() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_dblink(index);
    }

    @Override
    public Db.Type_dblinklist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dblinklist,
       vals);
    }

    @Override
    public Db.Type_dblinklist vx_copy(final Object... vals) {
      Type_dblinklist output = this;
      boolean ischanged = false;
      Class_dblinklist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Db.Type_dblink> listval = new ArrayList<Db.Type_dblink>(val.vx_listdblink());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Db.Type_dblink) {
          Db.Type_dblink allowsub = (Db.Type_dblink)valsub;;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Db.Type_dblink) {
          ischanged = true;
          listval.add((Db.Type_dblink)valsub);
        } else if (valsub instanceof Db.Type_dblinklist) {
          Db.Type_dblinklist multi = (Db.Type_dblinklist)valsub;;
          ischanged = true;
          listval.addAll(multi.vx_listdblink());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Db.Type_dblink) {
              Db.Type_dblink valitem = (Db.Type_dblink)item;;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;;
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
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
    public Core.Type_any vx_empty() {
      return e_dblinklist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dblinklist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/db", // pkgname
        "dblinklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Db.t_dblink), // allowtypes
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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dblinklist links();
  }

  public static class Class_dbnode extends Core.Class_base implements Type_dbnode {

    public Db.Type_dbid vx_p_dbid = null;

    @Override
    public Db.Type_dbid dbid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Db.Type_dblinklist vx_p_links = null;

    @Override
    public Db.Type_dblinklist links() {
      Db.Type_dblinklist output = Db.e_dblinklist;
      if (this.vx_p_links != null) {
        output = this.vx_p_links;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":links", this.links());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbnode vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbnode,
       vals);
    }

    @Override
    public Db.Type_dbnode vx_copy(final Object... vals) {
      Type_dbnode output = this;
      boolean ischanged = false;
      Class_dbnode val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dblinklist vx_p_links = val.links();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":links");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":links":
            if (valsub == vx_p_links) {
            } else if (valsub instanceof Db.Type_dblinklist) {
              Db.Type_dblinklist vallinks = (Db.Type_dblinklist)valsub;;
              ischanged = true;
              vx_p_links = vallinks;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("links"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbnode;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbnode;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dbid valid();
    public Db.Type_dbid noteid();
    public Db.Type_dbid valueid();
    public Core.Type_string value();
  }

  public static class Class_dbnote extends Core.Class_base implements Type_dbnote {

    public Db.Type_dbid vx_p_dbid = null;

    @Override
    public Db.Type_dbid dbid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valid = null;

    @Override
    public Db.Type_dbid valid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_valid != null) {
        output = this.vx_p_valid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_noteid = null;

    @Override
    public Db.Type_dbid noteid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_noteid != null) {
        output = this.vx_p_noteid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valueid = null;

    @Override
    public Db.Type_dbid valueid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_valueid != null) {
        output = this.vx_p_valueid;
      }
      return output;
    }

    public Core.Type_string vx_p_value = null;

    @Override
    public Core.Type_string value() {
      Core.Type_string output = Core.e_string;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":valid", this.valid());
      output.put(":noteid", this.noteid());
      output.put(":valueid", this.valueid());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbnote vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbnote,
       vals);
    }

    @Override
    public Db.Type_dbnote vx_copy(final Object... vals) {
      Type_dbnote output = this;
      boolean ischanged = false;
      Class_dbnote val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dbid vx_p_valid = val.valid();
      Db.Type_dbid vx_p_noteid = val.noteid();
      Db.Type_dbid vx_p_valueid = val.valueid();
      Core.Type_string vx_p_value = val.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":valid");
      validkeys.add(":noteid");
      validkeys.add(":valueid");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("valid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valnoteid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("noteid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valueid":
            if (valsub == vx_p_valueid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalueid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_valueid = valvalueid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("valueid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valvalue = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_value = valvalue;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_value = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbnote;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbnote;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string dbtableid();
    public Db.Type_db db();
    public Db.Type_dbcellmap dbcellmap();
    public Db.Type_dbfieldmap dbfieldmap();
  }

  public static class Class_dbtable extends Core.Class_base implements Type_dbtable {

    public Core.Type_string vx_p_dbtableid = null;

    @Override
    public Core.Type_string dbtableid() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_dbtableid != null) {
        output = this.vx_p_dbtableid;
      }
      return output;
    }

    public Db.Type_db vx_p_db = null;

    @Override
    public Db.Type_db db() {
      Db.Type_db output = Db.e_db;
      if (this.vx_p_db != null) {
        output = this.vx_p_db;
      }
      return output;
    }

    public Db.Type_dbcellmap vx_p_dbcellmap = null;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      Db.Type_dbcellmap output = Db.e_dbcellmap;
      if (this.vx_p_dbcellmap != null) {
        output = this.vx_p_dbcellmap;
      }
      return output;
    }

    public Db.Type_dbfieldmap vx_p_dbfieldmap = null;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      Db.Type_dbfieldmap output = Db.e_dbfieldmap;
      if (this.vx_p_dbfieldmap != null) {
        output = this.vx_p_dbfieldmap;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbtableid", this.dbtableid());
      output.put(":db", this.db());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbtable vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbtable,
       vals);
    }

    @Override
    public Db.Type_dbtable vx_copy(final Object... vals) {
      Type_dbtable output = this;
      boolean ischanged = false;
      Class_dbtable val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbtableid = val.dbtableid();
      Db.Type_db vx_p_db = val.db();
      Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbtableid");
      validkeys.add(":db");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbtableid":
            if (valsub == vx_p_dbtableid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbtableid = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_dbtableid = valdbtableid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbtableid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbtableid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":db":
            if (valsub == vx_p_db) {
            } else if (valsub instanceof Db.Type_db) {
              Db.Type_db valdb = (Db.Type_db)valsub;;
              ischanged = true;
              vx_p_db = valdb;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("db"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              Db.Type_dbcellmap valdbcellmap = (Db.Type_dbcellmap)valsub;;
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbcellmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              Db.Type_dbfieldmap valdbfieldmap = (Db.Type_dbfieldmap)valsub;;
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbfieldmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbtable;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbtable;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Db.Type_dbid dbid();
    public Db.Type_dbid fromid();
    public Db.Type_dbid toid();
    public Db.Type_dbid noteid();
    public Db.Type_dbid valid();
    public Core.Type_string valtext();
  }

  public static class Class_dbvalue extends Core.Class_base implements Type_dbvalue {

    public Db.Type_dbid vx_p_dbid = null;

    @Override
    public Db.Type_dbid dbid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_fromid = null;

    @Override
    public Db.Type_dbid fromid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_fromid != null) {
        output = this.vx_p_fromid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_toid = null;

    @Override
    public Db.Type_dbid toid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_toid != null) {
        output = this.vx_p_toid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_noteid = null;

    @Override
    public Db.Type_dbid noteid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_noteid != null) {
        output = this.vx_p_noteid;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valid = null;

    @Override
    public Db.Type_dbid valid() {
      Db.Type_dbid output = Db.e_dbid;
      if (this.vx_p_valid != null) {
        output = this.vx_p_valid;
      }
      return output;
    }

    public Core.Type_string vx_p_valtext = null;

    @Override
    public Core.Type_string valtext() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_valtext != null) {
        output = this.vx_p_valtext;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      output.put(":noteid", this.noteid());
      output.put(":valid", this.valid());
      output.put(":valtext", this.valtext());
      return Core.immutablemap(output);
    }

    @Override
    public Db.Type_dbvalue vx_new(final Object... vals) {
      return Core.vx_copy(
       e_dbvalue,
       vals);
    }

    @Override
    public Db.Type_dbvalue vx_copy(final Object... vals) {
      Type_dbvalue output = this;
      boolean ischanged = false;
      Class_dbvalue val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = val.dbid();
      Db.Type_dbid vx_p_fromid = val.fromid();
      Db.Type_dbid vx_p_toid = val.toid();
      Db.Type_dbid vx_p_noteid = val.noteid();
      Db.Type_dbid vx_p_valid = val.valid();
      Core.Type_string vx_p_valtext = val.valtext();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":fromid");
      validkeys.add(":toid");
      validkeys.add(":noteid");
      validkeys.add(":valid");
      validkeys.add(":valtext");
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
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valfromid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("fromid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valtoid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("toid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valnoteid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("noteid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalid = (Db.Type_dbid)valsub;;
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("valid"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valtext":
            if (valsub == vx_p_valtext) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valvaltext = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_valtext = valvaltext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_valtext = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("valtext"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_dbvalue;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_dbvalue;
    }

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
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
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
