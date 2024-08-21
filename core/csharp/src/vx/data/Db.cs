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
      Vx.Core.Type_string? testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbid", this.dbid());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_db vx_new(params object[] vals) {
      Vx.Data.Db.Type_db output = Vx.Core.vx_copy(Vx.Data.Db.e_db, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_db output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_db value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbid = value.dbid();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbid")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/db", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_db work = new Vx.Data.Db.Class_db();
        work.vx_p_dbid = vx_p_dbid;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Db.e_db;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_db;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_db e_db = new Vx.Data.Db.Class_db();
  public static Vx.Data.Db.Type_db t_db = new Vx.Data.Db.Class_db();

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
      Vx.Core.Type_string? testnull = vx_p_dbcellid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcellmap? vx_p_dbcellmap = null;

    public Vx.Data.Db.Type_dbcellmap dbcellmap() {
      Vx.Data.Db.Type_dbcellmap output = Vx.Data.Db.e_dbcellmap;
      Vx.Data.Db.Type_dbcellmap? testnull = vx_p_dbcellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbfieldmap? vx_p_dbfieldmap = null;

    public Vx.Data.Db.Type_dbfieldmap dbfieldmap() {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Data.Db.e_dbfieldmap;
      Vx.Data.Db.Type_dbfieldmap? testnull = vx_p_dbfieldmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcell? vx_p_dbparent = null;

    public Vx.Data.Db.Type_dbcell dbparent() {
      Vx.Data.Db.Type_dbcell output = Vx.Data.Db.e_dbcell;
      Vx.Data.Db.Type_dbcell? testnull = vx_p_dbparent;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbtable? vx_p_dbtable = null;

    public Vx.Data.Db.Type_dbtable dbtable() {
      Vx.Data.Db.Type_dbtable output = Vx.Data.Db.e_dbtable;
      Vx.Data.Db.Type_dbtable? testnull = vx_p_dbtable;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbcellid")) {
        output = this.dbcellid();
      } else if ((skey==":dbcellmap")) {
        output = this.dbcellmap();
      } else if ((skey==":dbfieldmap")) {
        output = this.dbfieldmap();
      } else if ((skey==":dbparent")) {
        output = this.dbparent();
      } else if ((skey==":dbtable")) {
        output = this.dbtable();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbcellid", this.dbcellid());
      map.put(":dbcellmap", this.dbcellmap());
      map.put(":dbfieldmap", this.dbfieldmap());
      map.put(":dbparent", this.dbparent());
      map.put(":dbtable", this.dbtable());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbcell vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbcell output = Vx.Core.vx_copy(Vx.Data.Db.e_dbcell, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbcell output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbcell value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbcellid = value.dbcellid();
      Vx.Data.Db.Type_dbcellmap vx_p_dbcellmap = value.dbcellmap();
      Vx.Data.Db.Type_dbfieldmap vx_p_dbfieldmap = value.dbfieldmap();
      Vx.Data.Db.Type_dbcell vx_p_dbparent = value.dbparent();
      Vx.Data.Db.Type_dbtable vx_p_dbtable = value.dbtable();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbcellid");
      validkeys.Add(":dbcellmap");
      validkeys.Add(":dbfieldmap");
      validkeys.Add(":dbparent");
      validkeys.Add(":dbtable");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbcellid")) {
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
          } else if ((key==":dbcellmap")) {
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
          } else if ((key==":dbfieldmap")) {
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
          } else if ((key==":dbparent")) {
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
          } else if ((key==":dbtable")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcell", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbcell work = new Vx.Data.Db.Class_dbcell();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbcell;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbcell;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbcell e_dbcell = new Vx.Data.Db.Class_dbcell();
  public static Vx.Data.Db.Type_dbcell t_dbcell = new Vx.Data.Db.Class_dbcell();

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
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_dbcell(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Db.Class_dbcellmap output = new Vx.Data.Db.Class_dbcellmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Data.Db.Type_dbcell castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/db/dbcellmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Db.Type_dbcellmap vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbcellmap output = Vx.Core.vx_copy(Vx.Data.Db.e_dbcellmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbcellmap output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbcellmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Db.Type_dbcell> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbcell>(value.vx_mapdbcell());
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          Vx.Data.Db.Type_dbcell valany = Vx.Data.Db.e_dbcell;
          if (false) {
          } else if (valsub is Vx.Data.Db.Type_dbcell valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Db.Type_dbcell) {
            valany = (Vx.Data.Db.Type_dbcell)valsub;
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
          if (valany != Vx.Core.e_any) {
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
        Vx.Data.Db.Class_dbcellmap work = new Vx.Data.Db.Class_dbcellmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Db.e_dbcellmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbcellmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbcellmap e_dbcellmap = new Vx.Data.Db.Class_dbcellmap();
  public static Vx.Data.Db.Type_dbcellmap t_dbcellmap = new Vx.Data.Db.Class_dbcellmap();

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
      Vx.Core.Type_string? testnull = vx_p_dbfieldid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_type = null;

    public Vx.Core.Type_any type() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any? testnull = vx_p_type;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_value = null;

    public Vx.Core.Type_any value() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any? testnull = vx_p_value;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbfieldid")) {
        output = this.dbfieldid();
      } else if ((skey==":type")) {
        output = this.type();
      } else if ((skey==":value")) {
        output = this.value();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbfieldid", this.dbfieldid());
      map.put(":type", this.type());
      map.put(":value", this.value());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbfield vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbfield output = Vx.Core.vx_copy(Vx.Data.Db.e_dbfield, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbfield output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbfield value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbfieldid = value.dbfieldid();
      Vx.Core.Type_any vx_p_type = value.type();
      Vx.Core.Type_any vx_p_value = value.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbfieldid");
      validkeys.Add(":type");
      validkeys.Add(":value");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbfieldid")) {
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
          } else if ((key==":type")) {
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
          } else if ((key==":value")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfield", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbfield work = new Vx.Data.Db.Class_dbfield();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbfield;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbfield;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbfield e_dbfield = new Vx.Data.Db.Class_dbfield();
  public static Vx.Data.Db.Type_dbfield t_dbfield = new Vx.Data.Db.Class_dbfield();

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
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_dbfield(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Db.Class_dbfieldmap output = new Vx.Data.Db.Class_dbfieldmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Data.Db.Type_dbfield castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/db/dbfieldmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Db.Type_dbfieldmap vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Core.vx_copy(Vx.Data.Db.e_dbfieldmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbfieldmap output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbfieldmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Db.Type_dbfield> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Db.Type_dbfield>(value.vx_mapdbfield());
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          Vx.Data.Db.Type_dbfield valany = Vx.Data.Db.e_dbfield;
          if (false) {
          } else if (valsub is Vx.Data.Db.Type_dbfield valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Db.Type_dbfield) {
            valany = (Vx.Data.Db.Type_dbfield)valsub;
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
          if (valany != Vx.Core.e_any) {
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
        Vx.Data.Db.Class_dbfieldmap work = new Vx.Data.Db.Class_dbfieldmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Db.e_dbfieldmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbfieldmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbfieldmap e_dbfieldmap = new Vx.Data.Db.Class_dbfieldmap();
  public static Vx.Data.Db.Type_dbfieldmap t_dbfieldmap = new Vx.Data.Db.Class_dbfieldmap();

  /**
   * type: dbid
   * Database id
   * (type dbid)
   */
  public interface Type_dbid : Vx.Core.Type_any {
  }

  public class Class_dbid : Vx.Core.Class_base, Type_dbid {

    public override Vx.Data.Db.Type_dbid vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbid output = Vx.Core.vx_copy(Vx.Data.Db.e_dbid, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbid output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbid value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbid work = new Vx.Data.Db.Class_dbid();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Db.e_dbid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbid;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbid e_dbid = new Vx.Data.Db.Class_dbid();
  public static Vx.Data.Db.Type_dbid t_dbid = new Vx.Data.Db.Class_dbid();

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
      Vx.Data.Db.Type_dbid? testnull = vx_p_fromid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_toid = null;

    public Vx.Data.Db.Type_dbid toid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_toid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":fromid")) {
        output = this.fromid();
      } else if ((skey==":toid")) {
        output = this.toid();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":fromid", this.fromid());
      map.put(":toid", this.toid());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dblink vx_new(params object[] vals) {
      Vx.Data.Db.Type_dblink output = Vx.Core.vx_copy(Vx.Data.Db.e_dblink, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dblink output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dblink value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_fromid = value.fromid();
      Vx.Data.Db.Type_dbid vx_p_toid = value.toid();
      List<string> validkeys = new List<string>();
      validkeys.Add(":fromid");
      validkeys.Add(":toid");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":fromid")) {
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
          } else if ((key==":toid")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dblink", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dblink work = new Vx.Data.Db.Class_dblink();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dblink;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dblink;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dblink e_dblink = new Vx.Data.Db.Class_dblink();
  public static Vx.Data.Db.Type_dblink t_dblink = new Vx.Data.Db.Class_dblink();

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

    public List<Vx.Data.Db.Type_dblink> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Db.Type_dblink>()
    );

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
      List<Vx.Data.Db.Type_dblink> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Db.Type_dblink output = this.vx_dblink(index);
      return output;
    }

    public override Vx.Data.Db.Type_dblinklist vx_new(params object[] vals) {
      Vx.Data.Db.Type_dblinklist output = Vx.Core.vx_copy(Vx.Data.Db.e_dblinklist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dblinklist output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dblinklist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Db.Type_dblink> listval = new List<Vx.Data.Db.Type_dblink>(value.vx_listdblink());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
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
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
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
        Vx.Data.Db.Class_dblinklist work = new Vx.Data.Db.Class_dblinklist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Db.e_dblinklist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dblinklist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dblinklist e_dblinklist = new Vx.Data.Db.Class_dblinklist();
  public static Vx.Data.Db.Type_dblinklist t_dblinklist = new Vx.Data.Db.Class_dblinklist();

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
      Vx.Data.Db.Type_dbid? testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dblinklist? vx_p_links = null;

    public Vx.Data.Db.Type_dblinklist links() {
      Vx.Data.Db.Type_dblinklist output = Vx.Data.Db.e_dblinklist;
      Vx.Data.Db.Type_dblinklist? testnull = vx_p_links;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid();
      } else if ((skey==":links")) {
        output = this.links();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":links", this.links());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbnode vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbnode output = Vx.Core.vx_copy(Vx.Data.Db.e_dbnode, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbnode output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbnode value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = value.dbid();
      Vx.Data.Db.Type_dblinklist vx_p_links = value.links();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":links");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbid")) {
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
          } else if ((key==":links")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnode", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbnode work = new Vx.Data.Db.Class_dbnode();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbnode;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbnode;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbnode e_dbnode = new Vx.Data.Db.Class_dbnode();
  public static Vx.Data.Db.Type_dbnode t_dbnode = new Vx.Data.Db.Class_dbnode();

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
      Vx.Data.Db.Type_dbid? testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valid = null;

    public Vx.Data.Db.Type_dbid valid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_valid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_noteid = null;

    public Vx.Data.Db.Type_dbid noteid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_noteid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valueid = null;

    public Vx.Data.Db.Type_dbid valueid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_valueid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_value = null;

    public Vx.Core.Type_string value() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_value;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid();
      } else if ((skey==":valid")) {
        output = this.valid();
      } else if ((skey==":noteid")) {
        output = this.noteid();
      } else if ((skey==":valueid")) {
        output = this.valueid();
      } else if ((skey==":value")) {
        output = this.value();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":valid", this.valid());
      map.put(":noteid", this.noteid());
      map.put(":valueid", this.valueid());
      map.put(":value", this.value());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbnote vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbnote output = Vx.Core.vx_copy(Vx.Data.Db.e_dbnote, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbnote output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbnote value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = value.dbid();
      Vx.Data.Db.Type_dbid vx_p_valid = value.valid();
      Vx.Data.Db.Type_dbid vx_p_noteid = value.noteid();
      Vx.Data.Db.Type_dbid vx_p_valueid = value.valueid();
      Vx.Core.Type_string vx_p_value = value.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":valid");
      validkeys.Add(":noteid");
      validkeys.Add(":valueid");
      validkeys.Add(":value");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbid")) {
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
          } else if ((key==":valid")) {
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
          } else if ((key==":noteid")) {
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
          } else if ((key==":valueid")) {
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
          } else if ((key==":value")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbnote", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbnote work = new Vx.Data.Db.Class_dbnote();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbnote;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbnote;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbnote e_dbnote = new Vx.Data.Db.Class_dbnote();
  public static Vx.Data.Db.Type_dbnote t_dbnote = new Vx.Data.Db.Class_dbnote();

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
      Vx.Core.Type_string? testnull = vx_p_dbtableid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_db? vx_p_db = null;

    public Vx.Data.Db.Type_db db() {
      Vx.Data.Db.Type_db output = Vx.Data.Db.e_db;
      Vx.Data.Db.Type_db? testnull = vx_p_db;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbcellmap? vx_p_dbcellmap = null;

    public Vx.Data.Db.Type_dbcellmap dbcellmap() {
      Vx.Data.Db.Type_dbcellmap output = Vx.Data.Db.e_dbcellmap;
      Vx.Data.Db.Type_dbcellmap? testnull = vx_p_dbcellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbfieldmap? vx_p_dbfieldmap = null;

    public Vx.Data.Db.Type_dbfieldmap dbfieldmap() {
      Vx.Data.Db.Type_dbfieldmap output = Vx.Data.Db.e_dbfieldmap;
      Vx.Data.Db.Type_dbfieldmap? testnull = vx_p_dbfieldmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbtableid")) {
        output = this.dbtableid();
      } else if ((skey==":db")) {
        output = this.db();
      } else if ((skey==":dbcellmap")) {
        output = this.dbcellmap();
      } else if ((skey==":dbfieldmap")) {
        output = this.dbfieldmap();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbtableid", this.dbtableid());
      map.put(":db", this.db());
      map.put(":dbcellmap", this.dbcellmap());
      map.put(":dbfieldmap", this.dbfieldmap());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbtable vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbtable output = Vx.Core.vx_copy(Vx.Data.Db.e_dbtable, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbtable output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbtable value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_dbtableid = value.dbtableid();
      Vx.Data.Db.Type_db vx_p_db = value.db();
      Vx.Data.Db.Type_dbcellmap vx_p_dbcellmap = value.dbcellmap();
      Vx.Data.Db.Type_dbfieldmap vx_p_dbfieldmap = value.dbfieldmap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbtableid");
      validkeys.Add(":db");
      validkeys.Add(":dbcellmap");
      validkeys.Add(":dbfieldmap");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbtableid")) {
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
          } else if ((key==":db")) {
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
          } else if ((key==":dbcellmap")) {
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
          } else if ((key==":dbfieldmap")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbtable", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbtable work = new Vx.Data.Db.Class_dbtable();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbtable;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbtable;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbtable e_dbtable = new Vx.Data.Db.Class_dbtable();
  public static Vx.Data.Db.Type_dbtable t_dbtable = new Vx.Data.Db.Class_dbtable();

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
      Vx.Data.Db.Type_dbid? testnull = vx_p_dbid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_fromid = null;

    public Vx.Data.Db.Type_dbid fromid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_fromid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_toid = null;

    public Vx.Data.Db.Type_dbid toid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_toid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_noteid = null;

    public Vx.Data.Db.Type_dbid noteid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_noteid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Db.Type_dbid? vx_p_valid = null;

    public Vx.Data.Db.Type_dbid valid() {
      Vx.Data.Db.Type_dbid output = Vx.Data.Db.e_dbid;
      Vx.Data.Db.Type_dbid? testnull = vx_p_valid;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_valtext = null;

    public Vx.Core.Type_string valtext() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_valtext;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":dbid")) {
        output = this.dbid();
      } else if ((skey==":fromid")) {
        output = this.fromid();
      } else if ((skey==":toid")) {
        output = this.toid();
      } else if ((skey==":noteid")) {
        output = this.noteid();
      } else if ((skey==":valid")) {
        output = this.valid();
      } else if ((skey==":valtext")) {
        output = this.valtext();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":dbid", this.dbid());
      map.put(":fromid", this.fromid());
      map.put(":toid", this.toid());
      map.put(":noteid", this.noteid());
      map.put(":valid", this.valid());
      map.put(":valtext", this.valtext());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Db.Type_dbvalue vx_new(params object[] vals) {
      Vx.Data.Db.Type_dbvalue output = Vx.Core.vx_copy(Vx.Data.Db.e_dbvalue, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Db.Type_dbvalue output = this;
      bool ischanged = false;
      Vx.Data.Db.Class_dbvalue value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Data.Db.Type_dbid vx_p_dbid = value.dbid();
      Vx.Data.Db.Type_dbid vx_p_fromid = value.fromid();
      Vx.Data.Db.Type_dbid vx_p_toid = value.toid();
      Vx.Data.Db.Type_dbid vx_p_noteid = value.noteid();
      Vx.Data.Db.Type_dbid vx_p_valid = value.valid();
      Vx.Core.Type_string vx_p_valtext = value.valtext();
      List<string> validkeys = new List<string>();
      validkeys.Add(":dbid");
      validkeys.Add(":fromid");
      validkeys.Add(":toid");
      validkeys.Add(":noteid");
      validkeys.Add(":valid");
      validkeys.Add(":valtext");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":dbid")) {
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
          } else if ((key==":fromid")) {
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
          } else if ((key==":toid")) {
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
          } else if ((key==":noteid")) {
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
          } else if ((key==":valid")) {
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
          } else if ((key==":valtext")) {
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
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/db/dbvalue", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Db.Class_dbvalue work = new Vx.Data.Db.Class_dbvalue();
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
      Vx.Core.Type_any output = Vx.Data.Db.e_dbvalue;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Db.t_dbvalue;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Data.Db.Type_dbvalue e_dbvalue = new Vx.Data.Db.Class_dbvalue();
  public static Vx.Data.Db.Type_dbvalue t_dbvalue = new Vx.Data.Db.Class_dbvalue();

  public static class PackageRunOnce {
    public static bool RunOnce() {
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
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
