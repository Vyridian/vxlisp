package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import java.nio.file.*;

public final class File {


  public static Core.Type_string vx_string_read_from_file(File.Type_file file) throws java.io.IOException {
    Core.Type_string output = Core.e_string;
    Core.Type_string fullpath = File.f_pathfull_from_file(file);
    String sfullpath = fullpath.vx_string();
    Path path = Paths.get(sfullpath);
    if (Files.exists(path)) {
      byte[] bytes = Files.readAllBytes(path);
      String scontent = new String(bytes);
      Core.Type_string valcontent = Core.vx_new_string(scontent);
      output = valcontent;
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("string-read<-file", ":filenotfound", file);
      output = Core.t_string.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * type: file
   * File structure
   * (type file)
   */
  public interface Type_file extends Core.Type_struct {
    public File.Type_file vx_new(final Object... vals);
    public File.Type_file vx_copy(final Object... vals);
    public File.Type_file vx_empty();
    public File.Type_file vx_type();
    public Core.Type_string name();
    public File.Type_fileformat format();
    public Core.Type_string path();
    public Core.Type_permission permission();
    public Core.Type_string text();
  }

  public static class Class_file extends Core.Class_base implements Type_file {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected File.Type_fileformat vx_p_format;

    @Override
    public File.Type_fileformat format() {
      return this.vx_p_format == null ? File.e_fileformat : this.vx_p_format;
    }

    protected Core.Type_string vx_p_path;

    @Override
    public Core.Type_string path() {
      return this.vx_p_path == null ? Core.e_string : this.vx_p_path;
    }

    protected Core.Type_permission vx_p_permission;

    @Override
    public Core.Type_permission permission() {
      return this.vx_p_permission == null ? Core.e_permission : this.vx_p_permission;
    }

    protected Core.Type_string vx_p_text;

    @Override
    public Core.Type_string text() {
      return this.vx_p_text == null ? Core.e_string : this.vx_p_text;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":format", this.format());
      output.put(":path", this.path());
      output.put(":permission", this.permission());
      output.put(":text", this.text());
      return Core.immutablemap(output);
    }

    @Override
    public Type_file vx_new(final Object... vals) {return e_file.vx_copy(vals);}

    @Override
    public Type_file vx_copy(final Object... vals) {
      Type_file output = this;
      boolean ischanged = false;
      Class_file val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      File.Type_fileformat vx_p_format = val.format();
      Core.Type_string vx_p_path = val.path();
      Core.Type_permission vx_p_permission = val.permission();
      Core.Type_string vx_p_text = val.text();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":format");
      validkeys.add(":path");
      validkeys.add(":permission");
      validkeys.add(":text");
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
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":format":
            if (valsub == vx_p_format) {
            } else if (valsub instanceof File.Type_fileformat) {
              ischanged = true;
              vx_p_format = (File.Type_fileformat)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("format"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_path = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_path = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("path"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":permission":
            if (valsub == vx_p_permission) {
            } else if (valsub instanceof Core.Type_permission) {
              ischanged = true;
              vx_p_permission = (Core.Type_permission)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("permission"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub == vx_p_text) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("text"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/file/file", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_file work = new Class_file();
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
    public Type_file vx_empty() {return e_file;}
    @Override
    public Type_file vx_type() {return t_file;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_file e_file = new Class_file();
  public static final Type_file t_file = new Class_file();

  /**
   * type: fileformat
   * (type fileformat)
   */
  public interface Type_fileformat extends Core.Type_any {
    public File.Type_fileformat vx_new(final Object... vals);
    public File.Type_fileformat vx_copy(final Object... vals);
    public File.Type_fileformat vx_empty();
    public File.Type_fileformat vx_type();
  }

  public static class Class_fileformat extends Core.Class_base implements Type_fileformat {

    @Override
    public Type_fileformat vx_new(final Object... vals) {return e_fileformat.vx_copy(vals);}

    @Override
    public Type_fileformat vx_copy(final Object... vals) {
      Type_fileformat output = this;
      boolean ischanged = false;
      Class_fileformat val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_fileformat work = new Class_fileformat();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_fileformat vx_empty() {return e_fileformat;}
    @Override
    public Type_fileformat vx_type() {return t_fileformat;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
    }

  }

  public static final Type_fileformat e_fileformat = new Class_fileformat();
  public static final Type_fileformat t_fileformat = new Class_fileformat();
  /**
   * @function boolean_exists_from_file
   * Returns true if file/path exists.
   * @param  {file} file
   * @return {boolean}
   * (func boolean-exists<-file)
   */
  public static interface Func_boolean_exists_from_file extends Core.Func_any_from_any {
    public Core.Type_boolean vx_boolean_exists_from_file(final File.Type_file file);
  }

  public static class Class_boolean_exists_from_file extends Core.Class_base implements Func_boolean_exists_from_file {

    @Override
    public Func_boolean_exists_from_file vx_new(Object... vals) {
      Class_boolean_exists_from_file output = new Class_boolean_exists_from_file();
      return output;
    }

    @Override
    public Func_boolean_exists_from_file vx_copy(Object... vals) {
      Class_boolean_exists_from_file output = new Class_boolean_exists_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_exists_from_file vx_empty() {return e_boolean_exists_from_file;}
    @Override
    public Func_boolean_exists_from_file vx_type() {return t_boolean_exists_from_file;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_boolean_exists_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_boolean_exists_from_file(file);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_exists_from_file(final File.Type_file file) {
      return File.f_boolean_exists_from_file(file);
    }

  }

  public static final Func_boolean_exists_from_file e_boolean_exists_from_file = new File.Class_boolean_exists_from_file();
  public static final Func_boolean_exists_from_file t_boolean_exists_from_file = new File.Class_boolean_exists_from_file();

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
  public static interface Func_boolean_write_from_file extends Core.Func_any_from_any_context {
    public Core.Type_boolean vx_boolean_write_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_boolean_write_from_file extends Core.Class_base implements Func_boolean_write_from_file {

    @Override
    public Func_boolean_write_from_file vx_new(Object... vals) {
      Class_boolean_write_from_file output = new Class_boolean_write_from_file();
      return output;
    }

    @Override
    public Func_boolean_write_from_file vx_copy(Object... vals) {
      Class_boolean_write_from_file output = new Class_boolean_write_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_write_from_file vx_empty() {return e_boolean_write_from_file;}
    @Override
    public Func_boolean_write_from_file vx_type() {return t_boolean_write_from_file;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_boolean_write_from_file(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_boolean_write_from_file(context, file);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_file(final Core.Type_context context, final File.Type_file file) {
      return File.f_boolean_write_from_file(context, file);
    }

  }

  public static final Func_boolean_write_from_file e_boolean_write_from_file = new File.Class_boolean_write_from_file();
  public static final Func_boolean_write_from_file t_boolean_write_from_file = new File.Class_boolean_write_from_file();

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
  public static interface Func_boolean_write_from_file_any extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_file_any(final Core.Type_context context, final File.Type_file file, final Core.Type_any val);
  }

  public static class Class_boolean_write_from_file_any extends Core.Class_base implements Func_boolean_write_from_file_any {

    @Override
    public Func_boolean_write_from_file_any vx_new(Object... vals) {
      Class_boolean_write_from_file_any output = new Class_boolean_write_from_file_any();
      return output;
    }

    @Override
    public Func_boolean_write_from_file_any vx_copy(Object... vals) {
      Class_boolean_write_from_file_any output = new Class_boolean_write_from_file_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_write_from_file_any vx_empty() {return e_boolean_write_from_file_any;}
    @Override
    public Func_boolean_write_from_file_any vx_type() {return t_boolean_write_from_file_any;}

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
      return File.f_boolean_write_from_file_any(context, file, val);
    }

  }

  public static final Func_boolean_write_from_file_any e_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();
  public static final Func_boolean_write_from_file_any t_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();

  public static Core.Type_boolean f_boolean_write_from_file_any(final Core.Type_context context, final File.Type_file file, final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = File.f_boolean_write_from_file_string(
      context,
      file,
      Core.f_string_from_any(val)
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
  public static interface Func_boolean_write_from_file_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_file_string(final Core.Type_context context, final File.Type_file file, final Core.Type_string text);
  }

  public static class Class_boolean_write_from_file_string extends Core.Class_base implements Func_boolean_write_from_file_string {

    @Override
    public Func_boolean_write_from_file_string vx_new(Object... vals) {
      Class_boolean_write_from_file_string output = new Class_boolean_write_from_file_string();
      return output;
    }

    @Override
    public Func_boolean_write_from_file_string vx_copy(Object... vals) {
      Class_boolean_write_from_file_string output = new Class_boolean_write_from_file_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_boolean_write_from_file_string vx_empty() {return e_boolean_write_from_file_string;}
    @Override
    public Func_boolean_write_from_file_string vx_type() {return t_boolean_write_from_file_string;}

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
      return File.f_boolean_write_from_file_string(context, file, text);
    }

  }

  public static final Func_boolean_write_from_file_string e_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();
  public static final Func_boolean_write_from_file_string t_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();

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
        output = output.vx_copy(msg);
      }
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("boolean-write<-file-string"));
      output = output.vx_copy(msg);
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
  public static interface Func_file_read_from_file extends Core.Func_any_from_any_context {
    public File.Type_file vx_file_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_file_read_from_file extends Core.Class_base implements Func_file_read_from_file {

    @Override
    public Func_file_read_from_file vx_new(Object... vals) {
      Class_file_read_from_file output = new Class_file_read_from_file();
      return output;
    }

    @Override
    public Func_file_read_from_file vx_copy(Object... vals) {
      Class_file_read_from_file output = new Class_file_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_file_read_from_file vx_empty() {return e_file_read_from_file;}
    @Override
    public Func_file_read_from_file vx_type() {return t_file_read_from_file;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_file_read_from_file(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_file_read_from_file(context, file);
      return output;
    }

    @Override
    public File.Type_file vx_file_read_from_file(final Core.Type_context context, final File.Type_file file) {
      return File.f_file_read_from_file(context, file);
    }

  }

  public static final Func_file_read_from_file e_file_read_from_file = new File.Class_file_read_from_file();
  public static final Func_file_read_from_file t_file_read_from_file = new File.Class_file_read_from_file();

  public static File.Type_file f_file_read_from_file(final Core.Type_context context, final File.Type_file file) {
    File.Type_file output = File.e_file;
    if (Core.f_boolean_permission_from_func(context, File.t_file_read_from_file).vx_boolean()) {
      output = Core.f_copy(
        file,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":text"),
          File.f_string_read_from_file(context, file)
        )
      );
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("file-read<-file"));
      output = output.vx_copy(msg);
    }
    return output;
  }

  /**
   * @function name_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   * (func name<-file)
   */
  public static interface Func_name_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_name_from_file(final File.Type_file file);
  }

  public static class Class_name_from_file extends Core.Class_base implements Func_name_from_file {

    @Override
    public Func_name_from_file vx_new(Object... vals) {
      Class_name_from_file output = new Class_name_from_file();
      return output;
    }

    @Override
    public Func_name_from_file vx_copy(Object... vals) {
      Class_name_from_file output = new Class_name_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_name_from_file vx_empty() {return e_name_from_file;}
    @Override
    public Func_name_from_file vx_type() {return t_name_from_file;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_name_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_name_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_name_from_file(final File.Type_file file) {
      return File.f_name_from_file(file);
    }

  }

  public static final Func_name_from_file e_name_from_file = new File.Class_name_from_file();
  public static final Func_name_from_file t_name_from_file = new File.Class_name_from_file();

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
  public static interface Func_path_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_path_from_file(final File.Type_file file);
  }

  public static class Class_path_from_file extends Core.Class_base implements Func_path_from_file {

    @Override
    public Func_path_from_file vx_new(Object... vals) {
      Class_path_from_file output = new Class_path_from_file();
      return output;
    }

    @Override
    public Func_path_from_file vx_copy(Object... vals) {
      Class_path_from_file output = new Class_path_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_path_from_file vx_empty() {return e_path_from_file;}
    @Override
    public Func_path_from_file vx_type() {return t_path_from_file;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_path_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_path_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_path_from_file(final File.Type_file file) {
      return File.f_path_from_file(file);
    }

  }

  public static final Func_path_from_file e_path_from_file = new File.Class_path_from_file();
  public static final Func_path_from_file t_path_from_file = new File.Class_path_from_file();

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
  public static interface Func_pathcurrent_from_os extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_pathcurrent_from_os();
  }

  public static class Class_pathcurrent_from_os extends Core.Class_base implements Func_pathcurrent_from_os {

    @Override
    public Func_pathcurrent_from_os vx_new(Object... vals) {
      Class_pathcurrent_from_os output = new Class_pathcurrent_from_os();
      return output;
    }

    @Override
    public Func_pathcurrent_from_os vx_copy(Object... vals) {
      Class_pathcurrent_from_os output = new Class_pathcurrent_from_os();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_pathcurrent_from_os vx_empty() {return e_pathcurrent_from_os;}
    @Override
    public Func_pathcurrent_from_os vx_type() {return t_pathcurrent_from_os;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = File.f_pathcurrent_from_os();
      return output;
    }

    @Override
    public Core.Type_string vx_pathcurrent_from_os() {
      return File.f_pathcurrent_from_os();
    }

  }

  public static final Func_pathcurrent_from_os e_pathcurrent_from_os = new File.Class_pathcurrent_from_os();
  public static final Func_pathcurrent_from_os t_pathcurrent_from_os = new File.Class_pathcurrent_from_os();

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
  public static interface Func_pathfull_from_file extends Core.Func_any_from_any {
    public Core.Type_string vx_pathfull_from_file(final File.Type_file file);
  }

  public static class Class_pathfull_from_file extends Core.Class_base implements Func_pathfull_from_file {

    @Override
    public Func_pathfull_from_file vx_new(Object... vals) {
      Class_pathfull_from_file output = new Class_pathfull_from_file();
      return output;
    }

    @Override
    public Func_pathfull_from_file vx_copy(Object... vals) {
      Class_pathfull_from_file output = new Class_pathfull_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_pathfull_from_file vx_empty() {return e_pathfull_from_file;}
    @Override
    public Func_pathfull_from_file vx_type() {return t_pathfull_from_file;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_pathfull_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_pathfull_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string vx_pathfull_from_file(final File.Type_file file) {
      return File.f_pathfull_from_file(file);
    }

  }

  public static final Func_pathfull_from_file e_pathfull_from_file = new File.Class_pathfull_from_file();
  public static final Func_pathfull_from_file t_pathfull_from_file = new File.Class_pathfull_from_file();

  public static Core.Type_string f_pathfull_from_file(final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string path = File.f_path_from_file(file);
        final Core.Type_string name = File.f_name_from_file(file);
        return Core.f_new(
          Core.t_string,
          Core.t_anylist.vx_new(
            path,
            Core.vx_new_string("/"),
            name
          )
        );
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
  public static interface Func_string_read_from_file extends Core.Func_any_from_any_context {
    public Core.Type_string vx_string_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_string_read_from_file extends Core.Class_base implements Func_string_read_from_file {

    @Override
    public Func_string_read_from_file vx_new(Object... vals) {
      Class_string_read_from_file output = new Class_string_read_from_file();
      return output;
    }

    @Override
    public Func_string_read_from_file vx_copy(Object... vals) {
      Class_string_read_from_file output = new Class_string_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
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
    }

    @Override
    public Func_string_read_from_file vx_empty() {return e_string_read_from_file;}
    @Override
    public Func_string_read_from_file vx_type() {return t_string_read_from_file;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_string_read_from_file(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = File.f_string_read_from_file(context, file);
      return output;
    }

    @Override
    public Core.Type_string vx_string_read_from_file(final Core.Type_context context, final File.Type_file file) {
      return File.f_string_read_from_file(context, file);
    }

  }

  public static final Func_string_read_from_file e_string_read_from_file = new File.Class_string_read_from_file();
  public static final Func_string_read_from_file t_string_read_from_file = new File.Class_string_read_from_file();

  public static Core.Type_string f_string_read_from_file(final Core.Type_context context, final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    if (Core.f_boolean_permission_from_func(context, File.t_string_read_from_file).vx_boolean()) {
      try {
        output = vx_string_read_from_file(file);
      } catch (Exception err) {
        Core.Type_msg msg = Core.vx_msg_from_exception("vx/data/file/string-read<-file", err);
        output = output.vx_copy(msg);
      }
    } else {
      Core.Type_msg msg = Core.vx_msg_from_error("vx/core/func", ":permissiondenied", Core.vx_new_string("string-read<-file"));
      output = output.vx_copy(msg);
    }
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("file", File.t_file);
    maptype.put("fileformat", File.t_fileformat);
    mapfunc.put("boolean-exists<-file", File.t_boolean_exists_from_file);
    mapfunc.put("boolean-write<-file", File.t_boolean_write_from_file);
    mapfunc.put("boolean-write<-file-any", File.t_boolean_write_from_file_any);
    mapfunc.put("boolean-write<-file-string", File.t_boolean_write_from_file_string);
    mapfunc.put("file-read<-file", File.t_file_read_from_file);
    mapfunc.put("name<-file", File.t_name_from_file);
    mapfunc.put("path<-file", File.t_path_from_file);
    mapfunc.put("pathcurrent<-os", File.t_pathcurrent_from_os);
    mapfunc.put("pathfull<-file", File.t_pathfull_from_file);
    mapfunc.put("string-read<-file", File.t_string_read_from_file);
    Core.vx_global_package_set("vx/data/file", maptype, mapconst, mapfunc);
  }

}
