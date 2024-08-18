namespace Vx.Data;

public static class File {

  public static Vx.Core.Type_boolean vx_boolean_exists_from_file(
    Vx.Data.File.Type_file file) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    Vx.Core.Type_string fullpath = File.f_pathfull_from_file(file);
    string sfullpath = fullpath.vx_string();
    sfullpath = vx_path_normalize_from_path(sfullpath);
    if (System.IO.File.Exists(sfullpath)) {
      output = Core.c_true;
    }
    return output;
  }

  public static Vx.Core.Type_boolean vx_boolean_write_from_file_string(
    Vx.Core.Type_context context,
    Vx.Data.File.Type_file file,
    Vx.Core.Type_string text) {
    Vx.Core.Type_boolean output = Vx.Core.c_false;
    Core.Type_string fullpath = File.f_pathfull_from_file(file);
    string sfullpath = fullpath.vx_string();
    sfullpath = vx_path_normalize_from_path(sfullpath);
    string stext = text.vx_string();
    try {
      System.IO.File.WriteAllText(sfullpath, stext);
      output = Vx.Core.c_true;
    } catch (Exception ex) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("boolean-write<-file", ex);
      output = Vx.Core.vx_copy(Vx.Core.c_false, msg);
    }
    return output;
  }

  public static string vx_path_normalize_from_path(string spath) {
    string output = spath;
    if (spath.IndexOf(":") < 0) {
      string pathcurrent = vx_spathcurrent_from_os();
      output = pathcurrent + "/" + output;
    }
    return output;
  }

  public static Vx.Core.Type_string vx_pathcurrent_from_os() {
    string stext = vx_spathcurrent_from_os();
    Vx.Core.Type_string output = Vx.Core.vx_new_string(stext);
    return output;
  }

  public static string vx_spathcurrent_from_os() {
    string output = System.Environment.CurrentDirectory;
    int ipos = output.IndexOf("\\test\\AppTest");
    if (ipos >= 0) {
      output = Vx.Core.vx_string_from_string_start_end(output, 1, ipos);
    }
    return output;
  }

  public static Vx.Core.Type_string vx_string_read_from_file(
    Vx.Data.File.Type_file file) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    Vx.Core.Type_string fullpath = File.f_pathfull_from_file(file);
    string sfullpath = fullpath.vx_string();
    sfullpath = vx_path_normalize_from_path(sfullpath);
    if (System.IO.File.Exists(sfullpath)) {
      try {
        string scontent = System.IO.File.ReadAllText(sfullpath);
        output = Vx.Core.vx_new_string(scontent);
      } catch (Exception ex) {
        Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("string-read<-file", ex);
        output = Vx.Core.vx_copy(output, msg);
      }
    } else {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("string-read<-file", ":filenotfound", file);
      output = Vx.Core.vx_copy(output, msg);
    }
    return output;
  }

  public static Vx.Core.Type_string vx_string_read_from_file(
    Vx.Core.Type_context context,
    Vx.Data.File.Type_file file) {
    return vx_string_read_from_file(file);
  }

  /**
   * type: file
   * File structure
   * (type file)
   */
  public interface Type_file : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Data.File.Type_fileformat format();
    public Vx.Core.Type_string path();
    public Vx.Core.Type_permission permission();
    public Vx.Core.Type_string text();
  }

  public class Class_file : Vx.Core.Class_base, Type_file {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Data.File.Type_fileformat? vx_p_format = null;

    public Vx.Data.File.Type_fileformat format() {
      Vx.Data.File.Type_fileformat output = Vx.Data.File.e_fileformat;
      if (this.vx_p_format != null) {
        output = this.vx_p_format;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_path = null;

    public Vx.Core.Type_string path() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_path != null) {
        output = this.vx_p_path;
      }
      return output;
    }

    public Vx.Core.Type_permission? vx_p_permission = null;

    public Vx.Core.Type_permission permission() {
      Vx.Core.Type_permission output = Vx.Core.e_permission;
      if (this.vx_p_permission != null) {
        output = this.vx_p_permission;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_text = null;

    public Vx.Core.Type_string text() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_text != null) {
        output = this.vx_p_text;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":format":
        output = this.format();
        break;
      case ":path":
        output = this.path();
        break;
      case ":permission":
        output = this.permission();
        break;
      case ":text":
        output = this.text();
        break;
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":format", this.format());
      output.put(":path", this.path());
      output.put(":permission", this.permission());
      output.put(":text", this.text());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Data.File.Type_file vx_new(params object[] vals) {
      Vx.Data.File.Type_file output = Vx.Core.vx_copy(Vx.Data.File.e_file, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Type_file output = this;
      bool ischanged = false;
      Vx.Data.File.Class_file value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Data.File.Type_fileformat vx_p_format = value.format();
      Vx.Core.Type_string vx_p_path = value.path();
      Vx.Core.Type_permission vx_p_permission = value.permission();
      Vx.Core.Type_string vx_p_text = value.text();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":format");
      validkeys.Add(":path");
      validkeys.Add(":permission");
      validkeys.Add(":text");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
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
            msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
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
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":format":
            if (valsub == vx_p_format) {
            } else if (valsub is Vx.Data.File.Type_fileformat valformat) {
              ischanged = true;
              vx_p_format = valformat;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("format"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub is Vx.Core.Type_string valpath) {
              ischanged = true;
              vx_p_path = valpath;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_path = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":permission":
            if (valsub == vx_p_permission) {
            } else if (valsub is Vx.Core.Type_permission valpermission) {
              ischanged = true;
              vx_p_permission = valpermission;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("permission"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub is Vx.Core.Type_string valtext) {
              ischanged = true;
              vx_p_text = valtext;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_text = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.File.Class_file work = new Vx.Data.File.Class_file();
        work.vx_p_name = vx_p_name;
        work.vx_p_format = vx_p_format;
        work.vx_p_path = vx_p_path;
        work.vx_p_permission = vx_p_permission;
        work.vx_p_text = vx_p_text;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_file;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/file", // pkgname
        "file", // name
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

  public static Vx.Data.File.Type_file e_file = new Vx.Data.File.Class_file();
  public static Vx.Data.File.Type_file t_file = new Vx.Data.File.Class_file();

  /**
   * type: fileformat
   * (type fileformat)
   */
  public interface Type_fileformat : Vx.Core.Type_any {
  }

  public class Class_fileformat : Vx.Core.Class_base, Type_fileformat {

    public override Vx.Data.File.Type_fileformat vx_new(params object[] vals) {
      Vx.Data.File.Type_fileformat output = Vx.Core.vx_copy(Vx.Data.File.e_fileformat, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Type_fileformat output = this;
      bool ischanged = false;
      Vx.Data.File.Class_fileformat value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.File.Class_fileformat work = new Vx.Data.File.Class_fileformat();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_fileformat;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_fileformat;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/file", // pkgname
        "fileformat", // name
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

  public static Vx.Data.File.Type_fileformat e_fileformat = new Vx.Data.File.Class_fileformat();
  public static Vx.Data.File.Type_fileformat t_fileformat = new Vx.Data.File.Class_fileformat();

  /**
   * type: filelist
   * List of file
   * (type filelist)
   */
  public interface Type_filelist : Vx.Core.Type_list {
    public List<Vx.Data.File.Type_file> vx_listfile();
    public Vx.Data.File.Type_file vx_file(Vx.Core.Type_int index);
  }

  public class Class_filelist : Vx.Core.Class_base, Type_filelist {

    public List<Vx.Data.File.Type_file> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.File.Type_file>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.File.Type_file vx_file(Vx.Core.Type_int index) {
      Vx.Data.File.Type_file output = Vx.Data.File.e_file;
      Vx.Data.File.Class_filelist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.File.Type_file> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.File.Type_file> vx_listfile() {
      List<Vx.Data.File.Type_file> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.File.Type_file output = this.vx_file(index);
      return output;
    }

    public override Vx.Data.File.Type_filelist vx_new(params object[] vals) {
      Vx.Data.File.Type_filelist output = Vx.Core.vx_copy(Vx.Data.File.e_filelist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Type_filelist output = this;
      bool ischanged = false;
      Vx.Data.File.Class_filelist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.File.Type_file> listval = new List<Vx.Data.File.Type_file>(value.vx_listfile());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.File.Type_file allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.File.Type_file) {
          ischanged = true;
          listval.Add((Vx.Data.File.Type_file)valsub);
        } else if (valsub is Vx.Data.File.Type_filelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listfile());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.File.Type_file valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.File.Class_filelist work = new Vx.Data.File.Class_filelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_filelist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_filelist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/file", // pkgname
        "filelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.File.t_file), // allowtypes
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

  public static Vx.Data.File.Type_filelist e_filelist = new Vx.Data.File.Class_filelist();
  public static Vx.Data.File.Type_filelist t_filelist = new Vx.Data.File.Class_filelist();
  /**
   * @function boolean_exists_from_file
   * Returns true if file/path exists.
   * @param  {file} file
   * @return {boolean}
   * (func boolean-exists<-file)
   */
  public interface Func_boolean_exists_from_file : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_exists_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_boolean_exists_from_file : Vx.Core.Class_base, Func_boolean_exists_from_file {

    public override Vx.Data.File.Func_boolean_exists_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_boolean_exists_from_file output = new Vx.Data.File.Class_boolean_exists_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_boolean_exists_from_file output = new Vx.Data.File.Class_boolean_exists_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_boolean_exists_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_boolean_exists_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_boolean_exists_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_boolean_exists_from_file(file);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_exists_from_file(Vx.Data.File.Type_file file) {
      Vx.Core.Type_boolean output = Vx.Data.File.f_boolean_exists_from_file(file);
      return output;
    }

  }

  public static Vx.Data.File.Func_boolean_exists_from_file e_boolean_exists_from_file = new Vx.Data.File.Class_boolean_exists_from_file();
  public static Vx.Data.File.Func_boolean_exists_from_file t_boolean_exists_from_file = new Vx.Data.File.Class_boolean_exists_from_file();

  public static Vx.Core.Type_boolean f_boolean_exists_from_file(Vx.Data.File.Type_file file) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Data.File.vx_boolean_exists_from_file(file);
    return output;
  }

  /**
   * @function boolean_write_from_file
   * Write a File to Disk
   * @param  {file} file
   * @return {boolean}
   * (func boolean-write<-file)
   */
  public interface Func_boolean_write_from_file : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_write_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file);
  }

  public class Class_boolean_write_from_file : Vx.Core.Class_base, Func_boolean_write_from_file {

    public override Vx.Data.File.Func_boolean_write_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file output = new Vx.Data.File.Class_boolean_write_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file output = new Vx.Data.File.Class_boolean_write_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_boolean_write_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_boolean_write_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_boolean_write_from_file(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_boolean_write_from_file(context, file);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
      Vx.Core.Type_boolean output = Vx.Data.File.f_boolean_write_from_file(context, file);
      return output;
    }

  }

  public static Vx.Data.File.Func_boolean_write_from_file e_boolean_write_from_file = new Vx.Data.File.Class_boolean_write_from_file();
  public static Vx.Data.File.Func_boolean_write_from_file t_boolean_write_from_file = new Vx.Data.File.Class_boolean_write_from_file();

  public static Vx.Core.Type_boolean f_boolean_write_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Data.File.f_boolean_write_from_file_string(
      context,
      file,
      file.text()
    );
    return output;
  }

  /**
   * @function boolean_write_from_file_any
   * Write any data structure as a file.
   * @param  {file} file
   * @param  {any} val
   * @return {boolean}
   * (func boolean-write<-file-any)
   */
  public interface Func_boolean_write_from_file_any : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_file_any(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_any val);
  }

  public class Class_boolean_write_from_file_any : Vx.Core.Class_base, Func_boolean_write_from_file_any {

    public override Vx.Data.File.Func_boolean_write_from_file_any vx_new(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file_any output = new Vx.Data.File.Class_boolean_write_from_file_any();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file_any output = new Vx.Data.File.Class_boolean_write_from_file_any();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_boolean_write_from_file_any;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_boolean_write_from_file_any;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any val = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.File.f_boolean_write_from_file_any(context, file, val);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_file_any(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_any val) {
      Vx.Core.Type_boolean output = Vx.Data.File.f_boolean_write_from_file_any(context, file, val);
      return output;
    }

  }

  public static Vx.Data.File.Func_boolean_write_from_file_any e_boolean_write_from_file_any = new Vx.Data.File.Class_boolean_write_from_file_any();
  public static Vx.Data.File.Func_boolean_write_from_file_any t_boolean_write_from_file_any = new Vx.Data.File.Class_boolean_write_from_file_any();

  public static Vx.Core.Type_boolean f_boolean_write_from_file_any(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_any val) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Data.File.f_boolean_write_from_file_string(
      context,
      file,
      Vx.Core.f_string_from_any(
        val
      )
    );
    return output;
  }

  /**
   * @function boolean_write_from_file_string
   * Write a File to Disk
   * @param  {file} file
   * @param  {string} text
   * @return {boolean}
   * (func boolean-write<-file-string)
   */
  public interface Func_boolean_write_from_file_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_file_string(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_string text);
  }

  public class Class_boolean_write_from_file_string : Vx.Core.Class_base, Func_boolean_write_from_file_string {

    public override Vx.Data.File.Func_boolean_write_from_file_string vx_new(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file_string output = new Vx.Data.File.Class_boolean_write_from_file_string();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_boolean_write_from_file_string output = new Vx.Data.File.Class_boolean_write_from_file_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_boolean_write_from_file_string;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_boolean_write_from_file_string;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Data.File.f_boolean_write_from_file_string(context, file, text);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_file_string(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_string text) {
      Vx.Core.Type_boolean output = Vx.Data.File.f_boolean_write_from_file_string(context, file, text);
      return output;
    }

  }

  public static Vx.Data.File.Func_boolean_write_from_file_string e_boolean_write_from_file_string = new Vx.Data.File.Class_boolean_write_from_file_string();
  public static Vx.Data.File.Func_boolean_write_from_file_string t_boolean_write_from_file_string = new Vx.Data.File.Class_boolean_write_from_file_string();

  public static Vx.Core.Type_boolean f_boolean_write_from_file_string(Vx.Core.Type_context context, Vx.Data.File.Type_file file, Vx.Core.Type_string text) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    if (Vx.Core.f_boolean_permission_from_func(context, Vx.Data.File.t_boolean_write_from_file_string).vx_boolean()) {
      try {
        output = Vx.Data.File.vx_boolean_write_from_file_string(context, file, text);
      } catch (Exception err) {
        Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/data/file/boolean-write<-file-string", err);
        output = Vx.Core.vx_copy(output, msg);
      }
    } else {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Vx.Core.vx_new_string("boolean-write<-file-string"));
      output = Vx.Core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function file_read_from_file
   * Read a Text File from Disk
   * @param  {file} file
   * @return {file}
   * (func file-read<-file)
   */
  public interface Func_file_read_from_file : Vx.Core.Func_any_from_any_context {
    public Vx.Data.File.Type_file vx_file_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file);
  }

  public class Class_file_read_from_file : Vx.Core.Class_base, Func_file_read_from_file {

    public override Vx.Data.File.Func_file_read_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_file_read_from_file output = new Vx.Data.File.Class_file_read_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_file_read_from_file output = new Vx.Data.File.Class_file_read_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_file_read_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_file_read_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_file_read_from_file(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_file_read_from_file(context, file);
      return output;
    }

    public Vx.Data.File.Type_file vx_file_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
      Vx.Data.File.Type_file output = Vx.Data.File.f_file_read_from_file(context, file);
      return output;
    }

  }

  public static Vx.Data.File.Func_file_read_from_file e_file_read_from_file = new Vx.Data.File.Class_file_read_from_file();
  public static Vx.Data.File.Func_file_read_from_file t_file_read_from_file = new Vx.Data.File.Class_file_read_from_file();

  public static Vx.Data.File.Type_file f_file_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
    Vx.Data.File.Type_file output = Vx.Data.File.e_file;
    if (Vx.Core.f_boolean_permission_from_func(context, Vx.Data.File.t_file_read_from_file).vx_boolean()) {
      output = Vx.Core.f_copy(
        file,
        Vx.Core.vx_new(
          Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":text"),
          Vx.Data.File.f_string_read_from_file(
            context,
            file
          )
        )
      );
    } else {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Vx.Core.vx_new_string("file-read<-file"));
      output = Vx.Core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function file_from_path
   * Returns a file from a given path
   * @param  {string} path
   * @return {file}
   * (func file<-path)
   */
  public interface Func_file_from_path : Vx.Core.Func_any_from_any {
    public Vx.Data.File.Type_file vx_file_from_path(Vx.Core.Type_string path);
  }

  public class Class_file_from_path : Vx.Core.Class_base, Func_file_from_path {

    public override Vx.Data.File.Func_file_from_path vx_new(params object[] vals) {
      Vx.Data.File.Class_file_from_path output = new Vx.Data.File.Class_file_from_path();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_file_from_path output = new Vx.Data.File.Class_file_from_path();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "file<-path", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_file_from_path;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_file_from_path;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_file_from_path(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string path = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_file_from_path(path);
      return output;
    }

    public Vx.Data.File.Type_file vx_file_from_path(Vx.Core.Type_string path) {
      Vx.Data.File.Type_file output = Vx.Data.File.f_file_from_path(path);
      return output;
    }

  }

  public static Vx.Data.File.Func_file_from_path e_file_from_path = new Vx.Data.File.Class_file_from_path();
  public static Vx.Data.File.Func_file_from_path t_file_from_path = new Vx.Data.File.Class_file_from_path();

  public static Vx.Data.File.Type_file f_file_from_path(Vx.Core.Type_string path) {
    Vx.Data.File.Type_file output = Vx.Data.File.e_file;
    output = Vx.Core.f_let(
      Vx.Data.File.t_file,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pos = Vx.Type.f_int_from_string_findlast(
          path,
          Vx.Core.vx_new_string("/")
        );
        Vx.Core.Type_string name = Vx.Type.f_string_from_string_start(
          path,
          Vx.Core.f_plus1(
            pos
          )
        );
        Vx.Core.Type_string pth = Vx.Type.f_string_from_string_end(
          path,
          Vx.Core.f_minus1(
            pos
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Data.File.t_file,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            name,
            Vx.Core.vx_new_string(":path"),
            pth
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function name_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   * (func name<-file)
   */
  public interface Func_name_from_file : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_name_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_name_from_file : Vx.Core.Class_base, Func_name_from_file {

    public override Vx.Data.File.Func_name_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_name_from_file output = new Vx.Data.File.Class_name_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_name_from_file output = new Vx.Data.File.Class_name_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_name_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_name_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_name_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_name_from_file(file);
      return output;
    }

    public Vx.Core.Type_string vx_name_from_file(Vx.Data.File.Type_file file) {
      Vx.Core.Type_string output = Vx.Data.File.f_name_from_file(file);
      return output;
    }

  }

  public static Vx.Data.File.Func_name_from_file e_name_from_file = new Vx.Data.File.Class_name_from_file();
  public static Vx.Data.File.Func_name_from_file t_name_from_file = new Vx.Data.File.Class_name_from_file();

  public static Vx.Core.Type_string f_name_from_file(Vx.Data.File.Type_file file) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = file.name();
    return output;
  }

  /**
   * @function path_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   * (func path<-file)
   */
  public interface Func_path_from_file : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_path_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_path_from_file : Vx.Core.Class_base, Func_path_from_file {

    public override Vx.Data.File.Func_path_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_path_from_file output = new Vx.Data.File.Class_path_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_path_from_file output = new Vx.Data.File.Class_path_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_path_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_path_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_path_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_path_from_file(file);
      return output;
    }

    public Vx.Core.Type_string vx_path_from_file(Vx.Data.File.Type_file file) {
      Vx.Core.Type_string output = Vx.Data.File.f_path_from_file(file);
      return output;
    }

  }

  public static Vx.Data.File.Func_path_from_file e_path_from_file = new Vx.Data.File.Class_path_from_file();
  public static Vx.Data.File.Func_path_from_file t_path_from_file = new Vx.Data.File.Class_path_from_file();

  public static Vx.Core.Type_string f_path_from_file(Vx.Data.File.Type_file file) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = file.path();
    return output;
  }

  /**
   * @function pathcurrent_from_os
   * Returns current system path.
   * @return {string}
   * (func pathcurrent<-os)
   */
  public interface Func_pathcurrent_from_os : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_pathcurrent_from_os();
  }

  public class Class_pathcurrent_from_os : Vx.Core.Class_base, Func_pathcurrent_from_os {

    public override Vx.Data.File.Func_pathcurrent_from_os vx_new(params object[] vals) {
      Vx.Data.File.Class_pathcurrent_from_os output = new Vx.Data.File.Class_pathcurrent_from_os();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_pathcurrent_from_os output = new Vx.Data.File.Class_pathcurrent_from_os();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_pathcurrent_from_os;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_pathcurrent_from_os;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Data.File.f_pathcurrent_from_os();
      return output;
    }

    public Vx.Core.Type_string vx_pathcurrent_from_os() {
      Vx.Core.Type_string output = Vx.Data.File.f_pathcurrent_from_os();
      return output;
    }

  }

  public static Vx.Data.File.Func_pathcurrent_from_os e_pathcurrent_from_os = new Vx.Data.File.Class_pathcurrent_from_os();
  public static Vx.Data.File.Func_pathcurrent_from_os t_pathcurrent_from_os = new Vx.Data.File.Class_pathcurrent_from_os();

  public static Vx.Core.Type_string f_pathcurrent_from_os() {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Data.File.vx_pathcurrent_from_os();
    return output;
  }

  /**
   * @function pathfull_from_file
   * Returns full path and name from file.
   * @param  {file} file
   * @return {string}
   * (func pathfull<-file)
   */
  public interface Func_pathfull_from_file : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_pathfull_from_file(Vx.Data.File.Type_file file);
  }

  public class Class_pathfull_from_file : Vx.Core.Class_base, Func_pathfull_from_file {

    public override Vx.Data.File.Func_pathfull_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_pathfull_from_file output = new Vx.Data.File.Class_pathfull_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_pathfull_from_file output = new Vx.Data.File.Class_pathfull_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_pathfull_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_pathfull_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_pathfull_from_file(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_pathfull_from_file(file);
      return output;
    }

    public Vx.Core.Type_string vx_pathfull_from_file(Vx.Data.File.Type_file file) {
      Vx.Core.Type_string output = Vx.Data.File.f_pathfull_from_file(file);
      return output;
    }

  }

  public static Vx.Data.File.Func_pathfull_from_file e_pathfull_from_file = new Vx.Data.File.Class_pathfull_from_file();
  public static Vx.Data.File.Func_pathfull_from_file t_pathfull_from_file = new Vx.Data.File.Class_pathfull_from_file();

  public static Vx.Core.Type_string f_pathfull_from_file(Vx.Data.File.Type_file file) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string path = Vx.Data.File.f_path_from_file(
          file
        );
        Vx.Core.Type_string name = Vx.Data.File.f_name_from_file(
          file
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(
            Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_2 = Vx.Core.f_is_empty(
                  path
                );
                return output_2;
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_3 = name;
                return output_3;
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any output_4 = Vx.Core.f_new(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    path,
                    Vx.Core.vx_new_string("/"),
                    name
                  )
                );
                return output_4;
              })
            )
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_read_from_file
   * Read text from a File
   * @param  {file} file
   * @return {string}
   * (func string-read<-file)
   */
  public interface Func_string_read_from_file : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_string vx_string_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file);
  }

  public class Class_string_read_from_file : Vx.Core.Class_base, Func_string_read_from_file {

    public override Vx.Data.File.Func_string_read_from_file vx_new(params object[] vals) {
      Vx.Data.File.Class_string_read_from_file output = new Vx.Data.File.Class_string_read_from_file();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.File.Class_string_read_from_file output = new Vx.Data.File.Class_string_read_from_file();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.File.e_string_read_from_file;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.File.t_string_read_from_file;
      return output;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.File.Type_file inputval = (Vx.Data.File.Type_file)value;
      Vx.Core.Type_any outputval = Vx.Data.File.f_string_read_from_file(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Data.File.f_string_read_from_file(context, file);
      return output;
    }

    public Vx.Core.Type_string vx_string_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
      Vx.Core.Type_string output = Vx.Data.File.f_string_read_from_file(context, file);
      return output;
    }

  }

  public static Vx.Data.File.Func_string_read_from_file e_string_read_from_file = new Vx.Data.File.Class_string_read_from_file();
  public static Vx.Data.File.Func_string_read_from_file t_string_read_from_file = new Vx.Data.File.Class_string_read_from_file();

  public static Vx.Core.Type_string f_string_read_from_file(Vx.Core.Type_context context, Vx.Data.File.Type_file file) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    if (Vx.Core.f_boolean_permission_from_func(context, Vx.Data.File.t_string_read_from_file).vx_boolean()) {
      try {
        output = Vx.Data.File.vx_string_read_from_file(context, file);
      } catch (Exception err) {
        Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/data/file/string-read<-file", err);
        output = Vx.Core.vx_copy(output, msg);
      }
    } else {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Vx.Core.vx_new_string("string-read<-file"));
      output = Vx.Core.vx_copy(output, msg);
    }
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("file", Vx.Data.File.t_file);
    maptype.put("fileformat", Vx.Data.File.t_fileformat);
    maptype.put("filelist", Vx.Data.File.t_filelist);
    mapfunc.put("boolean-exists<-file", Vx.Data.File.t_boolean_exists_from_file);
    mapfunc.put("boolean-write<-file", Vx.Data.File.t_boolean_write_from_file);
    mapfunc.put("boolean-write<-file-any", Vx.Data.File.t_boolean_write_from_file_any);
    mapfunc.put("boolean-write<-file-string", Vx.Data.File.t_boolean_write_from_file_string);
    mapfunc.put("file-read<-file", Vx.Data.File.t_file_read_from_file);
    mapfunc.put("file<-path", Vx.Data.File.t_file_from_path);
    mapfunc.put("name<-file", Vx.Data.File.t_name_from_file);
    mapfunc.put("path<-file", Vx.Data.File.t_path_from_file);
    mapfunc.put("pathcurrent<-os", Vx.Data.File.t_pathcurrent_from_os);
    mapfunc.put("pathfull<-file", Vx.Data.File.t_pathfull_from_file);
    mapfunc.put("string-read<-file", Vx.Data.File.t_string_read_from_file);
    Vx.Core.vx_global_package_set("vx/data/file", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
