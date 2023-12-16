package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ConcurrentLinkedDeque;
import java.util.concurrent.ConcurrentHashMap;
import java.util.Deque;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.*;
import java.util.stream.Collectors;


public final class Core {

  public static interface vx_Type_const {
    public Core.Type_constdef vx_constdef();
  }

  public static interface Type_replfunc {
    public Core.Type_any vx_repl(Core.Type_anylist arglist);
  }

  public static interface Type_replfunc_async {
    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist);
  }

  public static List<Core.Type_any> emptylistany = Core.immutablelist(new ArrayList<Core.Type_any>());

  public static Map<String, Core.Type_any> emptymapany = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());

  public static <T> List<T> immutablelist(List<T> listany) {
    return Collections.unmodifiableList(listany);
  }

  public static <T> Map<String, T> immutablemap(Map<String, T> mapany) {
    return Collections.unmodifiableMap(mapany);
  }

  public static class Class_base {
    protected int vx_iref = 0;
    protected Core.Type_constdef vxconstdef = null;
    protected Core.Type_msgblock vxmsgblock = null;
    public List<Type_any> vx_dispose() {
      this.vx_iref = 0;
      this.vxmsgblock = null;
      return emptylistany;
    }
    public Core.Type_msgblock vx_msgblock() {return vxmsgblock;}
    public boolean vx_release() {
      boolean output = false;
      if (this.vx_iref < 0) {
      } else if (vx_iref == 0) {
        vx_iref = -1;
        output = true;
      } else {
        vx_iref -= 1;
      }
      return output;
    }
    public void vx_reserve() {this.vx_iref += 1;}
  }

  public static class KeyValue<T> {
    public String key = "";
    public T value = null;
  }

  public static Core.Type_constdef constdef_new(
    String pkgname,
    String name,
    Core.Type_any typ
  ) {
    Core.Class_constdef output = new Core.Class_constdef();
    output.vx_p_pkgname = Core.vx_new_string(pkgname);
    output.vx_p_name = Core.vx_new_string(name);
    output.vx_p_type = typ;
    return output;
  }

  public static Core.Type_funcdef funcdef_new(
    String pkgname,
    String name,
    int idx,
    boolean async,
    Core.Type_any typ
  ) {
    Core.Class_funcdef output = new Core.Class_funcdef();
    output.vx_p_pkgname = Core.vx_new_string(pkgname);
    output.vx_p_name = Core.vx_new_string(name);
    output.vx_p_idx = Core.vx_new_int(idx);
    output.vx_p_async = Core.vx_new_boolean(async);
    output.vx_p_type = typ;
    return output;
  }

  public static Core.Type_any[] arrayany_from_anylist(final Core.Type_anylist list) {
    return list.vx_list().toArray(new Core.Type_any[0]);
  }

  @SafeVarargs
  public static <T> List<T> arraylist_from_array(final T... items) {
    List<T> output = new ArrayList<T>(Arrays.asList(items));
    output = Core.immutablelist(output);
    return output;
  }

  public static <T extends Core.Type_any, U extends Core.Type_any> List<T> arraylist_from_arraylist(final T generic_any_1, final List<U> listval) {
    List<T> output = new ArrayList<>();
    for (Core.Type_any value : listval) {
      T t_val = Core.f_any_from_any(generic_any_1, value);
      output.add(t_val);
    }
    output = Core.immutablelist(output);
    return output;
  }

  public static <T, U> List<T> arraylist_from_arraylist_fn(final List<U> listval, final Function<U, T> fn_any_from_any) {
    List<T> output = new ArrayList<>();
    for (U value_u : listval) {
      T t_val = fn_any_from_any.apply(value_u);
      output.add(t_val);
    }
    output = Core.immutablelist(output);
    return output;
  }

  public static <T extends Core.Type_any, U extends Core.Type_any> List<T> arraylist_from_linkedhashmap(final T generic_any_1, final Map<String, U> mapval) {
    List<T> output = new ArrayList<T>();
    Set<String> keys = mapval.keySet();
    for (String key : keys) {
      U u_val = mapval.get(key);
      T t_val = Core.f_any_from_any(generic_any_1, u_val);
      output.add(t_val);
    }
    output = Core.immutablelist(output);
    return output;
  }

  public static <T, U> List<T> arraylist_from_linkedhashmap_fn(final Map<String, U> mapval, final BiFunction<String, U, T> fn_any_from_key_value) {
    List<T> output = new ArrayList<T>();
    Set<String> keys = mapval.keySet();
    for (String key : keys) {
      U u_val = mapval.get(key);
      T t_val = fn_any_from_key_value.apply(key, u_val);
      output.add(t_val);
    }
    return output;
  }

  public static <T> CompletableFuture<T> async_new_completed(final T val) {
    CompletableFuture<T> output = CompletableFuture.completedFuture(val);
    return output;
  }

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> async_from_async(T generic_any_1, final CompletableFuture<U> future) {
    CompletableFuture<T> output = future.thenApply(val -> {
      return Core.f_any_from_any(generic_any_1, val);
    });
    return output;
  }

  public static <T, U> CompletableFuture<T> async_from_async_fn(final CompletableFuture<U> future, final Function<? super U, ? extends T> fn) {
    CompletableFuture<T> output = future.thenApply(fn);
    return output;
  }

  public static <T> CompletableFuture<List<T>> async_arraylist_from_arraylist_async(final List<CompletableFuture<T>> list_future) {
    CompletableFuture<Void> allFutures = CompletableFuture.allOf(
      list_future.toArray(new CompletableFuture[list_future.size()])
    );
    CompletableFuture<List<T>> output = allFutures.thenApply(v -> {
      List<T> list = list_future.stream()
        .map(future -> future.join())
        .collect(Collectors.toList());
      return Core.immutablelist(list);
    });
    return output;
  }

  @SafeVarargs
  public static <T> LinkedHashMap<String, T> hashmap_from_keyvalues(final KeyValue<T>... keyvalues) {
    LinkedHashMap<String, T> output = new LinkedHashMap<String, T>();
    for (KeyValue<T> keyvalue : keyvalues) {
      String key = keyvalue.key;
      T value = keyvalue.value;
      output.put(key, value);
    }
    return output;
  }

  public static <T> KeyValue<T> keyvalue_from_key_value(final String key, final T value) {
    KeyValue<T> output = new KeyValue<T>();
    output.key = key;
    output.value = value;
    return output;
  }

  public static <T> Map<String, T> map_from_list_fn(final List<T> listval, final Function<T, Core.Type_string> fn_any_from_any) {
    Map<String, T> output = new LinkedHashMap<>();
    for (T val : listval) {
      Core.Type_string valkey = fn_any_from_any.apply(val);
      String key = valkey.vx_string();
      output.put(key, val);
    }
    return output;
  }

  public static <T extends Core.Type_any> LinkedHashMap<String, T> map_from_map(final LinkedHashMap<String, Core.Type_any> mapval) {
    LinkedHashMap<String, T> output = new LinkedHashMap<String, T>();
    Set<String> keys = mapval.keySet();
    for (String key : keys) {
      Core.Type_any value = mapval.get(key);
      try {
        @SuppressWarnings("unchecked")
        T castval = (T)value;
        output.put(key, castval);
      } catch (Exception ex) {
        Core.vx_log("map<-map", ex);
      }
    }
    return output;
  }

  // vx_boolean_from_string_ends(string, string)
  public static boolean vx_boolean_from_string_ends(String text, String ends) {
    return text.endsWith(ends);
  }

  // vx_boolean_from_string_find(string, string)
  public static boolean vx_boolean_from_string_find(String text, String find) {
    return text.contains(find);
  }

  // vx_boolean_from_string_starts(string, string)
  public static boolean vx_boolean_from_string_starts(String text, String starts) {
    return text.startsWith(starts);
  }

  // vx_eqeq(any, any)
  public static boolean vx_eqeq(Core.Type_any val1, Core.Type_any val2) {
    boolean output = false;
    if (val1 == val2) {
      output = true;
    } else if (val1.vx_msgblock() != Core.e_msgblock) {
    } else if (val2.vx_msgblock() != Core.e_msgblock) {
    } else {
      Core.Type_any type1 = val1.vx_type();
      Core.Type_any type2 = val2.vx_type();
      if (type1 != type2) {
      } else if (type1 == Core.t_int) {
        Core.Type_int valint1 = (Core.Type_int)val1;
        Core.Type_int valint2 = (Core.Type_int)val2;
        if (valint1.vx_int() == valint2.vx_int()) {
          output = true;
        }
      } else if (type1 == Core.t_float) {
        Core.Type_float valfloat1 = (Core.Type_float)val1;
        Core.Type_float valfloat2 = (Core.Type_float)val2;
        if (valfloat1.vx_float() == valfloat2.vx_float()) {
          output = true;
        }
      } else if (type1 == Core.t_decimal) {
        Core.Type_decimal valdecimal1 = (Core.Type_decimal)val1;
        Core.Type_decimal valdecimal2 = (Core.Type_decimal)val2;
        if (valdecimal1.vx_string() == valdecimal2.vx_string()) {
          output = true;
        }
      } else if (type1 == Core.t_string) {
        Core.Type_string valstring1 = (Core.Type_string)val1;
        Core.Type_string valstring2 = (Core.Type_string)val2;
        if (valstring1.vx_string() == valstring2.vx_string()) {
          output = true;
        }
      }
    }
    return output;
  }

  // vx_float_from_string(string)
  public static float vx_float_from_string(String text) {
    float output = 0;
    try {
      output = Float.parseFloat(text);
    } catch (Exception e) {
    }    
    return output;
  }

  // vx_global_package_set(string, map<any>, map<any>, map<func>)
  public static void vx_global_package_set(String pkgname, Map<String, Core.Type_any> maptype, Map<String, Core.Type_any> mapconst, Map<String, Core.Type_func> mapfunc) {
    Core.Class_typemap typemap = new Core.Class_typemap();
		  typemap.vx_p_map = Core.immutablemap(maptype);
	   Core.Class_constmap constmap = new Core.Class_constmap();
		  constmap.vx_p_map = Core.immutablemap(mapconst);
		  Core.Class_funcmap funcmap = new Core.Class_funcmap();
		  funcmap.vx_p_map = Core.immutablemap(mapfunc);
    Core.Class_project global = (Core.Class_project)Core.c_global;
    Core.Class_packagemap packagemap = (Core.Class_packagemap)global.vx_p_packagemap;
    if (packagemap == null) {
      packagemap = new Core.Class_packagemap();
      global.vx_p_packagemap = packagemap;
    }
    Map<String, Core.Type_package> mappackage = new LinkedHashMap<>(packagemap.vx_p_map);
		  Core.Class_package pkg = new Core.Class_package();
		  pkg.vx_p_constmap = constmap;
		  pkg.vx_p_typemap = typemap;
		  pkg.vx_p_funcmap = funcmap;
    mappackage.put(pkgname, pkg);
    packagemap.vx_p_map = Core.immutablemap(mappackage);
  }

  // vx_int_from_string(string)
  public static int vx_int_from_string(String text) {
    int output = 0;
    try {
      output = Integer.parseInt(text);
    } catch (Exception e) {
    }    
    return output;
  }

  // vx_int_from_string_find(string, string)
  public static int vx_int_from_string_find(String text, String find) {
    return text.indexOf(find);
  }

  // vx_int_from_string_findlast(string, string)
  public static int vx_int_from_string_findlast(String text, String findlast) {
    return text.lastIndexOf(findlast);
  }

  // vx_is_float(string)
  public static boolean vx_is_float(String text) {
    boolean output = false;
    try {
      Float.parseFloat(text);
      output = true;
    } catch (Exception e) {
    }    
    return output;
  }

  // vx_is_float(any)
  public static boolean vx_is_float(Core.Type_any value) {
    boolean output = false;
    if (value instanceof Core.Type_number) {
      output = true;
    } else if (value instanceof Core.Type_string) {
      Core.Type_string valuestring = (Core.Type_string)value;
      output = Core.vx_is_float(valuestring.vx_string());
    }
    return output;
  }

  // vx_is_int(string)
  public static boolean vx_is_int(String text) {
    boolean output = false;
    switch (text) {
    case "notanumber":
    case "infinity":
    case "neginfinity":
      output = true;
      break;
    default:
      try {
        Integer.parseInt(text);
        output = true;
      } catch (Exception e) {
      }
      break;
    }
    return output;
  }

  // vx_is_int(any)
  public static boolean vx_is_int(Core.Type_any value) {
    boolean result = false;
    if (value == Core.c_infinity) {
      result = true;
    } else if (value == Core.c_neginfinity) {
      result = true;
    } else if (value == Core.c_notanumber) {
      result = true;
    } else if (value instanceof Core.Type_int) {
      result = true;
    } else if (value instanceof Core.Type_float) {
      Core.Type_float valfloat = (Core.Type_float)value;
      float floatval = valfloat.vx_float();
      if ((int)floatval == floatval) {
        result = true;
      }
    } else if (value instanceof Core.Type_decimal) {
      Core.Type_decimal valdec = (Core.Type_decimal)value;
      String strval = valdec.vx_string();
      try {
        if (Integer.parseInt(strval) == Float.parseFloat(strval)) {
          result = true;
        }
      } catch (Exception ex) {
      }
    } else if (value instanceof Core.Type_string) {
      Core.Type_string valstr = (Core.Type_string)value;
      String strval = valstr.vx_string();
      result = vx_is_int(strval);
    }
    return result;
  }

  // vx_log(object...)
  public static void vx_log(Object... values) {
    for (Object value : values) {
      String text = "";
      if (value == null) {
        text = "null";
      } else if (value instanceof Core.Type_string) {
        Core.Type_string valstring = (Core.Type_string)value;
        text = valstring.vx_string();
      } else if (value instanceof Core.Type_any) {
        Core.Type_any valany = (Core.Type_any)value;
        Core.Type_string valstring = Core.f_string_from_any(valany);
        text = valstring.vx_string();
      } else {
        text = value.toString();
      }
      System.out.println(text);
    }
  }

  // vx_msg_error
  public static Type_msg vx_msg_error(final String text) {
    Class_msg output = new Class_msg();
    output.vx_p_text = Core.vx_new_string(text);
    output.vx_p_severity = Core.c_msg_severe;
    return output;
  }

  // vx_msg_from_exception
  public static Type_msg vx_msg_from_exception(final String text, final Exception err) {
    Class_msg output = new Class_msg();
    output.vx_p_text = Core.vx_new_string(text);
    output.vx_p_severity = Core.c_msg_severe;
    output.err = err;
    Core.vx_log(output);
    return output;
  }

  public static Type_boolean vx_new_boolean(final boolean isval) {
    Type_boolean output = Core.c_false;
    if (isval) {
      output = Core.c_true;
    }
    return output;
  }

  public static Type_float vx_new_float(final float fval) {
    Class_float output = new Core.Class_float();
    output.vxfloat = fval;
    return output;
  }

  public static Type_int vx_new_int(final int ival) {
    Type_int output;
    if ((ival == 0) && Core.e_int != null) {
      output = Core.e_int;
    } else {
      Class_int work = new Core.Class_int();
      work.vxint = ival;
      output = work;

    }
    return output;
  }

  public static Type_string vx_new_string(final String text) {
    Type_string output;
    if (text.equals("") && Core.e_string != null) {
      output = Core.e_string;
    } else {
      Class_string work = new Core.Class_string();
      work.vxstring = text;
      output = work;
    }
    return output;
  }

  public static String vx_string_from_any(Core.Type_any value) {
    return vx_string_from_any_indent(value, 0, false);
  }

  public static String vx_string_from_any_indent(Core.Type_any value, int indent, boolean linefeed) {
    String indenttext = " ".repeat(indent);
    String output = "";
    if (indent > 50) {
      output = "Error: Max Depth Exceeded";
    } else if (value == null) {
      output = "null";
    } else if (value == value.vx_type()) {
      if (value instanceof Core.Type_func) {
        Core.Type_func valuefunc = (Core.Type_func)value;
        Core.Type_funcdef funcdef = valuefunc.vx_funcdef();
        output = funcdef.pkgname().vx_string() + "/" + funcdef.name().vx_string();
      } else {
        Core.Type_typedef typedef = value.vx_typedef();
        output = typedef.pkgname().vx_string() + "/" + typedef.name().vx_string();
      }
    } else if (value instanceof Core.Type_boolean) {
      Core.Type_boolean valbool = Core.f_any_from_any(Core.t_boolean, value);
      if (valbool.vx_boolean() == true) {
        output = "true";
      } else {
        output = "false";
      }
    } else if (value instanceof Core.Type_decimal) {
      Core.Type_decimal valdec = Core.f_any_from_any(Core.t_decimal, value);
      output = valdec.vx_string();
    } else if (value instanceof Core.Type_float) {
      Core.Type_float valfloat = Core.f_any_from_any(Core.t_float, value);
      output = Float.toString(valfloat.vx_float());
      if (output.endsWith(".0")) {
        output = output.substring(0, output.length() - 2);
      }
    } else if (value instanceof Core.Type_int) {
      if (value == Core.c_notanumber) {
        output = "notanumber";
      } else if (value == Core.c_infinity) {
        output = "infinity";
      } else if (value == Core.c_neginfinity) {
        output = "neginfinity";
      } else {
        Core.Type_int valint = Core.f_any_from_any(Core.t_int, value);
        output = Integer.toString(valint.vx_int());
      }
    } else if (value instanceof Core.Type_string) {
      Core.Type_string valstring = Core.f_any_from_any(Core.t_string, value);
      output = "\"" + valstring.vx_string() + "\"";
    } else if (value instanceof Core.vx_Type_const) {
      Core.vx_Type_const constvalue = (Core.vx_Type_const)value;
      Core.Type_constdef constdef = constvalue.vx_constdef();
      String constpkg = constdef.pkgname().vx_string();
      String constname = constdef.name().vx_string();
      if (constpkg.equals("vx/core")) {
        output = constname;
      } else {
        output = constpkg + "/" + constname;
      }
    } else if (value instanceof Core.Type_list) {
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, value);
      Core.Type_typedef typedef = vallist.vx_typedef();
      Core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 1;
      List<Core.Type_any> listval = vallist.vx_list();
      for (Core.Type_any valsub : listval) {
        String valtext = Core.vx_string_from_any_indent(valsub, indentint, linefeed);
        output += "\n " + indenttext + valtext;
      }
      if (vallist.vx_msgblock() != null) {
        String msgtext = Core.vx_string_from_any_indent(vallist.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value instanceof Core.Type_map) {
      Core.Type_map valmap = Core.f_any_from_any(Core.t_map, value);
      Core.Type_typedef typedef = valmap.vx_typedef();
      Core.Type_string typedefname = typedef.name();
      int indentint = indent;
      indentint += 2;
      Map<String, Core.Type_any> mapval = valmap.vx_map();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any valsub = mapval.get(key);
        if (!key.startsWith(":")) {
          key = ":" + key;
        }
        String strval = Core.vx_string_from_any_indent(valsub, indentint, linefeed);
        if (strval.contains("\n")) {
          strval = "\n  " + indenttext + strval;
        } else {
          strval = " " + strval;
        }
        output += "\n" + indenttext + " " + key + strval;
      }
      if (valmap.vx_msgblock() != null) {
        String msgtext = Core.vx_string_from_any_indent(valmap.vx_msgblock(), indentint, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value instanceof Core.Type_struct) {
      Core.Type_struct valstruct = Core.f_any_from_any(Core.t_struct, value);
      Core.Type_typedef typedef = valstruct.vx_typedef();
      Core.Type_string typedefname = typedef.name();
      int indentint2 = indent;
      indentint2 += 2;
      Map<String, Core.Type_any> mapval2 = valstruct.vx_map();
      Set<String> keys2 = mapval2.keySet();
      for (String key : keys2) {
        Core.Type_any valsub2 = mapval2.get(key);
        if (!Core.f_is_empty_1(valsub2).vx_boolean()) {
          if (!key.startsWith(":")) {
            key = ":" + key;
          }
          String strval2 = Core.vx_string_from_any_indent(valsub2, indentint2, linefeed);
          if (strval2.contains("\n")) {
            strval2 = "\n  " + indenttext + strval2;
          } else {
            strval2 = " " + strval2;
          }
          output += "\n" + indenttext + " " + key + strval2;
        }
      }
      if (valstruct.vx_msgblock() != null) {
        String msgtext2 = Core.vx_string_from_any_indent(valstruct.vx_msgblock(), indentint2, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext2;
      }
      output = "(" + typedefname.vx_string() + output + ")";
    } else if (value instanceof Core.Type_func) {
      Core.Type_func valfunc = Core.f_any_from_any(Core.t_func, value);
      Core.Type_funcdef funcdef = valfunc.vx_funcdef();
      Core.Type_string funcdefname = Core.f_funcname_from_funcdef(funcdef);
      output = funcdefname.vx_string();
      if (valfunc.vx_msgblock() != null) {
        String msgtext = Core.vx_string_from_any_indent(valfunc.vx_msgblock(), indent, linefeed);
        output += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
      }
      output = "(" + output + ")";
    }
    return output;
  }

  public static String vx_string_from_string_start_end(String text, int start, int end) {
    String output = "";
    int maxlen = text.length();
    if (end < 0) {
     end += maxlen;
    }
    if (start < 1) {
    } else if (start > end) {
    } else if (start > maxlen) {
    } else {
      if (end >= maxlen) {
        end = maxlen;
      }
      output = text.substring(start - 1, end);
    }
    return output;
  }

  public static Core.Type_typedef typedef_new(
    String pkgname,
    String name,
    String extend,
    Core.Type_typelist traits,
    Core.Type_typelist allowtypes,
    Core.Type_typelist disallowtypes,
    Core.Type_funclist allowfuncs,
    Core.Type_funclist disallowfuncs,
    Core.Type_anylist allowvalues,
    Core.Type_anylist disallowvalues,
    Core.Type_argmap properties
  ) {
    Core.Class_typedef output = new Core.Class_typedef();
    output.vx_p_pkgname = Core.vx_new_string(pkgname);
    output.vx_p_name = Core.vx_new_string(name);
    output.vx_p_extend = Core.vx_new_string(extend);
    output.vx_p_traits = traits;
    output.vx_p_allowtypes = allowtypes;
    output.vx_p_disallowtypes = disallowtypes;
    output.vx_p_allowfuncs = disallowfuncs;
    output.vx_p_disallowfuncs = disallowfuncs;
    output.vx_p_allowvalues = disallowvalues;
    output.vx_p_disallowvalues = disallowvalues;
    output.vx_p_properties = properties;
    return output;
  }

  public static Core.Type_anylist vx_anylist_from_arraystring(String[] arraystring) {
    List<Object> listany = new ArrayList<>();
    for (String svalue : arraystring) {
      Core.Type_string value = Core.vx_new_string(svalue);
      listany.add(value);
    }
    Object[] arrayany = listany.toArray();
    Core.Type_anylist output = Core.t_anylist.vx_new(arrayany);
    return output;
  }

  // Warning!: Blocking
  public static <T extends Core.Type_any> T vx_sync_from_async(final T generic_any_1, final CompletableFuture<T> future) {
    T output = Core.f_empty(generic_any_1);
    try {
      output = future.get();
    } catch (Exception e) {
      Core.Type_msg msg = Core.vx_msg_from_exception("sync<-async", e);
      Core.Type_any val = generic_any_1.vx_new(msg);
      output = Core.f_any_from_any(generic_any_1, val);
    }
    return output;
  }

  /**
   * type: any
   * Any Value for Variant Type
   * (type any)
   */
  public interface Type_any {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_typedef vx_typedef();
    public List<Type_any> vx_dispose();
    public Core.Type_msgblock vx_msgblock();
    public boolean vx_release();
    public void vx_reserve();
  }

  public static class Class_any extends Core.Class_base implements Type_any {

    @Override
    public Type_any vx_new(final Object... vals) {return e_any.vx_copy(vals);}

    @Override
    public Type_any vx_copy(final Object... vals) {
      Type_any output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_msgblock msgblock = Core.e_msgblock;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        }
      }
      if (msgblock != Core.e_msgblock) {
        Class_any work = new Class_any();
        work.vxmsgblock = msgblock;
        output = work;
      }
      return output;
    }

    @Override
    public Type_any vx_empty() {return e_any;}
    @Override
    public Type_any vx_type() {return t_any;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
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

  public static final Type_any e_any = new Class_any();
  public static final Type_any t_any = new Class_any();

  /**
   * type: any-async<-func
   * A sync or async function that returns one value.
   * (type any-async<-func)
   */
  public interface Type_any_async_from_func extends Core.Type_any {
    public Core.Type_any_async_from_func vx_new(final Object... vals);
    public Core.Type_any_async_from_func vx_copy(final Object... vals);
    public Core.Type_any_async_from_func vx_empty();
    public Core.Type_any_async_from_func vx_type();
  }

  public static class Class_any_async_from_func extends Core.Class_base implements Type_any_async_from_func {

    @Override
    public Type_any_async_from_func vx_new(final Object... vals) {return e_any_async_from_func.vx_copy(vals);}

    @Override
    public Type_any_async_from_func vx_copy(final Object... vals) {
      Type_any_async_from_func output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_any_async_from_func vx_empty() {return e_any_async_from_func;}
    @Override
    public Type_any_async_from_func vx_type() {return t_any_async_from_func;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "any-async<-func", // name
        ":func", // extends
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

  public static final Type_any_async_from_func e_any_async_from_func = new Class_any_async_from_func();
  public static final Type_any_async_from_func t_any_async_from_func = new Class_any_async_from_func();

  /**
   * type: any<-anylist
   * List of any<-any
   * (type any<-anylist)
   */
  public interface Type_any_from_anylist extends Core.Type_list {
    public Core.Type_any_from_anylist vx_new(final Object... vals);
    public Core.Type_any_from_anylist vx_copy(final Object... vals);
    public Core.Type_any_from_anylist vx_empty();
    public Core.Type_any_from_anylist vx_type();
    public List<Core.Func_any_from_any> vx_listany_from_any();
    public Core.Func_any_from_any vx_any_from_any(final Core.Type_int index);
  }

  public static class Class_any_from_anylist extends Core.Class_base implements Type_any_from_anylist {

    protected List<Core.Func_any_from_any> vx_p_list = Core.immutablelist(new ArrayList<Core.Func_any_from_any>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Func_any_from_any vx_any_from_any(final Core.Type_int index) {
      Core.Func_any_from_any output = Core.e_any_from_any;
      Class_any_from_anylist list = this;
      int iindex = index.vx_int();
      List<Core.Func_any_from_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Func_any_from_any> vx_listany_from_any() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_any_from_any(index);
    }

    @Override
    public Type_any_from_anylist vx_new(final Object... vals) {return e_any_from_anylist.vx_copy(vals);}

    @Override
    public Type_any_from_anylist vx_copy(final Object... vals) {
      Type_any_from_anylist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_any_from_anylist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Func_any_from_any> listval = new ArrayList<>(val.vx_listany_from_any());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Func_any_from_any) {
          ischanged = true;
          listval.add((Core.Func_any_from_any)valsub);
        } else if (valsub instanceof Type_any_from_anylist) {
          Type_any_from_anylist multi = (Type_any_from_anylist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listany_from_any());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Func_any_from_any) {
              Core.Func_any_from_any valitem = (Core.Func_any_from_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new any<-anylist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_any_from_anylist work = new Class_any_from_anylist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_any_from_anylist vx_empty() {return e_any_from_anylist;}
    @Override
    public Type_any_from_anylist vx_type() {return t_any_from_anylist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "any<-anylist", // name
        ":list", // extends
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

  public static final Type_any_from_anylist e_any_from_anylist = new Class_any_from_anylist();
  public static final Type_any_from_anylist t_any_from_anylist = new Class_any_from_anylist();

  /**
   * type: anylist
   * (type anylist)
   */
  public interface Type_anylist extends Core.Type_list {
    public Core.Type_anylist vx_new(final Object... vals);
    public Core.Type_anylist vx_copy(final Object... vals);
    public Core.Type_anylist vx_empty();
    public Core.Type_anylist vx_type();
  }

  public static class Class_anylist extends Core.Class_base implements Type_anylist {

    protected List<Core.Type_any> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_any>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_any output = Core.e_any;
      Class_anylist list = this;
      int iindex = index.vx_int();
      List<Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public Type_anylist vx_new(final Object... vals) {return e_anylist.vx_copy(vals);}

    @Override
    public Type_anylist vx_copy(final Object... vals) {
      Type_anylist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_anylist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_any> listval = new ArrayList<>(val.vx_list());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Type_anylist) {
          Type_anylist multi = (Type_anylist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_any) {
              Core.Type_any valitem = (Core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new anylist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_anylist work = new Class_anylist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_anylist vx_empty() {return e_anylist;}
    @Override
    public Type_anylist vx_type() {return t_anylist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "anylist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_anylist e_anylist = new Class_anylist();
  public static final Type_anylist t_anylist = new Class_anylist();

  /**
   * type: anytype
   * Any Type that allows any Type as a Value
   * (type anytype)
   */
  public interface Type_anytype extends Core.Type_any {
    public Core.Type_anytype vx_new(final Object... vals);
    public Core.Type_anytype vx_copy(final Object... vals);
    public Core.Type_anytype vx_empty();
    public Core.Type_anytype vx_type();
  }

  public static class Class_anytype extends Core.Class_base implements Type_anytype {

    @Override
    public Type_anytype vx_new(final Object... vals) {return e_anytype.vx_copy(vals);}

    @Override
    public Type_anytype vx_copy(final Object... vals) {
      Type_anytype output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_anytype vx_empty() {return e_anytype;}
    @Override
    public Type_anytype vx_type() {return t_anytype;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "anytype", // name
        ":type", // extends
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

  public static final Type_anytype e_anytype = new Class_anytype();
  public static final Type_anytype t_anytype = new Class_anytype();

  /**
   * type: arg
   * A function argument
   * (type arg)
   */
  public interface Type_arg extends Core.Type_struct {
    public Core.Type_arg vx_new(final Object... vals);
    public Core.Type_arg vx_copy(final Object... vals);
    public Core.Type_arg vx_empty();
    public Core.Type_arg vx_type();
    public Core.Type_string name();
    public Core.Type_type argtype();
    public Core.Func_any_from_func fn_any();
  }

  public static class Class_arg extends Core.Class_base implements Type_arg {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_type vx_p_argtype;

    @Override
    public Core.Type_type argtype() {
      return this.vx_p_argtype == null ? Core.e_type : this.vx_p_argtype;
    }

    protected Core.Func_any_from_func vx_p_fn_any;

    @Override
    public Core.Func_any_from_func fn_any() {
      return this.vx_p_fn_any == null ? Core.e_any_from_func : this.vx_p_fn_any;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":argtype":
        output = this.argtype();
        break;
      case ":fn-any":
        output = this.fn_any();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":argtype", this.argtype());
      output.put(":fn-any", this.fn_any());
      return Core.immutablemap(output);
    }

    @Override
    public Type_arg vx_new(final Object... vals) {return e_arg.vx_copy(vals);}

    @Override
    public Type_arg vx_copy(final Object... vals) {
      Type_arg output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_arg val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_name = val.name();
      Core.Type_type vx_p_argtype = val.argtype();
      Core.Func_any_from_func vx_p_fn_any = val.fn_any();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":argtype");
      validkeys.add(":fn-any");
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
            Core.Type_msg msg = Core.vx_msg_error("(new arg) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
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
              Core.Type_msg msg = Core.vx_msg_error("(new arg :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":argtype":
            if (valsub == vx_p_argtype) {
            } else if (valsub instanceof Core.Type_type) {
              ischanged = true;
              vx_p_argtype = (Core.Type_type)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new arg :argtype " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub instanceof Core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (Core.Func_any_from_func)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new arg :fn-any " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new arg) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_arg work = new Class_arg();
        work.vx_p_name = vx_p_name;
        work.vx_p_argtype = vx_p_argtype;
        work.vx_p_fn_any = vx_p_fn_any;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_arg vx_empty() {return e_arg;}
    @Override
    public Type_arg vx_type() {return t_arg;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "arg", // name
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

  public static final Type_arg e_arg = new Class_arg();
  public static final Type_arg t_arg = new Class_arg();

  /**
   * type: arglist
   * A list of arg
   * (type arglist)
   */
  public interface Type_arglist extends Core.Type_list {
    public Core.Type_arglist vx_new(final Object... vals);
    public Core.Type_arglist vx_copy(final Object... vals);
    public Core.Type_arglist vx_empty();
    public Core.Type_arglist vx_type();
    public List<Core.Type_arg> vx_listarg();
    public Core.Type_arg vx_arg(final Core.Type_int index);
  }

  public static class Class_arglist extends Core.Class_base implements Type_arglist {

    protected List<Core.Type_arg> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_arg>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_arg vx_arg(final Core.Type_int index) {
      Core.Type_arg output = Core.e_arg;
      Class_arglist list = this;
      int iindex = index.vx_int();
      List<Core.Type_arg> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_arg> vx_listarg() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_arg(index);
    }

    @Override
    public Type_arglist vx_new(final Object... vals) {return e_arglist.vx_copy(vals);}

    @Override
    public Type_arglist vx_copy(final Object... vals) {
      Type_arglist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_arglist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_arg> listval = new ArrayList<>(val.vx_listarg());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_arg) {
          ischanged = true;
          listval.add((Core.Type_arg)valsub);
        } else if (valsub instanceof Core.Type_arg) {
          ischanged = true;
          listval.add((Core.Type_arg)valsub);
        } else if (valsub instanceof Type_arglist) {
          Type_arglist multi = (Type_arglist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listarg());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_arg) {
              Core.Type_arg valitem = (Core.Type_arg)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new arglist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_arglist work = new Class_arglist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_arglist vx_empty() {return e_arglist;}
    @Override
    public Type_arglist vx_type() {return t_arglist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "arglist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_arg), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_arglist e_arglist = new Class_arglist();
  public static final Type_arglist t_arglist = new Class_arglist();

  /**
   * type: argmap
   * A map of arg
   * (type argmap)
   */
  public interface Type_argmap extends Core.Type_map {
    public Core.Type_argmap vx_new(final Object... vals);
    public Core.Type_argmap vx_copy(final Object... vals);
    public Core.Type_argmap vx_empty();
    public Core.Type_argmap vx_type();
    public Map<String, Core.Type_arg> vx_maparg();
    public Core.Type_arg vx_arg(final Core.Type_string key);
  }

  public static class Class_argmap extends Core.Class_base implements Type_argmap {

    protected Map<String, Core.Type_arg> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_arg>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_arg vx_arg(final Core.Type_string key) {
      Core.Type_arg output = Core.e_arg;
      Class_argmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_arg> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_arg);
      return output;
    }

    @Override
    public Map<String, Core.Type_arg> vx_maparg() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_arg(key);
    }

    @Override
    public Type_argmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_argmap output = new Class_argmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_arg> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_arg) {
          Core.Type_arg castval = (Core.Type_arg)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(argmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_argmap vx_new(final Object... vals) {return e_argmap.vx_copy(vals);}

    @Override
    public Type_argmap vx_copy(final Object... vals) {
      Type_argmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_argmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_arg> mapval = new LinkedHashMap<>(valmap.vx_maparg());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_arg valany = null;
          if (valsub instanceof Core.Type_arg) {
            valany = (Core.Type_arg)valsub;
          } else if (valsub instanceof Core.Type_arg) {
            valany = (Core.Type_arg)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_argmap work = new Class_argmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_argmap vx_empty() {return e_argmap;}
    @Override
    public Type_argmap vx_type() {return t_argmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_arg), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_argmap e_argmap = new Class_argmap();
  public static final Type_argmap t_argmap = new Class_argmap();

  /**
   * type: boolean
   * Standard Boolean Type
   * (type boolean)
   */
  public interface Type_boolean extends Core.Type_any {
    public Core.Type_boolean vx_new(final Object... vals);
    public Core.Type_boolean vx_copy(final Object... vals);
    public Core.Type_boolean vx_empty();
    public Core.Type_boolean vx_type();
    public boolean vx_boolean();
  }

  public static class Class_boolean extends Core.Class_base implements Type_boolean {

    protected boolean vxboolean = false;
    
    @Override
    public boolean vx_boolean() {return vxboolean;}

    @Override
    public Type_boolean vx_new(final Object... vals) {return e_boolean.vx_copy(vals);}

    @Override
    public Type_boolean vx_copy(final Object... vals) {
      Type_boolean output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_boolean val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      boolean booleanval = val.vx_boolean();
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_boolean) {
          Core.Type_boolean valboolean = (Core.Type_boolean)valsub;
          booleanval = booleanval || valboolean.vx_boolean();
        } else if (valsub instanceof Boolean) {
          booleanval = booleanval || (Boolean)valsub;
        }
      }
      if (msgblock != Core.e_msgblock) {
        Class_boolean work = new Class_boolean();
        work.vxboolean = booleanval;
        work.vxmsgblock = msgblock;
        output = work;
      } else if (booleanval) {
        output = Core.c_true;
      } else {
        output = Core.c_false;
      }
      return output;
    }

    @Override
    public Type_boolean vx_empty() {return e_boolean;}
    @Override
    public Type_boolean vx_type() {return t_boolean;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
      );
    }

  }

  public static final Type_boolean e_boolean = new Class_boolean();
  public static final Type_boolean t_boolean = new Class_boolean();

  /**
   * type: booleanlist
   * (type booleanlist)
   */
  public interface Type_booleanlist extends Core.Type_list {
    public Core.Type_booleanlist vx_new(final Object... vals);
    public Core.Type_booleanlist vx_copy(final Object... vals);
    public Core.Type_booleanlist vx_empty();
    public Core.Type_booleanlist vx_type();
    public List<Core.Type_boolean> vx_listboolean();
    public Core.Type_boolean vx_boolean(final Core.Type_int index);
  }

  public static class Class_booleanlist extends Core.Class_base implements Type_booleanlist {

    protected List<Core.Type_boolean> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_boolean>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_boolean vx_boolean(final Core.Type_int index) {
      Core.Type_boolean output = Core.e_boolean;
      Class_booleanlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_boolean> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_boolean> vx_listboolean() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_boolean(index);
    }

    @Override
    public Type_booleanlist vx_new(final Object... vals) {return e_booleanlist.vx_copy(vals);}

    @Override
    public Type_booleanlist vx_copy(final Object... vals) {
      Type_booleanlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_booleanlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_boolean> listval = new ArrayList<>(val.vx_listboolean());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_boolean) {
          ischanged = true;
          listval.add((Core.Type_boolean)valsub);
        } else if (valsub instanceof Boolean) {
          ischanged = true;
          listval.add(Core.t_boolean.vx_new(valsub));
        } else if (valsub instanceof Type_booleanlist) {
          Type_booleanlist multi = (Type_booleanlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listboolean());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_boolean) {
              Core.Type_boolean valitem = (Core.Type_boolean)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new booleanlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_booleanlist work = new Class_booleanlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_booleanlist vx_empty() {return e_booleanlist;}
    @Override
    public Type_booleanlist vx_type() {return t_booleanlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "booleanlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_boolean), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_booleanlist e_booleanlist = new Class_booleanlist();
  public static final Type_booleanlist t_booleanlist = new Class_booleanlist();

  /**
   * type: collection
   * (type collection)
   */
  public interface Type_collection extends Core.Type_any {
    public Core.Type_collection vx_new(final Object... vals);
    public Core.Type_collection vx_copy(final Object... vals);
    public Core.Type_collection vx_empty();
    public Core.Type_collection vx_type();
  }

  public static class Class_collection extends Core.Class_base implements Type_collection {

    @Override
    public Type_collection vx_new(final Object... vals) {return e_collection.vx_copy(vals);}

    @Override
    public Type_collection vx_copy(final Object... vals) {
      Type_collection output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_collection vx_empty() {return e_collection;}
    @Override
    public Type_collection vx_type() {return t_collection;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "collection", // name
        "", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_list, Core.t_map), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_collection e_collection = new Class_collection();
  public static final Type_collection t_collection = new Class_collection();

  /**
   * type: compilelanguages
   * (type compilelanguages)
   */
  public interface Type_compilelanguages extends Core.Type_any {
    public Core.Type_compilelanguages vx_new(final Object... vals);
    public Core.Type_compilelanguages vx_copy(final Object... vals);
    public Core.Type_compilelanguages vx_empty();
    public Core.Type_compilelanguages vx_type();
  }

  public static class Class_compilelanguages extends Core.Class_base implements Type_compilelanguages {

    @Override
    public Type_compilelanguages vx_new(final Object... vals) {return e_compilelanguages.vx_copy(vals);}

    @Override
    public Type_compilelanguages vx_copy(final Object... vals) {
      Type_compilelanguages output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_compilelanguages vx_empty() {return e_compilelanguages;}
    @Override
    public Type_compilelanguages vx_type() {return t_compilelanguages;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "compilelanguages", // name
        "", // extends
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

  public static final Type_compilelanguages e_compilelanguages = new Class_compilelanguages();
  public static final Type_compilelanguages t_compilelanguages = new Class_compilelanguages();

  /**
   * type: connect
   * General connect trait
   * (type connect)
   */
  public interface Type_connect extends Core.Type_any {
    public Core.Type_connect vx_new(final Object... vals);
    public Core.Type_connect vx_copy(final Object... vals);
    public Core.Type_connect vx_empty();
    public Core.Type_connect vx_type();
  }

  public static class Class_connect extends Core.Class_base implements Type_connect {

    @Override
    public Type_connect vx_new(final Object... vals) {return e_connect.vx_copy(vals);}

    @Override
    public Type_connect vx_copy(final Object... vals) {
      Type_connect output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_connect vx_empty() {return e_connect;}
    @Override
    public Type_connect vx_type() {return t_connect;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "connect", // name
        "", // extends
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

  public static final Type_connect e_connect = new Class_connect();
  public static final Type_connect t_connect = new Class_connect();

  /**
   * type: connectlist
   * List of connect
   * (type connectlist)
   */
  public interface Type_connectlist extends Core.Type_list {
    public Core.Type_connectlist vx_new(final Object... vals);
    public Core.Type_connectlist vx_copy(final Object... vals);
    public Core.Type_connectlist vx_empty();
    public Core.Type_connectlist vx_type();
    public List<Core.Type_connect> vx_listconnect();
    public Core.Type_connect vx_connect(final Core.Type_int index);
  }

  public static class Class_connectlist extends Core.Class_base implements Type_connectlist {

    protected List<Core.Type_connect> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_connect>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_connect vx_connect(final Core.Type_int index) {
      Core.Type_connect output = Core.e_connect;
      Class_connectlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_connect> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_connect> vx_listconnect() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_connect(index);
    }

    @Override
    public Type_connectlist vx_new(final Object... vals) {return e_connectlist.vx_copy(vals);}

    @Override
    public Type_connectlist vx_copy(final Object... vals) {
      Type_connectlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_connectlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_connect> listval = new ArrayList<>(val.vx_listconnect());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_connect) {
          ischanged = true;
          listval.add((Core.Type_connect)valsub);
        } else if (valsub instanceof Core.Type_connect) {
          ischanged = true;
          listval.add((Core.Type_connect)valsub);
        } else if (valsub instanceof Type_connectlist) {
          Type_connectlist multi = (Type_connectlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listconnect());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_connect) {
              Core.Type_connect valitem = (Core.Type_connect)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new connectlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_connectlist work = new Class_connectlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_connectlist vx_empty() {return e_connectlist;}
    @Override
    public Type_connectlist vx_type() {return t_connectlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "connectlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_connect), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_connectlist e_connectlist = new Class_connectlist();
  public static final Type_connectlist t_connectlist = new Class_connectlist();

  /**
   * type: connectmap
   * Map of connect
   * (type connectmap)
   */
  public interface Type_connectmap extends Core.Type_map {
    public Core.Type_connectmap vx_new(final Object... vals);
    public Core.Type_connectmap vx_copy(final Object... vals);
    public Core.Type_connectmap vx_empty();
    public Core.Type_connectmap vx_type();
    public Map<String, Core.Type_connect> vx_mapconnect();
    public Core.Type_connect vx_connect(final Core.Type_string key);
  }

  public static class Class_connectmap extends Core.Class_base implements Type_connectmap {

    protected Map<String, Core.Type_connect> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_connect>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_connect vx_connect(final Core.Type_string key) {
      Core.Type_connect output = Core.e_connect;
      Class_connectmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_connect> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_connect);
      return output;
    }

    @Override
    public Map<String, Core.Type_connect> vx_mapconnect() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_connect(key);
    }

    @Override
    public Type_connectmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_connectmap output = new Class_connectmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_connect> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_connect) {
          Core.Type_connect castval = (Core.Type_connect)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(connectmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_connectmap vx_new(final Object... vals) {return e_connectmap.vx_copy(vals);}

    @Override
    public Type_connectmap vx_copy(final Object... vals) {
      Type_connectmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_connectmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_connect> mapval = new LinkedHashMap<>(valmap.vx_mapconnect());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_connect valany = null;
          if (valsub instanceof Core.Type_connect) {
            valany = (Core.Type_connect)valsub;
          } else if (valsub instanceof Core.Type_connect) {
            valany = (Core.Type_connect)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_connectmap work = new Class_connectmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_connectmap vx_empty() {return e_connectmap;}
    @Override
    public Type_connectmap vx_type() {return t_connectmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "connectmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_connect), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_connectmap e_connectmap = new Class_connectmap();
  public static final Type_connectmap t_connectmap = new Class_connectmap();

  /**
   * type: const
   * Original Constant Class.
   * (type const)
   */
  public interface Type_const extends Core.Type_any {
    public Core.Type_const vx_new(final Object... vals);
    public Core.Type_const vx_copy(final Object... vals);
    public Core.Type_const vx_empty();
    public Core.Type_const vx_type();
  }

  public static class Class_const extends Core.Class_base implements Type_const {

    @Override
    public Type_const vx_new(final Object... vals) {return e_const.vx_copy(vals);}

    @Override
    public Type_const vx_copy(final Object... vals) {
      Type_const output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_const vx_empty() {return e_const;}
    @Override
    public Type_const vx_type() {return t_const;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "const", // name
        ":const", // extends
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

  public static final Type_const e_const = new Class_const();
  public static final Type_const t_const = new Class_const();

  /**
   * type: constdef
   * Const Definition Class for inspecting properties.
   * (type constdef)
   */
  public interface Type_constdef extends Core.Type_struct {
    public Core.Type_constdef vx_new(final Object... vals);
    public Core.Type_constdef vx_copy(final Object... vals);
    public Core.Type_constdef vx_empty();
    public Core.Type_constdef vx_type();
    public Core.Type_string pkgname();
    public Core.Type_string name();
    public Core.Type_any type();
  }

  public static class Class_constdef extends Core.Class_base implements Type_constdef {

    protected Core.Type_string vx_p_pkgname;

    @Override
    public Core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? Core.e_string : this.vx_p_pkgname;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_any vx_p_type;

    @Override
    public Core.Type_any type() {
      return this.vx_p_type == null ? Core.e_any : this.vx_p_type;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pkgname":
        output = this.pkgname();
        break;
      case ":name":
        output = this.name();
        break;
      case ":type":
        output = this.type();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":type", this.type());
      return Core.immutablemap(output);
    }

    @Override
    public Type_constdef vx_new(final Object... vals) {return e_constdef.vx_copy(vals);}

    @Override
    public Type_constdef vx_copy(final Object... vals) {
      Type_constdef output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_constdef val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_pkgname = val.pkgname();
      Core.Type_string vx_p_name = val.name();
      Core.Type_any vx_p_type = val.type();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":name");
      validkeys.add(":type");
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
            Core.Type_msg msg = Core.vx_msg_error("(new constdef) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_pkgname = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new constdef :pkgname " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new constdef :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_type = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new constdef :type " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new constdef) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_constdef work = new Class_constdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_constdef vx_empty() {return e_constdef;}
    @Override
    public Type_constdef vx_type() {return t_constdef;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "constdef", // name
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

  public static final Type_constdef e_constdef = new Class_constdef();
  public static final Type_constdef t_constdef = new Class_constdef();

  /**
   * type: constlist
   * List of Const.
   * (type constlist)
   */
  public interface Type_constlist extends Core.Type_list {
    public Core.Type_constlist vx_new(final Object... vals);
    public Core.Type_constlist vx_copy(final Object... vals);
    public Core.Type_constlist vx_empty();
    public Core.Type_constlist vx_type();
  }

  public static class Class_constlist extends Core.Class_base implements Type_constlist {

    protected List<Core.Type_any> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_any>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_any output = Core.e_any;
      Class_constlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public Type_constlist vx_new(final Object... vals) {return e_constlist.vx_copy(vals);}

    @Override
    public Type_constlist vx_copy(final Object... vals) {
      Type_constlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_constlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_any> listval = new ArrayList<>(val.vx_list());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Type_constlist) {
          Type_constlist multi = (Type_constlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_any) {
              Core.Type_any valitem = (Core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new constlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_constlist work = new Class_constlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_constlist vx_empty() {return e_constlist;}
    @Override
    public Type_constlist vx_type() {return t_constlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "constlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_constlist e_constlist = new Class_constlist();
  public static final Type_constlist t_constlist = new Class_constlist();

  /**
   * type: constmap
   * Map of Const.
   * (type constmap)
   */
  public interface Type_constmap extends Core.Type_map {
    public Core.Type_constmap vx_new(final Object... vals);
    public Core.Type_constmap vx_copy(final Object... vals);
    public Core.Type_constmap vx_empty();
    public Core.Type_constmap vx_type();
  }

  public static class Class_constmap extends Core.Class_base implements Type_constmap {

    protected Map<String, Core.Type_any> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      Class_constmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_any);
      return output;
    }

    @Override
    public Type_constmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_constmap output = new Class_constmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_any) {
          Core.Type_any castval = (Core.Type_any)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(constmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_constmap vx_new(final Object... vals) {return e_constmap.vx_copy(vals);}

    @Override
    public Type_constmap vx_copy(final Object... vals) {
      Type_constmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_constmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_any> mapval = new LinkedHashMap<>(valmap.vx_map());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_any valany = null;
          if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_constmap work = new Class_constmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_constmap vx_empty() {return e_constmap;}
    @Override
    public Type_constmap vx_type() {return t_constmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "constmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_constmap e_constmap = new Class_constmap();
  public static final Type_constmap t_constmap = new Class_constmap();

  /**
   * type: context
   * Context
   * (type context)
   */
  public interface Type_context extends Core.Type_struct {
    public Core.Type_context vx_new(final Object... vals);
    public Core.Type_context vx_copy(final Object... vals);
    public Core.Type_context vx_empty();
    public Core.Type_context vx_type();
    public Core.Type_string code();
    public Core.Type_session session();
    public Core.Type_setting setting();
    public Core.Type_state state();
  }

  public static class Class_context extends Core.Class_base implements Type_context {

    protected Core.Type_string vx_p_code;

    @Override
    public Core.Type_string code() {
      return this.vx_p_code == null ? Core.e_string : this.vx_p_code;
    }

    protected Core.Type_session vx_p_session;

    @Override
    public Core.Type_session session() {
      return this.vx_p_session == null ? Core.e_session : this.vx_p_session;
    }

    protected Core.Type_setting vx_p_setting;

    @Override
    public Core.Type_setting setting() {
      return this.vx_p_setting == null ? Core.e_setting : this.vx_p_setting;
    }

    protected Core.Type_state vx_p_state;

    @Override
    public Core.Type_state state() {
      return this.vx_p_state == null ? Core.e_state : this.vx_p_state;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":code":
        output = this.code();
        break;
      case ":session":
        output = this.session();
        break;
      case ":setting":
        output = this.setting();
        break;
      case ":state":
        output = this.state();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":session", this.session());
      output.put(":setting", this.setting());
      output.put(":state", this.state());
      return Core.immutablemap(output);
    }

    @Override
    public Type_context vx_new(final Object... vals) {return e_context.vx_copy(vals);}

    @Override
    public Type_context vx_copy(final Object... vals) {
      Type_context output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_context val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_code = val.code();
      Core.Type_session vx_p_session = val.session();
      Core.Type_setting vx_p_setting = val.setting();
      Core.Type_state vx_p_state = val.state();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":session");
      validkeys.add(":setting");
      validkeys.add(":state");
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
            Core.Type_msg msg = Core.vx_msg_error("(new context) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_code = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_code = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new context :code " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":session":
            if (valsub == vx_p_session) {
            } else if (valsub instanceof Core.Type_session) {
              ischanged = true;
              vx_p_session = (Core.Type_session)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new context :session " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":setting":
            if (valsub == vx_p_setting) {
            } else if (valsub instanceof Core.Type_setting) {
              ischanged = true;
              vx_p_setting = (Core.Type_setting)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new context :setting " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":state":
            if (valsub == vx_p_state) {
            } else if (valsub instanceof Core.Type_state) {
              ischanged = true;
              vx_p_state = (Core.Type_state)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new context :state " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new context) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_context work = new Class_context();
        work.vx_p_code = vx_p_code;
        work.vx_p_session = vx_p_session;
        work.vx_p_setting = vx_p_setting;
        work.vx_p_state = vx_p_state;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_context vx_empty() {return e_context;}
    @Override
    public Type_context vx_type() {return t_context;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "context", // name
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

  public static final Type_context e_context = new Class_context();
  public static final Type_context t_context = new Class_context();

  /**
   * type: decimal
   * A clean version of float like Java BigDecimal.
   * (type decimal)
   */
  public interface Type_decimal extends Core.Type_number {
    public Core.Type_decimal vx_new(final Object... vals);
    public Core.Type_decimal vx_copy(final Object... vals);
    public Core.Type_decimal vx_empty();
    public Core.Type_decimal vx_type();
    public float vx_float();
    public String vx_string();
    public Type_decimal vx_new_from_string(final String sval);
  }

  public static class Class_decimal extends Core.Class_base implements Type_decimal {

    protected String vxdecimal = "0.0";
    
    @Override
    public float vx_float() {
      return Float.parseFloat(vxdecimal);
    }
    
    @Override
    public String vx_string() {return vxdecimal;}
    
    @Override
    public Type_decimal vx_new_from_string(final String sval) {
      Class_decimal output = new Class_decimal();
      output.vxdecimal = sval;
      return output;
    }

    @Override
    public Type_decimal vx_new(final Object... vals) {return e_decimal.vx_copy(vals);}

    @Override
    public Type_decimal vx_copy(final Object... vals) {
      Type_decimal output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_decimal val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      String sval = val.vx_string();
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_string) {
          Core.Type_string valstring = (Core.Type_string)valsub;
          ischanged = true;
          sval = valstring.vx_string();
        } else if (valsub instanceof String) {
          ischanged = true;
          sval = (String)valsub;
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_decimal work = new Class_decimal();
        work.vxdecimal = sval;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_decimal vx_empty() {return e_decimal;}
    @Override
    public Type_decimal vx_type() {return t_decimal;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "decimal", // name
        "", // extends
        Core.t_typelist.vx_new(Core.t_number), // traits
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

  public static final Type_decimal e_decimal = new Class_decimal();
  public static final Type_decimal t_decimal = new Class_decimal();

  /**
   * type: error
   * Error Type
   * (type error)
   */
  public interface Type_error extends Core.Type_any {
    public Core.Type_error vx_new(final Object... vals);
    public Core.Type_error vx_copy(final Object... vals);
    public Core.Type_error vx_empty();
    public Core.Type_error vx_type();
  }

  public static class Class_error extends Core.Class_base implements Type_error {

    @Override
    public Type_error vx_new(final Object... vals) {return e_error.vx_copy(vals);}

    @Override
    public Type_error vx_copy(final Object... vals) {
      Type_error output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_error vx_empty() {return e_error;}
    @Override
    public Type_error vx_type() {return t_error;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "error", // name
        "", // extends
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

  public static final Type_error e_error = new Class_error();
  public static final Type_error t_error = new Class_error();

  /**
   * type: float
   * Standard Floating Point Number
   * (type float)
   */
  public interface Type_float extends Core.Type_number {
    public Core.Type_float vx_new(final Object... vals);
    public Core.Type_float vx_copy(final Object... vals);
    public Core.Type_float vx_empty();
    public Core.Type_float vx_type();
    public float vx_float();
  }

  public static class Class_float extends Core.Class_base implements Type_float {

    protected float vxfloat = 0;
    
    @Override
    public float vx_float() {return vxfloat;}

    @Override
    public Type_float vx_new(final Object... vals) {return e_float.vx_copy(vals);}

    @Override
    public Type_float vx_copy(final Object... vals) {
      Type_float output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_float val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      float floatval = val.vx_float();
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_decimal) {
          Core.Type_decimal valnum = (Core.Type_decimal)valsub;
          ischanged = true;
          floatval += valnum.vx_float();
        } else if (valsub instanceof Core.Type_float) {
          Core.Type_float valnum = (Core.Type_float)valsub;
          ischanged = true;
          floatval += valnum.vx_float();
        } else if (valsub instanceof Core.Type_int) {
          Core.Type_int valnum = (Core.Type_int)valsub;
          ischanged = true;
          floatval += valnum.vx_int();
        } else if (valsub instanceof Core.Type_string) {
          Core.Type_string valstring = (Core.Type_string)valsub;
          ischanged = true;
          floatval += Float.parseFloat(valstring.vx_string());
        } else if (valsub instanceof Float) {
          ischanged = true;
          floatval += (Float)valsub;
        } else if (valsub instanceof Integer) {
          ischanged = true;
          floatval += (Integer)valsub;
        } else if (valsub instanceof String) {
          ischanged = true;
          floatval += Float.parseFloat((String)valsub);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_float work = new Class_float();
        work.vxfloat = floatval;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_float vx_empty() {return e_float;}
    @Override
    public Type_float vx_type() {return t_float;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "float", // name
        "", // extends
        Core.t_typelist.vx_new(Core.t_number), // traits
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

  public static final Type_float e_float = new Class_float();
  public static final Type_float t_float = new Class_float();

  /**
   * type: func
   * Original Function Class.
   * (type func)
   */
  public interface Type_func extends Core.Type_any {
    public Core.Type_func vx_new(final Object... vals);
    public Core.Type_func vx_copy(final Object... vals);
    public Core.Type_func vx_empty();
    public Core.Type_func vx_type();
	   public Core.Type_funcdef vx_funcdef();
  }

  public static class Class_func extends Core.Class_base implements Type_func {

    public Core.Type_funcdef vx_funcdef() {
      return Core.e_funcdef;
    }
    @Override
    public Type_func vx_new(final Object... vals) {return e_func.vx_copy(vals);}

    @Override
    public Type_func vx_copy(final Object... vals) {
      Type_func output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_func vx_empty() {return e_func;}
    @Override
    public Type_func vx_type() {return t_func;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "func", // name
        ":func", // extends
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

  public static final Type_func e_func = new Class_func();
  public static final Type_func t_func = new Class_func();

  /**
   * type: funcdef
   * Func Definition Class for inspecting properties.
   * (type funcdef)
   */
  public interface Type_funcdef extends Core.Type_struct {
    public Core.Type_funcdef vx_new(final Object... vals);
    public Core.Type_funcdef vx_copy(final Object... vals);
    public Core.Type_funcdef vx_empty();
    public Core.Type_funcdef vx_type();
    public Core.Type_string pkgname();
    public Core.Type_string name();
    public Core.Type_int idx();
    public Core.Type_any type();
    public Core.Type_boolean async();
  }

  public static class Class_funcdef extends Core.Class_base implements Type_funcdef {

    protected Core.Type_string vx_p_pkgname;

    @Override
    public Core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? Core.e_string : this.vx_p_pkgname;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_int vx_p_idx;

    @Override
    public Core.Type_int idx() {
      return this.vx_p_idx == null ? Core.e_int : this.vx_p_idx;
    }

    protected Core.Type_any vx_p_type;

    @Override
    public Core.Type_any type() {
      return this.vx_p_type == null ? Core.e_any : this.vx_p_type;
    }

    protected Core.Type_boolean vx_p_async;

    @Override
    public Core.Type_boolean async() {
      return this.vx_p_async == null ? Core.e_boolean : this.vx_p_async;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pkgname":
        output = this.pkgname();
        break;
      case ":name":
        output = this.name();
        break;
      case ":idx":
        output = this.idx();
        break;
      case ":type":
        output = this.type();
        break;
      case ":async":
        output = this.async();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":idx", this.idx());
      output.put(":type", this.type());
      output.put(":async", this.async());
      return Core.immutablemap(output);
    }

    @Override
    public Type_funcdef vx_new(final Object... vals) {return e_funcdef.vx_copy(vals);}

    @Override
    public Type_funcdef vx_copy(final Object... vals) {
      Type_funcdef output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_funcdef val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_pkgname = val.pkgname();
      Core.Type_string vx_p_name = val.name();
      Core.Type_int vx_p_idx = val.idx();
      Core.Type_any vx_p_type = val.type();
      Core.Type_boolean vx_p_async = val.async();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":name");
      validkeys.add(":idx");
      validkeys.add(":type");
      validkeys.add(":async");
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
            Core.Type_msg msg = Core.vx_msg_error("(new funcdef) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_pkgname = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new funcdef :pkgname " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new funcdef :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":idx":
            if (valsub == vx_p_idx) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_idx = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_idx = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new funcdef :idx " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_type = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new funcdef :type " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_async = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_async = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new funcdef :async " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new funcdef) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_funcdef work = new Class_funcdef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_idx = vx_p_idx;
        work.vx_p_type = vx_p_type;
        work.vx_p_async = vx_p_async;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_funcdef vx_empty() {return e_funcdef;}
    @Override
    public Type_funcdef vx_type() {return t_funcdef;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
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

  public static final Type_funcdef e_funcdef = new Class_funcdef();
  public static final Type_funcdef t_funcdef = new Class_funcdef();

  /**
   * type: funclist
   * List of Func.
   * (type funclist)
   */
  public interface Type_funclist extends Core.Type_list {
    public Core.Type_funclist vx_new(final Object... vals);
    public Core.Type_funclist vx_copy(final Object... vals);
    public Core.Type_funclist vx_empty();
    public Core.Type_funclist vx_type();
    public List<Core.Type_func> vx_listfunc();
    public Core.Type_func vx_func(final Core.Type_int index);
  }

  public static class Class_funclist extends Core.Class_base implements Type_funclist {

    protected List<Core.Type_func> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_func>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_func vx_func(final Core.Type_int index) {
      Core.Type_func output = Core.e_func;
      Class_funclist list = this;
      int iindex = index.vx_int();
      List<Core.Type_func> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_func> vx_listfunc() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_func(index);
    }

    @Override
    public Type_funclist vx_new(final Object... vals) {return e_funclist.vx_copy(vals);}

    @Override
    public Type_funclist vx_copy(final Object... vals) {
      Type_funclist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_funclist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_func> listval = new ArrayList<>(val.vx_listfunc());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_func) {
          ischanged = true;
          listval.add((Core.Type_func)valsub);
        } else if (valsub instanceof Core.Type_func) {
          ischanged = true;
          listval.add((Core.Type_func)valsub);
        } else if (valsub instanceof Type_funclist) {
          Type_funclist multi = (Type_funclist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listfunc());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_func) {
              Core.Type_func valitem = (Core.Type_func)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new funclist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_funclist work = new Class_funclist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_funclist vx_empty() {return e_funclist;}
    @Override
    public Type_funclist vx_type() {return t_funclist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "funclist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_func), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_funclist e_funclist = new Class_funclist();
  public static final Type_funclist t_funclist = new Class_funclist();

  /**
   * type: funcmap
   * Map of Func.
   * (type funcmap)
   */
  public interface Type_funcmap extends Core.Type_map {
    public Core.Type_funcmap vx_new(final Object... vals);
    public Core.Type_funcmap vx_copy(final Object... vals);
    public Core.Type_funcmap vx_empty();
    public Core.Type_funcmap vx_type();
    public Map<String, Core.Type_func> vx_mapfunc();
    public Core.Type_func vx_func(final Core.Type_string key);
  }

  public static class Class_funcmap extends Core.Class_base implements Type_funcmap {

    protected Map<String, Core.Type_func> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_func>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_func vx_func(final Core.Type_string key) {
      Core.Type_func output = Core.e_func;
      Class_funcmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_func> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_func);
      return output;
    }

    @Override
    public Map<String, Core.Type_func> vx_mapfunc() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_func(key);
    }

    @Override
    public Type_funcmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_funcmap output = new Class_funcmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_func> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_func) {
          Core.Type_func castval = (Core.Type_func)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(funcmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_funcmap vx_new(final Object... vals) {return e_funcmap.vx_copy(vals);}

    @Override
    public Type_funcmap vx_copy(final Object... vals) {
      Type_funcmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_funcmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_func> mapval = new LinkedHashMap<>(valmap.vx_mapfunc());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_func valany = null;
          if (valsub instanceof Core.Type_func) {
            valany = (Core.Type_func)valsub;
          } else if (valsub instanceof Core.Type_func) {
            valany = (Core.Type_func)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_funcmap work = new Class_funcmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_funcmap vx_empty() {return e_funcmap;}
    @Override
    public Type_funcmap vx_type() {return t_funcmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "funcmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_func), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_funcmap e_funcmap = new Class_funcmap();
  public static final Type_funcmap t_funcmap = new Class_funcmap();

  /**
   * type: int
   * A simple integer.
   * (type int)
   */
  public interface Type_int extends Core.Type_number {
    public Core.Type_int vx_new(final Object... vals);
    public Core.Type_int vx_copy(final Object... vals);
    public Core.Type_int vx_empty();
    public Core.Type_int vx_type();
    public int vx_int();
  }

  public static class Class_int extends Core.Class_base implements Type_int {

    protected int vxint = 0;
    
    @Override
    public int vx_int() {return vxint;}

    @Override
    public Type_int vx_new(final Object... vals) {return e_int.vx_copy(vals);}

    @Override
    public Type_int vx_copy(final Object... vals) {
      Type_int output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_int val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      int intval = val.vx_int();
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_int) {
          ischanged = true;
          Core.Type_int valnum = (Core.Type_int)valsub;
          intval += valnum.vx_int();
        } else if (valsub instanceof Integer) {
          ischanged = true;
          intval += (Integer)valsub;
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_int work = new Class_int();
        work.vxint = intval;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_int vx_empty() {return e_int;}
    @Override
    public Type_int vx_type() {return t_int;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        Core.t_typelist.vx_new(Core.t_number), // traits
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

  public static final Type_int e_int = new Class_int();
  public static final Type_int t_int = new Class_int();

  /**
   * type: intlist
   * A list of int.
   * (type intlist)
   */
  public interface Type_intlist extends Core.Type_list {
    public Core.Type_intlist vx_new(final Object... vals);
    public Core.Type_intlist vx_copy(final Object... vals);
    public Core.Type_intlist vx_empty();
    public Core.Type_intlist vx_type();
    public List<Core.Type_int> vx_listint();
    public Core.Type_int vx_int(final Core.Type_int index);
  }

  public static class Class_intlist extends Core.Class_base implements Type_intlist {

    protected List<Core.Type_int> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_int>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_int vx_int(final Core.Type_int index) {
      Core.Type_int output = Core.e_int;
      Class_intlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_int> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_int> vx_listint() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_int(index);
    }

    @Override
    public Type_intlist vx_new(final Object... vals) {return e_intlist.vx_copy(vals);}

    @Override
    public Type_intlist vx_copy(final Object... vals) {
      Type_intlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_intlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_int> listval = new ArrayList<>(val.vx_listint());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_int) {
          ischanged = true;
          listval.add((Core.Type_int)valsub);
        } else if (valsub instanceof Integer) {
          ischanged = true;
          listval.add(Core.t_int.vx_new(valsub));
        } else if (valsub instanceof Type_intlist) {
          Type_intlist multi = (Type_intlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listint());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_int) {
              Core.Type_int valitem = (Core.Type_int)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new intlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_intlist work = new Class_intlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_intlist vx_empty() {return e_intlist;}
    @Override
    public Type_intlist vx_type() {return t_intlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "intlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_int), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_intlist e_intlist = new Class_intlist();
  public static final Type_intlist t_intlist = new Class_intlist();

  /**
   * type: intmap
   * A map of int.
   * (type intmap)
   */
  public interface Type_intmap extends Core.Type_map {
    public Core.Type_intmap vx_new(final Object... vals);
    public Core.Type_intmap vx_copy(final Object... vals);
    public Core.Type_intmap vx_empty();
    public Core.Type_intmap vx_type();
    public Map<String, Core.Type_int> vx_mapint();
    public Core.Type_int vx_int(final Core.Type_string key);
  }

  public static class Class_intmap extends Core.Class_base implements Type_intmap {

    protected Map<String, Core.Type_int> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_int>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_int vx_int(final Core.Type_string key) {
      Core.Type_int output = Core.e_int;
      Class_intmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_int> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_int);
      return output;
    }

    @Override
    public Map<String, Core.Type_int> vx_mapint() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_int(key);
    }

    @Override
    public Type_intmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_intmap output = new Class_intmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_int> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_int) {
          Core.Type_int castval = (Core.Type_int)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(intmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_intmap vx_new(final Object... vals) {return e_intmap.vx_copy(vals);}

    @Override
    public Type_intmap vx_copy(final Object... vals) {
      Type_intmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_intmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_int> mapval = new LinkedHashMap<>(valmap.vx_mapint());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_int valany = null;
          if (valsub instanceof Core.Type_int) {
            valany = (Core.Type_int)valsub;
          } else if (valsub instanceof Integer) {
            valany = Core.t_int.vx_new(valsub);;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_intmap work = new Class_intmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_intmap vx_empty() {return e_intmap;}
    @Override
    public Type_intmap vx_type() {return t_intmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "intmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_int), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_intmap e_intmap = new Class_intmap();
  public static final Type_intmap t_intmap = new Class_intmap();

  /**
   * type: list
   * A simple untyped list.
   * (type list)
   */
  public interface Type_list extends Core.Type_any {
    public Core.Type_list vx_new(final Object... vals);
    public Core.Type_list vx_copy(final Object... vals);
    public Core.Type_list vx_empty();
    public Core.Type_list vx_type();
    public List<Core.Type_any> vx_list();
    public Core.Type_any vx_any(final Core.Type_int index);
  }

  public static class Class_list extends Core.Class_base implements Type_list {


    public <T extends Core.Type_any> List<T> vx_any(final T generic_any_1) {
      return Core.arraylist_from_arraylist(generic_any_1, this.vx_list());
    }

    public <T extends Core.Type_any> T vx_any_from_list(final T generic_any_1, final int index) {
      return vx_any_from_list(generic_any_1, this.vx_list(), index);
    }

    protected List<Core.Type_any> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_any>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_any output = Core.e_any;
      Class_list list = this;
      int iindex = index.vx_int();
      List<Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public Type_list vx_new(final Object... vals) {return e_list.vx_copy(vals);}

    @Override
    public Type_list vx_copy(final Object... vals) {
      Type_list output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_list val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_any> listval = new ArrayList<>(val.vx_list());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Type_list) {
          Type_list multi = (Type_list)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_any) {
              Core.Type_any valitem = (Core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new list) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_list work = new Class_list();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_list vx_empty() {return e_list;}
    @Override
    public Type_list vx_type() {return t_list;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "list", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

    public static <T extends Core.Type_any> List<T> list_new(final T generic_any_1, final Core.Type_any... vals) {
      List<Core.Type_any> listval = Arrays.asList(vals);
      return Core.arraylist_from_arraylist(generic_any_1, listval);
    }

    public static <T extends Core.Type_any> T vx_any_from_list(final T generic_any_1, final List<Core.Type_any> list, final int index) {
      T output = Core.f_empty(generic_any_1);
      if (list.size() > index) {
        output = Core.f_any_from_any(generic_any_1, list.get(index));
      }
      return output;
    }

    public static <T extends Core.Type_any> T vx_any_first_from_list_fn(final T generic_any_1, final Core.Type_list list, final Function<Core.Type_any, T> fn_any) {
      T output = Core.f_empty(generic_any_1);
      List<Core.Type_any> listany = list.vx_list();
      for (Core.Type_any any : listany) {
        T tany = Core.f_any_from_any(generic_any_1, any);
        T val = fn_any.apply(tany);
        if (val != null) {
          output = val;
          break;
        }
      }
      return output;
    }

  }

  public static final Type_list e_list = new Class_list();
  public static final Type_list t_list = new Class_list();

  /**
   * type: listtype
   * A generic type that extends :list.
   * (type listtype)
   */
  public interface Type_listtype extends Core.Type_any {
    public Core.Type_listtype vx_new(final Object... vals);
    public Core.Type_listtype vx_copy(final Object... vals);
    public Core.Type_listtype vx_empty();
    public Core.Type_listtype vx_type();
  }

  public static class Class_listtype extends Core.Class_base implements Type_listtype {

    @Override
    public Type_listtype vx_new(final Object... vals) {return e_listtype.vx_copy(vals);}

    @Override
    public Type_listtype vx_copy(final Object... vals) {
      Type_listtype output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_listtype vx_empty() {return e_listtype;}
    @Override
    public Type_listtype vx_type() {return t_listtype;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "listtype", // name
        ":type", // extends
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

  public static final Type_listtype e_listtype = new Class_listtype();
  public static final Type_listtype t_listtype = new Class_listtype();

  /**
   * type: map
   * A simple untyped map.
   * (type map)
   */
  public interface Type_map extends Core.Type_any {
    public Core.Type_map vx_new(final Object... vals);
    public Core.Type_map vx_copy(final Object... vals);
    public Core.Type_map vx_empty();
    public Core.Type_map vx_type();
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval);
    public Core.Type_any vx_any(final Core.Type_string key);
    public Map<String, Core.Type_any> vx_map();
  }

  public static class Class_map extends Core.Class_base implements Type_map {

    protected Map<String, Core.Type_any> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      Class_map map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_any);
      return output;
    }

    @Override
    public Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_map output = new Class_map();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_any) {
          Core.Type_any castval = (Core.Type_any)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(map) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_map vx_new(final Object... vals) {return e_map.vx_copy(vals);}

    @Override
    public Type_map vx_copy(final Object... vals) {
      Type_map output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_map valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_any> mapval = new LinkedHashMap<>(valmap.vx_map());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_any valany = null;
          if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_map work = new Class_map();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_map vx_empty() {return e_map;}
    @Override
    public Type_map vx_type() {return t_map;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "map", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_map e_map = new Class_map();
  public static final Type_map t_map = new Class_map();

  /**
   * type: maptype
   * A generic type that extends :map.
   * (type maptype)
   */
  public interface Type_maptype extends Core.Type_any {
    public Core.Type_maptype vx_new(final Object... vals);
    public Core.Type_maptype vx_copy(final Object... vals);
    public Core.Type_maptype vx_empty();
    public Core.Type_maptype vx_type();
  }

  public static class Class_maptype extends Core.Class_base implements Type_maptype {

    @Override
    public Type_maptype vx_new(final Object... vals) {return e_maptype.vx_copy(vals);}

    @Override
    public Type_maptype vx_copy(final Object... vals) {
      Type_maptype output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_maptype vx_empty() {return e_maptype;}
    @Override
    public Type_maptype vx_type() {return t_maptype;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "maptype", // name
        ":type", // extends
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

  public static final Type_maptype e_maptype = new Class_maptype();
  public static final Type_maptype t_maptype = new Class_maptype();

  /**
   * type: mempool
   * Memory Pool
   * (type mempool)
   */
  public interface Type_mempool extends Core.Type_struct {
    public Core.Type_mempool vx_new(final Object... vals);
    public Core.Type_mempool vx_copy(final Object... vals);
    public Core.Type_mempool vx_empty();
    public Core.Type_mempool vx_type();
    public <T extends Core.Type_any> T vx_restore(final T generic_any_1);
    public void vx_recycle(final Core.Type_any addany);
    public void vx_recyclelist(final List<Core.Type_any> addlistany);
    public Core.Type_value valuepool();
  }

  public static class Class_mempool extends Core.Class_base implements Type_mempool {

    private int vx_max = 20;
    
    private Map<String, Deque<Core.Type_any>> vx_maplistany = new ConcurrentHashMap<>();
    
    @Override
    public <T extends Core.Type_any> T vx_restore(final T generic_any_1) {
      T output = null;
      String typename = Core.f_typename_from_any(generic_any_1).vx_string();
      Deque<Core.Type_any> listany = this.vx_maplistany.get(typename);
      if (listany == null) {
      } else if (!listany.isEmpty()) {
        Core.Type_any any = listany.remove();
        if (any != null) {
          output = Core.f_any_from_any(generic_any_1, any);
        }
      }
      return output;
    }
    
    @Override
    public void vx_recycle(final Core.Type_any addany) {
      String typename = Core.f_typename_from_any(addany).vx_string();
      Deque<Core.Type_any> listany = this.vx_maplistany.get(typename);
      boolean isdestroy = true;
      int imax = this.vx_max;
      if (imax == 0) {
      } else if (listany == null) {
       isdestroy = false;
       listany = new ConcurrentLinkedDeque<Core.Type_any>();
       listany.add(addany);
       this.vx_maplistany.put(typename, listany);
      } else {
       int ilen = listany.size();
       if (ilen < imax) {
         listany.add(addany);
       }
      }
      if (isdestroy) {
        // destroy
      }
    }
    
    @Override
    public void vx_recyclelist(final List<Core.Type_any> addlistany) {
      for (Core.Type_any addany : addlistany) {
        this.vx_recycle(addany);
      }
    }

    protected Core.Type_value vx_p_valuepool;

    @Override
    public Core.Type_value valuepool() {
      return this.vx_p_valuepool == null ? Core.e_value : this.vx_p_valuepool;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":valuepool":
        output = this.valuepool();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":valuepool", this.valuepool());
      return Core.immutablemap(output);
    }

    @Override
    public Type_mempool vx_new(final Object... vals) {return e_mempool.vx_copy(vals);}

    @Override
    public Type_mempool vx_copy(final Object... vals) {
      Type_mempool output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_mempool val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_value vx_p_valuepool = val.valuepool();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":valuepool");
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
            Core.Type_msg msg = Core.vx_msg_error("(new mempool) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":valuepool":
            if (valsub == vx_p_valuepool) {
            } else if (valsub instanceof Core.Type_value) {
              ischanged = true;
              vx_p_valuepool = (Core.Type_value)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new mempool :valuepool " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new mempool) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_mempool work = new Class_mempool();
        work.vx_p_valuepool = vx_p_valuepool;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_mempool vx_empty() {return e_mempool;}
    @Override
    public Type_mempool vx_type() {return t_mempool;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "mempool", // name
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

  public static final Type_mempool e_mempool = new Class_mempool();
  public static final Type_mempool t_mempool = new Class_mempool();

  /**
   * type: msg
   * Message Type for error handling
   * (type msg)
   */
  public interface Type_msg extends Core.Type_struct {
    public Core.Type_msg vx_new(final Object... vals);
    public Core.Type_msg vx_copy(final Object... vals);
    public Core.Type_msg vx_empty();
    public Core.Type_msg vx_type();
    public Core.Type_typedef vx_typedef();
    public Core.Type_string code();
    public Core.Type_int severity();
    public Core.Type_string text();
  }

  public static class Class_msg extends Core.Class_base implements Type_msg {

    public Exception err = null;

    protected Core.Type_string vx_p_code;

    @Override
    public Core.Type_string code() {
      return this.vx_p_code == null ? Core.e_string : this.vx_p_code;
    }

    protected Core.Type_int vx_p_severity;

    @Override
    public Core.Type_int severity() {
      return this.vx_p_severity == null ? Core.e_int : this.vx_p_severity;
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
      case ":code":
        output = this.code();
        break;
      case ":severity":
        output = this.severity();
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
      output.put(":code", this.code());
      output.put(":severity", this.severity());
      output.put(":text", this.text());
      return Core.immutablemap(output);
    }

    @Override
    public Type_msg vx_new(final Object... vals) {return e_msg.vx_copy(vals);}

    @Override
    public Type_msg vx_copy(final Object... vals) {
      Type_msg output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_msg val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_code = val.code();
      Core.Type_int vx_p_severity = val.severity();
      Core.Type_string vx_p_text = val.text();
      String key = "";
      for (Object valsub : vals) {
        if (key == "") {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            key = valstr.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("(new msg) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_code = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_code = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new msg :code " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":severity":
            if (valsub == vx_p_severity) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_severity = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_severity = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new msg :severity " + valsub.toString() + ") - Invalid Value");
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
              Core.Type_msg msg = Core.vx_msg_error("(new msg :text " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          }
          key = "";
        }
      }
      return output;
    }

    @Override
    public Core.Type_msgblock vx_msgblock() {return Core.e_msgblock;}
    @Override
    public Type_msg vx_empty() {return e_msg;}
    @Override
    public Type_msg vx_type() {return t_msg;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "msg", // name
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

  public static final Type_msg e_msg = new Class_msg();
  public static final Type_msg t_msg = new Class_msg();

  /**
   * type: msgblock
   * Block of Messages
   * (type msgblock)
   */
  public interface Type_msgblock extends Core.Type_struct {
    public Core.Type_msgblock vx_new(final Object... vals);
    public Core.Type_msgblock vx_copy(final Object... vals);
    public Core.Type_msgblock vx_empty();
    public Core.Type_msgblock vx_type();
    public Core.Type_typedef vx_typedef();
    public Type_msgblock vx_msgblock_from_copy_arrayval(final Core.Type_any copy, final Object... vals);
    public Core.Type_msglist msgs();
    public Core.Type_msgblocklist msgblocks();
  }

  public static class Class_msgblock extends Core.Class_base implements Type_msgblock {

    public Type_msgblock vx_msgblock_from_copy_arrayval(final Core.Type_any copy, final Object... vals) {
      Core.Type_msgblock output = Core.e_msgblock;
      Core.Type_msgblock copymsgblock = copy.vx_msgblock();
      if (copymsgblock != null) {
        output = copymsgblock;
      }
      return output;
    }

    protected Core.Type_msglist vx_p_msgs;

    @Override
    public Core.Type_msglist msgs() {
      return this.vx_p_msgs == null ? Core.e_msglist : this.vx_p_msgs;
    }

    protected Core.Type_msgblocklist vx_p_msgblocks;

    @Override
    public Core.Type_msgblocklist msgblocks() {
      return this.vx_p_msgblocks == null ? Core.e_msgblocklist : this.vx_p_msgblocks;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":msgs":
        output = this.msgs();
        break;
      case ":msgblocks":
        output = this.msgblocks();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":msgs", this.msgs());
      output.put(":msgblocks", this.msgblocks());
      return Core.immutablemap(output);
    }

    @Override
    public Type_msgblock vx_new(final Object... vals) {return e_msgblock.vx_copy(vals);}

    @Override
    public Type_msgblock vx_copy(final Object... vals) {
      Type_msgblock output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_msgblock val = this;
      Core.Type_msgblock msgblock = this;
      Core.Type_msglist vx_p_msgs = val.msgs();
      Core.Type_msgblocklist vx_p_msgblocks = val.msgblocks();
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          Core.Type_msgblocklist msgblocks = this.msgblocks();
          msgblocks = msgblocks.vx_copy(valsub);
          vx_p_msgblocks = msgblocks;
        } else if (valsub instanceof Core.Type_msg) {
          Core.Type_msglist msgs = this.msgs();
          msgs = msgs.vx_copy(valsub);
          vx_p_msgs = msgs;
        } else if (valsub instanceof Core.Type_msgblocklist) {
          Core.Type_msgblocklist msgblocks = this.msgblocks();
          msgblocks = msgblocks.vx_copy(valsub);
          vx_p_msgblocks = msgblocks;
        } else if (valsub instanceof Core.Type_msglist) {
          Core.Type_msglist msgs = this.msgs();
          msgs = msgs.vx_copy(valsub);
          vx_p_msgs = msgs;
        } else if (key == "") {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            key = valstr.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("(new msgblock) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":msgs":
            if (valsub == vx_p_msgs) {
            } else if (valsub instanceof Core.Type_msglist) {
              ischanged = true;
              vx_p_msgs = (Core.Type_msglist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new msgblock :msgs " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":msgblocks":
            if (valsub == vx_p_msgblocks) {
            } else if (valsub instanceof Core.Type_msgblocklist) {
              ischanged = true;
              vx_p_msgblocks = (Core.Type_msgblocklist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new msgblock :msgblocks " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          }
          key = "";
        }
        Class_msgblock work = new Class_msgblock();
        work.vxmsgblock = msgblock;
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_msgblock vx_msgblock() {return this;}
    @Override
    public Type_msgblock vx_empty() {return e_msgblock;}
    @Override
    public Type_msgblock vx_type() {return t_msgblock;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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

  public static final Type_msgblock e_msgblock = new Class_msgblock();
  public static final Type_msgblock t_msgblock = new Class_msgblock();

  /**
   * type: msgblocklist
   * List of Message Blocks
   * (type msgblocklist)
   */
  public interface Type_msgblocklist extends Core.Type_list {
    public Core.Type_msgblocklist vx_new(final Object... vals);
    public Core.Type_msgblocklist vx_copy(final Object... vals);
    public Core.Type_msgblocklist vx_empty();
    public Core.Type_msgblocklist vx_type();
    public List<Core.Type_msgblock> vx_listmsgblock();
    public Core.Type_msgblock vx_msgblock(final Core.Type_int index);
  }

  public static class Class_msgblocklist extends Core.Class_base implements Type_msgblocklist {

    protected List<Core.Type_msgblock> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_msgblock>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_msgblock vx_msgblock(final Core.Type_int index) {
      Core.Type_msgblock output = Core.e_msgblock;
      Class_msgblocklist list = this;
      int iindex = index.vx_int();
      List<Core.Type_msgblock> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_msgblock> vx_listmsgblock() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_msgblock(index);
    }

    @Override
    public Type_msgblocklist vx_new(final Object... vals) {return e_msgblocklist.vx_copy(vals);}

    @Override
    public Type_msgblocklist vx_copy(final Object... vals) {
      Type_msgblocklist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_msgblocklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_msgblock> listval = new ArrayList<>(val.vx_listmsgblock());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msgblock) {
          ischanged = true;
          listval.add((Core.Type_msgblock)valsub);
        } else if (valsub instanceof Type_msgblocklist) {
          Type_msgblocklist multi = (Type_msgblocklist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listmsgblock());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_msgblock) {
              Core.Type_msgblock valitem = (Core.Type_msgblock)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new msgblocklist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_msgblocklist work = new Class_msgblocklist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_msgblocklist vx_empty() {return e_msgblocklist;}
    @Override
    public Type_msgblocklist vx_type() {return t_msgblocklist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "msgblocklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_msgblock), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_msgblocklist e_msgblocklist = new Class_msgblocklist();
  public static final Type_msgblocklist t_msgblocklist = new Class_msgblocklist();

  /**
   * type: msglist
   * List of Messages
   * (type msglist)
   */
  public interface Type_msglist extends Core.Type_list {
    public Core.Type_msglist vx_new(final Object... vals);
    public Core.Type_msglist vx_copy(final Object... vals);
    public Core.Type_msglist vx_empty();
    public Core.Type_msglist vx_type();
    public List<Core.Type_msg> vx_listmsg();
    public Core.Type_msg vx_msg(final Core.Type_int index);
  }

  public static class Class_msglist extends Core.Class_base implements Type_msglist {

    protected List<Core.Type_msg> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_msg>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_msg vx_msg(final Core.Type_int index) {
      Core.Type_msg output = Core.e_msg;
      Class_msglist list = this;
      int iindex = index.vx_int();
      List<Core.Type_msg> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_msg> vx_listmsg() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_msg(index);
    }

    @Override
    public Type_msglist vx_new(final Object... vals) {return e_msglist.vx_copy(vals);}

    @Override
    public Type_msglist vx_copy(final Object... vals) {
      Type_msglist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_msglist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_msg> listval = new ArrayList<>(val.vx_listmsg());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          ischanged = true;
          listval.add((Core.Type_msg)valsub);
        } else if (valsub instanceof Type_msglist) {
          Type_msglist multi = (Type_msglist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listmsg());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_msg) {
              Core.Type_msg valitem = (Core.Type_msg)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new msglist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_msglist work = new Class_msglist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_msglist vx_empty() {return e_msglist;}
    @Override
    public Type_msglist vx_type() {return t_msglist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "msglist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_msg), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_msglist e_msglist = new Class_msglist();
  public static final Type_msglist t_msglist = new Class_msglist();

  /**
   * type: none
   * No Type. No type is returned at all. e.g. Void
   * (type none)
   */
  public interface Type_none extends Core.Type_any {
    public Core.Type_none vx_new(final Object... vals);
    public Core.Type_none vx_copy(final Object... vals);
    public Core.Type_none vx_empty();
    public Core.Type_none vx_type();
  }

  public static class Class_none extends Core.Class_base implements Type_none {

    @Override
    public Type_none vx_new(final Object... vals) {return e_none.vx_copy(vals);}

    @Override
    public Type_none vx_copy(final Object... vals) {
      Type_none output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_none vx_empty() {return e_none;}
    @Override
    public Type_none vx_type() {return t_none;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
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

  public static final Type_none e_none = new Class_none();
  public static final Type_none t_none = new Class_none();

  /**
   * type: notype
   * No Type that allows no Types as a Value
   * (type notype)
   */
  public interface Type_notype extends Core.Type_any {
    public Core.Type_notype vx_new(final Object... vals);
    public Core.Type_notype vx_copy(final Object... vals);
    public Core.Type_notype vx_empty();
    public Core.Type_notype vx_type();
  }

  public static class Class_notype extends Core.Class_base implements Type_notype {

    @Override
    public Type_notype vx_new(final Object... vals) {return e_notype.vx_copy(vals);}

    @Override
    public Type_notype vx_copy(final Object... vals) {
      Type_notype output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_notype vx_empty() {return e_notype;}
    @Override
    public Type_notype vx_type() {return t_notype;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "notype", // name
        "", // extends
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

  public static final Type_notype e_notype = new Class_notype();
  public static final Type_notype t_notype = new Class_notype();

  /**
   * type: number
   * A generic number that could be int, float, or decimal.
   * (type number)
   */
  public interface Type_number extends Core.Type_any {
    public Core.Type_number vx_new(final Object... vals);
    public Core.Type_number vx_copy(final Object... vals);
    public Core.Type_number vx_empty();
    public Core.Type_number vx_type();
  }

  public static class Class_number extends Core.Class_base implements Type_number {

    @Override
    public Type_number vx_new(final Object... vals) {return e_number.vx_copy(vals);}

    @Override
    public Type_number vx_copy(final Object... vals) {
      Type_number output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_number vx_empty() {return e_number;}
    @Override
    public Type_number vx_type() {return t_number;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_number e_number = new Class_number();
  public static final Type_number t_number = new Class_number();

  /**
   * type: numberlist
   * A list of number.
   * (type numberlist)
   */
  public interface Type_numberlist extends Core.Type_list {
    public Core.Type_numberlist vx_new(final Object... vals);
    public Core.Type_numberlist vx_copy(final Object... vals);
    public Core.Type_numberlist vx_empty();
    public Core.Type_numberlist vx_type();
    public List<Core.Type_number> vx_listnumber();
    public Core.Type_number vx_number(final Core.Type_int index);
  }

  public static class Class_numberlist extends Core.Class_base implements Type_numberlist {

    protected List<Core.Type_number> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_number>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_number vx_number(final Core.Type_int index) {
      Core.Type_number output = Core.e_number;
      Class_numberlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_number> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_number> vx_listnumber() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_number(index);
    }

    @Override
    public Type_numberlist vx_new(final Object... vals) {return e_numberlist.vx_copy(vals);}

    @Override
    public Type_numberlist vx_copy(final Object... vals) {
      Type_numberlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_numberlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_number> listval = new ArrayList<>(val.vx_listnumber());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_number) {
          ischanged = true;
          listval.add((Core.Type_number)valsub);
        } else if (valsub instanceof Core.Type_number) {
          ischanged = true;
          listval.add((Core.Type_number)valsub);
        } else if (valsub instanceof Type_numberlist) {
          Type_numberlist multi = (Type_numberlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listnumber());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_number) {
              Core.Type_number valitem = (Core.Type_number)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new numberlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_numberlist work = new Class_numberlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_numberlist vx_empty() {return e_numberlist;}
    @Override
    public Type_numberlist vx_type() {return t_numberlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "numberlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_number), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_numberlist e_numberlist = new Class_numberlist();
  public static final Type_numberlist t_numberlist = new Class_numberlist();

  /**
   * type: numbermap
   * A map of number.
   * (type numbermap)
   */
  public interface Type_numbermap extends Core.Type_map {
    public Core.Type_numbermap vx_new(final Object... vals);
    public Core.Type_numbermap vx_copy(final Object... vals);
    public Core.Type_numbermap vx_empty();
    public Core.Type_numbermap vx_type();
    public Map<String, Core.Type_number> vx_mapnumber();
    public Core.Type_number vx_number(final Core.Type_string key);
  }

  public static class Class_numbermap extends Core.Class_base implements Type_numbermap {

    protected Map<String, Core.Type_number> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_number>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_number vx_number(final Core.Type_string key) {
      Core.Type_number output = Core.e_number;
      Class_numbermap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_number> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_number);
      return output;
    }

    @Override
    public Map<String, Core.Type_number> vx_mapnumber() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_number(key);
    }

    @Override
    public Type_numbermap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_numbermap output = new Class_numbermap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_number> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_number) {
          Core.Type_number castval = (Core.Type_number)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(numbermap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_numbermap vx_new(final Object... vals) {return e_numbermap.vx_copy(vals);}

    @Override
    public Type_numbermap vx_copy(final Object... vals) {
      Type_numbermap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_numbermap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_number> mapval = new LinkedHashMap<>(valmap.vx_mapnumber());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_number valany = null;
          if (valsub instanceof Core.Type_number) {
            valany = (Core.Type_number)valsub;
          } else if (valsub instanceof Core.Type_number) {
            valany = (Core.Type_number)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_numbermap work = new Class_numbermap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_numbermap vx_empty() {return e_numbermap;}
    @Override
    public Type_numbermap vx_type() {return t_numbermap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "numbermap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_number), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_numbermap e_numbermap = new Class_numbermap();
  public static final Type_numbermap t_numbermap = new Class_numbermap();

  /**
   * type: package
   * A package that store types, consts and funcs.
   * (type package)
   */
  public interface Type_package extends Core.Type_struct {
    public Core.Type_package vx_new(final Object... vals);
    public Core.Type_package vx_copy(final Object... vals);
    public Core.Type_package vx_empty();
    public Core.Type_package vx_type();
    public Core.Type_string pkgname();
    public Core.Type_constmap constmap();
    public Core.Type_funcmap funcmap();
    public Core.Type_typemap typemap();
    public Core.Type_map emptymap();
  }

  public static class Class_package extends Core.Class_base implements Type_package {

    protected Core.Type_string vx_p_pkgname;

    @Override
    public Core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? Core.e_string : this.vx_p_pkgname;
    }

    protected Core.Type_constmap vx_p_constmap;

    @Override
    public Core.Type_constmap constmap() {
      return this.vx_p_constmap == null ? Core.e_constmap : this.vx_p_constmap;
    }

    protected Core.Type_funcmap vx_p_funcmap;

    @Override
    public Core.Type_funcmap funcmap() {
      return this.vx_p_funcmap == null ? Core.e_funcmap : this.vx_p_funcmap;
    }

    protected Core.Type_typemap vx_p_typemap;

    @Override
    public Core.Type_typemap typemap() {
      return this.vx_p_typemap == null ? Core.e_typemap : this.vx_p_typemap;
    }

    protected Core.Type_map vx_p_emptymap;

    @Override
    public Core.Type_map emptymap() {
      return this.vx_p_emptymap == null ? Core.e_map : this.vx_p_emptymap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pkgname":
        output = this.pkgname();
        break;
      case ":constmap":
        output = this.constmap();
        break;
      case ":funcmap":
        output = this.funcmap();
        break;
      case ":typemap":
        output = this.typemap();
        break;
      case ":emptymap":
        output = this.emptymap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":typemap", this.typemap());
      output.put(":emptymap", this.emptymap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_package vx_new(final Object... vals) {return e_package.vx_copy(vals);}

    @Override
    public Type_package vx_copy(final Object... vals) {
      Type_package output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_package val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_pkgname = val.pkgname();
      Core.Type_constmap vx_p_constmap = val.constmap();
      Core.Type_funcmap vx_p_funcmap = val.funcmap();
      Core.Type_typemap vx_p_typemap = val.typemap();
      Core.Type_map vx_p_emptymap = val.emptymap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":constmap");
      validkeys.add(":funcmap");
      validkeys.add(":typemap");
      validkeys.add(":emptymap");
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
            Core.Type_msg msg = Core.vx_msg_error("(new package) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_pkgname = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new package :pkgname " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub instanceof Core.Type_constmap) {
              ischanged = true;
              vx_p_constmap = (Core.Type_constmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new package :constmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub instanceof Core.Type_funcmap) {
              ischanged = true;
              vx_p_funcmap = (Core.Type_funcmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new package :funcmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub instanceof Core.Type_typemap) {
              ischanged = true;
              vx_p_typemap = (Core.Type_typemap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new package :typemap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":emptymap":
            if (valsub == vx_p_emptymap) {
            } else if (valsub instanceof Core.Type_map) {
              ischanged = true;
              vx_p_emptymap = (Core.Type_map)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new package :emptymap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new package) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_package work = new Class_package();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_typemap = vx_p_typemap;
        work.vx_p_emptymap = vx_p_emptymap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_package vx_empty() {return e_package;}
    @Override
    public Type_package vx_type() {return t_package;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "package", // name
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

  public static final Type_package e_package = new Class_package();
  public static final Type_package t_package = new Class_package();

  /**
   * type: packagemap
   * (type packagemap)
   */
  public interface Type_packagemap extends Core.Type_map {
    public Core.Type_packagemap vx_new(final Object... vals);
    public Core.Type_packagemap vx_copy(final Object... vals);
    public Core.Type_packagemap vx_empty();
    public Core.Type_packagemap vx_type();
    public Map<String, Core.Type_package> vx_mappackage();
    public Core.Type_package vx_package(final Core.Type_string key);
  }

  public static class Class_packagemap extends Core.Class_base implements Type_packagemap {

    protected Map<String, Core.Type_package> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_package>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_package vx_package(final Core.Type_string key) {
      Core.Type_package output = Core.e_package;
      Class_packagemap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_package> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_package);
      return output;
    }

    @Override
    public Map<String, Core.Type_package> vx_mappackage() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_package(key);
    }

    @Override
    public Type_packagemap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_packagemap output = new Class_packagemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_package> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_package) {
          Core.Type_package castval = (Core.Type_package)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(packagemap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_packagemap vx_new(final Object... vals) {return e_packagemap.vx_copy(vals);}

    @Override
    public Type_packagemap vx_copy(final Object... vals) {
      Type_packagemap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_packagemap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_package> mapval = new LinkedHashMap<>(valmap.vx_mappackage());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_package valany = null;
          if (valsub instanceof Core.Type_package) {
            valany = (Core.Type_package)valsub;
          } else if (valsub instanceof Core.Type_package) {
            valany = (Core.Type_package)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_packagemap work = new Class_packagemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_packagemap vx_empty() {return e_packagemap;}
    @Override
    public Type_packagemap vx_type() {return t_packagemap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "packagemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_package), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_packagemap e_packagemap = new Class_packagemap();
  public static final Type_packagemap t_packagemap = new Class_packagemap();

  /**
   * type: permission
   * Permission
   * (type permission)
   */
  public interface Type_permission extends Core.Type_struct {
    public Core.Type_permission vx_new(final Object... vals);
    public Core.Type_permission vx_copy(final Object... vals);
    public Core.Type_permission vx_empty();
    public Core.Type_permission vx_type();
    public Core.Type_string id();
  }

  public static class Class_permission extends Core.Class_base implements Type_permission {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      return Core.immutablemap(output);
    }

    @Override
    public Type_permission vx_new(final Object... vals) {return e_permission.vx_copy(vals);}

    @Override
    public Type_permission vx_copy(final Object... vals) {
      Type_permission output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_permission val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_id = val.id();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
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
            Core.Type_msg msg = Core.vx_msg_error("(new permission) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new permission :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new permission) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_permission work = new Class_permission();
        work.vx_p_id = vx_p_id;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_permission vx_empty() {return e_permission;}
    @Override
    public Type_permission vx_type() {return t_permission;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "permission", // name
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

  public static final Type_permission e_permission = new Class_permission();
  public static final Type_permission t_permission = new Class_permission();

  /**
   * type: permissionlist
   * List of Permission
   * (type permissionlist)
   */
  public interface Type_permissionlist extends Core.Type_list {
    public Core.Type_permissionlist vx_new(final Object... vals);
    public Core.Type_permissionlist vx_copy(final Object... vals);
    public Core.Type_permissionlist vx_empty();
    public Core.Type_permissionlist vx_type();
    public List<Core.Type_permission> vx_listpermission();
    public Core.Type_permission vx_permission(final Core.Type_int index);
  }

  public static class Class_permissionlist extends Core.Class_base implements Type_permissionlist {

    protected List<Core.Type_permission> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_permission>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_permission vx_permission(final Core.Type_int index) {
      Core.Type_permission output = Core.e_permission;
      Class_permissionlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_permission> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_permission> vx_listpermission() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_permission(index);
    }

    @Override
    public Type_permissionlist vx_new(final Object... vals) {return e_permissionlist.vx_copy(vals);}

    @Override
    public Type_permissionlist vx_copy(final Object... vals) {
      Type_permissionlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_permissionlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_permission> listval = new ArrayList<>(val.vx_listpermission());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_permission) {
          ischanged = true;
          listval.add((Core.Type_permission)valsub);
        } else if (valsub instanceof Core.Type_permission) {
          ischanged = true;
          listval.add((Core.Type_permission)valsub);
        } else if (valsub instanceof Type_permissionlist) {
          Type_permissionlist multi = (Type_permissionlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listpermission());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_permission) {
              Core.Type_permission valitem = (Core.Type_permission)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new permissionlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_permissionlist work = new Class_permissionlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_permissionlist vx_empty() {return e_permissionlist;}
    @Override
    public Type_permissionlist vx_type() {return t_permissionlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "permissionlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_permission), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_permissionlist e_permissionlist = new Class_permissionlist();
  public static final Type_permissionlist t_permissionlist = new Class_permissionlist();

  /**
   * type: permissionmap
   * Map of Permission
   * (type permissionmap)
   */
  public interface Type_permissionmap extends Core.Type_map {
    public Core.Type_permissionmap vx_new(final Object... vals);
    public Core.Type_permissionmap vx_copy(final Object... vals);
    public Core.Type_permissionmap vx_empty();
    public Core.Type_permissionmap vx_type();
    public Map<String, Core.Type_permission> vx_mappermission();
    public Core.Type_permission vx_permission(final Core.Type_string key);
  }

  public static class Class_permissionmap extends Core.Class_base implements Type_permissionmap {

    protected Map<String, Core.Type_permission> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_permission>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_permission vx_permission(final Core.Type_string key) {
      Core.Type_permission output = Core.e_permission;
      Class_permissionmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_permission> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_permission);
      return output;
    }

    @Override
    public Map<String, Core.Type_permission> vx_mappermission() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_permission(key);
    }

    @Override
    public Type_permissionmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_permissionmap output = new Class_permissionmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_permission> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_permission) {
          Core.Type_permission castval = (Core.Type_permission)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(permissionmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_permissionmap vx_new(final Object... vals) {return e_permissionmap.vx_copy(vals);}

    @Override
    public Type_permissionmap vx_copy(final Object... vals) {
      Type_permissionmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_permissionmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_permission> mapval = new LinkedHashMap<>(valmap.vx_mappermission());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_permission valany = null;
          if (valsub instanceof Core.Type_permission) {
            valany = (Core.Type_permission)valsub;
          } else if (valsub instanceof Core.Type_permission) {
            valany = (Core.Type_permission)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_permissionmap work = new Class_permissionmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_permissionmap vx_empty() {return e_permissionmap;}
    @Override
    public Type_permissionmap vx_type() {return t_permissionmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "permissionmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_permission), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_permissionmap e_permissionmap = new Class_permissionmap();
  public static final Type_permissionmap t_permissionmap = new Class_permissionmap();

  /**
   * type: project
   * A project.
   * (type project)
   */
  public interface Type_project extends Core.Type_struct {
    public Core.Type_project vx_new(final Object... vals);
    public Core.Type_project vx_copy(final Object... vals);
    public Core.Type_project vx_empty();
    public Core.Type_project vx_type();
    public Core.Type_packagemap packagemap();
  }

  public static class Class_project extends Core.Class_base implements Type_project {

    protected Core.Type_packagemap vx_p_packagemap;

    @Override
    public Core.Type_packagemap packagemap() {
      return this.vx_p_packagemap == null ? Core.e_packagemap : this.vx_p_packagemap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":packagemap":
        output = this.packagemap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":packagemap", this.packagemap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_project vx_new(final Object... vals) {return e_project.vx_copy(vals);}

    @Override
    public Type_project vx_copy(final Object... vals) {
      Type_project output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_project val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_packagemap vx_p_packagemap = val.packagemap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":packagemap");
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
            Core.Type_msg msg = Core.vx_msg_error("(new project) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":packagemap":
            if (valsub == vx_p_packagemap) {
            } else if (valsub instanceof Core.Type_packagemap) {
              ischanged = true;
              vx_p_packagemap = (Core.Type_packagemap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new project :packagemap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new project) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_project work = new Class_project();
        work.vx_p_packagemap = vx_p_packagemap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_project vx_empty() {return e_project;}
    @Override
    public Type_project vx_type() {return t_project;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "project", // name
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

  public static final Type_project e_project = new Class_project();
  public static final Type_project t_project = new Class_project();

  /**
   * type: security
   * Security rules
   * (type security)
   */
  public interface Type_security extends Core.Type_struct {
    public Core.Type_security vx_new(final Object... vals);
    public Core.Type_security vx_copy(final Object... vals);
    public Core.Type_security vx_empty();
    public Core.Type_security vx_type();
    public Core.Type_funclist allowfuncs();
    public Core.Type_permissionlist permissions();
    public Core.Type_permissionmap permissionmap();
  }

  public static class Class_security extends Core.Class_base implements Type_security {

    protected Core.Type_funclist vx_p_allowfuncs;

    @Override
    public Core.Type_funclist allowfuncs() {
      return this.vx_p_allowfuncs == null ? Core.e_funclist : this.vx_p_allowfuncs;
    }

    protected Core.Type_permissionlist vx_p_permissions;

    @Override
    public Core.Type_permissionlist permissions() {
      return this.vx_p_permissions == null ? Core.e_permissionlist : this.vx_p_permissions;
    }

    protected Core.Type_permissionmap vx_p_permissionmap;

    @Override
    public Core.Type_permissionmap permissionmap() {
      return this.vx_p_permissionmap == null ? Core.e_permissionmap : this.vx_p_permissionmap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":allowfuncs":
        output = this.allowfuncs();
        break;
      case ":permissions":
        output = this.permissions();
        break;
      case ":permissionmap":
        output = this.permissionmap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":allowfuncs", this.allowfuncs());
      output.put(":permissions", this.permissions());
      output.put(":permissionmap", this.permissionmap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_security vx_new(final Object... vals) {return e_security.vx_copy(vals);}

    @Override
    public Type_security vx_copy(final Object... vals) {
      Type_security output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_security val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      Core.Type_permissionlist vx_p_permissions = val.permissions();
      Core.Type_permissionmap vx_p_permissionmap = val.permissionmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":allowfuncs");
      validkeys.add(":permissions");
      validkeys.add(":permissionmap");
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
            Core.Type_msg msg = Core.vx_msg_error("(new security) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub instanceof Core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (Core.Type_funclist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new security :allowfuncs " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":permissions":
            if (valsub == vx_p_permissions) {
            } else if (valsub instanceof Core.Type_permissionlist) {
              ischanged = true;
              vx_p_permissions = (Core.Type_permissionlist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new security :permissions " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":permissionmap":
            if (valsub == vx_p_permissionmap) {
            } else if (valsub instanceof Core.Type_permissionmap) {
              ischanged = true;
              vx_p_permissionmap = (Core.Type_permissionmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new security :permissionmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new security) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_security work = new Class_security();
        work.vx_p_allowfuncs = vx_p_allowfuncs;
        work.vx_p_permissions = vx_p_permissions;
        work.vx_p_permissionmap = vx_p_permissionmap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_security vx_empty() {return e_security;}
    @Override
    public Type_security vx_type() {return t_security;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "security", // name
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

  public static final Type_security e_security = new Class_security();
  public static final Type_security t_security = new Class_security();

  /**
   * type: session
   * Session
   * (type session)
   */
  public interface Type_session extends Core.Type_struct {
    public Core.Type_session vx_new(final Object... vals);
    public Core.Type_session vx_copy(final Object... vals);
    public Core.Type_session vx_empty();
    public Core.Type_session vx_type();
    public Core.Type_user user();
    public Core.Type_connectlist connectlist();
    public Core.Type_connectmap connectmap();
  }

  public static class Class_session extends Core.Class_base implements Type_session {

    protected Core.Type_user vx_p_user;

    @Override
    public Core.Type_user user() {
      return this.vx_p_user == null ? Core.e_user : this.vx_p_user;
    }

    protected Core.Type_connectlist vx_p_connectlist;

    @Override
    public Core.Type_connectlist connectlist() {
      return this.vx_p_connectlist == null ? Core.e_connectlist : this.vx_p_connectlist;
    }

    protected Core.Type_connectmap vx_p_connectmap;

    @Override
    public Core.Type_connectmap connectmap() {
      return this.vx_p_connectmap == null ? Core.e_connectmap : this.vx_p_connectmap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":user":
        output = this.user();
        break;
      case ":connectlist":
        output = this.connectlist();
        break;
      case ":connectmap":
        output = this.connectmap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":user", this.user());
      output.put(":connectlist", this.connectlist());
      output.put(":connectmap", this.connectmap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_session vx_new(final Object... vals) {return e_session.vx_copy(vals);}

    @Override
    public Type_session vx_copy(final Object... vals) {
      Type_session output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_session val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_user vx_p_user = val.user();
      Core.Type_connectlist vx_p_connectlist = val.connectlist();
      Core.Type_connectmap vx_p_connectmap = val.connectmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":user");
      validkeys.add(":connectlist");
      validkeys.add(":connectmap");
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
            Core.Type_msg msg = Core.vx_msg_error("(new session) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":user":
            if (valsub == vx_p_user) {
            } else if (valsub instanceof Core.Type_user) {
              ischanged = true;
              vx_p_user = (Core.Type_user)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new session :user " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":connectlist":
            if (valsub == vx_p_connectlist) {
            } else if (valsub instanceof Core.Type_connectlist) {
              ischanged = true;
              vx_p_connectlist = (Core.Type_connectlist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new session :connectlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":connectmap":
            if (valsub == vx_p_connectmap) {
            } else if (valsub instanceof Core.Type_connectmap) {
              ischanged = true;
              vx_p_connectmap = (Core.Type_connectmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new session :connectmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new session) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_session work = new Class_session();
        work.vx_p_user = vx_p_user;
        work.vx_p_connectlist = vx_p_connectlist;
        work.vx_p_connectmap = vx_p_connectmap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_session vx_empty() {return e_session;}
    @Override
    public Type_session vx_type() {return t_session;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "session", // name
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

  public static final Type_session e_session = new Class_session();
  public static final Type_session t_session = new Class_session();

  /**
   * type: setting
   * Settings
   * (type setting)
   */
  public interface Type_setting extends Core.Type_struct {
    public Core.Type_setting vx_new(final Object... vals);
    public Core.Type_setting vx_copy(final Object... vals);
    public Core.Type_setting vx_empty();
    public Core.Type_setting vx_type();
    public Core.Type_stringmap pathmap();
  }

  public static class Class_setting extends Core.Class_base implements Type_setting {

    protected Core.Type_stringmap vx_p_pathmap;

    @Override
    public Core.Type_stringmap pathmap() {
      return this.vx_p_pathmap == null ? Core.e_stringmap : this.vx_p_pathmap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pathmap":
        output = this.pathmap();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pathmap", this.pathmap());
      return Core.immutablemap(output);
    }

    @Override
    public Type_setting vx_new(final Object... vals) {return e_setting.vx_copy(vals);}

    @Override
    public Type_setting vx_copy(final Object... vals) {
      Type_setting output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_setting val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_stringmap vx_p_pathmap = val.pathmap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pathmap");
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
            Core.Type_msg msg = Core.vx_msg_error("(new setting) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pathmap":
            if (valsub == vx_p_pathmap) {
            } else if (valsub instanceof Core.Type_stringmap) {
              ischanged = true;
              vx_p_pathmap = (Core.Type_stringmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new setting :pathmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new setting) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_setting work = new Class_setting();
        work.vx_p_pathmap = vx_p_pathmap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_setting vx_empty() {return e_setting;}
    @Override
    public Type_setting vx_type() {return t_setting;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "setting", // name
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

  public static final Type_setting e_setting = new Class_setting();
  public static final Type_setting t_setting = new Class_setting();

  /**
   * type: state
   * (type state)
   */
  public interface Type_state extends Core.Type_map {
    public Core.Type_state vx_new(final Object... vals);
    public Core.Type_state vx_copy(final Object... vals);
    public Core.Type_state vx_empty();
    public Core.Type_state vx_type();
    public Map<String, Core.Type_statelistener> vx_mapstatelistener();
    public Core.Type_statelistener vx_statelistener(final Core.Type_string key);
  }

  public static class Class_state extends Core.Class_base implements Type_state {

    protected Map<String, Core.Type_statelistener> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_statelistener>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_statelistener vx_statelistener(final Core.Type_string key) {
      Core.Type_statelistener output = Core.e_statelistener;
      Class_state map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_statelistener> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_statelistener);
      return output;
    }

    @Override
    public Map<String, Core.Type_statelistener> vx_mapstatelistener() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_statelistener(key);
    }

    @Override
    public Type_state vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_state output = new Class_state();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_statelistener> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_statelistener) {
          Core.Type_statelistener castval = (Core.Type_statelistener)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(state) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_state vx_new(final Object... vals) {return e_state.vx_copy(vals);}

    @Override
    public Type_state vx_copy(final Object... vals) {
      Type_state output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_state valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_statelistener> mapval = new LinkedHashMap<>(valmap.vx_mapstatelistener());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_statelistener valany = null;
          if (valsub instanceof Core.Type_statelistener) {
            valany = (Core.Type_statelistener)valsub;
          } else if (valsub instanceof Core.Type_statelistener) {
            valany = (Core.Type_statelistener)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_state work = new Class_state();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_state vx_empty() {return e_state;}
    @Override
    public Type_state vx_type() {return t_state;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "state", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_statelistener), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_state e_state = new Class_state();
  public static final Type_state t_state = new Class_state();

  /**
   * type: statelistener
   * (type statelistener)
   */
  public interface Type_statelistener extends Core.Type_struct {
    public Core.Type_statelistener vx_new(final Object... vals);
    public Core.Type_statelistener vx_copy(final Object... vals);
    public Core.Type_statelistener vx_empty();
    public Core.Type_statelistener vx_type();
    public Core.Type_string path();
    public Core.Type_any value();
    public Core.Func_boolean_from_none fn_boolean();
  }

  public static class Class_statelistener extends Core.Class_base implements Type_statelistener {

    protected Core.Type_string vx_p_path;

    @Override
    public Core.Type_string path() {
      return this.vx_p_path == null ? Core.e_string : this.vx_p_path;
    }

    protected Core.Type_any vx_p_value;

    @Override
    public Core.Type_any value() {
      return this.vx_p_value == null ? Core.e_any : this.vx_p_value;
    }

    protected Core.Func_boolean_from_none vx_p_fn_boolean;

    @Override
    public Core.Func_boolean_from_none fn_boolean() {
      return this.vx_p_fn_boolean == null ? Core.e_boolean_from_none : this.vx_p_fn_boolean;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":path":
        output = this.path();
        break;
      case ":value":
        output = this.value();
        break;
      case ":fn-boolean":
        output = this.fn_boolean();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":path", this.path());
      output.put(":value", this.value());
      output.put(":fn-boolean", this.fn_boolean());
      return Core.immutablemap(output);
    }

    @Override
    public Type_statelistener vx_new(final Object... vals) {return e_statelistener.vx_copy(vals);}

    @Override
    public Type_statelistener vx_copy(final Object... vals) {
      Type_statelistener output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_statelistener val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_path = val.path();
      Core.Type_any vx_p_value = val.value();
      Core.Func_boolean_from_none vx_p_fn_boolean = val.fn_boolean();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":path");
      validkeys.add(":value");
      validkeys.add(":fn-boolean");
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
            Core.Type_msg msg = Core.vx_msg_error("(new statelistener) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":path":
            if (valsub == vx_p_path) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_path = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_path = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new statelistener :path " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_value = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new statelistener :value " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-boolean":
            if (valsub == vx_p_fn_boolean) {
            } else if (valsub instanceof Core.Func_boolean_from_none) {
              ischanged = true;
              vx_p_fn_boolean = (Core.Func_boolean_from_none)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new statelistener :fn-boolean " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new statelistener) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_statelistener work = new Class_statelistener();
        work.vx_p_path = vx_p_path;
        work.vx_p_value = vx_p_value;
        work.vx_p_fn_boolean = vx_p_fn_boolean;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_statelistener vx_empty() {return e_statelistener;}
    @Override
    public Type_statelistener vx_type() {return t_statelistener;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "statelistener", // name
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

  public static final Type_statelistener e_statelistener = new Class_statelistener();
  public static final Type_statelistener t_statelistener = new Class_statelistener();

  /**
   * type: string
   * A simple string.
   * (type string)
   */
  public interface Type_string extends Core.Type_any {
    public Core.Type_string vx_new(final Object... vals);
    public Core.Type_string vx_copy(final Object... vals);
    public Core.Type_string vx_empty();
    public Core.Type_string vx_type();
    public String vx_string();
  }

  public static class Class_string extends Core.Class_base implements Type_string {

    protected String vxstring = "";
    
    @Override
    public String vx_string() {
      return vxstring;
    }

    @Override
    public Type_string vx_new(final Object... vals) {return e_string.vx_copy(vals);}

    @Override
    public Type_string vx_copy(final Object... vals) {
      Type_string output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Class_string val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      StringBuilder sb = new StringBuilder(val.vx_string());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_string) {
          Core.Type_string valstring = (Core.Type_string)valsub;
          String ssub = valstring.vx_string();
          if (!ssub.equals("")) {
            ischanged = true;
            sb.append(ssub);
          }
        } else if (valsub instanceof Core.Type_int) {
          Core.Type_int valint = (Core.Type_int)valsub;
          ischanged = true;
          sb.append(valint.vx_int());
        } else if (valsub instanceof Core.Type_float) {
          Core.Type_float valfloat = (Core.Type_float)valsub;
          ischanged = true;
          sb.append(valfloat.vx_float());
        } else if (valsub instanceof Core.Type_decimal) {
          Core.Type_decimal valdecimal = (Core.Type_decimal)valsub;
          ischanged = true;
          sb.append(valdecimal.vx_string());
        } else if (valsub instanceof String) {
          String ssub2 = (String)valsub;
          if (!ssub2.equals("")) {
            ischanged = true;
            sb.append(ssub2);
          }
        } else if (valsub instanceof Integer) {
          ischanged = true;
          sb.append((Integer)valsub);
        } else if (valsub instanceof Float) {
          ischanged = true;
          sb.append((Float)valsub);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new string) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        String vxstring = sb.toString();
        Class_string work = new Class_string();
        work.vxstring = vxstring;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_string vx_empty() {return e_string;}
    @Override
    public Type_string vx_type() {return t_string;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
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
      );
    }

  }

  public static final Type_string e_string = new Class_string();
  public static final Type_string t_string = new Class_string();

  /**
   * type: stringlist
   * A list of string.
   * (type stringlist)
   */
  public interface Type_stringlist extends Core.Type_list {
    public Core.Type_stringlist vx_new(final Object... vals);
    public Core.Type_stringlist vx_copy(final Object... vals);
    public Core.Type_stringlist vx_empty();
    public Core.Type_stringlist vx_type();
    public List<Core.Type_string> vx_liststring();
    public Core.Type_string vx_string(final Core.Type_int index);
  }

  public static class Class_stringlist extends Core.Class_base implements Type_stringlist {

    protected List<Core.Type_string> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_string>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_string vx_string(final Core.Type_int index) {
      Core.Type_string output = Core.e_string;
      Class_stringlist list = this;
      int iindex = index.vx_int();
      List<Core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_string> vx_liststring() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_string(index);
    }

    @Override
    public Type_stringlist vx_new(final Object... vals) {return e_stringlist.vx_copy(vals);}

    @Override
    public Type_stringlist vx_copy(final Object... vals) {
      Type_stringlist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_stringlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_string> listval = new ArrayList<>(val.vx_liststring());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_string) {
          ischanged = true;
          listval.add((Core.Type_string)valsub);
        } else if (valsub instanceof String) {
          ischanged = true;
          listval.add(Core.t_string.vx_new(valsub));
        } else if (valsub instanceof Type_stringlist) {
          Type_stringlist multi = (Type_stringlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststring());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_string) {
              Core.Type_string valitem = (Core.Type_string)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new stringlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_stringlist work = new Class_stringlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_stringlist vx_empty() {return e_stringlist;}
    @Override
    public Type_stringlist vx_type() {return t_stringlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_string), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_stringlist e_stringlist = new Class_stringlist();
  public static final Type_stringlist t_stringlist = new Class_stringlist();

  /**
   * type: stringmap
   * A map of string.
   * (type stringmap)
   */
  public interface Type_stringmap extends Core.Type_map {
    public Core.Type_stringmap vx_new(final Object... vals);
    public Core.Type_stringmap vx_copy(final Object... vals);
    public Core.Type_stringmap vx_empty();
    public Core.Type_stringmap vx_type();
    public Map<String, Core.Type_string> vx_mapstring();
    public Core.Type_string vx_string(final Core.Type_string key);
  }

  public static class Class_stringmap extends Core.Class_base implements Type_stringmap {

    protected Map<String, Core.Type_string> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_string>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_string vx_string(final Core.Type_string key) {
      Core.Type_string output = Core.e_string;
      Class_stringmap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_string> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_string);
      return output;
    }

    @Override
    public Map<String, Core.Type_string> vx_mapstring() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_string(key);
    }

    @Override
    public Type_stringmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_stringmap output = new Class_stringmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_string> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_string) {
          Core.Type_string castval = (Core.Type_string)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(stringmap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_stringmap vx_new(final Object... vals) {return e_stringmap.vx_copy(vals);}

    @Override
    public Type_stringmap vx_copy(final Object... vals) {
      Type_stringmap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_stringmap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_string> mapval = new LinkedHashMap<>(valmap.vx_mapstring());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_string valany = null;
          if (valsub instanceof Core.Type_string) {
            valany = (Core.Type_string)valsub;
          } else if (valsub instanceof String) {
            valany = Core.t_string.vx_new(valsub);;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_stringmap work = new Class_stringmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_stringmap vx_empty() {return e_stringmap;}
    @Override
    public Type_stringmap vx_type() {return t_stringmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "stringmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_string), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_stringmap e_stringmap = new Class_stringmap();
  public static final Type_stringmap t_stringmap = new Class_stringmap();

  /**
   * type: struct
   * Struct is the type of all structures/objects with properties.
   * (type struct)
   */
  public interface Type_struct extends Core.Type_any {
    public Core.Type_struct vx_new(final Object... vals);
    public Core.Type_struct vx_copy(final Object... vals);
    public Core.Type_struct vx_empty();
    public Core.Type_struct vx_type();
    public Core.Type_any vx_any(final Core.Type_string key);
    public Map<String, Core.Type_any> vx_map();
  }

  public static class Class_struct extends Core.Class_base implements Type_struct {

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      return Core.immutablemap(output);
    }

    @Override
    public Type_struct vx_new(final Object... vals) {return e_struct.vx_copy(vals);}

    @Override
    public Type_struct vx_copy(final Object... vals) {
      Type_struct output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_struct val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (msgblock != Core.e_msgblock) {
        Class_struct work = new Class_struct();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_struct vx_empty() {return e_struct;}
    @Override
    public Type_struct vx_type() {return t_struct;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "struct", // name
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

  public static final Type_struct e_struct = new Class_struct();
  public static final Type_struct t_struct = new Class_struct();

  /**
   * type: thenelse
   * (type thenelse)
   */
  public interface Type_thenelse extends Core.Type_struct {
    public Core.Type_thenelse vx_new(final Object... vals);
    public Core.Type_thenelse vx_copy(final Object... vals);
    public Core.Type_thenelse vx_empty();
    public Core.Type_thenelse vx_type();
    public Core.Type_string code();
    public Core.Type_any value();
    public Core.Type_list values();
    public Core.Func_boolean_from_func fn_cond();
    public Core.Func_any_from_func fn_any();
  }

  public static class Class_thenelse extends Core.Class_base implements Type_thenelse {

    protected Core.Type_string vx_p_code;

    @Override
    public Core.Type_string code() {
      return this.vx_p_code == null ? Core.e_string : this.vx_p_code;
    }

    protected Core.Type_any vx_p_value;

    @Override
    public Core.Type_any value() {
      return this.vx_p_value == null ? Core.e_any : this.vx_p_value;
    }

    protected Core.Type_list vx_p_values;

    @Override
    public Core.Type_list values() {
      return this.vx_p_values == null ? Core.e_list : this.vx_p_values;
    }

    protected Core.Func_boolean_from_func vx_p_fn_cond;

    @Override
    public Core.Func_boolean_from_func fn_cond() {
      return this.vx_p_fn_cond == null ? Core.e_boolean_from_func : this.vx_p_fn_cond;
    }

    protected Core.Func_any_from_func vx_p_fn_any;

    @Override
    public Core.Func_any_from_func fn_any() {
      return this.vx_p_fn_any == null ? Core.e_any_from_func : this.vx_p_fn_any;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":code":
        output = this.code();
        break;
      case ":value":
        output = this.value();
        break;
      case ":values":
        output = this.values();
        break;
      case ":fn-cond":
        output = this.fn_cond();
        break;
      case ":fn-any":
        output = this.fn_any();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":value", this.value());
      output.put(":values", this.values());
      output.put(":fn-cond", this.fn_cond());
      output.put(":fn-any", this.fn_any());
      return Core.immutablemap(output);
    }

    @Override
    public Type_thenelse vx_new(final Object... vals) {return e_thenelse.vx_copy(vals);}

    @Override
    public Type_thenelse vx_copy(final Object... vals) {
      Type_thenelse output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_thenelse val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_code = val.code();
      Core.Type_any vx_p_value = val.value();
      Core.Type_list vx_p_values = val.values();
      Core.Func_boolean_from_func vx_p_fn_cond = val.fn_cond();
      Core.Func_any_from_func vx_p_fn_any = val.fn_any();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":value");
      validkeys.add(":values");
      validkeys.add(":fn-cond");
      validkeys.add(":fn-any");
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
            Core.Type_msg msg = Core.vx_msg_error("(new thenelse) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_code = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_code = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new thenelse :code " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_value = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new thenelse :value " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":values":
            if (valsub == vx_p_values) {
            } else if (valsub instanceof Core.Type_list) {
              ischanged = true;
              vx_p_values = (Core.Type_list)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new thenelse :values " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-cond":
            if (valsub == vx_p_fn_cond) {
            } else if (valsub instanceof Core.Func_boolean_from_func) {
              ischanged = true;
              vx_p_fn_cond = (Core.Func_boolean_from_func)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new thenelse :fn-cond " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-any":
            if (valsub == vx_p_fn_any) {
            } else if (valsub instanceof Core.Func_any_from_func) {
              ischanged = true;
              vx_p_fn_any = (Core.Func_any_from_func)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new thenelse :fn-any " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new thenelse) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_thenelse work = new Class_thenelse();
        work.vx_p_code = vx_p_code;
        work.vx_p_value = vx_p_value;
        work.vx_p_values = vx_p_values;
        work.vx_p_fn_cond = vx_p_fn_cond;
        work.vx_p_fn_any = vx_p_fn_any;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_thenelse vx_empty() {return e_thenelse;}
    @Override
    public Type_thenelse vx_type() {return t_thenelse;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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

  public static final Type_thenelse e_thenelse = new Class_thenelse();
  public static final Type_thenelse t_thenelse = new Class_thenelse();

  /**
   * type: thenelselist
   * (type thenelselist)
   */
  public interface Type_thenelselist extends Core.Type_list {
    public Core.Type_thenelselist vx_new(final Object... vals);
    public Core.Type_thenelselist vx_copy(final Object... vals);
    public Core.Type_thenelselist vx_empty();
    public Core.Type_thenelselist vx_type();
    public List<Core.Type_thenelse> vx_listthenelse();
    public Core.Type_thenelse vx_thenelse(final Core.Type_int index);
  }

  public static class Class_thenelselist extends Core.Class_base implements Type_thenelselist {

    protected List<Core.Type_thenelse> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_thenelse>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_thenelse vx_thenelse(final Core.Type_int index) {
      Core.Type_thenelse output = Core.e_thenelse;
      Class_thenelselist list = this;
      int iindex = index.vx_int();
      List<Core.Type_thenelse> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_thenelse> vx_listthenelse() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_thenelse(index);
    }

    @Override
    public Type_thenelselist vx_new(final Object... vals) {return e_thenelselist.vx_copy(vals);}

    @Override
    public Type_thenelselist vx_copy(final Object... vals) {
      Type_thenelselist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_thenelselist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_thenelse> listval = new ArrayList<>(val.vx_listthenelse());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_thenelse) {
          ischanged = true;
          listval.add((Core.Type_thenelse)valsub);
        } else if (valsub instanceof Core.Type_thenelse) {
          ischanged = true;
          listval.add((Core.Type_thenelse)valsub);
        } else if (valsub instanceof Type_thenelselist) {
          Type_thenelselist multi = (Type_thenelselist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listthenelse());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_thenelse) {
              Core.Type_thenelse valitem = (Core.Type_thenelse)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new thenelselist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_thenelselist work = new Class_thenelselist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_thenelselist vx_empty() {return e_thenelselist;}
    @Override
    public Type_thenelselist vx_type() {return t_thenelselist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "thenelselist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_thenelse), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_thenelselist e_thenelselist = new Class_thenelselist();
  public static final Type_thenelselist t_thenelselist = new Class_thenelselist();

  /**
   * type: type
   * Original Type Class
   * (type type)
   */
  public interface Type_type extends Core.Type_any {
    public Core.Type_type vx_new(final Object... vals);
    public Core.Type_type vx_copy(final Object... vals);
    public Core.Type_type vx_empty();
    public Core.Type_type vx_type();
  }

  public static class Class_type extends Core.Class_base implements Type_type {

    @Override
    public Type_type vx_new(final Object... vals) {return e_type.vx_copy(vals);}

    @Override
    public Type_type vx_copy(final Object... vals) {
      Type_type output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      return output;
    }

    @Override
    public Type_type vx_empty() {return e_type;}
    @Override
    public Type_type vx_type() {return t_type;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "type", // name
        ":type", // extends
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

  public static final Type_type e_type = new Class_type();
  public static final Type_type t_type = new Class_type();

  /**
   * type: typedef
   * Type Definition Class for inspecting Type properties.
   * (type typedef)
   */
  public interface Type_typedef extends Core.Type_struct {
    public Core.Type_typedef vx_new(final Object... vals);
    public Core.Type_typedef vx_copy(final Object... vals);
    public Core.Type_typedef vx_empty();
    public Core.Type_typedef vx_type();
    public Core.Type_string pkgname();
    public Core.Type_string name();
    public Core.Type_string extend();
    public Core.Type_funclist allowfuncs();
    public Core.Type_typelist allowtypes();
    public Core.Type_anylist allowvalues();
    public Core.Type_funclist disallowfuncs();
    public Core.Type_typelist disallowtypes();
    public Core.Type_anylist disallowvalues();
    public Core.Type_argmap properties();
    public Core.Type_arg proplast();
    public Core.Type_typelist traits();
  }

  public static class Class_typedef extends Core.Class_base implements Type_typedef {

    protected Core.Type_string vx_p_pkgname;

    @Override
    public Core.Type_string pkgname() {
      return this.vx_p_pkgname == null ? Core.e_string : this.vx_p_pkgname;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_extend;

    @Override
    public Core.Type_string extend() {
      return this.vx_p_extend == null ? Core.e_string : this.vx_p_extend;
    }

    protected Core.Type_funclist vx_p_allowfuncs;

    @Override
    public Core.Type_funclist allowfuncs() {
      return this.vx_p_allowfuncs == null ? Core.e_funclist : this.vx_p_allowfuncs;
    }

    protected Core.Type_typelist vx_p_allowtypes;

    @Override
    public Core.Type_typelist allowtypes() {
      return this.vx_p_allowtypes == null ? Core.e_typelist : this.vx_p_allowtypes;
    }

    protected Core.Type_anylist vx_p_allowvalues;

    @Override
    public Core.Type_anylist allowvalues() {
      return this.vx_p_allowvalues == null ? Core.e_anylist : this.vx_p_allowvalues;
    }

    protected Core.Type_funclist vx_p_disallowfuncs;

    @Override
    public Core.Type_funclist disallowfuncs() {
      return this.vx_p_disallowfuncs == null ? Core.e_funclist : this.vx_p_disallowfuncs;
    }

    protected Core.Type_typelist vx_p_disallowtypes;

    @Override
    public Core.Type_typelist disallowtypes() {
      return this.vx_p_disallowtypes == null ? Core.e_typelist : this.vx_p_disallowtypes;
    }

    protected Core.Type_anylist vx_p_disallowvalues;

    @Override
    public Core.Type_anylist disallowvalues() {
      return this.vx_p_disallowvalues == null ? Core.e_anylist : this.vx_p_disallowvalues;
    }

    protected Core.Type_argmap vx_p_properties;

    @Override
    public Core.Type_argmap properties() {
      return this.vx_p_properties == null ? Core.e_argmap : this.vx_p_properties;
    }

    protected Core.Type_arg vx_p_proplast;

    @Override
    public Core.Type_arg proplast() {
      return this.vx_p_proplast == null ? Core.e_arg : this.vx_p_proplast;
    }

    protected Core.Type_typelist vx_p_traits;

    @Override
    public Core.Type_typelist traits() {
      return this.vx_p_traits == null ? Core.e_typelist : this.vx_p_traits;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":pkgname":
        output = this.pkgname();
        break;
      case ":name":
        output = this.name();
        break;
      case ":extends":
        output = this.extend();
        break;
      case ":allowfuncs":
        output = this.allowfuncs();
        break;
      case ":allowtypes":
        output = this.allowtypes();
        break;
      case ":allowvalues":
        output = this.allowvalues();
        break;
      case ":disallowfuncs":
        output = this.disallowfuncs();
        break;
      case ":disallowtypes":
        output = this.disallowtypes();
        break;
      case ":disallowvalues":
        output = this.disallowvalues();
        break;
      case ":properties":
        output = this.properties();
        break;
      case ":proplast":
        output = this.proplast();
        break;
      case ":traits":
        output = this.traits();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pkgname", this.pkgname());
      output.put(":name", this.name());
      output.put(":extends", this.extend());
      output.put(":allowfuncs", this.allowfuncs());
      output.put(":allowtypes", this.allowtypes());
      output.put(":allowvalues", this.allowvalues());
      output.put(":disallowfuncs", this.disallowfuncs());
      output.put(":disallowtypes", this.disallowtypes());
      output.put(":disallowvalues", this.disallowvalues());
      output.put(":properties", this.properties());
      output.put(":proplast", this.proplast());
      output.put(":traits", this.traits());
      return Core.immutablemap(output);
    }

    @Override
    public Type_typedef vx_new(final Object... vals) {return e_typedef.vx_copy(vals);}

    @Override
    public Type_typedef vx_copy(final Object... vals) {
      Type_typedef output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_typedef val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_pkgname = val.pkgname();
      Core.Type_string vx_p_name = val.name();
      Core.Type_string vx_p_extend = val.extend();
      Core.Type_funclist vx_p_allowfuncs = val.allowfuncs();
      Core.Type_typelist vx_p_allowtypes = val.allowtypes();
      Core.Type_anylist vx_p_allowvalues = val.allowvalues();
      Core.Type_funclist vx_p_disallowfuncs = val.disallowfuncs();
      Core.Type_typelist vx_p_disallowtypes = val.disallowtypes();
      Core.Type_anylist vx_p_disallowvalues = val.disallowvalues();
      Core.Type_argmap vx_p_properties = val.properties();
      Core.Type_arg vx_p_proplast = val.proplast();
      Core.Type_typelist vx_p_traits = val.traits();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pkgname");
      validkeys.add(":name");
      validkeys.add(":extends");
      validkeys.add(":allowfuncs");
      validkeys.add(":allowtypes");
      validkeys.add(":allowvalues");
      validkeys.add(":disallowfuncs");
      validkeys.add(":disallowtypes");
      validkeys.add(":disallowvalues");
      validkeys.add(":properties");
      validkeys.add(":proplast");
      validkeys.add(":traits");
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
            Core.Type_msg msg = Core.vx_msg_error("(new typedef) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pkgname":
            if (valsub == vx_p_pkgname) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_pkgname = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_pkgname = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :pkgname " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":extends":
            if (valsub == vx_p_extend) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_extend = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_extend = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :extends " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":allowfuncs":
            if (valsub == vx_p_allowfuncs) {
            } else if (valsub instanceof Core.Type_funclist) {
              ischanged = true;
              vx_p_allowfuncs = (Core.Type_funclist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :allowfuncs " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":allowtypes":
            if (valsub == vx_p_allowtypes) {
            } else if (valsub instanceof Core.Type_typelist) {
              ischanged = true;
              vx_p_allowtypes = (Core.Type_typelist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :allowtypes " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":allowvalues":
            if (valsub == vx_p_allowvalues) {
            } else if (valsub instanceof Core.Type_anylist) {
              ischanged = true;
              vx_p_allowvalues = (Core.Type_anylist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :allowvalues " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":disallowfuncs":
            if (valsub == vx_p_disallowfuncs) {
            } else if (valsub instanceof Core.Type_funclist) {
              ischanged = true;
              vx_p_disallowfuncs = (Core.Type_funclist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :disallowfuncs " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":disallowtypes":
            if (valsub == vx_p_disallowtypes) {
            } else if (valsub instanceof Core.Type_typelist) {
              ischanged = true;
              vx_p_disallowtypes = (Core.Type_typelist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :disallowtypes " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":disallowvalues":
            if (valsub == vx_p_disallowvalues) {
            } else if (valsub instanceof Core.Type_anylist) {
              ischanged = true;
              vx_p_disallowvalues = (Core.Type_anylist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :disallowvalues " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":properties":
            if (valsub == vx_p_properties) {
            } else if (valsub instanceof Core.Type_argmap) {
              ischanged = true;
              vx_p_properties = (Core.Type_argmap)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :properties " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":proplast":
            if (valsub == vx_p_proplast) {
            } else if (valsub instanceof Core.Type_arg) {
              ischanged = true;
              vx_p_proplast = (Core.Type_arg)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :proplast " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":traits":
            if (valsub == vx_p_traits) {
            } else if (valsub instanceof Core.Type_typelist) {
              ischanged = true;
              vx_p_traits = (Core.Type_typelist)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new typedef :traits " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new typedef) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_typedef work = new Class_typedef();
        work.vx_p_pkgname = vx_p_pkgname;
        work.vx_p_name = vx_p_name;
        work.vx_p_extend = vx_p_extend;
        work.vx_p_allowfuncs = vx_p_allowfuncs;
        work.vx_p_allowtypes = vx_p_allowtypes;
        work.vx_p_allowvalues = vx_p_allowvalues;
        work.vx_p_disallowfuncs = vx_p_disallowfuncs;
        work.vx_p_disallowtypes = vx_p_disallowtypes;
        work.vx_p_disallowvalues = vx_p_disallowvalues;
        work.vx_p_properties = vx_p_properties;
        work.vx_p_proplast = vx_p_proplast;
        work.vx_p_traits = vx_p_traits;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_typedef vx_empty() {return e_typedef;}
    @Override
    public Type_typedef vx_type() {return t_typedef;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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

  public static final Type_typedef e_typedef = new Class_typedef();
  public static final Type_typedef t_typedef = new Class_typedef();

  /**
   * type: typelist
   * List of Types
   * (type typelist)
   */
  public interface Type_typelist extends Core.Type_list {
    public Core.Type_typelist vx_new(final Object... vals);
    public Core.Type_typelist vx_copy(final Object... vals);
    public Core.Type_typelist vx_empty();
    public Core.Type_typelist vx_type();
  }

  public static class Class_typelist extends Core.Class_base implements Type_typelist {

    protected List<Core.Type_any> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_any>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_any output = Core.e_any;
      Class_typelist list = this;
      int iindex = index.vx_int();
      List<Core.Type_any> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public Type_typelist vx_new(final Object... vals) {return e_typelist.vx_copy(vals);}

    @Override
    public Type_typelist vx_copy(final Object... vals) {
      Type_typelist output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_typelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_any> listval = new ArrayList<>(val.vx_list());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Core.Type_any) {
          ischanged = true;
          listval.add((Core.Type_any)valsub);
        } else if (valsub instanceof Type_typelist) {
          Type_typelist multi = (Type_typelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_list());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_any) {
              Core.Type_any valitem = (Core.Type_any)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(new typelist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_typelist work = new Class_typelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_typelist vx_empty() {return e_typelist;}
    @Override
    public Type_typelist vx_type() {return t_typelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_typelist e_typelist = new Class_typelist();
  public static final Type_typelist t_typelist = new Class_typelist();

  /**
   * type: typemap
   * Map of Any Type Class
   * (type typemap)
   */
  public interface Type_typemap extends Core.Type_map {
    public Core.Type_typemap vx_new(final Object... vals);
    public Core.Type_typemap vx_copy(final Object... vals);
    public Core.Type_typemap vx_empty();
    public Core.Type_typemap vx_type();
  }

  public static class Class_typemap extends Core.Class_base implements Type_typemap {

    protected Map<String, Core.Type_any> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      Class_typemap map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_any);
      return output;
    }

    @Override
    public Type_typemap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_typemap output = new Class_typemap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_any) {
          Core.Type_any castval = (Core.Type_any)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(typemap) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_typemap vx_new(final Object... vals) {return e_typemap.vx_copy(vals);}

    @Override
    public Type_typemap vx_copy(final Object... vals) {
      Type_typemap output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_typemap valmap = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);
      Map<String, Core.Type_any> mapval = new LinkedHashMap<>(valmap.vx_map());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_any valany = null;
          if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_typemap work = new Class_typemap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_typemap vx_empty() {return e_typemap;}
    @Override
    public Type_typemap vx_type() {return t_typemap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "typemap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_typemap e_typemap = new Class_typemap();
  public static final Type_typemap t_typemap = new Class_typemap();

  /**
   * type: user
   * User Type
   * (type user)
   */
  public interface Type_user extends Core.Type_struct {
    public Core.Type_user vx_new(final Object... vals);
    public Core.Type_user vx_copy(final Object... vals);
    public Core.Type_user vx_empty();
    public Core.Type_user vx_type();
    public Core.Type_security security();
    public Core.Type_string username();
    public Core.Type_string token();
  }

  public static class Class_user extends Core.Class_base implements Type_user {

    protected Core.Type_security vx_p_security;

    @Override
    public Core.Type_security security() {
      return this.vx_p_security == null ? Core.e_security : this.vx_p_security;
    }

    protected Core.Type_string vx_p_username;

    @Override
    public Core.Type_string username() {
      return this.vx_p_username == null ? Core.e_string : this.vx_p_username;
    }

    protected Core.Type_string vx_p_token;

    @Override
    public Core.Type_string token() {
      return this.vx_p_token == null ? Core.e_string : this.vx_p_token;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":security":
        output = this.security();
        break;
      case ":username":
        output = this.username();
        break;
      case ":token":
        output = this.token();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":security", this.security());
      output.put(":username", this.username());
      output.put(":token", this.token());
      return Core.immutablemap(output);
    }

    @Override
    public Type_user vx_new(final Object... vals) {return e_user.vx_copy(vals);}

    @Override
    public Type_user vx_copy(final Object... vals) {
      Type_user output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_user val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_security vx_p_security = val.security();
      Core.Type_string vx_p_username = val.username();
      Core.Type_string vx_p_token = val.token();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":security");
      validkeys.add(":username");
      validkeys.add(":token");
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
            Core.Type_msg msg = Core.vx_msg_error("(new user) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":security":
            if (valsub == vx_p_security) {
            } else if (valsub instanceof Core.Type_security) {
              ischanged = true;
              vx_p_security = (Core.Type_security)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new user :security " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":username":
            if (valsub == vx_p_username) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_username = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_username = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new user :username " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":token":
            if (valsub == vx_p_token) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_token = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_token = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new user :token " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new user) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_user work = new Class_user();
        work.vx_p_security = vx_p_security;
        work.vx_p_username = vx_p_username;
        work.vx_p_token = vx_p_token;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_user vx_empty() {return e_user;}
    @Override
    public Type_user vx_type() {return t_user;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "user", // name
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

  public static final Type_user e_user = new Class_user();
  public static final Type_user t_user = new Class_user();

  /**
   * type: value
   * (type value)
   */
  public interface Type_value extends Core.Type_struct {
    public Core.Type_value vx_new(final Object... vals);
    public Core.Type_value vx_copy(final Object... vals);
    public Core.Type_value vx_empty();
    public Core.Type_value vx_type();
    public Core.Type_any next();
    public Core.Type_int refs();
  }

  public static class Class_value extends Core.Class_base implements Type_value {

    protected Core.Type_any vx_p_next;

    @Override
    public Core.Type_any next() {
      return this.vx_p_next == null ? Core.e_any : this.vx_p_next;
    }

    protected Core.Type_int vx_p_refs;

    @Override
    public Core.Type_int refs() {
      return this.vx_p_refs == null ? Core.e_int : this.vx_p_refs;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":next":
        output = this.next();
        break;
      case ":refs":
        output = this.refs();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":next", this.next());
      output.put(":refs", this.refs());
      return Core.immutablemap(output);
    }

    @Override
    public Type_value vx_new(final Object... vals) {return e_value.vx_copy(vals);}

    @Override
    public Type_value vx_copy(final Object... vals) {
      Type_value output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_value val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_any vx_p_next = val.next();
      Core.Type_int vx_p_refs = val.refs();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":next");
      validkeys.add(":refs");
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
            Core.Type_msg msg = Core.vx_msg_error("(new value) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":next":
            if (valsub == vx_p_next) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_next = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new value :next " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":refs":
            if (valsub == vx_p_refs) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_refs = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_refs = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new value :refs " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new value) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_value work = new Class_value();
        work.vx_p_next = vx_p_next;
        work.vx_p_refs = vx_p_refs;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_value vx_empty() {return e_value;}
    @Override
    public Type_value vx_type() {return t_value;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/core", // pkgname
        "value", // name
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

  public static final Type_value e_value = new Class_value();
  public static final Type_value t_value = new Class_value();

  /**
   * Constant: false
   * {boolean}
   */
  public static class Const_false extends Core.Class_boolean implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "false", // name
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
        )
      );
    }

    public static void const_new(Const_false output) {
    }

    @Override
    public boolean vx_boolean() {
      this.vxboolean = false;
      return this.vxboolean;
    }

  }

  public static final Const_false c_false = new Const_false();


  /**
   * Constant: global
   * Global variable for project data.
   * {project}
   */
  public static class Const_global extends Core.Class_project implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "global", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "project", // name
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

    public static void const_new(Const_global output) {
    }


  }

  public static final Const_global c_global = new Const_global();


  /**
   * Constant: infinity
   * Infinity. Returned during unusual calculations.
   * {int}
   */
  public static class Const_infinity extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "infinity", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_infinity output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static final Const_infinity c_infinity = new Const_infinity();


  /**
   * Constant: mempool-active
   * Active Value Memory Pool
   * {mempool}
   */
  public static class Const_mempool_active extends Core.Class_mempool implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "mempool-active", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "mempool", // name
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

    public static void const_new(Const_mempool_active output) {
    }


  }

  public static final Const_mempool_active c_mempool_active = new Const_mempool_active();


  /**
   * Constant: msg-error
   * Message is an Error
   * {int}
   */
  public static class Const_msg_error extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "msg-error", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_msg_error output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 2;
      return this.vxint;
    }

  }

  public static final Const_msg_error c_msg_error = new Const_msg_error();


  /**
   * Constant: msg-info
   * Message is just information
   * {int}
   */
  public static class Const_msg_info extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "msg-info", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_msg_info output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static final Const_msg_info c_msg_info = new Const_msg_info();


  /**
   * Constant: msg-severe
   * Message is a Severe Error
   * {int}
   */
  public static class Const_msg_severe extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "msg-severe", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_msg_severe output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 3;
      return this.vxint;
    }

  }

  public static final Const_msg_severe c_msg_severe = new Const_msg_severe();


  /**
   * Constant: msg-warning
   * Message is a Warning
   * {int}
   */
  public static class Const_msg_warning extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "msg-warning", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_msg_warning output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 1;
      return this.vxint;
    }

  }

  public static final Const_msg_warning c_msg_warning = new Const_msg_warning();


  /**
   * Constant: neginfinity
   * Negative Infinity. Returned during unusual calculations.
   * {int}
   */
  public static class Const_neginfinity extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "neginfinity", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_neginfinity output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static final Const_neginfinity c_neginfinity = new Const_neginfinity();


  /**
   * Constant: newline
   * New line constant
   * {string}
   */
  public static class Const_newline extends Core.Class_string implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "newline", // name
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
        )
      );
    }

    public static void const_new(Const_newline output) {
    }

    @Override
    public String vx_string() {
      this.vxstring = "\n";
      return this.vxstring;
    }

  }

  public static final Const_newline c_newline = new Const_newline();


  /**
   * Constant: notanumber
   * Not a number. Returned during invalid calculations.
   * {int}
   */
  public static class Const_notanumber extends Core.Class_int implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "notanumber", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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

    public static void const_new(Const_notanumber output) {
    }

    @Override
    public int vx_int() {
      this.vxint = 0;
      return this.vxint;
    }

  }

  public static final Const_notanumber c_notanumber = new Const_notanumber();


  /**
   * Constant: nothing
   * Nothing Value. Opposite of every other value. e.g. Nil, Null
   * {string}
   */
  public static class Const_nothing extends Core.Class_string implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "nothing", // name
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
        )
      );
    }

    public static void const_new(Const_nothing output) {
    }

    @Override
    public String vx_string() {
      this.vxstring = "nothing";
      return this.vxstring;
    }

  }

  public static final Const_nothing c_nothing = new Const_nothing();


  /**
   * Constant: quote
   * Quotation mark constant
   * {string}
   */
  public static class Const_quote extends Core.Class_string implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "quote", // name
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
        )
      );
    }

    public static void const_new(Const_quote output) {
    }

    @Override
    public String vx_string() {
      this.vxstring = "\"";
      return this.vxstring;
    }

  }

  public static final Const_quote c_quote = new Const_quote();


  /**
   * Constant: true
   * {boolean}
   */
  public static class Const_true extends Core.Class_boolean implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/core", // pkgname
        "true", // name
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
        )
      );
    }

    public static void const_new(Const_true output) {
    }

    @Override
    public boolean vx_boolean() {
      this.vxboolean = true;
      return this.vxboolean;
    }

  }

  public static final Const_true c_true = new Const_true();

  /**
   * @function not
   * Boolean not
   * @param  {boolean} val Thing to not
   * @return {boolean}
   * (func !)
   */
  public static interface Func_not extends Core.Func_any_from_any {
    public Core.Type_boolean f_not(final Core.Type_boolean val);
  }

  public static class Class_not extends Core.Class_base implements Func_not {

    @Override
    public Func_not vx_new(Object... vals) {
      Class_not output = new Class_not();
      return output;
    }

    @Override
    public Func_not vx_copy(Object... vals) {
      Class_not output = new Class_not();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "!", // name
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
    public Func_not vx_empty() {return e_not;}
    @Override
    public Func_not vx_type() {return t_not;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_boolean inputval = (Core.Type_boolean)value;
      Core.Type_any outputval = Core.f_not(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_boolean val = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_not(val);
      return output;
    }

    @Override
    public Core.Type_boolean f_not(final Core.Type_boolean val) {
      return Core.f_not(val);
    }

  }

  public static final Func_not e_not = new Core.Class_not();
  public static final Func_not t_not = new Core.Class_not();

  public static Core.Type_boolean f_not(final Core.Type_boolean val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.vx_new_boolean(!val.vx_boolean());
    return output;
  }

  /**
   * @function notempty
   * Returns true if text is not empty.
   * @param  {string} text
   * @return {boolean}
   * (func !-empty)
   */
  public static interface Func_notempty extends Core.Func_any_from_any {
    public Core.Type_boolean f_notempty(final Core.Type_string text);
  }

  public static class Class_notempty extends Core.Class_base implements Func_notempty {

    @Override
    public Func_notempty vx_new(Object... vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    @Override
    public Func_notempty vx_copy(Object... vals) {
      Class_notempty output = new Class_notempty();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
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
    public Func_notempty vx_empty() {return e_notempty;}
    @Override
    public Func_notempty vx_type() {return t_notempty;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_notempty(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_notempty(text);
      return output;
    }

    @Override
    public Core.Type_boolean f_notempty(final Core.Type_string text) {
      return Core.f_notempty(text);
    }

  }

  public static final Func_notempty e_notempty = new Core.Class_notempty();
  public static final Func_notempty t_notempty = new Core.Class_notempty();

  public static Core.Type_boolean f_notempty(final Core.Type_string text) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_is_empty(text)
    );
    return output;
  }

  /**
   * @function notempty 1
   * Returns true if val is not empty.
   * @param  {any} val
   * @return {boolean}
   * (func !-empty)
   */
  public static interface Func_notempty_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_notempty_1(final Core.Type_any val);
  }

  public static class Class_notempty_1 extends Core.Class_base implements Func_notempty_1 {

    @Override
    public Func_notempty_1 vx_new(Object... vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    @Override
    public Func_notempty_1 vx_copy(Object... vals) {
      Class_notempty_1 output = new Class_notempty_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        1, // idx
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
    public Func_notempty_1 vx_empty() {return e_notempty_1;}
    @Override
    public Func_notempty_1 vx_type() {return t_notempty_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_notempty_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_notempty_1(val);
      return output;
    }

    @Override
    public Core.Type_boolean f_notempty_1(final Core.Type_any val) {
      return Core.f_notempty_1(val);
    }

  }

  public static final Func_notempty_1 e_notempty_1 = new Core.Class_notempty_1();
  public static final Func_notempty_1 t_notempty_1 = new Core.Class_notempty_1();

  public static Core.Type_boolean f_notempty_1(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_is_empty_1(val)
    );
    return output;
  }

  /**
   * @function ne
   * Returns true if the first arg is not equal to any of the other arg.
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func !=)
   */
  public static interface Func_ne extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_ne(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_ne extends Core.Class_base implements Func_ne {

    @Override
    public Func_ne vx_new(Object... vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    @Override
    public Func_ne vx_copy(Object... vals) {
      Class_ne output = new Class_ne();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "!=", // name
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
    public Func_ne vx_empty() {return e_ne;}
    @Override
    public Func_ne vx_type() {return t_ne;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_ne(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_ne(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_ne(val1, val2);
    }

  }

  public static final Func_ne e_ne = new Core.Class_ne();
  public static final Func_ne t_ne = new Core.Class_ne();

  public static Core.Type_boolean f_ne(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_eq(val1, val2)
    );
    return output;
  }

  /**
   * @function neqeq
   * Returns true if the first arg is not strictly equal to any of the other arg.
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func !==)
   */
  public static interface Func_neqeq extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_neqeq(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_neqeq extends Core.Class_base implements Func_neqeq {

    @Override
    public Func_neqeq vx_new(Object... vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    @Override
    public Func_neqeq vx_copy(Object... vals) {
      Class_neqeq output = new Class_neqeq();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "!==", // name
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
    public Func_neqeq vx_empty() {return e_neqeq;}
    @Override
    public Func_neqeq vx_type() {return t_neqeq;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_neqeq(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_neqeq(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_neqeq(val1, val2);
    }

  }

  public static final Func_neqeq e_neqeq = new Core.Class_neqeq();
  public static final Func_neqeq t_neqeq = new Core.Class_neqeq();

  public static Core.Type_boolean f_neqeq(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_eqeq(val1, val2)
    );
    return output;
  }

  /**
   * @function multiply
   * Math int multiply
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func *)
   */
  public static interface Func_multiply extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int f_multiply(final Core.Type_int num1, final Core.Type_int num2);
  }

  public static class Class_multiply extends Core.Class_base implements Func_multiply {

    @Override
    public Func_multiply vx_new(Object... vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    @Override
    public Func_multiply vx_copy(Object... vals) {
      Class_multiply output = new Class_multiply();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_multiply vx_empty() {return e_multiply;}
    @Override
    public Func_multiply vx_type() {return t_multiply;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int num1 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int num2 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_multiply(num1, num2);
      return output;
    }

    @Override
    public Core.Type_int f_multiply(final Core.Type_int num1, final Core.Type_int num2) {
      return Core.f_multiply(num1, num2);
    }

  }

  public static final Func_multiply e_multiply = new Core.Class_multiply();
  public static final Func_multiply t_multiply = new Core.Class_multiply();

  public static Core.Type_int f_multiply(final Core.Type_int num1, final Core.Type_int num2) {
    Core.Type_int output = Core.e_int;
    int result = num1.vx_int() * num2.vx_int();
    output = Core.vx_new_int(result);
    return output;
  }

  /**
   * @function multiply 1
   * Math multipy
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func *)
   */
  public static interface Func_multiply_1 extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_number f_multiply_1(final Core.Type_number num1, final Core.Type_number num2);
  }

  public static class Class_multiply_1 extends Core.Class_base implements Func_multiply_1 {

    @Override
    public Func_multiply_1 vx_new(Object... vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    @Override
    public Func_multiply_1 vx_copy(Object... vals) {
      Class_multiply_1 output = new Class_multiply_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_multiply_1 vx_empty() {return e_multiply_1;}
    @Override
    public Func_multiply_1 vx_type() {return t_multiply_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_number num1 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_number num2 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_multiply_1(num1, num2);
      return output;
    }

    @Override
    public Core.Type_number f_multiply_1(final Core.Type_number num1, final Core.Type_number num2) {
      return Core.f_multiply_1(num1, num2);
    }

  }

  public static final Func_multiply_1 e_multiply_1 = new Core.Class_multiply_1();
  public static final Func_multiply_1 t_multiply_1 = new Core.Class_multiply_1();

  public static Core.Type_number f_multiply_1(final Core.Type_number num1, final Core.Type_number num2) {
    Core.Type_number output = Core.e_number;
    Core.Type_float float1 = Core.t_float.vx_new(num1);
    Core.Type_float float2 = Core.t_float.vx_new(num2);
    float result = float1.vx_float() * float2.vx_float();
    output = Core.vx_new_float(result);
    return output;
  }

  /**
   * @function multiply 2
   * Math multiply
   * @param  {intlist} nums
   * @return {int}
   * (func *)
   */
  public static interface Func_multiply_2 extends Core.Func_any_from_any {
    public Core.Type_int f_multiply_2(final Core.Type_intlist nums);
  }

  public static class Class_multiply_2 extends Core.Class_base implements Func_multiply_2 {

    @Override
    public Func_multiply_2 vx_new(Object... vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    @Override
    public Func_multiply_2 vx_copy(Object... vals) {
      Class_multiply_2 output = new Class_multiply_2();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        2, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_multiply_2 vx_empty() {return e_multiply_2;}
    @Override
    public Func_multiply_2 vx_type() {return t_multiply_2;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_intlist inputval = (Core.Type_intlist)value;
      Core.Type_any outputval = Core.f_multiply_2(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_intlist nums = Core.f_any_from_any(Core.t_intlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_multiply_2(nums);
      return output;
    }

    @Override
    public Core.Type_int f_multiply_2(final Core.Type_intlist nums) {
      return Core.f_multiply_2(nums);
    }

  }

  public static final Func_multiply_2 e_multiply_2 = new Core.Class_multiply_2();
  public static final Func_multiply_2 t_multiply_2 = new Core.Class_multiply_2();

  public static Core.Type_int f_multiply_2(final Core.Type_intlist nums) {
    Core.Type_int output = Core.e_int;
    output = Core.f_any_from_list_reduce(
      Core.t_int,
      nums,
      Core.vx_new_int(1),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_int total = Core.f_any_from_any(Core.t_int, total_any);
        Core.Type_int num = Core.f_any_from_any(Core.t_int, num_any);
        return 
          Core.f_multiply(total, num);
      })
    );
    return output;
  }

  /**
   * @function multiply 3
   * Math multiply
   * @param  {numberlist} nums
   * @return {number}
   * (func *)
   */
  public static interface Func_multiply_3 extends Core.Func_any_from_any {
    public Core.Type_number f_multiply_3(final Core.Type_numberlist nums);
  }

  public static class Class_multiply_3 extends Core.Class_base implements Func_multiply_3 {

    @Override
    public Func_multiply_3 vx_new(Object... vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    @Override
    public Func_multiply_3 vx_copy(Object... vals) {
      Class_multiply_3 output = new Class_multiply_3();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "*", // name
        3, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_multiply_3 vx_empty() {return e_multiply_3;}
    @Override
    public Func_multiply_3 vx_type() {return t_multiply_3;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_numberlist inputval = (Core.Type_numberlist)value;
      Core.Type_any outputval = Core.f_multiply_3(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_numberlist nums = Core.f_any_from_any(Core.t_numberlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_multiply_3(nums);
      return output;
    }

    @Override
    public Core.Type_number f_multiply_3(final Core.Type_numberlist nums) {
      return Core.f_multiply_3(nums);
    }

  }

  public static final Func_multiply_3 e_multiply_3 = new Core.Class_multiply_3();
  public static final Func_multiply_3 t_multiply_3 = new Core.Class_multiply_3();

  public static Core.Type_number f_multiply_3(final Core.Type_numberlist nums) {
    Core.Type_number output = Core.e_number;
    output = Core.f_any_from_list_reduce(
      Core.t_number,
      nums,
      Core.vx_new_int(1),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_number total = Core.f_any_from_any(Core.t_number, total_any);
        Core.Type_number num = Core.f_any_from_any(Core.t_number, num_any);
        return 
          Core.f_multiply_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus
   * Math int plus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func +)
   */
  public static interface Func_plus extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int f_plus(final Core.Type_int num1, final Core.Type_int num2);
  }

  public static class Class_plus extends Core.Class_base implements Func_plus {

    @Override
    public Func_plus vx_new(Object... vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    @Override
    public Func_plus vx_copy(Object... vals) {
      Class_plus output = new Class_plus();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_plus vx_empty() {return e_plus;}
    @Override
    public Func_plus vx_type() {return t_plus;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int num1 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int num2 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_plus(num1, num2);
      return output;
    }

    @Override
    public Core.Type_int f_plus(final Core.Type_int num1, final Core.Type_int num2) {
      return Core.f_plus(num1, num2);
    }

  }

  public static final Func_plus e_plus = new Core.Class_plus();
  public static final Func_plus t_plus = new Core.Class_plus();

  public static Core.Type_int f_plus(final Core.Type_int num1, final Core.Type_int num2) {
    Core.Type_int output = Core.e_int;
    int result = num1.vx_int() + num2.vx_int();
    output = Core.vx_new_int(result);
    return output;
  }

  /**
   * @function plus 1
   * Math number plus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func +)
   */
  public static interface Func_plus_1 extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_number f_plus_1(final Core.Type_number num1, final Core.Type_number num2);
  }

  public static class Class_plus_1 extends Core.Class_base implements Func_plus_1 {

    @Override
    public Func_plus_1 vx_new(Object... vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    @Override
    public Func_plus_1 vx_copy(Object... vals) {
      Class_plus_1 output = new Class_plus_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_plus_1 vx_empty() {return e_plus_1;}
    @Override
    public Func_plus_1 vx_type() {return t_plus_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_number num1 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_number num2 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_plus_1(num1, num2);
      return output;
    }

    @Override
    public Core.Type_number f_plus_1(final Core.Type_number num1, final Core.Type_number num2) {
      return Core.f_plus_1(num1, num2);
    }

  }

  public static final Func_plus_1 e_plus_1 = new Core.Class_plus_1();
  public static final Func_plus_1 t_plus_1 = new Core.Class_plus_1();

  public static Core.Type_number f_plus_1(final Core.Type_number num1, final Core.Type_number num2) {
    Core.Type_number output = Core.e_number;
    Core.Type_float float1 = Core.t_float.vx_new(num1);
    Core.Type_float float2 = Core.t_float.vx_new(num2);
    float result = float1.vx_float() + float2.vx_float();
    output = Core.vx_new_float(result);
    return output;
  }

  /**
   * @function plus 2
   * Math int plus
   * @param  {intlist} nums
   * @return {int}
   * (func +)
   */
  public static interface Func_plus_2 extends Core.Func_any_from_any {
    public Core.Type_int f_plus_2(final Core.Type_intlist nums);
  }

  public static class Class_plus_2 extends Core.Class_base implements Func_plus_2 {

    @Override
    public Func_plus_2 vx_new(Object... vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    @Override
    public Func_plus_2 vx_copy(Object... vals) {
      Class_plus_2 output = new Class_plus_2();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        2, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_plus_2 vx_empty() {return e_plus_2;}
    @Override
    public Func_plus_2 vx_type() {return t_plus_2;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_intlist inputval = (Core.Type_intlist)value;
      Core.Type_any outputval = Core.f_plus_2(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_intlist nums = Core.f_any_from_any(Core.t_intlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_plus_2(nums);
      return output;
    }

    @Override
    public Core.Type_int f_plus_2(final Core.Type_intlist nums) {
      return Core.f_plus_2(nums);
    }

  }

  public static final Func_plus_2 e_plus_2 = new Core.Class_plus_2();
  public static final Func_plus_2 t_plus_2 = new Core.Class_plus_2();

  public static Core.Type_int f_plus_2(final Core.Type_intlist nums) {
    Core.Type_int output = Core.e_int;
    output = Core.f_any_from_list_reduce(
      Core.t_int,
      nums,
      Core.vx_new_int(0),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_int total = Core.f_any_from_any(Core.t_int, total_any);
        Core.Type_int num = Core.f_any_from_any(Core.t_int, num_any);
        return 
          Core.f_plus(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus 3
   * Math number plus
   * @param  {numberlist} nums
   * @return {number}
   * (func +)
   */
  public static interface Func_plus_3 extends Core.Func_any_from_any {
    public Core.Type_number f_plus_3(final Core.Type_numberlist nums);
  }

  public static class Class_plus_3 extends Core.Class_base implements Func_plus_3 {

    @Override
    public Func_plus_3 vx_new(Object... vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    @Override
    public Func_plus_3 vx_copy(Object... vals) {
      Class_plus_3 output = new Class_plus_3();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "+", // name
        3, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_plus_3 vx_empty() {return e_plus_3;}
    @Override
    public Func_plus_3 vx_type() {return t_plus_3;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_numberlist inputval = (Core.Type_numberlist)value;
      Core.Type_any outputval = Core.f_plus_3(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_numberlist nums = Core.f_any_from_any(Core.t_numberlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_plus_3(nums);
      return output;
    }

    @Override
    public Core.Type_number f_plus_3(final Core.Type_numberlist nums) {
      return Core.f_plus_3(nums);
    }

  }

  public static final Func_plus_3 e_plus_3 = new Core.Class_plus_3();
  public static final Func_plus_3 t_plus_3 = new Core.Class_plus_3();

  public static Core.Type_number f_plus_3(final Core.Type_numberlist nums) {
    Core.Type_number output = Core.e_number;
    output = Core.f_any_from_list_reduce(
      Core.t_number,
      nums,
      Core.vx_new_int(0),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_number total = Core.f_any_from_any(Core.t_number, total_any);
        Core.Type_number num = Core.f_any_from_any(Core.t_number, num_any);
        return 
          Core.f_plus_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus1
   * Math int plus 1
   * @param  {int} num
   * @return {int}
   * (func +1)
   */
  public static interface Func_plus1 extends Core.Func_any_from_any {
    public Core.Type_int f_plus1(final Core.Type_int num);
  }

  public static class Class_plus1 extends Core.Class_base implements Func_plus1 {

    @Override
    public Func_plus1 vx_new(Object... vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    @Override
    public Func_plus1 vx_copy(Object... vals) {
      Class_plus1 output = new Class_plus1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "+1", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_plus1 vx_empty() {return e_plus1;}
    @Override
    public Func_plus1 vx_type() {return t_plus1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Core.f_plus1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int num = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_plus1(num);
      return output;
    }

    @Override
    public Core.Type_int f_plus1(final Core.Type_int num) {
      return Core.f_plus1(num);
    }

  }

  public static final Func_plus1 e_plus1 = new Core.Class_plus1();
  public static final Func_plus1 t_plus1 = new Core.Class_plus1();

  public static Core.Type_int f_plus1(final Core.Type_int num) {
    Core.Type_int output = Core.e_int;
    output = Core.f_plus(num, Core.vx_new_int(1));
    return output;
  }

  /**
   * @function minus
   * Math int minus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func -)
   */
  public static interface Func_minus extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int f_minus(final Core.Type_int num1, final Core.Type_int num2);
  }

  public static class Class_minus extends Core.Class_base implements Func_minus {

    @Override
    public Func_minus vx_new(Object... vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    @Override
    public Func_minus vx_copy(Object... vals) {
      Class_minus output = new Class_minus();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_minus vx_empty() {return e_minus;}
    @Override
    public Func_minus vx_type() {return t_minus;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int num1 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int num2 = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_minus(num1, num2);
      return output;
    }

    @Override
    public Core.Type_int f_minus(final Core.Type_int num1, final Core.Type_int num2) {
      return Core.f_minus(num1, num2);
    }

  }

  public static final Func_minus e_minus = new Core.Class_minus();
  public static final Func_minus t_minus = new Core.Class_minus();

  public static Core.Type_int f_minus(final Core.Type_int num1, final Core.Type_int num2) {
    Core.Type_int output = Core.e_int;
    int result = num1.vx_int() - num2.vx_int();
    output = Core.vx_new_int(result);
    return output;
  }

  /**
   * @function minus 1
   * Math number minus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func -)
   */
  public static interface Func_minus_1 extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_number f_minus_1(final Core.Type_number num1, final Core.Type_number num2);
  }

  public static class Class_minus_1 extends Core.Class_base implements Func_minus_1 {

    @Override
    public Func_minus_1 vx_new(Object... vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    @Override
    public Func_minus_1 vx_copy(Object... vals) {
      Class_minus_1 output = new Class_minus_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_minus_1 vx_empty() {return e_minus_1;}
    @Override
    public Func_minus_1 vx_type() {return t_minus_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_number num1 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_number num2 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_minus_1(num1, num2);
      return output;
    }

    @Override
    public Core.Type_number f_minus_1(final Core.Type_number num1, final Core.Type_number num2) {
      return Core.f_minus_1(num1, num2);
    }

  }

  public static final Func_minus_1 e_minus_1 = new Core.Class_minus_1();
  public static final Func_minus_1 t_minus_1 = new Core.Class_minus_1();

  public static Core.Type_number f_minus_1(final Core.Type_number num1, final Core.Type_number num2) {
    Core.Type_number output = Core.e_number;
    Core.Type_float float1 = Core.t_float.vx_new(num1);
    Core.Type_float float2 = Core.t_float.vx_new(num2);
    float result = float1.vx_float() - float2.vx_float();
    output = Core.vx_new_float(result);
    return output;
  }

  /**
   * @function minus 2
   * Math integer minus
   * @param  {intlist} nums
   * @return {int}
   * (func -)
   */
  public static interface Func_minus_2 extends Core.Func_any_from_any {
    public Core.Type_int f_minus_2(final Core.Type_intlist nums);
  }

  public static class Class_minus_2 extends Core.Class_base implements Func_minus_2 {

    @Override
    public Func_minus_2 vx_new(Object... vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    @Override
    public Func_minus_2 vx_copy(Object... vals) {
      Class_minus_2 output = new Class_minus_2();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        2, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_minus_2 vx_empty() {return e_minus_2;}
    @Override
    public Func_minus_2 vx_type() {return t_minus_2;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_intlist inputval = (Core.Type_intlist)value;
      Core.Type_any outputval = Core.f_minus_2(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_intlist nums = Core.f_any_from_any(Core.t_intlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_minus_2(nums);
      return output;
    }

    @Override
    public Core.Type_int f_minus_2(final Core.Type_intlist nums) {
      return Core.f_minus_2(nums);
    }

  }

  public static final Func_minus_2 e_minus_2 = new Core.Class_minus_2();
  public static final Func_minus_2 t_minus_2 = new Core.Class_minus_2();

  public static Core.Type_int f_minus_2(final Core.Type_intlist nums) {
    Core.Type_int output = Core.e_int;
    output = Core.f_any_from_list_reduce(
      Core.t_int,
      nums,
      Core.vx_new_int(0),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_int total = Core.f_any_from_any(Core.t_int, total_any);
        Core.Type_int num = Core.f_any_from_any(Core.t_int, num_any);
        return 
          Core.f_minus(total, num);
      })
    );
    return output;
  }

  /**
   * @function minus 3
   * Math number minus
   * @param  {numberlist} nums
   * @return {number}
   * (func -)
   */
  public static interface Func_minus_3 extends Core.Func_any_from_any {
    public Core.Type_number f_minus_3(final Core.Type_numberlist nums);
  }

  public static class Class_minus_3 extends Core.Class_base implements Func_minus_3 {

    @Override
    public Func_minus_3 vx_new(Object... vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    @Override
    public Func_minus_3 vx_copy(Object... vals) {
      Class_minus_3 output = new Class_minus_3();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "-", // name
        3, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_minus_3 vx_empty() {return e_minus_3;}
    @Override
    public Func_minus_3 vx_type() {return t_minus_3;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_numberlist inputval = (Core.Type_numberlist)value;
      Core.Type_any outputval = Core.f_minus_3(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_numberlist nums = Core.f_any_from_any(Core.t_numberlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_minus_3(nums);
      return output;
    }

    @Override
    public Core.Type_number f_minus_3(final Core.Type_numberlist nums) {
      return Core.f_minus_3(nums);
    }

  }

  public static final Func_minus_3 e_minus_3 = new Core.Class_minus_3();
  public static final Func_minus_3 t_minus_3 = new Core.Class_minus_3();

  public static Core.Type_number f_minus_3(final Core.Type_numberlist nums) {
    Core.Type_number output = Core.e_number;
    output = Core.f_any_from_list_reduce(
      Core.t_number,
      nums,
      Core.vx_new_int(0),
      Core.t_any_from_reduce.vx_fn_new((total_any, num_any) -> {
        Core.Type_number total = Core.f_any_from_any(Core.t_number, total_any);
        Core.Type_number num = Core.f_any_from_any(Core.t_number, num_any);
        return 
          Core.f_minus_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function minus1
   * Math int minus 1
   * @param  {int} num
   * @return {int}
   * (func -1)
   */
  public static interface Func_minus1 extends Core.Func_any_from_any {
    public Core.Type_int f_minus1(final Core.Type_int num);
  }

  public static class Class_minus1 extends Core.Class_base implements Func_minus1 {

    @Override
    public Func_minus1 vx_new(Object... vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    @Override
    public Func_minus1 vx_copy(Object... vals) {
      Class_minus1 output = new Class_minus1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "-1", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_minus1 vx_empty() {return e_minus1;}
    @Override
    public Func_minus1 vx_type() {return t_minus1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Core.f_minus1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int num = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_minus1(num);
      return output;
    }

    @Override
    public Core.Type_int f_minus1(final Core.Type_int num) {
      return Core.f_minus1(num);
    }

  }

  public static final Func_minus1 e_minus1 = new Core.Class_minus1();
  public static final Func_minus1 t_minus1 = new Core.Class_minus1();

  public static Core.Type_int f_minus1(final Core.Type_int num) {
    Core.Type_int output = Core.e_int;
    output = Core.f_minus(num, Core.vx_new_int(1));
    return output;
  }

  /**
   * @function dotmethod
   * Not Recommened: Support for Object Oriented dot notation. e.g. (this.foo 'a') = this.foo('a')
   * @param  {any} object
   * @param  {string} method
   * @param  {anylist} params
   * @return {any}
   * (func .)
   */
  public static interface Func_dotmethod extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_any f_dotmethod(final Core.Type_any object, final Core.Type_string method, final Core.Type_anylist params);
  }

  public static class Class_dotmethod extends Core.Class_base implements Func_dotmethod {

    @Override
    public Func_dotmethod vx_new(Object... vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    @Override
    public Func_dotmethod vx_copy(Object... vals) {
      Class_dotmethod output = new Class_dotmethod();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        ".", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_dotmethod vx_empty() {return e_dotmethod;}
    @Override
    public Func_dotmethod vx_type() {return t_dotmethod;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any object = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string method = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_anylist params = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_dotmethod(object, method, params);
      return output;
    }

    @Override
    public Core.Type_any f_dotmethod(final Core.Type_any object, final Core.Type_string method, final Core.Type_anylist params) {
      return Core.f_dotmethod(object, method, params);
    }

  }

  public static final Func_dotmethod e_dotmethod = new Core.Class_dotmethod();
  public static final Func_dotmethod t_dotmethod = new Core.Class_dotmethod();

  public static Core.Type_any f_dotmethod(final Core.Type_any object, final Core.Type_string method, final Core.Type_anylist params) {
    Core.Type_any output = Core.e_any;
    return output;
  }

  /**
   * @function divide
   * Math divide
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func /)
   */
  public static interface Func_divide extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_number f_divide(final Core.Type_number num1, final Core.Type_number num2);
  }

  public static class Class_divide extends Core.Class_base implements Func_divide {

    @Override
    public Func_divide vx_new(Object... vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    @Override
    public Func_divide vx_copy(Object... vals) {
      Class_divide output = new Class_divide();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "/", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_divide vx_empty() {return e_divide;}
    @Override
    public Func_divide vx_type() {return t_divide;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_number num1 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_number num2 = Core.f_any_from_any(Core.t_number, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_divide(num1, num2);
      return output;
    }

    @Override
    public Core.Type_number f_divide(final Core.Type_number num1, final Core.Type_number num2) {
      return Core.f_divide(num1, num2);
    }

  }

  public static final Func_divide e_divide = new Core.Class_divide();
  public static final Func_divide t_divide = new Core.Class_divide();

  public static Core.Type_number f_divide(final Core.Type_number num1, final Core.Type_number num2) {
    Core.Type_number output = Core.e_number;
    Core.Type_float float1 = Core.t_float.vx_new(num1);
    Core.Type_float float2 = Core.t_float.vx_new(num2);
    if (float1.vx_float() == 0) {
    } else if (float2.vx_float() == 0) {
      output = Core.c_notanumber;
    } else {
      float result = float1.vx_float() / float2.vx_float();
      output = Core.vx_new_float(result);
    };
    return output;
  }

  /**
   * @function lt
   * Returns true if the first arg is less than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func <)
   */
  public static interface Func_lt extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_lt(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_lt extends Core.Class_base implements Func_lt {

    @Override
    public Func_lt vx_new(Object... vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    @Override
    public Func_lt vx_copy(Object... vals) {
      Class_lt output = new Class_lt();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
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
    public Func_lt vx_empty() {return e_lt;}
    @Override
    public Func_lt vx_type() {return t_lt;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_lt(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_lt(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_lt(val1, val2);
    }

  }

  public static final Func_lt e_lt = new Core.Class_lt();
  public static final Func_lt t_lt = new Core.Class_lt();

  public static Core.Type_boolean f_lt(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_switch(
      Core.t_boolean,
      Core.f_compare(val1, val2),
      Core.t_thenelselist.vx_new(
        Core.f_case_1(
          Core.vx_new_int(-1),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(true);
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(false);
          })
        )
      )
    );
    return output;
  }

  /**
   * @function lt 1
   * Returns true if the first arg is less than all of the other args
   * @param  {anylist} values
   * @return {boolean}
   * (func <)
   */
  public static interface Func_lt_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_lt_1(final Core.Type_anylist values);
  }

  public static class Class_lt_1 extends Core.Class_base implements Func_lt_1 {

    @Override
    public Func_lt_1 vx_new(Object... vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    @Override
    public Func_lt_1 vx_copy(Object... vals) {
      Class_lt_1 output = new Class_lt_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<", // name
        1, // idx
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
    public Func_lt_1 vx_empty() {return e_lt_1;}
    @Override
    public Func_lt_1 vx_type() {return t_lt_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_lt_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_lt_1(values);
      return output;
    }

    @Override
    public Core.Type_boolean f_lt_1(final Core.Type_anylist values) {
      return Core.f_lt_1(values);
    }

  }

  public static final Func_lt_1 e_lt_1 = new Core.Class_lt_1();
  public static final Func_lt_1 t_lt_1 = new Core.Class_lt_1();

  public static Core.Type_boolean f_lt_1(final Core.Type_anylist values) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_reduce_next(
      Core.t_boolean,
      values,
      Core.vx_new_boolean(true),
      Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) -> {
        Core.Type_boolean reduce = Core.f_any_from_any(Core.t_boolean, reduce_any);
        Core.Type_any current = Core.f_any_from_any(Core.t_any, current_any);
        Core.Type_any next = Core.f_any_from_any(Core.t_any, next_any);
        return 
          Core.f_and(
            reduce,
            Core.f_lt(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function chainfirst
   * This is a special function that applies a value as the first argument for the first function.
   * The result is then used as the first argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {any-1} value
   * @param  {any<-anylist} fnlist
   * @return {any-1}
   * (func <-)
   */
  public static interface Func_chainfirst extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_chainfirst(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist);
  }

  public static class Class_chainfirst extends Core.Class_base implements Func_chainfirst {

    @Override
    public Func_chainfirst vx_new(Object... vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    @Override
    public Func_chainfirst vx_copy(Object... vals) {
      Class_chainfirst output = new Class_chainfirst();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<-", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_chainfirst vx_empty() {return e_chainfirst;}
    @Override
    public Func_chainfirst vx_type() {return t_chainfirst;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any_from_anylist fnlist = Core.f_any_from_any(Core.t_any_from_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_chainfirst(generic_any_1, value, fnlist);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_chainfirst(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist) {
      return Core.f_chainfirst(generic_any_1, value, fnlist);
    }

  }

  public static final Func_chainfirst e_chainfirst = new Core.Class_chainfirst();
  public static final Func_chainfirst t_chainfirst = new Core.Class_chainfirst();

  public static <T extends Core.Type_any> T f_chainfirst(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function chainlast
   * This is a special function that applies a value as the last argument for the first function.
   * The result is then used as the last argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {any-1} value
   * @param  {any<-anylist} fnlist
   * @return {any-1}
   * (func <<-)
   */
  public static interface Func_chainlast extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_chainlast(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist);
  }

  public static class Class_chainlast extends Core.Class_base implements Func_chainlast {

    @Override
    public Func_chainlast vx_new(Object... vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    @Override
    public Func_chainlast vx_copy(Object... vals) {
      Class_chainlast output = new Class_chainlast();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<<-", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_chainlast vx_empty() {return e_chainlast;}
    @Override
    public Func_chainlast vx_type() {return t_chainlast;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any_from_anylist fnlist = Core.f_any_from_any(Core.t_any_from_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_chainlast(generic_any_1, value, fnlist);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_chainlast(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist) {
      return Core.f_chainlast(generic_any_1, value, fnlist);
    }

  }

  public static final Func_chainlast e_chainlast = new Core.Class_chainlast();
  public static final Func_chainlast t_chainlast = new Core.Class_chainlast();

  public static <T extends Core.Type_any> T f_chainlast(final T generic_any_1, final T value, final Core.Type_any_from_anylist fnlist) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function le
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func <=)
   */
  public static interface Func_le extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_le(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_le extends Core.Class_base implements Func_le {

    @Override
    public Func_le vx_new(Object... vals) {
      Class_le output = new Class_le();
      return output;
    }

    @Override
    public Func_le vx_copy(Object... vals) {
      Class_le output = new Class_le();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
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
    public Func_le vx_empty() {return e_le;}
    @Override
    public Func_le vx_type() {return t_le;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_le(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_le(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_le(val1, val2);
    }

  }

  public static final Func_le e_le = new Core.Class_le();
  public static final Func_le t_le = new Core.Class_le();

  public static Core.Type_boolean f_le(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_gt(val1, val2)
    );
    return output;
  }

  /**
   * @function le 1
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {anylist} args
   * @return {boolean}
   * (func <=)
   */
  public static interface Func_le_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_le_1(final Core.Type_anylist args);
  }

  public static class Class_le_1 extends Core.Class_base implements Func_le_1 {

    @Override
    public Func_le_1 vx_new(Object... vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    @Override
    public Func_le_1 vx_copy(Object... vals) {
      Class_le_1 output = new Class_le_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        1, // idx
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
    public Func_le_1 vx_empty() {return e_le_1;}
    @Override
    public Func_le_1 vx_type() {return t_le_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_le_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_le_1(args);
      return output;
    }

    @Override
    public Core.Type_boolean f_le_1(final Core.Type_anylist args) {
      return Core.f_le_1(args);
    }

  }

  public static final Func_le_1 e_le_1 = new Core.Class_le_1();
  public static final Func_le_1 t_le_1 = new Core.Class_le_1();

  public static Core.Type_boolean f_le_1(final Core.Type_anylist args) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_gt_1(args)
    );
    return output;
  }

  /**
   * @function eq
   * Boolean equal/equivalent
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func =)
   */
  public static interface Func_eq extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_eq(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_eq extends Core.Class_base implements Func_eq {

    @Override
    public Func_eq vx_new(Object... vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    @Override
    public Func_eq vx_copy(Object... vals) {
      Class_eq output = new Class_eq();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
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
    public Func_eq vx_empty() {return e_eq;}
    @Override
    public Func_eq vx_type() {return t_eq;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_eq(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_eq(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_eq(val1, val2);
    }

  }

  public static final Func_eq e_eq = new Core.Class_eq();
  public static final Func_eq t_eq = new Core.Class_eq();

  public static Core.Type_boolean f_eq(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    boolean isequal = false;
    if (val1 == val2) {
      isequal = true;
    } else {
      Core.Type_string strval1 = Core.f_string_from_any(val1);
      Core.Type_string strval2 = Core.f_string_from_any(val2);
      if (strval1.vx_string().equals(strval2.vx_string())) {
        isequal = true;
      }
    }
    output = Core.vx_new_boolean(isequal);
    return output;
  }

  /**
   * @function eq 1
   * Boolean equal/equivalent
   * @param  {anylist} values
   * @return {boolean}
   * (func =)
   */
  public static interface Func_eq_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_eq_1(final Core.Type_anylist values);
  }

  public static class Class_eq_1 extends Core.Class_base implements Func_eq_1 {

    @Override
    public Func_eq_1 vx_new(Object... vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    @Override
    public Func_eq_1 vx_copy(Object... vals) {
      Class_eq_1 output = new Class_eq_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "=", // name
        1, // idx
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
    public Func_eq_1 vx_empty() {return e_eq_1;}
    @Override
    public Func_eq_1 vx_type() {return t_eq_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_eq_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_eq_1(values);
      return output;
    }

    @Override
    public Core.Type_boolean f_eq_1(final Core.Type_anylist values) {
      return Core.f_eq_1(values);
    }

  }

  public static final Func_eq_1 e_eq_1 = new Core.Class_eq_1();
  public static final Func_eq_1 t_eq_1 = new Core.Class_eq_1();

  public static Core.Type_boolean f_eq_1(final Core.Type_anylist values) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_reduce_next(
      Core.t_boolean,
      values,
      Core.vx_new_boolean(false),
      Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) -> {
        Core.Type_boolean reduce = Core.f_any_from_any(Core.t_boolean, reduce_any);
        Core.Type_any current = Core.f_any_from_any(Core.t_any, current_any);
        Core.Type_any next = Core.f_any_from_any(Core.t_any, next_any);
        return 
          Core.f_and(
            reduce,
            Core.f_eq(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function eqeq
   * Strict equality check. Note that all non-empty, non-constants will not be equal.
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func ==)
   */
  public static interface Func_eqeq extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_eqeq(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_eqeq extends Core.Class_base implements Func_eqeq {

    @Override
    public Func_eqeq vx_new(Object... vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    @Override
    public Func_eqeq vx_copy(Object... vals) {
      Class_eqeq output = new Class_eqeq();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "==", // name
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
    public Func_eqeq vx_empty() {return e_eqeq;}
    @Override
    public Func_eqeq vx_type() {return t_eqeq;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_eqeq(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_eqeq(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_eqeq(val1, val2);
    }

  }

  public static final Func_eqeq e_eqeq = new Core.Class_eqeq();
  public static final Func_eqeq t_eqeq = new Core.Class_eqeq();

  public static Core.Type_boolean f_eqeq(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    boolean isequal = Core.vx_eqeq(val1, val2);
    output = Core.vx_new_boolean(isequal);
    return output;
  }

  /**
   * @function gt
   * Returns true if the first arg is greater than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func >)
   */
  public static interface Func_gt extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_gt(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_gt extends Core.Class_base implements Func_gt {

    @Override
    public Func_gt vx_new(Object... vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    @Override
    public Func_gt vx_copy(Object... vals) {
      Class_gt output = new Class_gt();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
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
    public Func_gt vx_empty() {return e_gt;}
    @Override
    public Func_gt vx_type() {return t_gt;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_gt(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_gt(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_gt(val1, val2);
    }

  }

  public static final Func_gt e_gt = new Core.Class_gt();
  public static final Func_gt t_gt = new Core.Class_gt();

  public static Core.Type_boolean f_gt(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_switch(
      Core.t_boolean,
      Core.f_compare(val1, val2),
      Core.t_thenelselist.vx_new(
        Core.f_case_1(
          Core.vx_new_int(1),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(true);
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(false);
          })
        )
      )
    );
    return output;
  }

  /**
   * @function gt 1
   * Returns true if the first arg is greater than all of the other args
   * @param  {anylist} values
   * @return {boolean}
   * (func >)
   */
  public static interface Func_gt_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_gt_1(final Core.Type_anylist values);
  }

  public static class Class_gt_1 extends Core.Class_base implements Func_gt_1 {

    @Override
    public Func_gt_1 vx_new(Object... vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    @Override
    public Func_gt_1 vx_copy(Object... vals) {
      Class_gt_1 output = new Class_gt_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        ">", // name
        1, // idx
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
    public Func_gt_1 vx_empty() {return e_gt_1;}
    @Override
    public Func_gt_1 vx_type() {return t_gt_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_gt_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_gt_1(values);
      return output;
    }

    @Override
    public Core.Type_boolean f_gt_1(final Core.Type_anylist values) {
      return Core.f_gt_1(values);
    }

  }

  public static final Func_gt_1 e_gt_1 = new Core.Class_gt_1();
  public static final Func_gt_1 t_gt_1 = new Core.Class_gt_1();

  public static Core.Type_boolean f_gt_1(final Core.Type_anylist values) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_reduce_next(
      Core.t_boolean,
      values,
      Core.vx_new_boolean(true),
      Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) -> {
        Core.Type_boolean reduce = Core.f_any_from_any(Core.t_boolean, reduce_any);
        Core.Type_any current = Core.f_any_from_any(Core.t_any, current_any);
        Core.Type_any next = Core.f_any_from_any(Core.t_any, next_any);
        return 
          Core.f_and(
            reduce,
            Core.f_gt(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function ge
   * Returns true if val1 is greater or equal to val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func >=)
   */
  public static interface Func_ge extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_ge(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_ge extends Core.Class_base implements Func_ge {

    @Override
    public Func_ge vx_new(Object... vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    @Override
    public Func_ge vx_copy(Object... vals) {
      Class_ge output = new Class_ge();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
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
    public Func_ge vx_empty() {return e_ge;}
    @Override
    public Func_ge vx_type() {return t_ge;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_ge(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_ge(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_ge(val1, val2);
    }

  }

  public static final Func_ge e_ge = new Core.Class_ge();
  public static final Func_ge t_ge = new Core.Class_ge();

  public static Core.Type_boolean f_ge(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_lt(val1, val2)
    );
    return output;
  }

  /**
   * @function ge 1
   * Returns true if the first arg is greater or equal than all of the other args
   * @param  {anylist} args
   * @return {boolean}
   * (func >=)
   */
  public static interface Func_ge_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_ge_1(final Core.Type_anylist args);
  }

  public static class Class_ge_1 extends Core.Class_base implements Func_ge_1 {

    @Override
    public Func_ge_1 vx_new(Object... vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    @Override
    public Func_ge_1 vx_copy(Object... vals) {
      Class_ge_1 output = new Class_ge_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        1, // idx
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
    public Func_ge_1 vx_empty() {return e_ge_1;}
    @Override
    public Func_ge_1 vx_type() {return t_ge_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_ge_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_ge_1(args);
      return output;
    }

    @Override
    public Core.Type_boolean f_ge_1(final Core.Type_anylist args) {
      return Core.f_ge_1(args);
    }

  }

  public static final Func_ge_1 e_ge_1 = new Core.Class_ge_1();
  public static final Func_ge_1 t_ge_1 = new Core.Class_ge_1();

  public static Core.Type_boolean f_ge_1(final Core.Type_anylist args) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_not(
      Core.f_lt_1(args)
    );
    return output;
  }

  /**
   * @function allowfuncs_from_security
   * Returns allowfuncs from a given security.
   * @param  {security} security
   * @return {funclist}
   * (func allowfuncs<-security)
   */
  public static interface Func_allowfuncs_from_security extends Core.Func_any_from_any {
    public Core.Type_funclist f_allowfuncs_from_security(final Core.Type_security security);
  }

  public static class Class_allowfuncs_from_security extends Core.Class_base implements Func_allowfuncs_from_security {

    @Override
    public Func_allowfuncs_from_security vx_new(Object... vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    @Override
    public Func_allowfuncs_from_security vx_copy(Object... vals) {
      Class_allowfuncs_from_security output = new Class_allowfuncs_from_security();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "allowfuncs<-security", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "funclist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_func), // allowtypes
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
    public Func_allowfuncs_from_security vx_empty() {return e_allowfuncs_from_security;}
    @Override
    public Func_allowfuncs_from_security vx_type() {return t_allowfuncs_from_security;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_security inputval = (Core.Type_security)value;
      Core.Type_any outputval = Core.f_allowfuncs_from_security(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_security security = Core.f_any_from_any(Core.t_security, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_allowfuncs_from_security(security);
      return output;
    }

    @Override
    public Core.Type_funclist f_allowfuncs_from_security(final Core.Type_security security) {
      return Core.f_allowfuncs_from_security(security);
    }

  }

  public static final Func_allowfuncs_from_security e_allowfuncs_from_security = new Core.Class_allowfuncs_from_security();
  public static final Func_allowfuncs_from_security t_allowfuncs_from_security = new Core.Class_allowfuncs_from_security();

  public static Core.Type_funclist f_allowfuncs_from_security(final Core.Type_security security) {
    Core.Type_funclist output = Core.e_funclist;
    output = security.allowfuncs();
    return output;
  }

  /**
   * @function allowtypenames_from_typedef
   * Return allow name list from type
   * @param  {typedef} vtypedef
   * @return {stringlist}
   * (func allowtypenames<-typedef)
   */
  public static interface Func_allowtypenames_from_typedef extends Core.Func_any_from_any {
    public Core.Type_stringlist f_allowtypenames_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_allowtypenames_from_typedef extends Core.Class_base implements Func_allowtypenames_from_typedef {

    @Override
    public Func_allowtypenames_from_typedef vx_new(Object... vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    @Override
    public Func_allowtypenames_from_typedef vx_copy(Object... vals) {
      Class_allowtypenames_from_typedef output = new Class_allowtypenames_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "allowtypenames<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_string), // allowtypes
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
    public Func_allowtypenames_from_typedef vx_empty() {return e_allowtypenames_from_typedef;}
    @Override
    public Func_allowtypenames_from_typedef vx_type() {return t_allowtypenames_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_allowtypenames_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_allowtypenames_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_stringlist f_allowtypenames_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_allowtypenames_from_typedef(vtypedef);
    }

  }

  public static final Func_allowtypenames_from_typedef e_allowtypenames_from_typedef = new Core.Class_allowtypenames_from_typedef();
  public static final Func_allowtypenames_from_typedef t_allowtypenames_from_typedef = new Core.Class_allowtypenames_from_typedef();

  public static Core.Type_stringlist f_allowtypenames_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_typenames_from_typelist(
      Core.f_allowtypes_from_typedef(vtypedef)
    );
    return output;
  }

  /**
   * @function allowtypes_from_typedef
   * Return allow type list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func allowtypes<-typedef)
   */
  public static interface Func_allowtypes_from_typedef extends Core.Func_any_from_any {
    public Core.Type_typelist f_allowtypes_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_allowtypes_from_typedef extends Core.Class_base implements Func_allowtypes_from_typedef {

    @Override
    public Func_allowtypes_from_typedef vx_new(Object... vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    @Override
    public Func_allowtypes_from_typedef vx_copy(Object... vals) {
      Class_allowtypes_from_typedef output = new Class_allowtypes_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "allowtypes<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_allowtypes_from_typedef vx_empty() {return e_allowtypes_from_typedef;}
    @Override
    public Func_allowtypes_from_typedef vx_type() {return t_allowtypes_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_allowtypes_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_allowtypes_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_typelist f_allowtypes_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_allowtypes_from_typedef(vtypedef);
    }

  }

  public static final Func_allowtypes_from_typedef e_allowtypes_from_typedef = new Core.Class_allowtypes_from_typedef();
  public static final Func_allowtypes_from_typedef t_allowtypes_from_typedef = new Core.Class_allowtypes_from_typedef();

  public static Core.Type_typelist f_allowtypes_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_typelist output = Core.e_typelist;
    output = vtypedef.allowtypes();
    return output;
  }

  /**
   * @function and
   * Returns true if all values are true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   * (func and)
   */
  public static interface Func_and extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_and(final Core.Type_boolean val1, final Core.Type_boolean val2);
  }

  public static class Class_and extends Core.Class_base implements Func_and {

    @Override
    public Func_and vx_new(Object... vals) {
      Class_and output = new Class_and();
      return output;
    }

    @Override
    public Func_and vx_copy(Object... vals) {
      Class_and output = new Class_and();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
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
    public Func_and vx_empty() {return e_and;}
    @Override
    public Func_and vx_type() {return t_and;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_boolean val1 = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_boolean val2 = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_and(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_and(final Core.Type_boolean val1, final Core.Type_boolean val2) {
      return Core.f_and(val1, val2);
    }

  }

  public static final Func_and e_and = new Core.Class_and();
  public static final Func_and t_and = new Core.Class_and();

  public static Core.Type_boolean f_and(final Core.Type_boolean val1, final Core.Type_boolean val2) {
    Core.Type_boolean output = Core.e_boolean;
    if (val1.vx_boolean() && val2.vx_boolean()) {
      output = Core.c_true;
    } else {
      output = Core.c_false;
    };
    return output;
  }

  /**
   * @function and 1
   * Returns true if all values are true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func and)
   */
  public static interface Func_and_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_and_1(final Core.Type_booleanlist values);
  }

  public static class Class_and_1 extends Core.Class_base implements Func_and_1 {

    @Override
    public Func_and_1 vx_new(Object... vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    @Override
    public Func_and_1 vx_copy(Object... vals) {
      Class_and_1 output = new Class_and_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "and", // name
        1, // idx
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
    public Func_and_1 vx_empty() {return e_and_1;}
    @Override
    public Func_and_1 vx_type() {return t_and_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_booleanlist inputval = (Core.Type_booleanlist)value;
      Core.Type_any outputval = Core.f_and_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_booleanlist values = Core.f_any_from_any(Core.t_booleanlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_and_1(values);
      return output;
    }

    @Override
    public Core.Type_boolean f_and_1(final Core.Type_booleanlist values) {
      return Core.f_and_1(values);
    }

  }

  public static final Func_and_1 e_and_1 = new Core.Class_and_1();
  public static final Func_and_1 t_and_1 = new Core.Class_and_1();

  public static Core.Type_boolean f_and_1(final Core.Type_booleanlist values) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_switch(
      Core.t_boolean,
      Core.f_length_from_list(values),
      Core.t_thenelselist.vx_new(
        Core.f_case_1(
          Core.vx_new_int(0),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(true);
          })
        ),
        Core.f_case_1(
          Core.vx_new_int(1),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_any_from_list(Core.t_boolean, values, Core.vx_new_int(1));
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_any_from_list_reduce_next(
              Core.t_boolean,
              values,
              Core.vx_new_boolean(true),
              Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) -> {
                Core.Type_boolean reduce = Core.f_any_from_any(Core.t_boolean, reduce_any);
                Core.Type_boolean current = Core.f_any_from_any(Core.t_boolean, current_any);
                Core.Type_boolean next = Core.f_any_from_any(Core.t_boolean, next_any);
                return 
                    Core.f_and(
                      reduce,
                      Core.f_and(current, next)
                    );
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function any_from_any
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any)
   */
  public static interface Func_any_from_any extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value);
  }

  public static class Class_any_from_any extends Core.Class_base implements Func_any_from_any {

    public IFn fn = null;

    @Override
    public Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      Class_any_from_any output = new Class_any_from_any();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_any vx_new(Object... vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    @Override
    public Func_any_from_any vx_copy(Object... vals) {
      Class_any_from_any output = new Class_any_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_any vx_empty() {return e_any_from_any;}
    @Override
    public Func_any_from_any vx_type() {return t_any_from_any;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_any value);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_any_from_any(generic_any_1, value);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(value));
      }
      return output;
    }

  }

  public static final Func_any_from_any e_any_from_any = new Core.Class_any_from_any();
  public static final Func_any_from_any t_any_from_any = new Core.Class_any_from_any();

  @SuppressWarnings("unchecked")
  public static <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
    T output = Core.f_empty(generic_any_1);
    output = (T)value;
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_any_async
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-async)
   */
  public static interface Func_any_from_any_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value);
  }

  public static class Class_any_from_any_async extends Core.Class_base implements Func_any_from_any_async {

    public IFn fn = null;

    @Override
    public Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_any_async vx_new(Object... vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    @Override
    public Func_any_from_any_async vx_copy(Object... vals) {
      Class_any_from_any_async output = new Class_any_from_any_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_any_async vx_empty() {return e_any_from_any_async;}
    @Override
    public Func_any_from_any_async vx_type() {return t_any_from_any_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve(Core.Type_any value);
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_any_async(generic_any_1, value);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve(value);
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_any_async e_any_from_any_async = new Core.Class_any_from_any_async();
  public static final Func_any_from_any_async t_any_from_any_async = new Core.Class_any_from_any_async();

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_any_context
   * Function Type taking any value any-2 and returning generic any-1 using context
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context)
   */
  public static interface Func_any_from_any_context extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value);
  }

  public static class Class_any_from_any_context extends Core.Class_base implements Func_any_from_any_context {

    public IFn fn = null;

    @Override
    public Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_any_context vx_new(Object... vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    @Override
    public Func_any_from_any_context vx_copy(Object... vals) {
      Class_any_from_any_context output = new Class_any_from_any_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_any_context vx_empty() {return e_any_from_any_context;}
    @Override
    public Func_any_from_any_context vx_type() {return t_any_from_any_context;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_context context, Core.Type_any value);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_any_from_any_context(generic_any_1, context, value);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(context, value));
      }
      return output;
    }

  }

  public static final Func_any_from_any_context e_any_from_any_context = new Core.Class_any_from_any_context();
  public static final Func_any_from_any_context t_any_from_any_context = new Core.Class_any_from_any_context();

  @SuppressWarnings("unchecked")
  public static <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
    T output = Core.f_empty(generic_any_1);
    output = (T)value;
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_any_context_async
   * Generic Function taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context-async)
   */
  public static interface Func_any_from_any_context_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_any_context_async vx_fn_new(Core.Class_any_from_any_context_async.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_context_async(final T generic_any_1, final Core.Type_context context, final U value);
  }

  public static class Class_any_from_any_context_async extends Core.Class_base implements Func_any_from_any_context_async {

    public IFn fn = null;

    @Override
    public Func_any_from_any_context_async vx_fn_new(Core.Class_any_from_any_context_async.IFn fn) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_any_context_async vx_new(Object... vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    @Override
    public Func_any_from_any_context_async vx_copy(Object... vals) {
      Class_any_from_any_context_async output = new Class_any_from_any_context_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-any-context-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_any_context_async vx_empty() {return e_any_from_any_context_async;}
    @Override
    public Func_any_from_any_context_async vx_type() {return t_any_from_any_context_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve(Core.Type_context context, Core.Type_any value);
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_any_context_async(generic_any_1, context, value);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_context_async(final T generic_any_1, final Core.Type_context context, final U value) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve(context, value);
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_any_context_async e_any_from_any_context_async = new Core.Class_any_from_any_context_async();
  public static final Func_any_from_any_context_async t_any_from_any_context_async = new Core.Class_any_from_any_context_async();

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_context_async(final T generic_any_1, final Core.Type_context context, final U value) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_func
   * Generic Function returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func)
   */
  public static interface Func_any_from_func extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_func vx_fn_new(Core.Class_any_from_func.IFn fn);
    public <T extends Core.Type_any> T f_any_from_func(final T generic_any_1);
  }

  public static class Class_any_from_func extends Core.Class_base implements Func_any_from_func {

    public IFn fn = null;

    @Override
    public Func_any_from_func vx_fn_new(Core.Class_any_from_func.IFn fn) {
      Class_any_from_func output = new Class_any_from_func();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_func vx_new(Object... vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    @Override
    public Func_any_from_func vx_copy(Object... vals) {
      Class_any_from_func output = new Class_any_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-func", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_func vx_empty() {return e_any_from_func;}
    @Override
    public Func_any_from_func vx_type() {return t_any_from_func;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve();
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_any_from_func(generic_any_1);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_any_from_func(final T generic_any_1) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve());
      }
      return output;
    }

  }

  public static final Func_any_from_func e_any_from_func = new Core.Class_any_from_func();
  public static final Func_any_from_func t_any_from_func = new Core.Class_any_from_func();

  public static <T extends Core.Type_any> T f_any_from_func(final T generic_any_1) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_func_async
   * Generic Function returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func-async)
   */
  public static interface Func_any_from_func_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_func_async vx_fn_new(Core.Class_any_from_func_async.IFn fn);
    public <T extends Core.Type_any> CompletableFuture<T> f_any_from_func_async(final T generic_any_1);
  }

  public static class Class_any_from_func_async extends Core.Class_base implements Func_any_from_func_async {

    public IFn fn = null;

    @Override
    public Func_any_from_func_async vx_fn_new(Core.Class_any_from_func_async.IFn fn) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_func_async vx_new(Object... vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    @Override
    public Func_any_from_func_async vx_copy(Object... vals) {
      Class_any_from_func_async output = new Class_any_from_func_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-func-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_func_async vx_empty() {return e_any_from_func_async;}
    @Override
    public Func_any_from_func_async vx_type() {return t_any_from_func_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve();
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_func_async(generic_any_1);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any> CompletableFuture<T> f_any_from_func_async(final T generic_any_1) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve();
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_func_async e_any_from_func_async = new Core.Class_any_from_func_async();
  public static final Func_any_from_func_async t_any_from_func_async = new Core.Class_any_from_func_async();

  public static <T extends Core.Type_any> CompletableFuture<T> f_any_from_func_async(final T generic_any_1) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_int
   * Generic Function returning Generic any-1 from an int
   * @param  {int} value
   * @return {any-1}
   * (func any<-int)
   */
  public static interface Func_any_from_int extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_int vx_fn_new(Core.Class_any_from_int.IFn fn);
    public <T extends Core.Type_any> T f_any_from_int(final T generic_any_1, final Core.Type_int value);
  }

  public static class Class_any_from_int extends Core.Class_base implements Func_any_from_int {

    public IFn fn = null;

    @Override
    public Func_any_from_int vx_fn_new(Core.Class_any_from_int.IFn fn) {
      Class_any_from_int output = new Class_any_from_int();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_int vx_new(Object... vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    @Override
    public Func_any_from_int vx_copy(Object... vals) {
      Class_any_from_int output = new Class_any_from_int();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-int", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_int vx_empty() {return e_any_from_int;}
    @Override
    public Func_any_from_int vx_type() {return t_any_from_int;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_int value);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int value = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_any_from_int(generic_any_1, value);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_any_from_int(final T generic_any_1, final Core.Type_int value) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(value));
      }
      return output;
    }

  }

  public static final Func_any_from_int e_any_from_int = new Core.Class_any_from_int();
  public static final Func_any_from_int t_any_from_int = new Core.Class_any_from_int();

  public static <T extends Core.Type_any> T f_any_from_int(final T generic_any_1, final Core.Type_int value) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_key_value
   * Generic Function returning Generic any-1 from a key and a value
   * @param  {string} key
   * @param  {any-2} val
   * @return {any-1}
   * (func any<-key-value)
   */
  public static interface Func_any_from_key_value extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_key_value vx_fn_new(Core.Class_any_from_key_value.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_key_value(final T generic_any_1, final Core.Type_string key, final U val);
  }

  public static class Class_any_from_key_value extends Core.Class_base implements Func_any_from_key_value {

    public IFn fn = null;

    @Override
    public Func_any_from_key_value vx_fn_new(Core.Class_any_from_key_value.IFn fn) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_key_value vx_new(Object... vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    @Override
    public Func_any_from_key_value vx_copy(Object... vals) {
      Class_any_from_key_value output = new Class_any_from_key_value();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_key_value vx_empty() {return e_any_from_key_value;}
    @Override
    public Func_any_from_key_value vx_type() {return t_any_from_key_value;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_string key, Core.Type_any val);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_any_from_key_value(generic_any_1, key, val);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_key_value(final T generic_any_1, final Core.Type_string key, final U val) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(key, val));
      }
      return output;
    }

  }

  public static final Func_any_from_key_value e_any_from_key_value = new Core.Class_any_from_key_value();
  public static final Func_any_from_key_value t_any_from_key_value = new Core.Class_any_from_key_value();

  public static <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_key_value(final T generic_any_1, final Core.Type_string key, final U val) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_key_value_async
   * Generic Function returning Asynchronous Generic any-1 from a key and a value
   * @param  {string} key
   * @param  {any-2} val
   * @return {any-1}
   * (func any<-key-value-async)
   */
  public static interface Func_any_from_key_value_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_key_value_async vx_fn_new(Core.Class_any_from_key_value_async.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_key_value_async(final T generic_any_1, final Core.Type_string key, final U val);
  }

  public static class Class_any_from_key_value_async extends Core.Class_base implements Func_any_from_key_value_async {

    public IFn fn = null;

    @Override
    public Func_any_from_key_value_async vx_fn_new(Core.Class_any_from_key_value_async.IFn fn) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_key_value_async vx_new(Object... vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    @Override
    public Func_any_from_key_value_async vx_copy(Object... vals) {
      Class_any_from_key_value_async output = new Class_any_from_key_value_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-key-value-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_key_value_async vx_empty() {return e_any_from_key_value_async;}
    @Override
    public Func_any_from_key_value_async vx_type() {return t_any_from_key_value_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve(Core.Type_string key, Core.Type_any val);
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_key_value_async(generic_any_1, key, val);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_key_value_async(final T generic_any_1, final Core.Type_string key, final U val) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve(key, val);
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_key_value_async e_any_from_key_value_async = new Core.Class_any_from_key_value_async();
  public static final Func_any_from_key_value_async t_any_from_key_value_async = new Core.Class_any_from_key_value_async();

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_key_value_async(final T generic_any_1, final Core.Type_string key, final U val) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_list
   * Returns nth value from a list or none if out of bounds
   * @param  {list-1} values
   * @param  {int} index
   * @return {any-1}
   * (func any<-list)
   */
  public static interface Func_any_from_list extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, X extends Core.Type_list> T f_any_from_list(final T generic_any_1, final X values, final Core.Type_int index);
  }

  public static class Class_any_from_list extends Core.Class_base implements Func_any_from_list {

    @Override
    public Func_any_from_list vx_new(Object... vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    @Override
    public Func_any_from_list vx_copy(Object... vals) {
      Class_any_from_list output = new Class_any_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_list vx_empty() {return e_any_from_list;}
    @Override
    public Func_any_from_list vx_type() {return t_any_from_list;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int index = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_any_from_list(generic_any_1, values, index);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> T f_any_from_list(final T generic_any_1, final X values, final Core.Type_int index) {
      return Core.f_any_from_list(generic_any_1, values, index);
    }

  }

  public static final Func_any_from_list e_any_from_list = new Core.Class_any_from_list();
  public static final Func_any_from_list t_any_from_list = new Core.Class_any_from_list();

  public static <T extends Core.Type_any, X extends Core.Type_list> T f_any_from_list(final T generic_any_1, final X values, final Core.Type_int index) {
    T output = Core.f_empty(generic_any_1);
    int intindex = index.vx_int();
    int intsize = values.vx_list().size();
    if (intindex <= intsize) {
      List<Core.Type_any> listvalue = values.vx_list();
      Core.Type_any value = listvalue.get(intindex - 1);
      output = Core.f_any_from_any(generic_any_1, value);
    };
    return output;
  }

  /**
   * @function any_from_list_reduce
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce} fn-reduce
   * @return {any-1}
   * (func any<-list-reduce)
   */
  public static interface Func_any_from_list_reduce extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_list_reduce vx_fn_new(Core.Class_any_from_list_reduce.IFn fn);
    public <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce fn_reduce);
  }

  public static class Class_any_from_list_reduce extends Core.Class_base implements Func_any_from_list_reduce {

    public IFn fn = null;

    @Override
    public Func_any_from_list_reduce vx_fn_new(Core.Class_any_from_list_reduce.IFn fn) {
      Class_any_from_list_reduce output = new Class_any_from_list_reduce();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_list_reduce vx_new(Object... vals) {
      Class_any_from_list_reduce output = new Class_any_from_list_reduce();
      return output;
    }

    @Override
    public Func_any_from_list_reduce vx_copy(Object... vals) {
      Class_any_from_list_reduce output = new Class_any_from_list_reduce();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_list_reduce vx_empty() {return e_any_from_list_reduce;}
    @Override
    public Func_any_from_list_reduce vx_type() {return t_any_from_list_reduce;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_list list, Core.Type_any valstart, Core.Func_any_from_reduce fn_reduce);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list list = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any valstart = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_reduce fn_reduce = Core.f_any_from_any(Core.t_any_from_reduce, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_any_from_list_reduce(generic_any_1, list, valstart, fn_reduce);
      return output;
    }

    @Override
    public <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce fn_reduce) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(list, valstart, fn_reduce));
      }
      return output;
    }

  }

  public static final Func_any_from_list_reduce e_any_from_list_reduce = new Core.Class_any_from_list_reduce();
  public static final Func_any_from_list_reduce t_any_from_list_reduce = new Core.Class_any_from_list_reduce();

  public static <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce fn_reduce) {
    T output = Core.f_empty(generic_any_1);
    output = valstart;
    List<Core.Type_any> listval = list.vx_list();
    for (Core.Type_any item : listval) {
      output = fn_reduce.f_any_from_reduce(generic_any_1, output, item);
    };
    return output;
  }

  /**
   * @function any_from_list_reduce_next
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce-next} fn-reduce-next
   * @return {any-1}
   * (func any<-list-reduce-next)
   */
  public static interface Func_any_from_list_reduce_next extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_list_reduce_next vx_fn_new(Core.Class_any_from_list_reduce_next.IFn fn);
    public <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce_next(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce_next fn_reduce_next);
  }

  public static class Class_any_from_list_reduce_next extends Core.Class_base implements Func_any_from_list_reduce_next {

    public IFn fn = null;

    @Override
    public Func_any_from_list_reduce_next vx_fn_new(Core.Class_any_from_list_reduce_next.IFn fn) {
      Class_any_from_list_reduce_next output = new Class_any_from_list_reduce_next();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_list_reduce_next vx_new(Object... vals) {
      Class_any_from_list_reduce_next output = new Class_any_from_list_reduce_next();
      return output;
    }

    @Override
    public Func_any_from_list_reduce_next vx_copy(Object... vals) {
      Class_any_from_list_reduce_next output = new Class_any_from_list_reduce_next();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce-next", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_list_reduce_next vx_empty() {return e_any_from_list_reduce_next;}
    @Override
    public Func_any_from_list_reduce_next vx_type() {return t_any_from_list_reduce_next;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_list list, Core.Type_any valstart, Core.Func_any_from_reduce_next fn_reduce_next);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list list = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any valstart = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_reduce_next fn_reduce_next = Core.f_any_from_any(Core.t_any_from_reduce_next, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_any_from_list_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
      return output;
    }

    @Override
    public <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce_next(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce_next fn_reduce_next) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(list, valstart, fn_reduce_next));
      }
      return output;
    }

  }

  public static final Func_any_from_list_reduce_next e_any_from_list_reduce_next = new Core.Class_any_from_list_reduce_next();
  public static final Func_any_from_list_reduce_next t_any_from_list_reduce_next = new Core.Class_any_from_list_reduce_next();

  public static <T extends Core.Type_any, Y extends Core.Type_list> T f_any_from_list_reduce_next(final T generic_any_1, final Y list, final T valstart, final Core.Func_any_from_reduce_next fn_reduce_next) {
    T output = Core.f_empty(generic_any_1);
    output = valstart;
    final List<Core.Type_any> listval = list.vx_list();
    Core.Type_any current = Core.e_any;
    boolean first = true;
    for (final Core.Type_any next : listval) {
      if (first) {
        first = false;
      } else {
        output = fn_reduce_next.f_any_from_reduce_next(generic_any_1, output, current, next);
      }
      current = next;
    };
    return output;
  }

  /**
   * @function any_from_map
   * Returns value from a map or empty if not found
   * @param  {map-1} valuemap
   * @param  {string} key
   * @return {any}
   * (func any<-map)
   */
  public static interface Func_any_from_map extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, N extends Core.Type_map> T f_any_from_map(final T generic_any_1, final N valuemap, final Core.Type_string key);
  }

  public static class Class_any_from_map extends Core.Class_base implements Func_any_from_map {

    @Override
    public Func_any_from_map vx_new(Object... vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    @Override
    public Func_any_from_map vx_copy(Object... vals) {
      Class_any_from_map output = new Class_any_from_map();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-map", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_any_from_map vx_empty() {return e_any_from_map;}
    @Override
    public Func_any_from_map vx_type() {return t_any_from_map;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_any_from_map(generic_any_1, valuemap, key);
      return output;
    }

    @Override
    public <T extends Core.Type_any, N extends Core.Type_map> T f_any_from_map(final T generic_any_1, final N valuemap, final Core.Type_string key) {
      return Core.f_any_from_map(generic_any_1, valuemap, key);
    }

  }

  public static final Func_any_from_map e_any_from_map = new Core.Class_any_from_map();
  public static final Func_any_from_map t_any_from_map = new Core.Class_any_from_map();

  public static <T extends Core.Type_any, N extends Core.Type_map> T f_any_from_map(final T generic_any_1, final N valuemap, final Core.Type_string key) {
    T output = Core.f_empty(generic_any_1);
    Core.Type_any val = valuemap.vx_map().getOrDefault(key.vx_string(), output);
    output = Core.f_any_from_any(generic_any_1, val);
    return output;
  }

  /**
   * @function any_from_none
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none)
   */
  public static interface Func_any_from_none extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_none vx_fn_new(Core.Class_any_from_none.IFn fn);
    public <T extends Core.Type_any> T f_any_from_none(final T generic_any_1);
  }

  public static class Class_any_from_none extends Core.Class_base implements Func_any_from_none {

    public IFn fn = null;

    @Override
    public Func_any_from_none vx_fn_new(Core.Class_any_from_none.IFn fn) {
      Class_any_from_none output = new Class_any_from_none();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_none vx_new(Object... vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    @Override
    public Func_any_from_none vx_copy(Object... vals) {
      Class_any_from_none output = new Class_any_from_none();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-none", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_none vx_empty() {return e_any_from_none;}
    @Override
    public Func_any_from_none vx_type() {return t_any_from_none;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve();
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_any_from_none(generic_any_1);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_any_from_none(final T generic_any_1) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve());
      }
      return output;
    }

  }

  public static final Func_any_from_none e_any_from_none = new Core.Class_any_from_none();
  public static final Func_any_from_none t_any_from_none = new Core.Class_any_from_none();

  public static <T extends Core.Type_any> T f_any_from_none(final T generic_any_1) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_none_async
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none-async)
   */
  public static interface Func_any_from_none_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_none_async vx_fn_new(Core.Class_any_from_none_async.IFn fn);
    public <T extends Core.Type_any> CompletableFuture<T> f_any_from_none_async(final T generic_any_1);
  }

  public static class Class_any_from_none_async extends Core.Class_base implements Func_any_from_none_async {

    public IFn fn = null;

    @Override
    public Func_any_from_none_async vx_fn_new(Core.Class_any_from_none_async.IFn fn) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_none_async vx_new(Object... vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    @Override
    public Func_any_from_none_async vx_copy(Object... vals) {
      Class_any_from_none_async output = new Class_any_from_none_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-none-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_none_async vx_empty() {return e_any_from_none_async;}
    @Override
    public Func_any_from_none_async vx_type() {return t_any_from_none_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve();
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_none_async(generic_any_1);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any> CompletableFuture<T> f_any_from_none_async(final T generic_any_1) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve();
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_none_async e_any_from_none_async = new Core.Class_any_from_none_async();
  public static final Func_any_from_none_async t_any_from_none_async = new Core.Class_any_from_none_async();

  public static <T extends Core.Type_any> CompletableFuture<T> f_any_from_none_async(final T generic_any_1) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce)
   */
  public static interface Func_any_from_reduce extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_reduce vx_fn_new(Core.Class_any_from_reduce.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce(final T generic_any_1, final T result, final U item);
  }

  public static class Class_any_from_reduce extends Core.Class_base implements Func_any_from_reduce {

    public IFn fn = null;

    @Override
    public Func_any_from_reduce vx_fn_new(Core.Class_any_from_reduce.IFn fn) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_reduce vx_new(Object... vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    @Override
    public Func_any_from_reduce vx_copy(Object... vals) {
      Class_any_from_reduce output = new Class_any_from_reduce();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_reduce vx_empty() {return e_any_from_reduce;}
    @Override
    public Func_any_from_reduce vx_type() {return t_any_from_reduce;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_any result, Core.Type_any item);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any result = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any item = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_any_from_reduce(generic_any_1, result, item);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce(final T generic_any_1, final T result, final U item) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(result, item));
      }
      return output;
    }

  }

  public static final Func_any_from_reduce e_any_from_reduce = new Core.Class_any_from_reduce();
  public static final Func_any_from_reduce t_any_from_reduce = new Core.Class_any_from_reduce();

  public static <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce(final T generic_any_1, final T result, final U item) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_reduce_async
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce-async)
   */
  public static interface Func_any_from_reduce_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_reduce_async vx_fn_new(Core.Class_any_from_reduce_async.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_async(final T generic_any_1, final T result, final U item);
  }

  public static class Class_any_from_reduce_async extends Core.Class_base implements Func_any_from_reduce_async {

    public IFn fn = null;

    @Override
    public Func_any_from_reduce_async vx_fn_new(Core.Class_any_from_reduce_async.IFn fn) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_reduce_async vx_new(Object... vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    @Override
    public Func_any_from_reduce_async vx_copy(Object... vals) {
      Class_any_from_reduce_async output = new Class_any_from_reduce_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_reduce_async vx_empty() {return e_any_from_reduce_async;}
    @Override
    public Func_any_from_reduce_async vx_type() {return t_any_from_reduce_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve(Core.Type_any result, Core.Type_any item);
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any result = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any item = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_reduce_async(generic_any_1, result, item);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_async(final T generic_any_1, final T result, final U item) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve(result, item);
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_reduce_async e_any_from_reduce_async = new Core.Class_any_from_reduce_async();
  public static final Func_any_from_reduce_async t_any_from_reduce_async = new Core.Class_any_from_reduce_async();

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_async(final T generic_any_1, final T result, final U item) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce_next
   * @param  {any-1} result
   * @param  {any-2} current
   * @param  {any-2} next
   * @return {any-1}
   * (func any<-reduce-next)
   */
  public static interface Func_any_from_reduce_next extends Core.Type_func, Core.Type_replfunc {
    public Func_any_from_reduce_next vx_fn_new(Core.Class_any_from_reduce_next.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce_next(final T generic_any_1, final T result, final U current, final U next);
  }

  public static class Class_any_from_reduce_next extends Core.Class_base implements Func_any_from_reduce_next {

    public IFn fn = null;

    @Override
    public Func_any_from_reduce_next vx_fn_new(Core.Class_any_from_reduce_next.IFn fn) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_reduce_next vx_new(Object... vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    @Override
    public Func_any_from_reduce_next vx_copy(Object... vals) {
      Class_any_from_reduce_next output = new Class_any_from_reduce_next();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_reduce_next vx_empty() {return e_any_from_reduce_next;}
    @Override
    public Func_any_from_reduce_next vx_type() {return t_any_from_reduce_next;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_any result, Core.Type_any current, Core.Type_any next);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any result = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any current = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_any next = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_any_from_reduce_next(generic_any_1, result, current, next);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce_next(final T generic_any_1, final T result, final U current, final U next) {
      T output = Core.f_empty(generic_any_1);
      if (fn != null) {
        output = Core.f_any_from_any(generic_any_1, fn.resolve(result, current, next));
      }
      return output;
    }

  }

  public static final Func_any_from_reduce_next e_any_from_reduce_next = new Core.Class_any_from_reduce_next();
  public static final Func_any_from_reduce_next t_any_from_reduce_next = new Core.Class_any_from_reduce_next();

  public static <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_reduce_next(final T generic_any_1, final T result, final U current, final U next) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_reduce_next_async
   * @param  {any-1} result
   * @param  {any-2} current
   * @param  {any-2} next
   * @return {any-1}
   * (func any<-reduce-next-async)
   */
  public static interface Func_any_from_reduce_next_async extends Core.Type_func, Core.Type_replfunc_async {
    public Func_any_from_reduce_next_async vx_fn_new(Core.Class_any_from_reduce_next_async.IFn fn);
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_next_async(final T generic_any_1, final T result, final U current, final U next);
  }

  public static class Class_any_from_reduce_next_async extends Core.Class_base implements Func_any_from_reduce_next_async {

    public IFn fn = null;

    @Override
    public Func_any_from_reduce_next_async vx_fn_new(Core.Class_any_from_reduce_next_async.IFn fn) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_any_from_reduce_next_async vx_new(Object... vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    @Override
    public Func_any_from_reduce_next_async vx_copy(Object... vals) {
      Class_any_from_reduce_next_async output = new Class_any_from_reduce_next_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_reduce_next_async vx_empty() {return e_any_from_reduce_next_async;}
    @Override
    public Func_any_from_reduce_next_async vx_type() {return t_any_from_reduce_next_async;}

    @FunctionalInterface
    public static interface IFn {
      public CompletableFuture<Core.Type_any> resolve(Core.Type_any result, Core.Type_any current, Core.Type_any next);
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any result = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any current = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_any next = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(2)));
      CompletableFuture<Core.Type_any> future = Core.f_any_from_reduce_next_async(generic_any_1, result, current, next);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_next_async(final T generic_any_1, final T result, final U current, final U next) {
      CompletableFuture<T> output;
      if (fn == null) {
        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));
      } else {
        CompletableFuture<Core.Type_any> future = fn.resolve(result, current, next);
        output = Core.async_from_async(generic_any_1, future);
      }
      return output;
    }

  }

  public static final Func_any_from_reduce_next_async e_any_from_reduce_next_async = new Core.Class_any_from_reduce_next_async();
  public static final Func_any_from_reduce_next_async t_any_from_reduce_next_async = new Core.Class_any_from_reduce_next_async();

  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_reduce_next_async(final T generic_any_1, final T result, final U current, final U next) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_struct
   * Returns value from a struct
   * @param  {struct-2} vstruct
   * @param  {string} key
   * @return {any-1}
   * (func any<-struct)
   */
  public static interface Func_any_from_struct extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, R extends Core.Type_struct> T f_any_from_struct(final T generic_any_1, final R vstruct, final Core.Type_string key);
  }

  public static class Class_any_from_struct extends Core.Class_base implements Func_any_from_struct {

    @Override
    public Func_any_from_struct vx_new(Object... vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    @Override
    public Func_any_from_struct vx_copy(Object... vals) {
      Class_any_from_struct output = new Class_any_from_struct();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "any<-struct", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_any_from_struct vx_empty() {return e_any_from_struct;}
    @Override
    public Func_any_from_struct vx_type() {return t_any_from_struct;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_struct vstruct = Core.f_any_from_any(Core.t_struct, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_any_from_struct(generic_any_1, vstruct, key);
      return output;
    }

    @Override
    public <T extends Core.Type_any, R extends Core.Type_struct> T f_any_from_struct(final T generic_any_1, final R vstruct, final Core.Type_string key) {
      return Core.f_any_from_struct(generic_any_1, vstruct, key);
    }

  }

  public static final Func_any_from_struct e_any_from_struct = new Core.Class_any_from_struct();
  public static final Func_any_from_struct t_any_from_struct = new Core.Class_any_from_struct();

  public static <T extends Core.Type_any, R extends Core.Type_struct> T f_any_from_struct(final T generic_any_1, final R vstruct, final Core.Type_string key) {
    T output = Core.f_empty(generic_any_1);
    Core.Type_any val = vstruct.vx_any(key);
    output = Core.f_any_from_any(generic_any_1, val);
    return output;
  }

  /**
   * 
   * @async
   * @function async
   * Returns an asynchonous version value. This exists mostly for type-casting.
   * @param  {any-1} value
   * @return {any-1}
   * (func async)
   */
  public static interface Func_async extends Core.Func_any_from_any_async {
    public <T extends Core.Type_any> CompletableFuture<T> f_async(final T generic_any_1, final T value);
  }

  public static class Class_async extends Core.Class_base implements Func_async {

    @Override
    public Func_async vx_new(Object... vals) {
      Class_async output = new Class_async();
      return output;
    }

    @Override
    public Func_async vx_copy(Object... vals) {
      Class_async output = new Class_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_async vx_empty() {return e_async;}
    @Override
    public Func_async vx_type() {return t_async;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      T inputval = Core.f_any_from_any(generic_any_1, value);
      CompletableFuture<T> output = Core.f_async(generic_any_1, inputval);
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_async(generic_any_1, value);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any> CompletableFuture<T> f_async(final T generic_any_1, final T value) {
      return Core.f_async(generic_any_1, value);
    }

  }

  public static final Func_async e_async = new Core.Class_async();
  public static final Func_async t_async = new Core.Class_async();

  public static <T extends Core.Type_any> CompletableFuture<T> f_async(final T generic_any_1, final T value) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    output = Core.async_new_completed(value);
    return output;
  }

  /**
   * @function boolean_permission_from_func
   * Returns true if the given func has permission.
   * @param  {func} func
   * @return {boolean}
   * (func boolean-permission<-func)
   */
  public static interface Func_boolean_permission_from_func extends Core.Func_any_from_any_context {
    public Core.Type_boolean f_boolean_permission_from_func(final Core.Type_context context, final Core.Type_func func);
  }

  public static class Class_boolean_permission_from_func extends Core.Class_base implements Func_boolean_permission_from_func {

    @Override
    public Func_boolean_permission_from_func vx_new(Object... vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    @Override
    public Func_boolean_permission_from_func vx_copy(Object... vals) {
      Class_boolean_permission_from_func output = new Class_boolean_permission_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "boolean-permission<-func", // name
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
    public Func_boolean_permission_from_func vx_empty() {return e_boolean_permission_from_func;}
    @Override
    public Func_boolean_permission_from_func vx_type() {return t_boolean_permission_from_func;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_func inputval = (Core.Type_func)value;
      Core.Type_any outputval = Core.f_boolean_permission_from_func(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_func func = Core.f_any_from_any(Core.t_func, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_boolean_permission_from_func(context, func);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_permission_from_func(final Core.Type_context context, final Core.Type_func func) {
      return Core.f_boolean_permission_from_func(context, func);
    }

  }

  public static final Func_boolean_permission_from_func e_boolean_permission_from_func = new Core.Class_boolean_permission_from_func();
  public static final Func_boolean_permission_from_func t_boolean_permission_from_func = new Core.Class_boolean_permission_from_func();

  public static Core.Type_boolean f_boolean_permission_from_func(final Core.Type_context context, final Core.Type_func func) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_contains_1(
      Core.f_allowfuncs_from_security(
        Core.f_security_from_context(context)
      ),
      func
    );
    return output;
  }

  /**
   * @function boolean_from_any
   * Function Type taking generic any-1 and returning boolean
   * @param  {any-1} value
   * @return {boolean}
   * (func boolean<-any)
   */
  public static interface Func_boolean_from_any extends Core.Type_func, Core.Type_replfunc {
    public Func_boolean_from_any vx_fn_new(Core.Class_boolean_from_any.IFn fn);
    public Core.Type_boolean f_boolean_from_any(final Core.Type_any value);
  }

  public static class Class_boolean_from_any extends Core.Class_base implements Func_boolean_from_any {

    public IFn fn = null;

    @Override
    public Func_boolean_from_any vx_fn_new(Core.Class_boolean_from_any.IFn fn) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      output.fn = fn;
      return output;
    }

    @Override
    public Func_boolean_from_any vx_new(Object... vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    @Override
    public Func_boolean_from_any vx_copy(Object... vals) {
      Class_boolean_from_any output = new Class_boolean_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-any", // name
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
    public Func_boolean_from_any vx_empty() {return e_boolean_from_any;}
    @Override
    public Func_boolean_from_any vx_type() {return t_boolean_from_any;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve(Core.Type_any value);
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_boolean_from_any(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_from_any(final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (fn != null) {
        output = Core.f_any_from_any(Core.t_boolean, fn.resolve(value));
      }
      return output;
    }

  }

  public static final Func_boolean_from_any e_boolean_from_any = new Core.Class_boolean_from_any();
  public static final Func_boolean_from_any t_boolean_from_any = new Core.Class_boolean_from_any();

  public static Core.Type_boolean f_boolean_from_any(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_func
   * Function Type returning boolean with any parameters
   * @return {boolean}
   * (func boolean<-func)
   */
  public static interface Func_boolean_from_func extends Core.Type_func, Core.Type_replfunc {
    public Func_boolean_from_func vx_fn_new(Core.Class_any_from_func.IFn fn);
    public Core.Type_boolean f_boolean_from_func();
  }

  public static class Class_boolean_from_func extends Core.Class_base implements Func_boolean_from_func {

    @Override
    public Func_boolean_from_func vx_new(Object... vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    @Override
    public Func_boolean_from_func vx_copy(Object... vals) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-func", // name
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
    public Func_boolean_from_func vx_empty() {return e_boolean_from_func;}
    @Override
    public Func_boolean_from_func vx_type() {return t_boolean_from_func;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve();
    }

    public Core.Class_any_from_func.IFn fn = null;

    @Override
    public Func_boolean_from_func vx_fn_new(Core.Class_any_from_func.IFn fn) {
      Class_boolean_from_func output = new Class_boolean_from_func();
      output.fn = fn;
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_boolean_from_func();
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_from_func() {
      Core.Type_boolean output = Core.c_false;
      if (fn != null) {
        output = Core.f_any_from_any(Core.t_boolean, fn.resolve());
      }
      return output;
    }

  }

  public static final Func_boolean_from_func e_boolean_from_func = new Core.Class_boolean_from_func();
  public static final Func_boolean_from_func t_boolean_from_func = new Core.Class_boolean_from_func();

  public static Core.Type_boolean f_boolean_from_func() {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_from_none
   * Function Type returning boolean with no parameters
   * @return {boolean}
   * (func boolean<-none)
   */
  public static interface Func_boolean_from_none extends Core.Type_func, Core.Type_replfunc {
    public Func_boolean_from_none vx_fn_new(Core.Class_any_from_func.IFn fn);
    public Core.Type_boolean f_boolean_from_none();
  }

  public static class Class_boolean_from_none extends Core.Class_base implements Func_boolean_from_none {

    @Override
    public Func_boolean_from_none vx_new(Object... vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    @Override
    public Func_boolean_from_none vx_copy(Object... vals) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "boolean<-none", // name
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
    public Func_boolean_from_none vx_empty() {return e_boolean_from_none;}
    @Override
    public Func_boolean_from_none vx_type() {return t_boolean_from_none;}

    @FunctionalInterface
    public static interface IFn {
      public Core.Type_any resolve();
    }

    public Core.Class_any_from_func.IFn fn = null;

    @Override
    public Func_boolean_from_none vx_fn_new(Core.Class_any_from_func.IFn fn) {
      Class_boolean_from_none output = new Class_boolean_from_none();
      output.fn = fn;
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_boolean_from_none();
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_from_none() {
      Core.Type_boolean output = Core.c_false;
      if (fn != null) {
        output = Core.f_any_from_any(Core.t_boolean, fn.resolve());
      }
      return output;
    }

  }

  public static final Func_boolean_from_none e_boolean_from_none = new Core.Class_boolean_from_none();
  public static final Func_boolean_from_none t_boolean_from_none = new Core.Class_boolean_from_none();

  public static Core.Type_boolean f_boolean_from_none() {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function case
   * @param  {list-1} values
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  public static interface Func_case extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_thenelse f_case(final Core.Type_list values, final Core.Func_any_from_func fn_any);
  }

  public static class Class_case extends Core.Class_base implements Func_case {

    @Override
    public Func_case vx_new(Object... vals) {
      Class_case output = new Class_case();
      return output;
    }

    @Override
    public Func_case vx_copy(Object... vals) {
      Class_case output = new Class_case();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
    public Func_case vx_empty() {return e_case;}
    @Override
    public Func_case vx_type() {return t_case;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_case(values, fn_any);
      return output;
    }

    @Override
    public Core.Type_thenelse f_case(final Core.Type_list values, final Core.Func_any_from_func fn_any) {
      return Core.f_case(values, fn_any);
    }

  }

  public static final Func_case e_case = new Core.Class_case();
  public static final Func_case t_case = new Core.Class_case();

  public static Core.Type_thenelse f_case(final Core.Type_list values, final Core.Func_any_from_func fn_any) {
    Core.Type_thenelse output = Core.e_thenelse;
    output = Core.f_new(
      Core.t_thenelse,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":code"),
        Core.vx_new_string(":casemany"),
        Core.vx_new_string(":values"),
        values,
        Core.vx_new_string(":fn-any"),
        fn_any
      )
    );
    return output;
  }

  /**
   * @function case 1
   * @param  {any-1} value
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  public static interface Func_case_1 extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_thenelse f_case_1(final Core.Type_any value, final Core.Func_any_from_func fn_any);
  }

  public static class Class_case_1 extends Core.Class_base implements Func_case_1 {

    @Override
    public Func_case_1 vx_new(Object... vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    @Override
    public Func_case_1 vx_copy(Object... vals) {
      Class_case_1 output = new Class_case_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "case", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
    public Func_case_1 vx_empty() {return e_case_1;}
    @Override
    public Func_case_1 vx_type() {return t_case_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_case_1(value, fn_any);
      return output;
    }

    @Override
    public Core.Type_thenelse f_case_1(final Core.Type_any value, final Core.Func_any_from_func fn_any) {
      return Core.f_case_1(value, fn_any);
    }

  }

  public static final Func_case_1 e_case_1 = new Core.Class_case_1();
  public static final Func_case_1 t_case_1 = new Core.Class_case_1();

  public static Core.Type_thenelse f_case_1(final Core.Type_any value, final Core.Func_any_from_func fn_any) {
    Core.Type_thenelse output = Core.e_thenelse;
    output = Core.f_new(
      Core.t_thenelse,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":code"),
        Core.vx_new_string(":case"),
        Core.vx_new_string(":value"),
        value,
        Core.vx_new_string(":fn-any"),
        fn_any
      )
    );
    return output;
  }

  /**
   * @function compare
   * Returns 0 if vals are equal, 1 if val1 > val2, -1 if val1 < val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {int}
   * (func compare)
   */
  public static interface Func_compare extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int f_compare(final Core.Type_any val1, final Core.Type_any val2);
  }

  public static class Class_compare extends Core.Class_base implements Func_compare {

    @Override
    public Func_compare vx_new(Object... vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    @Override
    public Func_compare vx_copy(Object... vals) {
      Class_compare output = new Class_compare();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "compare", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_compare vx_empty() {return e_compare;}
    @Override
    public Func_compare vx_type() {return t_compare;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val2 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_compare(val1, val2);
      return output;
    }

    @Override
    public Core.Type_int f_compare(final Core.Type_any val1, final Core.Type_any val2) {
      return Core.f_compare(val1, val2);
    }

  }

  public static final Func_compare e_compare = new Core.Class_compare();
  public static final Func_compare t_compare = new Core.Class_compare();

  public static Core.Type_int f_compare(final Core.Type_any val1, final Core.Type_any val2) {
    Core.Type_int output = Core.e_int;
    int intresult = 0;
    if ((val1 instanceof Core.Type_number) && (val2 instanceof Core.Type_number)) {
      Core.Type_number num1 = (Core.Type_number)val1;
      Core.Type_number num2 = (Core.Type_number)val2;
      float float1 = Core.t_float.vx_new(num1).vx_float();
      float float2 = Core.t_float.vx_new(num2).vx_float();
      if (float1 < float2) {
        intresult = -1;
      } else if (float1 > float2) {
        intresult = 1;
      }
    } else {
      String stringval1 = Core.f_string_from_any(val1).vx_string();
      String stringval2 = Core.f_string_from_any(val2).vx_string();
      int compare = stringval1.compareTo(stringval2);
      if (compare > 0) {
        intresult = 1;
      } else if (compare < 0) {
        intresult = -1;
      }
    }
    output = Core.vx_new_int(intresult);
    return output;
  }

  /**
   * @function contains
   * Returns true if the given list contains the given value.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   * (func contains)
   */
  public static interface Func_contains extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_contains(final Core.Type_string text, final Core.Type_string find);
  }

  public static class Class_contains extends Core.Class_base implements Func_contains {

    @Override
    public Func_contains vx_new(Object... vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    @Override
    public Func_contains vx_copy(Object... vals) {
      Class_contains output = new Class_contains();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
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
    public Func_contains vx_empty() {return e_contains;}
    @Override
    public Func_contains vx_type() {return t_contains;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_contains(text, find);
      return output;
    }

    @Override
    public Core.Type_boolean f_contains(final Core.Type_string text, final Core.Type_string find) {
      return Core.f_contains(text, find);
    }

  }

  public static final Func_contains e_contains = new Core.Class_contains();
  public static final Func_contains t_contains = new Core.Class_contains();

  public static Core.Type_boolean f_contains(final Core.Type_string text, final Core.Type_string find) {
    Core.Type_boolean output = Core.e_boolean;
    boolean check = vx_boolean_from_string_find(text.vx_string(), find.vx_string());
    output = Core.vx_new_boolean(check);
    return output;
  }

  /**
   * @function contains 1
   * Returns true if the given list contains the given value.
   * @param  {list-2} values Any list
   * @param  {any} find Any value
   * @return {boolean}
   * (func contains)
   */
  public static interface Func_contains_1 extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_contains_1(final Core.Type_list values, final Core.Type_any find);
  }

  public static class Class_contains_1 extends Core.Class_base implements Func_contains_1 {

    @Override
    public Func_contains_1 vx_new(Object... vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    @Override
    public Func_contains_1 vx_copy(Object... vals) {
      Class_contains_1 output = new Class_contains_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        1, // idx
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
    public Func_contains_1 vx_empty() {return e_contains_1;}
    @Override
    public Func_contains_1 vx_type() {return t_contains_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any find = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_contains_1(values, find);
      return output;
    }

    @Override
    public Core.Type_boolean f_contains_1(final Core.Type_list values, final Core.Type_any find) {
      return Core.f_contains_1(values, find);
    }

  }

  public static final Func_contains_1 e_contains_1 = new Core.Class_contains_1();
  public static final Func_contains_1 t_contains_1 = new Core.Class_contains_1();

  public static Core.Type_boolean f_contains_1(final Core.Type_list values, final Core.Type_any find) {
    Core.Type_boolean output = Core.e_boolean;
    boolean booleanresult = false;
    List<Core.Type_any> listvalues = values.vx_list();
    for (Core.Type_any item : listvalues) {
      Core.Type_boolean iseq = Core.f_eq(item, find);
      if (iseq.vx_boolean()) {
        booleanresult = true;
        break;
      }
    }
    output = Core.vx_new_boolean(booleanresult);
    return output;
  }

  /**
   * @function context_main
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-main)
   */
  public static interface Func_context_main extends Core.Func_any_from_any {
    public Core.Type_context f_context_main(final Core.Type_anylist args);
  }

  public static class Class_context_main extends Core.Class_base implements Func_context_main {

    @Override
    public Func_context_main vx_new(Object... vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    @Override
    public Func_context_main vx_copy(Object... vals) {
      Class_context_main output = new Class_context_main();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "context-main", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
    public Func_context_main vx_empty() {return e_context_main;}
    @Override
    public Func_context_main vx_type() {return t_context_main;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_context_main(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_context_main(args);
      return output;
    }

    @Override
    public Core.Type_context f_context_main(final Core.Type_anylist args) {
      return Core.f_context_main(args);
    }

  }

  public static final Func_context_main e_context_main = new Core.Class_context_main();
  public static final Func_context_main t_context_main = new Core.Class_context_main();

  public static Core.Type_context f_context_main(final Core.Type_anylist args) {
    Core.Type_context output = Core.e_context;
    output = Core.f_empty(
      Core.t_context
    );
    return output;
  }

  /**
   * @function copy
   * Returns a copy of a given value with the given values added or updated.
   * @param  {any} value
   * @param  {anylist} values
   * @return {any-1}
   * (func copy)
   */
  public static interface Func_copy extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_copy(final Core.Type_any value, final Core.Type_anylist values);
  }

  public static class Class_copy extends Core.Class_base implements Func_copy {

    @Override
    public Func_copy vx_new(Object... vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    @Override
    public Func_copy vx_copy(Object... vals) {
      Class_copy output = new Class_copy();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "copy", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_copy vx_empty() {return e_copy;}
    @Override
    public Func_copy vx_type() {return t_copy;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_copy(value, values);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_copy(final Core.Type_any value, final Core.Type_anylist values) {
      return Core.f_copy(value, values);
    }

  }

  public static final Func_copy e_copy = new Core.Class_copy();
  public static final Func_copy t_copy = new Core.Class_copy();

  @SuppressWarnings("unchecked")
  public static <T extends Core.Type_any> T f_copy(final Core.Type_any value, final Core.Type_anylist values) {
    Core.Type_any[] arrayany = Core.arrayany_from_anylist(values);
    Object[] arrayobj = (Core.Type_any[])arrayany;
    T output = (T)(value.vx_copy(arrayobj));
    return output;
  }

  /**
   * @function else
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func else)
   */
  public static interface Func_else extends Core.Func_any_from_any {
    public Core.Type_thenelse f_else(final Core.Func_any_from_func fn_any);
  }

  public static class Class_else extends Core.Class_base implements Func_else {

    @Override
    public Func_else vx_new(Object... vals) {
      Class_else output = new Class_else();
      return output;
    }

    @Override
    public Func_else vx_copy(Object... vals) {
      Class_else output = new Class_else();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "else", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
    public Func_else vx_empty() {return e_else;}
    @Override
    public Func_else vx_type() {return t_else;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func inputval = (Core.Func_any_from_func)value;
      Core.Type_any outputval = Core.f_else(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_else(fn_any);
      return output;
    }

    @Override
    public Core.Type_thenelse f_else(final Core.Func_any_from_func fn_any) {
      return Core.f_else(fn_any);
    }

  }

  public static final Func_else e_else = new Core.Class_else();
  public static final Func_else t_else = new Core.Class_else();

  public static Core.Type_thenelse f_else(final Core.Func_any_from_func fn_any) {
    Core.Type_thenelse output = Core.e_thenelse;
    output = Core.f_new(
      Core.t_thenelse,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":code"),
        Core.vx_new_string(":else"),
        Core.vx_new_string(":fn-any"),
        fn_any
      )
    );
    return output;
  }

  /**
   * @function empty
   * Returns the empty value for a given type. Can be called using (empty type) or simply (type)
   * @param  {any-1} type
   * @return {any-1}
   * (func empty)
   */
  public static interface Func_empty extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T f_empty(final T type);
  }

  public static class Class_empty extends Core.Class_base implements Func_empty {

    @Override
    public Func_empty vx_new(Object... vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    @Override
    public Func_empty vx_copy(Object... vals) {
      Class_empty output = new Class_empty();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "empty", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_empty vx_empty() {return e_empty;}
    @Override
    public Func_empty vx_type() {return t_empty;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_empty(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_empty(type);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_empty(final T type) {
      return Core.f_empty(type);
    }

  }

  public static final Func_empty e_empty = new Core.Class_empty();
  public static final Func_empty t_empty = new Core.Class_empty();

  @SuppressWarnings("unchecked")
  public static <T extends Core.Type_any> T f_empty(final T type) {
    T output = (T)(type.vx_empty());
    return output;
  }

  /**
   * @function extends_from_any
   * @param  {any-1} val
   * @return {string}
   * (func extends<-any)
   */
  public static interface Func_extends_from_any extends Core.Func_any_from_any {
    public Core.Type_string f_extends_from_any(final Core.Type_any val);
  }

  public static class Class_extends_from_any extends Core.Class_base implements Func_extends_from_any {

    @Override
    public Func_extends_from_any vx_new(Object... vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    @Override
    public Func_extends_from_any vx_copy(Object... vals) {
      Class_extends_from_any output = new Class_extends_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "extends<-any", // name
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
    public Func_extends_from_any vx_empty() {return e_extends_from_any;}
    @Override
    public Func_extends_from_any vx_type() {return t_extends_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_extends_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_extends_from_any(val);
      return output;
    }

    @Override
    public Core.Type_string f_extends_from_any(final Core.Type_any val) {
      return Core.f_extends_from_any(val);
    }

  }

  public static final Func_extends_from_any e_extends_from_any = new Core.Class_extends_from_any();
  public static final Func_extends_from_any t_extends_from_any = new Core.Class_extends_from_any();

  public static Core.Type_string f_extends_from_any(final Core.Type_any val) {
    Core.Type_string output = Core.e_string;
    output = Core.f_extends_from_typedef(
      Core.f_typedef_from_any(val)
    );
    return output;
  }

  /**
   * @function extends_from_typedef
   * Get the basetype of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   * (func extends<-typedef)
   */
  public static interface Func_extends_from_typedef extends Core.Func_any_from_any {
    public Core.Type_string f_extends_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_extends_from_typedef extends Core.Class_base implements Func_extends_from_typedef {

    @Override
    public Func_extends_from_typedef vx_new(Object... vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    @Override
    public Func_extends_from_typedef vx_copy(Object... vals) {
      Class_extends_from_typedef output = new Class_extends_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "extends<-typedef", // name
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
    public Func_extends_from_typedef vx_empty() {return e_extends_from_typedef;}
    @Override
    public Func_extends_from_typedef vx_type() {return t_extends_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_extends_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_extends_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_string f_extends_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_extends_from_typedef(vtypedef);
    }

  }

  public static final Func_extends_from_typedef e_extends_from_typedef = new Core.Class_extends_from_typedef();
  public static final Func_extends_from_typedef t_extends_from_typedef = new Core.Class_extends_from_typedef();

  public static Core.Type_string f_extends_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_string output = Core.e_string;
    output = vtypedef.extend();
    return output;
  }

  /**
   * @function first_from_list
   * Returns first value
   * @param  {list-1} values
   * @return {any-1}
   * (func first<-list)
   */
  public static interface Func_first_from_list extends Core.Func_any_from_any {
    public <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list(final T generic_any_1, final X values);
  }

  public static class Class_first_from_list extends Core.Class_base implements Func_first_from_list {

    @Override
    public Func_first_from_list vx_new(Object... vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    @Override
    public Func_first_from_list vx_copy(Object... vals) {
      Class_first_from_list output = new Class_first_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "first<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_first_from_list vx_empty() {return e_first_from_list;}
    @Override
    public Func_first_from_list vx_type() {return t_first_from_list;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_list inputval = (Core.Type_list)value;
      Core.Type_any outputval = Core.f_first_from_list(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_first_from_list(generic_any_1, values);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list(final T generic_any_1, final X values) {
      return Core.f_first_from_list(generic_any_1, values);
    }

  }

  public static final Func_first_from_list e_first_from_list = new Core.Class_first_from_list();
  public static final Func_first_from_list t_first_from_list = new Core.Class_first_from_list();

  public static <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list(final T generic_any_1, final X values) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_any_from_list(generic_any_1, values, Core.vx_new_int(1));
    return output;
  }

  /**
   * @function first_from_list_any_from_any
   * Returns first value that is not nothing
   * @param  {list-1} values
   * @param  {any<-any} fn-any<-any
   * @return {any-1}
   * (func first<-list-any<-any)
   */
  public static interface Func_first_from_list_any_from_any extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list_any_from_any(final T generic_any_1, final X values, final Core.Func_any_from_any fn_any_from_any);
  }

  public static class Class_first_from_list_any_from_any extends Core.Class_base implements Func_first_from_list_any_from_any {

    @Override
    public Func_first_from_list_any_from_any vx_new(Object... vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    @Override
    public Func_first_from_list_any_from_any vx_copy(Object... vals) {
      Class_first_from_list_any_from_any output = new Class_first_from_list_any_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "first<-list-any<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_first_from_list_any_from_any vx_empty() {return e_first_from_list_any_from_any;}
    @Override
    public Func_first_from_list_any_from_any vx_type() {return t_first_from_list_any_from_any;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any fn_any_from_any = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list_any_from_any(final T generic_any_1, final X values, final Core.Func_any_from_any fn_any_from_any) {
      return Core.f_first_from_list_any_from_any(generic_any_1, values, fn_any_from_any);
    }

  }

  public static final Func_first_from_list_any_from_any e_first_from_list_any_from_any = new Core.Class_first_from_list_any_from_any();
  public static final Func_first_from_list_any_from_any t_first_from_list_any_from_any = new Core.Class_first_from_list_any_from_any();

  public static <T extends Core.Type_any, X extends Core.Type_list> T f_first_from_list_any_from_any(final T generic_any_1, final X values, final Core.Func_any_from_any fn_any_from_any) {
    T output = Core.f_empty(generic_any_1);
    List<Core.Type_any> listvalue = values.vx_list();
    for (Core.Type_any value : listvalue) {
      if (value != Core.c_nothing) {
        output = fn_any_from_any.f_any_from_any(generic_any_1, value);
        break;
      }
    };
    return output;
  }

  /**
   * @function float_from_string
   * Returns float from a given string.
   * @param  {string} text
   * @return {float}
   * (func float<-string)
   */
  public static interface Func_float_from_string extends Core.Func_any_from_any {
    public Core.Type_float f_float_from_string(final Core.Type_string text);
  }

  public static class Class_float_from_string extends Core.Class_base implements Func_float_from_string {

    @Override
    public Func_float_from_string vx_new(Object... vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    @Override
    public Func_float_from_string vx_copy(Object... vals) {
      Class_float_from_string output = new Class_float_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "float<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "float", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_float_from_string vx_empty() {return e_float_from_string;}
    @Override
    public Func_float_from_string vx_type() {return t_float_from_string;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_float_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_float_from_string(text);
      return output;
    }

    @Override
    public Core.Type_float f_float_from_string(final Core.Type_string text) {
      return Core.f_float_from_string(text);
    }

  }

  public static final Func_float_from_string e_float_from_string = new Core.Class_float_from_string();
  public static final Func_float_from_string t_float_from_string = new Core.Class_float_from_string();

  public static Core.Type_float f_float_from_string(final Core.Type_string text) {
    Core.Type_float output = Core.e_float;
    float num = Core.vx_float_from_string(text.vx_string());
    output = Core.vx_new_float(num);
    return output;
  }

  /**
   * @function fn
   * Shell for lambda function calls
   * @param  {arglist} params
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func fn)
   */
  public static interface Func_fn extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_fn(final T generic_any_1, final Core.Type_arglist params, final Core.Func_any_from_func fn_any);
  }

  public static class Class_fn extends Core.Class_base implements Func_fn {

    @Override
    public Func_fn vx_new(Object... vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    @Override
    public Func_fn vx_copy(Object... vals) {
      Class_fn output = new Class_fn();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "fn", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_fn vx_empty() {return e_fn;}
    @Override
    public Func_fn vx_type() {return t_fn;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_arglist params = Core.f_any_from_any(Core.t_arglist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_fn(generic_any_1, params, fn_any);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_fn(final T generic_any_1, final Core.Type_arglist params, final Core.Func_any_from_func fn_any) {
      return Core.f_fn(generic_any_1, params, fn_any);
    }

  }

  public static final Func_fn e_fn = new Core.Class_fn();
  public static final Func_fn t_fn = new Core.Class_fn();

  public static <T extends Core.Type_any> T f_fn(final T generic_any_1, final Core.Type_arglist params, final Core.Func_any_from_func fn_any) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function funcdef_from_func
   * @param  {func} val
   * @return {funcdef}
   * (func funcdef<-func)
   */
  public static interface Func_funcdef_from_func extends Core.Func_any_from_any {
    public Core.Type_funcdef f_funcdef_from_func(final Core.Type_func val);
  }

  public static class Class_funcdef_from_func extends Core.Class_base implements Func_funcdef_from_func {

    @Override
    public Func_funcdef_from_func vx_new(Object... vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    @Override
    public Func_funcdef_from_func vx_copy(Object... vals) {
      Class_funcdef_from_func output = new Class_funcdef_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "funcdef<-func", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "funcdef", // name
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
    public Func_funcdef_from_func vx_empty() {return e_funcdef_from_func;}
    @Override
    public Func_funcdef_from_func vx_type() {return t_funcdef_from_func;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_func inputval = (Core.Type_func)value;
      Core.Type_any outputval = Core.f_funcdef_from_func(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_func val = Core.f_any_from_any(Core.t_func, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_funcdef_from_func(val);
      return output;
    }

    @Override
    public Core.Type_funcdef f_funcdef_from_func(final Core.Type_func val) {
      return Core.f_funcdef_from_func(val);
    }

  }

  public static final Func_funcdef_from_func e_funcdef_from_func = new Core.Class_funcdef_from_func();
  public static final Func_funcdef_from_func t_funcdef_from_func = new Core.Class_funcdef_from_func();

  public static Core.Type_funcdef f_funcdef_from_func(final Core.Type_func val) {
    Core.Type_funcdef output = Core.e_funcdef;
    output = val.vx_funcdef();
    return output;
  }

  /**
   * @function funcname_from_funcdef
   * Get the name of a given funcdef
   * @param  {funcdef} funcdef
   * @return {string}
   * (func funcname<-funcdef)
   */
  public static interface Func_funcname_from_funcdef extends Core.Func_any_from_any {
    public Core.Type_string f_funcname_from_funcdef(final Core.Type_funcdef funcdef);
  }

  public static class Class_funcname_from_funcdef extends Core.Class_base implements Func_funcname_from_funcdef {

    @Override
    public Func_funcname_from_funcdef vx_new(Object... vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    @Override
    public Func_funcname_from_funcdef vx_copy(Object... vals) {
      Class_funcname_from_funcdef output = new Class_funcname_from_funcdef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "funcname<-funcdef", // name
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
    public Func_funcname_from_funcdef vx_empty() {return e_funcname_from_funcdef;}
    @Override
    public Func_funcname_from_funcdef vx_type() {return t_funcname_from_funcdef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_funcdef inputval = (Core.Type_funcdef)value;
      Core.Type_any outputval = Core.f_funcname_from_funcdef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_funcdef funcdef = Core.f_any_from_any(Core.t_funcdef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_funcname_from_funcdef(funcdef);
      return output;
    }

    @Override
    public Core.Type_string f_funcname_from_funcdef(final Core.Type_funcdef funcdef) {
      return Core.f_funcname_from_funcdef(funcdef);
    }

  }

  public static final Func_funcname_from_funcdef e_funcname_from_funcdef = new Core.Class_funcname_from_funcdef();
  public static final Func_funcname_from_funcdef t_funcname_from_funcdef = new Core.Class_funcname_from_funcdef();

  public static Core.Type_string f_funcname_from_funcdef(final Core.Type_funcdef funcdef) {
    Core.Type_string output = Core.e_string;
    output = Core.f_new(
      Core.t_string,
      Core.t_anylist.vx_new(
        funcdef.pkgname(),
        Core.vx_new_string("/"),
        funcdef.name()
      )
    );
    return output;
  }

  /**
   * @function if
   * Logical If function
   * @param  {boolean} clause
   * @param  {any-1} then
   * @return {any-1}
   * (func if)
   */
  public static interface Func_if extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_if(final T generic_any_1, final Core.Type_boolean clause, final T then);
  }

  public static class Class_if extends Core.Class_base implements Func_if {

    @Override
    public Func_if vx_new(Object... vals) {
      Class_if output = new Class_if();
      return output;
    }

    @Override
    public Func_if vx_copy(Object... vals) {
      Class_if output = new Class_if();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_if vx_empty() {return e_if;}
    @Override
    public Func_if vx_type() {return t_if;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_boolean clause = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any then = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_if(generic_any_1, clause, then);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_if(final T generic_any_1, final Core.Type_boolean clause, final T then) {
      return Core.f_if(generic_any_1, clause, then);
    }

  }

  public static final Func_if e_if = new Core.Class_if();
  public static final Func_if t_if = new Core.Class_if();

  public static <T extends Core.Type_any> T f_if(final T generic_any_1, final Core.Type_boolean clause, final T then) {
    T output = Core.f_empty(generic_any_1);
    if (clause.vx_boolean()) {
      output = then;
    };
    return output;
  }

  /**
   * @function if 1
   * Logical If function
   * @param  {boolean} clause
   * @param  {any-1} thenval
   * @param  {any-1} elseval
   * @return {any-1}
   * (func if)
   */
  public static interface Func_if_1 extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_if_1(final T generic_any_1, final Core.Type_boolean clause, final T thenval, final T elseval);
  }

  public static class Class_if_1 extends Core.Class_base implements Func_if_1 {

    @Override
    public Func_if_1 vx_new(Object... vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    @Override
    public Func_if_1 vx_copy(Object... vals) {
      Class_if_1 output = new Class_if_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_if_1 vx_empty() {return e_if_1;}
    @Override
    public Func_if_1 vx_type() {return t_if_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_boolean clause = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any thenval = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_any elseval = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_if_1(generic_any_1, clause, thenval, elseval);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_if_1(final T generic_any_1, final Core.Type_boolean clause, final T thenval, final T elseval) {
      return Core.f_if_1(generic_any_1, clause, thenval, elseval);
    }

  }

  public static final Func_if_1 e_if_1 = new Core.Class_if_1();
  public static final Func_if_1 t_if_1 = new Core.Class_if_1();

  public static <T extends Core.Type_any> T f_if_1(final T generic_any_1, final Core.Type_boolean clause, final T thenval, final T elseval) {
    T output = Core.f_empty(generic_any_1);
    if (clause.vx_boolean()) {
      output = thenval;
    } else {
      output = elseval;
    };
    return output;
  }

  /**
   * @function if 2
   * Logical If function
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func if)
   */
  public static interface Func_if_2 extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T f_if_2(final T generic_any_1, final Core.Type_thenelselist thenelselist);
  }

  public static class Class_if_2 extends Core.Class_base implements Func_if_2 {

    @Override
    public Func_if_2 vx_new(Object... vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    @Override
    public Func_if_2 vx_copy(Object... vals) {
      Class_if_2 output = new Class_if_2();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "if", // name
        2, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_if_2 vx_empty() {return e_if_2;}
    @Override
    public Func_if_2 vx_type() {return t_if_2;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_thenelselist inputval = (Core.Type_thenelselist)value;
      Core.Type_any outputval = Core.f_if_2(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_thenelselist thenelselist = Core.f_any_from_any(Core.t_thenelselist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_if_2(generic_any_1, thenelselist);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_if_2(final T generic_any_1, final Core.Type_thenelselist thenelselist) {
      return Core.f_if_2(generic_any_1, thenelselist);
    }

  }

  public static final Func_if_2 e_if_2 = new Core.Class_if_2();
  public static final Func_if_2 t_if_2 = new Core.Class_if_2();

  public static <T extends Core.Type_any> T f_if_2(final T generic_any_1, final Core.Type_thenelselist thenelselist) {
    T output = Core.f_empty(generic_any_1);
    Core.Func_any_from_func fn_any = Core.Class_list.vx_any_first_from_list_fn(Core.t_any_from_func, thenelselist, (any) -> {
      Core.Func_any_from_func fnany = null;
      if (any instanceof Core.Type_thenelse) {
        Core.Type_thenelse thenelse = (Core.Type_thenelse)any;
        Core.Type_string code = thenelse.code();
        switch (code.vx_string()) {
        case ":then":
          Core.Func_boolean_from_func fn_cond = thenelse.fn_cond();
          Core.Type_boolean cond = fn_cond.f_boolean_from_func();
          if (cond.vx_boolean() == true) {
            fnany = thenelse.fn_any();
          }
          break;
        case ":else":
          fnany = thenelse.fn_any();
          break;
        }
      }
      return fnany;
    });
    if (fn_any != null) {
      output = fn_any.f_any_from_func(generic_any_1);
    };
    return output;
  }

  /**
   * @function int_from_func
   * Function Type returning int with any parameters
   * @return {int}
   * (func int<-func)
   */
  public static interface Func_int_from_func extends Core.Type_func, Core.Type_replfunc {
    public Func_int_from_func vx_fn_new(Core.Class_any_from_func.IFn fn);
    public Core.Type_int f_int_from_func();
  }

  public static class Class_int_from_func extends Core.Class_base implements Func_int_from_func {

    @Override
    public Func_int_from_func vx_new(Object... vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    @Override
    public Func_int_from_func vx_copy(Object... vals) {
      Class_int_from_func output = new Class_int_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "int<-func", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_int_from_func vx_empty() {return e_int_from_func;}
    @Override
    public Func_int_from_func vx_type() {return t_int_from_func;}

    public Core.Class_any_from_func.IFn fn = null;

    @Override
    public Func_int_from_func vx_fn_new(Core.Class_any_from_func.IFn fn) {
      Class_int_from_func output = new Class_int_from_func();
      output.fn = fn;
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_int_from_func();
      return output;
    }

    @Override
    public Core.Type_int f_int_from_func() {
      return Core.f_int_from_func();
    }

  }

  public static final Func_int_from_func e_int_from_func = new Core.Class_int_from_func();
  public static final Func_int_from_func t_int_from_func = new Core.Class_int_from_func();

  public static Core.Type_int f_int_from_func() {
    Core.Type_int output = Core.e_int;
    return output;
  }

  /**
   * @function int_from_string
   * Function Type converting string to int
   * @param  {string} val
   * @return {int}
   * (func int<-string)
   */
  public static interface Func_int_from_string extends Core.Func_any_from_any {
    public Core.Type_int f_int_from_string(final Core.Type_string val);
  }

  public static class Class_int_from_string extends Core.Class_base implements Func_int_from_string {

    @Override
    public Func_int_from_string vx_new(Object... vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    @Override
    public Func_int_from_string vx_copy(Object... vals) {
      Class_int_from_string output = new Class_int_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "int<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_int_from_string vx_empty() {return e_int_from_string;}
    @Override
    public Func_int_from_string vx_type() {return t_int_from_string;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_int_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string val = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_int_from_string(val);
      return output;
    }

    @Override
    public Core.Type_int f_int_from_string(final Core.Type_string val) {
      return Core.f_int_from_string(val);
    }

  }

  public static final Func_int_from_string e_int_from_string = new Core.Class_int_from_string();
  public static final Func_int_from_string t_int_from_string = new Core.Class_int_from_string();

  public static Core.Type_int f_int_from_string(final Core.Type_string val) {
    Core.Type_int output = Core.e_int;
    output = Core.f_switch(
      Core.t_int,
      val,
      Core.t_thenelselist.vx_new(
        Core.f_case_1(
          Core.vx_new_string("notanumber"),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.c_notanumber;
          })
        ),
        Core.f_case_1(
          Core.vx_new_string("infinity"),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.c_infinity;
          })
        ),
        Core.f_case_1(
          Core.vx_new_string("neginfinity"),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.c_neginfinity;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {int intresult = 0;
            String strval = val.vx_string();
            try {
              float floatresult = Float.parseFloat(strval);
              intresult = (int)floatresult;
              return Core.vx_new_int(intresult);
            } catch (Exception ex) {
              return Core.c_notanumber;
            }
          })
        )
      )
    );
    return output;
  }

  /**
   * @function is_empty
   * Returns true if text is empty.
   * @param  {string} text
   * @return {boolean}
   * (func is-empty)
   */
  public static interface Func_is_empty extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_empty(final Core.Type_string text);
  }

  public static class Class_is_empty extends Core.Class_base implements Func_is_empty {

    @Override
    public Func_is_empty vx_new(Object... vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    @Override
    public Func_is_empty vx_copy(Object... vals) {
      Class_is_empty output = new Class_is_empty();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
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
    public Func_is_empty vx_empty() {return e_is_empty;}
    @Override
    public Func_is_empty vx_type() {return t_is_empty;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_is_empty(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_empty(text);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_empty(final Core.Type_string text) {
      return Core.f_is_empty(text);
    }

  }

  public static final Func_is_empty e_is_empty = new Core.Class_is_empty();
  public static final Func_is_empty t_is_empty = new Core.Class_is_empty();

  public static Core.Type_boolean f_is_empty(final Core.Type_string text) {
    Core.Type_boolean output = Core.e_boolean;
    if (text.vx_string().length() == 0) {
      output = Core.c_true;
    };
    return output;
  }

  /**
   * @function is_empty 1
   * Returns true if an value is empty
   * @param  {any} value
   * @return {boolean}
   * (func is-empty)
   */
  public static interface Func_is_empty_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_empty_1(final Core.Type_any value);
  }

  public static class Class_is_empty_1 extends Core.Class_base implements Func_is_empty_1 {

    @Override
    public Func_is_empty_1 vx_new(Object... vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    @Override
    public Func_is_empty_1 vx_copy(Object... vals) {
      Class_is_empty_1 output = new Class_is_empty_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        1, // idx
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
    public Func_is_empty_1 vx_empty() {return e_is_empty_1;}
    @Override
    public Func_is_empty_1 vx_type() {return t_is_empty_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_is_empty_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_empty_1(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_empty_1(final Core.Type_any value) {
      return Core.f_is_empty_1(value);
    }

  }

  public static final Func_is_empty_1 e_is_empty_1 = new Core.Class_is_empty_1();
  public static final Func_is_empty_1 t_is_empty_1 = new Core.Class_is_empty_1();

  public static Core.Type_boolean f_is_empty_1(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    if (value == value.vx_empty()) {
      output = Core.c_true;
    } else {
      output = Core.c_false;
    };
    return output;
  }

  /**
   * @function is_endswith
   * Returns true if text ends with find.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   * (func is-endswith)
   */
  public static interface Func_is_endswith extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_is_endswith(final Core.Type_string text, final Core.Type_string find);
  }

  public static class Class_is_endswith extends Core.Class_base implements Func_is_endswith {

    @Override
    public Func_is_endswith vx_new(Object... vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    @Override
    public Func_is_endswith vx_copy(Object... vals) {
      Class_is_endswith output = new Class_is_endswith();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-endswith", // name
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
    public Func_is_endswith vx_empty() {return e_is_endswith;}
    @Override
    public Func_is_endswith vx_type() {return t_is_endswith;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_is_endswith(text, find);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_endswith(final Core.Type_string text, final Core.Type_string find) {
      return Core.f_is_endswith(text, find);
    }

  }

  public static final Func_is_endswith e_is_endswith = new Core.Class_is_endswith();
  public static final Func_is_endswith t_is_endswith = new Core.Class_is_endswith();

  public static Core.Type_boolean f_is_endswith(final Core.Type_string text, final Core.Type_string find) {
    Core.Type_boolean output = Core.e_boolean;
    String stext = text.vx_string();
    String sfind = find.vx_string();
    if (stext.endsWith(sfind)) {
      output = Core.c_true;
    };
    return output;
  }

  /**
   * @function is_float
   * Returns true if the value is a float.
   * @param  {any} value
   * @return {boolean}
   * (func is-float)
   */
  public static interface Func_is_float extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_float(final Core.Type_any value);
  }

  public static class Class_is_float extends Core.Class_base implements Func_is_float {

    @Override
    public Func_is_float vx_new(Object... vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    @Override
    public Func_is_float vx_copy(Object... vals) {
      Class_is_float output = new Class_is_float();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-float", // name
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
    public Func_is_float vx_empty() {return e_is_float;}
    @Override
    public Func_is_float vx_type() {return t_is_float;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_is_float(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_float(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_float(final Core.Type_any value) {
      return Core.f_is_float(value);
    }

  }

  public static final Func_is_float e_is_float = new Core.Class_is_float();
  public static final Func_is_float t_is_float = new Core.Class_is_float();

  public static Core.Type_boolean f_is_float(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    boolean result = Core.vx_is_float(value);
    output = Core.vx_new_boolean(result);
    return output;
  }

  /**
   * @function is_func
   * Returns true if val is a function.
   * @param  {any} val
   * @return {boolean}
   * (func is-func)
   */
  public static interface Func_is_func extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_func(final Core.Type_any val);
  }

  public static class Class_is_func extends Core.Class_base implements Func_is_func {

    @Override
    public Func_is_func vx_new(Object... vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    @Override
    public Func_is_func vx_copy(Object... vals) {
      Class_is_func output = new Class_is_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-func", // name
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
    public Func_is_func vx_empty() {return e_is_func;}
    @Override
    public Func_is_func vx_type() {return t_is_func;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_is_func(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_func(val);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_func(final Core.Type_any val) {
      return Core.f_is_func(val);
    }

  }

  public static final Func_is_func e_is_func = new Core.Class_is_func();
  public static final Func_is_func t_is_func = new Core.Class_is_func();

  public static Core.Type_boolean f_is_func(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    if (val instanceof Core.Type_func) {
      output = Core.c_true;
    };
    return output;
  }

  /**
   * @function is_int
   * Returns true if the value is an integer.
   * @param  {any} value
   * @return {boolean}
   * (func is-int)
   */
  public static interface Func_is_int extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_int(final Core.Type_any value);
  }

  public static class Class_is_int extends Core.Class_base implements Func_is_int {

    @Override
    public Func_is_int vx_new(Object... vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    @Override
    public Func_is_int vx_copy(Object... vals) {
      Class_is_int output = new Class_is_int();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-int", // name
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
    public Func_is_int vx_empty() {return e_is_int;}
    @Override
    public Func_is_int vx_type() {return t_is_int;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_is_int(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_int(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_int(final Core.Type_any value) {
      return Core.f_is_int(value);
    }

  }

  public static final Func_is_int e_is_int = new Core.Class_is_int();
  public static final Func_is_int t_is_int = new Core.Class_is_int();

  public static Core.Type_boolean f_is_int(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    boolean result = Core.vx_is_int(value);
    output = Core.vx_new_boolean(result);
    return output;
  }

  /**
   * @function is_number
   * Return true if val is a number
   * @param  {any} value
   * @return {boolean}
   * (func is-number)
   */
  public static interface Func_is_number extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_number(final Core.Type_any value);
  }

  public static class Class_is_number extends Core.Class_base implements Func_is_number {

    @Override
    public Func_is_number vx_new(Object... vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    @Override
    public Func_is_number vx_copy(Object... vals) {
      Class_is_number output = new Class_is_number();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-number", // name
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
    public Func_is_number vx_empty() {return e_is_number;}
    @Override
    public Func_is_number vx_type() {return t_is_number;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_is_number(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_number(value);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_number(final Core.Type_any value) {
      return Core.f_is_number(value);
    }

  }

  public static final Func_is_number e_is_number = new Core.Class_is_number();
  public static final Func_is_number t_is_number = new Core.Class_is_number();

  public static Core.Type_boolean f_is_number(final Core.Type_any value) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_switch(
      Core.t_boolean,
      Core.f_typename_from_any(value),
      Core.t_thenelselist.vx_new(
        Core.f_case(
          Core.f_new(
            Core.t_list,
            Core.t_anylist.vx_new(
              Core.vx_new_string("vx/core/decimal"),
              Core.vx_new_string("vx/core/float"),
              Core.vx_new_string("vx/core/int"),
              Core.vx_new_string("vx/core/number")
            )
          ),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(true);
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_boolean(false);
          })
        )
      )
    );
    return output;
  }

  /**
   * @function is_pass_from_permission
   * Returns true if permission passes.
   * @param  {permission} permission
   * @return {boolean}
   * (func is-pass<-permission)
   */
  public static interface Func_is_pass_from_permission extends Core.Func_any_from_any_context {
    public Core.Type_boolean f_is_pass_from_permission(final Core.Type_context context, final Core.Type_permission permission);
  }

  public static class Class_is_pass_from_permission extends Core.Class_base implements Func_is_pass_from_permission {

    @Override
    public Func_is_pass_from_permission vx_new(Object... vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    @Override
    public Func_is_pass_from_permission vx_copy(Object... vals) {
      Class_is_pass_from_permission output = new Class_is_pass_from_permission();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "is-pass<-permission", // name
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
    public Func_is_pass_from_permission vx_empty() {return e_is_pass_from_permission;}
    @Override
    public Func_is_pass_from_permission vx_type() {return t_is_pass_from_permission;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_permission inputval = (Core.Type_permission)value;
      Core.Type_any outputval = Core.f_is_pass_from_permission(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_permission permission = Core.f_any_from_any(Core.t_permission, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_is_pass_from_permission(context, permission);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_pass_from_permission(final Core.Type_context context, final Core.Type_permission permission) {
      return Core.f_is_pass_from_permission(context, permission);
    }

  }

  public static final Func_is_pass_from_permission e_is_pass_from_permission = new Core.Class_is_pass_from_permission();
  public static final Func_is_pass_from_permission t_is_pass_from_permission = new Core.Class_is_pass_from_permission();

  public static Core.Type_boolean f_is_pass_from_permission(final Core.Type_context context, final Core.Type_permission permission) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string id = permission.id();
        final Core.Type_permission lookup = Core.f_permission_from_id_context(context, id);
        return Core.f_eq(lookup, permission);
      })
    );
    return output;
  }

  /**
   * @function last_from_list
   * Returns last value
   * @param  {list-1} values
   * @return {any-1}
   * (func last<-list)
   */
  public static interface Func_last_from_list extends Core.Func_any_from_any {
    public <T extends Core.Type_any, X extends Core.Type_list> T f_last_from_list(final T generic_any_1, final X values);
  }

  public static class Class_last_from_list extends Core.Class_base implements Func_last_from_list {

    @Override
    public Func_last_from_list vx_new(Object... vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    @Override
    public Func_last_from_list vx_copy(Object... vals) {
      Class_last_from_list output = new Class_last_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "last<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_last_from_list vx_empty() {return e_last_from_list;}
    @Override
    public Func_last_from_list vx_type() {return t_last_from_list;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_list inputval = (Core.Type_list)value;
      Core.Type_any outputval = Core.f_last_from_list(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_last_from_list(generic_any_1, values);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> T f_last_from_list(final T generic_any_1, final X values) {
      return Core.f_last_from_list(generic_any_1, values);
    }

  }

  public static final Func_last_from_list e_last_from_list = new Core.Class_last_from_list();
  public static final Func_last_from_list t_last_from_list = new Core.Class_last_from_list();

  public static <T extends Core.Type_any, X extends Core.Type_list> T f_last_from_list(final T generic_any_1, final X values) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int len = Core.f_length_from_list(values);
        return Core.f_any_from_list(generic_any_1, values, len);
      })
    );
    return output;
  }

  /**
   * @function length_from_list
   * Returns the currently used size/length of a list
   * @param  {list-1} values
   * @return {int}
   * (func length<-list)
   */
  public static interface Func_length_from_list extends Core.Func_any_from_any {
    public Core.Type_int f_length_from_list(final Core.Type_list values);
  }

  public static class Class_length_from_list extends Core.Class_base implements Func_length_from_list {

    @Override
    public Func_length_from_list vx_new(Object... vals) {
      Class_length_from_list output = new Class_length_from_list();
      return output;
    }

    @Override
    public Func_length_from_list vx_copy(Object... vals) {
      Class_length_from_list output = new Class_length_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "length<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.t_typelist.vx_new(Core.t_number), // traits
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
    public Func_length_from_list vx_empty() {return e_length_from_list;}
    @Override
    public Func_length_from_list vx_type() {return t_length_from_list;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_list inputval = (Core.Type_list)value;
      Core.Type_any outputval = Core.f_length_from_list(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_length_from_list(values);
      return output;
    }

    @Override
    public Core.Type_int f_length_from_list(final Core.Type_list values) {
      return Core.f_length_from_list(values);
    }

  }

  public static final Func_length_from_list e_length_from_list = new Core.Class_length_from_list();
  public static final Func_length_from_list t_length_from_list = new Core.Class_length_from_list();

  public static Core.Type_int f_length_from_list(final Core.Type_list values) {
    Core.Type_int output = Core.e_int;
    int intresult = values.vx_list().size();
    output = Core.vx_new_int(intresult);
    return output;
  }

  /**
   * @function let
   * @param  {arglist} args
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func let)
   */
  public static interface Func_let extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_let(final T generic_any_1, final Core.Func_any_from_func fn_any);
  }

  public static class Class_let extends Core.Class_base implements Func_let {

    @Override
    public Func_let vx_new(Object... vals) {
      Class_let output = new Class_let();
      return output;
    }

    @Override
    public Func_let vx_copy(Object... vals) {
      Class_let output = new Class_let();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "let", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_let vx_empty() {return e_let;}
    @Override
    public Func_let vx_type() {return t_let;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_let(generic_any_1, fn_any);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_let(final T generic_any_1, Core.Func_any_from_func fn_any) {
      return Core.f_let(generic_any_1, fn_any);
    }

  }

  public static final Func_let e_let = new Core.Class_let();
  public static final Func_let t_let = new Core.Class_let();

  public static <T extends Core.Type_any> T f_let(final T generic_any_1, Core.Func_any_from_func fn_any) {
    T output = Core.f_empty(generic_any_1);
    output = fn_any.f_any_from_func(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function let_async
   * Same as normal let but returns async values.
   * @param  {arglist} args
   * @param  {any<-func-async} fn-any-async
   * @return {any-1}
   * (func let-async)
   */
  public static interface Func_let_async extends Core.Type_func, Core.Type_replfunc_async {
    public <T extends Core.Type_any> CompletableFuture<T> f_let_async(final T generic_any_1, final Core.Func_any_from_func_async fn_any_async);
  }

  public static class Class_let_async extends Core.Class_base implements Func_let_async {

    @Override
    public Func_let_async vx_new(Object... vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    @Override
    public Func_let_async vx_copy(Object... vals) {
      Class_let_async output = new Class_let_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "let-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_let_async vx_empty() {return e_let_async;}
    @Override
    public Func_let_async vx_type() {return t_let_async;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_any_async = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_let_async(generic_any_1, fn_any_async);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any> CompletableFuture<T> f_let_async(final T generic_any_1, Core.Func_any_from_func_async fn_any_async) {
      return Core.f_let_async(generic_any_1, fn_any_async);
    }

  }

  public static final Func_let_async e_let_async = new Core.Class_let_async();
  public static final Func_let_async t_let_async = new Core.Class_let_async();

  public static <T extends Core.Type_any> CompletableFuture<T> f_let_async(final T generic_any_1, Core.Func_any_from_func_async fn_any_async) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    output = fn_any_async.f_any_from_func_async(generic_any_1);
    return output;
  }

  /**
   * @function list_join_from_list
   * Returns a flattened list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list-join<-list)
   */
  public static interface Func_list_join_from_list extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_join_from_list(final X generic_any_1, final Y values, final Core.Func_any_from_any fn_any_from_any);
  }

  public static class Class_list_join_from_list extends Core.Class_base implements Func_list_join_from_list {

    @Override
    public Func_list_join_from_list vx_new(Object... vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    @Override
    public Func_list_join_from_list vx_copy(Object... vals) {
      Class_list_join_from_list output = new Class_list_join_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_list_join_from_list vx_empty() {return e_list_join_from_list;}
    @Override
    public Func_list_join_from_list vx_type() {return t_list_join_from_list;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any fn_any_from_any = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_list_join_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_join_from_list(final X generic_list_1, final Y values, final Core.Func_any_from_any fn_any_from_any) {
      return Core.f_list_join_from_list(generic_list_1, values, fn_any_from_any);
    }

  }

  public static final Func_list_join_from_list e_list_join_from_list = new Core.Class_list_join_from_list();
  public static final Func_list_join_from_list t_list_join_from_list = new Core.Class_list_join_from_list();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_join_from_list(final X generic_list_1, final Y values, final Core.Func_any_from_any fn_any_from_any) {
    X output = Core.f_empty(generic_list_1);
    List<Core.Type_any> list_value = values.vx_list();
    List<Core.Type_any> list_result = new ArrayList<>();
    for (Core.Type_any val : list_value) {
      Core.Type_any listoflist = fn_any_from_any.f_any_from_any(generic_list_1, val);
      if (listoflist instanceof Core.Type_list) {
        Core.Type_list vallist = (Core.Type_list)listoflist;
        List<Core.Type_any> listval = vallist.vx_list();
        list_result.addAll(listval);
      }
    }
    output = Core.f_any_from_any(generic_list_1, generic_list_1.vx_new(list_result));
    return output;
  }

  /**
   * @function list_from_list
   * Returns a list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list<-list)
   */
  public static interface Func_list_from_list extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list(final X generic_any_1, final Y values, final Core.Func_any_from_any fn_any_from_any);
  }

  public static class Class_list_from_list extends Core.Class_base implements Func_list_from_list {

    @Override
    public Func_list_from_list vx_new(Object... vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    @Override
    public Func_list_from_list vx_copy(Object... vals) {
      Class_list_from_list output = new Class_list_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_list_from_list vx_empty() {return e_list_from_list;}
    @Override
    public Func_list_from_list vx_type() {return t_list_from_list;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any fn_any_from_any = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_list_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list(final X generic_list_1, final Y values, final Core.Func_any_from_any fn_any_from_any) {
      return Core.f_list_from_list(generic_list_1, values, fn_any_from_any);
    }

  }

  public static final Func_list_from_list e_list_from_list = new Core.Class_list_from_list();
  public static final Func_list_from_list t_list_from_list = new Core.Class_list_from_list();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list(final X generic_list_1, final Y values, final Core.Func_any_from_any fn_any_from_any) {
    X output = Core.f_empty(generic_list_1);
    List<Core.Type_any> list_value = values.vx_list();
    List<Core.Type_any> list_result = Core.arraylist_from_arraylist_fn(list_value, (val) -> {
      return fn_any_from_any.f_any_from_any(generic_list_1, val);
    });
    output = Core.f_any_from_any(generic_list_1, generic_list_1.vx_new(list_result));
    return output;
  }

  /**
   * 
   * @async
   * @function list_from_list_async
   * Returns an asynchronous list of the processed asynchronous items from another list
   * @param  {list-2} values
   * @param  {any<-any-async} fn-any<-any-async
   * @return {list-1}
   * (func list<-list-async)
   */
  public static interface Func_list_from_list_async extends Core.Type_func, Core.Type_replfunc_async {
    public <X extends Core.Type_list, Y extends Core.Type_list> CompletableFuture<X> f_list_from_list_async(final X generic_any_1, final Y values, final Core.Func_any_from_any_async fn_any_from_any_async);
  }

  public static class Class_list_from_list_async extends Core.Class_base implements Func_list_from_list_async {

    @Override
    public Func_list_from_list_async vx_new(Object... vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    @Override
    public Func_list_from_list_async vx_copy(Object... vals) {
      Class_list_from_list_async output = new Class_list_from_list_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list<-list-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_list_from_list_async vx_empty() {return e_list_from_list_async;}
    @Override
    public Func_list_from_list_async vx_type() {return t_list_from_list_async;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any_async fn_any_from_any_async = Core.f_any_from_any(Core.t_any_from_any_async, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Core.Type_list> future = Core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> CompletableFuture<X> f_list_from_list_async(final X generic_list_1, final Y values, final Core.Func_any_from_any_async fn_any_from_any_async) {
      return Core.f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
    }

  }

  public static final Func_list_from_list_async e_list_from_list_async = new Core.Class_list_from_list_async();
  public static final Func_list_from_list_async t_list_from_list_async = new Core.Class_list_from_list_async();

  public static <X extends Core.Type_list, Y extends Core.Type_list> CompletableFuture<X> f_list_from_list_async(final X generic_list_1, final Y values, final Core.Func_any_from_any_async fn_any_from_any_async) {
    CompletableFuture<X> output = Core.async_new_completed(Core.f_empty(generic_list_1));
    List<Core.Type_any> list_value = values.vx_list();
    List<CompletableFuture<Core.Type_any>> list_async_result = Core.arraylist_from_arraylist_fn(list_value, (val) -> {
      return fn_any_from_any_async.f_any_from_any_async(generic_list_1, val);
    });
    CompletableFuture<List<Core.Type_any>> async_list_result = Core.async_arraylist_from_arraylist_async(list_async_result);
    output = Core.async_from_async_fn(async_list_result, (list_result) -> {
      X work = Core.f_any_from_any(generic_list_1, generic_list_1.vx_new(list_result));
      return work;
    });
    return output;
  }

  /**
   * @function list_from_map
   * Returns a list from a map by applying a function to each key value.
   * @param  {map-2} valuemap
   * @param  {any<-key-value} fn-any<-key-value
   * @return {list-1}
   * (func list<-map)
   */
  public static interface Func_list_from_map extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, O extends Core.Type_map> X f_list_from_map(final X generic_any_1, final O valuemap, final Core.Func_any_from_key_value fn_any_from_key_value);
  }

  public static class Class_list_from_map extends Core.Class_base implements Func_list_from_map {

    @Override
    public Func_list_from_map vx_new(Object... vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    @Override
    public Func_list_from_map vx_copy(Object... vals) {
      Class_list_from_map output = new Class_list_from_map();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_list_from_map vx_empty() {return e_list_from_map;}
    @Override
    public Func_list_from_map vx_type() {return t_list_from_map;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_key_value fn_any_from_key_value = Core.f_any_from_any(Core.t_any_from_key_value, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_list_from_map(generic_list_1, valuemap, fn_any_from_key_value);
      return output;
    }

    @Override
    public <X extends Core.Type_list, O extends Core.Type_map> X f_list_from_map(final X generic_list_1, final O valuemap, final Core.Func_any_from_key_value fn_any_from_key_value) {
      return Core.f_list_from_map(generic_list_1, valuemap, fn_any_from_key_value);
    }

  }

  public static final Func_list_from_map e_list_from_map = new Core.Class_list_from_map();
  public static final Func_list_from_map t_list_from_map = new Core.Class_list_from_map();

  public static <X extends Core.Type_list, O extends Core.Type_map> X f_list_from_map(final X generic_list_1, final O valuemap, final Core.Func_any_from_key_value fn_any_from_key_value) {
    X output = Core.f_empty(generic_list_1);
    Map<String, Core.Type_any> map_value = valuemap.vx_map();
    List<Core.Type_any> listresult = Core.arraylist_from_linkedhashmap_fn(map_value, (key, val) -> {
      Core.Type_string valkey = Core.vx_new_string(key);
      return fn_any_from_key_value.f_any_from_key_value(Core.t_any, valkey, val);
    });
    output = Core.f_any_from_any(generic_list_1, generic_list_1.vx_new(listresult));
    return output;
  }

  /**
   * 
   * @async
   * @function list_from_map_async
   * @param  {map-2} valuemap
   * @param  {any<-key-value-async} fn-any<-key-value-async
   * @return {list-1}
   * (func list<-map-async)
   */
  public static interface Func_list_from_map_async extends Core.Type_func, Core.Type_replfunc_async {
    public <X extends Core.Type_list, O extends Core.Type_map> CompletableFuture<X> f_list_from_map_async(final X generic_any_1, final O valuemap, final Core.Func_any_from_key_value_async fn_any_from_key_value_async);
  }

  public static class Class_list_from_map_async extends Core.Class_base implements Func_list_from_map_async {

    @Override
    public Func_list_from_map_async vx_new(Object... vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    @Override
    public Func_list_from_map_async vx_copy(Object... vals) {
      Class_list_from_map_async output = new Class_list_from_map_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list<-map-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_list_from_map_async vx_empty() {return e_list_from_map_async;}
    @Override
    public Func_list_from_map_async vx_type() {return t_list_from_map_async;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_key_value_async fn_any_from_key_value_async = Core.f_any_from_any(Core.t_any_from_key_value_async, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Core.Type_list> future = Core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <X extends Core.Type_list, O extends Core.Type_map> CompletableFuture<X> f_list_from_map_async(final X generic_list_1, final O valuemap, final Core.Func_any_from_key_value_async fn_any_from_key_value_async) {
      return Core.f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
    }

  }

  public static final Func_list_from_map_async e_list_from_map_async = new Core.Class_list_from_map_async();
  public static final Func_list_from_map_async t_list_from_map_async = new Core.Class_list_from_map_async();

  public static <X extends Core.Type_list, O extends Core.Type_map> CompletableFuture<X> f_list_from_map_async(final X generic_list_1, final O valuemap, final Core.Func_any_from_key_value_async fn_any_from_key_value_async) {
    CompletableFuture<X> output = Core.async_new_completed(Core.f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_type
   * Create an empty list from a type. Used internally for default lists
   * @param  {any} type
   * @return {any}
   * (func list<-type)
   */
  public static interface Func_list_from_type extends Core.Func_any_from_any {
    public Core.Type_any f_list_from_type(final Core.Type_any type);
  }

  public static class Class_list_from_type extends Core.Class_base implements Func_list_from_type {

    @Override
    public Func_list_from_type vx_new(Object... vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    @Override
    public Func_list_from_type vx_copy(Object... vals) {
      Class_list_from_type output = new Class_list_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "list<-type", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_list_from_type vx_empty() {return e_list_from_type;}
    @Override
    public Func_list_from_type vx_type() {return t_list_from_type;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_list_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_list_from_type(type);
      return output;
    }

    @Override
    public Core.Type_any f_list_from_type(final Core.Type_any type) {
      return Core.f_list_from_type(type);
    }

  }

  public static final Func_list_from_type e_list_from_type = new Core.Class_list_from_type();
  public static final Func_list_from_type t_list_from_type = new Core.Class_list_from_type();

  public static Core.Type_any f_list_from_type(final Core.Type_any type) {
    Core.Type_any output = Core.e_any;
    return output;
  }

  /**
   * @function log
   * Writes a value to the console.
   * @param  {any} value
   * @return {any}
   * (func log)
   */
  public static interface Func_log extends Core.Func_any_from_any {
    public Core.Type_any f_log(final Core.Type_any value);
  }

  public static class Class_log extends Core.Class_base implements Func_log {

    @Override
    public Func_log vx_new(Object... vals) {
      Class_log output = new Class_log();
      return output;
    }

    @Override
    public Func_log vx_copy(Object... vals) {
      Class_log output = new Class_log();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_log vx_empty() {return e_log;}
    @Override
    public Func_log vx_type() {return t_log;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_log(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_log(value);
      return output;
    }

    @Override
    public Core.Type_any f_log(final Core.Type_any value) {
      return Core.f_log(value);
    }

  }

  public static final Func_log e_log = new Core.Class_log();
  public static final Func_log t_log = new Core.Class_log();

  public static Core.Type_any f_log(final Core.Type_any value) {
    Core.Type_any output = Core.e_any;
    Core.Type_string stringtext = Core.f_string_from_any(value);
    String text = stringtext.vx_string();
    System.out.println(text);
    output = value;
    return output;
  }

  /**
   * @function log 1
   * Writes a string and a value to the console.
   * @param  {string} text
   * @param  {any-1} value
   * @return {any-1}
   * (func log)
   */
  public static interface Func_log_1 extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_log_1(final T generic_any_1, final Core.Type_string text, final T value);
  }

  public static class Class_log_1 extends Core.Class_base implements Func_log_1 {

    @Override
    public Func_log_1 vx_new(Object... vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    @Override
    public Func_log_1 vx_copy(Object... vals) {
      Class_log_1 output = new Class_log_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "log", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_log_1 vx_empty() {return e_log_1;}
    @Override
    public Func_log_1 vx_type() {return t_log_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_log_1(generic_any_1, text, value);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_log_1(final T generic_any_1, final Core.Type_string text, final T value) {
      return Core.f_log_1(generic_any_1, text, value);
    }

  }

  public static final Func_log_1 e_log_1 = new Core.Class_log_1();
  public static final Func_log_1 t_log_1 = new Core.Class_log_1();

  public static <T extends Core.Type_any> T f_log_1(final T generic_any_1, final Core.Type_string text, final T value) {
    T output = Core.f_empty(generic_any_1);
    Core.vx_log(text);
    Core.vx_log(value);
    output = value;
    return output;
  }

  /**
   * @function main
   * The default function for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {string}
   * (func main)
   */
  public static interface Func_main extends Core.Func_any_from_any {
    public Core.Type_string f_main(final Core.Type_anylist args);
  }

  public static class Class_main extends Core.Class_base implements Func_main {

    @Override
    public Func_main vx_new(Object... vals) {
      Class_main output = new Class_main();
      return output;
    }

    @Override
    public Func_main vx_copy(Object... vals) {
      Class_main output = new Class_main();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "main", // name
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
    public Func_main vx_empty() {return e_main;}
    @Override
    public Func_main vx_type() {return t_main;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_main(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_main(args);
      return output;
    }

    @Override
    public Core.Type_string f_main(final Core.Type_anylist args) {
      return Core.f_main(args);
    }

  }

  public static final Func_main e_main = new Core.Class_main();
  public static final Func_main t_main = new Core.Class_main();

  public static Core.Type_string f_main(final Core.Type_anylist args) {
    Core.Type_string output = Core.e_string;
    output = Core.f_new(
      Core.t_string,
      args
    );
    return output;
  }

  /**
   * @function map_from_list
   * Returns a map from a list by applying a function to each key value.
   * @param  {list-2} vallist
   * @param  {any<-any} fn-any<-any
   * @return {map-1}
   * (func map<-list)
   */
  public static interface Func_map_from_list extends Core.Type_func, Core.Type_replfunc {
    public <Y extends Core.Type_list, N extends Core.Type_map> N f_map_from_list(final N generic_any_1, final Y vallist, final Core.Func_any_from_any fn_any_from_any);
  }

  public static class Class_map_from_list extends Core.Class_base implements Func_map_from_list {

    @Override
    public Func_map_from_list vx_new(Object... vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    @Override
    public Func_map_from_list vx_copy(Object... vals) {
      Class_map_from_list output = new Class_map_from_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "map<-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_map_from_list vx_empty() {return e_map_from_list;}
    @Override
    public Func_map_from_list vx_type() {return t_map_from_list;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map generic_map_1 = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any fn_any_from_any = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
      return output;
    }

    @Override
    public <Y extends Core.Type_list, N extends Core.Type_map> N f_map_from_list(final N generic_map_1, final Y vallist, final Core.Func_any_from_any fn_any_from_any) {
      return Core.f_map_from_list(generic_map_1, vallist, fn_any_from_any);
    }

  }

  public static final Func_map_from_list e_map_from_list = new Core.Class_map_from_list();
  public static final Func_map_from_list t_map_from_list = new Core.Class_map_from_list();

  public static <Y extends Core.Type_list, N extends Core.Type_map> N f_map_from_list(final N generic_map_1, final Y vallist, final Core.Func_any_from_any fn_any_from_any) {
    N output = Core.f_empty(generic_map_1);
    List<Core.Type_any> listval = vallist.vx_list();
    Map<String, Core.Type_any> mapresult = Core.map_from_list_fn(listval, (val) -> {
      return fn_any_from_any.f_any_from_any(Core.t_string, val);
    });
    output = Core.f_any_from_any(generic_map_1, output.vx_new_from_map(mapresult));
    return output;
  }

  /**
   * @function mempool_addref
   * Add Value Reference
   * @param  {anylist} values
   * @return {none}
   * (func mempool-addref)
   */
  public static interface Func_mempool_addref extends Core.Type_func, Core.Type_replfunc {
    public void f_mempool_addref(final Core.Type_anylist values);
  }

  public static class Class_mempool_addref extends Core.Class_base implements Func_mempool_addref {

    @Override
    public Func_mempool_addref vx_new(Object... vals) {
      Class_mempool_addref output = new Class_mempool_addref();
      return output;
    }

    @Override
    public Func_mempool_addref vx_copy(Object... vals) {
      Class_mempool_addref output = new Class_mempool_addref();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "mempool-addref", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
    public Func_mempool_addref vx_empty() {return e_mempool_addref;}
    @Override
    public Func_mempool_addref vx_type() {return t_mempool_addref;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      Core.f_mempool_addref(values);
      return output;
    }

    @Override
    public void f_mempool_addref(final Core.Type_anylist values) {Core.f_mempool_addref(values);
    }

  }

  public static final Func_mempool_addref e_mempool_addref = new Core.Class_mempool_addref();
  public static final Func_mempool_addref t_mempool_addref = new Core.Class_mempool_addref();

  public static void f_mempool_addref(final Core.Type_anylist values) {
  }

  /**
   * @function mempool_release
   * Recycles a Value and adds it to the valuepool.
   * @param  {value} value
   * @return {none}
   * (func mempool-release)
   */
  public static interface Func_mempool_release extends Core.Type_func, Core.Type_replfunc {
    public void f_mempool_release(final Core.Type_value value);
  }

  public static class Class_mempool_release extends Core.Class_base implements Func_mempool_release {

    @Override
    public Func_mempool_release vx_new(Object... vals) {
      Class_mempool_release output = new Class_mempool_release();
      return output;
    }

    @Override
    public Func_mempool_release vx_copy(Object... vals) {
      Class_mempool_release output = new Class_mempool_release();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "mempool-release", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
    public Func_mempool_release vx_empty() {return e_mempool_release;}
    @Override
    public Func_mempool_release vx_type() {return t_mempool_release;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_value value = Core.f_any_from_any(Core.t_value, arglist.vx_any(Core.vx_new_int(0)));
      Core.f_mempool_release(value);
      return output;
    }

    @Override
    public void f_mempool_release(final Core.Type_value value) {Core.f_mempool_release(value);
    }

  }

  public static final Func_mempool_release e_mempool_release = new Core.Class_mempool_release();
  public static final Func_mempool_release t_mempool_release = new Core.Class_mempool_release();

  public static void f_mempool_release(final Core.Type_value value) {
  }

  /**
   * @function mempool_removeref
   * Remove Value Reference
   * @param  {anylist} values
   * @return {none}
   * (func mempool-removeref)
   */
  public static interface Func_mempool_removeref extends Core.Type_func, Core.Type_replfunc {
    public void f_mempool_removeref(final Core.Type_anylist values);
  }

  public static class Class_mempool_removeref extends Core.Class_base implements Func_mempool_removeref {

    @Override
    public Func_mempool_removeref vx_new(Object... vals) {
      Class_mempool_removeref output = new Class_mempool_removeref();
      return output;
    }

    @Override
    public Func_mempool_removeref vx_copy(Object... vals) {
      Class_mempool_removeref output = new Class_mempool_removeref();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "mempool-removeref", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
    public Func_mempool_removeref vx_empty() {return e_mempool_removeref;}
    @Override
    public Func_mempool_removeref vx_type() {return t_mempool_removeref;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      Core.f_mempool_removeref(values);
      return output;
    }

    @Override
    public void f_mempool_removeref(final Core.Type_anylist values) {Core.f_mempool_removeref(values);
    }

  }

  public static final Func_mempool_removeref e_mempool_removeref = new Core.Class_mempool_removeref();
  public static final Func_mempool_removeref t_mempool_removeref = new Core.Class_mempool_removeref();

  public static void f_mempool_removeref(final Core.Type_anylist values) {
  }

  /**
   * @function mempool_removerefchildren
   * Remove Value Child References
   * @param  {anylist} values
   * @return {none}
   * (func mempool-removerefchildren)
   */
  public static interface Func_mempool_removerefchildren extends Core.Type_func, Core.Type_replfunc {
    public void f_mempool_removerefchildren(final Core.Type_anylist values);
  }

  public static class Class_mempool_removerefchildren extends Core.Class_base implements Func_mempool_removerefchildren {

    @Override
    public Func_mempool_removerefchildren vx_new(Object... vals) {
      Class_mempool_removerefchildren output = new Class_mempool_removerefchildren();
      return output;
    }

    @Override
    public Func_mempool_removerefchildren vx_copy(Object... vals) {
      Class_mempool_removerefchildren output = new Class_mempool_removerefchildren();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "mempool-removerefchildren", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
    public Func_mempool_removerefchildren vx_empty() {return e_mempool_removerefchildren;}
    @Override
    public Func_mempool_removerefchildren vx_type() {return t_mempool_removerefchildren;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      Core.f_mempool_removerefchildren(values);
      return output;
    }

    @Override
    public void f_mempool_removerefchildren(final Core.Type_anylist values) {Core.f_mempool_removerefchildren(values);
    }

  }

  public static final Func_mempool_removerefchildren e_mempool_removerefchildren = new Core.Class_mempool_removerefchildren();
  public static final Func_mempool_removerefchildren t_mempool_removerefchildren = new Core.Class_mempool_removerefchildren();

  public static void f_mempool_removerefchildren(final Core.Type_anylist values) {
  }

  /**
   * @function mempool_reserve
   * Returns a recycled Value or creates a new one.
   * @return {value}
   * (func mempool-reserve)
   */
  public static interface Func_mempool_reserve extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_value f_mempool_reserve();
  }

  public static class Class_mempool_reserve extends Core.Class_base implements Func_mempool_reserve {

    @Override
    public Func_mempool_reserve vx_new(Object... vals) {
      Class_mempool_reserve output = new Class_mempool_reserve();
      return output;
    }

    @Override
    public Func_mempool_reserve vx_copy(Object... vals) {
      Class_mempool_reserve output = new Class_mempool_reserve();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "mempool-reserve", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "value", // name
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
    public Func_mempool_reserve vx_empty() {return e_mempool_reserve;}
    @Override
    public Func_mempool_reserve vx_type() {return t_mempool_reserve;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_mempool_reserve();
      return output;
    }

    @Override
    public Core.Type_value f_mempool_reserve() {
      return Core.f_mempool_reserve();
    }

  }

  public static final Func_mempool_reserve e_mempool_reserve = new Core.Class_mempool_reserve();
  public static final Func_mempool_reserve t_mempool_reserve = new Core.Class_mempool_reserve();

  public static Core.Type_value f_mempool_reserve() {
    Core.Type_value output = Core.e_value;
    return output;
  }

  /**
   * @function msg_from_error
   * Returns a msg from error string
   * @param  {string} error
   * @return {msg}
   * (func msg<-error)
   */
  public static interface Func_msg_from_error extends Core.Func_any_from_any {
    public Core.Type_msg f_msg_from_error(final Core.Type_string error);
  }

  public static class Class_msg_from_error extends Core.Class_base implements Func_msg_from_error {

    @Override
    public Func_msg_from_error vx_new(Object... vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    @Override
    public Func_msg_from_error vx_copy(Object... vals) {
      Class_msg_from_error output = new Class_msg_from_error();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
    public Func_msg_from_error vx_empty() {return e_msg_from_error;}
    @Override
    public Func_msg_from_error vx_type() {return t_msg_from_error;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_msg_from_error(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string error = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_msg_from_error(error);
      return output;
    }

    @Override
    public Core.Type_msg f_msg_from_error(final Core.Type_string error) {
      return Core.f_msg_from_error(error);
    }

  }

  public static final Func_msg_from_error e_msg_from_error = new Core.Class_msg_from_error();
  public static final Func_msg_from_error t_msg_from_error = new Core.Class_msg_from_error();

  public static Core.Type_msg f_msg_from_error(final Core.Type_string error) {
    Core.Type_msg output = Core.e_msg;
    output = Core.f_new(
      Core.t_msg,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":severity"),
        Core.c_msg_error,
        Core.vx_new_string(":text"),
        error
      )
    );
    return output;
  }

  /**
   * @function msg_from_warning
   * Returns a msg from a warning string
   * @param  {string} warning
   * @return {msg}
   * (func msg<-warning)
   */
  public static interface Func_msg_from_warning extends Core.Func_any_from_any {
    public Core.Type_msg f_msg_from_warning(final Core.Type_string warning);
  }

  public static class Class_msg_from_warning extends Core.Class_base implements Func_msg_from_warning {

    @Override
    public Func_msg_from_warning vx_new(Object... vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    @Override
    public Func_msg_from_warning vx_copy(Object... vals) {
      Class_msg_from_warning output = new Class_msg_from_warning();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "msg<-warning", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "msg", // name
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
    public Func_msg_from_warning vx_empty() {return e_msg_from_warning;}
    @Override
    public Func_msg_from_warning vx_type() {return t_msg_from_warning;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_msg_from_warning(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string warning = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_msg_from_warning(warning);
      return output;
    }

    @Override
    public Core.Type_msg f_msg_from_warning(final Core.Type_string warning) {
      return Core.f_msg_from_warning(warning);
    }

  }

  public static final Func_msg_from_warning e_msg_from_warning = new Core.Class_msg_from_warning();
  public static final Func_msg_from_warning t_msg_from_warning = new Core.Class_msg_from_warning();

  public static Core.Type_msg f_msg_from_warning(final Core.Type_string warning) {
    Core.Type_msg output = Core.e_msg;
    output = Core.f_new(
      Core.t_msg,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":severity"),
        Core.c_msg_warning,
        Core.vx_new_string(":text"),
        warning
      )
    );
    return output;
  }

  /**
   * @function msgblock_from_msgblock_msg
   * Return a new Msgblock with the added msg
   * @param  {msgblock} origblock
   * @param  {msg} addmsg
   * @return {msgblock}
   * (func msgblock<-msgblock-msg)
   */
  public static interface Func_msgblock_from_msgblock_msg extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_msgblock f_msgblock_from_msgblock_msg(final Core.Type_msgblock origblock, final Core.Type_msg addmsg);
  }

  public static class Class_msgblock_from_msgblock_msg extends Core.Class_base implements Func_msgblock_from_msgblock_msg {

    @Override
    public Func_msgblock_from_msgblock_msg vx_new(Object... vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    @Override
    public Func_msgblock_from_msgblock_msg vx_copy(Object... vals) {
      Class_msgblock_from_msgblock_msg output = new Class_msgblock_from_msgblock_msg();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msg", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
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
    public Func_msgblock_from_msgblock_msg vx_empty() {return e_msgblock_from_msgblock_msg;}
    @Override
    public Func_msgblock_from_msgblock_msg vx_type() {return t_msgblock_from_msgblock_msg;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_msgblock origblock = Core.f_any_from_any(Core.t_msgblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_msg addmsg = Core.f_any_from_any(Core.t_msg, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_msgblock_from_msgblock_msg(origblock, addmsg);
      return output;
    }

    @Override
    public Core.Type_msgblock f_msgblock_from_msgblock_msg(final Core.Type_msgblock origblock, final Core.Type_msg addmsg) {
      return Core.f_msgblock_from_msgblock_msg(origblock, addmsg);
    }

  }

  public static final Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg = new Core.Class_msgblock_from_msgblock_msg();
  public static final Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg = new Core.Class_msgblock_from_msgblock_msg();

  public static Core.Type_msgblock f_msgblock_from_msgblock_msg(final Core.Type_msgblock origblock, final Core.Type_msg addmsg) {
    Core.Type_msgblock output = Core.e_msgblock;
    output = Core.f_copy(origblock, Core.t_anylist.vx_new(
      addmsg));
    return output;
  }

  /**
   * @function msgblock_from_msgblock_msgblock
   * Return a new Msgblock with the added block
   * @param  {msgblock} origblock
   * @param  {msgblock} addblock
   * @return {msgblock}
   * (func msgblock<-msgblock-msgblock)
   */
  public static interface Func_msgblock_from_msgblock_msgblock extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_msgblock f_msgblock_from_msgblock_msgblock(final Core.Type_msgblock origblock, final Core.Type_msgblock addblock);
  }

  public static class Class_msgblock_from_msgblock_msgblock extends Core.Class_base implements Func_msgblock_from_msgblock_msgblock {

    @Override
    public Func_msgblock_from_msgblock_msgblock vx_new(Object... vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    @Override
    public Func_msgblock_from_msgblock_msgblock vx_copy(Object... vals) {
      Class_msgblock_from_msgblock_msgblock output = new Class_msgblock_from_msgblock_msgblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msgblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
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
    public Func_msgblock_from_msgblock_msgblock vx_empty() {return e_msgblock_from_msgblock_msgblock;}
    @Override
    public Func_msgblock_from_msgblock_msgblock vx_type() {return t_msgblock_from_msgblock_msgblock;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_msgblock origblock = Core.f_any_from_any(Core.t_msgblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_msgblock addblock = Core.f_any_from_any(Core.t_msgblock, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
      return output;
    }

    @Override
    public Core.Type_msgblock f_msgblock_from_msgblock_msgblock(final Core.Type_msgblock origblock, final Core.Type_msgblock addblock) {
      return Core.f_msgblock_from_msgblock_msgblock(origblock, addblock);
    }

  }

  public static final Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock = new Core.Class_msgblock_from_msgblock_msgblock();
  public static final Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock = new Core.Class_msgblock_from_msgblock_msgblock();

  public static Core.Type_msgblock f_msgblock_from_msgblock_msgblock(final Core.Type_msgblock origblock, final Core.Type_msgblock addblock) {
    Core.Type_msgblock output = Core.e_msgblock;
    output = Core.f_new(
      Core.t_msgblock,
      Core.t_anylist.vx_new(
        origblock,
        addblock
      )
    );
    return output;
  }

  /**
   * @function name_from_typedef
   * Returns the name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   * (func name<-typedef)
   */
  public static interface Func_name_from_typedef extends Core.Func_any_from_any {
    public Core.Type_string f_name_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_name_from_typedef extends Core.Class_base implements Func_name_from_typedef {

    @Override
    public Func_name_from_typedef vx_new(Object... vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    @Override
    public Func_name_from_typedef vx_copy(Object... vals) {
      Class_name_from_typedef output = new Class_name_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "name<-typedef", // name
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
    public Func_name_from_typedef vx_empty() {return e_name_from_typedef;}
    @Override
    public Func_name_from_typedef vx_type() {return t_name_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_name_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_name_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_string f_name_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_name_from_typedef(vtypedef);
    }

  }

  public static final Func_name_from_typedef e_name_from_typedef = new Core.Class_name_from_typedef();
  public static final Func_name_from_typedef t_name_from_typedef = new Core.Class_name_from_typedef();

  public static Core.Type_string f_name_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_string output = Core.e_string;
    output = vtypedef.name();
    return output;
  }

  /**
   * @function native
   * Native Function Call
   * @param  {anylist} clauses
   * @return {any-1}
   * (func native)
   */
  public static interface Func_native extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T f_native(final T generic_any_1, final Core.Type_anylist clauses);
  }

  public static class Class_native extends Core.Class_base implements Func_native {

    @Override
    public Func_native vx_new(Object... vals) {
      Class_native output = new Class_native();
      return output;
    }

    @Override
    public Func_native vx_copy(Object... vals) {
      Class_native output = new Class_native();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "native", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_native vx_empty() {return e_native;}
    @Override
    public Func_native vx_type() {return t_native;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Core.f_native(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist clauses = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_native(generic_any_1, clauses);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_native(final T generic_any_1, final Core.Type_anylist clauses) {
      return Core.f_native(generic_any_1, clauses);
    }

  }

  public static final Func_native e_native = new Core.Class_native();
  public static final Func_native t_native = new Core.Class_native();

  public static <T extends Core.Type_any> T f_native(final T generic_any_1, final Core.Type_anylist clauses) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }

  /**
   * @function native_from_any
   * Returns native value of value object
   * @param  {any-1} value
   * @return {any}
   * (func native<-any)
   */
  public static interface Func_native_from_any extends Core.Func_any_from_any {
    public Core.Type_any f_native_from_any(final Core.Type_any value);
  }

  public static class Class_native_from_any extends Core.Class_base implements Func_native_from_any {

    @Override
    public Func_native_from_any vx_new(Object... vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    @Override
    public Func_native_from_any vx_copy(Object... vals) {
      Class_native_from_any output = new Class_native_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "native<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_native_from_any vx_empty() {return e_native_from_any;}
    @Override
    public Func_native_from_any vx_type() {return t_native_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_native_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_native_from_any(value);
      return output;
    }

    @Override
    public Core.Type_any f_native_from_any(final Core.Type_any value) {
      return Core.f_native_from_any(value);
    }

  }

  public static final Func_native_from_any e_native_from_any = new Core.Class_native_from_any();
  public static final Func_native_from_any t_native_from_any = new Core.Class_native_from_any();

  public static Core.Type_any f_native_from_any(final Core.Type_any value) {
    Core.Type_any output = Core.e_any;
    return output;
  }

  /**
   * @function new
   * Create a new Value of Type A
   * @param  {any-1} type
   * @param  {anylist} values
   * @return {any-1}
   * (func new)
   */
  public static interface Func_new extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_new(final T type, final Core.Type_anylist values);
  }

  public static class Class_new extends Core.Class_base implements Func_new {

    @Override
    public Func_new vx_new(Object... vals) {
      Class_new output = new Class_new();
      return output;
    }

    @Override
    public Func_new vx_copy(Object... vals) {
      Class_new output = new Class_new();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "new", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_new vx_empty() {return e_new;}
    @Override
    public Func_new vx_type() {return t_new;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist values = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_new(type, values);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_new(final T type, final Core.Type_anylist values) {
      return Core.f_new(type, values);
    }

  }

  public static final Func_new e_new = new Core.Class_new();
  public static final Func_new t_new = new Core.Class_new();

  @SuppressWarnings("unchecked")
  public static <T extends Core.Type_any> T f_new(final T type, final Core.Type_anylist values) {
    Core.Type_any[] arrayany = Core.arrayany_from_anylist(values);
    Object[] arrayobj = (Core.Type_any[])arrayany;
    T output = (T)(type.vx_new(arrayobj));
    return output;
  }

  /**
   * @function number_from_func
   * Function Type returning number with any parameters
   * @return {number}
   * (func number<-func)
   */
  public static interface Func_number_from_func extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_number f_number_from_func();
  }

  public static class Class_number_from_func extends Core.Class_base implements Func_number_from_func {

    @Override
    public Func_number_from_func vx_new(Object... vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    @Override
    public Func_number_from_func vx_copy(Object... vals) {
      Class_number_from_func output = new Class_number_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "number<-func", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_int, Core.t_float, Core.t_decimal), // allowtypes
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
    public Func_number_from_func vx_empty() {return e_number_from_func;}
    @Override
    public Func_number_from_func vx_type() {return t_number_from_func;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_number_from_func();
      return output;
    }

    @Override
    public Core.Type_number f_number_from_func() {
      return Core.f_number_from_func();
    }

  }

  public static final Func_number_from_func e_number_from_func = new Core.Class_number_from_func();
  public static final Func_number_from_func t_number_from_func = new Core.Class_number_from_func();

  public static Core.Type_number f_number_from_func() {
    Core.Type_number output = Core.e_number;
    return output;
  }

  /**
   * @function or
   * Returns true if any value is true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   * (func or)
   */
  public static interface Func_or extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_or(final Core.Type_boolean val1, final Core.Type_boolean val2);
  }

  public static class Class_or extends Core.Class_base implements Func_or {

    @Override
    public Func_or vx_new(Object... vals) {
      Class_or output = new Class_or();
      return output;
    }

    @Override
    public Func_or vx_copy(Object... vals) {
      Class_or output = new Class_or();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
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
    public Func_or vx_empty() {return e_or;}
    @Override
    public Func_or vx_type() {return t_or;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_boolean val1 = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_boolean val2 = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_or(val1, val2);
      return output;
    }

    @Override
    public Core.Type_boolean f_or(final Core.Type_boolean val1, final Core.Type_boolean val2) {
      return Core.f_or(val1, val2);
    }

  }

  public static final Func_or e_or = new Core.Class_or();
  public static final Func_or t_or = new Core.Class_or();

  public static Core.Type_boolean f_or(final Core.Type_boolean val1, final Core.Type_boolean val2) {
    Core.Type_boolean output = Core.e_boolean;
    if (val1.vx_boolean() || val2.vx_boolean()) {
      output = Core.c_true;
    } else {
      output = Core.c_false;
    };
    return output;
  }

  /**
   * @function or 1
   * Returns true if any value is true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func or)
   */
  public static interface Func_or_1 extends Core.Func_any_from_any {
    public Core.Type_boolean f_or_1(final Core.Type_booleanlist values);
  }

  public static class Class_or_1 extends Core.Class_base implements Func_or_1 {

    @Override
    public Func_or_1 vx_new(Object... vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    @Override
    public Func_or_1 vx_copy(Object... vals) {
      Class_or_1 output = new Class_or_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "or", // name
        1, // idx
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
    public Func_or_1 vx_empty() {return e_or_1;}
    @Override
    public Func_or_1 vx_type() {return t_or_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_booleanlist inputval = (Core.Type_booleanlist)value;
      Core.Type_any outputval = Core.f_or_1(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_booleanlist values = Core.f_any_from_any(Core.t_booleanlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_or_1(values);
      return output;
    }

    @Override
    public Core.Type_boolean f_or_1(final Core.Type_booleanlist values) {
      return Core.f_or_1(values);
    }

  }

  public static final Func_or_1 e_or_1 = new Core.Class_or_1();
  public static final Func_or_1 t_or_1 = new Core.Class_or_1();

  public static Core.Type_boolean f_or_1(final Core.Type_booleanlist values) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_any_from_list_reduce_next(
      Core.t_boolean,
      values,
      Core.vx_new_boolean(false),
      Core.t_any_from_reduce_next.vx_fn_new((reduce_any, current_any, next_any) -> {
        Core.Type_boolean reduce = Core.f_any_from_any(Core.t_boolean, reduce_any);
        Core.Type_boolean current = Core.f_any_from_any(Core.t_boolean, current_any);
        Core.Type_boolean next = Core.f_any_from_any(Core.t_boolean, next_any);
        return 
          Core.f_or(
            reduce,
            Core.f_or(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function package_global_from_name
   * Returns a package from global with the given name.
   * @param  {string} name
   * @return {package}
   * (func package-global<-name)
   */
  public static interface Func_package_global_from_name extends Core.Func_any_from_any {
    public Core.Type_package f_package_global_from_name(final Core.Type_string name);
  }

  public static class Class_package_global_from_name extends Core.Class_base implements Func_package_global_from_name {

    @Override
    public Func_package_global_from_name vx_new(Object... vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    @Override
    public Func_package_global_from_name vx_copy(Object... vals) {
      Class_package_global_from_name output = new Class_package_global_from_name();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "package-global<-name", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "package", // name
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
    public Func_package_global_from_name vx_empty() {return e_package_global_from_name;}
    @Override
    public Func_package_global_from_name vx_type() {return t_package_global_from_name;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_package_global_from_name(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_package_global_from_name(name);
      return output;
    }

    @Override
    public Core.Type_package f_package_global_from_name(final Core.Type_string name) {
      return Core.f_package_global_from_name(name);
    }

  }

  public static final Func_package_global_from_name e_package_global_from_name = new Core.Class_package_global_from_name();
  public static final Func_package_global_from_name t_package_global_from_name = new Core.Class_package_global_from_name();

  public static Core.Type_package f_package_global_from_name(final Core.Type_string name) {
    Core.Type_package output = Core.e_package;
    output = Core.f_any_from_map(
      Core.t_package,
      Core.c_global.packagemap(),
      name
    );
    return output;
  }

  /**
   * @function packagename_from_typedef
   * Returns the package name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   * (func packagename<-typedef)
   */
  public static interface Func_packagename_from_typedef extends Core.Func_any_from_any {
    public Core.Type_string f_packagename_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_packagename_from_typedef extends Core.Class_base implements Func_packagename_from_typedef {

    @Override
    public Func_packagename_from_typedef vx_new(Object... vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    @Override
    public Func_packagename_from_typedef vx_copy(Object... vals) {
      Class_packagename_from_typedef output = new Class_packagename_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "packagename<-typedef", // name
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
    public Func_packagename_from_typedef vx_empty() {return e_packagename_from_typedef;}
    @Override
    public Func_packagename_from_typedef vx_type() {return t_packagename_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_packagename_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_packagename_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_string f_packagename_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_packagename_from_typedef(vtypedef);
    }

  }

  public static final Func_packagename_from_typedef e_packagename_from_typedef = new Core.Class_packagename_from_typedef();
  public static final Func_packagename_from_typedef t_packagename_from_typedef = new Core.Class_packagename_from_typedef();

  public static Core.Type_string f_packagename_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_string output = Core.e_string;
    output = vtypedef.pkgname();
    return output;
  }

  /**
   * @function path_from_context_path
   * Returns a path from a context
   * @param  {string} path
   * @return {string}
   * (func path<-context-path)
   */
  public static interface Func_path_from_context_path extends Core.Func_any_from_any_context {
    public Core.Type_string f_path_from_context_path(final Core.Type_context context, final Core.Type_string path);
  }

  public static class Class_path_from_context_path extends Core.Class_base implements Func_path_from_context_path {

    @Override
    public Func_path_from_context_path vx_new(Object... vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    @Override
    public Func_path_from_context_path vx_copy(Object... vals) {
      Class_path_from_context_path output = new Class_path_from_context_path();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "path<-context-path", // name
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
    public Func_path_from_context_path vx_empty() {return e_path_from_context_path;}
    @Override
    public Func_path_from_context_path vx_type() {return t_path_from_context_path;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_path_from_context_path(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string path = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_path_from_context_path(context, path);
      return output;
    }

    @Override
    public Core.Type_string f_path_from_context_path(final Core.Type_context context, final Core.Type_string path) {
      return Core.f_path_from_context_path(context, path);
    }

  }

  public static final Func_path_from_context_path e_path_from_context_path = new Core.Class_path_from_context_path();
  public static final Func_path_from_context_path t_path_from_context_path = new Core.Class_path_from_context_path();

  public static Core.Type_string f_path_from_context_path(final Core.Type_context context, final Core.Type_string path) {
    Core.Type_string output = Core.e_string;
    output = Core.f_path_from_setting_path(
      Core.f_setting_from_context(context),
      path
    );
    return output;
  }

  /**
   * @function path_from_setting_path
   * Returns a path from a setting
   * @param  {setting} session
   * @param  {string} path
   * @return {string}
   * (func path<-setting-path)
   */
  public static interface Func_path_from_setting_path extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_path_from_setting_path(final Core.Type_setting session, final Core.Type_string path);
  }

  public static class Class_path_from_setting_path extends Core.Class_base implements Func_path_from_setting_path {

    @Override
    public Func_path_from_setting_path vx_new(Object... vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    @Override
    public Func_path_from_setting_path vx_copy(Object... vals) {
      Class_path_from_setting_path output = new Class_path_from_setting_path();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "path<-setting-path", // name
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
    public Func_path_from_setting_path vx_empty() {return e_path_from_setting_path;}
    @Override
    public Func_path_from_setting_path vx_type() {return t_path_from_setting_path;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_setting session = Core.f_any_from_any(Core.t_setting, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string path = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_path_from_setting_path(session, path);
      return output;
    }

    @Override
    public Core.Type_string f_path_from_setting_path(final Core.Type_setting session, final Core.Type_string path) {
      return Core.f_path_from_setting_path(session, path);
    }

  }

  public static final Func_path_from_setting_path e_path_from_setting_path = new Core.Class_path_from_setting_path();
  public static final Func_path_from_setting_path t_path_from_setting_path = new Core.Class_path_from_setting_path();

  public static Core.Type_string f_path_from_setting_path(final Core.Type_setting session, final Core.Type_string path) {
    Core.Type_string output = Core.e_string;
    return output;
  }

  /**
   * @function permission_from_id_context
   * Return a permission from context by id
   * @param  {string} id
   * @return {permission}
   * (func permission<-id-context)
   */
  public static interface Func_permission_from_id_context extends Core.Func_any_from_any_context {
    public Core.Type_permission f_permission_from_id_context(final Core.Type_context context, final Core.Type_string id);
  }

  public static class Class_permission_from_id_context extends Core.Class_base implements Func_permission_from_id_context {

    @Override
    public Func_permission_from_id_context vx_new(Object... vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    @Override
    public Func_permission_from_id_context vx_copy(Object... vals) {
      Class_permission_from_id_context output = new Class_permission_from_id_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "permission<-id-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "permission", // name
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
    public Func_permission_from_id_context vx_empty() {return e_permission_from_id_context;}
    @Override
    public Func_permission_from_id_context vx_type() {return t_permission_from_id_context;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Core.f_permission_from_id_context(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_permission_from_id_context(context, id);
      return output;
    }

    @Override
    public Core.Type_permission f_permission_from_id_context(final Core.Type_context context, final Core.Type_string id) {
      return Core.f_permission_from_id_context(context, id);
    }

  }

  public static final Func_permission_from_id_context e_permission_from_id_context = new Core.Class_permission_from_id_context();
  public static final Func_permission_from_id_context t_permission_from_id_context = new Core.Class_permission_from_id_context();

  public static Core.Type_permission f_permission_from_id_context(final Core.Type_context context, final Core.Type_string id) {
    Core.Type_permission output = Core.e_permission;
    output = Core.f_let(
      Core.t_permission,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_user user = Core.f_user_from_context(context);
        final Core.Type_security security = user.security();
        final Core.Type_permissionmap permissionmap = security.permissionmap();
        return Core.f_any_from_map(Core.t_permission, permissionmap, Core.vx_new_string(":id"));
      })
    );
    return output;
  }

  /**
   * @function properties_from_typedef
   * Return property map from typedef
   * @param  {typedef} vtypedef
   * @return {argmap}
   * (func properties<-typedef)
   */
  public static interface Func_properties_from_typedef extends Core.Func_any_from_any {
    public Core.Type_argmap f_properties_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_properties_from_typedef extends Core.Class_base implements Func_properties_from_typedef {

    @Override
    public Func_properties_from_typedef vx_new(Object... vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    @Override
    public Func_properties_from_typedef vx_copy(Object... vals) {
      Class_properties_from_typedef output = new Class_properties_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "properties<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_arg), // allowtypes
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
    public Func_properties_from_typedef vx_empty() {return e_properties_from_typedef;}
    @Override
    public Func_properties_from_typedef vx_type() {return t_properties_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_properties_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_properties_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_argmap f_properties_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_properties_from_typedef(vtypedef);
    }

  }

  public static final Func_properties_from_typedef e_properties_from_typedef = new Core.Class_properties_from_typedef();
  public static final Func_properties_from_typedef t_properties_from_typedef = new Core.Class_properties_from_typedef();

  public static Core.Type_argmap f_properties_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_argmap output = Core.e_argmap;
    output = vtypedef.properties();
    return output;
  }

  /**
   * @function proplast_from_typedef
   * Return last property from typedef
   * @param  {typedef} vtypedef
   * @return {arg}
   * (func proplast<-typedef)
   */
  public static interface Func_proplast_from_typedef extends Core.Func_any_from_any {
    public Core.Type_arg f_proplast_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_proplast_from_typedef extends Core.Class_base implements Func_proplast_from_typedef {

    @Override
    public Func_proplast_from_typedef vx_new(Object... vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    @Override
    public Func_proplast_from_typedef vx_copy(Object... vals) {
      Class_proplast_from_typedef output = new Class_proplast_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "proplast<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "arg", // name
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
    public Func_proplast_from_typedef vx_empty() {return e_proplast_from_typedef;}
    @Override
    public Func_proplast_from_typedef vx_type() {return t_proplast_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_proplast_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_proplast_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_arg f_proplast_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_proplast_from_typedef(vtypedef);
    }

  }

  public static final Func_proplast_from_typedef e_proplast_from_typedef = new Core.Class_proplast_from_typedef();
  public static final Func_proplast_from_typedef t_proplast_from_typedef = new Core.Class_proplast_from_typedef();

  public static Core.Type_arg f_proplast_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_arg output = Core.e_arg;
    output = vtypedef.proplast();
    return output;
  }

  /**
   * @function resolve
   * @param  {any-1} value
   * @return {any-1}
   * (func resolve)
   */
  public static interface Func_resolve extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T f_resolve(final T generic_any_1, final T value);
  }

  public static class Class_resolve extends Core.Class_base implements Func_resolve {

    @Override
    public Func_resolve vx_new(Object... vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    @Override
    public Func_resolve vx_copy(Object... vals) {
      Class_resolve output = new Class_resolve();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_resolve vx_empty() {return e_resolve;}
    @Override
    public Func_resolve vx_type() {return t_resolve;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_resolve(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_resolve(generic_any_1, value);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_resolve(final T generic_any_1, final T value) {
      return Core.f_resolve(generic_any_1, value);
    }

  }

  public static final Func_resolve e_resolve = new Core.Class_resolve();
  public static final Func_resolve t_resolve = new Core.Class_resolve();

  public static <T extends Core.Type_any> T f_resolve(final T generic_any_1, final T value) {
    T output = Core.f_empty(generic_any_1);
    output = value;
    return output;
  }

  /**
   * @function resolve 1
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func resolve)
   */
  public static interface Func_resolve_1 extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T f_resolve_1(final T generic_any_1, final Core.Func_any_from_func fn_any);
  }

  public static class Class_resolve_1 extends Core.Class_base implements Func_resolve_1 {

    @Override
    public Func_resolve_1 vx_new(Object... vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    @Override
    public Func_resolve_1 vx_copy(Object... vals) {
      Class_resolve_1 output = new Class_resolve_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_resolve_1 vx_empty() {return e_resolve_1;}
    @Override
    public Func_resolve_1 vx_type() {return t_resolve_1;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func inputval = (Core.Func_any_from_func)value;
      Core.Type_any outputval = Core.f_resolve_1(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_resolve_1(generic_any_1, fn_any);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_resolve_1(final T generic_any_1, final Core.Func_any_from_func fn_any) {
      return Core.f_resolve_1(generic_any_1, fn_any);
    }

  }

  public static final Func_resolve_1 e_resolve_1 = new Core.Class_resolve_1();
  public static final Func_resolve_1 t_resolve_1 = new Core.Class_resolve_1();

  public static <T extends Core.Type_any> T f_resolve_1(final T generic_any_1, final Core.Func_any_from_func fn_any) {
    T output = Core.f_empty(generic_any_1);
    if (fn_any != null) {
      output = fn_any.f_any_from_func(generic_any_1);
    };
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_async
   * @param  {any<-func-async} fn-any
   * @return {any-1}
   * (func resolve-async)
   */
  public static interface Func_resolve_async extends Core.Func_any_from_any_async {
    public <T extends Core.Type_any> CompletableFuture<T> f_resolve_async(final T generic_any_1, final Core.Func_any_from_func_async fn_any);
  }

  public static class Class_resolve_async extends Core.Class_base implements Func_resolve_async {

    @Override
    public Func_resolve_async vx_new(Object... vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    @Override
    public Func_resolve_async vx_copy(Object... vals) {
      Class_resolve_async output = new Class_resolve_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-async", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_resolve_async vx_empty() {return e_resolve_async;}
    @Override
    public Func_resolve_async vx_type() {return t_resolve_async;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      T inputval = Core.f_any_from_any(generic_any_1, value);
      CompletableFuture<T> output = Core.f_async(generic_any_1, inputval);
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_any = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_any> future = Core.f_resolve_async(generic_any_1, fn_any);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public <T extends Core.Type_any> CompletableFuture<T> f_resolve_async(final T generic_any_1, final Core.Func_any_from_func_async fn_any) {
      return Core.f_resolve_async(generic_any_1, fn_any);
    }

  }

  public static final Func_resolve_async e_resolve_async = new Core.Class_resolve_async();
  public static final Func_resolve_async t_resolve_async = new Core.Class_resolve_async();

  public static <T extends Core.Type_any> CompletableFuture<T> f_resolve_async(final T generic_any_1, final Core.Func_any_from_func_async fn_any) {
    CompletableFuture<T> output = Core.async_new_completed(Core.f_empty(generic_any_1));
    if (fn_any != null) {
      output = fn_any.f_any_from_func_async(generic_any_1);
    };
    return output;
  }

  /**
   * @function resolve_first
   * Returns the first value that is not nothing
   * @param  {list-1} clauses
   * @return {any-1}
   * (func resolve-first)
   */
  public static interface Func_resolve_first extends Core.Func_any_from_any {
    public <T extends Core.Type_any, X extends Core.Type_list> T f_resolve_first(final T generic_any_1, final X clauses);
  }

  public static class Class_resolve_first extends Core.Class_base implements Func_resolve_first {

    @Override
    public Func_resolve_first vx_new(Object... vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    @Override
    public Func_resolve_first vx_copy(Object... vals) {
      Class_resolve_first output = new Class_resolve_first();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-first", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_resolve_first vx_empty() {return e_resolve_first;}
    @Override
    public Func_resolve_first vx_type() {return t_resolve_first;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_list inputval = (Core.Type_list)value;
      Core.Type_any outputval = Core.f_resolve_first(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list clauses = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_resolve_first(generic_any_1, clauses);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> T f_resolve_first(final T generic_any_1, final X clauses) {
      return Core.f_resolve_first(generic_any_1, clauses);
    }

  }

  public static final Func_resolve_first e_resolve_first = new Core.Class_resolve_first();
  public static final Func_resolve_first t_resolve_first = new Core.Class_resolve_first();

  public static <T extends Core.Type_any, X extends Core.Type_list> T f_resolve_first(final T generic_any_1, final X clauses) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_first_from_list_any_from_any(
      generic_any_1,
      clauses,
      Core.t_resolve
    );
    return output;
  }

  /**
   * @function resolve_list
   * @param  {list-1} clauses
   * @return {list-1}
   * (func resolve-list)
   */
  public static interface Func_resolve_list extends Core.Func_any_from_any {
    public <X extends Core.Type_list> X f_resolve_list(final X generic_any_1, final X clauses);
  }

  public static class Class_resolve_list extends Core.Class_base implements Func_resolve_list {

    @Override
    public Func_resolve_list vx_new(Object... vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    @Override
    public Func_resolve_list vx_copy(Object... vals) {
      Class_resolve_list output = new Class_resolve_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "resolve-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_resolve_list vx_empty() {return e_resolve_list;}
    @Override
    public Func_resolve_list vx_type() {return t_resolve_list;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_list inputval = (Core.Type_list)value;
      Core.Type_any outputval = Core.f_resolve_list(Core.t_list, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list clauses = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_resolve_list(generic_list_1, clauses);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X f_resolve_list(final X generic_list_1, final X clauses) {
      return Core.f_resolve_list(generic_list_1, clauses);
    }

  }

  public static final Func_resolve_list e_resolve_list = new Core.Class_resolve_list();
  public static final Func_resolve_list t_resolve_list = new Core.Class_resolve_list();

  public static <X extends Core.Type_list> X f_resolve_list(final X generic_list_1, final X clauses) {
    X output = Core.f_empty(generic_list_1);
    output = Core.f_list_from_list(
      generic_list_1,
      clauses,
      Core.t_resolve
    );
    return output;
  }

  /**
   * @function security_from_context
   * Return security from the given context.
   * @return {security}
   * (func security<-context)
   */
  public static interface Func_security_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_security f_security_from_context(final Core.Type_context context);
  }

  public static class Class_security_from_context extends Core.Class_base implements Func_security_from_context {

    @Override
    public Func_security_from_context vx_new(Object... vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    @Override
    public Func_security_from_context vx_copy(Object... vals) {
      Class_security_from_context output = new Class_security_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "security<-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
    public Func_security_from_context vx_empty() {return e_security_from_context;}
    @Override
    public Func_security_from_context vx_type() {return t_security_from_context;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_security_from_context(context);
      return output;
    }

    @Override
    public Core.Type_security f_security_from_context(final Core.Type_context context) {
      return Core.f_security_from_context(context);
    }

  }

  public static final Func_security_from_context e_security_from_context = new Core.Class_security_from_context();
  public static final Func_security_from_context t_security_from_context = new Core.Class_security_from_context();

  public static Core.Type_security f_security_from_context(final Core.Type_context context) {
    Core.Type_security output = Core.e_security;
    output = Core.f_security_from_user(
      Core.f_user_from_context(context)
    );
    return output;
  }

  /**
   * @function security_from_user
   * Return security from the given user.
   * @param  {user} user
   * @return {security}
   * (func security<-user)
   */
  public static interface Func_security_from_user extends Core.Func_any_from_any {
    public Core.Type_security f_security_from_user(final Core.Type_user user);
  }

  public static class Class_security_from_user extends Core.Class_base implements Func_security_from_user {

    @Override
    public Func_security_from_user vx_new(Object... vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    @Override
    public Func_security_from_user vx_copy(Object... vals) {
      Class_security_from_user output = new Class_security_from_user();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "security<-user", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
    public Func_security_from_user vx_empty() {return e_security_from_user;}
    @Override
    public Func_security_from_user vx_type() {return t_security_from_user;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_user inputval = (Core.Type_user)value;
      Core.Type_any outputval = Core.f_security_from_user(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_user user = Core.f_any_from_any(Core.t_user, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_security_from_user(user);
      return output;
    }

    @Override
    public Core.Type_security f_security_from_user(final Core.Type_user user) {
      return Core.f_security_from_user(user);
    }

  }

  public static final Func_security_from_user e_security_from_user = new Core.Class_security_from_user();
  public static final Func_security_from_user t_security_from_user = new Core.Class_security_from_user();

  public static Core.Type_security f_security_from_user(final Core.Type_user user) {
    Core.Type_security output = Core.e_security;
    output = user.security();
    return output;
  }

  /**
   * @function session_from_context
   * Returns session from a context
   * @return {session}
   * (func session<-context)
   */
  public static interface Func_session_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_session f_session_from_context(final Core.Type_context context);
  }

  public static class Class_session_from_context extends Core.Class_base implements Func_session_from_context {

    @Override
    public Func_session_from_context vx_new(Object... vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    @Override
    public Func_session_from_context vx_copy(Object... vals) {
      Class_session_from_context output = new Class_session_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "session<-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
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
    public Func_session_from_context vx_empty() {return e_session_from_context;}
    @Override
    public Func_session_from_context vx_type() {return t_session_from_context;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_session_from_context(context);
      return output;
    }

    @Override
    public Core.Type_session f_session_from_context(final Core.Type_context context) {
      return Core.f_session_from_context(context);
    }

  }

  public static final Func_session_from_context e_session_from_context = new Core.Class_session_from_context();
  public static final Func_session_from_context t_session_from_context = new Core.Class_session_from_context();

  public static Core.Type_session f_session_from_context(final Core.Type_context context) {
    Core.Type_session output = Core.e_session;
    output = context.session();
    return output;
  }

  /**
   * @function setting_from_context
   * Returns setting from a context
   * @return {setting}
   * (func setting<-context)
   */
  public static interface Func_setting_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_setting f_setting_from_context(final Core.Type_context context);
  }

  public static class Class_setting_from_context extends Core.Class_base implements Func_setting_from_context {

    @Override
    public Func_setting_from_context vx_new(Object... vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    @Override
    public Func_setting_from_context vx_copy(Object... vals) {
      Class_setting_from_context output = new Class_setting_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "setting<-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "setting", // name
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
    public Func_setting_from_context vx_empty() {return e_setting_from_context;}
    @Override
    public Func_setting_from_context vx_type() {return t_setting_from_context;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_setting_from_context(context);
      return output;
    }

    @Override
    public Core.Type_setting f_setting_from_context(final Core.Type_context context) {
      return Core.f_setting_from_context(context);
    }

  }

  public static final Func_setting_from_context e_setting_from_context = new Core.Class_setting_from_context();
  public static final Func_setting_from_context t_setting_from_context = new Core.Class_setting_from_context();

  public static Core.Type_setting f_setting_from_context(final Core.Type_context context) {
    Core.Type_setting output = Core.e_setting;
    output = context.setting();
    return output;
  }

  /**
   * @function string_repeat
   * @param  {string} text
   * @param  {int} repeat
   * @return {string}
   * (func string-repeat)
   */
  public static interface Func_string_repeat extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_repeat(final Core.Type_string text, final Core.Type_int repeat);
  }

  public static class Class_string_repeat extends Core.Class_base implements Func_string_repeat {

    @Override
    public Func_string_repeat vx_new(Object... vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    @Override
    public Func_string_repeat vx_copy(Object... vals) {
      Class_string_repeat output = new Class_string_repeat();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "string-repeat", // name
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
    public Func_string_repeat vx_empty() {return e_string_repeat;}
    @Override
    public Func_string_repeat vx_type() {return t_string_repeat;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int repeat = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_string_repeat(text, repeat);
      return output;
    }

    @Override
    public Core.Type_string f_string_repeat(final Core.Type_string text, final Core.Type_int repeat) {
      return Core.f_string_repeat(text, repeat);
    }

  }

  public static final Func_string_repeat e_string_repeat = new Core.Class_string_repeat();
  public static final Func_string_repeat t_string_repeat = new Core.Class_string_repeat();

  public static Core.Type_string f_string_repeat(final Core.Type_string text, final Core.Type_int repeat) {
    Core.Type_string output = Core.e_string;
    String stringtext = text.vx_string();
    int intrepeat = repeat.vx_int();
    String stringresult = stringtext.repeat(intrepeat);
    output = Core.vx_new_string(stringresult);
    return output;
  }

  /**
   * @function string_from_any
   * Return a string representation of a value
   * @param  {any} value
   * @return {string}
   * (func string<-any)
   */
  public static interface Func_string_from_any extends Core.Func_any_from_any {
    public Core.Type_string f_string_from_any(final Core.Type_any value);
  }

  public static class Class_string_from_any extends Core.Class_base implements Func_string_from_any {

    @Override
    public Func_string_from_any vx_new(Object... vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    @Override
    public Func_string_from_any vx_copy(Object... vals) {
      Class_string_from_any output = new Class_string_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "string<-any", // name
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
    public Func_string_from_any vx_empty() {return e_string_from_any;}
    @Override
    public Func_string_from_any vx_type() {return t_string_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_string_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_string_from_any(value);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_any(final Core.Type_any value) {
      return Core.f_string_from_any(value);
    }

  }

  public static final Func_string_from_any e_string_from_any = new Core.Class_string_from_any();
  public static final Func_string_from_any t_string_from_any = new Core.Class_string_from_any();

  public static Core.Type_string f_string_from_any(final Core.Type_any value) {
    Core.Type_string output = Core.e_string;
    output = Core.f_string_from_any_indent(
      value,
      Core.vx_new_int(0),
      Core.vx_new_boolean(true)
    );
    return output;
  }

  /**
   * @function string_from_any_indent
   * Return a string representation of a value
   * @param  {any} value
   * @param  {int} indent
   * @param  {boolean} linefeed
   * @return {string}
   * (func string<-any-indent)
   */
  public static interface Func_string_from_any_indent extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string f_string_from_any_indent(final Core.Type_any value, final Core.Type_int indent, final Core.Type_boolean linefeed);
  }

  public static class Class_string_from_any_indent extends Core.Class_base implements Func_string_from_any_indent {

    @Override
    public Func_string_from_any_indent vx_new(Object... vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    @Override
    public Func_string_from_any_indent vx_copy(Object... vals) {
      Class_string_from_any_indent output = new Class_string_from_any_indent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "string<-any-indent", // name
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
    public Func_string_from_any_indent vx_empty() {return e_string_from_any_indent;}
    @Override
    public Func_string_from_any_indent vx_type() {return t_string_from_any_indent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int indent = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_boolean linefeed = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(2)));
      output = Core.f_string_from_any_indent(value, indent, linefeed);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_any_indent(final Core.Type_any value, final Core.Type_int indent, final Core.Type_boolean linefeed) {
      return Core.f_string_from_any_indent(value, indent, linefeed);
    }

  }

  public static final Func_string_from_any_indent e_string_from_any_indent = new Core.Class_string_from_any_indent();
  public static final Func_string_from_any_indent t_string_from_any_indent = new Core.Class_string_from_any_indent();

  public static Core.Type_string f_string_from_any_indent(final Core.Type_any value, final Core.Type_int indent, final Core.Type_boolean linefeed) {
    Core.Type_string output = Core.e_string;
    String soutput = Core.vx_string_from_any_indent(value, indent.vx_int(), linefeed.vx_boolean());
    output = Core.vx_new_string(soutput);
    return output;
  }

  /**
   * @function string_from_func
   * Function Type returning string with any parameters
   * @return {string}
   * (func string<-func)
   */
  public static interface Func_string_from_func extends Core.Type_func, Core.Type_replfunc {
    public Func_string_from_func vx_fn_new(Core.Class_any_from_func.IFn fn);
    public Core.Type_string f_string_from_func();
  }

  public static class Class_string_from_func extends Core.Class_base implements Func_string_from_func {

    @Override
    public Func_string_from_func vx_new(Object... vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    @Override
    public Func_string_from_func vx_copy(Object... vals) {
      Class_string_from_func output = new Class_string_from_func();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "string<-func", // name
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
    public Func_string_from_func vx_empty() {return e_string_from_func;}
    @Override
    public Func_string_from_func vx_type() {return t_string_from_func;}

    public Core.Class_any_from_func.IFn fn = null;

    @Override
    public Func_string_from_func vx_fn_new(Core.Class_any_from_func.IFn fn) {
      Class_string_from_func output = new Class_string_from_func();
      output.fn = fn;
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Core.f_string_from_func();
      return output;
    }

    @Override
    public Core.Type_string f_string_from_func() {
      return Core.f_string_from_func();
    }

  }

  public static final Func_string_from_func e_string_from_func = new Core.Class_string_from_func();
  public static final Func_string_from_func t_string_from_func = new Core.Class_string_from_func();

  public static Core.Type_string f_string_from_func() {
    Core.Type_string output = Core.e_string;
    return output;
  }

  /**
   * @function switch
   * @param  {any-2} val
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func switch)
   */
  public static interface Func_switch extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, U extends Core.Type_any> T f_switch(final T generic_any_1, final U val, final Core.Type_thenelselist thenelselist);
  }

  public static class Class_switch extends Core.Class_base implements Func_switch {

    @Override
    public Func_switch vx_new(Object... vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    @Override
    public Func_switch vx_copy(Object... vals) {
      Class_switch output = new Class_switch();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "switch", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Func_switch vx_empty() {return e_switch;}
    @Override
    public Func_switch vx_type() {return t_switch;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_thenelselist thenelselist = Core.f_any_from_any(Core.t_thenelselist, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_switch(generic_any_1, val, thenelselist);
      return output;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_switch(final T generic_any_1, final U val, final Core.Type_thenelselist thenelselist) {
      return Core.f_switch(generic_any_1, val, thenelselist);
    }

  }

  public static final Func_switch e_switch = new Core.Class_switch();
  public static final Func_switch t_switch = new Core.Class_switch();

  public static <T extends Core.Type_any, U extends Core.Type_any> T f_switch(final T generic_any_1, final U val, final Core.Type_thenelselist thenelselist) {
    T output = Core.f_empty(generic_any_1);
    Core.Func_any_from_func fn_any = null;
    List<Core.Type_thenelse> listthenelse = thenelselist.vx_listthenelse();
    for (Core.Type_thenelse thenelse : listthenelse) {
      Core.Type_string code = thenelse.code();
      switch (code.vx_string()) {
      case ":case":
        Core.Type_any value = thenelse.value();
        Core.Type_boolean iseq = Core.f_eq(val, value);
        if (iseq.vx_boolean()) {
          fn_any = thenelse.fn_any();
        }
        break;
      case ":casemany":
        Core.Type_list values = thenelse.values();
        Core.Type_boolean iscontain = Core.f_contains_1(values, val);
        if (iscontain.vx_boolean()) {
          fn_any = thenelse.fn_any();
        }
        break;
      case ":else":
        fn_any = thenelse.fn_any();
        break;
      }
      if (fn_any != null) {
        break;
      }
    }
    if (fn_any != null) {
      output = fn_any.f_any_from_func(generic_any_1);
    };
    return output;
  }

  /**
   * @function then
   * @param  {boolean<-func} fn-cond
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func then)
   */
  public static interface Func_then extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_thenelse f_then(final Core.Func_boolean_from_func fn_cond, final Core.Func_any_from_func fn_any);
  }

  public static class Class_then extends Core.Class_base implements Func_then {

    @Override
    public Func_then vx_new(Object... vals) {
      Class_then output = new Class_then();
      return output;
    }

    @Override
    public Func_then vx_copy(Object... vals) {
      Class_then output = new Class_then();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "then", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
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
    public Func_then vx_empty() {return e_then;}
    @Override
    public Func_then vx_type() {return t_then;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Func_boolean_from_func fn_cond = Core.f_any_from_any(Core.t_boolean_from_func, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func fn_any = Core.f_any_from_any(Core.t_any_from_func, arglist.vx_any(Core.vx_new_int(1)));
      output = Core.f_then(fn_cond, fn_any);
      return output;
    }

    @Override
    public Core.Type_thenelse f_then(final Core.Func_boolean_from_func fn_cond, final Core.Func_any_from_func fn_any) {
      return Core.f_then(fn_cond, fn_any);
    }

  }

  public static final Func_then e_then = new Core.Class_then();
  public static final Func_then t_then = new Core.Class_then();

  public static Core.Type_thenelse f_then(final Core.Func_boolean_from_func fn_cond, final Core.Func_any_from_func fn_any) {
    Core.Type_thenelse output = Core.e_thenelse;
    output = Core.f_new(
      Core.t_thenelse,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":code"),
        Core.vx_new_string(":then"),
        Core.vx_new_string(":fn-cond"),
        fn_cond,
        Core.vx_new_string(":fn-any"),
        fn_any
      )
    );
    return output;
  }

  /**
   * @function traits_from_typedef
   * Return trait list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func traits<-typedef)
   */
  public static interface Func_traits_from_typedef extends Core.Func_any_from_any {
    public Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_traits_from_typedef extends Core.Class_base implements Func_traits_from_typedef {

    @Override
    public Func_traits_from_typedef vx_new(Object... vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    @Override
    public Func_traits_from_typedef vx_copy(Object... vals) {
      Class_traits_from_typedef output = new Class_traits_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_traits_from_typedef vx_empty() {return e_traits_from_typedef;}
    @Override
    public Func_traits_from_typedef vx_type() {return t_traits_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_traits_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_traits_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_traits_from_typedef(vtypedef);
    }

  }

  public static final Func_traits_from_typedef e_traits_from_typedef = new Core.Class_traits_from_typedef();
  public static final Func_traits_from_typedef t_traits_from_typedef = new Core.Class_traits_from_typedef();

  public static Core.Type_typelist f_traits_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_typelist output = Core.e_typelist;
    output = vtypedef.traits();
    return output;
  }

  /**
   * @function type_from_any
   * Gets the Type of a given Value
   * @param  {any-1} value
   * @return {any}
   * (func type<-any)
   */
  public static interface Func_type_from_any extends Core.Func_any_from_any {
    public Core.Type_any f_type_from_any(final Core.Type_any value);
  }

  public static class Class_type_from_any extends Core.Class_base implements Func_type_from_any {

    @Override
    public Func_type_from_any vx_new(Object... vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    @Override
    public Func_type_from_any vx_copy(Object... vals) {
      Class_type_from_any output = new Class_type_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "type<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_type_from_any vx_empty() {return e_type_from_any;}
    @Override
    public Func_type_from_any vx_type() {return t_type_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_type_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_type_from_any(value);
      return output;
    }

    @Override
    public Core.Type_any f_type_from_any(final Core.Type_any value) {
      return Core.f_type_from_any(value);
    }

  }

  public static final Func_type_from_any e_type_from_any = new Core.Class_type_from_any();
  public static final Func_type_from_any t_type_from_any = new Core.Class_type_from_any();

  public static Core.Type_any f_type_from_any(final Core.Type_any value) {
    Core.Type_any output = Core.e_any;
    output = value.vx_type();
    return output;
  }

  /**
   * @function typedef_from_any
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-any)
   */
  public static interface Func_typedef_from_any extends Core.Func_any_from_any {
    public Core.Type_typedef f_typedef_from_any(final Core.Type_any val);
  }

  public static class Class_typedef_from_any extends Core.Class_base implements Func_typedef_from_any {

    @Override
    public Func_typedef_from_any vx_new(Object... vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    @Override
    public Func_typedef_from_any vx_copy(Object... vals) {
      Class_typedef_from_any output = new Class_typedef_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-any", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
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
    public Func_typedef_from_any vx_empty() {return e_typedef_from_any;}
    @Override
    public Func_typedef_from_any vx_type() {return t_typedef_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_typedef_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typedef_from_any(val);
      return output;
    }

    @Override
    public Core.Type_typedef f_typedef_from_any(final Core.Type_any val) {
      return Core.f_typedef_from_any(val);
    }

  }

  public static final Func_typedef_from_any e_typedef_from_any = new Core.Class_typedef_from_any();
  public static final Func_typedef_from_any t_typedef_from_any = new Core.Class_typedef_from_any();

  public static Core.Type_typedef f_typedef_from_any(final Core.Type_any val) {
    Core.Type_typedef output = Core.e_typedef;
    output = Core.f_typedef_from_type(
      Core.f_type_from_any(val)
    );
    return output;
  }

  /**
   * @function typedef_from_type
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-type)
   */
  public static interface Func_typedef_from_type extends Core.Func_any_from_any {
    public Core.Type_typedef f_typedef_from_type(final Core.Type_any val);
  }

  public static class Class_typedef_from_type extends Core.Class_base implements Func_typedef_from_type {

    @Override
    public Func_typedef_from_type vx_new(Object... vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    @Override
    public Func_typedef_from_type vx_copy(Object... vals) {
      Class_typedef_from_type output = new Class_typedef_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typedef<-type", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "typedef", // name
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
    public Func_typedef_from_type vx_empty() {return e_typedef_from_type;}
    @Override
    public Func_typedef_from_type vx_type() {return t_typedef_from_type;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_typedef_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typedef_from_type(val);
      return output;
    }

    @Override
    public Core.Type_typedef f_typedef_from_type(final Core.Type_any val) {
      return Core.f_typedef_from_type(val);
    }

  }

  public static final Func_typedef_from_type e_typedef_from_type = new Core.Class_typedef_from_type();
  public static final Func_typedef_from_type t_typedef_from_type = new Core.Class_typedef_from_type();

  public static Core.Type_typedef f_typedef_from_type(final Core.Type_any val) {
    Core.Type_typedef output = Core.e_typedef;
    output = val.vx_typedef();
    return output;
  }

  /**
   * @function typename_from_any
   * Gets the type of a given value
   * @param  {any-2} value
   * @return {string}
   * (func typename<-any)
   */
  public static interface Func_typename_from_any extends Core.Func_any_from_any {
    public Core.Type_string f_typename_from_any(final Core.Type_any value);
  }

  public static class Class_typename_from_any extends Core.Class_base implements Func_typename_from_any {

    @Override
    public Func_typename_from_any vx_new(Object... vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    @Override
    public Func_typename_from_any vx_copy(Object... vals) {
      Class_typename_from_any output = new Class_typename_from_any();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-any", // name
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
    public Func_typename_from_any vx_empty() {return e_typename_from_any;}
    @Override
    public Func_typename_from_any vx_type() {return t_typename_from_any;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_typename_from_any(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any value = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typename_from_any(value);
      return output;
    }

    @Override
    public Core.Type_string f_typename_from_any(final Core.Type_any value) {
      return Core.f_typename_from_any(value);
    }

  }

  public static final Func_typename_from_any e_typename_from_any = new Core.Class_typename_from_any();
  public static final Func_typename_from_any t_typename_from_any = new Core.Class_typename_from_any();

  public static Core.Type_string f_typename_from_any(final Core.Type_any value) {
    Core.Type_string output = Core.e_string;
    output = Core.f_typename_from_type(
      Core.f_type_from_any(value)
    );
    return output;
  }

  /**
   * @function typename_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {string}
   * (func typename<-type)
   */
  public static interface Func_typename_from_type extends Core.Func_any_from_any {
    public Core.Type_string f_typename_from_type(final Core.Type_any type);
  }

  public static class Class_typename_from_type extends Core.Class_base implements Func_typename_from_type {

    @Override
    public Func_typename_from_type vx_new(Object... vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    @Override
    public Func_typename_from_type vx_copy(Object... vals) {
      Class_typename_from_type output = new Class_typename_from_type();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-type", // name
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
    public Func_typename_from_type vx_empty() {return e_typename_from_type;}
    @Override
    public Func_typename_from_type vx_type() {return t_typename_from_type;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Core.f_typename_from_type(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typename_from_type(type);
      return output;
    }

    @Override
    public Core.Type_string f_typename_from_type(final Core.Type_any type) {
      return Core.f_typename_from_type(type);
    }

  }

  public static final Func_typename_from_type e_typename_from_type = new Core.Class_typename_from_type();
  public static final Func_typename_from_type t_typename_from_type = new Core.Class_typename_from_type();

  public static Core.Type_string f_typename_from_type(final Core.Type_any type) {
    Core.Type_string output = Core.e_string;
    output = Core.f_typename_from_typedef(
      Core.f_typedef_from_type(type)
    );
    return output;
  }

  /**
   * @function typename_from_typedef
   * Get the name of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   * (func typename<-typedef)
   */
  public static interface Func_typename_from_typedef extends Core.Func_any_from_any {
    public Core.Type_string f_typename_from_typedef(final Core.Type_typedef vtypedef);
  }

  public static class Class_typename_from_typedef extends Core.Class_base implements Func_typename_from_typedef {

    @Override
    public Func_typename_from_typedef vx_new(Object... vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    @Override
    public Func_typename_from_typedef vx_copy(Object... vals) {
      Class_typename_from_typedef output = new Class_typename_from_typedef();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typename<-typedef", // name
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
    public Func_typename_from_typedef vx_empty() {return e_typename_from_typedef;}
    @Override
    public Func_typename_from_typedef vx_type() {return t_typename_from_typedef;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typedef inputval = (Core.Type_typedef)value;
      Core.Type_any outputval = Core.f_typename_from_typedef(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typedef vtypedef = Core.f_any_from_any(Core.t_typedef, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typename_from_typedef(vtypedef);
      return output;
    }

    @Override
    public Core.Type_string f_typename_from_typedef(final Core.Type_typedef vtypedef) {
      return Core.f_typename_from_typedef(vtypedef);
    }

  }

  public static final Func_typename_from_typedef e_typename_from_typedef = new Core.Class_typename_from_typedef();
  public static final Func_typename_from_typedef t_typename_from_typedef = new Core.Class_typename_from_typedef();

  public static Core.Type_string f_typename_from_typedef(final Core.Type_typedef vtypedef) {
    Core.Type_string output = Core.e_string;
    output = Core.f_new(
      Core.t_string,
      Core.t_anylist.vx_new(
        vtypedef.pkgname(),
        Core.vx_new_string("/"),
        vtypedef.name()
      )
    );
    return output;
  }

  /**
   * @function typenames_from_typelist
   * Get the names from a type list
   * @param  {typelist} typelist
   * @return {stringlist}
   * (func typenames<-typelist)
   */
  public static interface Func_typenames_from_typelist extends Core.Func_any_from_any {
    public Core.Type_stringlist f_typenames_from_typelist(final Core.Type_typelist typelist);
  }

  public static class Class_typenames_from_typelist extends Core.Class_base implements Func_typenames_from_typelist {

    @Override
    public Func_typenames_from_typelist vx_new(Object... vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    @Override
    public Func_typenames_from_typelist vx_copy(Object... vals) {
      Class_typenames_from_typelist output = new Class_typenames_from_typelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "typenames<-typelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_string), // allowtypes
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
    public Func_typenames_from_typelist vx_empty() {return e_typenames_from_typelist;}
    @Override
    public Func_typenames_from_typelist vx_type() {return t_typenames_from_typelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_typelist inputval = (Core.Type_typelist)value;
      Core.Type_any outputval = Core.f_typenames_from_typelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_typelist typelist = Core.f_any_from_any(Core.t_typelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_typenames_from_typelist(typelist);
      return output;
    }

    @Override
    public Core.Type_stringlist f_typenames_from_typelist(final Core.Type_typelist typelist) {
      return Core.f_typenames_from_typelist(typelist);
    }

  }

  public static final Func_typenames_from_typelist e_typenames_from_typelist = new Core.Class_typenames_from_typelist();
  public static final Func_typenames_from_typelist t_typenames_from_typelist = new Core.Class_typenames_from_typelist();

  public static Core.Type_stringlist f_typenames_from_typelist(final Core.Type_typelist typelist) {
    Core.Type_stringlist output = Core.e_stringlist;
    output = Core.f_list_from_list(
      Core.t_stringlist,
      typelist,
      Core.t_any_from_any.vx_fn_new((type_any) -> {
        Core.Type_any type = Core.f_any_from_any(Core.t_any, type_any);
        return 
          Core.f_typename_from_type(type);
      })
    );
    return output;
  }

  /**
   * @function user_from_context
   * Returns the current user from context.
   * @return {user}
   * (func user<-context)
   */
  public static interface Func_user_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_user f_user_from_context(final Core.Type_context context);
  }

  public static class Class_user_from_context extends Core.Class_base implements Func_user_from_context {

    @Override
    public Func_user_from_context vx_new(Object... vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    @Override
    public Func_user_from_context vx_copy(Object... vals) {
      Class_user_from_context output = new Class_user_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/core", // pkgname
        "user<-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "user", // name
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
    public Func_user_from_context vx_empty() {return e_user_from_context;}
    @Override
    public Func_user_from_context vx_type() {return t_user_from_context;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Core.f_user_from_context(context);
      return output;
    }

    @Override
    public Core.Type_user f_user_from_context(final Core.Type_context context) {
      return Core.f_user_from_context(context);
    }

  }

  public static final Func_user_from_context e_user_from_context = new Core.Class_user_from_context();
  public static final Func_user_from_context t_user_from_context = new Core.Class_user_from_context();

  public static Core.Type_user f_user_from_context(final Core.Type_context context) {
    Core.Type_user output = Core.e_user;
    output = Core.f_session_from_context(context).user();
    return output;
  }


  static {
    Const_false.const_new(c_false);
    Const_global.const_new(c_global);
    Const_infinity.const_new(c_infinity);
    Const_mempool_active.const_new(c_mempool_active);
    Const_msg_error.const_new(c_msg_error);
    Const_msg_info.const_new(c_msg_info);
    Const_msg_severe.const_new(c_msg_severe);
    Const_msg_warning.const_new(c_msg_warning);
    Const_neginfinity.const_new(c_neginfinity);
    Const_newline.const_new(c_newline);
    Const_notanumber.const_new(c_notanumber);
    Const_nothing.const_new(c_nothing);
    Const_quote.const_new(c_quote);
    Const_true.const_new(c_true);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("any", Core.t_any);
    maptype.put("any-async<-func", Core.t_any_async_from_func);
    maptype.put("any<-anylist", Core.t_any_from_anylist);
    maptype.put("anylist", Core.t_anylist);
    maptype.put("anytype", Core.t_anytype);
    maptype.put("arg", Core.t_arg);
    maptype.put("arglist", Core.t_arglist);
    maptype.put("argmap", Core.t_argmap);
    maptype.put("boolean", Core.t_boolean);
    maptype.put("booleanlist", Core.t_booleanlist);
    maptype.put("collection", Core.t_collection);
    maptype.put("compilelanguages", Core.t_compilelanguages);
    maptype.put("connect", Core.t_connect);
    maptype.put("connectlist", Core.t_connectlist);
    maptype.put("connectmap", Core.t_connectmap);
    maptype.put("const", Core.t_const);
    maptype.put("constdef", Core.t_constdef);
    maptype.put("constlist", Core.t_constlist);
    maptype.put("constmap", Core.t_constmap);
    maptype.put("context", Core.t_context);
    maptype.put("decimal", Core.t_decimal);
    maptype.put("error", Core.t_error);
    maptype.put("float", Core.t_float);
    maptype.put("func", Core.t_func);
    maptype.put("funcdef", Core.t_funcdef);
    maptype.put("funclist", Core.t_funclist);
    maptype.put("funcmap", Core.t_funcmap);
    maptype.put("int", Core.t_int);
    maptype.put("intlist", Core.t_intlist);
    maptype.put("intmap", Core.t_intmap);
    maptype.put("list", Core.t_list);
    maptype.put("listtype", Core.t_listtype);
    maptype.put("map", Core.t_map);
    maptype.put("maptype", Core.t_maptype);
    maptype.put("mempool", Core.t_mempool);
    maptype.put("msg", Core.t_msg);
    maptype.put("msgblock", Core.t_msgblock);
    maptype.put("msgblocklist", Core.t_msgblocklist);
    maptype.put("msglist", Core.t_msglist);
    maptype.put("none", Core.t_none);
    maptype.put("notype", Core.t_notype);
    maptype.put("number", Core.t_number);
    maptype.put("numberlist", Core.t_numberlist);
    maptype.put("numbermap", Core.t_numbermap);
    maptype.put("package", Core.t_package);
    maptype.put("packagemap", Core.t_packagemap);
    maptype.put("permission", Core.t_permission);
    maptype.put("permissionlist", Core.t_permissionlist);
    maptype.put("permissionmap", Core.t_permissionmap);
    maptype.put("project", Core.t_project);
    maptype.put("security", Core.t_security);
    maptype.put("session", Core.t_session);
    maptype.put("setting", Core.t_setting);
    maptype.put("state", Core.t_state);
    maptype.put("statelistener", Core.t_statelistener);
    maptype.put("string", Core.t_string);
    maptype.put("stringlist", Core.t_stringlist);
    maptype.put("stringmap", Core.t_stringmap);
    maptype.put("struct", Core.t_struct);
    maptype.put("thenelse", Core.t_thenelse);
    maptype.put("thenelselist", Core.t_thenelselist);
    maptype.put("type", Core.t_type);
    maptype.put("typedef", Core.t_typedef);
    maptype.put("typelist", Core.t_typelist);
    maptype.put("typemap", Core.t_typemap);
    maptype.put("user", Core.t_user);
    maptype.put("value", Core.t_value);
    mapconst.put("false", Core.c_false);
    mapconst.put("global", Core.c_global);
    mapconst.put("infinity", Core.c_infinity);
    mapconst.put("mempool-active", Core.c_mempool_active);
    mapconst.put("msg-error", Core.c_msg_error);
    mapconst.put("msg-info", Core.c_msg_info);
    mapconst.put("msg-severe", Core.c_msg_severe);
    mapconst.put("msg-warning", Core.c_msg_warning);
    mapconst.put("neginfinity", Core.c_neginfinity);
    mapconst.put("newline", Core.c_newline);
    mapconst.put("notanumber", Core.c_notanumber);
    mapconst.put("nothing", Core.c_nothing);
    mapconst.put("quote", Core.c_quote);
    mapconst.put("true", Core.c_true);
    mapfunc.put("!", Core.t_not);
    mapfunc.put("!-empty", Core.t_notempty);
    mapfunc.put("!-empty_1", Core.t_notempty_1);
    mapfunc.put("!=", Core.t_ne);
    mapfunc.put("!==", Core.t_neqeq);
    mapfunc.put("*", Core.t_multiply);
    mapfunc.put("*_1", Core.t_multiply_1);
    mapfunc.put("*_2", Core.t_multiply_2);
    mapfunc.put("*_3", Core.t_multiply_3);
    mapfunc.put("+", Core.t_plus);
    mapfunc.put("+_1", Core.t_plus_1);
    mapfunc.put("+_2", Core.t_plus_2);
    mapfunc.put("+_3", Core.t_plus_3);
    mapfunc.put("+1", Core.t_plus1);
    mapfunc.put("-", Core.t_minus);
    mapfunc.put("-_1", Core.t_minus_1);
    mapfunc.put("-_2", Core.t_minus_2);
    mapfunc.put("-_3", Core.t_minus_3);
    mapfunc.put("-1", Core.t_minus1);
    mapfunc.put(".", Core.t_dotmethod);
    mapfunc.put("/", Core.t_divide);
    mapfunc.put("<", Core.t_lt);
    mapfunc.put("<_1", Core.t_lt_1);
    mapfunc.put("<-", Core.t_chainfirst);
    mapfunc.put("<<-", Core.t_chainlast);
    mapfunc.put("<=", Core.t_le);
    mapfunc.put("<=_1", Core.t_le_1);
    mapfunc.put("=", Core.t_eq);
    mapfunc.put("=_1", Core.t_eq_1);
    mapfunc.put("==", Core.t_eqeq);
    mapfunc.put(">", Core.t_gt);
    mapfunc.put(">_1", Core.t_gt_1);
    mapfunc.put(">=", Core.t_ge);
    mapfunc.put(">=_1", Core.t_ge_1);
    mapfunc.put("allowfuncs<-security", Core.t_allowfuncs_from_security);
    mapfunc.put("allowtypenames<-typedef", Core.t_allowtypenames_from_typedef);
    mapfunc.put("allowtypes<-typedef", Core.t_allowtypes_from_typedef);
    mapfunc.put("and", Core.t_and);
    mapfunc.put("and_1", Core.t_and_1);
    mapfunc.put("any<-any", Core.t_any_from_any);
    mapfunc.put("any<-any-async", Core.t_any_from_any_async);
    mapfunc.put("any<-any-context", Core.t_any_from_any_context);
    mapfunc.put("any<-any-context-async", Core.t_any_from_any_context_async);
    mapfunc.put("any<-func", Core.t_any_from_func);
    mapfunc.put("any<-func-async", Core.t_any_from_func_async);
    mapfunc.put("any<-int", Core.t_any_from_int);
    mapfunc.put("any<-key-value", Core.t_any_from_key_value);
    mapfunc.put("any<-key-value-async", Core.t_any_from_key_value_async);
    mapfunc.put("any<-list", Core.t_any_from_list);
    mapfunc.put("any<-list-reduce", Core.t_any_from_list_reduce);
    mapfunc.put("any<-list-reduce-next", Core.t_any_from_list_reduce_next);
    mapfunc.put("any<-map", Core.t_any_from_map);
    mapfunc.put("any<-none", Core.t_any_from_none);
    mapfunc.put("any<-none-async", Core.t_any_from_none_async);
    mapfunc.put("any<-reduce", Core.t_any_from_reduce);
    mapfunc.put("any<-reduce-async", Core.t_any_from_reduce_async);
    mapfunc.put("any<-reduce-next", Core.t_any_from_reduce_next);
    mapfunc.put("any<-reduce-next-async", Core.t_any_from_reduce_next_async);
    mapfunc.put("any<-struct", Core.t_any_from_struct);
    mapfunc.put("async", Core.t_async);
    mapfunc.put("boolean-permission<-func", Core.t_boolean_permission_from_func);
    mapfunc.put("boolean<-any", Core.t_boolean_from_any);
    mapfunc.put("boolean<-func", Core.t_boolean_from_func);
    mapfunc.put("boolean<-none", Core.t_boolean_from_none);
    mapfunc.put("case", Core.t_case);
    mapfunc.put("case_1", Core.t_case_1);
    mapfunc.put("compare", Core.t_compare);
    mapfunc.put("contains", Core.t_contains);
    mapfunc.put("contains_1", Core.t_contains_1);
    mapfunc.put("context-main", Core.t_context_main);
    mapfunc.put("copy", Core.t_copy);
    mapfunc.put("else", Core.t_else);
    mapfunc.put("empty", Core.t_empty);
    mapfunc.put("extends<-any", Core.t_extends_from_any);
    mapfunc.put("extends<-typedef", Core.t_extends_from_typedef);
    mapfunc.put("first<-list", Core.t_first_from_list);
    mapfunc.put("first<-list-any<-any", Core.t_first_from_list_any_from_any);
    mapfunc.put("float<-string", Core.t_float_from_string);
    mapfunc.put("fn", Core.t_fn);
    mapfunc.put("funcdef<-func", Core.t_funcdef_from_func);
    mapfunc.put("funcname<-funcdef", Core.t_funcname_from_funcdef);
    mapfunc.put("if", Core.t_if);
    mapfunc.put("if_1", Core.t_if_1);
    mapfunc.put("if_2", Core.t_if_2);
    mapfunc.put("int<-func", Core.t_int_from_func);
    mapfunc.put("int<-string", Core.t_int_from_string);
    mapfunc.put("is-empty", Core.t_is_empty);
    mapfunc.put("is-empty_1", Core.t_is_empty_1);
    mapfunc.put("is-endswith", Core.t_is_endswith);
    mapfunc.put("is-float", Core.t_is_float);
    mapfunc.put("is-func", Core.t_is_func);
    mapfunc.put("is-int", Core.t_is_int);
    mapfunc.put("is-number", Core.t_is_number);
    mapfunc.put("is-pass<-permission", Core.t_is_pass_from_permission);
    mapfunc.put("last<-list", Core.t_last_from_list);
    mapfunc.put("length<-list", Core.t_length_from_list);
    mapfunc.put("let", Core.t_let);
    mapfunc.put("let-async", Core.t_let_async);
    mapfunc.put("list-join<-list", Core.t_list_join_from_list);
    mapfunc.put("list<-list", Core.t_list_from_list);
    mapfunc.put("list<-list-async", Core.t_list_from_list_async);
    mapfunc.put("list<-map", Core.t_list_from_map);
    mapfunc.put("list<-map-async", Core.t_list_from_map_async);
    mapfunc.put("list<-type", Core.t_list_from_type);
    mapfunc.put("log", Core.t_log);
    mapfunc.put("log_1", Core.t_log_1);
    mapfunc.put("main", Core.t_main);
    mapfunc.put("map<-list", Core.t_map_from_list);
    mapfunc.put("mempool-addref", Core.t_mempool_addref);
    mapfunc.put("mempool-release", Core.t_mempool_release);
    mapfunc.put("mempool-removeref", Core.t_mempool_removeref);
    mapfunc.put("mempool-removerefchildren", Core.t_mempool_removerefchildren);
    mapfunc.put("mempool-reserve", Core.t_mempool_reserve);
    mapfunc.put("msg<-error", Core.t_msg_from_error);
    mapfunc.put("msg<-warning", Core.t_msg_from_warning);
    mapfunc.put("msgblock<-msgblock-msg", Core.t_msgblock_from_msgblock_msg);
    mapfunc.put("msgblock<-msgblock-msgblock", Core.t_msgblock_from_msgblock_msgblock);
    mapfunc.put("name<-typedef", Core.t_name_from_typedef);
    mapfunc.put("native", Core.t_native);
    mapfunc.put("native<-any", Core.t_native_from_any);
    mapfunc.put("new", Core.t_new);
    mapfunc.put("number<-func", Core.t_number_from_func);
    mapfunc.put("or", Core.t_or);
    mapfunc.put("or_1", Core.t_or_1);
    mapfunc.put("package-global<-name", Core.t_package_global_from_name);
    mapfunc.put("packagename<-typedef", Core.t_packagename_from_typedef);
    mapfunc.put("path<-context-path", Core.t_path_from_context_path);
    mapfunc.put("path<-setting-path", Core.t_path_from_setting_path);
    mapfunc.put("permission<-id-context", Core.t_permission_from_id_context);
    mapfunc.put("properties<-typedef", Core.t_properties_from_typedef);
    mapfunc.put("proplast<-typedef", Core.t_proplast_from_typedef);
    mapfunc.put("resolve", Core.t_resolve);
    mapfunc.put("resolve_1", Core.t_resolve_1);
    mapfunc.put("resolve-async", Core.t_resolve_async);
    mapfunc.put("resolve-first", Core.t_resolve_first);
    mapfunc.put("resolve-list", Core.t_resolve_list);
    mapfunc.put("security<-context", Core.t_security_from_context);
    mapfunc.put("security<-user", Core.t_security_from_user);
    mapfunc.put("session<-context", Core.t_session_from_context);
    mapfunc.put("setting<-context", Core.t_setting_from_context);
    mapfunc.put("string-repeat", Core.t_string_repeat);
    mapfunc.put("string<-any", Core.t_string_from_any);
    mapfunc.put("string<-any-indent", Core.t_string_from_any_indent);
    mapfunc.put("string<-func", Core.t_string_from_func);
    mapfunc.put("switch", Core.t_switch);
    mapfunc.put("then", Core.t_then);
    mapfunc.put("traits<-typedef", Core.t_traits_from_typedef);
    mapfunc.put("type<-any", Core.t_type_from_any);
    mapfunc.put("typedef<-any", Core.t_typedef_from_any);
    mapfunc.put("typedef<-type", Core.t_typedef_from_type);
    mapfunc.put("typename<-any", Core.t_typename_from_any);
    mapfunc.put("typename<-type", Core.t_typename_from_type);
    mapfunc.put("typename<-typedef", Core.t_typename_from_typedef);
    mapfunc.put("typenames<-typelist", Core.t_typenames_from_typelist);
    mapfunc.put("user<-context", Core.t_user_from_context);
    Core.vx_global_package_set("vx/core", maptype, mapconst, mapfunc);
  }

}
