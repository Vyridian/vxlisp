namespace Vx.Data;

public static class Csv {


  /**
   * type: csv
   * (type csv)
   */
  public interface Type_csv : Vx.Core.Type_struct {
    public Vx.Core.Type_stringlist headers();
    public Vx.Data.Csv.Type_csvrows rows();
  }

  public class Class_csv : Vx.Core.Class_base, Type_csv {

    public Vx.Core.Type_stringlist? vx_p_headers = null;

    public Vx.Core.Type_stringlist headers() {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      if (this.vx_p_headers != null) {
        output = this.vx_p_headers;
      }
      return output;
    }

    public Vx.Data.Csv.Type_csvrows? vx_p_rows = null;

    public Vx.Data.Csv.Type_csvrows rows() {
      Vx.Data.Csv.Type_csvrows output = Vx.Data.Csv.e_csvrows;
      if (this.vx_p_rows != null) {
        output = this.vx_p_rows;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":headers":
        output = this.headers();
        break;
      case ":rows":
        output = this.rows();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":headers", this.headers());
      output.put(":rows", this.rows());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Data.Csv.Type_csv vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_csv,
       vals);
    }

    public override Vx.Data.Csv.Type_csv vx_copy(params Object[] vals) {
      Type_csv output = this;
      bool ischanged = false;
      Class_csv val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_stringlist vx_p_headers = val.headers();
      Vx.Data.Csv.Type_csvrows vx_p_rows = val.rows();
      List<string> validkeys = new List<string>();
      validkeys.Add(":headers");
      validkeys.Add(":rows");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":headers":
            if (valsub == vx_p_headers) {
            } else if (valsub is Vx.Core.Type_stringlist valheaders) {
              ischanged = true;
              vx_p_headers = valheaders;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("headers"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":rows":
            if (valsub == vx_p_rows) {
            } else if (valsub is Vx.Data.Csv.Type_csvrows valrows) {
              ischanged = true;
              vx_p_rows = valrows;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("rows"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_csv work = new Class_csv();
        work.vx_p_headers = vx_p_headers;
        work.vx_p_rows = vx_p_rows;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csv;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_csv;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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

  public static Type_csv e_csv = new Class_csv();
  public static Type_csv t_csv = new Class_csv();

  /**
   * type: csvrowmap
   * (type csvrowmap)
   */
  public interface Type_csvrowmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Core.Type_stringlist> vx_mapstringlist();
    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_string key);
  }

  public class Class_csvrowmap : Vx.Core.Class_base, Type_csvrowmap {

    public Vx.Core.Map<string, Vx.Core.Type_stringlist> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_stringlist>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = (Vx.Core.Map<string, Vx.Core.Type_any>)Convert.ChangeType(this.vx_p_map, typeof(Vx.Core.Map<string, Vx.Core.Type_any>));
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Core.Type_stringlist castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Core.Type_stringlist> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_stringlist>(this.vx_p_map);
        if (castval == Vx.Core.e_stringlist) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_string key) {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      Vx.Data.Csv.Class_csvrowmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_stringlist> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_stringlist);
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_stringlist> vx_mapstringlist() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_stringlist(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Data.Csv.Class_csvrowmap output = new Vx.Data.Csv.Class_csvrowmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_stringlist> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_stringlist>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_stringlist castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Data.Csv.Type_csvrowmap vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_csvrowmap,
       vals);
    }

    public override Vx.Data.Csv.Type_csvrowmap vx_copy(params Object[] vals) {
      Type_csvrowmap output = this;
      bool ischanged = false;
      Class_csvrowmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_stringlist> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_stringlist>(val.vx_mapstringlist());
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
            msg = Vx.Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_stringlist? valany = null;
          if (false) {
          } else if (valsub is Vx.Core.Type_stringlist valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Core.Type_stringlist) {
            valany = valsub as Vx.Core.Type_stringlist;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidkeyvalue", msgmap);
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
        Class_csvrowmap work = new Class_csvrowmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csvrowmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_csvrowmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrowmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_stringlist), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_csvrowmap e_csvrowmap = new Class_csvrowmap();
  public static Type_csvrowmap t_csvrowmap = new Class_csvrowmap();

  /**
   * type: csvrows
   * (type csvrows)
   */
  public interface Type_csvrows : Vx.Core.Type_list {
    public List<Vx.Core.Type_stringlist> vx_liststringlist();
    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_int index);
  }

  public class Class_csvrows : Vx.Core.Class_base, Type_csvrows {

    public List<Vx.Core.Type_stringlist> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_stringlist>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_stringlist vx_stringlist(Vx.Core.Type_int index) {
      Vx.Core.Type_stringlist output = Vx.Core.e_stringlist;
      Vx.Data.Csv.Class_csvrows list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_stringlist> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_stringlist> vx_liststringlist() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_stringlist(index);
    }

    public override Vx.Data.Csv.Type_csvrows vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_csvrows,
       vals);
    }

    public override Vx.Data.Csv.Type_csvrows vx_copy(params Object[] vals) {
      Type_csvrows output = this;
      bool ischanged = false;
      Class_csvrows val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_stringlist> listval = new List<Vx.Core.Type_stringlist>(val.vx_liststringlist());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_stringlist allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_stringlist) {
          ischanged = true;
          listval.Add((Vx.Core.Type_stringlist)valsub);
        } else if (valsub is Vx.Data.Csv.Type_csvrows multi) {
          ischanged = true;
          listval.AddRange(multi.vx_liststringlist());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Core.Type_stringlist valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_csvrows work = new Class_csvrows();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csvrows;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_csvrows;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_stringlist), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_csvrows e_csvrows = new Class_csvrows();
  public static Type_csvrows t_csvrows = new Class_csvrows();

  /**
   * Constant: delimcsv
   * Csv File Delimiters
   * {delim}
   */
  public class Const_delimcsv : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/data/csv", // pkgname
        "delimcsv", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_delimcsv output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimcsv"),
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_delimlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Data.Textblock.c_delimline,
                    Vx.Data.Textblock.c_delimquote,
                    Vx.Data.Textblock.c_delimcomma
                  )
                )
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimcsv c_delimcsv = new Const_delimcsv();

  /**
   * @function csv_read_from_file
   * Returns a parsed csv from a file.
   * @param  {file} file
   * @return {csv}
   * (func csv-read<-file)
   */
  public interface Func_csv_read_from_file : Vx.Core.Func_any_from_any_context {
    public Vx.Data.Csv.Type_csv vx_csv_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file);
  }

  public class Class_csv_read_from_file : Vx.Core.Class_base, Func_csv_read_from_file {

    public override Vx.Data.Csv.Func_csv_read_from_file vx_new(params Object[] vals) {
      Class_csv_read_from_file output = new Class_csv_read_from_file();
      return output;
    }

    public override Vx.Data.Csv.Func_csv_read_from_file vx_copy(params Object[] vals) {
      Class_csv_read_from_file output = new Class_csv_read_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv-read<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csv_read_from_file;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_csv_read_from_file;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_csv_read_from_file(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_csv_read_from_file(context, file);
      return output;
    }

    public Vx.Data.Csv.Type_csv vx_csv_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
      return Vx.Data.Csv.f_csv_read_from_file(context, file);
    }

  }

  public static Func_csv_read_from_file e_csv_read_from_file = new Vx.Data.Csv.Class_csv_read_from_file();
  public static Func_csv_read_from_file t_csv_read_from_file = new Vx.Data.Csv.Class_csv_read_from_file();

  public static Vx.Data.Csv.Type_csv f_csv_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
    Vx.Data.Csv.Type_csv output = Vx.Data.Csv.e_csv;
    output = Vx.Core.f_let(
      Vx.Data.Csv.t_csv,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.File.Type_file loaded = Vx.Data.File.f_file_read_from_file(context, file);
        Vx.Core.Type_any output_1 = Vx.Data.Csv.f_csv_from_file(loaded);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function csv_from_file
   * Returns a parsed csv from a file.
   * @param  {file} file
   * @return {csv}
   * (func csv<-file)
   */
  public interface Func_csv_from_file : Vx.Core.Func_any_from_any {
    public Vx.Data.Csv.Type_csv vx_csv_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_csv_from_file : Vx.Core.Class_base, Func_csv_from_file {

    public override Vx.Data.Csv.Func_csv_from_file vx_new(params Object[] vals) {
      Class_csv_from_file output = new Class_csv_from_file();
      return output;
    }

    public override Vx.Data.Csv.Func_csv_from_file vx_copy(params Object[] vals) {
      Class_csv_from_file output = new Class_csv_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csv_from_file;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_csv_from_file;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_csv_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_csv_from_file(file);
      return output;
    }

    public Vx.Data.Csv.Type_csv vx_csv_from_file(Vx.Data.File.Type_file file) {
      return Vx.Data.Csv.f_csv_from_file(file);
    }

  }

  public static Func_csv_from_file e_csv_from_file = new Vx.Data.Csv.Class_csv_from_file();
  public static Func_csv_from_file t_csv_from_file = new Vx.Data.Csv.Class_csv_from_file();

  public static Vx.Data.Csv.Type_csv f_csv_from_file(Vx.Data.File.Type_file file) {
    Vx.Data.Csv.Type_csv output = Vx.Data.Csv.e_csv;
    output = Vx.Core.f_let(
      Vx.Data.Csv.t_csv,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = file.text();
        Vx.Core.Type_any output_1 = Vx.Data.Csv.f_csv_from_string(text);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function csv_from_string
   * Returns a parsed csv from a string.
   * @param  {string} text
   * @return {csv}
   * (func csv<-string)
   */
  public interface Func_csv_from_string : Vx.Core.Func_any_from_any {
    public Vx.Data.Csv.Type_csv vx_csv_from_string(Vx.Core.Type_string text);
  }

  public class Class_csv_from_string : Vx.Core.Class_base, Func_csv_from_string {

    public override Vx.Data.Csv.Func_csv_from_string vx_new(params Object[] vals) {
      Class_csv_from_string output = new Class_csv_from_string();
      return output;
    }

    public override Vx.Data.Csv.Func_csv_from_string vx_copy(params Object[] vals) {
      Class_csv_from_string output = new Class_csv_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csv_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_csv_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_csv_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_csv_from_string(text);
      return output;
    }

    public Vx.Data.Csv.Type_csv vx_csv_from_string(Vx.Core.Type_string text) {
      return Vx.Data.Csv.f_csv_from_string(text);
    }

  }

  public static Func_csv_from_string e_csv_from_string = new Vx.Data.Csv.Class_csv_from_string();
  public static Func_csv_from_string t_csv_from_string = new Vx.Data.Csv.Class_csv_from_string();

  public static Vx.Data.Csv.Type_csv f_csv_from_string(Vx.Core.Type_string text) {
    Vx.Data.Csv.Type_csv output = Vx.Data.Csv.e_csv;
    output = Vx.Data.Csv.f_csv_from_textblock(
      Vx.Data.Textblock.f_textblock_parse_from_string_delim(
        text,
        Vx.Data.Csv.c_delimcsv
      )
    );
    return output;
  }

  /**
   * @function csv_from_textblock
   * Returns a parsed csv from a textblock.
   * @param  {textblock} textblock
   * @return {csv}
   * (func csv<-textblock)
   */
  public interface Func_csv_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Data.Csv.Type_csv vx_csv_from_textblock(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_csv_from_textblock : Vx.Core.Class_base, Func_csv_from_textblock {

    public override Vx.Data.Csv.Func_csv_from_textblock vx_new(params Object[] vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    public override Vx.Data.Csv.Func_csv_from_textblock vx_copy(params Object[] vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csv_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_csv_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_csv_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_csv_from_textblock(textblock);
      return output;
    }

    public Vx.Data.Csv.Type_csv vx_csv_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
      return Vx.Data.Csv.f_csv_from_textblock(textblock);
    }

  }

  public static Func_csv_from_textblock e_csv_from_textblock = new Vx.Data.Csv.Class_csv_from_textblock();
  public static Func_csv_from_textblock t_csv_from_textblock = new Vx.Data.Csv.Class_csv_from_textblock();

  public static Vx.Data.Csv.Type_csv f_csv_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Data.Csv.Type_csv output = Vx.Data.Csv.e_csv;
    output = Vx.Core.f_let(
      Vx.Data.Csv.t_csv,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Csv.Type_csvrows allrows = Vx.Data.Csv.f_csvrows_from_textblock(textblock);
        Vx.Core.Type_stringlist headers = Vx.Core.f_any_from_list(Vx.Core.t_stringlist, allrows, Vx.Core.vx_new_int(1));
        Vx.Data.Csv.Type_csvrows rows = Vx.Collection.f_list_from_list_end(Vx.Data.Csv.t_csvrows, allrows, Vx.Core.vx_new_int(2));
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Data.Csv.t_csv,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":headers"),
            headers,
            Vx.Core.vx_new_string(":rows"),
            rows
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function csvrows_from_textblock
   * @param  {textblock} textblock
   * @return {csvrows}
   * (func csvrows<-textblock)
   */
  public interface Func_csvrows_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Data.Csv.Type_csvrows vx_csvrows_from_textblock(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_csvrows_from_textblock : Vx.Core.Class_base, Func_csvrows_from_textblock {

    public override Vx.Data.Csv.Func_csvrows_from_textblock vx_new(params Object[] vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    public override Vx.Data.Csv.Func_csvrows_from_textblock vx_copy(params Object[] vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csvrows", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_stringlist), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_csvrows_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_csvrows_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_csvrows_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_csvrows_from_textblock(textblock);
      return output;
    }

    public Vx.Data.Csv.Type_csvrows vx_csvrows_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
      return Vx.Data.Csv.f_csvrows_from_textblock(textblock);
    }

  }

  public static Func_csvrows_from_textblock e_csvrows_from_textblock = new Vx.Data.Csv.Class_csvrows_from_textblock();
  public static Func_csvrows_from_textblock t_csvrows_from_textblock = new Vx.Data.Csv.Class_csvrows_from_textblock();

  public static Vx.Data.Csv.Type_csvrows f_csvrows_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Data.Csv.Type_csvrows output = Vx.Data.Csv.e_csvrows;
    output = Vx.Core.f_let(
      Vx.Data.Csv.t_csvrows,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblock parsedtb = Vx.Data.Textblock.f_textblock_from_textblock_delim(
          textblock,
          Vx.Data.Csv.c_delimcsv
        );
        Vx.Data.Textblock.Type_textblocklist children = Vx.Data.Textblock.f_children_from_textblock(parsedtb);
        Vx.Core.Type_stringlist strings = Vx.Data.Textblock.f_stringlist_from_textblocklist(children);
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Data.Csv.t_csvrows,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            strings
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function stringmap_from_csv
   * Returns a stringmap using the first 2 values in each row.
   * @param  {csv} csv
   * @return {stringmap}
   * (func stringmap<-csv)
   */
  public interface Func_stringmap_from_csv : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_stringmap vx_stringmap_from_csv(Vx.Data.Csv.Type_csv csv);
  }

  public class Class_stringmap_from_csv : Vx.Core.Class_base, Func_stringmap_from_csv {

    public override Vx.Data.Csv.Func_stringmap_from_csv vx_new(params Object[] vals) {
      Class_stringmap_from_csv output = new Class_stringmap_from_csv();
      return output;
    }

    public override Vx.Data.Csv.Func_stringmap_from_csv vx_copy(params Object[] vals) {
      Class_stringmap_from_csv output = new Class_stringmap_from_csv();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "stringmap<-csv", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stringmap_from_csv;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stringmap_from_csv;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Csv.Type_csv inputval = (Vx.Data.Csv.Type_csv)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_stringmap_from_csv(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Csv.Type_csv csv = Vx.Core.f_any_from_any(Vx.Data.Csv.t_csv, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_stringmap_from_csv(csv);
      return output;
    }

    public Vx.Core.Type_stringmap vx_stringmap_from_csv(Vx.Data.Csv.Type_csv csv) {
      return Vx.Data.Csv.f_stringmap_from_csv(csv);
    }

  }

  public static Func_stringmap_from_csv e_stringmap_from_csv = new Vx.Data.Csv.Class_stringmap_from_csv();
  public static Func_stringmap_from_csv t_stringmap_from_csv = new Vx.Data.Csv.Class_stringmap_from_csv();

  public static Vx.Core.Type_stringmap f_stringmap_from_csv(Vx.Data.Csv.Type_csv csv) {
    Vx.Core.Type_stringmap output = Vx.Core.e_stringmap;
    output = Vx.Core.f_let(
      Vx.Core.t_stringmap,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Csv.Type_csvrows rows = csv.rows();
        Vx.Data.Csv.Type_csvrowmap rowmap = Vx.Core.f_map_from_list(
          Vx.Data.Csv.t_csvrowmap,
          rows,
          Vx.Core.t_any_from_any.vx_fn_new((textlist_any) => {
            Vx.Core.Type_stringlist textlist = Vx.Core.f_any_from_any(Vx.Core.t_stringlist, textlist_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_any_from_list(Vx.Core.t_string, textlist, Vx.Core.vx_new_int(1));
            return output_1;
          })
        );
        Vx.Core.Type_any output_3 = Vx.Core.f_map_from_map_1(
          Vx.Core.t_stringmap,
          rowmap,
          Vx.Core.t_any_from_key_value.vx_fn_new((key_any, val_any) => {
            Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
            Vx.Core.Type_stringlist val = Vx.Core.f_any_from_any(Vx.Core.t_stringlist, val_any);
            Vx.Core.Type_any output_2 = 
              Vx.Core.f_any_from_list(Vx.Core.t_string, val, Vx.Core.vx_new_int(2));
            return output_2;
          })
        );
        return output_3;
      })
    );
    return output;
  }

  /**
   * @function textblock_csv_from_string
   * Returns a parsed csv-textblock from a string.
   * @param  {string} text
   * @return {textblock}
   * (func textblock-csv<-string)
   */
  public interface Func_textblock_csv_from_string : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_csv_from_string(Vx.Core.Type_string text);
  }

  public class Class_textblock_csv_from_string : Vx.Core.Class_base, Func_textblock_csv_from_string {

    public override Vx.Data.Csv.Func_textblock_csv_from_string vx_new(params Object[] vals) {
      Class_textblock_csv_from_string output = new Class_textblock_csv_from_string();
      return output;
    }

    public override Vx.Data.Csv.Func_textblock_csv_from_string vx_copy(params Object[] vals) {
      Class_textblock_csv_from_string output = new Class_textblock_csv_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_textblock_csv_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_csv_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.Csv.f_textblock_csv_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.Csv.f_textblock_csv_from_string(text);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_csv_from_string(Vx.Core.Type_string text) {
      return Vx.Data.Csv.f_textblock_csv_from_string(text);
    }

  }

  public static Func_textblock_csv_from_string e_textblock_csv_from_string = new Vx.Data.Csv.Class_textblock_csv_from_string();
  public static Func_textblock_csv_from_string t_textblock_csv_from_string = new Vx.Data.Csv.Class_textblock_csv_from_string();

  public static Vx.Data.Textblock.Type_textblock f_textblock_csv_from_string(Vx.Core.Type_string text) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Data.Textblock.f_textblock_parse_from_string_delim(
      text,
      Vx.Data.Csv.c_delimcsv
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_delimcsv.const_new(c_delimcsv);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("csv", Vx.Data.Csv.t_csv);
    maptype.put("csvrowmap", Vx.Data.Csv.t_csvrowmap);
    maptype.put("csvrows", Vx.Data.Csv.t_csvrows);
    mapconst.put("delimcsv", Vx.Data.Csv.c_delimcsv);
    mapfunc.put("csv-read<-file", Vx.Data.Csv.t_csv_read_from_file);
    mapfunc.put("csv<-file", Vx.Data.Csv.t_csv_from_file);
    mapfunc.put("csv<-string", Vx.Data.Csv.t_csv_from_string);
    mapfunc.put("csv<-textblock", Vx.Data.Csv.t_csv_from_textblock);
    mapfunc.put("csvrows<-textblock", Vx.Data.Csv.t_csvrows_from_textblock);
    mapfunc.put("stringmap<-csv", Vx.Data.Csv.t_stringmap_from_csv);
    mapfunc.put("textblock-csv<-string", Vx.Data.Csv.t_textblock_csv_from_string);
    Vx.Core.vx_global_package_set("vx/data/csv", maptype, mapconst, mapfunc);
    }
  }

}
