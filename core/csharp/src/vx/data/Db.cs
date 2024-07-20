namespace Vx.Data;

public static class Db {


  /**
   * type: db
   * Database trait
   * (type db)
   */
  public interface Type_db : Vx.Core.Type_struct {
    public Vx.Core.Type_string dbid();
  }

  public class Class_db : Vx.Core.Class_base, Type_db {

    public Vx.Core.Type_string? vx_p_dbid = null;

    public Vx.Core.Type_string dbid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":dbid":
        output = this.dbid();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbid", this.dbid());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_db vx_new(params Object[] vals) {
      Vx.Data.Db.Type_db output = Vx.Core.vx_copy(Vx.Data.Db.e_db, vals);
      return output;
    }

    public override Vx.Data.Db.Type_db vx_copy(params Object[] vals) {
      Type_db output = this;
      bool ischanged = false;
      Class_db val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbid = val.dbid();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/db", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub is Vx.Core.Type_string valdbid) {
              ischanged = true;
              vx_p_dbid = valdbid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_dbid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/db", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_db work = new Class_db();
        work.vx_p_dbid = vx_p_dbid;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_db;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_db;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "db", // name
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

  public static Type_db e_db = new Class_db();
  public static Type_db t_db = new Class_db();

  /**
   * type: dbcell
   * Database Cell trait
   * (type dbcell)
   */
  public interface Type_dbcell : Vx.Core.Type_struct {
    public Vx.Core.Type_string dbcellid();
    public Vx.Data.Db.Type_dbcellmap dbcellmap();
    public Vx.Data.Db.Type_dbfieldmap dbfieldmap();
    public Vx.Data.Db.Type_dbcell dbparent();
    public Vx.Data.Db.Type_dbtable dbtable();
  }

  public class Class_dbcell : Vx.Core.Class_base, Type_dbcell {

    public Vx.Core.Type_string? vx_p_dbcellid = null;

    public Vx.Core.Type_string dbcellid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_dbcellid != null) {
        output = this.vx_p_dbcellid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcellmap? vx_p_dbcellmap = null;

    public Vx.Data.Db.Type_dbcellmap dbcellmap() {
      Vx.Data.Db.Type_dbcellmap output = Vx.Data.Db.e_dbcellmap;
      if (this.vx_p_dbcellmap != null) {
        output = this.vx_p_dbcellmap;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbfieldmap? vx_p_dbfieldmap = null;

    public Vx.Data.Db.Type_dbfieldmap dbfieldmap() {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Data.Db.e_dbfieldmap;
      if (this.vx_p_dbfieldmap != null) {
        output = this.vx_p_dbfieldmap;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcell? vx_p_dbparent = null;

    public Vx.Data.Db.Type_dbcell dbparent() {
      Vx.Data.Db.Type_dbcell output = Vx.Data.Db.e_dbcell;
      if (this.vx_p_dbparent != null) {
        output = this.vx_p_dbparent;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbtable? vx_p_dbtable = null;

    public Vx.Data.Db.Type_dbtable dbtable() {
      Vx.Data.Db.Type_dbtable output = Vx.Data.Db.e_dbtable;
      if (this.vx_p_dbtable != null) {
        output = this.vx_p_dbtable;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbcellid", this.dbcellid());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      output.put(":dbparent", this.dbparent());
      output.put(":dbtable", this.dbtable());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbcell vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbcell output = Vx.Core.vx_copy(Vx.Data.Db.e_dbcell, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbcell vx_copy(params Object[] vals) {
      Type_dbcell output = this;
      bool ischanged = false;
      Class_dbcell val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbcellid = val.dbcellid();
      Vx.Data.Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Vx.Data.Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      Vx.Data.Db.Type_dbcell vx_p_dbparent = val.dbparent();
      Vx.Data.Db.Type_dbtable vx_p_dbtable = val.dbtable();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbcellid");
      validkeys.Add(":dbcellmap");
      validkeys.Add(":dbfieldmap");
      validkeys.Add(":dbparent");
      validkeys.Add(":dbtable");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbcellid":
            if (valsub == vx_p_dbcellid) {
            } else if (valsub is Vx.Core.Type_string valdbcellid) {
              ischanged = true;
              vx_p_dbcellid = valdbcellid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_dbcellid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbcellid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub is Vx.Data.Db.Type_dbcellmap valdbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbcellmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub is Vx.Data.Db.Type_dbfieldmap valdbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbfieldmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbparent":
            if (valsub == vx_p_dbparent) {
            } else if (valsub is Vx.Data.Db.Type_dbcell valdbparent) {
              ischanged = true;
              vx_p_dbparent = valdbparent;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbparent"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbtable":
            if (valsub == vx_p_dbtable) {
            } else if (valsub is Vx.Data.Db.Type_dbtable valdbtable) {
              ischanged = true;
              vx_p_dbtable = valdbtable;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbtable"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbcell work = new Class_dbcell();
        work.vx_p_dbcellid = vx_p_dbcellid;
        work.vx_p_dbcellmap = vx_p_dbcellmap;
        work.vx_p_dbfieldmap = vx_p_dbfieldmap;
        work.vx_p_dbparent = vx_p_dbparent;
        work.vx_p_dbtable = vx_p_dbtable;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbcell;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbcell;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbcell", // name
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

  public static Type_dbcell e_dbcell = new Class_dbcell();
  public static Type_dbcell t_dbcell = new Class_dbcell();

  /**
   * type: dbcellmap
   * Database Cell Map
   * (type dbcellmap)
   */
  public interface Type_dbcellmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> vx_mapdbcell();
    public Vx.Data.Db.Type_dbcell vx_dbcell(Vx.Core.Type_string key);
  }

  public class Class_dbcellmap : Vx.Core.Class_base, Type_dbcellmap {

    public Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Data.Db.Type_dbcell>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Data.Db.Type_dbcell castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>(this.vx_p_map);
        if (castval == Vx.Data.Db.e_dbcell) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcell vx_dbcell(Vx.Core.Type_string key) {
      Vx.Data.Db.Type_dbcell output = Vx.Data.Db.e_dbcell;
      Vx.Data.Db.Class_dbcellmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Data.Db.e_dbcell);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> vx_mapdbcell() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_dbcell(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Db.Class_dbcellmap output = new Vx.Data.Db.Class_dbcellmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Data.Db.Type_dbcell castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Db.Type_dbcellmap vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbcellmap output = Vx.Core.vx_copy(Vx.Data.Db.e_dbcellmap, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbcellmap vx_copy(params Object[] vals) {
      Type_dbcellmap output = this;
      bool ischanged = false;
      Class_dbcellmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>(val.vx_mapdbcell());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcellmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Db.Type_dbcell? valany = null;
          if (false) {
          } else if (valsub is Vx.Data.Db.Type_dbcell valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Db.Type_dbcell) {
            valany = valsub as Vx.Data.Db.Type_dbcell;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidkeyvalue", msgmap);
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
        Class_dbcellmap work = new Class_dbcellmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbcellmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbcellmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Db.t_dbcell), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_dbcellmap e_dbcellmap = new Class_dbcellmap();
  public static Type_dbcellmap t_dbcellmap = new Class_dbcellmap();

  /**
   * type: dbfield
   * Database Field trait
   * (type dbfield)
   */
  public interface Type_dbfield : Vx.Core.Type_struct {
    public Vx.Core.Type_string dbfieldid();
    public Vx.Core.Type_any type();
    public Vx.Core.Type_any value();
  }

  public class Class_dbfield : Vx.Core.Class_base, Type_dbfield {

    public Vx.Core.Type_string? vx_p_dbfieldid = null;

    public Vx.Core.Type_string dbfieldid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_dbfieldid != null) {
        output = this.vx_p_dbfieldid;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_type = null;

    public Vx.Core.Type_any type() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_value = null;

    public Vx.Core.Type_any value() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbfieldid", this.dbfieldid());
      output.put(":type", this.type());
      output.put(":value", this.value());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbfield vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbfield output = Vx.Core.vx_copy(Vx.Data.Db.e_dbfield, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbfield vx_copy(params Object[] vals) {
      Type_dbfield output = this;
      bool ischanged = false;
      Class_dbfield val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbfieldid = val.dbfieldid();
      Vx.Core.Type_any vx_p_type = val.type();
      Vx.Core.Type_any vx_p_value = val.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbfieldid");
      validkeys.Add(":type");
      validkeys.Add(":value");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbfieldid":
            if (valsub == vx_p_dbfieldid) {
            } else if (valsub is Vx.Core.Type_string valdbfieldid) {
              ischanged = true;
              vx_p_dbfieldid = valdbfieldid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_dbfieldid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbfieldid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx.Core.Type_any valtype) {
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is Vx.Core.Type_any valvalue) {
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbfield work = new Class_dbfield();
        work.vx_p_dbfieldid = vx_p_dbfieldid;
        work.vx_p_type = vx_p_type;
        work.vx_p_value = vx_p_value;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbfield;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbfield;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbfield", // name
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

  public static Type_dbfield e_dbfield = new Class_dbfield();
  public static Type_dbfield t_dbfield = new Class_dbfield();

  /**
   * type: dbfieldmap
   * Database Field Map
   * (type dbfieldmap)
   */
  public interface Type_dbfieldmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> vx_mapdbfield();
    public Vx.Data.Db.Type_dbfield vx_dbfield(Vx.Core.Type_string key);
  }

  public class Class_dbfieldmap : Vx.Core.Class_base, Type_dbfieldmap {

    public Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Data.Db.Type_dbfield>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Data.Db.Type_dbfield castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>(this.vx_p_map);
        if (castval == Vx.Data.Db.e_dbfield) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbfield vx_dbfield(Vx.Core.Type_string key) {
      Vx.Data.Db.Type_dbfield output = Vx.Data.Db.e_dbfield;
      Vx.Data.Db.Class_dbfieldmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Data.Db.e_dbfield);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> vx_mapdbfield() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_dbfield(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Db.Class_dbfieldmap output = new Vx.Data.Db.Class_dbfieldmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Data.Db.Type_dbfield castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Db.Type_dbfieldmap vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Core.vx_copy(Vx.Data.Db.e_dbfieldmap, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbfieldmap vx_copy(params Object[] vals) {
      Type_dbfieldmap output = this;
      bool ischanged = false;
      Class_dbfieldmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>(val.vx_mapdbfield());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Db.Type_dbfield? valany = null;
          if (false) {
          } else if (valsub is Vx.Data.Db.Type_dbfield valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Db.Type_dbfield) {
            valany = valsub as Vx.Data.Db.Type_dbfield;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidkeyvalue", msgmap);
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
        Class_dbfieldmap work = new Class_dbfieldmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbfieldmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbfieldmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Db.t_dbfield), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_dbfieldmap e_dbfieldmap = new Class_dbfieldmap();
  public static Type_dbfieldmap t_dbfieldmap = new Class_dbfieldmap();

  /**
   * type: dbid
   * Database id
   * (type dbid)
   */
  public interface Type_dbid : Vx.Core.Type_any {
  }

  public class Class_dbid : Vx.Core.Class_base, Type_dbid {

    public override Vx.Data.Db.Type_dbid vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbid output = Vx.Core.vx_copy(Vx.Data.Db.e_dbid, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbid vx_copy(params Object[] vals) {
      Type_dbid output = this;
      bool ischanged = false;
      Class_dbid val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbid work = new Class_dbid();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbid;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbid;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbid", // name
        ":string", // extends
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

  public static Type_dbid e_dbid = new Class_dbid();
  public static Type_dbid t_dbid = new Class_dbid();

  /**
   * type: dblink
   * Database link
   * (type dblink)
   */
  public interface Type_dblink : Vx.Core.Type_struct {
    public Vx.Data.Db.Type_dbid fromid();
    public Vx.Data.Db.Type_dbid toid();
  }

  public class Class_dblink : Vx.Core.Class_base, Type_dblink {

    public Vx.Data.Db.Type_dbid? vx_p_fromid = null;

    public Vx.Data.Db.Type_dbid fromid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_fromid != null) {
        output = this.vx_p_fromid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_toid = null;

    public Vx.Data.Db.Type_dbid toid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_toid != null) {
        output = this.vx_p_toid;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dblink vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dblink output = Vx.Core.vx_copy(Vx.Data.Db.e_dblink, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dblink vx_copy(params Object[] vals) {
      Type_dblink output = this;
      bool ischanged = false;
      Class_dblink val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_fromid = val.fromid();
      Vx.Data.Db.Type_dbid vx_p_toid = val.toid();
      List<string> validkeys = new List<string>();
      validkeys.Add(":fromid");
      validkeys.Add(":toid");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valfromid) {
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fromid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valtoid) {
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("toid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dblink work = new Class_dblink();
        work.vx_p_fromid = vx_p_fromid;
        work.vx_p_toid = vx_p_toid;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dblink;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dblink;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dblink", // name
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

  public static Type_dblink e_dblink = new Class_dblink();
  public static Type_dblink t_dblink = new Class_dblink();

  /**
   * type: dblinklist
   * Database link
   * (type dblinklist)
   */
  public interface Type_dblinklist : Vx.Core.Type_list {
    public List<Vx.Data.Db.Type_dblink> vx_listdblink();
    public Vx.Data.Db.Type_dblink vx_dblink(Vx.Core.Type_int index);
  }

  public class Class_dblinklist : Vx.Core.Class_base, Type_dblinklist {

    public List<Vx.Data.Db.Type_dblink> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Db.Type_dblink>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Db.Type_dblink vx_dblink(Vx.Core.Type_int index) {
      Vx.Data.Db.Type_dblink output = Vx.Data.Db.e_dblink;
      Vx.Data.Db.Class_dblinklist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Db.Type_dblink> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Db.Type_dblink> vx_listdblink() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_dblink(index);
    }

    public override Vx.Data.Db.Type_dblinklist vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dblinklist output = Vx.Core.vx_copy(Vx.Data.Db.e_dblinklist, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dblinklist vx_copy(params Object[] vals) {
      Type_dblinklist output = this;
      bool ischanged = false;
      Class_dblinklist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Db.Type_dblink> listval = new List<Vx.Data.Db.Type_dblink>(val.vx_listdblink());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Db.Type_dblink allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Db.Type_dblink) {
          ischanged = true;
          listval.Add((Vx.Data.Db.Type_dblink)valsub);
        } else if (valsub is Vx.Data.Db.Type_dblinklist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listdblink());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Data.Db.Type_dblink valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/db/dblinklist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dblinklist work = new Class_dblinklist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dblinklist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dblinklist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dblinklist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Db.t_dblink), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_dblinklist e_dblinklist = new Class_dblinklist();
  public static Type_dblinklist t_dblinklist = new Class_dblinklist();

  /**
   * type: dbnode
   * Database node
   * (type dbnode)
   */
  public interface Type_dbnode : Vx.Core.Type_struct {
    public Vx.Data.Db.Type_dbid dbid();
    public Vx.Data.Db.Type_dblinklist links();
  }

  public class Class_dbnode : Vx.Core.Class_base, Type_dbnode {

    public Vx.Data.Db.Type_dbid? vx_p_dbid = null;

    public Vx.Data.Db.Type_dbid dbid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dblinklist? vx_p_links = null;

    public Vx.Data.Db.Type_dblinklist links() {
      Vx.Data.Db.Type_dblinklist output = Vx.Data.Db.e_dblinklist;
      if (this.vx_p_links != null) {
        output = this.vx_p_links;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":links", this.links());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbnode vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbnode output = Vx.Core.vx_copy(Vx.Data.Db.e_dbnode, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbnode vx_copy(params Object[] vals) {
      Type_dbnode output = this;
      bool ischanged = false;
      Class_dbnode val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = val.dbid();
      Vx.Data.Db.Type_dblinklist vx_p_links = val.links();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":links");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valdbid) {
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":links":
            if (valsub == vx_p_links) {
            } else if (valsub is Vx.Data.Db.Type_dblinklist vallinks) {
              ischanged = true;
              vx_p_links = vallinks;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("links"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbnode work = new Class_dbnode();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_links = vx_p_links;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbnode;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbnode;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbnode", // name
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

  public static Type_dbnode e_dbnode = new Class_dbnode();
  public static Type_dbnode t_dbnode = new Class_dbnode();

  /**
   * type: dbnote
   * Database Value
   * (type dbnote)
   */
  public interface Type_dbnote : Vx.Core.Type_struct {
    public Vx.Data.Db.Type_dbid dbid();
    public Vx.Data.Db.Type_dbid valid();
    public Vx.Data.Db.Type_dbid noteid();
    public Vx.Data.Db.Type_dbid valueid();
    public Vx.Core.Type_string value();
  }

  public class Class_dbnote : Vx.Core.Class_base, Type_dbnote {

    public Vx.Data.Db.Type_dbid? vx_p_dbid = null;

    public Vx.Data.Db.Type_dbid dbid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valid = null;

    public Vx.Data.Db.Type_dbid valid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_valid != null) {
        output = this.vx_p_valid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_noteid = null;

    public Vx.Data.Db.Type_dbid noteid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_noteid != null) {
        output = this.vx_p_noteid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valueid = null;

    public Vx.Data.Db.Type_dbid valueid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_valueid != null) {
        output = this.vx_p_valueid;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_value = null;

    public Vx.Core.Type_string value() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":valid", this.valid());
      output.put(":noteid", this.noteid());
      output.put(":valueid", this.valueid());
      output.put(":value", this.value());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbnote vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbnote output = Vx.Core.vx_copy(Vx.Data.Db.e_dbnote, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbnote vx_copy(params Object[] vals) {
      Type_dbnote output = this;
      bool ischanged = false;
      Class_dbnote val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = val.dbid();
      Vx.Data.Db.Type_dbid vx_p_valid = val.valid();
      Vx.Data.Db.Type_dbid vx_p_noteid = val.noteid();
      Vx.Data.Db.Type_dbid vx_p_valueid = val.valueid();
      Vx.Core.Type_string vx_p_value = val.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":valid");
      validkeys.Add(":noteid");
      validkeys.Add(":valueid");
      validkeys.Add(":value");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valdbid) {
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valvalid) {
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("valid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valnoteid) {
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("noteid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valueid":
            if (valsub == vx_p_valueid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valvalueid) {
              ischanged = true;
              vx_p_valueid = valvalueid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("valueid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub is Vx.Core.Type_string valvalue) {
              ischanged = true;
              vx_p_value = valvalue;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_value = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbnote work = new Class_dbnote();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_valid = vx_p_valid;
        work.vx_p_noteid = vx_p_noteid;
        work.vx_p_valueid = vx_p_valueid;
        work.vx_p_value = vx_p_value;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbnote;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbnote;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbnote", // name
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

  public static Type_dbnote e_dbnote = new Class_dbnote();
  public static Type_dbnote t_dbnote = new Class_dbnote();

  /**
   * type: dbtable
   * Database Table trait
   * (type dbtable)
   */
  public interface Type_dbtable : Vx.Core.Type_struct {
    public Vx.Core.Type_string dbtableid();
    public Vx.Data.Db.Type_db db();
    public Vx.Data.Db.Type_dbcellmap dbcellmap();
    public Vx.Data.Db.Type_dbfieldmap dbfieldmap();
  }

  public class Class_dbtable : Vx.Core.Class_base, Type_dbtable {

    public Vx.Core.Type_string? vx_p_dbtableid = null;

    public Vx.Core.Type_string dbtableid() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_dbtableid != null) {
        output = this.vx_p_dbtableid;
      }
      return output;
    }

    public Vx.Data.Db.Type_db? vx_p_db = null;

    public Vx.Data.Db.Type_db db() {
      Vx.Data.Db.Type_db output = Vx.Data.Db.e_db;
      if (this.vx_p_db != null) {
        output = this.vx_p_db;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcellmap? vx_p_dbcellmap = null;

    public Vx.Data.Db.Type_dbcellmap dbcellmap() {
      Vx.Data.Db.Type_dbcellmap output = Vx.Data.Db.e_dbcellmap;
      if (this.vx_p_dbcellmap != null) {
        output = this.vx_p_dbcellmap;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbfieldmap? vx_p_dbfieldmap = null;

    public Vx.Data.Db.Type_dbfieldmap dbfieldmap() {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Data.Db.e_dbfieldmap;
      if (this.vx_p_dbfieldmap != null) {
        output = this.vx_p_dbfieldmap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbtableid", this.dbtableid());
      output.put(":db", this.db());
      output.put(":dbcellmap", this.dbcellmap());
      output.put(":dbfieldmap", this.dbfieldmap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbtable vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbtable output = Vx.Core.vx_copy(Vx.Data.Db.e_dbtable, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbtable vx_copy(params Object[] vals) {
      Type_dbtable output = this;
      bool ischanged = false;
      Class_dbtable val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbtableid = val.dbtableid();
      Vx.Data.Db.Type_db vx_p_db = val.db();
      Vx.Data.Db.Type_dbcellmap vx_p_dbcellmap = val.dbcellmap();
      Vx.Data.Db.Type_dbfieldmap vx_p_dbfieldmap = val.dbfieldmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbtableid");
      validkeys.Add(":db");
      validkeys.Add(":dbcellmap");
      validkeys.Add(":dbfieldmap");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbtableid":
            if (valsub == vx_p_dbtableid) {
            } else if (valsub is Vx.Core.Type_string valdbtableid) {
              ischanged = true;
              vx_p_dbtableid = valdbtableid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_dbtableid = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbtableid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":db":
            if (valsub == vx_p_db) {
            } else if (valsub is Vx.Data.Db.Type_db valdb) {
              ischanged = true;
              vx_p_db = valdb;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("db"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbcellmap":
            if (valsub == vx_p_dbcellmap) {
            } else if (valsub is Vx.Data.Db.Type_dbcellmap valdbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = valdbcellmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbcellmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":dbfieldmap":
            if (valsub == vx_p_dbfieldmap) {
            } else if (valsub is Vx.Data.Db.Type_dbfieldmap valdbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = valdbfieldmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbfieldmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbtable work = new Class_dbtable();
        work.vx_p_dbtableid = vx_p_dbtableid;
        work.vx_p_db = vx_p_db;
        work.vx_p_dbcellmap = vx_p_dbcellmap;
        work.vx_p_dbfieldmap = vx_p_dbfieldmap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbtable;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbtable;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbtable", // name
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

  public static Type_dbtable e_dbtable = new Class_dbtable();
  public static Type_dbtable t_dbtable = new Class_dbtable();

  /**
   * type: dbvalue
   * Database Value
   * (type dbvalue)
   */
  public interface Type_dbvalue : Vx.Core.Type_struct {
    public Vx.Data.Db.Type_dbid dbid();
    public Vx.Data.Db.Type_dbid fromid();
    public Vx.Data.Db.Type_dbid toid();
    public Vx.Data.Db.Type_dbid noteid();
    public Vx.Data.Db.Type_dbid valid();
    public Vx.Core.Type_string valtext();
  }

  public class Class_dbvalue : Vx.Core.Class_base, Type_dbvalue {

    public Vx.Data.Db.Type_dbid? vx_p_dbid = null;

    public Vx.Data.Db.Type_dbid dbid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_dbid != null) {
        output = this.vx_p_dbid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_fromid = null;

    public Vx.Data.Db.Type_dbid fromid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_fromid != null) {
        output = this.vx_p_fromid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_toid = null;

    public Vx.Data.Db.Type_dbid toid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_toid != null) {
        output = this.vx_p_toid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_noteid = null;

    public Vx.Data.Db.Type_dbid noteid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_noteid != null) {
        output = this.vx_p_noteid;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valid = null;

    public Vx.Data.Db.Type_dbid valid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      if (this.vx_p_valid != null) {
        output = this.vx_p_valid;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_valtext = null;

    public Vx.Core.Type_string valtext() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_valtext != null) {
        output = this.vx_p_valtext;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":dbid", this.dbid());
      output.put(":fromid", this.fromid());
      output.put(":toid", this.toid());
      output.put(":noteid", this.noteid());
      output.put(":valid", this.valid());
      output.put(":valtext", this.valtext());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Db.Type_dbvalue vx_new(params Object[] vals) {
      Vx.Data.Db.Type_dbvalue output = Vx.Core.vx_copy(Vx.Data.Db.e_dbvalue, vals);
      return output;
    }

    public override Vx.Data.Db.Type_dbvalue vx_copy(params Object[] vals) {
      Type_dbvalue output = this;
      bool ischanged = false;
      Class_dbvalue val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = val.dbid();
      Vx.Data.Db.Type_dbid vx_p_fromid = val.fromid();
      Vx.Data.Db.Type_dbid vx_p_toid = val.toid();
      Vx.Data.Db.Type_dbid vx_p_noteid = val.noteid();
      Vx.Data.Db.Type_dbid vx_p_valid = val.valid();
      Vx.Core.Type_string vx_p_valtext = val.valtext();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":fromid");
      validkeys.Add(":toid");
      validkeys.Add(":noteid");
      validkeys.Add(":valid");
      validkeys.Add(":valtext");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":dbid":
            if (valsub == vx_p_dbid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valdbid) {
              ischanged = true;
              vx_p_dbid = valdbid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("dbid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fromid":
            if (valsub == vx_p_fromid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valfromid) {
              ischanged = true;
              vx_p_fromid = valfromid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fromid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":toid":
            if (valsub == vx_p_toid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valtoid) {
              ischanged = true;
              vx_p_toid = valtoid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("toid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":noteid":
            if (valsub == vx_p_noteid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valnoteid) {
              ischanged = true;
              vx_p_noteid = valnoteid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("noteid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valid":
            if (valsub == vx_p_valid) {
            } else if (valsub is Vx.Data.Db.Type_dbid valvalid) {
              ischanged = true;
              vx_p_valid = valvalid;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("valid"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":valtext":
            if (valsub == vx_p_valtext) {
            } else if (valsub is Vx.Core.Type_string valvaltext) {
              ischanged = true;
              vx_p_valtext = valvaltext;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_valtext = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("valtext"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_dbvalue work = new Class_dbvalue();
        work.vx_p_dbid = vx_p_dbid;
        work.vx_p_fromid = vx_p_fromid;
        work.vx_p_toid = vx_p_toid;
        work.vx_p_noteid = vx_p_noteid;
        work.vx_p_valid = vx_p_valid;
        work.vx_p_valtext = vx_p_valtext;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_dbvalue;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_dbvalue;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/db", // pkgname
        "dbvalue", // name
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

  public static Type_dbvalue e_dbvalue = new Class_dbvalue();
  public static Type_dbvalue t_dbvalue = new Class_dbvalue();

  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("db", Vx.Data.Db.t_db);
    maptype.put("dbcell", Vx.Data.Db.t_dbcell);
    maptype.put("dbcellmap", Vx.Data.Db.t_dbcellmap);
    maptype.put("dbfield", Vx.Data.Db.t_dbfield);
    maptype.put("dbfieldmap", Vx.Data.Db.t_dbfieldmap);
    maptype.put("dbid", Vx.Data.Db.t_dbid);
    maptype.put("dblink", Vx.Data.Db.t_dblink);
    maptype.put("dblinklist", Vx.Data.Db.t_dblinklist);
    maptype.put("dbnode", Vx.Data.Db.t_dbnode);
    maptype.put("dbnote", Vx.Data.Db.t_dbnote);
    maptype.put("dbtable", Vx.Data.Db.t_dbtable);
    maptype.put("dbvalue", Vx.Data.Db.t_dbvalue);
    Vx.Core.vx_global_package_set("vx/data/db", maptype, mapconst, mapfunc);
    }
  }

}
