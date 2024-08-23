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
    public Core.Type_stringlist headers();
    public Csv.Type_csvrows rows();
  }

  public static class Class_csv extends Core.Class_base implements Type_csv {

    public Core.Type_stringlist vx_p_headers = null;

    @Override
    public Core.Type_stringlist headers() {
      Core.Type_stringlist output = Core.e_stringlist;
      Core.Type_stringlist testnull = vx_p_headers;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Csv.Type_csvrows vx_p_rows = null;

    @Override
    public Csv.Type_csvrows rows() {
      Csv.Type_csvrows output = Csv.e_csvrows;
      Csv.Type_csvrows testnull = vx_p_rows;
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
      } else if ((skey.equals(":headers"))) {
        output = this.headers();
      } else if ((skey.equals(":rows"))) {
        output = this.rows();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":headers", this.headers());
      map.put(":rows", this.rows());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Type_csv output = Core.vx_copy(Csv.e_csv, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Type_csv output = this;
      boolean ischanged = false;
      Csv.Class_csv value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_stringlist vx_p_headers = value.headers();
      Csv.Type_csvrows vx_p_rows = value.rows();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":headers");
      validkeys.add(":rows");
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
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":headers"))) {
            if (valsub == vx_p_headers) {
            } else if (valsub instanceof Core.Type_stringlist) {
              Core.Type_stringlist valheaders = (Core.Type_stringlist)valsub;
              ischanged = true;
              vx_p_headers = valheaders;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("headers"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":rows"))) {
            if (valsub == vx_p_rows) {
            } else if (valsub instanceof Csv.Type_csvrows) {
              Csv.Type_csvrows valrows = (Csv.Type_csvrows)valsub;
              ischanged = true;
              vx_p_rows = valrows;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("rows"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/csv/csv", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Csv.Class_csv work = new Csv.Class_csv();
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
      Core.Type_any output = Csv.e_csv;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csv;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Csv.Type_csv e_csv = new Csv.Class_csv();
  public static final Csv.Type_csv t_csv = new Csv.Class_csv();

  /**
   * type: csvrowmap
   * (type csvrowmap)
   */
  public interface Type_csvrowmap extends Core.Type_map {
    public Map<String, Core.Type_stringlist> vx_mapstringlist();
    public Core.Type_stringlist vx_stringlist(final Core.Type_string key);
  }

  public static class Class_csvrowmap extends Core.Class_base implements Type_csvrowmap {

    public Map<String, Core.Type_stringlist> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_stringlist>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Core.Type_stringlist) {
        Core.Type_stringlist castval = (Core.Type_stringlist)value;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Core.Type_stringlist> map = new LinkedHashMap<String, Core.Type_stringlist>(this.vx_p_map);
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
      Map<String, Core.Type_stringlist> output = this.vx_p_map;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = this.vx_stringlist(key);
      return output;
    }


    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Csv.Class_csvrowmap output = new Csv.Class_csvrowmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_stringlist> map = new LinkedHashMap<String, Core.Type_stringlist>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any value = mapval.get(key);
        if (false) {
        } else if (value instanceof Core.Type_stringlist) {
          Core.Type_stringlist castval = (Core.Type_stringlist)value;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidvalue", value);
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
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Type_csvrowmap output = Core.vx_copy(Csv.e_csvrowmap, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Type_csvrowmap output = this;
      boolean ischanged = false;
      Csv.Class_csvrowmap value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Core.Type_stringlist> mapval = new LinkedHashMap<String, Core.Type_stringlist>(value.vx_mapstringlist());
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_stringlist valany = Core.e_stringlist;
          if (false) {
          } else if (valsub instanceof Core.Type_stringlist) {
            Core.Type_stringlist valallowed = (Core.Type_stringlist)valsub;
            valany = valallowed;
          } else if (valsub instanceof Core.Type_stringlist) {
            valany = (Core.Type_stringlist)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/data/csv/csvrowmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (valany != Core.e_any) {
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
        Csv.Class_csvrowmap work = new Csv.Class_csvrowmap();
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
      Core.Type_any output = Csv.e_csvrowmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csvrowmap;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Csv.Type_csvrowmap e_csvrowmap = new Csv.Class_csvrowmap();
  public static final Csv.Type_csvrowmap t_csvrowmap = new Csv.Class_csvrowmap();

  /**
   * type: csvrows
   * (type csvrows)
   */
  public interface Type_csvrows extends Core.Type_list {
    public List<Core.Type_stringlist> vx_liststringlist();
    public Core.Type_stringlist vx_stringlist(final Core.Type_int index);
  }

  public static class Class_csvrows extends Core.Class_base implements Type_csvrows {

    public List<Core.Type_stringlist> vx_p_list = Core.immutablelist(
      new ArrayList<Core.Type_stringlist>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
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
      List<Core.Type_stringlist> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_stringlist output = this.vx_stringlist(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Type_csvrows output = Core.vx_copy(Csv.e_csvrows, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Type_csvrows output = this;
      boolean ischanged = false;
      Csv.Class_csvrows value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Core.Type_stringlist> listval = new ArrayList<Core.Type_stringlist>(value.vx_liststringlist());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_stringlist) {
          Core.Type_stringlist allowsub = (Core.Type_stringlist)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Core.Type_stringlist) {
          ischanged = true;
          listval.add((Core.Type_stringlist)valsub);
        } else if (valsub instanceof Csv.Type_csvrows) {
          Csv.Type_csvrows multi = (Csv.Type_csvrows)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststringlist());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Core.Type_stringlist) {
              Core.Type_stringlist valitem = (Core.Type_stringlist)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/csv/csvrows", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Csv.Class_csvrows work = new Csv.Class_csvrows();
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
      Core.Type_any output = Csv.e_csvrows;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csvrows;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Csv.Type_csvrows e_csvrows = new Csv.Class_csvrows();
  public static final Csv.Type_csvrows t_csvrows = new Csv.Class_csvrows();

  /**
   * Constant: delimcsv
   * Csv File Delimiters
   * {delim}
   */
  public static class Const_delimcsv {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimcsv"),
          Core.vx_new_string(":delimlist"),
          Core.f_new(
            Textblock.t_delimlist,
            Core.vx_new(
              Core.t_anylist,
              Textblock.c_delimline,
              Textblock.c_delimquote,
              Textblock.c_delimcomma
            )
          )
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimcsv = new Textblock.Class_delim();

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
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_csv_read_from_file output = new Csv.Class_csv_read_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_csv_read_from_file output = new Csv.Class_csv_read_from_file();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_csv_read_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csv_read_from_file;
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
      Core.Type_any outputval = Csv.f_csv_read_from_file(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_read_from_file(context, file);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_read_from_file(final Core.Type_context context, final File.Type_file file) {
      Csv.Type_csv output = Csv.f_csv_read_from_file(context, file);
      return output;
    }

  }

  public static final Csv.Func_csv_read_from_file e_csv_read_from_file = new Csv.Class_csv_read_from_file();
  public static final Csv.Func_csv_read_from_file t_csv_read_from_file = new Csv.Class_csv_read_from_file();

  public static Csv.Type_csv f_csv_read_from_file(final Core.Type_context context, final File.Type_file file) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        File.Type_file loaded = File.f_file_read_from_file(
          context,
          file
        );
        Core.Type_any output_1 = Csv.f_csv_from_file(
          loaded
        );
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
  public interface Func_csv_from_file extends Core.Func_any_from_any {
    public Csv.Type_csv vx_csv_from_file(final File.Type_file file);
  }

  public static class Class_csv_from_file extends Core.Class_base implements Func_csv_from_file {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_csv_from_file output = new Csv.Class_csv_from_file();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_csv_from_file output = new Csv.Class_csv_from_file();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_csv_from_file;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csv_from_file;
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
      Core.Type_any outputval = Csv.f_csv_from_file(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      File.Type_file file = Core.f_any_from_any(File.t_file, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_file(file);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_file(final File.Type_file file) {
      Csv.Type_csv output = Csv.f_csv_from_file(file);
      return output;
    }

  }

  public static final Csv.Func_csv_from_file e_csv_from_file = new Csv.Class_csv_from_file();
  public static final Csv.Func_csv_from_file t_csv_from_file = new Csv.Class_csv_from_file();

  public static Csv.Type_csv f_csv_from_file(final File.Type_file file) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string text = file.text();
        Core.Type_any output_1 = Csv.f_csv_from_string(
          text
        );
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
  public interface Func_csv_from_string extends Core.Func_any_from_any {
    public Csv.Type_csv vx_csv_from_string(final Core.Type_string text);
  }

  public static class Class_csv_from_string extends Core.Class_base implements Func_csv_from_string {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_csv_from_string output = new Csv.Class_csv_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_csv_from_string output = new Csv.Class_csv_from_string();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_csv_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csv_from_string;
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
      Core.Type_any outputval = Csv.f_csv_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_string(text);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_string(final Core.Type_string text) {
      Csv.Type_csv output = Csv.f_csv_from_string(text);
      return output;
    }

  }

  public static final Csv.Func_csv_from_string e_csv_from_string = new Csv.Class_csv_from_string();
  public static final Csv.Func_csv_from_string t_csv_from_string = new Csv.Class_csv_from_string();

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
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_csv_from_textblock output = new Csv.Class_csv_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_csv_from_textblock output = new Csv.Class_csv_from_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_csv_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csv_from_textblock;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csv_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csv vx_csv_from_textblock(final Textblock.Type_textblock textblock) {
      Csv.Type_csv output = Csv.f_csv_from_textblock(textblock);
      return output;
    }

  }

  public static final Csv.Func_csv_from_textblock e_csv_from_textblock = new Csv.Class_csv_from_textblock();
  public static final Csv.Func_csv_from_textblock t_csv_from_textblock = new Csv.Class_csv_from_textblock();

  public static Csv.Type_csv f_csv_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.vx_fn_new(() -> {
        Csv.Type_csvrows allrows = Csv.f_csvrows_from_textblock(
          textblock
        );
        Core.Type_stringlist headers = Core.f_any_from_list(
          Core.t_stringlist,
          allrows,
          Core.vx_new_int(1)
        );
        Csv.Type_csvrows rows = Collection.f_list_from_list_end(
          Csv.t_csvrows,
          allrows,
          Core.vx_new_int(2)
        );
        Core.Type_any output_1 = Core.f_new(
          Csv.t_csv,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":headers"),
            headers,
            Core.vx_new_string(":rows"),
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
  public interface Func_csvrows_from_textblock extends Core.Func_any_from_any {
    public Csv.Type_csvrows vx_csvrows_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_csvrows_from_textblock extends Core.Class_base implements Func_csvrows_from_textblock {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_csvrows_from_textblock output = new Csv.Class_csvrows_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_csvrows_from_textblock output = new Csv.Class_csvrows_from_textblock();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_csvrows_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_csvrows_from_textblock;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_csvrows_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csvrows vx_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
      Csv.Type_csvrows output = Csv.f_csvrows_from_textblock(textblock);
      return output;
    }

  }

  public static final Csv.Func_csvrows_from_textblock e_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();
  public static final Csv.Func_csvrows_from_textblock t_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();

  public static Csv.Type_csvrows f_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csvrows output = Csv.e_csvrows;
    output = Core.f_let(
      Csv.t_csvrows,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblock parsedtb = Textblock.f_textblock_from_textblock_delim(
          textblock,
          Csv.c_delimcsv
        );
        Textblock.Type_textblocklist children = Textblock.f_children_from_textblock(
          parsedtb
        );
        Core.Type_stringlist strings = Textblock.f_stringlist_from_textblocklist(
          children
        );
        Core.Type_any output_1 = Core.f_new(
          Csv.t_csvrows,
          Core.vx_new(
            Core.t_anylist,
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
  public interface Func_stringmap_from_csv extends Core.Func_any_from_any {
    public Core.Type_stringmap vx_stringmap_from_csv(final Csv.Type_csv csv);
  }

  public static class Class_stringmap_from_csv extends Core.Class_base implements Func_stringmap_from_csv {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_stringmap_from_csv output = new Csv.Class_stringmap_from_csv();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_stringmap_from_csv output = new Csv.Class_stringmap_from_csv();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_stringmap_from_csv;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_stringmap_from_csv;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Csv.Type_csv csv = Core.f_any_from_any(Csv.t_csv, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_stringmap_from_csv(csv);
      return output;
    }

    @Override
    public Core.Type_stringmap vx_stringmap_from_csv(final Csv.Type_csv csv) {
      Core.Type_stringmap output = Csv.f_stringmap_from_csv(csv);
      return output;
    }

  }

  public static final Csv.Func_stringmap_from_csv e_stringmap_from_csv = new Csv.Class_stringmap_from_csv();
  public static final Csv.Func_stringmap_from_csv t_stringmap_from_csv = new Csv.Class_stringmap_from_csv();

  public static Core.Type_stringmap f_stringmap_from_csv(final Csv.Type_csv csv) {
    Core.Type_stringmap output = Core.e_stringmap;
    output = Core.f_let(
      Core.t_stringmap,
      Core.t_any_from_func.vx_fn_new(() -> {
        Csv.Type_csvrows rows = csv.rows();
        Csv.Type_csvrowmap rowmap = Core.f_map_from_list(
          Csv.t_csvrowmap,
          rows,
          Core.t_any_from_any.vx_fn_new((textlist_any) -> {
            Core.Type_stringlist textlist = Core.f_any_from_any(Core.t_stringlist, textlist_any);
            Core.Type_any output_3 = Core.f_any_from_list(
              Core.t_string,
              textlist,
              Core.vx_new_int(1)
            );
            return output_3;
          })
        );
        Core.Type_any output_1 = Core.f_map_from_map_1(
          Core.t_stringmap,
          rowmap,
          Core.t_any_from_key_value.vx_fn_new((key_any, val_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            Core.Type_stringlist val = Core.f_any_from_any(Core.t_stringlist, val_any);
            Core.Type_any output_2 = Core.f_any_from_list(
              Core.t_string,
              val,
              Core.vx_new_int(2)
            );
            return output_2;
          })
        );
        return output_1;
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
    public Core.Type_any vx_new(final Object... vals) {
      Csv.Class_textblock_csv_from_string output = new Csv.Class_textblock_csv_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Csv.Class_textblock_csv_from_string output = new Csv.Class_textblock_csv_from_string();
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Csv.e_textblock_csv_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Csv.t_textblock_csv_from_string;
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
      Core.Type_any outputval = Csv.f_textblock_csv_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Csv.f_textblock_csv_from_string(text);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_csv_from_string(final Core.Type_string text) {
      Textblock.Type_textblock output = Csv.f_textblock_csv_from_string(text);
      return output;
    }

  }

  public static final Csv.Func_textblock_csv_from_string e_textblock_csv_from_string = new Csv.Class_textblock_csv_from_string();
  public static final Csv.Func_textblock_csv_from_string t_textblock_csv_from_string = new Csv.Class_textblock_csv_from_string();

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
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
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
