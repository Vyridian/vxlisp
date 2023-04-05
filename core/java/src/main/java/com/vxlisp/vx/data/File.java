package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import java.nio.file.*;


public final class File {


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
      Class_file output = new Class_file();
      Type_file val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_format = val.format();
      output.vx_p_path = val.path();
      output.vx_p_permission = val.permission();
      output.vx_p_text = val.text();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":format");
      validkeys.add(":path");
      validkeys.add(":permission");
      validkeys.add(":text");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new file) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new file :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":format":
            if (valsub instanceof File.Type_fileformat) {
              output.vx_p_format = (File.Type_fileformat)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new file :format " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":path":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_path = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_path = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new file :path " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":permission":
            if (valsub instanceof Core.Type_permission) {
              output.vx_p_permission = (Core.Type_permission)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new file :permission " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":text":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_text = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_text = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new file :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new file) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
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
      Class_fileformat output = new Class_fileformat();
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
    public Core.Type_boolean f_boolean_exists_from_file(final File.Type_file file);
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_boolean_exists_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = File.f_boolean_exists_from_file(file);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_exists_from_file(final File.Type_file file) {
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
   * @function boolean_write_from_file_any
   * Write any data structure as a file.
   * @param  {file} file
   * @param  {any} val
   * @return {boolean}
   * (func boolean-write<-file-any)
   */
  public static interface Func_boolean_write_from_file_any extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_boolean_write_from_file_any(final File.Type_file file, final Core.Type_any val, Core.Type_context context);
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
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = File.f_boolean_write_from_file_any(file, val, context);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_write_from_file_any(final File.Type_file file, final Core.Type_any val, final Core.Type_context context) {
      return File.f_boolean_write_from_file_any(file, val, context);
    }

  }

  public static final Func_boolean_write_from_file_any e_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();
  public static final Func_boolean_write_from_file_any t_boolean_write_from_file_any = new File.Class_boolean_write_from_file_any();

  public static Core.Type_boolean f_boolean_write_from_file_any(final File.Type_file file, final Core.Type_any val, final Core.Type_context context) {
    Core.Type_boolean output = Core.e_boolean;
    output = File.f_boolean_write_from_file_string(
      file,
      Core.f_string_from_any(val),
      context
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
    public Core.Type_boolean f_boolean_write_from_file_string(final File.Type_file file, final Core.Type_string text, Core.Type_context context);
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
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = File.f_boolean_write_from_file_string(file, text, context);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_write_from_file_string(final File.Type_file file, final Core.Type_string text, final Core.Type_context context) {
      return File.f_boolean_write_from_file_string(file, text, context);
    }

  }

  public static final Func_boolean_write_from_file_string e_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();
  public static final Func_boolean_write_from_file_string t_boolean_write_from_file_string = new File.Class_boolean_write_from_file_string();

  public static Core.Type_boolean f_boolean_write_from_file_string(final File.Type_file file, final Core.Type_string text, final Core.Type_context context) {
      Core.Type_boolean output = Core.e_boolean;
    try {
      Core.Type_string fullpath = File.f_pathfull_from_file(file);
      String sfullpath = fullpath.vx_string();
      Path path = Paths.get(sfullpath);
      String stext = text.vx_string();
      byte[] bytes = stext.getBytes();
      java.nio.file.Files.write(path, bytes);
      output = Core.c_true;
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("boolean-write<-file-string", err);
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
    public File.Type_file f_file_read_from_file(final File.Type_file file, Core.Type_context context);
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_file_read_from_file(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = File.f_file_read_from_file(file, context);
      return output;
    }

    @Override
    public File.Type_file f_file_read_from_file(final File.Type_file file, final Core.Type_context context) {
      return File.f_file_read_from_file(file, context);
    }

  }

  public static final Func_file_read_from_file e_file_read_from_file = new File.Class_file_read_from_file();
  public static final Func_file_read_from_file t_file_read_from_file = new File.Class_file_read_from_file();

  public static File.Type_file f_file_read_from_file(final File.Type_file file, final Core.Type_context context) {
    File.Type_file output = File.e_file;
    output = Core.f_copy(
      file,
      Core.t_anylist.vx_new(
        Core.t_string.vx_new_from_string(":text"),
        File.f_string_read_from_file(file, context)
      )
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
  public static interface Func_name_from_file extends Core.Func_any_from_any {
    public Core.Type_string f_name_from_file(final File.Type_file file);
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
          "string", // extends
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_name_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = File.f_name_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string f_name_from_file(final File.Type_file file) {
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
    public Core.Type_string f_path_from_file(final File.Type_file file);
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
          "string", // extends
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_path_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = File.f_path_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string f_path_from_file(final File.Type_file file) {
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
    public Core.Type_string f_pathcurrent_from_os();
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
          "string", // extends
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
    public Core.Type_string f_pathcurrent_from_os() {
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
    output = Core.t_string.vx_new_from_string(spath);
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
    public Core.Type_string f_pathfull_from_file(final File.Type_file file);
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
          "string", // extends
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_pathfull_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = File.f_pathfull_from_file(file);
      return output;
    }

    @Override
    public Core.Type_string f_pathfull_from_file(final File.Type_file file) {
      return File.f_pathfull_from_file(file);
    }

  }

  public static final Func_pathfull_from_file e_pathfull_from_file = new File.Class_pathfull_from_file();
  public static final Func_pathfull_from_file t_pathfull_from_file = new File.Class_pathfull_from_file();

  public static Core.Type_string f_pathfull_from_file(final File.Type_file file) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.fn_new(() -> {
        final Core.Type_string path = File.f_path_from_file(file);
        final Core.Type_string name = File.f_name_from_file(file);
        return Core.f_new(
          Core.t_string,
          Core.t_anylist.vx_new(
            path,
            Core.t_string.vx_new_from_string("/"),
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
    public Core.Type_string f_string_read_from_file(final File.Type_file file, Core.Type_context context);
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
          "string", // extends
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = File.f_string_read_from_file(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = File.f_string_read_from_file(file, context);
      return output;
    }

    @Override
    public Core.Type_string f_string_read_from_file(final File.Type_file file, final Core.Type_context context) {
      return File.f_string_read_from_file(file, context);
    }

  }

  public static final Func_string_read_from_file e_string_read_from_file = new File.Class_string_read_from_file();
  public static final Func_string_read_from_file t_string_read_from_file = new File.Class_string_read_from_file();

  public static Core.Type_string f_string_read_from_file(final File.Type_file file, final Core.Type_context context) {
      Core.Type_string output = Core.e_string;
    try {
      Core.Type_string fullpath = File.f_pathfull_from_file(file);
      String sfullpath = fullpath.vx_string();
      Path path = Paths.get(sfullpath);
      if (Files.exists(path)) {
        byte[] bytes = Files.readAllBytes(path);
        String scontent = new String(bytes);
        Core.Type_string valcontent = Core.t_string.vx_new_from_string(scontent);
        output = valcontent;
      } else {
        Core.Type_msg msg = Core.t_msg.vx_new_error("File Not Found: " + sfullpath);
        output = Core.t_string.vx_copy(output, msg);
      };
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("string-read<-file", err);
      output = output.vx_copy(msg);
    }
      return output;
  }


}
