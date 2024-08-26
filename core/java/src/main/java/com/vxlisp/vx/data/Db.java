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
    public Core.Type_string dbid();
  }

  public static class Class_db extends Core.Class_base implements Type_db {

    public Core.Type_string vx_p_dbid = null;

    @Override
    public Core.Type_string dbid() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_dbid;
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
      } else if ((skey.equals(":dbid"))) {
        output = this.dbid();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbid", this.dbid());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_db output = Core.vx_copy(Db.e_db, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_db output = this;
      boolean ischanged = false;
      Db.Class_db value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbid = value.dbid();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
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
          if (false) {
          } else if ((key.equals(":dbid"))) {
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_db work = new Db.Class_db();
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
      Core.Type_any output = Db.e_db;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_db;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_db e_db = new Db.Class_db();
  public static final Db.Type_db t_db = new Db.Class_db();

  /**
   * type: dbcell
   * Database Cell trait
   * (type dbcell)
   */
  public interface Type_dbcell extends Core.Type_struct {
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
      Core.Type_string testnull = vx_p_dbcellid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbcellmap vx_p_dbcellmap = null;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      Db.Type_dbcellmap output = Db.e_dbcellmap;
      Db.Type_dbcellmap testnull = vx_p_dbcellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbfieldmap vx_p_dbfieldmap = null;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      Db.Type_dbfieldmap output = Db.e_dbfieldmap;
      Db.Type_dbfieldmap testnull = vx_p_dbfieldmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbcell vx_p_dbparent = null;

    @Override
    public Db.Type_dbcell dbparent() {
      Db.Type_dbcell output = Db.e_dbcell;
      Db.Type_dbcell testnull = vx_p_dbparent;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbtable vx_p_dbtable = null;

    @Override
    public Db.Type_dbtable dbtable() {
      Db.Type_dbtable output = Db.e_dbtable;
      Db.Type_dbtable testnull = vx_p_dbtable;
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
      } else if ((skey.equals(":dbcellid"))) {
        output = this.dbcellid();
      } else if ((skey.equals(":dbcellmap"))) {
        output = this.dbcellmap();
      } else if ((skey.equals(":dbfieldmap"))) {
        output = this.dbfieldmap();
      } else if ((skey.equals(":dbparent"))) {
        output = this.dbparent();
      } else if ((skey.equals(":dbtable"))) {
        output = this.dbtable();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbcellid", this.dbcellid());
      map.put(":dbcellmap", this.dbcellmap());
      map.put(":dbfieldmap", this.dbfieldmap());
      map.put(":dbparent", this.dbparent());
      map.put(":dbtable", this.dbtable());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbcell output = Core.vx_copy(Db.e_dbcell, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbcell output = this;
      boolean ischanged = false;
      Db.Class_dbcell value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbcellid = value.dbcellid();
      Db.Type_dbcellmap vx_p_dbcellmap = value.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = value.dbfieldmap();
      Db.Type_dbcell vx_p_dbparent = value.dbparent();
      Db.Type_dbtable vx_p_dbtable = value.dbtable();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbcellid");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
      validkeys.add(":dbparent");
      validkeys.add(":dbtable");
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
          if (false) {
          } else if ((key.equals(":dbcellid"))) {
            if (valsub == vx_p_dbcellid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbcellid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_dbcellid = valdbcellid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbcellid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbcellmap"))) {
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              Db.Type_dbcellmap valdbcellmap = (Db.Type_dbcellmap)valsub;
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbfieldmap"))) {
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              Db.Type_dbfieldmap valdbfieldmap = (Db.Type_dbfieldmap)valsub;
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbparent"))) {
            if (valsub == vx_p_dbparent) {
            } else if (valsub instanceof Db.Type_dbcell) {
              Db.Type_dbcell valdbparent = (Db.Type_dbcell)valsub;
              ischanged = true;
              vx_p_dbparent = valdbparent;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbtable"))) {
            if (valsub == vx_p_dbtable) {
            } else if (valsub instanceof Db.Type_dbtable) {
              Db.Type_dbtable valdbtable = (Db.Type_dbtable)valsub;
              ischanged = true;
              vx_p_dbtable = valdbtable;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbcell work = new Db.Class_dbcell();
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
      Core.Type_any output = Db.e_dbcell;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbcell;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbcell e_dbcell = new Db.Class_dbcell();
  public static final Db.Type_dbcell t_dbcell = new Db.Class_dbcell();

  /**
   * type: dbcellmap
   * Database Cell Map
   * (type dbcellmap)
   */
  public interface Type_dbcellmap extends Core.Type_map {
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
        Db.Type_dbcell castval = (Db.Type_dbcell)value;
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
      Map<String, Db.Type_dbcell> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_dbcell(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Db.Class_dbcellmap output = new Db.Class_dbcellmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbcell> map = new LinkedHashMap<String, Db.Type_dbcell>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Db.Type_dbcell) {
          Db.Type_dbcell castval = (Db.Type_dbcell)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidvalue", value);
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
      Db.Type_dbcellmap output = Core.vx_copy(Db.e_dbcellmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbcellmap output = this;
      boolean ischanged = false;
      Db.Class_dbcellmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Db.Type_dbcell> mapval = new LinkedHashMap<String, Db.Type_dbcell>(value.vx_mapdbcell());
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
            msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbcell valany = Db.e_dbcell;
          if (false) {
          } else if (valsub instanceof Db.Type_dbcell) {
            Db.Type_dbcell valallowed = (Db.Type_dbcell)valsub;
            valany = valallowed;
          } else if (valsub instanceof Db.Type_dbcell) {
            valany = (Db.Type_dbcell)valsub;
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
            msg = Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidkeyvalue", msgmap);
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
        Db.Class_dbcellmap work = new Db.Class_dbcellmap();
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
      Core.Type_any output = Db.e_dbcellmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbcellmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbcellmap e_dbcellmap = new Db.Class_dbcellmap();
  public static final Db.Type_dbcellmap t_dbcellmap = new Db.Class_dbcellmap();

  /**
   * type: dbfield
   * Database Field trait
   * (type dbfield)
   */
  public interface Type_dbfield extends Core.Type_struct {
    public Core.Type_string dbfieldid();
    public Core.Type_any type();
    public Core.Type_any value();
  }

  public static class Class_dbfield extends Core.Class_base implements Type_dbfield {

    public Core.Type_string vx_p_dbfieldid = null;

    @Override
    public Core.Type_string dbfieldid() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_dbfieldid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_any vx_p_type = null;

    @Override
    public Core.Type_any type() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_type;
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
      } else if ((skey.equals(":dbfieldid"))) {
        output = this.dbfieldid();
      } else if ((skey.equals(":type"))) {
        output = this.type();
      } else if ((skey.equals(":value"))) {
        output = this.value();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbfieldid", this.dbfieldid());
      map.put(":type", this.type());
      map.put(":value", this.value());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbfield output = Core.vx_copy(Db.e_dbfield, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbfield output = this;
      boolean ischanged = false;
      Db.Class_dbfield value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbfieldid = value.dbfieldid();
      Core.Type_any vx_p_type = value.type();
      Core.Type_any vx_p_value = value.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbfieldid");
      validkeys.add(":type");
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
          if (false) {
          } else if ((key.equals(":dbfieldid"))) {
            if (valsub == vx_p_dbfieldid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbfieldid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_dbfieldid = valdbfieldid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbfieldid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":type"))) {
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valtype = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
              msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbfield work = new Db.Class_dbfield();
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
      Core.Type_any output = Db.e_dbfield;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbfield;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbfield e_dbfield = new Db.Class_dbfield();
  public static final Db.Type_dbfield t_dbfield = new Db.Class_dbfield();

  /**
   * type: dbfieldmap
   * Database Field Map
   * (type dbfieldmap)
   */
  public interface Type_dbfieldmap extends Core.Type_map {
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
        Db.Type_dbfield castval = (Db.Type_dbfield)value;
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
      Map<String, Db.Type_dbfield> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_dbfield(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Db.Class_dbfieldmap output = new Db.Class_dbfieldmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Db.Type_dbfield> map = new LinkedHashMap<String, Db.Type_dbfield>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Db.Type_dbfield) {
          Db.Type_dbfield castval = (Db.Type_dbfield)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidvalue", value);
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
      Db.Type_dbfieldmap output = Core.vx_copy(Db.e_dbfieldmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbfieldmap output = this;
      boolean ischanged = false;
      Db.Class_dbfieldmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Db.Type_dbfield> mapval = new LinkedHashMap<String, Db.Type_dbfield>(value.vx_mapdbfield());
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
            msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Db.Type_dbfield valany = Db.e_dbfield;
          if (false) {
          } else if (valsub instanceof Db.Type_dbfield) {
            Db.Type_dbfield valallowed = (Db.Type_dbfield)valsub;
            valany = valallowed;
          } else if (valsub instanceof Db.Type_dbfield) {
            valany = (Db.Type_dbfield)valsub;
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
            msg = Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidkeyvalue", msgmap);
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
        Db.Class_dbfieldmap work = new Db.Class_dbfieldmap();
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
      Core.Type_any output = Db.e_dbfieldmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbfieldmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbfieldmap e_dbfieldmap = new Db.Class_dbfieldmap();
  public static final Db.Type_dbfieldmap t_dbfieldmap = new Db.Class_dbfieldmap();

  /**
   * type: dbid
   * Database id
   * (type dbid)
   */
  public interface Type_dbid extends Core.Type_any {
  }

  public static class Class_dbid extends Core.Class_base implements Type_dbid {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbid output = Core.vx_copy(Db.e_dbid, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbid output = this;
      boolean ischanged = false;
      Db.Class_dbid value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbid work = new Db.Class_dbid();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Db.e_dbid;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbid;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbid e_dbid = new Db.Class_dbid();
  public static final Db.Type_dbid t_dbid = new Db.Class_dbid();

  /**
   * type: dblink
   * Database link
   * (type dblink)
   */
  public interface Type_dblink extends Core.Type_struct {
    public Db.Type_dbid fromid();
    public Db.Type_dbid toid();
  }

  public static class Class_dblink extends Core.Class_base implements Type_dblink {

    public Db.Type_dbid vx_p_fromid = null;

    @Override
    public Db.Type_dbid fromid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_fromid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_toid = null;

    @Override
    public Db.Type_dbid toid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_toid;
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
      } else if ((skey.equals(":fromid"))) {
        output = this.fromid();
      } else if ((skey.equals(":toid"))) {
        output = this.toid();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":fromid", this.fromid());
      map.put(":toid", this.toid());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dblink output = Core.vx_copy(Db.e_dblink, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dblink output = this;
      boolean ischanged = false;
      Db.Class_dblink value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_fromid = value.fromid();
      Db.Type_dbid vx_p_toid = value.toid();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":fromid");
      validkeys.add(":toid");
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
          if (false) {
          } else if ((key.equals(":fromid"))) {
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valfromid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":toid"))) {
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valtoid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dblink work = new Db.Class_dblink();
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
      Core.Type_any output = Db.e_dblink;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dblink;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dblink e_dblink = new Db.Class_dblink();
  public static final Db.Type_dblink t_dblink = new Db.Class_dblink();

  /**
   * type: dblinklist
   * Database link
   * (type dblinklist)
   */
  public interface Type_dblinklist extends Core.Type_list {
    public List<Db.Type_dblink> vx_listdblink();
    public Db.Type_dblink vx_dblink(final Core.Type_int index);
  }

  public static class Class_dblinklist extends Core.Class_base implements Type_dblinklist {

    public List<Db.Type_dblink> vx_p_list = Core.immutablelist(
      new ArrayList<Db.Type_dblink>()
    );

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
      List<Db.Type_dblink> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Db.Type_dblink output = this.vx_dblink(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dblinklist output = Core.vx_copy(Db.e_dblinklist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dblinklist output = this;
      boolean ischanged = false;
      Db.Class_dblinklist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Db.Type_dblink> listval = new ArrayList<Db.Type_dblink>(value.vx_listdblink());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Db.Type_dblinklist) {
          Db.Type_dblinklist multi = (Db.Type_dblinklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listdblink());
        } else if (valsub instanceof Db.Type_dblink) {
          Db.Type_dblink allowsub = (Db.Type_dblink)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Db.Type_dblink) {
          ischanged = true;
          listval.add((Db.Type_dblink)valsub);
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Db.Type_dblink) {
              Db.Type_dblink valitem = (Db.Type_dblink)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dblinklist work = new Db.Class_dblinklist();
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
      Core.Type_any output = Db.e_dblinklist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dblinklist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dblinklist e_dblinklist = new Db.Class_dblinklist();
  public static final Db.Type_dblinklist t_dblinklist = new Db.Class_dblinklist();

  /**
   * type: dbnode
   * Database node
   * (type dbnode)
   */
  public interface Type_dbnode extends Core.Type_struct {
    public Db.Type_dbid dbid();
    public Db.Type_dblinklist links();
  }

  public static class Class_dbnode extends Core.Class_base implements Type_dbnode {

    public Db.Type_dbid vx_p_dbid = null;

    @Override
    public Db.Type_dbid dbid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dblinklist vx_p_links = null;

    @Override
    public Db.Type_dblinklist links() {
      Db.Type_dblinklist output = Db.e_dblinklist;
      Db.Type_dblinklist testnull = vx_p_links;
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
      } else if ((skey.equals(":dbid"))) {
        output = this.dbid();
      } else if ((skey.equals(":links"))) {
        output = this.links();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":links", this.links());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbnode output = Core.vx_copy(Db.e_dbnode, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbnode output = this;
      boolean ischanged = false;
      Db.Class_dbnode value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = value.dbid();
      Db.Type_dblinklist vx_p_links = value.links();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":links");
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
          if (false) {
          } else if ((key.equals(":dbid"))) {
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":links"))) {
            if (valsub == vx_p_links) {
            } else if (valsub instanceof Db.Type_dblinklist) {
              Db.Type_dblinklist vallinks = (Db.Type_dblinklist)valsub;
              ischanged = true;
              vx_p_links = vallinks;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbnode work = new Db.Class_dbnode();
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
      Core.Type_any output = Db.e_dbnode;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbnode;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbnode e_dbnode = new Db.Class_dbnode();
  public static final Db.Type_dbnode t_dbnode = new Db.Class_dbnode();

  /**
   * type: dbnote
   * Database Value
   * (type dbnote)
   */
  public interface Type_dbnote extends Core.Type_struct {
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
      Db.Type_dbid testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valid = null;

    @Override
    public Db.Type_dbid valid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_valid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_noteid = null;

    @Override
    public Db.Type_dbid noteid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_noteid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valueid = null;

    @Override
    public Db.Type_dbid valueid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_valueid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_value = null;

    @Override
    public Core.Type_string value() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_value;
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
      } else if ((skey.equals(":dbid"))) {
        output = this.dbid();
      } else if ((skey.equals(":valid"))) {
        output = this.valid();
      } else if ((skey.equals(":noteid"))) {
        output = this.noteid();
      } else if ((skey.equals(":valueid"))) {
        output = this.valueid();
      } else if ((skey.equals(":value"))) {
        output = this.value();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":valid", this.valid());
      map.put(":noteid", this.noteid());
      map.put(":valueid", this.valueid());
      map.put(":value", this.value());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbnote output = Core.vx_copy(Db.e_dbnote, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbnote output = this;
      boolean ischanged = false;
      Db.Class_dbnote value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = value.dbid();
      Db.Type_dbid vx_p_valid = value.valid();
      Db.Type_dbid vx_p_noteid = value.noteid();
      Db.Type_dbid vx_p_valueid = value.valueid();
      Core.Type_string vx_p_value = value.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":valid");
      validkeys.add(":noteid");
      validkeys.add(":valueid");
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
          if (false) {
          } else if ((key.equals(":dbid"))) {
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":valid"))) {
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":noteid"))) {
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valnoteid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":valueid"))) {
            if (valsub == vx_p_valueid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalueid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_valueid = valvalueid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":value"))) {
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valvalue = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_value = valvalue;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_value = Core.vx_new(Core.t_string, valsub);
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
              msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbnote work = new Db.Class_dbnote();
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
      Core.Type_any output = Db.e_dbnote;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbnote;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbnote e_dbnote = new Db.Class_dbnote();
  public static final Db.Type_dbnote t_dbnote = new Db.Class_dbnote();

  /**
   * type: dbtable
   * Database Table trait
   * (type dbtable)
   */
  public interface Type_dbtable extends Core.Type_struct {
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
      Core.Type_string testnull = vx_p_dbtableid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_db vx_p_db = null;

    @Override
    public Db.Type_db db() {
      Db.Type_db output = Db.e_db;
      Db.Type_db testnull = vx_p_db;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbcellmap vx_p_dbcellmap = null;

    @Override
    public Db.Type_dbcellmap dbcellmap() {
      Db.Type_dbcellmap output = Db.e_dbcellmap;
      Db.Type_dbcellmap testnull = vx_p_dbcellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbfieldmap vx_p_dbfieldmap = null;

    @Override
    public Db.Type_dbfieldmap dbfieldmap() {
      Db.Type_dbfieldmap output = Db.e_dbfieldmap;
      Db.Type_dbfieldmap testnull = vx_p_dbfieldmap;
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
      } else if ((skey.equals(":dbtableid"))) {
        output = this.dbtableid();
      } else if ((skey.equals(":db"))) {
        output = this.db();
      } else if ((skey.equals(":dbcellmap"))) {
        output = this.dbcellmap();
      } else if ((skey.equals(":dbfieldmap"))) {
        output = this.dbfieldmap();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbtableid", this.dbtableid());
      map.put(":db", this.db());
      map.put(":dbcellmap", this.dbcellmap());
      map.put(":dbfieldmap", this.dbfieldmap());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbtable output = Core.vx_copy(Db.e_dbtable, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbtable output = this;
      boolean ischanged = false;
      Db.Class_dbtable value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_dbtableid = value.dbtableid();
      Db.Type_db vx_p_db = value.db();
      Db.Type_dbcellmap vx_p_dbcellmap = value.dbcellmap();
      Db.Type_dbfieldmap vx_p_dbfieldmap = value.dbfieldmap();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbtableid");
      validkeys.add(":db");
      validkeys.add(":dbcellmap");
      validkeys.add(":dbfieldmap");
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
          if (false) {
          } else if ((key.equals(":dbtableid"))) {
            if (valsub == vx_p_dbtableid) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdbtableid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_dbtableid = valdbtableid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_dbtableid = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":db"))) {
            if (valsub == vx_p_db) {
            } else if (valsub instanceof Db.Type_db) {
              Db.Type_db valdb = (Db.Type_db)valsub;
              ischanged = true;
              vx_p_db = valdb;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbcellmap"))) {
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub instanceof Db.Type_dbcellmap) {
              Db.Type_dbcellmap valdbcellmap = (Db.Type_dbcellmap)valsub;
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":dbfieldmap"))) {
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub instanceof Db.Type_dbfieldmap) {
              Db.Type_dbfieldmap valdbfieldmap = (Db.Type_dbfieldmap)valsub;
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbtable work = new Db.Class_dbtable();
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
      Core.Type_any output = Db.e_dbtable;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbtable;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbtable e_dbtable = new Db.Class_dbtable();
  public static final Db.Type_dbtable t_dbtable = new Db.Class_dbtable();

  /**
   * type: dbvalue
   * Database Value
   * (type dbvalue)
   */
  public interface Type_dbvalue extends Core.Type_struct {
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
      Db.Type_dbid testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_fromid = null;

    @Override
    public Db.Type_dbid fromid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_fromid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_toid = null;

    @Override
    public Db.Type_dbid toid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_toid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_noteid = null;

    @Override
    public Db.Type_dbid noteid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_noteid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Db.Type_dbid vx_p_valid = null;

    @Override
    public Db.Type_dbid valid() {
      Db.Type_dbid output = Db.e_dbid;
      Db.Type_dbid testnull = vx_p_valid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_valtext = null;

    @Override
    public Core.Type_string valtext() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_valtext;
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
      } else if ((skey.equals(":dbid"))) {
        output = this.dbid();
      } else if ((skey.equals(":fromid"))) {
        output = this.fromid();
      } else if ((skey.equals(":toid"))) {
        output = this.toid();
      } else if ((skey.equals(":noteid"))) {
        output = this.noteid();
      } else if ((skey.equals(":valid"))) {
        output = this.valid();
      } else if ((skey.equals(":valtext"))) {
        output = this.valtext();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":fromid", this.fromid());
      map.put(":toid", this.toid());
      map.put(":noteid", this.noteid());
      map.put(":valid", this.valid());
      map.put(":valtext", this.valtext());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Db.Type_dbvalue output = Core.vx_copy(Db.e_dbvalue, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Db.Type_dbvalue output = this;
      boolean ischanged = false;
      Db.Class_dbvalue value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Db.Type_dbid vx_p_dbid = value.dbid();
      Db.Type_dbid vx_p_fromid = value.fromid();
      Db.Type_dbid vx_p_toid = value.toid();
      Db.Type_dbid vx_p_noteid = value.noteid();
      Db.Type_dbid vx_p_valid = value.valid();
      Core.Type_string vx_p_valtext = value.valtext();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":dbid");
      validkeys.add(":fromid");
      validkeys.add(":toid");
      validkeys.add(":noteid");
      validkeys.add(":valid");
      validkeys.add(":valtext");
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
          if (false) {
          } else if ((key.equals(":dbid"))) {
            if (valsub == vx_p_dbid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valdbid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":fromid"))) {
            if (valsub == vx_p_fromid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valfromid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":toid"))) {
            if (valsub == vx_p_toid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valtoid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":noteid"))) {
            if (valsub == vx_p_noteid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valnoteid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":valid"))) {
            if (valsub == vx_p_valid) {
            } else if (valsub instanceof Db.Type_dbid) {
              Db.Type_dbid valvalid = (Db.Type_dbid)valsub;
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":valtext"))) {
            if (valsub == vx_p_valtext) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valvaltext = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_valtext = valvaltext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_valtext = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Db.Class_dbvalue work = new Db.Class_dbvalue();
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
      Core.Type_any output = Db.e_dbvalue;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Db.t_dbvalue;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Db.Type_dbvalue e_dbvalue = new Db.Class_dbvalue();
  public static final Db.Type_dbvalue t_dbvalue = new Db.Class_dbvalue();

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
