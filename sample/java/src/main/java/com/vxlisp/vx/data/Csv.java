package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;


public final class Csv {


  /**
   * type: csv
   * (type csv)
   */
  public interface Type_csv extends Core.Type_struct {
    public Csv.Type_csv vx_new(final Object... vals);
    public Csv.Type_csv vx_copy(final Object... vals);
    public Csv.Type_csv vx_empty();
    public Csv.Type_csv vx_type();
    public Core.Type_stringlist headers();
    public Csv.Type_csvrows rows();
  }

  public static class Class_csv extends Core.Class_base implements Type_csv {

    protected Core.Type_stringlist vx_p_headers;

    @Override
    public Core.Type_stringlist headers() {
      return this.vx_p_headers == null ? Core.e_stringlist : this.vx_p_headers;
    }

    protected Csv.Type_csvrows vx_p_rows;

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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":headers", this.headers());
      output.put(":rows", this.rows());
      return Core.immutablemap(output);
    }

    @Override
    public Type_csv vx_new(final Object... vals) {return e_csv.vx_copy(vals);}

    @Override
    public Type_csv vx_copy(final Object... vals) {
      Class_csv output = new Class_csv();
      Type_csv val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_headers = val.headers();
      output.vx_p_rows = val.rows();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":headers");
      validkeys.add(":rows");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new csv) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":headers":
            if (valsub instanceof Core.Type_stringlist) {
              output.vx_p_headers = (Core.Type_stringlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new csv :headers " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rows":
            if (valsub instanceof Csv.Type_csvrows) {
              output.vx_p_rows = (Csv.Type_csvrows)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new csv :rows " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new csv) - Invalid Key: " + key);
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
    public Type_csv vx_empty() {return e_csv;}
    @Override
    public Type_csv vx_type() {return t_csv;}

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
   * type: csvrows
   * (type csvrows)
   */
  public interface Type_csvrows extends Core.Type_list {
    public Csv.Type_csvrows vx_new(final Object... vals);
    public Csv.Type_csvrows vx_copy(final Object... vals);
    public Csv.Type_csvrows vx_empty();
    public Csv.Type_csvrows vx_type();
    public List<Core.Type_stringlist> vx_liststringlist();
    public Core.Type_stringlist vx_stringlist(final Core.Type_int index);
  }

  public static class Class_csvrows extends Core.Class_base implements Type_csvrows {

    protected List<Core.Type_stringlist> vxlist = Core.immutablelist(new ArrayList<Core.Type_stringlist>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Core.Type_stringlist vx_stringlist(final Core.Type_int index) {
      Core.Type_stringlist output = Core.e_stringlist;
      Class_csvrows list = this;
      int iindex = index.vx_int();
      List<Core.Type_stringlist> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_stringlist> vx_liststringlist() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_stringlist(index);
    }

    @Override
    public Type_csvrows vx_new(final Object... vals) {return e_csvrows.vx_copy(vals);}

    @Override
    public Type_csvrows vx_copy(final Object... vals) {
      Class_csvrows output = new Class_csvrows();
      Type_csvrows val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_stringlist> listval = new ArrayList<>(val.vx_liststringlist());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_stringlist) {
          listval.add((Core.Type_stringlist)valsub);
        } else if (valsub instanceof Core.Type_stringlist) {
          listval.add((Core.Type_stringlist)valsub);
        } else if (valsub instanceof Type_csvrows) {
          Type_csvrows multi = (Type_csvrows)valsub;
          listval.addAll(multi.vx_liststringlist());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_stringlist) {
              Core.Type_stringlist valitem = (Core.Type_stringlist)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new csvrows) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_csvrows vx_empty() {return e_csvrows;}
    @Override
    public Type_csvrows vx_type() {return t_csvrows;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_stringlist), // allowtypes
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
   * Constant: delims
   * {delimset}
   */
  public static class Const_delims extends Textblock.Class_delimset {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "vx/data/csv", // pkgname
        "delims", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delimset", // name
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

    public static Const_delims const_new() {
      Const_delims output = new Const_delims();
      Textblock.Type_delimset val = Core.f_new(
        Textblock.t_delimset,
        Core.t_anylist.vx_new(
                Core.t_string.vx_new_from_string(":split"),
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("\n")
                  )
                ),
                Core.t_string.vx_new_from_string(":subset"),
                Core.f_new(
                  Textblock.t_delimset,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":split"),
                    Core.f_new(
                      Core.t_stringlist,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string(",")
                      )
                    ),
                    Core.t_string.vx_new_from_string(":subset"),
                    Core.f_new(
                      Textblock.t_delimset,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string(":start"),
                        Core.f_new(
                          Core.t_stringlist,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string("\"")
                          )
                        ),
                        Core.t_string.vx_new_from_string(":end"),
                        Core.f_new(
                          Core.t_stringlist,
                          Core.t_anylist.vx_new(
                            Core.t_string.vx_new_from_string("\"")
                          )
                        )
                      )
                    )
                  )
                )
        )
      );
      output.vx_p_start = val.start();
      output.vx_p_end = val.end();
      output.vx_p_split = val.split();
      output.vx_p_subset = val.subset();
      return output;
    }


  }

  public static final Const_delims c_delims = Const_delims.const_new();

  /**
   * @function csv_from_textblock
   * @param  {textblock} textblock
   * @return {csv}
   * (func csv<-textblock)
   */
  public static interface Func_csv_from_textblock extends Core.Func_any_from_any {
    public Csv.Type_csv f_csv_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_csv_from_textblock extends Core.Class_base implements Func_csv_from_textblock {

    @Override
    public Func_csv_from_textblock vx_new(Object... vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    @Override
    public Func_csv_from_textblock vx_copy(Object... vals) {
      Class_csv_from_textblock output = new Class_csv_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_csv_from_textblock vx_empty() {return e_csv_from_textblock;}
    @Override
    public Func_csv_from_textblock vx_type() {return t_csv_from_textblock;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Csv.f_csv_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Csv.f_csv_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csv f_csv_from_textblock(final Textblock.Type_textblock textblock) {
      return Csv.f_csv_from_textblock(textblock);
    }

  }

  public static final Func_csv_from_textblock e_csv_from_textblock = new Csv.Class_csv_from_textblock();
  public static final Func_csv_from_textblock t_csv_from_textblock = new Csv.Class_csv_from_textblock();

  public static Csv.Type_csv f_csv_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csv output = Csv.e_csv;
    output = Core.f_let(
      Csv.t_csv,
      Core.t_any_from_func.fn_new(() -> {
        final Csv.Type_csvrows allrows = Csv.f_csvrows_from_textblock(textblock);
        final Core.Type_stringlist headers = Core.f_any_from_list(Core.t_stringlist, allrows, Core.t_int.vx_new_from_int(0));
        final Csv.Type_csvrows rows = Collection.f_list_from_list_end(Csv.t_csvrows, allrows, Core.t_int.vx_new_from_int(1));
        return Core.f_new(
          Csv.t_csv,
          Core.t_anylist.vx_new(
            Core.t_string.vx_new_from_string(":headers"),
            headers,
            Core.t_string.vx_new_from_string(":rows"),
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
  public static interface Func_csvrows_from_textblock extends Core.Func_any_from_any {
    public Csv.Type_csvrows f_csvrows_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_csvrows_from_textblock extends Core.Class_base implements Func_csvrows_from_textblock {

    @Override
    public Func_csvrows_from_textblock vx_new(Object... vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    @Override
    public Func_csvrows_from_textblock vx_copy(Object... vals) {
      Class_csvrows_from_textblock output = new Class_csvrows_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
          Core.t_typelist.vx_new(Core.t_stringlist), // allowtypes
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
    public Func_csvrows_from_textblock vx_empty() {return e_csvrows_from_textblock;}
    @Override
    public Func_csvrows_from_textblock vx_type() {return t_csvrows_from_textblock;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Csv.f_csvrows_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Csv.f_csvrows_from_textblock(textblock);
      return output;
    }

    @Override
    public Csv.Type_csvrows f_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
      return Csv.f_csvrows_from_textblock(textblock);
    }

  }

  public static final Func_csvrows_from_textblock e_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();
  public static final Func_csvrows_from_textblock t_csvrows_from_textblock = new Csv.Class_csvrows_from_textblock();

  public static Csv.Type_csvrows f_csvrows_from_textblock(final Textblock.Type_textblock textblock) {
    Csv.Type_csvrows output = Csv.e_csvrows;
    output = Core.f_let(
      Csv.t_csvrows,
      Core.t_any_from_func.fn_new(() -> {
        final Textblock.Type_textblock parsedtb = Textblock.f_parse(
          textblock,
          Csv.c_delims
        );
        final Textblock.Type_textblocklist childtbs = Textblock.f_textblocks_from_textblock(parsedtb);
        final Core.Type_stringlist strings = Textblock.f_stringlist_from_textblocklist(childtbs);
        return Core.f_new(
          Csv.t_csvrows,
          Core.t_anylist.vx_new(
            strings
          )
        );
      })
    );
    return output;
  }


}
