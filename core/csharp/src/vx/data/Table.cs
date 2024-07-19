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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
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
      case ":id":
        output = this.id();
        break;
      case ":value":
        output = this.value();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":value", this.value());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_cell vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_cell,
       vals);
    }

    public override Vx.Data.Table.Type_cell vx_copy(params Object[] vals) {
      Type_cell output = this;
      bool ischanged = false;
      Class_cell val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Core.Type_any vx_p_value = val.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
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
          switch (key) {
          case ":id":
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
              msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cell", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_cell work = new Class_cell();
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
      return e_cell;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_cell;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_cell e_cell = new Class_cell();
  public static Type_cell t_cell = new Class_cell();

  /**
   * type: celllist
   * (type celllist)
   */
  public interface Type_celllist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_cell> vx_listcell();
    public Vx.Data.Table.Type_cell vx_cell(Vx.Core.Type_int index);
  }

  public class Class_celllist : Vx.Core.Class_base, Type_celllist {

    public List<Vx.Data.Table.Type_cell> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Table.Type_cell>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_cell(index);
    }

    public override Vx.Data.Table.Type_celllist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_celllist,
       vals);
    }

    public override Vx.Data.Table.Type_celllist vx_copy(params Object[] vals) {
      Type_celllist output = this;
      bool ischanged = false;
      Class_celllist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_cell> listval = new List<Vx.Data.Table.Type_cell>(val.vx_listcell());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_cell allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_cell) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_cell)valsub);
        } else if (valsub is Vx.Data.Table.Type_celllist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listcell());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
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
        Class_celllist work = new Class_celllist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_celllist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_celllist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_celllist e_celllist = new Class_celllist();
  public static Type_celllist t_celllist = new Class_celllist();

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
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)Convert.ChangeType(this.vx_p_map, typeof(Vx.Core.Map<string, Vx.Core.Type_any>));
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
      output = mapval.getOrDefault(skey, Vx.Data.Table.e_cell);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Table.Type_cell> vx_mapcell() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_cell(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Table.Class_cellmap output = new Vx.Data.Table.Class_cellmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Data.Table.Type_cell castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/table/cellmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Table.Type_cellmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_cellmap,
       vals);
    }

    public override Vx.Data.Table.Type_cellmap vx_copy(params Object[] vals) {
      Type_cellmap output = this;
      bool ischanged = false;
      Class_cellmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Table.Type_cell> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_cell>(val.vx_mapcell());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/cellmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Table.Type_cell? valany = null;
          if (false) {
          } else if (valsub is Vx.Data.Table.Type_cell valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Table.Type_cell) {
            valany = valsub as Vx.Data.Table.Type_cell;
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
        Class_cellmap work = new Class_cellmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_cellmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_cellmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_cellmap e_cellmap = new Class_cellmap();
  public static Type_cellmap t_cellmap = new Class_cellmap();

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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_fldtype = null;

    public Vx.Core.Type_any fldtype() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_fldtype != null) {
        output = this.vx_p_fldtype;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":fldtype", this.fldtype());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_field vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_field,
       vals);
    }

    public override Vx.Data.Table.Type_field vx_copy(params Object[] vals) {
      Type_field output = this;
      bool ischanged = false;
      Class_field val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_any vx_p_fldtype = val.fldtype();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":fldtype");
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
          switch (key) {
          case ":id":
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
            break;
          case ":name":
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
            break;
          case ":fldtype":
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
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/field", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_field work = new Class_field();
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
      return e_field;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_field;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_field e_field = new Class_field();
  public static Type_field t_field = new Class_field();

  /**
   * type: fieldlist
   * (type fieldlist)
   */
  public interface Type_fieldlist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_field> vx_listfield();
    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index);
  }

  public class Class_fieldlist : Vx.Core.Class_base, Type_fieldlist {

    public List<Vx.Data.Table.Type_field> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Table.Type_field>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_field(index);
    }

    public override Vx.Data.Table.Type_fieldlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fieldlist,
       vals);
    }

    public override Vx.Data.Table.Type_fieldlist vx_copy(params Object[] vals) {
      Type_fieldlist output = this;
      bool ischanged = false;
      Class_fieldlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_field> listval = new List<Vx.Data.Table.Type_field>(val.vx_listfield());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_field allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_field) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_field)valsub);
        } else if (valsub is Vx.Data.Table.Type_fieldlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfield());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
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
        Class_fieldlist work = new Class_fieldlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fieldlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fieldlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fieldlist e_fieldlist = new Class_fieldlist();
  public static Type_fieldlist t_fieldlist = new Class_fieldlist();

  /**
   * type: fieldmap
   * (type fieldmap)
   */
  public interface Type_fieldmap : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_field> vx_listfield();
    public Vx.Data.Table.Type_field vx_field(Vx.Core.Type_int index);
  }

  public class Class_fieldmap : Vx.Core.Class_base, Type_fieldmap {

    public List<Vx.Data.Table.Type_field> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Table.Type_field>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_field(index);
    }

    public override Vx.Data.Table.Type_fieldmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_fieldmap,
       vals);
    }

    public override Vx.Data.Table.Type_fieldmap vx_copy(params Object[] vals) {
      Type_fieldmap output = this;
      bool ischanged = false;
      Class_fieldmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_field> listval = new List<Vx.Data.Table.Type_field>(val.vx_listfield());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_field allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_field) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_field)valsub);
        } else if (valsub is Vx.Data.Table.Type_fieldmap multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfield());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
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
        Class_fieldmap work = new Class_fieldmap();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_fieldmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_fieldmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_fieldmap e_fieldmap = new Class_fieldmap();
  public static Type_fieldmap t_fieldmap = new Class_fieldmap();

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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_stringlist? vx_p_idlist = null;

    public Vx.Core.Type_stringlist idlist() {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      if (this.vx_p_idlist != null) {
        output = this.vx_p_idlist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_filter vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_filter,
       vals);
    }

    public override Vx.Data.Table.Type_filter vx_copy(params Object[] vals) {
      Type_filter output = this;
      bool ischanged = false;
      Class_filter val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_stringlist vx_p_idlist = val.idlist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":idlist");
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
          switch (key) {
          case ":id":
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
            break;
          case ":name":
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
            break;
          case ":idlist":
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
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/filter", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_filter work = new Class_filter();
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
      return e_filter;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_filter;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_filter e_filter = new Class_filter();
  public static Type_filter t_filter = new Class_filter();

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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Data.Table.Type_cellmap? vx_p_cellmap = null;

    public Vx.Data.Table.Type_cellmap cellmap() {
      Vx.Data.Table.Type_cellmap output = Vx.Data.Table.e_cellmap;
      if (this.vx_p_cellmap != null) {
        output = this.vx_p_cellmap;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_cellsort = null;

    public Vx.Data.Table.Type_sort cellsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      if (this.vx_p_cellsort != null) {
        output = this.vx_p_cellsort;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":cellmap", this.cellmap());
      output.put(":cellsort", this.cellsort());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_row vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_row,
       vals);
    }

    public override Vx.Data.Table.Type_row vx_copy(params Object[] vals) {
      Type_row output = this;
      bool ischanged = false;
      Class_row val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Data.Table.Type_cellmap vx_p_cellmap = val.cellmap();
      Vx.Data.Table.Type_sort vx_p_cellsort = val.cellsort();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":cellmap");
      validkeys.Add(":cellsort");
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
          switch (key) {
          case ":id":
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
            break;
          case ":cellmap":
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
            break;
          case ":cellsort":
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
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/row", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_row work = new Class_row();
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
      return e_row;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_row;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_row e_row = new Class_row();
  public static Type_row t_row = new Class_row();

  /**
   * type: rowlist
   * (type rowlist)
   */
  public interface Type_rowlist : Vx.Core.Type_list {
    public List<Vx.Data.Table.Type_row> vx_listrow();
    public Vx.Data.Table.Type_row vx_row(Vx.Core.Type_int index);
  }

  public class Class_rowlist : Vx.Core.Class_base, Type_rowlist {

    public List<Vx.Data.Table.Type_row> vx_p_list = Vx.Core.immutablelist(new List<Vx.Data.Table.Type_row>());

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
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_row(index);
    }

    public override Vx.Data.Table.Type_rowlist vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_rowlist,
       vals);
    }

    public override Vx.Data.Table.Type_rowlist vx_copy(params Object[] vals) {
      Type_rowlist output = this;
      bool ischanged = false;
      Class_rowlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Data.Table.Type_row> listval = new List<Vx.Data.Table.Type_row>(val.vx_listrow());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Table.Type_row allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Table.Type_row) {
          ischanged = true;
          listval.Add((Vx.Data.Table.Type_row)valsub);
        } else if (valsub is Vx.Data.Table.Type_rowlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listrow());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
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
        Class_rowlist work = new Class_rowlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_rowlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_rowlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_rowlist e_rowlist = new Class_rowlist();
  public static Type_rowlist t_rowlist = new Class_rowlist();

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
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)Convert.ChangeType(this.vx_p_map, typeof(Vx.Core.Map<string, Vx.Core.Type_any>));
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
      output = mapval.getOrDefault(skey, Vx.Data.Table.e_row);
      return output;
    }

    public Vx.Core.Map<string, Vx.Data.Table.Type_row> vx_maprow() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_row(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Table.Class_rowmap output = new Vx.Data.Table.Class_rowmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Data.Table.Type_row> map = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Data.Table.Type_row castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/table/rowmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Table.Type_rowmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_rowmap,
       vals);
    }

    public override Vx.Data.Table.Type_rowmap vx_copy(params Object[] vals) {
      Type_rowmap output = this;
      bool ischanged = false;
      Class_rowmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Data.Table.Type_row> mapval = new Vx.Core.LinkedHashMap<string, Vx.Data.Table.Type_row>(val.vx_maprow());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/table/rowmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Data.Table.Type_row? valany = null;
          if (false) {
          } else if (valsub is Vx.Data.Table.Type_row valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Data.Table.Type_row) {
            valany = valsub as Vx.Data.Table.Type_row;
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
        Class_rowmap work = new Class_rowmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_rowmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_rowmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_rowmap e_rowmap = new Class_rowmap();
  public static Type_rowmap t_rowmap = new Class_rowmap();

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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_stringlist? vx_p_idlist = null;

    public Vx.Core.Type_stringlist idlist() {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      if (this.vx_p_idlist != null) {
        output = this.vx_p_idlist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":idlist", this.idlist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_sort vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_sort,
       vals);
    }

    public override Vx.Data.Table.Type_sort vx_copy(params Object[] vals) {
      Type_sort output = this;
      bool ischanged = false;
      Class_sort val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_stringlist vx_p_idlist = val.idlist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":idlist");
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
          switch (key) {
          case ":id":
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
            break;
          case ":name":
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
            break;
          case ":idlist":
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
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/sort", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_sort work = new Class_sort();
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
      return e_sort;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_sort;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_sort e_sort = new Class_sort();
  public static Type_sort t_sort = new Class_sort();

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
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Data.Table.Type_fieldmap? vx_p_fieldmap = null;

    public Vx.Data.Table.Type_fieldmap fieldmap() {
      Vx.Data.Table.Type_fieldmap output = Vx.Data.Table.e_fieldmap;
      if (this.vx_p_fieldmap != null) {
        output = this.vx_p_fieldmap;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_fieldsort = null;

    public Vx.Data.Table.Type_sort fieldsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      if (this.vx_p_fieldsort != null) {
        output = this.vx_p_fieldsort;
      }
      return output;
    }

    public Vx.Data.Table.Type_rowmap? vx_p_rowmap = null;

    public Vx.Data.Table.Type_rowmap rowmap() {
      Vx.Data.Table.Type_rowmap output = Vx.Data.Table.e_rowmap;
      if (this.vx_p_rowmap != null) {
        output = this.vx_p_rowmap;
      }
      return output;
    }

    public Vx.Data.Table.Type_filter? vx_p_rowfilter = null;

    public Vx.Data.Table.Type_filter rowfilter() {
      Vx.Data.Table.Type_filter output = Vx.Data.Table.e_filter;
      if (this.vx_p_rowfilter != null) {
        output = this.vx_p_rowfilter;
      }
      return output;
    }

    public Vx.Data.Table.Type_sort? vx_p_rowsort = null;

    public Vx.Data.Table.Type_sort rowsort() {
      Vx.Data.Table.Type_sort output = Vx.Data.Table.e_sort;
      if (this.vx_p_rowsort != null) {
        output = this.vx_p_rowsort;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":fieldmap", this.fieldmap());
      output.put(":fieldsort", this.fieldsort());
      output.put(":rowmap", this.rowmap());
      output.put(":rowfilter", this.rowfilter());
      output.put(":rowsort", this.rowsort());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Table.Type_table vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_table,
       vals);
    }

    public override Vx.Data.Table.Type_table vx_copy(params Object[] vals) {
      Type_table output = this;
      bool ischanged = false;
      Class_table val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = val.id();
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Data.Table.Type_fieldmap vx_p_fieldmap = val.fieldmap();
      Vx.Data.Table.Type_sort vx_p_fieldsort = val.fieldsort();
      Vx.Data.Table.Type_rowmap vx_p_rowmap = val.rowmap();
      Vx.Data.Table.Type_filter vx_p_rowfilter = val.rowfilter();
      Vx.Data.Table.Type_sort vx_p_rowsort = val.rowsort();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":fieldmap");
      validkeys.Add(":fieldsort");
      validkeys.Add(":rowmap");
      validkeys.Add(":rowfilter");
      validkeys.Add(":rowsort");
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
          switch (key) {
          case ":id":
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
            break;
          case ":name":
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
            break;
          case ":fieldmap":
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
            break;
          case ":fieldsort":
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
            break;
          case ":rowmap":
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
            break;
          case ":rowfilter":
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
            break;
          case ":rowsort":
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
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/table/table", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_table work = new Class_table();
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
      return e_table;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_table;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
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
    }

  }

  public static Type_table e_table = new Class_table();
  public static Type_table t_table = new Class_table();

  public static class PackageRunOnce {
    public static void RunOnce() {
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
    }
  }

}
