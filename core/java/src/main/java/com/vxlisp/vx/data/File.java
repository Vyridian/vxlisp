package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;
import java.nio.file.*;

public final class File {


  public static Core.Type_string vx_string_read_from_file(File.Type_file file) {
    Core.Type_string output = Core.e_string;
    Core.Type_string fullpath = File.f_pathfull_from_file(file);
    String sfullpath = fullpath.vx_string();
    Path path = Paths.get(sfullpath);
    if (Files.exists(path)) {
      try {
        byte[] bytes = Files.readAllBytes(path);
        String scontent = new String(bytes);
        Core.Type_string valcontent = Core.vx_new_string(scontent);
        output = valcontent;
      } catch (Exception ex) {
        Core.Type_msg msg = Core.vx_msg_from_exception("string-read<-file", ex);
        output = Core.vx_copy(output, msg);
      }
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("string-read<-file", ":filenotfound", file);
      output = Core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * type: file
   * File structure
   * (type file)
   */
  public interface Type_file extends Core.Type_struct {
    public Core.Type_string name();
    public File.Type_fileformat format();
    public Core.Type_string path();
    public Core.Type_permission permission();
    public Core.Type_string text();
  }

  public static class Class_file extends Core.Class_base implements Type_file {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public File.Type_fileformat vx_p_format = null;

    @Override
    public File.Type_fileformat format() {
      File.Type_fileformat output = File.e_fileformat;
      File.Type_fileformat testnull = vx_p_format;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_path = null;

    @Override
    public Core.Type_string path() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_path;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_permission vx_p_permission = null;

    @Override
    public Core.Type_permission permission() {
      Core.Type_permission output = Core.e_permission;
      Core.Type_permission testnull = vx_p_permission;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_text = null;

    @Override
    public Core.Type_string text() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_text;
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
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":format"))) {
        output = this.format();
      } else if ((skey.equals(":path"))) {
        output = this.path();
      } else if ((skey.equals(":permission"))) {
        output = this.permission();
      } else if ((skey.equals(":text"))) {
        output = this.text();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":format", this.format());
      map.put(":path", this.path());
      map.put(":permission", this.permission());
      map.put(":text", this.text());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Type_file output = Core.vx_copy(File.e_file, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Type_file output = this;
      boolean ischanged = false;
      File.Class_file value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      File.Type_fileformat vx_p_format = value.format();
      Core.Type_string vx_p_path = value.path();
      Core.Type_permission vx_p_permission = value.permission();
      Core.Type_string vx_p_text = value.text();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":format");
      validkeys.add(":path");
      validkeys.add(":permission");
      validkeys.add(":text");
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
            msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":format"))) {
            if (valsub == vx_p_format) {
            } else if (valsub instanceof File.Type_fileformat) {
              File.Type_fileformat valformat = (File.Type_fileformat)valsub;
              ischanged = true;
              vx_p_format = valformat;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("format"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":path"))) {
            if (valsub == vx_p_path) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valpath = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_path = valpath;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_path = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":permission"))) {
            if (valsub == vx_p_permission) {
            } else if (valsub instanceof Core.Type_permission) {
              Core.Type_permission valpermission = (Core.Type_permission)valsub;
              ischanged = true;
              vx_p_permission = valpermission;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("permission"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":text"))) {
            if (valsub == vx_p_text) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valtext = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_text = valtext;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        File.Class_file work = new File.Class_file();
        work.vx_p_name = vx_p_name;
        work.vx_p_format = vx_p_format;
        work.vx_p_path = vx_p_path;
        work.vx_p_permission = vx_p_permission;
        work.vx_p_text = vx_p_text;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_file;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/data/file", // pkgname
        "file", // name
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

  public static final File.Type_file e_file = new File.Class_file();
  public static final File.Type_file t_file = new File.Class_file();

  /**
   * type: fileformat
   * (type fileformat)
   */
  public interface Type_fileformat extends Core.Type_any {
  }

  public static class Class_fileformat extends Core.Class_base implements Type_fileformat {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Type_fileformat output = Core.vx_copy(File.e_fileformat, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Type_fileformat output = this;
      boolean ischanged = false;
      File.Class_fileformat value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        File.Class_fileformat work = new File.Class_fileformat();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_fileformat;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_fileformat;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/data/file", // pkgname
        "fileformat", // name
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

  public static final File.Type_fileformat e_fileformat = new File.Class_fileformat();
  public static final File.Type_fileformat t_fileformat = new File.Class_fileformat();

  /**
   * type: filelist
   * List of file
   * (type filelist)
   */
  public interface Type_filelist extends Core.Type_list {
    public List<File.Type_file> vx_listfile();
    public File.Type_file vx_file(final Core.Type_int index);
  }

  public static class Class_filelist extends Core.Class_base implements Type_filelist {

    public List<File.Type_file> vx_p_list = Core.immutablelist(
      new ArrayList<File.Type_file>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public File.Type_file vx_file(final Core.Type_int index) {
      File.Type_file output = File.e_file;
      File.Class_filelist list = this;
      int iindex = index.vx_int();
      List<File.Type_file> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<File.Type_file> vx_listfile() {
      List<File.Type_file> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      File.Type_file output = this.vx_file(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Type_filelist output = Core.vx_copy(File.e_filelist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Type_filelist output = this;
      boolean ischanged = false;
      File.Class_filelist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<File.Type_file> listval = new ArrayList<File.Type_file>(value.vx_listfile());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof File.Type_file) {
          File.Type_file allowsub = (File.Type_file)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof File.Type_file) {
          ischanged = true;
          listval.add((File.Type_file)valsub);
        } else if (valsub instanceof File.Type_filelist) {
          File.Type_filelist multi = (File.Type_filelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfile());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof File.Type_file) {
              File.Type_file valitem = (File.Type_file)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/file/filelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        File.Class_filelist work = new File.Class_filelist();
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
      Core.Type_any output = File.e_filelist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_filelist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/data/file", // pkgname
        "filelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, File.t_file), // allowtypes
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

  public static final File.Type_filelist e_filelist = new File.Class_filelist();
  public static final File.Type_filelist t_filelist = new File.Class_filelist();
  /**
   * @function boolean_exists_from_file
   * Returns true if file/path exists.
   * @param  {file} file
   * @return {boolean}
   * (func boolean-exists<-file)
   */
  public interface Func_boolean_exists_from_file extends Core.Func_any_from_any {
    public Core.Type_boolean vx_boolean_exists_from_file(final File.Type_file file);
  }

  public static class Class_boolean_exists_from_file extends Core.Class_base implements Func_boolean_exists_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_boolean_exists_from_file output = new File.Class_boolean_exists_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_boolean_exists_from_file output = new File.Class_boolean_exists_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_boolean_exists_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_boolean_exists_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_boolean_exists_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_boolean_exists_from_file(file);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_exists_from_file(final File.Type_file file) {
      Core.Type_boolean output = File.f_boolean_exists_from_file(file);
      return output;
    }

  }

  public static final File.Func_boolean_exists_from_file e_boolean_exists_from_file = new File.Class_boolean_exists_from_file();
  public static final File.Func_boolean_exists_from_file t_boolean_exists_from_file = new File.Class_boolean_exists_from_file();

  public static Core.Type_boolean f_boolean_exists_from_file(final File.Type_file file) {
    Core.Type_boolean output = Core.e_boolean;
    Core.Type_string fullpath = File.f_pathfull_from_file(file);
    String sfullpath = fullpath.vx_string();
    Path path = Paths.get(sfullpath);
    if (Files.exists(path)) {
      output = Core.c_true;
    };
    return output;
  }

  /**
   * @function boolean_write_from_file
   * Write a File to Disk
   * @param  {file} file
   * @return {boolean}
   * (func boolean-write<-file)
   */
  public interface Func_boolean_write_from_file extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_write_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_boolean_write_from_file extends Core.Class_base implements Func_boolean_write_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_boolean_write_from_file output = new File.Class_boolean_write_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_boolean_write_from_file output = new File.Class_boolean_write_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_boolean_write_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_boolean_write_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_boolean_write_from_file(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_boolean_write_from_file(context, file);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_file(final Core.Type_context context, final File.Type_file file) {
      Core.Type_boolean output = File.f_boolean_write_from_file(context, file);
      return output;
    }

  }

  public static final File.Func_boolean_write_from_file e_boolean_write_from_file = new File.Class_boolean_write_from_file();
  public static final File.Func_boolean_write_from_file t_boolean_write_from_file = new File.Class_boolean_write_from_file();

  public static Core.Type_boolean f_boolean_write_from_file(final Core.Type_context context, final File.Type_file file) {
    Core.Type_boolean output = Core.e_boolean;
    output = File.f_boolean_write_from_file_string(
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
  public interface Func_boolean_write_from_file_any extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_file_any(final Core.Type_context context, final File.Type_file file, final Core.Type_any val);
  }

  public static class Class_boolean_write_from_file_any extends Core.Class_base implements Func_boolean_write_from_file_any {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_boolean_write_from_file_any output = new File.Class_boolean_write_from_file_any();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_boolean_write_from_file_any output = new File.Class_boolean_write_from_file_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_boolean_write_from_file_any;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_boolean_write_from_file_any;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = File.f_boolean_write_from_file_any(context, file, val);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_file_any(final Core.Type_context context, final File.Type_file file, final Core.Type_any val) {
      Core.Type_boolean output = File.f_boolean_write_from_file_any(context, file, val);
      return output;
    }

  }

  public static final File.Func_boolean_write_from_file_any e_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();
  public static final File.Func_boolean_write_from_file_any t_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();

  public static Core.Type_boolean f_boolean_write_from_file_any(final Core.Type_context context, final File.Type_file file, final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = File.f_boolean_write_from_file_string(
      context,
      file,
      Core.f_string_from_any(
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
  public interface Func_boolean_write_from_file_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_file_string(final Core.Type_context context, final File.Type_file file, final Core.Type_string text);
  }

  public static class Class_boolean_write_from_file_string extends Core.Class_base implements Func_boolean_write_from_file_string {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_boolean_write_from_file_string output = new File.Class_boolean_write_from_file_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_boolean_write_from_file_string output = new File.Class_boolean_write_from_file_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_boolean_write_from_file_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_boolean_write_from_file_string;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = File.f_boolean_write_from_file_string(context, file, text);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_file_string(final Core.Type_context context, final File.Type_file file, final Core.Type_string text) {
      Core.Type_boolean output = File.f_boolean_write_from_file_string(context, file, text);
      return output;
    }

  }

  public static final File.Func_boolean_write_from_file_string e_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();
  public static final File.Func_boolean_write_from_file_string t_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();

  public static Core.Type_boolean f_boolean_write_from_file_string(final Core.Type_context context, final File.Type_file file, final Core.Type_string text) {
    Core.Type_boolean output = Core.e_boolean;
    if (Core.f_boolean_permission_from_func(context, File.t_boolean_write_from_file_string).vx_boolean()) {
      try {
        Core.Type_string fullpath = File.f_pathfull_from_file(file);
        String sfullpath = fullpath.vx_string();
        Path path = Paths.get(sfullpath);
        String stext = text.vx_string();
        byte[] bytes = stext.getBytes();
        java.nio.file.Files.write(path, bytes);
        output = Core.c_true;
      } catch (Exception err) {
        Core.Type_msg msg = Core.vx_msg_from_exception("vx/data/file/boolean-write<-file-string", err);
        output = Core.vx_copy(output, msg);
      }
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("boolean-write<-file-string"));
      output = Core.vx_copy(output, msg);
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
  public interface Func_file_read_from_file extends Core.Func_any_from_any_context {
    public File.Type_file vx_file_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_file_read_from_file extends Core.Class_base implements Func_file_read_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_file_read_from_file output = new File.Class_file_read_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_file_read_from_file output = new File.Class_file_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_file_read_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_file_read_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_file_read_from_file(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_file_read_from_file(context, file);
      return output;
    }

    @Override
    public File.Type_file vx_file_read_from_file(final Core.Type_context context, final File.Type_file file) {
      File.Type_file output = File.f_file_read_from_file(context, file);
      return output;
    }

  }

  public static final File.Func_file_read_from_file e_file_read_from_file = new File.Class_file_read_from_file();
  public static final File.Func_file_read_from_file t_file_read_from_file = new File.Class_file_read_from_file();

  public static File.Type_file f_file_read_from_file(final Core.Type_context context, final File.Type_file file) {
    File.Type_file output = File.e_file;
    if (Core.f_boolean_permission_from_func(context, File.t_file_read_from_file).vx_boolean()) {
      output = Core.f_copy(
        file,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":text"),
          File.f_string_read_from_file(
            context,
            file
          )
        )
      );
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("file-read<-file"));
      output = Core.vx_copy(output, msg);
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
  public interface Func_file_from_path extends Core.Func_any_from_any {
    public File.Type_file vx_file_from_path(final Core.Type_string path);
  }

  public static class Class_file_from_path extends Core.Class_base implements Func_file_from_path {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_file_from_path output = new File.Class_file_from_path();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_file_from_path output = new File.Class_file_from_path();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "file<-path", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_file_from_path;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_file_from_path;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = File.f_file_from_path(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string path = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_file_from_path(path);
      return output;
    }

    @Override
    public File.Type_file vx_file_from_path(final Core.Type_string path) {
      File.Type_file output = File.f_file_from_path(path);
      return output;
    }

  }

  public static final File.Func_file_from_path e_file_from_path = new File.Class_file_from_path();
  public static final File.Func_file_from_path t_file_from_path = new File.Class_file_from_path();

  public static File.Type_file f_file_from_path(final Core.Type_string path) {
    File.Type_file output = File.e_file;
    output = Core.f_let(
      File.t_file,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int pos = Type.f_int_from_string_findlast(
          path,
          Core.vx_new_string("/")
        );
        Core.Type_string name = Type.f_string_from_string_start(
          path,
          Core.f_plus1(
            pos
          )
        );
        Core.Type_string pth = Type.f_string_from_string_end(
          path,
          Core.f_minus1(
            pos
          )
        );
        Core.Type_any output_1 = Core.f_new(
          File.t_file,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":name"),
            name,
            Core.vx_new_string(":path"),
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
  public interface Func_name_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_name_from_file(final File.Type_file file);
  }

  public static class Class_name_from_file extends Core.Class_base implements Func_name_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_name_from_file output = new File.Class_name_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_name_from_file output = new File.Class_name_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_name_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_name_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_name_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_name_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_name_from_file(final File.Type_file file) {
      Core.Type_string output = File.f_name_from_file(file);
      return output;
    }

  }

  public static final File.Func_name_from_file e_name_from_file = new File.Class_name_from_file();
  public static final File.Func_name_from_file t_name_from_file = new File.Class_name_from_file();

  public static Core.Type_string f_name_from_file(final File.Type_file file) {
    Core.Type_string output = Core.e_string;
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
  public interface Func_path_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_path_from_file(final File.Type_file file);
  }

  public static class Class_path_from_file extends Core.Class_base implements Func_path_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_path_from_file output = new File.Class_path_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_path_from_file output = new File.Class_path_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_path_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_path_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_path_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_path_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_path_from_file(final File.Type_file file) {
      Core.Type_string output = File.f_path_from_file(file);
      return output;
    }

  }

  public static final File.Func_path_from_file e_path_from_file = new File.Class_path_from_file();
  public static final File.Func_path_from_file t_path_from_file = new File.Class_path_from_file();

  public static Core.Type_string f_path_from_file(final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    output = file.path();
    return output;
  }

  /**
   * @function pathcurrent_from_os
   * Returns current system path.
   * @return {string}
   * (func pathcurrent<-os)
   */
  public interface Func_pathcurrent_from_os extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_pathcurrent_from_os();
  }

  public static class Class_pathcurrent_from_os extends Core.Class_base implements Func_pathcurrent_from_os {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_pathcurrent_from_os output = new File.Class_pathcurrent_from_os();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_pathcurrent_from_os output = new File.Class_pathcurrent_from_os();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_pathcurrent_from_os;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_pathcurrent_from_os;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = File.f_pathcurrent_from_os();
      return output;
    }

    @Override
    public Core.Type_string vx_pathcurrent_from_os() {
      Core.Type_string output = File.f_pathcurrent_from_os();
      return output;
    }

  }

  public static final File.Func_pathcurrent_from_os e_pathcurrent_from_os = new File.Class_pathcurrent_from_os();
  public static final File.Func_pathcurrent_from_os t_pathcurrent_from_os = new File.Class_pathcurrent_from_os();

  public static Core.Type_string f_pathcurrent_from_os() {
    Core.Type_string output = Core.e_string;
    Path path = Paths.get("");
    path = path.toAbsolutePath();
    String spath = path.toString();
    output = Core.vx_new_string(spath);
    return output;
  }

  /**
   * @function pathfull_from_file
   * Returns full path and name from file.
   * @param  {file} file
   * @return {string}
   * (func pathfull<-file)
   */
  public interface Func_pathfull_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_pathfull_from_file(final File.Type_file file);
  }

  public static class Class_pathfull_from_file extends Core.Class_base implements Func_pathfull_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_pathfull_from_file output = new File.Class_pathfull_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_pathfull_from_file output = new File.Class_pathfull_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_pathfull_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_pathfull_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_pathfull_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_pathfull_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_pathfull_from_file(final File.Type_file file) {
      Core.Type_string output = File.f_pathfull_from_file(file);
      return output;
    }

  }

  public static final File.Func_pathfull_from_file e_pathfull_from_file = new File.Class_pathfull_from_file();
  public static final File.Func_pathfull_from_file t_pathfull_from_file = new File.Class_pathfull_from_file();

  public static Core.Type_string f_pathfull_from_file(final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string path = File.f_path_from_file(
          file
        );
        Core.Type_string name = File.f_name_from_file(
          file
        );
        Core.Type_any output_1 = Core.f_if_2(
          Core.t_string,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_is_empty(
                  path
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = name;
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_new(
                  Core.t_string,
                  Core.vx_new(
                    Core.t_anylist,
                    path,
                    Core.vx_new_string("/"),
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
  public interface Func_string_read_from_file extends Core.Func_any_from_any_context {
    public Core.Type_string vx_string_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_string_read_from_file extends Core.Class_base implements Func_string_read_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      File.Class_string_read_from_file output = new File.Class_string_read_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      File.Class_string_read_from_file output = new File.Class_string_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = File.e_string_read_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = File.t_string_read_from_file;
      return output;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_string_read_from_file(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_string_read_from_file(context, file);
      return output;
    }

    @Override
    public Core.Type_string vx_string_read_from_file(final Core.Type_context context, final File.Type_file file) {
      Core.Type_string output = File.f_string_read_from_file(context, file);
      return output;
    }

  }

  public static final File.Func_string_read_from_file e_string_read_from_file = new File.Class_string_read_from_file();
  public static final File.Func_string_read_from_file t_string_read_from_file = new File.Class_string_read_from_file();

  public static Core.Type_string f_string_read_from_file(final Core.Type_context context, final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    if (Core.f_boolean_permission_from_func(context, File.t_string_read_from_file).vx_boolean()) {
      try {
        output = vx_string_read_from_file(file);
      } catch (Exception err) {
        Core.Type_msg msg = Core.vx_msg_from_exception("vx/data/file/string-read<-file", err);
        output = Core.vx_copy(output, msg);
      }
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("string-read<-file"));
      output = Core.vx_copy(output, msg);
    }
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("file", File.t_file);
    maptype.put("fileformat", File.t_fileformat);
    maptype.put("filelist", File.t_filelist);
    mapfunc.put("boolean-exists<-file", File.t_boolean_exists_from_file);
    mapfunc.put("boolean-write<-file", File.t_boolean_write_from_file);
    mapfunc.put("boolean-write<-file-any", File.t_boolean_write_from_file_any);
    mapfunc.put("boolean-write<-file-string", File.t_boolean_write_from_file_string);
    mapfunc.put("file-read<-file", File.t_file_read_from_file);
    mapfunc.put("file<-path", File.t_file_from_path);
    mapfunc.put("name<-file", File.t_name_from_file);
    mapfunc.put("path<-file", File.t_path_from_file);
    mapfunc.put("pathcurrent<-os", File.t_pathcurrent_from_os);
    mapfunc.put("pathfull<-file", File.t_pathfull_from_file);
    mapfunc.put("string-read<-file", File.t_string_read_from_file);
    Core.vx_global_package_set("vx/data/file", maptype, mapconst, mapfunc);
  }

}
