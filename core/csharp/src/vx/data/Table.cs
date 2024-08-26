namespace Vx.Data;

public static class Table {


  /**
   * type: cell
   * (type cell)
   */
  public interface Type_cell : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_any value();
  }

  public class Class_cell : Vx.Core.Class_base, Type_cell {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
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
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":value")) {
        output = this.value();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":value", this.value());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_cell output = Vx.Core.vx_copy(Vx.Data.Table.e_cell, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_cell output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_cell value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_any vx_p_value = value.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_cell work = new Vx.Data.Table.Class_cell();
        work.vx_p_id = vx_p_id;
        work.vx_p_value = vx_p_value;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_cell;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_cell;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "cell", // name
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

  public static Vx.Data.Table.Type_cell e_cell = new Vx.Data.Table.Class_cell();
  public static Vx.Data.Table.Type_cell t_cell = new Vx.Data.Table.Class_cell();

  /**
   * type: celllist
   * (type celllist)
   */
  public interface Type_celllist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_cell> vx_listcell();
    public Vx.Data.Table.Type_cell vx_cell(Vx.Core.Type_int index);
  }

  public class Class_celllist : Vx.Core.Class_base, Type_celllist {

    public List<Vx.Data.Table.Type_cell> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Table.Type_cell>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Table.Type_cell vx_cell(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_cell output = Vx.Data.Table.e_cell;
      Vx.Data.Table.Class_celllist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Table.Type_cell> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Table.Type_cell> vx_listcell() {
      List<Vx.Data.Table.Type_cell> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_cell output = this.vx_cell(index);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_celllist output = Vx.Core.vx_copy(Vx.Data.Table.e_celllist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_celllist output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_celllist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_cell> listval = new List<Vx.Data.Table.Type_cell>(value.vx_listcell());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_celllist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listcell());
        } else if (valsub is Vx.Data.Table.Type_cell allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_cell) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_cell)valsub);
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Table.Type_cell valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/celllist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_celllist work = new Vx.Data.Table.Class_celllist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_celllist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_celllist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_cell), // allowtypes
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

  public static Vx.Data.Table.Type_celllist e_celllist = new Vx.Data.Table.Class_celllist();
  public static Vx.Data.Table.Type_celllist t_celllist = new Vx.Data.Table.Class_celllist();

  /**
   * type: cellmap
   * (type cellmap)
   */
  public interface Type_cellmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Data.Table.Type_cell> vx_mapcell();
    public Vx.Data.Table.Type_cell vx_cell(Vx.Core.Type_string key);
  }

  public class Class_cellmap : Vx.Core.Class_base, Type_cellmap {

    public Vx.Core.Map<string, Vx.Data.Table.Type_cell> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Data.Table.Type_cell>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Data.Table.Type_cell castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Data.Table.Type_cell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>(this.vx_p_map);
        if (castval == Vx.Data.Table.e_cell) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Data.Table.Type_cell vx_cell(Vx.Core.Type_string key) {
      Vx.Data.Table.Type_cell output = Vx.Data.Table.e_cell;
      Vx.Data.Table.Class_cellmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Data.Table.e_cell);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Table.Type_cell> vx_mapcell() {
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_cell(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Table.Class_cellmap output = new Vx.Data.Table.Class_cellmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Data.Table.Type_cell castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_cellmap output = Vx.Core.vx_copy(Vx.Data.Table.e_cellmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_cellmap output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_cellmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>(value.vx_mapcell());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cellmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Table.Type_cell valany = Vx.Data.Table.e_cell;
          if (false) {
          } else if (valsub is Vx.Data.Table.Type_cell valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Table.Type_cell) {
            valany = (Vx.Data.Table.Type_cell)valsub;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidkeyvalue", msgmap);
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
        Vx.Data.Table.Class_cellmap work = new Vx.Data.Table.Class_cellmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_cellmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_cellmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_cell), // allowtypes
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

  public static Vx.Data.Table.Type_cellmap e_cellmap = new Vx.Data.Table.Class_cellmap();
  public static Vx.Data.Table.Type_cellmap t_cellmap = new Vx.Data.Table.Class_cellmap();

  /**
   * type: field
   * (type field)
   */
  public interface Type_field : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any fldtype();
  }

  public class Class_field : Vx.Core.Class_base, Type_field {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_fldtype = null;

    public Vx.Core.Type_any fldtype() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any? testnull = vx_p_fldtype;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":fldtype")) {
        output = this.fldtype();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":fldtype", this.fldtype());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_field output = Vx.Core.vx_copy(Vx.Data.Table.e_field, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_field output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_field value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_any vx_p_fldtype = value.fldtype();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":fldtype");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":fldtype")) {
            if (valsub == vx_p_fldtype) {
            } else if (valsub is Vx.Core.Type_any valfldtype) {
              ischanged = true;
              vx_p_fldtype = valfldtype;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fldtype"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_field work = new Vx.Data.Table.Class_field();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_fldtype = vx_p_fldtype;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_field;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_field;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "field", // name
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

  public static Vx.Data.Table.Type_field e_field = new Vx.Data.Table.Class_field();
  public static Vx.Data.Table.Type_field t_field = new Vx.Data.Table.Class_field();

  /**
   * type: fieldlist
   * (type fieldlist)
   */
  public interface Type_fieldlist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_field> vx_listfield();
    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index);
  }

  public class Class_fieldlist : Vx.Core.Class_base, Type_fieldlist {

    public List<Vx.Data.Table.Type_field> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Table.Type_field>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_field output = Vx.Data.Table.e_field;
      Vx.Data.Table.Class_fieldlist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Table.Type_field> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Table.Type_field> vx_listfield() {
      List<Vx.Data.Table.Type_field> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_field output = this.vx_field(index);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_fieldlist output = Vx.Core.vx_copy(Vx.Data.Table.e_fieldlist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_fieldlist output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_fieldlist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_field> listval = new List<Vx.Data.Table.Type_field>(value.vx_listfield());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_fieldlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfield());
        } else if (valsub is Vx.Data.Table.Type_field allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_field) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_field)valsub);
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Table.Type_field valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/fieldlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_fieldlist work = new Vx.Data.Table.Class_fieldlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_fieldlist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_fieldlist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_field), // allowtypes
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

  public static Vx.Data.Table.Type_fieldlist e_fieldlist = new Vx.Data.Table.Class_fieldlist();
  public static Vx.Data.Table.Type_fieldlist t_fieldlist = new Vx.Data.Table.Class_fieldlist();

  /**
   * type: fieldmap
   * (type fieldmap)
   */
  public interface Type_fieldmap : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_field> vx_listfield();
    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index);
  }

  public class Class_fieldmap : Vx.Core.Class_base, Type_fieldmap {

    public List<Vx.Data.Table.Type_field> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Table.Type_field>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_field output = Vx.Data.Table.e_field;
      Vx.Data.Table.Class_fieldmap list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Table.Type_field> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Table.Type_field> vx_listfield() {
      List<Vx.Data.Table.Type_field> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_field output = this.vx_field(index);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_fieldmap output = Vx.Core.vx_copy(Vx.Data.Table.e_fieldmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_fieldmap output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_fieldmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_field> listval = new List<Vx.Data.Table.Type_field>(value.vx_listfield());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_fieldmap multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfield());
        } else if (valsub is Vx.Data.Table.Type_field allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_field) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_field)valsub);
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Table.Type_field valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/fieldmap", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_fieldmap work = new Vx.Data.Table.Class_fieldmap();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_fieldmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_fieldmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_field), // allowtypes
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

  public static Vx.Data.Table.Type_fieldmap e_fieldmap = new Vx.Data.Table.Class_fieldmap();
  public static Vx.Data.Table.Type_fieldmap t_fieldmap = new Vx.Data.Table.Class_fieldmap();

  /**
   * type: filter
   * (type filter)
   */
  public interface Type_filter : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_stringlist idlist();
  }

  public class Class_filter : Vx.Core.Class_base, Type_filter {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_stringlist? vx_p_idlist = null;

    public Vx.Core.Type_stringlist idlist() {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      Vx.Core.Type_stringlist? testnull = vx_p_idlist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":idlist")) {
        output = this.idlist();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":idlist", this.idlist());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_filter output = Vx.Core.vx_copy(Vx.Data.Table.e_filter, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_filter output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_filter value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_stringlist vx_p_idlist = value.idlist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":idlist");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":idlist")) {
            if (valsub == vx_p_idlist) {
            } else if (valsub is Vx.Core.Type_stringlist validlist) {
              ischanged = true;
              vx_p_idlist = validlist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("idlist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_filter work = new Vx.Data.Table.Class_filter();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_idlist = vx_p_idlist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_filter;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_filter;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "filter", // name
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

  public static Vx.Data.Table.Type_filter e_filter = new Vx.Data.Table.Class_filter();
  public static Vx.Data.Table.Type_filter t_filter = new Vx.Data.Table.Class_filter();

  /**
   * type: row
   * (type row)
   */
  public interface Type_row : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Data.Table.Type_cellmap cellmap();
    public Vx.Data.Table.Type_sort cellsort();
  }

  public class Class_row : Vx.Core.Class_base, Type_row {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_cellmap? vx_p_cellmap = null;

    public Vx.Data.Table.Type_cellmap cellmap() {
      Vx.Data.Table.Type_cellmap output = Vx.Data.Table.e_cellmap;
      Vx.Data.Table.Type_cellmap? testnull = vx_p_cellmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_cellsort = null;

    public Vx.Data.Table.Type_sort cellsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      Vx.Data.Table.Type_sort? testnull = vx_p_cellsort;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":cellmap")) {
        output = this.cellmap();
      } else if ((skey==":cellsort")) {
        output = this.cellsort();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":cellmap", this.cellmap());
      map.put(":cellsort", this.cellsort());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_row output = Vx.Core.vx_copy(Vx.Data.Table.e_row, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_row output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_row value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Data.Table.Type_cellmap vx_p_cellmap = value.cellmap();
      Vx.Data.Table.Type_sort vx_p_cellsort = value.cellsort();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":cellmap");
      validkeys.Add(":cellsort");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":cellmap")) {
            if (valsub == vx_p_cellmap) {
            } else if (valsub is Vx.Data.Table.Type_cellmap valcellmap) {
              ischanged = true;
              vx_p_cellmap = valcellmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("cellmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":cellsort")) {
            if (valsub == vx_p_cellsort) {
            } else if (valsub is Vx.Data.Table.Type_sort valcellsort) {
              ischanged = true;
              vx_p_cellsort = valcellsort;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("cellsort"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_row work = new Vx.Data.Table.Class_row();
        work.vx_p_id = vx_p_id;
        work.vx_p_cellmap = vx_p_cellmap;
        work.vx_p_cellsort = vx_p_cellsort;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_row;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_row;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "row", // name
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

  public static Vx.Data.Table.Type_row e_row = new Vx.Data.Table.Class_row();
  public static Vx.Data.Table.Type_row t_row = new Vx.Data.Table.Class_row();

  /**
   * type: rowlist
   * (type rowlist)
   */
  public interface Type_rowlist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_row> vx_listrow();
    public Vx.Data.Table.Type_row vx_row(Vx.Core.Type_int index);
  }

  public class Class_rowlist : Vx.Core.Class_base, Type_rowlist {

    public List<Vx.Data.Table.Type_row> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Table.Type_row>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Table.Type_row vx_row(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_row output = Vx.Data.Table.e_row;
      Vx.Data.Table.Class_rowlist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Table.Type_row> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Table.Type_row> vx_listrow() {
      List<Vx.Data.Table.Type_row> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Table.Type_row output = this.vx_row(index);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_rowlist output = Vx.Core.vx_copy(Vx.Data.Table.e_rowlist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_rowlist output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_rowlist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_row> listval = new List<Vx.Data.Table.Type_row>(value.vx_listrow());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_rowlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listrow());
        } else if (valsub is Vx.Data.Table.Type_row allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_row) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_row)valsub);
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Table.Type_row valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/table/rowlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_rowlist work = new Vx.Data.Table.Class_rowlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_rowlist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_rowlist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_row), // allowtypes
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

  public static Vx.Data.Table.Type_rowlist e_rowlist = new Vx.Data.Table.Class_rowlist();
  public static Vx.Data.Table.Type_rowlist t_rowlist = new Vx.Data.Table.Class_rowlist();

  /**
   * type: rowmap
   * (type rowmap)
   */
  public interface Type_rowmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Data.Table.Type_row> vx_maprow();
    public Vx.Data.Table.Type_row vx_row(Vx.Core.Type_string key);
  }

  public class Class_rowmap : Vx.Core.Class_base, Type_rowmap {

    public Vx.Core.Map<string, Vx.Data.Table.Type_row> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Data.Table.Type_row>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Data.Table.Type_row castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Data.Table.Type_row> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>(this.vx_p_map);
        if (castval == Vx.Data.Table.e_row) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Data.Table.Type_row vx_row(Vx.Core.Type_string key) {
      Vx.Data.Table.Type_row output = Vx.Data.Table.e_row;
      Vx.Data.Table.Class_rowmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Data.Table.Type_row> mapval = map.vx_p_map;
      output = mapval.getOrElse(skey, Vx.Data.Table.e_row);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Table.Type_row> vx_maprow() {
      Vx.Core.Map<string, Vx.Data.Table.Type_row> output = this.vx_p_map;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = this.vx_row(key);
      return output;
    }


    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Table.Class_rowmap output = new Vx.Data.Table.Class_rowmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Table.Type_row> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value is Vx.Data.Table.Type_row castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidvalue", value);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_rowmap output = Vx.Core.vx_copy(Vx.Data.Table.e_rowmap, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_rowmap output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_rowmap value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Table.Type_row> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>(value.vx_maprow());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/rowmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Table.Type_row valany = Vx.Data.Table.e_row;
          if (false) {
          } else if (valsub is Vx.Data.Table.Type_row valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Table.Type_row) {
            valany = (Vx.Data.Table.Type_row)valsub;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidkeyvalue", msgmap);
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
        Vx.Data.Table.Class_rowmap work = new Vx.Data.Table.Class_rowmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_rowmap;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_rowmap;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Table.t_row), // allowtypes
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

  public static Vx.Data.Table.Type_rowmap e_rowmap = new Vx.Data.Table.Class_rowmap();
  public static Vx.Data.Table.Type_rowmap t_rowmap = new Vx.Data.Table.Class_rowmap();

  /**
   * type: sort
   * (type sort)
   */
  public interface Type_sort : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_stringlist idlist();
  }

  public class Class_sort : Vx.Core.Class_base, Type_sort {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_stringlist? vx_p_idlist = null;

    public Vx.Core.Type_stringlist idlist() {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      Vx.Core.Type_stringlist? testnull = vx_p_idlist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":idlist")) {
        output = this.idlist();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":idlist", this.idlist());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_sort output = Vx.Core.vx_copy(Vx.Data.Table.e_sort, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_sort output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_sort value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_stringlist vx_p_idlist = value.idlist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":idlist");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":idlist")) {
            if (valsub == vx_p_idlist) {
            } else if (valsub is Vx.Core.Type_stringlist validlist) {
              ischanged = true;
              vx_p_idlist = validlist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("idlist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_sort work = new Vx.Data.Table.Class_sort();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_idlist = vx_p_idlist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_sort;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_sort;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "sort", // name
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

  public static Vx.Data.Table.Type_sort e_sort = new Vx.Data.Table.Class_sort();
  public static Vx.Data.Table.Type_sort t_sort = new Vx.Data.Table.Class_sort();

  /**
   * type: table
   * (type table)
   */
  public interface Type_table : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Data.Table.Type_fieldmap fieldmap();
    public Vx.Data.Table.Type_sort fieldsort();
    public Vx.Data.Table.Type_rowmap rowmap();
    public Vx.Data.Table.Type_filter rowfilter();
    public Vx.Data.Table.Type_sort rowsort();
  }

  public class Class_table : Vx.Core.Class_base, Type_table {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_fieldmap? vx_p_fieldmap = null;

    public Vx.Data.Table.Type_fieldmap fieldmap() {
      Vx.Data.Table.Type_fieldmap output = Vx.Data.Table.e_fieldmap;
      Vx.Data.Table.Type_fieldmap? testnull = vx_p_fieldmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_fieldsort = null;

    public Vx.Data.Table.Type_sort fieldsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      Vx.Data.Table.Type_sort? testnull = vx_p_fieldsort;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_rowmap? vx_p_rowmap = null;

    public Vx.Data.Table.Type_rowmap rowmap() {
      Vx.Data.Table.Type_rowmap output = Vx.Data.Table.e_rowmap;
      Vx.Data.Table.Type_rowmap? testnull = vx_p_rowmap;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_filter? vx_p_rowfilter = null;

    public Vx.Data.Table.Type_filter rowfilter() {
      Vx.Data.Table.Type_filter output = Vx.Data.Table.e_filter;
      Vx.Data.Table.Type_filter? testnull = vx_p_rowfilter;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_rowsort = null;

    public Vx.Data.Table.Type_sort rowsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      Vx.Data.Table.Type_sort? testnull = vx_p_rowsort;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":fieldmap")) {
        output = this.fieldmap();
      } else if ((skey==":fieldsort")) {
        output = this.fieldsort();
      } else if ((skey==":rowmap")) {
        output = this.rowmap();
      } else if ((skey==":rowfilter")) {
        output = this.rowfilter();
      } else if ((skey==":rowsort")) {
        output = this.rowsort();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":fieldmap", this.fieldmap());
      map.put(":fieldsort", this.fieldsort());
      map.put(":rowmap", this.rowmap());
      map.put(":rowfilter", this.rowfilter());
      map.put(":rowsort", this.rowsort());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Data.Table.Type_table output = Vx.Core.vx_copy(Vx.Data.Table.e_table, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Table.Type_table output = this;
      bool ischanged = false;
      Vx.Data.Table.Class_table value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Data.Table.Type_fieldmap vx_p_fieldmap = value.fieldmap();
      Vx.Data.Table.Type_sort vx_p_fieldsort = value.fieldsort();
      Vx.Data.Table.Type_rowmap vx_p_rowmap = value.rowmap();
      Vx.Data.Table.Type_filter vx_p_rowfilter = value.rowfilter();
      Vx.Data.Table.Type_sort vx_p_rowsort = value.rowsort();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":fieldmap");
      validkeys.Add(":fieldsort");
      validkeys.Add(":rowmap");
      validkeys.Add(":rowfilter");
      validkeys.Add(":rowsort");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":fieldmap")) {
            if (valsub == vx_p_fieldmap) {
            } else if (valsub is Vx.Data.Table.Type_fieldmap valfieldmap) {
              ischanged = true;
              vx_p_fieldmap = valfieldmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fieldmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":fieldsort")) {
            if (valsub == vx_p_fieldsort) {
            } else if (valsub is Vx.Data.Table.Type_sort valfieldsort) {
              ischanged = true;
              vx_p_fieldsort = valfieldsort;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fieldsort"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":rowmap")) {
            if (valsub == vx_p_rowmap) {
            } else if (valsub is Vx.Data.Table.Type_rowmap valrowmap) {
              ischanged = true;
              vx_p_rowmap = valrowmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("rowmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":rowfilter")) {
            if (valsub == vx_p_rowfilter) {
            } else if (valsub is Vx.Data.Table.Type_filter valrowfilter) {
              ischanged = true;
              vx_p_rowfilter = valrowfilter;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("rowfilter"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":rowsort")) {
            if (valsub == vx_p_rowsort) {
            } else if (valsub is Vx.Data.Table.Type_sort valrowsort) {
              ischanged = true;
              vx_p_rowsort = valrowsort;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("rowsort"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Table.Class_table work = new Vx.Data.Table.Class_table();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_fieldmap = vx_p_fieldmap;
        work.vx_p_fieldsort = vx_p_fieldsort;
        work.vx_p_rowmap = vx_p_rowmap;
        work.vx_p_rowfilter = vx_p_rowfilter;
        work.vx_p_rowsort = vx_p_rowsort;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Table.e_table;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Table.t_table;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/table", // pkgname
        "table", // name
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

  public static Vx.Data.Table.Type_table e_table = new Vx.Data.Table.Class_table();
  public static Vx.Data.Table.Type_table t_table = new Vx.Data.Table.Class_table();

  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("cell", Vx.Data.Table.t_cell);
    maptype.put("celllist", Vx.Data.Table.t_celllist);
    maptype.put("cellmap", Vx.Data.Table.t_cellmap);
    maptype.put("field", Vx.Data.Table.t_field);
    maptype.put("fieldlist", Vx.Data.Table.t_fieldlist);
    maptype.put("fieldmap", Vx.Data.Table.t_fieldmap);
    maptype.put("filter", Vx.Data.Table.t_filter);
    maptype.put("row", Vx.Data.Table.t_row);
    maptype.put("rowlist", Vx.Data.Table.t_rowlist);
    maptype.put("rowmap", Vx.Data.Table.t_rowmap);
    maptype.put("sort", Vx.Data.Table.t_sort);
    maptype.put("table", Vx.Data.Table.t_table);
    Vx.Core.vx_global_package_set("vx/data/table", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
