package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import com.vxlisp.vx.*;

public final class Csv {


  /**
   * type: csv
   * (type csv)
   */
  public interface Type_csv extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_stringlist headers();
    public Csv.Type_csvrows rows();
  }

  public static class Class_csv extends Core.Class_base implements Type_csv {

    public Core.Type_stringlist vx_p_headers;

    @Override
    public Core.Type_stringlist headers() {
      return this.vx_p_headers == null ? Core.e_stringlist : this.vx_p_headers;
    }

    public Csv.Type_csvrows vx_p_rows;

    @Override
    public Csv.Type_csvrows rows() {
      return this.vx_p_rows == null ? Csv.e_csvrows : this.vx_p_rows;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":headers", this.headers());
      output.put(":rows", this.rows());
      return Core.immutablemap(output);
    }

    @Override
    public Csv.Type_csv vx_new(final Object... vals) {
      return Core.vx_copy(
       e_csv,
       vals);
    }

    @Override
    public Csv.Type_csv vx_copy(final Object... vals) {
      Type_csv output = this;
      boolean ischanged = false;
      Class_csv val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_stringlist vx_p_headers = val.headers();
      Csv.Type_csvrows vx_p_rows = val.rows();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":headers");
      validkeys.add(":rows");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkeytype", msgval);
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
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":headers":
            if (valsub == vx_p_headers) {
            } else if (valsub instanceof Core.Type_stringlist) {
              ischanged = true;
              vx_p_headers = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("headers"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":rows":
            if (valsub == vx_p_rows) {
            } else if (valsub instanceof Csv.Type_csvrows) {
              ischanged = true;
              vx_p_rows = (Csv.Type_csvrows)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("rows"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_csv work = new Class_csv();
        work.vx_p_headers = vx_p_headers;
        work.vx_p_rows = vx_p_rows;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_csv;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_csv;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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

  public static final Type_csv e_csv = new Class_csv();
  public static final Type_csv t_csv = new Class_csv();

  /**
   * type: csvrowmap
   * (type csvrowmap)
   */
  public interface Type_csvrowmap extends Core.Type_map {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Core.Type_stringlist> vx_mapstringlist();
    public Core.Type_stringlist vx_stringlist(final Core.Type_string key);
  }

  public static class Class_csvrowmap extends Core.Class_base implements Type_csvrowmap {

    public Map<String, Core.Type_stringlist> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_stringlist>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (value instanceof Core.Type_stringlist) {
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Core.Type_stringlist castval = (Core.Type_stringlist)value;
        Map<String, Core.Type_stringlist> map = new LinkedHashMap<>(this.vx_p_map);
        if (castval == Core.e_stringlist) {
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
    public Core.Type_stringlist vx_stringlist(final Core.Type_string key) {
      Core.Type_stringlist output = Core.e_stringlist;
      Csv.Class_csvrowmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_stringlist> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_stringlist);
      return output;
    }

    @Override
    public Map<String, Core.Type_stringlist> vx_mapstringlist() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_stringlist(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Csv.Class_csvrowmap output = new Csv.Class_csvrowmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_stringlist> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_stringlist) {
          Core.Type_stringlist castval = (Core.Type_stringlist)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidvalue", val);
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
    public Csv.Type_csvrowmap vx_new(final Object... vals) {
      return Core.vx_copy(
       e_csvrowmap,
       vals);
    }

    @Override
    public Csv.Type_csvrowmap vx_copy(final Object... vals) {
      Type_csvrowmap output = this;
      boolean ischanged = false;
      Class_csvrowmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Core.Type_stringlist> mapval = new LinkedHashMap<>(val.vx_mapstringlist());
      Core.Type_msg msg;
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_stringlist valany = null;
          if (valsub instanceof Core.Type_stringlist) {
            valany = (Core.Type_stringlist)valsub;
          } else if (valsub instanceof Core.Type_stringlist) {
            valany = (Core.Type_stringlist)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
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
        Class_csvrowmap work = new Class_csvrowmap();
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
      return e_csvrowmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_csvrowmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrowmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Core.t_stringlist), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_csvrowmap e_csvrowmap = new Class_csvrowmap();
  public static final Type_csvrowmap t_csvrowmap = new Class_csvrowmap();

  /**
   * type: csvrows
   * (type csvrows)
   */
  public interface Type_csvrows extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Core.Type_stringlist> vx_liststringlist();
    public Core.Type_stringlist vx_stringlist(final Core.Type_int index);
  }

  public static class Class_csvrows extends Core.Class_base implements Type_csvrows {

    public List<Core.Type_stringlist> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_stringlist>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));
      return output;
    }

    @Override
    public Core.Type_stringlist vx_stringlist(final Core.Type_int index) {
      Core.Type_stringlist output = Core.e_stringlist;
      Csv.Class_csvrows list = this;
      int iindex = index.vx_int();
      List<Core.Type_stringlist> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_stringlist> vx_liststringlist() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_stringlist(index);
    }

    @Override
    public Csv.Type_csvrows vx_new(final Object... vals) {
      return Core.vx_copy(
       e_csvrows,
       vals);
    }

    @Override
    public Csv.Type_csvrows vx_copy(final Object... vals) {
      Type_csvrows output = this;
      boolean ischanged = false;
      Class_csvrows val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Core.Type_stringlist> listval = new ArrayList<>(val.vx_liststringlist());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_stringlist) {
          Core.Type_stringlist anysub = (Core.Type_stringlist)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Core.Type_stringlist) {
          ischanged = true;
          listval.add((Core.Type_stringlist)valsub);
        } else if (valsub instanceof Csv.Type_csvrows) {
          Type_csvrows multi = (Type_csvrows)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststringlist());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_stringlist) {
              Core.Type_stringlist valitem = (Core.Type_stringlist)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_csvrows work = new Class_csvrows();
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
      return e_csvrows;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_csvrows;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Core.t_stringlist), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_csvrows e_csvrows = new Class_csvrows();
  public static final Type_csvrows t_csvrows = new Class_csvrows();

  /**
   * Constant: delimcsv
   * Csv File Delimiters
   * {delim}
   */
  public static class Const_delimcsv extends Textblock.Class_delim implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/csv", // pkgname
        "delimcsv", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_delimcsv output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimcsv"),
                Core.vx_new_string(":delimlist"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.vx_new(Core.t_anylist,
                    Textblock.c_delimline,
                    Textblock.c_delimquote,
                    Textblock.c_delimcomma
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

  public static final Const_delimcsv c_delimcsv = new Const_delimcsv();

  /**
   * @function csv_read_from_file
   * Returns a parsed csv from a file.
   * @param  {file} file
   * @return {csv}
   * (func csv-read<-file)
   */
  public interface Func_csv_read_from_file extends Core.Func_any_from_any_context {
    public Csv.Type_csv vx_csv_read_from_file(final Core.Type_context context, final File.Type_file file);
  }

  public static class Class_csv_read_from_file extends Core.Class_base implements Func_csv_read_from_file {

    @Override
    public Csv.Func_csv_read_from_file vx_new(final Object... vals) {
      Class_csv_read_from_file output = new Class_csv_read_from_file();
      return output;
    }

    @Override
    public Csv.Func_csv_read_from_file vx_copy(final Object... vals) {
      Class_csv_read_from_file output = new Class_csv_read_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv-read<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
    public Core.Type_any vx_empty() {
      return e_csv_read_from_file;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_csv_read_from_file;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = Csv.f_csv_read_from_file(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_read_from_file(context, file);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_read_from_file(final Core.Type_context context, final File.Type_file file) {
      return Csv.f_csv_read_from_file(context, file);
    }

  }

  public static final Func_csv_read_from_file e_csv_read_from_file = new Csv.Class_csv_read_from_file();
  public static final Func_csv_read_from_file t_csv_read_from_file = new Csv.Class_csv_read_from_file();

  public static Csv.Type_csv f_csv_read_from_file(final Core.Type_context context, final File.Type_file file) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        final File.Type_file loaded = File.f_file_read_from_file(context, file);
        return Csv.f_csv_from_file(loaded);
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
  public interface Func_csv_from_file extends Core.Func_any_from_any {
    public Csv.Type_csv vx_csv_from_file(final File.Type_file file);
  }

  public static class Class_csv_from_file extends Core.Class_base implements Func_csv_from_file {

    @Override
    public Csv.Func_csv_from_file vx_new(final Object... vals) {
      Class_csv_from_file output = new Class_csv_from_file();
      return output;
    }

    @Override
    public Csv.Func_csv_from_file vx_copy(final Object... vals) {
      Class_csv_from_file output = new Class_csv_from_file();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-file", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
    public Core.Type_any vx_empty() {
      return e_csv_from_file;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_csv_from_file;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      File.Type_file inputval = (File.Type_file)value;
      Core.Type_any outputval = Csv.f_csv_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_file(file);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_file(final File.Type_file file) {
      return Csv.f_csv_from_file(file);
    }

  }

  public static final Func_csv_from_file e_csv_from_file = new Csv.Class_csv_from_file();
  public static final Func_csv_from_file t_csv_from_file = new Csv.Class_csv_from_file();

  public static Csv.Type_csv f_csv_from_file(final File.Type_file file) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = file.text();
        return Csv.f_csv_from_string(text);
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
  public interface Func_csv_from_string extends Core.Func_any_from_any {
    public Csv.Type_csv vx_csv_from_string(final Core.Type_string text);
  }

  public static class Class_csv_from_string extends Core.Class_base implements Func_csv_from_string {

    @Override
    public Csv.Func_csv_from_string vx_new(final Object... vals) {
      Class_csv_from_string output = new Class_csv_from_string();
      return output;
    }

    @Override
    public Csv.Func_csv_from_string vx_copy(final Object... vals) {
      Class_csv_from_string output = new Class_csv_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
    public Core.Type_any vx_empty() {
      return e_csv_from_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_csv_from_string;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Csv.f_csv_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_string(text);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_string(final Core.Type_string text) {
      return Csv.f_csv_from_string(text);
    }

  }

  public static final Func_csv_from_string e_csv_from_string = new Csv.Class_csv_from_string();
  public static final Func_csv_from_string t_csv_from_string = new Csv.Class_csv_from_string();

  public static Csv.Type_csv f_csv_from_string(final Core.Type_string text) {
    Csv.Type_csv output = Csv.e_csv;
    output = Csv.f_csv_from_textblock(
      Textblock.f_textblock_parse_from_string_delim(
        text,
        Csv.c_delimcsv
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
  public interface Func_csv_from_textblock extends Core.Func_any_from_any {
    public Csv.Type_csv vx_csv_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_csv_from_textblock extends Core.Class_base implements Func_csv_from_textblock {

    @Override
    public Csv.Func_csv_from_textblock vx_new(final Object... vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    @Override
    public Csv.Func_csv_from_textblock vx_copy(final Object... vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
    public Core.Type_any vx_empty() {
      return e_csv_from_textblock;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_csv_from_textblock;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Csv.f_csv_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_textblock(final Textblock.Type_textblock textblock) {
      return Csv.f_csv_from_textblock(textblock);
    }

  }

  public static final Func_csv_from_textblock e_csv_from_textblock = new Csv.Class_csv_from_textblock();
  public static final Func_csv_from_textblock t_csv_from_textblock = new Csv.Class_csv_from_textblock();

  public static Csv.Type_csv f_csv_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Csv.Type_csvrows allrows = Csv.f_csvrows_from_textblock(textblock);
        final Core.Type_stringlist headers = Core.f_any_from_list(Core.t_stringlist, allrows, Core.vx_new_int(1));
        final Csv.Type_csvrows rows = Collection.f_list_from_list_end(Csv.t_csvrows, allrows, Core.vx_new_int(2));
        return Core.f_new(
          Csv.t_csv,
          Core.vx_new(Core.t_anylist,
            Core.vx_new_string(":headers"),
            headers,
            Core.vx_new_string(":rows"),
            rows
          )
        );
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
  public interface Func_csvrows_from_textblock extends Core.Func_any_from_any {
    public Csv.Type_csvrows vx_csvrows_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_csvrows_from_textblock extends Core.Class_base implements Func_csvrows_from_textblock {

    @Override
    public Csv.Func_csvrows_from_textblock vx_new(final Object... vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    @Override
    public Csv.Func_csvrows_from_textblock vx_copy(final Object... vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csvrows", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_stringlist), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_csvrows_from_textblock;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_csvrows_from_textblock;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Csv.f_csvrows_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csvrows_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csvrows vx_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
      return Csv.f_csvrows_from_textblock(textblock);
    }

  }

  public static final Func_csvrows_from_textblock e_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();
  public static final Func_csvrows_from_textblock t_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();

  public static Csv.Type_csvrows f_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csvrows output = Csv.e_csvrows;
    output = Core.f_let(
      Csv.t_csvrows,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblock parsedtb = Textblock.f_textblock_from_textblock_delim(
          textblock,
          Csv.c_delimcsv
        );
        final Textblock.Type_textblocklist children = Textblock.f_children_from_textblock(parsedtb);
        final Core.Type_stringlist strings = Textblock.f_stringlist_from_textblocklist(children);
        return Core.f_new(
          Csv.t_csvrows,
          Core.vx_new(Core.t_anylist,
            strings
          )
        );
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
  public interface Func_stringmap_from_csv extends Core.Func_any_from_any {
    public Core.Type_stringmap vx_stringmap_from_csv(final Csv.Type_csv csv);
  }

  public static class Class_stringmap_from_csv extends Core.Class_base implements Func_stringmap_from_csv {

    @Override
    public Csv.Func_stringmap_from_csv vx_new(final Object... vals) {
      Class_stringmap_from_csv output = new Class_stringmap_from_csv();
      return output;
    }

    @Override
    public Csv.Func_stringmap_from_csv vx_copy(final Object... vals) {
      Class_stringmap_from_csv output = new Class_stringmap_from_csv();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "stringmap<-csv", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_string), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_stringmap_from_csv;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_stringmap_from_csv;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Csv.Type_csv inputval = (Csv.Type_csv)value;
      Core.Type_any outputval = Csv.f_stringmap_from_csv(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Csv.Type_csv csv = Core.f_any_from_any(Csv.t_csv, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_stringmap_from_csv(csv);
      return output;
    }

    @Override
    public Core.Type_stringmap vx_stringmap_from_csv(final Csv.Type_csv csv) {
      return Csv.f_stringmap_from_csv(csv);
    }

  }

  public static final Func_stringmap_from_csv e_stringmap_from_csv = new Csv.Class_stringmap_from_csv();
  public static final Func_stringmap_from_csv t_stringmap_from_csv = new Csv.Class_stringmap_from_csv();

  public static Core.Type_stringmap f_stringmap_from_csv(final Csv.Type_csv csv) {
    Core.Type_stringmap output = Core.e_stringmap;
    output = Core.f_let(
      Core.t_stringmap,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Csv.Type_csvrows rows = csv.rows();
        final Csv.Type_csvrowmap rowmap = Core.f_map_from_list(
          Csv.t_csvrowmap,
          rows,
          Core.t_any_from_any.vx_fn_new((textlist_any) -> {
            Core.Type_stringlist textlist = Core.f_any_from_any(Core.t_stringlist, textlist_any);
            return 
              Core.f_any_from_list(Core.t_string, textlist, Core.vx_new_int(1));
          })
        );
        return Core.f_map_from_map_1(
          Core.t_stringmap,
          rowmap,
          Core.t_any_from_key_value.vx_fn_new((key_any, val_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Core.Type_stringlist val = Core.f_any_from_any(Core.t_stringlist, val_any);
            return 
            Core.f_any_from_list(Core.t_string, val, Core.vx_new_int(2));
          })
        );
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
  public interface Func_textblock_csv_from_string extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_csv_from_string(final Core.Type_string text);
  }

  public static class Class_textblock_csv_from_string extends Core.Class_base implements Func_textblock_csv_from_string {

    @Override
    public Csv.Func_textblock_csv_from_string vx_new(final Object... vals) {
      Class_textblock_csv_from_string output = new Class_textblock_csv_from_string();
      return output;
    }

    @Override
    public Csv.Func_textblock_csv_from_string vx_copy(final Object... vals) {
      Class_textblock_csv_from_string output = new Class_textblock_csv_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Core.Type_any vx_empty() {
      return e_textblock_csv_from_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_textblock_csv_from_string;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Csv.f_textblock_csv_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_textblock_csv_from_string(text);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_csv_from_string(final Core.Type_string text) {
      return Csv.f_textblock_csv_from_string(text);
    }

  }

  public static final Func_textblock_csv_from_string e_textblock_csv_from_string = new Csv.Class_textblock_csv_from_string();
  public static final Func_textblock_csv_from_string t_textblock_csv_from_string = new Csv.Class_textblock_csv_from_string();

  public static Textblock.Type_textblock f_textblock_csv_from_string(final Core.Type_string text) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Textblock.f_textblock_parse_from_string_delim(
      text,
      Csv.c_delimcsv
    );
    return output;
  }


  static {
    Const_delimcsv.const_new(c_delimcsv);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("csv", Csv.t_csv);
    maptype.put("csvrowmap", Csv.t_csvrowmap);
    maptype.put("csvrows", Csv.t_csvrows);
    mapconst.put("delimcsv", Csv.c_delimcsv);
    mapfunc.put("csv-read<-file", Csv.t_csv_read_from_file);
    mapfunc.put("csv<-file", Csv.t_csv_from_file);
    mapfunc.put("csv<-string", Csv.t_csv_from_string);
    mapfunc.put("csv<-textblock", Csv.t_csv_from_textblock);
    mapfunc.put("csvrows<-textblock", Csv.t_csvrows_from_textblock);
    mapfunc.put("stringmap<-csv", Csv.t_stringmap_from_csv);
    mapfunc.put("textblock-csv<-string", Csv.t_textblock_csv_from_string);
    Core.vx_global_package_set("vx/data/csv", maptype, mapconst, mapfunc);
  }

}
